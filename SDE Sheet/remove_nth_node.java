class ListNode {
    int val;
    ListNode next;

    ListNode() {
        this.val = 0;
    }

    ListNode(int val) {
        this.val = val;
    }
}

/*
 * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * 
 * Approach 1: two pass
 * Linearly iterate and calc len of LL
 * traverse again till (len-n)th node 
 * curr.next = curr.next.next
 * 
 * edge case: delete 1st node so len-n = 0
 * head = head.next
 * 
 * Time: O(n + n)
 * Space: O(1)
 * 
 * Approach 2:
 * have fast and slow ptr initiallt at head
 * move fast ptr at nth node ahead
 * now move slow and fast together until fast reaches last node
 * now slow will be just before the node to be deleted
 * slow.next = slow.next.next
 * 
 * Time: O(n)
 */

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode fast = head, slow = head;
        for(int i = 1; i <= n; i++)
            fast = fast.next;

        // edge case when len-n == 0 i.e delete first node
        if (fast == null)
            return head.next;

        while(fast.next != null)
        {
            fast = fast.next;
            slow = slow.next;
        }

        slow.next = slow.next.next;
        return head;
    }
}