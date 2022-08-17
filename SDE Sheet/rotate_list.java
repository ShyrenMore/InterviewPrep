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
 * Link:
 * https://leetcode.com/problems/rotate-list/
 */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        /*
         * - convert to circular LL
         * - traverse to n-k th node i.e 3 where n is len
         * - 3's next will be new head
         * - update 3's next to null to revolve back to single LL
         * 
         * if n<<<k
         * calc len and do k = k%n
         */

        // corner cases
        if (head == null || head.next == null || k == 0)
            return head;

        ListNode temp = head;
        int n = 1;
        while (temp.next != null) {
            ++n;
            temp = temp.next;
        }

        // convert to circular LL
        temp.next = head;

        k = k % n;
        temp = head;
        for (int i = 1; i < n - k; i++)
            temp = temp.next;

        // System.out.print(temp.val);

        ListNode newHead = temp.next;
        temp.next = null;

        return newHead;
    }
}