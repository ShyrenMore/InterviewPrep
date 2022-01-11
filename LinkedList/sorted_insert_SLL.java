import java.util.Scanner;

/**
 * Given a sorted LL and a data item, insert data item such that LL remains
 * sorted even after insertion
 * 
 * ip: 10->20->30->40, x=25
 * op: 10->20->25->30->40
 * 
 * ip: 10->25, x=5
 * op: 5->10->25
 * 
 * ip: 10->20, x=30
 * op: 10->20->30
 * 
 * ip: null, x= 10
 * op: 10
 * 
 * we traverse the list, for traversing let's have a node called curr, it will initially point to first node 
 * we will compare curr's next data item with x
 * if(curr.next < x)
 *  move to next node
 * if(curr.next > x)
 *  insert a node after curr
 * 
 * newNode.next = curr.next 
 * curr.next = newNode
 */

class Node {
    Node next;
    int data;
    Node(int x){
        data = x;
        next = null;
    }
}

class sorted_insert_SLL {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(30);

        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();

        printList(head);
        head = sortedInsert(head, x);
        printList(head);

        sc.close();
    }
    
    public static Node sortedInsert(Node head, int x) {
        Node newNode = new Node(x);

        if (head == null)
            return null;

        if (x < head.data) {
            newNode.next = head;
            head = newNode;
            return head;
        }

        Node curr = head;
        while (curr.next != null && curr.next.data < x) {
            curr = curr.next;
        }

        newNode.next = curr.next;
        curr.next = newNode;
        return head;
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
 * ip:
 * 5
 * 
 * op:
 * 10->20->30->null
 * 5->10->20->30->null
 */