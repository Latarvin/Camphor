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
        if (l1 == NULL)
          return l2;
        if (l2 == NULL)
          return l1;

        ListNode *tmp, *head = NULL, *now;

        while (l1 != NULL && l2 != NULL) {
          if (l1->val < l2->val) {
            tmp = l1;
            l1 = l1->next;
          } else {
            tmp = l2;
            l2 = l2->next;
          }

          tmp->next = NULL;
          if (head == NULL)
              head = tmp;
          else
              now->next = tmp;
          now = tmp;
        }

        if (l1 != NULL)
          now->next = l1;
        if (l2 != NULL)
          now->next = l2;

        return head;
    }
};
