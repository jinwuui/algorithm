#include <math.h>

#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
ll solution(int n, vector<int> works) {
    sort(works.begin(), works.end());

    ll answer = 0;
    int sum = 0;

    for (int i = 0; i < works.size(); i++) sum += works[i];
    sum -= n;

    if (sum <= 0) return 0;

    int cur = 0, idx = 0, criteria = 1;
    while (1) {
        while (criteria > works[idx]) idx++;

        if (cur + works.size() - idx >= sum)
            break;
        else {
            cur += works.size() - idx;
            criteria++;
        }
    }
    criteria--;

    for (int i = 0; i < works.size(); i++)
        if (i < idx) {
            answer += pow(works[i], 2);
        } else {
            int value = criteria + (cur < sum);
            answer += pow(value, 2);
            cur++;
        }

    return answer;
}