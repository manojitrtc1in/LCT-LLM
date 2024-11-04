import java.util.*;
public class qd2{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int a[][]=new int[n][2];
        for(int i=0;i<n;i++){
            a[i][0]=i;
            a[i][1]=sc.nextInt();
        }
        Arrays.sort(a,(a1,a2)->a2[1]-a1[1]);
        int m=sc.nextInt();
        ArrayList<Pair> query=new ArrayList<>();
        for(int i=0;i<m;i++){
            query.add(new Pair(i,sc.nextInt(),sc.nextInt()));
        }      
        Collections.sort(query,(q1,q2)->q1.a-q2.a);
        id4<Integer,Integer> id1=new id4();
        int j=0;
        for(Pair qu:query){
            while(id1.size()<qu.a){
                id1.put(a[j][0], a[j][1]);
                j++;
            }
            

            

            qu.ans=id1.get(id1.select(qu.b-1));
        }
        Collections.sort(query,(q1,q2)->q1.id-q2.id);
        for(Pair qu:query){
            System.out.println(qu.ans);
        }
    }
}
class Pair{
    int a,b,ans,id;

     Pair(int id,int a,int b){
        this.a=a;
        this.id=id;
        this.b=b;
    }
}






class id4<Key extends Comparable<Key>, Value> {

    private static final boolean RED   = true;
    private static final boolean BLACK = false;

    private Node root;     


    

    private class Node {
        private Key key;           

        private Value val;         

        private Node left, right;  

        private boolean color;     

        private int size;          


        public Node(Key key, Value val, boolean color, int size) {
            this.key = key;
            this.val = val;
            this.color = color;
            this.size = size;
        }
    }

    
    public id4() {
    }

   
    

    private boolean isRed(Node x) {
        if (x == null) return false;
        return x.color == RED;
    }

    

    private int size(Node x) {
        if (x == null) return 0;
        return x.size;
    } 


    
    public int size() {
        return size(root);
    }

   
    public boolean isEmpty() {
        return root == null;
    }


   

    
    public Value get(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to get() is null");
        return get(root, key);
    }

    

    private Value get(Node x, Key key) {
        while (x != null) {
            int cmp = key.compareTo(x.key);
            if      (cmp < 0) x = x.left;
            else if (cmp > 0) x = x.right;
            else              return x.val;
        }
        return null;
    }

    
    public boolean contains(Key key) {
        return get(key) != null;
    }

   

    
    public void put(Key key, Value val) {
        if (key == null) throw new IllegalArgumentException("first argument to put() is null");
        if (val == null) {
            delete(key);
            return;
        }

        root = put(root, key, val);
        root.color = BLACK;
        

    }

    

    private Node put(Node h, Key key, Value val) { 
        if (h == null) return new Node(key, val, RED, 1);

        int cmp = key.compareTo(h.key);
        if      (cmp < 0) h.left  = put(h.left,  key, val); 
        else if (cmp > 0) h.right = put(h.right, key, val); 
        else              h.val   = val;

        

        if (isRed(h.right) && !isRed(h.left))      h = rotateLeft(h);
        if (isRed(h.left)  &&  isRed(h.left.left)) h = rotateRight(h);
        if (isRed(h.left)  &&  isRed(h.right))     flipColors(h);
        h.size = size(h.left) + size(h.right) + 1;

        return h;
    }

   

    
    public void deleteMin() {
        if (isEmpty()) throw new NoSuchElementException("BST underflow");

        

        if (!isRed(root.left) && !isRed(root.right))
            root.color = RED;

        root = deleteMin(root);
        if (!isEmpty()) root.color = BLACK;
        

    }

    

    private Node deleteMin(Node h) { 
        if (h.left == null)
            return null;

        if (!isRed(h.left) && !isRed(h.left.left))
            h = id0(h);

        h.left = deleteMin(h.left);
        return balance(h);
    }


    
    public void deleteMax() {
        if (isEmpty()) throw new NoSuchElementException("BST underflow");

        

        if (!isRed(root.left) && !isRed(root.right))
            root.color = RED;

        root = deleteMax(root);
        if (!isEmpty()) root.color = BLACK;
        

    }

    

    private Node deleteMax(Node h) { 
        if (isRed(h.left))
            h = rotateRight(h);

        if (h.right == null)
            return null;

        if (!isRed(h.right) && !isRed(h.right.left))
            h = id3(h);

        h.right = deleteMax(h.right);

        return balance(h);
    }

    
    public void delete(Key key) { 
        if (key == null) throw new IllegalArgumentException("argument to delete() is null");
        if (!contains(key)) return;

        

        if (!isRed(root.left) && !isRed(root.right))
            root.color = RED;

        root = delete(root, key);
        if (!isEmpty()) root.color = BLACK;
        

    }

    

    private Node delete(Node h, Key key) { 
        


        if (key.compareTo(h.key) < 0)  {
            if (!isRed(h.left) && !isRed(h.left.left))
                h = id0(h);
            h.left = delete(h.left, key);
        }
        else {
            if (isRed(h.left))
                h = rotateRight(h);
            if (key.compareTo(h.key) == 0 && (h.right == null))
                return null;
            if (!isRed(h.right) && !isRed(h.right.left))
                h = id3(h);
            if (key.compareTo(h.key) == 0) {
                Node x = min(h.right);
                h.key = x.key;
                h.val = x.val;
                

                

                h.right = deleteMin(h.right);
            }
            else h.right = delete(h.right, key);
        }
        return balance(h);
    }

   

    

    private Node rotateRight(Node h) {
        

        Node x = h.left;
        h.left = x.right;
        x.right = h;
        x.color = x.right.color;
        x.right.color = RED;
        x.size = h.size;
        h.size = size(h.left) + size(h.right) + 1;
        return x;
    }

    

