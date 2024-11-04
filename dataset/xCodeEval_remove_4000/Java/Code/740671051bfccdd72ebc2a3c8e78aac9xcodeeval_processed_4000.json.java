import java.io.*;
import java.util.*;

public class Main {
	static InputReader in = new InputReader(System.in);
	static OutputWriter out = new OutputWriter(System.out);

	public static void main(String[] args) throws IOException {


		int t = i();
		int c = 1;
		sb = new StringBuilder();
		while (t-- > 0) {


			solve();
			c++;
		}
		out.println(sb.toString());
		out.close();

	}

	static int mod = 1000000007;
	static StringBuilder sb;

	private static void solve() {			
		int n = i();
		int[] arr = readArray(n);
		ArrayList<int[]> al = new ArrayList<>();
		for(int i=0;i<n;i++) {
			if(arr[i]<(i+1)) {
				al.add(new int[]{arr[i],i+1});
			}
		}
		long res=0L;
		for(int i=0;i<al.size();i++) {
			int cv = al.get(i)[0];
			int lo = 0;
			int hi = i-1;
			int ans=-1;
			while(lo<=hi) {
				int mid = lo+(hi-lo)/2;
				if(al.get(mid)[1]<cv) {
					ans=mid;
					lo=mid+1;
				}else {
					hi=mid-1;
				}
			}
			res+=ans+1;
		}
		sb.append(res).append("\n");
	}

	private static boolean isPossible(int n, int[][] edges, int k, int[] idxs, int val) {
		ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			graph.add(new ArrayList<>());
		}
		for (int[] e : edges) {
			if (idxs[e[0]] >= val && idxs[e[1]] >= val) {
				graph.get(e[0]).add(e[1]);
			}
		}
		

		boolean[] visited = new boolean[n];
		Stack<Integer> stack = new Stack<>();
		for (int i = 0; i < n; i++) {
			if (visited[i]) {
				continue;
			}
			dfs1(graph, i, visited, stack);
		}

		

