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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prevNode;

        while(fast && fast->next){
            fast=fast->next->next;
            prevNode=slow;
            slow=slow->next;
        }

        prevNode->next=prevNode->next->next;

        return head;
    }
};