import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.ObjectInputStream.GetField;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;


	public class Q1 {
		
		static long MOD = 1000000009;
		static boolean b[], b1[], check;
		static ArrayList<Integer>[] amp, pa;
		static ArrayList<Graph>[] amp1;
		static int left[],s[],right[],sum[],dist[],cnt[],start[],color[],parent[],prime[],size[];
		static long ans = 0,k;
		static int p = 0;
		static id9 sc = new id9(System.in);
		static Queue<Pair> queue = new LinkedList<>();
		static PriorityQueue<Integer> pq;
		static BufferedWriter log;
		static HashSet<Integer>[] hs;
		static HashMap<String,Integer> hm;
		static HashMap<Pair,Integer> hmp;
		static Stack<Integer> st;
		static Pair prr[];
		static long parent1[],parent2[],size1[],size2[],arr1[],SUM[],MAX[];
		static int arr[];
		public static void main(String[] args) throws Exception {
	    	new Thread(null, new Runnable() {
				public void run() {
					try {
						soln();
					} catch (Exception e) {
						System.out.println(e);
					}
				}
			}, "1", 1 << 26).start();
		}
		static long dp[];
		static int n;
		public static void soln() throws IOException {
			

			

			log = new BufferedWriter(new OutputStreamWriter(System.out));
			int n = sc.nextInt(), k = sc.nextInt(), l = sc.nextInt(), r = sc.nextInt(), sa = sc.nextInt(), sk = sc.nextInt();
			if(n==k){
				int a1 = sa/n;
				int a2 = sa%n;
				for(int i = 0; i< n-a2;i++) System.out.print(a1+" ");
				for(int i = n-a2;i<n;i++) System.out.print(a1+1+" ");
				return;
			}
			int v = (sa-sk)/(n-k);
			int v1 = (sa-sk)%(n-k);
			int w = sk/k;
			int w1 = sk%k;
			

			for(int i = 0; i<k-w1;i++){
				System.out.print(w+" ");
			}
			for(int i = k-w1;i<k;i++){
				System.out.print(w+1+" ");
			}
			for(int i = 0; i<n-k-v1 ; i++){
				System.out.print(v+" ");
			}
			for(int i = n-v1-k;i<n-k;i++) System.out.print(v+1+" ");
			log.close();
			

		}
		
		static void dfs(int x){
			long sum = 0, max = Long.MIN_VALUE;
			b[x] = true;
			

			PriorityQueue<Long> pq=new PriorityQueue<>(10,Collections.reverseOrder());
			if(amp[x].size()>2) check = true;
			for(int i:amp[x]){
				if(!b[i]){
					parent[i] = x;
					dfs(i);
					sum+=SUM[i];
					max = Math.max(max, MAX[i]);
					pq.add(MAX[i]);
				}
			}
			SUM[x] = sum+arr[x];
			MAX[x] = Math.max(SUM[x],max);
			if(pq.size()>=2){
				ans = Math.max(ans, pq.poll()+pq.poll());
			}
			
		}
		public static void id0(int n){
			for(int i =0 ;i< n; i++){
				int x = sc.nextInt(), y = sc.nextInt(), w = sc.nextInt();
				amp1[--x].add(new Graph(--y,w));
				amp1[y].add(new Graph(x,w));
			}
		}
		
		public static void seive(int n){
			b = new boolean[(n+1)];
			Arrays.fill(b, true);
			b[1] = false;
			for(int i = 2;i*i<=n;i++){
				if(b[i]){
					for(int p = 2*i;p<=n;p+=i){
						b[p] = false;
						prime[p] = i;
					}
				}
			}
			for(int i = 2;i<=n;i++){
				if(b[i]) prime[i] = i;
			}
		}
		
		static class Graph{
			int vertex;
			int weight;
			Graph(int v, int w){
				vertex = v;
				weight = w;
			}
		}
		static class Pair implements Comparable<Pair> {
			int u;
			int v;
			int w;
			public Pair(int u, int v, int w) {
				this.u = u;
				this.v = v;
				this.w = w;
			}
			
			public int hashCode() {
				int hu = (int) (u ^ (u >>> 32));
				int hv = (int) (v ^ (v >>> 32));
				return 31*hu + hv;
			}
	 
			public boolean equals(Object o) {
				Pair other = (Pair) o;
				return ((u == other.u && v == other.v));
			}
	 
			public int compareTo(Pair other) {
				return Long.compare(other.w, w); 

				

			}
			
			public String toString() {
				return "[u=" + u + ", v=" + v + "]";
			}
		}
		
		public static void buildGraph(int n){
			for(int i =0;i<n;i++){
				int x = sc.nextInt()-1, y = sc.nextInt()-1;
				amp[x].add(y);
				amp[y].add(x);
			}
		}
		
		
		public static int getParent(long x){
			while(parent[(int) x]!=x){
				parent[ (int) x] = parent[(int) parent[ (int) x]];
				x = parent[ (int) x];
			}
			return (int) x;
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
		 static void id12(String pat, String txt)
		    {
		        int M = pat.length();
		        int N = txt.length();
		 
		        

		        

		        int lps[] = new int[M];
		        int j = 0;  

		 
		        

		        

		        id1(pat,M,lps);
		 
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
		 static void id1(String pat, int M, int lps[])
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
		
		public static void buildTree(int n){
			int arr[] = sc.id5(n);
			for(int i = 0;i<n;i++){
				int x = arr[i]-1;
				amp[i+1].add(x);
				amp[x].add(i+1);
			}
		}
		
		static class SegmentTree {
			boolean st[];
			boolean lazy[];

			SegmentTree(int n) {
				int size = 4 * n;
				st = new boolean[size];
				Arrays.fill(st, true);
				lazy = new boolean[size];
				Arrays.fill(lazy, true);
				

			}
			
			

			void update(int si, int ss, int se, int idx, long x) {
				if (ss == se) {
					

					st[si]=false;
				} 
				else {
					int mid = (ss + se) / 2;
					if(ss <= idx && idx <= mid)
			        {
			             update(2*si, ss, mid, idx, x);
			        }
			        else
			        { update(2*si+1, mid+1, se, idx, x);
			        }
					st[si] = st[2*si]|st[2*si+1];
				}
			}
			
			void updateRange(int node, int start, int end, int l, int r, boolean val)
			{
			    if(!lazy[node])
			    { 
			        

			        st[node] = lazy[node];    

			        if(start != end)
			        {
			            lazy[node*2] = lazy[node];                  

			            lazy[node*2+1] = lazy[node];                

			        }
			        lazy[node] = true;                                  

			    }
			    if(start > end || start > r || end < l)              

			        return;
			    if(start >= l && end <= r)
			    {
			        

			        st[node] =  val;
			        if(start != end)
			        {
			            

			            lazy[node*2] = val;
			            lazy[node*2+1] = val;
			        }
			        return;
			    }
			    int mid = (start + end) / 2;
			    updateRange(node*2, start, mid, l, r, val);        

			    updateRange(node*2 + 1, mid + 1, end, l, r, val);   

			    st[node] = st[node*2] | st[node*2+1];        

			}

			boolean queryRange(int node, int start, int end, int l, int r)
			{
			    if(start > end || start > r || end < l)
			        return false;         

			    if(!lazy[node])
			    {
			        

			        st[node] = lazy[node];            

			        if(start != end)
			        {
			            lazy[node*2] = lazy[node];         

			            lazy[node*2+1] = lazy[node];    

			        }
			        lazy[node] = true;                 

			    }
			    if(start >= l && end <= r)             

			        return  st[node];
			    int mid = (start + end) / 2;
			    boolean p1 = queryRange(node*2, start, mid, l, r);         

			    boolean p2 = queryRange(node*2 + 1, mid + 1, end, l, r); 

			    return (p1 | p2);
			}
			void print() {
				for (int i = 0; i < st.length; i++) {
					System.out.print(st[i]+" ");
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
		static class id3{
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
		
		static long modInverse(long a, long id7){
		            return  power(a, id7-2, id7);
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
		public static void id6(long a, long b){
			if(b == 0) {
		        d = a;
		        x = 1;
		        y = 0;
		    }
		    else {
		        id6(b, a%b);
		        int temp = (int) x;
		        x = y;
		        y = temp - (a/b)*y;
		    }
		}
		
		public static long gcd(long n, long m){
			if(m!=0) return gcd(m,n%m);
			else return n;
		}
		
		static BufferedReader reader;
	    static StringTokenizer tokenizer;
	    static PrintWriter writer;
	
	
	   
	    static class id9 {

			private final InputStream stream;
			private final byte[] buf = new byte[8192];
			private int curChar, id4;
			private id10 filter;

			public id9(InputStream stream) {
				this.stream = stream;
			}

			public int snext() {
				if (id4 == -1)
					throw new InputMismatchException();
				if (curChar >= id4) {
					curChar = 0;
					try {
						id4 = stream.read(buf);
					} catch (IOException e) {
						throw new InputMismatchException();
					}
					if (id4 <= 0)
						return -1;
				}
				return buf[curChar++];
			}

			public int nextInt() {
				int c = snext();
				while (id2(c)) {
					c = snext();
				}
				int sgn = 1;
				if (c == '-') {
					sgn = -1;
					c = snext();
				}
				int res = 0;
				do {
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					res *= 10;
					res += c - '0';
					c = snext();
				} while (!id2(c));
				return res * sgn;
			}

			public long nextLong() {
				int c = snext();
				while (id2(c)) {
					c = snext();
				}
				int sgn = 1;
				if (c == '-') {
					sgn = -1;
					c = snext();
				}
				long res = 0;
				do {
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					res *= 10;
					res += c - '0';
					c = snext();
				} while (!id2(c));
				return res * sgn;
			}

			public int[] id5(int n) {
				int a[] = new int[n];
				for (int i = 0; i < n; i++) {
					a[i] = nextInt();
				}
				return a;
			}

			public long[] id11(int n) {
				long a[] = new long[n];
				for (int i = 0; i < n; i++) {
					a[i] = nextInt();
				}
				return a;
			}
	                
			public String readString() {
				int c = snext();
				while (id2(c)) {
					c = snext();
				}
				StringBuilder res = new StringBuilder();
				do {
					res.appendCodePoint(c);
					c = snext();
				} while (!id2(c));
				return res.toString();
			}

			public String nextLine() {
				int c = snext();
				while (id2(c))
					c = snext();
				StringBuilder res = new StringBuilder();
				do {
					res.appendCodePoint(c);
					c = snext();
				} while (!id8(c));
				return res.toString();
			}

			public boolean id2(int c) {
				if (filter != null)
					return filter.id2(c);
				return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
			}

			private boolean id8(int c) {
				return c == '\n' || c == '\r' || c == -1;
			}

			public interface id10 {
				public boolean id2(int ch);
			}
		}
	}  