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
			static FasterScanner sc = new FasterScanner();
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
				int n = sc.nextInt(), m = sc.nextInt();
				char ch[][] = new char[n][m];
				for(int i =0;i<n;i++) ch[i] = sc.nextLine().toCharArray();
				int x1 = sc.nextInt()-1, x2 = sc.nextInt()-1;
				x = sc.nextInt()-1; y = sc.nextInt()-1;
				if(n==1 && m==1){
					System.out.println("NO");
					System.exit(0);
				}
				arr = (ArrayList<Pair>[][]) new ArrayList[n][m];
				for(int i = 0;i < n; i++){
					for(int j = 0;j<m;j++){
						arr[i][j] = new ArrayList<>();
						if(ch[i][j]=='.' || (i==x1 && j==x2)){
							if(i>0 && (ch[i-1][j]=='.' || (x==i-1 && y==j))) arr[i][j].add(new Pair(i-1,j));
							if(i<n-1 && (ch[i+1][j]=='.' || (x==i+1 && y==j))) arr[i][j].add(new Pair(i+1,j));
							if(j>0 && (ch[i][j-1]=='.' || (x==i && y==j-1))) arr[i][j].add(new Pair(i,j-1));
							if(j<m-1 && (ch[i][j+1]=='.' || (x==i && y==j+1))) arr[i][j].add(new Pair(i,j+1));
						}
					}
				}
				boo = new boolean[n][m];
				pnt = new int[n][m];
				bfs2D(x1,x2);
				
				if(boo[x][y]){
					if(x1==x && x2==y){
						if(x>0 && ch[x-1][y]=='.') System.out.println("YES");
						else if(x<n-1 && ch[x+1][y]=='.') System.out.println("YES");
						else if(y>0 && ch[x][y-1]=='.') System.out.println("YES");
						else if(y<m-1 && ch[x][y+1]=='.') System.out.println("YES");
						else System.out.println("NO");
					}
					else if((Math.abs(x1-x)+Math.abs(x2-y))==1){
						if(ch[x][y]=='X') System.out.println("YES");
						else{
							if(x>0 && ch[x-1][y]=='.') System.out.println("YES");
							else if(x<n-1 && ch[x+1][y]=='.') System.out.println("YES");
							else if(y>0 && ch[x][y-1]=='.') System.out.println("YES");
							else if(y<m-1 && ch[x][y+1]=='.') System.out.println("YES");
							else System.out.println("NO");
						}
						
					}
					else{
						if(ch[x][y]=='X'){
							if(x>0 && ch[x-1][y]=='.') System.out.println("YES");
							else if(x<n-1 && ch[x+1][y]=='.') System.out.println("YES");
							else if(y>0 && ch[x][y-1]=='.') System.out.println("YES");
							else if(y<m-1 && ch[x][y+1]=='.') System.out.println("YES");
							else System.out.println("NO");
						}
						else{
							int cnt = 0;
							if(x>0 && ch[x-1][y]=='.') cnt++;
							if(x<n-1 && ch[x+1][y]=='.') cnt++;
							if(y>0 && ch[x][y-1]=='.') cnt++;
							if(y<m-1 && ch[x][y+1]=='.') cnt++;
							if(cnt>=2) System.out.println("YES");
							else System.out.println("NO");
						}
					}
				}
				else System.out.println("NO");
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
			public static void bfs2D(int x1,int y1){
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
			public static void print2DArray(int arr[][],int row, int column){
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
			static void findFactors(ArrayList<Integer> primeDivisors, ArrayList<Integer> multiplicity, int currentDivisor, long currentResult) {
			    if (currentDivisor == primeDivisors.size()) {
			      

			        return;
			    }
			    for (int i = 0; i <= multiplicity.get(currentDivisor); ++i) {
			        findFactors(primeDivisors, multiplicity, currentDivisor + 1, currentResult);
			        currentResult *= primeDivisors.get(currentDivisor);
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
			
			public static void buildWeightedGraph(int m){
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
				int arr[] = sc.nextIntArray(n);
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
				int st[][];
				boolean lazy[];
				SegmentTree(int n){
					int size = 4*n;
					st = new int[size][2];
					lazy = new boolean[size];
					build(0,n-1,1);
				}
				int[] build(int ss, int se, int si){
					if(ss==se){
						if(ch[ss]=='<') st[si][0]++;
						else st[si][1]++;
						return st[si];
					}
					int mid = (ss+se)/2;
					int[] a1 = build(ss,mid,si*2), a2 = build(mid+1,se,si*2+1);
					st[si][0] = a1[0]+a2[0];
					st[si][1] = a1[1]+a2[1];
					return st[si];
				}
				void updateRange(int node, int start, int end, int l, int r, boolean val)
				{
				

				    if(lazy[node])
				    { 
				        

				    	

				    	

				    	

				        if(start != end)
				        {
				        	lazy[node*2+1] = !lazy[node*2+1];                  

				            lazy[node*2] = !lazy[node*2];               

				        }
				        lazy[node] = false;                                  

				    }
				    if(start > end || start > r || end < l)              

				        return;
				    if(start >= l && end <= r)
				    {
				        

				    	int temp = st[node][0];
				    	st[node][0] = st[node][1];
				    	st[node][1] = temp;
				        if(start != end)
				        {
				            

				        	lazy[node*2+1] = !lazy[node*2+1];                  

				            lazy[node*2] = !lazy[node*2]; 
				        }
				    	
				        return;
				    }
				    int mid = (start + end) / 2;
				    updateRange(node*2, start, mid, l, r, val);        

				    updateRange(node*2 + 1, mid + 1, end, l, r, val);   

				    st[node][0] = st[node*2][0] + st[node*2+1][0];
				    st[node][1] = st[node*2][1] + st[node*2+1][1];

				}
				int[] queryRange(int node, int start, int end, int l, int r)
				{
				    if(start > end || start > r || end < l)
				        return new int[]{0,0};         

				    if(lazy[node])
				    {
				    	int temp = st[node][0];
				    	st[node][0] = st[node][1];
				    	st[node][1] = temp; 

				        if(start != end)
				        {
				        	lazy[node*2+1] = !lazy[node*2+1];                  

				            lazy[node*2] = !lazy[node*2];               

				        }
				        lazy[node] = false;                  

				    }
				    if(start >= l && end <= r)             

				        return st[node];
				    int mid = (start + end) / 2;
				    int p1[] = queryRange(node*2, start, mid, l, r);         

				    int p2[] = queryRange(node*2 + 1, mid + 1, end, l, r); 

				    p1[0]+=p2[0];
				    p1[1]+=p2[1];
				    return p1;
				}
			void print(){
					for(int i = 0;i<st.length;i++){
						System.out.println(st[i][0]+" "+st[i][1]);
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
			
			
			public static long gcd(long n, long m){
				if(m!=0) return gcd(m,n%m);
				else return n;
			}
			
			
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