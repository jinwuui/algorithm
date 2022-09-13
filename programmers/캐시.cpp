#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

void changeToLowerCase(vector<string> &cities) {
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities[i].length(); j++) {
            if ('A' <= cities[i][j] && cities[i][j] <= 'Z')
                cities[i][j] = cities[i][j] - 'A' + 'a';
        }
    }
}

int solution(int cacheSize, vector<string> cities) {
    changeToLowerCase(cities);
    
    int answer = 0, size = 0;
    
    queue<string> q;
    multiset<string> st;
    
    for (int i = 0; i < cities.size(); i++) {
        if (st.find(cities[i]) == st.end()) {
            q.push(cities[i]);
            st.insert(cities[i]);
            answer += 5;
            size++;

            if (size > cacheSize) {
                while (1) {
                string target = q.front(); q.pop();
                    auto it = st.find(target);

                    if(it != st.end()) st.erase(it);
                    if (st.find(target) == st.end()) break;
                }
                size--;
            }
            
        } else {
            q.push(cities[i]);
            st.insert(cities[i]);
            answer++;
        }
    }
    
    return answer;
}