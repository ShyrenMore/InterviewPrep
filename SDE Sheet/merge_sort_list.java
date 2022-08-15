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
 * Link: https://leetcode.com/problems/merge-two-sorted-lists/
 * 
 * Approach 1: not in place
 * we follow logic of merge sort that is merging two sorted arrays in m+n time
 * - create dummy node with val 0, which gives you head of LL and a temp node
 * we compare l1 and l2
 * case 1 : l1 <= l2 => create newNode(l1) and point temp to this new Node, l1 = l1.next;
 * 
 * case 2 : l1 > l2 => create newNode(l2) and point temp to this new Node, l2 = l2.next;
 * 
 * if (l1 != null || l2 != null)
 *      create newNode and append val
 * 
 * dummy.next is the linked List head of ans
 */

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        // corner case: if any of LL is empty
        if (list1 == null)
            return list2;
        if (list2 == null)
            return list1;

        ListNode dummy = new ListNode();
        ListNode temp = dummy;

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                ListNode newNode = new ListNode(list1.val);
                list1 = list1.next;
                temp.next = newNode;
                temp = temp.next;
            } else {
                ListNode newNode = new ListNode(list2.val);
                list2 = list2.next;
                temp.next = newNode;
                temp = temp.next;
            }
        }

        while (list1 != null) {
            ListNode newNode = new ListNode(list1.val);
            list1 = list1.next;
            temp.next = newNode;
            temp = temp.next;
        }

        while (list2 != null) {
            ListNode newNode = new ListNode(list2.val);
            list2 = list2.next;
            temp.next = newNode;
            temp = temp.next;
        }

        return dummy.next;
    }
    
}

/*

Approach 2: In place


*/