import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class TaskD {
	private static final double id1 = 0;

	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	private final InputReader in;
	private final PrintWriter out;
	private final boolean testMode;

	private static class Point implements Comparable<Point> {
		private final double x;
		private final double y;
		private final double angle;
		private final double distance;

		private Point(double x, double y) {
			this.x = x;
			this.y = y;
			angle = Math.atan2(y, x);
			distance = Math.hypot(x, y);
		}

		public int compareTo(Point o) {
			if (Math.abs(angle - o.angle) > 1e-13)
				return Double.compare(angle, o.angle);
			return 0;
		}
	}

	private void solve() {
		int queryCount = in.readInt();
		double[] startX = new double[3];
		double[] startY = new double[3];
		for (int i = 0; i < 3; i++) {
			in.readInt();
			startX[i] = in.readInt();
			startY[i] = in.readInt();
		}
		double x = 0;
		double y = 0;
		for (int i = 0; i < 3; i++) {
			x += startX[i];
			y += startY[i];
		}
		x /= 3;
		y /= 3;
		NavigableSet<Point> id9 = new TreeSet<Point>();
		for (int i = 0; i < 3; i++)
			id9.add(new Point(startX[i] - x, startY[i] - y));
		for (int i = 3; i < queryCount; i++) {
			int queryType = in.readInt();
			double currentX = in.readInt() - x;
			double currentY = in.readInt() - y;
			Point current = new Point(currentX, currentY);
			Point lastPoint = getLast(current, id9, true);
			Point nextPoint = getNext(current, id9, true);
			boolean inside;
			if (lastPoint == nextPoint)
				inside = current.distance <= lastPoint.distance;
			else
				inside = isInside(current, lastPoint, nextPoint);
			if (queryType == 2) {
				out.println(inside ? "YES" : "NO");
				continue;
			}
			if (inside)
				continue;
			while (true) {
				Point preLast = getLast(lastPoint, id9, false);
				if (!isInside(lastPoint, preLast, current))
					break;
				id9.remove(lastPoint);
				lastPoint = preLast;
			}
			while (true) {
				Point preNext = getNext(nextPoint, id9, false);
				if (!isInside(nextPoint, preNext, current))
					break;
				id9.remove(nextPoint);
				nextPoint = preNext;
			}
			id9.add(current);
		}
	}

	private boolean isInside(Point toCheck, Point first, Point second) {
		return Math.abs(square(toCheck, first) + square(toCheck, second) + square(toCheck, first, second) - square(first, second)) < .25;
	}

	private double square(Point first, Point second, Point third) {
		return square(first.x, first.y, second.x, second.y, third.x, third.y);
	}

	private double square(double x1, double y1, double x2, double y2, double x3, double y3) {
		return Math.abs((x1 - x2) * (y1 + y2) + (x2 - x3) * (y3 + y2) + (x3 - x1) * (y1 + y3)) / 2;
	}

	private double square(Point first, Point second) {
		return square(first.x, first.y, second.x, second.y, 0, 0);
	}

	private Point getLast(Point current, NavigableSet<Point> id9, boolean inclusive) {
		NavigableSet<Point> head = id9.headSet(current, inclusive);
		if (head.isEmpty())
			head = id9;
		return head.last();
	}

	private Point getNext(Point current, NavigableSet<Point> id9, boolean inclusive) {
		NavigableSet<Point> tail = id9.tailSet(current, inclusive);
		if (tail.isEmpty())
			tail = id9;
		return tail.first();
	}

	private static List<Test> createTests() {
		List<Test> tests = new ArrayList<Test>();
		tests.add(new Test("7\n" +
			"1 -2 -1000000\n" +
			"1 -1 -1000000\n" +
			"1 -1 -999999\n" +
			"1 1 1000000\n" +
			"1 -231100 1000000\n" +
			"2 0 0\n" +
			"2 1 999999", "YES\n" +
			"NO"));
		tests.add(new Test("8\n" +
			"1 0 0\n" +
			"1 2 0\n" +
			"1 2 2\n" +
			"2 1 0\n" +
			"1 0 2\n" +
			"2 1 1\n" +
			"2 2 1\n" +
			"2 20 -1", "YES\n" +
			"YES\n" +
			"YES\n" +
			"NO"));
		tests.add(new Test("5 1 0 1 1 1 -1 1 -1 -1 1 0 3 2 0 2", "YES"));


































		return tests;
	}

	private void run() {
		







		solve();
		exit();
	}

	private TaskD() {
		@SuppressWarnings({"UnusedDeclaration"})
		String id = getClass().getName().toLowerCase();
		

		try {








		} catch (Exception e) {
			throw new RuntimeException(e);
		}
		in = new id12(System.in);
		out = new PrintWriter(System.out);
		testMode = false;
	}

	@SuppressWarnings({"UnusedParameters"})
	private static String check(String input, String result, String output) {


		return tokenCheck(result, output);
	}

	public static void main(String[] args) {
		if (args.length != 0 && args[0].equals("42"))
			test();
		else
			new TaskD().run();
	}

	private static void test() {
		System.setProperty("line.separator", "\n");
		List<Test> tests = createTests();
		int testCase = 0;
		List<Verdict> id11 = new ArrayList<Verdict>();
		long id15 = 0;
		boolean ok = true;
		for (Test test : tests) {
			System.out.println("Test 
			InputReader in = new id4(test.getInput());
			StringWriter out = new StringWriter(test.getOutput().length());
			System.out.println("Input:");
			System.out.println(test.getInput());
			System.out.println("Expected output:");
			System.out.println(test.getOutput());
			System.out.println("Execution result:");
			long time = System.currentTimeMillis();
			try {
				new TaskD(in, new PrintWriter(out)).run();
			} catch (TestException e) {
				time = System.currentTimeMillis() - time;
				id15 = Math.max(time, id15);
				String result = out.getBuffer().toString();
				System.out.println(result);
				System.out.print("Verdict: ");
				String checkResult = check(test.getInput(), result, test.getOutput());
				if (checkResult == null) {
					System.out.print("OK");
					id11.add(Verdict.OK);
				} else {
					System.out.print("WA (" + checkResult + ")");
					id11.add(Verdict.WA);
					ok = false;
				}
				System.out.printf(" in %.3f s.\n", time / 1000.);
			} catch (Throwable e) {
				System.out.println("Exception thrown:");
				e.printStackTrace(System.out);
				id11.add(Verdict.RTE);
				ok = false;
			}
			testCase++;
			System.out.println("------------------------------------------------------------------");
		}
		System.out.println("==================================================================");
		System.out.println("Test results:");
		if (ok)
			System.out.printf("All test passed in %.3f s.\n", id15 / 1000.);
		else {
			for (int i = 0; i < id11.size(); i++)
				System.out.println("Test 
		}
	}

	private static enum Verdict {
		OK, WA, RTE
	}

	private static String tokenCheck(String result, String output) {
		id4 resultStream = new id4(result);
		id4 outputStream = new id4(output);
		int index = 0;
		boolean readingResult = false;
		try {
			while (true) {
				readingResult = true;
				String resultToken = resultStream.readString();
				readingResult = false;
				String outputToken = outputStream.readString();
				if (!resultToken.equals(outputToken)) {
					try {
						

						if (id1 != 0 && id10(Double.parseDouble(outputToken.replace(',', '.')),
								Double.parseDouble(resultToken.replace(',', '.')), id1))
						{
							index++;
							continue;
						}
					} catch (NumberFormatException ignored) {}
					return "'" + outputToken + "' expected at " + index + " but '" + resultToken + "' received";
				}
				index++;
			}
		} catch (InputMismatchException e) {
			if (readingResult) {
				try {
					outputStream.readString();
					return "only " + index + " tokens received";
				} catch (InputMismatchException e1) {
					return null;
				}
			} else
				return "only " + index + " tokens expected";
		}
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private static String strictCheck(String result, String output) {
		if (result.equals(output))
			return null;
		return "Result and expected output do not match";
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private static boolean id10(double expected, double result, double certainty) {
		return Math.abs(expected - result) < certainty || Math.abs(expected - result) < certainty * expected;
	}

	private TaskD(InputReader in, PrintWriter out) {
		this.in = in;
		this.out = out;
		testMode = true;
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private void exit() {
		out.close();
		if (testMode)
			throw new TestException();
		System.exit(0);
	}

	private static class Test {
		private final String input;
		private final String output;

		private Test(String input, String output) {
			this.input = input;
			this.output = output;
		}

		public String getInput() {
			return input;
		}

		public String getOutput() {
			return output;
		}
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private abstract static class InputReader {
		public abstract int read();

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
			StringBuffer res = new StringBuffer();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id5(c));
			return res.toString();
		}

		private boolean id5(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private String id3() {
			StringBuffer buf = new StringBuffer();
			int c = read();
			while (c != '\n' && c != -1) {
				if (c != '\r')
					buf.appendCodePoint(c);
				c = read();
			}
			return buf.toString();
		}

		public String readLine() {
			String s = id3();
			while (s.trim().length() == 0)
				s = id3();
			return s;
		}

		public String readLine(boolean id13) {
			if (id13)
				return readLine();
			else
				return id3();
		}

		public BigInteger id8() {
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

		public int[] id0(int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++)
				array[i] = readInt();
			return array;
		}

		public long[] id6(int size) {
			long[] array = new long[size];
			for (int i = 0; i < size; i++)
				array[i] = readLong();
			return array;
		}

		public double[] id2(int size) {
			double[] array = new double[size];
			for (int i = 0; i < size; i++)
				array[i] = readDouble();
			return array;
		}

		public String[] id14(int size) {
			String[] array = new String[size];
			for (int i = 0; i < size; i++)
				array[i] = readString();
			return array;
		}

		public char[][] readTable(int rowCount, int columnCount) {
			char[][] table = new char[rowCount][columnCount];
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < columnCount; j++)
					table[i][j] = readCharacter();
			}
			return table;
		}

		public void id7(int[]... arrays) {
			for (int i = 0; i < arrays[0].length; i++) {
				for (int j = 0; j < arrays.length; j++)
					arrays[j][i] = readInt();
			}
		}
	}

	private static class id12 extends InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar, numChars;

		public id12(InputStream stream) {
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
	}

	private static class id4 extends InputReader {
		private Reader stream;
		private char[] buf = new char[1024];
		private int curChar, numChars;

		public id4(String stream) {
			this.stream = new StringReader(stream);
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
	}

	private static class TestException extends RuntimeException {}
}
