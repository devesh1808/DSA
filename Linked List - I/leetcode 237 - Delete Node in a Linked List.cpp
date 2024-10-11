void deleteNode(ListNode *node)
{
    ListNode *p = node, *q = node->next;
    p->val = q->val;
    p->next = q->next;
}