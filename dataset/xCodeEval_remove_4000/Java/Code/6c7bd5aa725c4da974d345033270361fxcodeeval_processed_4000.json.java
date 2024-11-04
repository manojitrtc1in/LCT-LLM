


import java.security.*;
import java.lang.annotation.*;
import java.nio.file.StandardOpenOption;
import java.util.stream.*;
import java.nio.file.Files;
import java.util.function.*;
import java.util.concurrent.*;
import java.util.*;
import java.nio.file.Paths;
import java.util.concurrent.atomic.AtomicReference;
import java.text.SimpleDateFormat;
import java.nio.charset.*;
import java.nio.file.Path;
import java.io.*;
import java.lang.reflect.*;
import java.text.DecimalFormat;
import java.math.*;









public class Solution {
    public static void main(String[] args) throws Exception {
        Main.main(args);
    }
}




class Main {
	public static void main(String[] args) throws Exception {
		Class<? extends AbstractSubmission> clss = TaskA.class;

			new TaskA().runSubmission();

	}
};







@ContestSubmission(ContestType.CODEFORCES)
@CacheVersion(0)
class TaskA extends AbstractSubmission {

	@Override
	public void testCase() {
		int t = sc.nextInt();
		for (int it = 0; it < t; it++) {
			out.println(id28.gcd(sc.nextInt(), sc.nextInt()) == 1 ? "finite" : "infinite");
		}
	}



	@Override
	public void init() {
		


		

		

	}











	


	
	
	
	





	
};



abstract class AbstractSubmission {
	
	public FastScanner sc;
	
	public InputStream in;
	public PrintStream out;
	
	public PrintStream debug;
	public volatile double score = 0;
	public volatile int id5 = -1;
	public volatile int id24;
	
	public volatile double progress = 0;


	public void runSubmission() {
		runSubmission(false);
	}

	public void runSubmission(boolean debug) {
		runSubmission(System.in, System.out, debug);
	}

	public void runSubmission(InputStream in, PrintStream out) {
		runSubmission(in, out,  false);
	}

	public void runSubmission(InputStream in, PrintStream out, boolean debug) {
		runSubmission(in, out,  debug ? System.err : new id25());
	}

	public void runSubmission(InputStream in, OutputStream out, OutputStream debug) {
		this.in = in;
		this.sc = new FastScanner(this.in);
		this.out = new PrintStream(out);
		

		

		this.debug = debug instanceof id23 || debug instanceof id25 ? new id25() : new id26(debug);

		ContestType type = getType();

		id5 = type.id5;

		init();

		if (id5 <= 0) {
			

			id5 = sc.nextInt();
			sc.nextLine();
		}

		id24 = 0;

		

		for (id24 = 1; id24 <= id5; id24++) {
			progress = 0;
			this.out.printf(type.caseString, id24, id5);
			testCase();
		}
	}

	private class id26 extends PrintStream {
		public id26(OutputStream debug) {
			super(debug);
		}

		private Object conv(Object obj) {
			if (obj instanceof byte[]) return Arrays.toString((byte[]) obj);
			else if (obj instanceof char[]) return Arrays.toString((char[]) obj);
			else if (obj instanceof short[]) return Arrays.toString((short[]) obj);
			else if (obj instanceof int[]) return Arrays.toString((int[]) obj);
			else if (obj instanceof long[]) return Arrays.toString((long[]) obj);
			else if (obj instanceof float[]) return Arrays.toString((float[]) obj);
			else if (obj instanceof double[]) return Arrays.toString((double[]) obj);
			else if (obj instanceof boolean[]) return Arrays.toString((int[]) obj);
			else if (obj instanceof Object[]) return Arrays.deepToString((Object[]) obj);
			else return obj;
		}

		@Override
		public void print(Object obj) {
			super.print(conv(obj));
		}

		@Override
		public void println(Object obj) {
			super.println(conv(obj));
		}
	}

	public ContestType getType() {
		return getType(getClass());
	}

	public static ContestType getType(Class<? extends AbstractSubmission> clss) {
		return getAnnotation(clss).value();
	}

	private static ContestSubmission getAnnotation(Class<? extends AbstractSubmission> clss) {
		if (!clss.isAnnotationPresent(ContestSubmission.class)) {
			throw new RuntimeException("ContestSubmission annotation not present on class " + clss.getCanonicalName() + "!");
		}

		return clss.getAnnotation(ContestSubmission.class);
	}

	

	


	



