import java.io.*;
import java.util.*;

public class d567{
	
    public static void main(String[] args) {
    	FastReader scan = new FastReader();
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		
		Task solver = new Task();
		
		int t = 1;
		for(int i = 1; i <= t; i++) solver.solve(i, scan, out);
		out.close();
    }
    
	static class Task {

		public void solve(int testNumber, FastReader sc, PrintWriter out) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			int Q = sc.nextInt();
			
			tup[] pq = new tup[M];
			for(int i = 0; i < N; i++) {
				int l = sc.nextInt()-1;
				if(pq[l] == null) {
					pq[l] = new tup(l, 0);
				}
				pq[l].b++;
			}
			for(int i = 0; i < M; i++) {
				if(pq[i] == null)
					pq[i] = new tup(i, 0);
			}
			sort(pq);
 
			int[] pSum = new int[M];
			pSum[0] = pq[0].b;
			for(int i = 1; i < M; i++) {
				pSum[i] = pSum[i-1] + pq[i].b;
			}
			
			
			PriorityQueue<tup> queries = new PriorityQueue<>(new comp());
			long[] ans = new long[Q];
 
			for(int i = 0; i < Q; i++) {
				queries.add(new tup(sc.nextLong(), i));
			}
			id41<Long> counted = new id41<>();
			int last = -1;
			while(queries.size() > 0) {
				tup t = queries.poll();
				long id27 = t.a - N;
				
				int X = binarySearch(pq, id27, pSum, last);
				
				if(X > last) {
					for(int i = last+1; i < X; i++) {
						counted.add(pq[i].a);
					}
					last = X-1;
				}
				
				int ext = (int)((id27 - ((long)X * pq[(int)X-1].b - pSum[(int)X-1]) - 1) % X);
				ans[t.b] = counted.exact((int)ext)+1; 
			}
			
			for(long each: ans)
				out.println(each);			
		}
		
