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
	import java.util.PriorityQueue;
	import java.util.Queue;
		import java.util.Stack;
		import java.util.TreeMap;
		import java.util.TreeSet;
public	class Q2 {
			static int MOD = 1000000007;
			static boolean b[];
			static boolean boo[][];
			static int[][] pnt;
			static ArrayList<Integer>[] amp, amp2;
			static HashMap<ArrayList<Integer>,Integer> ts1 = new HashMap<>();
			static int sum[],dist[],array[];
			static long ans = 0;
			static int p = 0;
			static int color[][],brr[][];
			static HashSet<Integer>[][] hrr;
			static HashSet<Integer>[] hmp;
			static id10 sc = new id10();
			static Queue<Integer> q = new LinkedList<>();
			static Queue<Pair> qu = new LinkedList<>();
			static ArrayList<Pair>[][] arr;
			static ArrayList<Graph>[] amp1;
			static ArrayList<Integer> parent = new ArrayList<>();
			static BufferedWriter log;
			static TreeMap<Integer,LinkedList<Pair>> tm;
			static HashSet<Integer> hs;
			static Stack<Integer> s = new Stack<>();
			static Pair prr[];
			static char ch[];
			static int prime[];
			static int d,x,y;
			static int n,k,m;
			public static void main(String[] args) throws IOException {
				log = new BufferedWriter(new OutputStreamWriter(System.out));
				int n = sc.nextInt(), k = sc.nextInt(), a = sc.nextInt(), b = sc.nextInt();
				int q = sc.nextInt();
				

				

				SegmentTree st1 = new SegmentTree(n,b);
				SegmentTree st2 = new SegmentTree(n,a);
				while(q-->0){
					int t = sc.nextInt();
					if(t==1){
						int d = sc.nextInt(), v = sc.nextInt();
					

					

						st1.update(1, n, 1, d, v);
						st2.update(1, n, 1, d, v);
						

					}
					else{
						int p = sc.nextInt();
						long ans1 = 0, ans2 = 0;
						if(p>1)
						ans1 = st1.get(1, p-1, 1, n, 1);
						if(p+k<=n)
						ans2 = st2.get(p+k, n, 1, n, 1);
						

						log.write(ans2+ans1+"\n");
					}
				}
				log.close();
			}
			public static int getParent(int x, int parent[]){
				while(parent[x]!=x){
					parent[x] = parent[parent[x]];
					x = parent[x];
				}
				return x;
			}
			public static void factors(int n){
				b = new boolean[n+1];
				prime = new int[n+1];
				Arrays.fill(b, true);
				b[0] =false;
				b[1] = false;
				for(int i = 2;i*i<=n;i++){
					if(b[i]){
						prime[i] = i;
						for(int p = 2*i;p<=n;p+=i){
							if(b[p]){
							b[p] = false;
							prime[p] = i;
							}
						}
					}
				}
				for(int i = 2;i<=n;i++){
					if(b[i]) prime[i] = i;
				}
			}
			public static void id6(int x1,int y1){
				boo[x1][y1] = true;
				qu.add(new Pair(x1,y1));
				while(!qu.isEmpty()){
					Pair p = qu.poll();
					

					for(Pair e:arr[p.u][p.v]){
						if(!boo[e.u][e.v]){
							boo[e.u][e.v] = true;
							if(e.u==x && e.v==y) break;
							qu.add(e);
						}
					}
				}
			}
			public static void id1(int arr[][],int row, int column){
				for(int i = 0;i<row;i++){
					for(int j = 0;j<column;j++){
						System.out.print(arr[i][j]+" ");
					}
					System.out.println();
				}
			}
			public static void dfs(int x){
				b[x] = true;
				for(int i =0 ;i<amp[x].size();i++){
					if(!b[amp[x].get(i)]){
						dfs(amp[x].get(i));
					}
				}
			}
			
