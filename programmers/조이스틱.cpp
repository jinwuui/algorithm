#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int ans = 0, n = name.length(), dist = n - 1;
    for (int i = 0; i < n; i++) {
        ans += min(name[i] - 'A', 'Z' - name[i] + 1);

        int idx = i + 1;
        while (idx < n && name[idx] == 'A')
            idx++;

        dist = min(dist, n - idx + i + min(i, n - idx));
    }

    return ans + dist;
}