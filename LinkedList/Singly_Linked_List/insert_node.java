package Singly_Linked_List;

/*
Given a SLL, a pos & a data item, insert data-item at given pos(1-based indexing) 

ip: 10->30->50->70, pos=2, data=20
op: 10->20->30->50->70

ip: 5->15->25->35, pos=5, data=10
op: 5->15->25->35->10

ip: 10->20, pos=4, data=5
op: 10->20

idea: we need to traverse the list (pos-2) times, so we can reach (pos-1)th node, let's call it curr node, we will insert a newNode after it

after that we need to point newNode's next to where curr's next is pointing & change curr's next to newNode
*/
public class insert_node {
    public static void main(String[] args) {
        Node head = null;
        // head = insertAtPos(head, 20);
        // head = insertEnd(head, 10);
        printList(head);
    }

    public static Node insertAtPos(Node head, int data, int pos) {
        
        Node newNode = new Node(data);
        
        if(pos==1)
        {
            newNode.next = head;
            return newNode;
        }

        Node prevNode = head;

        // go to pos-1th node
        for(int i = 1; i<=pos-2 && prevNode!=null; i++)
            prevNode = prevNode.next;

        // case: pos > LL size
        if(prevNode==null)
            return head;
        
        // actual logic
        newNode.next = prevNode.next;
        prevNode.next = newNode;

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