	public abstract void testCase();
	public abstract void init();
};



@Documented
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.TYPE)
@interface CacheVersion {
	int value();
};



@Documented
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.TYPE)
@interface ContestSubmission {
	ContestType value();
};



enum ContestType {
	PLAIN("", -1),
	ETH_JUDGE("", -1, null, false, false, 6),
	GOOGLE("Case 
	GOOGLE_JAM("Case 
	GOOGLE_JAM_INTERACTIVE("", -1, "Solution.java", false, false, 8),
	FACEBOOK("Case 
	BLOOMBERG("", 1, "Problem.java", false, false, 8),
	SINGLE_TESTCASE("", 1),
	OPTIMIZER("", 1, null, false, false, 8, true),
	HACKERRANK("", 1, "Solution.java", false, false, 8),
	CODEFORCES("", 1, "Solution.java", false, false, 8);


	public final int id5;
	public final String caseString;
	public final String launcher;
	public final boolean disableCompression;
	public final boolean id36;
	public final int javaVersion;
	public final boolean isOptimizer;

	ContestType(String caseString, int id5, String launcher, boolean disableCompression, boolean id36, int javaVersion, boolean isOptimizer) {
		this.caseString = caseString;
		this.id5 = id5;
		this.launcher = launcher;
		this.disableCompression = disableCompression;
		this.javaVersion = javaVersion;
		this.id36 = id36;
		this.isOptimizer = isOptimizer;
	}

	ContestType(String a1, int a2, String a3, boolean a4, boolean a5, int a6) { this(a1, a2, a3, a4, a5, a6, false); }
	ContestType(String a1, int a2) {
		this(a1, a2, null, false, false, 8);
	}


};



final class id28 extends Algorithm {
	private id28() {
		

	}

	
	public static Triple<Long, Long, Long> id21(long a, long b) {
		if (b == 0) {
			return new Triple<>(a, 1l, 0l);
		}

		Triple<Long, Long, Long> res = id21(b, a % b);
		long tmp = res.b;
		res.b = res.c;
		res.c = tmp - a / b * res.b;

		return res;
	}

	public static long id4(long a, long b) {
		return gcd(a, b);
	}

	public static long id30(long a, long b) {
		return lcm(a, b);
	}

	public static long gcd(long a, long b) {
		return id21(a, b).a;
	}

	public static long lcm(long a, long b) {
		return Math.multiplyExact(a / gcd(a, b), b);
	}

	public static long id17(long a, long modulo) {
		Triple<Long, Long, Long> result = id21(MathUtils.realMod(a, modulo), modulo);
		if (result.a != 1) throw new IllegalArgumentException("Arguments are not coprime!");
		return result.b;
	}

	public static Pair<Long, Long> id16(int[] a, int[] m) {
		return id16(IntStream.range(0, a.length).mapToObj(i -> new Pair<>(a[i], m[i])).toArray(Pair[]::new));
	}

	public static Pair<Long, Long> id16(long[] a, long[] m) {
		return id16(IntStream.range(0, a.length).mapToObj(i -> new Pair<>(a[i], m[i])).toArray(Pair[]::new));
	}

	public static Pair<Long, Long> id16(Pair<Long, Long> ...equations) {
		if (equations.length == 2) {
			if (Arrays.asList(equations).contains(null)) return null;
			long a = equations[0].a;
			long m = equations[0].b;
			long b = equations[1].a;
			long n = equations[1].b;

			Triple<Long, Long, Long> euclid = id21(m, n);
			long T = euclid.a;						

			long M = Math.multiplyExact(m / T, n);	


			if (MathUtils.realMod(a, T) != MathUtils.realMod(b, T)) return null; 


			a = MathUtils.realMod(a, m);
			b = MathUtils.realMod(b, n);

			long u = euclid.b;
			long v = euclid.c;


			BigInteger bia = BigInteger.valueOf(a);
			BigInteger bib = BigInteger.valueOf(b);
			BigInteger biu = BigInteger.valueOf(u);
			BigInteger biv = BigInteger.valueOf(v);
			BigInteger bim = BigInteger.valueOf(m);
			BigInteger bin = BigInteger.valueOf(n);
			BigInteger biM = BigInteger.valueOf(M);
			BigInteger biT = BigInteger.valueOf(T);
			long res = MathUtils.realMod(bia.multiply(biv).multiply(bin).add(bib.multiply(biu).multiply(bim)).divide(biT).mod(biM).longValueExact(), M);
			return new Pair<>(res, M);
		} else {
			return Arrays.stream(equations).reduce(new Pair<>(0l, 1l), id28::id16);
		}
	}

	private static long id9(long a, long b, long c, long mod) {
		return MathUtils.modMul(MathUtils.modMul(a, b, mod), c, mod);
	}
};



abstract class Algorithm {

	private Object result;
	private boolean end;

	protected Object id1(Runnable runnable) {
		end = false;
		result = null;

		runnable.run();
		return result;
	}


	protected void end() {
		end(null);
	}
	protected void end(Object result) {
		if (shouldEnd()) return;
		this.result = result;
		this.end = true;
	}

	protected boolean shouldEnd() {
		return end;
	}

};




class FastScanner {
	private static final String id32 = " \t\n\r\f";
	private BufferedReader buffer;
	private StringTokenizer tokenizer;
	private final InputStream stream;

	public FastScanner(InputStream stream) {
		this.stream = stream;
	}

	public String nextLine() {
		if (this.buffer == null) this.buffer = new BufferedReader(new InputStreamReader(stream));
		while (tokenizer == null) {
			try {
				tokenizer = new StringTokenizer(buffer.readLine() + "\n");
			} catch (IOException e) {
				throw new RuntimeException("IO exception occured!", e);
			}
		}
		String res = tokenizer.nextToken("");

		if (!res.endsWith("\n")) throw new RuntimeException("waddaheq just heppenenened");
		res = res.substring(0, res.length() - 1);
		if (res.contains("\n")) throw new RuntimeException("oke wat lamo");

		tokenizer = null;
		return res;
	}

	public String next() {
		if (this.buffer == null) this.buffer = new BufferedReader(new InputStreamReader(stream));
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(buffer.readLine() + "\n");
			} catch (IOException e) {
				throw new RuntimeException("IO exception occured!", e);
			}
		}
		return tokenizer.nextToken(id32);
	}

	public BigDecimal id31() {
		return new BigDecimal(next());
	}

	public BigInteger id3() {
		return new BigInteger(next());
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

};




final class MathUtils {
	private MathUtils() {
		

	}

	public static int[] id22(int i, int[] max) {
		int[] res = new int[max.length];
		for (int j = max.length - 1; j >= 0; j--) {
			res[j] = i % max[j];
			i /= max[j];
		}
		return res;
	}

	public static int id13(int[] arr, int[] max) {
		int result = 0;
		for (int i = 0; i < max.length; i++) {
			result *= max[i];
			result += arr[i];
		}
		return result;
	}

	
	public static int foldl(IntBinaryOperator operator, int... vals) {
		int result = vals[0];
		for (int i = 1; i < vals.length; i++) {
			result = operator.applyAsInt(result, vals[i]);
		}
		return result;
	}

	public static int min(int a, int b) {
		return Math.min(a, b);
	}

	public static int max(int a, int b) {
		return Math.max(a, b);
	}

	public static int min(int a, int b, int c) {
		return Math.min(a, Math.min(b, c));
	}

	public static int max(int a, int b, int c) {
		return Math.max(a, Math.max(b, c));
	}

	public static int min(int... vals) {
		return foldl(Math::min, vals);
	}

	public static int max(int... vals) {
		return foldl(Math::max, vals);
	}
	

	public static int sum(int... vals) {
		int result = 0;
		for (int v : vals) {
			result += v;
		}
		return result;
	}

	public static int prod(int... vals) {
		int result = 1;
		for (int v : vals) {
			result *= v;
		}
		return result;
	}

	public static int factorial(int n) {
		if (n <= 1) return 1;
		return n * factorial(n - 1);
	}

	public static boolean doubleEquals(double a, double b) {
		return a == b || (Double.isNaN(a) && Double.isNaN(b));
	}

	public static int pow(int a, int exponent) {
		if (exponent < 0) return 0;
		if (exponent == 0) return 1;
		if ((a & (a - 1)) == 0) return a << (exponent - 1);
		if (exponent % 2 == 0) return sq(pow(a, exponent / 2));
		return pow(a, exponent - 1) * a;
	}

	public static long pow(long a, long exponent) {
		if (a == 2) return 1l << exponent;
		if (exponent < 0) return 0;
		if (exponent == 0) return 1;
		if (exponent % 2 == 0) return sq(pow(a, exponent / 2));
		return pow(a, exponent - 1) * a;
	}

	public static double pow(double a, double exponent) {
		return Math.pow(a, exponent);
	}

	public static int sq(int a) {
		return a*a;
	}

	public static long sq(long a) {
		return a*a;
	}

	public static double sq(double a) {
		return a*a;
	}


	
	public static int realMod(int i, int mod) {
		return MathUtils.floorMod(i, mod);
	}

	
	public static long realMod(long i, long mod) {
		return MathUtils.floorMod(i, mod);
	}

	public static int floorDiv(int a, int b) {
		return Math.floorDiv(a, b);
	}

	public static long floorDiv(long a, long b) {
		return Math.floorDiv(a, b);
	}

	public static int floorMod(int a, int b) {
		return Math.floorMod(a, b);
	}

	public static long floorMod(long a, long b) {
		return Math.floorMod(a, b);
	}

	public static int ceilDiv(int a, int b) {
		return Math.floorDiv(a + b - 1, b);
	}

	public static long ceilDiv(long a, long b) {
		return Math.floorDiv(a + b - 1, b);
	}

	public static int ceilMod(int a, int b) {
		return a - ceilDiv(a, b) * b;
	}

	public static long ceilMod(long a, long b) {
		return a - ceilDiv(a, b) * b;
	}

	
	public static long modMul(long a, long b, long mod) {
		a = realMod(a, mod);
		if (a == 0) return 0;
		b = realMod(b, mod);
		if (b <= Long.MAX_VALUE / a) {
			return MathUtils.realMod(a * b, mod);
		}
		return BigInteger.valueOf(a).multiply(BigInteger.valueOf(b)).mod(BigInteger.valueOf(mod)).longValueExact();
	}

	
	public static long modAdd(long a, long b, long mod) {
		a = realMod(a, mod);
		b = realMod(b, mod);
		return realMod(a - mod + b, mod);
	}
};



@Documented
@Retention(RetentionPolicy.SOURCE)
@Target(ElementType.METHOD)
@interface O {
	String value();
};




@Target(ElementType.FIELD)
@Retention(RetentionPolicy.RUNTIME)
@interface Optimize {
	long imin() default 0;
	long imax() default 100;
	double fmin() default 0;
	double fmax() default 1;
};



class Pair<A, B> extends Tuple implements Map.Entry<A, B> {

	public A a;
	public B b;

	public Pair(A a, B b) {
		this.a = a;
		this.b = b;
	}

	public A getLeft() {
		return a;
	}

	public B getRight() {
		return b;
	}

	public void setLeft(A a) {
		this.a = a;
	}

	public void setRight(B b) {
		this.b = b;
	}

	public <A1, B1> Pair<A1, B1> map(Function<A, A1> mapA, Function<B, B1> mapB) {
		return new Pair<>(mapA.apply(this.a), mapB.apply(this.b));
	}

	@Override
	public A getKey() {
		return a;
	}

	public A setKey(A a) {
		A old = this.a;
		this.a = a;
		return old;
	}

	@Override
	public B getValue() {
		return b;
	}

	@Override
	public B setValue(B b) {
		B old = this.b;
		this.b = b;
		return old;
	}

	@Override
	public Object[] toArray() {
		return new Object[] {a, b};
	}

	@Override
	public boolean equals(Object other) {
		if (!(other instanceof Pair)) return super.equals(other);
		Pair pair = (Pair) other;
		return Objects.equals(this.a, pair.a) && Objects.equals(this.b, pair.b);
	}

	@Override
	public int hashCode() {
		return 961 + 31 * Objects.hashCode(a) + Objects.hashCode(b);
	}
};



class Triple<A, B, C> extends Tuple {

	public A a;
	public B b;
	public C c;

	public Triple(A a, B b, C c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}

	public A getLeft() {
		return a;
	}

	public B getMiddle() {
		return b;
	}

	public C getRight() {
		return c;
	}

	public void setLeft(A a) {
		this.a = a;
	}

	public void setMiddle(B b) {
		this.b = b;
	}

	public void setRight(C c) {
		this.c = c;
	}

	public <A1, B1, C1> Triple<A1, B1, C1> map(Function<A, A1> mapA, Function<B, B1> mapB, Function<C, C1> mapC) {
		return new Triple<>(mapA.apply(this.a), mapB.apply(this.b), mapC.apply(this.c));
	}



	@Override
	public Object[] toArray() {
		return new Object[] {a, b, c};
	}

};



abstract class Tuple extends Structure {

	public abstract Object[] toArray();


	@Override
	public boolean equals(Object obj) {
		if (obj == null) return false;
		if (!(obj instanceof Tuple)) return false;

		return Arrays.equals(this.toArray(), ((Tuple) obj).toArray());
	}

	@Override
	public int hashCode() {
		return Arrays.hashCode(this.toArray());
	}

	@Override
	public String toString() {
		Object[] els = toArray();
		String[] elements = new String[els.length];
		for (int i = 0; i < els.length; i++) {
			elements[i] = "" + els[i];
		}
		return "(" + String.join(", ", elements) + ")";
	}
};




abstract class Structure implements Serializable, Cloneable {

	@Override
	public Structure clone() {
		try {
			Structure struct = (Structure) super.clone();
			for (Field field : this.getClass().getDeclaredFields()) {
				field.setAccessible(true);
				if (Modifier.isTransient(field.getModifiers())) {
					continue;
				}
				field.set(struct, field.get(this));
			}
			return struct;
		} catch (CloneNotSupportedException e) {
			

			throw new AssertionError("Cloning a structure should always be supported - please report this bug", e);
		} catch (IllegalAccessException e) {
			throw new RuntimeException("Can't access my own elements!", e);
		}
	}


	private NavigableMap<String, Object> getFields() {
		try {
			NavigableMap<String, Object> result = new TreeMap<String, Object>();
			for (Field field : this.getClass().getFields()) {
				if (Modifier.isTransient(field.getModifiers())) {
					continue;
				}
				result.put(field.getName(), field.get(this));
			}
			return result;
		} catch (IllegalAccessException e) {
			throw new RuntimeException("Can't access my own elements!", e);
		}
	}




	@Override
	public boolean equals(Object obj) {
		if (obj == null) return false;
		if (getClass() != obj.getClass()) return false;

		return getFields().equals(((Structure) obj).getFields());
	}

	@Override
	public int hashCode() {
		return getFields().hashCode();
	}


	@Override
	public String toString() {
		return getFields().toString();
	}


};



class Tree<T> implements Serializable {
	private TreeNode<T> root;
	final Pair<Double, DoubleBinaryOperator> distanceFolder;

	public Tree(T rootValue) {
		this(rootValue, null);
	}

	public Tree(T rootValue, Pair<Double, DoubleBinaryOperator> distanceFolder) {
		this(distanceFolder);
		initRoot(new TreeNode(rootValue, this));
	}

	protected Tree() {
		this((Pair<Double, DoubleBinaryOperator>) null);
	}

	protected Tree(Pair<Double, DoubleBinaryOperator> distanceFolder) {
		this.distanceFolder = distanceFolder == null ? new Pair<>(0.0, Double::sum) : distanceFolder;
	}

	protected void initRoot(TreeNode<T> node) {
		if (root != null) throw new IllegalStateException("Can't modify the root after it has already been initialized!");
		this.root = node;
	}

	public TreeNode<T> getRoot() {
		return root;
	}

	@Override
	public String toString() {
		return root.toString();
	}
};



class TreeNode<T> implements Serializable {
	private T value;
	private int height;
	private double distance;
	private double id12;
	private List<TreeNode<T>> children;
	private TreeNode<T> parent;
	private Tree<T> tree;

	public TreeNode(T value) {
		this(value, null);
	}

	protected TreeNode(T value, Tree<T> tree) {
		this.value = value;
		this.parent = null;
		this.tree = tree;
		this.children = new ArrayList<>(5);
		this.height = 0;
		this.distance = tree.distanceFolder.a;
	}

	protected TreeNode(T value, TreeNode<T> parent, double id12) {
		this.value = value;
		this.parent = parent;
		this.tree = parent.tree;
		this.children = new ArrayList<>();
		this.height = parent.getHeight() + 1;
		this.id12 = id12;
		this.distance = tree.distanceFolder.b.applyAsDouble(parent.getDistance(), id12);
	}

	public T getValue() {
		return value;
	}

	public void setValue(T value) {
		this.value = value;
	}

	public int getHeight() {
		return height;
	}

	public double getDistance() {
		return distance;
	}

	public double id14() {
		if (!hasParent()) throw new NoSuchElementException("Node has no parent!");
		return this.id12;
	}

	public List<TreeNode<T>> getChildren() {
		return this.children.size() == 0 ? Collections.emptyList() : Collections.unmodifiableList(children);
	}

	public int id29() {
		return children.size();
	}

	public TreeNode<T> addChild(T value) {
		return addChild(value, 1);
	}

	public TreeNode<T> addChild(T value, double distance) {
		return id33(value, distance).attach();
	}

	public TreeNode<T>.Unattached id33(T value, double distance) {
		return new Unattached(value, distance);
	}

	class Unattached extends TreeNode<T> {
		private boolean isAttached = false;

		private Unattached(T value, double distance) {
			super(value, TreeNode.this, distance);
		}

		public TreeNode<T> attach() {
			if (isAttached()) throw new NoSuchElementException("Node has already been attached!");
			TreeNode.this.children.add(this);
			isAttached = true;
			return this;
		}

		@Override
		public boolean isAttached() {
			return isAttached;
		}
	}

	public TreeNode<T> getParent() {
		return parent;
	}

	public List<TreeNode<T>> id8() {
		List<TreeNode<T>> res = new ArrayList<>();
		TreeNode<T> node = this;
		while ((node = node.getParent()) != null) {
			res.add(node);
		}
		Collections.reverse(res);
		return res;
	}

	public boolean hasParent() {
		return getParent() != null;
	}

	public Tree<T> getTree() {
		return tree;
	}

	public boolean isAttached() {
		return true;
	}


	@Override
	public String toString() {
		return value.toString() + (children.isEmpty() ? "" : children.toString());
	}
};



final class Utils {
	private Utils() {
		

	}


	
	public static void repeat(int times, Consumer<Integer> consumer) {
		for (int i = 0; i < times; i++) {
			consumer.accept(i);
		}
	}

	public static void repeat(int times, Runnable runnable) {
		repeat(times, (a) -> runnable.run());
	}


	
	public static <E extends Throwable> double timing(id15<E> runnable) throws E {
		long start = System.nanoTime();
		runnable.run();
		long end = System.nanoTime();
		return (end - start) / 1_000_000_000.0;
	}

	private static int id18 = 0;
	
	public static <T, E extends Throwable> T printTiming(id10<T, E> supplier, String name) throws E {
		int tid = id18++;
		if (name == null) name = "" + tid;
		else name = tid + " - " + name;
		System.err.println("Starting task " + name);
		long start = System.nanoTime();
		try {
			return supplier.get();
		} finally {
			long end = System.nanoTime();
			System.err.println("Time taken for task " + name + ": " + (end - start) / 1_000_000_000.0 + "s");
		}
	}

	
	public static <E extends Throwable> void printTiming(id15<E> runnable, String name) throws E {
		printTiming(() -> {
			runnable.run();
			return null;
		}, name);
	}

	
	public static <E extends Throwable> void printTiming(id15<E> runnable) throws E {
		printTiming(runnable, null);
	}

	
	public static <T, E extends Throwable> T printTiming(id10<T, E> supplier) throws E {
		return printTiming(supplier, null);
	}
	




	public static <T> ArrayList<T> id2(Iterable<T> iterable) {
		int size = iterable instanceof Collection ? ((Collection) iterable).size() : -1;
		return id2(iterable, size);
	}

	public static <T> ArrayList<T> id2(Iterable<T> iterable, int size) {
		return id2(iterable.iterator(), size);
	}


	public static <T> ArrayList<T> id2(Iterator<T> iterator) {
		return id2(iterator, -1);
	}

	public static <T> ArrayList<T> id2(Iterator<T> iterator, int estimatedSize) {
		return id2(Spliterators.spliterator(iterator, estimatedSize, Spliterator.ORDERED));
	}

	public static <T> ArrayList<T> id2(Spliterator<T> spliterator) {
		long estimatedSize = spliterator.estimateSize();
		if (estimatedSize >= Long.MAX_VALUE || estimatedSize <= 10) estimatedSize = 10;
		ArrayList<T> result = new ArrayList<>((int) Math.min(estimatedSize, Integer.MAX_VALUE));
		spliterator.forEachRemaining(result::add);
		return result;
	}


	public static IntStream stream(PrimitiveIterator.OfInt iterator) {
		return stream(iterator, -1);
	}

	public static IntStream stream(PrimitiveIterator.OfInt iterator, int estimatedSize) {
		return stream(Spliterators.spliterator(iterator, estimatedSize, Spliterator.ORDERED));
	}

	public static IntStream stream(Spliterator.OfInt spliterator) {
		return StreamSupport.intStream(spliterator, false);
	}


	public static LongStream stream(PrimitiveIterator.OfLong iterator) {
		return stream(iterator, -1);
	}

	public static LongStream stream(PrimitiveIterator.OfLong iterator, int estimatedSize) {
		return stream(Spliterators.spliterator(iterator, estimatedSize, Spliterator.ORDERED));
	}

	public static LongStream stream(Spliterator.OfLong spliterator) {
		return StreamSupport.longStream(spliterator, false);
	}

	public static <T> Stream<T> stream(Iterator<T> iterator) {
		return stream(iterator, -1);
	}

	public static <T> Stream<T> stream(Iterator<T> iterator, int estimatedSize) {
		return stream(Spliterators.spliterator(iterator, estimatedSize, Spliterator.ORDERED));
	}

	public static <T> Stream<T> stream(Spliterator<T> spliterator) {
		return StreamSupport.stream(spliterator, false);
	}


	
	public static <T> Map<T, Set<Integer>> invert(Collection<T> coll) {
		Map<T, Set<Integer>> map = new HashMap<>();
		int i = 0;
		for (T t : coll) {
			Set<Integer> set = map.get(t);
			if (set == null) {
				map.put(t, Collections.singleton(i));
			} else {
				if (!(set instanceof LinkedHashSet)) {
					set = new LinkedHashSet<>(set);
					map.put(t, set);
				}
				set.add(i);
			}
			i++;
		}
		return Collections.unmodifiableMap(map);
	}




	public static <T> ArrayList<T> id6(int size) {
		return id6(size, null);
	}

	public static <T> ArrayList<T> id6(int size, T element) {
		ArrayList<T> result = new ArrayList<T>(size);
		for (int i = 0; i < size; i++) {
			result.add(element);
		}
		return result;
	}


	public static <T> int hashAll(Iterator<T> iterator) {
		int hash = 1;
		while (iterator.hasNext()) {
			T obj = iterator.next();
			hash = hash * 31 + Objects.hashCode(obj);
		}
		return hash;
	}


	
	public static <T> Set<T> asSet(Collection<T> uniqueElements) {
		return id7(Collections.unmodifiableCollection(uniqueElements));
	}

	
	public static <T> Set<T> id7(Collection<T> uniqueElements) {
		return new AbstractSet<T>() {
			@Override
			public int size() {
				return uniqueElements.size();
			}

			@Override
			public boolean isEmpty() {
				return uniqueElements.isEmpty();
			}

			@Override
			public boolean contains(Object o) {
				return uniqueElements.contains(o);
			}

			@Override
			public Iterator<T> iterator() {
				return uniqueElements.iterator();
			}

			@Override
			public Object[] toArray() {
				return uniqueElements.toArray();
			}

			@Override
			public <T1> T1[] toArray(T1[] a) {
				return uniqueElements.toArray(a);
			}

			@Override
			public boolean add(T t) {
				return uniqueElements.add(t);
			}

			@Override
			public boolean remove(Object o) {
				return uniqueElements.remove(o);
			}

			@Override
			public boolean containsAll(Collection<?> c) {
				return uniqueElements.containsAll(c);
			}

			@Override
			public boolean addAll(Collection<? extends T> c) {
				return uniqueElements.addAll(c);
			}

			@Override
			public boolean retainAll(Collection<?> c) {
				return uniqueElements.retainAll(c);
			}

			@Override
			public boolean removeAll(Collection<?> c) {
				return uniqueElements.removeAll(c);
			}

			@Override
			public void clear() {
				uniqueElements.clear();
			}
		};
	}

	
	public static <T> Collector<T, ?, Set<T>> id11() {
		return Collectors.collectingAndThen(Collectors.toList(), Utils::asSet);
	}

	
	public static <T> ListIterator<T> reverseIterator(List<T> list) {
		return reverseIterator(list.listIterator(list.size()));
	}

	
	public static <T> ListIterator<T> reverseIterator(ListIterator<T> it) {
		return new ListIterator<T>() {
			@Override
			public boolean hasNext() {
				return it.hasPrevious();
			}

			@Override
			public T next() {
				return it.previous();
			}

			@Override
			public boolean hasPrevious() {
				return it.hasNext();
			}

			@Override
			public T previous() {
				return it.next();
			}

			@Override
			public int nextIndex() {
				return it.previousIndex();
			}

			@Override
			public int previousIndex() {
				return it.nextIndex();
			}

			@Override
			public void remove() {
				it.remove();
			}

			@Override
			public void set(T t) {
				it.set(t);
			}

			@Override
			public void add(T t) {
				it.add(t);
			}
		};
	}

	
	public static Runnable id34(id15<?> r) {
		return () -> {
			try {
				r.run();
			} catch (Throwable e) {
				throw new RuntimeException(e);
			}
		};
	}

	
	public static <T> Supplier<T> id34(id10<T, ?> r) {
		return () -> {
			try {
				return r.get();
			} catch (Throwable e) {
				throw new RuntimeException(e);
			}
		};
	}

	
	public static <T, R> Function<T, R> id34(id27<T, R, ?> r) {
		return (a) -> {
			try {
				return r.apply(a);
			} catch (Throwable e) {
				throw new RuntimeException(e);
			}
		};
	}



	
	public static <T> Iterable<T> reverseIterable(List<T> list) {
		return () -> reverseIterator(list);
	}




	private static final Map<Class, Class> id0 = new HashMap<Class, Class>() {{
		put(boolean.class, Boolean.class);
		put(byte.class, Byte.class);
		put(short.class, Short.class);
		put(char.class, Character.class);
		put(int.class, Integer.class);
		put(long.class, Long.class);
		put(float.class, Float.class);
		put(double.class, Double.class);
	}};
	public static Class<?> id20(Class<?> clss) {
		return id0.getOrDefault(clss, clss);
	}

};



class ArrayUtils {
	public static long[] id19(byte[] arr) {
		return asList(arr).stream().mapToLong(a -> a).toArray();
	}

	public static long[] id19(short[] arr) {
		return asList(arr).stream().mapToLong(a -> a).toArray();
	}

	public static long[] id19(char[] arr) {
		return asList(arr).stream().mapToLong(a -> a).toArray();
	}

	public static long[] id19(int[] arr) {
		return Arrays.stream(arr).mapToLong(a -> a).toArray();
	}

	public static List<Byte> asList(byte[] arr) {
		return new id35<>(arr);
	}

	public static List<Character> asList(char[] arr) {
		return new id35<>(arr);
	}

	public static List<Short> asList(short[] arr) {
		return new id35<>(arr);
	}

	public static List<Integer> asList(int[] arr) {
		return new id35<>(arr);
	}

	public static List<Boolean> asList(boolean[] arr) {
		return new id35<>(arr);
	}

	public static List<Float> asList(float[] arr) {
		return new id35<>(arr);
	}

	public static List<Double> asList(double[] arr) {
		return new id35<>(arr);
	}

	public static List<Long> asList(long[] arr) {
		return new id35<>(arr);
	}

	public static <T> List<T> asList(T[] arr) {
		return Arrays.asList(arr);
	}


	private static class id35<T, A> extends AbstractList<T> {
		private final A arr;
		private final int length;
		public id35(A arr) {
			this.arr = arr;
			this.length = java.lang.reflect.Array.getLength(arr);
		}

		@Override
		public T get(int index) {
			return (T) java.lang.reflect.Array.get(arr, index);
		}

		@Override
		public T set(int index, T val) {
			T oldValue = get(index);
			java.lang.reflect.Array.set(arr, index, val);
			return oldValue;
		}

		@Override
		public int size() {
			return length;
		}
	}




};



@FunctionalInterface
interface id27<T, R, E extends Throwable> {
	R apply(T t) throws E;
};



@FunctionalInterface
interface id15<E extends Throwable> {
	void run() throws E;
};



@FunctionalInterface
interface id10<T, E extends Throwable> {
	T get() throws E;
};



final class id23 extends OutputStream {
	@Override
	public void write(int b) {
		return;
	}

	@Override
	public void write(byte b[]) {
		return;
	}

	@Override
	public void write(byte b[], int off, int len) {
		return;
	}

};



final class id25 extends PrintStream {
	public id25() {
		super(new id23());
	}

	@Override
	public void write(int b) {
		return;
	}

	@Override
	public void print(char[] buf) {
		return;
	}

	@Override
	public void print(String s) {
		return;
	}

	@Override
	public void print(Object obj) {
		return;
	}

	@Override
	public void println(char[] buf) {
		return;
	}

	@Override
	public void println(String s) {
		return;
	}

	@Override
	public void println(Object obj) {
		return;
	}

	@Override
	public PrintStream format(Locale l, String s, Object... objs) {
		return this;
	}

	@Override
	public PrintStream format(String s, Object... objs) {
		return this;
	}



};