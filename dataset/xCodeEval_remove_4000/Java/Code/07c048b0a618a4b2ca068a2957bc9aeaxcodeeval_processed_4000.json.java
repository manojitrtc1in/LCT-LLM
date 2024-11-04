		import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.ObjectInputStream.GetField;
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
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;
			public class Q2 {
				
				static long MOD = 1000000007;
				static boolean b1,b[],bc[];
				static boolean boo[][][];
				static int ans1 = -1,ans2 = -1, root;
				static ArrayList<Integer>[] amp,amp1;
				static int sum[],dist[],cnt[],ans[];
				static long p = 0;
				

				static id5 sc = new id5();
				static Queue<Integer> q = new LinkedList<>();
				static int arr[],start[],end[],color[],parent[];
				static PriorityQueue<Integer> pq;
				

				static LinkedList<Integer> fa;
				static BufferedWriter log;
				static TreeMap<Integer,Integer> tm = new TreeMap<>();
				static HashSet<Pair> hs;
				static Stack<Integer> stack = new Stack<>();
				static Pair prr[];
				static long parent1[],parent2[],size[][],size1[],size2[],value[];
				public static void main(String[] args) throws Exception {
			    	soln();
			    }
				static int MAX = 10000001;

				public static void soln() throws IOException {
					log = new BufferedWriter(new OutputStreamWriter(System.out));
					int n = sc.nextInt();
					Pair prr[] = new Pair[n];
					for(int i = 0; i< n ;i++)  prr[i] = new Pair(sc.nextInt(),sc.nextInt(),sc.nextLong());
					Arrays.sort(prr);
					Stack<Pair> st = new Stack<>();
					long ans = 0, sum = 0;
					for(int i = n-1;i>=0;i--){
						

						if(st.isEmpty() || st.peek().u<prr[i].v ){
							st.add(prr[i]);
							sum+=prr[i].h;
						}
						else{
							while(!st.isEmpty() && st.peek().u>=prr[i].v){
								sum-=st.pop().h;
							}
							st.add(prr[i]);
							sum+=prr[i].h;
						}
						ans = Math.max(ans, sum);
						

					}
					System.out.println(ans);
					log.close();
				}
				public static void buildGraph(int n){
					for(int i =0;i<n;i++){
						int x = sc.nextInt(), y = sc.nextInt();
						amp[--x].add(--y);
						amp[y].add(x);
					}
				}
				public static void dfs(int x){
					b[x] = true;
					for(int e:amp[x]){
						if(!b[e]){
							parent[e] = x;
							dfs(e);
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

				public static long getParent(long x, long parent[]){
					while(parent[(int) x]!=x){
						parent[(int) x] = parent[(int) parent[(int) x]];
						x = parent[(int) x];
					}
					return x;
				}
				static class Pair implements Comparable<Pair> {
					int u;
					int v;
					long h;
					public Pair(int u, int v, long h) {
						this.u = u;
						this.v = v;
						this.h = h;
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
						return Integer.compare(v, other.v) != 0 ? (Integer.compare(v, other.v)) : (Integer.compare(u, other.u));
					}
					
					public String toString() {
						return "[u=" + u + ", v=" + v + "]";
					}
				}
				static long min(long a, long b, long c){
					if(a<b && a<c) return a;
					if(b<c) return b;
					return c;
				}
				private static void permutation(String prefix, String str) {
				    int n = str.length();
				    if (n == 0); 

				    else {
				        for (int i = 0; i < n; i++)
				            permutation(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n));
				    }
				}
				static class Graph{
					int vertex;
					long weight;
				}
				public static void buildTree(int n){
					int arr[] = sc.id1(n);
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
				static class Tree {
					ArrayList<Integer>[] g ;
					int T[]; 

					int L[]; 

					int P[][]; 


					public Tree(int n) {
						T = new int[n];
						L = new int[n];
						P = new int[n][log2(n) + 1];
						g = (ArrayList<Integer>[])new ArrayList[n];
						L[0] = 0;
						for (int i = 0; i < n; i++) {
							g[i] = new ArrayList<>();
						}
						for (int i = 0; i < n ; i++) {
							int a = sc.nextInt();
							for(int j = 0; j<a; j++){
								int b = sc.nextInt()-1;
								g[i].add(b);
								g[b].add(i);
							}
						}
						dfs(0, -1);
						for (int j = 0; (1 << j) <= n; j++)
							pre(0, j,-1);
					}

					public int log2(int n) {
						return (int) (Math.log10(n) / Math.log10(2));
					}

					public void dfs(int node, int p) {
						for (int k : g[node]) {
							if (k != p) {
								T[k] = node;
								L[k] = L[node] + 1;
								dfs(k, node);
							}
						}
					}
					public void pre(int node, int j,int p) {
						if (j == 0) {
							P[node][j] = T[node];
						} else {
							P[node][j] = P[P[node][j - 1]][j - 1];
						}
						for (int k : g[node]) {
							if(k!=p)
								pre(k, j,node);
						}
					}
					public int lca(int u, int v) {
						if (L[u] > L[v]) {
							int temp = u;
							u = v;
							v = temp;
						}
						int log;
						for (log = 0; (1 << log) <= L[v]; log++)
							; 

						log--;

						for (int i = log; i >= 0; i--) {
							if ((1 << i) <= L[v] - L[u]) 

								v = P[v][i];
						}
						if (u == v)
							return u;
						for (int i = log; i >= 0; i--) {
							if (P[u][i] != 0 && P[u][i] != P[v][i]) 

							{
								u = P[u][i];
								v = P[v][i];
							}
						}
						return T[u];
					}
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
				static long modInverse(long a, long id3){
				            return  power(a, id3-2, id3);
				}
				static long power(long x, long y, long m)
				{
				    if (y == 0)
				        return 1;
				    long p = power(x, y/2, m) % m;
				    p = (p * p) % m;
				 
				    return (y%2 == 0)? p : (x * p) % m;
				}
				static long d,x,y;
				public static void id2(long a, long b){
					if(b == 0) {
				        d = a;
				        x = 1;
				        y = 0;
				    }
				    else {
				        id2(b, a%b);
				        int temp = (int) x;
				        x = y;
				        y = temp - (a/b)*y;
				    }
				}
				
				public static long gcd(long n, long m){
					if(m!=0) return gcd(m,n%m);
					else return n;
				}
				public static class id5 {
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
						while (id0(c))
							c = read();
						StringBuilder res = new StringBuilder();
						do {
							res.appendCodePoint(c);
							c = read();
						} while (!id4(c));
						return res.toString();
					}
			 
					public String nextString() {
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
			 
					public long nextLong() {
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
			 
					public int nextInt() {
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
				        
				    public int[] id1(int n) {
				        return id1(n, 0);
				    }
				    
				    public int[] id1(int n, int off) {
				    	int[] arr = new int[n + off];
				    	for (int i = 0; i < n; i++) {
				    		arr[i + off] = nextInt();
				    	}
				    	return arr;
				    }
				    
				    public long[] id6(int n) {
				    	return id6(n, 0);
				    }
			        
					public long[] id6(int n, int off) {
					    long[] arr = new long[n + off];
					    for (int i = 0; i < n; i++) {
					        arr[i + off] = nextLong();
					    }
					    return arr;
					}
			 
				    private boolean id0(int c) {
						return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
					}
			 
					private boolean id4(int c) {
						return c == '\n' || c == '\r' || c == -1;
					}
				}
			} 