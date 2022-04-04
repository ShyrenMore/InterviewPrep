
/**
 * Given a binary tree find height of the tree 
 * Height of binary tree is max no of nodes from root to leaf path 
 * 
 * We recursively find height of left-subtree, height of right sub-tree, we take maximum of these two heights and add one to it and return to height
 * base case:
 * if root is null that is we have reached the leaf node then return 0
 */
public class binary_tree_height {

    public static int height(TreeNode root) {
        
        if(root == null)
            return 0;
        
        return 1 + Math.max(height(root.left), height(root.right));
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(8);
        root.right = new TreeNode(30);
        root.right.right = new TreeNode(50);
        root.right.left = new TreeNode(40);

        int ans = height(root);
        System.out.println(ans);
    }
}

/**
 * op: 3
 */