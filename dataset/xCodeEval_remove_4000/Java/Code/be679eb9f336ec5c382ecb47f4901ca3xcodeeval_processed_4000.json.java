import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.ObjectInputStream.GetField;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;
 
public class first {
	static long MOD = 1000000007;
	static boolean b[],bc[];
	static boolean boo[][][];
	static ArrayList<Integer>[] amp,amp1;
	static int sum[],dist[];
	static long ans = 0;
	static int p = 0;
	

	static id7 sc = new id7();
	static Queue<Integer> q = new LinkedList<>();
	static int arr[];
	static PriorityQueue<Integer> pq;
	

	static LinkedList<Integer> fa;
	static BufferedWriter log;
	static HashMap<Long,Long> hm;
	static HashSet<Integer> hs = new HashSet<>();
	static Stack<Integer> stack = new Stack<>();
	static Pair prr[];
	static long parent1[],parent2[],size[][],size1[],size2[];
	public static void main(String[] args) throws IOException {
		log = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = sc.nextInt();
		amp = (ArrayList<Integer>[]) new ArrayList[n];
		for(int i = 0; i< n; i++) amp[i]=  new ArrayList<>();
		buildGraph(n-1);
		arr = sc.id3(n);
		HashSet<Pair> hs = new HashSet<>();
		for(int i =0;i<amp.length;i++){
			

			for(int e: amp[i]){
				if(arr[i]!=arr[e]){
					hs.add(new Pair(i,e));
				}
			}
		}
		boolean b = true;
		if(hs.size()==0){
			System.out.println("YES\n"+1);
			
			System.exit(0);
		}
		int x = 0,y = 0, cnt1 = 0, cnt2 = 0;
		for(Pair p:hs){
			if(b){
				x = p.u; y = p.v;
				b = false;
				break;
			}
		}
		for(Pair p:hs){
			if(p.u==x) cnt1++;
			if(p.v==y) cnt2++;
		}
		

		

		if(cnt1==hs.size()/2) System.out.println("YES\n"+(x+1));
		else if(cnt2==hs.size()/2) System.out.println("YES\n"+(y+1));
		else System.out.println("NO");
		log.close();
	}
	static long func(long n, long d, long t){
		return (t*(2*(n-1)+(t-1)*(d)))/2;
	}
	static class Pair implements Comparable<Pair> {
		int u;
		int v;
		public Pair(int u, int v) {
			this.u = u;
			this.v = v;
		}
		
		public int hashCode() {
			int hu = (int) (u ^ (u >>> 32));
			int hv = (int) (v ^ (v >>> 32));
			return 31*hu + hv;
		}
 
		public boolean equals(Object o) {
			Pair other = (Pair) o;
			return (u == other.u && v == other.v);
		}
 
		public int compareTo(Pair other) {
			return Integer.compare(u, other.u) != 0 ? (Integer.compare(u, other.u)) : (Integer.compare(v, other.v));
		}
		
		public String toString() {
			return "[u=" + u + ", v=" + v + "]";
		}
	}
	static class Pair2 implements Comparable<Pair> {
		int u;
		Pair v;
		public  Pair2(Pair v,int u) {
			this.u = u;
			this.v = v;
		}
		public boolean equals(Object o) {
			Pair2 other = (Pair2) o;
			return (u == other.u && v.equals(other.v));
		}
		public int compareTo(Pair2 other){
			return v.compareTo(other.v);
		}
		public String toString() {
			return "[u=" + u + ", v=" + v + "]";
		}
		@Override
		public int compareTo(Pair other) {
			return Integer.compare(u, other.u) != 0 ? (Integer.compare(u, other.u)):1;
		}
	}
	public static void buildGraph(int n){
		for(int i =0;i<n;i++){
			int x = sc.nextInt(), y = sc.nextInt();
			amp[--x].add(--y);
			amp[y].add(x);
		}
	}
	public static void dfs(){
		fa = new LinkedList<>();
		while(!pq.isEmpty()){
			int y = pq.poll();
			fa.add(y);
			for(int i = 0; i<amp[y].size();i++){
				
				int c = amp[y].get(i);
				if(bc[c]){
				--size1[c];
				if(size1[c]==0) pq.add(c);
				}
			}
		}
	}
	
	public static long getParent(long x, long parent[]){
		while(parent[(int) x]!=x){
			parent[(int) x] = parent[(int) parent[(int) x]];
			x = parent[(int) x];
		}
		return x;
	}
	static long min(long a, long b, long c){
		if(a<b && a<c) return a;
		if(b<c) return b;
		return c;
	}
	
