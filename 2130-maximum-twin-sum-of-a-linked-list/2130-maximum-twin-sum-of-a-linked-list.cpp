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
        ListNode* middle(ListNode* head){
            if(head==NULL || head->next==NULL) return head;

            ListNode* slow=head;
            ListNode* fast=head;

            while(fast && fast->next){
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow;
        }

        ListNode* reverse(ListNode* head){
            ListNode* prev=nullptr;
            ListNode* curr=head;

            while(curr){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }

    int pairSum(ListNode* head) {
        ListNode* mid=middle(head);
        ListNode* second=reverse(mid);
        ListNode* temp=head;

        int maxi=0;
        while(second){
            int sum=temp->val +second->val;
            temp=temp->next;
            second=second->next;
            maxi=max(maxi,sum);
        }

        return maxi;
    }
};