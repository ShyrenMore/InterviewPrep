/**
 * Given a LL and number n,
 * print nth node from end of LL
 * 
 * ip: 10 -> 20 -> 30 -> 40 -> 50, n = 2
 * op: 40
 * 
 * ip: 10 -> 20, n = 3
 * op: 
 * 
 * ip: 10 -> 20 -> 30, n = 1
 * op: 30
 * 
 * Approach1: 
 * find len of LL
 * ans: (len-n)th node
 * 
 * Approach2: two ptrs
 * we move firstptr n positions ahead from head
 * we have secondptr from head
 * move both the ptr in same speed
 * when firstptr reaches null, secondptr will be present on op node 
 * 
 * Both of have time O(n)
 */

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class nthNodefromEnd {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(30);
        head.next.next.next = new Node(40);
        // printNthFromEnd(head, 3);
        printNthFromEnd_twoptr(head, 3);
    }

    public static void printNthFromEnd(Node head, int n) {
        int len = 0;
        Node curr = head;

        while (curr != null) {
            ++len;
            curr = curr.next;
        }

        if (len < n)
            return;

        curr = head;
        int i = 0;
        while (i < (len - n)) {
            curr = curr.next;
            ++i;
        }

        System.out.println(curr.data);
    }

    public static void printNthFromEnd_twoptr(Node head, int n) {
        if(head == null)
            return;

        Node first = head;
        for(int i = 0; i < n; i++)
        {
            // if len<n
            if (first == null)
                return;
            first = first.next;
        }
        
        Node second = head;
        while(first != null)
        {
            second = second.next;
            first = first.next;
        }

        System.out.println(second.data);
    }
    public static void printList(Node head) {
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.data + " ");
            curr = curr.next;
        }
    }
}
