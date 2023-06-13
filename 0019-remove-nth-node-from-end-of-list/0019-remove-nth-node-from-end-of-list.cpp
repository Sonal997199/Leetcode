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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode* temp,*t;
        //ListNode* t=head;
        temp=head;
        t=head;
        int cnt=1;
        while(temp->next)
        {
            temp=temp->next;
            cnt++;
        }
        int res=cnt+1-n;
        if(res==1)
        {
            t=t->next;
            head=t;
            return head;
        }
        else if(res==cnt)
        {
            while(t->next->next!=NULL)
            {
                t=t->next;
            }
            t->next=nullptr;
            return head;
        }
        else
        {
            while(res-2)
            {
                t=t->next;
                res--;
            }
            t->next=t->next->next;
            return head;
        }
        return head;
    }
};