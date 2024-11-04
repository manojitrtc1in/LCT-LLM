	import java.io.BufferedReader;
	import java.io.BufferedWriter;
	import java.io.IOException;
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
		
		static long MOD = 1000000007;
		static boolean b[];
		static ArrayList<Integer>[] amp;
		static ArrayList<Graph>[] amp1;
		static int sum[],dist[],cnt[],arr[],start[],color[],parent[],prime[];
		static long ans = 0;
		static int p = 0;
		static id9 sc = new id9();
		static Queue<Integer> q = new LinkedList<>();
		static PriorityQueue<Integer> pq;
		static BufferedWriter log;
		static HashSet<Integer> hs;
		static HashMap<String,Integer> hm;
		static Pair prr[];
		static long parent1[],parent2[],size[][],size1[],size2[];
		public static void main(String[] args) throws Exception {
	    	new Thread(null, new Runnable() {
				public void run() {
					try {
						soln();
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			}, "1", 1 << 26).start();
		}
		
		static int MAX = 2000000;
		static long l, r;
		StringBuilder sb = new StringBuilder();
		public static void soln() throws IOException {
			log = new BufferedWriter(new OutputStreamWriter(System.out));
			int n = sc.nextInt();
			int arr[] = sc.id4(n);
			int ans = 0;
			int dp[] = new int[61];
			dp[0] = 0;
			int cnt = 2, temp = 1;
			loop1 : while(true){
				for(int i =temp;i<=temp+cnt;i++){
					try{
						dp[i] = cnt-1;
					}
					catch(Exception e){
						break loop1;
					}
				}
				temp+=cnt;
				cnt++;
			}
			for(int i =0 ; i< n;i++){
				ans^=(dp[arr[i]]);
			}
			if(ans==0) System.out.println("YES");
			else System.out.println("NO");
			log.close();
		}
		static long id0(long n, long s, long e){
			if(l>e || r<s) return 0;
			if(n==0) return 0;
			long mid = (s+e)/2;
			long ans = 0;
			if(l<=mid && r>=mid){
				ans = n%2;
			}
			if(l>mid) return ans+id0(n/2,mid+1,e);
			else if(r<mid) return ans+id0(n/2,s,mid-1);
			else return ans+id0(n/2,mid+1,e)+id0(n/2,s,mid-1);
		}
		long sum1 = 0;
		public static long id5(long n){
			if(n==0) return 0;
			if(n==1) return 1;
			return 1+2*id5(n/2);
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
		}
		static class Graph{
			int vertex;
			int weight;
			Graph(int v, int w){
				vertex = v;
				weight = w;
			}
		}
		static void dfs(int x){
			b[x] = true;
			for(Graph e:amp1[x]){
				int v = e.vertex, w = e.weight;
				if(!b[v]){
					dist[v] = dist[x]^w;
					dfs(v);
				}
			}
		}
		public static void bfs(int x,int arr[]){
		b = new boolean[arr.length];
		b[x] = true;
		q = new LinkedList<>();
		q.add(x);
		while(!q.isEmpty()){
			int y = q.poll();
			for(int i = 0;i<amp[y].size();i++) {
				if(!b[amp[y].get(i)]){
					q.add(amp[y].get(i));
					b[amp[y].get(i)] = true;
					arr[amp[y].get(i)] = (arr[y]+1);
				}
			}
		}
		}
		
		static long get(long x){
			if((x%10)<5) return x-(x%10);
			else return x+(10-x%10);
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
				return Long.compare(u, other.u) != 0 ? (Long.compare(u, other.u)) : (Long.compare(v, other.v));
			}
			
			public String toString() {
				return "[u=" + u + ", v=" + v + "]";
			}
		}
		public static void buildGraph(int n){
			for(int i =0;i<n;i++){
				int x = sc.nextInt(), y = sc.nextInt();
				amp[--x].add(--y);
				amp[y].add(x);
			}
		}
		
		
		public static int getParent(int x){
			while(parent[x]!=x){
				parent[ x] = parent[(int) parent[ x]];
				x = parent[ x];
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
		 static void id11(String pat, String txt)
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
			int arr[] = sc.id4(n);
			for(int i = 0;i<n;i++){
				int x = arr[i]-1;
				amp[i+1].add(x);
				amp[x].add(i+1);
			}
		}
		
		
		static class SegmentTree{
			int pre[], suf[], max[], val[];
			SegmentTree( int n){
				int size = 4*n;
				pre = new int[size];
				suf = new int[size];
				max = new int[size];
				val = new int[size];
				build(0,n-1,1);
			}
			void build(int ss, int se, int si){
				if(ss==se){
					pre[si] = 1;
					suf[si] = 1;
					max[si] = 1;
					val[si] = arr[ss];
				}
				else{
				int mid = (ss+se)>>2;
				si*=2;
				build(ss,mid,si);build(mid+1,se,si+1);
				}
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
	
	
	   
		public static class id9 {
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
				while (id2(c))
					c = read();
				StringBuilder res = new StringBuilder();
				do {
					res.appendCodePoint(c);
					c = read();
				} while (!id8(c));
				return res.toString();
			}
	 
			public String nextString() {
				int c = read();
				while (id2(c))
					c = read();
				StringBuilder res = new StringBuilder();
				do {
					res.appendCodePoint(c);
					c = read();
				} while (!id2(c));
				return res.toString();
			}
	 
			public long nextLong() {
				int c = read();
				while (id2(c))
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
				} while (!id2(c));
				return res * sgn;
			}
	 
			public int nextInt() {
				int c = read();
				while (id2(c))
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
				} while (!id2(c));
				return res * sgn;
			}
		        
		    public int[] id4(int n) {
		        return id4(n, 0);
		    }
		    
		    public int[] id4(int n, int off) {
		    	int[] arr = new int[n + off];
		    	for (int i = 0; i < n; i++) {
		    		arr[i + off] = nextInt();
		    	}
		    	return arr;
		    }
		    
		    public long[] id10(int n) {
		    	return id10(n, 0);
		    }
	        
			public long[] id10(int n, int off) {
			    long[] arr = new long[n + off];
			    for (int i = 0; i < n; i++) {
			        arr[i + off] = nextLong();
			    }
			    return arr;
			}
	 
		    private boolean id2(int c) {
				return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
			}
	 
			private boolean id8(int c) {
				return c == '\n' || c == '\r' || c == -1;
			}
		}
	}   