	static int sum(int n){
		String str = Integer.toString(n);
		int cnt = 0;
		for(int i = 0; i< str.length();i++){
			cnt+=(str.charAt(i)-'0');
		}
		return cnt;
	}
	 static void id9(String pat, String txt)
	    {
	        int M = pat.length();
	        int N = txt.length();
	 
	        

	        

	        int lps[] = new int[M];
	        int j = 0;  

	 
	        

	        

	        id0(pat,M,lps);
	 
	        int i = 0;  

	        while (i < N)
	        {
	            if (pat.charAt(j) == txt.charAt(i))
	            {
	                j++;
	                i++;
	            }
	            if (j == M)
	            {
	               

	                j = lps[j-1];
	            }
	 
	            

	            else if (i < N && pat.charAt(j) != txt.charAt(i))
	            {
	                

	                

	                if (j != 0)
	                    j = lps[j-1];
	                else
	                    i = i+1;
	            }
	        }
	    }
	 static void id0(String pat, int M, int lps[])
	    {
	        

	        int len = 0;
	        int i = 1;
	        lps[0] = 0;  

	 
	        

	        while (i < M)
	        {
	            if (pat.charAt(i) == pat.charAt(len))
	            {
	                len++;
	                lps[i] = len;
	                i++;
	            }
	            else  

	            {
	                

	                

	                

	                if (len != 0)
	                {
	                    len = lps[len-1];
	 
	                    

	                    

	                }
	                else  

	                {
	                    lps[i] = len;
	                    i++;
	                }
	            }
	        }
	    }
	private static void permutation(String prefix, String str) {
	    int n = str.length();
	    if (n == 0); 

	    else {
	        for (int i = 0; i < n; i++)
	            permutation(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n));
	    }
	}
	public static char give(char c1,char c2){
		if(c1!='a' && c2!='a') return 'a';
		if(c1!='b' && c2!='b') return 'b';
		return 'c';
	}
	static class Graph{
		int vertex;
		long weight;
	}
	public static void buildTree(int n){
		int arr[] = sc.id3(n);
		for(int i = 0;i<n;i++){
			int x = arr[i]-1;
			amp[i+1].add(x);
			amp[x].add(i+1);
		}
	}
	
	
		
	
	
	
	static class SegmentTree{
		int st[];
		int cnt = 1;
		SegmentTree(int n){
			int size = 4*n;
			st = new int[size];
			

		}
		void update(int si, int ss, int se, int idx, int val){
			if(ss==se){
				st[si]+=val;
			}
			else{
				int mid = (ss+se)/2;
				if(ss<=idx && idx<=mid){
					update(si*2, ss, mid, idx, val);
				}
				else update(si*2+1, mid+1, se, idx, val);
				st[si] = st[si*2]+st[si*2+1];
			}
		}
		
		
		int getSum(int qs, int qe, int ss, int se, int si){
			if(qe<ss || qs>se){
				return 0;
			}
			if(qs<=ss && qe>=se) return st[si];
			int mid = (ss+se)/2;
            return getSum(qs,qe,ss,mid,2*si) + getSum(qs,qe, mid+1, se, 2*si+1);
		}
		void print(){
			for(int i = 0;i<st.length;i++){
				System.out.print(st[i]);
				

			}
			System.out.println();
		}
	}
	static int convert(int x){
		int cnt = 0;
		String str = Integer.toBinaryString(x);
		

		for(int i = 0;i<str.length();i++){
			if(str.charAt(i)=='1'){
				cnt++;
			}
		}
		int ans = (int) Math.pow(3, 6-cnt);
		return ans;
	}
	static class Node2{
		Node2 left = null;
		Node2 right = null;
		Node2 parent = null;
		int data;
	}
	static class id2{
		Node2 root = null;
		int height = 0;
		int max = 0;
		int cnt = 1;
		ArrayList<Integer> parent = new ArrayList<>();
		HashMap<Integer, Integer> hm = new HashMap<>();
		public void insert(int x){
			Node2 n = new Node2();
			n.data = x;
			if(root==null){
				root = n;
			}
			else{
				Node2 temp = root,temp2 = null;
				while(temp!=null){
					temp2 = temp;
					if(x>temp.data) temp = temp.right;
					else temp = temp.left;
				}
				if(x>temp2.data) temp2.right = n;
				else temp2.left = n;
				n.parent = temp2;
				parent.add(temp2.data);
			}
		}
		public Node2 getSomething(int x, int y, Node2 n){
			if(n.data==x || n.data==y) return n;
			else if(n.data>x && n.data<y) return n;
			else if(n.data<x && n.data<y) return getSomething(x,y,n.right);
			else return getSomething(x,y,n.left);
		}
		public Node2 search(int x,Node2 n){
			if(x==n.data){
				max = Math.max(max, n.data);
				return n;
			}
			if(x>n.data){
				max = Math.max(max, n.data);
				return search(x,n.right);
			}
			else{
				max = Math.max(max, n.data);
				return search(x,n.left);
			}
		}
		public int getHeight(Node2 n){
			if(n==null) return 0;
			height = 1+ Math.max(getHeight(n.left), getHeight(n.right));
			return height;
		}
	}
	static long findDiff(long[] arr, long[] brr, int m){
		int i = 0, j = 0;
		long fa = 1000000000000L;
		while(i<m && j<m){
			long x = arr[i]-brr[j];
			if(x>=0){
				if(x<fa) fa = x;
				j++;
			}
			else{
				if((-x)<fa) fa = -x;
				i++;
			}
		}
		return fa;
	}
	public static long max(long x, long y, long z){
		if(x>=y && x>=z) return x;
		if(y>=x && y>=z) return y;
		return z;
	}
	
	public static void seive(long n){
		b = new boolean[(int) (n+1)];
		Arrays.fill(b, true);
		for(int i = 2;i*i<=n;i++){
			if(b[i]){
				for(int p = 2*i;p<=n;p+=i){
					b[p] = false;
				}
			}
		}
	}
	static long modInverse(long a, long id5){
	            return  power(a, id5-2, id5);
	}
	static long power(long x, long y, long m)
	{
	    if (y == 0)
	        return 1;
	    long p = power(x, y/2, m) % m;
	    p = (p * p) % m;
	 
	    return (y%2 == 0)? p : (x * p) % m;
	}
	static long power2(long x,BigInteger y,long m){
		long ans = 1;
		BigInteger two = new BigInteger("2");
		while(y.compareTo(BigInteger.ZERO)>0){
			if(y.getLowestSetBit()==y.bitCount()){
				x = (x*x)%MOD;
				y = y.divide(two);
			}
			else{
				ans = (ans*x)%MOD;
				y = y.subtract(BigInteger.ONE);
			}
		}
		return ans;
	}
	static BigInteger power2(BigInteger x, BigInteger y, BigInteger m){
		BigInteger ans = new BigInteger("1");
		BigInteger one  = new BigInteger("1");
		BigInteger two  = new BigInteger("2");
		BigInteger zero  = new BigInteger("0");
		while(y.compareTo(zero)>0){
			

			if(y.mod(two).equals(one)){
				ans = ans.multiply(x).mod(m);
				y = y.subtract(one);
			}
			else{
				x = x.multiply(x).mod(m);
				y = y.divide(two);
			}
		}
		return ans;
	}
	static BigInteger power(BigInteger x, BigInteger y, BigInteger m)
	{
	    if (y.equals(0))
	        return (new BigInteger("1"));
	    BigInteger p = power(x, y.divide(new BigInteger("2")), m).mod(m);
	    p = (p.multiply(p)).mod(m);
	 
	    return (y.mod(new BigInteger("2")).equals(0))? p : (p.multiply(x)).mod(m);
	}
	static long d,x,y;
	public static void id4(long a, long b){
		if(b == 0) {
	        d = a;
	        x = 1;
	        y = 0;
	    }
	    else {
	        id4(b, a%b);
	        int temp = (int) x;
	        x = y;
	        y = temp - (a/b)*y;
	    }
	}
	
	public static long gcd(long n, long m){
		if(m!=0) return gcd(m,n%m);
		else return n;
	}
	
	
	public static class id7 {
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
 
		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = System.in.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}
 
		public String nextLine() {
			int c = read();
			while (id1(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id6(c));
			return res.toString();
		}
 
		public String nextString() {
			int c = read();
			while (id1(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id1(c));
			return res.toString();
		}
 
		public long nextLong() {
			int c = read();
			while (id1(c))
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
			} while (!id1(c));
			return res * sgn;
		}
 
		public int nextInt() {
			int c = read();
			while (id1(c))
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
			} while (!id1(c));
			return res * sgn;
		}
	        
	    public int[] id3(int n) {
	        return id3(n, 0);
	    }
	    
	    public int[] id3(int n, int off) {
	    	int[] arr = new int[n + off];
	    	for (int i = 0; i < n; i++) {
	    		arr[i + off] = nextInt();
	    	}
	    	return arr;
	    }
	    
	    public long[] id8(int n) {
	    	return id8(n, 0);
	    }
        
		public long[] id8(int n, int off) {
		    long[] arr = new long[n + off];
		    for (int i = 0; i < n; i++) {
		        arr[i + off] = nextLong();
		    }
		    return arr;
		}
 
	    private boolean id1(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
 
		private boolean id6(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
	}
}