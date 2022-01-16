#include <bits/stdc++.h>
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<set<pair<int, pii>>> buys(6);
vector<set<pair<int, pii>>> sells(6);
vector<vector<int>> v(6, vector<int>());
vector<pair<set<pair<int, pii>>::iterator, pii>> vit(222222);

const int NONE = 0;
const int BUYS = 1;
const int SELLS = 2;

void init() {
	vit.clear();
	for (int i = 1; i < 6; i++) {
		v[i].clear();
		buys[i].clear();
		sells[i].clear();
	}
}

void buyDebug(int n) {
	set<pair<int, pii>>::iterator it = buys[n].begin();
	cout << "-----buys-----" << sp << buys[n].size() << endl;
	for (; it != buys[n].end(); it++) {
		cout << "[price: " << it->first << ", num: " << -(it->second.first) << ", quantitiy: " << it->second.second << "]\n";
	}
}

void sellDebug(int n) {
	set<pair<int, pii>>::iterator it = sells[n].begin();
	cout << "-----sells-----" << sp << sells[n].size() << endl;
	for (; it != sells[n].end(); it++) {
		cout << "[price: " << it->first << ", num: " << it->second.first << ", quantitiy: " << it->second.second << "]\n";
	}
	cout << endl;
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice) {
	set<pair<int, pii>>::iterator it = sells[mStock].lower_bound({mPrice, {1e9, mQuantity}});
	set<pair<int, pii>>::iterator i = sells[mStock].begin();

	vector<set<pair<int, pii>>::iterator> del;
	pair<int, pii> pushData = {-1, {-1 ,-1}};
	for (; i != it; i++) {
		int num = i->second.first, quan = i->second.second, price = i->first;

		cout << "buy : " << price << sp << num << sp << quan << endl;
		mQuantity -= quan;
		v[mStock].push_back(price);
		
		if (mQuantity < 0) {
			pushData = {price, {num, -mQuantity}};
			del.push_back(i);

			mQuantity = 0;
			break;
		} else {
			vit[num].second.first = NONE;
			del.push_back(i);
			if (mQuantity == 0) break;
		}
	}

	for (int j = 0; j < del.size(); j++) {
		sells[mStock].erase(del[j]);
	}
	if (pushData.first != -1) {
		pair<set<pair<int, pii>>::iterator, bool> pib = sells[mStock].insert(pushData);
		vit[pushData.second.first] = {pib.first, {SELLS, mStock}};
	}

	if (mQuantity) {
		pair<set<pair<int, pii>>::iterator, bool> pib = buys[mStock].insert({mPrice, {-mNumber, mQuantity}});
		vit[mNumber] = {pib.first, {BUYS, mStock}};
		return mQuantity;
	} else {
		return 0;
	}
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice) {
	set<pair<int, pii>>::iterator it = buys[mStock].lower_bound({mPrice, {-1e9, mQuantity}});
	set<pair<int, pii>>::iterator i = buys[mStock].end();
	
	if (it == buys[mStock].end()) {
		// pass
	} else {
		// 값 있음 - 매도

		--i;
		bool isOk = true;
		vector<set<pair<int, pii>>::iterator> del;
		pair<int, pii> pushData = {-1, {-1 ,-1}};
		while (isOk && mQuantity > 0) {
			if (i == it) isOk = false;

			int num = -(i->second.first), quan = i->second.second, price = i->first;

			cout << "sell : " << i->first << sp << num << sp << i->second.second << endl;
			mQuantity -= quan;
			v[mStock].push_back(price);

			if (mQuantity < 0) {
				pushData = {price, {-num, -mQuantity}};
				del.push_back(i);

				mQuantity = 0;
				break;
			} else {
				vit[num].second.first = NONE;
				del.push_back(i);
				if (mQuantity == 0) break;
			}

			i--;
		}

		for (int j = 0; j < del.size(); j++) {
			buys[mStock].erase(del[j]);
		}
		if (pushData.first != -1) {
			pair<set<pair<int, pii>>::iterator, bool> pib = buys[mStock].insert(pushData);
			vit[-pushData.second.first] = {pib.first, {BUYS, mStock}};
		}
	}

	if (mQuantity) {
		pair<set<pair<int, pii>>::iterator, bool> pib = sells[mStock].insert({mPrice, {mNumber, mQuantity}});
		vit[mNumber] = {pib.first, {SELLS, mStock}};
		return mQuantity;
	} else {
		return 0;
	}
}

void cancel(int mNumber) {
	pair<set<pair<int, pii>>::iterator, pii> val = vit[mNumber];
	if (val.second.first == BUYS) {
		vit[mNumber].second.first = NONE;
		buys[val.second.second].erase(val.first);
		cout << "cancel " << mNumber << endl;
	} else if (val.second.first == SELLS) {
		vit[mNumber].second.first = NONE;
		sells[val.second.second].erase(val.first);
		cout << "cancel " << mNumber << endl;
	}
}

int bestProfit(int mStock) {
	int minv = 1e9, minidx = -1, maxv = -1e9, maxidx = -1;
	int ans = 0;
	for (int i = 0; i < v[mStock].size(); i++) {
		ans = max(ans, maxv - minv);
		if (minv > v[mStock][i]) {
			minv = v[mStock][i];
			minidx = i;
		} else if (maxv < v[mStock][i]) {
			maxv = v[mStock][i];
			maxidx = i;
		}

		if (minidx > maxidx) {
			maxidx = minidx;
			maxv = minv;
		}
	}
	ans = max(ans, maxv - minv);

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t, score;
	cin >> t >> score;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int order;
			cin >> order;
			cout << "i-" << i;
			if (order == 1) {
				cout << " init()" << endl;
				init();
			} else if (order == 2) {
				int mNumber, mStock, mQuantity, mPrice, ans;
				cin >> mNumber >> mStock >> mQuantity >> mPrice >> ans;
				if (buy(mNumber, mStock, mQuantity, mPrice) != ans) {
					cout << " : buy() 틀림 " << --score << endl;
				} else {
					cout << " : buy() 맞음 " << score << endl;
				}
				buyDebug(mStock);
				sellDebug(mStock);
			} else if (order == 3) {
				int mNumber, mStock, mQuantity, mPrice, ans;
				cin >> mNumber >> mStock >> mQuantity >> mPrice >> ans;
				if (sell(mNumber, mStock, mQuantity, mPrice) != ans) {
					cout << " : sell() 틀림" << --score << endl;
				} else {
					cout << " : sell() 맞음" << score << endl;
				}
				buyDebug(mStock);
				sellDebug(mStock);
			} else if (order == 4) {
				cout << " is cancel order" << endl;
				int mNumber;
				cin >> mNumber;
				cancel(mNumber);
			} else {
				int mStock, ans;
				cin >> mStock >> ans;
				if (bestProfit(mStock) != ans) {
					cout << " : bestProfit() 틀림" << --score << endl;
				} else {
					cout << " : bestProfit() 맞음" << score << endl;
				}
				buyDebug(mStock);
				sellDebug(mStock);
			}
		}
	}
	
	cout << score;

	return 0;
}