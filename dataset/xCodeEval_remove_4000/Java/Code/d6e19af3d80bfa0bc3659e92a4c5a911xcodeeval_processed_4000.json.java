
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;
 
public class SuffixArray {
    private static InputStream stream;
    private static byte[] buf = new byte[1024];
    private static int curChar;
    private static int numChars;
    private static id5 filter;
    private static PrintWriter pw;
    private static long max = Long.MIN_VALUE;
    private static int mod = 1000000000+7;
    private static long mod1=(long) Math.pow(2,63);
    
    private static void soln() {
    	int n=nextInt();
    	int[] arr=id2(n);
    	Segment tree=new Segment(arr,n);
    	int m=nextInt();
    	while(m-->0){
    		int x=nextInt();
    		if(x==1){
    			int l=nextInt()-1;
    			int r=nextInt()-1;
    			pw.println(tree.query(l, r));
    		}else{
    			int l=nextInt()-1;
    			int r=nextInt()-1;
    			int xor=nextInt();
    			tree.update(l,r, xor, 0, 0, n-1);
    		}
    	}
    }
    public static class Segment {
        private int[][] tree;
        private int[] lazy;
        private int size;
        private int n;
        private int[] arr;
        private class node{
            private int a;
            private int b;
            private int c;
            public node(int x,int y,int z){
                a=x;
                b=y;
                c=z;
            }
        }
        public Segment(int[] arr,int n){
            

            int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
            size = 2 * (int) Math.pow(2, x) - 1;
            tree=new int[size][21];
            lazy=new int[size];
            this.n=n;
            this.arr=arr;
            build(0,0,n-1);
        }
        private void build(int id,int l,int r){
            

            if(r==l){
            	int tmp=arr[l];
            	for(int i=0;i<21;i++){
            		tree[id][i]=tmp%2;
            		

            		tmp=tmp/2;
            	}
            	

                return;
            }
            int mid=l+(r-l)/2;
            

            build(2*id+1,l,mid);
            

            build(2*id+2,mid+1,r);
            for(int i=0;i<21;i++){
            	tree[id][i]=tree[2*id+1][i]+tree[2*id+2][i];
            }
        }
        public long query(int l,int r){
            return queryUtil(l,r,0,0,n-1);
        }
        private long queryUtil(int x,int y,int id,int l,int r){
            if(l>y || x>r)
                return 0;
            if(x <= l && r<=y){
            	long sum=0;
            	long sum1=1;
            	for(int i=0;i<21;i++){
            		sum+=((long)tree[id][i])*sum1;
            		sum1*=2;
            	}
                return sum;
            }
            int mid=l+(r-l)/2;
            shift(id,l,mid,r);
            return queryUtil(x,y,2*id+1,l,mid)+queryUtil(x,y,2*id+2,mid+1,r);
        }
        
