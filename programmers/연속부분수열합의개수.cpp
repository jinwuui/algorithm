#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> elements) {
    int maxsum = 0, n = elements.size();
    for (auto e : elements) maxsum += e;

    vector<int> vis(maxsum + 1);
    vis[maxsum] = 1;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n - 1; j++) {
            sum += elements[(i + j) % n];
            vis[sum]++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < vis.size(); i++) {
        if (vis[i]) cnt++;
    }
    return cnt;
}