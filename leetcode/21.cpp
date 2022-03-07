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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
        
        vector<ListNode*> v;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                v.push_back(list1);
                list1 = list1->next;
            } else {
                v.push_back(list2);
                list2 = list2->next;
            }
        }
        while (list1 != nullptr) {
            v.push_back(list1);
            list1 = list1->next;
        }
        while (list2 != nullptr) {
            v.push_back(list2);
            list2 = list2->next;
        }
        
        for (int i = 1; i < v.size(); i++) {
            v[i - 1]->next = v[i];
        }
        
        return v[0];
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        else if (!list2) return list1;
        
        ListNode* start = list1;
        if (list1->val > list2->val) {
            start = list2;
            list2 = list2->next;
        } else {
            list1 = list1->next;
        }
        
        ListNode* cur;
        cur = start;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        if (!list1) cur->next = list2;
        else cur->next = list1;
        
        return start;
    }
};