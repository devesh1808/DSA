ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *slow = head, *fast = head;
    while (n)
    {
        slow = slow->next;
        if (slow == NULL)
            break;
        n--;
    }
    if (slow == NULL)
        return head->next;
    ListNode *q;
    while (slow != NULL)
    {
        q = fast;
        slow = slow->next;
        fast = fast->next;
    }
    q->next = fast->next;
    return head;
}