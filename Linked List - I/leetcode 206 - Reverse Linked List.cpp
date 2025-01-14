ListNode *reverseList(ListNode *head)
{
    ListNode *p = head, *r = NULL;
    ListNode *q;
    while (p != NULL)
    {
        q = p->next;
        p->next = r;
        r = p;
        p = q;
    }
    return r;
}


// Recursive solution

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *newHead = reverseList(head->next);
        ListNode *p = head->next;
        p->next = head;
        head->next = NULL;
        return newHead;
    }
};