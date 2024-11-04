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
import java.util.Scanner;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;

 
		public 	class Q2 {
				
				static long MOD = 1000000009;
				static boolean b1,b[],bc[];
				static boolean boo[][][];
				static int ans1 = -1,ans2 = -1, root;
				static ArrayList<Integer>[] amp,amp1;
				static ArrayList<Pair>[] pmp;
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
				static Pair prr[];
				static int dp[][];
				static long parent1[],parent2[],size1[],size2[],value[];
				static long Ans;
				public static void main(String[] args) throws Exception {
					
					soln();
			    }
				static int MAX = 1000005;
				static int n , m ,k, max, x1, x2;
				static HashSet<Pair> hs;
				public static void soln() throws IOException {
					

					

					log = new BufferedWriter(new OutputStreamWriter(System.out));
					int n = sc.nextInt();
					int temp = 0;
					hs = new HashSet<>();
					int arr[] = new int[n+1];
					amp = (ArrayList<Integer>[]) new ArrayList[n+1];
					for(int i = 0; i<=n;i++) amp[i] = new ArrayList<>();
					buildGraph((n*(n-1))/2-1);
					b = new boolean[n+1];
					for(int i = 1;i<=n;i++){
						for(int j = i+1;j<=n;j++){
							if(!hs.contains(new Pair(i,j))){
								dfs(i);
								if(b[j]){
									System.out.println(i+" "+j);
									return;
								}
								else{
									System.out.println(j+" "+i);return;
								}
							}
						}
					}
					log.close();
					

				}
				public static class id8 {
				    int[] array; 

				    public id8(int size) {
				        array = new int[size + 1];
				    }
				    public int rsq(int ind) {
				        assert ind > 0;
				        int sum = 0;
				        while (ind > 0) {
				            sum += array[ind];ind -= ind & (-ind);
				        }
				        return sum;
				    }
				    public int rsq(int a, int b) {
				        assert b >= a && a > 0 && b > 0;
				        return rsq(b) - rsq(a - 1);
				    }
				    public void update(int ind, int value) {
				        assert ind > 0;
				        while (ind < array.length) {
				            array[ind] += value; ind += ind & (-ind);
				        }
				    }
				    public int size() {
				        return array.length - 1;
				    }
				}
				public static void dfs(int x){
					b[x] = true;
					for(int e:amp[x]){
						if(!b[e]){
							dfs(e);
						}
					}
				}
				public static void bfs(int x){
					b[x] = true;
					q = new LinkedList<Integer>();
					q.add(x);
					while(!q.isEmpty()){
						

						int y = q.poll();
							for(int i:amp[y]){
							if(!b[i]){
								q.add(i);
								dist[i] = Math.max(dist[i], dist[y]+1);
								if(dist[i]>max){
									max = dist[i];
									k = i;
								}
								b[i]= true;
							}
						}
					}
				}
				static class Pair implements Comparable<Pair> {
					int u;
					int v;
					public Pair(){
						u = 0;
						v = 0;
					}
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
				
				public static int gcd(int n, int m){
					if(m!=0) return gcd(m,n%m);
					else return n;
				}
				
				static int id10(int A[], int l, int r, int key)
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
			
				public static void mergeSort(int[] arr2, int l ,int r){
					if((r-l)>=1){
						int mid = (l+r)/2;
						mergeSort(arr2,l,mid);
						mergeSort(arr2,mid+1,r);
						merge(arr2,l,r,mid);
						

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
							cnt[right[j]]+=(n1-i);
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
						amp[x].add(y);
						hs.add(new Pair(x,y));
						hs.add(new Pair(y,x));
					}
				}
				
				
 
				public static int getParent(int x){
					while(parent[x]!=x){
						parent[x] = parent[ parent[x]];
						x = parent[ x];
					}
					return x;
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
				
				
				static class id6 {
 
					private final InputStream stream;
					private final byte[] buf = new byte[8192];
					private int curChar, id1;
					private id7 filter;
					public int read() {
						if (id1 == -1)
							throw new InputMismatchException();
						if (curChar >= id1) {
							curChar = 0;
							try {
								id1 = System.in.read(buf);
							} catch (IOException e) {
								throw new InputMismatchException();
							}
							if (id1 <= 0)
								return -1;
						}
						return buf[curChar++];
					}
					public id6(InputStream stream) {
						this.stream = stream;
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
 
					public long[] id9(int n) {
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