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

 template <class T>
 class comparator{
    public:
      bool operator()(T a, T b)
      {
          return a>b;
      }

 };
class Solution {
private:
    /*ListNode* merge(ListNode* ll1,ListNode* ll2)
    {
        if(!ll1) return ll2;
        if(!ll2) return ll1;

        ListNode* root=ll1->val<=ll2->val?ll1:ll2;
        root->next=ll1->val<=ll2->val?merge(ll1->next,ll2):merge(ll1,ll2->next);

        return root;
    }*/
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*if(!lists.size()) return NULL;

        ListNode* head=lists[0];

        for(int i=1;i<lists.size();i++)
        {
            head=merge(head,lists[i]);
        }
        return head;*/


        priority_queue<int, vector<int>, comparator<int>> pq;
        for(auto i:lists)
        {
            ListNode* curr=i;
            while(curr)
            {
                pq.push(curr->val);
                curr=curr->next;
            }
        }
        if(pq.empty()) return NULL;

        ListNode* head=new ListNode(pq.top());
        pq.pop();
        ListNode* p=head;

        while(!pq.empty())
        {
            p->next=new ListNode(pq.top());
            pq.pop();
            p=p->next;
        }

        return head;
    }
};