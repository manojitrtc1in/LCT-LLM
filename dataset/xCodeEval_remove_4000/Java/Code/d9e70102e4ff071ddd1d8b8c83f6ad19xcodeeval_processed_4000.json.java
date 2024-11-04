import java.awt.Point;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Map.Entry;
import static java.lang.Math.*;


public class E implements Runnable {

	final boolean id6 = System.getProperty("id6") != null;

	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok;

	public static void main(String[] args) {
		new Thread(null, new E(), "", 128 * (1L << 20)).start();
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
	
	int[] id1(int n) throws IOException {
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = readInt();
		}
		return a;
	}
	
	long[] id7(int n) throws IOException {
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = readLong();
		}
		return a;
	}
	
	double[] id2(int n) throws IOException {
		double[] a = new double[n];
		for (int i = 0; i < n; i++) {
			a[i] = readDouble();
		}
		return a;
	}
	
	int[][] id8(int n, int m) throws IOException {
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = readInt();
			}
		}
		return a;
	}
	
	long[][] id13(int n, int m) throws IOException {
		long[][] a = new long[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = readLong();
			}
		}
		return a;
	}
	
	double[][] id12(int n, int m) throws IOException {
		double[][] a = new double[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = readDouble();
			}
		}
		return a;
	}

	void debug(Object... o) {
		if (!id6) {
			System.err.println(Arrays.deepToString(o));
		}
	}
	
	static class id11 {

		private id11() {}

		public static void mergeSort(int[] a) {
			id10(a, 0, a.length - 1);
		}

		public static void mergeSort(long[] a) {
			id10(a, 0, a.length - 1);
		}

		public static void mergeSort(double[] a) {
			id10(a, 0, a.length - 1);
		}

		private static final int id4 = 50;

		private static void id10(int[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= id4) {
					id5(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) >> 1;
					id10(a, leftIndex, middleIndex);
					id10(a, middleIndex + 1, rightIndex);
					merge(a, leftIndex, middleIndex, rightIndex);
				}
			}
		}

		private static void id10(long[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= id4) {
					id5(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) >> 1;
					id10(a, leftIndex, middleIndex);
					id10(a, middleIndex + 1, rightIndex);
					merge(a, leftIndex, middleIndex, rightIndex);
				}
			}
		}

		private static void id10(double[] a, int leftIndex, int rightIndex) {
			if (leftIndex < rightIndex) {
				if (rightIndex - leftIndex <= id4) {
					id5(a, leftIndex, rightIndex);
				} else {
					int middleIndex = (leftIndex + rightIndex) >> 1;
					id10(a, leftIndex, middleIndex);
					id10(a, middleIndex + 1, rightIndex);
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

		private static void id5(int[] a, int leftIndex, int rightIndex) {
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

		private static void id5(long[] a, int leftIndex, int rightIndex) {
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

		private static void id5(double[] a, int leftIndex, int rightIndex) {
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
	
	static class Task {
		long startTime, pageCount, priority;
		int index;

		public Task(long startTime, long pageCount, long priority, int index) {
			this.startTime = startTime;
			this.pageCount = pageCount;
			this.priority = priority;
			this.index = index;
		}

		@Override
		public String toString() {
			return "Task [startTime=" + startTime + ", pageCount=" + pageCount
					+ ", priority=" + priority + ", index=" + index + "]";
		}
	}
	
	void solve() throws IOException {
		int n = readInt();
		Task[] a = new Task[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Task(readLong(), readLong(), readLong(), i);
		}
		Arrays.sort(a, new Comparator<Task>() {
			@Override
			public int compare(Task o1, Task o2) {
				if (o1.startTime < o2.startTime) return -1;
				if (o1.startTime > o2.startTime) return 1;
				return 0;
			}
		});
		int idx = -1;
		for (int i = 0; i < n; i++) {
			if (a[i].priority == -1) {
				idx = i;
				break;
			}
		}
		long T = readLong();
		Set<Long> id3 = new TreeSet<Long>();
		for (Task t : a) {
			if (t.priority != -1) {
				id3.add(t.priority);
			}
		}
		List<Long> id9 = new ArrayList<Long>();
		for (long p : id3) {
			if (p-1 >= 1 && !id3.contains(p-1)) {
				id9.add(p-1);
			}
			if (p+1 <= 1000*1000*1000 && !id3.contains(p+1)) {
				id9.add(p+1);
			}
		}
		Collections.sort(id9);
		int left = 0, right = id9.size() - 1;
		long ansP = -1;
		while (left <= right) {
			int mid = (left + right) / 2;
			long p = id9.get(mid);
			a[idx].priority = p;
			long time = calcTime(n, a, idx, false);
			if (time == T) {
				ansP = p;
				break;
			}
			if (time < T) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
			a[idx].priority = -1;
		}
		a[idx].priority = ansP;
		calcTime(n, a, idx, true);
	}
	
	static class RealTask implements Comparable<RealTask> {
		long remTime, priority;
		int index;
		
		public RealTask(long remTime, long priority, int index) {
			this.remTime = remTime;
			this.priority = priority;
			this.index = index;
		}
		
		@Override
		public int compareTo(RealTask other) {
			if (this.priority > other.priority) return -1;
			if (this.priority < other.priority) return 1;
			return 0;
		}

		@Override
		public String toString() {
			return "RealTask [remTime=" + remTime + ", priority=" + priority
					+ ", index=" + index + "]";
		}
	}

	private long calcTime(int n, Task[] a, int idx, boolean output) {
		PriorityQueue<RealTask> q = new PriorityQueue<RealTask>(n);
		long[] answers = new long[n];
		long time = a[0].startTime;
		int pos = 0;
		while (!q.isEmpty() || pos < n) {
			if (q.isEmpty()) {
				time = max(time, a[pos].startTime);
			}
			while (pos < n && a[pos].startTime == time) {
				q.add(new RealTask(a[pos].pageCount, a[pos].priority, a[pos].index));
				pos++;
			}
			if (!q.isEmpty()) {
				long id0 = (pos == n ? (long)1e18 : a[pos].startTime - time);
				RealTask now = q.peek();
				if (now.remTime <= id0) {
					time += now.remTime;
					answers[now.index] = time;
					q.poll();
				} else {
					now.remTime -= id0;
					time += id0;
				}
			}
		}
		if (output) {
			out.println(a[idx].priority);
			for (int i = 0; i < n; i++) {
				out.print(answers[i]);
				if (i == n-1) out.println(); else out.print(' ');
			}
		}
		return answers[a[idx].index];
	}

}
