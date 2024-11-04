import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Random;
import java.util.StringTokenizer;

public class C implements CodeforcesSolver {

	private static final Sort SORT = new QuickSort();
	private static final Float64NumberSystem NS = Float64NumberSystem.getInstance();
	private static final Point2D<Float64> ORIGIN = Point2D.create(NS.getZero(), NS.getZero());

	public void solve(InputStream is) {
		FastScanner in = new FastScanner(is);
		double w = in.nextDouble();
		double h = in.nextDouble();
		double a= in.nextDouble();
		
		if(a % 180 == 0) {
			System.out.println(w*h);
		} else if(a % 90 == 0) {
			System.out.println(DoubleSquare.calc(Math.min(w,h)));
		} else {
			DynamicArray<Point2D<Float64>> points = DynamicArray.create();
			points.addToLast(toPoint(w/2, h/2));
			points.addToLast(toPoint(-w/2, h/2));
			points.addToLast(toPoint(-w/2, -h/2));
			points.addToLast(toPoint(w/2, -h/2));
			
			DynamicArray<Point2D<Float64>> intersects = DynamicArray.create();
			for(int i=0;i<4;i++) { 
				Segment2D<Float64> s1 = Segment2D.create(points.get(i), points.get((i+1)%4));
				for(int j=0;j<4;j++) {
					Segment2D<Float64> s2 = Segment2D.create(rotate(points.get(j), a), rotate(points.get((j+1)%4), a));
					Point2D<Float64> inter = IntersectionOfNonParallelSegments.calc(NS, s1, s2, null);
					if(inter != null)
						intersects.addToLast(inter);
				}
			}
			
			SORT.sort(intersects, DirectionComparator.create(NS, ORIGIN, ArrayUtil.getFirst(intersects)));
			Polygon2D<Float64> polygon = Polygon2D.create(intersects);
			Float64 area = AreaOfSimplePolygon2D.calc(NS, polygon);
			System.out.format("%.20f", area.toPrimitive());
		}
	}

	private Point2D<Float64> toPoint(double x, double y) {
		return Point2D.create(Float64.valueOf(x), Float64.valueOf(y));
	}

	private Point2D<Float64> rotate(Point2D<Float64> p, double deg) {
		return calcLeftRotatedPoint(p, Angle.create(Math.toRadians(deg)));
	}

	private static Point2D<Float64> calcLeftRotatedPoint(Point2D<Float64> p, Angle a) {
		Azimuth am = Azimuth.create(AzimuthFromOrigin.calc(p).radian() + a.radian());
		double dis = DistanceBetweenPointOrigin.calc(p);
		return PointByDistanceAzimuth.calc(dis, am);
	}

	public static void main(String[] args) throws Exception {
		CodeforcesSolverLauncher.launch(new CodeforcesSolverFactory() {
			public CodeforcesSolver create() {
				return new C();
			}
		}, "C1.txt", "C2.txt", "C3.txt");
	}

}

interface CodeforcesSolver {
	void solve(InputStream is); 
}

interface CodeforcesSolverFactory {
	CodeforcesSolver create();
}

class CodeforcesSolverLauncher {

	public static void launch(CodeforcesSolverFactory factory, String... inputFilePath) throws FileNotFoundException, IOException {
		if(System.getProperty("ONLINE_JUDGE", "false").equals("true")) {
			factory.create().solve(System.in);
		} else { 
			for(String path : inputFilePath) {
				FileInputStream is = new FileInputStream(new File(path));
				factory.create().solve(is);
				is.close();
				System.out.println();
			}
		}
	}

}

class FastScanner {
	
	private StringTokenizer tokenizer;

