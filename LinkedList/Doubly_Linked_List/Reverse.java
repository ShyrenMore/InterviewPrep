/**
 * ip: 10 <=> 20 <=> 30 <=> 40
 * op: 40 <=> 30 <=> 20 <=> 10
 * 
 * ip: 10
 * op: 10
 * 
 * ip: NULL
 * op: NULL
 * 
 * solution: consider 10 <=> 20 <=> 30 <=> 40
 * for a node we want to swap node.next and node.prev 
 * see dry run in LinkedList/imgs/
 * Travserse every node of DLL, simply swap next and prev
 */
public class Reverse {
    public static void main(String[] args) {
        Node head = new Node(10);
        Node temp1 = new Node(20);
        Node temp2 = new Node(30);

        head.next = temp1;
        temp1.prev = head;
        temp1.next = temp2;
        temp2.prev = temp1;
        printList(head);
        head = reverseList(head);
        printList(head);
    }

    public static Node reverseList(Node head) {

        // corner cases: Empty or only one node list
        if(head == null || head.next == null)
            return head;

        Node currNode = head, tempNode = null;
        while(currNode!=null)
        {
            // swapping
            tempNode = currNode.prev;
            currNode.prev = currNode.next;
            currNode.next = tempNode;

            // moving on to next node of og DLL
            currNode = currNode.prev;
        }

        return tempNode.prev;
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
 * 10<=>20<=>30<=>null
 * 30<=>20<=>10<=>null
 * 
 * Time: O(n)
 * Space: O(1)
 */