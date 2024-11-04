import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
import java.util.Map.Entry;

public class submit {
	static Scanner sc = new Scanner(System.in);
	static PrintWriter pw = new PrintWriter(System.out);
	static TreeSet<Pair> allowed;










	public static void main(String[] args) throws IOException {
		int n = sc.nextInt();
		int q = sc.nextInt();
		Integer arr_[] = new Integer[n];
		for (int i = 0; i < n; i++)
			arr_[i] = sc.nextInt();
		Arrays.sort(arr_);
		Long[] arr = new Long[n + 1];
		arr[0] = 0l;
		for (int i = 1; i <= n; i++)
			arr[i] = arr_[i - 1] + arr[i - 1];

		for (int i = 0; i < q; i++) {
			int x = sc.nextInt(), y = sc.nextInt();
			long sum = arr[n - x + y] - arr[n - x];
			pw.println(sum);
		}

		pw.close();

	}
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	








































































	void cccxE() throws IOException {

		int n = sc.nextInt(), m = sc.nextInt();

		HashMap<Integer, HashSet<Integer>> from = new HashMap<Integer, HashSet<Integer>>();
		HashMap<Integer, HashSet<Integer>> rem = new HashMap<Integer, HashSet<Integer>>();

		for (int i = 0; i < n; i++)
			from.put(i + 1, new HashSet<Integer>());
		for (int i = 0; i < m; i++) {
			int f = sc.nextInt();
			int t = sc.nextInt();
			from.get(f).add(t);
			from.get(t).add(f);
		}
		int sum = 1;
		int s = -1;
		while (sum != 0) {
			s++;
			sum = 0;
			for (int i = 0; i < n; i++)
				if (from.get(i + 1).size() == 1) {
					sum++;
					int b = from.get(i + 1).iterator().next();
					if (!rem.containsKey(b))
						rem.put(b, new HashSet<Integer>());
					if (!rem.containsKey(i + 1))
						rem.put(i + 1, new HashSet<Integer>());
					HashSet<Integer> tmp = rem.get(b);
					tmp.add(i + 1);
					rem.put(b, tmp);
					tmp = rem.get(i + 1);
					tmp.add(b);
					rem.put(i + 1, tmp);

				}
			remove(rem, from);
		}
		pw.println(s);
		pw.close();
	}

	private static void remove(HashMap<Integer, HashSet<Integer>> rem, HashMap<Integer, HashSet<Integer>> from) {

		for (Entry<Integer, HashSet<Integer>> n : rem.entrySet()) {
			int a = n.getKey();
			Iterator<Integer> b = n.getValue().iterator();
			while (b.hasNext())
				from.get(a).remove(b.next());
		}
	}

	private static int check(int mid, int[] num) {
		

		return 0;
	}

