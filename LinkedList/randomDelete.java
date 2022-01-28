/**
 * 10->20->30->40->25->null
 * ip: pointer or ref to node with value 30
 * op: the list should change to
 * 10->20->40->25->null
 * 
 * You may assume, the node to be deleted is never the last node 
 * 
 * Approach: Copy nexr node's data in curr node, 
 * and remove the next node
 * then create a link b/w curr and curr.next.next
 * 
 */

public class randomDelete {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(30);
        head.next.next.next = new Node(40);
        head.next.next.next.next = new Node(25);

        printList(head);
        deleteNode(head.next.next);
        printList(head);
    }

    public static void deleteNode(Node ptr) {
        ptr.data = ptr.next.data;
        ptr.next = ptr.next.next;
    }

    public static void printList(Node head) {
        Node traverse = head;
        while (traverse != null) {
            System.out.print(traverse.data + "->");
            traverse = traverse.next;
        }
        System.out.print("null\n");
    }
}

/**
 * op:
 * 10->20->30->40->25->null
 * 10->20->40->25->null
 */