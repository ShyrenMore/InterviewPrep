/**
 * Go see the prev problem in readme
 * 
 * ip:
 * 10 -> 12 -> 15 -> 20 -> 25
 *       ^                  |
 *       |------------------|
 * 
 * op: yes
 * 
 * Approach: maintain two ptrs from head: slowptr and fastptr
 * 
 * slowptr moves one position at a time
 * fastptr moves two position at a time
 * 
 * Claim:
 * if there is a loop they will meet each other at some point
 * else no loop
 * 
 * see dry run 
 * 
 * Why fastptr is twice the distance, why not 3 times or 4 times? 
 * If you are increasing the value k by 1 and if we want it to reach n always, 
 * we have no option but to increment it by 1
 * if we increment it by two, it will reach n-1 and then n+1
 * 
 * Time: if len of loop is n, and m nodes are before loop
 * O(m+n) = O(len of LL)
 * Space: O(1)
 */

public class floydCycleDetection {
    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(12);
        head.next.next = new Node(15);
        head.next.next.next = new Node(20);
        head.next.next.next.next = new Node(25);
        head.next.next.next.next.next = head.next;
    }

    public static boolean isLoop(Node head)
    {
        Node slowptr = head, fastptr = head;

        while(fastptr!=null && fastptr.next!=null)
        {
            slowptr = slowptr.next;
            fastptr = fastptr.next.next;

            if (slowptr == fastptr)
                return true;
        }
        
        return false;
    }
}
