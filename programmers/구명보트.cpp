#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int n = people.size(), cnt = 0;

    int l = 0, r = n - 1;
    while (l < r) {
        if (people[l] + people[r] <= limit) {
            l++, r--, cnt++;
        } else {
            r--;
        }
    }
    return n - cnt;
}