		public static int binarySearch(tup arr[], long id27, int[] pSum, int lo) 
	    { 
			lo = Math.max(0, lo);
	        int hi = arr.length - 1; 
	        while (lo <= hi) { 
	            int mid = (lo + hi) / 2; 
	              if ((long)mid * arr[mid].b < id27) 
	                lo = mid + 1; 
	              else
	                hi = mid - 1; 
	        } 
	        
	        lo = Math.min(lo, arr.length-1);
	        lo = Math.max(0, lo);
	        while(lo >= 0 && (long)lo * arr[lo].b - psum(lo-1, pSum) > id27)
	        	lo--;
	        while(lo < arr.length && (long)lo * arr[lo].b - psum(lo-1, pSum) < id27)
	        	lo++;
	        return lo;
	    } 
	}
	
	public static int psum(int index, int[] pSum) {
		if(index < 0)
			return 0;
		return pSum[index];
	}
	
	static void sort(tup[] x){
		shuffle(x);
		Arrays.sort(x, new tup());
	}
	
	static class comp implements Comparator<tup> {

		@Override
		public int compare(tup o1, tup o2) {
			return Long.compare(o1.a, o2.a);
		}
		
	}
	
	static class tup implements Comparator<tup>{
		long a; int b;
		tup(long a, int b){
			this.a=a;
			this.b=b;
		}
		public tup() {
		}
		@Override
		public int compare(tup o1, tup o2) {
			return o1.b == o2.b ? Long.compare(o1.a, o2.a) : Integer.compare(o1.b,  o2.b);
		}
		
		@Override
	    public int hashCode() {
			return Objects.hash(a, b);
	    }
 
	    @Override
	    public boolean equals(Object obj) {
	    	if (this == obj)
                return true;
	    	if (obj == null)
                return false;
	    	if (getClass() != obj.getClass())
                return false;
	    	tup other = (tup) obj;
	    	return a==other.a && b==other.b;
	    }
	    
	    @Override
	    public String toString() {
	    	return a + " " + b;
	    }
	}

	static void shuffle(tup[] a) {
		Random get = new Random();
		for (int i = 0; i < a.length; i++) {
			int r = get.nextInt(a.length);
			tup temp = a[i];
			a[i] = a[r];
			a[r] = temp;
		}
	}

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastReader(String s) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(new File(s)));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
	
	public static class id41<E> extends java.util.AbstractSet<E>
    implements id22<E>, Cloneable, java.io.Serializable {

private transient NavigableMap<E, Object> m;


private static final Object PRESENT = new Object();


id41(NavigableMap<E, Object> m) {
    if (!(m instanceof id30)) {
        throw new IllegalArgumentException("Map should implement id30");
    }
    this.m = m;
}


public id41() {
    this(new id30<E, Object>());
}


public id41(Comparator<? super E> comparator) {
    this(new id30<E, Object>(comparator));
}


public id41(Collection<? extends E> c) {
    this();
    addAll(c);
}


public id41(SortedSet<E> s) {
    this(s.comparator());
    addAll(s);
}


public Iterator<E> iterator() {
    return m.id38().iterator();
}


public Iterator<E> descendingIterator() {
    return m.id24().iterator();
}


public NavigableSet<E> descendingSet() {
    return new id41(m.descendingMap());
}


public int size() {
    return m.size();
}


public boolean isEmpty() {
    return m.isEmpty();
}


public boolean contains(Object o) {
    return m.containsKey(o);
}


public boolean add(E e) {
    return m.put(e, PRESENT) == null;
}


public boolean remove(Object o) {
    return m.remove(o) == PRESENT;
}


public void clear() {
    m.clear();
}


public boolean addAll(Collection<? extends E> c) {
    
    if (m.size() == 0 && c.size() > 0 &&
            c instanceof SortedSet &&
            m instanceof id30) {
        SortedSet<? extends E> set = (SortedSet<? extends E>) c;
        id30<E, Object> map = (id30<E, Object>) m;
        Comparator<? super E> cc = (Comparator<? super E>) set.comparator();
        Comparator<? super E> mc = map.comparator();
        if (cc == mc || (cc != null && cc.equals(mc))) {
            map.id42(set, PRESENT);
            return true;
        }
    }
    return super.addAll(c);
}


public NavigableSet<E> subSet(E fromElement, boolean fromInclusive,
                              E toElement, boolean toInclusive) {
    return new id41<E>(m.subMap(fromElement, fromInclusive,
            toElement, toInclusive));
}


public NavigableSet<E> headSet(E toElement, boolean inclusive) {
    return new id41<E>(m.headMap(toElement, inclusive));
}


public NavigableSet<E> tailSet(E fromElement, boolean inclusive) {
    return new id41<E>(m.tailMap(fromElement, inclusive));
}


public SortedSet<E> subSet(E fromElement, E toElement) {
    return subSet(fromElement, true, toElement, false);
}


public SortedSet<E> headSet(E toElement) {
    return headSet(toElement, false);
}


public SortedSet<E> tailSet(E fromElement) {
    return tailSet(fromElement, true);
}

public Comparator<? super E> comparator() {
    return m.comparator();
}


public E first() {
    return m.firstKey();
}


public E last() {
    return m.lastKey();
}




public E lower(E e) {
    return m.lowerKey(e);
}


public E floor(E e) {
    return m.floorKey(e);
}


public E ceiling(E e) {
    return m.id25(e);
}


public E higher(E e) {
    return m.higherKey(e);
}


public E pollFirst() {
    Map.Entry<E, ?> e = m.id48();
    return (e == null) ? null : e.getKey();
}


public E pollLast() {
    Map.Entry<E, ?> e = m.id7();
    return (e == null) ? null : e.getKey();
}


public Object clone() {
    id41<E> clone = null;
    try {
        clone = (id41<E>) super.clone();
    } catch (CloneNotSupportedException e) {
        throw new InternalError();
    }

    clone.m = new id30<E, Object>(m);
    return clone;
}


private void writeObject(java.io.ObjectOutputStream s)
        throws java.io.IOException {
    
    s.defaultWriteObject();

    
    s.writeObject(m.comparator());

    
    s.writeInt(m.size());

    
    for (Iterator i = m.keySet().iterator(); i.hasNext(); )
        s.writeObject(i.next());
}


private void readObject(java.io.ObjectInputStream s)
        throws java.io.IOException, ClassNotFoundException {
    
    s.defaultReadObject();

    
    Comparator<? super E> c = (Comparator<? super E>) s.readObject();

    
    id30<E, Object> tm;
    if (c == null)
        tm = new id30<E, Object>();
    else
        tm = new id30<E, Object>(c);
    m = tm;

    
    int size = s.readInt();

    tm.id47(size, s, PRESENT);
}

private static final long id40 = -2479143000061671589L;

public E exact(int index) {
    Map.Entry<E, ?> e = ((id53) m).exactEntry(index);
    return (e == null) ? null : e.getKey();
}

public int entryIndex(E e) {
    return ((id53) m).keyIndex(e);
}

public void debug() throws Exception {
    id30.Entry e = ((id30) m).id46();
    while (e != null) {



        if (e.weight != e.sumup()) {
            throw new Exception("Weight is incorrect:" + e.weight + "!=" + e.sumup() + " for " + e.key);
        }
        e = ((id30) m).successor(e);
    }
}
}

	public static interface id22<E> extends NavigableSet<E> {
	    
	    E exact(int index);
	    
	    int entryIndex(E e);
	}

	public static class id30<K, V>
    extends AbstractMap<K, V>
    implements id53<K, V>, Cloneable, java.io.Serializable {

private final Comparator<? super K> comparator;

private transient Entry<K, V> root = null;


private transient int size = 0;


private transient int modCount = 0;


public id30() {
    comparator = null;
}


public id30(Comparator<? super K> comparator) {
    this.comparator = comparator;
}


public id30(Map<? extends K, ? extends V> m) {
    comparator = null;
    putAll(m);
}


public id30(SortedMap<K, ? extends V> m) {
    comparator = m.comparator();
    try {
        id11(m.size(), m.entrySet().iterator(), null, null);
    } catch (java.io.IOException cannotHappen) {
    } catch (ClassNotFoundException cannotHappen) {
    }
}





public int size() {
    return size;
}


public boolean containsKey(Object key) {
    return getEntry(key) != null;
}


public boolean containsValue(Object value) {
    for (Entry<K, V> e = id46(); e != null; e = successor(e))
        if (valEquals(value, e.value))
            return true;
    return false;
}


public V get(Object key) {
    Entry<K, V> p = getEntry(key);
    return (p == null ? null : p.value);
}

public Comparator<? super K> comparator() {
    return comparator;
}


public K firstKey() {
    return key(id46());
}


public K lastKey() {
    return key(id13());
}


public void putAll(Map<? extends K, ? extends V> map) {
    int mapSize = map.size();
    if (size == 0 && mapSize != 0 && map instanceof SortedMap) {
        Comparator c = ((SortedMap) map).comparator();
        if (c == comparator || (c != null && c.equals(comparator))) {
            ++modCount;
            try {
                id11(mapSize, map.entrySet().iterator(),
                        null, null);
            } catch (java.io.IOException cannotHappen) {
            } catch (ClassNotFoundException cannotHappen) {
            }
            return;
        }
    }
    super.putAll(map);
}


final Entry<K, V> getEntry(Object key) {
    
    if (comparator != null)
        return id31(key);
    if (key == null)
        throw new NullPointerException();
    Comparable<? super K> k = (Comparable<? super K>) key;
    Entry<K, V> p = root;
    while (p != null) {
        int cmp = k.compareTo(p.key);
        if (cmp < 0)
            p = p.left;
        else if (cmp > 0)
            p = p.right;
        else
            return p;
    }
    return null;
}


final Entry<K, V> id31(Object key) {
    K k = (K) key;
    Comparator<? super K> cpr = comparator;
    if (cpr != null) {
        Entry<K, V> p = root;
        while (p != null) {
            int cmp = cpr.compare(k, p.key);
            if (cmp < 0)
                p = p.left;
            else if (cmp > 0)
                p = p.right;
            else
                return p;
        }
    }
    return null;
}


final Entry<K, V> id9(K key) {
    Entry<K, V> p = root;
    while (p != null) {
        int cmp = compare(key, p.key);
        if (cmp < 0) {
            if (p.left != null)
                p = p.left;
            else
                return p;
        } else if (cmp > 0) {
            if (p.right != null) {
                p = p.right;
            } else {
                Entry<K, V> parent = p.parent;
                Entry<K, V> ch = p;
                while (parent != null && ch == parent.right) {
                    ch = parent;
                    parent = parent.parent;
                }
                return parent;
            }
        } else
            return p;
    }
    return null;
}


final Entry<K, V> id43(K key) {
    Entry<K, V> p = root;
    while (p != null) {
        int cmp = compare(key, p.key);
        if (cmp > 0) {
            if (p.right != null)
                p = p.right;
            else
                return p;
        } else if (cmp < 0) {
            if (p.left != null) {
                p = p.left;
            } else {
                Entry<K, V> parent = p.parent;
                Entry<K, V> ch = p;
                while (parent != null && ch == parent.left) {
                    ch = parent;
                    parent = parent.parent;
                }
                return parent;
            }
        } else
            return p;

    }
    return null;
}


public void debug() throws Exception {
    Entry<K, V> e = id46();
    while (e != null) {



        if (e.weight != e.sumup()) {
            throw new Exception("Weight is incorrect:" + e.weight + "!=" + e.sumup() + " for " + e.key);
        }
        e = successor(e);
    }
}

public void dbg() {
    Entry<K, V> e = id46();
    while (e != null) {
        String l = e.left == null ? "null" : "   " + e.left.key.toString();
        String r = e.right == null ? "null" : "   " + e.right.key.toString();
        System.out.println(e.key + ":" + l + ":" + r + ":" + e.weight);
        e = successor(e);
    }
}


final Entry<K, V> id20(K key) {
    Entry<K, V> p = root;
    while (p != null) {
        int cmp = compare(key, p.key);
        if (cmp < 0) {
            if (p.left != null)
                p = p.left;
            else
                return p;
        } else {
            if (p.right != null) {
                p = p.right;
            } else {
                Entry<K, V> parent = p.parent;
                Entry<K, V> ch = p;
                while (parent != null && ch == parent.right) {
                    ch = parent;
                    parent = parent.parent;
                }
                return parent;
            }
        }
    }
    return null;
}


final Entry<K, V> id52(K key) {
    Entry<K, V> p = root;
    while (p != null) {
        int cmp = compare(key, p.key);
        if (cmp > 0) {
            if (p.right != null)
                p = p.right;
            else
                return p;
        } else {
            if (p.left != null) {
                p = p.left;
            } else {
                Entry<K, V> parent = p.parent;
                Entry<K, V> ch = p;
                while (parent != null && ch == parent.left) {
                    ch = parent;
                    parent = parent.parent;
                }
                return parent;
            }
        }
    }
    return null;
}


public V put(K key, V value) {
    Entry<K, V> t = root;
    if (t == null) {
        
        
        
        
        
        root = new Entry<K, V>(key, value, null);
        root.weight = 1;
        size = 1;
        modCount++;
        return null;
    }
    int cmp;
    Entry<K, V> parent;
    
    Comparator<? super K> cpr = comparator;
    if (cpr != null) {
        do {
            parent = t;
            cmp = cpr.compare(key, t.key);
            if (cmp < 0)
                t = t.left;
            else if (cmp > 0)
                t = t.right;
            else
                return t.setValue(value);
        } while (t != null);
    } else {
        if (key == null)
            throw new NullPointerException();
        Comparable<? super K> k = (Comparable<? super K>) key;
        do {
            parent = t;
            cmp = k.compareTo(t.key);
            if (cmp < 0)
                t = t.left;
            else if (cmp > 0)
                t = t.right;
            else
                return t.setValue(value);
        } while (t != null);
    }
    Entry<K, V> e = new Entry<K, V>(key, value, parent);
    if (cmp < 0) {
        parent.left = e;
    } else {
        parent.right = e;
    }
    e.updateWeight(1);

    id51(e);
    size++;
    modCount++;
    return null;
}


public V remove(Object key) {
    Entry<K, V> p = getEntry(key);
    if (p == null)
        return null;

    V oldValue = p.value;
    deleteEntry(p);
    return oldValue;
}


public void clear() {
    modCount++;
    size = 0;
    root = null;
}


public Object clone() {
    id30<K, V> clone = null;
    try {
        clone = (id30<K, V>) super.clone();
    } catch (CloneNotSupportedException e) {
        throw new InternalError();
    }

    
    clone.root = null;
    clone.size = 0;
    clone.modCount = 0;
    clone.entrySet = null;
    clone.id38 = null;
    clone.descendingMap = null;

    
    try {
        clone.id11(size, entrySet().iterator(), null, null);
    } catch (java.io.IOException cannotHappen) {
    } catch (ClassNotFoundException cannotHappen) {
    }

    return clone;
}




public Map.Entry<K, V> firstEntry() {
    return exportEntry(id46());
}


public Map.Entry<K, V> lastEntry() {
    return exportEntry(id13());
}


public Map.Entry<K, V> id48() {
    Entry<K, V> p = id46();
    Map.Entry<K, V> result = exportEntry(p);
    if (p != null)
        deleteEntry(p);
    return result;
}


public Map.Entry<K, V> id7() {
    Entry<K, V> p = id13();
    Map.Entry<K, V> result = exportEntry(p);
    if (p != null)
        deleteEntry(p);
    return result;
}


public Map.Entry<K, V> lowerEntry(K key) {
    return exportEntry(id52(key));
}


public K lowerKey(K key) {
    return id15(id52(key));
}


public Map.Entry<K, V> floorEntry(K key) {
    return exportEntry(id43(key));
}


public K floorKey(K key) {
    return id15(id43(key));
}


public Map.Entry<K, V> id14(K key) {
    return exportEntry(id9(key));
}


public K id25(K key) {
    return id15(id9(key));
}


public Map.Entry<K, V> higherEntry(K key) {
    return exportEntry(id20(key));
}


public K higherKey(K key) {
    return id15(id20(key));
}

public K exactKey(int index) {
    if (index < 0 || index > size() - 1) {
        throw new ArrayIndexOutOfBoundsException();
    }
    return id37(root, index);
}

private K id37(Entry<K, V> e, int index) {
    if (e.left == null && index == 0) {
        return e.key;
    }
    if (e.left == null && e.right == null) {
        return e.key;
    }
    if (e.left != null && e.left.weight > index) {
        return id37(e.left, index);
    }
    if (e.left != null && e.left.weight == index) {
        return e.key;
    }
    return id37(e.right, index - (e.left == null ? 0 : e.left.weight) - 1);
}

public int keyIndex(K key) {
    if (key == null) {
        throw new NullPointerException();
    }
    Entry<K, V> e = getEntry(key);
    if (e == null) {
        throw new NullPointerException();
    }
    if (e == root) {
        return getWeight(e) - getWeight(e.right) - 1;
    }
    int index = 0;
    int cmp;
    index += getWeight(e.left);
    Entry<K, V> p = e.parent;
    
    Comparator<? super K> cpr = comparator;
    if (cpr != null) {
        while (p != null) {
            cmp = cpr.compare(key, p.key);
            if (cmp > 0) {
                index += getWeight(p.left) + 1;
            }
            p = p.parent;
        }
    } else {
        Comparable<? super K> k = (Comparable<? super K>) key;
        while (p != null) {
            if (k.compareTo(p.key) > 0) {
                index += getWeight(p.left) + 1;
            }
            p = p.parent;
        }
    }
    return index;
}


public Entry<K, V> exactEntry(int index) {
    return id0(root, index);
}

private Entry<K, V> id0(Entry<K, V> e, int index) {
    if (e.left == null && index == 0) {
        return e;
    }
    if (e.left == null && e.right == null) {
        return e;
    }
    if (e.left != null && e.left.weight > index) {
        return id0(e.left, index);
    }
    if (e.left != null && e.left.weight == index) {
        return e;
    }
    return id0(e.right, index - (e.left == null ? 0 : e.left.weight) - 1);
}





private transient EntrySet entrySet = null;
private transient KeySet<K> id38 = null;
private transient NavigableMap<K, V> descendingMap = null;


public Set<K> keySet() {
    return id38();
}


public NavigableSet<K> id38() {
    KeySet<K> nks = id38;
    return (nks != null) ? nks : (id38 = new KeySet(this));
}


public NavigableSet<K> id24() {
    return descendingMap().id38();
}


public Set<Map.Entry<K, V>> entrySet() {
    EntrySet es = entrySet;
    return (es != null) ? es : (entrySet = new EntrySet());
}


public NavigableMap<K, V> descendingMap() {
    NavigableMap<K, V> km = descendingMap;
    return (km != null) ? km :
            (descendingMap = new id44(this,
                    true, null, true,
                    true, null, true));
}


public NavigableMap<K, V> subMap(K fromKey, boolean fromInclusive,
                                 K toKey, boolean toInclusive) {
    return new id12(this,
            false, fromKey, fromInclusive,
            false, toKey, toInclusive);
}


public NavigableMap<K, V> headMap(K toKey, boolean inclusive) {
    return new id12(this,
            true, null, true,
            false, toKey, inclusive);
}


public NavigableMap<K, V> tailMap(K fromKey, boolean inclusive) {
    return new id12(this,
            false, fromKey, inclusive,
            true, null, true);
}


public SortedMap<K, V> subMap(K fromKey, K toKey) {
    return subMap(fromKey, true, toKey, false);
}


public SortedMap<K, V> headMap(K toKey) {
    return headMap(toKey, false);
}


public SortedMap<K, V> tailMap(K fromKey) {
    return tailMap(fromKey, true);
}




class Values extends AbstractCollection<V> {
    public Iterator<V> iterator() {
        return new ValueIterator(id46());
    }

    public int size() {
        return id30.this.size();
    }

    public boolean contains(Object o) {
        return id30.this.containsValue(o);
    }

    public boolean remove(Object o) {
        for (Entry<K, V> e = id46(); e != null; e = successor(e)) {
            if (valEquals(e.getValue(), o)) {
                deleteEntry(e);
                return true;
            }
        }
        return false;
    }

    public void clear() {
        id30.this.clear();
    }
}

class EntrySet extends AbstractSet<Map.Entry<K, V>> {
    public Iterator<Map.Entry<K, V>> iterator() {
        return new EntryIterator(id46());
    }

    public boolean contains(Object o) {
        if (!(o instanceof Map.Entry))
            return false;
        Map.Entry<K, V> entry = (Map.Entry<K, V>) o;
        V value = entry.getValue();
        Entry<K, V> p = getEntry(entry.getKey());
        return p != null && valEquals(p.getValue(), value);
    }

    public boolean remove(Object o) {
        if (!(o instanceof Map.Entry))
            return false;
        Map.Entry<K, V> entry = (Map.Entry<K, V>) o;
        V value = entry.getValue();
        Entry<K, V> p = getEntry(entry.getKey());
        if (p != null && valEquals(p.getValue(), value)) {
            deleteEntry(p);
            return true;
        }
        return false;
    }

    public int size() {
        return id30.this.size();
    }

    public void clear() {
        id30.this.clear();
    }
}



Iterator<K> keyIterator() {
    return new KeyIterator(id46());
}

Iterator<K> id1() {
    return new id34(id13());
}

static final class KeySet<E> extends AbstractSet<E> implements NavigableSet<E> {
    private final NavigableMap<E, Object> m;

    KeySet(NavigableMap<E, Object> map) {
        m = map;
    }

    public Iterator<E> iterator() {
        if (m instanceof id30)
            return ((id30<E, Object>) m).keyIterator();
        else
            return (Iterator<E>) (((id30.id29) m).keyIterator());
    }

    public Iterator<E> descendingIterator() {
        if (m instanceof id30)
            return ((id30<E, Object>) m).id1();
        else
            return (Iterator<E>) (((id30.id29) m).id1());
    }

    public int size() {
        return m.size();
    }

    public boolean isEmpty() {
        return m.isEmpty();
    }

    public boolean contains(Object o) {
        return m.containsKey(o);
    }

    public void clear() {
        m.clear();
    }

    public E lower(E e) {
        return m.lowerKey(e);
    }

    public E floor(E e) {
        return m.floorKey(e);
    }

    public E ceiling(E e) {
        return m.id25(e);
    }

    public E higher(E e) {
        return m.higherKey(e);
    }

    public E first() {
        return m.firstKey();
    }

    public E last() {
        return m.lastKey();
    }

    public Comparator<? super E> comparator() {
        return m.comparator();
    }

    public E pollFirst() {
        Map.Entry<E, Object> e = m.id48();
        return e == null ? null : e.getKey();
    }

    public E pollLast() {
        Map.Entry<E, Object> e = m.id7();
        return e == null ? null : e.getKey();
    }

    public boolean remove(Object o) {
        int oldSize = size();
        m.remove(o);
        return size() != oldSize;
    }

    public NavigableSet<E> subSet(E fromElement, boolean fromInclusive,
                                  E toElement, boolean toInclusive) {
        return new id41<E>(m.subMap(fromElement, fromInclusive,
                toElement, toInclusive));
    }

    public NavigableSet<E> headSet(E toElement, boolean inclusive) {
        return new id41<E>(m.headMap(toElement, inclusive));
    }

    public NavigableSet<E> tailSet(E fromElement, boolean inclusive) {
        return new id41<E>(m.tailMap(fromElement, inclusive));
    }

    public SortedSet<E> subSet(E fromElement, E toElement) {
        return subSet(fromElement, true, toElement, false);
    }

    public SortedSet<E> headSet(E toElement) {
        return headSet(toElement, false);
    }

    public SortedSet<E> tailSet(E fromElement) {
        return tailSet(fromElement, true);
    }

    public NavigableSet<E> descendingSet() {
        return new id41(m.descendingMap());
    }
}


abstract class id4<T> implements Iterator<T> {
    Entry<K, V> next;
    Entry<K, V> lastReturned;
    int id49;

    id4(Entry<K, V> first) {
        id49 = modCount;
        lastReturned = null;
        next = first;
    }

    public final boolean hasNext() {
        return next != null;
    }

    final Entry<K, V> nextEntry() {
        Entry<K, V> e = next;
        if (e == null)
            throw new NoSuchElementException();
        if (modCount != id49)
            throw new ConcurrentModificationException();
        next = successor(e);
        lastReturned = e;
        return e;
    }

    final Entry<K, V> prevEntry() {
        Entry<K, V> e = next;
        if (e == null)
            throw new NoSuchElementException();
        if (modCount != id49)
            throw new ConcurrentModificationException();
        next = id28(e);
        lastReturned = e;
        return e;
    }

    public void remove() {
        if (lastReturned == null)
            throw new IllegalStateException();
        if (modCount != id49)
            throw new ConcurrentModificationException();
        
        if (lastReturned.left != null && lastReturned.right != null)
            next = lastReturned;
        deleteEntry(lastReturned);
        id49 = modCount;
        lastReturned = null;
    }
}

final class EntryIterator extends id4<Map.Entry<K, V>> {
    EntryIterator(Entry<K, V> first) {
        super(first);
    }

    public Map.Entry<K, V> next() {
        return nextEntry();
    }
}

final class ValueIterator extends id4<V> {
    ValueIterator(Entry<K, V> first) {
        super(first);
    }

    public V next() {
        return nextEntry().value;
    }
}

final class KeyIterator extends id4<K> {
    KeyIterator(Entry<K, V> first) {
        super(first);
    }

    public K next() {
        return nextEntry().key;
    }
}

final class id34 extends id4<K> {
    id34(Entry<K, V> first) {
        super(first);
    }

    public K next() {
        return prevEntry().key;
    }
}




final int compare(Object k1, Object k2) {
    return comparator == null ? ((Comparable<? super K>) k1).compareTo((K) k2)
            : comparator.compare((K) k1, (K) k2);
}


final static boolean valEquals(Object o1, Object o2) {
    return (o1 == null ? o2 == null : o1.equals(o2));
}


static <K, V> Map.Entry<K, V> exportEntry(id30.Entry<K, V> e) {
    return e == null ? null :
            new java.util.AbstractMap.SimpleImmutableEntry<K, V>(e);
}


static <K, V> K id15(id30.Entry<K, V> e) {
    return e == null ? null : e.key;
}


static <K> K key(Entry<K, ?> e) {
    if (e == null)
        throw new NoSuchElementException();
    return e.key;
}





static abstract class id29<K, V> extends java.util.AbstractMap<K, V>
        implements NavigableMap<K, V>, java.io.Serializable {
    
    final id30<K, V> m;

    
    final K lo, hi;
    final boolean fromStart, toEnd;
    final boolean loInclusive, hiInclusive;

    id29(id30<K, V> m,
                    boolean fromStart, K lo, boolean loInclusive,
                    boolean toEnd, K hi, boolean hiInclusive) {
        if (!fromStart && !toEnd) {
            if (m.compare(lo, hi) > 0)
                throw new IllegalArgumentException("fromKey > toKey");
        } else {
            if (!fromStart) 
                m.compare(lo, lo);
            if (!toEnd)
                m.compare(hi, hi);
        }

        this.m = m;
        this.fromStart = fromStart;
        this.lo = lo;
        this.loInclusive = loInclusive;
        this.toEnd = toEnd;
        this.hi = hi;
        this.hiInclusive = hiInclusive;
    }

    

    final boolean tooLow(Object key) {
        if (!fromStart) {
            int c = m.compare(key, lo);
            if (c < 0 || (c == 0 && !loInclusive))
                return true;
        }
        return false;
    }

    final boolean tooHigh(Object key) {
        if (!toEnd) {
            int c = m.compare(key, hi);
            if (c > 0 || (c == 0 && !hiInclusive))
                return true;
        }
        return false;
    }

    final boolean inRange(Object key) {
        return !tooLow(key) && !tooHigh(key);
    }

    final boolean id6(Object key) {
        return (fromStart || m.compare(key, lo) >= 0)
                && (toEnd || m.compare(hi, key) >= 0);
    }

    final boolean inRange(Object key, boolean inclusive) {
        return inclusive ? inRange(key) : id6(key);
    }

    

    final id30.Entry<K, V> absLowest() {
        id30.Entry<K, V> e =
                (fromStart ? m.id46() :
                        (loInclusive ? m.id9(lo) :
                                m.id20(lo)));
        return (e == null || tooHigh(e.key)) ? null : e;
    }

    final id30.Entry<K, V> absHighest() {
        id30.Entry<K, V> e =
                (toEnd ? m.id13() :
                        (hiInclusive ? m.id43(hi) :
                                m.id52(hi)));
        return (e == null || tooLow(e.key)) ? null : e;
    }

    final id30.Entry<K, V> id54(K key) {
        if (tooLow(key))
            return absLowest();
        id30.Entry<K, V> e = m.id9(key);
        return (e == null || tooHigh(e.key)) ? null : e;
    }

    final id30.Entry<K, V> absHigher(K key) {
        if (tooLow(key))
            return absLowest();
        id30.Entry<K, V> e = m.id20(key);
        return (e == null || tooHigh(e.key)) ? null : e;
    }

    final id30.Entry<K, V> absFloor(K key) {
        if (tooHigh(key))
            return absHighest();
        id30.Entry<K, V> e = m.id43(key);
        return (e == null || tooLow(e.key)) ? null : e;
    }

    final id30.Entry<K, V> absLower(K key) {
        if (tooHigh(key))
            return absHighest();
        id30.Entry<K, V> e = m.id52(key);
        return (e == null || tooLow(e.key)) ? null : e;
    }

    
    final id30.Entry<K, V> id33() {
        return (toEnd ? null : (hiInclusive ?
                m.id20(hi) :
                m.id9(hi)));
    }

    
    final id30.Entry<K, V> id32() {
        return (fromStart ? null : (loInclusive ?
                m.id52(lo) :
                m.id43(lo)));
    }

    
    

    abstract id30.Entry<K, V> subLowest();

    abstract id30.Entry<K, V> subHighest();

    abstract id30.Entry<K, V> id21(K key);

    abstract id30.Entry<K, V> subHigher(K key);

    abstract id30.Entry<K, V> subFloor(K key);

    abstract id30.Entry<K, V> subLower(K key);

    
    abstract Iterator<K> keyIterator();

    
    abstract Iterator<K> id1();

    

    public boolean isEmpty() {
        return (fromStart && toEnd) ? m.isEmpty() : entrySet().isEmpty();
    }

    public int size() {
        return (fromStart && toEnd) ? m.size() : entrySet().size();
    }

    public final boolean containsKey(Object key) {
        return inRange(key) && m.containsKey(key);
    }

    public final V put(K key, V value) {
        if (!inRange(key))
            throw new IllegalArgumentException("key out of range");
        return m.put(key, value);
    }

    public final V get(Object key) {
        return !inRange(key) ? null : m.get(key);
    }

    public final V remove(Object key) {
        return !inRange(key) ? null : m.remove(key);
    }

    public final Map.Entry<K, V> id14(K key) {
        return exportEntry(id21(key));
    }

    public final K id25(K key) {
        return id15(id21(key));
    }

    public final Map.Entry<K, V> higherEntry(K key) {
        return exportEntry(subHigher(key));
    }

    public final K higherKey(K key) {
        return id15(subHigher(key));
    }

    public final Map.Entry<K, V> floorEntry(K key) {
        return exportEntry(subFloor(key));
    }

    public final K floorKey(K key) {
        return id15(subFloor(key));
    }

    public final Map.Entry<K, V> lowerEntry(K key) {
        return exportEntry(subLower(key));
    }

    public final K lowerKey(K key) {
        return id15(subLower(key));
    }

    public final K firstKey() {
        return key(subLowest());
    }

    public final K lastKey() {
        return key(subHighest());
    }

    public final Map.Entry<K, V> firstEntry() {
        return exportEntry(subLowest());
    }

    public final Map.Entry<K, V> lastEntry() {
        return exportEntry(subHighest());
    }

    public final Map.Entry<K, V> id48() {
        id30.Entry<K, V> e = subLowest();
        Map.Entry<K, V> result = exportEntry(e);
        if (e != null)
            m.deleteEntry(e);
        return result;
    }

    public final Map.Entry<K, V> id7() {
        id30.Entry<K, V> e = subHighest();
        Map.Entry<K, V> result = exportEntry(e);
        if (e != null)
            m.deleteEntry(e);
        return result;
    }

    
    transient NavigableMap<K, V> id2 = null;
    transient id5 id26 = null;
    transient KeySet<K> id23 = null;

    public final NavigableSet<K> id38() {
        KeySet<K> id50 = id23;
        return (id50 != null) ? id50 :
                (id23 = new id30.KeySet(this));
    }

    public final Set<K> keySet() {
        return id38();
    }

    public NavigableSet<K> id24() {
        return descendingMap().id38();
    }

    public final SortedMap<K, V> subMap(K fromKey, K toKey) {
        return subMap(fromKey, true, toKey, false);
    }

    public final SortedMap<K, V> headMap(K toKey) {
        return headMap(toKey, false);
    }

    public final SortedMap<K, V> tailMap(K fromKey) {
        return tailMap(fromKey, true);
    }

    

    abstract class id5 extends AbstractSet<Map.Entry<K, V>> {
        private transient int size = -1, id18;

        public int size() {
            if (fromStart && toEnd)
                return m.size();
            if (size == -1 || id18 != m.modCount) {
                id18 = m.modCount;
                size = 0;
                Iterator i = iterator();
                while (i.hasNext()) {
                    size++;
                    i.next();
                }
            }
            return size;
        }

        public boolean isEmpty() {
            id30.Entry<K, V> n = absLowest();
            return n == null || tooHigh(n.key);
        }

        public boolean contains(Object o) {
            if (!(o instanceof Map.Entry))
                return false;
            Map.Entry<K, V> entry = (Map.Entry<K, V>) o;
            K key = entry.getKey();
            if (!inRange(key))
                return false;
            id30.Entry node = m.getEntry(key);
            return node != null &&
                    valEquals(node.getValue(), entry.getValue());
        }

        public boolean remove(Object o) {
            if (!(o instanceof Map.Entry))
                return false;
            Map.Entry<K, V> entry = (Map.Entry<K, V>) o;
            K key = entry.getKey();
            if (!inRange(key))
                return false;
            id30.Entry<K, V> node = m.getEntry(key);
            if (node != null && valEquals(node.getValue(), entry.getValue())) {
                m.deleteEntry(node);
                return true;
            }
            return false;
        }
    }

    
    abstract class id39<T> implements Iterator<T> {
        id30.Entry<K, V> lastReturned;
        id30.Entry<K, V> next;
        final K id45;
        int id49;

        id39(id30.Entry<K, V> first,
                       id30.Entry<K, V> fence) {
            id49 = m.modCount;
            lastReturned = null;
            next = first;
            id45 = fence == null ? null : fence.key;
        }

        public final boolean hasNext() {
            return next != null && next.key != id45;
        }

        final id30.Entry<K, V> nextEntry() {
            id30.Entry<K, V> e = next;
            if (e == null || e.key == id45)
                throw new NoSuchElementException();
            if (m.modCount != id49)
                throw new ConcurrentModificationException();
            next = successor(e);
            lastReturned = e;
            return e;
        }

        final id30.Entry<K, V> prevEntry() {
            id30.Entry<K, V> e = next;
            if (e == null || e.key == id45)
                throw new NoSuchElementException();
            if (m.modCount != id49)
                throw new ConcurrentModificationException();
            next = id28(e);
            lastReturned = e;
            return e;
        }

        final void removeAscending() {
            if (lastReturned == null)
                throw new IllegalStateException();
            if (m.modCount != id49)
                throw new ConcurrentModificationException();
            
            if (lastReturned.left != null && lastReturned.right != null)
                next = lastReturned;
            m.deleteEntry(lastReturned);
            lastReturned = null;
            id49 = m.modCount;
        }

        final void removeDescending() {
            if (lastReturned == null)
                throw new IllegalStateException();
            if (m.modCount != id49)
                throw new ConcurrentModificationException();
            m.deleteEntry(lastReturned);
            lastReturned = null;
            id49 = m.modCount;
        }

    }

    final class id35 extends id39<Map.Entry<K, V>> {
        id35(id30.Entry<K, V> first,
                            id30.Entry<K, V> fence) {
            super(first, fence);
        }

        public Map.Entry<K, V> next() {
            return nextEntry();
        }

        public void remove() {
            removeAscending();
        }
    }

    final class id17 extends id39<K> {
        id17(id30.Entry<K, V> first,
                          id30.Entry<K, V> fence) {
            super(first, fence);
        }

        public K next() {
            return nextEntry().key;
        }

        public void remove() {
            removeAscending();
        }
    }

    final class id36 extends id39<Map.Entry<K, V>> {
        id36(id30.Entry<K, V> last,
                                      id30.Entry<K, V> fence) {
            super(last, fence);
        }

        public Map.Entry<K, V> next() {
            return prevEntry();
        }

        public void remove() {
            removeDescending();
        }
    }

    final class id3 extends id39<K> {
        id3(id30.Entry<K, V> last,
                                    id30.Entry<K, V> fence) {
            super(last, fence);
        }

        public K next() {
            return prevEntry().key;
        }

        public void remove() {
            removeDescending();
        }
    }
}


static final class id12<K, V> extends id29<K, V> {
    private static final long id40 = 912986545866124060L;

    id12(id30<K, V> m,
                    boolean fromStart, K lo, boolean loInclusive,
                    boolean toEnd, K hi, boolean hiInclusive) {
        super(m, fromStart, lo, loInclusive, toEnd, hi, hiInclusive);
    }

    public Comparator<? super K> comparator() {
        return m.comparator();
    }

    public NavigableMap<K, V> subMap(K fromKey, boolean fromInclusive,
                                     K toKey, boolean toInclusive) {
        if (!inRange(fromKey, fromInclusive))
            throw new IllegalArgumentException("fromKey out of range");
        if (!inRange(toKey, toInclusive))
            throw new IllegalArgumentException("toKey out of range");
        return new id12(m,
                false, fromKey, fromInclusive,
                false, toKey, toInclusive);
    }

    public NavigableMap<K, V> headMap(K toKey, boolean inclusive) {
        if (!inRange(toKey, inclusive))
            throw new IllegalArgumentException("toKey out of range");
        return new id12(m,
                fromStart, lo, loInclusive,
                false, toKey, inclusive);
    }

    public NavigableMap<K, V> tailMap(K fromKey, boolean inclusive) {
        if (!inRange(fromKey, inclusive))
            throw new IllegalArgumentException("fromKey out of range");
        return new id12(m,
                false, fromKey, inclusive,
                toEnd, hi, hiInclusive);
    }

    public NavigableMap<K, V> descendingMap() {
        NavigableMap<K, V> mv = id2;
        return (mv != null) ? mv :
                (id2 =
                        new id44(m,
                                fromStart, lo, loInclusive,
                                toEnd, hi, hiInclusive));
    }

    Iterator<K> keyIterator() {
        return new id17(absLowest(), id33());
    }

    Iterator<K> id1() {
        return new id3(absHighest(), id32());
    }

    final class id10 extends id5 {
        public Iterator<Map.Entry<K, V>> iterator() {
            return new id35(absLowest(), id33());
        }
    }

    public Set<Map.Entry<K, V>> entrySet() {
        id5 es = id26;
        return (es != null) ? es : new id10();
    }

    id30.Entry<K, V> subLowest() {
        return absLowest();
    }

    id30.Entry<K, V> subHighest() {
        return absHighest();
    }

    id30.Entry<K, V> id21(K key) {
        return id54(key);
    }

    id30.Entry<K, V> subHigher(K key) {
        return absHigher(key);
    }

    id30.Entry<K, V> subFloor(K key) {
        return absFloor(key);
    }

    id30.Entry<K, V> subLower(K key) {
        return absLower(key);
    }
}


static final class id44<K, V> extends id29<K, V> {
    private static final long id40 = 912986545866120460L;

    id44(id30<K, V> m,
                     boolean fromStart, K lo, boolean loInclusive,
                     boolean toEnd, K hi, boolean hiInclusive) {
        super(m, fromStart, lo, loInclusive, toEnd, hi, hiInclusive);
    }

    private final Comparator<? super K> reverseComparator =
            Collections.reverseOrder(m.comparator);

    public Comparator<? super K> comparator() {
        return reverseComparator;
    }

    public NavigableMap<K, V> subMap(K fromKey, boolean fromInclusive,
                                     K toKey, boolean toInclusive) {
        if (!inRange(fromKey, fromInclusive))
            throw new IllegalArgumentException("fromKey out of range");
        if (!inRange(toKey, toInclusive))
            throw new IllegalArgumentException("toKey out of range");
        return new id44(m,
                false, toKey, toInclusive,
                false, fromKey, fromInclusive);
    }

    public NavigableMap<K, V> headMap(K toKey, boolean inclusive) {
        if (!inRange(toKey, inclusive))
            throw new IllegalArgumentException("toKey out of range");
        return new id44(m,
                false, toKey, inclusive,
                toEnd, hi, hiInclusive);
    }

    public NavigableMap<K, V> tailMap(K fromKey, boolean inclusive) {
        if (!inRange(fromKey, inclusive))
            throw new IllegalArgumentException("fromKey out of range");
        return new id44(m,
                fromStart, lo, loInclusive,
                false, fromKey, inclusive);
    }

    public NavigableMap<K, V> descendingMap() {
        NavigableMap<K, V> mv = id2;
        return (mv != null) ? mv :
                (id2 =
                        new id12(m,
                                fromStart, lo, loInclusive,
                                toEnd, hi, hiInclusive));
    }

    Iterator<K> keyIterator() {
        return new id3(absHighest(), id32());
    }

    Iterator<K> id1() {
        return new id17(absLowest(), id33());
    }

    final class id16 extends id5 {
        public Iterator<Map.Entry<K, V>> iterator() {
            return new id36(absHighest(), id32());
        }
    }

    public Set<Map.Entry<K, V>> entrySet() {
        id5 es = id26;
        return (es != null) ? es : new id16();
    }

    id30.Entry<K, V> subLowest() {
        return absHighest();
    }

    id30.Entry<K, V> subHighest() {
        return absLowest();
    }

    id30.Entry<K, V> id21(K key) {
        return absFloor(key);
    }

    id30.Entry<K, V> subHigher(K key) {
        return absLower(key);
    }

    id30.Entry<K, V> subFloor(K key) {
        return id54(key);
    }

    id30.Entry<K, V> subLower(K key) {
        return absHigher(key);
    }
}


private class SubMap extends AbstractMap<K, V>
        implements SortedMap<K, V>, java.io.Serializable {
    private static final long id40 = -6520786458950516097L;
    private boolean fromStart = false, toEnd = false;
    private K fromKey, toKey;

    private Object readResolve() {
        return new id12(id30.this,
                fromStart, fromKey, true,
                toEnd, toKey, false);
    }

    public Set<Map.Entry<K, V>> entrySet() {
        throw new InternalError();
    }

    public K lastKey() {
        throw new InternalError();
    }

    public K firstKey() {
        throw new InternalError();
    }

    public SortedMap<K, V> subMap(K fromKey, K toKey) {
        throw new InternalError();
    }

    public SortedMap<K, V> headMap(K toKey) {
        throw new InternalError();
    }

    public SortedMap<K, V> tailMap(K fromKey) {
        throw new InternalError();
    }

    public Comparator<? super K> comparator() {
        throw new InternalError();
    }
}




private static final boolean RED = false;
private static final boolean BLACK = true;



static final class Entry<K, V> implements Map.Entry<K, V> {
    K key;
    V value;
    Entry<K, V> left = null;
    Entry<K, V> right = null;
    Entry<K, V> parent;
    boolean color = BLACK;
    int weight = 0;

    int sumup() {
        int left = this.left == null ? 0 : this.left.sumup();
        int right = this.right == null ? 0 : this.right.sumup();
        return left + right + 1;
    }

    void updateWeight(int delta) {
        weight += delta;
        Entry<K, V> p = parent;
        while (p != null) {
            p.weight += delta;
            p = p.parent;
        }
    }

    
    Entry(K key, V value, Entry<K, V> parent) {
        this.key = key;
        this.value = value;
        this.parent = parent;
    }

    
    public K getKey() {
        return key;
    }

    
    public V getValue() {
        return value;
    }

    
    public V setValue(V value) {
        V oldValue = this.value;
        this.value = value;
        return oldValue;
    }

    public boolean equals(Object o) {
        if (!(o instanceof Map.Entry))
            return false;
        Map.Entry<?, ?> e = (Map.Entry<?, ?>) o;

        return valEquals(key, e.getKey()) && valEquals(value, e.getValue());
    }

    public int hashCode() {
        int keyHash = (key == null ? 0 : key.hashCode());
        int valueHash = (value == null ? 0 : value.hashCode());
        return keyHash ^ valueHash;
    }

    public String toString() {
        return key + "=" + value;
    }
}


final Entry<K, V> id46() {
    Entry<K, V> p = root;
    if (p != null)
        while (p.left != null)
            p = p.left;
    return p;
}


final Entry<K, V> id13() {
    Entry<K, V> p = root;
    if (p != null)
        while (p.right != null)
            p = p.right;
    return p;
}


static <K, V> id30.Entry<K, V> successor(Entry<K, V> t) {
    if (t == null)
        return null;
    else if (t.right != null) {
        Entry<K, V> p = t.right;
        while (p.left != null)
            p = p.left;
        return p;
    } else {
        Entry<K, V> p = t.parent;
        Entry<K, V> ch = t;
        while (p != null && ch == p.right) {
            ch = p;
            p = p.parent;
        }
        return p;
    }
}


static <K, V> Entry<K, V> id28(Entry<K, V> t) {
    if (t == null)
        return null;
    else if (t.left != null) {
        Entry<K, V> p = t.left;
        while (p.right != null)
            p = p.right;
        return p;
    } else {
        Entry<K, V> p = t.parent;
        Entry<K, V> ch = t;
        while (p != null && ch == p.left) {
            ch = p;
            p = p.parent;
        }
        return p;
    }
}



private static <K, V> boolean colorOf(Entry<K, V> p) {
    return (p == null ? BLACK : p.color);
}

private static <K, V> Entry<K, V> parentOf(Entry<K, V> p) {
    return (p == null ? null : p.parent);
}

private static <K, V> void setColor(Entry<K, V> p, boolean c) {
    if (p != null)
        p.color = c;
}

private static <K, V> Entry<K, V> leftOf(Entry<K, V> p) {
    return (p == null) ? null : p.left;
}

private static <K, V> Entry<K, V> rightOf(Entry<K, V> p) {
    return (p == null) ? null : p.right;
}

private static <K, V> int getWeight(Entry<K, V> p) {
    return (p == null) ? 0 : p.weight;
}


private void rotateLeft(Entry<K, V> p) {
    if (p != null) {
        Entry<K, V> r = p.right;

        int delta = getWeight(r.left) - getWeight(p.right);
        p.right = r.left;
        p.updateWeight(delta);

        if (r.left != null) {
            r.left.parent = p;
        }

        r.parent = p.parent;


        if (p.parent == null) {
            root = r;
        } else if (p.parent.left == p) {
            delta = getWeight(r) - getWeight(p.parent.left);
            p.parent.left = r;
            p.parent.updateWeight(delta);
        } else {
            delta = getWeight(r) - getWeight(p.parent.right);
            p.parent.right = r;
            p.parent.updateWeight(delta);
        }

        delta = getWeight(p) - getWeight(r.left);
        r.left = p;
        r.updateWeight(delta);

        p.parent = r;
    }
}


private void rotateRight(Entry<K, V> p) {
    if (p != null) {
        Entry<K, V> l = p.left;

        int delta = getWeight(l.right) - getWeight(p.left);
        p.left = l.right;
        p.updateWeight(delta);


        if (l.right != null) {
            l.right.parent = p;
        }

        l.parent = p.parent;

        if (p.parent == null) {
            root = l;
        } else if (p.parent.right == p) {
            delta = getWeight(l) - getWeight(p.parent.right);
            p.parent.right = l;
            p.parent.updateWeight(delta);
        } else {
            delta = getWeight(l) - getWeight(p.parent.left);
            p.parent.left = l;
            p.parent.updateWeight(delta);
        }

        delta = getWeight(p) - getWeight(l.right);
        l.right = p;
        l.updateWeight(delta);

        p.parent = l;
    }
}


private void id51(Entry<K, V> x) {
    x.color = RED;

    while (x != null && x != root && x.parent.color == RED) {
        if (parentOf(x) == leftOf(parentOf(parentOf(x)))) {
            Entry<K, V> y = rightOf(parentOf(parentOf(x)));
            if (colorOf(y) == RED) {
                setColor(parentOf(x), BLACK);
                setColor(y, BLACK);
                setColor(parentOf(parentOf(x)), RED);
                x = parentOf(parentOf(x));
            } else {
                if (x == rightOf(parentOf(x))) {
                    x = parentOf(x);
                    rotateLeft(x);
                }
                setColor(parentOf(x), BLACK);
                setColor(parentOf(parentOf(x)), RED);
                rotateRight(parentOf(parentOf(x)));
            }
        } else {
            Entry<K, V> y = leftOf(parentOf(parentOf(x)));
            if (colorOf(y) == RED) {
                setColor(parentOf(x), BLACK);
                setColor(y, BLACK);
                setColor(parentOf(parentOf(x)), RED);
                x = parentOf(parentOf(x));
            } else {
                if (x == leftOf(parentOf(x))) {
                    x = parentOf(x);
                    rotateRight(x);
                }
                setColor(parentOf(x), BLACK);
                setColor(parentOf(parentOf(x)), RED);
                rotateLeft(parentOf(parentOf(x)));
            }
        }
    }
    root.color = BLACK;
}


private void deleteEntry(Entry<K, V> p) {
    modCount++;
    size--;

    
    
    if (p.left != null && p.right != null) {
        Entry<K, V> s = successor(p);
        p.key = s.key;
        p.value = s.value;
        p = s;
    } 

    
    Entry<K, V> replacement = (p.left != null ? p.left : p.right);

    if (replacement != null) {
        
        replacement.parent = p.parent;
        if (p.parent == null) {
            root = replacement;
        } else if (p == p.parent.left) {
            int delta = getWeight(replacement) - getWeight(p.parent.left);
            p.parent.left = replacement;
            p.parent.updateWeight(delta);
        } else {
            int delta = getWeight(replacement) - getWeight(p.parent.right);
            p.parent.right = replacement;
            p.parent.updateWeight(delta);
        }

        
        p.left = p.right = p.parent = null;

        
        if (p.color == BLACK)
            id8(replacement);
    } else if (p.parent == null) { 
        root = null;
    } else { 
        if (p.color == BLACK)
            id8(p);

        if (p.parent != null) {
            if (p == p.parent.left) {

                p.parent.left = null;

            } else if (p == p.parent.right) {

                p.parent.right = null;

            }

            p.parent.updateWeight(-1);

            p.parent = null;
        }
    }
}


private void id8(Entry<K, V> x) {
    while (x != root && colorOf(x) == BLACK) {
        if (x == leftOf(parentOf(x))) {
            Entry<K, V> sib = rightOf(parentOf(x));

            if (colorOf(sib) == RED) {
                setColor(sib, BLACK);
                setColor(parentOf(x), RED);
                rotateLeft(parentOf(x));
                sib = rightOf(parentOf(x));
            }

            if (colorOf(leftOf(sib)) == BLACK &&
                    colorOf(rightOf(sib)) == BLACK) {
                setColor(sib, RED);
                x = parentOf(x);
            } else {
                if (colorOf(rightOf(sib)) == BLACK) {
                    setColor(leftOf(sib), BLACK);
                    setColor(sib, RED);
                    rotateRight(sib);
                    sib = rightOf(parentOf(x));
                }
                setColor(sib, colorOf(parentOf(x)));
                setColor(parentOf(x), BLACK);
                setColor(rightOf(sib), BLACK);
                rotateLeft(parentOf(x));
                x = root;
            }
        } else { 
            Entry<K, V> sib = leftOf(parentOf(x));

            if (colorOf(sib) == RED) {
                setColor(sib, BLACK);
                setColor(parentOf(x), RED);
                rotateRight(parentOf(x));
                sib = leftOf(parentOf(x));
            }

            if (colorOf(rightOf(sib)) == BLACK &&
                    colorOf(leftOf(sib)) == BLACK) {
                setColor(sib, RED);
                x = parentOf(x);
            } else {
                if (colorOf(leftOf(sib)) == BLACK) {
                    setColor(rightOf(sib), BLACK);
                    setColor(sib, RED);
                    rotateLeft(sib);
                    sib = leftOf(parentOf(x));
                }
                setColor(sib, colorOf(parentOf(x)));
                setColor(parentOf(x), BLACK);
                setColor(leftOf(sib), BLACK);
                rotateRight(parentOf(x));
                x = root;
            }
        }
    }

    setColor(x, BLACK);
}

private static final long id40 = 919286545866124006L;


private void writeObject(java.io.ObjectOutputStream s)
        throws java.io.IOException {
    
    s.defaultWriteObject();

    
    s.writeInt(size);

    
    for (Iterator<Map.Entry<K, V>> i = entrySet().iterator(); i.hasNext(); ) {
        Map.Entry<K, V> e = i.next();
        s.writeObject(e.getKey());
        s.writeObject(e.getValue());
    }
}


private void readObject(final java.io.ObjectInputStream s)
        throws java.io.IOException, ClassNotFoundException {
    
    s.defaultReadObject();

    
    int size = s.readInt();

    id11(size, null, s, null);
}


void id47(int size, java.io.ObjectInputStream s, V defaultVal)
        throws java.io.IOException, ClassNotFoundException {
    id11(size, null, s, defaultVal);
    if (root!=null){
        updateWeight(root);
    }
}

private int updateWeight(Entry<K,V>e){
    int weight = 1;
    if (e.left!=null){weight += updateWeight(e.left);}
    if (e.right!=null){weight += updateWeight(e.right);}
    e.weight = weight;
    return weight;
}


void id42(SortedSet<? extends K> set, V defaultVal) {
    try {
        id11(set.size(), set.iterator(), null, defaultVal);
    } catch (java.io.IOException cannotHappen) {
    } catch (ClassNotFoundException cannotHappen) {
    }
}



private void id11(int size, Iterator it,
                             java.io.ObjectInputStream str,
                             V defaultVal)
        throws java.io.IOException, ClassNotFoundException {
    this.size = size;
    root = id11(0, 0, size - 1, id19(size),
            it, str, defaultVal);
}


private final Entry<K, V> id11(int level, int lo, int hi,
                                          int redLevel,
                                          Iterator it,
                                          java.io.ObjectInputStream str,
                                          V defaultVal)
        throws java.io.IOException, ClassNotFoundException {
    

    if (hi < lo) return null;

    int mid = (lo + hi) / 2;

    Entry<K, V> left = null;
    if (lo < mid)
        left = id11(level + 1, lo, mid - 1, redLevel,
                it, str, defaultVal);

    
    K key;
    V value;
    if (it != null) {
        if (defaultVal == null) {
            Map.Entry<K, V> entry = (Map.Entry<K, V>) it.next();
            key = entry.getKey();
            value = entry.getValue();
        } else {
            key = (K) it.next();
            value = defaultVal;
        }
    } else { 
        key = (K) str.readObject();
        value = (defaultVal != null ? defaultVal : (V) str.readObject());
    }

    Entry<K, V> middle = new Entry<K, V>(key, value, null);

    
    if (level == redLevel)
        middle.color = RED;

    if (left != null) {
        middle.left = left;
        left.parent = middle;
    }

    if (mid < hi) {
        Entry<K, V> right = id11(level + 1, mid + 1, hi, redLevel,
                it, str, defaultVal);
        middle.right = right;
        right.parent = middle;
    }

    return middle;
}


private static int id19(int sz) {
    int level = 0;
    for (int m = sz - 1; m >= 0; m = m / 2 - 1)
        level++;
    return level;
}
}

	public static interface id53<K, V> extends NavigableMap<K, V> {
	    
	    K exactKey(int index);

	    Entry<K, V> exactEntry(int index);

	    int keyIndex(K k);

	}

}