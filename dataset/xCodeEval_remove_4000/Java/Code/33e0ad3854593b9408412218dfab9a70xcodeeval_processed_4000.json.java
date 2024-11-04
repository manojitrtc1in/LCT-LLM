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

public class C implements id23 {

	private static final Sort SORT = new QuickSort();
	private static final id26 NS = id26.getInstance();
	private static final id41<Float64> ORIGIN = id41.create(NS.getZero(), NS.getZero());

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
			DynamicArray<id41<Float64>> points = DynamicArray.create();
			points.id10(toPoint(w/2, h/2));
			points.id10(toPoint(-w/2, h/2));
			points.id10(toPoint(-w/2, -h/2));
			points.id10(toPoint(w/2, -h/2));
			
			DynamicArray<id41<Float64>> intersects = DynamicArray.create();
			for(int i=0;i<4;i++) { 
				id9<Float64> s1 = id9.create(points.get(i), points.get((i+1)%4));
				for(int j=0;j<4;j++) {
					id9<Float64> s2 = id9.create(rotate(points.get(j), a), rotate(points.get((j+1)%4), a));
					id41<Float64> inter = id20.calc(NS, s1, s2, null);
					if(inter != null)
						intersects.id10(inter);
				}
			}
			
			SORT.sort(intersects, DirectionComparator.create(NS, ORIGIN, ArrayUtil.getFirst(intersects)));
			id36<Float64> polygon = id36.create(intersects);
			Float64 area = id39.calc(NS, polygon);
			System.out.format("%.20f", area.toPrimitive());
		}
	}

	private id41<Float64> toPoint(double x, double y) {
		return id41.create(Float64.valueOf(x), Float64.valueOf(y));
	}

	private id41<Float64> rotate(id41<Float64> p, double deg) {
		return id0(p, Angle.create(Math.toRadians(deg)));
	}

	private static id41<Float64> id0(id41<Float64> p, Angle a) {
		Azimuth am = Azimuth.create(id43.calc(p).radian() + a.radian());
		double dis = id1.calc(p);
		return id17.calc(dis, am);
	}

	public static void main(String[] args) throws Exception {
		id12.launch(new id8() {
			public id23 create() {
				return new C();
			}
		}, "C1.txt", "C2.txt", "C3.txt");
	}

}

interface id23 {
	void solve(InputStream is); 
}

interface id8 {
	id23 create();
}

class id12 {

	public static void launch(id8 factory, String... id37) throws FileNotFoundException, IOException {
		if(System.getProperty("ONLINE_JUDGE", "false").equals("true")) {
			factory.create().solve(System.in);
		} else { 
			for(String path : id37) {
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
			id44.swap(list, start, RANDOM.nextInt(end-start) + start + 1);
			int pos = start;
			for(int i=start+1;i<=end;i++) {
				int c = comparator.compare(list.get(i), list.get(start)); 
				if(c < 0 || c == 0 && i%2==0)
					id44.swap(list, i,++pos);
			}
			id44.swap(list, start, pos);
			sort(list, start,pos-1, comparator);
			sort(list, pos+1, end, comparator);
		}
	}
	
}

class id44 {
	
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
	public void id10(T value) {
		if(a.length == asize) {
			T[] ta = (T[])new Object[asize*2];
			for(int i=0;i<asize;i++)
				ta[i] = a[i];
			a =ta;
		}
		a[asize++] = value;						
	}
	
	public void id38(Iterable<? extends T> values) {
		id2.id10(this, values);
	}

	public T removeLast() {
		T r = ArrayUtil.getLast(this);
		a[--asize] = null;
		return r;
	}
	
	public boolean equals(Object obj) {
		return id24.areEqual(this, obj, this);
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
			r ^= id29.id7(get(i).hashCode());
		return r;
	}

	public final boolean isEmpty() {
		return size() == 0;
	}

	public final Iterator<T> iterator() {
		return ArrayIterator.create(this);
	}

