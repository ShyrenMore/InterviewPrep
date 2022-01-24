import java.util.ArrayList;

/**
 * Given a SLL, reverse it
 * ip: 10->20->30->40
 * op: 40->30->20->10
 * 
 * Naive: use an aux array, copy contents of LL into the array
 * then we traverse the linked list again, we copy of aux array into LL in reverese order 
 * Time: O(2n) Space: O(n)
 * 
 * Eff: Change the links 
 * we store curr's next in a var nextNode
 * then we point curr's next to prevNode
 * then we set prev and curr for next itr by moving curr and next
 * i.e prev = curr and curr=next
 * 
 * Throughout the process, nextNode is maintained only for keeping track of items ahead of curr node
 * 
 * it would be better if you imagine 3 nodes having names prev, curr and next 
 * 
 * Time: O(n), Space: O(1)
 */
public class reverseSLL {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(30);

        // head = naive_itr(head);
        head = eff_itr(head);
        printList(head);
    }

    public static Node naive_itr(Node head) {
        ArrayList<Integer> arr = new ArrayList<Integer>();

        for (Node curr = head; curr != null; curr = curr.next)
            arr.add(curr.data);

        for (Node curr = head; curr != null; curr = curr.next)
            curr.data = arr.remove(arr.size() - 1);

        return head;
    }

    public static Node eff_itr(Node head) {
        Node curr = head;
        Node prev = null;

        while(curr!=null)
        {
            Node nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
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
 * op
 * 30->20->10->null
 */