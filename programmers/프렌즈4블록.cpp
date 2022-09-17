#include <bits/stdc++.h>

using namespace std;
void dropBlocks(vector<vector<int>> &vis, vector<string> &board, int time) {
    for (int i = 0; i < board[0].length(); i++) {
        int pos = -1;
        for (int j = board.size() - 1; j >= 0; j--) {
            if (pos == -1 && vis[j][i] == time)
                pos = j;
            else if (pos != -1 && vis[j][i] != time) {
                swap(board[pos][i], board[j][i]);
                swap(vis[pos][i], vis[j][i]);

                pos--;
            }
        }
    }

    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[i].length(); j++)
            if (vis[i][j] == time) board[i][j] = '-';
}

int solution(int m, int n, vector<string> board) {
    int ans = 0, prevAns = 0, time = 1;
    vector<vector<int>> vis(m, vector<int>(n));

    while (1) {
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (board[i][j] == '-') continue;
                if (board[i][j] != board[i][j + 1]) continue;
                if (board[i][j] != board[i + 1][j]) continue;
                if (board[i][j] != board[i + 1][j + 1]) continue;

                vis[i][j] = vis[i + 1][j] = vis[i][j + 1] = vis[i + 1][j + 1] =
                    time;
            }
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (vis[i][j] == time) ans++;

        dropBlocks(vis, board, time);

        if (prevAns == ans) break;
        prevAns = ans;
        time++;
    }
    return ans;
}