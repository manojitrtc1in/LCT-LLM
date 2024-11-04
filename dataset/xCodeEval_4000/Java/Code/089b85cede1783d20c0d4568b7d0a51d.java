import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;

public class practiceQuestions1 {

	static class Reader {

		final private int BUFFER_SIZE = 1 << 12;
		boolean consume = false;
		private byte[] buffer;
		private int bufferPointer, bytesRead;
		private boolean reachedEnd = false;

		public Reader() {
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = 0;
			bytesRead = 0;
		}

		public boolean hasNext() {
			return !reachedEnd;
		}

		private void fillBuffer() throws IOException {
			bytesRead = System.in.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1) {
				buffer[0] = -1;
				reachedEnd = true;
			}
		}

		private void consumeSpaces() throws IOException {
			while (read() <= ' ' && reachedEnd == false)
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

		public int[] nextIntArray(int n) throws IOException {
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			return a;
		}

		public int[][] nextIntMatrix(int n, int m) throws IOException {
			int[][] grid = new int[n][m];
			for (int i = 0; i < n; i++) {
				grid[i] = nextIntArray(m);
			}
			return grid;
		}

		public char[][] nextCharacterMatrix(int n) throws IOException {
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

	static Reader r = new Reader();
	static PrintWriter out = new PrintWriter(System.out);

	private static void solve1() throws IOException {

		int n = r.nextInt();
		int k = r.nextInt();

		int arr[] = r.nextIntArray(n);
		Arrays.sort(arr);

		int cnt = 0, max = 5 - k;
		for (int i = 0; i < n; i++) {
			if (arr[i] > max) {
				break;
			}
			cnt++;
		}

		int ans = (cnt / 3);

		out.print(ans);
		out.close();

	}

	private static boolean checker(String s) {
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '1' && (i + 2) < s.length() && s.substring(i, i + 3) == "111") {
				return false;
			} else if (s.charAt(i) == '0' && (i + 1) < s.length() && s.substring(i, i + 2) == "00") {
				return false;
			}
		}
		return true;
	}

	private static void solve2() throws IOException {

		int n = r.nextInt();
		int m = r.nextInt();

		String ans = "";

		StringBuilder temp = new StringBuilder();
		while (n + m > 2 && n != 0 && m != 0) {
			if (m >= 2 * n) {
				temp.append("110");
				m -= 2;
				n -= 1;
			} else {
				temp.append("10");
				m -= 1;
				n -= 1;
			}
		}

		ans = temp.toString();

		if (n == 1 && m == 0) {
			temp.insert(0, '0');
			ans = temp.toString();
		} else if (m == 2 && n == 0 || m == 1 && n == 0) {
			for (int i = 1; i <= m; i++) {
				temp.append("1");
			}
			ans = temp.toString();
		} else if (n == 1 && m == 1) {
			temp.append("10");
			ans = temp.toString();
		} else if (m != 0 || n != 0) {
			ans = "-1";
		}




		out.print(ans);
		out.close();

	}

	private static void solve3() throws IOException {

		String a = r.next();
		String b = r.next();

		boolean flag = false;

		if (a.length() == b.length()) {
			if (a.equals(b)) {
				flag = true;
			} else {
				flag = ((a.contains("1") && b.contains("1")) || ((!a.contains("1") && !b.contains("1")))) ? true
						: false;
			}
		}

		out.print(flag ? "YES" : "NO");
		out.close();

	}

	private static void solve4() throws IOException {

		int n = r.nextInt();
		StringBuilder res = new StringBuilder();

		int A = 0, G = 0;
		boolean flag = true;

		while (n-- > 0) {

			int a = r.nextInt();
			int g = r.nextInt();

			int temp_a = A + a;
			int temp_g = G + g;

			if (flag) {
				if (Math.abs(temp_a - G) > 500) {
					if (Math.abs(temp_g - A) > 500) {
						flag = false;
					} else {
						G = temp_g;
						res.append("G");
					}
				} else {
					A = temp_a;
					res.append("A");
				}
			}

		}

		out.print(flag ? res : -1);
		out.close();

	}

