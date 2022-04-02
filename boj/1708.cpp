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
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};
const int MOD = 1000000007;

struct Dot {
	ll x, y, p, q;

	Dot() {}
	Dot(int nx, int ny) {
		x = nx, y = ny, p = 0, q = 0;
	}

	bool operator <(const Dot &d) const {
		if (q * d.p != d.q * p) return q * d.p < d.q * p;
		if (y != d.y) return y < d.y;
		return x < d.x;
	}
};

ll ccw(Dot &s, Dot &e, Dot &nx) {
	return (e.x - s.x) * (nx.y - s.y) - (e.y - s.y) * (nx.x - s.x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<Dot> buf(n);
	// 1. 점을 입력 받음
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		buf[i] = Dot(x, y);
	}

	// 2. 점을 y -> x 좌표 순으로 오름차순 정렬
	sort(buf.begin(), buf.end());

	// 3. 첫 점에 대한 나머지 점들의 상대 거리를 구함
	for (int i = 1; i < n; i++) {
		buf[i].p = buf[i].x - buf[0].x;
		buf[i].q = buf[i].y - buf[0].y;
	}

	// 4. 점을 반시계 방향으로 정렬함
	sort(buf.begin() + 1, buf.end());

	// 5. 스택에 두 점을 넣고, 모든 점을 훑음
	stack<int> stk;
	stk.push(0);
	stk.push(1);

	for (int nx = 2; nx < n; nx++) {
		while (stk.size() > 1) {
			int s, e;
			e = stk.top();
			stk.pop();
			s = stk.top();

			// 5.1 점 s, e와 다음 점의 관계가 ccw 일 때까지 스택 pop
			// (같은 직선 위의 점은 볼록 껍질을 이루는 점에서 제외되기때문에, ccw == 0 인 경우도 지나감)
			if (ccw(buf[s], buf[e], buf[nx]) > 0) {
				// 만약 세 점이 ccw 라면, 다음 단계에서 e => s가 되고 nx => e 가 되야하므로
				// 중간 점인 e를 stk 에 넣어줌
				stk.push(e);
				break;
			}
		}
        // 5.2 세 점이 ccw인 경우를 찾게되거나, 스택의 개수가 2개 미만(1개) 가 되면,
        // nx를 스택에 넣어서 기준점(buf[0])과 함께 새로운 볼록 껍질 후보들을 찾아나섬
		stk.push(nx);
	}

    // 문제에서 원하는 볼록 껍질을 이루는 점의 개수
	cout << stk.size();
	return 0;
}