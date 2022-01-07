public class DeleteTail {
    public static void main(String[] args) {
        Node head = new Node(10);
        Node temp1 = new Node(20);
        Node temp2 = new Node(30);

        head.next = temp1;
        temp1.next = temp2;
        temp1.prev = head;
        temp2.prev = temp1;
        printList(head);
        head = deletetailDLL(head);
        printList(head);
    }

    public static Node deletetailDLL(Node head) {
        
        if(head==null)
            return null;
        
        if(head.next == null)
            return null;

        Node lastNode = head;
        while(lastNode.next.next != null)
            lastNode = lastNode.next;
        
        lastNode.next = null;
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
 * null<-10<=>20<=>null
 * 
 * theta(n) time, O(1) space
 * 
 * apart from gaining acces to second last node, you can delete it using only lastnode for DLL
 * lastnode.prev.next = null
 */