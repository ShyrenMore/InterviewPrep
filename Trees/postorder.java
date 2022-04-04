import java.util.ArrayList;
import java.util.List;

/**
 * In post-order traversal, process the left-subtree completely and then process the right-subtree completeley and then the root node, this processing happens recursively
 */

public class postorder {

    public static List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();

        helper(root, res);
        return res;
    }

    // helper function for method 1
    private static void helper(TreeNode root, List<Integer> res) {
        if (root != null) {
            if (root.left != null) 
                helper(root.left, res);
            
            if (root.right != null) 
                helper(root.right, res);
            
            res.add(root.data);
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(20);
        root.right = new TreeNode(30);
        root.right.right = new TreeNode(50);
        root.right.left = new TreeNode(40);

        List<Integer> ans = postorderTraversal(root);
        System.out.println(ans);
    }
}

/**
 * op: [20, 40, 50, 30, 10]
 * Time: theta(n)
 * Aux space: theta(h) in function call stack
 */