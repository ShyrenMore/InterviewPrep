class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }
}

/*
 * Approach: maintain slow and fast ptr, when fast points to null, slow will point to middle
 */

class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode slowptr = head, fastptr = head;

        while (fastptr != null && fastptr.next != null) {
            fastptr = fastptr.next.next;
            slowptr = slowptr.next;
        }

        return slowptr;
    }
}