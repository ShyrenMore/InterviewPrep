/**
 * insert item x at the beginning of the circular LL
 * 
 * Concept: we want to change two things after inserting, the head ptr, and last node should point to newNode
 * 
 * Naive sol: 
 * Traverse the list until we find the last node i.e node whose next is pointing to head, and insert the node
 * Time: O(n)
 * 
 * Eff sol:
 * O(1) time
 * method 1: Maintain tail ptr as part of LL representation
 * method 2: Insert newNode after head, 
 * after inserting newNode, we swap contents or data of head node and newNode
 */

public class InsertAtHead {
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
        // head = naive_insertAtHead(head, 100);
        head = eff_insertAtHead(head, 100);
        printList(head);
    }

    public static Node naive_insertAtHead(Node head, int x) {
        Node newNode = new Node(x);
        if (head == null)
            newNode.next = newNode;
        else {
            Node currNode = head;
            while (currNode.next != head)
                currNode = currNode.next;

            currNode.next = newNode;
            newNode.next = head;
        }

        return newNode;
    }
    
    public static Node eff_insertAtHead(Node head, int x) {
        Node newNode = new Node(x);
        if (head == null)
        {
            newNode.next = newNode;
            return newNode;
        }

        newNode.next = head.next;
        head.next = newNode;

        int t = head.data;
        head.data = newNode.data;
        newNode.data = t;
        return head;
    }
    
    public static void printList(Node head) {
        if (head == null)
            return;

        System.out.print(head.data + "->");
        for (Node r = head.next; r != head; r = r.next)
            System.out.print(r.data + "->");
        System.out.print(head.data+"\n");
    }
}

/**
 * 
 * op:
 * 10->5->20->15->10
 * 100->10->5->20->15->100
 */