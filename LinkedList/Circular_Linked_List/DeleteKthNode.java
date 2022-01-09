/**
 * Given a CLL and a value k, delete kth node from beginning
 * 
 * ip 10->20->30->10, k=2
 * op 10->30->10
 * 
 * ip: 10->20->30->40->10, k=1
 * op: 20->30->40
 * 
 * ip: 10->10, k=1
 * op: head=null or NULL
 * 
 * The sol can be divided into two cases
 * 1) deleting head node
 * 2) deleting any other node
 * 
 * for deleting other node i.e k>1, we need to traverse to (k-1)th node
 * once we have access to (k-1)h node, we can do
 * (k-1)h node.next = (k-1)h node.next.next
 * so k-1th node's next will point to k+1th node
 * 
 */

public class DeleteKthNode {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(5);
        head.next.next = new Node(20);
        head.next.next.next = new Node(15);
        head.next.next.next.next = head;
        printList(head);

        deletekNode(head, 5);

        printList(head);
    }

    public static Node deleteHead(Node head) {
        if (head == null)
            return null;

        if (head.next == head)
            return null;

        head.data = head.next.data;
        head.next = head.next.next;
        return head;
    }
    
    public static Node deletekNode(Node head, int k)
    {
        if (head == null)
            return head;

        if (k == 1)
            return deleteHead(head);

        Node curr = head;
        for (int i = 0; i < k - 2; i++)
            curr = curr.next;

        curr.next = curr.next.next;
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
