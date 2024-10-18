class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (slow != fast)
            return NULL;
        slow = head;
        if (slow == fast)
            return slow;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (slow == fast)
                return slow;
        }
        return slow;
    }
};