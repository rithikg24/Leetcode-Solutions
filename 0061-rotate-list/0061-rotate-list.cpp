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
    int lengthOfList(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len=lengthOfList(head);
        if(len==0 || len==1) return head;
        if(k>=len) k=k%len;

        if(k==0) return head;

        int cnt=0;
        ListNode* store;
        ListNode*temp=head;
        while(cnt<len-k){
            store=temp;
            temp=temp->next;
            cnt++;
        }
        store->next=NULL;
        ListNode* newHead=temp;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        return newHead;
    }
};