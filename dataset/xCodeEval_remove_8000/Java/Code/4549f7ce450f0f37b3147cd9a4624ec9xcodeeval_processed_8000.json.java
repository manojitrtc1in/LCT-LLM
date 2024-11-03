import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.io.*;
import java.lang.reflect.*;

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
	
	int[] arr, inc;
	
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int n=in.readInt(), m=in.readInt(), w=in.readInt();
		arr=new int[n+1];
		inc=new int[n+1];
		for (int i=0; i<n; i++) arr[i]=in.readInt();
		out.println(binarySearch(n, m, w, 1, 1000100001)-1);
	}
	
	int binarySearch(int n, int m, int w, int from, int to) {
		while (from<to) {
			int x=(from+to)/2;
			if (f(n, m, w, x)) from=x+1;
			else to=x;
		}
		return from;
	}
	
	boolean f(int n, int m, int w, int x) {


		Arrays.fill(inc, 0);
		int add=0;
		for (int i=0; i<n; i++) {
			if (i-w>=0) add-=inc[i-w];
			if (arr[i]+add<x) {
				inc[i]=x-arr[i]-add;
				if (m<inc[i]) return false;
				m-=inc[i];
				add+=inc[i];
			}
		}
		return true;
	}
}

class OutputWriter extends PrintWriter {

	public OutputWriter(OutputStream outputStream) {
		super(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

}

class InputReader {
	private boolean finished = false;

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private id53 filter;

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
		while (id1(c))
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
		} while (!id1(c));
		return res * sgn;
	}

