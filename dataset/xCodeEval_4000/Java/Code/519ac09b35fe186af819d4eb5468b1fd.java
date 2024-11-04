import java.util.*;

public class T4  {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = 1;
        for (int i=0;i<n;i++) {
            mainPrint(s);
        }














    }
    public static void mainPrint(Scanner s){
        int n = s.nextInt();
        int q = s.nextInt();
        int[] nums = new int[n];
        MyRBTree myRBTree = new MyRBTree();
        int max = 1,min = (int) 1e9;
        for(int i=0;i<n;i++){
            nums[i] = s.nextInt();
            max = Math.max(max,nums[i]);
            min = Math.min(min,nums[i]);
            myRBTree.add(nums[i]);
        }
        nums = Arrays.stream(nums).boxed().sorted().mapToInt($->$).toArray();


        TreeMap<Integer, Integer> m = new TreeMap<>();
        for (int i=0;i<n-1;i++) add(nums[i+1]-nums[i],m);
        int peek;
        if(n>=2) {
            peek = m.lastKey();
            System.out.println(max - min - peek);
        }
        else System.out.println(0);


        boolean delete;
        int num;
        int next,last;
        for (int i=0;i<q;i++){
            delete = s.nextInt() == 0;
            num = s.nextInt();
            if(delete){
                n--;
                next = myRBTree.queryNext(num);
                last = myRBTree.queryLast(num);
                myRBTree.delete(num);
                if(next != Integer.MAX_VALUE) remove(next - num,m);
                else if(last != Integer.MIN_VALUE) max = last;
                else max = 1;
                if(last != Integer.MIN_VALUE) remove(num - last,m);
                else if(next != Integer.MAX_VALUE) min = next;
                else min = (int) 1e9;
                if(next != Integer.MAX_VALUE && last != Integer.MIN_VALUE) add(next - last,m);
            }else {
                n++;
                myRBTree.add(num);
                next = myRBTree.queryNext(num);
                last = myRBTree.queryLast(num);
                if(next == Integer.MAX_VALUE ) {
                    max = num;
                    if(last != Integer.MIN_VALUE) add(num - last,m);
                    else min = num;
                }else if (last == Integer.MIN_VALUE){
                    min = num;
                    if(next != Integer.MAX_VALUE) add(next - num,m);
                }else {
                    remove(next - last,m);
                    add(num - last,m);
                    add(next - num,m);
                }
            }
            if(n>=2) {
                peek = m.lastKey();
                System.out.println(max - min - peek);
            }else {
                System.out.println(0);
            }


        }
    }
    public static void add(int val,TreeMap<Integer,Integer> m){
        m.put(val,m.getOrDefault(val,0)+1);
    }
    public static void remove(int val,TreeMap<Integer,Integer> m) {
        int k = m.get(val) - 1;
        if (k == 0)
            m.remove(val);
        else
            m.put(val, k);
    }
}

class MyAVLTree {

    private static class AVLTreeNode{
        int val;
        int height;
        AVLTreeNode left;
        AVLTreeNode right;
        AVLTreeNode parent;

        public AVLTreeNode(int val) {
            this.val = val;
        }

        public AVLTreeNode() {

        }
    }
    AVLTreeNode root;

    public boolean query(int val){
        return queryNode(val)!=null;
    }

    public int queryNext(int val){
        AVLTreeNode node = queryNode(val);
        if(node.right!=null){
            AVLTreeNode next = node.right;
            while (next.left!=null) next = next.left;
            return next.val;
        }else if(node.parent != null){
            AVLTreeNode parent = node.parent;
            AVLTreeNode child = node;
            while (parent.left != child && parent.parent != null){
                child = parent;
                parent = parent.parent;
            }
            if(parent.left == child) return parent.val;
            else return Integer.MAX_VALUE;
        }else {
            return Integer.MAX_VALUE;
        }
    }

