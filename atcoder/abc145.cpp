#include <bits/stdc++.h>
#define R first
#define C second
#define W first
#define ND second
#define endl '\n'
#define sp ' '
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, start, n) for (int i = start; i < (n); i++)
#define all(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

vector<string> split(string s, char deli) {
    istringstream iss(s);
    string sb; vector<string> ret;
    ret.clear();
    while (getline(iss, sb, deli)) ret.push_back(sb);
    return ret;
}

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};
const int MOD = 1000000007;

vector<int> x, y;
vector<int> vis(10), path;
double ans;
int n;

void brute(int k) {
    if (k == n) {
        double dist = 0;
        for (int i = 1; i < n; i++) {
            int cur = path[i];
            int pre = path[i - 1];
            dist += hypot(abs(x[cur] - x[pre]), abs(y[cur] - y[pre]));
        }
        ans += dist;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        vis[i] = 1;
        path.push_back(i);
        brute(k + 1);
        path.pop_back();
        vis[i] = 0;
    }

}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    freopen("../input.txt", "r", stdin); freopen("../output.txt", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        x.push_back(a);
        y.push_back(b);
    }

    brute(0);

    int facto = n;
    while (--n) facto *= n;
    printf("%.6lf", ans * 1.0 / facto);

    return 0;
}