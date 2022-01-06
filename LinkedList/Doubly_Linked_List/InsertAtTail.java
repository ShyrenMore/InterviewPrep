public class InsertAtTail {
    public static void main(String[] args) {
        Node head = new Node(10);
        Node temp1 = new Node(20);
        Node temp2 = new Node(30);

        head.next = temp1;
        temp1.prev = head;
        temp1.next = temp2;
        temp2.prev = temp1;
        printList(head);
        head = insertTail(head, 40);
        printList(head);
    }

    public static Node insertTail(Node head, int data) {
        Node newNode = new Node(data);
        
        if(head==null)
            return newNode;

        Node curr = head;

        while (curr.next != null)
            curr = curr.next;

        curr.next = newNode;
        newNode.prev = curr;
        return head;
    }
    
    public static void printList(Node head) {
        Node tempNode = head;
        while(tempNode!=null)
        {
            System.out.print(tempNode.data + "<=>");
            tempNode = tempNode.next;
        }
        System.out.print("null\n");
    }
}
