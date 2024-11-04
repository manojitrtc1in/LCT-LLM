import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.InputMismatchException;


final public class Main implements Runnable {
	private static String[] args;

	public static void main(String[] args) {
		Main.args = args;
		new Thread(null, new Main(), "MyRunThread", 1 << 26).start();
	}

	@Override
	public void run() {
		long id2 = -1;
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		if (args.length > 0 && args[0].equals("outside")) {
			id2 = System.currentTimeMillis();
			try {
				inputStream = new FileInputStream("IO/in.txt");


			} catch (Exception e) {
				System.err.println(e);
				System.exit(1);
			}
		} else {
			try {




			} catch (Exception e) {
				System.err.println(e);
				System.exit(1);
			}
		}

		Solver s = new Solver();
		s.in = new InputReader(inputStream);
		s.out = new OutputWriter(outputStream);
		if (args.length > 0 && args[0].equals("outside")) {
			s.debug = new DebugWriter(s.out);
		}

		s.solve();
		s.out.close();

		if (args.length > 0 && args[0].equals("outside")) {
			s.debug.close();
			System.err.printf("*** Total time: %.3f ***\n", (System.currentTimeMillis() - id2) / 1000.0);
		}
	}
}

final class Solver {
	InputReader in;
	OutputWriter out;
	DebugWriter debug;

	public void solve() {
		long exp = in.readLong();
		int n = in.readInt();

		int[][] matrix = new int[n][n];
		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				matrix[j][i] = 1;

		int m = in.readInt();
		for (int i = 0; i < m; ++i) {
			char c = in.readCharacter();
			int a, b;
			if (c >= 'a' && c <= 'z') a = (c - 'a');
			else a = 26 + (c - 'A');
			c = in.readCharacter();
			if (c >= 'a' && c <= 'z') b = (c - 'a');
			else b = 26 + (c - 'A');
			matrix[a][b] = 0;
		}

		int MOD = 1000 * 1000 * 1000 + 7;

		matrix = MatrixUtils.matrixPower(matrix, exp - 1, MOD);

		int res = 0;
		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i) {
				res += matrix[j][i];
				if (res >= MOD) res -= MOD;
			}

		out.printLine(res);
	}


}

final class InputReader {
	private boolean finished = false;

