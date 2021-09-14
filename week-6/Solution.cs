public class Solution {
    public ListNode MergeKLists(ListNode[] lists)
    {
        if (lists.Length == 0)
        {
            return null;
        }
        int count = lists.Length;
        while (count > 1)
        {
            for (int i = 0; i < count - 1; i+=2)
            {
                lists[i / 2] = MergeTwoList(lists[i], lists[i + 1]);
            }

            if (count % 2 == 1)
                lists[count / 2] = lists[count - 1];
            count = (count + 1) / 2;
        }
        return lists[0];
    }

    public ListNode MergeTwoList(ListNode head1, ListNode head2)
    {
        if (head1 == null || head2 == null)
            return head1 ?? head2;
        ListNode returnHead;
        if (head1.val > head2.val)
        {
            returnHead = head2;
            head2 = head2.next;
        }
        else
        {
            returnHead = head1;
            head1 = head1.next;
        }

        var cursor = returnHead;
        while (head1 != null && head2 != null)
        {
            if (head1.val < head2.val)
            {
                cursor.next = head1;
                head1 = head1.next;
            }
            else
            {
                cursor.next = head2;
                head2 = head2.next;
            }

            cursor = cursor.next;

        }

        cursor.next = head1 ?? head2;
        
        return returnHead;
    }
}