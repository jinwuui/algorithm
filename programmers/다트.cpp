#include <math.h>

#include <string>
#include <vector>

using namespace std;
int solution(string dartResult) {
    int answer = 0, num = 0;
    vector<int> v;

    for (int i = 0; i < dartResult.length(); i++) {
        char c = dartResult[i];

        if ('0' <= c && c <= '9') {
            num = num * 10 + c - '0';
        } else {
            if (c == 'S' || c == 'D' || c == 'T') {
                int x = 1;
                if (c == 'D') x = 2;
                if (c == 'T') x = 3;

                v.push_back(pow(num, x));
            } else {
                if (c == '*') {
                    v[v.size() - 1] *= 2;
                    if (v.size() - 2 >= 0) v[v.size() - 2] *= 2;
                } else {
                    v[v.size() - 1] *= -1;
                }
            }

            num = 0;
        }
    }
    for (int i = 0; i < v.size(); i++) answer += v[i];

    return answer;
}
