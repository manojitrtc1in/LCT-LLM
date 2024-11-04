import java.util.*;

class Main {
    static class Idx2<T> {
        T i, j;
        Idx2(T i, T j) {
            this.i = i;
            this.j = j;
        }
        Idx2() {
            this.i = null;
            this.j = null;
        }
        public void _write() {
            System.out.print("(" + i + ", " + j + ")");
        }
        public void _read(int idx) {
            Scanner sc = new Scanner(System.in);
            i = (T)sc.next();
            j = (T)sc.next();
        }
        public boolean equals(Idx2<T> other) {
            return i.equals(other.i) && j.equals(other.j);
        }
        public boolean lessThan(Idx2<T> other) {
            return i.compareTo(other.i) < 0 || (i.equals(other.i) && j.compareTo(other.j) < 0);
        }
    }

    static class tup0 {
        public void _read(int i) {}
        public void __write() {
            System.out.print("(");
        }
        public void _write() {
            __write();
            System.out.print(")");
        }
        public boolean equals(tup0 other) {
            return true;
        }
    }

    static class tup1<T1> extends tup0 {
        T1 f;
        tup1(T1 f) {
            this.f = f;
        }
        public void __write() {
            super.__write();
            System.out.print("f:" + f);
        }
        public boolean equals(tup1<T1> other) {
            return super.equals(other) && f.equals(other.f);
        }
    }

    static class tup2<T1, T2> extends tup1<T1> {
        T2 s;
        tup2(T1 f, T2 s) {
            super(f);
            this.s = s;
        }
        public void __write() {
            super.__write();
            System.out.print(", s:" + s);
        }
        public boolean equals(tup2<T1, T2> other) {
            return super.equals(other) && s.equals(other.s);
        }
    }

    static class ArrWrapper<T> {
        T[] a;
        int n;
        ArrWrapper(T[] a, int n) {
            this.a = a;
            this.n = n;
        }
        public int size(int mx) {
            return n;
        }
        public T resolveIterator(int it) {
            return a[it];
        }
        public T get(int i) {
            return a[i];
        }
        public void erase(int p) {
            for (int i = p + 1; i < n; i++) {
                a[i-1] = a[i];
            }
            n--;
        }
        public void process(Processor<T> f) {
            for (int i = 0; i < n; i++) {
                if (!f.process(a[i])) {
                    break;
                }
            }
        }
        public void _write() {
            System.out.print("[");
            for (int i = 0; i < n-1; i++) {
                System.out.print(a[i] + ", ");
            }
            if (n > 0) {
                System.out.print(a[n-1]);
            }
            System.out.print("]");
        }
    }

    static class ArrWrapper2<T> {
        T[][] a;
        int n, m;
        ArrWrapper2(T[][] a, int n, int m) {
            this.a = a;
            this.n = n;
            this.m = m;
        }
        public int size(int mx) {
            return n * m;
        }
        public T resolveIterator(Idx2<Integer> it) {
            return a[it.i][it.j];
        }
        public ArrWrapper<T> get(int i) {
            return new ArrWrapper<T>(a[i], m);
        }
        public void process(Processor<T> f) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!f.process(a[i][j])) {
                        break;
                    }
                }
            }
        }
        public void _write() {
            System.out.print("<");
            for (int i = 0; i < n; i++) {
                System.out.print(get(i));
            }
            System.out.print(">");
        }
    }

    static class Processor<T> {
        boolean process(T t) {
            return true;
        }
    }

    static class Range<T> implements Iterable<T> {
        T a, b;
        Range(T a, T b) {
            this.a = a;
            this.b = b;
        }
        public Iterator<T> iterator() {
            return new Iterator<T>() {
                T current = a;
                public boolean hasNext() {
                    return !current.equals(b);
                }
                public T next() {
                    T res = current;
                    current = (T)((Integer)current + 1);
                    return res;
                }
            };
        }
    }

    static class SepComma {
        public void print() {
            System.out.print(", ");
        }
    }

    static class SumFtr<T> {
        T operator(T a, T b) {
            return a + b;
        }
    }

    static class _sum_neutral<T> {
        T value() {
            return 0;
        }
    }

    static <T> T _sum(Iterable<T> a) {
        T res = _sum_neutral<T>.value();
        for (T x : a) {
            res = SumFtr<T>.operator(res, x);
        }
        return res;
    }

    static class _DummyType {}

    static class ValueType<T> {
        Class<?> clean_type1 = T.class;
        Class<?> clean_type = clean_type1;
        Class<?> type = clean_type.value_type;
    }

    static class _CleanType<T> {
        Class<?> _type = T.class;
        Class<?> type = _type;
    }

    static class _IsIterable<T> {
        boolean value = false;
    }

    static class _io<T> {
        static void read(T x, int i) {
            Scanner sc = new Scanner(System.in);
            if (x instanceof Integer) {
                x = (T)sc.nextInt();
            } else if (x instanceof Long) {
                x = (T)sc.nextLong();
            } else if (x instanceof Double) {
                x = (T)sc.nextDouble();
            } else if (x instanceof Character) {
                x = (T)sc.next().charAt(0);
            } else if (x instanceof Boolean) {
                x = (T)(Boolean)(sc.nextInt() != 0);
            } else if (x instanceof String) {
                x = (T)sc.next();
            }
        }
        static void write(T x) {
            System.out.print(x);
        }
    }

    static class key_type<T> {
        Class<?> type = Integer.class;
    }

    static class cmap<T> {
        static void write(T a, int i, Object value) {
            a[i] = (T)value;
        }
        static T read(T a, int i) {
            return a[i];
        }
    }

    static class xlen_<T> {
        static int size(T a, int mx) {
            return a.size();
        }
    }

    static class xlen_<String> {
        static int size(String s, int mx) {
            return s.length();
        }
    }

    static class xlen_<List<T>> {
        static int size(List<T> v, int mx) {
            return v.size();
        }
    }

    static class xlen_<Set<T>> {
        static int size(Set<T> s, int mx) {
            return s.size();
        }
    }

    static class xlen_<Map<T, S>> {
        static int size(Map<S, T> m, int mx) {
            return m.size();
        }
    }

    static class xlen_<Range<T>> {
        static int size(Range<T> r, int mx) {
            return r.size();
        }
    }

    static class xlen_<ArrWrapper<T>> {
        static int size(ArrWrapper<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

    static class xlen_<MapWrapper<T, F, S>> {
        static int size(MapWrapper<T, F, S> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<SimpleMapWrapper<T, F>> {
        static int size(SimpleMapWrapper<T, F> m, int mx) {
            return m.size(mx);
        }
    }

    static class xlen_<ArrWrapper2<T>> {
        static int size(ArrWrapper2<T> a, int mx) {
            return a.size(mx);
        }
    }

    static class xlen_<FilterWrapper<T, Filter>> {
        static int size(FilterWrapper<T, Filter> f, int mx) {
            return f.size(mx);
        }
    }

    static class xlen_<TakeWrapper<T>> {
        static int size(TakeWrapper<T> t, int mx) {
            return t.size(mx);
        }
    }

    static class xlen_<CartProdWrapper<S1, S2>> {
        static int size(CartProdWrapper<S1, S2> c, int mx) {
            return c.size(mx);
        }
    }

