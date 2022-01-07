/*

ip: 10->20->30->NULL
op: 10->20->NULL

ip: 10->NULL
op: NULL

ip: NULL
op: NULL

idea: stop at node whose next's next field is null, i.e stop at second last node, and then change the link of curr.next to null
*/
public class delete_last_node {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(30);

        // printing before deleting a node
        printList(head);
        System.out.println();
        head = delTail(head);

        // printing after deleting the node
        printList(head);
    }

    static Node delTail(Node head) {
        if (head == null)
            return head;
        
        if (head.next == null)
            return null;
        
        Node currNode = head;
        while(currNode.next.next != null)
            currNode = currNode.next;
        
        currNode.next = null;
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
 * Time: O(n)
 * op
 * 10 20 30
 * 10 20
 */