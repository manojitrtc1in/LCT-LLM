import java.util.*;

public class A{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<Long, Integer> m = new TreeMap<>();
        Map<Long, Integer> m1 = new TreeMap<>();
        for (int i = 0; i < n; ++i){
            long c = sc.nextLong();
            m.put(c, 1 + m.getOrDefault(c, 0));
        }
        for (int i = 1; i < n; ++i){
            long c = sc.nextInt();
            int t = m.get(c) - 1;
            if (t == 0){
                m.remove(c);
            } else {
                m.put(c, t);
            }
            m1.put(c, 1 + m1.getOrDefault(c, 0));
        }
        for (Object o : m.keySet())
            System.out.println(o);
        for (int i = 2; i < n; ++i){
            long c = sc.nextInt();
            int t = m1.get(c) - 1;
            if (t == 0){
                m1.remove(c);
            } else {
                m1.put(c, t);
            }
        }
        for (Object o : m1.keySet())
            System.out.println(o);
        System.out.flush();
    }
}

class id6 extends AbstractSet<Long> {
    public static final long id2 = 0;
    public static final long id4 = (1L << 32) - 1L;
    public static final long NO_ELEMENT = -1;
    static final long id9 = id2 - 1;
    static final long id0 = id4 + 1;
    long minKey = id0;
    long maxKey = id9;

    
    private final int k;
    private final int k2;
    private id6 summary = null;
    private id6[] clusters = null;

    private int lowBits(long num){
        return (int)(num & ((1L << k2) - 1L));
    }

    private int highBits(long num){
        return (int)(num >> k2);
    }

    private long id7(long low, long high){
        return (high << k2) | low;
    }

    private int size = 0;
    @Override
    public int size() {
        return size;
    }
    @Override
    public boolean isEmpty() {
        return 0 == size;
    }

    @Override
    public boolean contains(Object o) {
        return o instanceof Long && contains((long) o);
    }

    private boolean contains(long val){
        boolean retVal = minKey == val || maxKey == val;
        if (!retVal) {
            final int low = lowBits(val);
            final int hi = highBits(val);
            if (clusters != null && clusters[hi] != null)
                retVal = clusters[hi].contains(low);
        }
        return retVal;
    }

    @Override
    public boolean add(Long aLong) {
        return add(aLong.longValue());
    }
    boolean add(long val){
        if (val < 0 || val >= (1L << k))
            throw new UnsupportedOperationException("Adding element " + val +
                    " to (sub)vebTree which can contains only values in range [0; " +
                    (1L << k) + ").");
        return insert(val);
    }

    boolean insert(long val){
        boolean retVal = false;
        if (size == 0){
            minKey = maxKey = val;
            retVal = true;
        }
        else if (size == 1){
            if (val < minKey) {
                minKey = val;
                retVal = true;
            }
            if (val > maxKey){
                maxKey = val;
                retVal = true;
            }
        }
        else {
            if (val < minKey) {
                long t = val;
                val = minKey;
                minKey = t;
            }
            else if (val > maxKey){
                long t = val;
                val = maxKey;
                maxKey = t;
            }

            if (minKey < val && val < maxKey){
                if (summary == null) summary = new id6(k2);
                if (clusters == null) clusters = new id6[1 << k2];
                final int low = lowBits(val);
                final int hi = highBits(val);
                if (clusters[hi] == null){
                    clusters[hi] = new id6(k - k2);
                    clusters[hi].insert((long)low);
                    summary.insert(hi);
                    retVal = true;
                } else {
                    retVal = clusters[hi].insert((long)low);
                }
            }
        }
        if (retVal) {
            ++size;
        }
        return retVal;
    }

    public id6(){
        this(32);
    }
    id6(int k){
        this.k = k;
        this.k2 = k / 2;
    }

    @Override
    public void clear() {
        minKey = id0;
        maxKey = id9;
        size = 0;
        summary = null;
        clusters = null;
    }

    @Override
    public boolean remove(Object o) {
        return remove(((Long) o).longValue());
    }

    @SuppressWarnings("Duplicates")
    public boolean remove(long val){
        if (size < 2){
            if (val == minKey && val == maxKey) {
                clear();
                return true;
            }
            return false;
        }
        boolean retVal = false;
        if (size == 2){
            if (minKey == val || maxKey == val){
                minKey = maxKey = minKey ^ maxKey ^ val;
                retVal = true;
            }
        }
        else {
            if (minKey == val){
                minKey = id7(clusters[(int)summary.minKey].minKey,summary.minKey);
                val = minKey;
            }
            else if (maxKey == val){
                maxKey = id7(clusters[(int)summary.maxKey].maxKey,summary.maxKey);
                val = maxKey;
            }
            final int low = lowBits(val);
            final int hi = highBits(val);
            if (clusters[hi] != null){
                retVal = clusters[hi].remove(low);
                if (clusters[hi].isEmpty()){
                    clusters[hi] = null;
                    summary.remove(hi);
                }
            }
        }
        if (retVal){
            --size;
        }
        return retVal;
    }

