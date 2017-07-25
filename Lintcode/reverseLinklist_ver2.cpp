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
        ListNode *change, *save;
        change = NULL;
        save = NULL;
        while (head != NULL) {
          save = head->next;
          head->next = change;
          change = head;
          head = save;
          if (save == NULL)
             break;
        }
        return change;
    }
};
