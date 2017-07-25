/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        int temp=-1;
        ListNode *r,*f;
        r=new ListNode(0);
        f=r;
        while(head!=NULL)
        {
            if(head->val!=temp)
            {
                ListNode *dummy;
                temp=head->val;
                dummy=new ListNode(temp);
                r->next=dummy;
                r=dummy;
                head=head->next;
            }
            else
                head=head->next;
        }
        return f->next;
    }
};
