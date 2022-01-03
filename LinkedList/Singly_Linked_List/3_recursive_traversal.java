class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class RecursiveTraversal {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(30);
        head.next.next.next = new Node(40);
        rprintList(head);
    }

    public static void rprintList(Node headNode) {
        if (headNode == null)
            return;

        System.out.println(headNode.data + " ");
        rprintList(headNode.next);
    }
}

/*

Time: O(n)
Space: O(n), for n nodes, n+1 function calls in function call stack

Hence iterative sol is better

*/

/*
 * op
 * 10
 * 20
 * 30
 * 40
 */