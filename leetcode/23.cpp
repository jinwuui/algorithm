/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> count(20010);
        
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                do {
                    count[lists[i]->val + 10000]++;
                    lists[i] = lists[i]->next;
                } while (lists[i] != nullptr);
                // count[lists[i]->val + 10000]++;               
            }
        }
        
        ListNode *result = new ListNode();
        ListNode *first = result;
        for (int i = 0; i < 20010; i++) {
            if (count[i]) {
                cout << i << " " << count[i] << endl;
            }
            for (int j = 0; j < count[i]; j++) {
                result->next = new ListNode(i - 10000);
                result = result->next;
            }
        }
        
        return first->next;
    }
};