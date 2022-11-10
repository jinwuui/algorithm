#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string solution(vector<int> food) {
    string foods = "";
    for (int i = 1; i < food.size(); i++) {
        int cur = food[i] / 2;
        for (int j = 0; j < cur; j++) foods += (char)(i + '0');
    }
    string ans = foods + "0";
    reverse(foods.begin(), foods.end());
    return ans + foods;
}