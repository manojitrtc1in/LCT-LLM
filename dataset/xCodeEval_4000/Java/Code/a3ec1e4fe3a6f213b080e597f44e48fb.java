import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.TreeSet;

public class practice_DP {

	static Reader r = new Reader();
	static PrintWriter out = new PrintWriter(System.out);

	private static void solve1() throws IOException {

		int t = r.nextInt();
		StringBuilder res = new StringBuilder();

		while (t-- > 0) {

			int n = r.nextInt();
			int m = r.nextInt();

			int x = r.nextInt();
			int y = r.nextInt();

			char ch[][] = new char[n][m];

			long ans = 0;

			for (int i = 0; i < n; i++) {
				ch[i] = r.next().toCharArray();
				for (int j = 0; j < m; j++) {
					if (ch[i][j] == '.') {
						if (j + 1 < m && ch[i][j + 1] == '.') {
							if (2 * x < y) {
								ans += 2 * x;
							} else {
								ans += y;
							}
							j++;
						} else {
							ans += x;
						}
					}
				}
			}

			res.append(ans).append("\n");

		}

		out.print(res);
		out.close();
	}

	private static void solve2() throws IOException {

		StringBuilder res = new StringBuilder();

		int n = r.nextInt();
		int k = r.nextInt();

		int arr[] = r.nextIntArray(n);

		int cnt = 0;

		for (int i = 1; i < n; i++) {
			if (arr[i] + arr[i - 1] < k) {
				cnt += k - (arr[i] + arr[i - 1]);
				arr[i] += k - (arr[i] + arr[i - 1]);
			}
		}

		res.append(cnt).append("\n");
		for (int i = 0; i < n; i++) {
			res.append(arr[i] + " ");
		}

		out.print(res);
		out.close();

	}

	private static void solve3() throws IOException {

		int n = r.nextInt();

		int ans = 0;
		if ((n & 1) != 0) {
			ans = 0;
		} else {
			ans = (int) Math.pow(2, n / 2);
		}

		out.print(ans);
		out.close();

	}

	private static void solve4() throws IOException {

		int n = r.nextInt();

		int cnt = 0;

		ArrayList<Integer> ans = new ArrayList<Integer>();

		int start = 1, sum = 0;
		while (true) {
			sum += start;
			if (sum > n) {
				sum -= start;
				break;
			} else {
				ans.add(start++);
			}
		}






		ans.set(ans.size() - 1, ans.get(ans.size() - 1) + (n - sum));
		out.print(ans.size() + "\n");
		for (int candies : ans) {
			out.print(candies + " ");
		}
		out.close();

	}

	private static void solve5() throws IOException {

		int n = r.nextInt();

		int fibo[] = new int[21];
		fibo[0] = fibo[1] = 1;

		for (int i = 2; i <= 20; i++) {
			fibo[i] = (fibo[i - 1] + fibo[i - 2]);
		}

		out.print(fibo[n]);
		out.close();

	}

	private static int binarySearch6(int ele) {
		int lt = 0, rt = arr.length - 1;
		int ans = 0;
		while (lt <= rt) {
			int mid = (lt + rt) / 2;
			if (arr[mid] > ele) {
				rt = mid - 1;
			} else {
				ans = mid + 1;
				lt = mid + 1;
			}
		}
		return ans;
	}

	private static void solve6() throws IOException {

		StringBuilder res = new StringBuilder();

		int n = r.nextInt();
		arr = r.nextIntArray(n);

		Arrays.sort(arr);

		int q = r.nextInt();
		while (q-- > 0) {
			int ele = r.nextInt();
			res.append(binarySearch6(ele)).append("\n");
		}

		out.print(res);
		out.close();

	}

	private static void solve7() throws IOException {

		String s = r.next();

		int dp1[] = new int[s.length() + 1];
		int dp2[] = new int[s.length() + 1];

		dp1[0] = dp2[0] = 0;
		for (int i = 0; i < s.length(); i++) {
			dp1[i + 1] = dp1[i];
			dp2[i + 1] = dp2[i];
			if (s.charAt(i) == '.') {
				if (i + 1 < s.length() && s.charAt(i + 1) == '.') {
					dp1[i + 1]++;
				}
			} else {
				if (i + 1 < s.length() && s.charAt(i + 1) == '#') {
					dp2[i + 1]++;
				}
			}
		}






		int m = r.nextInt();
		while (m-- > 0) {

			int lt = r.nextInt() - 1;
			int rt = r.nextInt() - 1;

			out.print(dp1[rt] - dp1[lt] + dp2[rt] - dp2[lt] + "\n");

		}
		out.close();

	}

