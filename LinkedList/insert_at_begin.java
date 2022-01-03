/*

ip: 10->20->30->NULL, x=5
op: 5->10->20->30->NULL

ip: 10->NULL, x=5
op: 5->10->NULL

ip: NULL, x=5
op: 5->NULL

*/

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class insert_at_begin {
    public static void main(String[] args) {
        Node head = null;
        head = insertBegin(head, 30);
        head = insertBegin(head, 20);
        head = insertBegin(head, 10);
        printList(head);
    }

    static Node insertBegin(Node head, int x)
    {
        Node tempNode = new Node(x);
        tempNode.next = head;
        return tempNode;
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
Time: O(1) for each insert
*/