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
    public ListNode rotateRight(ListNode head, int k) {
        int count = 0;
        ListNode temp = head;
        if(head==null) return head;
        while(temp.next!=null) {
            temp = temp.next;
            count++;
        }
        count++;
        k %= count;
        if(k==0) return head;
        int diff = count - k;
        ListNode lastnode = temp;
        temp = head;
        while(diff>1) {
            temp = temp.next;
            diff--;
        }
        ListNode newNode = temp.next;
        temp.next = null;
        lastnode.next = head;
        return newNode;
    }
}