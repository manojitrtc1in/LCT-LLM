import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task {
	
	int n, m, N;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		Matrix.mod=1_000_000_007;
		n=in.readInt();
		m=in.readInt();
		int q=in.readInt();
		N=n*m;
		int[] dx=new int[]{-1, 0, 0, 1}, dy=new int[]{0, -1, 1, 0};
		Matrix matrix=new Matrix(new long[N][N]), result=Matrix.identityMatrix(N);
		for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
			for (int k=0; k<4; k++) {
				int i2=i+dx[k], j2=j+dy[k];
				if (valid(i2, j2)) matrix.data[f(i, j)][f(i2, j2)]=1;
			}
		}
		boolean[][] valid=new boolean[n][m];
		for (int i=0; i<N; i++) matrix.data[i][i]=1;
		int last=0;
		while (q-->0) {
			int type=in.readInt(), x=in.readInt()-1, y=in.readInt()-1, t=in.readInt()-1;


			if (type==1) {
				result=Matrix.multiply(result, matrix.power(t-last));
				out.printLine(result.data[f(0, 0)][f(x, y)]);
			}
			else {
				result=Matrix.multiply(result, matrix.power(t-last));
				if (type==2) {
					for (int i=0; i<N; i++) result.data[i][f(x, y)]=0;
					valid[x][y]=true;
				} else valid[x][y]=false;
				for (int k=0; k<4; k++) {
					int x2=x+dx[k], y2=y+dy[k];
					if (valid(x2, y2)) {
						if (type==2) matrix.data[f(x, y)][f(x2, y2)]=matrix.data[f(x2, y2)][f(x, y)]=0;
						else if (!valid[x2][y2]) matrix.data[f(x, y)][f(x2, y2)]=matrix.data[f(x2, y2)][f(x, y)]=1;
					}
				}
			}
			last=t;
		}
	}
	
	void print(Matrix m, OutputWriter out) {
		out.printLine("*********");
		for (long[]i: m.data) out.printLine(i);
	}
	
	boolean valid(int i, int j) {
		return i>=0 && i<n && j>=0 && j<m;
	}
	
	int f(int i, int j) {
		return i*m+j;
	}
}

class InputReader {
	private boolean finished = false;

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
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
		while (isSpaceChar(c))
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
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
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
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String readLine0() {
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
		String s = readLine0();
		while (s.trim().length() == 0)
			s = readLine0();
		return s;
	}

	public String readLine(boolean ignoreEmptyLines) {
		if (ignoreEmptyLines)
			return readLine();
		else
			return readLine0();
	}

