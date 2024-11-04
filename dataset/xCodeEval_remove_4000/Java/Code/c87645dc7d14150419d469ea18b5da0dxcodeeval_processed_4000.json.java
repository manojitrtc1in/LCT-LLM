import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Objects;
import java.util.PriorityQueue;
import java.util.TreeSet;

public class id6 {

	static Reader r = new Reader();
	static PrintWriter out = new PrintWriter(System.out);

	private static void solve1() throws IOException {

		int n = r.nextInt();
		int arr[] = r.id5(n);

		for (int i = 0; i < n; i++) {
			if (arr[i] > i + 1) {
				out.println(-1);
				out.close();
				return;
			}
		}

		int cnt = 1;
		int ans[] = new int[n];
		Arrays.fill(ans, -1);
		boolean vis[] = new boolean[(int) 1e6 + 1];
		ArrayList<Integer> av = new ArrayList<Integer>();

		vis[arr[0]] = true;
		for (int i = 1; i < n; i++) {
			if (arr[i] != arr[i - 1]) {
				ans[i] = arr[i - 1];
				vis[arr[i]] = true;
			} else {
				cnt++;
			}
		}

		for (int i = 0; i <= 1000000 && cnt > 0; i++) {
			if (!vis[i]) {
				av.add(i);
				cnt--;
			}
		}

		int idx = 0;
		for (int i = 0; i < n; i++) {
			if (ans[i] == -1) {
				ans[i] = av.get(idx++);
			}
		}

		for (int i = 0; i < n; i++) {
			out.print(ans[i] + " ");
		}
		out.close();

	}

	static ArrayList<Integer> tree[];
	static int one, more;

	private static void BFS(int node, int depth, int parent) {
		if (depth == 1) {
			one++;
		} else if (depth > 1) {
			more++;
		}
		for (int child : tree[node]) {
			if (child != parent) {
				BFS(child, depth + 1, node);
			}
		}
	}

	private static void solve2() throws IOException {

		int t = r.nextInt();
		StringBuilder res = new StringBuilder();

		while (t-- > 0) {

			int n = r.nextInt();
			int x = r.nextInt();

			one = 0;
			more = 0;

			tree = new ArrayList[n + 1];

			for (int i = 1; i <= n; i++) {
				tree[i] = new ArrayList<Integer>();
			}

			for (int i = 1; i <= n - 1; i++) {
				int u = r.nextInt();
				int v = r.nextInt();
				tree[u].add(v);
				tree[v].add(u);
			}

			BFS(x, 0, -1);

			String ans = "";

			if (one <= 1) {
				ans = "Ayush";
			} else {
				int chance = (more & 1) == 0 ? 0 : 1; 

				if ((one & 1) == 0) {
					chance = (chance + 1) % 2;
				}
				ans = (chance == 0) ? "Ayush" : "Ashish";
			}

			res.append(ans).append("\n");

		}

		out.print(res);
		out.close();
	}

	private static boolean isOn(long num, int bit) {
		if ((num & (1L << bit)) == 0) {
			return false;
		}
		return true;
	}

	private static void solve3() throws IOException {

		int t = r.nextInt();
		StringBuilder res = new StringBuilder();

		while (t-- > 0) {
			long n = r.nextLong();
			long ans = 2 * n - Long.bitCount(n);
			res.append(ans).append("\n");
		}

		out.print(res);
		out.close();

	}

	private static void solve4() throws IOException {

		int t = r.nextInt();
		StringBuilder res = new StringBuilder();

		while (t-- > 0) {

			int n = r.nextInt();

			ArrayList<Integer> arr = new ArrayList<Integer>();
			for (int i = 0; i < n; i++) {
				arr.add(r.nextInt());
			}
			Collections.sort(arr);

			int ans = -1;
			ArrayList<Integer> temp;

			for (int i = 1; i <= 1024; i++) {
				temp = new ArrayList<Integer>();
				for (int j = 0; j < n; j++) {
					temp.add((arr.get(j) ^ i));
				}
				Collections.sort(temp);
				if (temp.equals(arr)) {
					ans = i;
					break;
				}
			}

			res.append(ans).append("\n");

		}

		out.print(res);
		out.close();

	}

	private static void solve5() throws IOException {

		int t = r.nextInt();
		StringBuilder res = new StringBuilder();

		while (t-- > 0) {
			int x1 = r.nextInt();
			int y1 = r.nextInt();
			int x2 = r.nextInt();
			int y2 = r.nextInt();
			res.append((long) (x2 - x1) * (y2 - y1) + 1).append("\n");
		}

		out.print(res);
		out.close();

	}

