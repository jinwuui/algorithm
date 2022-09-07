#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    set<int> st;
    for (int i = 0; i < win_nums.size(); i++) {
        st.insert(win_nums[i]);
    }
    
    int cnt_zero = 0, matched = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) {
            cnt_zero++;
            continue;
        }
        
        if (st.find(lottos[i]) != st.end()) {
            matched++;
        }
    }
    
    int best = 7 - (matched + cnt_zero), worst = 7 - matched;
    
    answer.push_back(best >= 7 ? 6 : best);
    answer.push_back(worst >= 7 ? 6 : worst);        
    
    return answer;
}