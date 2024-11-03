import java.io.*;
import java.util.*;
import java.math.*;

final public class Main implements Runnable {
	private static boolean local;

	public static void main(String[] args) {
		if (args.length > 0 && args[0].equals("-1")) {
			local = true;
		}
		new Thread(null, new Main(), "mainthread", 1 << 27).start();
	}

	public void run() {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;

		try {
			if (local) {
				inputStream = new FileInputStream("/home/outside/coding/workspace/java/main/io/input.txt");
				outputStream = new FileOutputStream("/home/outside/coding/workspace/java/main/io/output.txt");
			} else {
				

				

			}
		} catch (Exception e) {
			throw new RuntimeException(e);
		}

		Task.in = new InputReader(inputStream);
		Task.out = new OutputWriter(outputStream);
		if (local) {
			Task.dout = new DebugWriter(Task.out);
		}
		new Task().solve();
		Task.out.close();
	}
}

final class Task {
	public static InputReader in;
	public static OutputWriter out;
	public static DebugWriter dout;

	public void solve() {
		long n = in.readLong();
		
		ArrayList<BigInteger> ans = new ArrayList<>();
		
		for (int p = 0; p < 100; ++p) {
			BigInteger x = BigInteger.valueOf(1);
			for (int i = 0; i < p; ++i)
				x = x.multiply(BigInteger.valueOf(2));
			
			
			BigInteger d = x.multiply(BigInteger.valueOf(2)).subtract(BigInteger.valueOf(3));
			d = d.multiply(d).add(BigInteger.valueOf(n).multiply(BigInteger.valueOf(8)));
			
			

			
			if (sqrt(d) != BigInteger.valueOf(-1)) {
				BigInteger k = BigInteger.valueOf(3).subtract(x.multiply(BigInteger.valueOf(2))).add(sqrt(d));
				if (k.remainder(BigInteger.valueOf(2)).equals(BigInteger.ZERO) &&
					k.compareTo(BigInteger.ZERO) > 0 &&
					!k.divide(BigInteger.valueOf(2)).remainder(BigInteger.valueOf(2)).equals(BigInteger.ZERO))
					ans.add(k.divide(BigInteger.valueOf(2)).multiply(x));
				
				k = BigInteger.valueOf(3).subtract(x.multiply(BigInteger.valueOf(2))).subtract(sqrt(d));
				if (k.remainder(BigInteger.valueOf(2)).equals(BigInteger.ZERO) &&
					k.compareTo(BigInteger.ZERO) > 0 &&
					!k.divide(BigInteger.valueOf(2)).remainder(BigInteger.valueOf(2)).equals(BigInteger.ZERO))
					ans.add(k.divide(BigInteger.valueOf(2)).multiply(x));
			}
			
			

		}
		
		
		
		if (ans.size() == 0) out.printLine(-1);
		else {
			SequenceUtils.quickSort(ans);
			ans = SequenceUtils.unique(ans);
			for (int i = 0; i < ans.size(); ++i)
				out.printLine(ans.get(i));
		}
		
	}
	
	BigInteger sqrt(BigInteger n) {
		BigInteger lo = BigInteger.valueOf(1);
		BigInteger hi = n;
		while (lo.compareTo(hi) < 0) {
			BigInteger m = lo.add(hi.subtract(lo).divide(BigInteger.valueOf(2)));
			if (m.multiply(m).compareTo(n) < 0) lo = m.add(BigInteger.valueOf(1));
			else hi = m;
		}
		
		if (lo.multiply(lo).equals(n)) return lo;
		return BigInteger.valueOf(-1);
	}
}

final class InputReader {
	private boolean finished = false;

