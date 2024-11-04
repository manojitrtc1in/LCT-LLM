		import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
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
import java.util.Random;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;

			public class Q2 {
				
				static long MOD = 1000000007;
				static boolean b1,b[],bc[];
				static boolean boo[][][];
				static int ans1 = -1,ans2 = -1, root;
				static ArrayList<Integer>[] amp,amp1;
				static int sum[],dist[],cnt[],ans[],size[],col[][];
				static int p = 0,cnt1 =0 ,cnt2 = 0;
				

				static id6 sc = new id6(System.in);
				static Queue<Integer> q = new LinkedList<>();
				static int arr[],start[],end[],color[],parent[];
				static PriorityQueue<Integer> pq;
				

				static LinkedList<Integer> fa;
				static BufferedWriter log;
				static TreeMap<Integer,Integer> tm = new TreeMap<>();
			

				static Stack<Integer> stack = new Stack<>();
				static Pair prr[],dp[][][];
				static long parent1[],parent2[],size1[],size2[],value[];
				static long Ans;
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
				static int MAX = 10000001;
				static int n , m ,k, max;
				static HashSet<Integer>[] hs;
				public static void soln() throws IOException {
					

					

					log = new BufferedWriter(new OutputStreamWriter(System.out));
					int n = sc.nextInt(), m = sc.nextInt();
					long arr[] = sc.id8(n);
					long brr[] = sc.id8(m);
					mergeSort(arr, 0 , n-1);
					mergeSort(brr, 0 , m-1);
					int j = 0;
					long sum1[] = new long[n];
					long sum2[] = new long[m];
					sum1[0] = arr[0];
					for(int i =1 ;i < n ;i ++) sum1[i] = sum1[i-1]+arr[i];
					sum2[m-1] = brr[m-1];
					for(int i =m-2 ;i >=0 ;i --) sum2[i] = sum2[i+1]+brr[i];
					int i = 0;
					long fa = Long.MAX_VALUE/2;
					while(i< n && j<m){
						if(arr[i]>=brr[j]){
							j++;
						}
						else{
							fa = Math.min(fa, sum2[j]-(m-j)*arr[i]+arr[i]*(i+1)-sum1[i]);
							i++;
						}
						

					}
					i = m-1; j= n-1;
					while(i>=0 && j>=0){
						if(brr[i]<=arr[j]){
							j--;
						}
						else{
							fa = Math.min(fa, sum2[i]-brr[i]*(m-i)-sum1[j]+(j+1)*brr[i]);
							i--;
						}
					}
					if(fa==Long.MAX_VALUE/2) System.out.println(0);
					else System.out.println(fa);
					log.close();
					

				} 
				public static void bfs(int x){
					b[x] = true;
					Random r = new Random();
					q = new LinkedList<Integer>();
					color[x] = r.nextInt(max)+1;
					hs[x].add(color[x]);
					q.add(x);
					while(!q.isEmpty()){
						

						int y = q.poll();
							for(int i:amp[y]){
							if(!b[i]){
								hs[i].add(color[y]);
								int d = r.nextInt(max)+1;
								while(hs[y].contains(d)) d = r.nextInt(max)+1;
								color[i] = d;
								hs[y].add(d);
								hs[i].add(d);
								q.add(i);
								b[i]= true;
							}
						}
					}
				}
				static int id9(int A[], int l, int r, int key)
			    {
			        while (r - l > 1)
			        {
			            int m = l + (r - l)/2;
			            if (A[m]>=key)
			                r = m;
			            else
			                l = m;
			        }
			 
			        return r;
			    }
			
				public static void mergeSort(long[] arr, int l ,int r){
					if((r-l)>=1){
						int mid = (l+r)/2;
						mergeSort(arr,l,mid);
						mergeSort(arr,mid+1,r);
						merge(arr,l,r,mid);
						

					}
				}
				public static void merge(long arr[], int l, int r, int mid){
					int n1 = (mid-l+1), n2 = (r-mid);
					long left[] = new long[n1];
					long right[] = new long[n2];
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
				

				public static int getParent(int x){
					while(parent[x]!=x){
						parent[x] = parent[ parent[x]];
						x = parent[ x];
					}
					return x;
				}
				static class Pair implements Comparable<Pair> {
					long u;
					long v;
					public Pair(long u, long v) {
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
					int arr[] = sc.id2(n);
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
						T[0] = -1;
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
							if (P[u][i] != -1 && P[u][i] != P[v][i]) 

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
				static long modInverse(long a, long id4){
				            return  power(a, id4-2, id4);
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
				public static void id3(long a, long b){
					if(b == 0) {
				        d = a;
				        x = 1;
				        y = 0;
				    }
				    else {
				        id3(b, a%b);
				        int temp = (int) x;
				        x = y;
				        y = temp - (a/b)*y;
				    }
				}
				
				public static long gcd(long n, long m){
					if(m!=0) return gcd(m,n%m);
					else return n;
				}
				static class id6 {

					private final InputStream stream;
					private final byte[] buf = new byte[8192];
					private int curChar, id1;
					private id7 filter;

					public id6(InputStream stream) {
						this.stream = stream;
					}

					public int snext() {
						if (id1 == -1)
							throw new InputMismatchException();
						if (curChar >= id1) {
							curChar = 0;
							try {
								id1 = stream.read(buf);
							} catch (IOException e) {
								throw new InputMismatchException();
							}
							if (id1 <= 0)
								return -1;
						}
						return buf[curChar++];
					}

					public int nextInt() {
						int c = snext();
						while (id0(c)) {
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
						} while (!id0(c));
						return res * sgn;
					}

					public long nextLong() {
						int c = snext();
						while (id0(c)) {
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
						} while (!id0(c));
						return res * sgn;
					}

					public int[] id2(int n) {
						int a[] = new int[n];
						for (int i = 0; i < n; i++) {
							a[i] = nextInt();
						}
						return a;
					}

					public long[] id8(int n) {
						long a[] = new long[n];
						for (int i = 0; i < n; i++) {
							a[i] = nextInt();
						}
						return a;
					}
			                
					public String readString() {
						int c = snext();
						while (id0(c)) {
							c = snext();
						}
						StringBuilder res = new StringBuilder();
						do {
							res.appendCodePoint(c);
							c = snext();
						} while (!id0(c));
						return res.toString();
					}

					public String nextLine() {
						int c = snext();
						while (id0(c))
							c = snext();
						StringBuilder res = new StringBuilder();
						do {
							res.appendCodePoint(c);
							c = snext();
						} while (!id5(c));
						return res.toString();
					}

					public boolean id0(int c) {
						if (filter != null)
							return filter.id0(c);
						return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
					}

					private boolean id5(int c) {
						return c == '\n' || c == '\r' || c == -1;
					}

					public interface id7 {
						public boolean id0(int ch);
					}
				}
			} 