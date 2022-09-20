#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    set<string> st;
    for (int i = 0; i < phone_book.size(); i++) {
        string s = phone_book[i];
        for (int j = 0; j < s.length(); j++) {
            if (st.find(s.substr(0, j + 1)) != st.end())
                return false;
        }

        st.insert(s);
    }

    return true;
}