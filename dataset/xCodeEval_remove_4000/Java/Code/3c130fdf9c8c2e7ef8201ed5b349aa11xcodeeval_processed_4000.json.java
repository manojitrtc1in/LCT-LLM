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
import java.util.Objects;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;
	
		
		
		
		
			public class Q2 {
				
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
				static BufferedWriter log;
				static HashSet<Pair> hs;
				static HashMap<Pair,Integer> hm;
				static PriorityQueue<Integer> pri[];
				static ArrayList<Integer>[] level;
				static Stack<Integer> st;
				static boolean boo[][];
				static Pair prr[];
				static long parent1[],parent2[],size1[],size2[],arr1[],SUM[],lev[], fibo[];
				static int arr[], ver[][];
				public static void main(String[] args) throws Exception {
			    	
					soln();
				}
				static long dp[][];
				static int N,K,T,A,B;
				static int time;
				static int cost[][];
				static boolean b11[];
				static HashMap<Integer,Integer> h = new HashMap<>();
				static HashSet<Pair> chec;
				static long ans1;		static long ans2;
				static int BLOCK, MAX = 200000;
				static double pi = Math.PI;
				static int Arr[], Brr[], pow[],  M;
				static long fact[] = new long[100000+1];
				static HashMap<Pair,Integer> hm1;
				static HashSet<Integer> hs1[], hs2[];
				static PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
				public static void soln() throws IOException {
					

					

					log = new BufferedWriter(new OutputStreamWriter(System.out));
					int n = sc.nextInt();
					int arr[] = sc.id4(n);
					HashSet<Integer> hs = new HashSet<>();
					HashSet<Integer> ms = new HashSet<>();
					hs.add(arr[0]);ms.add(arr[0]);
					for(int i = 1; i< n ;i ++){
						HashSet<Integer> temp = new HashSet<>();
						for(int j : hs) temp.add(j|arr[i]);
						hs = temp;
						hs.add(arr[i]);
						for(int j : hs) ms.add(j);
					}
					System.out.println(ms.size());
					log.close();
					

				}
				public static class id10 {
					
				    int[] array; 

	
				    public id10(int size) {
				        array = new int[size + 1];
				    }
				    public int rsq(int ind) {
				        assert ind > 0;
				        int sum = 0;
				        while (ind > 0) {
				            sum += array[ind];
				            

				            ind -= ind & (-ind);
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
				            array[ind] += value;
				            

				            ind += ind & (-ind);
				        }
				    }
	
				    public int size() {
				        return array.length - 1;
				    }
				}
				static double power(double x, long y)
				{
				    if (y == 0)
				        return 1;
				    double p = power(x, y/2);
				    p = (p * p);
				 
				    return (y%2 == 0)? p : (x * p);
				}
				static void Bfs(int x){
					q.add(x);
					b[x] = true;
					while(!q.isEmpty()){
						int y = q.poll();
						b[y] = true;
						for(int p:hs2[y]){
							if(!b[p]){
								if(!hs1[y].contains(p)) dist[p] = dist[y]-1;
								else dist[p] = dist[y]+1;
								q.add(p);
							}
						}
					}
				}
				static int Dfs(int x, int val){
					b[x] = true;
					for(int p:hs2[x]){
						if(!b[p]){
							if(!hs1[x].contains(p)) val++;
							val += Dfs(p,0);
						}
					}
					return val;
				}
				static long nCr(int n, int r){
					if(n<r) return 0;
					else return (((fact[n]*modInverse(fact[r], MOD))%MOD)*modInverse(fact[n-r], MOD))%MOD;
				}
				static void dfs1(int x, int p){
					arr1[x] += lev[x];
					for(int v:amp[x]){
						if(v!=p){
							dfs1(v,x);
						}
					}
				}
				static void bfs(){
					q = new LinkedList<>();
					q.add(0);
					while(!q.isEmpty()){
						int y = q.poll();
						b[y] = true;
						level[dist[y]].add(start[y]);
						for(int x:amp[y]){
							if(!b[x]){
								q.add(x);
								dist[x] = 1+dist[y];	
							}
						}
					}
				}
				static void dfs(int x, int p){
					start[x] = time++;
					for(int v:amp[x]){
						if(v!=p){
							dfs(v,x);
						}
					}
					end[x] = time;
				}
				
				
				static void bfs(int x){
					
				}
				public static void seive(int n){
					b = new boolean[(n+1)];
					Arrays.fill(b, true);
					b[1] = true;
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
					long v;
					double ans;
					public Pair(){
						u = 0;
						v = 0;
					}
					public Pair(long u, long v) {
						this.u = u;
						this.v = v;
					}
					public int hashCode() {
						return Objects.hash();
					}
					public boolean equals(Object o) {
						Pair other = (Pair) o;
						return ((u == other.u && v == other.v));
					}
			 
					public int compareTo(Pair other) {
						return Double.compare(ans, other.ans);
						

					}
					
					public String toString() {
						return "[u=" + u + ", v=" + v + "]";
					}
				}
				
				public static void buildGraph(int n){
					for(int i =0;i<n;i++){
						int x = sc.nextInt()-1, y = sc.nextInt()-1;
						

						hs1[x].add(y);
						hs2[y].add(x);
						hs2[x].add(y);
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
				
				 static void id12(String pat, String txt)
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
		
					public long[] id11(int n) {
						long a[] = new long[n];
						for (int i = 0; i < n; i++) {
							a[i] = nextLong();
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