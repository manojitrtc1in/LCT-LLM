import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class TaskC {
	private static final double id1 = 1e-6;

	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	private final InputReader in;
	private final PrintWriter out;
	private final boolean testMode;

	private void solve() {
		int allyCount = in.readInt();
		int baseCount = in.readInt();
		int id7 = in.readInt();
		int queryCount = in.readInt();
		for (int i = 0; i < baseCount; i++)
			in.readString();
		Map<String, MultiSet<String>> composite = new HashMap<String, MultiSet<String>>();
		for (int i = 0; i < id7; i++) {
			String artifactName = in.readString();
			artifactName = artifactName.substring(0, artifactName.length() - 1);
			MultiSet<String> current = new MultiSet<String>();
			String components = in.readLine();
			for (String component : components.split(", ")) {
				String[] description = component.split(" ");
				current.add(description[0], Integer.parseInt(description[1]));
			}
			composite.put(artifactName, current);
		}
		@SuppressWarnings({"unchecked"})
		MultiSet<String>[] allies = new MultiSet[allyCount];
		for (int i = 0; i < allyCount; i++)
			allies[i] = new MultiSet<String>();
		for (int i = 0; i < queryCount; i++) {
			int allyIndex = in.readInt() - 1;
			String artifact = in.readString();
			allies[allyIndex].add(artifact);
			for (Map.Entry<String, MultiSet<String>> entry : composite.entrySet()) {
				boolean good = true;
				for (String baseArtifact : entry.getValue().map.keySet()) {
					if (entry.getValue().get(baseArtifact) > allies[allyIndex].get(baseArtifact)) {
						good = false;
						break;
					}
				}
				if (good) {
					for (String baseArtifact : entry.getValue().map.keySet())
						allies[allyIndex].add(baseArtifact, -entry.getValue().get(baseArtifact));
					allies[allyIndex].add(entry.getKey());
					break;
				}
			}
		}
		for (MultiSet<String> ally : allies) {
			out.println(ally.entryCount());
			NavigableSet<String> sorted = new TreeSet<String>(ally.map.keySet());
			for (String artifact : sorted)
				out.println(artifact + " " + ally.get(artifact));
		}
	}

	public static class MultiSet<K> {
		private Map<K, Integer> map = new HashMap<K, Integer>();
		private int size = 0;

		public int size() {
			return size;
		}

		public int entryCount() {
			return map.size();
		}

		public boolean isEmpty() {
			return size == 0;
		}

		public boolean contains(K key) {
			return map.containsKey(key);
		}

		public int add(K key) {
			Integer value = map.get(key);
			if (value == null)
				value = 0;
			value++;
			size++;
			map.put(key, value);
			return value;
		}

		public int remove(K key) {
			Integer value = map.get(key);
			if (value == null)
				return 0;
			value--;
			size--;
			if (value == 0)
				map.remove(key);
			else
				map.put(key, value);
			return value + 1;
		}

		public int removeAll(K key) {
			int value = map.remove(key);
			size -= value;
			return value;
		}

		public int get(K key) {
			Integer value = map.get(key);
			if (value == null)
				value = 0;
			return value;
		}

		public void clear() {
			map.clear();
			size = 0;
		}

		@Override
		public boolean equals(Object o) {
			if (this == o)
				return true;
			if (o == null || getClass() != o.getClass())
				return false;

			MultiSet multiSet = (MultiSet) o;

			return !(map != null ? !map.equals(multiSet.map) : multiSet.map != null);

		}

		@Override
		public int hashCode() {
			return map.hashCode();
		}

		public int add(K key, int count) {
			Integer value = map.get(key);
			if (value == null)
				value = 0;
			value += count;
			size += count;
			if (value == 0)
				map.remove(key);
			else
				map.put(key, value);
			return value;
		}
	}

	private static List<Test> createTests() {
		List<Test> tests = new ArrayList<Test>();
		tests.add(new Test("2 3 2 5\n" +
				"desolator\n" +
				"refresher\n" +
				"perseverance\n" +
				"vanguard: desolator 1, refresher 1\n" +
				"maelstorm: perseverance 2\n" +
				"1 desolator\n" +
				"2 perseverance\n" +
				"1 refresher\n" +
				"2 desolator\n" +
				"2 perseverance", "1\n" +
				"vanguard 1\n" +
				"2\n" +
				"desolator 1\n" +
				"maelstorm 1"));






































		return tests;
	}

	private void run() {
		







		solve();
		exit();
	}

	private TaskC() {
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
			new TaskC().run();
	}

	private static void test() {
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
				new TaskC(in, new PrintWriter(out)).run();
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

	private TaskC(InputReader in, PrintWriter out) {
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

		public BigInteger id9() {
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

		public void id8(int[]... arrays) {
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
