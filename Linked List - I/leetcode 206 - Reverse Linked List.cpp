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