import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Solution {

	static InputReader in = new InputReader(System.in);
	static OutputWriter out = new OutputWriter(System.out);
	static int exp = (int) (1e9);
	static int mod1 = (int) (1e9 + 7);
	static int mod2 = (int) (1e9 + 9);
	static int base = 5;
	static long[] powers;

	private static long makeHash(String s, long mod) {
		long h = 0;
		for (int i = 0; i < s.length(); i++) {
			h *= base;
			h %= mod;
			h += s.charAt(i) - 'a' + 1;
		}
		h %= mod;
		return h;
	}

	public static void main(String[] args) {

		int n = in.nextInt();
		int m = in.nextInt();

		HashSet<Long> hs = new HashSet<>();
		long[] powers1 = IntegerUtils.id7(base, 600001, mod1);
		long[] powers2 = IntegerUtils.id7(base, 600001, mod2);

		for (int i = 0; i < n; i++) {
			String str = in.readLine();
			long h1 = makeHash(str, mod1);
			long h2 = makeHash(str, mod2);
			long h = h1 * Integer.MAX_VALUE + h2;
			hs.add(h);
		}

		for (int i = 0; i < m; i++) {
			String str = in.readLine();
			char[] arr = str.toCharArray();

			long h1 = makeHash(str, mod1);
			long h2 = makeHash(str, mod2);

			boolean found = false;

			for (int j = 0; j < arr.length && !found; j++) {
				for (int c = 'a'; c <= 'c' && !found; c++) {
					if (arr[j] != c) {
						long hh1 = ((h1 + powers1[arr.length - 1 - j] * (c - arr[j])) % mod1 + mod1) % mod1;
						long hh2 = ((h2 + powers2[arr.length - 1 - j] * (c - arr[j])) % mod2 + mod2) % mod2;
						long h = hh1 * Integer.MAX_VALUE + hh2;
						if (hs.contains(h)) {
							found = true;
						}
					}
				}
			}

			out.println(found ? "YES" : "NO");
		}

		out.close();

	}

}

class Node {

	int r;
	int idx;

	public Node(int r, int idx) {
		super();
		this.r = r;
		this.idx = idx;
	}

	@Override
	public String toString() {
		return "Node [r=" + r + ", idx=" + idx + "]";
	}

}

class Trie {

	HashMap<Character, HashMap> root;

	public Trie() {
		root = new HashMap<Character, HashMap>();
	}

	public Trie(String[] sa) {
		this();
		addAll(sa);
	}

	public Trie(Collection<String> sc) {
		this();
		addAll(sc);
	}

	public void add(String s) {
		HashMap<Character, HashMap> curr_node = root;
		for (int i = 0, n = s.length(); i < n; i++) {
			Character c = s.charAt(i);
			if (curr_node.containsKey(c))
				curr_node = curr_node.get(c);
			else {
				curr_node.put(c, new HashMap<Character, HashMap>());
				curr_node = curr_node.get(c);
			}
		}
		curr_node.put('\0', new HashMap<Character, HashMap>(0)); 

	}

	public void addAll(String[] sa) {
		for (String s : sa)
			add(s);
	}

	public void addAll(Collection<String> sc) {
		for (String s : sc)
			add(s);
	}

	public boolean contains(String s, HashMap<Character, HashMap> h, int count) {
		if (s.length() == 0)
			if (h.containsKey('\0') && count == 1)
				return true;
			else
				return false;
		if (h.containsKey(s.charAt(0))) {
			return contains(s.substring(1), h.get(s.charAt(0)), count);
		} else {
			if (count == 0) {
				count++;
				Set<Character> ks = h.keySet();
				System.out.println(ks.size());
				for (Character c : ks) {
					System.out.println(c);
					if (contains(s.substring(1), h.get(c), count))
						return true;
				}
				return false;
			} else
				return false;
		}
	}

	public boolean contains(String s) {
		HashMap<Character, HashMap> curr_node = root;
		for (int i = 0, n = s.length(); i < n; i++) {
			Character c = s.charAt(i);
			if (curr_node.containsKey(c))
				curr_node = curr_node.get(c);
			else
				return false;
		}
		if (curr_node.containsKey('\0'))
			return true;
		else
			return false;
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

	public static boolean[] id2(int upTo) {
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

	public static int[] id1(int upTo) {
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

	public static int[] id0(int upTo) {
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

	public static long id9(long n, long p) {
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

	public static long[][] id14(int n) {
		long[][] result = new long[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			result[i][0] = 1;
			for (int j = 1; j <= i; j++)
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
		return result;
	}

	public static long[][] id14(int n, long module) {
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

	public static long[] id8(int n, long module) {
		long[] result = generateReverse(n + 1, module);
		result[0] = 1;
		for (int i = 1; i <= n; i++)
			result[i] = result[i - 1] * (n - i + 1) % module * result[i] % module;
		return result;
	}

	public static int[] id15(long number, int base) {
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

	public static long[] id6(long upTo) {
		int count = 0;
		long last = 0;
		long current = 1;
		while (current <= upTo) {
			long next = last + current;
			last = current;
			current = next;
			count++;
		}
		return id6(count, -1);
	}

	public static long[] id6(int count, long module) {
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

	public static long[] id10(int count, long module) {
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
			result[i] = (module - module / i * result[((int) (module % i))] % module) % module;
		return result;
	}

	public static long[] id5(int upTo, long module) {
		long[] result = generateReverse(upTo, module);
		if (upTo > 0)
			result[0] = 1;
		for (int i = 1; i < upTo; i++)
			result[i] = result[i] * result[i - 1] % module;
		return result;
	}

	public static long[] id7(long base, int count, long mod) {
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

	public static long id13(int n, int m, long mod) {
		if (m < 0 || m > n)
			return 0;
		if (2 * m > n)
			m = n - m;
		long result = 1;
		for (int i = n - m + 1; i <= n; i++)
			result = result * i % mod;
		return result * BigInteger.valueOf(factorial(m, mod)).modInverse(BigInteger.valueOf(mod)).longValue() % mod;
	}

	public static boolean isSquare(long number) {
		long sqrt = Math.round(Math.sqrt(number));
		return sqrt * sqrt == number;
	}

	public static long findCommon(long id3, long aMod, long id12, long bMod) {
		long id11 = gcd(aMod, bMod);
		long id4 = id3 % id11;
		if (id4 != id12 % id11)
			return -1;
		aMod /= id11;
		id3 /= id11;
		bMod /= id11;
		id12 /= id11;
		long aReverse = BigInteger.valueOf(aMod).modInverse(BigInteger.valueOf(bMod)).longValue();
		long bReverse = BigInteger.valueOf(bMod).modInverse(BigInteger.valueOf(aMod)).longValue();
		long mod = aMod * bMod;
		return BigInteger.valueOf(bReverse * id3 % mod).multiply(BigInteger.valueOf(bMod))
				.add(BigInteger.valueOf(aReverse * id12 % mod).multiply(BigInteger.valueOf(aMod)))
				.mod(BigInteger.valueOf(mod)).longValue() * id11 + id4;
	}

	public static long[] id7(long base, long maxValue) {
		if (maxValue <= 0)
			return new long[0];
		int size = 1;
		long current = 1;
		while (maxValue / base >= current) {
			current *= base;
			size++;
		}
		return id7(base, size, Long.MAX_VALUE);
	}
}

class OutputWriter {
	public PrintWriter writer;

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

	public void println(Object... objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream), 32768);
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());

			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public String readLine() {
		try {
			return reader.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	public char nextChar() {
		return next().charAt(0);
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public float nextFloat() {
		return Float.parseFloat(next());
	}

}