	public FastScanner(InputStream is) {
		try {
			ByteArrayOutputStream bos = new ByteArrayOutputStream(1024*1024);
			byte[] buf = new byte[1024*1024];
			while(true) {
				int read = is.read(buf);
				if(read == -1)
					break;
				bos.write(buf, 0, read);
			}
			tokenizer = new StringTokenizer(new String(bos.toByteArray()));
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
	
	public int nextInt() {
		return Integer.parseInt(tokenizer.nextToken());
	}
	
	public long nextLong() {
		return Long.parseLong(tokenizer.nextToken());
	}
	
	public double nextDouble() {
		return Double.parseDouble(tokenizer.nextToken());
	}
	
	public String next() {
		return tokenizer.nextToken();
	}

}

class DoubleSquare {

	public static double calc(double a) {
		return a*a;
	}

}

class QuickSort implements Sort {
	
	private static Random RANDOM = new Random();

	

	
	public <T> void sort(MutableArray<T> a, Comparator<T> comparator) {
		sort(a, 0, a.size()-1, comparator);		
	}

	public <T> void sort(MutableArray<T> list, int start, int end, Comparator<T> comparator) {
		if(start < end) {
			ArraySwapper.swap(list, start, RANDOM.nextInt(end-start) + start + 1);
			int pos = start;
			for(int i=start+1;i<=end;i++) {
				int c = comparator.compare(list.get(i), list.get(start)); 
				if(c < 0 || c == 0 && i%2==0)
					ArraySwapper.swap(list, i,++pos);
			}
			ArraySwapper.swap(list, start, pos);
			sort(list, start,pos-1, comparator);
			sort(list, pos+1, end, comparator);
		}
	}
	
}

class ArraySwapper {
	
	public static <T> void swap(MutableArray<T> a, int p1, int p2) {
		T t = a.get(p1);
		a.set(p1, a.get(p2));
		a.set(p2, t);
	}
}

interface MutableArray<T> extends Array<T> {
	void set(int index, T value);	
}

interface Array<T> extends Collection<T> {
	T get(int index);
}

interface Collection<T> extends Iterable<T> {
	int size();
	boolean isEmpty();
}

interface Sort {
	<T> void sort(MutableArray<T> a, Comparator<T> comparator);
}

class ArrayUtil {

	public static <T> T getLast(Array<T> a) { 

		return a.get(a.size()-1);
	}

	public static <T> T getFirst(Array<T> a) { 

												

		return a.get(0);
	}

}

class DynamicArray<T> implements MutableArray<T>, EqualityTester<DynamicArray<T>> {
	
	public static <T> DynamicArray<T> create() {
		return new DynamicArray<T>();
	}
	
	private T[] a;
	private int asize;
	
	@SuppressWarnings("unchecked")
	public DynamicArray() {
		asize = 0;
		a = (T[])new Object[1];
	}

	public T get(int index) {
		return a[index];
	}	
	
	public void set(int index, T value) {
		a[index] = value;		
	}
	
	public int size() {
		return asize;
	}
	
	public void clear() {
		asize = 0;
	}
	
	@SuppressWarnings("unchecked")
	public void reserve(int size) {
		if(a.length < size) {
			T[] na = (T[])new Object[size];
			for(int i=0;i<a.length;i++)
				na[i] = a[i];
			a = na;
		}
	}
	
	@SuppressWarnings("unchecked")
	public void addToLast(T value) {
		if(a.length == asize) {
			T[] ta = (T[])new Object[asize*2];
			for(int i=0;i<asize;i++)
				ta[i] = a[i];
			a =ta;
		}
		a[asize++] = value;						
	}
	
	public void addToLastAll(Iterable<? extends T> values) {
		DynamicArrayUtil.addToLast(this, values);
	}

	public T removeLast() {
		T r = ArrayUtil.getLast(this);
		a[--asize] = null;
		return r;
	}
	
	public boolean equals(Object obj) {
		return StrictEqualityTester.areEqual(this, obj, this);
	}

	public boolean areEqual(DynamicArray<T> o1, DynamicArray<T> o2) {
		if(o1.size() != o2.size())
			return false;
		for(int i=0;i<o1.size();i++)
			if(!o1.get(i).equals(o2.get(i)))
				return false;		
		return true;
	}

	public int hashCode() {
		int r = 0;
		for(int i=0;i<size();i++)
			r ^= ThomasWangHash.hash32bit(get(i).hashCode());
		return r;
	}

	public final boolean isEmpty() {
		return size() == 0;
	}

	public final Iterator<T> iterator() {
		return ArrayIterator.create(this);
	}

	public final String toString() {
		return IterableToString.toString(this);
	}
	
}

interface EqualityTester<T> {
	boolean areEqual(T o1, T o2);
}

class IterableToString {
	public static <T> String toString(Iterable<T> iterable) {
		StringBuilder sb = new StringBuilder();
		sb.append('(');
		boolean first = true;
		for(T v : iterable) {
			if(first)
				first = false;
			else
				sb.append(',');
			sb.append(v);
		}
		sb.append(')');
		return sb.toString();
	}
}

class StrictEqualityTester {
	@SuppressWarnings("unchecked")
	public static <T> boolean areEqual(T me, Object you, EqualityTester<T> tester) {
		if(me == you)
			return true;
		if(you == null)
			return false;
		if(you.getClass() != me.getClass())
			return false;
		return tester.areEqual(me, (T)you);
	}
}

class ThomasWangHash {
	
	

	
	public static int hash32bit(int key) {
		key = ~key + (key << 15); 

		key = key ^ (key >>> 12);
		key = key + (key << 2);
		key = key ^ (key >>> 4);
		key = key * 2057; 

		key = key ^ (key >>> 16);
		return key;
	}

	public static int hash64bit(long key) { 
		key = (~key) + (key << 18); 

		key = key ^ (key >>> 31);
		key = key * 21; 

		key = key ^ (key >>> 11);
		key = key + (key << 6);
		key = key ^ (key >>> 22);
		return (int) key;
	}
}

class ArrayIterator {
	public static <T> Iterator<T> create(final Array<T> a) {
		return new ReadOnlyIterator<T>() {
			int p = 0;
			public boolean hasNext() {
				return p < a.size();
			}
			public T next() {
				return a.get(p++);
			}
		};
	}

	private ArrayIterator() {
	}
}

abstract class ReadOnlyIterator<T> implements Iterator<T> {
	public final void remove() {
		throw new UnsupportedOperationException();
	}
}

class DynamicArrayUtil {

	public static <T> void addToLast(DynamicArray<T> dynamicArray, Iterable<? extends T> values) {
		for (T v : values)
			dynamicArray.addToLast(v);
	}

}

class AreaOfSimplePolygon2D {
	
	


	public static <T> T calc(DivisableNumberSystem<T> ns, Polygon2D<T> sp) {
		T two = ns.add(ns.getOne(), ns.getOne());
		return ns.divide(calcDouble(ns, sp), two);
	}

	private static <T> T calcDouble(MultipliableNumberSystem<T> ns, Polygon2D<T> sp) {
		T total = ns.getZero();
		for (int i : ZeroTo.get(sp.pointNumber())) {
			Point2D<T> p1 = sp.get(i);
			Point2D<T> p2 = sp.get((i + 1) % sp.pointNumber());
			total = ns.add(total, ns.subtract(ns.multiply(p1.x(), p2.y()), ns.multiply(p1.y(), p2.x())));
		}
		return Abs.calc(ns, total);
	}

}

class ZeroTo {

	public static Iterable<Integer> get(int end) {
		return FromTo.get(0, end);
	}
	
}

class FromTo {

	public static Iterable<Integer> get(int begin, int end) {
		return IntSequenceIterable.create(begin, 1, end-begin);
	}

}

class IntSequenceIterable {
	public static Iterable<Integer> create(final int from, final int step, final int size) {
		return new Iterable<Integer>() {
			public Iterator<Integer> iterator() {
				return new ReadOnlyIterator<Integer>() {
					int nextIndex = 0;
					public boolean hasNext() {
						return nextIndex < size;
					}
					public Integer next() {
						return from + step * (nextIndex++);
					}
				};
			}
		};
	}

	private IntSequenceIterable() {
	}
}

class Abs {
	

	public static <T> T calc(AddableNumberSystem<T> ns, T v) {
		if (ns.isNegative(v))
			return AddInvert.calc(ns, v);
		return v;
	}
}

class AddInvert {

	public static <T> T calc(AddableNumberSystem<T> ns, T v) {
		return ns.subtract(ns.getZero(), v);
	}

}

interface AddableNumberSystem<T> extends NumberSystem<T> {
	T add(T v1, T v2);
	T subtract(T minuend, T subtrahend);
	T getZero();
	boolean isPositive(T v);
	boolean isZero(T v);
	boolean isNegative(T v);
	int getSign(T v);
}

interface NumberSystem<T> extends EqualityTester<T>, Comparator<T> {

}

class Point2D<T> implements EqualityTester<Point2D<T>> {

	public static <T> Point2D<T> create(T x, T y) {
		return new Point2D<T>(x, y); 
	}
	
	private final T x;
	private final T y;
	
	private Point2D(T x, T y) {
		this.x = x;
		this.y = y;
	}

	public T x() {
		return x;
	}
	
	public T y() {
		return y;
	}

	public final boolean equals(Object o) {
		return StrictEqualityTester.areEqual(this, o, this);
	}

	public boolean areEqual(Point2D<T> o1, Point2D<T> o2) {
		return o1.x.equals(o2.x) && o1.y.equals(o2.y);
	}

	public final int hashCode() {
		return x.hashCode() ^ y.hashCode();
	}
	
	public String toString() {
		return "(" + x + "," + y + ")";
	}
	
}

class Polygon2D<T> implements EqualityTester<Polygon2D<T>> {
	
	public static <T> Polygon2D<T> create(Iterable<Point2D<T>> src) {
		return new Polygon2D<T>(src);
	}

	private final DynamicArray<Point2D<T>> points = DynamicArray.create();
	
	private Polygon2D(Iterable<Point2D<T>> src) {
		points.addToLastAll(src);
	}

	public boolean equals(Object obj) {
		return StrictEqualityTester.areEqual(this, obj, this);
	}

	public boolean areEqual(Polygon2D<T> o1, Polygon2D<T> o2) {
		return o1.points.equals(o2.points);
	}

	public int hashCode() {
		return points.hashCode();
	}

	public int pointNumber() {
		return points.size();
	}
	
	public Point2D<T> get(int index) {
		return points.get(index);
	}
	
	public int size() {
		return points.size();
	}
	
	public String toString() {
		return "Polygon" + points;
	}

}

interface DivisableNumberSystem<T> extends MultipliableNumberSystem<T> {
	T divide(T dividend, T divisor);
}

interface MultipliableNumberSystem<T> extends AddableNumberSystem<T> {
	T multiply(T v1, T v2);
	T getOne();
	boolean isOne(T v);
}

class AzimuthFromOrigin {

	public static Azimuth calc(Point2D<Float64> p) {
		return AzimuthFromPoint.calc(p, Point2D.create(Float64.valueOf(0), Float64.valueOf(0)));
	}

}

class Azimuth implements EqualityTester<Azimuth> {
	
	private static final double DOUBLE_PI = Math.PI + Math.PI;

	public static Azimuth create(double radian) {
		return new Azimuth(radian); 
	}
	
	private final double radian; 

	
	public Azimuth(double radian) {
		if(Double.isNaN(radian))
			throw new IllegalArgumentException("Direction cannot be NaN");
		this.radian = adjustRadian(radian);
	}

	private double adjustRadian(double radian) {
		radian = radian % DOUBLE_PI;
		if (radian < 0)
			radian += DOUBLE_PI;
		if (radian > DOUBLE_PI)
			radian = 0;
		return radian;
	}
	
	public double radian() {
		return radian;
	}

	public final boolean equals(Object v) {
		return StrictEqualityTester.areEqual(this, v, this);
	}

	public boolean areEqual(Azimuth o1, Azimuth o2) {
		return o1.radian == o2.radian;
	}

	public final int hashCode() {
		return ThomasWangHash.hash64bit(Double.doubleToLongBits(radian));
	}
	
	public String toString() {
		return "Dir(" + String.format("%.2f", radian) +"pi)";
	}
	
}

class Float64 {

	public static Float64 valueOf(double value) {
		return new Float64(value);
	}

	private double value;

	private Float64(double value) {
		this.value = value;
	}

	public double toPrimitive() {
		return value;
	}

	public int hashCode() {
		return ThomasWangHash.hash64bit(Double.doubleToLongBits(value));
	}

	public boolean equals(Object obj) {
		return StrictEqualityTester.areEqual(this, obj, EQ_TESTER);
	}

	private static EqualityTester<Float64> EQ_TESTER = new EqualityTester<Float64>() {
		public boolean areEqual(Float64 o1, Float64 o2) {
			return o1.value == o2.value;
		}
	};

	public String toString() {
		return Double.toString(value);
	}

}

class AzimuthFromPoint {

	public static Azimuth calc(Point2D<Float64> p, Point2D<Float64> ref) {
		return Azimuth.create(Math.atan2(p.y().toPrimitive() - ref.y().toPrimitive(), p.x().toPrimitive() - ref.x().toPrimitive()));
	}

}

class DirectionComparator {
	
	public static <T> Comparator<Point2D<T>> create(final MultipliableNumberSystem<T> ns, final Point2D<T> center, final Point2D<T> basis) {
		return new Comparator<Point2D<T>>() {
			public int compare(Point2D<T> p1, Point2D<T> p2) {
				int z1 = calcZoneOrder(p1);
				int z2 = calcZoneOrder(p2);
				if (z1 != z2) {
					return z1 - z2;
				} else { 

					if (z1 == 0 || z1 == 2) {
						return 0;
					} else {
						T ccw = CCW.ccw(ns, p1, center, p2);
						if (RightTurnFromCCW.is(ns, ccw))
							return -1;
						else if (LeftTurnFromCCW.is(ns, ccw))
							return 1;
						else
							return 0;
					}
				}
			}

			int calcZoneOrder(Point2D<T> p) {
				T ccw = CCW.ccw(ns, basis, center, p);
				if (StraightOrderFromCCW.is(ns, basis, center, p, ccw))
					return 2; 

				else if (RightTurnFromCCW.is(ns, ccw))
					return 1; 

				else if (LeftTurnFromCCW.is(ns, ccw))
					return 3; 

				else
					return 0; 

			}

		};
	}
	
}

class CCW {

	@SuppressWarnings("unchecked")
	public static <T> T ccw(MultipliableNumberSystem<T> ns, Point2D<T> p1, Point2D<T> p2, Point2D<T> p3) {
		T a1 = ns.multiply(p1.x(), p2.y());
		T a2 = ns.multiply(p2.x(), p3.y());
		T a3 = ns.multiply(p3.x(), p1.y());
		T m1 = ns.multiply(p1.x(), p3.y());
		T m2 = ns.multiply(p2.x(), p1.y());
		T m3 = ns.multiply(p3.x(), p2.y());
		T a = AddAll.add(ns, a1, a2, a3);
		T s = AddAll.add(ns, m1, m2, m3);
		return ns.subtract(a, s);
	}

}

class AddAll {

	public static <T> T add(AddableNumberSystem<T> ns, T value, T... values) {
		T r = value;
		for (T v : values)
			r = ns.add(r, v);
		return r;
	}

}

class LeftTurnFromCCW {

	public static <T> boolean is(AddableNumberSystem<T> ns, T ccw) {
		return ns.isPositive(ccw);
	}

}

class RightTurnFromCCW {

	public static <T> boolean is(AddableNumberSystem<T> ns, T ccw) {
		return ns.isNegative(ccw);
	}


}

class StraightOrderFromCCW {

	public static <T> boolean is(AddableNumberSystem<T> ns, Point2D<T> p1, Point2D<T> p2, Point2D<T> p3, T ccw) {
		return ns.isZero(ccw) && PointOnFilledRectangle.is(p2, p1.x(), p3.x(), p1.y(), p3.y(), ns);
	}

}

class PointOnFilledRectangle {

	public static <T> boolean is(Point2D<T> p, T x1, T x2, T y1, T y2, Comparator<T> comp) {
		T maxx = Max.max(x1, x2, comp);
		T minx = Min.min(x1, x2, comp);
		T maxy = Max.max(y1, y2, comp);
		T miny = Min.min(y1, y2, comp);
		return InRange.is(p.x(), minx, maxx, comp) && InRange.is(p.y(), miny, maxy, comp);
	}

}

class InRange {
	
	public static <T> boolean is(T v, T lower, T upper, Comparator<T> comp) {
		return comp.compare(lower, v) <= 0 && comp.compare(v, upper) <= 0;
	}

}

class Max {
	
	public static <T> T max(T v1, T v2, Comparator<T> comp) {
		if (comp.compare(v1, v2) > 0)
			return v1;
		else
			return v2;
	}
	
}

class Min {
	public static <T> T min(T v1, T v2, Comparator<T> comp) {
		if(comp.compare(v1, v2) < 0)
			return v1;
		else
			return v2;
	}
}

class DistanceBetweenPointOrigin {

	public static double calc(Point2D<Float64> p) {
		return DistanceBetweenPoints.calc(p, Point2D.create(Float64.valueOf(0), Float64.valueOf(0)));
	}

}

class DistanceBetweenPoints {
	
	public static double calc(Point2D<Float64> p1, Point2D<Float64> p2) {
		return Math.sqrt(DistanceSquareBetweenPoints.calc(Float64NumberSystem.getInstance(), p1, p2).toPrimitive());
	}
}

class Float64NumberSystem implements DivisableNumberSystem<Float64>, Comparator<Float64> {

	private static Float64NumberSystem INSTANCE = new Float64NumberSystem();

	public static Float64NumberSystem getInstance() {
		return INSTANCE;
	}

	private Float64NumberSystem() {
	}

	public Float64 getOne() {
		return Float64.valueOf(1);
	}

	public Float64 getZero() {
		return Float64.valueOf(0);
	}

	public boolean isNegative(Float64 v) {
		return v.toPrimitive() < 0;
	}

	public boolean isOne(Float64 v) {
		return v.toPrimitive() == 1;
	}

	public boolean isPositive(Float64 v) {
		return v.toPrimitive() > 0;
	}

	public boolean isZero(Float64 v) {
		return v.toPrimitive() == 0;
	}

	public boolean areEqual(Float64 o1, Float64 o2) {
		return o1.toPrimitive() == o2.toPrimitive();
	}

	public int compare(Float64 o1, Float64 o2) {
		return Double.compare(o1.toPrimitive(), o2.toPrimitive());
	}

	public int getSign(Float64 v) {
		return Double.compare(v.toPrimitive(), 0);
	}

	public Float64 add(Float64 v1, Float64 v2) {
		return Float64.valueOf(v1.toPrimitive() + v2.toPrimitive());
	}

	public Float64 subtract(Float64 minuend, Float64 subtrahend) {
		return Float64.valueOf(minuend.toPrimitive() - subtrahend.toPrimitive());
	}

	public Float64 divide(Float64 dividend, Float64 divisor) {
		return Float64.valueOf(dividend.toPrimitive() / divisor.toPrimitive());
	}

	public Float64 multiply(Float64 v1, Float64 v2) {
		return Float64.valueOf(v1.toPrimitive() * v2.toPrimitive());
	}
}

class DistanceSquareBetweenPoints {

	public static <T> T calc(MultipliableNumberSystem<T> ns, Point2D<T> p1, Point2D<T> p2) {
		T sq1 = Square.calc(ns, ns.subtract(p1.x(), p2.x()));
		T sq2 = Square.calc(ns, ns.subtract(p1.y(), p2.y()));
		return ns.add(sq1, sq2);
	}

}

class Square {
	static public <T> T calc(MultipliableNumberSystem<T> ns, T v) {
		return ns.multiply(v, v);
	}
}

class PointByDistanceAzimuth {
	
	public static Point2D<Float64> calc(double d, Azimuth a) {
		double x = d * Math.cos(a.radian());
		double y = d * Math.sin(a.radian());
		return Point2D.create(Float64.valueOf(x), Float64.valueOf(y));
	}

}

class Angle implements EqualityTester<Angle> {
	
	public static Angle create(double radian) {
		return new Angle(radian);
	}

	private final double radian;
	
	private Angle(double a) {
		this.radian = a;
	}
	
	public double radian() {
		return radian;
	}

	public String toString() {
		return "A"+radian ;
	}
	
	public boolean equals(Object o) {
		return StrictEqualityTester.areEqual(this, o, this);
	}

	public boolean areEqual(Angle o1, Angle o2) {
		return o1.radian == o2.radian;
	}
	
	public int hashCode() {
		return ThomasWangHash.hash64bit(Double.doubleToLongBits(radian));
	}

}

class Segment2D<T> implements EqualityTester<Segment2D<T>> {
	
	public static <T> Segment2D<T> create(Point2D<T> p1, Point2D<T> p2) {
		return new Segment2D<T>(p1, p2);
	}
	
	public final Point2D<T> p1;
	public final Point2D<T> p2;

	private Segment2D(Point2D<T> p1, Point2D<T> p2) {
		if(p1.equals(p2))
			throw new IllegalArgumentException("Segment : two points are same");
		this.p1 = p1;
		this.p2 = p2;
	}

	public String toString() {
		return "Segment(" + p1 + "-" + p2 + ")";
	}
	
	public final boolean equals(Object obj) { 
		return StrictEqualityTester.areEqual(this, obj, this);
	}

	public boolean areEqual(Segment2D<T> o1, Segment2D<T> o2) {
		return (o2.p1.equals(o1.p1) && o2.p2.equals(o1.p2)) || (o2.p1.equals(o1.p2) && o2.p2.equals(o1.p1));
	}


	public final int hashCode() {
		return p1.hashCode() ^ p2.hashCode();
	}
	
}

class IntersectionOfNonParallelSegments {

	public static <T> Point2D<T> calc(DivisableNumberSystem<T> ns, Segment2D<T> s1, Segment2D<T> s2, Point2D<T> def) {
		

		Point2D<T> p = s1.p1;
		Point2D<T> q = s2.p1;
		Vector2D<T> r = DirectionVectorFrom2DPoints.get(ns, p, s1.p2);
		Vector2D<T> s = DirectionVectorFrom2DPoints.get(ns, q, s2.p2);
		T rxs = CrossProduct2D.calc(ns, r, s);
		if(ns.isZero(rxs))
			throw new IllegalArgumentException("two segments are parallel");
		
		Vector2D<T> pq = DirectionVectorFrom2DPoints.get(ns, p, q); 

		T t = ns.divide(CrossProduct2D.calc(ns, pq, s), rxs);
		T u = ns.divide(CrossProduct2D.calc(ns, pq, r), rxs);
		
		if(inZeroToOne(ns, t)  && inZeroToOne(ns, u)) 
			return MiddlePoint.calc(ns, s1.p1, s1.p2, t);
		else
			return def;
	}

	private static <T> boolean inZeroToOne(MultipliableNumberSystem<T> ns, T v) {
		return InRange.is(v, ns.getZero(), ns.getOne(), ns);
	}

}

class DirectionVectorFrom2DPoints {

	public static <T> Vector2D<T> get(AddableNumberSystem<T> ns, Point2D<T> from, Point2D<T> to) {
		return Vector2D.create(ns.subtract(to.x(), from.x()), ns.subtract(to.y(), from.y()));
	}

}

class Vector2D<T> {
	private final T x, y;

	public static <T> Vector2D<T> create(T x, T y) {
		return new Vector2D<T>(x, y);
	}

	private Vector2D(T x, T y) {
		this.x = x;
		this.y = y;
	}

	public T x() {
		return x;
	}

	public T y() {
		return y;
	}
}

class MiddlePoint {

	public static <T> Point2D<T> calc(MultipliableNumberSystem<T> ns, Point2D<T> p1, Point2D<T> p2, T rateOf2) {
		T x = calc(ns, p1.x(), p2.x(), rateOf2);
		T y = calc(ns, p1.y(), p2.y(), rateOf2);
		return Point2D.create(x, y);
	}

	private static <T> T calc(MultipliableNumberSystem<T> ns, T v1, T v2, T rateOf2) {
		T rateOf1 = ns.subtract(ns.getOne(), rateOf2);
		return ns.add(ns.multiply(v1, rateOf1), ns.multiply(v2, rateOf2));
	}

}

class CrossProduct2D {

	public static <T> T calc(MultipliableNumberSystem<T> ns, Vector2D<T> d1, Vector2D<T> d2) {
		return ns.subtract(ns.multiply(d1.x(), d2.y()), ns.multiply(d1.y(), d2.x()));
	}

}
