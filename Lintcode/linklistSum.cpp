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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode* head, tmp, tmp1, tmp2;
        tmp = head;
        tmp1 = l1;
        tmp2 = l2;

        if (l1 != NULL && l2 != NULL) {
          head-val = l1->val + l2->val;
          tmp1 = l1->next;
          tmp2 = l2->next;
          // tmp = head->next;
        }

        while (tmp1 != NULL && tmp2 != NULL) {
          ListNode* new_node;
          new_node->val = tmp1->val + tmp2->val;
          tmp->next = new_node;
          tmp = tmp->next;
          tmp1 = tmp1->next;
          tmp2 = tmp2->next;
        }

        if (tmp1 == NULL) {
          while (tmp2 != NULL) {
            ListNode* new_node;
            new_node->val = tmp2->val;
            tmp->next = new_node;
            tmp = tmp->next;
            tmp2 = tmp2->next;
          }
        }

        if (tmp2 == NULL) {
          while (tmp1 != NULL) {
            ListNode* new_node;
            new_node->val = tmp1->val;
            tmp->next = new_node;
            tmp = tmp->next;
            tmp1 = tmp1->next;
          }
        }

        ListNode* tmp_del = tmp;
        tmp = NULL;
        delete [] tmp_del;

        return head;

    }
};
