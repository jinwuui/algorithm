#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> tri) {
    int row = tri.size();

    for (int i = 1; i < row; i++) {
        for (int j = 0; j <= i; j++) {
            int maxv = -1;
            if (j != i) maxv = max(maxv, tri[i - 1][j]);
            if (j > 0) maxv = max(maxv, tri[i - 1][j - 1]);
            tri[i][j] += maxv;
        }
    }

    return *max_element(tri[row - 1].begin(), tri[row - 1].end());
}