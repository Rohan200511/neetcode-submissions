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
    private:
        ListNode* reverse(ListNode* head){
            if(!head || !head->next) return head;

            ListNode* prev = nullptr;
            ListNode* temp = head;

            while(temp){
                ListNode* curr = temp->next;
                temp->next = prev;
                prev = temp;
                temp = curr;
            }
            return prev;
        }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* firstHalf = head;
        ListNode* secondHalf = reverse(slow->next);

        slow->next = nullptr;

        while(firstHalf && secondHalf){
            ListNode* temp1 = firstHalf->next;
            firstHalf->next = secondHalf;
            firstHalf = temp1;

            temp1 = secondHalf->next;
            secondHalf->next = firstHalf;
            secondHalf = temp1;
        }
    }
};
