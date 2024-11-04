import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Stack;
import java.util.concurrent.ThreadLocalRandom;

public class Main {

	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static long ans = 0;
	private static int[] res;
	private static boolean[] valid;

	public static void main(String[] args) throws IOException {
		

		solve2();
		

	}

	private static void solve3() throws NumberFormatException, IOException {
		int i, j, n;
		n = readInt();
		Map<Integer, List<Integer>> map = new HashMap<>();
		for (i = 0; i < n - 1; i++) {
			int[] temp = readArray();
			int key = temp[0];
			int value = temp[1];
			

			if (map.containsKey(key)) {
				List<Integer> values = map.get(key);
				values.add(value);
				map.put(key, values);
			} else {
				List<Integer> values = new ArrayList<>();
				values.add(value);
				map.put(key, values);
			}

			

			if (map.containsKey(value)) {
				List<Integer> values = map.get(value);
				values.add(key);
				map.put(value, values);
			} else {
				List<Integer> values = new ArrayList<>();
				values.add(key);
				map.put(value, values);
			}
		}
		if (n % 2 == 1) {
			System.out.println("-1");
			return;
		}
		int ans = 0;
		int count = map.keySet().size();
		while (true) {
			int c = 0;
			for (i = 1; i <= n; i++) {
				

				

				

				

				if (map.get(i).size() == 0) {
					System.out.println("-1");
					return;
				}
				if (map.get(i).size() == 1) {
					Integer value = map.get(i).get(0);
					if (map.get(value).size() > 1) {
						List<Integer> id4 = new ArrayList<>();
						for (Integer key : map.get(value)) {
							if (key == i) {
								continue;
							}
							id4.add(key);
						}
						List<Integer> newList = new ArrayList<>();
						newList.add(i);
						

						map.put(value, newList);
						if (id4.size() == 0) {
							c++;
						} else {
							

							for (Integer key : id4) {
								List<Integer> values = map.get(key);
								if (values.size() > 1) {
									ans++;
									values.remove(value);
									map.put(key, values);
								}
							}
						}
					} else if (map.get(value).size() == 1) {
						c++;
					}
				}
			}
			if (c == count) {
				break;
			}
		}
		System.out.println(ans);
	}

	private static void solve2() throws NumberFormatException, IOException {
		int i, j, n;
		n = readInt();
		int[] w = readArray();
		Map<Integer, Integer> map = new HashMap<>();
		for (i = 0; i < n; i++) {
			map.put(w[i], i + 1);
		}
		Arrays.sort(w);
		String str = br.readLine();
		Stack<Integer> stack = new Stack<>();
		int intro = 0;
		for (i = 0; i < 2 * n; i++) {
			if (str.charAt(i) == '0') {
				System.out.print(map.get(w[intro]) + " ");
				stack.push(w[intro]);
				intro++;
			} else {
				System.out.print(map.get(stack.pop()) + " ");
			}
		}

	}