    public int queryLast(int val){
        AVLTreeNode node = queryNode(val);
        if(node.left!=null){
            AVLTreeNode next = node.left;
            while (next.right!=null) next = next.right;
            return next.val;
        }else if(node.parent != null ){
            AVLTreeNode parent = node.parent;
            AVLTreeNode child = node;
            while (parent.right != child && parent.parent != null){
                child = parent;
                parent = parent.parent;
            }
            if(parent.right == child) return parent.val;
            else return Integer.MIN_VALUE;
        }else {
            return Integer.MIN_VALUE;
        }
    }

    AVLTreeNode queryNode(int val){
        AVLTreeNode p = root;
        if(p==null) return null;
        while (p.val != val){
            if(p.val>val && p.left!=null){
                p=p.left;
                continue;
            }else if(p.val<val && p.right!=null){
                p=p.right;
                continue;
            }
            return null;
        }
        return p;
    }

    private void lRotate(AVLTreeNode node)  {


        if(node.right==null){
            try {
                throw new Exception("right child of the Node which lRotate can't be null");
            } catch (Exception e) {
                e.printStackTrace();
            }
            return;
        }
        AVLTreeNode nodeNew = node.right;
        AVLTreeNode parent = node.parent;
        AVLTreeNode a1 = node.left;
        AVLTreeNode a2 = nodeNew.left;
        AVLTreeNode a3 = nodeNew.right;
        if(parent==null){
            root = nodeNew;
        } else {
            if(parent.left==node) parent.left=nodeNew;
            else parent.right=nodeNew;
        }
        node.parent = nodeNew;
        node.right = a2;
        nodeNew.left = node;
        nodeNew.parent = parent;
        if(a2!=null){
            a2.parent = node;
        }
        countHeight(node);
        countHeight(nodeNew);
    }

    private boolean countHeight(AVLTreeNode node){
        int oldH = node.height;
        node.height=Math.max(height(node.left),height(node.right))+1;
        return oldH == node.height;
    }

    private void rRotate(AVLTreeNode node){


        if(node.left==null){
            try {
                throw new Exception("left child of the Node which lRotate can't be null");
            } catch (Exception e) {
                e.printStackTrace();
            }
            return;
        }
        AVLTreeNode nodeNew = node.left;
        AVLTreeNode parent = node.parent;
        AVLTreeNode a1 = nodeNew.left;
        AVLTreeNode a2 = nodeNew.right;
        AVLTreeNode a3 = node.right;
        if(parent==null){
            root = nodeNew;
        } else {
            if(parent.left==node) parent.left=nodeNew;
            else parent.right=nodeNew;
        }
        node.parent = nodeNew;
        node.left = a2;
        nodeNew.right = node;
        nodeNew.parent = parent;
        if(a2!=null){
            a2.parent = node;
        }
        countHeight(node);
        countHeight(nodeNew);
    }

    public void add(int val){
        if(root==null) {
            root = new AVLTreeNode(val);
            return;
        }
        AVLTreeNode p = root;
        while ((p.val>val && p.left!=null) || (p.val<val && p.right!=null)){
            if(p.val>val) p = p.left;
            else p = p.right;
        }
        if(p.val>val) {
            p.left = new AVLTreeNode(val);
            p.left.parent = p;
        }else if(p.val<val){
            p.right = new AVLTreeNode(val);
            p.right.parent = p;
        }
        balance(p);
    }

    private void balance(AVLTreeNode p){
        while (p!=null){
            int leftHeight = height(p.left),rightHeight = height(p.right);
            if(leftHeight-rightHeight>1) {
                if(height(p.left.right)-height(p.left.left)==1) {
                    lRotate(p.left);
                }
                rRotate(p);
            }else if(rightHeight - leftHeight>1){
                if(height(p.right.left)-height(p.right.right)==1){
                    rRotate(p.right);
                }
                lRotate(p);
            }
            boolean b = countHeight(p);
            if(b) break;
            p=p.parent;
        }

    }

    private int height(AVLTreeNode node){
        return node==null?-1:node.height;
    }

