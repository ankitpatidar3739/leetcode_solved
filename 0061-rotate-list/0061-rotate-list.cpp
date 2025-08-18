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
    ListNode* func(ListNode* temp,int k){
        int cnt=1;
        while(temp!=NULL){
            if(cnt==k) return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL || k==0) return head;
        int l=1;
        ListNode* tail=head;
        while(tail->next!=NULL){
            l++;
            tail=tail->next;
        }
        if(k%l==0) return head;
        k=k%l;

        tail->next=head;

        ListNode* newlastnode=func(head,l-k);
        head=newlastnode->next;
        newlastnode->next=NULL;

        return head;
   }
};