import java.io.*;
import java.util.*;
import java.lang.*;

public class cf1 {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		if (System.getProperty("ONLINE_JUDGE") == null) {
			long startTime = System.currentTimeMillis();
			try {
				sc = new InputReader(new FileInputStream("src/input.txt"));
				out = new PrintWriter(new FileOutputStream("src/output.txt"));
				pr = new PrintWriter(new FileOutputStream("src/error.txt"));
			} catch (Exception ignored) {
			}
			int t = 1;
			int tt = t;
			t = sc.nextInt();
			while (t-- > 0) {
				solve();
			}
			long endTime = System.currentTimeMillis();
			System.out.println("Time: " + (endTime - startTime) / tt + " ms");
			out.flush();
			pr.flush();

		} else {
			sc = new InputReader(inputStream);
			out = new PrintWriter(outputStream);
			pr = new PrintWriter(outputStream);
			int t = 1;
			t = sc.nextInt();
			while (t-- > 0) {
				solve();
			}
			out.flush();
		}
	}

	public static void solve() {
		int n = sc.nextInt();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		for(int i = 0; i <= n; i++) {
			if(isSorted(arr)) {
				out.println(i);
				break;
			}
			for (int j = (i) % 2; j < n - 1; j += 2) {
                if (arr[j] > arr[j + 1])
                	swap(arr, j, j + 1);
            }
		}
	}
	
	public static void swap(int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	public static boolean isSorted(int[] arr) {
		for(int i = 1; i < arr.length; i++) {
			if(arr[i] < arr[i - 1])
				return false;
		}
		return true;
	}

	
	

	

	


	

	

	

	

	


	

	


	


	public static int inf = Integer.MAX_VALUE;
	public static int minf = Integer.MIN_VALUE;
	public static long linf = 1L << 61;
	public static int mod = 1000000007;
	public static InputReader sc;
	public static PrintWriter out;
	public static PrintWriter pr;

	


	static class Pair {
		int first, second;

		Pair(int x, int y) {
			this.first = x;
			this.second = y;
		}
	}

	


	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	


	static class Node {
		Node next;
		int data;

		Node(int x) {
			next = null;
			this.data = x;
		}
	}

	

	public static int gcd(int a, int b) {
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	public static int lcm(int a, int b) {
		return (a / gcd(a, b)) * b;
	}

	public static long gcd(long a, long b) {
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	public static long lcm(long a, long b) {
		return (a / gcd(a, b)) * b;
	}

	public static long nCr(int n, int r) {
		return fact(n) / (fact(r) * fact(n - r));
	}

	public static long fact(int n) {
		int res = 1;
		for (int i = 2; i <= n; i++)
			res = res * i;
		return res;
	}

	public static long nCr(long n, long r) {
		return fact(n) / (fact(r) * fact(n - r));
	}

	public static long fact(long n) {
		int res = 1;
		for (int i = 2; i <= n; i++)
			res = res * i;
		return res;
	}

	public static String reverseString(String input) {
		StringBuilder str = new StringBuilder("");

		for (int i = input.length() - 1; i >= 0; i--) {
			str.append(input.charAt(i));
		}
		return str.toString();
	}

	public static int maxOf3(int x, int y, int z) {
		return Math.max(x, Math.max(y, z));
	}

	public static int minof3(int x, int y, int z) {
		return Math.min(x, Math.min(y, z));
	}

	public static long maxOf3(long x, long y, long z) {
		return Math.max(x, Math.max(y, z));
	}

	public static long minof3(long x, long y, long z) {
		return Math.min(x, Math.min(y, z));
	}

	public static void arrInput(int[] arr, int n) {
		for (int i = 0; i < n; i++)
			arr[i] = sc.nextInt();
	}

	public static void arrInput(long[] arr, int n) {
		for (int i = 0; i < n; i++)
			arr[i] = sc.nextLong();
	}

	public static void arrInput(Pair[] pair, int n) {
		for (int i = 0; i < n; i++)
			pair[i] = new Pair(sc.nextInt(), sc.nextInt());
	}

	public static int lowerBound(int[] arr, int x) {
		int l = -1, r = arr.length;
		while (l + 1 < r) {
			int m = (l + r) >>> 1;
			if (arr[m] >= x)
				r = m;
			else
				l = m;
		}
		return r;
	}

	public static int upperBound(int[] arr, int x) {
		int l = -1, r = arr.length;
		while (l + 1 < r) {
			int m = (l + r) >>> 1;
			if (arr[m] <= x)
				l = m;
			else
				r = m;
		}
		return l + 1;
	}

	public static void fill(char[][] arr, char c) {
		int n = arr.length, m = arr[0].length;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = c;
	}

	public static void fill(int[][] arr, int c) {
		int n = arr.length, m = arr[0].length;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = c;
	}

	public static void fill(long[][] arr, long c) {
		int n = arr.length, m = arr[0].length;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = c;
	}

	public static void fillPrime(ArrayList<Integer> chprime, int high) {
		boolean[] ck = new boolean[high + 1];
		Arrays.fill(ck, true);
		ck[1] = false;
		ck[0] = false;

		for (int i = 2; (i * i) <= high; i++) {
			if (ck[i] == true) {
				for (int j = i * i; j <= high; j = j + i) {
					ck[j] = false;
				}
			}
		}
		for (int i = 2; i * i <= high; i++) {
			if (ck[i] == true) {
				chprime.add(i);
			}
		}
	}

	public static void segmentedSieve(int low, int high) {
		ArrayList<Integer> chprime = new ArrayList<Integer>();
		fillPrime(chprime, high);

		boolean[] prime = new boolean[high - low + 1];
		Arrays.fill(prime, true);
		for (int i : chprime) {
			int lower = (low / i);
			if (lower <= 1) {
				lower = i + i;
			} else if (low % i != 0) {
				lower = (lower * i) + i;
			} else {
				lower = (lower * i);
			}
			for (int j = lower; j <= high; j = j + i) {
				prime[j - low] = false;
			}
		}
		for (int i = low; i <= high; i++) {
			if (prime[i - low] == true) {
				primeNo.add(i);
			}
		}
	}

	public static ArrayList<Integer> primeNo = new ArrayList<>();

	public static void merge(int arr[], int l, int m, int r) {
		int n1 = m - l + 1;
		int n2 = r - m;
		int L[] = new int[n1];
		int R[] = new int[n2];
		for (int i = 0; i < n1; ++i)
			L[i] = arr[l + i];
		for (int j = 0; j < n2; ++j)
			R[j] = arr[m + 1 + j];
		int i = 0, j = 0;
		int k = l;
		while (i < n1 && j < n2) {
			if (L[i] >= R[j]) {
				arr[k] = L[i];
				i++;
			} else {
				arr[k] = R[j];
				j++;
			}
			k++;
		}
		while (i < n1) {
			arr[k] = L[i];
			i++;
			k++;
		}
		while (j < n2) {
			arr[k] = R[j];
			j++;
			k++;
		}
	}

	public static void reversesort(int arr[], int l, int r) {
		if (l < r) {
			int m = l + (r - l) / 2;
			reversesort(arr, l, m);
			reversesort(arr, m + 1, r);
			merge(arr, l, m, r);
		}
	}

	public static void merge(long arr[], int l, int m, int r) {
		int n1 = m - l + 1;
		int n2 = r - m;
		long L[] = new long[n1];
		long R[] = new long[n2];
		for (int i = 0; i < n1; ++i)
			L[i] = arr[l + i];
		for (int j = 0; j < n2; ++j)
			R[j] = arr[m + 1 + j];
		int i = 0, j = 0;
		int k = l;
		while (i < n1 && j < n2) {
			if (L[i] >= R[j]) {
				arr[k] = L[i];
				i++;
			} else {
				arr[k] = R[j];
				j++;
			}
			k++;
		}
		while (i < n1) {
			arr[k] = L[i];
			i++;
			k++;
		}
		while (j < n2) {
			arr[k] = R[j];
			j++;
			k++;
		}
	}

	public static void reversesort(long arr[], int l, int r) {
		if (l < r) {
			int m = l + (r - l) / 2;
			reversesort(arr, l, m);
			reversesort(arr, m + 1, r);
			merge(arr, l, m, r);
		}
	}

	public static void sort(int[] arr) {
		Arrays.sort(arr);
	}

	public static void sort(long[] arr) {
		Arrays.sort(arr);
	}

	public static void sort(ArrayList<Integer> list) {
		Collections.sort(list);
	}

	public static long sumint(int n) {
		long ans = 0;
		char[] s = String.valueOf(n).toCharArray();
		for (int i = 0; i < s.length; ++i)
			ans += s[i] - '0';
		return ans;
	}

	public static long sumint(long n) {
		long ans = 0;
		char[] s = String.valueOf(n).toCharArray();
		for (int i = 0; i < s.length; ++i)
			ans += s[i] - '0';
		return ans;
	}

	public static void arrInput(ArrayList<Integer> list, int n) {
		for (int i = 0; i < n; i++) {
			list.add(sc.nextInt());
		}
	}

	public static void arrLInput(ArrayList<Long> list, int n) {
		for (int i = 0; i < n; i++) {
			list.add(sc.nextLong());
		}
	}

	


	public static void debug() {
		if (sysFlag)
			pr.println("");
	}

	public static boolean sysFlag = System.getProperty("ONLINE_JUDGE") == null;

	public static void debug(int[][] dp) {
		if (sysFlag) {
			for (int i = 0; i < dp.length; ++i) {
				pr.print(i + "--> ");
				for (int j = 0; j < dp[0].length; ++j) {
					pr.print(dp[i][j] + " ");
				}
				pr.println("");
			}
		}
	}

	public static void debug(char[][] arr) {
		if (sysFlag) {
			for (int i = 0; i < arr.length; ++i) {
				for (int j = 0; j < arr[0].length; ++j) {
					pr.print(arr[i][j]);
				}
				pr.println("");
			}
		}
	}

	public static void debug(long[][] dp) {
		if (sysFlag) {
			for (int i = 0; i < dp.length; ++i) {
				pr.print(i + "--> ");
				for (int j = 0; j < dp[0].length; ++j) {
					pr.print(dp[i][j] + " ");
				}
				pr.println("");
			}
		}
	}

	public static void debug(int x) {
		if (sysFlag)
			pr.println("Int-Ele: " + x);
	}

	public static void debug(String x) {
		if (sysFlag)
			pr.println("String: " + x);
	}

	public static void debug(char x) {
		if (sysFlag)
			pr.println("Char: " + x);
	}

	public static void debug(long x) {
		if (sysFlag)
			pr.println("Long-Ele: " + x);
	}

	public static void debug(int[] arr) {
		if (sysFlag) {
			for (int i = 0; i < arr.length; ++i) {
				pr.println(i + " -> " + arr[i]);
			}
		}
	}

	public static void debug(char[] arr) {
		if (sysFlag) {
			for (int i = 0; i < arr.length; ++i) {
				pr.println(i + " -> " + arr[i]);
			}
		}
	}

	public static void debug(long[] arr) {
		if (sysFlag) {
			for (int i = 0; i < arr.length; ++i) {
				pr.println(i + " -> " + arr[i]);
			}
		}
	}

	public static void debug(ArrayList<Integer> list) {
		if (sysFlag) {
			for (int i = 0; i < list.size(); ++i) {
				pr.println(i + " -> " + list.get(i));
			}
		}
	}

	public static void Ldebug(ArrayList<Long> list) {
		if (sysFlag) {
			for (int i = 0; i < list.size(); ++i) {
				pr.println(i + " -> " + list.get(i));
			}
		}
	}

	public static void debugmapII(HashMap<Integer, Integer> map) {
		if (sysFlag) {
			for (Map.Entry<Integer, Integer> entry : map.entrySet())
				pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
		}
	}

	public static void debugmapLI(HashMap<Long, Integer> map) {
		if (sysFlag) {
			for (Map.Entry<Long, Integer> entry : map.entrySet())
				pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
		}
	}

	public static void debugmapLL(HashMap<Long, Long> map) {
		if (sysFlag) {
			for (Map.Entry<Long, Long> entry : map.entrySet())
				pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
		}
	}

	public static void debugmapIL(HashMap<Integer, Long> map) {
		if (sysFlag) {
			for (Map.Entry<Integer, Long> entry : map.entrySet())
				pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
		}
	}

	public static void debugmapSL(HashMap<String, Long> map) {
		if (sysFlag) {
			for (Map.Entry<String, Long> entry : map.entrySet())
				pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
		}
	}

	public static void debugmapCL(HashMap<Character, Long> map) {
		if (sysFlag) {
			for (Map.Entry<Character, Long> entry : map.entrySet())
				pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
		}
	}

	public static void debugmapSI(HashMap<String, Integer> map) {
		if (sysFlag) {
			for (Map.Entry<String, Integer> entry : map.entrySet())
				pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
		}
	}

	public static void debugmapCI(HashMap<Character, Integer> map) {
		if (sysFlag) {
			for (Map.Entry<Character, Integer> entry : map.entrySet())
				pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
		}
	}

	public static void debug(Set<Integer> set) {
		if (sysFlag) {
			Iterator value = set.iterator();
			int i = 1;
			while (value.hasNext()) {
				pr.println((i++) + "-> " + value.next());
			}
		}
	}

	public static void debug(Pair[] pair, int n) {
		if (sysFlag) {
			for (int i = 0; i < n; i++) {
				pr.println("first:" + pair[i].first + " second:" + pair[i].second);
			}
		}
	}
}