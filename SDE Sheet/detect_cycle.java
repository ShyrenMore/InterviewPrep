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

/**
 * Link: https://leetcode.com/problems/linked-list-cycle/
 */

public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast)
                return true;
        }

        return false;
    }
}