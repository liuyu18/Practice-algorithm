//平衡二叉树:它是一 棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树
public class Code_06_IsBalancedTree {
    public static class Node {
		public int value;
		public Node left;
		public Node right;

		public Node(int data) {
			this.value = data;
		}
    }

	public static boolean isBalance(Node head) {
		boolean[] res = new boolean[1];
		res[0] = true;
		getHeight(head, 1, res);
		return res[0];
	}

    public static int getHeight(Node head, int level, boolean[] res) {
        if(head == null){
            return level;
        }
        //每一层也就是每一个棵子树
        int lh = getHeight(head.left, level + 1, res);
        if(!res[0]){
            return level;
        }
        int rh = getHeight(head.right, level + 1, res);
        if(!res[0]){
            return level;
        }
        if(Math.abs(lh - rh) > 1){
            res[0] = false;
        }
        return Math.max(lh,rh);
    }
	public static void main(String[] args) {
		Node head = new Node(1);
		head.left = new Node(2);
		head.right = new Node(3);
		head.left.left = new Node(4);
		head.left.right = new Node(5);
		head.right.left = new Node(6);
		head.right.right = new Node(7);

		System.out.println(isBalance(head));

	}
}