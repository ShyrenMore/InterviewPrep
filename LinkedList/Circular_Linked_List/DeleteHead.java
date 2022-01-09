/**
 * Naive sol would be find last node through traversing the entire list
 * lastnode.next = head.next
 * O(n) time
 * 
 * Eff sol would be copy data of second node to head, now delete the second node
 * O(1) time
 * 
 * Visualisation
 * 10 -> 20 -> 30 -> 40
 * |                  |
 * -------------------
 * 
 * 20 -> 20 -> 30 -> 40
 * |                 |
 * -------------------
 * 
 * 20 -> 30 -> 40
 * |            |
 * --------------
 */

public class DeleteHead {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(5);
        head.next.next = new Node(20);
        head.next.next.next = new Node(15);
        head.next.next.next.next = head;

        // creating a single node CLL
        Node head2 = new Node(10);
        head2.next = head2;

        printList(head);
        head = naive_deleteHead(head);
        // head = eff_deleteHead(head);
        printList(head);
    }

    public static Node naive_deleteHead(Node head)
    {
        if (head == null)
            return head;

        if (head.next == head)
            return null;

        Node curr = head;
        while (curr.next != head)
            curr = curr.next;

        curr.next = head.next;
        return curr.next;
    }

    public static Node eff_deleteHead(Node head) {
        if(head == null)
            return null;
        
        if (head.next == head)
            return null;

        head.data = head.next.data;
        head.next = head.next.next;
        return head;
    }

    public static void printList(Node head) {
        if (head == null)
            return;

        System.out.print(head.data + "->");
        for (Node r = head.next; r != head; r = r.next)
            System.out.print(r.data + "->");
        System.out.print(head.data + "\n");
    }
}
