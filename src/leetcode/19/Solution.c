/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int listLen(struct ListNode *head)
{
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    int len = listLen(head);
    struct ListNode *pseudo = (struct ListNode *)malloc(sizeof(struct ListNode));
    pseudo->next = head;
    int rn = len - n + 1;
    struct ListNode *pre = pseudo;
    struct ListNode *cur = pseudo->next;
    int i = 1;
    while (i != rn) {
        pre = pre->next;
        cur = cur->next;
        i++;
    }
    pre->next = cur->next;
    struct ListNode *ans = pseudo->next;
    free(pseudo);
    return ans;
}