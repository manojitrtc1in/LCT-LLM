	import java.io.BufferedReader;
	import java.io.BufferedWriter;
	import java.io.FileInputStream;
	import java.io.IOException;
	import java.io.InputStream;
	import java.io.InputStreamReader;
	import java.io.OutputStreamWriter;
	import java.io.ObjectInputStream.GetField;
	import java.io.PrintWriter;
	import java.math.BigDecimal;
	import java.math.BigInteger;
	import java.util.ArrayList;
	import java.util.Arrays;
	import java.util.Collection;
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
			static boolean b[], b1[], check;
			static ArrayList<Integer>[] amp, pa;
			static ArrayList<Pair>[] amp1;
			static ArrayList<Pair>[][] damp;
			static int left[],s[],right[],end[],sum[],dist[],cnt[],start[],color[],parent[],prime[],size[];
			static long ans = 0,k;
			static int p = 0;
			static id8 sc = new id8(System.in);
			static Queue<Integer> q = new LinkedList<>();
			static PriorityQueue<Pair> pq;
			static BufferedWriter log;
			static HashSet<Integer>[] hs;
			static HashMap<Pair,Integer> hm;
			static PriorityQueue<Integer> pri[];
			static Stack<Integer> st;
			static boolean boo[][];
			static Pair prr[];
			static long parent1[],parent2[],size1[],size2[],arr1[],SUM[],MAX[];
			static int arr[], ver[][];
			public static void main(String[] args) throws Exception {
		    	
				soln();
			}
			static int dp[][];
			static int N,K,T;
			static int time;
			static int cost[][];
			static boolean b11[];
			static HashMap<Integer,Integer> h = new HashMap<>();
			static HashSet<Pair> chec;
			static long ans1;		static long ans2;
			static int BLOCK = 350;
			public static void soln() throws IOException {
				

				

				log = new BufferedWriter(new OutputStreamWriter(System.out));
				int n = sc.nextInt();
				TreeSet<Long> ts = new TreeSet<>();
				ts.add(0L);
				for(int i = 0; i<= 63;i++) ts.add((long) (Math.round(Math.pow(2,i))-1));
				

				while(n-->0){
					long l = sc.nextLong(), r = sc.nextLong();
					Long x = ts.floor(r);
					if(x!=null && x>=l){
						System.out.println(x);
						continue;
					}
					else{
						long ans = 0;
						String str1 = Long.toBinaryString(l), str2 = Long.toBinaryString(r);
						if(Long.bitCount(l)>=Long.bitCount(r)){
							ans = l;
						}
						else ans = r;
						StringBuilder sb = new StringBuilder();
						for(int i = 0; i< str1.length();i++){
							if(str2.charAt(i)=='1' && str1.charAt(i)=='0'){
								sb.append(0);
								for(int j = i+1;j<str1.length();j++){
									sb.append(1);
								}
								break;
							}
							else sb.append(str2.charAt(i));
						}
						

						long v = make(sb.reverse().toString());
						if(v<ans){
							if(Long.bitCount(v)>=Long.bitCount(ans)){
								ans = v;
							}
						}
						else{
							if(Long.bitCount(v)>Long.bitCount(ans)){
								ans = v;
							}
						}
						System.out.println(ans);
					}
				}
				log.close();
				

			}
			static long make(String s){
				long ans = 0;
				for(int i = 0; i<s.length();i++){
					if(s.charAt(i)=='1')
					ans += Math.round(Math.pow(2, i));
				}
				return ans;
			}
			static int dfs(int x, int cur){
				b[x] = true;
				

				for(int i : amp[x]){
					if(b[i]){
						if(ver[i][0]==x || ver[i][1] == x){
							if(chec.contains(new Pair(x,i))) return cur = 0;
							chec.add(new Pair(x,i));
							break;
						}
						if(ver[i][1] == -1){
							ver[i][1] = x;
							
							chec.add(new Pair(x,i));
							break;
						}
						else{
							return cur = -100000000;
						}
					}
					else{
						chec.add(new Pair(x,i));
						ver[x][0] = i;
						ver[i][1] = i;
						cur = dfs(i,cur+1)-1;
					}
				}
				pri[x].add(cur);
				return cur;
			}
			static int recur(int l, int r){
				if(l<0 || r<0 || l>N || r>N) return Integer.MAX_VALUE/2;
				if(l>r) return 1;
				if(l==r) return 1;
				if(dp[l][r]!=Integer.MAX_VALUE/2) return dp[l][r];
				if(arr[l]==arr[r]){
					dp[l][r] = Math.min(dp[l][r], recur(l+1,r-1));
				}
				for(int i = l; i< r; i++){
					dp[l][r] = Math.min(dp[l][r], recur(l,i)+recur(i+1,r));	
				}
				return dp[l][r];
			}
			static void bfs(int x){
				
			}
			static void dfs(int x){
				b[x] = true;
				if(amp[x].size()%2==1) p++;
				for(int p:amp[x]){
					if(!b[p]){
						dfs(p);
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
			static class Pair implements Comparable<Pair> {
				long u;
				int v;
				public Pair(){
					u = 0;
					v = 0;
				}
				public Pair(long u, int v) {
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
					return Long.compare(u, other.u) != 0 ? (Long.compare(u, other.u)) : (Long.compare(v,other.v));
				}
				
				public String toString() {
					return "[u=" + u + ", v=" + v + "]";
				}
			}
			
			public static void buildGraph(int n){
				for(int i =0;i<n;i++){
					int x = sc.nextInt()-1, y = sc.nextInt()-1;
					hm.put(new Pair(x,y), i+1);
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
			 static void id11(String pat, String txt)
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
			
			public static void buildTree(int n){
				int arr[] = sc.id4(n);
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

				    boolean b = queryRange(node*2 + 1, mid + 1, end, l, r); 

				    return (p1 | b);
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
						Node2 temp = root,temb = null;
						while(temp!=null){
							temb = temp;
							if(x>temp.data) temp = temp.right;
							else temp = temp.left;
						}
						if(x>temb.data) temb.right = n;
						else temb.left = n;
						n.parent = temb;
						parent.add(temb.data);
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
		
		
		   
		    static class id8 {
	
				private final InputStream stream;
				private final byte[] buf = new byte[8192];
				private int curChar, id3;
				private id9 filter;
	
				public id8(InputStream stream) {
					this.stream = stream;
				}
	
				public int snext() {
					if (id3 == -1)
						throw new InputMismatchException();
					if (curChar >= id3) {
						curChar = 0;
						try {
							id3 = stream.read(buf);
						} catch (IOException e) {
							throw new InputMismatchException();
						}
						if (id3 <= 0)
							return -1;
					}
					return buf[curChar++];
				}
	
				public int nextInt() {
					int c = snext();
					while (id1(c)) {
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
					} while (!id1(c));
					return res * sgn;
				}
	
				public long nextLong() {
					int c = snext();
					while (id1(c)) {
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
					} while (!id1(c));
					return res * sgn;
				}
	
				public int[] id4(int n) {
					int a[] = new int[n];
					for (int i = 0; i < n; i++) {
						a[i] = nextInt();
					}
					return a;
				}
	
				public long[] id10(int n) {
					long a[] = new long[n];
					for (int i = 0; i < n; i++) {
						a[i] = nextInt();
					}
					return a;
				}
		                
				public String readString() {
					int c = snext();
					while (id1(c)) {
						c = snext();
					}
					StringBuilder res = new StringBuilder();
					do {
						res.appendCodePoint(c);
						c = snext();
					} while (!id1(c));
					return res.toString();
				}
	
				public String nextLine() {
					int c = snext();
					while (id1(c))
						c = snext();
					StringBuilder res = new StringBuilder();
					do {
						res.appendCodePoint(c);
						c = snext();
					} while (!id7(c));
					return res.toString();
				}
	
				public boolean id1(int c) {
					if (filter != null)
						return filter.id1(c);
					return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
				}
	
				private boolean id7(int c) {
					return c == '\n' || c == '\r' || c == -1;
				}
	
				public interface id9 {
					public boolean id1(int ch);
				}
			}
		}  