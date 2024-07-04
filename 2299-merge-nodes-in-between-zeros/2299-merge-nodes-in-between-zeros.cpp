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
    void insert(ListNode* &head,int n){
        if(head==NULL){
            head = new ListNode(n);
            return;
        }
        ListNode* t=head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=new ListNode(n);
    }
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* loc=head;
        ListNode* res=NULL;

        int s=0;

        while(temp){
            if(temp->val==0){
                loc->val=s;
                s=0;
                if(temp->next!=NULL){
                    loc=loc->next;
                }
            }else{
                s+=temp->val;
            }
            temp=temp->next;
        }

        loc->next=NULL;


        return head;
    }
};