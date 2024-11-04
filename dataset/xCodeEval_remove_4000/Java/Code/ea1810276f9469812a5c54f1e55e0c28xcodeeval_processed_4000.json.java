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
			static ArrayList<Integer>[] amp, amp2;
			static HashMap<ArrayList<Integer>,Integer> ts1 = new HashMap<>();
			static int sum[][],dist[][];
			static long ans = 0;
			static int p = 0;
			static int color[][];
			static id9 sc = new id9();
			static Queue<Integer> q = new LinkedList<>();
			static Queue<Pair> qu = new LinkedList<>();
			static ArrayList<Pair>[][] arr;
			static ArrayList<Graph>[] amp1;
			static ArrayList<Integer> parent = new ArrayList<>();
			static BufferedWriter log;
			static HashMap<Long,Long> hm;
			static TreeSet<Long> ts = new TreeSet<>();
			static Stack<Integer> s = new Stack<>();
			static Pair prr[];
			static char ch[][];
			static int prime[];
			static long d,x,y;
			static int n,k,m;
			public static void main(String[] args) throws IOException {
				log = new BufferedWriter(new OutputStreamWriter(System.out));
				int n = sc.nextInt(), k = sc.nextInt();
				k = Math.min(k, n-k);
				SegmentTree st = new SegmentTree(n);
				int z = 0;
				ans = 1;
				for(int i = 0;i<n;i++){
					int temp = (z+k)%n;
					st.update(0, n-1, 0, temp);
					st.update(0, n-1, 0, z);
					

					if(z+1<=temp){
					ans+=st.get(z+1, temp, 0, n-1, 0);
					}
					else{
						ans+=(st.get(0, n-1, 0, n-1, 0)-st.get(temp+1, z, 0, n-1, 0));
					}
					if(i==n-1) ans--;
					log.write(ans+" ");
					z = temp;
				}
				log.close();
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
				q.add(x);
				while(!q.isEmpty()){
					ans++;
					int y = q.poll();
					for(int i = 0;i<amp[y].size();i++) {
						if(!b[amp[y].get(i)]){
							q.add(amp[y].get(i));
							b[amp[y].get(i)] = true;
							prime[amp[y].get(i)] = y;
						}
						else{
							if(amp[y].get(i)!=prime[y]) p++;
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
			public static void dfs2(int x, int y){
				boo[x][y] = true;
				ans++;
				if(ans==(p-k)){
					return;
				}
				for(Pair e:arr[x][y]){
					if(!boo[e.u][e.v]){
						dfs2(e.u,e.v);
						if(ans==(p-k)){
							return;
						}
					}
				}
			}
		
			static void findFactors(ArrayList<Integer> id8, ArrayList<Integer> multiplicity, int id0, long currentResult) {
			    if (id0 == id8.size()) {
			        ts.add(currentResult);
			        return;
			    }
			    for (int i = 0; i <= multiplicity.get(id0); ++i) {
			        findFactors(id8, multiplicity, id0 + 1, currentResult);
			        currentResult *= id8.get(id0);
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
			public static void id1(int m){
				for(int i = 0; i<m;i++){
					int x = sc.nextInt(), y = sc.nextInt(), w = sc.nextInt();
					amp1[--x].add(new Graph(--y,w));
					amp1[y].add(new Graph(x,w));
				}
			}
			public static void id5(long a, long b){
				if(b == 0) {
			        d = a;
			        x = 1;
			        y = 0;
			    }
			    else {
			        id5(b, a%b);
			        int temp = (int) x;
			        x = y;
			        y = temp - (a/b)*y;
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
				int arr[] = sc.id4(n);
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
					amp[y].add(x);
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
					return Integer.compare(u, other.u) != 0 ? (Integer.compare(u, other.u)) : (Integer.compare(v, other.v));
				}
				
				public String toString() {
					return "[u=" + u + ", v=" + v + "]";
				}
			}
			static class SegmentTree{
				long st[];
				char ch[];
				boolean lazy[];
				SegmentTree(int n){
					int size = 4*n;
					

					st = new long[size];
					lazy = new boolean[size];
					build(ch,0,n-1,0);
				}
				long build(char str[], int ss, int se, int si){
					if(ss==se){
						return 0;
					}
					int mid = (ss+se)/2;
					 st[si] = build(str,ss,mid,si*2+1) + build(str,mid+1,se,si*2+2);
					
					return st[si];
				}
				

				long get(int qs, int qe, int ss, int se, int si){
					if(qe<ss || qs>se){
						return 0;
					}
					if(qs<=ss && qe>=se) return st[si];
					int mid = (ss+se)/2;
		            return (get(qs,qe,ss,mid,2*si+1)+get(qs,qe, mid+1, se, 2*si+2));
				}
				void update(int ss,int se,int si,int idx){
					if(ss==se){
						st[si]++;
						

					}
					else{
						int mid = (ss+se)/2;
						if(ss<=idx && idx<=mid) update(ss,mid,2*si+1,idx);
						else update(mid+1,se,2*si+2,idx);
						st[si] = (st[2*si+1]+st[2*si+2]);
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
			
			
			static long modInverse(long a, long id6){
			            return  power(a, id6-2, id6);
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
					} while (!id7(c));
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
		 
				private boolean id7(int c) {
					return c == '\n' || c == '\r' || c == -1;
				}
			}
		}