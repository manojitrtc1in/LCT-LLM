import java.io.File;
import java.io.FileNotFoundException;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Random;
import java.util.Scanner;

public class CF178D2C implements CodeforcesSolver {

	long mod = 1000000007;
	CombinationNumberTableWithModular<Int64> cn = new CombinationNumberTableWithModular<Int64>(Int64.ONE, new Int64(mod), new MemoizationFactory(new JavaHashMapFactory())); 
	Sort sort = new QuickSort();
	
	public void solve(Scanner in) {
		int n = in.nextInt();
		int m = in.nextInt();
		DynamicArray<Integer> initialLights = DynamicArray.create();
		for(int i : Range.get(m))
			initialLights.addToLast(in.nextInt());
		
		sort.sort(initialLights);
		
		DynamicArray<Integer> spaces = extractSpaces(n, initialLights);
		long res = 1;
		int remain = n-m;
		for(int size : spaces) {
			long combi = cn.calc(remain, size).toPrimitive();
			res = (res * combi) % mod;
			remain -= size;
		}
		for(int i : Range.get(1, m-1)) 
			for(int j : Range.get(spaces.get(i)-1))
				res = (res * 2) % mod;
		
		System.out.println(res);
	}

	private DynamicArray<Integer> extractSpaces(int n, DynamicArray<Integer> initialLights) {
		DynamicArray<Integer> r = DynamicArray.create();
		int start = 1;
		for(int p : initialLights) {
			r.addToLast(p-start);
			start = p+1;
		}
		r.addToLast(n-start+1);
		return r;
	}

	public static void main(String[] args) throws Exception {
		CodeforcesSolverLauncher.launch(new CodeforcesSolverFactory() {
			public CodeforcesSolver create() {
				return new CF178D2C();
			}
		}, "C1.in", "C2.in", "C3.in");
	}

}

class MemoizationFactory {
	
	private MapFactory mapFactory;

	public MemoizationFactory(MapFactory mapFactory) {
		this.mapFactory = mapFactory;
	}
	
	public <I, V> Memoization<I, V> create(ItemCalculator<I, V> calc) {
		return new Memoization<I, V>(mapFactory, calc);
	}

}

interface MapFactory {
	<K,V> Map<K,V> create();
}

interface Map<K, V> extends Container<Entry<K, V>> {
	void clear(); 
	void put(K key, V value);
	void remove(K key);
	boolean containsKey(K key);
	V get(K key);
	Iterable<V> values();
	Iterable<K> keys();
}

interface Container<T> extends Iterable<T> {
	int size();
	boolean isEmpty();
}

interface Entry<K, V> {
	K getKey();
	V getValue();
	void setValue(V v);
}

interface ItemCalculator<I, V> {
	V calc(I index, SubItem<I, V> sub);
}

interface SubItem<I, V> {
	V get(I index);
}

class Memoization<I, V> {
	
	private ItemCalculator<I, V> calc;  
	private Map<I, V> table;
	
	

	Memoization(MapFactory mapFactory, ItemCalculator<I, V> calc) {
		this.calc = calc; 
		this.table = mapFactory.create();
	}

	public V get(I index) {
		V v = table.get(index);
		if(v == null) {
			v = calc.calc(index, subItem);
			table.put(index, v);
		}
		return v;
	}
	
	private SubItem<I, V> subItem = new SubItem<I, V>() {
		public V get(I index) {
			return Memoization.this.get(index);
		}			
	};

}

interface CodeforcesSolver {
	void solve(Scanner in);
}

interface CodeforcesSolverFactory {
	CodeforcesSolver create();
}

class CodeforcesSolverLauncher {

	public static void launch(CodeforcesSolverFactory factory, String... inputFilePath) throws FileNotFoundException {
		if(System.getProperty("ONLINE_JUDGE", "false").equals("true")) {
			factory.create().solve(new Scanner(System.in));
		} else { 
			for(String path : inputFilePath) {
				factory.create().solve(new Scanner(new File(path)));
				System.out.println();
			}
		}
	}

}

class Range {

	public static Iterable<Integer> get(int len) {
		return IntSequenceIterable.create(0, 1, len);
	}

	public static Iterable<Integer> get(int from, int size) {
		return IntSequenceIterable.create(from, 1, size);
	}

}

class IntSequenceIterable {
	