	private static void solve6() throws IOException {

		int n = r.nextInt();
		int s = r.nextInt();

		if ((s / n <= 1)) {
			out.print("NO");
		} else {
			int last = (s / n) + (s % n);
			int rem = (s / n);
			out.println("YES");
			for (int i = 1; i <= n - 1; i++) {
				out.print(rem + " ");
			}
			out.println(last);
			out.print(1);
		}
		out.close();

	}

	static class Pair implements Comparable<Pair> {

		int fi, se;

		public Pair(int fi, int se) {
			this.fi = fi;
			this.se = se;
		}

		@Override
		public boolean equals(Object o) {
			if (this == o)
				return true;
			if (o == null || getClass() != o.getClass())
				return false;
			Pair pair = (Pair) o;
			return fi == pair.fi && se == pair.se;
		}

		@Override
		public int hashCode() {
			return Objects.hash(fi, se);
		}

		@Override
		public int compareTo(Pair o) {
			if (o.se - o.fi + 1 == this.se - this.fi + 1) {
				return this.fi - o.fi;
			}
			return (o.se - o.fi + 1) - (this.se - this.fi + 1);
		}

	}

	private static void solve7() throws IOException {

		int t = r.nextInt();

		while (t-- > 0) {

			int n = r.nextInt();

			PriorityQueue<Pair> pq = new PriorityQueue<>();
			pq.add(new Pair(0, n - 1));

			int cnt = 0;
			int ans[] = new int[n];

			while (!pq.isEmpty()) {
				Pair p = pq.poll();
				int lt = p.fi;
				int rt = p.se;
				int idx = (lt + rt) / 2;
				ans[idx] = ++cnt;
				if (lt < idx)
					pq.add(new Pair(lt, idx - 1));
				if (rt > idx)
					pq.add(new Pair(idx + 1, rt));
			}

			for (int i = 0; i < n; i++) {
				out.print(ans[i] + " ");
			}
			out.println();

		}

		out.close();

	}

	public static class Pair1 {

		int x, y, prevX, prevY;

		public Pair1(int a, int b, int c, int d) {
			x = a;
			y = b;
			prevX = c;
			prevY = d;
		}

		@Override
		public int hashCode() {
			return prevX + prevY + x + y;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (this.getClass() != obj.getClass())
				return false;
			Pair1 other = (Pair1) obj;
			if (x == other.x && y == other.y && prevX == other.prevX && prevY == other.prevY)
				return true;
			if (x == other.prevX && y == other.prevY && prevX == other.x && prevY == other.y)
				return true;
			return false;
		}

	}

	private static void solve8() throws IOException {

		int t = r.nextInt();

		while (t-- > 0) {

			char str[] = r.next().toCharArray();
			HashSet<Pair1> set = new HashSet<>();

			long ans = 0;
			int x = 0, y = 0;

			for (int i = 0; i < str.length; i++) {
				int fi = x, se = y;
				if (str[i] == 'N')
					y++;
				else if (str[i] == 'S')
					y--;
				else if (str[i] == 'E')
					x++;
				else
					x--;
				int th = x, fo = y;
				Pair1 p = new Pair1(fi, se, th, fo);
				if (set.contains(p)) {
					ans += 1;
				} else {
					ans += 5;
					set.add(p);
				}
			}

			out.println(ans);

		}
		out.close();

	}

