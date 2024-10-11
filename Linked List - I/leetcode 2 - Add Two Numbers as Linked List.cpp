ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(0);
    ListNode *temp = head;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        if (sum < 10)
        {
            ListNode *n = new ListNode(sum);
            carry = 0;
            temp->next = n;
            temp = temp->next;
        }
        else
        {
            ListNode *n = new ListNode(sum % 10);
            carry = 1;
            temp->next = n;
            temp = temp->next;
        }
    }
    return head->next;
}