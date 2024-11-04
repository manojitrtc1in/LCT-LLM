import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class _C {

	final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok = new StringTokenizer("");

	void init() throws FileNotFoundException {
		if (ONLINE_JUDGE) {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
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

	int[] readArr(int n) throws IOException {
		int[] res = new int[n];
		for (int i = 0; i < n; i++) {
			res[i] = readInt();
		}
		return res;
	}

	long[] readArrL(int n) throws IOException {
		long[] res = new long[n];
		for (int i = 0; i < n; i++) {
			res[i] = readLong();
		}
		return res;
	}

	public static void main(String[] args) {
		new _C().run();
	}

	public void run() {
		try {
			long t1 = System.currentTimeMillis();
			init();
			solve();
			out.close();
			long t2 = System.currentTimeMillis();
			System.err.println("Time = " + (t2 - t1));
		} catch (Exception e) {
			e.printStackTrace(System.err);
			System.exit(-1);
		}
	}

	void solve() throws IOException {
		int n = readInt();
		int len = readInt();
		long[] a = readArrL(n);
		int k = readInt();

		long[] sum = new long[n - len + 1];
		for (int i = 0; i < len; i++) {
			sum[0] += a[i];
		}
		for (int i = len; i < n; i++) {
			sum[i - len + 1] = sum[i - len] + a[i] - a[i - len];
		}

		long maxk0 = 0;
		if (k == 0) {
			for (int i = 0; i < sum.length; i++)
				maxk0 = max(maxk0, abs(sum[i]));
			out.print(maxk0);
			return;
		}

		TreeSet<Point> poz = new TreeSet<Point>(new Comparator<Point>() {

			@Override
			public int compare(Point o1, Point o2) {
				if(o1.x > o2.x)return 1;
				if(o1.x < o2.x) return -1;
				return o1.y - o2.y;
			}
		});
		TreeSet<Point> neg = new TreeSet<Point>(new Comparator<Point>() {

			@Override
			public int compare(Point o1, Point o2) {
				if(o1.x > o2.x)return 1;
				if(o1.x < o2.x) return -1;
				return o1.y - o2.y;
			}
		});
		long sumPos = 0;
		long sumNeg = 0;

		PriorityQueue<Point> qPos = new PriorityQueue<Point>(n,
				new Comparator<Point>() {

					@Override
					public int compare(Point o1, Point o2) {
						if(o1.x > o2.x)return -1;
						if(o1.x < o2.x) return 1;
						return o1.y - o2.y;
					}

				});
		PriorityQueue<Point> qNeg = new PriorityQueue<Point>(n,
				new Comparator<Point>() {

					@Override
					public int compare(Point o1, Point o2) {
						if(o1.x > o2.x)return -1;
						if(o1.x < o2.x) return 1;
						return o1.y - o2.y;
					}

				});

		for (int i = 0; i < len; i++) {
			if (a[i] > 0) {
				if (poz.size() < k) {
					poz.add(new Point((int) a[i], i));
					sumPos += a[i];
				} else {
					if (poz.first().x <= a[i]) {
						Point removed = poz.first();
						sumPos -= poz.pollFirst().x;
						poz.add(new Point((int) a[i], i));
						sumPos += a[i];
						qPos.add(removed);
					} else {
						qPos.add(new Point((int) a[i], i));
					}
				}
			}
			if (a[i] < 0) {
				if (neg.size() < k) {
					neg.add(new Point((int) abs(a[i]), i));
					sumNeg += abs(a[i]);
				} else {
					if (neg.first().x <= abs(a[i])) {
						Point removed = neg.first();
						sumNeg -= neg.pollFirst().x;
						neg.add(new Point((int) abs(a[i]), i));
						sumNeg += abs(a[i]);
						qNeg.add(removed);
					} else {
						qNeg.add(new Point((int) abs(a[i]), i));
					}
				}
			}
		}

		long max = max(abs(sum[0] - 2 * sumPos), abs(sum[0] + 2 * sumNeg));

		int count = 0;

		for (int i = len; i < n; i++) {
			int left = i - len + 1;

			if (a[i - len] > 0) {
				if (poz.contains(new Point((int) a[i - len], i - len))) {
					poz.remove(new Point((int) a[i - len], i - len));
					sumPos -= a[i - len];

					while (true) {
						if (qPos.size() == 0)
							break;
						Point ins = qPos.poll();
						if (ins.y >= left) {
							poz.add(ins);
							sumPos += ins.x;
							break;
						}
					}
				}
			}

			if (a[i - len] < 0) {
				if (neg.contains(new Point((int) abs(a[i - len]), i - len))) {
					neg.remove(new Point((int) abs(a[i - len]), i - len));
					sumNeg -= abs(a[i - len]);
					while (true) {
						if (qNeg.size() == 0)
							break;
						Point ins = qNeg.poll();
						if (ins.y >= left) {
							neg.add(ins);
							sumNeg += abs(ins.x);
							break;
						}
					}
				}				
			}

			if (a[i] > 0) {

				if (poz.size() < k) {
					boolean check = false;
					while (poz.size() < k) {
						count++;
						if (qPos.size() == 0) {
							if (!check) {
								poz.add(new Point((int) a[i], i));
								sumPos += a[i];
							}
							break;
						}
						if (qPos.peek().y < left) {
							qPos.poll();
							continue;
						}
						if (qPos.peek().x > a[i]) {
							Point ins = qPos.poll();
							poz.add(ins);
							sumPos += ins.x;
						} else {
							if (!check) {
								poz.add(new Point((int) a[i], i));
								sumPos += a[i];
								check = true;
							} else {
								Point ins = qPos.poll();
								poz.add(ins);
								sumPos += ins.x;
							}
						}
					}
				}

				else {
					if (poz.first().x <= a[i]) {
						Point removed = poz.first();
						sumPos -= poz.pollFirst().x;
						poz.add(new Point((int) a[i], i));
						sumPos += a[i];
						qPos.add(removed);
					} else {
						qPos.add(new Point((int) a[i], i));
					}
				}
			}

			if (a[i] < 0) {
				if (neg.size() < k) {
					boolean check = false;
					while (neg.size() < k) {
						if (qNeg.size() == 0) {
							if (!check) {
								neg.add(new Point((int) abs(a[i]), i));
								sumNeg += abs(a[i]);
							}
							break;
						}
						if (qNeg.peek().y < left) {
							qNeg.poll();
							continue;
						}
						if (qNeg.peek().x > abs(a[i])) {
							Point ins = qNeg.poll();
							neg.add(ins);
							sumNeg += ins.x;
						} else {
							if (!check) {
								neg.add(new Point((int) abs(a[i]), i));
								sumNeg += abs(a[i]);
								check = true;
							} else {
								Point ins = qNeg.poll();
								neg.add(ins);
								sumNeg += ins.x;
							}
						}
					}
				} else {
					if (neg.first().x <= abs(a[i])) {
						Point removed = neg.first();
						sumNeg -= neg.pollFirst().x;
						neg.add(new Point((int) abs(a[i]), i));
						sumNeg += abs(a[i]);
						qNeg.add(removed);
					} else {
						qNeg.add(new Point((int) abs(a[i]), i));
					}
				}
			}

			max = max(abs(sum[i - len + 1] - 2 * sumPos), max);
			max = max(max, abs(sum[i - len + 1] + 2 * sumNeg));
		}
		out.println(max);
	}

	void maxHepify(int[] a, int i, int length) {
		int l = (i << 1) + 1;
		int r = (i << 1) + 2;
		int largest = i;
		if (l < length && a[l] > a[largest])
			largest = l;
		if (r < length && a[r] > a[largest])
			largest = r;
		if (largest != i) {
			a[largest] += a[i];
			a[i] = a[largest] - a[i];
			a[largest] -= a[i];
			maxHepify(a, largest, length);
		}
	}

	void buildMaxHeap(int[] a) {
		for (int i = a.length / 2 - 1; i >= 0; i--) {
			maxHepify(a, i, a.length);
		}
	}

	void heapSort(int[] a) {
		buildMaxHeap(a);
		for (int i = a.length - 1; i > 0; i--) {
			a[i] += a[0];
			a[0] = a[i] - a[0];
			a[i] -= a[0];
			maxHepify(a, 0, i);
		}
	}

	int[] zFunction(char[] s) {
		int[] z = new int[s.length];
		z[0] = 0;
		for (int i = 1, l = 0, r = 0; i < s.length; ++i) {
			if (i <= r)
				z[i] = min(r - i + 1, z[i - l]);
			while (i + z[i] < s.length && s[z[i]] == s[i + z[i]])
				++z[i];
			if (i + z[i] - 1 > r) {
				l = i;
				r = i + z[i] - 1;
			}
		}
		return z;
	}

	int[] prefixFunction(char[] s) {
		int[] pr = new int[s.length];
		for (int i = 1; i < s.length; ++i) {
			int j = pr[i - 1];
			while (j > 0 && s[i] != s[j])
				j = pr[j - 1];
			if (s[i] == s[j])
				++j;
			pr[i] = j;
		}
		return pr;
	}

	int ModExp(int a, int n, int mod) {
		int res = 1;
		while (n != 0)
			if ((n & 1) != 0) {
				res = (res * a) % mod;
				--n;
			} else {
				a = (a * a) % mod;
				n >>= 1;
			}
		return res;
	}

	public static class Utils {

		private Utils() {
		}

		public static void mergeSort(int[] a) {
			mergeSort(a, 0, a.length - 1);
		}

		private static void mergeSort(int[] a, int leftIndex, int rightIndex) {
			final int MAGIC_VALUE = 50;
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= MAGIC_VALUE) {
					insertionSort(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) / 2;
					mergeSort(a, leftIndex, middleIndex);
					mergeSort(a, middleIndex + 1, rightIndex);
					merge(a, leftIndex, middleIndex, rightIndex);
				}
			}
		}

		private static void merge(int[] a, int leftIndex, int middleIndex,
				int rightIndex) {
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
					a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++]
							: rightArray[j++];
				}
			}
		}

		private static void insertionSort(int[] a, int leftIndex, int rightIndex) {
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
	}

	boolean isPrime(int a) {
		for (int i = 2; i <= sqrt(a); i++)
			if (a % i == 0)
				return false;
		return true;
	}

	static double distance(long x1, long y1, long x2, long y2) {
		return Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	}

	static long gcd(long a, long b) {
		if (min(a, b) == 0)
			return max(a, b);
		return gcd(max(a, b) % min(a, b), min(a, b));
	}

	static long lcm(long a, long b) {
		return a * b / gcd(a, b);
	}
}

