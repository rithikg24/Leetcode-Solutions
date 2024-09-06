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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* res=NULL;
        ListNode* prev=NULL;
        ListNode* t=head;
        set<int> st(nums.begin(),nums.end());
        while(t){
            if(st.find(t->val)==st.end()){
                if(res==NULL){
                    res=t;
                    prev=t;
                }else{
                    prev->next=t;
                    prev=t;
                }
            }
            t=t->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
        }
        return res;
    }
};