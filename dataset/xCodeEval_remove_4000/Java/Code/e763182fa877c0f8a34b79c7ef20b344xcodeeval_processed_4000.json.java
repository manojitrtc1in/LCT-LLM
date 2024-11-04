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
import java.util.Iterator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;
import java.util.SortedSet;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;

public class Q21 {
	static int MOD = 1000000007;
	static boolean b[],b1[], c1 = false;
	static int m, bo, c, di;
	static ArrayList<Integer>[] amp;
	static ArrayList<Integer>[][] amp2;
	static long sum[], dist[], arr[], cnt[];
	static long pow[], ans = 0;
	static int p = 10000, time = 0, p1 = -1, p2 = -1;
	static id8 sc = new id8();
	static Queue<Integer> q = new LinkedList<>();
	static ArrayList<Pair>[] amp1;
	static int arr1[];
	static ArrayList<Integer> parent = new ArrayList<>();
	static BufferedWriter log;
	static HashMap<Pair, Integer> hm;
	static HashSet<Integer> hs = new HashSet<>();
	static TreeMap<Integer, Pair> hsm;
	static Stack<Integer> s = new Stack<>();
	static Pair prr[];
	static Random r = new Random();
	static long dp[];
	static int MAX = (int) 1e7;
	public static void main(String[] args) throws IOException {
		log = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = sc.nextInt(), m = sc.nextInt();
		amp = (ArrayList<Integer>[]) new ArrayList[n];
		for(int i = 0; i< n; i++) amp[i] =new ArrayList<>();
		buildGraph(m);
		b = new boolean[n];
		for(int i = 0 ;i<n;i++){
			if(!b[i] && amp[i].size()>1){
				ans = 0;p = 0;
				bfs(i);
				

				if(ans != (1L*p*(p-1))){
					System.out.println("NO");return;
				}
			}
		}
		System.out.println("YES");
		log.close();
	}

	public static void bfs(int x) {
		b[x] = true;
		q = new LinkedList<Integer>();
		q.add(x);
		while (!q.isEmpty()) {
			int y = q.poll();
			p++;
			ans+=amp[y].size();
			for (int i = 0; i < amp[y].size(); i++) {
				if (!b[amp[y].get(i)]) {
					q.add(amp[y].get(i));
					b[amp[y].get(i)] = true;
				}
			}
		}
	}
	public static void dfs(int x) {
		b[x] = true;
		for (int i = 0; i < amp[x].size(); i++) {
			if (!b[amp[x].get(i)]) {
				dfs(amp[x].get(i));
			}
		}
	}
	public int[] findMoves(int[] start){
		int n = start.length;
		int i = 0;
		ArrayList<Integer> amp = new ArrayList<>();
		while(i<n-1){
			if(start[i]==0){
				i++;continue;
			}
			int temp = start[i];
			start[i] = 0;
			int j = i+1;
			amp.add(i+1);
			while(temp>0){
				start[j%n]++;
				temp--;
				j++;
			}
			if(start[i]==0) i++;
		}
		int ans[] = new int[amp.size()];
		for(i = 0; i< amp.size();i++) ans[i] = amp.get(i);
		return ans;
	}
	static class Pair implements Comparable<Pair> {
		long u;
		long v;

		public Pair() {

		}

		public Pair(long u, long v) {
			this.u = u;
			this.v = v;
		}

		public int hashCode() {
			int hu = (int) (u ^ (u >>> 32));
			int hv = (int) (v ^ (v >>> 32));
			return 31 * hu + hv;
		}

		public boolean equals(Object o) {
			Pair other = (Pair) o;
			return (u == other.u && v == other.v);
		}

		public int compareTo(Pair other) {
			return Long.compare(u, other.u) != 0 ? (Long.compare(u, other.u))
					: (Long.compare(v, other.v));
		}

		public String toString() {
			return "[u=" + u + ", v=" + v + "]";
		}
	}

