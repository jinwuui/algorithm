#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (computers[i][i] == -1) continue;
        
        ans++;
        computers[i][i] = -1;
        
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1) {

                computers[i][j] = computers[j][i] = 0;
                computers[j][j] = -1;
                queue<int> q;
                q.push(j);
                while (q.size()) {
                    int cur = q.front();
                    q.pop();
                    
                    for (int k = 0; k < n; k++) {
                        if (computers[cur][k] == 1) {
                            computers[cur][k] = computers[k][cur] = 0;
                            computers[k][k] = -1;
                            q.push(k);
                        }
                    }
                }
            }
        }
    }    
    
    return ans;
}