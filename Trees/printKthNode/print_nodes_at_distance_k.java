/*
    Given a binary tree and an integer K, 
    print nodes which are at distance K from root

    Sol: 
    we need to print (k+1)th level
    ok, we need to print something, so return type is void
    what about args?
    it should ofc take root and value k
    how do we crack it?
    let's think of some base cases:
    1) if k == 0, print root 
    2) if root is null, do nothing 
    
    the only rem case is k>0
    In this scenario we recursively call left-subtree with val of k reduced by 1 i.e k-1
    similarly we recursively call right-subtree with val of k reduced by 1 i.e k-1

    in term of ordering base case, our first base case must be checking for an empty tree i.e root==null
    if we put k==0 as first base case, we end up accessing null.data in case of empty tree 
*/

public class print_nodes_at_distance_k {
    public static void printKthNode(Node root, int k) {
        if (root == null)
            return;
        
        if(k==0)
            System.out.print(root.key + " ");

        printKthNode(root.left, k-1);
        printKthNode(root.right, k-1);
    }
}

/**
 * Time: O(n)
 * best case: k==0 O(1)
 * worst case: other case
 * 
 * Space:
 * best case: O(1)
 * worst case: O(height)
 */