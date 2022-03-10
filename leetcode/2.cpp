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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = l1;
        ListNode *prev;
        
        int up = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + up;
            l1->val = sum % 10;
            up = sum / 10;
            
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if (l1) {
            while (l1) {
                int sum = l1->val + up;
                l1->val = sum % 10;
                up = sum / 10;

                prev = l1;
                l1 = l1->next;
            } 
        } else {
            prev->next = l2;
            l1 = l2;
            while (l1) {
                int sum = l1->val + up;
                l1->val = sum % 10;
                up = sum / 10;

                prev = l1;
                l1 = l1->next;
            }
        }

        if (up) prev->next = new ListNode(1);
        
        return head;
    }
};

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(), *result;
        result = dummy;

        int up = 0;
        while (l1 || l2) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a + b + up;
            
            if (sum >= 10)
                up = 1, sum -= 10;
            else
                up = 0;
            
            result->next = new ListNode(sum);
            result = result->next;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        
        if (up) result->next = new ListNode(1);
        
        return dummy->next;
    }
};