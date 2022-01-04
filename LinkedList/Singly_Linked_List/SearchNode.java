/*

given head of a SLL and key to be searched, find pos of given key, if given key is absent return -1

ip: 10->5->20->15, x=20
op: 3

ip: 10->15, x=20
op: -1

ip: 3->20->5, x=3
op: 1

in recursive solution, we compare first data item with head's data, if they are matching return 1, 
if not, we recusrsively call for remanining LL

now there are two cases:
1) x is present
2) x is absent

*/

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class SearchNode {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(30);
        System.out.println(itrSearch(head, 20));
        System.out.println(recSearch(head, 20));
    }

    public static int itrSearch(Node head, int x)
    {
        int pos = 1;
        Node curr = head;

        while (curr != null) {
            if (curr.data == x)
                return pos;
            else {
                ++pos;
                curr = curr.next;
            }
        }
        return -1;
    }
    
    public static int recSearch(Node head, int x) {
        if (head == null)
            return -1;
        if(head.data == x)
            return 1;
        
        int res = recSearch(head.next, x);
        if(res == -1)
            return -1;
                         
        return (res + 1);
    }
}

/*
Time: O(n)
Space: 
O(1) or theta(1) for itr
O(n) for recursive

op: 
2
2

*/