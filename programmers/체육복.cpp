#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    vector<int> lostv(n + 1);
    for (int i = 0; i < lost.size(); i++)
        lostv[lost[i]]++;

    int cnt = 0;
    for (int i = 0; i < reserve.size(); i++)
        if (lostv[reserve[i]]) {
            lostv[reserve[i]]--, cnt++;
            reserve[i] = -1;
        }

    sort(reserve.begin(), reserve.end());
    for (int i = cnt; i < reserve.size(); i++) {
        int tmp = reserve[i];

        if (tmp > 1 && lostv[tmp - 1]) {
            lostv[tmp - 1]--, cnt++;
        } else if (tmp < n && lostv[tmp + 1]) {
            lostv[tmp + 1]--, cnt++;
        }
    }

    return n - (lost.size() - cnt);
}