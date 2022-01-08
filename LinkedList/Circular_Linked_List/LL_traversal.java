/**
 * ip: NULL
 * op: 
 * 
 * ip: 
 * 10 -> 5 -> 20 -> 15
 * |                 |
 *  ------------------ 
 * op: 10 5 20 15 10
 * 
 * ip: 10
 * op: 10 -> 10
 */
public class LL_traversal {
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
        // printList(head2);
    }

    public static void printList(Node head)
    {
        if(head==null)
            return;

        System.out.print(head.data + "->");
        for(Node r = head.next; r!=head; r = r.next)
            System.out.print(r.data + "->");
        System.out.print(head.data);        
    }
}
/**
 * op:
 * 10->5->20->15->10
 * 
 * op:
 * 10->10
 */