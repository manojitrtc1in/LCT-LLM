import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;


public class TestClass {
	private static InputStream stream;
	private static byte[] buf = new byte[1024];
	private static int curChar;
	private static int numChars;
	private static SpaceCharFilter filter;
	private static PrintWriter pw;
	public static class Node {
		int value;
		int height;
		int nodes;
		Node left,right;
	}
public static class AVLTree {
	int height(Node q){
		if(q==null)
			return 0;
		return q.height;
	}
	int getBalance(Node q){
		if(q==null)
			return 0;
		return height(q.left)-height(q.right);
	}
	int predessor,successor;
	Node RightRotation(Node q){
		Node x = q.left;
		Node y = x.right;
		x.right = q;
		q.left = y;
		q.nodes = q.nodes-(x.nodes+1);
		q.height = Math.max(height(q.left),height(q.right))+1;
		x.height = Math.max(height(x.left), height(x.right))+1;
		return x;
	}
	Node LeftRotation(Node q){
		Node x = q.right;
		Node y = x.left;
		x.left = q;
		q.right = y;
		x.nodes = x.nodes+q.nodes+1;
		q.height = Math.max(height(q.left),height(q.right))+1;
		x.height = Math.max(height(x.left), height(x.right))+1;
		return x;
	}
	Node insert(Node q,int key){
		if(q==null){
			Node p = new Node();
			p.value = key;
			p.left = null;
			p.right = null;
			p.height = 1;
			return p;
		}
		else if(q.value>key){
			q.nodes++;
			successor = q.value;
			q.left = insert(q.left,key);
		}
		else{
			predessor = q.value;
			q.right = insert(q.right,key);
		}
		q.height = Math.max(height(q.left),height(q.right))+1;
		long balance = getBalance(q);
		if(balance>1&&key<q.left.value)
			return RightRotation(q);
		else if(balance>1&&key>q.left.value){
			q.left = LeftRotation(q.left);
			return RightRotation(q);
		}
		else if(balance<-1&&key>q.right.value)
			return LeftRotation(q);
		else if(balance<-1&&key<q.right.value){
			q.right = RightRotation(q.right);
			return LeftRotation(q);
		}
		return q;
	}
	void InOrder(Node root){
		if(root==null)
			return ;
		InOrder(root.left);
		System.out.println(root.value+" "+getBalance(root));
		InOrder(root.right);
	}
	void PreOrder(Node root){
		if(root==null)
			return ;
		System.out.println(root.value+" "+getBalance(root));
		PreOrder(root.left);
		PreOrder(root.right);
	}
	boolean Search(Node root,int key){
		if(root==null)
			return false;
		if(root.value==key)
			return true;
		if(root.value>key)
			return Search(root.left,key);
		else
			return Search(root.right,key);
	}
	Node minValueNode(Node node) {
        Node current = node;
 
        
        while (current.left != null) {
            current = current.left;
        }
 
        return current;
    }
	Node get(Node root,int k){
		if(root.nodes==k)
			return root;
		if(root.nodes>k)
			return get(root.left,k);
		else
			return get(root.right,k-(root.nodes+1));
	}
    Node deleteNode(Node root, int key) {
 
        

        if (root == null) {
            return root;
        }
 
        

        

        if (key < root.value) {
        	root.nodes--;
            root.left = deleteNode(root.left, key);
        } 
 
        

        

        else if (key > root.value) {
            root.right = deleteNode(root.right, key);
        } 
         
        

        

        else {
 
            

            if ((root.left == null) || (root.right == null)) {
                Node temp = null;
                if (temp == root.left) {
                    temp = root.right;
                } else {
                    temp = root.left;
                }
                
                

                if (temp == null) {
                    temp = root;
                    root = null;
                } else 

                {
                    root = temp; 

                }
            } else {
 
                

                

                Node temp = minValueNode(root.right);
 
                

                root.value = temp.value;
 
                

                root.right = deleteNode(root.right, temp.value);
            }
        }
 
        

        if (root == null) {
            return root;
        }
 
        

        root.height = Math.max(height(root.left), height(root.right)) + 1;
 
        

        

        int balance = (int) getBalance(root);
 
        

        

        if (balance > 1 && getBalance(root.left) >= 0) {
            return RightRotation(root);
        }
 
        

        if (balance > 1 && getBalance(root.left) < 0) {
            root.left = LeftRotation(root.left);
            return RightRotation(root);
        }
 
        

        if (balance < -1 && getBalance(root.right) <= 0) {
            return LeftRotation(root);
        }
 
        

        if (balance < -1 && getBalance(root.right) > 0) {
            root.right = RightRotation(root.right);
            return LeftRotation(root);
        }
 
        return root;
    }
}
	public static class SegmentTree{
		int arr[];
		SegmentTree(int a[]){
			arr = new int[(int) (2*Math.pow(2, Math.ceil(Math.log(a.length)/Math.log(2)))-1)];
			Construct(a,0,0,a.length-1);
		}
		public int Construct(int a[],int node,int x,int y){
			if(x==y){
				arr[node] = a[x];
				return arr[node];
			}
			int mid = (x+y)/2;
			return arr[node] = Math.min(Construct(a,2*node+1,x,mid),Construct(a,2*node+2,mid+1,y));
		}
		public int getResult(int node,int x,int y,int p,int q){
			if(y<p||x>q)
				return 10000000;
			else if(p>=x&&q<=y)
				return arr[node];
			int mid = (p+q)/2;
			return Math.min(getResult(2*node+1,x,y,p,mid),getResult(2*node+2,x,y,mid+1,q));
		}
		public void Query(int node,int x,int y,int p,int q,int di){
			if(y<p||x>q)
				return;
			if(p==q){
				arr[node] = di;
				return ;
			}
			int mid = (p+q)/2;
			Query(2*node+1,x,y,p,mid,di);
			Query(2*node+2,x,y,mid+1,q,di);
			arr[node] = Math.min(arr[node*2+1], arr[2*node+2]);
		}
	}
	static int di = 0,gi = 0;
	public static class Heap {
		long arr[][];
		int num;
		Heap(int a){
			arr = new long[a][3];
			num = 0;
		}
		public void swap(long arr[][],int i,int j){
			long t = arr[i][0];
			arr[i][0] = arr[j][0];
			arr[j][0] = t;
			t = arr[i][1];
			arr[i][1] = arr[j][1];
			arr[j][1] = t;
			t = arr[i][2];
			arr[i][2] = arr[j][2];
			arr[j][2] = t;
		}
		public void Minheap(int a){
			while(a>0&&arr[(a-1)/2][0]>arr[a][0]){
				swap(arr,(a-1)/2,a);
				a = (a-1)/2;
			}
		}
		public void Minheapify(int a){
			int largest = a;
			if(2*a+1<num&&arr[largest][0]>arr[2*a+1][0])
				largest = 2*a+1;
			if(2*a+2<num&&arr[largest][0]>arr[2*a+2][0])
				largest = 2*a+2;
			if(largest!=a){
				swap(arr,a,largest);
				Minheapify(largest);
			}
		}
		public void insert(long a,int b,int c){
			arr[num++][0] = a;
			arr[num-1][1] = b;
			arr[num-1][2] = c;
			Minheap(num-1);
		}
		public void deleteAtIndex(int a){
			long pi = arr[a][0];
			di = (int)arr[a][1];
			gi = (int)arr[a][2];
			arr[a][0] = arr[num-1][0];
			arr[a][1] = arr[num-1][1];
			arr[a][2] = arr[num-1][2];
			num--;
			if(arr[a][0]>pi)
				Minheapify(a);
			else
				Minheap(a);
		}
		public long getMin(){
			long pi = arr[0][0];
			di = (int)arr[0][1];
			gi = (int)arr[0][2];
			deleteAtIndex(0);
			return pi;
		}
		public void deleteAtValue(int a){
			for(int i=0;i<num;i++){
				if(arr[i][0]==a){
					deleteAtIndex(i);
					break;
				}
			}
		}
	}
	public static class Queue{
		private class node{
			int val;
			node next;
			node(int a){
				val = a;
				next = null;
			}
		}
		node head,tail;
		Queue(){
			head = null;
			tail = null;
		}
		public void EnQueue(int a){
			if(head==null){
				node p = new node(a);
				head = p;
				tail = p;
			}
			else{
				node p = new node(a);
				tail.next = p;
				tail = p;
			}
		}
		public int DeQueue(){
			int a = head.val;
			head = head.next;
			return a;
		}
		public boolean isEmpty(){
			return head==null;
		}
	}
	public static void Merge(int a[],int p,int r){
        if(p<r){
            int q = (p+r)/2;
            Merge(a,p,q);
            Merge(a,q+1,r);
            Merge_Array(a,p,q,r);
        }
    }
    public static void Merge_Array(int a[],int p,int q,int r){
        int b[] = new int[q-p+1];
        int c[] = new int[r-q];
        for(int i=0;i<b.length;i++)
            b[i] = a[p+i];
        for(int i=0;i<c.length;i++)
            c[i] = a[q+i+1];
        int i = 0,j = 0;
        for(int k=p;k<=r;k++){
            if(i==b.length){
                a[k] = c[j];
                j++;
            }
            else if(j==c.length){
                a[k] = b[i];
                i++;
            }
            else if(b[i]<c[j]){
                a[k] = b[i];
                i++;
            }
            else{
                a[k] = c[j];
                j++;
            }
        }
    }
    public static void Merge(int a[][],int p,int r){
        if(p<r){
            int q = (p+r)/2;
            Merge(a,p,q);
            Merge(a,q+1,r);
            Merge_Array(a,p,q,r);
        }
    }
    public static void Merge_Array(int a[][],int p,int q,int r){
        int b[][] = new int[q-p+1][2];
        int c[][] = new int[r-q][2];
        for(int i=0;i<b.length;i++){
            b[i][0] = a[p+i][0];
            b[i][1] = a[p+i][1];
        }
        for(int i=0;i<c.length;i++){
            c[i][0] = a[q+i+1][0];
            c[i][1] = a[q+i+1][1];
        }
        int i = 0,j = 0;
        for(int k=p;k<=r;k++){
            if(i==b.length){
                a[k][0] = c[j][0];
                a[k][1] = c[j][1];
                j++;
            }
            else if(j==c.length){
                a[k][0] = b[i][0];
                a[k][1] = b[i][1];
                i++;
            }
            else if(b[i][0]<c[j][0]||(b[i][0]==c[j][0]&&b[i][1]<c[j][0])){
                a[k][0] = b[i][0];
                a[k][1] = b[i][1];
                i++;
            }
            else{
                a[k][0] = c[j][0];
                a[k][1] = c[j][1];
                j++;
            }
        }
    }
    public static int pow(int x,int y,long m){
    	if(y==0)
    		return 1;
    	int k = pow(x,y/2,m);
    	if(y%2==0)
    		return (int)((k*(long)k)%m);
    	else
    		return (int)((((k*(long)k)%m)*x)%m);
    }
    static int Inversex = 0,Inversey = 0;
    public static void InverseModulo(int a,int m){
    	if(m==0){
    		Inversex = 1;
    		Inversey = 0;
    	}
    	else{
    		InverseModulo(m,a%m);
    		int temp = Inversex;
    		Inversex = Inversey;
    		Inversey = temp - (a/m)*Inversey;
    	}
    }
    static long mod1 = 1000000007;
    static long mod2 = 1000000009;
	public static long gcd(long a,long b){
		if(a%b==0)
			return b;
		return gcd(b,a%b);
	}
	public static boolean isPrime(long a){
		if(a==1)
			return false;
		else if(a==2||a==3)
			return true;
		for(long i=2;i<=Math.sqrt(a);i++)
			if(a%i==0)
				return true;
		return false;
	}
	public static double distance(int a,int b,int x,int y){
		return Math.sqrt(((long)(a-x)*(long)(a-x))+((long)(b-y)*(long)(b-y)));
	}
	private static void soln() {
		int n = nextInt();
		int a = nextInt();
		int k = nextInt();
		int p = nextInt();
		AVLTree h = new AVLTree();
		int i = 0;
		Node root = null;
		root = h.insert(root, 0);
		root = h.insert(root, n+1);
		int count = (n+1)/(k+1);
		for(i=0;i<p;i++){
			int nm = nextInt();
			root = h.insert(root,nm);
			count-=(h.successor-(h.predessor))/(k+1);
			count+=(nm-(h.predessor))/(k+1)+(h.successor-(nm))/(k+1);
			if(count<a){
				pw.println(i+1);
				return ;
			}
		}
		pw.println("-1");
	}
	public static void main(String[] args) {
		InputReader(System.in);
		pw = new PrintWriter(System.out);
		soln();
		pw.close();
	}

	

	


	public static void InputReader(InputStream stream1) {
		stream = stream1;
	}

	private static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private static boolean isEndOfLine(int c) {
		return c == '\n' || c == '\r' || c == -1;
	}

	private static int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	private static int nextInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	private static long nextLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	private static String nextToken() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	private static String nextLine() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isEndOfLine(c));
		return res.toString();
	}

	private static int[] nextIntArray(int n) {
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextInt();
		}
		return arr;
	}

	private static long[] nextLongArray(int n) {
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextLong();
		}
		return arr;
	}

	private static void pArray(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		return;
	}

	private static void pArray(long[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		return;
	}

	private static boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	private interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}

}