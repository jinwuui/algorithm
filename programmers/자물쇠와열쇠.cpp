#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt0 = 0;

void rotate(vector<vector<int>> &key) {
    vector<vector<int>> cp(key.size(), vector<int>(key[0].size()));

    for (int i = 0 ; i < key.size(); i++)
        for (int j = 0; j < key[i].size(); j++)
            cp[key.size() - j - 1][i] = key[i][j];
    
    key = cp;
}

bool isUnlock(vector<vector<int>> &key, vector<vector<int>> &lock) {
    int n = key.size() + lock.size() - 1;
    int kn = key.size(), ln = lock.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            bool isOk = true;
            int cnt = 0;
            for (int ii = 0; ii < ln && isOk; ii++) {
                for (int jj = 0; jj < ln && isOk; jj++) {
                    int kr = kn - (i + 1) + ii, kc = kn - (j + 1) + jj;

                    if (kr < 0 || kr >= kn || kc < 0 || kc >= kn) continue;

                    if (lock[ii][jj] && key[kr][kc]) {
                        isOk = false;
                    } else if (!lock[ii][jj] && key[kr][kc]) {
                        cnt++;
                    }
                }
            }

            if (isOk && cnt == cnt0)
                return true;
        }
    }
    
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    for (int i = 0; i < lock.size(); i++)
        for (int j = 0; j < lock.size(); j++)
            if (!lock[i][j]) cnt0++;

    for (int i = 0; i < 4; i++) {

        if (isUnlock(key, lock))
            return true;

        rotate(key);
    }

    return false;
}

int main() {
    freopen("../input.txt", "r", stdin); freopen("../output.txt", "w", stdout);

    int size = 3;
    vector<vector<int>> key(size, vector<int>(size));
    vector<vector<int>> lock(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> key[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> lock[i][j];
        }
    }

    cout << solution(key, lock);

    return 0;
}