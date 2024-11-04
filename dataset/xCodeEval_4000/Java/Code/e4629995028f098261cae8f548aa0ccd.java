import java.io.*;
import java.util.*;
import java.util.function.BiConsumer;
import java.util.function.BiFunction;
import java.util.function.Consumer;
import java.util.function.Function;


public class E implements Runnable {
    public static void main(String[] args) {
        new Thread(null, new E(), "whatever", 1 << 26).start();
    }

    FastScanner s;
    StringBuilder sb;

    
    void init() {
        s = new FastScanner(System.in);
        sb = new StringBuilder();
    }


    class SingleTest {
        int n = s.nextInt();
        AL<IndexedPair> input = s.readNextListIndexedPairs(n);
        AL<IndexedPair> sorted = input.concatenate(input.map(p -> p.swapped())).sorted();
        AL<Pair> sol = new AL<>();
        IndexedPair minYSameX = INF_Pair;
        IndexedPair minYDiffX = INF_Pair;

        IndexedPair minByY(IndexedPair a, IndexedPair b) {
            return a.y < b.y ? a : b;
        }

        

        

        

        

        

        

        public SingleTest(int testNumber) {
           sorted.map((i, ip)->{
                if (i == 0 || ip.x != sorted.get(i - 1).x) {
                    

                    minYDiffX = minByY(minYSameX, minYDiffX);
                    minYSameX = INF_Pair;
                }
                minYSameX = minByY(minYSameX, ip);
                return new Pair(ip.index,
                        minYDiffX.y < ip.y ? (minYDiffX.index + 1) : -1
                );
            }).sorted().partition(2).map((list) -> {
                Pair a = list.get(0);
                Pair b = list.get(1);
                return a.y == -1 || (a.y > -1 && b.y < a.y) ? b.y : a.y;
            }).output();
            newline();
        }
    }

    public void run() {
        init();
        int numTests = s.nextInt();
        for (int i = 1; i <= numTests; i++) {
            new SingleTest(i);
        }
        System.out.print(sb);
    }
    

    class AL<E extends Comparable<? super E>> extends ArrayList<E> implements Comparable<AL<E>>{
        <T extends Comparable<? super T>> AL<T> map(Function<E, T> function) {
            AL<T> newList = new AL<T>();
            for (int i = 0; i < this.size(); i++) {
                newList.add(function.apply(this.get(i)));
            }
            return newList;
        }
        <T extends Comparable<? super T>> AL<T> map(BiFunction<Integer, E, T> function) {
            AL<T> newList = new AL<T>();
            for (int i = 0; i < this.size(); i++) {
                newList.add(function.apply(i, this.get(i)));
            }
            return newList;
        }

        E reduce(BiFunction<E,E,E> func) {
            E reduction = this.get(0);
            for (int i = 1; i < size(); i++) {
                reduction = func.apply(reduction, get(i));
            }
            return reduction;
        }

        E min() {
            return reduce((a, b) -> a.compareTo(b) < 0 ? a : b);
        }
        E max() {
            return reduce((a, b) -> a.compareTo(b) > 0 ? a : b);
        }

        AL<E> filter(Function<E, Boolean> condition) {
            AL<E> filtered = new AL<>();
            for (int i = 0; i < size(); i++) {
                if (condition.apply(get(i)))
                    filtered.add(get(i));
            }
            return filtered;
        }

        public void forEach(BiConsumer<Integer, ? super E> func) {
            for (int i = 0; i < size(); i++) {
                func.accept(i, get(i));
            }
        }

        public AL concatenate(AL<E> other) {
            AL<E> clone = clone();
            clone.addAll(other);
            return clone;
        }

        AL<AL<E>> partition(int partitionSize) {
            AL<AL<E>> part = new AL<AL<E>>();
            for (int i = 0; i < size(); i += partitionSize) {
                AL<E> sublist = new AL<E>();
                for (int j = i; j < i + partitionSize && j < size(); j++) {
                    sublist.add(get(j));
                }
                part.add(sublist);
            }
            return part;
        }

        @Override
        public void forEach(Consumer<? super E> func) {
            for (int i = 0; i < size(); i++) {
                func.accept(get(i));
            }
        }

        @Override
        public AL<E> clone() {
            AL<E> newList = new AL<>();
            for (int i = 0; i < size(); i++) {
                newList.add(get(i));
            }
            return newList;
        }
        AL<E> sorted() {
            AL<E> newList = clone();
            Collections.sort(newList);
            return newList;
        }
        AL<E> sorted(Comparator<E> comp) {
            AL<E> newList = clone();
            Collections.sort(clone(), comp);
            return newList;
        }

        AL<E> reversed() {
            AL<E> newList = clone();
            Collections.reverse(clone());
            return newList;
        }

        void output() {
            for (int i = 0; i < this.size(); i++) {
                E t = this.get(i);
                sb.append(t.toString());
                if (i < this.size() - 1) {
                    sb.append(" ");
                }
            }
        }

