import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

import javax.xml.bind.ValidationEvent;


public class DynamicProgrammingPractice {
	public static void main(String[] args) {
		

		

		

		

		

		

		

		

		mysteriousPresent(System.in);
	}

	public static void mysteriousPresent(InputStream in) {
		MyScanner scan = new MyScanner(in);
		int n = scan.nextInt();
		int w = scan.nextInt();
		int h = scan.nextInt();
		ArrayList<int[]> list = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int[] x = {scan.nextInt(), scan.nextInt(), i+1};
			list.add(x);
		}
		
		for (int i = 0; i < list.size(); i++) {
			if (list.get(i)[0] <= w || list.get(i)[1] <= h) {
				list.remove(i--);
			}
		}
		
		int[][] a = new int[list.size()][2];
		for (int i = 0; i < list.size(); i++) {
			a[i] = list.get(i);
		}
		
		Arrays.sort(a, new Comparator<int[]>(){
			@Override
			public int compare(int[] o1, int[] o2) {				
				return Long.compare((long)o2[0] * o2[1], (long)o1[0] * o1[1]);
			}
		});
		
		int[] dp = new int[a.length];
		int[] back = new int[a.length];
		for (int i = 0; i < a.length; i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (a[i][0] < a[j][0] && a[i][1] < a[j][1]) {
					if (dp[i] < dp[j] + 1) {
						dp[i] = dp[j] + 1;
						back[i] = j;
					}
				}
			}
		}
		int max = 0;
		int maxIdx = 0;
		for (int i = 0; i < back.length; i++) {
			if (dp[i] > max) {
				max = dp[i];
				maxIdx = i;
			}
		}
		
		String ret = "";
		for (int i = 0; i < max; i++) {
			 ret += (a[maxIdx][2]) + " ";
			 maxIdx = back[maxIdx];
		}
		
		System.out.println(max);
		if (max > 0) {
			System.out.println(ret);
		}
	}

	public static void weather(InputStream in) {
		MyScanner scan = null;
		try {
			scan = new MyScanner(new FileInputStream("input.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int n = scan.nextInt();
		int[] a = scan.nextIntArray(n);
		int[] zeros = new int[n];
		int[] zerosBack = new int[n];
		int[] pos = new int[n];
		int[] neg = new int[n];
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			zeros[i] = i > 0 ? zeros[i-1] : 0; 
			if (a[i] == 0) {
				zeros[i]++;
			}
			pos[i] = i > 0 ? pos[i-1] : 0; 
			if (a[i] > 0) {
				pos[i]++;
			}
		}
		for (int i = n-1; i >= 0; i--) {
			zerosBack[i] = (i < n-1) ? zerosBack[i+1] : 0; 
			if (a[i] == 0) {
				zerosBack[i]++;
			}
			neg[i] = (i < n-1) ? neg[i+1] : 0; 
			if (a[i] < 0) {
				neg[i]++;
			}
		}
		for (int i = 0; i < n-1; i++) {
			min = Math.min(min, zeros[i] + pos[i] + neg[i+1] + zerosBack[i+1]);
		}
		FileWriter write = null;
		try {
			write = new FileWriter("output.txt");
			write.write(min + "\n");
			write.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void goodSequences(InputStream in) {
		MyScanner scan = new MyScanner(in);
		int n = scan.nextInt();
		int[] a = scan.nextIntArray(n);
		LinkedHashSet<Integer> allp = getPrimes(100000);
		HashMap<Integer, Integer> dp = new HashMap<>();
		for (int p: allp) {
			dp.put(p, 0);
		}
		int best = 0;
		for (int i = 0; i < a.length; i++) {
			HashSet<Integer> primes = getPrimeFactors(a[i]);
			int max = 0;
			for (int p: primes) {
				max = Math.max(dp.get(p), max);
			}
			max++;
			for (int p: primes) {
				dp.put(p, max);
			}
			best = Math.max(best, max);
		}
		System.out.println(best); 
	}
	
	public static HashSet<Integer> getPrimeFactors(int n) {
		HashSet<Integer> factors = new HashSet<>();
		int d = 2;
		while (n > 1) {
			while (n % d == 0) {
				factors.add(d);
				n /= d;
			}
			d++;
			if (d*d > n) {
				if (n > 1) {
					factors.add(n);
					break;
				}
			}
		}
		return factors;
	}
	
	
	public static LinkedHashSet<Integer> getPrimes(long limit) {
		LinkedHashSet<Integer> primes = new LinkedHashSet<Integer>();
		LinkedHashSet<Integer> notPrimes = new LinkedHashSet<Integer>();
		boolean prime = true;
		for (int i = 2; i <= limit; i++) {
			prime = true;
			if (notPrimes.contains(i)) {
				prime = false;
			}
			if (prime) {
				primes.add(i);
				for (int j = 2; j*i <= limit; j++) {
					notPrimes.add(j*i);
				}
			}
		}
		return primes;
	}

	public static void colorStripeTest() {
		int n = 500000;
		int k = 26;
		char[] c = new char[n];
		Random rand = new Random(0);
		for (int i = 0; i < c.length; i++) {
			c[i] = (char) ('A' + rand.nextInt(k));
		}
		long time = System.currentTimeMillis();
		colorStripe(n, k, c);
		time = System.currentTimeMillis() - time;
		System.out.println(time);
	}

	public static void colorStripe(InputStream in) {
		MyScanner scan = new MyScanner(in);
		int n = scan.nextInt();
		int k = scan.nextInt();
		char[] a = scan.nextLine().toCharArray();
		
		colorStripe(n, k, a);
	}
	
	
	public static void colorStripe(int n, int k, char[] a) {
		int[][] dp = new int[n][k];
		int[][] back = new int[n][k];
		for (int i = 0; i < k; i++) {
			dp[0][i] = i == (a[0] - 'A') ? 0 : 1;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < k; j++) {
				int min = Integer.MAX_VALUE;
				for (int m = 0; m < k; m++) {
					if (min > dp[i-1][m] && j != m) {
						min = dp[i-1][m];
						back[i][j] = m;
					}
				}
				min += j == (a[i] - 'A') ? 0 : 1;
				dp[i][j] = min;
			}
		}
		
		int min = Integer.MAX_VALUE;
		int minIdx = 0;
		for (int i = 0; i < k; i++) {
			if (dp[n-1][i] < min) {
				min = dp[n-1][i];
				minIdx = i;
			}
		}
		
		char[] ret = new char[n];
		int current = minIdx;
		for (int i = n-1; i >= 0; i--) {
			ret[i] = (char) (current + 'A');
			current = back[i][current];
		}
		System.out.println(min);
		System.out.println(new String(ret));
	}

	public static class Array1Comp implements Comparator<int[]> {
		@Override
		public int compare(int[] o1, int[] o2) {
			return Integer.compare(o1[0], o2[0]);
		}
	}
	
	public static class Array2Comp implements Comparator<int[]> {
		@Override
		public int compare(int[] o1, int[] o2) {
			return Integer.compare(o1[1], o2[1]);
		}
	}

	public static void theLeastRoundWay(InputStream in) {
		MyScanner scan = new MyScanner(in);
		int n = scan.nextInt();
		int[][] a = new int[n][n];
		for (int i = 0; i < n; i++) {
			a[i] = scan.nextIntArray(n);
		}
		int[][] backtrack = new int[n][n];
		int[][][] dp = new int[n][2][2];
		int[][][] nextDp = new int[n][2][2];
		for (int i = 0; i < n; i++) {
			nextDp = new int[n][2][2];
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < 2; k++) {
					int[] rem = {0, 0};
					int x = a[i][j];
					while (x > 0 && x % 2 == 0) {
						rem[0]++;
						x /= 2;
					}
					while (x > 0 && x % 5 == 0) {
						rem[1]++;
						x /= 5;
					}
					if (i == 0 && j == 0) {
						for (int m = 0; m < 2; m++) {
							nextDp[j][k][m] = rem[m];
						}
					} else if (i == 0) {
						for (int m = 0; m < 2; m++) {
							nextDp[j][k][m] = (nextDp[j-1][k][m] + rem[m]);
							backtrack[i][j] = 1;
						}
					} else if (j == 0) {
						for (int m = 0; m < 2; m++) {
							nextDp[j][k][m] = (dp[j][k][m] + rem[m]);
							backtrack[i][j] = 2;
						}
					} else {
						ArrayList<int[]> list = new ArrayList<>();
						list.add(new int[]{dp[j][0][0], dp[j][0][1], 2});
						list.add(new int[]{dp[j][1][0], dp[j][1][1], 2});
						list.add(new int[]{nextDp[j-1][0][0], nextDp[j-1][0][1], 1});
						list.add(new int[]{nextDp[j-1][1][0], nextDp[j-1][1][1], 1});
						if (k == 0) {
							Collections.sort(list, new Array1Comp());
						} else {
							Collections.sort(list, new Array2Comp());
						}
						for (int m = 0; m < 2; m++) {
							nextDp[j][k][m] = (list.get(0)[m] + rem[m]);
							backtrack[i][j] = list.get(0)[2];
						}
					}
				}
			}
			dp = nextDp;
		}
		int min = Integer.MAX_VALUE;
		ArrayList<Character> path = new ArrayList<>();
		int x = n-1;
		int y = n-1;
		while (x >= 0 && y >= 0) {
			if (backtrack[y][x] == 0) {
				break;
			} else if (backtrack[y][x] == 1) {
				path.add('R');
				x--;
			} else {
				path.add('D');
				y--;
			}
		}
		Collections.reverse(path);
		StringBuilder sb = new StringBuilder();
		for (char c: path) {
			sb.append(c);
		}
		for (int k = 0; k < 2; k++) {
			for (int m = 0; m < 2; m++) {
				min = Math.min(dp[n-1][k][m], min);
			}
		}
		System.out.println(min);
		System.out.println(sb);
	}
	
	public static void test() {
		Random rand = new Random(0);
		int max = 1000;
		int numTests = 1000;
		for (int t = 0; t < numTests; t++) {
			int k = rand.nextInt(max);
			char[] s = new char[rand.nextInt(max)];
			for (int i = 0; i < s.length; i++) {
				s[i] = (char) (rand.nextInt(2) + '0');
			}
			anotherProblemOnStrings(k, s);
		}
	}

	public static long anotherProblemOnStrings(InputStream in) {
		MyScanner scan = new MyScanner(in);
		int k = scan.nextInt();
		char[] s = scan.nextLine().toCharArray();
		return anotherProblemOnStrings(k, s);
	}
	
	private static long anotherProblemOnStrings(int k, char[] s) {

		int start = 0;
		ArrayList<Integer> ones = new ArrayList<>();
		for (int i = 0; i < s.length; i++) {
			if (s[i] == '1') {
				ones.add(i);
			}
		}
		if (k == 0) {
			ArrayList<Integer> numZ = new ArrayList<>();
			int len = 0;
			if (s[0] == '0') {
				len++;
			}
			for (int i = 1; i < s.length; i++) {
				if (s[i] == '0' && s[i-1] == s[i]) {
					len++;
				} else if (s[i] == '0') {
					len = 1;
				} else {
					numZ.add(len);
					len = 0;
				}
			}
			numZ.add(len);
			long total = 0;
			for (int i = 0; i < numZ.size(); i++) {
				total += (long)numZ.get(i) * (numZ.get(i)+1)/2;
			}
			return total;
		} 
		if (ones.isEmpty()) {
			return 0;
		}
		int end = 0;
		long total = 0;
		for (int i = 0; i < ones.size()-k+1; i++) {
			start = ones.get(i);
			end = ones.get(i + k-1);
			int leftZ = 0;
			int rightZ = 0;
			start--;
			while (start >= 0 && start <= s.length && s[start] == '0') {
				leftZ++;
				start--;
			}
			end++;
			while (end >= 0 && end < s.length && s[end] == '0') {
				rightZ++;
				end++;
			}
			total += (long)(leftZ+1) * (rightZ +1);
		}
		return total;
	}

	public static void poloThePenguinAndMatrix(InputStream in) {
		MyScanner scan = new MyScanner(in);
		int n = scan.nextInt();
		int m = scan.nextInt();
		int d = scan.nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < a.length; i++) {
			a[i] = scan.nextIntArray(m);
		}
		
		boolean valid = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (Math.abs(a[0][0] - a[i][j]) % d != 0) {
					valid = false;
				}
			}
		}
		
		if (!valid) {
			System.out.println(-1);
			return;
		}
		
		int min = Integer.MAX_VALUE;
		int max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				min = Math.min(min, a[i][j]);
				max = Math.max(max, a[i][j]);
			}
		}
		
		int best = Integer.MAX_VALUE;
		for (int i0 = min; i0 <= max; i0+=d) {
			int total = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					total += Math.abs(a[i][j] - i0)/d;
				}
			}
			best = Math.min(best, total);
		}
		
		System.out.println(best);
	}

	public static final int mod = 1000000007;
	public static void tetrahedron(InputStream in) {
		MyScanner scan = new MyScanner(in);
		int n = scan.nextInt();
		int[] dp = new int[4];
		dp[3] = 1;
		for (int i = 1; i <= n; i++) {
			int[] nextDp = new int[4];
			for (int j = 0; j < nextDp.length; j++) {
				for (int k = 0; k < nextDp.length; k++) {
					if (k != j) {
						nextDp[j] = (nextDp[j] + dp[k]) % mod;
					}
				}
			}
			dp = nextDp;
		}
		System.out.println(dp[3]);
	}

	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner(InputStream in) {
			this.br = new BufferedReader(new InputStreamReader(in));
		}

		public void close() {
			try {
				this.br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					String s = br.readLine();
					if (s != null) {
						st = new StringTokenizer(s);
					} else {
						return null;
					}
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = this.nextLong();
			}
			return a;
		}

		int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = this.nextInt();
			}
			return a;
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

		String nextLine(){
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