			public static void bfs(int x){
				b[x] = true;
				q = new LinkedList<>();
				q.add(x);
				while(!q.isEmpty()){
					int y = q.poll();
					for(int i = 0;i<amp[y].size();i++) {
						if(!b[amp[y].get(i)]){
							q.add(amp[y].get(i));
							b[amp[y].get(i)] = true;
						}
					}
				}
			}
			public static void toThread(String[] args) throws Exception {
		    	new Thread(null, new Runnable() {
					public void run() {
						try {
							

					       

					        

					        

							

						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				}, "1", 1 << 26).start();
		    }
			public static long mod(int x, int y){
				long ans = 1;
				while(y>0){
					if(y%2==1){
						ans = ((ans%MOD)*(x%MOD))%MOD;
						y-=1;
					}
					else{
						x = (int) (((x%MOD)*(x%MOD))%MOD);
						y = y/2;
					}
				}
				return ans;
			}
			static void findFactors(ArrayList<Integer> id9, ArrayList<Integer> multiplicity, int id0, long currentResult) {
			    if (id0 == id9.size()) {
			      

			        return;
			    }
			    for (int i = 0; i <= multiplicity.get(id0); ++i) {
			        findFactors(id9, multiplicity, id0 + 1, currentResult);
			        currentResult *= id9.get(id0);
			    }
			}
			public static void seive(long n){
				b = new boolean[(int) (n+1)];
				Arrays.fill(b, true);
				b[0] =false;
				b[1] = true;
				for(int i = 2;i*i<=n;i++){
					if(b[i]){
						for(int p = 2*i;p<=n;p+=i){
							b[p] = false;
						}
					}
				}
				for(int i = 0;i<n;i++) if(b[i]) parent.add(i);
			}
			
			public static void id2(int m){
				for(int i = 0; i<m;i++){
					int x = sc.nextInt(), y = sc.nextInt(), w = sc.nextInt();
					amp1[--x].add(new Graph(--y,w));
					amp1[y].add(new Graph(x,w));
				}
			}
			private static void permutation(String prefix, String str) {
			    int n = str.length();
			   

			  

			        for (int i = 0; i < n; i++)
			            permutation(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n));
			   

			}
			public static char give(char c1,char c2){
				if(c1!='a' && c2!='a') return 'a';
				if(c1!='b' && c2!='b') return 'b';
				return 'c';
			}
			static class Graph{
				int vertex;
				long weight;
				Graph(int v,int w){
					vertex = v;
					weight = w;
				}
			}
			public static void buildTree(int n){
				int arr[] = sc.id5(n);
				for(int i = 0;i<n;i++){
					int x = arr[i]-1;
					amp[i+1].add(x);
					amp[x].add(i+1);
				}
			}
			
				
			public static void buildGraph(int n){
				
				for(int i =0;i<n;i++){
					int x = sc.nextInt(), y = sc.nextInt();
					amp[--x].add(--y);
					

				}
			}
				
			
			static class Pair implements Comparable<Pair> {
				int u;
				int v;
				int z;
				public Pair(){
					
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
					return Integer.compare(other.u, u) != 0 ? (Integer.compare(other.u, u)) : (Integer.compare(v, other.v));
				}
				
				public String toString() {
					return "[u=" + u + ", v=" + v + "]";
				}
			}
			static class SegmentTree{
				long st[];
				boolean lazy[];
				int y;
				SegmentTree(int n, int y){
					int size = 4*n;
					st = new long[size];
					

					this.y = y; 
				}
				
				long get(int qs, int qe, int ss, int se, int si){
					if(qe<ss || qs>se){
						return 0;
					}
					if(qs<=ss && qe>=se) return st[si];
					int mid = (ss+se)/2;
		            return (get(qs,qe,ss,mid,2*si)+get(qs,qe, mid+1, se, 2*si+1));
				}
				void update(int ss,int se,int si,int idx, int value){
					if(ss==se){
						st[si]= Math.min(value+st[si],y);
						

					}
					else{
						int mid = (ss+se)/2;
						if(ss<=idx && idx<=mid) update(ss,mid,2*si,idx,value);
						else update(mid+1,se,2*si+1,idx,value);
						st[si] = (st[2*si]+st[2*si+1]);
					}
				}
				void print(){
					for(int i = 0;i<st.length;i++){
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
			static class Node{
				int data;
				Node arr[] = new Node[2];
				Node(){
					data = 0;
					arr[0] = null;
					arr[1] = null;
				}
			}
			static class Trie{
				 Node root = new Node();
				public  void insert(int y){
					int qrr[] = new int[30];
					Node temp = root;
					int x = y;
					for(int i =0 ; i<= 29;i++){
						qrr[i] = x%2;
						x/=2;
					}
					for(int i = 29;i>=0;i--){
						if(temp.arr[qrr[i]] != null){
							temp = temp.arr[qrr[i]];
						}
						else{
							temp.arr[qrr[i]] = new Node();
							temp = temp.arr[qrr[i]];
						}
					}
					temp.data = y;
				}
				public  int query(int y){
					int qrr[] = new int[30];
					Node temp = root;
					int x = y;
					for(int i =0 ; i< 30;i++){
						qrr[i] = x%2;
						x/=2;
					}
					for(int i = 29;i>=0;i--){
						if(temp.arr[1-qrr[i]] != null){
							temp = temp.arr[1-qrr[i]];
						}
						else {

							temp = temp.arr[qrr[i]];
						}
					}
					return temp.data^y;
				}
			}
			static class id4{
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
			
			
			public static long gcd(long n, long m){
				if(m!=0) return gcd(m,n%m);
				else return n;
			}
			
			
			public static class id10 {
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
					while (id3(c))
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
					while (id3(c))
						c = read();
					StringBuilder res = new StringBuilder();
					do {
						res.appendCodePoint(c);
						c = read();
					} while (!id3(c));
					return res.toString();
				}
		 
				public long nextLong() {
					int c = read();
					while (id3(c))
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
					} while (!id3(c));
					return res * sgn;
				}
		 
				public int nextInt() {
					int c = read();
					while (id3(c))
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
					} while (!id3(c));
					return res * sgn;
				}
			        
			    public int[] id5(int n) {
			        return id5(n, 0);
			    }
			    
			    public int[] id5(int n, int off) {
			    	int[] arr = new int[n + off];
			    	for (int i = 0; i < n; i++) {
			    		arr[i + off] = nextInt();
			    	}
			    	return arr;
			    }
			    
			    public long[] id11(int n) {
			    	return id11(n, 0);
			    }
		        
				public long[] id11(int n, int off) {
				    long[] arr = new long[n + off];
				    for (int i = 0; i < n; i++) {
				        arr[i + off] = nextLong();
				    }
				    return arr;
				}
		 
			    private boolean id3(int c) {
					return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
				}
		 
				private boolean id8(int c) {
					return c == '\n' || c == '\r' || c == -1;
				}
			}
		}