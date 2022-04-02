class Node {
    int key;
    Node left;
    Node right;

    /*
    Uninitialise members of a class are always initialised as NULL
    */
    Node(int k)
    {
        key = k;
    }
}

class basics{
    public static void main(String[] args) {
        Node root =  new Node(10);
        root.left = new Node(20);
        root.right = new Node(30);
        root.left.left = new Node(40);

        // empty tree
        Node root2 = null; 
    }
}