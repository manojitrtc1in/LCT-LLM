import java.awt.Point;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Map.Entry;
import static java.lang.Math.*;


public class D implements Runnable {

	final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok;

	public static void main(String[] args) {
		new Thread(null, new D(), "", 128 * (1L << 20)).start();
	}

	public void run() {
		try {
			long startTime = System.currentTimeMillis();
			Locale.setDefault(Locale.US);














			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			tok = new StringTokenizer("");
			solve();
			in.close();
			out.close();
			long freeMemory = Runtime.getRuntime().freeMemory();
			long totalMemory = Runtime.getRuntime().totalMemory();
			long endTime = System.currentTimeMillis();
			System.err.printf("Time = %.3f ms\n", (endTime - startTime) / 1000.0);
			System.err.printf("Memory = %.3f MB\n", (totalMemory - freeMemory) / (double) (1 << 20));
		} catch (Throwable t) {
			t.printStackTrace(System.err);
			System.exit(-1);
		}
	}

	String readString() throws IOException {
		while (!tok.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) return null;
			tok = new StringTokenizer(line);
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
	
	int[] readIntArray(int n) throws IOException {
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = readInt();
		}
		return a;
	}
	
	long[] readLongArray(int n) throws IOException {
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = readLong();
		}
		return a;
	}
	
	double[] readDoubleArray(int n) throws IOException {
		double[] a = new double[n];
		for (int i = 0; i < n; i++) {
			a[i] = readDouble();
		}
		return a;
	}
	
	int[][] readIntMatrix(int n, int m) throws IOException {
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = readInt();
			}
		}
		return a;
	}
	
	long[][] readLongMatrix(int n, int m) throws IOException {
		long[][] a = new long[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = readLong();
			}
		}
		return a;
	}
	
	double[][] readDoubleMatrix(int n, int m) throws IOException {
		double[][] a = new double[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = readDouble();
			}
		}
		return a;
	}

	void debug(Object... o) {
		if (!ONLINE_JUDGE) {
			System.err.println(Arrays.deepToString(o));
		}
	}
	
	static class Mergesort {

		private Mergesort() {}

		public static void mergeSort(int[] a) {
			mergesort(a, 0, a.length - 1);
		}

		public static void mergeSort(long[] a) {
			mergesort(a, 0, a.length - 1);
		}

		public static void mergeSort(double[] a) {
			mergesort(a, 0, a.length - 1);
		}

		private static final int MAGIC_VALUE = 50;

		private static void mergesort(int[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= MAGIC_VALUE) {
					insertionSort(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) >> 1;
					mergesort(a, leftIndex, middleIndex);
					mergesort(a, middleIndex + 1, rightIndex);
					merge(a, leftIndex, middleIndex, rightIndex);
				}
			}
		}

		private static void mergesort(long[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= MAGIC_VALUE) {
					insertionSort(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) >> 1;
					mergesort(a, leftIndex, middleIndex);
					mergesort(a, middleIndex + 1, rightIndex);
					merge(a, leftIndex, middleIndex, rightIndex);
				}
			}
		}

		private static void mergesort(double[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= MAGIC_VALUE) {
					insertionSort(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) >> 1;
					mergesort(a, leftIndex, middleIndex);
					mergesort(a, middleIndex + 1, rightIndex);
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

		private static void insertionSort(long[] a, int leftIndex, int rightIndex) {
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

		private static void insertionSort(double[] a, int leftIndex, int rightIndex) {
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
	
	static class Complex {
		public double real;
		public double imag;

		public Complex(double real) {
			this.real = real;
			this.imag = 0;
		}
		
		public Complex(double real, double imag) {
			this.real = real;
			this.imag = imag;
		}
		
		public Complex add(Complex other) {
			return new Complex(this.real + other.real, this.imag + other.imag);
		}
		
		public Complex subtract(Complex other) {
			return new Complex(this.real - other.real, this.imag - other.imag);
		}
		
		public Complex multiply(Complex other) {
			return new Complex(this.real * other.real - this.imag * other.imag, this.real * other.imag + other.real * this.imag);
		}

		public void multiply(double alpha) {
			real *= alpha;
			imag *= alpha;
		}
		
		public void divide(double alpha) {
			real /= alpha;
			imag /= alpha;
		}
		
		public double angle() {
			return atan2(imag, real);
		}
		
		public double length() {
			return sqrt(real * real + imag * imag);
		}
		
		public void normalize() {
			double length = length();
			if (length == 0) return;
			real /= length;
			imag /= length;
		}
		
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			long temp;
			temp = Double.doubleToLongBits(imag);
			result = prime * result + (int) (temp ^ (temp >>> 32));
			temp = Double.doubleToLongBits(real);
			result = prime * result + (int) (temp ^ (temp >>> 32));
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Complex other = (Complex) obj;
			if (Double.doubleToLongBits(imag) != Double.doubleToLongBits(other.imag))
				return false;
			if (Double.doubleToLongBits(real) != Double.doubleToLongBits(other.real))
				return false;
			return true;
		}
		
		@Override
		public String toString() {
			char sign = signum(imag) < 0 ? '-' : '+';
			return String.format("%.8f %c %.8f*i", real, sign, abs(imag));
		}
		
	}
	
	static class Pair<F extends Comparable<F>, S extends Comparable<S>> implements Comparable<Pair<F, S>> {
		public F first;
		public S second;
		
		public Pair(F first, S second) {
			this.first = first;
			this.second = second;
		}

		public int compareTo(Pair<F, S> other) {
			int firstCompare = this.first.compareTo(other.first);
			if (firstCompare != 0) {
				return firstCompare;
			}
			return this.second.compareTo(other.second);
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + ((first == null) ? 0 : first.hashCode());
			result = prime * result + ((second == null) ? 0 : second.hashCode());
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair<F, S> other = (Pair<F, S>) obj;
			if (first == null) {
				if (other.first != null)
					return false;
			} else if (!first.equals(other.first))
				return false;
			if (second == null) {
				if (other.second != null)
					return false;
			} else if (!second.equals(other.second))
				return false;
			return true;
		}

		@Override
		public String toString() {
			return String.format("(%s %s)",
					first == null ? "null" : first.toString(),
					second == null ? "null" : second.toString());
		}
		
	}
	
	void solve() throws IOException {
		int n = readInt();
		int m = readInt();
		int k = readInt();
		char[][] a = new char[n][];
		for (int i = 0; i < n; i++) {
			a[i] = readString().toCharArray();
		}
		long ans = 0;
		int[][] sums = calcPrefSums(a, n, m);
		int[][] inds = new int[26][m];
		int[] lens = new int[26];
		for (int up = 0; up < n-1; up++) {
			for (int down = up+1; down < n; down++) {
				recalcIndices(a, inds, lens, up, down, m);
				ans += solve(a, n, m, k, inds, lens, up, down, sums);
			}
		}
		out.println(ans);
	}

	private void recalcIndices(char[][] a, int[][] inds, int[] lens, int up, int down, int m) {
		Arrays.fill(lens, 0);
		for (int j = 0; j < m; j++) {
			if (a[up][j] == a[down][j]) {
				int c = a[up][j] - 'a';
				inds[c][lens[c]++] = j;
			}
		}
	}

	private long solve(char[][] a, int n, int m, int k, int[][] inds, int[] lens, int up, int down, int[][] sums) {
		long ans = 0;
		for (int c = 0; c < 26; c++) {
			ans += solve(a, n, m, k, inds[c], lens[c], up, down, sums);
		}
		return ans;
	}
	
	private long solve(char[][] a, int n, int m, int k, int[] inds, int len, int up, int down, int[][] sums) {
		if (len <= 1) {
			return 0;
		}
		long ans = 0;
		int r = 0;
		for (int l = 0; l < len; l++) {
			r = max(r, l);
			while (r < len && getSum(sums, up, down, inds[l], inds[r]) <= k) {
				r++;
			}
			if (l < r-1) {
				long t = r - l - 1;
				ans += t;
			}
		}
		return ans;
	}

	private int getSum(int[][] sums, int i1, int i2, int j1, int j2) {
		if (i1 > i2) return 0;
		if (j1 > j2) return 0;
		int ans = sums[i2][j2];
		if (i1 > 0) ans -= sums[i1-1][j2];
		if (j1 > 0) ans -= sums[i2][j1-1];
		if (i1 > 0 && j1 > 0) ans += sums[i1-1][j1-1];
		return ans;
	}

	private int[][] calcPrefSums(char[][] a, int n, int m) {
		int[][] sums = new int[n][m];
		sums[0][0] = (a[0][0] == 'a' ? 1 : 0);
		for (int i = 1; i < n; i++) {
			sums[i][0] = sums[i-1][0] + (a[i][0] == 'a' ? 1 : 0);
		}
		for (int j = 1; j < m; j++) {
			sums[0][j] = sums[0][j-1] + (a[0][j] == 'a' ? 1 : 0);
		}
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + (a[i][j] == 'a' ? 1 : 0);
			}
		}
		return sums;
	}

}
