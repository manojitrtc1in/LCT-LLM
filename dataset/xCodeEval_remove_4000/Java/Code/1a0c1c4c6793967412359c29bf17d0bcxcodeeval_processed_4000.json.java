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
				static int sum[],dist[],cnt[],ans[],size[];
				static int p = 0,cnt1 =0 ,cnt2 = 0;
				

				static id5 sc = new id5();
				static Queue<Integer> q = new LinkedList<>();
				static int arr[],start[],end[],color[],parent[];
				static PriorityQueue<Integer> pq;
				

				static LinkedList<Integer> fa;
				static BufferedWriter log;
				static TreeMap<Integer,Integer> tm = new TreeMap<>();
				static HashMap<Integer,Pair> hs;
				static Stack<Integer> stack = new Stack<>();
				static Pair prr[];
				static long parent1[],parent2[],size1[],size2[],value[];
				static long Ans;
				public static void main(String[] args) throws Exception {
			    	soln();
			    }
				static int MAX = 10000001;

				public static void soln() throws IOException {
					log = new BufferedWriter(new OutputStreamWriter(System.out));
					HashMap<Integer,Integer> hm = new HashMap<>();
					int n = sc.nextInt();
						int arr[] = sc.id1(n);
						int m = sc.nextInt();
						int brr[] = sc.id1(m);
						int crr[] = sc.id1(m);
						int ans = brr[0], c = crr[0], temp = 1;
						Pair prr[] = new Pair[m];
						for(int i : arr){
							if(hm.containsKey(i)) hm.put(i, hm.get(i)+1);
							else hm.put(i, 1);
						}
						for(int i = 0; i< m; i++){
							int a = 0, b = 0;
							if(hm.containsKey(brr[i])){
								a = hm.get(brr[i]);
							}
							if(hm.containsKey(crr[i])){
								b = hm.get(crr[i]);
							}
							prr[i] = new Pair(a,b,i+1);
						}
						Arrays.sort(prr);
						System.out.println(prr[m-1].h);
					log.close();
				}
				public static void mergeSort(int[] arr, int l ,int r){
					if((r-l)>=1){
						int mid = (l+r)/2;
						mergeSort(arr,l,mid);
						mergeSort(arr,mid+1,r);
						merge(arr,l,r,mid);
						

					}
				}
				public static void merge(int arr[], int l, int r, int mid){
					int n1 = (mid-l+1), n2 = (r-mid);
					int left[] = new int[n1];
					int right[] = new int[n2];
					for(int i =0 ;i<n1;i++) left[i] = arr[l+i];
					for(int i =0 ;i<n2;i++) right[i] = arr[mid+1+i];
					int i =0, j =0, k = l;
					while(i<n1 && j<n2){
						if(left[i]>right[j]){
							Ans+=(n1-i);
							arr[k++] = right[j++];
						}
						else{
							arr[k++] = left[i++];
						}
					}
					while(i<n1) arr[k++] = left[i++];
					while(j<n2) arr[k++] = right[j++];
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
							color[e] = -1*color[x];
							if(color[e]==1) cnt1++;
							else cnt2++;
							dfs(e);
						}
						else{
							if(color[x]==color[e]){
								System.out.println(0+" "+1);
								System.exit(0);
							}
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

				public static int getParent(int x){
					while(parent[x]!=x){
						parent[x] = parent[ parent[x]];
						x = parent[ x];
					}
					return x;
				}
				static class Pair implements Comparable<Pair> {
					int u;
					int v;
					int h;
					public Pair(int u, int v, int h) {
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
						return Integer.compare(u, other.u) != 0 ? (Integer.compare(u, other.u)) : (Integer.compare(v, other.v));
					}
					
					public String toString() {
						return "[u=" + u + ", v=" + v + "]";
					}
				}
				static int min(int a, int b, int c){
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
				static class Struct{
					int prefixSum, suffixSum, Sum, ans;
					Struct(int p,int s, int S, int a){
						prefixSum = p;
						suffixSum = s;
						Sum  = S;
						ans = a;
					}
					Struct(){
						
					}
				}
				static class SegmentTree {
					Struct st[];
				


					SegmentTree(int n) {
						int size = 4 * 2;
						st = new Struct[size];
						for(int i =0;i<size;i++) st[i] = new Struct();
					

						build(0, n - 1, 1);
					}
					
					Struct build(int ss, int se, int si) {
						if (ss == se) {
							st[si].prefixSum = arr[ss];
							st[si].suffixSum = arr[ss];
							st[si].Sum = arr[ss];
							st[si].ans = arr[ss];
							return st[si];
						}
						int mid = (ss + se) / 2;
						st[si*2] = build(ss,mid,2*si); st[si*2+1] = build(mid+1,se,2*si+1);
						st[si].prefixSum = Math.max(st[si*2].prefixSum, st[2*si].Sum+st[2*si+1].prefixSum); 
						st[si].suffixSum = Math.max(st[si*2+1].suffixSum, st[2*si+1].Sum+st[2*si].suffixSum); 
						st[si].Sum = (st[si*2].Sum+ st[2*si+1].Sum); 
						st[si].ans = Math.max(st[si*2].ans, Math.max(st[2*si+1].ans,st[2*si].suffixSum+st[2*si+1].prefixSum)); 
						return st[si];
					}

					void update(int si, int ss, int se, int idx, int val) {
						if (ss == se) {
							arr[idx] = val;
							st[si].prefixSum = arr[ss];
							st[si].suffixSum = arr[ss];
							st[si].Sum = arr[ss];
							st[si].ans = arr[ss];
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
							st[si].prefixSum = Math.max(st[si*2].prefixSum, st[2*si].Sum+st[2*si+1].prefixSum); 
							st[si].suffixSum = Math.max(st[si*2+1].suffixSum, st[2*si+1].Sum+st[2*si].suffixSum); 
							st[si].Sum = (st[si*2].Sum+ st[2*si+1].Sum); 
							st[si].ans = Math.max(st[si*2].ans, Math.max(st[2*si+1].ans,st[2*si].suffixSum+st[2*si+1].prefixSum));
						}
					}
					Struct get(int qs, int qe, int ss, int se, int si){
						if(qs>se || qe<ss){
							return new Struct(Integer.MIN_VALUE/2,Integer.MIN_VALUE/2,Integer.MIN_VALUE/2,Integer.MIN_VALUE/2);
						}
						if (qs <= ss && qe >= se) {
							return st[si];
						}
						int mid = (ss+se)/2;
						Struct s1 = get(qs, qe, ss, mid, si * 2), s2 = get(qs, qe, mid + 1, se, si * 2 + 1);
						st[si].prefixSum = Math.max(s1.prefixSum, s1.Sum+s2.prefixSum); 
						st[si].suffixSum = Math.max(s2.suffixSum, s2.Sum+s1.suffixSum); 
						st[si].Sum = (s1.Sum+ s2.Sum); 
						st[si].ans = Math.max(s1.ans, Math.max(s2.ans,s1.suffixSum+s2.prefixSum));
						return st[si];
					}
					
					void print() {
						for (int i = 0; i < st.length; i++) {
							System.out.print(st[i].ans+" "+st[i].prefixSum+" "+st[i].suffixSum+" "+st[i].Sum+"\n");
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