    @SuppressWarnings("Duplicates")
    public long nextKey(long val){
        if (isEmpty() || val >= maxKey) return NO_ELEMENT;
        if (val < minKey) return minKey;
        long id5 = val < maxKey? maxKey : NO_ELEMENT;
        if (summary == null || clusters == null) return id5;
        final int low = lowBits(val);
        int hi = highBits(val);
        if (clusters[hi] != null && low < clusters[hi].maxKey){
            return id7(clusters[hi].nextKey(low), hi);
        }
        hi = (int)summary.nextKey(hi);
        if (hi == NO_ELEMENT) return id5;
        return id7(clusters[hi].minKey, hi);
    }




    @Override
    public Iterator<Long> iterator() {
        return new Iterator<Long>() {
            long prev = NO_ELEMENT;
            long cur = isEmpty()? NO_ELEMENT : minKey;

            @Override
            public boolean hasNext() {
                return cur != NO_ELEMENT;
            }

            @Override
            public Long next() {
                if (cur == NO_ELEMENT) throw new NoSuchElementException();
                prev = cur;
                cur = nextKey(cur);
                return prev;
            }

            @Override
            public void remove() {
                if (prev == NO_ELEMENT) throw new IllegalStateException();
                id6.this.remove(prev);
                prev = NO_ELEMENT;
            }
        };
    }

    @Override
    public boolean containsAll(Collection<?> c) {
        for (Object o : c) {
            if (!contains(o))
                return false;
        }
        return true;
    }
}

class id1<V> extends AbstractMap<Long, V>{
    public static long id2 = id6.id2;
    public static long id4 = id6.id4;
    public static final long NO_ELEMENT = id6.NO_ELEMENT;
    static final long id9 = id2 - 1;
    static final long id0 = id4 + 1;
    private long minKey = id0;
    private long maxKey = id9;
    private V minVal = null;
    private V maxVal = null;

    private final int k;
    private final int k2;
    private id6 summary = null;
    private id1<V>[] clusters = null;

    private int lowBits(long num){
        return (int)(num & ((1L << k2) - 1L));
    }

    private int highBits(long num){
        return (int)(num >> k2);
    }

    private long id7(long low, long high){
        return (high << k2) | low;
    }

    private int size = 0;
    @Override
    public int size() {
        return size;
    }
    @Override
    public boolean isEmpty() {
        return 0 == size;
    }

    public id1(){
        this(32);
    }
    private id1(int k){
        this.k = k;
        this.k2 = k / 2;
    }

    @Override
    public void clear() {
        minKey = id0;
        maxKey = id9;
        size = 0;
        summary = null;
        clusters = null;
        minVal = null;
        maxVal = null;
    }

    @Override
    public boolean containsKey(Object key) {
        return key instanceof Long && containsKey(((Long) key).longValue());
    }

    private boolean containsKey(long key){
        boolean retVal = minKey == key || maxKey == key;
        if (!retVal) {
            final int low = lowBits(key);
            final int hi = highBits(key);
            if (clusters != null && clusters[hi] != null)
                retVal = clusters[hi].containsKey(low);
        }
        return retVal;
    }

    @Override
    public V get(Object key) {
        if (key instanceof Long) return get(((Long) key).longValue());
        return null;
    }

    private V get(long key){
        V retVal = null;
        if (key == minKey)
            retVal = minVal;
        else if (key == maxKey)
            retVal = maxVal;
        else {
            final int low = lowBits(key);
            final int hi = highBits(key);
            if (clusters != null && clusters[hi] != null)
                retVal = clusters[hi].get(low);
        }
        return retVal;
    }

    @Override
    public V put(Long key, V value) {
        return put(key.longValue(), value);
    }

    private V put(long key, V value) {
        if (key < 0 || key >= (1L << k))
            throw new UnsupportedOperationException("Adding key " + key +
                    " to (sub)vebTree which can contains only values in range [0; " +
                    (1L << k) + ").");
        final V retVal = get(key);
        insert(key, value);
        return retVal;
    }

    private boolean insert(long key, V value){
        boolean id3 = false;
        if (size == 0){
            minKey = maxKey = key;
            minVal = maxVal = value;
            id3 = true;
        } else if (key == minKey || key == maxKey){
            if (key == minKey){
                minVal = value;
            }
            if (key == maxKey) {
                maxVal = value;
            }
        }
        else if (size == 1){
            if (key < minKey) {
                minKey = key;
                minVal = value;
                id3 = true;
            }
            else if (key > maxKey){
                maxKey = key;
                maxVal = value;
                id3 = true;
            } else {
                

                throw new RuntimeException("Unexpected inner state");
            }
        }
        else {
            if (key < minKey) {
                long tk = key;
                V tv = value;
                key = minKey;
                value = minVal;
                minKey = tk;
                minVal = tv;
            }
            else if (key > maxKey){
                long tk = key;
                V tv = value;
                key = maxKey;
                value = maxVal;
                maxKey = tk;
                maxVal = tv;
            }

            if (summary == null) summary = new id6(k2);
            if (clusters == null) clusters = new id1[1 << k2];
            final int low = lowBits(key);
            final int hi = highBits(key);
            if (clusters[hi] == null){
                clusters[hi] = new id1<>(k - k2);
                clusters[hi].insert((long)low, value);
                summary.insert(hi);
                id3 = true;
            } else {
                id3 = clusters[hi].insert((long)low, value);
            }
        }
        if (id3) {
            ++size;
        }
        return id3;
    }