    public void delete(int val){
        AVLTreeNode node = queryNode(val);
        if (node==null){
            try {
                throw new Exception("the AVLTree don't contain the value");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }else {
            delete(node);
        }
    }

    private void delete(AVLTreeNode node){
        if(node.left==null){
            delete1(node);
        }else if(node.left.right==null){
            delete2(node);
        }else {
            delete3(node);
        }
    }

    private void delete1(AVLTreeNode node){
        AVLTreeNode nodeNew = node.right;
        delete(node,nodeNew);
    }

    private void delete2(AVLTreeNode node){
        AVLTreeNode nodeNew = node.left;
        AVLTreeNode parent = node.parent;
        AVLTreeNode right = node.right;

        nodeNew.parent = parent;
        nodeNew.right = right;
        if(right!=null) right.parent = nodeNew;
        if(parent == null) {
            root = nodeNew;
            nodeNew.parent = null;
        } else {
            if (parent.left == node) {
                parent.left = nodeNew;
            }else {
                parent.right = nodeNew;
            }
        }
        balance(nodeNew);
    }

    private void delete3(AVLTreeNode node){
        AVLTreeNode p = node.left.right;
        while (p.right!=null) p=p.right;
        node.val = p.val;
        delete(p,p.left);
    }

    private void delete(AVLTreeNode node,AVLTreeNode nodeNew){
        AVLTreeNode parent = node.parent;
        if(nodeNew != null) nodeNew.parent = parent;
        if(parent==null) {
            root = nodeNew;
        }
        else {
            if(parent.right == node) parent.right = nodeNew;
            else parent.left = nodeNew;
            balance(parent);
        }
    }

    @Override
    public String toString() {
        if(root==null) return "nullVal";
        if(root.parent!=null) System.out.println("error");
        Queue<AVLTreeNode> q = new LinkedList<>();
        Queue<AVLTreeNode> q1 = new LinkedList<>();
        q.add(root);
        StringBuilder s = new StringBuilder();
        boolean flag;
        do {
            flag = false;
            while (!q.isEmpty()) {
                AVLTreeNode get = q.poll();
                if (get != null && get.parent == null && get != root) System.out.println("error");
                if (get != null) {
                    q1.add(get.left);
                    q1.add(get.right);
                    if(get.left!=null || get.right!=null) flag = true;
                    if((get.left != null && get.left.parent!=get) || (get.right != null && get.right.parent !=get)) System.out.println("error");
                    s.append(" ").append(get.val);
                } else {
                    q1.add(null);
                    q1.add(null);
                    s.append(" null");
                }
            }
            s.append("\n");
            q = q1;
            q1 = new LinkedList<>();
        } while (flag);
        return s.toString();
    }
}

class MyRBTree {

    static class RBTreeNode {
        int val;
        RBTreeNode left;
        RBTreeNode right;
        RBTreeNode parent;
        boolean red = true;

        public RBTreeNode(int val) {
            this.val = val;
        }
    }

    RBTreeNode root;

    public int queryNext(int val){
        RBTreeNode node = queryNode(val);
        if(node.right!=null){
            RBTreeNode next = node.right;
            while (next.left!=null) next = next.left;
            return next.val;
        }else if(node.parent != null){
            RBTreeNode parent = node.parent;
            RBTreeNode child = node;
            while (parent.left != child && parent.parent != null){
                child = parent;
                parent = parent.parent;
            }
            if(parent.left == child) return parent.val;
            else return Integer.MAX_VALUE;
        }else {
            return Integer.MAX_VALUE;
        }
    }

    public int queryLast(int val){
        RBTreeNode node = queryNode(val);
        if(node.left!=null){
            RBTreeNode next = node.left;
            while (next.right!=null) next = next.right;
            return next.val;
        }else if(node.parent != null ){
            RBTreeNode parent = node.parent;
            RBTreeNode child = node;
            while (parent.right != child && parent.parent != null){
                child = parent;
                parent = parent.parent;
            }
            if(parent.right == child) return parent.val;
            else return Integer.MIN_VALUE;
        }else {
            return Integer.MIN_VALUE;
        }
    }

    public boolean query(int val){
        return queryNode(val)!=null;
    }

