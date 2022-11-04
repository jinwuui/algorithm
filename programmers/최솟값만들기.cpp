#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        ans += A[i] * B[B.size() - i - 1];
    }
    return ans;
}