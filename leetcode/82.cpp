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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return NULL;
        if (head->next == nullptr) return head;
            
        ListNode *prev = head;
        ListNode *pprev, *ans = head, *lastAns;
        // head = head->next;
        while (head && head->next) {
            // cout << head->val << endl;
            if (head->val == head->next->val) {
                int cur = head->val;
                while (head && cur == head->val) head = head->next;
                if (!head && ans->val == cur) return NULL; 
                if (ans->val == cur) ans = head;
                else {
                    lastAns->next = head;
                    // lastAns = lastAns->next;
                }
            }
            if (head && head->next && head->val == head->next->val) continue;
            
            lastAns = head;
            // cout << "lastAns : " << lastAns->val << endl;
            if (head)
                head = head->next;
        }
        return ans;
    }
};