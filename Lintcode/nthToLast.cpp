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
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list.
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        ListNode *forward = head;
        for (int i = 0; i < n; i++) {
          if (forward == NULL)
            return NULL;
          forward = forward->next;
        }

        while (forward != NULL) {
          head = head->next;
          forward = forward->next;
        }
        return head;
    }
};
