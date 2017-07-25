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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        if (!head)
          return NULL;

        if (!head->next)
          return head;

        ListNode *tmp, *swap1, *swap2;
        if (head->next) {
          swap1 = head;
          swap2 = head->next;
          swap1->next = swap2->next;
          head = swap2;
          head->next = swap1;
          tmp = swap1;
        }

        while (tmp->next && tmp->next->next) {
          swap1 = tmp->next;
          swap2 = tmp->next->next;
          swap1->next = swap2->next;
          tmp->next = swap2;
          tmp->next->next = swap1;
          tmp = swap1;
        }

        return head;
    }
};
