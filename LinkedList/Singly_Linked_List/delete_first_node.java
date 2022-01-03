/*

ip: 10->20->30->NULL
op: 20->30->40->NULL

ip: 10->NULL
op: NULL

ip: NULL
op: NULL

*/

public class delete_first_node {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(30);

        // printing before deleting a node
        printList(head);
        System.out.println();
        head = delHead(head);

        // printing after deleting the node 
        printList(head);
    }

    static Node delHead(Node head) {
        if (head == null)
            return head;
        else
            return head.next;
    }

    public static void printList(Node head) {
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.data + " ");
            curr = curr.next;
        }
    }
}

/*
in java, we do not have to worry about memory de-allocation
in c++:
Node* temp = head->next;
delete head
return temp;

Time: O(1)
*/
