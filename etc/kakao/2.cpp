#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <sstream>

using namespace std;

bool buf[5000001];

vector<string> ntok(int n, int k) {
	vector<string> v;
	string ret;
	while (n) {
		if (n % k == 0) {
			reverse(ret.begin(), ret.end());
			while (ret.length() && ret.back() == '0') ret.pop_back();
			if (ret.length())
				v.push_back(ret);
			
			ret.clear();
		}
		else {
			ret.push_back((n % k) + '0');
		}
		n /= k;
	}
	reverse(ret.begin(), ret.end());
	if (ret.length())
		v.push_back(ret);
	return v;
}

bool isPrime(string s) {
	long long num = stoll(s);
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

vector<string> split(string s, char c) {
	istringstream iss(s);
	string sb;
	vector<string> ret;
	ret.clear();

	while (getline(iss, sb, c))
		ret.push_back(sb);

	return ret;
}

int solution(int n, int k) {
    int ans = 0;

	buf[0] = 1;
	buf[1] = 1;
	for (int i = 2; i * i <= 5000000; i++) {
		if (!buf[i]) {
			for (int j = i * i; j <= 5000000; j += i) {
				buf[j] = 1;
			}
		}
	}

	// 1. n을 k진수로 바꾸기
	vector<string> v = ntok(n, k);

	for (int i = 0; i < v.size(); i++) {
		string tmp = v[i];

		if (tmp.length() > 7 || stoi(tmp) >= 5000000) {
			if (isPrime(tmp)) {
				ans++;
			}
		}
		else {
			int num = stoi(tmp);
			if (!buf[num]) ans++;
		}
	}
    
	return ans;
}


int main() {
	int n, k;
	cin >> n >> k;
	cout << solution(n, k);
	return 0;
}