	public static Iterable<Integer> create(final int from, final int step, final int size) {
		return new Iterable<Integer>() {
			public Iterator<Integer> iterator() {
				return new AbstractIterator<Integer>() {
					int nextIndex = 0;
					int nextValue = from;
					public boolean hasNext() {
						return nextIndex < size;
					}
					public Integer next() {
						int r = nextValue;
						nextIndex++;
						nextValue += step;
						return r;
					}
				};
			}
		};
	}
	
}

abstract class AbstractIterator<T> implements Iterator<T> {

	public final void remove() {
		throw new UnsupportedOperationException();
	}

}

class DynamicArray<T> extends AbstractReadableArray<T>  implements StaticArray<T> {
	
	public static <T> DynamicArray<T> create() {
		return new DynamicArray<T>();
	}
	
	private T[] a;
	private int asize;
	
	
	@SuppressWarnings("unchecked")
	private void init(int cap) {
		asize = 0;
		a = (T[])new Object[Math.max(1, cap)];		
	}
	
	public DynamicArray() {
		init(1);
	}
	
	public DynamicArray(int initialCapacity) {
		init(initialCapacity);
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
			T[] ta = (T[])new Object[size];
			for(int i=0;i<a.length;i++)
				ta[i] = a[i];
			a = ta;
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
		for(T v : values)
			addToLast(v);
	}
	
	public T removeLast() {
		T r = last();
		a[--asize] = null;
		return r;
	}
	
	public boolean equals(Object obj) {
		return StrictEqualityChecker.isEquals(this, obj, new EqualityChecker<DynamicArray<T>>() {
			public boolean isEquals(DynamicArray<T> o1, DynamicArray<T> o2) {
				if(o1.size() != o2.size())
					return false;
				for(int i=0;i<o1.size();i++)
					if(!o1.get(i).equals(o2.get(i)))
						return false;		
				return true;
			}
		});
	}

	public int hashCode() {
		int r = 0;
		for(int i=0;i<size();i++)
			r ^= Int32Hash.hash(get(i).hashCode());
		return r;
	}
	
}

interface EqualityChecker<T> {
	boolean isEquals(T o1, T o2);
}

class Int32Hash {
	public static int hash(int key) {
		key = ~key + (key << 15); 

		key = key ^ (key >>> 12);
		key = key + (key << 2);
		key = key ^ (key >>> 4);
		key = key * 2057; 

		key = key ^ (key >>> 16);
		return key;
	}
}

class StrictEqualityChecker {
	@SuppressWarnings("unchecked")
	public static <T> boolean isEquals(T me, Object you, EqualityChecker<T> ec) {
		if(me == you)
			return true;
		if(you == null)
			return false;
		if(you.getClass() != me.getClass())
			return false;
		return ec.isEquals(me, (T)you);
	}
}

abstract class AbstractReadableArray<T> extends AbstractContainer<T> implements ReadableArray<T> {
	
	public final boolean isEmpty() {
		return size() == 0;
	}
	
	public final T last() {
		return get(size()-1);
	}
	
	public final T first() {
		return get(0);
	}	
	
	public final Iterator<T> iterator() {
		return new AbstractIterator<T>() {
			int p = 0;
			public boolean hasNext() {
				return p < size();
			}
			public T next() {
				return get(p++);
			}
		};
	}

}

abstract class AbstractContainer<T> implements Container<T> {

