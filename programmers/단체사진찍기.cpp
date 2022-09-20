#include <string>
#include <vector>

using namespace std;

vector<int> v;
vector<int> vis(8);

int_least64_t brute(vector<string> &cond, int ord) {
    if (v.size() == 8) {
        // check logic
        bool isOk = true;
        for (int i = 0; i < cond.size() && isOk; i++) {
            int pos1 = vis[cond[i][0] - '0'], pos2 = vis[cond[i][2] - '0'];
            int posGap = abs(pos1 - pos2) - 1;
            int dist = cond[i][4] - '0';

            if (cond[i][3] == '=' && posGap != dist) {
                isOk = false;
            } else if (cond[i][3] == '<' && posGap >= dist) {
                isOk = false;
            } else if (cond[i][3] == '>' && posGap <= dist) {
                isOk = false;
            }
        }

        return isOk;
    }

    int ans = 0;
    for (int i = 0; i < 8; i++) {
        if (vis[i])
            continue;

        vis[i] = ord;
        v.push_back(i);
        ans += brute(cond, ord + 1);
        vis[i] = 0;
        v.pop_back();
    }

    return ans;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].length(); j++) {
            if (data[i][j] == 'A')
                data[i][j] = '0';
            else if (data[i][j] == 'C')
                data[i][j] = '1';
            else if (data[i][j] == 'F')
                data[i][j] = '2';
            else if (data[i][j] == 'J')
                data[i][j] = '3';
            else if (data[i][j] == 'M')
                data[i][j] = '4';
            else if (data[i][j] == 'N')
                data[i][j] = '5';
            else if (data[i][j] == 'R')
                data[i][j] = '6';
            else if (data[i][j] == 'T')
                data[i][j] = '7';
        }
    }

    return brute(data, 1);
}