        @Override
        public int compareTo(AL<E> o) {
            int minSize = Integer.min(size(), o.size());
            for (int i = 0; i < minSize; i++) {
                int res = get(i).compareTo(o.get(i));
                if (res != 0) {
                    return res;
                }
            }
            return Integer.compare(size(), o.size());
        }

        

        

    }

    class Pair implements Comparable<Pair> {
        long x, y;

        public Pair(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public Pair swapped() {
            return new Pair(y, x);
        }

        @Override
        public int compareTo(Pair o) {
            int res1 = Long.compare(x, o.x);
            if (res1 == 0) {
                return Long.compare(y, o.y);
            }
            return res1;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair pair = (Pair) o;
            return x == pair.x &&
                    y == pair.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
    }

    final IndexedPair INF_Pair = new IndexedPair(
            Integer.MAX_VALUE, new Pair(Long.MAX_VALUE / 2, Long.MAX_VALUE / 2));
    final IndexedPair NEG_INF_Pair = new IndexedPair(
            Integer.MIN_VALUE, new Pair(Long.MIN_VALUE / 2, Long.MIN_VALUE / 2));

    public class IndexedPair extends Pair {
        int index;

        public IndexedPair(int index, Pair p) {
            super(p.x, p.y);
            this.index = index;
        }

        @Override
        public String toString() {
            return "IndexedPair{" +
                    "x=" + x +
                    ", y=" + y +
                    ", index=" + index +
                    '}';
        }

        @Override
        public IndexedPair swapped() {
            return new IndexedPair(index, super.swapped());
        }
    }

    public Comparator<IndexedPair> comparatorByXYThenIndex() {
        return (a, b) -> {
            int res = a.compareTo(b);
            if (res == 0) {
                return Integer.compare(a.index, b.index);
            }
            return res;
        };
    }

    public Comparator<IndexedPair> comparatorByIndexThenXY() {
        return (a, b) -> {
            int res = Integer.compare(a.index, b.index);

            if (res == 0) {
                return a.compareTo(b);
            }
            return res;
        };
    }

    public static Comparator<Pair> ComparatorByXThenY() {
        return (p, q) -> {
            int res1 = Long.compare(p.x, q.x);
            if (res1 == 0) {
                return Long.compare(p.y, q.y);
            }
            return res1;
        };
    }

    public static Comparator<Pair> ComparatorByYThenX() {
        return (q, p) -> {
            int res1 = Long.compare(p.x, q.x);
            if (res1 == 0) {
                return Long.compare(p.y, q.y);
            }
            return res1;
        };
    }

    <T> void output(T[] arr) {
        for (int i = 0; i < arr.length; i++) {
            T t = arr[i];
            sb.append(t.toString());
            if (i < arr.length - 1) {
                sb.append(" ");
            }
        }
    }

    void newline() {
        sb.append('\n');
    }

    

    @SuppressWarnings({"unchecked"})
    <T> T[] toArray(Collection<T> arg) {
        T[] arr = (T[]) new Object[arg.size()];
        Iterator<T> it = arg.iterator();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = it.next();
        }
        return arr;
    }

    <T> ArrayList<T> toList(T[] arr) {
        return new ArrayList<>(Arrays.asList(arr));
    }

    ArrayList<Character> toList(String str) {
        ArrayList<Character> chars = new ArrayList<>();
        for (int i = 0; i < str.length(); i++) {
            chars.add(str.charAt(i));
        }
        return chars;
    }

