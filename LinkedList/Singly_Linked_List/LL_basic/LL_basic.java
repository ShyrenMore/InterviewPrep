class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class LL_basic {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(30);
        head.next.next.next = new Node(40);
        printList(head);
    }

    public static void printList(Node headNode) {
        Node curr = headNode;
        while (curr != null) {
            System.out.println(curr.data + " ");
            curr = curr.next;
        }
    }
}
