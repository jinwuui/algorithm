#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int l = 0, r = 1, sum = 1, cnt = 0;
    while (l <= r) {
        if (sum < n) {
            r++;
            sum += r;
        } else if (sum > n) {
            sum -= l;
            l++;
        } else {  // sum == n
            cnt++;
            r++;
            sum += r;
        }
    }
    return cnt;
}