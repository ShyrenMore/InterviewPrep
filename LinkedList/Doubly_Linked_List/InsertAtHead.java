class Node {
    int data;
    Node prev;
    Node next;

    Node(int d)
    {
        data = d;
        next = prev = null;
    }
}
public class InsertAtHead {
    public static void main(String[] args) {
        Node head = new Node(10);
        Node temp1 = new Node(20);
        Node temp2 = new Node(30);

        head.next = temp1;
        temp1.prev = head;
        temp1.next = temp2;
        temp2.prev = temp1;
        head = insertBegin(head, 40);
        System.out.println(head.data);
    }
    
    public static Node insertBegin(Node head, int data)
    {
        Node newNode = new Node(data);
        newNode.next = head;

        if(head!=null)
            head.prev = newNode;
        return newNode;
    }
}
