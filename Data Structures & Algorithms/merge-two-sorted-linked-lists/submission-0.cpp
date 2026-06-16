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
        if(!list1) return list2;
        if(!list2) return list1;
        if(!list1 && !list2) return nullptr;

        ListNode* dummy = new ListNode(0);
        ListNode* newHead = dummy;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                newHead->next = temp1;
                newHead = newHead->next;
                temp1 = temp1->next;
            }
            else if(temp1->val > temp2->val){
                newHead->next = temp2;
                newHead = newHead->next;
                temp2 = temp2->next;
            }
        }
        if(temp1 == nullptr && temp2 != nullptr) newHead->next = temp2;
        else if(temp2 == nullptr && temp1) newHead->next = temp1; 

        return dummy->next;
    }
};