		ArrayList<ArrayList<Integer>> revgraph = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			revgraph.add(new ArrayList<>());
		}
		for (int i = 0; i < n; i++) {
			ArrayList<Integer> nbrs = graph.get(i);
			for (int nbr : nbrs) {
				revgraph.get(nbr).add(i);
			}
		}
		

		boolean[] visited2 = new boolean[n];
		while (!stack.isEmpty()) {
			int top = stack.pop();
			if (visited2[top]) {
				continue;
			}
			if (dfs2(revgraph, top, visited2) >= k) {
				return true;
			}

		}
		return false;
	}

	private static void dfs1(ArrayList<ArrayList<Integer>> graph, int src, boolean[] visited, Stack<Integer> stack) {
		visited[src] = true;
		for (int nbr : graph.get(src)) {
			if (!visited[nbr]) {
				visited[nbr] = true;
				dfs1(graph, nbr, visited, stack);
			}
		}
		stack.push(src);
	}

	private static int dfs2(ArrayList<ArrayList<Integer>> revgraph, int src, boolean[] visited) {
		visited[src] = true;
		int res = 1;
		for (int nbr : revgraph.get(src)) {
			if (!visited[nbr]) {
				res += dfs2(revgraph, nbr, visited);
			}
		}
		return res;
	}

	

	static class id4 {
		int n;
		long[] farr;

		id4(int n, long[] a) {
			this.n = n;
			farr = new long[n + 1];
			for (int i = 0; i < n; i++) {
				update(i + 1, a[i]);
			}
		}

		void update(int i, long val) {
			while (i < farr.length) {
				farr[i] += val;
				i += (i & -i);
			}
		}

		long sum(int i) {
			long sum = 0L;
			while (i > 0) {
				sum += farr[i];
				i -= (i & -i);
			}
			return sum;
		}
	}
































	static class Pair implements Comparable<Pair> {
		char ch;
		ArrayList<Integer> idxs;

		Pair(char ch, ArrayList<Integer> idxs) {
			this.ch = ch;
			this.idxs = idxs;
		}

		public int compareTo(Pair o) {
			return o.idxs.size() - this.idxs.size();
		}

	}

	static class Edge implements Comparable<Edge> {
		int u;
		int v;
		int wt;

		Edge(int u, int v, int wt) {
			this.u = u;
			this.v = v;
			this.wt = wt;
		}

		public int compareTo(Edge o) {
			return this.wt - o.wt;
		}
	}



	static class dsu {
		int[] par;
		int[] rank;

		dsu(int n) {
			par = new int[n + 1];
			rank = new int[n + 1];
			for (int i = 0; i <= n; i++) {
				par[i] = i;
				rank[i] = 1;
			}
		}

		int find(int a) {
			if (par[a] == a) {
				return a;
			}
			int x = find(par[a]);
			par[a] = x;
			return x;
		}

		boolean union(int a, int b) {
			int pa = find(a);
			int pb = find(b);
			if (pa == pb) {
				return false;
			}
			if (rank[pa] > rank[pb]) {
				par[pb] = pa;
			} else if (rank[pb] > rank[pa]) {
				par[pa] = pb;
			} else {
				par[pa] = pb;
				rank[pb]++;
			}
			return true;
		}

	}

	

	static long ncr(int n, int r) {
		if (r > n)
			return (long) 0;
		long[] fact = new long[(int) 1e6 + 10];
		fact[0] = fact[1] = 1;
		for (int i = 2; i < fact.length; i++) {
			fact[i] = ((long) (i % mod) * (long) (fact[i - 1] % mod)) % mod;
		}
		long res = fact[n] % mod;
		res = ((long) (res % mod) * (long) (p(fact[r], mod - 2) % mod)) % mod;
		res = ((long) (res % mod) * (long) (p(fact[n - r], mod - 2) % mod)) % mod;
		return res;
	}

	static ArrayList<Integer> id0(int n) {
		ArrayList<Integer> al = new ArrayList<>();
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				if (n == i * i) {
					al.add(i);
				} else {
					al.add(i);
					al.add(n / i);
				}
			}
		}
		Collections.sort(al);
		return al;
	}

	static long p(long x, long y)

	{
		if (y == 0)
			return 1;

		long res = 1;
		while (y > 0) {
			if (y % 2 == 1) {
				res = (res * x) % mod;
				y--;
			}

			x = (x * x) % mod;
			y = y / 2;

		}
		return res % mod;
	}

	private static boolean pow2(int i) {
		return (i & (i - 1)) == 0;
	}

	private static void sort(int[] arr) {
		int n = arr.length;
		ArrayList<Integer> res = new ArrayList<>();
		for (int a : arr) {
			res.add(a);
		}
		Collections.sort(res);
		for (int i = 0; i < n; i++) {
			arr[i] = res.get(i);
		}
	}

	private static void sort(long[] arr) {
		int n = arr.length;
		ArrayList<Long> res = new ArrayList<>();
		for (long a : arr) {
			res.add(a);
		}
		Collections.sort(res);
		for (int i = 0; i < n; i++) {
			arr[i] = res.get(i);
		}
	}

	private static void revSort(int[] arr) {
		int n = arr.length;
		ArrayList<Integer> res = new ArrayList<>();
		for (int a : arr) {
			res.add(a);
		}
		Collections.sort(res, Collections.reverseOrder());
		for (int i = 0; i < n; i++) {
			arr[i] = res.get(i);
		}
	}

	private static ArrayList<Integer> id3(int n) {
		boolean[] arr = new boolean[n + 1];

		arr[0] = arr[1] = true;
		for (int i = 2; i * i <= n; i++) {
			if (!arr[i]) {
				for (int j = i * i; j <= n; j += i) {
					arr[j] = true;
				}
			}
		}
		ArrayList<Integer> primes = new ArrayList<>();
		for (int i = 2; i <= n; i++) {
			if (!arr[i]) {
				primes.add(i);
			}
		}
		return primes;
	}

	private static ArrayList<Integer> id2(int s, int e) {
		int len = (int) (Math.sqrt(e) + 1);
		ArrayList<Integer> primes = id3(len);
		boolean[] arr2 = new boolean[e - s + 1];
		if (s == 1) {
			arr2[0] = true;
		}
		ArrayList<Integer> res = new ArrayList<>();
		for (int p : primes) {

			int st = (int) (p * (Math.ceil((double) s / p)));
			if (st < s) {
				st += p;
			}
			if (st == p) {
				st += p;
			}
			for (int i = st; i <= e; i += p) {
				arr2[i - s] = true;
			}
		}
		for (int i = 0; i < arr2.length; i++) {
			if (!arr2[i]) {
				res.add(i + s);
			}
		}
		return res;
	}

	private static long pow(int n, int k) {
		long res = 1;
		long num = (long) n;
		while (k > 0) {
			if ((k & 1) == 1) {
				res = (res * num) % mod;
			}
			k /= 2;
			num = num * num % mod;
		}
		return res;
	}

	private static int countDigits(int n) {
		int c = 0;
		while (n != 0) {
			c++;
			n /= 10;
		}
		return c;
	}

	private static boolean palindrome(String str) {
		int s = 0;
		int e = str.length() - 1;
		while (s < e) {
			if (str.charAt(s) != str.charAt(e)) {
				return false;
			}
			s++;
			e--;
		}
		return true;
	}

	private static void reverse(int[] arr, int s, int e) {
		while (s < e) {
			int temp = arr[s];
			arr[s++] = arr[e];
			arr[e--] = temp;
		}
	}

	private static int getMax(int[] arr, int s, int e) {
		int maxi = s;
		for (int i = s + 1; i <= e; i++) {
			if (arr[i] > arr[maxi]) {
				maxi = i;
			}
		}
		return maxi;
	}

	private static int getMin(int[] arr, int s, int e) {
		int mini = s;
		for (int i = s + 1; i <= e; i++) {
			if (arr[i] < arr[mini]) {
				mini = i;
			}
		}
		return mini;
	}

	

	private static long lcm(long n1, long n2) {
		return (n1 * n2) / gcd(n1, n2);
	}

	private static int lcm(int n1, int n2) {
		return (n1 * n2) / gcd(n1, n2);
	}

	

	private static long gcd(long num1, long num2) {
		if (num2 == 0) {
			return num1;
		}
		return gcd(num2, num1 % num2);
	}

	private static int gcd(int num1, int num2) {
		if (num2 == 0) {
			return num1;
		}
		return gcd(num2, num1 % num2);
	}

	

	static TreeMap<Long, Long> prime(long n) {
		TreeMap<Long, Long> h = new TreeMap<>();
		long num = n;
		for (int i = 2; i <= Math.sqrt(num); i++) {
			if (n % i == 0) {
				long nt = 0L;
				while (n % i == 0) {
					n = n / i;
					nt++;
				}
				h.put(i * 1L, nt);
			}
		}
		if (n != 1)
			h.put(n, 1L);
		return h;

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private id5 filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int Int() {
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

		public String String() {
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

		public boolean id1(int c) {
			if (filter != null)
				return filter.id1(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public String next() {
			return String();
		}

		public interface id5 {
			public boolean id1(int ch);
		}
	}

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void print(Object... objects) {
			for (int i = 0; i < objects.length; i++) {
				if (i != 0)
					writer.print(' ');
				writer.print(objects[i]);
			}
		}

		public void println(Object... objects) {
			print(objects);
			writer.println();
		}

		public void close() {
			writer.close();
		}

		public void flush() {
			writer.flush();
		}
	}



	public static int i() {
		return in.Int();
	}

	public static long l() {
		String s = in.String();
		return Long.parseLong(s);
	}

	public static String s() {
		return in.String();
	}

	public static int[] readArray(int n) {
		int A[] = new int[n];
		for (int i = 0; i < n; i++) {
			A[i] = i();
		}
		return A;
	}

	public static long[] readArray(long n) {
		long A[] = new long[(int) n];
		for (int i = 0; i < n; i++) {
			A[i] = l();
		}
		return A;
	}

}
