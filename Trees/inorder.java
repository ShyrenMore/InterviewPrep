import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        data = x;
    }
}

class inorder {

    public static List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();

        helper(root, res);
        return res;
    }

    // helper function for method 1
    private static void helper(TreeNode root, List<Integer> res) {
        if (root != null) {
            if (root.left != null) {
                helper(root.left, res);
            }
            res.add(root.data);
            if (root.right != null) {
                helper(root.right, res);
            }
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(20);
        root.right = new TreeNode(30);
        root.right.right = new TreeNode(50);
        root.right.left = new TreeNode(40);

        List<Integer> ans = inorderTraversal(root);
        System.out.println(ans);
    }

}

/**
 * op: 20 10 40 30 50
 */