    RBTreeNode queryNode(int val){
        RBTreeNode p = root;
        if(p==null) return null;
        while (p.val != val){
            if(p.val>val && p.left!=null){
                p=p.left;
                continue;
            }else if(p.val<val && p.right!=null){
                p=p.right;
                continue;
            }
            return null;
        }
        return p;
    }

    public void add(int val) {
        if (query(val)) return;
        if (root == null) {
            root = new RBTreeNode(val);
            root.red = false;
            return;
        }
        RBTreeNode p = root;
        while ((p.val > val && p.left != null) || (p.val < val && p.right != null)) {
            if (p.val > val) p = p.left;
            else p = p.right;
        }
        if (p.val > val) {
            p.left = new RBTreeNode(val);
            p.left.parent = p;
            if(p.red) insertBalance(p.left);
        } else {
            p.right = new RBTreeNode(val);
            p.right.parent = p;
            if(p.red) insertBalance(p.right);
        }
    }

    private void insertBalance(RBTreeNode node){
        RBTreeNode parent = node.parent;
        RBTreeNode grandParent = parent.parent;
        RBTreeNode uncle = grandParent.left == parent ? grandParent.right:grandParent.left;
        if(uncle == null || !uncle.red){
            balance1(node,parent,grandParent,uncle);
        }else {
            balance2(node,parent,grandParent,uncle);
        }
    }

    private void balance1(RBTreeNode node,RBTreeNode parent,RBTreeNode grandParent,RBTreeNode uncle){
        if(node == parent.left && parent == grandParent.left){
            rRotate(grandParent);
            grandParent.red = true;
            parent.red = false;
        }else if(node == parent.right && parent == grandParent.left){
            lRotate(parent);
            rRotate(grandParent);
            grandParent.red = true;
            node.red = false;
        }else if(node == parent.left && parent == grandParent.right){
            rRotate(parent);
            lRotate(grandParent);
            grandParent.red = true;
            node.red = false;
        }else {
            lRotate(grandParent);
            grandParent.red = true;
            parent.red = false;
        }
    }

    private void balance2(RBTreeNode node,RBTreeNode parent,RBTreeNode grandParent,RBTreeNode uncle){
        grandParent.red = true;
        parent.red = false;
        uncle.red = false;
        if(grandParent == root) grandParent.red = false;
        else if(grandParent.parent.red) insertBalance(grandParent);
    }

    private void lRotate(RBTreeNode node){
        if(node.right==null){
            try {
                throw new Exception("right child of the Node which lRotate can't be null");
            } catch (Exception e) {
                e.printStackTrace();
            }
            return;
        }
        RBTreeNode nodeNew = node.right;
        RBTreeNode parent = node.parent;
        RBTreeNode a1 = node.left;
        RBTreeNode a2 = nodeNew.left;
        RBTreeNode a3 = nodeNew.right;
        if(parent==null){
            root = nodeNew;
        } else {
            if(parent.left==node) parent.left=nodeNew;
            else parent.right=nodeNew;
        }
        node.parent = nodeNew;
        node.right = a2;
        nodeNew.left = node;
        nodeNew.parent = parent;
        if(a2!=null){
            a2.parent = node;
        }
    }

    private void rRotate(RBTreeNode node){
        if(node.left==null){
            try {
                throw new Exception("left child of the Node which lRotate can't be null");
            } catch (Exception e) {
                e.printStackTrace();
            }
            return;
        }
        RBTreeNode nodeNew = node.left;
        RBTreeNode parent = node.parent;
        RBTreeNode a1 = nodeNew.left;
        RBTreeNode a2 = nodeNew.right;
        RBTreeNode a3 = node.right;
        if(parent==null){
            root = nodeNew;
        } else {
            if(parent.left==node) parent.left=nodeNew;
            else parent.right=nodeNew;
        }
        node.parent = nodeNew;
        node.left = a2;
        nodeNew.right = node;
        nodeNew.parent = parent;
        if(a2!=null){
            a2.parent = node;
        }
    }

