class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> v(query_row + 1, vector<double>(query_row + 2));
    
        v[0][1] = poured;
        int maxRow = query_row + 1;
        for (int i = 1; i < maxRow; i++) {
            for (int j = 1; j <= i + 1; j++) {
                if (v[i - 1][j - 1] > 1) {
                    v[i][j] += (v[i - 1][j - 1] - 1) / 2;
                }
                if (v[i - 1][j] > 1) {
                    v[i][j] += (v[i - 1][j] - 1) / 2;
                }
            }
        }
        
        return v[query_row][query_glass + 1] > 1.0 ? 1.0 : v[query_row][query_glass + 1];
    }
};