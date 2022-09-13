#include <string>
#include <vector>

using namespace std;

string intToBinary(int num, int rep) {
    string result = "";
    
    for (int i = 0; i < rep; i++) {
        if (num % 2) result = "#" + result;
        else result = " " + result;
        num /= 2;
    }
    
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> ans;
    
    for (int i = 0; i < n; i++) {
        arr1[i] = arr1[i] | arr2[i];
        ans.push_back(intToBinary(arr1[i], n));
    }
    
    return ans;
}