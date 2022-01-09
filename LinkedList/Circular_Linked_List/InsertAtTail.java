/**
 * 
 * Naive sol would be to start from head and traverse till last node and then insert newNode but it will take O(n) time
 * 
 * Eff sol would be maintain tail ptr
 * 
 * Another eff sol would be 
 * insert newNode after head, then we swap contents of head of newNode, and we now need to change the head to head.next, we are done, time: O(1)
 */

public class InsertAtTail {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = head;
        head = eff_insertAtTail(head, 20);
        head = eff_insertAtTail(head, 30);
        head = eff_insertAtTail(head, 15);
        printList(head);
    }

    public static Node insertAtTail(Node head, int x)
    {
        Node newNode = new Node(x);
        if (head == null)
            return newNode;

        Node curr = head;
        while (curr.next != head)
            curr = curr.next;
        curr.next = newNode;
        newNode.next = head;
        return head;
    }

    public static Node eff_insertAtTail(Node head, int x) {
        Node newNode = new Node(x);
        if(head==null)
        {
            newNode.next = newNode;
            return newNode;
        }
        else {
            // insert newNode after head
            newNode.next = head.next;
            head.next = newNode;

            // swapping
            int t = newNode.data;
            newNode.data = head.data;
            head.data = t;

            // now change the head
            head = head.next;
            return head;
        }
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

/**
 * op
 * 200->10->200
 * 200->10->20->30->200
 */