    @Override
    public V remove(Object key) {
        if (key instanceof Long) return remove(((Long) key).longValue());
        return null;
    }

    private V remove(long key){
        final V retVal = get(key);
        erase(key);
        return retVal;
    }

    @SuppressWarnings("Duplicates")
    private boolean erase(long key){
        if (size < 2){
            if (key == minKey && key == maxKey) {
                clear();
                return true;
            }
            return false;
        }

        boolean retVal = false;
        if (size == 2){
            if (minKey == key){
                minKey = maxKey;
                minVal = maxVal;
                retVal = true;
            }
            else if (maxKey == key){
                maxKey = minKey;
                maxVal = minVal;
                retVal = true;
            }
        }
        else {
            if (minKey == key){
                int i = (int) summary.minKey;
                this.minKey = id7(clusters[i].minKey,summary.minKey);
                this.minVal = clusters[i].minVal;
                key = this.minKey;
            }
            else if (maxKey == key){
                int i = (int) summary.maxKey;
                this.maxKey = id7(clusters[i].maxKey,summary.maxKey);
                this.maxVal = clusters[i].maxVal;
                key = this.maxKey;
            }
            final int low = lowBits(key);
            final int hi = highBits(key);
            if (clusters[hi] != null){
                retVal = clusters[hi].erase(low);
                if (clusters[hi].isEmpty()){
                    clusters[hi] = null;
                    summary.remove(hi);
                }
            }
        }
        if (retVal){
            --size;
        }
        return retVal;
    }

    @SuppressWarnings("Duplicates")
    public long nextKey(long val){
        if (isEmpty() || val >= maxKey) return NO_ELEMENT;
        if (val < minKey) return minKey;
        long id5 = val < maxKey? maxKey : NO_ELEMENT;
        if (summary == null || clusters == null) return id5;
        final int low = lowBits(val);
        int hi = highBits(val);
        if (clusters[hi] != null && low < clusters[hi].maxKey){
            return id7(clusters[hi].nextKey(low), hi);
        }
        hi = (int)summary.nextKey(hi);
        if (hi == NO_ELEMENT) return id5;
        return id7(clusters[hi].minKey, hi);
    }



    @Override
    public Set<Entry<Long, V>> entrySet() {
        return new AbstractSet<Entry<Long, V>>() {
            @Override
            public int size() {
                return id1.this.size();
            }

            @Override
            public boolean isEmpty() {
                return id1.this.isEmpty();
            }

            @Override
            public boolean contains(Object o) {
                if (!(o instanceof Map.Entry)) return false;
                Map.Entry entry = (Map.Entry)o;
                try {
                    long key = (Long) entry.getKey();
                    Object val = entry.getValue();
                    if (!id1.this.containsKey(key))
                        return false;
                    V realVal = get(key);
                    return (val == null || realVal == null)?
                            val == realVal :
                            val.equals(realVal);
                } catch (ClassCastException unused){
                    return false;
                }
            }

            @Override
            public Iterator<Entry<Long, V>> iterator() {
                return new Iterator<Entry<Long, V>>() {
                    long prev = NO_ELEMENT;
                    long cur = isEmpty()? NO_ELEMENT : minKey;

                    @Override
                    public boolean hasNext() {
                        return cur != NO_ELEMENT;
                    }

                    @Override
                    public Entry<Long, V> next() {
                        if (cur == NO_ELEMENT) throw new NoSuchElementException();
                        prev = cur;
                        cur = nextKey(cur);
                        return new SimpleEntry<Long, V>(prev, get(prev)){
                            @Override
                            public V setValue(V value) {
                                id1.this.insert(getKey(), value);
                                return super.setValue(value);
                            }
                        };
                    }
                };
            }

            @Override
            public boolean addAll(Collection<? extends Entry<Long, V>> c) {
                throw new UnsupportedOperationException();
            }

            @Override
            public boolean add(Entry<Long, V> id8) {
                throw new UnsupportedOperationException();
            }

            @Override
            public boolean remove(Object o) {
                return false;
            }

            @Override
            public boolean containsAll(Collection<?> c) {
                for (Object o : c) {
                    if (!contains(o))
                        return false;
                }
                return true;
            }

            @Override
            public void clear() {
                id1.this.clear();
            }
        };

    }
}
