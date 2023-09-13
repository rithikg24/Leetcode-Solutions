/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head;
        ListNode *slow=head;

        if(head==NULL || head->next==NULL){
            return NULL;
        }

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                fast=head;
                break;
            }
        }

        while(fast!=slow && fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

        return fast;
    }
};