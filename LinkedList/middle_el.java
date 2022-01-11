/**
 * Given a SLL, find middle el
 *
 * odd nodes
 * ip: 10->5->20->15->25
 * op: 20
 * 
 * even nodes
 * ip: 10->5->20->15->25->30
 * op: 15
 * 
 * ip: 10
 * op: 10
 * 
 * ip: NULL
 * op:
 * 
 * ip: 10->20
 * op: 20
 * 
 * Naive sol: first count how many nodes LL has, once we have count, we traverse till count/2th node and print it
 * 
 * requires ~2 passes
 * 
 * Eff sol: 1 traversal
 * we maintain two ptrs: slow and fast
 * slow moves one node at a time
 * fast moves two nodes at a time
 * so when fast reaches end, slow reaches middle
 * 
 * for even no of nodes fast will reach null as end
 * but for odd no of nodes fast will be last node as end
 */

public class middle_el {
    public static void main(String[] args) {
        Node head = new Node(40);
        head.next = new Node(20);
        head.next.next = new Node(30);
        head.next.next.next = new Node(40);

        System.out.println(printMiddle(head));
    }
    
    public static int printMiddle(Node head) {
        if(head==null)
            return -1;
        
        Node slow = head, fast = head;

        while(fast!=null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow.data;
    }
}
