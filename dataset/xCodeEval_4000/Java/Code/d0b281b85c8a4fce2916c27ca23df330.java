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
		static boolean b[], b1[];
		static ArrayList<Integer>[] amp, pa;
		static ArrayList<Graph>[] amp1;
		static int sum[],dist[],cnt[],arr[],start[],color[],parent[],prime[];
		static long ans = 0,k;
		static int p = 0;
		static FasterScanner sc = new FasterScanner();
		static Queue<Integer> q = new LinkedList<>();
		static PriorityQueue<Integer> pq;
		static BufferedWriter log;
		static HashSet<Integer> hs;
		static HashMap<String,Integer> hm;
		static Pair prr[];
		static long parent1[],parent2[],size[][],size1[],size2[],arr1[];
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
	 static	class Node{
			int x,len,val;
			Node(int x, int len, int val){
				this.x = x;
				this.len = len;
				this.val = val;
			}
		}
		
		static int MAX = 2000000;
		StringBuilder sb = new StringBuilder();
		static String str;
		public static void soln() throws IOException {
			log = new BufferedWriter(new OutputStreamWriter(System.out));
			int n = sc.nextInt();
			int arr[] = sc.nextIntArray(n);
			int brr[] = sc.nextIntArray(n);
			int[] l = new int[100001];
			int cnt[] = new int[100001];
			int cntsum[] = new int[100001];
			int d[] = new int[201];
			amp = (ArrayList<Integer>[]) new ArrayList[100001];
			for(int i =1;i<=100000;i++) amp[i] = new ArrayList<>();
			for(int i = 0; i< n; i++){
				l[arr[i]]+=brr[i];
				amp[arr[i]].add(i);
			}
			long sum[] = new long[100001];
			for(int i = 1;i<=100000;i++){
				sum[i] = sum[i-1]+l[i];
			}
			for(int i = 0;i < n; i++){
				cnt[arr[i]]++;
			}
			for(int i = 1;i<=100000;i++) cntsum[i] = cntsum[i-1]+cnt[i];
			for(int i = 1; i<=20;i++){
			

			}
			long ans = Long.MAX_VALUE/2;
			for(int i = 1;i<=100000;i++){
				if(cnt[i]>0){
				long fa = sum[100000]-sum[i];
				int x = cntsum[100000]-cntsum[i];
				int y = n-x, z = y/2+1;
				int v = y-(2*cnt[i]-1);
				

				for(int j = 1;j<=200;j++){
					if(d[j]>=v){
						fa+=Math.max(0, j*v);
						break;
					}
					else{
						fa+=(j*d[j]);
						v-=d[j];
					}
				}
				for(int j:amp[i]){
					d[brr[j]]++;
				}
				ans = Math.min(ans,fa);
				

				}
			}
			System.out.println(ans);
			log.close();
		}
		static void dfs(int x){
			b[x] = false;
			b1[x] = true;
			System.out.println(pa[x]);
			for(int e:pa[x]){
				if(!b1[e]){
					dfs(e);
				}
			}
		}
		public static void bfs(int x){
		b[x] = true;
		q = new LinkedList<>();
		dist[x] = 0;
		q.add(x);
		while(!q.isEmpty()){
			int y = q.poll();
			for(int i = 0;i<amp[y].size();i++) {
				if(!b[amp[y].get(i)]){
					q.add(amp[y].get(i));
					b[amp[y].get(i)] = true;
					dist[amp[y].get(i)] = dist[y]+1;
				}
			}
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
		long sum1 = 0;
		public static long recur1(long n){
			if(n==0) return 0;
			if(n==1) return 1;
			return 1+2*recur1(n/2);
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
		 static void KMPSearch(String pat, String txt)
		    {
		        int M = pat.length();
		        int N = txt.length();
		 
		        

		        

		        int lps[] = new int[M];
		        int j = 0;  

		 
		        

		        

		        computeLPSArray(pat,M,lps);
		 
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
		 static void computeLPSArray(String pat, int M, int lps[])
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
			int arr[] = sc.nextIntArray(n);
			for(int i = 0;i<n;i++){
				int x = arr[i]-1;
				amp[i+1].add(x);
				amp[x].add(i+1);
			}
		}
		
		static class SegmentTree {
			long st[];
			long lazy[];

			SegmentTree(int n) {
				int size = 4 * n;
				st = new long[size];
				

				

			}
			
			

			void update(int si, int ss, int se, int idx, int val) {
				if (ss == se) {
					arr[idx] += val;
					st[si]+=val;
				} 
				else {
					int mid = (ss + se) / 2;
					if(ss <= idx && idx <= mid)
			        {
			             update(2*si, ss, mid, idx, val);
			        }
			        else
			        { update(2*si+1, mid+1, se, idx, val);
			        }
					st[si] = st[2*si]+st[2*si+1];
				}
			}
			long get(int qs, int qe, int ss, int se, int si){
				if(qs>se || qe<ss) return 0;
				if (qs <= ss && qe >= se) {
					return st[si];
				}
				int mid = (ss+se)/2;
				return get(qs, qe, ss, mid, si * 2)+get(qs, qe, mid + 1, se, si * 2 + 1);
			}
			void updateRange(int node, int start, int end, int l, int r, int val)
			{
			    if(lazy[node] != 0)
			    { 
			        

			        st[node] += (end - start + 1) * lazy[node];    

			        if(start != end)
			        {
			            lazy[node*2] += lazy[node];                  

			            lazy[node*2+1] += lazy[node];                

			        }
			        lazy[node] = 0;                                  

			    }
			    if(start > end || start > r || end < l)              

			        return;
			    if(start >= l && end <= r)
			    {
			        

			        st[node] += (end - start + 1) * val;
			        if(start != end)
			        {
			            

			            lazy[node*2] += val;
			            lazy[node*2+1] += val;
			        }
			        return;
			    }
			    int mid = (start + end) / 2;
			    updateRange(node*2, start, mid, l, r, val);        

			    updateRange(node*2 + 1, mid + 1, end, l, r, val);   

			    st[node] = st[node*2] + st[node*2+1];        

			}

			int queryRange(int node, int start, int end, int l, int r)
			{
			    if(start > end || start > r || end < l)
			        return 0;         

			    if(lazy[node] != 0)
			    {
			        

			        st[node] += (end - start + 1) * lazy[node];            

			        if(start != end)
			        {
			            lazy[node*2] += lazy[node];         

			            lazy[node*2+1] += lazy[node];    

			        }
			        lazy[node] = 0;                 

			    }
			    if(start >= l && end <= r)             

			        return (int) st[node];
			    int mid = (start + end) / 2;
			    int p1 = queryRange(node*2, start, mid, l, r);         

			    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); 

			    return (p1 + p2);
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
		static class BinarySearchTree{
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
		
		static long modInverse(long a, long mOD2){
		            return  power(a, mOD2-2, mOD2);
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
		public static void extendedEuclidian(long a, long b){
			if(b == 0) {
		        d = a;
		        x = 1;
		        y = 0;
		    }
		    else {
		        extendedEuclidian(b, a%b);
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
	
	
	   
		public static class FasterScanner {
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
				while (isSpaceChar(c))
					c = read();
				StringBuilder res = new StringBuilder();
				do {
					res.appendCodePoint(c);
					c = read();
				} while (!isEndOfLine(c));
				return res.toString();
			}
	 
			public String nextString() {
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
	 
			public long nextLong() {
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
	 
			public int nextInt() {
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
		        
		    public int[] nextIntArray(int n) {
		        return nextIntArray(n, 0);
		    }
		    
		    public int[] nextIntArray(int n, int off) {
		    	int[] arr = new int[n + off];
		    	for (int i = 0; i < n; i++) {
		    		arr[i + off] = nextInt();
		    	}
		    	return arr;
		    }
		    
		    public long[] nextLongArray(int n) {
		    	return nextLongArray(n, 0);
		    }
	        
			public long[] nextLongArray(int n, int off) {
			    long[] arr = new long[n + off];
			    for (int i = 0; i < n; i++) {
			        arr[i + off] = nextLong();
			    }
			    return arr;
			}
	 
		    private boolean isSpaceChar(int c) {
				return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
			}
	 
			private boolean isEndOfLine(int c) {
				return c == '\n' || c == '\r' || c == -1;
			}
		}
	}  