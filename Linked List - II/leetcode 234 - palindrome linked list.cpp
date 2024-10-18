class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *p = head, *r = NULL;
        while (p != NULL)
        {
            ListNode *q = p->next;
            p->next = r;
            r = p;
            p = q;
        }
        return r;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *p = reverse(slow->next);
        slow = head;
        while (p != NULL)
        {
            if (slow->val != p->val)
                return false;
            slow = slow->next;
            p = p->next;
        }
        return true;
    }
};