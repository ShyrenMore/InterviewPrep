/*

ip: 10->20->30->NULL, x=40
op: 10->20->30->40->NULL

ip: 10->NULL, x=20
op: 10->20->NULL

ip: NULL, x=10
op: 10->NULL

idea: allocate memory for new Node, then we traverse the list and find the last node,  and we make next of last node as new node
*/


public class insert_at_end {
    public static void main(String[] args) {
        Node head = null;
        head = insertEnd(head, 20);
        head = insertEnd(head, 10);
        printList(head);
    }

    public static Node insertEnd(Node head, int x) {
        Node newNode = new Node(x);
        if(head == null)
            return newNode;

        Node curr = head;
        while (curr.next != null)
            curr = curr.next;
        
        curr.next = newNode;
        return head;
    }
    
    public static void printList(Node head) {
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.data + " ");
            curr = curr.next;
        }
    }
}

/**
 * op
 * 20 10
 * 
 */