	public final String toString() {
		return id4.toString(this);
	}
	
}

interface EqualityTester<T> {
	boolean areEqual(T o1, T o2);
}

class id4 {
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

class id24 {
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

class id29 {
	
	

	
	public static int id7(int key) {
		key = ~key + (key << 15); 

		key = key ^ (key >>> 12);
		key = key + (key << 2);
		key = key ^ (key >>> 4);
		key = key * 2057; 

		key = key ^ (key >>> 16);
		return key;
	}

	public static int id16(long key) { 
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
		return new id13<T>() {
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

abstract class id13<T> implements Iterator<T> {
	public final void remove() {
		throw new UnsupportedOperationException();
	}
}

class id2 {

	public static <T> void id10(DynamicArray<T> dynamicArray, Iterable<? extends T> values) {
		for (T v : values)
			dynamicArray.id10(v);
	}

}

class id39 {
	
	


	public static <T> T calc(id34<T> ns, id36<T> sp) {
		T two = ns.add(ns.getOne(), ns.getOne());
		return ns.divide(calcDouble(ns, sp), two);
	}

	private static <T> T calcDouble(id35<T> ns, id36<T> sp) {
		T total = ns.getZero();
		for (int i : ZeroTo.get(sp.pointNumber())) {
			id41<T> p1 = sp.get(i);
			id41<T> p2 = sp.get((i + 1) % sp.pointNumber());
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
		return id45.create(begin, 1, end-begin);
	}

}

class id45 {
	public static Iterable<Integer> create(final int from, final int step, final int size) {
		return new Iterable<Integer>() {
			public Iterator<Integer> iterator() {
				return new id13<Integer>() {
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

	private id45() {
	}
}

class Abs {
	

	public static <T> T calc(id5<T> ns, T v) {
		if (ns.isNegative(v))
			return AddInvert.calc(ns, v);
		return v;
	}
}

class AddInvert {

	public static <T> T calc(id5<T> ns, T v) {
		return ns.subtract(ns.getZero(), v);
	}

}

interface id5<T> extends NumberSystem<T> {
	T add(T v1, T v2);
	T subtract(T id19, T id40);
	T getZero();
	boolean isPositive(T v);
	boolean isZero(T v);
	boolean isNegative(T v);
	int getSign(T v);
}

interface NumberSystem<T> extends EqualityTester<T>, Comparator<T> {

}

class id41<T> implements EqualityTester<id41<T>> {

	public static <T> id41<T> create(T x, T y) {
		return new id41<T>(x, y); 
	}
	
	private final T x;
	private final T y;
	
	private id41(T x, T y) {
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
		return id24.areEqual(this, o, this);
	}

	public boolean areEqual(id41<T> o1, id41<T> o2) {
		return o1.x.equals(o2.x) && o1.y.equals(o2.y);
	}

	public final int hashCode() {
		return x.hashCode() ^ y.hashCode();
	}
	
	public String toString() {
		return "(" + x + "," + y + ")";
	}
	
}

class id36<T> implements EqualityTester<id36<T>> {
	
	public static <T> id36<T> create(Iterable<id41<T>> src) {
		return new id36<T>(src);
	}

	private final DynamicArray<id41<T>> points = DynamicArray.create();
	
	private id36(Iterable<id41<T>> src) {
		points.id38(src);
	}

	public boolean equals(Object obj) {
		return id24.areEqual(this, obj, this);
	}

	public boolean areEqual(id36<T> o1, id36<T> o2) {
		return o1.points.equals(o2.points);
	}

	public int hashCode() {
		return points.hashCode();
	}

	public int pointNumber() {
		return points.size();
	}
	
	public id41<T> get(int index) {
		return points.get(index);
	}
	
	public int size() {
		return points.size();
	}
	
	public String toString() {
		return "Polygon" + points;
	}

}

interface id34<T> extends id35<T> {
	T divide(T dividend, T divisor);
}

interface id35<T> extends id5<T> {
	T multiply(T v1, T v2);
	T getOne();
	boolean isOne(T v);
}

class id43 {

	public static Azimuth calc(id41<Float64> p) {
		return id22.calc(p, id41.create(Float64.valueOf(0), Float64.valueOf(0)));
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
		this.radian = id30(radian);
	}

	private double id30(double radian) {
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
		return id24.areEqual(this, v, this);
	}

	public boolean areEqual(Azimuth o1, Azimuth o2) {
		return o1.radian == o2.radian;
	}

	public final int hashCode() {
		return id29.id16(Double.doubleToLongBits(radian));
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
		return id29.id16(Double.doubleToLongBits(value));
	}

	public boolean equals(Object obj) {
		return id24.areEqual(this, obj, id6);
	}

	private static EqualityTester<Float64> id6 = new EqualityTester<Float64>() {
		public boolean areEqual(Float64 o1, Float64 o2) {
			return o1.value == o2.value;
		}
	};

	public String toString() {
		return Double.toString(value);
	}

}

class id22 {

	public static Azimuth calc(id41<Float64> p, id41<Float64> ref) {
		return Azimuth.create(Math.atan2(p.y().toPrimitive() - ref.y().toPrimitive(), p.x().toPrimitive() - ref.x().toPrimitive()));
	}

}

class DirectionComparator {
	
	public static <T> Comparator<id41<T>> create(final id35<T> ns, final id41<T> center, final id41<T> basis) {
		return new Comparator<id41<T>>() {
			public int compare(id41<T> p1, id41<T> p2) {
				int z1 = id42(p1);
				int z2 = id42(p2);
				if (z1 != z2) {
					return z1 - z2;
				} else { 

					if (z1 == 0 || z1 == 2) {
						return 0;
					} else {
						T ccw = CCW.ccw(ns, p1, center, p2);
						if (id25.is(ns, ccw))
							return -1;
						else if (id11.is(ns, ccw))
							return 1;
						else
							return 0;
					}
				}
			}

			int id42(id41<T> p) {
				T ccw = CCW.ccw(ns, basis, center, p);
				if (id18.is(ns, basis, center, p, ccw))
					return 2; 

				else if (id25.is(ns, ccw))
					return 1; 

				else if (id11.is(ns, ccw))
					return 3; 

				else
					return 0; 

			}

		};
	}
	
}

class CCW {

	@SuppressWarnings("unchecked")
	public static <T> T ccw(id35<T> ns, id41<T> p1, id41<T> p2, id41<T> p3) {
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

	public static <T> T add(id5<T> ns, T value, T... values) {
		T r = value;
		for (T v : values)
			r = ns.add(r, v);
		return r;
	}

}

class id11 {

	public static <T> boolean is(id5<T> ns, T ccw) {
		return ns.isPositive(ccw);
	}

}

class id25 {

	public static <T> boolean is(id5<T> ns, T ccw) {
		return ns.isNegative(ccw);
	}


}

class id18 {

	public static <T> boolean is(id5<T> ns, id41<T> p1, id41<T> p2, id41<T> p3, T ccw) {
		return ns.isZero(ccw) && id31.is(p2, p1.x(), p3.x(), p1.y(), p3.y(), ns);
	}

}

class id31 {

	public static <T> boolean is(id41<T> p, T x1, T x2, T y1, T y2, Comparator<T> comp) {
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

class id1 {

	public static double calc(id41<Float64> p) {
		return id14.calc(p, id41.create(Float64.valueOf(0), Float64.valueOf(0)));
	}

}

class id14 {
	
	public static double calc(id41<Float64> p1, id41<Float64> p2) {
		return Math.sqrt(id28.calc(id26.getInstance(), p1, p2).toPrimitive());
	}
}

class id26 implements id34<Float64>, Comparator<Float64> {

	private static id26 INSTANCE = new id26();

	public static id26 getInstance() {
		return INSTANCE;
	}

	private id26() {
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

	public Float64 subtract(Float64 id19, Float64 id40) {
		return Float64.valueOf(id19.toPrimitive() - id40.toPrimitive());
	}

	public Float64 divide(Float64 dividend, Float64 divisor) {
		return Float64.valueOf(dividend.toPrimitive() / divisor.toPrimitive());
	}

	public Float64 multiply(Float64 v1, Float64 v2) {
		return Float64.valueOf(v1.toPrimitive() * v2.toPrimitive());
	}
}

class id28 {

	public static <T> T calc(id35<T> ns, id41<T> p1, id41<T> p2) {
		T sq1 = Square.calc(ns, ns.subtract(p1.x(), p2.x()));
		T sq2 = Square.calc(ns, ns.subtract(p1.y(), p2.y()));
		return ns.add(sq1, sq2);
	}

}

class Square {
	static public <T> T calc(id35<T> ns, T v) {
		return ns.multiply(v, v);
	}
}

class id17 {
	
	public static id41<Float64> calc(double d, Azimuth a) {
		double x = d * Math.cos(a.radian());
		double y = d * Math.sin(a.radian());
		return id41.create(Float64.valueOf(x), Float64.valueOf(y));
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
		return id24.areEqual(this, o, this);
	}

	public boolean areEqual(Angle o1, Angle o2) {
		return o1.radian == o2.radian;
	}
	
	public int hashCode() {
		return id29.id16(Double.doubleToLongBits(radian));
	}

}

class id9<T> implements EqualityTester<id9<T>> {
	
	public static <T> id9<T> create(id41<T> p1, id41<T> p2) {
		return new id9<T>(p1, p2);
	}
	
	public final id41<T> p1;
	public final id41<T> p2;

	private id9(id41<T> p1, id41<T> p2) {
		if(p1.equals(p2))
			throw new IllegalArgumentException("Segment : two points are same");
		this.p1 = p1;
		this.p2 = p2;
	}

	public String toString() {
		return "Segment(" + p1 + "-" + p2 + ")";
	}
	
	public final boolean equals(Object obj) { 
		return id24.areEqual(this, obj, this);
	}

	public boolean areEqual(id9<T> o1, id9<T> o2) {
		return (o2.p1.equals(o1.p1) && o2.p2.equals(o1.p2)) || (o2.p1.equals(o1.p2) && o2.p2.equals(o1.p1));
	}


	public final int hashCode() {
		return p1.hashCode() ^ p2.hashCode();
	}
	
}

class id20 {

	public static <T> id41<T> calc(id34<T> ns, id9<T> s1, id9<T> s2, id41<T> def) {
		

		id41<T> p = s1.p1;
		id41<T> q = s2.p1;
		id21<T> r = id3.get(ns, p, s1.p2);
		id21<T> s = id3.get(ns, q, s2.p2);
		T rxs = id32.calc(ns, r, s);
		if(ns.isZero(rxs))
			throw new IllegalArgumentException("two segments are parallel");
		
		id21<T> pq = id3.get(ns, p, q); 

		T t = ns.divide(id32.calc(ns, pq, s), rxs);
		T u = ns.divide(id32.calc(ns, pq, r), rxs);
		
		if(id15(ns, t)  && id15(ns, u)) 
			return MiddlePoint.calc(ns, s1.p1, s1.p2, t);
		else
			return def;
	}

	private static <T> boolean id15(id35<T> ns, T v) {
		return InRange.is(v, ns.getZero(), ns.getOne(), ns);
	}

}

class id3 {

	public static <T> id21<T> get(id5<T> ns, id41<T> from, id41<T> to) {
		return id21.create(ns.subtract(to.x(), from.x()), ns.subtract(to.y(), from.y()));
	}

}

class id21<T> {
	private final T x, y;

	public static <T> id21<T> create(T x, T y) {
		return new id21<T>(x, y);
	}

	private id21(T x, T y) {
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

	public static <T> id41<T> calc(id35<T> ns, id41<T> p1, id41<T> p2, T id27) {
		T x = calc(ns, p1.x(), p2.x(), id27);
		T y = calc(ns, p1.y(), p2.y(), id27);
		return id41.create(x, y);
	}

	private static <T> T calc(id35<T> ns, T v1, T v2, T id27) {
		T id33 = ns.subtract(ns.getOne(), id27);
		return ns.add(ns.multiply(v1, id33), ns.multiply(v2, id27));
	}

}

class id32 {

	public static <T> T calc(id35<T> ns, id21<T> d1, id21<T> d2) {
		return ns.subtract(ns.multiply(d1.x(), d2.y()), ns.multiply(d1.y(), d2.x()));
	}

}
