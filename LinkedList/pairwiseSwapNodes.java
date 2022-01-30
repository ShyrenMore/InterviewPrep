/**
 * Given a LL, swap nodes pairwise
 * i.e swap ith node with (i+1)th node
 * 
 * ip: 1 -> 2 -> 3 -> 4 -> 5 -> 6
 * op: 2 -> 1 -> 4 -> 3 -> 6 -> 5
 * 
 * ip: 1 -> 2 -> 3 -> 4 -> 5
 * op: 2 -> 1 -> 4 -> 3 -> 5
 * 
 * Method 1: 
 * begin a ptr from first node, this ptr will move two positions ahead
 * before moving forward, swap curr's data and curr's next's data
 * 
 * Time: O(n),Space: O(1)
 * if data is an object, then swapping can be costly
 * disadvantage: we are swapping data
 * 
 */

public class pairwiseSwapNodes {
    public static void main(String[] args) {
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);
        head.next.next.next.next.next = new Node(6);

        printList(head);
        pairwiseSwap(head);
        printList(head);
    }

    public static void pairwiseSwap(Node head) {
        Node curr = head;
        while (curr != null && curr.next != null) {
            int x = curr.data;
            curr.data = curr.next.data;
            curr.next.data = x;

            curr = curr.next.next;
        }
    }

    public static void printList(Node head) {
        Node traverse = head;
        while (traverse != null) {
            System.out.print(traverse.data + "->");
            traverse = traverse.next;
        }
        System.out.print("null\n");
    }
}

/**
 * op
 * 1->2->3->4->5->6->null
 * 2->1->4->3->6->5->null
 */

