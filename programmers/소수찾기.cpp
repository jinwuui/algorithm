#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int che[10000000];
vector<int> vis(10);

int brute(string &src, string prime, int cnt) {
    if (cnt == src.length()) {
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < src.length(); i++) {
        if (vis[i])
            continue;

        vis[i] = 1;
        prime.push_back(src[i]);
        int num = stoi(prime);
        if (prime.length() != 0 && !che[num])
            ans++, che[num]--;

        ans += brute(src, prime, cnt + 1);
        vis[i] = 0;
        prime.pop_back();
    }

    return ans;
}

int solution(string numbers) {
    fill(che, che + 10000000, 0);
    vis.resize(10);

    che[1] = 1, che[0] = 1;
    for (int i = 2; i * i < 10000000; i++)
        if (!che[i])
            for (int j = i + i; j < 10000000; j += i)
                che[j] = 1;

    return brute(numbers, "", 0);
}