	public final String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append('(');
		boolean first = true;
		for(T v : this) {
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

interface ReadableArray<T> extends Container<T> {
	T get(int index);
	T last();
	T first();
}

interface StaticArray<T> extends ReadableArray<T>{
	void set(int index, T value);	
}

class JavaHashMapFactory implements MapFactory {

	public <K, V> Map<K, V> create() {
		return new MapWrapperForJavaMap<K, V>(new HashMap<K, V>());
	}
	
}

class MapWrapperForJavaMap<K, V> implements Map<K, V> {
	
	private final java.util.Map<K,V> map;
	
	public MapWrapperForJavaMap(java.util.Map<K,V> map) {
		this.map = map;				
	}

	public boolean containsKey(K key) {
		return map.containsKey(key);
	}

	public V get(K key) {
		return map.get(key);
	}

	public Iterable<K> keys() {
		return map.keySet();
	}

	public void put(K key, V value) {
		map.put(key, value);
	}

	public Iterable<V> values() {
		return map.values();
	}

	public void clear() {
		map.clear();
	}

	public boolean isEmpty() {
		return map.isEmpty();
	}

	public Iterator<Entry<K, V>> iterator() {
		return ConvertedDataIterator.create(map.entrySet().iterator(), new DataConverter<java.util.Map.Entry<K,V>, Entry<K,V>>() {
			public Entry<K, V> convert(java.util.Map.Entry<K, V> e) {
				return new EntryWrapper<K, V>(e);
			}
		});
	}

	public int size() {
		return map.size();
	}
	
	public void remove(K key) {
		map.remove(key);
	}
	
	public String toString() {
		return map.toString();
	}
	
	private static class EntryWrapper<K, V> implements Entry<K, V>, EqualityChecker<EntryWrapper<K,V>> {
		private java.util.Map.Entry<K, V> e;
		private EntryWrapper(java.util.Map.Entry<K, V> e) {
			this.e = e;
		}
		public K getKey() {
			return e.getKey();
		}
		public V getValue() { 
			return e.getValue();
		}
		public void setValue(V v) {
			e.setValue(v);						
		}
		public boolean equals(Object obj) {
			return StrictEqualityChecker.isEquals(this, obj, this);
		}
		public boolean isEquals(EntryWrapper<K, V> o1, EntryWrapper<K, V> o2) {
			return o1.getKey().equals(o2.getKey()) && o1.getValue().equals(o2.getValue());
		}
		public int hashCode() {
			return PairHash.hash(getKey().hashCode(), getValue().hashCode());
		}
	}

}

class ConvertedDataIterator {
	public static <T1, T2> Iterator<T2> create(final Iterator<T1> outerIterator, final DataConverter<T1, T2> extractor) {
		return new AbstractIterator<T2>() {
			public boolean hasNext() {
				return outerIterator.hasNext();
			}
			public T2 next() {
				return extractor.convert(outerIterator.next());
			}
		};
	}
}

interface DataConverter<T1, T2> {
	T2 convert(T1 v);
}

class PairHash {
	public static int hash(int h1, int h2) {
		return Int64Hash.hash6432shift((((long) h1) << 32) | h2);
	}
}

class Int64Hash {
	public static int hash6432shift(long key) { 
		

		key = (~key) + (key << 18); 

		key = key ^ (key >>> 31);
		key = key * 21; 

		key = key ^ (key >>> 11);
		key = key + (key << 6);
		key = key ^ (key >>> 22);
		return (int) key;
	}
}

class CombinationNumberTableWithModular<T extends Int<T>> {
	
	private Memoization<Index2D, T> mem;
	
	public CombinationNumberTableWithModular(final T one, final T mod, MemoizationFactory mf) {
		mem = mf.create(new ItemCalculator<Index2D, T>() {
			public T calc(Index2D index, SubItem<Index2D, T> sub) {
				int a = index.i1;
				int b = index.i2;
				if(b==0 || a==b) {
					return one;
				} else {
					T sub1 = sub.get(new Index2D(a-1,b-1));
					T sub2 = sub.get(new Index2D(a-1,b));
					return sub1.plus(sub2).mod(mod);
				}
			}
		});
	}

	public T calc(int a, int b) {
		if(b > a/2) 
			return calc(a, a-b);
		return mem.get(new Index2D(a,b));
	}

}

class Index2D implements EqualityChecker<Index2D>{
	
	public final int i1;
	public final int i2;
	
	public Index2D(int i, int j) {
		this.i1 = i;
		this.i2 = j;
	}
	
	public boolean equals(Object obj) {
		return StrictEqualityChecker.isEquals(this, obj, this);
	}
	
	public boolean isEquals(Index2D o1, Index2D o2) {
		return o1.i1 == o2.i1 && o1.i2 == o2.i2;
	}

	public int hashCode() {
		return PairHash.hash(i1, i2);
	}
	
	public String toString() {
		return "("+i1+","+i2 +")";
	}
}

interface Int<T extends Int<T>> extends Multiplicative<T> {
	T mod(T v);
	T floorDivide(T v);
	double toDouble();
}

interface Multiplicative<T extends Multiplicative<T>> extends Additive<T> { 

	T times(T a);
	T getOne();
	T get(int v);
	boolean isOne();
}

interface Additive<T extends Additive<T>> extends Number<T> { 

	T plus(T v);
	T minus(T v);
	T getAddInvert();
	T getZero();
	boolean isPositive();
	boolean isZero();
	boolean isNegative();
	int getSign();
}

interface Number<T> extends Comparable<T> {
}

class Int64 implements Int<Int64>, EqualityChecker<Int64> {
	
	

	
	private final long v;
	
	public Int64(long v) {
		this.v = v;
	}

	public Int64 plus(Int64 t) {
		return new Int64(v + t.v);
	}
	
	public Int64 minus(Int64 t) {
		return new Int64(v - t.v);
	}
	
	public long toPrimitive() {
		return v;
	}
	
	public Int64 getAddInvert() {
		return new Int64(-v);
	}
	
	public int compareTo(Int64 o) {
		if(v > o.v)
			return 1;
		else if(v < o.v)
			return -1;
		return 0;
	}
	
	public String toString() {
		return Long.toString(v);
	}
	
	public Int64 getZero() {
		return ZERO;
	}
	
	public Int64 getOne() {
		return ONE;
	}
	
	public boolean isOne() {
		return v == 1;
	}
	
	public Int64 times(Int64 a) {
		return new Int64(v * a.v);
	}	
	
	public Int64 floorDivide(Int64 o) {
		return new Int64(v / o.v);
	}
	
	public Int64 mod(Int64 o) {
		return new Int64(v % o.v);
	}
	
	public double toDouble() {
		return v;
	}
	
	public boolean equals(Object obj) {
		return StrictEqualityChecker.isEquals(this, obj, this);
	}
	
	public boolean isEquals(Int64 o1, Int64 o2) {
		return o1.v == o2.v;
	}
	
	public int hashCode() {
		return Int64Hash.hash6432shift(v);		
	}
	
	public int getSign() {
		if(v > 0)
			return 1;
		else if(v < 0)
			return -1;
		return 0;
	}

	public final Int64 get(int v) {
		return new Int64(v);
	}

	public final boolean isPositive() {
		return v > 0;
	}

	public final boolean isNegative() {
		return v < 0;
	}

	public final boolean isZero() {
		return v == 0;
	}

	static final public Int64 ZERO = new Int64(0);
	static final public Int64 ONE = new Int64(1);
}

class QuickSort extends AbstractSort {

	private static Random RANDOM = new Random();

	

	
	public <T> void sort(StaticArray<T> list, int start, int end, Comparator<T> comparator) {
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
	
	public static <T> void swap(StaticArray<T> a, int p1, int p2) {
		T t = a.get(p1);
		a.set(p1, a.get(p2));
		a.set(p2, t);
	}
	
	public static <T> void swap(T[] a, int p1, int p2) {
		swap(new StaticArrayUsingArray<T>(a), p1, p2);				
	}
}

class StaticArrayUsingArray<T> extends AbstractReadableArray<T> implements StaticArray<T> {
	
	final private T[] a;
	final private int start;
	final private int end;
	
	public StaticArrayUsingArray(T[] a) {
		this.a = a;
		start = 0;
		end = a.length-1;
	}
	
	public StaticArrayUsingArray(T[] a, int start, int end) {
		this.a = a;
		this.start = start;
		this.end = end;
	}
	
	public StaticArrayUsingArray(T[] a, int n) {
		this.a = a;
		this.start = 0;
		this.end = n-1;
	}	

	public T get(int arg0) {
		return a[start+arg0];
	}
	
	public void set(int arg0, T arg1) {
		a[start+arg0] = arg1;
	}

	public int size() {
		return end-start+1;
	}
	
}

abstract class AbstractSort implements Sort {
	
	

	
	public abstract <T> void sort(StaticArray<T> a, int start, int end, Comparator<T> comparator);
	
	public <T extends Comparable<T>> void sort(StaticArray<T> a) {
		sort(a, 0, a.size()-1);		
	}
	
	public <T> void sort(StaticArray<T> a, Comparator<T> comparator) {
		sort(a, 0, a.size()-1, comparator);		
	}
	
	public <T extends Comparable<T>> void sort(StaticArray<T> a, int start, int end) {
		sort(a, start, end, new DefaultComparator<T>());		
	}

}

class DefaultComparator<T> implements Comparator<T> {
	

	@SuppressWarnings("unchecked")
	public int compare(T arg0, T arg1) {
		return ((Comparable<T>)arg0).compareTo(arg1);
	}

}

interface Sort {
	

	<T> void sort(StaticArray<T> a, int start, int end, Comparator<T> comparator);
	<T> void sort(StaticArray<T> a, Comparator<T> comparator);
	<T extends Comparable<T>> void sort(StaticArray<T> a);
	<T extends Comparable<T>> void sort(StaticArray<T> a, int start, int end);
}