	private static void solve9() throws IOException {

		int n = r.nextInt();
		int arr[] = new int[n];

		int vis[] = new int[n + 1];
		for (int i = 0; i < n; i++) {
			arr[i] = r.nextInt();
			vis[arr[i]] = 1;
		}

		TreeSet<Integer> av = new TreeSet<Integer>();
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0)
				av.add(i);
		}

		for (int i = 0; i < n; i++) {
			if (arr[i] == 0 && av.contains(i + 1)) {
				if (av.higher(i + 1) != null) {
					arr[i] = av.higher(i + 1);
					av.remove(arr[i]);
				} else {
					arr[i] = av.lower(i + 1);
					av.remove(arr[i]);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) {
				if (av.higher(i + 1) != null) {
					arr[i] = av.higher(i + 1);
					av.remove(arr[i]);
				} else {
					arr[i] = av.lower(i + 1);
					av.remove(arr[i]);
				}
			}
			out.print(arr[i] + " ");
		}

		out.close();

	}

	static class Day implements Comparable<Day> {
		int a, b;

		public Day(int a, int b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(Day o) {
			if (a == o.a) {
				return (b - o.b);
			}
			return (a - o.a);
		}
	}

	private static void solve10() throws IOException {

		int n = r.nextInt();

		Day arr[] = new Day[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new Day(r.nextInt(), r.nextInt());
		}

		Arrays.sort(arr);

		int ans = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			if (Math.min(arr[i].a, arr[i].b) >= ans) {
				ans = Math.max(ans, Math.min(arr[i].a, arr[i].b));
			} else {
				ans = Math.max(ans, Math.max(arr[i].a, arr[i].b));
			}
		}

		out.print(ans);
		out.close();

	}

	static class Point implements Comparable<Point> {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Point o) {
			if (x == o.x) {
				return (y - o.y);
			}
			return (x - o.x);
		}
	}

	private static void solve11() throws IOException {

		int rebel = r.nextInt();
		int bases = r.nextInt();

		Point a1[] = new Point[rebel];
		Point a2[] = new Point[bases];

		for (int i = 0; i < rebel; i++) {
			a1[i] = new Point(r.nextInt(), r.nextInt());
		}
		for (int i = 0; i < bases; i++) {
			a2[i] = new Point(r.nextInt(), r.nextInt());
		}

		Arrays.sort(a1);
		Arrays.sort(a2);

		boolean flag = (a1.length == a2.length) ? true : false;

		out.print(flag ? "Yes" : "No");
		out.close();

	}

	private static void solve12() throws IOException {

		int t = r.nextInt();
		while (t-- > 0) {
			int n = r.nextInt();

			HashSet<Integer> set = new HashSet<Integer>();
			set.add(0);

			for (int i = 1; i * i <= n; i++) {
				set.add(i);
				set.add((n / i));
			}

			ArrayList<Integer> pal = new ArrayList<Integer>();

			pal.addAll(set);
			Collections.sort(pal);

			out.println(set.size());
			for (int ele : pal) {
				out.print(ele + " ");
			}
			out.println();

		}
		out.close();

	}

	private static long GCD(long a, long b) {
		return ((b == 0) ? a : GCD(b, a % b));
	}

	private static long LCM(long a, long b) {
		return (a * b) / GCD(a, b);
	}

	private static void solve13() throws IOException {

		int n = r.nextInt();

		HashSet<Long> set = new HashSet<>();
		set.add(1L);
		set.add(((long) n * (n + 1) / 2));

		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				long s1 = 0, s2 = 0;
				long l1 = LCM((long) n, (long) i);
				long d1 = Math.min(i, n - i);
				long n1 = l1 / i;
				s1 = (long) (n1 * (2 + (n1 - 1) * d1)) / 2;
				set.add(s1);
				if ((n / i) != i) {
					long l2 = LCM((long) n, (long) (n / i));
					long d2 = Math.min((n / i), n - (n / i));
					long n2 = l2 / (n / i);
					s2 = (long) (n2 * (2 + (n2 - 1) * d2)) / 2;
					set.add(s2);
				}
			}
		}

		ArrayList<Long> pal = new ArrayList<>();

		pal.addAll(set);
		Collections.sort(pal);

		for (Long ele : pal) {
			out.print(ele + " ");
		}
		out.close();

	}

	private static void solve14() throws IOException {

		int t = r.nextInt();

		while (t-- > 0) {

			int n = r.nextInt();

			ArrayList<Long> one = new ArrayList<Long>();
			for (int i = 0; i < n; i++) {
				one.add(r.nextLong());
			}

			Collections.sort(one);
			long ans = one.get(0) * one.get(n - 1);

			ArrayList<Long> two = new ArrayList<Long>();
			for (long i = 2; (long) i * i <= ans; i++) {
				if (ans % i == 0) {
					two.add(i);
					if ((ans / i) != i) {
						two.add((ans / i));
					}
				}
			}
			Collections.sort(two);

			if (one.equals(two)) {
				out.print(ans + "\n");
			} else {
				out.print(-1 + "\n");
			}

		}
		out.close();

	}

	private static void solve15() throws IOException {

		int t = r.nextInt();
		while (t-- > 0) {

			int n = r.nextInt();

			if (n == 1) {
				out.println("FastestFinger");
			} else if ((n & 1) != 0 || n == 2) {
				out.println("Ashishgup");
			} else {
				int even = 0, odd = 0;
				for (int i = 2; i * i <= n; i++) {
					if (n % i == 0) {
						while (n % i == 0) {
							n /= i;
							if ((i & 1) == 0) {
								even++;
							} else {
								odd++;
							}
						}
					}
				}
				if (n > 1) {
					if ((n & 1) == 0) {
						even++;
					} else {
						odd++;
					}
				}

				if (even > 1) {
					if (odd > 0) {
						out.println("Ashishgup");
					} else {
						out.println("FastestFinger");
					}
				} else {
					if (odd > 1) {
						out.println("Ashishgup");
					} else {
						out.println("FastestFinger");
					}
				}
			}

		}
		out.close();

	}

	private static boolean isLucky(int num) {
		while (num > 0) {
			int digit = num % 10;
			if (digit != 4 && digit != 7) {
				return false;
			}
			num /= 10;
		}
		return true;
	}

	private static void solve16() throws IOException {

		int n = r.nextInt();
		int m = r.nextInt();

		int arr[] = r.id5(m);
		long ans = arr[0] - 1;

		for (int i = 1; i < m; i++) {
			int diff = arr[i] - arr[i - 1];
			if (diff < 0)
				diff += n;
			ans += diff;
		}

		out.print(ans);
		out.close();

	}

	private static void solve17() throws IOException {

		int n = r.nextInt();
		int arr[] = new int[n];

		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i = 0; i < n; i++) {
			arr[i] = r.nextInt();
			map.put(arr[i], i);
		}

		char ans[] = new char[n];
		int ele = n;

		for (int num = ele; num >= 1; num--) {
			int idx = map.get(num);
			ans[idx] = 'B';
			int id1 = map.get(num) + num;
			int idx_back = map.get(num) - num;
			boolean flag = false;
			while (id1 < n) {
				if (arr[id1] > num) {
					if (ans[id1] == 'B') {
						ans[idx] = 'A';
						flag = true;
						break;
					}
				}
				id1 += num;
			}
			if (!flag) {
				while (idx_back >= 0) {
					if (arr[idx_back] > num) {
						if (ans[idx_back] == 'B') {
							ans[idx] = 'A';
							flag = true;
							break;
						}
					}
					idx_back -= num;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			out.print(ans[i]);
		}
		out.close();

	}

	private static void solve18() throws IOException {

		int n = r.nextInt();
		int m = r.nextInt();

		long a1[] = r.id7(n);
		long a2[] = r.id7(m);

		long ans = Long.MAX_VALUE;

		for (int i = 0; i < n; i++) {
			long curr = Long.MIN_VALUE;
			for (int j = 0; j < n; j++) {
				if (j != i) {
					for (int j2 = 0; j2 < m; j2++) {
						curr = Math.max(curr, a2[j2] * a1[j]);
					}
				}
			}
			ans = Math.min(ans, curr);
		}

		out.print(ans);
		out.close();

	}

	private static void solve19() throws IOException {

		int t = r.nextInt();

		while (t-- > 0) {

			int n = r.nextInt();
			int arr[] = r.id5(n);
			Arrays.sort(arr);

			int ans[] = new int[n];
			int idx = n - 1;

			for (int i = 0; i < n; i++) {
				ans[i] = arr[idx--];
				out.print(ans[i] + " ");
			}
			out.println();

		}
		out.close();

	}

	private static int GCD(int a, int b) {
		return ((b == 0) ? a : GCD(b, a % b));
	}

	private static int id2(int num, int radix) {
		int ans = 0;
		while (num > 0) {
			ans += (num % radix);
			num /= radix;
		}
		return ans;
	}

	private static void solve20() throws IOException {

		int A = r.nextInt();

		int num = 0, demo = A - 2;

		for (int i = 2; i <= A - 1; i++) {
			num += id2(A, i);
		}

		int gcd = GCD(num, demo);

		num /= gcd;
		demo /= gcd;

		out.print(num + "/" + demo);
		out.close();

	}

	private static void solve21() throws IOException {

		int n = r.nextInt();

		String s = r.next();

		StringBuilder ans = new StringBuilder();

		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != '1' && s.charAt(i) != '0') {
				if (s.charAt(i) == '4') {
					ans.append("223");
				} else if (s.charAt(i) == '6') {
					ans.append("35");
				} else if (s.charAt(i) == '8') {
					ans.append("2227");
				} else if (s.charAt(i) == '9') {
					ans.append("2337");
				} else {
					ans.append(s.charAt(i));
				}
			}
		}

		char str[] = ans.toString().toCharArray();

		Arrays.sort(str);

		for (int i = str.length - 1; i >= 0; i--) {
			out.print(str[i]);
		}
		out.close();

	}

	private static void solve22() throws IOException {

		int n = r.nextInt();
		int arr[] = r.id5(n);

		int ans = 0, cnt = 0;

		char ch = 'n';

		for (int i = 0; i < n; i++) {

			if (arr[i] == 0) {
				ch = 'n';
			} else {
				if (ch == 'n') {
					cnt++;
					if (arr[i] == 1) {
						ch = 'c';
					} else if (arr[i] == 2) {
						ch = 's';
					} else {
						ch = 'j';
					}
				} else if (ch == 'c') {
					if (arr[i] == 1) {
						ch = 'n';
					} else {
						cnt++;
						ch = 's';
					}
				} else if (ch == 'j') {
					cnt++;
					if (arr[i] == 1) {
						ch = 'c';
					} else if (arr[i] == 2) {
						ch = 's';
					}
				} else if (ch == 's') {
					if (arr[i] == 2) {
						ch = 'n';
					} else {
						cnt++;
						ch = 'c';
					}
				}
			}

		}

		ans = n - cnt;

		out.print(ans);
		out.close();

	}

	private static void solve23() throws IOException {

		int rad = r.nextInt();
		int x = r.nextInt();
		int y = r.nextInt();
		int x_ = r.nextInt();
		int y_ = r.nextInt();

		double hypot = Math.hypot(Math.abs(x - x_), Math.abs(y - y_));
		int ans = (int) Math.ceil(hypot / (2 * rad));

		out.print(ans);
		out.close();

	}

	private static void solve24() throws IOException {

		int n = r.nextInt();

		double x = r.nextDouble();
		double y = r.nextDouble();

		HashSet<Double> set = new HashSet<>();

		while (n-- > 0) {

			double x_ = r.nextDouble();
			double y_ = r.nextDouble();

			double slope = 0;

			if (x == x_) {
				slope = Double.MAX_VALUE;
			} else if (y != y_) {
				slope = (double) (y - y_) / (x - x_);
			}

			set.add(slope);

		}

		out.print(set.size());
		out.close();

	}

	public static void main(String[] args) throws IOException {






































































		solve24();

	}

	static class Reader {

		final private int BUFFER_SIZE = 1 << 12;
		boolean consume = false;
		private byte[] buffer;
		private int bufferPointer, bytesRead;
		private boolean id3 = false;

		public Reader() {
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = 0;
			bytesRead = 0;
		}

		public boolean hasNext() {
			return !id3;
		}

		private void fillBuffer() throws IOException {
			bytesRead = System.in.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1) {
				buffer[0] = -1;
				id3 = true;
			}
		}

		private void consumeSpaces() throws IOException {
			while (read() <= ' ' && id3 == false)
				;
			bufferPointer--;
		}

		private byte read() throws IOException {
			if (bufferPointer == bytesRead) {
				fillBuffer();
			}
			return buffer[bufferPointer++];
		}

		public String next() throws IOException {
			StringBuilder sb = new StringBuilder();
			consumeSpaces();
			byte c = read();
			do {
				sb.append((char) c);
			} while ((c = read()) > ' ');
			if (consume) {
				consumeSpaces();
			}
			;
			if (sb.length() == 0) {
				return null;
			}
			return sb.toString();
		}

		public String nextLine() throws IOException {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String str = br.readLine();
			return str;
		}

		public int nextInt() throws IOException {
			consumeSpaces();
			int ret = 0;
			byte c = read();
			boolean neg = (c == '-');
			if (neg) {
				c = read();
			}
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (consume) {
				consumeSpaces();
			}
			if (neg) {
				return -ret;
			}
			return ret;
		}

		public long nextLong() throws IOException {
			consumeSpaces();
			long ret = 0;
			byte c = read();
			boolean neg = (c == '-');
			if (neg) {
				c = read();
			}
			do {
				ret = ret * 10L + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (consume) {
				consumeSpaces();
			}
			if (neg) {
				return -ret;
			}
			return ret;
		}

		public double nextDouble() throws IOException {
			consumeSpaces();
			double ret = 0;
			double div = 1;
			byte c = read();
			boolean neg = (c == '-');
			if (neg) {
				c = read();
			}
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (c == '.') {
				while ((c = read()) >= '0' && c <= '9') {
					ret += (c - '0') / (div *= 10);
				}
			}
			if (consume) {
				consumeSpaces();
			}
			if (neg) {
				return -ret;
			}
			return ret;
		}

		public int[] id5(int n) throws IOException {
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			return a;
		}

		public long[] id7(int n) throws IOException {
			long[] a = new long[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextLong();
			}
			return a;
		}

		public int[][] id0(int n, int m) throws IOException {
			int[][] grid = new int[n][m];
			for (int i = 0; i < n; i++) {
				grid[i] = id5(m);
			}
			return grid;
		}

		public char[][] id4(int n) throws IOException {
			char[][] a = new char[n][];
			for (int i = 0; i < n; i++) {
				a[i] = next().toCharArray();
			}
			return a;
		}

		public void close() throws IOException {
			if (System.in == null) {
				return;
			} else {
				System.in.close();
			}
		}
	}

}