	static class sortedArr {
		int idx;
		long freq;

		public sortedArr(int id, long val) {
			idx = id;
			freq = val;
		}
	}

	static class Query {
		int lt, rt;

		public Query(int l, int r) {
			lt = l;
			rt = r;
		}
	}

	private static void solve5() throws IOException {

		int n = r.nextInt();
		int q = r.nextInt();

		long arr[] = new long[n + 1];
		for (int i = 1; i <= n; i++) {
			arr[i] = r.nextLong();
		}
		Arrays.sort(arr);

		long freq[] = new long[n + 2];
		sortedArr array[] = new sortedArr[n + 2];
		Query qu[] = new Query[q];

		for (int i = 0; i < array.length; i++) {
			array[i] = new sortedArr(0, 0);
		}

		for (int i = 0; i < q; i++) {

			int lt = r.nextInt();
			int rt = r.nextInt();

			qu[i] = new Query(lt, rt);

			freq[lt]++;
			freq[rt + 1]--;

		}

		for (int i = 1; i <= n; i++) {
			freq[i] += freq[i - 1];
			array[i].idx = i;
			array[i].freq = freq[i];
		}

		Arrays.sort(array, new Comparator<sortedArr>() {
			@Override
			public int compare(sortedArr o1, sortedArr o2) {
				return Integer.compare((int) o2.freq, (int) o1.freq);
			}
		});

		long fin_arr[] = new long[n + 1];
		int idx = n;

		for (int i = 0; i < n; i++) {
			fin_arr[array[i].idx] = arr[idx--];
		}

		for (int i = 1; i <= n; i++) {
			fin_arr[i] += fin_arr[i - 1];
		}




		long ans = 0;
		for (int i = 0; i < q; i++) {
			ans += (fin_arr[qu[i].rt] - fin_arr[qu[i].lt - 1]);
		}

		out.print(ans);
		out.close();

	}

	static long time[];

	private static long binarySearch(long t, int endI) {
		int i = 0, j = endI;
		long ans = 0, val = time[j];
		while (i <= j) {
			int mid = (i + j) / 2;
			if (val - time[mid] <= t) {
				ans = Math.max(ans, endI - mid);
				j = mid - 1;
			} else {
				i = mid + 1;
			}
		}
		return ans;
	}

	private static void solve6() throws IOException {

		int n = r.nextInt();
		long t = r.nextLong();

		time = new long[n];
		for (int i = 0; i < n; i++) {
			time[i] = r.nextLong();
			if (i > 0) {
				time[i] += time[i - 1];
			}
		}




		long ans = Long.MIN_VALUE;
		for (int i = n - 1; i >= 0; i--) {
			if (i == n - 1 && time[i] <= t) {
				ans = n;
				break;
			}
			ans = Math.max(ans, binarySearch(t, i));
		}

		out.print(ans);
		out.close();

	}

	static boolean seive[] = new boolean[1000001];

	public static void primeSeive() {

		Arrays.fill(seive, true);
		seive[0] = seive[1] = false;

		for (int i = 2; i * i <= 1000000; i++) {
			if (seive[i]) {
				for (int j = i * i; j <= 1000000; j += i) {
					if (seive[j]) {
						seive[j] = false;
					}
				}
			}
		}

	}

