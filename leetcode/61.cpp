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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        if (k == 0) return head;
        
        ListNode *first = head;
        ListNode *tail = head;
        int cnt = 0;
        
        while (k > cnt && head) {
            head = head->next;
            cnt++;
        }
        
        if (k > cnt) {
            k = k % cnt;
            cnt = 0;
            head = first;
            while (k > cnt && head) {
                head = head->next;
                cnt++;
            }
        }
        
        if (!head) return first;
        
        while (head->next) {
            head = head->next;
            tail = tail->next;
        }
        head->next = first;
        
        ListNode *ans = tail->next;
        tail->next = NULL;
        return ans;
    }
};