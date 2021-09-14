/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists==null) return null;
        
        ListNode head=new ListNode(-1);
        ListNode p=head;
        PriorityQueue<ListNode> front = new PriorityQueue<>((l1,l2)->Integer.compare(l1.val,l2.val));
        
        for(ListNode l:lists)
            if (l!=null) front.add(l);
        
        while(!front.isEmpty()){
            ListNode next = front.poll();
            p.next=next;
            p=next;
            if (next.next!=null) front.add(next.next);
        }
        return head.next;
    }
}