    public void delete(int val){
        RBTreeNode node = queryNode(val);
        if (node==null){
            try {
                throw new Exception("the RBTree don't contain the value");
            } catch (Exception e) {
                e.printStackTrace();
            }
            return;
        }
        if(node.left == null && node.right == null && node.red){
            justDelete(node);
        }else if(node.left == null && node.right == null && !node.red){
            delete1(node);
        }else if(node.left == null){
            delete2(node,node.right);
        }else if(node.right == null){
            delete2(node,node.left);
        }else {
            delete3(node);
        }
    }

    private void justDelete(RBTreeNode node){
        if(node.parent == null) {
            root = null;
            return;
        }
        RBTreeNode parent = node.parent;
        if(parent.left == node) parent.left = null;
        else parent.right = null;
    }

    private void delete1(RBTreeNode node){
        balanceForDelete1(node);
        justDelete(node);
    }

    private void balanceForDelete1(RBTreeNode node){
        RBTreeNode parent = node.parent;
        if(parent == null) {
            return;
        }
        RBTreeNode brother = parent.left == node ? parent.right:parent.left;
        if(!brother.red){
            if((brother.left == null || !brother.left.red) && (brother.right == null || !brother.right.red)){
                if(!parent.red){
                    brother.red = true;
                    balanceForDelete1(parent);
                }
                else {
                    brother.red = true;
                    parent.red = false;
                }
            }
            else {
                if(brother==parent.left && brother.left!=null && brother.left.red){
                    brother.left.red = false;
                    brother.red = parent.red;
                    parent.red = false;
                    rRotate(parent);

                }else if(brother==parent.left && brother.right!=null && brother.right.red) {
                    brother.right.red = false;
                    brother.red =true;
                    lRotate(brother);
                    balanceForDelete1(node);
                }else if(brother==parent.right && brother.right!=null && brother.right.red){
                    brother.right.red = false;
                    brother.red = parent.red;
                    parent.red = false;
                    lRotate(parent);
                }else {
                    brother.left.red =false;
                    brother.red = true;
                    rRotate(brother);
                    balanceForDelete1(node);
                }
            }
        }
        else {
            if(brother == parent.left){
                rRotate(parent);
            }
            else {
                lRotate(parent);

            }
            parent.red = true;
            brother.red = false;
            balanceForDelete1(node);
        }
    }

    private void delete2(RBTreeNode node,RBTreeNode newNode){
        RBTreeNode parent = node.parent;
        if(parent == null){
            root = newNode;
        }else {
            if(parent.left == node) {
                parent.left = newNode;
            }else {
                parent.right = newNode;
            }
        }
        newNode.parent = parent;
        newNode.red = false;
    }

    private void delete3(RBTreeNode node){
        RBTreeNode p = node.left;
        while (p.right != null) p = p.right;
        node.val = p.val;
        if(p.left!=null) delete2(p,p.left);
        else if(p.red) justDelete(p);
        else delete1(p);
    }

    @Override
    public String toString() {
        if(root==null) return "nullVal";
        if(root.parent!=null) System.out.println("error");
        Queue<RBTreeNode> q = new LinkedList<>();
        Queue<RBTreeNode> q1 = new LinkedList<>();
        q.add(root);
        StringBuilder s = new StringBuilder();
        boolean flag;
        do {
            flag = false;
            while (!q.isEmpty()) {
                RBTreeNode get = q.poll();
                if (get != null && get.parent == null && get != root) System.out.println("error");
                if (get != null) {
                    q1.add(get.left);
                    q1.add(get.right);
                    if(get.left!=null || get.right!=null) flag = true;
                    if((get.left != null && get.left.parent!=get) || (get.right != null && get.right.parent !=get)) System.out.println("error");
                    s.append(" ").append(get.val).append(get.red ? "red":"black");
                } else {
                    q1.add(null);
                    q1.add(null);
                    s.append(" null");
                }
            }
            s.append("\n");
            q = q1;
            q1 = new LinkedList<>();
        } while (flag);
        return s.toString();
    }
}


