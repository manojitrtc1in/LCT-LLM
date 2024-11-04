
import java.io.*;
import java.util.*;

public class Main {

    static int N = 200010;
    static long[] a = new long[4 * N];

    static int lowbit(int x) {
        return x & -x;
    }

    static void add(int x, int v) {
        for (int i = x; i < 4 * N; i += lowbit(i)) a[i] += v;
    }

    static long sum(int x) {
        long ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) ans += a[i];
        return ans;
    }

    static List<int[]>[] col = new List[N];
    static int tot;
    static List<Integer> d;

    static int check(int x) {
        int l = 0, r = d.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (d.get(mid) >= x) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    public static void main(String[] args) throws IOException {
        FastScanner f = new FastScanner();
        PrintWriter w = new PrintWriter(System.out);
        int T = f.nextInt();
        while (T-- > 0) {
            int n = f.nextInt();
            tot = 0;
            for (int i = 0; i < 3 * n; i++) a[i] = 0;
            d = new ArrayList<>();
            id8<Integer> s1 = new id8<>(), s2 = new id8<>();
            for (int i = 1; i <= n; i++) col[i] = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                int l = f.nextInt();
                int r = f.nextInt();
                int c = f.nextInt();
                col[c].add(new int[]{l, r, i, 0, 0});
                d.add(l);
                d.add(r);
            }
            d = new ArrayList<>(new HashSet<>(d));
            Collections.sort(d);
            for (int c = 1; c <= n; c++) {
                for (int j = 0; j < col[c].size(); j++) {
                    int l = col[c].get(j)[0], r = col[c].get(j)[1];
                    s1.add(l);
                    s2.add(r);
                    int k1 = check(l) + 1;
                    int k2 = check(r) + 1;
                    col[c].get(j)[3] = k1;
                    col[c].get(j)[4] = k2;
                    add(k1, 1);
                    add(k2 + 1, -1);
                }
            }
            long[] ans = new long[n + 1];
            for (int c = 1; c <= n; c++) {
                for (int j = 0; j < col[c].size(); j++) {
                    int l = col[c].get(j)[0], r = col[c].get(j)[1];
                    s1.remove(l);
                    s2.remove(r);
                    int k1 = col[c].get(j)[3];
                    int k2 = col[c].get(j)[4];
                    add(k1, -1);
                    add(k2 + 1, 1);
                }
                for (int j = 0; j < col[c].size(); j++) {
                    int l = col[c].get(j)[0], r = col[c].get(j)[1];
                    int idx = col[c].get(j)[2];
                    int k1 = col[c].get(j)[3];
                    int k2 = col[c].get(j)[4];
                    ans[idx] = Long.MAX_VALUE;
                    if (sum(k1) > 0 || sum(k2) > 0) {
                        ans[idx] = 0;
                        continue;
                    }
                    if (s1.ceiling(l) != null) {
                        long l_idx = s1.ceiling(l);
                        long r1 = r;
                        long L = Math.max(0, l_idx - r1);
                        ans[idx] = Math.min(ans[idx], L);
                    }
                    if (s2.floor(r) != null) {
                        long r_idx = s2.floor(r);
                        long l1 = l;
                        long R = Math.max(0, l1 - r_idx);
                        ans[idx] = Math.min(ans[idx], R);
                    }
                }
                for (int j = 0; j < col[c].size(); j++) {
                    int l = col[c].get(j)[0], r = col[c].get(j)[1];
                    s1.add(l);
                    s2.add(r);
                    int k1 = col[c].get(j)[3];
                    int k2 = col[c].get(j)[4];
                    add(k1, 1);
                    add(k2 + 1, -1);
                }
            }
            for (int i = 1; i <= n; i++) w.print(ans[i] + " ");
            w.println();
        }
        w.flush();
    }

    
    static class id8<E> extends AbstractSet<E>
            implements NavigableSet<E>, Cloneable, java.io.Serializable {

        private static final long id7 = 1L;

        private transient NavigableMap<E, Integer> treeMap;

        

        private transient int size = 0;

        private id8(NavigableMap<E, Integer> m) {
            this.treeMap = m;
        }

        public id8() {
            this(new TreeMap<E, Integer>());
        }

        public id8(Comparator<? super E> comparator) {
            this(new TreeMap<>(comparator));
        }

        public id8(Collection<? extends E> c) {
            this();
            addAll(c);
        }

        public id8(SortedSet<E> s) {
            this(s.comparator());
            addAll(s);
        }

        
        private class Itr implements Iterator<E> {
            private int cursor;
            

            private Iterator<E> id1;
            

            private E curVal;
            

            private int id4;

            Itr(NavigableSet<E> keySet) {
                cursor = 0;
                id1 = keySet.iterator();
                if (id1.hasNext()) {
                    curVal = id1.next();
                }
                id4 = 0;
            }

            Itr() {
                this(treeMap.navigableKeySet());
            }

            @Override
            public boolean hasNext() {
                return cursor < size;
            }

            @Override
            public E next() {
                if (!hasNext()) {
                    throw new NoSuchElementException();
                }

                int id0 = treeMap.get(curVal);
                E res = null;
                if (id4 < id0) {
                    id4++;
                    res = curVal;
                    if (id4 == id0) {
                        

                        if (id1.hasNext()) {
                            curVal = id1.next();
                        }
                        id4 = 0;
                    }
                }

                cursor++;
                return res;
            }
        }

        
        public Iterator<E> diffIterator() {
            return treeMap.navigableKeySet().iterator();
        }

        
        public Iterator<E> id6() {
            return treeMap.descendingKeySet().iterator();
        }

        
        @Override
        public Iterator<E> iterator() {
            return new Itr();
        }

        
        @Override
        public Iterator<E> descendingIterator() {
            return new Itr(treeMap.descendingKeySet());
        }

        
        @Override
        public NavigableSet<E> descendingSet() {
            id8<E> descendingSet = new id8<>(treeMap.descendingMap());
            descendingSet.size = size;
            return descendingSet;
        }

        
        private int id5(NavigableMap<E, Integer> countMap) {
            int size = 0;
            for (E e : countMap.keySet()) {
                size += countMap.get(e);
            }
            return size;
        }

        
        @Override
        public NavigableSet<E> subSet(E fromElement, boolean fromInclusive, E toElement, boolean toInclusive) {
            NavigableMap<E, Integer> subMap = treeMap.subMap(fromElement, fromInclusive, toElement, toInclusive);
            id8<E> subSet = new id8<>(subMap);
            subSet.size = id5(subMap);
            return subSet;
        }

        
        @Override
        public NavigableSet<E> headSet(E toElement, boolean inclusive) {
            NavigableMap<E, Integer> headMap = treeMap.headMap(toElement, inclusive);
            id8<E> headSet = new id8<>(headMap);
            headSet.size = id5(headMap);
            return headSet;
        }

        
        @Override
        public NavigableSet<E> tailSet(E fromElement, boolean inclusive) {
            NavigableMap<E, Integer> tailMap = treeMap.tailMap(fromElement, inclusive);
            id8<E> tailSet = new id8<>(tailMap);
            tailSet.size = id5(tailMap);
            return tailSet;
        }

        @Override
        public SortedSet<E> subSet(E fromElement, E toElement) {
            return subSet(fromElement, true, toElement, false);
        }

        @Override
        public SortedSet<E> headSet(E toElement) {
            return headSet(toElement, false);
        }

        @Override
        public SortedSet<E> tailSet(E fromElement) {
            return tailSet(fromElement, true);
        }

        @Override
        public Comparator<? super E> comparator() {
            return treeMap.comparator();
        }

        
        public int size() {
            return size;
        }

        
        public int id3() {
            

            return treeMap.keySet().size();
        }

        
        public E first() {
            if (treeMap.isEmpty()) {
                return null;
            }

            return treeMap.firstKey();
        }

        
        public E last() {
            if (treeMap.isEmpty()) {
                return null;
            }
            return treeMap.lastKey();
        }

        
        @Override
        public boolean contains(Object o) {
            return treeMap.containsKey(o);
        }

        @Override
        public void clear() {
            treeMap.clear();
            size = 0;
        }

        
        @Override
        public boolean add(E e) {
            return add(e, 1);
        }

        
        public boolean add(E e, int count) {
            if (treeMap.containsKey(e)) {
                treeMap.put(e, treeMap.get(e) + count);
            } else {
                treeMap.put(e, count);
            }
            size += count;
            return true;
        }

        
        public void setCount(E e, int count) {
            int oldCount = treeMap.getOrDefault(e, 0);
            treeMap.put(e, count);
            size = size - oldCount + count;
        }

        
        public int count(E e) {
            return treeMap.getOrDefault(e, 0);
        }

        
        public boolean remove(Object e) {
            return remove((E) e, 1);
        }

        
        public boolean remove(E e, int count) {
            if (count <= 0) {
                return false;
            }

            if (!treeMap.containsKey(e)) {
                return false;
            }

            int curCount = treeMap.get(e);
            if (curCount < count) {
                return false;
            } else if (curCount == count) {
                treeMap.remove(e);
            } else {
                treeMap.put(e, curCount - count);
            }

            size -= count;
            return true;
        }

        
        public boolean removeAll(Object e) {
            if (!treeMap.containsKey(e)) {
                return false;
            }

            size -= treeMap.get(e);
            treeMap.remove(e);
            return true;
        }

        
        @Override
        public E lower(E e) {
            return treeMap.lowerKey(e);
        }

        
        @Override
        public E floor(E e) {
            return treeMap.floorKey(e);
        }

        
        @Override
        public E higher(E e) {
            return treeMap.higherKey(e);
        }

        
        @Override
        public E ceiling(E e) {
            return treeMap.ceilingKey(e);
        }

        
        public E pollFirst(int count) {
            if (treeMap.isEmpty()) {
                return null;
            }
            E firstKey = treeMap.firstKey();
            remove(firstKey, count);
            return firstKey;
        }

        
        public E pollFirst() {
            return pollFirst(1);
        }

        
        public E id9() {
            

            if (treeMap.isEmpty()) {
                return null;
            }

            E firstKey = treeMap.firstKey();
            size -= treeMap.get(firstKey);
            treeMap.remove(firstKey);
            return firstKey;
        }

        
        public E pollLast() {
            return pollLast(1);
        }

        
        public E pollLast(int count) {
            if (treeMap.isEmpty()) {
                return null;
            }
            E lastKey = treeMap.lastKey();
            remove(lastKey, count);
            return lastKey;
        }

        
        public E id2() {
            if (treeMap.isEmpty()) {
                return null;
            }
            E lastKey = treeMap.lastKey();
            size -= treeMap.get(lastKey);
            treeMap.remove(lastKey);
            return lastKey;
        }

        
        @SuppressWarnings("unchecked")
        public Object clone() throws CloneNotSupportedException {
            id8<E> clone = (id8<E>) super.clone();
            clone.treeMap = new TreeMap<>(treeMap);
            return clone;
        }

    }

    private static class FastScanner {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        private FastScanner() throws IOException {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        private short nextShort() throws IOException {
            short ret = 0;
            byte c = read();
            while (c <= ' ') c = read();
            boolean neg = (c == '-');
            if (neg) c = read();
            do ret = (short) (ret * 10 + c - '0');
            while ((c = read()) >= '0' && c <= '9');
            if (neg) return (short) -ret;
            return ret;
        }

        private int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') c = read();
            boolean neg = (c == '-');
            if (neg) c = read();
            do ret = ret * 10 + c - '0';
            while ((c = read()) >= '0' && c <= '9');
            if (neg) return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ') c = read();
            boolean neg = (c == '-');
            if (neg) c = read();
            do ret = ret * 10 + c - '0';
            while ((c = read()) >= '0' && c <= '9');
            if (neg) return -ret;
            return ret;
        }

        private char nextChar() throws IOException {
            byte c = read();
            while (c <= ' ') c = read();
            return (char) c;
        }

        private String nextString() throws IOException {
            StringBuilder ret = new StringBuilder();
            byte c = read();
            while (c <= ' ') c = read();
            do {
                ret.append((char) c);
            } while ((c = read()) > ' ');
            return ret.toString();
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1) buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead) fillBuffer();
            return buffer[bufferPointer++];
        }
    }
}