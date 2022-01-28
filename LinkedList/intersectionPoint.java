/**
 * 
 * Given two LL, both of them have some common nodes 
 * there is one node where they intersect after which they have all nodes in common
 * Find intersection point 
 * 
 * ip: 
 * h1 -> 5->8->7-->10->12->15->null
 *                  ^
 *                  |
 *         h2 -> 9 ->
 * 
 * op: 10
 * 
 * Method1:
 * 1) Create an empty hash set
 * 2) Traverse the first list and put all of its nodes in hashset
 * 3) Traverse the second list and look for every node in hashset. As soon as we find a node in Hashset, we return the value of it 
 * 
 * Time: O(m+n)
 * Space: O(m)
 * 
 * Method2:
 * 1) Count nodes in both lists, let counts be c1 and c2
 * 2) Traverse the bigger list, move nodes abs(c1-c2) times
 * 3) Traverse both the lists simultaneously until we see a common node
 * 
 * Time: O(n)
 * Space: O(1)
 */

public class intersectionPoint {
    public static int getIntersection(Node head1, Node head2) {
        Node curr1 = head1, curr2 = head2;
        while(curr1!=null && curr2!=null)
        {
            if (curr1 == curr2)
                return (curr1.data);

            curr1 = curr1.next;
            curr2 = curr2.next;
        }
        
        return -1;
    }
}
