public class DeleteHead {
    public static void main(String[] args) {
        Node head = new Node(10);
        Node temp1 = new Node(20);
        Node temp2 = new Node(30);

        head.next = temp1;
        temp1.next = temp2;
        temp1.prev = head;
        temp2.prev = temp1;
        printList(head);
        head = deleteheadDLL(head);
        printList(head);
    }

    public static Node deleteheadDLL(Node head) {

        // 0 nodes 
        if (head == null)
            return null;
        
        // only one node
        if (head.next == null)
            return null;

        // >2 nodes
        head = head.next;
        head.prev = null;
        return head;
    }

    public static void printList(Node head) {
        Node tempNode = head;
        System.out.print("null<-");
        while (tempNode != null) {
            System.out.print(tempNode.data + "<=>");
            tempNode = tempNode.next;
        }
        System.out.print("null\n");
    }
}

/**
 * op
 * null<-10<=>20<=>30<=>null
 * null<-20<=>30<=>null
 * 
 * O(1) time & space
 */