	private static int findMax(int[] arr, int n) {
		int min = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i] > arr[min]) {
				min = i;
			}
		}
		return min;
	}

	private static void solve1() throws NumberFormatException, IOException {
		int t, i, j, n;
		n = readInt();
		String str = br.readLine();
		if (n == 1) {
			if (str.equals("1")) {
				System.out.println("Yes");
			} else {
				System.out.println("No");
			}
			return;
		}
		

		for (i = 0; i < n - 1; i++) {
			if (str.charAt(i) == str.charAt(i + 1) && str.charAt(i) == '1') {
				System.out.println("No");
				return;
			}
		}
		

		if (str.charAt(0) == '0' && str.charAt(1) == '0') {
			System.out.println("No");
			return;
		}
		if (str.charAt(n - 1) == '0' && str.charAt(n - 2) == '0') {
			System.out.println("No");
			return;
		}
		String wrong = "000";
		if (str.contains(wrong)) {
			System.out.println("No");
			return;
		}
		System.out.println("Yes");
	}

	public static void main3(String[] args) throws IOException {
		int t, i, j, n;
		t = 1;
		n = 200;
		while (t-- != 0) {
			int[] in1 = new int[n];
			for (i = 0; i < n; i++) {
				int randomNum = ThreadLocalRandom.current().nextInt(0, 100);
				in1[i] = randomNum;
			}
			

			

			int[] in2 = new int[n];
			for (i = 0; i < n; i++) {
				in2[i] = in1[i];
			}
			for (i = 0; i < n; i++) {
				System.out.print(in1[i] + ", ");
			}
			System.out.println();
			int[] a1 = abcd3(in1, n);
			System.out.println("done");
			int[] a2 = abcd2(in2, n);
			

			

			

			

			long sum1 = findSum(a1);
			long sum2 = findSum(a2);
			

			for (i = 0; i < n; i++) {
				if (a1[i] != a2[i] && sum1 != sum2) {
					System.out.println("miss-matching");
					for (j = 0; j < n; j++) {
						System.out.print(in1[j] + ", ");
					}
					System.out.println();
				}
			}
		}
	}

	private static long findSum(int[] a1) {
		long sum = 0;
		for (int i = 0; i < a1.length; i++) {
			sum += a1[i];
		}
		return sum;
	}

	private static int[] abcd(int[] a, int n) throws IOException {
		int i, j;
		ans = 0l;
		

		

		int[] res = new int[n];
		valid = new boolean[n];
		

		int[] temp = new int[n];
		for (i = 0; i < n; i++) {
			ans += a[i];
			res[i] = a[i];
			temp[i] = a[i];
			valid[i] = id5(a, i);
		}

		int[][] res1 = new int[2][n];
		res1[0] = temp;
		int size = 1;
		boolean done = false;
		for (i = 0; i < n; i++) {
			done = false;
			for (int k = 0; k < size; k++) {
				if (res1[k][i] > 0 && id5(res1[k], i)) {
					res1[k][i] = -res1[k][i];
				} else if (valid[i]) {
					if (size == 1) {
						temp = new int[n];
						for (j = 0; j < i - 2; j++) {
							temp[j] = res1[k][j];
						}
						for (j = (i - 2 >= 0 ? i - 2 : 0); j < n; j++) {
							temp[j] = a[j];
						}
						if (temp[i] > 0 && id5(temp, i)) {
							temp[i] = -temp[i];
							res1[1] = temp;
							done = true;
						}
					} else {
						if (k == 0 && res1[1][i] > 0 && id5(res1[1], i)) {
							res1[1][i] = -res1[1][i];
						} else if (res1[0][i] > 0 && id5(res1[0], i)) {
							res1[0][i] = -res1[0][i];
						}
					}
				}
			}
			if (done) {
				size = 2;
			}
		}
		

		

		

		

		

		

		

		long sum = ans;
		for (j = 0; j < size; j++) {
			long localSum = 0l;
			for (i = 0; i < n; i++) {
				localSum += res1[j][i];
			}
			if (localSum <= 0) {
				System.exit(1);
			}
			if (localSum < sum) {
				sum = localSum;
				res = res1[j];
			}
		}
		

		

		

		

		return res;
	}

	private static boolean id5(int[] a, int i) {
		int n = a.length;
		if (i > 0 && -a[i] + a[i - 1] <= 0) {
			return false;
		}
		if (i > 1 && -a[i] + a[i - 1] + a[i - 2] <= 0) {
			return false;
		}
		if (i < n - 1 && -a[i] + a[i + 1] <= 0) {
			return false;
		}
		if (i < n - 2 && -a[i] + a[i + 1] + a[i + 2] <= 0) {
			return false;
		}
		return true;
	}

	public static int[] abcd2(int[] a, int n) throws IOException {
		int t, i, j;
		t = 1;
		while (t-- != 0) {
			ans = 0l;
			

			

			res = new int[n];
			

			for (i = 0; i < n; i++) {
				ans += a[i];
				res[i] = a[i];
			}
			solve(a, n, 0, ans);
		}
		return res;
	}

	private static void solve(int[] a, int n, int index, long sum) {
		if (sum > 0 && sum < ans) {
			res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = a[i];
			}
			ans = sum;
		}

		if (sum <= 0 || index >= n) {
			return;
		}

		solve(a, n, index + 1, sum);

		if (id5(a, index)) {
			int[] temp = new int[n];
			for (int i = 0; i < n; i++) {
				temp[i] = a[i];
			}
			temp[index] = -1 * a[index];
			solve(temp, n, index + 1, sum - 2 * a[index]);
		}
	}

	public static int[] abcd3(int[] a, int n) throws IOException {
		int t, i, j;
		t = 1;
		while (t-- != 0) {
			ans = 0l;
			

			

			List<int[]> list = new ArrayList<int[]>();
			res = new int[n];
			valid = new boolean[n];
			

			int[] temp = new int[n];
			for (i = 0; i < n; i++) {
				ans += a[i];
				res[i] = a[i];
				temp[i] = a[i];
				valid[i] = id5(a, i);
			}
			list.add(temp);

			for (i = 0; i < n; i++) {
				Iterator<int[]> iter = list.iterator();
				List<int[]> tempList = new ArrayList<int[]>();
				while (iter.hasNext()) {
					int[] arr = iter.next();
					if (arr[i] > 0 && id5(arr, i)) {
						arr[i] = -arr[i];
					} else if (valid[i]) {
						temp = new int[n];
						for (j = 0; j < i - 2; j++) {
							temp[j] = arr[j];
						}
						for (j = (i - 2 >= 0 ? i - 2 : 0); j < n; j++) {
							temp[j] = a[j];
						}
						if (id5(temp, i)) {
							temp[i] = -temp[i];
							tempList.add(temp);
						}
					}
				}
				list.addAll(tempList);
			}
			

			

			

			

			

			

			

			long sum = ans;
			for (int[] arr : list) {
				long localSum = 0l;
				for (i = 0; i < n; i++) {
					localSum += arr[i];
				}
				if (localSum < sum) {
					sum = localSum;
					res = arr;
				}
			}
			

			

			

			

		}
		return res;
	}

	private static long id1(int[] a) {
		

		int n = a.length, i;
		long localMin, globalMin = Long.MAX_VALUE;
		localMin = a[0];
		for (i = 1; i < n; i++) {
			long id6 = a[i] + localMin;
			long id0 = a[i] + a[i - 1];
			localMin = id6 < id0 ? id6 : id0;
			if (localMin < globalMin) {
				globalMin = localMin;
			}
		}
		return globalMin;
	}

	public static int id2(int[] a) {
		int n = a.length;
		int i, localMax = 0, globalMax = 0, max = Integer.MIN_VALUE;
		for (i = 0; i < n; i++) {
			if (a[i] >= 0) {
				break;
			}
			if (a[i] > max) {
				max = a[i];
			}
		}
		if (i == n) {
			return max;
		}
		for (i = 0; i < n; i++) {
			localMax += a[i];
			if (localMax < 0) {
				localMax = 0;
			} else {
				if (localMax > globalMax) {
					globalMax = localMax;
				}
			}
		}
		return globalMax;
	}

	public static int gcd(int a, int b) {
		BigInteger big_a = BigInteger.valueOf(a);
		BigInteger big_b = BigInteger.valueOf(b);
		return big_a.gcd(big_b).intValue();
	}

	public static int readInt() throws NumberFormatException, IOException {
		return Integer.parseInt(br.readLine());
	}

	public static long readLong() throws NumberFormatException, IOException {
		return Long.parseLong(br.readLine());
	}

	public static int[] readArray() throws IOException {
		String[] arr = br.readLine().split(" ");
		int[] a = new int[arr.length];
		for (int i = 0; i < arr.length; i++) {
			a[i] = Integer.parseInt(arr[i]);
		}
		return a;
	}

	public static long[] id3() throws IOException {
		String[] arr = br.readLine().split(" ");
		long[] a = new long[arr.length];
		for (int i = 0; i < arr.length; i++) {
			a[i] = Long.parseLong(arr[i]);
		}
		return a;
	}
}