	public BigInteger readBigInteger() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!isSpaceChar(c) && c != '.') {
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
			while (!isSpaceChar(c)) {
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

	public boolean isExhausted() {
		int value;
		while (isSpaceChar(value = peek()) && value != -1)
			read();
		return value == -1;
	}

	public String next() {
		return readString();
	}

	public SpaceCharFilter getFilter() {
		return filter;
	}

	public void setFilter(SpaceCharFilter filter) {
		this.filter = filter;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(char[] array) {
		writer.print(array);
	}

	public void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void print(int[] array) {
		for (int i = 0; i < array.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(array[i]);
		}
	}

	public void print(long[] array) {
		for (int i = 0; i < array.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(array[i]);
		}
	}

	public void print(Collection<Integer> collection) {
		boolean first = true;
		for (Iterator<Integer> iterator = collection.iterator(); iterator
				.hasNext(); iterator.next()) {
			if (first)
				first = false;
			else
				writer.print(' ');
			writer.print(iterator);
		}
	}

	public void printLine(int[] array) {
		print(array);
		writer.println();
	}

	public void printLine(long[] array) {
		print(array);
		writer.println();
	}

	public void printLine(Collection<Integer> collection) {
		print(collection);
		writer.println();
	}

	public void printLine() {
		writer.println();
	}

	public void printLine(Object... objects) {
		print(objects);
		writer.println();
	}

	public void print(char i) {
		writer.print(i);
	}

	public void printLine(char i) {
		writer.println(i);
	}

	public void printLine(char[] array) {
		writer.println(array);
	}

	public void printFormat(String format, Object... objects) {
		writer.printf(format, objects);
	}

	public void close() {
		writer.close();
	}

	public void flush() {
		writer.flush();
	}

	public void print(long i) {
		writer.print(i);
	}

	public void printLine(long i) {
		writer.println(i);
	}

	public void print(int i) {
		writer.print(i);
	}

	public void printLine(int i) {
		writer.println(i);
	}
}

class Matrix {
    public static long mod = Long.MAX_VALUE;
    public final long[][] data;
    public final int rowCount;
    public final int columnCount;

    public Matrix(int rowCount, int columnCount) {
            this.rowCount = rowCount;
            this.columnCount = columnCount;
            this.data = new long[rowCount][columnCount];
    }

    public Matrix(long[][] data) {
            this.rowCount = data.length;
            this.columnCount = data[0].length;
            this.data = data;
    }

    public static Matrix add(Matrix first, Matrix second) {
            Matrix result = new Matrix(first.rowCount, first.columnCount);
            for (int i = 0; i < result.rowCount; i++) {
                    for (int j = 0; j < result.columnCount; j++) {
                            result.data[i][j] = first.data[i][j] + second.data[i][j];
                            if (result.data[i][j] >= mod)
                                    result.data[i][j] -= mod;
                    }
            }
            return result;
    }

    public static Matrix multiply(Matrix first, Matrix second) {
            Matrix result = new Matrix(first.rowCount, second.columnCount);
            for (int i = 0; i < first.rowCount; i++) {
                    for (int j = 0; j < second.rowCount; j++) {
                            for (int k = 0; k < second.columnCount; k++)
                                    result.data[i][k] = (result.data[i][k] + first.data[i][j] * second.data[j][k]) % mod;
                    }
            }
            return result;
    }

    public static Matrix fastMultiply(Matrix first, Matrix second) {
            Matrix result = new Matrix(first.rowCount, second.columnCount);
            for (int i = 0; i < first.rowCount; i++) {
                    for (int j = 0; j < second.rowCount; j++) {
                            for (int k = 0; k < second.columnCount; k++)
                                    result.data[i][k] += first.data[i][j] * second.data[j][k];
                    }
            }
            for (int i = 0; i < first.rowCount; i++) {
                    for (int j = 0; j < second.columnCount; j++)
                            result.data[i][j] %= mod;
            }
            return result;
    }

    public static Matrix identityMatrix(int size) {
            Matrix result = new Matrix(size, size);
            for (int i = 0; i < size; i++)
                    result.data[i][i] = 1;
            return result;
    }

    public static long[] convert(long[][] matrix) {
            long[] result = new long[matrix.length * matrix.length];
            for (int i = 0; i < matrix.length; i++) {
                    for (int j = 0; j < matrix.length; j++)
                            result[i * matrix.length + j] = matrix[i][j];
            }
            return result;
    }

    public static long[] sumPowers(long[] matrix, long exponent, long mod, int side) {
            long[] result = new long[matrix.length];
            long[] power = new long[matrix.length];
            long[] temp = new long[matrix.length];
            long[] temp2 = new long[matrix.length];
            sumPowers(matrix, result, power, temp, temp2, exponent + 1, mod, side);
            return result;
    }

    private static void sumPowers(long[] matrix, long[] result, long[] power, long[] temp, long[] temp2, long exponent, long mod, int side) {
            if (exponent == 0) {
                    for (int i = 0; i < matrix.length; i += side + 1)
                            power[i] = 1 % mod;
                    return;
            }
            if ((exponent & 1) == 0) {
                    sumPowers(matrix, result, temp, power, temp2, exponent >> 1, mod, side);
                    multiply(temp2, result, temp, mod, side);
                    add(result, temp2, mod, side);
                    multiply(power, temp, temp, mod, side);
            } else {
                    sumPowers(matrix, result, temp, power, temp2, exponent - 1, mod, side);
                    add(result, temp, mod, side);
                    multiply(power, temp, matrix, mod, side);
            }
    }

    public static long[][] convert(long[] matrix, int side) {
            long[][] result = new long[side][side];
            for (int i = 0; i < side; i++) {
                    for (int j = 0; j < side; j++)
                            result[i][j] = matrix[i * side + j];
            }
            return result;
    }

    public static long[] power(long[] matrix, long exponent, long mod, int side) {
            long[] result = new long[matrix.length];
            long[] temp = new long[result.length];
            power(matrix, result, temp, exponent, mod, side);
            return result;
    }

    private static void power(long[] matrix, long[] result, long[] temp, long exponent, long mod, int side) {
            if (exponent == 0) {
                    for (int i = 0; i < matrix.length; i += side + 1)
                            result[i] = 1 % mod;
                    return;
            }
            if ((exponent & 1) == 0) {
                    power(matrix, temp, result, exponent >> 1, mod, side);
                    multiply(result, temp, temp, mod, side);
            } else {
                    power(matrix, temp, result, exponent - 1, mod, side);
                    multiply(result, temp, matrix, mod, side);
            }
    }

    public static void multiply(long[] c, long[] a, long[] b, long mod, int side) {
            Arrays.fill(c, 0);
            for (int i = 0; i < side; i++) {
                    for (int j = 0; j < side; j++) {
                            for (int k = 0; k < side; k++) {
                                    c[i * side + k] += a[i * side + j] * b[j * side + k];
                                    if ((j & 3) == 3) {
                                            c[i * side + k] %= mod;
                                    }
                            }
                    }
            }
            for (int i = 0; i < c.length; i++)
                    c[i] %= mod;
    }

    public static void add(long[] c, long[] a, long mod, int side) {
            for (int i = 0; i < side; i++) {
                    for (int j = 0; j < side; j++) {
                            c[i * side + j] += a[i * side + j];
                            if (c[i * side + j] >= mod)
                                    c[i * side + j] -= mod;
                    }
            }
    }

    public static long[] fastPower(long[] matrix, long exponent, long mod, int side) {
            long[] result = new long[matrix.length];
            long[] temp = new long[result.length];
            fastPower(matrix, result, temp, exponent, mod, side);
            return result;
    }

    private static void fastPower(long[] matrix, long[] result, long[] temp, long exponent, long mod, int side) {
            if (exponent == 0) {
                    for (int i = 0; i < matrix.length; i += side + 1)
                            result[i] = 1;
                    return;
            }
            if ((exponent & 1) == 0) {
                    fastPower(matrix, temp, result, exponent >> 1, mod, side);
                    fastMultiply(result, temp, temp, mod, side);
            } else {
                    power(matrix, temp, result, exponent - 1, mod, side);
                    fastMultiply(result, temp, matrix, mod, side);
            }
    }

    public static void fastMultiply(long[] c, long[] a, long[] b, long mod, int side) {
            Arrays.fill(c, 0);
            for (int i = 0; i < side; i++) {
                    for (int j = 0; j < side; j++) {
                            for (int k = 0; k < side; k++)
                                    c[i * side + k] += a[i * side + j] * b[j * side + k];
                    }
            }
            for (int i = 0; i < c.length; i++)
                    c[i] %= mod;
    }

    public Matrix power(long exponent) {
            if (exponent == 0)
                    return identityMatrix(rowCount);
            if (exponent == 1)
                    return this;
            Matrix result = power(exponent >> 1);
            result = multiply(result, result);
            if ((exponent & 1) == 1)
                    result = multiply(result, this);
            return result;
    }

    public Matrix fastPower(long exponent) {
            if (exponent == 0)
                    return identityMatrix(rowCount);
            if (exponent == 1)
                    return this;
            Matrix result = power(exponent >> 1);
            result = fastMultiply(result, result);
            if ((exponent & 1) == 1)
                    result = fastMultiply(result, this);
            return result;
    }
}