	private InputStream stream;
	private byte[] buf = new byte[1 << 13];
	private int curChar;
	private int numChars;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	private int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int peek() {
		if (numChars == -1)
			return -1;
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				return -1;
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar];
	}

	public int readInt() {
		int c = read();
		while (id2(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!id2(c));
		return res * sgn;
	}

	public long readLong() {
		int c = read();
		while (id2(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!id2(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (id2(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!id2(c));
		return res.toString();
	}

	public static boolean id2(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String id0() {
		StringBuilder buf = new StringBuilder();
		int c = read();
		while (c != '\n' && c != -1) {
			if (c != '\r')
				buf.appendCodePoint(c);
			c = read();
		}
		return buf.toString();
	}

	public String readLine() {
		String s = id0();
		while (s.trim().length() == 0)
			s = id0();
		return s;
	}

	public String readLine(boolean id7) {
		if (id7)
			return readLine();
		else
			return id0();
	}
	
	public String id3() {
		StringBuilder buf = new StringBuilder();
		int c = read();
		while (c != -1) {
			if (c != '\r')
				buf.appendCodePoint(c);
			c = read();
		}
		return buf.toString();
	}

	public BigInteger id5() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (id2(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (id2(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!id2(c) && c != '.') {
			if (c == 'e' || c == 'E')
				return res * Math.pow(10, readInt());
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		if (c == '.') {
			c = read();
			double m = 1;
			while (!id2(c)) {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				m /= 10;
				res += (c - '0') * m;
				c = read();
			}
		}
		return res * sgn;
	}

	public boolean id1() {
		int value;
		while (id2(value = peek()) && value != -1)
			read();
		return value == -1;
	}
	
	public void close() {
		try {
			stream.close();
		} catch (IOException e) {
			throw new RuntimeException();			
		}
	}
}

final class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream), 1 << 13));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}


	public void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object... objects) {
		print(objects);
		writer.println();
	}

	public void printFormat(String format, Object... objects) {
		writer.printf(format, objects);
	}


	public void print(char[] objects) {
		writer.print(objects);
	}

	public void printLine(char[] objects) {
		writer.println(objects);
	}

	public void printLine(char[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(int[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(int[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(int[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(short[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(short[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(short[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(long[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(long[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(long[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(double[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(double[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(double[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(byte[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(byte[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(byte[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(boolean[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(boolean[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(boolean[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void close() {
		writer.close();
	}

	public void flush() {
		writer.flush();
	}
}

final class DebugWriter {
	private final OutputWriter writer;

	public DebugWriter(OutputWriter writer) {
		this.writer = writer;
	}

	private void id4() {
		writer.print("DEBUG:\t");
	}

	public void printLine(Object... objects) {
		id4();
		writer.printLine(objects);
		flush();
	}

	public void printFormat(String format, Object... objects) {
		id4();
		writer.printFormat(format, objects);
		flush();
	}

	public void printLine(char[] objects) {
		id4();
		writer.printLine(objects);
		flush();
	}

	public void printLine(char[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}

	public void printLine(double[] objects) {
		id4();
		writer.printLine(objects);
		flush();
	}

	public void printLine(double[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}

	public void printLine(int[] objects) {
		id4();
		writer.printLine(objects);
		flush();
	}

	public void printLine(int[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}

	public void printLine(short[] objects) {
		id4();
		writer.printLine(objects);
		flush();
	}

	public void printLine(short[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}

	public void printLine(long[] objects) {
		id4();
		writer.printLine(objects);
		flush();
	}

	public void printLine(long[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}

	public void printLine(byte[] objects) {
		id4();
		writer.printLine(objects);
		flush();
	}

	public void printLine(byte[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}

	public void printLine(boolean[] objects) {
		id4();
		writer.printLine(objects);
		flush();
	}

	public void printLine(boolean[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}

	public void flush() {
		writer.flush();
	}
}


final class SequenceUtils {
	

	public final static <T> void swap(List<T> sequence, int j, int i) {
		T tmp = sequence.get(j);
		sequence.set(j, sequence.get(i));
		sequence.set(i, tmp);
	}

	public final static <T> void swap(T[] sequence, int j, int i) {
		T tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	public final static void swap(int[] sequence, int j, int i) {
		int tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	public final static void swap(long[] sequence, int j, int i) {
		long tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	public final static void swap(char[] sequence, int j, int i) {
		char tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	public final static void swap(double[] sequence, int j, int i) {
		double tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	public final static void swap(boolean[] sequence, int j, int i) {
		boolean tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	public final static void swap(short[] sequence, int j, int i) {
		short tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	public final static void swap(byte[] sequence, int j, int i) {
		byte tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	

	public final static <T> void reverse(List<T> sequence) {
		for (int left = 0, right = sequence.size() - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static <T> void reverse(T[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static void reverse(int[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static void reverse(long[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static void reverse(char[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static void reverse(double[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static void reverse(boolean[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static void reverse(short[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static void reverse(byte[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	

	public final static <T extends Comparable<T>> boolean nextPermutation(List<T> sequence) {
		for (int j = sequence.size() - 2; j >= 0; --j) {
			if (sequence.get(j).compareTo(sequence.get(j + 1)) < 0) {
				reverse(sequence.subList(j + 1, sequence.size()));
				for (int i = j + 1; i < sequence.size(); ++i)
					if (sequence.get(j).compareTo(sequence.get(i)) < 0) {
						swap(sequence, j, i);
						return true;
					}
			}
		}
		return false;
	}

	public final static <T> boolean nextPermutation(List<T> sequence, Comparator<T> comparator) {
		for (int j = sequence.size() - 2; j >= 0; --j) {
			if (comparator.compare(sequence.get(j), sequence.get(j + 1)) < 0) {
				reverse(sequence.subList(j + 1, sequence.size()));
				for (int i = j + 1; i < sequence.size(); ++i)
					if (comparator.compare(sequence.get(j), sequence.get(i)) < 0) {
						swap(sequence, j, i);
						return true;
					}
			}
		}
		return false;
	}

	

	public final static <T> void shuffle(List<T> sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.size(); ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static <T> void shuffle(T[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static void shuffle(int[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static void shuffle(long[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static void shuffle(char[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static void shuffle(double[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static void shuffle(boolean[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static void shuffle(short[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static void shuffle(byte[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	

	public final static <T extends Comparable<T>> void mergeSort(List<T> sequence) {
		int n = sequence.size();
		T[] tmp = (T[]) new Object[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence.get(i);
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static <T extends Comparable<T>> void merge(List<T> sequence, T[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence.set(i, tmp[pRight++]);
			else if (pRight > right) sequence.set(i, tmp[pLeft++]);
			else if (tmp[pLeft].compareTo(tmp[pRight]) <= 0) sequence.set(i, tmp[pLeft++]);
			else sequence.set(i, tmp[pRight++]);
	}


	public final static <T extends Comparable<T>> void mergeSort(T[] sequence) {
		int n = sequence.length;
		T[] tmp = (T[]) new Object[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static <T extends Comparable<T>> void merge(T[] sequence, T[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (tmp[pLeft].compareTo(tmp[pRight]) <= 0) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static <T> void mergeSort(List<T> sequence, Comparator<T> comparator) {
		int n = sequence.size();
		T[] tmp = (T[]) new Object[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence.get(i);
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1), comparator);
		}
	}

	private final static <T> void merge(List<T> sequence, T[] tmp, int left, int mid, int right, Comparator<T> comparator) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence.set(i, tmp[pRight++]);
			else if (pRight > right) sequence.set(i, tmp[pLeft++]);
			else if (comparator.compare(tmp[pLeft], tmp[pRight]) <= 0) sequence.set(i, tmp[pLeft++]);
			else sequence.set(i, tmp[pRight++]);
	}


	public final static <T> void mergeSort(T[] sequence, Comparator<T> comparator) {
		int n = sequence.length;
		T[] tmp = (T[]) new Object[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1), comparator);
		}
	}

	private final static <T> void merge(T[] sequence, T[] tmp, int left, int mid, int right, Comparator<T> comparator) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (comparator.compare(tmp[pLeft], tmp[pRight]) <= 0) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static void mergeSort(int[] sequence) {
		int n = sequence.length;
		int[] tmp = new int[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static void merge(int[] sequence, int[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (tmp[pLeft] <= tmp[pRight]) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static void mergeSort(long[] sequence) {
		int n = sequence.length;
		long[] tmp = new long[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static void merge(long[] sequence, long[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (tmp[pLeft] <= tmp[pRight]) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static void mergeSort(char[] sequence) {
		int n = sequence.length;
		char[] tmp = new char[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static void merge(char[] sequence, char[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (tmp[pLeft] <= tmp[pRight]) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static void mergeSort(double[] sequence) {
		int n = sequence.length;
		double[] tmp = new double[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static void merge(double[] sequence, double[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (tmp[pLeft] <= tmp[pRight]) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static void mergeSort(boolean[] sequence) {
		int n = sequence.length;
		boolean[] tmp = new boolean[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static void merge(boolean[] sequence, boolean[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (!tmp[pLeft] || tmp[pRight]) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static void mergeSort(short[] sequence) {
		int n = sequence.length;
		short[] tmp = new short[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static void merge(short[] sequence, short[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (tmp[pLeft] <= tmp[pRight]) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static void mergeSort(byte[] sequence) {
		int n = sequence.length;
		byte[] tmp = new byte[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static void merge(byte[] sequence, byte[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (tmp[pLeft] <= tmp[pRight]) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}

	

	public final static <T extends Comparable<T>> void quickSort(List<T> sequence) {
		shuffle(sequence);
		id6(sequence, 0, sequence.size() - 1);
	}

	private final static <T extends Comparable<T>> void id6(List<T> sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		T value = sequence.get(left);

		while (i <= greaterThen) {
			int cmp = sequence.get(i).compareTo(value);
			if (cmp < 0) swap(sequence, i++, lessThen++);
			else if (cmp > 0) swap(sequence, i, greaterThen--);
			else ++i;
		}

		id6(sequence, left, lessThen - 1);
		id6(sequence, greaterThen + 1, right);
	}


	public final static <T extends Comparable<T>> void quickSort(T[] sequence) {
		shuffle(sequence);
		id6(sequence, 0, sequence.length - 1);
	}

	private final static <T extends Comparable<T>> void id6(T[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		T value = sequence[left];

		while (i <= greaterThen) {
			int cmp = sequence[i].compareTo(value);
			if (cmp < 0) swap(sequence, i++, lessThen++);
			else if (cmp > 0) swap(sequence, i, greaterThen--);
			else ++i;
		}

		id6(sequence, left, lessThen - 1);
		id6(sequence, greaterThen + 1, right);
	}


	public final static <T> void quickSort(List<T> sequence, Comparator<T> comparator) {
		shuffle(sequence);
		id6(sequence, 0, sequence.size() - 1, comparator);
	}

	private final static <T> void id6(List<T> sequence, int left, int right, Comparator<T> comparator) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		T value = sequence.get(left);

		while (i <= greaterThen) {
			int cmp = comparator.compare(sequence.get(i), value);
			if (cmp < 0) swap(sequence, i++, lessThen++);
			else if (cmp > 0) swap(sequence, i, greaterThen--);
			else ++i;
		}

		id6(sequence, left, lessThen - 1, comparator);
		id6(sequence, greaterThen + 1, right, comparator);
	}


	public final static <T> void quickSort(T[] sequence, Comparator<T> comparator) {
		shuffle(sequence);
		id6(sequence, 0, sequence.length - 1, comparator);
	}

	private final static <T> void id6(T[] sequence, int left, int right, Comparator<T> comparator) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		T value = sequence[left];

		while (i <= greaterThen) {
			int cmp = comparator.compare(sequence[i], value);
			if (cmp < 0) swap(sequence, i++, lessThen++);
			else if (cmp > 0) swap(sequence, i, greaterThen--);
			else ++i;
		}

		id6(sequence, left, lessThen - 1, comparator);
		id6(sequence, greaterThen + 1, right, comparator);
	}


	public final static void quickSort(int[] sequence) {
		shuffle(sequence);
		id6(sequence, 0, sequence.length - 1);
	}

	private final static void id6(int[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		int value = sequence[left];

		while (i <= greaterThen) {
			if (sequence[i] < value) swap(sequence, i++, lessThen++);
			else if (sequence[i] > value) swap(sequence, i, greaterThen--);
			else ++i;
		}

		id6(sequence, left, lessThen - 1);
		id6(sequence, greaterThen + 1, right);
	}


	public final static void quickSort(long[] sequence) {
		shuffle(sequence);
		id6(sequence, 0, sequence.length - 1);
	}

	private final static void id6(long[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		long value = sequence[left];

		while (i <= greaterThen) {
			if (sequence[i] < value) swap(sequence, i++, lessThen++);
			else if (sequence[i] > value) swap(sequence, i, greaterThen--);
			else ++i;
		}

		id6(sequence, left, lessThen - 1);
		id6(sequence, greaterThen + 1, right);
	}


	public final static void quickSort(char[] sequence) {
		shuffle(sequence);
		id6(sequence, 0, sequence.length - 1);
	}

	private final static void id6(char[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		char value = sequence[left];

		while (i <= greaterThen) {
			if (sequence[i] < value) swap(sequence, i++, lessThen++);
			else if (sequence[i] > value) swap(sequence, i, greaterThen--);
			else ++i;
		}

		id6(sequence, left, lessThen - 1);
		id6(sequence, greaterThen + 1, right);
	}


	public final static void quickSort(double[] sequence) {
		shuffle(sequence);
		id6(sequence, 0, sequence.length - 1);
	}

	private final static void id6(double[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		double value = sequence[left];

		while (i <= greaterThen) {
			if (sequence[i] < value) swap(sequence, i++, lessThen++);
			else if (sequence[i] > value) swap(sequence, i, greaterThen--);
			else ++i;
		}

		id6(sequence, left, lessThen - 1);
		id6(sequence, greaterThen + 1, right);
	}


	public final static void quickSort(boolean[] sequence) {
		shuffle(sequence);
		id6(sequence, 0, sequence.length - 1);
	}

	private final static void id6(boolean[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		boolean value = sequence[left];

		while (i <= greaterThen) {
			if (!sequence[i] && value) swap(sequence, i++, lessThen++);
			else if (sequence[i] && !value) swap(sequence, i, greaterThen--);
			else ++i;
		}

		id6(sequence, left, lessThen - 1);
		id6(sequence, greaterThen + 1, right);
	}


	public final static void quickSort(short[] sequence) {
		shuffle(sequence);
		id6(sequence, 0, sequence.length - 1);
	}

	private final static void id6(short[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		short value = sequence[left];

		while (i <= greaterThen) {
			if (sequence[i] < value) swap(sequence, i++, lessThen++);
			else if (sequence[i] > value) swap(sequence, i, greaterThen--);
			else ++i;
		}

		id6(sequence, left, lessThen - 1);
		id6(sequence, greaterThen + 1, right);
	}


	public final static void quickSort(byte[] sequence) {
		shuffle(sequence);
		id6(sequence, 0, sequence.length - 1);
	}

	private final static void id6(byte[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		byte value = sequence[left];

		while (i <= greaterThen) {
			if (sequence[i] < value) swap(sequence, i++, lessThen++);
			else if (sequence[i] > value) swap(sequence, i, greaterThen--);
			else ++i;
		}

		id6(sequence, left, lessThen - 1);
		id6(sequence, greaterThen + 1, right);
	}

	

	public static <T> ArrayList<T> unique(ArrayList<T> sequence) {
		int size = 1;
		for (int i = 1; i < sequence.size(); ++i)
			if (!sequence.get(i).equals(sequence.get(i - 1)))
				++size;

		ArrayList<T> newSequence = new ArrayList<T>(size);
		newSequence.add(sequence.get(0));

		for (int i = 1; i < sequence.size(); ++i)
			if (!sequence.get(i).equals(sequence.get(i - 1)))
				newSequence.add(sequence.get(i));

		return newSequence;
	}

	public static <T> T[] unique(T[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (!sequence[i].equals(sequence[i - 1]))
				++size;

		T[] newSequence = (T[]) new Object[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (!sequence[i].equals(sequence[i - 1]))
				newSequence[++size] = sequence[i];

		return newSequence;
	}

	public static int[] unique(int[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				++size;

		int[] newSequence = new int[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				newSequence[++size] = sequence[i];

		return newSequence;
	}

	public static long[] unique(long[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				++size;

		long[] newSequence = new long[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				newSequence[++size] = sequence[i];

		return newSequence;
	}

	public static char[] unique(char[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				++size;

		char[] newSequence = new char[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				newSequence[++size] = sequence[i];

		return newSequence;
	}

	public static double[] unique(double[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				++size;

		double[] newSequence = new double[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				newSequence[++size] = sequence[i];

		return newSequence;
	}

	public static boolean[] unique(boolean[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				++size;

		boolean[] newSequence = new boolean[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				newSequence[++size] = sequence[i];

		return newSequence;
	}

	public static short[] unique(short[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				++size;

		short[] newSequence = new short[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				newSequence[++size] = sequence[i];

		return newSequence;
	}

	public static byte[] unique(byte[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				++size;

		byte[] newSequence = new byte[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				newSequence[++size] = sequence[i];

		return newSequence;
	}
}