	public long readLong() {
		int c = read();
		while (id1(c))
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
		} while (!id1(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (id1(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!id1(c));
		return res.toString();
	}

	public boolean id1(int c) {
		if (filter != null)
			return filter.id1(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String id18() {
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
		String s = id18();
		while (s.trim().length() == 0)
			s = id18();
		return s;
	}

	public String readLine(boolean id72) {
		if (id72)
			return readLine();
		else
			return id18();
	}

	public BigInteger id7() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (id1(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (id1(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!id1(c) && c != '.') {
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
			while (!id1(c)) {
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

	public boolean id23() {
		int value;
		while (id1(value = peek()) && value != -1)
			read();
		return value == -1;
	}

	public String next() {
		return readString();
	}

	public id53 getFilter() {
		return filter;
	}

	public void setFilter(id53 filter) {
		this.filter = filter;
	}

	public interface id53 {
		public boolean id1(int ch);
	}
}

class MiscUtils {
	public static final int[] DX4 = { 1, 0, -1, 0 };
	public static final int[] DY4 = { 0, -1, 0, 1 };
	public static final int[] DX8 = { 1, 1, 1, 0, -1, -1, -1, 0 };
	public static final int[] DY8 = { -1, 0, 1, 1, 1, 0, -1, -1 };
	public static final int[] id36 = { 2, 1, -1, -2, -2, -1, 1, 2 };
	public static final int[] id25 = { 1, 2, 2, 1, -1, -2, -2, -1 };

	private static final String[] id39 = { "M", "CM", "D", "CD", "C",
			"XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	private static final int[] id74 = { 1000, 900, 500, 400, 100, 90,
			50, 40, 10, 9, 5, 4, 1 };

	public static long id22(long n, int k) {
		if (n == 1)
			return 0;
		if (k == 1)
			return n - 1;
		if (k > n)
			return (id22(n - 1, k) + k) % n;
		long count = n / k;
		long result = id22(n - count, k);
		result -= n % k;
		if (result < 0)
			result += n;
		else
			result += result / (k - 1);
		return result;
	}

	public static int parseIP(String ip) {
		String[] components = ip.split("[.]");
		int result = 0;
		for (int i = 0; i < 4; i++)
			result += (1 << (24 - 8 * i)) * Integer.parseInt(components[i]);
		return result;
	}

	public static String buildIP(int mask) {
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < 4; i++) {
			if (i != 0)
				result.append('.');
			result.append(mask >> (24 - 8 * i) & 255);
		}
		return result.toString();
	}

	public static String id33(int number) {
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < id39.length; i++) {
			while (number >= id74[i]) {
				number -= id74[i];
				result.append(id39[i]);
			}
		}
		return result.toString();
	}

	public static int id30(String number) {
		int result = 0;
		for (int i = 0; i < id39.length; i++) {
			while (number.startsWith(id39[i])) {
				number = number.substring(id39[i].length());
				result += id74[i];
			}
		}
		return result;
	}

	public static <T extends Comparable<T>> T min(T first, T second) {
		if (first.compareTo(second) <= 0)
			return first;
		return second;
	}

	public static <T extends Comparable<T>> T max(T first, T second) {
		if (first.compareTo(second) <= 0)
			return second;
		return first;
	}

	public static int[] id11(String s) {
		String[] tokens = s.split(" ");
		int[] result = new int[tokens.length];
		for (int i = 0; i < result.length; i++)
			result[i] = Integer.parseInt(tokens[i]);
		return result;
	}
}

class IntegerUtils {
	public static long gcd(long a, long b) {
		a = Math.abs(a);
		b = Math.abs(b);
		while (b != 0) {
			long temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}

	public static int gcd(int a, int b) {
		a = Math.abs(a);
		b = Math.abs(b);
		while (b != 0) {
			int temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}

	public static int[] id50(int upTo) {
		int[] isPrime = id20(upTo);
		List<Integer> primes = new ArrayList<Integer>();
		for (int i = 0; i < upTo; i++) {
			if ((isPrime[i >> 5] >>> (i & 31) & 1) == 1)
				primes.add(i);
		}
		isPrime = new int[primes.size()];
		for (int i = 0; i < primes.size(); i++)
			isPrime[i] = primes.get(i);
		return isPrime;
	}

	public static boolean[] id21(int upTo) {
		boolean[] isPrime = new boolean[upTo];
		if (upTo < 2)
			return isPrime;
		Arrays.fill(isPrime, true);
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i * i < upTo; i++) {
			if (isPrime[i]) {
				for (int j = i * i; j < upTo; j += i)
					isPrime[j] = false;
			}
		}
		return isPrime;
	}

	public static int[] id20(int upTo) {
		int[] isPrime = new int[(upTo + 31) >> 5];
		if (upTo < 2)
			return isPrime;
		Arrays.fill(isPrime, -1);
		isPrime[0] &= -4;
		for (int i = 2; i * i < upTo; i++) {
			if ((isPrime[i >> 5] >>> (i & 31) & 1) == 1) {
				for (int j = i * i; j < upTo; j += i)
					isPrime[j >> 5] &= -1 - (1 << (j & 31));
			}
		}
		return isPrime;
	}

	public static int[] id19(int upTo) {
		int[] divisor = new int[upTo];
		for (int i = 1; i < upTo; i++)
			divisor[i] = i;
		for (int i = 2; i * i < upTo; i++) {
			if (divisor[i] == i) {
				for (int j = i * i; j < upTo; j += i)
					divisor[j] = i;
			}
		}
		return divisor;
	}

	public static long id65(long n, long p) {
		long result = 0;
		while (n != 0) {
			result += n /= p;
		}
		return result;
	}

	public static int sumDigits(CharSequence number) {
		int result = 0;
		for (int i = number.length() - 1; i >= 0; i--)
			result += digitValue(number.charAt(i));
		return result;
	}

	public static int digitValue(char digit) {
		if (Character.isDigit(digit))
			return digit - '0';
		if (Character.isUpperCase(digit))
			return digit + 10 - 'A';
		return digit + 10 - 'a';
	}

	public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

	public static long[][] id47(int n) {
		long[][] result = new long[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			result[i][0] = 1;
			for (int j = 1; j <= i; j++)
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
		return result;
	}

	public static long[][] id47(int n, long module) {
		long[][] result = new long[n + 1][n + 1];
		if (module == 1)
			return result;
		for (int i = 0; i <= n; i++) {
			result[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
				if (result[i][j] >= module)
					result[i][j] -= module;
			}
		}
		return result;
	}

	public static long[] id62(int n, long module) {
		long[] result = generateReverse(n + 1, module);
		result[0] = 1;
		for (int i = 1; i <= n; i++)
			result[i] = result[i - 1] * (n - i + 1) % module * result[i]
					% module;
		return result;
	}

	public static int[] id52(long number, int base) {
		long basePower = base;
		int exponent = 1;
		while (number >= basePower) {
			basePower *= base;
			exponent++;
		}
		int[] representation = new int[exponent];
		for (int i = 0; i < exponent; i++) {
			basePower /= base;
			representation[i] = (int) (number / basePower);
			number %= basePower;
		}
		return representation;
	}

	public static int trueDivide(int a, int b) {
		return (a - trueMod(a, b)) / b;
	}

	public static long trueDivide(long a, long b) {
		return (a - trueMod(a, b)) / b;
	}

	public static int trueMod(int a, int b) {
		a %= b;
		a += b;
		a %= b;
		return a;
	}

	public static long trueMod(long a, long b) {
		a %= b;
		a += b;
		a %= b;
		return a;
	}

	public static long factorial(int n) {
		long result = 1;
		for (int i = 2; i <= n; i++)
			result *= i;
		return result;
	}

	public static long factorial(int n, long mod) {
		long result = 1;
		for (int i = 2; i <= n; i++)
			result = result * i % mod;
		return result % mod;
	}

	public static List<Pair<Long, Integer>> factorize(long number) {
		List<Pair<Long, Integer>> result = new ArrayList<Pair<Long, Integer>>();
		for (long i = 2; i * i <= number; i++) {
			if (number % i == 0) {
				int power = 0;
				do {
					power++;
					number /= i;
				} while (number % i == 0);
				result.add(Pair.makePair(i, power));
			}
		}
		if (number != 1)
			result.add(Pair.makePair(number, 1));
		return result;
	}

	public static List<Long> id14(long number) {
		List<Pair<Long, Integer>> id51 = factorize(number);
		return id40(id51, 0, 1, new ArrayList<Long>());
	}

	private static List<Long> id40(
			List<Pair<Long, Integer>> id51, int index, long current,
			List<Long> result) {
		if (index == id51.size()) {
			result.add(current);
			return result;
		}
		long p = id51.get(index).first;
		int power = id51.get(index).second;
		for (int i = 0; i <= power; i++) {
			id40(id51, index + 1, current, result);
			current *= p;
		}
		return result;
	}

	public static long power(long base, long exponent) {
		if (exponent == 0)
			return 1;
		long result = power(base, exponent >> 1);
		result = result * result;
		if ((exponent & 1) != 0)
			result = result * base;
		return result;
	}

	public static long power(long base, long exponent, long mod) {
		if (base >= mod)
			base %= mod;
		if (exponent == 0)
			return 1 % mod;
		long result = power(base, exponent >> 1, mod);
		result = result * result % mod;
		if ((exponent & 1) != 0)
			result = result * base % mod;
		return result;
	}

	public static long lcm(long a, long b) {
		return a / gcd(a, b) * b;
	}

	public static long[] id28(long upTo) {
		int count = 0;
		long last = 0;
		long current = 1;
		while (current <= upTo) {
			long next = last + current;
			last = current;
			current = next;
			count++;
		}
		return id28(count, -1);
	}

	public static long[] id28(int count, long module) {
		long[] result = new long[count];
		if (module == -1) {
			if (count != 0)
				result[0] = 1;
			if (count > 1)
				result[1] = 1;
			for (int i = 2; i < count; i++)
				result[i] = result[i - 1] + result[i - 2];
		} else {
			if (count != 0)
				result[0] = 1 % module;
			if (count > 1)
				result[1] = 1 % module;
			for (int i = 2; i < count; i++)
				result[i] = (result[i - 1] + result[i - 2]) % module;
		}
		return result;
	}

	public static long[] generateHappy(int digits) {
		long[] happy = new long[(1 << (digits + 1)) - 2];
		happy[0] = 4;
		happy[1] = 7;
		int first = 0;
		int last = 2;
		for (int i = 2; i <= digits; i++) {
			for (int j = 0; j < last - first; j++) {
				happy[last + 2 * j] = 10 * happy[first + j] + 4;
				happy[last + 2 * j + 1] = 10 * happy[first + j] + 7;
			}
			int next = last + 2 * (last - first);
			first = last;
			last = next;
		}
		return happy;
	}

	public static long[] id70(int count, long module) {
		long[] result = new long[count];
		if (module == -1) {
			if (count != 0)
				result[0] = 1;
			for (int i = 1; i < count; i++)
				result[i] = result[i - 1] * i;
		} else {
			if (count != 0)
				result[0] = 1 % module;
			for (int i = 1; i < count; i++)
				result[i] = (result[i - 1] * i) % module;
		}
		return result;
	}

	public static long reverse(long number, long module) {
		return power(number, module - 2, module);
	}

	public static boolean isPrime(long number) {
		if (number < 2)
			return false;
		for (long i = 2; i * i <= number; i++) {
			if (number % i == 0)
				return false;
		}
		return true;
	}

	public static long[] generateReverse(int upTo, long module) {
		long[] result = new long[upTo];
		if (upTo > 1)
			result[1] = 1;
		for (int i = 2; i < upTo; i++)
			result[i] = (module - module / i * result[((int) (module % i))]
					% module)
					% module;
		return result;
	}

	public static long[] id24(int upTo, long module) {
		long[] result = generateReverse(upTo, module);
		if (upTo > 0)
			result[0] = 1;
		for (int i = 1; i < upTo; i++)
			result[i] = result[i] * result[i - 1] % module;
		return result;
	}

	public static long[] id29(long base, int count, long mod) {
		long[] result = new long[count];
		if (count != 0)
			result[0] = 1 % mod;
		for (int i = 1; i < count; i++)
			result[i] = result[i - 1] * base % mod;
		return result;
	}

	public static long nextPrime(long from) {
		if (from <= 2)
			return 2;
		from += 1 - (from & 1);
		while (!isPrime(from))
			from += 2;
		return from;
	}

	public static long id35(int n, int m, long mod) {
		if (m < 0 || m > n)
			return 0;
		if (2 * m > n)
			m = n - m;
		long result = 1;
		for (int i = n - m + 1; i <= n; i++)
			result = result * i % mod;
		return result
				* BigInteger.valueOf(factorial(m, mod))
						.modInverse(BigInteger.valueOf(mod)).longValue() % mod;
	}

	public static boolean isSquare(long number) {
		long sqrt = Math.round(Math.sqrt(number));
		return sqrt * sqrt == number;
	}

	public static long findCommon(long id59, long aMod, long id10,
			long bMod) {
		long id8 = gcd(aMod, bMod);
		long id60 = id59 % id8;
		if (id60 != id10 % id8)
			return -1;
		aMod /= id8;
		id59 /= id8;
		bMod /= id8;
		id10 /= id8;
		long aReverse = BigInteger.valueOf(aMod)
				.modInverse(BigInteger.valueOf(bMod)).longValue();
		long bReverse = BigInteger.valueOf(bMod)
				.modInverse(BigInteger.valueOf(aMod)).longValue();
		long mod = aMod * bMod;
		return (bReverse * id59 % mod * bMod + aReverse * id10
				% mod * aMod)
				% mod * id8 + id60;
	}

	public static long[] id29(long base, long maxValue) {
		if (maxValue <= 0)
			return new long[0];
		int size = 1;
		long current = 1;
		while (maxValue / base >= current) {
			current *= base;
			size++;
		}
		return id29(base, size, Long.MAX_VALUE);
	}
}

interface Edge {
	public int getSource();

	public int getDestination();

	public long getWeight();

	public long getCapacity();

	public long getFlow();

	public void pushFlow(long flow);

	public boolean getFlag(int bit);

	public void setFlag(int bit);

	public void removeFlag(int bit);

	public int id54();

	public Edge id58();

	public int id12();

	public Edge id48();

	public int getID();

	public void remove();

	public void restore();
}

class Graph {
	public static final int id76 = 0;

	protected int vertexCount;
	protected int edgeCount;

	private int[] firstOutbound;
	private int[] firstInbound;

	private Edge[] edges;
	private int[] nextInbound;
	private int[] nextOutbound;
	private int[] from;
	private int[] to;
	private long[] weight;
	private long[] capacity;
	private int[] reverseEdge;
	private int[] flags;

	public Graph(int vertexCount) {
		this(vertexCount, vertexCount);
	}

	public Graph(int vertexCount, int edgeCapacity) {
		this.vertexCount = vertexCount;
		firstOutbound = new int[vertexCount];
		Arrays.fill(firstOutbound, -1);

		from = new int[edgeCapacity];
		to = new int[edgeCapacity];
		nextOutbound = new int[edgeCapacity];
		flags = new int[edgeCapacity];
	}

	public static Graph createGraph(int vertexCount, int[] from, int[] to) {
		Graph graph = new Graph(vertexCount, from.length);
		for (int i = 0; i < from.length; i++)
			graph.id6(from[i], to[i]);
		return graph;
	}

	public static Graph id16(int vertexCount, int[] from,
			int[] to, long[] weight) {
		Graph graph = new Graph(vertexCount, from.length);
		for (int i = 0; i < from.length; i++)
			graph.id0(from[i], to[i], weight[i]);
		return graph;
	}

	public static Graph id46(int vertexCount, int[] from, int[] to,
			long[] capacity) {
		Graph graph = new Graph(vertexCount, from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id27(from[i], to[i], capacity[i]);
		return graph;
	}

	public static Graph id41(int vertexCount, int[] from,
			int[] to, long[] weight, long[] capacity) {
		Graph graph = new Graph(vertexCount, from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id42(from[i], to[i], weight[i], capacity[i]);
		return graph;
	}

	public static Graph createTree(int[] parent) {
		Graph graph = new Graph(parent.length + 1, parent.length);
		for (int i = 0; i < parent.length; i++)
			graph.id6(parent[i], i + 1);
		return graph;
	}

	public int addEdge(int fromID, int toID, long weight, long capacity,
			int reverseEdge) {
		id45(edgeCount + 1);
		if (firstOutbound[fromID] != -1)
			nextOutbound[edgeCount] = firstOutbound[fromID];
		else
			nextOutbound[edgeCount] = -1;
		firstOutbound[fromID] = edgeCount;
		if (firstInbound != null) {
			if (firstInbound[toID] != -1)
				nextInbound[edgeCount] = firstInbound[toID];
			else
				nextInbound[edgeCount] = -1;
			firstInbound[toID] = edgeCount;
		}
		this.from[edgeCount] = fromID;
		this.to[edgeCount] = toID;
		if (capacity != 0) {
			if (this.capacity == null)
				this.capacity = new long[from.length];
			this.capacity[edgeCount] = capacity;
		}
		if (weight != 0) {
			if (this.weight == null)
				this.weight = new long[from.length];
			this.weight[edgeCount] = weight;
		}
		if (reverseEdge != -1) {
			if (this.reverseEdge == null) {
				this.reverseEdge = new int[from.length];
				Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
			}
			this.reverseEdge[edgeCount] = reverseEdge;
		}
		if (edges != null)
			edges[edgeCount] = createEdge(edgeCount);
		return edgeCount++;
	}

	protected final GraphEdge createEdge(int id) {
		return new GraphEdge(id);
	}

	public final int id42(int from, int to, long weight,
			long capacity) {
		if (capacity == 0) {
			return addEdge(from, to, weight, 0, -1);
		} else {
			int id66 = edgeCount;
			addEdge(to, from, -weight, 0, id66 + id5());
			return addEdge(from, to, weight, capacity, id66);
		}
	}

	protected int id5() {
		return 1;
	}

	public final int id27(int from, int to, long capacity) {
		return id42(from, to, 0, capacity);
	}

	public final int id0(int from, int to, long weight) {
		return id42(from, to, weight, 0);
	}

	public final int id6(int from, int to) {
		return id0(from, to, 0);
	}

	public final int vertexCount() {
		return vertexCount;
	}

	public final int edgeCount() {
		return edgeCount;
	}

	protected final int edgeCapacity() {
		return from.length;
	}

	public final Edge edge(int id) {
		initEdges();
		return edges[id];
	}

	public final int firstOutbound(int vertex) {
		int id = firstOutbound[vertex];
		while (id != -1 && isRemoved(id))
			id = nextOutbound[id];
		return id;
	}

	public final int nextOutbound(int id) {
		id = nextOutbound[id];
		while (id != -1 && isRemoved(id))
			id = nextOutbound[id];
		return id;
	}

	public final int firstInbound(int vertex) {
		initInbound();
		int id = firstInbound[vertex];
		while (id != -1 && isRemoved(id))
			id = nextInbound[id];
		return id;
	}

	public final int nextInbound(int id) {
		initInbound();
		id = nextInbound[id];
		while (id != -1 && isRemoved(id))
			id = nextInbound[id];
		return id;
	}

	public final int source(int id) {
		return from[id];
	}

	public final int destination(int id) {
		return to[id];
	}

	public final long weight(int id) {
		if (weight == null)
			return 0;
		return weight[id];
	}

	public final long capacity(int id) {
		if (capacity == null)
			return 0;
		return capacity[id];
	}

	public final long flow(int id) {
		if (reverseEdge == null)
			return 0;
		return capacity[reverseEdge[id]];
	}

	public final void pushFlow(int id, long flow) {
		if (flow == 0)
			return;
		if (flow > 0) {
			if (capacity(id) < flow)
				throw new IllegalArgumentException("Not enough capacity");
		} else {
			if (flow(id) < -flow)
				throw new IllegalArgumentException("Not enough capacity");
		}
		capacity[id] -= flow;
		capacity[reverseEdge[id]] += flow;
	}

	public int transposed(int id) {
		return -1;
	}

	public final int reverse(int id) {
		if (reverseEdge == null)
			return -1;
		return reverseEdge[id];
	}

	public final void addVertices(int count) {
		id43(vertexCount + count);
		Arrays.fill(firstOutbound, vertexCount, vertexCount + count, -1);
		if (firstInbound != null)
			Arrays.fill(firstInbound, vertexCount, vertexCount + count, -1);
		vertexCount += count;
	}

	protected final void initEdges() {
		if (edges == null) {
			edges = new Edge[from.length];
			for (int i = 0; i < edgeCount; i++)
				edges[i] = createEdge(i);
		}
	}

	public final void removeVertex(int vertex) {
		int id = firstOutbound[vertex];
		while (id != -1) {
			removeEdge(id);
			id = nextOutbound[id];
		}
		initInbound();
		id = firstInbound[vertex];
		while (id != -1) {
			removeEdge(id);
			id = nextInbound[id];
		}
	}

	private void initInbound() {
		if (firstInbound == null) {
			firstInbound = new int[firstOutbound.length];
			Arrays.fill(firstInbound, 0, vertexCount, -1);
			nextInbound = new int[from.length];
			for (int i = 0; i < edgeCount; i++) {
				nextInbound[i] = firstInbound[to[i]];
				firstInbound[to[i]] = i;
			}
		}
	}

	public final boolean flag(int id, int bit) {
		return (flags[id] >> bit & 1) != 0;
	}

	public final void setFlag(int id, int bit) {
		flags[id] |= 1 << bit;
	}

	public final void removeFlag(int id, int bit) {
		flags[id] &= -1 - (1 << bit);
	}

	public final void removeEdge(int id) {
		setFlag(id, id76);
	}

	public final void restoreEdge(int id) {
		removeFlag(id, id76);
	}

	public final boolean isRemoved(int id) {
		return flag(id, id76);
	}

	public final Iterable<Edge> outbound(final int id) {
		initEdges();
		return new Iterable<Edge>() {
			public Iterator<Edge> iterator() {
				return new EdgeIterator(id, firstOutbound, nextOutbound);
			}
		};
	}

	public final Iterable<Edge> inbound(final int id) {
		initEdges();
		initInbound();
		return new Iterable<Edge>() {
			public Iterator<Edge> iterator() {
				return new EdgeIterator(id, firstInbound, nextInbound);
			}
		};
	}

	protected void id45(int size) {
		if (from.length < size) {
			int newSize = Math.max(size, 2 * from.length);
			if (edges != null)
				edges = resize(edges, newSize);
			from = resize(from, newSize);
			to = resize(to, newSize);
			nextOutbound = resize(nextOutbound, newSize);
			if (nextInbound != null)
				nextInbound = resize(nextInbound, newSize);
			if (weight != null)
				weight = resize(weight, newSize);
			if (capacity != null)
				capacity = resize(capacity, newSize);
			if (reverseEdge != null)
				reverseEdge = resize(reverseEdge, newSize);
			flags = resize(flags, newSize);
		}
	}

	private void id43(int size) {
		if (firstOutbound.length < size) {
			int newSize = Math.max(size, 2 * from.length);
			firstOutbound = resize(firstOutbound, newSize);
			if (firstInbound != null)
				firstInbound = resize(firstInbound, newSize);
		}
	}

	protected final int[] resize(int[] array, int size) {
		int[] newArray = new int[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private long[] resize(long[] array, int size) {
		long[] newArray = new long[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private Edge[] resize(Edge[] array, int size) {
		Edge[] newArray = new Edge[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	public final boolean isSparse() {
		return vertexCount == 0 || edgeCount * 20 / vertexCount <= vertexCount;
	}

	protected class GraphEdge implements Edge {
		protected int id;

		protected GraphEdge(int id) {
			this.id = id;
		}

		public int getSource() {
			return source(id);
		}

		public int getDestination() {
			return destination(id);
		}

		public long getWeight() {
			return weight(id);
		}

		public long getCapacity() {
			return capacity(id);
		}

		public long getFlow() {
			return flow(id);
		}

		public void pushFlow(long flow) {
			Graph.this.pushFlow(id, flow);
		}

		public boolean getFlag(int bit) {
			return flag(id, bit);
		}

		public void setFlag(int bit) {
			Graph.this.setFlag(id, bit);
		}

		public void removeFlag(int bit) {
			Graph.this.removeFlag(id, bit);
		}

		public int id54() {
			return transposed(id);
		}

		public Edge id58() {
			int reverseID = id54();
			if (reverseID == -1)
				return null;
			initEdges();
			return edge(reverseID);
		}

		public int id12() {
			return reverse(id);
		}

		public Edge id48() {
			int reverseID = id12();
			if (reverseID == -1)
				return null;
			initEdges();
			return edge(reverseID);
		}

		public int getID() {
			return id;
		}

		public void remove() {
			removeEdge(id);
		}

		public void restore() {
			restoreEdge(id);
		}
	}

	public class EdgeIterator implements Iterator<Edge> {
		private int edgeID;
		private final int[] next;
		private int lastID = -1;

		public EdgeIterator(int id, int[] first, int[] next) {
			this.next = next;
			edgeID = nextEdge(first[id]);
		}

		private int nextEdge(int id) {
			while (id != -1 && isRemoved(id))
				id = next[id];
			return id;
		}

		public boolean hasNext() {
			return edgeID != -1;
		}

		public Edge next() {
			if (edgeID == -1)
				throw new NoSuchElementException();
			lastID = edgeID;
			edgeID = nextEdge(next[lastID]);
			return edges[lastID];
		}

		public void remove() {
			if (lastID == -1)
				throw new IllegalStateException();
			removeEdge(lastID);
			lastID = -1;
		}
	}

}

class id26 extends Graph {
	public int[] id17;

	public id26(int vertexCount) {
		this(vertexCount, vertexCount);
	}

	public id26(int vertexCount, int edgeCapacity) {
		super(vertexCount, 2 * edgeCapacity);
		id17 = new int[2 * edgeCapacity];
	}

	public static id26 createGraph(int vertexCount, int[] from,
			int[] to) {
		id26 graph = new id26(vertexCount,
				from.length);
		for (int i = 0; i < from.length; i++)
			graph.id6(from[i], to[i]);
		return graph;
	}

	public static id26 id16(int vertexCount,
			int[] from, int[] to, long[] weight) {
		id26 graph = new id26(vertexCount,
				from.length);
		for (int i = 0; i < from.length; i++)
			graph.id0(from[i], to[i], weight[i]);
		return graph;
	}

	public static id26 id46(int vertexCount,
			int[] from, int[] to, long[] capacity) {
		id26 graph = new id26(vertexCount,
				from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id27(from[i], to[i], capacity[i]);
		return graph;
	}

	public static id26 id41(int vertexCount,
			int[] from, int[] to, long[] weight, long[] capacity) {
		id26 graph = new id26(vertexCount,
				from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id42(from[i], to[i], weight[i], capacity[i]);
		return graph;
	}

	@Override
	public int addEdge(int fromID, int toID, long weight, long capacity,
			int reverseEdge) {
		int id66 = edgeCount;
		super.addEdge(fromID, toID, weight, capacity, reverseEdge);
		super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1
				: reverseEdge + 1);
		this.id17[id66] = id66 + 1;
		this.id17[id66 + 1] = id66;
		return id66;
	}

	@Override
	protected int id5() {
		return 2;
	}

	@Override
	public final int transposed(int id) {
		return id17[id];
	}

	@Override
	protected void id45(int size) {
		if (size > edgeCapacity()) {
			super.id45(size);
			id17 = resize(id17, edgeCapacity());
		}
	}
}

interface IntComparator extends Comparator<Integer> {
	public static final IntComparator DEFAULT = new IntComparator() {
		public int compare(Integer first, Integer second) {
			if (first < second)
				return -1;
			if (first > second)
				return 1;
			return 0;
		}
	};

	public static final IntComparator REVERSE = new IntComparator() {
		public int compare(Integer first, Integer second) {
			if (first < second)
				return 1;
			if (first > second)
				return -1;
			return 0;
		}
	};

	public int compare(Integer first, Integer second);
}

interface id64 {
	public boolean join(int first, int second);

	public int get(int index);

	public int id15();

	public void setListener(Listener listener);

	public static interface Listener {
		public void joined(int joinedRoot, int root);
	}
}

class id61 implements id64 {
	private final int[] color;
	private final int[] rank;
	private int setCount;
	private Listener listener;

	public id61(int size) {
		color = new int[size];
		rank = new int[size];
		for (int i = 0; i < size; i++)
			color[i] = i;
		setCount = size;
	}

	public id61(id61 other) {
		color = other.color.clone();
		rank = other.rank.clone();
		setCount = other.setCount;
	}

	public boolean join(int first, int second) {
		first = get(first);
		second = get(second);
		if (first == second)
			return false;
		if (rank[first] < rank[second]) {
			int temp = first;
			first = second;
			second = temp;
		} else if (rank[first] == rank[second])
			rank[first]++;
		setCount--;
		color[second] = first;
		if (listener != null)
			listener.joined(second, first);
		return true;
	}

	public int get(int index) {
		if (color[index] == index)
			return index;
		return color[index] = get(color[index]);
	}

	public int id15() {
		return setCount;
	}

	public void setListener(Listener listener) {
		this.listener = listener;
	}
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static <U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		Pair pair = (Pair) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null)
				&& !(second != null ? !second.equals(pair.second)
						: pair.second != null);

	}

	@Override
	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}

	public Pair<V, U> swap() {
		return makePair(second, first);
	}

	@Override
	public String toString() {
		return "(" + first + "," + second + ")";
	}

	@SuppressWarnings({ "unchecked" })
	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>) first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>) second).compareTo(o.second);
	}
}

class ArrayUtils {

	public static void sort(int[] array, IntComparator comparator) {
		Integer[] aux = new Integer[array.length];
		Arrays.sort(aux, comparator);
		for (int i = 0; i < aux.length; i++)
			array[i] = aux[i];
	}

	public static void sort(int[] array) {
		sort(array, IntComparator.DEFAULT);
	}

}

class StringUtils {
	public static String reverse(String sample) {
		StringBuilder result = new StringBuilder(sample);
		result.reverse();
		return result.toString();
	}

	public static int count(String string, char c) {
		int count = 0;
		for (int i = string.length() - 1; i >= 0; i--) {
			if (string.charAt(i) == c) {
				count++;
			}
		}
		return count;
	}

	public static String unite(String[] array) {
		StringBuilder result = new StringBuilder();
		for (String s : array) {
			result.append(s);
		}
		return result.toString();
	}

	public static int differs(String first, String second) {
		int result = 0;
		for (int i = 0; i < first.length(); i++) {
			if (first.charAt(i) != second.charAt(i)) {
				result++;
			}
		}
		return result;
	}

	public static int[] zAlgorithm(CharSequence s) {
		int length = s.length();
		int[] z = new int[length];
		int left = 0, right = 0;
		for (int i = 1; i < length; i++) {
			if (i > right) {
				int j;
				

				for (j = 0; i + j < length && s.charAt(i + j) == s.charAt(j); j++)
					;
				z[i] = j;
				left = i;
				right = i + j - 1;
			} else if (z[i - left] < right - i + 1)
				z[i] = z[i - left];
			else {
				int j;
				

				for (j = 1; right + j < length
						&& s.charAt(right + j) == s.charAt(right - i + j); j++)
					;
				z[i] = right - i + j;
				left = i;
				right = right + j - 1;
			}
		}
		return z;
	}

	public static int[] prefixFunction(CharSequence s) {
		int l = s.length();
		int[] p = new int[l];
		int k = 0;
		for (int i = 1; i < l; i++) {
			while ((k > 0) && (s.charAt(k) != s.charAt(i)))
				k = p[k - 1];
			if (s.charAt(k) == s.charAt(i))
				k++;
			p[i] = k;
		}
		return p;
	}

	public static int[] suffixArray(CharSequence s) {
		int length = s.length();
		int[] result = new int[length];
		for (int i = 0; i < length; i++)
			result[i] = length - i - 1;
		final long[] type = new long[length];
		for (int i = 0; i < length; i++)
			type[i] = s.charAt(i);
		final long[] nextType = new long[length];
		int curLength = 1;
		ArrayUtils.sort(result, new IntComparator() {
			public int compare(Integer first, Integer second) {
				return IntegerUtils.longCompare(type[first], type[second]);
			}
		});
		while (curLength < length) {
			for (int i = 0; i < length; i++)
				nextType[i] = (type[i] << 32)
						+ (i + curLength < length ? type[i + curLength] : -1);
			ArrayUtils.sort(result, new IntComparator() {
				public int compare(Integer first, Integer second) {
					return IntegerUtils.longCompare(nextType[first],
							nextType[second]);
				}
			});
			long currentType = nextType[result[0]];
			long currentIndex = 0;
			for (int i = 0; i < length; i++) {
				if (nextType[result[i]] != currentType) {
					currentIndex++;
					currentType = nextType[result[i]];
				}
				type[result[i]] = currentIndex;
			}
			curLength <<= 1;
		}
		return result;
	}

	public static int[][] id2(CharSequence s) {
		return id2(s, 'a', 'z');
	}

	public static int[][] id2(CharSequence s, char from,
			char to) {
		int[] prefixFunction = prefixFunction(s);
		int length = to - from + 1;
		int[][] result = new int[s.length() + 1][length];
		result[0][s.charAt(0) - from] = 1;
		for (int i = 1; i <= s.length(); i++) {
			System.arraycopy(result[prefixFunction[i - 1]], 0, result[i], 0,
					length);
			if (i != s.length())
				result[i][s.charAt(i) - from] = i + 1;
		}
		return result;
	}

	public static boolean contains(final String s, final String target) {
		int[] z = zAlgorithm(new CharSequence() {
			public int length() {
				return s.length() + target.length();
			}

			public char charAt(int index) {
				if (index < target.length())
					return target.charAt(index);
				return s.charAt(index - target.length());
			}

			public CharSequence subSequence(int start, int end) {
				throw new UnsupportedOperationException();
			}
		});
		for (int i = target.length(); i < z.length; i++) {
			if (z[i] >= target.length())
				return true;
		}
		return false;
	}

	public static int[] suffixArray(String s) {
		int length = s.length();
		int[] position = new int[length];
		int[] count = new int[Math.max(256, length)];
		int[] order = new int[length];
		for (int i = 0; i < length; ++i)
			count[s.charAt(i)]++;
		for (int i = 1; i < 256; ++i)
			count[i] += count[i - 1];
		for (int i = 0; i < length; ++i)
			position[--count[s.charAt(i)]] = i;
		order[position[0]] = 0;
		int currentClass = 0;
		for (int i = 1; i < length; ++i) {
			if (s.charAt(position[i]) != s.charAt(position[i - 1]))
				currentClass++;
			order[position[i]] = currentClass;
		}
		int[] nextPosition = new int[length];
		int[] nextOrder = new int[length];
		for (int h = 0; (1 << h) < length; h++) {
			for (int i = 0; i < length; ++i) {
				nextPosition[i] = position[i] - (1 << h);
				if (nextPosition[i] < 0)
					nextPosition[i] += length;
			}
			Arrays.fill(count, 0);
			for (int i = 0; i < length; ++i)
				count[order[nextPosition[i]]]++;
			for (int i = 1; i < currentClass; ++i)
				count[i] += count[i - 1];
			for (int i = length - 1; i >= 0; --i)
				position[--count[order[nextPosition[i]]]] = nextPosition[i];
			nextOrder[position[0]] = 0;
			currentClass = 0;
			for (int i = 1; i < length; ++i) {
				int mid1 = (position[i] + (1 << h));
				if (mid1 >= length)
					mid1 -= length;
				int mid2 = (position[i - 1] + (1 << h));
				if (mid2 >= length)
					mid2 -= length;
				if (order[position[i]] != order[position[i - 1]]
						|| order[mid1] != order[mid2])
					currentClass++;
				nextOrder[position[i]] = currentClass;
			}
			System.arraycopy(nextOrder, 0, order, 0, length);
		}
		return order;
	}
}

class MaxFlow {
	private final Graph graph;
	private int source;
	private int destination;
	private int[] queue;
	private int[] distance;
	private int[] nextEdge;

	private MaxFlow(Graph graph, int source, int destination) {
		this.graph = graph;
		this.source = source;
		this.destination = destination;
		int vertexCount = graph.vertexCount();
		queue = new int[vertexCount];
		distance = new int[vertexCount];
		nextEdge = new int[vertexCount];
	}

	public static long dinic(Graph graph, int source, int destination) {
		return new MaxFlow(graph, source, destination).dinic();
	}

	private long dinic() {
		long totalFlow = 0;
		while (true) {
			edgeDistances();
			if (distance[destination] == -1)
				break;
			Arrays.fill(nextEdge, -2);
			totalFlow += id56(source, Long.MAX_VALUE);
		}
		return totalFlow;
	}

	private void edgeDistances() {
		Arrays.fill(distance, -1);
		distance[source] = 0;
		int size = 1;
		queue[0] = source;
		for (int i = 0; i < size; i++) {
			int current = queue[i];
			int id = graph.firstOutbound(current);
			while (id != -1) {
				if (graph.capacity(id) != 0) {
					int next = graph.destination(id);
					if (distance[next] == -1) {
						distance[next] = distance[current] + 1;
						queue[size++] = next;
					}
				}
				id = graph.nextOutbound(id);
			}
		}
	}

	private long id56(int source, long flow) {
		if (source == destination)
			return flow;
		if (flow == 0 || distance[source] == distance[destination])
			return 0;
		int id = nextEdge[source];
		if (id == -2)
			nextEdge[source] = id = graph.firstOutbound(source);
		long id13 = 0;
		while (id != -1) {
			int id63 = graph.destination(id);
			if (graph.capacity(id) != 0
					&& distance[id63] == distance[source] + 1) {
				long pushed = id56(id63,
						Math.min(flow, graph.capacity(id)));
				if (pushed != 0) {
					graph.pushFlow(id, pushed);
					flow -= pushed;
					id13 += pushed;
					if (flow == 0)
						return id13;
				}
			}
			nextEdge[source] = id = graph.nextOutbound(id);
		}
		return id13;
	}
}

class Heap {
	private IntComparator comparator;
	private int size = 0;
	private int[] elements;
	private int[] at;

	public Heap(int maxElement) {
		this(10, maxElement);
	}

	public Heap(IntComparator comparator, int maxElement) {
		this(10, comparator, maxElement);
	}

	public Heap(int capacity, int maxElement) {
		this(capacity, IntComparator.DEFAULT, maxElement);
	}

	public Heap(int capacity, IntComparator comparator, int maxElement) {
		this.comparator = comparator;
		elements = new int[capacity];
		at = new int[maxElement];
		Arrays.fill(at, -1);
	}

	public int getSize() {
		return size;
	}

	public void setComparator(IntComparator comparator) {
		this.comparator = comparator;
	}

	public boolean isEmpty() {
		return size == 0;
	}

	public int add(int element) {
		ensureCapacity(size + 1);
		elements[size] = element;
		at[element] = size;
		shiftUp(size++);
		return at[element];
	}

	public void shiftUp(int index) {
		

		

		int value = elements[index];
		while (index != 0) {
			int parent = (index - 1) >>> 1;
			int parentValue = elements[parent];
			if (comparator.compare(parentValue, value) <= 0) {
				elements[index] = value;
				at[value] = index;
				return;
			}
			elements[index] = parentValue;
			at[parentValue] = index;
			index = parent;
		}
		elements[0] = value;
		at[value] = 0;
	}

	public void shiftDown(int index) {
		if (index < 0 || index >= size)
			throw new IllegalArgumentException();
		while (true) {
			int child = (index << 1) + 1;
			if (child >= size)
				return;
			if (child + 1 < size
					&& comparator.compare(elements[child], elements[child + 1]) > 0)
				child++;
			if (comparator.compare(elements[index], elements[child]) <= 0)
				return;
			swap(index, child);
			index = child;
		}
	}

	public int getIndex(int element) {
		return at[element];
	}

	private void swap(int first, int second) {
		int temp = elements[first];
		elements[first] = elements[second];
		elements[second] = temp;
		at[elements[first]] = first;
		at[elements[second]] = second;
	}

	private void ensureCapacity(int size) {
		if (elements.length < size) {
			int[] oldElements = elements;
			elements = new int[Math.max(2 * elements.length, size)];
			System.arraycopy(oldElements, 0, elements, 0, this.size);
		}
	}

	public int peek() {
		if (isEmpty())
			throw new IndexOutOfBoundsException();
		return elements[0];
	}

	public int poll() {
		if (isEmpty())
			throw new IndexOutOfBoundsException();
		int result = elements[0];
		at[result] = -1;
		if (size == 1) {
			size = 0;
			return result;
		}
		elements[0] = elements[--size];
		at[elements[0]] = 0;
		shiftDown(0);
		return result;
	}

	public void clear() {
		size = 0;
		Arrays.fill(at, -1);
	}
}

class ShortestDistance {
	public static Pair<long[], int[]> id37(Graph graph, int source) {
		int vertexCount = graph.vertexCount();
		final long[] distance = new long[vertexCount];
		int[] last = new int[vertexCount];
		Arrays.fill(distance, Long.MAX_VALUE);
		Arrays.fill(last, -1);
		distance[source] = 0;
		if (graph.isSparse()) {
			Heap heap = new Heap(vertexCount, new IntComparator() {
				public int compare(Integer first, Integer second) {
					return IntegerUtils.longCompare(distance[first],
							distance[second]);
				}
			}, vertexCount);
			heap.add(source);
			while (!heap.isEmpty()) {
				int current = heap.poll();
				int id = graph.firstOutbound(current);
				while (id != -1) {
					int next = graph.destination(id);
					long total = graph.weight(id) + distance[current];
					if (distance[next] > total) {
						distance[next] = total;
						if (heap.getIndex(next) == -1)
							heap.add(next);
						else
							heap.shiftUp(heap.getIndex(next));
						last[next] = id;
					}
					id = graph.nextOutbound(id);
				}
			}
		} else {
			boolean[] visited = new boolean[vertexCount];
			for (int i = 0; i < vertexCount; i++) {
				int index = -1;
				long length = Long.MAX_VALUE;
				for (int j = 0; j < vertexCount; j++) {
					if (!visited[j] && distance[j] < length) {
						length = distance[j];
						index = j;
					}
				}
				if (index == -1)
					break;
				visited[index] = true;
				int id = graph.firstOutbound(index);
				while (id != -1) {
					int next = graph.destination(id);
					if (!visited[next]) {
						long total = graph.weight(id) + length;
						if (distance[next] > total) {
							distance[next] = total;
							last[next] = id;
						}
					}
					id = graph.nextOutbound(id);
				}
			}
		}
		return Pair.makePair(distance, last);
	}

	public static Pair<Long, List<Integer>> id37(Graph graph,
			int source, int destination) {
		if (source == destination)
			return Pair.makePair(0L, (List<Integer>) new ArrayList<Integer>());
		Pair<long[], int[]> result = id37(graph, source);
		if (result.second[destination] == -1)
			return null;
		List<Integer> path = new ArrayList<Integer>();
		int id = destination;
		while (id != source) {
			path.add(result.second[id]);
			id = graph.source(result.second[id]);
		}
		Collections.reverse(path);
		return Pair.makePair(result.first[destination], path);
	}
}

class ReverseComparator<T extends Comparable<T>> implements Comparator<T> {
	public int compare(T o1, T o2) {
		return o2.compareTo(o1);
	}
}

class Indexer<K> extends TreeMap<K, Integer> {
	private int index = 0;

	@Override
	public Integer get(Object key) {
		if (!containsKey(key))
			put((K) key, index++);
		return super.get(key);
	}
}

class Counter<K> extends TreeMap<K, Long> {
	public Counter() {
		super();
	}

	public Counter(int capacity) {
		super();
	}

	public long add(K key) {
		long result = get(key);
		put(key, result + 1);
		return result + 1;
	}

	public void add(K key, long delta) {
		put(key, get(key) + delta);
	}

	@Override
	public Long get(Object key) {
		if (containsKey(key))
			return super.get(key);
		return 0L;
	}
}

interface StringHash {
	long hash(int from, int to);

	long hash(int from);

	int length();
}

abstract class id9 implements StringHash {
	public static final long id44;
	protected static final long id75;
	protected static final long id73;
	public static final long FIRST_MOD;
	public static final long SECOND_MOD;

	static {
		Random random = new Random(System.currentTimeMillis());
		FIRST_MOD = IntegerUtils.nextPrime((long) (1e9 + random
				.nextInt((int) 1e9)));
		SECOND_MOD = IntegerUtils.nextPrime((long) (1e9 + random
				.nextInt((int) 1e9)));
		id44 = random.nextInt((int) 1e9 - 257) + 257;
		id75 = IntegerUtils.reverse(id44, FIRST_MOD);
		id73 = IntegerUtils
				.reverse(id44, SECOND_MOD);
	}

	public long hash(int from) {
		return hash(from, length());
	}
}

class id3 extends id9 {
	private static long[] id31 = new long[0];
	private static long[] id34 = new long[0];

	private final long[] firstHash;
	private final long[] secondHash;

	public id3(CharSequence string) {
		int length = string.length();
		ensureCapacity(length);
		firstHash = new long[length + 1];
		secondHash = new long[length + 1];
		long firstPower = 1;
		long secondPower = 1;
		for (int i = 0; i < length; i++) {
			firstHash[i + 1] = (firstHash[i] + string.charAt(i) * firstPower)
					% FIRST_MOD;
			secondHash[i + 1] = (secondHash[i] + string.charAt(i) * secondPower)
					% SECOND_MOD;
			firstPower *= id44;
			firstPower %= FIRST_MOD;
			secondPower *= id44;
			secondPower %= SECOND_MOD;
		}
	}

	private void ensureCapacity(int length) {
		if (id31.length >= length)
			return;
		length = Math.max(length + 1, id31.length << 1);
		long[] oldFirst = id31;
		long[] oldSecond = id34;
		id31 = new long[length];
		id34 = new long[length];
		System.arraycopy(oldFirst, 0, id31, 0, oldFirst.length);
		System.arraycopy(oldSecond, 0, id34, 0, oldSecond.length);
		id31[0] = id34[0] = 1;
		for (int i = Math.max(oldFirst.length, 1); i < length; i++) {
			id31[i] = id31[i - 1]
					* id75 % FIRST_MOD;
			id34[i] = id34[i - 1]
					* id73 % SECOND_MOD;
		}
	}

	public long hash(int from, int to) {
		return (((firstHash[to] - firstHash[from] + FIRST_MOD)
				* id31[from] % FIRST_MOD) << 32)
				+ ((secondHash[to] - secondHash[from] + SECOND_MOD)
						* id34[from] % SECOND_MOD);
	}

	public int length() {
		return firstHash.length - 1;
	}
}

class id57 {
	public int[][] edges;
	public int[] ends;

	public id57(String[] words) {
		this(words, 'a', 'z');
	}

	public id57(String[] words, char first, char last) {
		Indexer<Long> indexer = new Indexer<>();
		Counter<Long> fullWords = new Counter<>();
		StringHash[] hashes = new StringHash[words.length];
		int totalLength = 0;
		for (int i = 0; i < words.length; i++) {
			String s = words[i];
			hashes[i] = new id3(s);
			for (int j = 0; j <= s.length(); j++)
				indexer.get(hashes[i].hash(0, j));
			fullWords.add(hashes[i].hash(0));
			totalLength += s.length();
		}
		int size = indexer.size();
		edges = new int[size][last - first + 1];
		ends = new int[size];
		int[] link = new int[size];
		Arrays.fill(link, -1);
		int[] start = new int[size];
		Arrays.fill(start, -1);
		int[] next = new int[totalLength];
		int[] to = new int[totalLength];
		int index = 0;
		Graph graph = new Graph(size);
		int[] length = new int[size];
		for (int i = 0; i < words.length; i++) {
			String s = words[i];
			for (int j = 0; j <= s.length(); j++) {
				int at = indexer.get(hashes[i].hash(0, j));
				if (j != s.length()) {
					to[index] = i;
					next[index] = start[at];
					start[at] = index++;
				}
				if (link[at] == -1) {
					length[at] = j;
					for (int k = 1; k <= j; k++) {
						long key = hashes[i].hash(k, j);
						if (indexer.containsKey(key)) {
							link[at] = indexer.get(key);
							graph.id6(link[at], at);
							break;
						}
					}
					for (int k = 0; k <= j; k++)
						ends[at] += fullWords.get(hashes[i].hash(k, j));
				}
			}
		}
		int[] queue = new int[size];
		int count = 1;
		for (int i = 0; i < count; i++) {
			int current = queue[i];
			for (int j = start[current]; j != -1; j = next[j]) {
				int at = to[j];
				edges[current][words[at].charAt(length[current]) - first] = indexer
						.get(hashes[at].hash(0, length[current] + 1));
			}
			for (int j = graph.firstOutbound(current); j != -1; j = graph
					.nextOutbound(j)) {
				int at = graph.destination(j);
				queue[count++] = at;
				System.arraycopy(edges[current], 0, edges[at], 0, last - first
						+ 1);
			}
		}
	}
}

class id67 {
	private final Graph graph;
	private final int source;
	private final int destination;
	private final long[] phi;
	private final long[] id55;
	private final int[] lastEdge;
	private final Heap heap;
	private final int vertexCount;
	private final int[] visited;
	private int visitIndex;

	public id67(Graph graph, int source, int destination,
			boolean id49) {
		this.graph = graph;
		this.source = source;
		this.destination = destination;
		vertexCount = graph.vertexCount();
		phi = new long[vertexCount];
		if (id49)
			id68();
		id55 = new long[vertexCount];
		lastEdge = new int[vertexCount];
		if (graph.isSparse()) {
			heap = new Heap(vertexCount, new IntComparator() {
				public int compare(Integer first, Integer second) {
					return IntegerUtils.longCompare(id55[first],
							id55[second]);
				}
			}, vertexCount);
			visited = null;
		} else {
			heap = null;
			visited = new int[vertexCount];
		}
	}

	private void id68() {
		Arrays.fill(phi, Long.MAX_VALUE);
		phi[source] = 0;
		boolean[] inQueue = new boolean[vertexCount];
		int[] queue = new int[vertexCount + 1];
		queue[0] = source;
		inQueue[source] = true;
		int stepCount = 0;
		int head = 0;
		int end = 1;
		int maxSteps = 2 * vertexCount * vertexCount;
		while (head != end) {
			int vertex = queue[head++];
			if (head == queue.length)
				head = 0;
			inQueue[vertex] = false;
			int edgeID = graph.firstOutbound(vertex);
			while (edgeID != -1) {
				long total = phi[vertex] + graph.weight(edgeID);
				int destination = graph.destination(edgeID);
				if (graph.capacity(edgeID) != 0 && phi[destination] > total) {
					phi[destination] = total;
					if (!inQueue[destination]) {
						queue[end++] = destination;
						inQueue[destination] = true;
						if (end == queue.length)
							end = 0;
					}
				}
				edgeID = graph.nextOutbound(edgeID);
			}
			if (++stepCount > maxSteps)
				throw new IllegalArgumentException(
						"Graph contains negative cycle");
		}
	}

	public static Pair<Long, Long> id4(Graph graph, int source,
			int destination, boolean id49) {
		return new id67(graph, source, destination, id49)
				.id4();
	}

	public static Pair<Long, Long> id4(Graph graph, int source,
			int destination, boolean id49, long maxFlow) {
		return new id67(graph, source, destination, id49)
				.id4(maxFlow);
	}

	public Pair<Long, Long> id4() {
		return id4(Long.MAX_VALUE);
	}

	public Pair<Long, Long> id4(long maxFlow) {
		long cost = 0;
		long flow = 0;
		while (maxFlow != 0) {
			if (graph.isSparse())
				id37();
			else
				id38();
			if (lastEdge[destination] == -1)
				return Pair.makePair(cost, flow);
			for (int i = 0; i < id55.length; i++) {
				if (id55[i] != Long.MAX_VALUE)
					phi[i] += id55[i];
			}
			int vertex = destination;
			long currentFlow = maxFlow;
			long currentCost = 0;
			while (vertex != source) {
				int edgeID = lastEdge[vertex];
				currentFlow = Math.min(currentFlow, graph.capacity(edgeID));
				currentCost += graph.weight(edgeID);
				vertex = graph.source(edgeID);
			}
			maxFlow -= currentFlow;
			cost += currentCost * currentFlow;
			flow += currentFlow;
			vertex = destination;
			while (vertex != source) {
				int edgeID = lastEdge[vertex];
				graph.pushFlow(edgeID, currentFlow);
				vertex = graph.source(edgeID);
			}
		}
		return Pair.makePair(cost, flow);
	}

	private void id37() {
		Arrays.fill(id55, Long.MAX_VALUE);
		Arrays.fill(lastEdge, -1);
		id55[source] = 0;
		heap.add(source);
		while (!heap.isEmpty()) {
			int current = heap.poll();
			int edgeID = graph.firstOutbound(current);
			while (edgeID != -1) {
				if (graph.capacity(edgeID) != 0) {
					int next = graph.destination(edgeID);
					long total = graph.weight(edgeID) - phi[next]
							+ phi[current] + id55[current];
					if (id55[next] > total) {
						id55[next] = total;
						if (heap.getIndex(next) == -1)
							heap.add(next);
						else
							heap.shiftUp(heap.getIndex(next));
						lastEdge[next] = edgeID;
					}
				}
				edgeID = graph.nextOutbound(edgeID);
			}
		}
	}

	private void id38() {
		visitIndex++;
		Arrays.fill(id55, Long.MAX_VALUE);
		lastEdge[destination] = -1;
		id55[source] = 0;
		for (int i = 0; i < vertexCount; i++) {
			int index = -1;
			long length = Long.MAX_VALUE;
			for (int j = 0; j < vertexCount; j++) {
				if (visited[j] != visitIndex && id55[j] < length) {
					length = id55[j];
					index = j;
				}
			}
			if (index == -1) {
				return;
			}
			visited[index] = visitIndex;
			int edgeID = graph.firstOutbound(index);
			while (edgeID != -1) {
				if (graph.capacity(edgeID) != 0) {
					int next = graph.destination(edgeID);
					if (visited[next] != visitIndex) {
						long total = graph.weight(edgeID) - phi[next]
								+ phi[index] + length;
						if (id55[next] > total) {
							id55[next] = total;
							lastEdge[next] = edgeID;
						}
					}
				}
				edgeID = graph.nextOutbound(edgeID);
			}
		}
	}
}

abstract class IntList {
	public abstract int get(int index);

	public abstract void set(int index, int value);

	public abstract int size();

	public abstract void add(int value);
}

class id32 {
	public final int[] length;
	public final int[] link;
	public final int[] first;
	public final int[] next;
	public final int[] to;
	public final int[] label;
	public int size;
	public int last;
	public int edgeSize;

	public id32(final CharSequence s) {
		this(new IntList() {
			@Override
			public int get(int index) {
				return s.charAt(index);
			}

			public void set(int index, int value) {
				throw new UnsupportedOperationException();
			}

			@Override
			public int size() {
				return s.length();
			}

			public void add(int value) {
				throw new UnsupportedOperationException();
			}
		});
	}

	public id32(IntList s) {
		int count = s.size();
		length = new int[2 * count + 1];
		link = new int[2 * count + 1];
		first = new int[2 * count + 1];
		next = new int[4 * count];
		label = new int[4 * count];
		to = new int[4 * count];
		Arrays.fill(first, -1);
		link[0] = -1;
		size = 1;
		edgeSize = 0;
		last = 0;
		for (int i = 0; i < s.size(); i++) {
			int c = s.get(i);
			int current = size++;
			length[current] = length[last] + 1;
			for (int previous = last;; previous = link[previous]) {
				if (previous == -1) {
					link[current] = 0;
					break;
				}
				int index = findEdge(previous, c);
				if (index != -1) {
					int curLink = to[index];
					if (length[previous] + 1 == length[curLink])
						link[current] = curLink;
					else {
						int clone = size++;
						length[clone] = length[previous] + 1;
						link[clone] = link[curLink];
						int linkEdge = first[curLink];
						while (linkEdge != -1) {
							next[edgeSize] = first[clone];
							first[clone] = edgeSize;
							label[edgeSize] = label[linkEdge];
							to[edgeSize++] = to[linkEdge];
							linkEdge = next[linkEdge];
						}
						for (; previous != -1; previous = link[previous]) {
							int edge = findEdge(previous, c);
							if (edge == -1 || to[edge] != curLink)
								break;
							to[edge] = clone;
						}
						link[current] = link[curLink] = clone;
					}
					break;
				}
				next[edgeSize] = first[previous];
				first[previous] = edgeSize;
				label[edgeSize] = c;
				to[edgeSize++] = current;
			}
			last = current;
		}
	}

	public int findEdge(int vertex, int label) {
		int edge = first[vertex];
		while (edge != -1) {
			if (this.label[edge] == label)
				return edge;
			edge = next[edge];
		}
		return -1;
	}
}

class id69 {
	private final Graph graph;
	private int[] order;
	private boolean[] visited;
	private int index = 0;
	private int vertexCount;
	private int[] condensed;
	private Set<Integer> next;

	private id69(Graph graph) {
		this.graph = graph;
		vertexCount = graph.vertexCount();
		order = new int[vertexCount];
		visited = new boolean[vertexCount];
		condensed = new int[vertexCount];
	}

	public static Pair<int[], Graph> id71(Graph graph) {
		return new id69(graph).id71();
	}

	private Pair<int[], Graph> id71() {
		for (int i = 0; i < vertexCount; i++) {
			if (!visited[i])
				firstDFS(i);
		}
		Arrays.fill(visited, false);
		Graph result = new Graph(0);
		index = 0;
		for (int i = vertexCount - 1; i >= 0; i--) {
			if (!visited[order[i]]) {
				next = new TreeSet<Integer>();
				secondDFS(order[i]);
				result.addVertices(1);
				for (int set : (Integer[]) next.toArray())
					result.id6(set, index);
				index++;
			}
		}
		return Pair.makePair(condensed, result);
	}

	private void secondDFS(int vertexID) {
		if (visited[vertexID]) {
			if (condensed[vertexID] != index)
				next.add(condensed[vertexID]);
			return;
		}
		condensed[vertexID] = index;
		visited[vertexID] = true;
		int edgeID = graph.firstInbound(vertexID);
		while (edgeID != -1) {
			secondDFS(graph.source(edgeID));
			edgeID = graph.nextInbound(edgeID);
		}
	}

	private void firstDFS(int vertexID) {
		if (visited[vertexID])
			return;
		visited[vertexID] = true;
		int edgeID = graph.firstOutbound(vertexID);
		while (edgeID != -1) {
			firstDFS(graph.destination(edgeID));
			edgeID = graph.nextOutbound(edgeID);
		}
		order[index++] = vertexID;
	}
}