	private InputStream stream;
	private byte[] buf = new byte[1024];
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
		while (id5(c))
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
		} while (!id5(c));
		return res * sgn;
	}

	public long readLong() {
		int c = read();
		while (id5(c))
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
		} while (!id5(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (id5(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!id5(c));
		return res.toString();
	}

	public static boolean id5(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String id1() {
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
		String s = id1();
		while (s.trim().length() == 0)
			s = id1();
		return s;
	}

	public String readLine(boolean id0) {
		if (id0)
			return readLine();
		else
			return id1();
	}

	public BigInteger id3() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (id5(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (id5(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!id5(c) && c != '.') {
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
			while (!id5(c)) {
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

	public boolean id4() {
		int value;
		while (id5(value = peek()) && value != -1)
			read();
		return value == -1;
	}
}

final class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
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

	private void id6() {
		writer.print("debug:\t");
	}


	public void printLine(Object... objects) {
		flush();
		id6();
		writer.printLine(objects);
		flush();
	}

	public void printFormat(String format, Object... objects) {
		flush();
		id6();
		writer.printFormat(format, objects);
		flush();
	}


	public void printLine(char[] objects) {
		flush();
		id6();
		writer.printLine(objects);
		flush();
	}

	public void printLine(char[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(double[] objects) {
		flush();
		id6();
		writer.printLine(objects);
		flush();
	}

	public void printLine(double[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(int[] objects) {
		flush();
		id6();
		writer.printLine(objects);
		flush();
	}

	public void printLine(int[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(short[] objects) {
		flush();
		id6();
		writer.printLine(objects);
		flush();
	}

	public void printLine(short[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(long[] objects) {
		flush();
		id6();
		writer.printLine(objects);
		flush();
	}

	public void printLine(long[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(byte[] objects) {
		flush();
		id6();
		writer.printLine(objects);
		flush();
	}

	public void printLine(byte[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(boolean[] objects) {
		flush();
		id6();
		writer.printLine(objects);
		flush();
	}

	public void printLine(boolean[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void flush() {
		writer.flush();
	}

	public void close() {
		writer.close();
	}
}

abstract class MatrixUtils {
	public final static long[][] multiply(long[][] A, long[][] B) {
		int n = A.length;
		long[][] res = new long[n][n];

		for (int j = 0; j < n; ++j)
			for (int i = j + 1; i < n; ++i) {
				long tmp = B[j][i];
				B[j][i] = B[i][j];
				B[i][j] = tmp;
			}

		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				for (int k = 0; k < n; ++k)
					res[j][i] += A[j][k] * B[i][k];

		for (int j = 0; j < n; ++j)
			for (int i = j + 1; i < n; ++i) {
				long tmp = B[j][i];
				B[j][i] = B[i][j];
				B[i][j] = tmp;
			}

		return res;
	}

	public final static long[][] multiply(long[][] A, long[][] B, final long MOD) {
		int n = A.length;
		long[][] res = new long[n][n];

		for (int j = 0; j < n; ++j)
			for (int i = j + 1; i < n; ++i) {
				long tmp = B[j][i];
				B[j][i] = B[i][j];
				B[i][j] = tmp;
			}

		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				for (int k = 0; k < n; ++k) {
					res[j][i] += A[j][k] * B[i][k] % MOD;
					if (res[j][i] >= MOD) res[j][i] -= MOD;
				}

		for (int j = 0; j < n; ++j)
			for (int i = j + 1; i < n; ++i) {
				long tmp = B[j][i];
				B[j][i] = B[i][j];
				B[i][j] = tmp;
			}

		return res;
	}


	public final static int[][] multiply(int[][] A, int[][] B) {
		int n = A.length;
		int[][] res = new int[n][n];

		for (int j = 0; j < n; ++j)
			for (int i = j + 1; i < n; ++i) {
				int tmp = B[j][i];
				B[j][i] = B[i][j];
				B[i][j] = tmp;
			}

		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				for (int k = 0; k < n; ++k)
					res[j][i] += A[j][k] * B[i][k];

		for (int j = 0; j < n; ++j)
			for (int i = j + 1; i < n; ++i) {
				int tmp = B[j][i];
				B[j][i] = B[i][j];
				B[i][j] = tmp;
			}

		return res;
	}

	public final static int[][] multiply(int[][] A, int[][] B, final int MOD) {
		int n = A.length;
		int[][] res = new int[n][n];

		for (int j = 0; j < n; ++j)
			for (int i = j + 1; i < n; ++i) {
				int tmp = B[j][i];
				B[j][i] = B[i][j];
				B[i][j] = tmp;
			}

		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				for (int k = 0; k < n; ++k) {
					res[j][i] += (long) A[j][k] * B[i][k] % MOD;
					if (res[j][i] >= MOD) res[j][i] -= MOD;
				}

		for (int j = 0; j < n; ++j)
			for (int i = j + 1; i < n; ++i) {
				int tmp = B[j][i];
				B[j][i] = B[i][j];
				B[i][j] = tmp;
			}

		return res;
	}


	public final static double[][] multiply(double[][] A, double[][] B) {
		int n = A.length;
		double[][] res = new double[n][n];

		for (int j = 0; j < n; ++j)
			for (int i = j + 1; i < n; ++i) {
				double tmp = B[j][i];
				B[j][i] = B[i][j];
				B[i][j] = tmp;
			}

		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				for (int k = 0; k < n; ++k)
					res[j][i] += A[j][k] * B[i][k];

		for (int j = 0; j < n; ++j)
			for (int i = j + 1; i < n; ++i) {
				double tmp = B[j][i];
				B[j][i] = B[i][j];
				B[i][j] = tmp;
			}

		return res;
	}


	public final static boolean[][] multiply(boolean[][] A, boolean[][] B) {
		int n = A.length;
		boolean[][] res = new boolean[n][n];

		for (int j = 0; j < n; ++j)
			for (int i = j + 1; i < n; ++i) {
				boolean tmp = B[j][i];
				B[j][i] = B[i][j];
				B[i][j] = tmp;
			}

		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				for (int k = 0; k < n; ++k)
					res[j][i] |= A[j][k] && B[i][k];

		for (int j = 0; j < n; ++j)
			for (int i = j + 1; i < n; ++i) {
				boolean tmp = B[j][i];
				B[j][i] = B[i][j];
				B[i][j] = tmp;
			}

		return res;
	}


	public final static long[][] square(long[][] A) {
		int n = A.length;
		long[][] res = new long[n][n];

		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				for (int k = 0; k < n; ++k)
					res[j][i] += A[j][k] * A[k][i];

		return res;
	}

	public final static long[][] square(long[][] A, final long MOD) {
		int n = A.length;
		long[][] res = new long[n][n];

		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				for (int k = 0; k < n; ++k) {
					res[j][i] += A[j][k] * A[k][i] % MOD;
					if (res[j][i] >= MOD) res[j][i] -= MOD;
				}

		return res;
	}


	public final static int[][] square(int[][] A) {
		int n = A.length;
		int[][] res = new int[n][n];

		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				for (int k = 0; k < n; ++k)
					res[j][i] += A[j][k] * A[k][i];

		return res;
	}

	public final static int[][] square(int[][] A, final int MOD) {
		int n = A.length;
		int[][] res = new int[n][n];

		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				for (int k = 0; k < n; ++k) {
					res[j][i] += (long) A[j][k] * A[k][i] % MOD;
					if (res[j][i] >= MOD) res[j][i] -= MOD;
				}

		return res;
	}


	public final static double[][] square(double[][] A) {
		int n = A.length;
		double[][] res = new double[n][n];

		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				for (int k = 0; k < n; ++k)
					res[j][i] += A[j][k] * A[k][i];


		return res;
	}


	public final static boolean[][] square(boolean[][] A) {
		int n = A.length;
		boolean[][] res = new boolean[n][n];

		for (int j = 0; j < n; ++j)
			for (int i = 0; i < n; ++i)
				for (int k = 0; k < n; ++k)
					res[j][i] |= A[j][k] && A[k][i];

		return res;
	}


	public final static long[][] matrixPower(long[][] A, long exp) {
		int n = A.length;
		long[][] res = new long[n][n];
		for (int i = 0; i < n; ++i)
			res[i][i] = 1;
		while (exp > 0) {
			if ((exp & 1) > 0)
				res = multiply(res, A);
			A = square(A);
			exp /= 2;
		}
		return res;
	}

	public final static long[][] matrixPower(long[][] A, long exp, final long MOD) {
		int n = A.length;
		long[][] res = new long[n][n];
		for (int i = 0; i < n; ++i)
			res[i][i] = 1;
		while (exp > 0) {
			if ((exp & 1) > 0)
				res = multiply(res, A, MOD);
			A = square(A, MOD);
			exp /= 2;
		}
		return res;
	}


	public final static int[][] matrixPower(int[][] A, long exp) {
		int n = A.length;
		int[][] res = new int[n][n];
		for (int i = 0; i < n; ++i)
			res[i][i] = 1;
		while (exp > 0) {
			if ((exp & 1) > 0)
				res = multiply(res, A);
			A = square(A);
			exp /= 2;
		}
		return res;
	}

	public final static int[][] matrixPower(int[][] A, long exp, final int MOD) {
		int n = A.length;
		int[][] res = new int[n][n];
		for (int i = 0; i < n; ++i)
			res[i][i] = 1;
		while (exp > 0) {
			if ((exp & 1) > 0)
				res = multiply(res, A, MOD);
			A = square(A, MOD);
			exp /= 2;
		}
		return res;
	}


	public final static boolean[][] matrixPower(boolean[][] A, long exp) {
		int n = A.length;
		boolean[][] res = new boolean[n][n];
		for (int i = 0; i < n; ++i)
			res[i][i] = true;
		while (exp > 0) {
			if ((exp & 1) > 0)
				res = multiply(res, A);
			A = square(A);
			exp /= 2;
		}
		return res;
	}


	public final static double[][] matrixPower(double[][] A, long exp) {
		int n = A.length;
		double[][] res = new double[n][n];
		for (int i = 0; i < n; ++i)
			res[i][i] = 1.0;
		while (exp > 0) {
			if ((exp & 1) > 0)
				res = multiply(res, A);
			A = square(A);
			exp /= 2;
		}
		return res;
	}
}

