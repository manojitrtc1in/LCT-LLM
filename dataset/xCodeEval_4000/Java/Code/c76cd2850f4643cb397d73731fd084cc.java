import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
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
		static boolean b[], b1[], check;
		static ArrayList<Integer>[] amp, pa;
		static ArrayList<Graph>[] amp1;
		static int left[],s[],right[],sum[],dist[],cnt[],start[],color[],parent[],prime[],size[];
		static long ans = 0,k;
		static int p = 0;
		static FasterScanner sc = new FasterScanner(System.in);
		static Queue<Pair> queue = new LinkedList<>();
		static PriorityQueue<Integer> pq;
		static BufferedWriter log;
		static HashSet<Integer>[] hs;
		static HashMap<String,Integer> hm;
		static HashMap<Pair,Integer> hmp;
		static Stack<Integer> st;
		static Pair prr[];
		static long parent1[],parent2[],size1[],size2[],arr1[],SUM[],MAX[];
		static int arr[];
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
		static long dp[], fact[];
		static char ch[];
		static int N,K;
		public static void soln() throws IOException {
			

			

			log = new BufferedWriter(new OutputStreamWriter(System.out));
			String str = sc.nextLine();
			ch = str.toCharArray();
			int n = ch.length;
			SegmentTree st = new SegmentTree(str.length());
			long ans = 0;
			fact = new long[500001];
			fact[0] = 1;
			for(int i = 1; i<=500000;i++){
				fact[i] = (fact[i-1]*i)%MOD;
			}
			for(int i = 0; i<n;i++){
				if(ch[i]=='('){
					long a1 = st.get(0, i-1, 0, n-1, 1).u, a2 = st.get(i+1, n-1, 0, n-1, 1).v;
					ans = (ans+ncr(a1+a2,a2-1))%MOD;
				}
			}
			System.out.println(ans);
			log.close();
			

		}
		static long ncr(long a, long b){
			if(b>a || b<0) return 0;
			long f = (fact[(int) a]*modInverse(((fact[(int) b]*fact[(int) (a-b)])%MOD), MOD))%MOD;
			return f;
		}
		static void recur(String str, int i, int n) throws IOException{
			

			String s = str+(char)(i+'a')+"";
			if(n==N){
				log.write(s+"\n");
				return;
			}
			if(b[i]){
				for(int j = 0;j<26;j++){
					

					if(!b[j] && j!=('y'-'a')){
						

						recur(s,j,n+1); 
					}
				}
			}
			else{
				for(int j = 0;j<26;j++){
					if(b[j]){
					

						recur(s,j,n+1); 
					}
				}
			}
		}
		static void dfs(int x){
			long sum = 0, max = Long.MIN_VALUE;
			b[x] = true;
			

			PriorityQueue<Long> pq=new PriorityQueue<>(10,Collections.reverseOrder());
			if(amp[x].size()>2) check = true;
			for(int i:amp[x]){
				if(!b[i]){
					parent[i] = x;
					dfs(i);
					sum+=SUM[i];
					max = Math.max(max, MAX[i]);
					pq.add(MAX[i]);
				}
			}
			SUM[x] = sum+arr[x];
			MAX[x] = Math.max(SUM[x],max);
			if(pq.size()>=2){
				ans = Math.max(ans, pq.poll()+pq.poll());
			}
			
		}
		public static void buildWeightedGraph(int n){
			for(int i =0 ;i< n; i++){
				int x = sc.nextInt(), y = sc.nextInt(), w = sc.nextInt();
				amp1[--x].add(new Graph(--y,w));
				amp1[y].add(new Graph(x,w));
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
			public Pair(){
				u = 0;v = 0;
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
				return ((u == other.u && v == other.v));
			}
	 
			public int compareTo(Pair other) {
				return Long.compare(u, other.u)!= 0 ? (Long.compare(u, other.u)) : (Long.compare(v, other.v));
			}
			
			public String toString() {
				return "[u=" + u + ", v=" + v + "]";
			}
		}
		
		public static void buildGraph(int n){
			for(int i =0;i<n;i++){
				int x = sc.nextInt()-1, y = sc.nextInt()-1;
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
			Pair st[];
			boolean lazy[];

			SegmentTree(int n) {
				int size = 4 * n;
				st = new Pair[size];
				for(int i = 0; i< size;i++) st[i] = new Pair();
				

				

				build(0, n - 1, 1);
			}
			
			Pair build(int ss, int se, int si) {
				if (ss == se) {
					if(ch[ss]=='('){
						st[si].u = 1;
					}
					else st[si].v = 1;
					return st[si];
				}
				int mid = (ss + se) / 2;
				Pair a1 = build(ss, mid, si * 2), a2 = build(mid + 1, se,
						si * 2 + 1);
				st[si].u = a1.u+a2.u; st[si].v = a2.v+a1.v;
				return st[si];
			}

			
			Pair get(int qs, int qe, int ss, int se, int si){
				if(qs>se || qe<ss) return new Pair(0,0);
				if (qs <= ss && qe >= se) {
					return st[si];
				}
				int mid = (ss+se)/2;
				Pair a1 = get(qs, qe, ss, mid, si * 2), a2 = get(qs, qe, mid + 1, se, si * 2 + 1);
				return new Pair(a1.u+a2.u,a1.v+a2.v);
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
	
	
	   
	    static class FasterScanner {

			private final InputStream stream;
			private final byte[] buf = new byte[8192];
			private int curChar, snumChars;
			private SpaceCharFilter filter;

			public FasterScanner(InputStream stream) {
				this.stream = stream;
			}

			public int snext() {
				if (snumChars == -1)
					throw new InputMismatchException();
				if (curChar >= snumChars) {
					curChar = 0;
					try {
						snumChars = stream.read(buf);
					} catch (IOException e) {
						throw new InputMismatchException();
					}
					if (snumChars <= 0)
						return -1;
				}
				return buf[curChar++];
			}

			public int nextInt() {
				int c = snext();
				while (isSpaceChar(c)) {
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
				} while (!isSpaceChar(c));
				return res * sgn;
			}

			public long nextLong() {
				int c = snext();
				while (isSpaceChar(c)) {
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
				} while (!isSpaceChar(c));
				return res * sgn;
			}

			public int[] nextIntArray(int n) {
				int a[] = new int[n];
				for (int i = 0; i < n; i++) {
					a[i] = nextInt();
				}
				return a;
			}

			public long[] nextLongArray(int n) {
				long a[] = new long[n];
				for (int i = 0; i < n; i++) {
					a[i] = nextInt();
				}
				return a;
			}
	                
			public String readString() {
				int c = snext();
				while (isSpaceChar(c)) {
					c = snext();
				}
				StringBuilder res = new StringBuilder();
				do {
					res.appendCodePoint(c);
					c = snext();
				} while (!isSpaceChar(c));
				return res.toString();
			}

			public String nextLine() {
				int c = snext();
				while (isSpaceChar(c))
					c = snext();
				StringBuilder res = new StringBuilder();
				do {
					res.appendCodePoint(c);
					c = snext();
				} while (!isEndOfLine(c));
				return res.toString();
			}

			public boolean isSpaceChar(int c) {
				if (filter != null)
					return filter.isSpaceChar(c);
				return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
			}

			private boolean isEndOfLine(int c) {
				return c == '\n' || c == '\r' || c == -1;
			}

			public interface SpaceCharFilter {
				public boolean isSpaceChar(int ch);
			}
		}
	}  