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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res(2,-1);
        vector<int> cp;

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return res;
        }

        ListNode* temp=head->next;
        ListNode* prev=head;
        int i=1;

        while(temp->next!=NULL){
            if(temp->val>prev->val && temp->val>temp->next->val){
                cp.push_back(i);
            }else if(temp->val<prev->val && temp->val<temp->next->val){
                cp.push_back(i);
            }
            prev=temp;
            temp=temp->next;
            i++;
        }

        if(cp.size()<2){
            return res;
        }

        res[1]=cp.back()-cp.front();
        res[0]=INT_MAX;

        for(int i=1;i<cp.size();i++){
            res[0]=min(res[0],cp[i]-cp[i-1]);
        }

        return res;

    }
};