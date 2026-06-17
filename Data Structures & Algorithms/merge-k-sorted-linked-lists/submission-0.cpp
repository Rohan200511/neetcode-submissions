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
    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        while(list1!=nullptr && list2!=nullptr){
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if(list1!=nullptr){
            temp->next = list1;
        }
        if(list2!=nullptr){
            temp->next = list2;
        }
        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        while(lists.size() > 1){
            vector<ListNode*>temp;

            for(auto i = 0 ; i < lists.size() ; i += 2){
                ListNode* l1 = lists[i];
                ListNode* l2 = (i+1 < lists.size()) ? lists[i+1] : nullptr;
                temp.push_back(mergeLists(l1,l2));
            }
            lists = move(temp);
        }
        return lists[0];
    }
};