	static class Query {
		int pos, val;

		public Query(int idx, int vali) {
			pos = idx;
			val = vali;
		}
	}

	static int cnt = 0, freq[], arr[];

	private static void add(int idx) {
		if (freq[arr[idx]] == 0) {
			cnt++;
		}
		freq[arr[idx]]++;
	}

	private static void remove(int idx) {
		freq[arr[idx]]--;
		if (freq[arr[idx]] == 0) {
			cnt--;
		}
	}

	private static void solve8() throws IOException {

		int n = r.nextInt();
		int m = r.nextInt();

		arr = new int[n + 1];
		freq = new int[(int) 1e5 + 1];
		Query q[] = new Query[m];

		for (int i = 1; i <= n; i++) {
			arr[i] = r.nextInt();
			add(i);
		}

		


		for (int i = 0; i < m; i++) {
			q[i] = new Query(i, r.nextInt());
		}
		Arrays.sort(q, new Comparator<Query>() {
			@Override
			public int compare(Query o1, Query o2) {
				return o1.val - o2.val;
			}
		});

		int ans[] = new int[m];
		int lt = 1;
		for (int i = 0; i < m; i++) {
			int val = q[i].val;
			while (lt < val) {
				remove(lt++);
			}
			ans[q[i].pos] = cnt;
		}

		for (int i = 0; i < m; i++) {
			out.println(ans[i]);
		}
		out.close();

	}

	private static void solve9() throws IOException {

		int n = r.nextInt();
		int k = r.nextInt();

		int dp[] = r.nextIntArray(n);
		for (int i = 1; i < n; i++) {
			dp[i] += dp[i - 1];
		}

		int min = dp[k - 1], ans = 0;

		for (int i = k; i < n; i++) {
			if (dp[i] - dp[i - k] < min) {
				min = dp[i] - dp[i - k];
				ans = i - k + 1;
			}
		}

		out.print(++ans);
		out.close();

	}

	private static long sum(long n) {
		return ((n * (3 * n + 1)) / 2);
	}

	private static long binarySearch10(long n) {
		long lt = 1, rt = n;
		long ans = 0;
		while (lt <= rt) {
			long mid = (lt + rt) / 2;
			long val = sum(mid);
			if (val <= n) {
				ans = mid;
				lt = mid + 1;
			} else {
				rt = mid - 1;
			}
		}
		return ans;
	}

	private static void solve10() throws IOException {

		int t = r.nextInt();

		while (t-- > 0) {

			long n = r.nextLong();

			long cnt = 0;

			while (n > 1) {
				long tallest = binarySearch10(n);
				cnt++;
				n -= sum(tallest);
			}

			out.println(cnt);

		}
		out.close();

	}

	private static void solve11() throws IOException {

		int a1 = r.nextInt();
		int a2 = r.nextInt();

		int temp = a1;
		a1 = Math.min(a1, a2);
		a2 = Math.max(a2, temp);

		int cnt = 0;
		while (a1 > 0 && a2 > 0) {
			if (a1 <= 1 && a2 <= 1) {
				break;
			}
			if (a1 > 2) {
				cnt++;
				a1 -= 2;
				a2++;
			} else {
				cnt++;
				a1++;
				a2 -= 2;
			}
		}

		out.print(cnt);
		out.close();

	}

	private static int digitSum(int num) {
		int sum = 0;
		while (num > 0) {
			sum += (num % 10);
			num /= 10;
		}
		return sum;
	}

	private static void solve12() throws IOException {

		int k = r.nextInt();

		int num = 18;
		while (k > 0) {
			if (digitSum(++num) == 10) {
				k--;
			}
		}

		out.print(num);
		out.close();

	}

	private static void solve13() throws IOException {

		int n = r.nextInt();

		int h[] = new int[n];
		int w[] = new int[n];
		int hi[] = new int[n];
		int w_cumu = 0;

		for (int i = 0; i < n; i++) {
			w[i] = r.nextInt();
			w_cumu += w[i];
			h[i] = r.nextInt();
			hi[i] = h[i];
		}

		Arrays.sort(hi);

		for (int i = 0; i < n; i++) {
			int ans = (w_cumu - w[i]);
			if (hi[n - 1] == h[i]) {
				ans *= hi[n - 2];
			} else {
				ans *= hi[n - 1];
			}
			out.print(ans + " ");
		}
		out.close();

	}

	private static long maxDigit(long num) {
		long max = -1;
		while (num > 0) {
			long digit = num % 10;
			num /= 10;
			max = Math.max(max, digit);
		}
		return max;
	}

