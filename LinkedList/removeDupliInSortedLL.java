/**
 * Given a sorted SLL, rmeove duplicates from the list
 * ip: 10->20->20->30->30->30->null
 * op: 10->20->30
 * 
 * ip: null
 * op: null
 * 
 * Approach: 
 * Traverse the LL using a curr ref/ptr
 * Check if curr's data === curr's next data
 * if yes
 *  remove the node
 * else 
 *  move curr to next node 
 */

public class removeDupliInSortedLL {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(20);
        head.next.next.next = new Node(30);
        head.next.next.next.next = new Node(30);
        head.next.next.next.next.next = new Node(30);

        printList(head);
        removeDupli(head);
        printList(head);
    }

    public static void removeDupli(Node head) {
        Node curr = head;
        while(curr!=null && curr.next!=null)
        {
            if(curr.data == curr.next.data)
                curr.next = curr.next.next;
            else 
                curr = curr.next;
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
 