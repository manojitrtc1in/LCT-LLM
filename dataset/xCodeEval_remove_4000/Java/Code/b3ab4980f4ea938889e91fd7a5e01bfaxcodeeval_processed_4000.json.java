import java.awt.*;
import java.io.*;
import java.math.*;
import java.util.*;

import static java.lang.Math.*;

public class id6 implements Runnable {

	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok = new StringTokenizer("");

	public static void main(String[] args) {
		new Thread(null, new id6(), "", 256 * (1L << 20)).start();
	}

	public void run() {
		try {
			long t1 = System.currentTimeMillis();
			if (System.getProperty("ONLINE_JUDGE") != null) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			} else {
				in = new BufferedReader(new FileReader("input.txt"));
				out = new PrintWriter("output.txt");
			}
			Locale.setDefault(Locale.US);
			solve();
			in.close();
			out.close();
			long t2 = System.currentTimeMillis();
			System.err.println("Time = " + (t2 - t1));
		} catch (Throwable t) {
			t.printStackTrace(System.err);
			System.exit(-1);
		}
	}

	String readString() throws IOException {
		while (!tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	int readInt() throws IOException {
		return Integer.parseInt(readString());
	}

	long readLong() throws IOException {
		return Long.parseLong(readString());
	}

	double readDouble() throws IOException {
		return Double.parseDouble(readString());
	}
	
	BigInteger id2() throws IOException {
		return new BigInteger(readString());
	}
	
	void debug(Object... objects) {
		System.err.println(Arrays.deepToString(objects));
	}

	static class Utils {

		private Utils() {}
		
		
		private static final int id3 = 50;
		

		public static void mergeSort(int[] a) {
			mergeSort(a, 0, a.length - 1);
		}
		public static void mergeSort(long[] a) {
			mergeSort(a, 0, a.length - 1);
		}
		public static void mergeSort(double[] a) {
			mergeSort(a, 0, a.length - 1);
		}


		private static void mergeSort(int[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= id3) {
					id4(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) / 2;
					mergeSort(a, leftIndex, middleIndex);
					mergeSort(a, middleIndex + 1, rightIndex);
					merge(a, leftIndex, middleIndex, rightIndex);
				}
			}
		}
		private static void mergeSort(long[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= id3) {
					id4(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) / 2;
					mergeSort(a, leftIndex, middleIndex);
					mergeSort(a, middleIndex + 1, rightIndex);
					merge(a, leftIndex, middleIndex, rightIndex);
				}
			}
		}
		private static void mergeSort(double[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= id3) {
					id4(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) / 2;
					mergeSort(a, leftIndex, middleIndex);
					mergeSort(a, middleIndex + 1, rightIndex);
					merge(a, leftIndex, middleIndex, rightIndex);
				}
			}
		}

		
		private static void merge(int[] a, int leftIndex, int middleIndex, int rightIndex) {
			int length1 = middleIndex - leftIndex + 1;
			int length2 = rightIndex - middleIndex;
			int[] leftArray = new int[length1];
			int[] rightArray = new int[length2];
			System.arraycopy(a, leftIndex, leftArray, 0, length1);
			System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
			for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
				if (i == length1) {
					a[k] = rightArray[j++];
				} else if (j == length2) {
					a[k] = leftArray[i++];
				} else {
					a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
				}
			}
		}
		private static void merge(long[] a, int leftIndex, int middleIndex, int rightIndex) {
			int length1 = middleIndex - leftIndex + 1;
			int length2 = rightIndex - middleIndex;
			long[] leftArray = new long[length1];
			long[] rightArray = new long[length2];
			System.arraycopy(a, leftIndex, leftArray, 0, length1);
			System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
			for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
				if (i == length1) {
					a[k] = rightArray[j++];
				} else if (j == length2) {
					a[k] = leftArray[i++];
				} else {
					a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
				}
			}
		}
		private static void merge(double[] a, int leftIndex, int middleIndex, int rightIndex) {
			int length1 = middleIndex - leftIndex + 1;
			int length2 = rightIndex - middleIndex;
			double[] leftArray = new double[length1];
			double[] rightArray = new double[length2];
			System.arraycopy(a, leftIndex, leftArray, 0, length1);
			System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
			for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
				if (i == length1) {
					a[k] = rightArray[j++];
				} else if (j == length2) {
					a[k] = leftArray[i++];
				} else {
					a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
				}
			}
		}

		
		private static void id4(int[] a, int leftIndex, int rightIndex) {
			for (int i = leftIndex + 1; i <= rightIndex; i++) {
				int current = a[i];
				int j = i - 1;
				while (j >= leftIndex && a[j] > current) {
					a[j + 1] = a[j];
					j--;
				}
				a[j + 1] = current;
			}
		}
		private static void id4(long[] a, int leftIndex, int rightIndex) {
			for (int i = leftIndex + 1; i <= rightIndex; i++) {
				long current = a[i];
				int j = i - 1;
				while (j >= leftIndex && a[j] > current) {
					a[j + 1] = a[j];
					j--;
				}
				a[j + 1] = current;
			}
		}
		private static void id4(double[] a, int leftIndex, int rightIndex) {
			for (int i = leftIndex + 1; i <= rightIndex; i++) {
				double current = a[i];
				int j = i - 1;
				while (j >= leftIndex && a[j] > current) {
					a[j + 1] = a[j];
					j--;
				}
				a[j + 1] = current;
			}
		}

	}
	
	boolean isLucky(long x) {
		if (x == 0) return false;
		while (x > 0) {
			if (x % 10 != 4 && x % 10 != 7) return false;
			x /= 10;
		}
		return true;
	}
	
	long[] id1(long limit) {
		ArrayList<Long> list = new ArrayList<Long>();
		int maxLen = Long.toString(limit).length();
		for (int len = 1; len <= maxLen; len++) {
			for (int mask = 0; mask < (1 << len); mask++) {
				long num = 0;
				for (int i = 0; i < len; i++) {
					if (((1 << i) & mask) == 0) {
						num = num * 10 + 4;
					} else {
						num = num * 10 + 7;
					}
				}
				if (num <= limit) {
					list.add(num);
				}
			}
		}
		long[] res = new long[list.size()];
		for (int i = 0; i < res.length; i++) {
			res[i] = list.get(i);
		}
		Utils.mergeSort(res);
		return res;
	}

	

	
	long[] id5 = id1(1000*1000*1000L*10);
	
	boolean isOk(String s, int a4, int a7, int a47, int a74) {
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '4') a4--;
		}
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '7') a7--;
		}
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i-1) == '4' && s.charAt(i) == '7') a47--;
		}
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i-1) == '7' && s.charAt(i) == '4') a74--;
		}
		return a4 == 0 && a7 == 0 && a47 == 0 && a74 == 0;
	}
	
	boolean isOk(long x, int a4, int a7, int a47, int a74) {
		String s = Long.toString(x);
		return isOk(s, a4, a7, a47, a74);
	}

	void solve() throws IOException {
		int a4 = readInt();
		int a7 = readInt();
		int a47 = readInt();
		int a74 = readInt();
		
		out.println(getAnswer(a4, a7, a47, a74));
		
		if (true) return;
		
		int LIMIT = 10;
		for (a4=1;a4<=LIMIT;a4++)
			for (a7=1;a4+a7<=LIMIT;a7++)
				for (a47=1;a47<=LIMIT;a47++)
					for (a74=1;a74<=LIMIT;a74++)
					{
						String myAnswer = getAnswer(a4, a7, a47, a74);
						String trueAnswer = id0(a4, a7, a47, a74);
						if (!myAnswer.equals(trueAnswer)) {
							debug(a4, a7, a47, a74, myAnswer, trueAnswer);
						}
					}
	}

	private String id0(int a4, int a7, int a47, int a74) {
		for (int i = 0; i < id5.length; i++) {
			if (isOk(id5[i], a4, a7, a47, a74)) {
				return Long.toString(id5[i]);
			}
		}
		return "-1";
	}

	String getAnswer(int a4, int a7, int a47, int a74) {
		answers.clear();
		trySolve(a4, a7, a47, a74, 4, 7);
		trySolve(a7, a4, a74, a47, 7, 4);
		ArrayList<String> list = new ArrayList<String>();
		for (String s : answers) {
			if (!s.equals("-1")) {
				list.add(s);
			}
		}
		if (list.size() > 2) {
			throw new RuntimeException();
		}
		if (list.isEmpty()) {
			return "-1";
		}
		if (list.size() == 1) {
			return list.get(0);
		}
		String s1 = list.get(0);
		String s2 = list.get(1);
		if (s1.length() < s2.length()) {
			return s1;
		} else if (s2.length() < s1.length()) {
			return s2;
		} else {
			Collections.sort(list);
			return list.get(0);
		}
	}
	
	void trySolve(int a4, int a7, int a47, int a74, int d4, int d7) {
		ArrayDeque<Integer> a = new ArrayDeque<Integer>();
		a.addLast(d4); a.addLast(d7); a47--; a4--; a7--;
		while (true) {
			if (a4 == 0 || a7 == 0 || a47 == 0 || a74 == 0) {
				break;
			}
			a.addLast(d4); a74--; a4--;
			if (a4 == 0 || a74 == 0) {
				break;
			}
			a.addLast(d7); a47--; a7--;
			if (a7 == 0 || a47 == 0) {
				break;
			}
		}
		
		if (a4 == 0) {
			if (a.getLast() == d4) {
				if (a47 > 1) {
					saveDeque(null);
					return;
				}
				if (a74 > 1) {
					saveDeque(null);
					return;
				}
				if (a47 == 1 && a74 == 1) {
					if (a7 <= 1) {
						saveDeque(null);
						return;
					}
					a.addFirst(d7);
					a.addLast(d7);
					a47--; a74--; a7 -= 2;
					if (d4 < d7) {
						for (int i = 0; i < a7; i++) {
							a.addLast(d7);
						}
					} else {
						for (int i = 0; i < a7; i++) {
							a.addFirst(d7);
						}
					}
					saveDeque(a);
					return;
				}
				if (a47 == 1) {
					if (a7 == 0) {
						saveDeque(null);
						return;
					}
					a.addLast(d7);
					a47--; a7--;
					for (int i = 0; i < a7; i++) {
						a.addLast(d7);
					}
					saveDeque(a);
					return;
				}
				if (a74 == 1) {
					if (a7 == 0) {
						saveDeque(null);
						return;
					}
					a.addFirst(d7);
					a74--; a7--;
					for (int i = 0; i < a7; i++) {
						a.addLast(d7);
					}
					saveDeque(a);
					return;
				}
				if (a7 == 0 && a47 == 0 && a74 == 0) {
					saveDeque(a);
					return;
				}
			} else if (a.getLast() == d7) {
				if (a47 > 0) {
					saveDeque(null);
					return;
				}
				if (a74 > 1) {
					saveDeque(null);
					return;
				}
				if (a74 == 1) {
					if (a7 == 0) {
						saveDeque(null);
						return;
					}
					a.addFirst(d7);
					a74--; a7--;
					for (int i = 0; i < a7; i++) {
						a.addLast(d7);
					}
					saveDeque(a);
					return;
				}
				for (int i = 0; i < a7; i++) {
					a.addLast(d7);
				}
				saveDeque(a);
				return;
			}
			saveDeque(null);
		}
		
		if (a7 == 0) {
			if (a.getLast() == d4) {
				if (a47 > 0 || a74 > 0) {
					saveDeque(null);
					return;
				}
				for (int i = 0; i < a4; i++) {
					a.addFirst(d4);
				}
				saveDeque(a);
				return;
			} else if (a.getLast() == d7) {
				if (a47 > 0) {
					saveDeque(null);
					return;
				}
				if (a74 > 1) {
					saveDeque(null);
					return;
				}
				if (a74 == 1) {
					a.addLast(d4);
					a4--; a74--;
					for (int i = 0; i < a4; i++) {
						a.addFirst(d4);
					}
					saveDeque(a);
					return;
				}
				for (int i = 0; i < a4; i++) {
					a.addFirst(d4);
				}
				saveDeque(a);
				return;
			}
			saveDeque(null);
		}
		
		if (a47 == 0) {
			if (a.getLast() == d4) {
				if (a74 == 0) {
					saveDeque(null);
					return;
				}
				a.addFirst(d7);
				a7--;
				a74--;
				if (a74 > 0) {
					saveDeque(null);
					return;
				}
				for (int i = 0; i < a4; i++) {
					a.addLast(d4);
				}
				for (int i = 0; i < a7; i++) {
					a.addFirst(d7);
				}
				saveDeque(a);
				return;
			} else if (a.getLast() == d7) {
				if (a74 > 2) {
					saveDeque(null);
					return;
				}
				if (a74 == 2) {
					a.addFirst(d7);
					a7--;
					a.addLast(d4);
					a4--;
					if (d4 < d7) {
						for (int i = 0; i < a7; i++) {
							a.pollLast();
							a.addLast(d7);
							a.addLast(d4);
						}
						for (int i = 0; i < a4; i++) {
							a.pollFirst();
							a.addFirst(d4);
							a.addFirst(d7);
						}
					} else {
						for (int i = 0; i < a7; i++) {
							a.addFirst(d7);
						}
						for (int i = 0; i < a4; i++) {
							a.addLast(d4);
						}
					}
					saveDeque(a);
					return;
				} else if (a74 == 1) {
					for (int i = 0; i < a7; i++) {
						a.addLast(d7);
					}
					a.addLast(d4);
					a4--;
					for (int i = 0; i < a4; i++) {
						a.addFirst(d4);
					}
					saveDeque(a);
					return;
				}
				if (a74 == 0) {
					for (int i = 0; i < a4; i++) {
						a.addFirst(d4);
					}
					for (int i = 0; i < a7; i++) {
						a.addLast(d7);
					}
					saveDeque(a);
					return;
				}
			}
		}
		
		if (a74 == 0) {
			if (a.getLast() == d4) {
				if (a47 > 1) {
					saveDeque(null);
					return;
				}
				if (a74 == 1) {
					for (int i = 0; i < a7; i++) {
						a.addLast(d7);
					}
					for (int i = 0; i < a4; i++) {
						a.addFirst(d4);
					}
					saveDeque(a);
					return;
				} else if (a74 == 0) {
					saveDeque(null);
					return;
				}
			} else if (a.getLast() == d7) {
				saveDeque(null);
				return;
			}
		}
	}

	ArrayList<String> answers = new ArrayList<String>();
	
	private void saveDeque(ArrayDeque<Integer> a) {
		if (a == null) {
			answers.add("-1");
			return;
		}
		StringBuilder sb = new StringBuilder(a.size());
		for (int x : a) {
			sb.append(x);
		}
		answers.add(sb.toString());
	}

}
