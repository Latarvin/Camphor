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
        if (head == NULL)
          return NULL;

        ListNode* tmp;
        ListNode* next_node;
        tmp = head;

        while (tmp->next != NULL) {
          next_node = tmp->next;

          if (next_node->val == tmp->val) {
            while (next_node->val == tmp->val) {
              ListNode* del_node;
              del_node = next_node;
              next_node = next_node->next;
              delete [] del_node;
            }
            tmp->next = next_node;
          }

          tmp = tmp->next;
          if (next_node == NULL)
            break;
          next_node = NULL;
        }

        delete [] next_node, tmp;
        return head;
    }
};
