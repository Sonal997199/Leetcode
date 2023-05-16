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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        /*ListNode* prev=new ListNode(0);
        ListNode* curr=head;
        ListNode* Next=head->next;

        ListNode* temp=head;
        head=head->next;

        while(temp!=NULL)
        {
            curr=temp;
            Next=temp->next;

            if(temp->next==NULL)
            {
                prev->next=curr;
                break;
            }
            else
            {
                curr->next=Next->next;
                Next->next=curr;
                prev->next=Next;
                prev=curr;
                temp=curr->next;
            }
        }
        return head;*/

        ListNode* slow=head;
        ListNode* fast=head->next;

        slow->next=fast->next;
        fast->next=slow;
        head=fast;
        slow->next=swapPairs(slow->next);
        return head;
    }
};