#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int all = brown + yellow;
    int h = 0;
    while (1) {
        h++;
        if (all % h != 0)
            continue;

        int w = all / h;
        int predict = h * 2 + w * 2 - 4;
        if (predict == brown && all - predict == yellow) {
            vector<int> answer({w, h});
            return answer;
        }
    }
}