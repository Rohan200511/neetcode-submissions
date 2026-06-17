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

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        ListNode* curr = head;
        int count = 0;

        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        if (count < k)
            return head;

        ListNode* nextGroup = curr;
        curr = head;
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }

        ListNode* temp = curr->next;
        curr->next = nullptr;  

    
        ListNode* newHead = reverse(head);

        head->next = reverseKGroup(nextGroup, k);

        return newHead;
    }
};