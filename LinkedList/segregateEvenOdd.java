/**
 * Given a SLL,
 * modify the LL such that nodes with even values appear first and then odd
 * nodes
 * relative order of occurence should be same
 * 
 * ip: 17->15->8->12->10->5->4
 * op: 8->12->10->4->17->15->5
 * 
 * // in case of LL having only odd els or only even els, 
 * there would be no change in LL
 * 
 * Naive approach: 
 * Traverse LL and get ref of last node 
 * we traverse the list again, node with odd el is removed and added after the last node 
 * 
 * O(2n)
 * 
 * Eff approach:
 * Traverse the list, while traversing, keep even nodes together by maintaining seperate LL of even nodes 
 * similarly we create a LL of only odd nodes
 * we have to maintain a track of 
 * 1) head of even and odd lists
 * 2) tail of even and odd lists
 * 
 * After the  traversal, we simply have to todo 
 * tail of even = head of odd list
 * 
 * Time: O(n)
 */
public class segregateEvenOdd {
    public static void main(String[] args) {
        Node head = new Node(17);
        head.next = new Node(15);
        head.next.next = new Node(8);
        head.next.next.next = new Node(12);
        head.next.next.next.next = new Node(10);
        head.next.next.next.next.next = new Node(5);
        head.next.next.next.next.next.next = new Node(4);
        
        printList(head);
        head = segregateEvenOdd(head);
        printList(head);
    }
    
    public static Node segregateEvenOdd(Node head) {
        Node evenHead = null, evenTail = null, oddHead = null, oddTail = null;

        Node curr = head;
        while (curr != null) {
            int x = curr.data;
            if (x % 2 == 0) {
                if (evenHead == null) {
                    evenHead = curr;
                    evenTail = evenHead;
                } else {
                    evenTail.next = curr;
                    evenTail = evenTail.next;
                }
            } else {
                if (oddHead == null) {
                    oddHead = curr;
                    oddTail = oddHead;
                } else {
                    oddTail.next = curr;
                    oddTail = oddTail.next;
                }
            }

            curr = curr.next;
        }

        // if no nodes of even els or odd els are found, ip==op
        if (oddHead == null || evenHead == null)
            return head;

        // connecting the two lists
        evenTail.next = oddHead;
        oddTail.next = null;

        return evenHead;
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