	public static int numISland(char[][] grid) {
		int count = 0;
		HashMap<Integer, HashSet<Integer>> vis = new HashMap<Integer, HashSet<Integer>>();
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[i].length; j++) {

				if (grid[i][j] == '1' && !(vis.containsKey(i) && vis.get(i).contains(j))) {
					ArrayList<Pair> island = DFS(grid, i, j, vis);
					pw.println("\nisland # " + (count + 1));
					for (Pair f : island)
						pw.print(f + "> ");

					count++;
				}

			}
		}
		return count;
	}

	private static ArrayList<Pair> DFS(char[][] grid, int x, int y, HashMap<Integer, HashSet<Integer>> vis) {
		ArrayList<Pair> island = new ArrayList<Pair>();
		int n = x + 1;
		if (n >= 0 && n < grid.length) {
			if (!(vis.containsKey(n) && vis.get(n).contains(y)) && grid[n][y] == '1') {
				if (!vis.containsKey(n))
					vis.put(n, new HashSet<Integer>());
				vis.get(n).add(y);
				island.add(new Pair(n, y));
				DFS(grid, x + 1, y, vis);
			}
		}
		n = x - 1;
		if (n >= 0 && n < grid.length) {
			if (!(vis.containsKey(n) && vis.get(n).contains(y)) && grid[n][y] == '1') {
				if (!vis.containsKey(n))
					vis.put(n, new HashSet<Integer>());
				vis.get(n).add(y);
				island.add(new Pair(n, y));
				DFS(grid, x - 1, y, vis);

			}
		}
		n = y + 1;
		if (n >= 0 && n < grid[x].length) {
			if (!(vis.containsKey(x) && vis.get(x).contains(n)) && grid[x][n] == '1') {
				if (!vis.containsKey(x))
					vis.put(x, new HashSet<Integer>());
				vis.get(x).add(n);
				island.add(new Pair(x, n));
				DFS(grid, x, y + 1, vis);

			}
		}
		n = y - 1;
		if (n >= 0 && n < grid[x].length) {
			if (!(vis.containsKey(x) && vis.get(x).contains(n)) && grid[x][n] == '1') {
				if (!vis.containsKey(x))
					vis.put(x, new HashSet<Integer>());
				vis.get(x).add(n);
				island.add(new Pair(x, n));
				DFS(grid, x, y - 1, vis);

			}
		}

		return island;
	}

	public static int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
		int old = image[sr][sc];
		Stack<Pair> ss = new Stack<Pair>();
		ss.add(new Pair(sr, sc));
		HashMap<Integer, HashSet<Integer>> hh = new HashMap<Integer, HashSet<Integer>>();
		hh.put(sr, new HashSet<Integer>());
		hh.get(sr).add(sc);
		image[sr][sc] = newColor;
		while (!ss.isEmpty()) {
			int x = ((Pair) ss.peek()).x;
			int y = ((Pair) ss.peek()).y;
			ss.pop();
			for (int i = -1; i < 2; i++)
				for (int j = -1; j < 2; j++) {
					if (Math.abs(i) == Math.abs(j) || x + i < 0 || y + j < 0 || x + i >= image.length
							|| y + j >= image[0].length)
						continue;
					if (image[x + i][y + j] == old && !(hh.containsKey(x + i) && hh.get(x + i).contains(y + j))) {
						ss.add(new Pair(x + i, y + j));
						image[x + i][y + j] = newColor;
						if (!hh.containsKey(x + i))
							hh.put(x + i, new HashSet<Integer>());
						hh.get(x + i).add(y + j);
					}

				}

		}

		return image;
	}

	private static TreeMap<Pair, Pair> bfs(Pair s, Pair e) {
		TreeSet<Pair> visited = new TreeSet<Pair>();
		TreeMap<Pair, Pair> path = new TreeMap<Pair, Pair>();
		Queue<Pair> aa = new LinkedList<Pair>();
		aa.add(s);
		visited.add(s);
		while (!aa.isEmpty()) {
			Pair curr = (Pair) aa.remove();
			if (s.x == e.x && s.y == e.y)
				break;

			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					if (i == 0 && j == 0)
						continue;
					Pair temp = new Pair(curr.x + i, curr.y + j);
					if (!visited.contains(temp) && allowed.contains(temp)) {
						visited.add(temp);
						aa.add(temp);
						path.put(temp, curr);
					}

				}

			}
		}
		return path;
	}

	private static boolean work(Queue<Pair> x, int i, int b, boolean[][] allowed) {

		if (allowed[i][b]) {
			x.add(new Pair(i, b));
			allowed[i][b] = false;
			return true;
		}
		return false;
	}

	public static class Pair implements Comparable<Pair> {
		int x, y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;

		}

		public int compareTo(Pair a) {
			if (a.x == x)
				return a.y - y;
			return a.x - x;
		}

		public String toString() {
			return x + "," + y;
		}

	}

	private static long binary_search_lower_bound(long[] sum, int x, long day) {

		


		int s = 0, e = sum.length - 1;
		int mid;
		while (s <= e) {

			mid = s + (e - s) / 2;
			if (sum[mid] + (day * (mid + 1)) == x)
				return mid;
			else if (sum[mid] + day * (mid + 1) > x)
				e = mid - 1;
			else
				s = mid + 1;

		}

		return e;

	}

	


	private static int binary_search_upper_bound(int[] arr, int x) {
		int s = 0, e = arr.length - 1;
		int mid;
		while (s <= e) {
			mid = s + (e - s) / 2;
			if (check(arr, mid, x))
				return mid;
			else if (arr[mid] <= x)
				s = mid + 1;
			else
				e = mid - 1;

		}

		return e;

	}

























	private static boolean check(int arr[], int i, int x) {
		

		if (i != 0)
			return arr[i] >= x && arr[i - 1] < x;

		return arr[i] >= x;
	}

	static int cost(String x, String y) {
		int c = 0;

		for (int i = 0; i < x.length(); i++)
			c += Math.abs(x.charAt(i) - (y.charAt(i)));

		return c;
	}

}

class Scanner {
	StringTokenizer st;
	BufferedReader br;

	public Scanner(InputStream s) {
		br = new BufferedReader(new InputStreamReader(s));
	}

	public Scanner(FileReader r) {
		br = new BufferedReader(r);
	}

	public String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	public String nextLine() throws IOException {
		return br.readLine();
	}

	public double nextDouble() throws IOException {
		String x = next();
		StringBuilder sb = new StringBuilder("0");
		double res = 0, f = 1;
		boolean dec = false, neg = false;
		int start = 0;
		if (x.charAt(0) == '-') {
			neg = true;
			start++;
		}
		for (int i = start; i < x.length(); i++)
			if (x.charAt(i) == '.') {
				res = Long.parseLong(sb.toString());
				sb = new StringBuilder("0");
				dec = true;
			} else {
				sb.append(x.charAt(i));
				if (dec)
					f *= 10;
			}
		res += Long.parseLong(sb.toString()) / f;
		return res * (neg ? -1 : 1);
	}

	public long[] nextlongArray(int n) throws IOException {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nextLong();
		return a;
	}

	public Long[] nextLongArray(int n) throws IOException {
		Long[] a = new Long[n];
		for (int i = 0; i < n; i++)
			a[i] = nextLong();
		return a;
	}

	public int[] nextIntArray(int n) throws IOException {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		return a;
	}

	public byte[] nextByteArray(int n) throws IOException {
		byte[] a = new byte[n];
		for (int i = 0; i < n; i++)
			a[i] = (byte) nextInt();
		return a;
	}

	public Integer[] nextIntegerArray(int n) throws IOException {
		Integer[] a = new Integer[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		return a;
	}

	public boolean ready() throws IOException {
		return br.ready();
	}

}