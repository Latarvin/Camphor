/**
 * Definition of ListNode
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        ListNode *former, *latter;

        if (head == NULL)
          return NULL;

        if (head->next == NULL)
          return head;

        former = head;
        former->next = NULL;
        head = head->next;
        latter = head->next;
        head->next = former;

        if (latter == NULL)
          return head;

        while (latter != NULL) {
          former = head;
          head = latter;
          latter = head->next;
          head->next = former;
        }
        return head;
    }
};
