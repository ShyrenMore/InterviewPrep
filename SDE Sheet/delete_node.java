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
 * Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
 * Approach: copy next data to curr node, and delete next node 
 */

class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}