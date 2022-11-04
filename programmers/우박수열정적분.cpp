#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> area;
    while (k != 1) {
        int prev = k;
        if (k % 2 == 0)
            k /= 2;
        else
            k = k * 3 + 1;
        area.push_back((prev + k) * 1.0 / 2.0);
    }
    vector<double> answer;
    for (auto& range : ranges) {
        int s = range[0], e = area.size() + range[1] - 1;
        double sum = 0;

        if (s == e + 1)
            sum = 0;
        else if (s > e + 1)
            sum = -1;
        else {
            for (; s <= e; s++) {
                sum += area[s];
            }
        }
        answer.push_back(sum);
    }
    return answer;
}