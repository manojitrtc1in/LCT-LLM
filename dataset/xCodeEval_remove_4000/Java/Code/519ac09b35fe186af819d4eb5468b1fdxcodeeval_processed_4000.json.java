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
        id4 id3 = new id4();
        int max = 1,min = (int) 1e9;
        for(int i=0;i<n;i++){
            nums[i] = s.nextInt();
            max = Math.max(max,nums[i]);
            min = Math.min(min,nums[i]);
            id3.add(nums[i]);
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
                next = id3.queryNext(num);
                last = id3.queryLast(num);
                id3.delete(num);
                if(next != Integer.MAX_VALUE) remove(next - num,m);
                else if(last != Integer.MIN_VALUE) max = last;
                else max = 1;
                if(last != Integer.MIN_VALUE) remove(num - last,m);
                else if(next != Integer.MAX_VALUE) min = next;
                else min = (int) 1e9;
                if(next != Integer.MAX_VALUE && last != Integer.MIN_VALUE) add(next - last,m);
            }else {
                n++;
                id3.add(num);
                next = id3.queryNext(num);
                last = id3.queryLast(num);
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

class id1 {

    private static class id2{
        int val;
        int height;
        id2 left;
        id2 right;
        id2 parent;

        public id2(int val) {
            this.val = val;
        }

        public id2() {

        }
    }
    id2 root;

    public boolean query(int val){
        return queryNode(val)!=null;
    }

    public int queryNext(int val){
        id2 node = queryNode(val);
        if(node.right!=null){
            id2 next = node.right;
            while (next.left!=null) next = next.left;
            return next.val;
        }else if(node.parent != null){
            id2 parent = node.parent;
            id2 child = node;
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
        id2 node = queryNode(val);
        if(node.left!=null){
            id2 next = node.left;
            while (next.right!=null) next = next.right;
            return next.val;
        }else if(node.parent != null ){
            id2 parent = node.parent;
            id2 child = node;
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

    id2 queryNode(int val){
        id2 p = root;
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

    private void lRotate(id2 node)  {


        if(node.right==null){
            try {
                throw new Exception("right child of the Node which lRotate can't be null");
            } catch (Exception e) {
                e.printStackTrace();
            }
            return;
        }
        id2 nodeNew = node.right;
        id2 parent = node.parent;
        id2 a1 = node.left;
        id2 a2 = nodeNew.left;
        id2 a3 = nodeNew.right;
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

    private boolean countHeight(id2 node){
        int oldH = node.height;
        node.height=Math.max(height(node.left),height(node.right))+1;
        return oldH == node.height;
    }

    private void rRotate(id2 node){


        if(node.left==null){
            try {
                throw new Exception("left child of the Node which lRotate can't be null");
            } catch (Exception e) {
                e.printStackTrace();
            }
            return;
        }
        id2 nodeNew = node.left;
        id2 parent = node.parent;
        id2 a1 = nodeNew.left;
        id2 a2 = nodeNew.right;
        id2 a3 = node.right;
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
            root = new id2(val);
            return;
        }
        id2 p = root;
        while ((p.val>val && p.left!=null) || (p.val<val && p.right!=null)){
            if(p.val>val) p = p.left;
            else p = p.right;
        }
        if(p.val>val) {
            p.left = new id2(val);
            p.left.parent = p;
        }else if(p.val<val){
            p.right = new id2(val);
            p.right.parent = p;
        }
        balance(p);
    }

    private void balance(id2 p){
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

    private int height(id2 node){
        return node==null?-1:node.height;
    }

    public void delete(int val){
        id2 node = queryNode(val);
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

    private void delete(id2 node){
        if(node.left==null){
            delete1(node);
        }else if(node.left.right==null){
            delete2(node);
        }else {
            delete3(node);
        }
    }

    private void delete1(id2 node){
        id2 nodeNew = node.right;
        delete(node,nodeNew);
    }

    private void delete2(id2 node){
        id2 nodeNew = node.left;
        id2 parent = node.parent;
        id2 right = node.right;

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

    private void delete3(id2 node){
        id2 p = node.left.right;
        while (p.right!=null) p=p.right;
        node.val = p.val;
        delete(p,p.left);
    }

    private void delete(id2 node,id2 nodeNew){
        id2 parent = node.parent;
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
        Queue<id2> q = new LinkedList<>();
        Queue<id2> q1 = new LinkedList<>();
        q.add(root);
        StringBuilder s = new StringBuilder();
        boolean flag;
        do {
            flag = false;
            while (!q.isEmpty()) {
                id2 get = q.poll();
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

class id4 {

    static class id0 {
        int val;
        id0 left;
        id0 right;
        id0 parent;
        boolean red = true;

        public id0(int val) {
            this.val = val;
        }
    }

    id0 root;

    public int queryNext(int val){
        id0 node = queryNode(val);
        if(node.right!=null){
            id0 next = node.right;
            while (next.left!=null) next = next.left;
            return next.val;
        }else if(node.parent != null){
            id0 parent = node.parent;
            id0 child = node;
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
        id0 node = queryNode(val);
        if(node.left!=null){
            id0 next = node.left;
            while (next.right!=null) next = next.right;
            return next.val;
        }else if(node.parent != null ){
            id0 parent = node.parent;
            id0 child = node;
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

    id0 queryNode(int val){
        id0 p = root;
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
            root = new id0(val);
            root.red = false;
            return;
        }
        id0 p = root;
        while ((p.val > val && p.left != null) || (p.val < val && p.right != null)) {
            if (p.val > val) p = p.left;
            else p = p.right;
        }
        if (p.val > val) {
            p.left = new id0(val);
            p.left.parent = p;
            if(p.red) insertBalance(p.left);
        } else {
            p.right = new id0(val);
            p.right.parent = p;
            if(p.red) insertBalance(p.right);
        }
    }

    private void insertBalance(id0 node){
        id0 parent = node.parent;
        id0 grandParent = parent.parent;
        id0 uncle = grandParent.left == parent ? grandParent.right:grandParent.left;
        if(uncle == null || !uncle.red){
            balance1(node,parent,grandParent,uncle);
        }else {
            balance2(node,parent,grandParent,uncle);
        }
    }

    private void balance1(id0 node,id0 parent,id0 grandParent,id0 uncle){
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

    private void balance2(id0 node,id0 parent,id0 grandParent,id0 uncle){
        grandParent.red = true;
        parent.red = false;
        uncle.red = false;
        if(grandParent == root) grandParent.red = false;
        else if(grandParent.parent.red) insertBalance(grandParent);
    }

    private void lRotate(id0 node){
        if(node.right==null){
            try {
                throw new Exception("right child of the Node which lRotate can't be null");
            } catch (Exception e) {
                e.printStackTrace();
            }
            return;
        }
        id0 nodeNew = node.right;
        id0 parent = node.parent;
        id0 a1 = node.left;
        id0 a2 = nodeNew.left;
        id0 a3 = nodeNew.right;
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

    private void rRotate(id0 node){
        if(node.left==null){
            try {
                throw new Exception("left child of the Node which lRotate can't be null");
            } catch (Exception e) {
                e.printStackTrace();
            }
            return;
        }
        id0 nodeNew = node.left;
        id0 parent = node.parent;
        id0 a1 = nodeNew.left;
        id0 a2 = nodeNew.right;
        id0 a3 = node.right;
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
        id0 node = queryNode(val);
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

    private void justDelete(id0 node){
        if(node.parent == null) {
            root = null;
            return;
        }
        id0 parent = node.parent;
        if(parent.left == node) parent.left = null;
        else parent.right = null;
    }

    private void delete1(id0 node){
        id5(node);
        justDelete(node);
    }

    private void id5(id0 node){
        id0 parent = node.parent;
        if(parent == null) {
            return;
        }
        id0 brother = parent.left == node ? parent.right:parent.left;
        if(!brother.red){
            if((brother.left == null || !brother.left.red) && (brother.right == null || !brother.right.red)){
                if(!parent.red){
                    brother.red = true;
                    id5(parent);
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
                    id5(node);
                }else if(brother==parent.right && brother.right!=null && brother.right.red){
                    brother.right.red = false;
                    brother.red = parent.red;
                    parent.red = false;
                    lRotate(parent);
                }else {
                    brother.left.red =false;
                    brother.red = true;
                    rRotate(brother);
                    id5(node);
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
            id5(node);
        }
    }

    private void delete2(id0 node,id0 newNode){
        id0 parent = node.parent;
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

    private void delete3(id0 node){
        id0 p = node.left;
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
        Queue<id0> q = new LinkedList<>();
        Queue<id0> q1 = new LinkedList<>();
        q.add(root);
        StringBuilder s = new StringBuilder();
        boolean flag;
        do {
            flag = false;
            while (!q.isEmpty()) {
                id0 get = q.poll();
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


