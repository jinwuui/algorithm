#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int, vector<int>, greater<int>> minQ;
    priority_queue<int> maxQ;
    map<int, int> minDel, maxDel;

    for (int i = 0; i < operations.size(); i++) {
        string op = operations[i];

        if (op[0] == 'I') {
            int num = stoi(op.substr(2));
            minQ.push(num);
            maxQ.push(num);
        } else {
            if (op[2] == '-') {
                while (minQ.size() && minDel[minQ.top()]) {
                    minDel[minQ.top()]--;
                    minQ.pop();
                }
                if (minQ.size()) {
                    maxDel[minQ.top()]++;
                    minQ.pop();
                }
            } else {
                while (maxQ.size() && maxDel[maxQ.top()]) {
                    maxDel[maxQ.top()]--;
                    maxQ.pop();
                }
                if (maxQ.size()) {
                    minDel[maxQ.top()]++;
                    maxQ.pop();
                }
            }
        }
    }

    while (minQ.size() && minDel[minQ.top()]) {
        minDel[minQ.top()]--;
        minQ.pop();
    }

    while (maxQ.size() && maxDel[maxQ.top()]) {
        maxDel[maxQ.top()]--;
        maxQ.pop();
    }

    vector<int> answer;
    if (minQ.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(maxQ.top());
        answer.push_back(minQ.top());
    }

    return answer;
}