	private static void solve7() throws IOException {

		int n = r.nextInt();
		int m = r.nextInt();

		primeSeive();
		int mat[][] = r.nextIntMatrix(n, m);

		int rowMin = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < m; j++) {
				if (!seive[mat[i][j]]) {
					int num = mat[i][j];
					while (!seive[num]) {
						num++;
						cnt++;
					}
				}
			}
			rowMin = Math.min(rowMin, cnt);
		}

		int colMin = Integer.MAX_VALUE;
		for (int i = 0; i < m; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (!seive[mat[j][i]]) {
					int num = mat[j][i];
					while (!seive[num]) {
						num++;
						cnt++;
					}
				}
			}
			colMin = Math.min(colMin, cnt);
		}

		int ans = Math.min(rowMin, colMin);

		out.print(ans);
		out.close();

	}

	private static void solve8() throws IOException {

		int n = r.nextInt();

		int freq[] = new int[(int) 1e5 + 1];

		for (int i = 0; i < n; i++) {
			freq[r.nextInt()]++;
		}

		long dp[] = new long[(int) 1e5 + 1];
		dp[1] = freq[1];

		for (int i = 2; i < dp.length; i++) {
			dp[i] = Math.max(dp[i - 1], (dp[i - 2] + (long) freq[i] * i));
		}

		out.print(dp[100000]);
		out.close();

	}

	private static void solve9() throws IOException {

		String s = r.next();

		StringBuilder ans = new StringBuilder();

		for (int i = 0; i < s.length(); i++) {
			if (i >= 2 && s.charAt(i) == s.charAt(i - 1) && s.charAt(i - 1) == s.charAt(i - 2)
					|| ans.length() >= 3 && s.charAt(i) == ans.charAt(ans.length() - 1)
							&& ans.charAt(ans.length() - 2) == ans.charAt(ans.length() - 3)) {
				continue;
			}
			ans.append(s.charAt(i));
		}

		out.print(ans);
		out.close();

	}

	private static void solve10() throws IOException {

		long ans1 = 0, ans2 = 0;

		long red = r.nextLong();
		long green = r.nextLong();
		long blue = r.nextLong();

		ans1 = (red / 3) + (green / 3) + (blue / 3);
		ans1 += Math.min((red % 3), Math.min((green % 3), (blue % 3)));

		long a = 0, b = 0, c = 0;
		if (red % 3 != 0) {
			ans2 += (red / 3);
			a = red % 3;
		} else {
			if (red >= 1) {
				ans2 += (red - 1) / 3;
				a = 3;
			}
		}

		if (green % 3 != 0) {
			ans2 += (green / 3);
			b = green % 3;
		} else {
			if (green >= 1) {
				ans2 += (green - 1) / 3;
				b = 3;
			}
		}

		if (blue % 3 != 0) {
			ans2 += (blue / 3);
			c = blue % 3;
		} else {
			if (blue >= 1) {
				ans2 += (blue - 1) / 3;
				c = 3;
			}
		}
		ans2 += Math.min(a, Math.min(b, c));

		out.print(Math.max(ans2, ans1));
		out.close();

	}

	static ArrayList<Integer> graph[];
	static boolean visited[];

	private static ArrayList<Integer> DFS(int node, ArrayList<Integer> cc) {
		cc.add(node);
		visited[node] = true;
		for (int child : graph[node]) {
			if (!visited[child]) {
				DFS(child, cc);
			}
		}
		return cc;
	}

	private static void solve11() throws IOException {

		int n = r.nextInt();
		int m = r.nextInt();

		graph = new ArrayList[n + 1];
		visited = new boolean[n + 1];

		for (int i = 0; i <= n; i++) {
			graph[i] = new ArrayList<Integer>();
		}

		for (int i = 1; i <= m; i++) {
			int u = r.nextInt();
			int v = r.nextInt();
			graph[u].add(v);
			graph[v].add(u);
		}

		ArrayList<ArrayList<Integer>> three = new ArrayList();
		ArrayList<ArrayList<Integer>> two = new ArrayList();
		ArrayList<ArrayList<Integer>> one = new ArrayList();
		StringBuilder res = new StringBuilder();

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				ArrayList<Integer> cc = DFS(i, new ArrayList<Integer>());
				if (cc.size() > 3) {
					out.print(-1);
					out.close();
					return;
				} else {
					if (cc.size() == 3) {
						three.add(cc);
					} else if (cc.size() == 2) {
						two.add(cc);
					} else {
						one.add(cc);
					}
				}
			}
		}

		for (int i = 0; i < three.size(); i++) {
			int a = three.get(i).get(0);
			int b = three.get(i).get(1);
			int c = three.get(i).get(2);
			res.append(a).append(" ").append(b).append(" ").append(c).append("\n");
		}

		if (one.size() > 0 || two.size() > 0) {
			if (two.size() == 0) {
				if (one.size() % 3 == 0) {
					for (int i = 0; i < one.size(); i += 3) {
						int a = one.get(i).get(0);
						int b = one.get(i + 1).get(0);
						int c = one.get(i + 2).get(0);
						res.append(a).append(" ").append(b).append(" ").append(c).append("\n");
					}
				} else {
					out.print(-1);
					out.close();
					return;
				}
			} else if (one.size() == 0) {
				out.print(-1);
				out.close();
				return;
			} else if (one.size() > 0 && two.size() > 0) {
				if (one.size() >= two.size() && ((one.size() - two.size()) % 3) == 0) {
					for (int i = 0; i < two.size(); i++) {
						int a = one.get(i).get(0);
						int b = two.get(i).get(0);
						int c = two.get(i).get(1);
						res.append(a).append(" ").append(b).append(" ").append(c).append("\n");
					}
					for (int i = two.size(); i < one.size(); i += 3) {
						int a = one.get(i).get(0);
						int b = one.get(i + 1).get(0);
						int c = one.get(i + 2).get(0);
						res.append(a).append(" ").append(b).append(" ").append(c).append("\n");
					}
				} else {
					out.print(-1);
					out.close();
					return;
				}
			}
		}

		out.print(res);
		out.close();

	}

	private static long recursive(long n, long sln, int f, int s) {
		if (sln >= n && f == s) {
			return sln;
		}
		if (sln >= (long) 1e18) {
			return Long.MAX_VALUE;
		}
		return Math.min(recursive(n, sln * 10 + 4, f + 1, s), recursive(n, sln * 10 + 7, f, s + 1));
	}

	private static void solve12() throws IOException {

		long n = r.nextLong();
		long ans = recursive(n, 0, 0, 0);
		out.print(ans);
		out.close();

	}

	private static void solve13() throws IOException {

		boolean flag = false;

		int n = r.nextInt();
		int arr[] = r.nextIntArray(n);
		HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();

		if (n > 1) {

			int lt = Math.min(arr[0], arr[1]), rt = Math.max(arr[0], arr[1]);

			ArrayList<Integer> temp = new ArrayList<Integer>();
			temp.add(rt);
			map.put(lt, temp);

			for (int i = 2; i < n && !flag; i++) {

				temp = new ArrayList<Integer>();
				lt = Math.min(arr[i - 1], arr[i]);
				rt = Math.max(arr[i - 1], arr[i]);

				if (map.containsKey(lt)) {
					temp = map.get(lt);
				}

				for (int start : map.keySet()) {
					ArrayList<Integer> nodes = map.get(start);
					if (start > lt && start < rt) {
						for (int node : nodes) {
							if (node > rt) {
								flag = true;
								break;
							}
						}
					} else if (start < lt) {
						for (int node : nodes) {
							if (node > lt && node < rt) {
								flag = true;
								break;
							}
						}
					}
					if (flag)
						break;
				}

				temp.add(rt);
				map.put(lt, temp);

			}
		}

		out.print(flag ? "yes" : "no");
		out.close();

	}

	private static int GCD(int a, int b) {
		return ((b == 0) ? a : GCD(b, a % b));
	}

	static int cnt, a, b;

	private static void calc(int num) {
		int p1 = 0, p2 = 0;
		while (a % num == 0) {
			a /= num;
			p1++;
		}
		while (b % num == 0) {
			b /= num;
			p2++;
		}
		cnt += Math.abs(p2 - p1);
	}

	private static void solve14() throws IOException {

		a = r.nextInt();
		b = r.nextInt();

		cnt = 0;

		calc(2);
		calc(3);
		calc(5);

		if (a == b) {
			out.print(cnt);
		} else {
			out.print(-1);
		}

		out.close();

	}

	private static void solve15() throws IOException {

		int n = r.nextInt();

		int arr[] = new int[n];

		int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;

		for (int i = 0; i < n; i++) {
			arr[i] = r.nextInt();
			min = Math.min(min, arr[i]);
			max = Math.max(max, arr[i]);
		}

		int pos = -1, pos_ = 0;

		for (int i = 0; i < n; i++) {
			if (pos == -1 && arr[i] == max) {
				pos = i;
			}
			if (arr[i] == min) {
				pos_ = i;
			}
		}

		int ans = 0;




		if (pos < pos_) {
			ans = pos + (n - 1 - pos_);
		} else {
			ans = pos + (n - pos_ - 2);
		}

		out.print(ans);
		out.close();

	}

	private static void solve16() throws IOException {

		int lt = -1, rt = -1;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				int ele = r.nextInt();
				if (ele == 1) {
					lt = i;
					rt = j;
				}
			}
		}

		out.print(Math.abs(rt - 2) + Math.abs(lt - 2));
		out.close();

	}

	private static void solve17() throws IOException {

		String a = r.next();
		String b = r.next();

		String ans = "";

		for (int i = 0; i < a.length(); i++) {
			if (a.charAt(i) != b.charAt(i)) {
				ans += '1';
			} else {
				ans += '0';
			}
		}

		out.print(ans);
		out.close();

	}

	private static void solve18() throws IOException {

		int n = r.nextInt();

		int diff = n - 10;

		int ans = 0;
		if (diff > 0) {
			if (diff >= 1 && diff <= 9 || diff == 11) {
				ans = 4;
			} else if (diff == 10) {
				ans = 15;
			}
		}

		out.print(ans);
		out.close();

	}

	private static void solve19() throws IOException {

		String s = r.next();

		out.print((s.contains("H") || s.contains("Q") || s.contains("9")) ? "YES" : "NO");
		out.close();

	}

	private static void solve20() throws IOException {

		int n = r.nextInt();
		int arr[] = r.nextIntArray(n);

		int ans = 0;

		int min = arr[0], max = arr[0];

		for (int i = 0; i < n; i++) {
			if (arr[i] < min) {
				ans++;
				min = arr[i];
			} else if (arr[i] > max) {
				ans++;
				max = arr[i];
			}
		}

		out.print(ans);
		out.close();

	}

	private static void solve21() throws IOException {

		String a = r.next();
		String b = r.next();

		int ans = 0;
		if (a.compareToIgnoreCase(b) < 0) {
			ans = -1;
		} else if (a.compareToIgnoreCase(b) > 0) {
			ans = 1;
		}

		out.print(ans);
		out.close();

	}

	private static void solve22() throws IOException {

		int n = r.nextInt();

		int even = 0, odd = 0;
		for (int i = 0; i < n; i++) {
			int ele = r.nextInt();
			if ((ele & 1) == 0) {
				even++;
			} else {
				odd++;
			}
		}

		int ans = 0;
		if ((odd & 1) == 0) {
			ans = even;
		} else {
			ans = odd;
		}

		out.print(ans);
		out.close();

	}

	private static void solve23() throws IOException {

		out.print(0);
		out.close();

	}

	private static void solve24() throws IOException {

		out.print(0);
		out.close();

	}

	private static void solve25() throws IOException {

		out.print(0);
		out.close();

	}

	public static void main(String[] args) throws IOException {
































































		solve22();










	}

}