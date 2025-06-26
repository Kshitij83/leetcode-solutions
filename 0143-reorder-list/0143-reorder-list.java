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
    public void reorderList(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next!=null && fast.next.next!=null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        slow.next = reverseLL(slow.next);
        fast = slow.next;
        slow.next = null;
        slow = head;
        while(fast!=null && fast.next!=null) {
            ListNode temp1 = fast.next;
            ListNode temp2 = slow.next;
            slow.next = fast;
            fast.next = temp2;
            slow = temp2;
            fast = temp1;
        }
        if(fast!=null) fast.next = slow.next;
        slow.next = fast;
    }
    public ListNode reverseLL(ListNode head) {
        ListNode prev = null;
        ListNode next = null;
        ListNode curr = head;
        while(curr!=null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}