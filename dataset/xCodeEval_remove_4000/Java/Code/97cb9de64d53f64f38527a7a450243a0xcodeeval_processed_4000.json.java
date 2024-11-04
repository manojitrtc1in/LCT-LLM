import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class EdA {

	public static void main(String[] args) {
		MyScanner in = new MyScanner();
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		n = in.nextInt();
		m = in.nextInt();
		k = in.nextInt();
		tubeLen = n * m / k;
		taken = new boolean[n][m];
		dfs(0, 0, 0);
	}

	static int n, m, k, tubeLen;
	static boolean taken[][];
	static boolean last = false;

	static void dfs(int i, int j, int count) {
		if (i < 0 || i >= taken.length || j < 0 || j >= taken[0].length || taken[i][j]) {
			return;
		}
		if (count == (k - 1) * tubeLen) {
			System.out.println();
			last = false;
			System.out.print(tubeLen + m * n % k + " ");
			last = true;
		}
		if (count % tubeLen == 0 && !last) {
			System.out.println();
			System.out.print(tubeLen + " ");
		}
		System.out.print((i + 1) + " " + (j + 1) + " ");
		taken[i][j] = true;
		dfs(i, j + 1, count + 1);
		dfs(i, j - 1, count + 1);
		dfs(i + 1, j, count + 1);
	}

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	class Pair implements Comparable<Pair> {
		int a;
		int b;

		Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(Pair p) {
			if (a != p.a) {
				return a - p.a;
			} else {
				return b - p.b;
			}
		}

	}

	static boolean isPrime(int n) {
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}

	static boolean isPalindrome(String s) {
		return s.equals(new StringBuilder(s).reverse().toString());
	}

	static boolean ana(String s1, String s2) {
		char[] a1 = s1.toCharArray();
		char[] a2 = s2.toCharArray();
		Arrays.sort(a1);
		Arrays.sort(a2);
		return Arrays.equals(a1, a2);
	}

	

	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}