    private Node rotateLeft(Node h) {
        

        Node x = h.right;
        h.right = x.left;
        x.left = h;
        x.color = x.left.color;
        x.left.color = RED;
        x.size = h.size;
        h.size = size(h.left) + size(h.right) + 1;
        return x;
    }

    

    private void flipColors(Node h) {
        

        

        

        

        h.color = !h.color;
        h.left.color = !h.left.color;
        h.right.color = !h.right.color;
    }

    

    

    private Node id0(Node h) {
        

        


        flipColors(h);
        if (isRed(h.right.left)) { 
            h.right = rotateRight(h.right);
            h = rotateLeft(h);
            flipColors(h);
        }
        return h;
    }

    

    

    private Node id3(Node h) {
        

        

        flipColors(h);
        if (isRed(h.left.left)) { 
            h = rotateRight(h);
            flipColors(h);
        }
        return h;
    }

    

    private Node balance(Node h) {
        


        if (isRed(h.right))                      h = rotateLeft(h);
        if (isRed(h.left) && isRed(h.left.left)) h = rotateRight(h);
        if (isRed(h.left) && isRed(h.right))     flipColors(h);

        h.size = size(h.left) + size(h.right) + 1;
        return h;
    }


   

    
    public int height() {
        return height(root);
    }
    private int height(Node x) {
        if (x == null) return -1;
        return 1 + Math.max(height(x.left), height(x.right));
    }

   

    
    public Key min() {
        if (isEmpty()) throw new NoSuchElementException("calls min() with empty symbol table");
        return min(root).key;
    } 

    

    private Node min(Node x) { 
        

        if (x.left == null) return x; 
        else                return min(x.left); 
    } 

    
    public Key max() {
        if (isEmpty()) throw new NoSuchElementException("calls max() with empty symbol table");
        return max(root).key;
    } 

    

    private Node max(Node x) { 
        

        if (x.right == null) return x; 
        else                 return max(x.right); 
    } 


    
    public Key floor(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to floor() is null");
        if (isEmpty()) throw new NoSuchElementException("calls floor() with empty symbol table");
        Node x = floor(root, key);
        if (x == null) return null;
        else           return x.key;
    }    

    

    private Node floor(Node x, Key key) {
        if (x == null) return null;
        int cmp = key.compareTo(x.key);
        if (cmp == 0) return x;
        if (cmp < 0)  return floor(x.left, key);
        Node t = floor(x.right, key);
        if (t != null) return t; 
        else           return x;
    }

    
    public Key ceiling(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to ceiling() is null");
        if (isEmpty()) throw new NoSuchElementException("calls ceiling() with empty symbol table");
        Node x = ceiling(root, key);
        if (x == null) return null;
        else           return x.key;  
    }

    

    private Node ceiling(Node x, Key key) {  
        if (x == null) return null;
        int cmp = key.compareTo(x.key);
        if (cmp == 0) return x;
        if (cmp > 0)  return ceiling(x.right, key);
        Node t = ceiling(x.left, key);
        if (t != null) return t; 
        else           return x;
    }

    
    public Key select(int k) {
        if (k < 0 || k >= size()) {
            throw new IllegalArgumentException("argument to select() is invalid: " + k);
        }
        Node x = select(root, k);
        return x.key;
    }

    

    private Node select(Node x, int k) {
        

        

        int t = size(x.left); 
        if      (t > k) return select(x.left,  k); 
        else if (t < k) return select(x.right, k-t-1); 
        else            return x; 
    } 

    
    public int rank(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to rank() is null");
        return rank(key, root);
    } 

    

    private int rank(Key key, Node x) {
        if (x == null) return 0; 
        int cmp = key.compareTo(x.key); 
        if      (cmp < 0) return rank(key, x.left); 
        else if (cmp > 0) return 1 + size(x.left) + rank(key, x.right); 
        else              return size(x.left); 
    } 

   

    
    

    

    

    


    
    

    

    


    

    

    

    

    


    

    

    

    

    

    

    

    

    

    


    
    public int size(Key lo, Key hi) {
        if (lo == null) throw new IllegalArgumentException("first argument to size() is null");
        if (hi == null) throw new IllegalArgumentException("second argument to size() is null");

        if (lo.compareTo(hi) > 0) return 0;
        if (contains(hi)) return rank(hi) - rank(lo) + 1;
        else              return rank(hi) - rank(lo);
    }


   
    

    

    

    

    

    

    

    


    

    

    private boolean isBST() {
        return isBST(root, null, null);
    }

    

    

    

    private boolean isBST(Node x, Key min, Key max) {
        if (x == null) return true;
        if (min != null && x.key.compareTo(min) <= 0) return false;
        if (max != null && x.key.compareTo(max) >= 0) return false;
        return isBST(x.left, min, x.key) && isBST(x.right, x.key, max);
    } 

    

    private boolean id2() { return id2(root); }
    private boolean id2(Node x) {
        if (x == null) return true;
        if (x.size != size(x.left) + size(x.right) + 1) return false;
        return id2(x.left) && id2(x.right);
    } 

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    


    

    private boolean isBalanced() { 
        int black = 0;     

        Node x = root;
        while (x != null) {
            if (!isRed(x)) black++;
            x = x.left;
        }
        return isBalanced(root, black);
    }

    

    private boolean isBalanced(Node x, int black) {
        if (x == null) return black == 0;
        if (!isRed(x)) black--;
        return isBalanced(x.left, black) && isBalanced(x.right, black);
    } 


    
    

    

    

    

    

    

    

    

    

    

}