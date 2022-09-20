#include <set>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    multiset<string> st;
    for (int i = 0; i < participant.size(); i++) {
        st.insert(participant[i]);
    }
    for (int i = 0; i < completion.size(); i++) {
        auto it = st.find(completion[i]);
        if (it != st.end())
            st.erase(it);
    }
    return *st.begin();
}