        public void update(int x,int y,int xor,int id,int l,int r){
            if(x>r || l>y)
                return;
            if(x<=l && r<=y){
            	lazy[id]=lazy[id]^xor;
            	for(int i=0;i<21;i++){
            		if(xor%2!=0){
            			tree[id][i]=r-l+1-tree[id][i];
            		}
            		xor/=2;
            	}
                return;
            }
            int mid=l+(r-l)/2;
            

            shift(id,l,mid,r);
            update(x,y,xor,2*id+1,l,mid);
            update(x,y,xor,2*id+2,mid+1,r);
            for(int i=0;i<21;i++)
            	tree[id][i]=tree[2*id+1][i]+tree[2*id+2][i];
        }
        private void shift(int id,int l,int mid,int r){
            if(lazy[id]!=0){
            	int xor=lazy[id];
            	lazy[2*id+1]^=lazy[id];
                lazy[2*id+2]^=lazy[id];
            	for(int i=0;i<21;i++){
            		if(xor%2!=0){
            			tree[2*id+1][i]=mid-l+1-tree[2*id+1][i];
            			tree[2*id+2][i]=r-mid-tree[2*id+2][i];
            		}
            		xor/=2;
            	}
            }
            lazy[id]=0;
        }
    }
    public static int fun(Node root,int xor){
    	Node tmp=root;
    	int temp=xor;
    	int[] arr=new int[28];
    	for(int i=0;i<=27;i++){
    		arr[i]=temp%2;
    		temp=temp/2;
    	}
    	for(int i=27;i>=0;i--){
    		int val= arr[i];
    		if(tmp.arr[1-val]!=null)
    			tmp=tmp.arr[1-val];
    		else if(tmp.arr[val]!=null)
    			tmp=tmp.arr[val];
    	}
    	return xor^(tmp.val);
    }
    public static void insert(Node root,int xor){
    	Node temp=root;
    	int tmp=xor;
    	int[] arr=new int[28];
    	for(int i=0;i<=27;i++){
    		arr[i]=tmp%2;
    		tmp=tmp/2;
    	}
    	for(int i=27;i>=0;i--){
    		int val= arr[i];
    		if(temp.arr[val]==null){
    			temp.arr[val]=new Node();
    		}
    		temp=temp.arr[val];
    	}
    	temp.val=xor;
    }
    public static class Node{
    	int val;
    	Node[] arr;
    	public Node(){
    		arr=new Node[2];
    		val=0;
    		arr[1]=null;
    		arr[0]=null;
    	}
    }
	public static boolean isPrime(int n) {
		

		if (n <= 1)
			return false;
		if (n <= 3)
			return true;
 
		

		

		if (n % 2 == 0 || n % 3 == 0)
			return false;
 
		for (int i = 5; i * i <= n; i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;
 
		return true;
	}
	public static long id1(LinkedList<Pair>[] l,LinkedList<Pair>[] l1,int n){
    	long ans=0;
    	PriorityQueue<Pair> q = new PriorityQueue<>();
    	long[] arr=new long[n];
    	Arrays.fill(arr,Long.MAX_VALUE);
   	 	arr[0]=0;
   	 	q.add(new Pair(0, 0));
   	 	while(!q.isEmpty()){
   			Pair p = q.poll();
   			for(Pair x:l[p.x]){
   				if(arr[x.x]>(arr[p.x]+x.w)){
   					arr[x.x] = (arr[p.x]+x.w);
   					q.add(new Pair(x.x,arr[x.x]));
	   			}
	   		}
	   	}
   	 	boolean[] visited=new boolean[n];
	   	visited[0] = true;
	   	PriorityQueue<Integer> q1=new PriorityQueue();
		q1.add(0);
		while(!q1.isEmpty()){
		int y = q1.poll();
			for(Pair g:l1[y]){
				if(!visited[g.x]){
					ans+=Math.max(0, Math.min(arr[y]+g.w-arr[g.x],arr[g.x]+g.w-arr[y]));
					visited[g.x] = true;
					q1.add(g.x);
				}else{
					ans+=Math.max(0, Math.min(arr[y]+g.w-arr[g.x],arr[g.x]+g.w-arr[y]));
				}
			}
		}
		

		return ans;
   	}
    private static class Pair implements Comparable<Pair>{
    	int x;
    	long w;
    	public Pair(int a,long b){
    		x=a;
    		w=b;
    	}
		@Override
		public int compareTo(Pair arg0) {
			return (int) (this.w-arg0.w);
		}
    }
    private static void DFS(int cur,int prev,boolean[] visited,LinkedList<Integer>[] l){
    	Iterator<Integer> i=l[cur].listIterator();
    	visited[cur]=true;
    	while(i.hasNext()){
    		int x=i.next();
    		if(!visited[x] && x!=prev){
    			DFS(x,cur,visited,l);
    		}
    	}
    }
	private static long mat_power(long n){
		long[][] matrix={{1,1},{1,0}};
		long[][] temp={{1,0},{0,1}};
		while(n!=0){
			if(n%2!=0){
				id4(temp,matrix);
			}
			id4(matrix,matrix);
			n>>=1;
		}
		return temp[0][1];
	}
	private static void id4(long[][] a,long[][] b){
		long[][] result=new long[2][2];
		for(int i = 0 ; i < 2 ; i ++)
	        for(int j = 0 ; j < 2 ; j++)
	            for(int k = 0 ; k < 2 ; k++)
	                result[i][j] = (result[i][j] + a[i][k]*b[k][j]) % mod;
	    for(int i = 0 ; i < 2 ; i++)
	        for(int j = 0 ; j < 2 ; j++)
	            a[i][j] = result[i][j];
	}
    private static long power(long x,long y,long mod){
    	long ans = 1;
		while(y>0){
			if(y%2==1){
			    if(ans>mod/x) return -1;
				ans*=x;
				y-=1;
			}
			else{
			    if(x>mod/x) return -1;
				x*=x;
				y/=2;
			}
		}
		return ans;
    }
    public static class Suffix implements Comparable<Suffix>{
        int index;
        int[] rank=new int[2];
        @Override
        public int compareTo(Suffix arg0){
            return (this.rank[0]==arg0.rank[0])?(this.rank[1]<arg0.rank[1]?-1:1):(this.rank[0]<arg0.rank[0]?-1:1);
        }   
    }
    private static int[] buildSuffix(String s,int n){
        Suffix[] arr=new Suffix[n];
        for(int i=0;i<n;i++)
            arr[i]=new Suffix();
        for(int i=0;i<n;i++){
            arr[i].index=i;
            arr[i].rank[0]=s.charAt(i)-'a';
            arr[i].rank[1]=((i+1)<n)?(s.charAt(i+1)-'a'):-1;
        }
        Arrays.sort(arr);
        

            

        int[] ind=new int[n];
        for(int k=4;k<2*n;k=k*2){
            int rank=0;
            int p_rank=arr[0].rank[0];
            arr[0].rank[0]=rank;
            ind[arr[0].index]=0;
            for(int i=1;i<n;i++){
                if (arr[i].rank[0] == p_rank && arr[i].rank[1] == arr[i-1].rank[1]) {
                    p_rank = arr[i].rank[0];
                    arr[i].rank[0] = rank;
                }
                else{
                    p_rank = arr[i].rank[0];
                    arr[i].rank[0] = ++rank;
                }
                ind[arr[i].index] = i;
            }
            for(int i=0;i<n;i++){
                int n_index=arr[i].index + k/2;
                arr[i].rank[1]=(n_index<n)?arr[ind[n_index]].rank[0] : -1;
            }
            Arrays.sort(arr);
        }
        int[] suffixArr=new int[n];
        for(int i=0;i<n;i++)
            suffixArr[i]=arr[i].index;
        return suffixArr;
    }
    private static long pow(long a, long b) {
        if (b == 0)
            return 1;
        long p = pow(a, b / 2);
        p = (p * p);
        return (b % 2 == 0) ? p : (a * p);
    }
    private static long gcd(long x, long y) {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
 
    private static long max(long a, long b) {
        if (a > b)
            return a;
        return b;
    }
 
    private static long min(long a, long b) {
        if (a < b)
            return a;
        return b;
    }
 
    public static void main(String[] args) throws Exception {
    	new Thread(null, new Runnable() {
			public void run() {
				try {
					InputReader(System.in);
			        pw = new PrintWriter(System.out);
			        soln();
			        pw.close();
					soln();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}, "1", 1 << 26).start();
    }
 
    public static void InputReader(InputStream stream1) {
        stream = stream1;
    }
 
    private static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
 
    private static boolean id3(int c) {
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
        while (id0(c))
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
        } while (!id0(c));
        return res * sgn;
    }
 
    private static long nextLong() {
        int c = read();
        while (id0(c))
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
        } while (!id0(c));
        return res * sgn;
    }
 
    private static String nextToken() {
        int c = read();
        while (id0(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!id0(c));
        return res.toString();
    }
 
    private static String nextLine() {
        int c = read();
        while (id0(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!id3(c));
        return res.toString();
    }
 
    private static int[] id2(int n) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nextInt();
        }
        return arr;
    }
 
    private static long[] id6(int n) {
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
 
    private static boolean id0(int c) {
        if (filter != null)
            return filter.id0(c);
        return isWhitespace(c);
    }
 
    private interface id5 {
        public boolean id0(int ch);
    }
}
