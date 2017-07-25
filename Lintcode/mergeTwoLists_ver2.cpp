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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if(!l1 && !l2)
            return NULL;

        if(!l1 && l2)
            return l2;
        if(!l2 && l1)
            return l1;

        ListNode *tmp, *ret=NULL, *v;

        while (l1&&l2) {
            if (l2->val > l1->val) {
                v = l1;
                l1 = l1->next;
            } else {
                v = l2;
                l2 = l2->next;
            }
            v->next = NULL;
            if (!ret)
                ret = v;
            else
                tmp->next = v;
            tmp = v;

        }
        if (l1)
            tmp->next = l1;
        if (l2)
            tmp->next = l2;
        return ret;
    }
};
