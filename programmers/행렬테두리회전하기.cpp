#include <string>
#include <vector>

using namespace std;

vector<vector<int>> mat(102, vector<int>(102));

int rotate(int sr, int sc, int er, int ec) {
    int first = mat[sr][sc], minv = first;
    
    for (int i = sr; i < er; i++) {
        mat[i][sc] = mat[i + 1][sc];
        minv = min(minv, mat[i][sc]);
    }
    for (int i = sc; i < ec; i++) {
        mat[er][i] = mat[er][i + 1];
        minv = min(minv, mat[er][i]);
    }
    for (int i = er; i > sr; i--) {
        mat[i][ec] = mat[i - 1][ec];
        minv = min(minv, mat[i][ec]);
    }
    for (int i = ec; i > sc + 1; i--) {
        mat[sr][i] = mat[sr][i - 1];
        minv = min(minv, mat[sr][i]);
    }
    mat[sr][sc + 1] = first;
    return minv;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            mat[i][j] = (i - 1) * columns + j;

    for (int i = 0; i < queries.size(); i++) {
        answer.push_back(rotate(
            queries[i][0],queries[i][1],queries[i][2],queries[i][3]));
    }
    
    return answer;
}