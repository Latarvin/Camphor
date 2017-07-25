/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        // exception
        if (head == NULL)
          return NULL;

        ListNode* tmp = head;
        ListNode* del_node;
        while (tmp->val == val) {
          del_node = tmp;
          tmp = tmp->next;
          head = tmp;
          delete [] del_node;
          if (head == NULL)
            return NULL;
        }

        while (tmp->next != NULL) {
          if (tmp->next->val == val) {
            del_node = tmp->next;
            tmp->next = tmp->next->next;
            delete [] del_node;
            if (tmp->next == NULL){
              break;
            }
          }
          if (tmp->next->val != val)
            tmp = tmp->next;
        }

        return head;
    }
};