	public static int getParent(int x, int parent[]) {
		while (parent[x] != x) {
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}


	public static void seive(long n) {
		b = new boolean[(int) (n + 1)];
		Arrays.fill(b, true);
		b[0] = true;
		b[1] = false;
		for (int i = 2; i * i <= n; i++) {
			if (b[i]) {
				for (int p = 2 * i; p <= n; p += i) {
					b[p] = false;
					dist[i]+=cnt[p];
				}
			}
		}
	}

	public static void buildGraph(int n) {
		for (int i = 0; i < n; i++) {
			int x = sc.nextInt(), y = sc.nextInt();
			amp[--x].add(--y);
			amp[y].add(x);
		}
	}


	public static void id2() {
		

		while (!q.isEmpty()) {
			int x = q.poll();
			for (int e : amp[x]) {
				if (!b[e]) {
					q.add(e);
					b[e] = true;
					sum[e] = x;
				} else {
					if (!hs.contains(x) && e != sum[x]) {
						System.out.println("NO");
						System.exit(0);
					}
				}
			}
		}
	}

	public static void getCycle(int x) {
		b[x] = true;
		for (int e : amp[x]) {
			if (b[e]) {
				p2 = x;
				if (e != sum[x]) {
					p1 = e;
					c1 = true;
					return;
				}
			} else {
				sum[e] = x;
				

				getCycle(e);
				if (c1)
					return;
			}
		}
		if (c1)
			return;
	}

	public static long count(long x, boolean b, long ans) {
		String str = Long.toString(x, 2);
		if (x == 1)
			return (ans + 1) % MOD;
		if (x == 0 && b)
			return (ans + 1) % MOD;
		else if (x == 0)
			return ans;
		if (str.length() > 1)
			ans = (long) ((ans + Math.pow(2, str.length() - 2) % MOD) % MOD);
		return count((long) (x - Math.pow(2, str.length() - 1)), !b, ans);
	}

	static boolean KMP(String pat, String txt) {
		int M = pat.length();
		int N = txt.length();

		

		

		int lps[] = new int[M];
		int j = 0; 


		

		

		id0(pat, M, lps);

		int i = 0; 

		while (i < N) {
			if (pat.charAt(j) == txt.charAt(i)) {
				j++;
				i++;
			}
			if (j == M) {

				j = lps[j - 1];
				return true;
			}

			

			else if (i < N && pat.charAt(j) != txt.charAt(i)) {
				

				

				if (j != 0)
					j = lps[j - 1];
				else
					i = i + 1;
			}
		}
		return false;
	}

	static void id0(String pat, int M, int lps[]) {
		

		int len = 0;
		int i = 1;
		lps[0] = 0; 


		

		while (i < M) {
			if (pat.charAt(i) == pat.charAt(len)) {
				len++;
				lps[i] = len;
				i++;
			} else 

			{
				

				

				

				if (len != 0) {
					len = lps[len - 1];

					

					

				} else 

				{
					lps[i] = len;
					i++;
				}
			}
		}
	}

	static long power(long x, long y, long m) {
		if (y == 0)
			return 1;
		long p = power(x, y / 2, m) % m;
		p = (p * p) % m;

		return (y % 2 == 0) ? p : (x * p) % m;
	}

	private static void permutation(String prefix, String str) {
		int n = str.length();
		

		

		for (int i = 0; i < n; i++)
			permutation(prefix + str.charAt(i),
					str.substring(0, i) + str.substring(i + 1, n));
		

	}

	public static char give(char c1, char c2) {
		if (c1 != 'a' && c2 != 'a')
			return 'a';
		if (c1 != 'b' && c2 != 'b')
			return 'b';
		return 'c';
	}

	static class Graph {
		int vertex;
		long weight;
	}

	public static void buildTree(int n) {
		int arr[] = sc.id4(n);
		for (int i = 0; i < n; i++) {
			int x = arr[i] - 1;
			amp[i + 1].add(x);
			amp[x].add(i + 1);
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
				arr1[idx] += val;
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

	static int convert(int x) {
		int cnt = 0;
		String str = Integer.toBinaryString(x);
		

		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == '1') {
				cnt++;
			}
		}
		int ans = (int) Math.pow(3, 6 - cnt);
		return ans;
	}

	static class Node2 {
		Node2 left = null;
		Node2 right = null;
		Node2 parent = null;
		int data;
	}

	static class id3 {
		Node2 root = null;
		int height = 0;
		int max = 0;
		int cnt = 1;
		ArrayList<Integer> parent = new ArrayList<>();
		HashMap<Integer, Integer> hm = new HashMap<>();

		public void insert(int x) {
			Node2 n = new Node2();
			n.data = x;
			if (root == null) {
				root = n;
			} else {
				Node2 temp = root, temp2 = null;
				while (temp != null) {
					temp2 = temp;
					if (x > temp.data)
						temp = temp.right;
					else
						temp = temp.left;
				}
				if (x > temp2.data)
					temp2.right = n;
				else
					temp2.left = n;
				n.parent = temp2;
				parent.add(temp2.data);
			}
		}

		public Node2 getSomething(int x, int y, Node2 n) {
			if (n.data == x || n.data == y)
				return n;
			else if (n.data > x && n.data < y)
				return n;
			else if (n.data < x && n.data < y)
				return getSomething(x, y, n.right);
			else
				return getSomething(x, y, n.left);
		}

		public Node2 search(int x, Node2 n) {
			if (x == n.data) {
				max = Math.max(max, n.data);
				return n;
			}
			if (x > n.data) {
				max = Math.max(max, n.data);
				return search(x, n.right);
			} else {
				max = Math.max(max, n.data);
				return search(x, n.left);
			}
		}

		public int getHeight(Node2 n) {
			if (n == null)
				return 0;
			height = 1 + Math.max(getHeight(n.left), getHeight(n.right));
			return height;
		}
	}

	static long findDiff(long[] arr, long[] brr, int m) {
		int i = 0, j = 0;
		long fa = 1000000000000L;
		while (i < m && j < m) {
			long x = arr[i] - brr[j];
			if (x >= 0) {
				if (x < fa)
					fa = x;
				j++;
			} else {
				if ((-x) < fa)
					fa = -x;
				i++;
			}
		}
		return fa;
	}

	public static long max(long x, long y, long z) {
		if (x >= y && x >= z)
			return x;
		if (y >= x && y >= z)
			return y;
		return z;
	}

	static long modInverse(long a, long id6) {
		return power(a, id6 - 2, id6);
	}

	static long power2(long x, BigInteger y, long m) {
		long ans = 1;
		BigInteger two = new BigInteger("2");
		while (y.compareTo(BigInteger.ZERO) > 0) {
			if (y.getLowestSetBit() == y.bitCount()) {
				x = (x * x) % MOD;
				y = y.divide(two);
			} else {
				ans = (ans * x) % MOD;
				y = y.subtract(BigInteger.ONE);
			}
		}
		return ans;
	}

	static BigInteger power2(BigInteger x, BigInteger y, BigInteger m) {
		BigInteger ans = new BigInteger("1");
		BigInteger one = new BigInteger("1");
		BigInteger two = new BigInteger("2");
		BigInteger zero = new BigInteger("0");
		while (y.compareTo(zero) > 0) {
			

			if (y.mod(two).equals(one)) {
				ans = ans.multiply(x).mod(m);
				y = y.subtract(one);
			} else {
				x = x.multiply(x).mod(m);
				y = y.divide(two);
			}
		}
		return ans;
	}

	static BigInteger power(BigInteger x, BigInteger y, BigInteger m) {
		if (y.equals(0))
			return (new BigInteger("1"));
		BigInteger p = power(x, y.divide(new BigInteger("2")), m).mod(m);
		p = (p.multiply(p)).mod(m);

		return (y.mod(new BigInteger("2")).equals(0)) ? p : (p.multiply(x))
				.mod(m);
	}

	static long d, x, y;

	public static void id5(long a, long b) {
		if (b == 0) {
			d = a;
			x = 1;
			y = 0;
		} else {
			id5(b, a % b);
			int temp = (int) x;
			x = y;
			y = temp - (a / b) * y;
		}
	}

	public static long gcd(long n, long m) {
		if (m != 0)
			return gcd(m, n % m);
		else
			return n;
	}

	public static class id8 {
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
			while (id1(c))
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
			while (id1(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id1(c));
			return res.toString();
		}

		public long nextLong() {
			int c = read();
			while (id1(c))
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
			} while (!id1(c));
			return res * sgn;
		}

		public int nextInt() {
			int c = read();
			while (id1(c))
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
			} while (!id1(c));
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

		public long[] id9(int n) {
			return id9(n, 0);
		}

		public long[] id9(int n, int off) {
			long[] arr = new long[n + off];
			for (int i = 0; i < n; i++) {
				arr[i + off] = nextLong();
			}
			return arr;
		}

		private boolean id1(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean id7(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
	}
}