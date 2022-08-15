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
 * Link: https://leetcode.com/problems/add-two-numbers/
 * Approach:
 *  - create dummy node with val 0, which gives you head of LL and a temp node
 *  - only move the temp node 
 *  - we need two vars: sum = 0 and carry = 0
 *  In each interation, until l1 = null || l2 = null || carry = 0 :
 *  sum += l1 (if l1 is not null)
 *  sum += l2 (if l2 is not null)
 *  
 *  if carry 
 *      sum += carry
 *      carry = 0
 *  if no carry
 *      then new Node(sum) and assign temp to newNode
 *  if sum >= 10
 *      then new Node(sum%10) and assign temp to newNode 
 *      and carry = sum/10;
 *  l1 = l1.next; l2 = l2.next
 * 
 * ans: dummy.next
 * 
 * Time: max(n1, n2), Space: O(n1)
 * Edge case: 
 */

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode();
        ListNode temp = dummy;
        int carry = 0;

        while(l1 != null || l2 != null || carry == 1)
        {
            int sum = 0;
            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }

            sum += carry;
            carry = sum / 10;
            ListNode newNode = new ListNode(sum % 10);
            temp.next = newNode;
            temp = temp.next;
        }
        
        return dummy.next;
    }
}