	private static void solve14() throws IOException {

		long n = r.nextLong();

		long cnt = 0;
		while (n > 0) {
			n -= maxDigit(n);
			cnt++;
		}

		out.print(cnt);
		out.close();

	}

	private static void solve15() throws IOException {

		int n = r.nextInt();
		int arr[] = r.nextIntArray(n);

		int dp[] = new int[n + 1];
		int tot = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) {
				dp[i + 1] = 1;
			} else {
				tot++;
				dp[i + 1] = -1;
			}
		}

		for (int i = 1; i <= n; i++) {
			dp[i] += dp[i - 1];
		}

		int max = Integer.MIN_VALUE;
		for (int i = n; i >= 1; i--) {
			for (int j = 1; j <= i; j++) {
				if (tot + dp[i] - dp[j - 1] > max) {
					max = tot + dp[i] - dp[j - 1];
				}
			}
		}

		out.print(max);
		out.close();

	}

	private static void solve16() throws IOException {

		int t = r.nextInt();

		while (t-- > 0) {

			int n = r.nextInt();
			int arr[] = r.nextIntArray(n);

			ArrayList<Integer> sub_seq = new ArrayList<Integer>();
			int i = 0;
			while (i < n) {
				int max = Integer.MIN_VALUE;
				while (i < n && arr[i] < 0) {
					max = Math.max(max, arr[i++]);
				}
				if (max != Integer.MIN_VALUE)
					sub_seq.add(max);
				max = Integer.MIN_VALUE;
				while (i < n && arr[i] > 0) {
					max = Math.max(max, arr[i++]);
				}
				if (max != Integer.MIN_VALUE)
					sub_seq.add(max);
			}
			long sum = 0;
			for (int ele : sub_seq) {
				sum += ele;
			}

			out.print(sum + "\n");

		}
		out.close();

	}

	private static void solve17() throws IOException {

		int t = r.nextInt();

		while (t-- > 0) {

			int n = r.nextInt();
			int arr[] = r.nextIntArray(n);

			Arrays.sort(arr);

			int max = Integer.MIN_VALUE, cnt = 0, ans = 0;
			for (int i = 0; i < n; i++) {
				max = Math.max(max, arr[i]);
				cnt++;
				if (max == cnt) {
					max = Integer.MIN_VALUE;
					cnt = 0;
					ans++;
				}
			}

			out.print(ans + "\n");

		}

		out.close();

	}

	private static void solve18() throws IOException {

		int t = r.nextInt();

		while (t-- > 0) {

			char str[] = r.next().toCharArray();

			TreeSet<Integer> one = new TreeSet<>();
			TreeSet<Integer> two = new TreeSet<>();
			TreeSet<Integer> three = new TreeSet<>();

			for (int i = 0; i < str.length; i++) {
				if (str[i] == '1') {
					one.add(i);
				} else if (str[i] == '2') {
					two.add(i);
				} else {
					three.add(i);
				}
			}

			int min = Integer.MAX_VALUE;

			for (int idx1 : one) {
				int len1 = Integer.MAX_VALUE, len2 = Integer.MAX_VALUE;
				if (two.higher(idx1) != null) {
					int idx2 = two.higher(idx1);
					if (three.higher(idx2) != null) {
						int idx3 = three.higher(idx2);
						len1 = Math.min(len1, idx3 - idx1 + 1);
					}
				}
				if (three.higher(idx1) != null) {
					int idx2 = three.higher(idx1);
					if (two.higher(idx2) != null) {
						int idx3 = two.higher(idx2);
						len2 = Math.min(len2, idx3 - idx1 + 1);
					}
				}
				min = Math.min(Math.min(len1, len2), min);
			}

			for (int idx1 : two) {
				int len1 = Integer.MAX_VALUE, len2 = Integer.MAX_VALUE;
				if (one.higher(idx1) != null) {
					int idx2 = one.higher(idx1);
					if (three.higher(idx2) != null) {
						int idx3 = three.higher(idx2);
						len1 = Math.min(len1, idx3 - idx1 + 1);
					}
				}
				if (three.higher(idx1) != null) {
					int idx2 = three.higher(idx1);
					if (one.higher(idx2) != null) {
						int idx3 = one.higher(idx2);
						len2 = Math.min(len2, idx3 - idx1 + 1);
					}
				}
				min = Math.min(Math.min(len1, len2), min);
			}

			for (int idx1 : three) {
				int len1 = Integer.MAX_VALUE, len2 = Integer.MAX_VALUE;
				if (two.higher(idx1) != null) {
					int idx2 = two.higher(idx1);
					if (one.higher(idx2) != null) {
						int idx3 = one.higher(idx2);
						len1 = Math.min(len1, idx3 - idx1 + 1);
					}
				}
				if (one.higher(idx1) != null) {
					int idx2 = one.higher(idx1);
					if (two.higher(idx2) != null) {
						int idx3 = two.higher(idx2);
						len2 = Math.min(len2, idx3 - idx1 + 1);
					}
				}
				min = Math.min(Math.min(len1, len2), min);
			}

			if (min == Integer.MAX_VALUE) {
				min = 0;
			}

			out.println(min);

		}

		out.close();

	}

	private static void solve19() throws IOException {

		int n = r.nextInt();

		long arr[] = new long[n + 1];
		long sorted[] = new long[n + 1];

		for (int i = 1; i <= n; i++) {
			arr[i] = r.nextLong();
			sorted[i] = arr[i];
		}

		Arrays.sort(sorted);

		for (int i = 1; i <= n; i++) {
			arr[i] += arr[i - 1];
			sorted[i] += sorted[i - 1];
		}

		int m = r.nextInt();
		StringBuilder ans = new StringBuilder();

		while (m-- > 0) {

			int type = r.nextInt();
			int lt = r.nextInt();
			int rt = r.nextInt();

			long an = 0;
			if (type == 1) {
				an = arr[rt] - arr[lt - 1];
			} else {
				an = sorted[rt] - sorted[lt - 1];
			}
			ans.append(an).append("\n");

		}

		out.print(ans);
		out.close();

	}

	private static void solve20() throws IOException {

		int n = r.nextInt();
		long arr[] = r.nextLongArray(n);

		long dp[][] = new long[n][1 << n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(dp[i], -1);
		}

		dp[0][0] = arr[0];
		dp[0][1] = -arr[0];

		for (int i = 1; i < n; i++) {
			int idx = 0;
			for (int j = 0; j < dp[i - 1].length; j++) {
				if (dp[i - 1][j] != -1) {
					dp[i][idx++] = dp[i - 1][j] + arr[i];
					dp[i][idx++] = dp[i - 1][j] - arr[i];
				} else {
					idx++;
				}
			}
		}

		boolean flag = false;
		for (int i = 0; i < dp[0].length; i++) {
			if (Math.abs(dp[n - 1][i]) % 360 == 0) {
				flag = true;
				break;
			}
		}

		out.print(flag ? "YES" : "NO");
		out.close();

	}

	private static void solve21() throws IOException {

		int n = r.nextInt();
		int k = r.nextInt();

		HashSet<Character> set = new HashSet<>();
		char str[] = r.next().toCharArray();

		for (int i = 0; i < k; i++) {
			set.add(r.next().charAt(0));
		}

		long ans = 0, cnt = 0;
		boolean flag = false;

		for (int i = 0; i < str.length; i++) {
			if (set.contains(str[i])) {
				cnt++;
				flag = true;
			} else {
				if (flag) {
					flag = false;
					ans += ((cnt * (cnt + 1)) / 2);
					cnt = 0;
				}
			}
		}

		if (flag)
			ans += ((cnt * (cnt + 1)) / 2);

		out.print(ans);
		out.close();

	}

	private static void solve22() throws IOException {

		int n = r.nextInt();

		long freq[] = new long[(int) 1e5 + 1];

		for (int i = 0; i < n; i++) {
			freq[r.nextInt()]++;
		}

		long dp[] = new long[(int) 1e5 + 1];
		dp[0] = 0;
		dp[1] = freq[1];

		for (int i = 2; i <= 100000; i++) {
			dp[i] = Math.max(dp[i - 1], (long) freq[i] * i + dp[i - 2]);
		}

		out.print(dp[100000]);
		out.close();

	}

	private static void solve23() throws IOException {

		int n = r.nextInt();
		int x = r.nextInt();

		ArrayList<Integer> arr = new ArrayList<Integer>();
		for (int i = 1; i <= n; i++) {
			arr.add(r.nextInt());
		}
		Collections.sort(arr);

		int ans = 0;

		while (arr.get((arr.size() + 1) / 2 - 1) != x) {
			ans++;
			arr.add(x);
			Collections.sort(arr);
		}

		out.print(ans);
		out.close();

	}

	public static void main(String[] args) throws IOException {



































































		solve23();

	}

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

		public long[] nextLongArray(int n) throws IOException {
			long[] a = new long[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextLong();
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

}