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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right)
            return head;
        ListNode* prev=NULL;
        ListNode* temp=head;
        int pos=1;
        while(pos<left){
            prev=temp;
            temp=temp->next;
            pos++;
        }
        ListNode* beforeleft=prev;
        ListNode* leftnode=temp;

        while(pos <= right) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
            pos++;
        }
        if(beforeleft != NULL)
            beforeleft->next = prev;
        else
            head = prev;

        leftnode->next = temp;

        return head;
    }
};