    ArrayList<Integer> toList(int[] arr) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i : arr) {
            list.add(i);
        }
        return list;
    }

    ArrayList<Long> toList(long[] arr) {
        ArrayList<Long> list = new ArrayList<>();
        for (long i : arr) {
            list.add(i);
        }
        return list;
    }

    ArrayList<Double> toList(double[] arr) {
        ArrayList<Double> list = new ArrayList<>();
        for (double i : arr) {
            list.add(i);
        }
        return list;
    }

    <T> ArrayList<T> toList(Collection<T> col) {
        ArrayList<T> list = new ArrayList<>();
        list.addAll(col);
        return list;
    }

    <T extends Comparable<? super T>> ArrayList<T> sorted(ArrayList<T> list) {
        ArrayList<T> copy = toList(list);
        Collections.sort(copy, (p, q) -> p.compareTo(q));
        return copy;
    }

    <T> ArrayList<T> sorted(ArrayList<T> list, Comparator<? super T> comp) {
        ArrayList<T> copy = toList(list);
        Collections.sort(copy, comp);
        return copy;
    }

    @SuppressWarnings({"unchecked"})
    <T> T[] copy(T[] arr) {
        T[] clone = (T[]) new Object[arr.length];
        System.arraycopy(arr, 0, clone, 0, arr.length);
        return clone;
    }

    <T extends Comparable<T>> T max(Collection<T> col) {
        T max = null;
        for (T t : col) {
            if (col == null) {
                continue;
            } else if (max == null) {
                max = t;
            } else if (max.compareTo(t) < 0) {
                max = t;
            }
        }
        return max;
    }

    <T extends Comparable<? super T>> T min(T a, T b) {
        return a.compareTo(b) < 0 ? a : b;
    }

    <T extends Comparable<? super T>> T max(T a, T b) {
        return a.compareTo(b) > 0 ? a : b;
    }

    <T extends Comparable<T>> T min(Collection<T> col) {
        T min = null;
        for (T t : col) {
            if (col == null) {
                continue;
            } else if (min == null) {
                min = t;
            } else if (min.compareTo(t) > 0) {
                min = t;
            }
        }
        return min;
    }

    <T extends Comparable<T>> T[] sorted(T[] arr) {
        T[] copy = copy(arr);
        Collections.sort(toList(copy));
        return copy;
    }

    <T> void accept(ArrayList<T> list, Consumer<T> consumer) {
        for (T t : list) {
            consumer.accept(t);
        }
    }

    <T> void accept(ArrayList<T> list, BiConsumer<Integer, T> consumer) {
        for (int i = 0; i < list.size(); i++) {
            consumer.accept(i, list.get(i));
        }
    }

    <T, R> ArrayList<R> apply(ArrayList<T> list, Function<T, R> func) {
        ArrayList<R> newList = new ArrayList<>();
        accept(list, t -> newList.add(func.apply(t)));
        return newList;
    }

    <T> T reduce(ArrayList<T> list, BiFunction<T,T,T> func) {
        T cur = list.get(0);
        for (int i = 1; i < list.size(); i++) {
            T next = list.get(i);
            cur = func.apply(cur, next);
        }
        return cur;
    }


    <T, R> ArrayList<R> apply(ArrayList<T> list, BiFunction<Integer, T, R> func) {
        ArrayList<R> newList = new ArrayList<>();
        accept(list, (i, t) -> newList.add(func.apply(i, t)));
        return newList;
    }

    <T> ArrayList<T> reverse(ArrayList<T> list) {
        ArrayList<T> reversed = apply(list, t -> t);
        Collections.reverse(reversed);
        return reversed;
    }

    <T> void reverseAccept(ArrayList<T> list, BiConsumer<Integer, T> consumer) {
        for (int i = list.size() - 1; i >= 0; i--) {
            consumer.accept(i, list.get(i));
        }
    }

    <T> ArrayList<T> reverseApply(ArrayList<T> list, BiFunction<Integer, T, T> func) {
        ArrayList<T> newList = new ArrayList<>();
        reverseAccept(list, (i, t) -> newList.add(func.apply(i, t)));
        return newList;
    }

    <T> T[] reverse(T[] arr) {
        return toArray(reverse(toList(arr)));
    }

    void repeat(int count, Runnable r) {
        for (int i = 0; i < count; i++) {
            r.run();
        }
    }

    final long NEG_INF = Long.MIN_VALUE;
    final long INF = Long.MAX_VALUE;

    ArrayList<Long> zerosList(int n) {
        return fill(n, 0L);
    }

    ArrayList<Long> negInfList(int n) {
        return fill(n, -(Long.MIN_VALUE / 2));
    }

    ArrayList<Long> posInfList(int n) {
        return fill(n, Long.MIN_VALUE / 2);
    }

    ArrayList<Long> fill(int size, long item) {
        ArrayList<Long> list = new ArrayList<>(size);
        repeat(size, () -> list.add(item));
        return list;
    }

    public void yes() {
        sb.append("YES\n");
    }

    public void no() {
        sb.append("NO\n");
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(Reader in) {
            br = new BufferedReader(in);
        }

        public FastScanner(InputStream in) {
            this(new InputStreamReader(in));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public long[] nextArrLongs(int n) {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = this.nextLong();
            }
            return arr;
        }

        public ArrayList<Integer> nextListInts(int n) {
            ArrayList<Integer> list = new ArrayList<>();
            repeat(n, () -> list.add(s.nextInt()));
            return list;
        }

        public ArrayList<Long> nextListLongs(int n) {
            ArrayList<Long> list = new ArrayList<>();
            repeat(n, () -> list.add(s.nextLong()));
            return list;
        }

        public ArrayList<Double> nextListDoubles(int n) {
            ArrayList<Double> list = new ArrayList<>();
            repeat(n, () -> list.add(s.nextDouble()));
            return list;
        }

        public Pair nextPair() {
            return new Pair(s.nextLong(), s.nextLong());
        }

        public AL<Pair> readNextListPairs(int n) {
            var list = new AL<Pair>();
            repeat(n, () -> list.add(nextPair()));
            return list;
        }

        public AL<IndexedPair> readNextListIndexedPairs(int n) {
            var list = new AL<Pair>();
            repeat(n, () -> list.add(nextPair()));
            var list2 = new AL<IndexedPair>();
            accept(list, (i, p) -> list2.add(new IndexedPair(i, p)));
            return list2;
        }

        public AL<String> nextListStrings(int n) {
            AL<String> list = new AL<>();
            repeat(n, () -> list.add(s.next()));
            return list;
        }

        public String[] nextArrStrings(int n) {
            String[] arr = new String[n];
            for (int i = 0; i < n; i++) {
                arr[i] = this.next();
            }
            return arr;
        }

        public double[] nextArrDoubles(int n) {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++) {
                arr[i] = this.nextDouble();
            }
            return arr;
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

    }
}