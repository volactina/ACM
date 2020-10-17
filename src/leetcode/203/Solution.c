/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (head == NULL) {
        return head;
    }
    if (head->val == val) {
        return removeElements(head->next, val);
    }
    head->next = removeElements(head->next, val);
    return head;
}