import java.util.HashSet;

/**
 * Given a SLL, the given LL may contain a loop
 * Check if the given LL contains loop or not 
 * 
 * ip:
 * 10 -> 15 -> 12 -> 20
 *       ^           |
 *       |-----------|
 * 
 * op: yes
 * 
 * ip: null
 * op: no
 * 
 * ip: 10->20->null
 * op: no
 * 
 * ip: 
 * 10 -> 20 -> 30
 * ^            |
 * |-------------
 * op: yes 
 * 
 * Naive sol: Travserse the LL from first node,
 * for every node, find next of it
 * store it in a temp var 
 * traverse again from 0 to (i-1)th node 
 * checking if (curr.next == temp)
 * if(yes)
 *  ans = yes
 * 
 * Time: O(n^2)
 * 
 * Eff solution: we break the rules
 * we modify the struct of LL and add an extra field isVisited initialised to false 
 * 
 * Now I traverse the list and if I find any node whose isVisited is already set, I will say there is a loop
 * if(yes)
 *  return yes
 * else
 *  move to next node
 * Time: O(n), but LL struct was modified
 * 
 * Method 3: Create a dummy node temp
 * Traverse the LL, while traversing, change every node's next to dummy node 
 * and if we find a node whose next is already pointing to a dummy node, then there is a loop in LL
 * else continue traversing 
 * 
 * Time: O(n), but destroys the linkage of LL
 * 
 * Method 4: 
 * Works in O(n) time, doesn't modify LL or it's stuct
 * We traverse the LL, whatever node we visited we put it in a HashTable, insertion & search are O(1) operations 
 * But requires O(n) space, damn...
 */


public class detectloop {
    public static void main(String[] args) {
        Node head = new Node(15);
        head.next = new Node(10);
        head.next.next = new Node(12);
        head.next.next.next = new Node(20);
        head.next.next.next.next = head.next;
        /**
         * 15 -> 10 -> 12 -> 20
         *        ^           |
         *        |-----------|
         */

        // Node head = new Node(15);
        // head.next = new Node(10);
        // head.next.next = new Node(12);
        // head.next.next.next = null;
        /**
         * 15->10->12->null
         */

        if(isLoop_method4(head))
            System.out.println("YES");
        else
            System.out.println("NO");
    }

    public static boolean isLoop_method3(Node head)
    {
        Node temp = new Node(-1);
        Node curr = head;

        while (curr != null) {
            // last node
            if (curr.next == null)
                break;

            if (curr.next == temp)
                return true;

            Node currsNext = curr.next;
            curr.next = temp;
            curr = currsNext;
        }

        return false;
    }
    
    public static boolean isLoop_method4(Node head)
    {
        HashSet<Node> s = new HashSet<Node>();
        // in c++, unordered_set<Node*> s;
        
        for(Node curr= head; curr!=null; curr = curr.next)
        {
            // for c++, if(s.find(curr)!=s.end())
            if (s.contains(curr))
                return true;

            // c++: s.insert(curr)
            s.add(curr);
        }
        
        return false;
    }
}
