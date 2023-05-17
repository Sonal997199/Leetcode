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
    int pairSum(ListNode* head) {
        int sum=0;
        ListNode* slow=head;
        ListNode* fast=head;
        stack<int> st;
        while(fast!=NULL)
        {
            st.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        while(slow)
        {
            int t=st.top()+slow->val;
            sum=max(sum,t);
            slow=slow->next;
            st.pop();
        }
        return sum;
    }
};