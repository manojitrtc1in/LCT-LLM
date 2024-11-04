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
            i = (T) sc.next();
            j = (T) sc.next();
        }

        public boolean equals(Idx2<T> other) {
            return i.equals(other.i) && j.equals(other.j);
        }

        public boolean lessThan(Idx2<T> other) {
            return i < other.i && j < other.j;
        }
    }

    static class _DummyType {
    }

    static class ValueType<T> {
        public static class clean_type1 {
        }

        public static class clean_type {
        }

        public static class type {
        }
    }

    static class _CleanType<T> {
        public static class _type {
        }

        public static class type {
        }
    }

    static class _IsIterable<T> {
        public static int value = 0;
    }

    static class strict_item_type<T> {
        public static class type {
        }
    }

    static class _null<T> {
        public static T value() {
            return null;
        }
    }

    static class cmap<T> {
        public static class key_type {
        }

        public static class read {
        }
    }

    static class citerator<T> {
        public static class value_type {
        }

        public static value_type resolve(Iterable<T> a, Iterator<T> it) {
            return it.next();
        }

        public static value_type xresolve(List<T> a, ListIterator<T> it) {
            return it.next();
        }
    }

    static class _seq<T> {
        public static void process(T t, Object f) {
            // TODO: Implement process method
        }
    }

    static class _io<T> {
        public static void read(T x, int i) {
            Scanner sc = new Scanner(System.in);
            if (x instanceof Integer) {
                x = (T) Integer.valueOf(sc.nextInt());
            } else if (x instanceof Long) {
                x = (T) Long.valueOf(sc.nextLong());
            } else if (x instanceof Double) {
                x = (T) Double.valueOf(sc.nextDouble());
            } else if (x instanceof Character) {
                x = (T) Character.valueOf(sc.next().charAt(0));
            } else if (x instanceof Boolean) {
                x = (T) Boolean.valueOf(sc.nextBoolean());
            } else if (x instanceof String) {
                x = (T) sc.next();
            }
        }

        public static void write(T x) {
            System.out.print(x);
        }
    }

    static class SepComma {
        public static void Print() {
            System.out.print(", ");
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
                private T current = a;

                public boolean hasNext() {
                    return current < b;
                }

                public T next() {
                    return current++;
                }
            };
        }

        public int size() {
            return b < a ? 0 : b - a;
        }

        public T get(int i) {
            return a + i;
        }
    }

    static class _io<vector<T>> {
        public static void read(vector<T> x, int idx) {
            Scanner sc = new Scanner(System.in);
            int sz = sc.nextInt();
            for (int i = 0; i < sz; i++) {
                T val = (T) sc.next();
                x.add(val);
            }
        }

        public static void write(vector<T> x) {
            System.out.print("[");
            for (int i = 0; i < x.size() - 1; i++) {
                System.out.print(x.get(i) + ", ");
            }
            if (x.size() > 0) {
                System.out.print(x.get(x.size() - 1));
            }
            System.out.print("]");
        }
    }

    static class _io<map<T1, T2>> {
        public static void write(map<T1, T2> x) {
            System.out.print("{");
            for (Map.Entry<T1, T2> entry : x.entrySet()) {
                System.out.print(entry.getKey() + "=" + entry.getValue() + ", ");
            }
            System.out.print("}");
        }
    }

    static class _io<pair<T1, T2>> {
        public static void write(pair<T1, T2> x) {
            System.out.print("(" + x.first + ", " + x.second + ")");
        }
    }

    static class tup0 {
        public void _read(int i) {
        }

        public void __write() {
            System.out.print("(");
        }

        public void _write() {
            __write();
            System.out.print(")");
        }

        public boolean equals(Object other) {
            return true;
        }
    }

    static class _is_empty {
        public static int value = 0;
    }

    static class cmap<ArrType> {
        public static class key_type {
        }

        public static void write(ArrType a, int i, Object value) {
            a.set(i, value);
        }

        public static Object read(ArrType a, int i) {
            return a.get(i);
        }
    }

    static class ArrWrapper<T> implements Iterable<T> {
        ArrType a;
        int n;

        ArrWrapper(ArrType a, int n) {
            this.a = a;
            this.n = n;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private int current = 0;

                public boolean hasNext() {
                    return current < n;
                }

                public T next() {
                    return a.get(current++);
                }
            };
        }

        public int size() {
            return n;
        }

        public T get(int i) {
            return a.get(i);
        }

        public void erase(int p) {
            a.remove(p);
            n--;
        }

        public void process(Object f) {
            // TODO: Implement process method
        }
    }

    static class ArrWrapper<T> implements Iterable<T> {
        ArrType a;
        int n;

        ArrWrapper(ArrType a, int n) {
            this.a = a;
            this.n = n;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private int current = 0;

                public boolean hasNext() {
                    return current < n;
                }

                public T next() {
                    return a.get(current++);
                }
            };
        }

        public int size() {
            return n;
        }

        public T get(int i) {
            return a.get(i);
        }

        public void erase(int p) {
            a.remove(p);
            n--;
        }

        public void process(Object f) {
            // TODO: Implement process method
        }
    }

    static class id1<T> {
        ArrType a;
        int n, m;

        id1(ArrType a, int n, int m) {
            this.a = a;
            this.n = n;
            this.m = m;
        }

        public ArrWrapper<sub_type> operator[](int i) {
            return new ArrWrapper<sub_type>(a.get(i), m);
        }

        public ArrWrapper<sub_type> operator[](int i) {
            return new ArrWrapper<sub_type>(a.get(i), m);
        }

        public value_type operator[](Idx2<Integer> idx) {
            return a.get(idx.i).get(idx.j);
        }

        public value_type operator[](pair<Integer, Integer> idx) {
            return a.get(idx.first).get(idx.second);
        }

        public void _write() {
            System.out.print("<");
            for (int i = 0; i < n; i++) {
                System.out.print(operator[](i));
            }
            System.out.print(">");
        }

        public boolean is_valid_idx(pair<Integer, Integer> idx) {
            return idx.first >= 0 && idx.first < n && idx.second >= 0 && idx.second < m;
        }
    }

    static class _pair<T1, T2> {
        T1 first;
        T2 second;

        _pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class id6<S1, S2> {
        S1 s1;
        S2 s2;

        id6(S1 s1, S2 s2) {
            this.s1 = s1;
            this.s2 = s2;
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return s1.size() * s2.size();
        }

        public _pair<s1_type, s2_type> operator[](int i) {
            int t = s2.size();
            return new _pair<s1_type, s2_type>(s1.get(i / t), s2.get(i % t));
        }
    }

    static class id9<T> {
        T a;

        id9(T a) {
            this.a = a;
        }

        public id6<T, T2> operator%(T2 b) {
            return new id6<T, T2>(a, b);
        }
    }

    static class _cprod {
    }

    static class FilterWrapper<T> implements Iterable<T> {
        T a;
        Filter filter;

        FilterWrapper(T a, Filter filter) {
            this.a = a;
            this.filter = filter;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private Iterator<T> it = a.iterator();
                private T current = it.next();

                public boolean hasNext() {
                    while (it.hasNext() && !filter(current)) {
                        current = it.next();
                    }
                    return it.hasNext();
                }

                public T next() {
                    return current;
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            int res = 0;
            for (T x : a) {
                if (filter(x)) {
                    res++;
                }
            }
            return res;
        }
    }

    static class TakeWrapper<T> implements Iterable<T> {
        T a;
        int cnt;

        TakeWrapper(int cnt, T a) {
            this.cnt = cnt;
            this.a = a;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private Iterator<T> it = a.iterator();
                private int count = 0;

                public boolean hasNext() {
                    return count < cnt && it.hasNext();
                }

                public T next() {
                    count++;
                    return it.next();
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return Math.min(cnt, a.size());
        }
    }

    static class SumFtr<T> {
        public T operator(T a, T b) {
            return a + b;
        }
    }

    static class _sum_neutral<T> {
        public static T value() {
            return 0;
        }
    }

    static class xlen_<T> {
        public static int size(T a, int mx) {
            return a.size();
        }
    }

    static class key_type<T> {
        public static class type {
        }
    }

    static class _count {
        public static int count(T a) {
            int res = 0;
            for (T x : a) {
                res++;
            }
            return res;
        }
    }

    static class StrictSize<T> {
        public static int size(T a) {
            return a.size();
        }
    }

    static class id11<T, F> {
        T a;
        F f;

        id11(T a, F f) {
            this.a = a;
            this.f = f;
        }

        public MapWrapper<T, F, zzz> operator%(zzz) {
            return new MapWrapper<T, F, zzz>(a, f);
        }
    }

    static class MapWrapper<T, F, S> implements Iterable<S> {
        T a;
        F f;

        MapWrapper(T a, F f) {
            this.a = a;
            this.f = f;
        }

        public Iterator<S> iterator() {
            return new Iterator<S>() {
                private Iterator<T> it = a.iterator();

                public boolean hasNext() {
                    return it.hasNext();
                }

                public S next() {
                    return f(it.next());
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return a.size();
        }
    }

    static class _take {
        public static TakeWrapper<T> take(int cnt, T a) {
            return new TakeWrapper<T>(cnt, a);
        }
    }

    static class _pair<T1, T2> {
        T1 first;
        T2 second;

        _pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class id12<T1, T2> {
        T1 name1;
        T2 name2;

        id12(T1 name1, T2 name2) {
            this.name1 = name1;
            this.name2 = name2;
        }
    }

    static class id9<T> {
        T a;

        id9(T a) {
            this.a = a;
        }

        public id6<T, T2> operator%(T2 b) {
            return new id6<T, T2>(a, b);
        }
    }

    static class _cprod {
    }

    static class FilterWrapper<T> implements Iterable<T> {
        T a;
        Filter filter;

        FilterWrapper(T a, Filter filter) {
            this.a = a;
            this.filter = filter;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private Iterator<T> it = a.iterator();
                private T current = it.next();

                public boolean hasNext() {
                    while (it.hasNext() && !filter(current)) {
                        current = it.next();
                    }
                    return it.hasNext();
                }

                public T next() {
                    return current;
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            int res = 0;
            for (T x : a) {
                if (filter(x)) {
                    res++;
                }
            }
            return res;
        }
    }

    static class TakeWrapper<T> implements Iterable<T> {
        T a;
        int cnt;

        TakeWrapper(int cnt, T a) {
            this.cnt = cnt;
            this.a = a;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private Iterator<T> it = a.iterator();
                private int count = 0;

                public boolean hasNext() {
                    return count < cnt && it.hasNext();
                }

                public T next() {
                    count++;
                    return it.next();
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return Math.min(cnt, a.size());
        }
    }

    static class SumFtr<T> {
        public T operator(T a, T b) {
            return a + b;
        }
    }

    static class _sum_neutral<T> {
        public static T value() {
            return 0;
        }
    }

    static class xlen_<T> {
        public static int size(T a, int mx) {
            return a.size();
        }
    }

    static class key_type<T> {
        public static class type {
        }
    }

    static class _count {
        public static int count(T a) {
            int res = 0;
            for (T x : a) {
                res++;
            }
            return res;
        }
    }

    static class StrictSize<T> {
        public static int size(T a) {
            return a.size();
        }
    }

    static class id11<T, F> {
        T a;
        F f;

        id11(T a, F f) {
            this.a = a;
            this.f = f;
        }

        public MapWrapper<T, F, zzz> operator%(zzz) {
            return new MapWrapper<T, F, zzz>(a, f);
        }
    }

    static class MapWrapper<T, F, S> implements Iterable<S> {
        T a;
        F f;

        MapWrapper(T a, F f) {
            this.a = a;
            this.f = f;
        }

        public Iterator<S> iterator() {
            return new Iterator<S>() {
                private Iterator<T> it = a.iterator();

                public boolean hasNext() {
                    return it.hasNext();
                }

                public S next() {
                    return f(it.next());
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return a.size();
        }
    }

    static class _take {
        public static TakeWrapper<T> take(int cnt, T a) {
            return new TakeWrapper<T>(cnt, a);
        }
    }

    static class _pair<T1, T2> {
        T1 first;
        T2 second;

        _pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class id12<T1, T2> {
        T1 name1;
        T2 name2;

        id12(T1 name1, T2 name2) {
            this.name1 = name1;
            this.name2 = name2;
        }
    }

    static class id6<S1, S2> {
        S1 s1;
        S2 s2;

        id6(S1 s1, S2 s2) {
            this.s1 = s1;
            this.s2 = s2;
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return s1.size() * s2.size();
        }

        public _pair<s1_type, s2_type> operator[](int i) {
            int t = s2.size();
            return new _pair<s1_type, s2_type>(s1.get(i / t), s2.get(i % t));
        }
    }

    static class id9<T> {
        T a;

        id9(T a) {
            this.a = a;
        }

        public id6<T, T2> operator%(T2 b) {
            return new id6<T, T2>(a, b);
        }
    }

    static class _cprod {
    }

    static class FilterWrapper<T> implements Iterable<T> {
        T a;
        Filter filter;

        FilterWrapper(T a, Filter filter) {
            this.a = a;
            this.filter = filter;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private Iterator<T> it = a.iterator();
                private T current = it.next();

                public boolean hasNext() {
                    while (it.hasNext() && !filter(current)) {
                        current = it.next();
                    }
                    return it.hasNext();
                }

                public T next() {
                    return current;
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            int res = 0;
            for (T x : a) {
                if (filter(x)) {
                    res++;
                }
            }
            return res;
        }
    }

    static class TakeWrapper<T> implements Iterable<T> {
        T a;
        int cnt;

        TakeWrapper(int cnt, T a) {
            this.cnt = cnt;
            this.a = a;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private Iterator<T> it = a.iterator();
                private int count = 0;

                public boolean hasNext() {
                    return count < cnt && it.hasNext();
                }

                public T next() {
                    count++;
                    return it.next();
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return Math.min(cnt, a.size());
        }
    }

    static class SumFtr<T> {
        public T operator(T a, T b) {
            return a + b;
        }
    }

    static class _sum_neutral<T> {
        public static T value() {
            return 0;
        }
    }

    static class xlen_<T> {
        public static int size(T a, int mx) {
            return a.size();
        }
    }

    static class key_type<T> {
        public static class type {
        }
    }

    static class _count {
        public static int count(T a) {
            int res = 0;
            for (T x : a) {
                res++;
            }
            return res;
        }
    }

    static class StrictSize<T> {
        public static int size(T a) {
            return a.size();
        }
    }

    static class id11<T, F> {
        T a;
        F f;

        id11(T a, F f) {
            this.a = a;
            this.f = f;
        }

        public MapWrapper<T, F, zzz> operator%(zzz) {
            return new MapWrapper<T, F, zzz>(a, f);
        }
    }

    static class MapWrapper<T, F, S> implements Iterable<S> {
        T a;
        F f;

        MapWrapper(T a, F f) {
            this.a = a;
            this.f = f;
        }

        public Iterator<S> iterator() {
            return new Iterator<S>() {
                private Iterator<T> it = a.iterator();

                public boolean hasNext() {
                    return it.hasNext();
                }

                public S next() {
                    return f(it.next());
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return a.size();
        }
    }

    static class _take {
        public static TakeWrapper<T> take(int cnt, T a) {
            return new TakeWrapper<T>(cnt, a);
        }
    }

    static class _pair<T1, T2> {
        T1 first;
        T2 second;

        _pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class id12<T1, T2> {
        T1 name1;
        T2 name2;

        id12(T1 name1, T2 name2) {
            this.name1 = name1;
            this.name2 = name2;
        }
    }

    static class id6<S1, S2> {
        S1 s1;
        S2 s2;

        id6(S1 s1, S2 s2) {
            this.s1 = s1;
            this.s2 = s2;
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return s1.size() * s2.size();
        }

        public _pair<s1_type, s2_type> operator[](int i) {
            int t = s2.size();
            return new _pair<s1_type, s2_type>(s1.get(i / t), s2.get(i % t));
        }
    }

    static class id9<T> {
        T a;

        id9(T a) {
            this.a = a;
        }

        public id6<T, T2> operator%(T2 b) {
            return new id6<T, T2>(a, b);
        }
    }

    static class _cprod {
    }

    static class FilterWrapper<T> implements Iterable<T> {
        T a;
        Filter filter;

        FilterWrapper(T a, Filter filter) {
            this.a = a;
            this.filter = filter;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private Iterator<T> it = a.iterator();
                private T current = it.next();

                public boolean hasNext() {
                    while (it.hasNext() && !filter(current)) {
                        current = it.next();
                    }
                    return it.hasNext();
                }

                public T next() {
                    return current;
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            int res = 0;
            for (T x : a) {
                if (filter(x)) {
                    res++;
                }
            }
            return res;
        }
    }

    static class TakeWrapper<T> implements Iterable<T> {
        T a;
        int cnt;

        TakeWrapper(int cnt, T a) {
            this.cnt = cnt;
            this.a = a;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private Iterator<T> it = a.iterator();
                private int count = 0;

                public boolean hasNext() {
                    return count < cnt && it.hasNext();
                }

                public T next() {
                    count++;
                    return it.next();
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return Math.min(cnt, a.size());
        }
    }

    static class SumFtr<T> {
        public T operator(T a, T b) {
            return a + b;
        }
    }

    static class _sum_neutral<T> {
        public static T value() {
            return 0;
        }
    }

    static class xlen_<T> {
        public static int size(T a, int mx) {
            return a.size();
        }
    }

    static class key_type<T> {
        public static class type {
        }
    }

    static class _count {
        public static int count(T a) {
            int res = 0;
            for (T x : a) {
                res++;
            }
            return res;
        }
    }

    static class StrictSize<T> {
        public static int size(T a) {
            return a.size();
        }
    }

    static class id11<T, F> {
        T a;
        F f;

        id11(T a, F f) {
            this.a = a;
            this.f = f;
        }

        public MapWrapper<T, F, zzz> operator%(zzz) {
            return new MapWrapper<T, F, zzz>(a, f);
        }
    }

    static class MapWrapper<T, F, S> implements Iterable<S> {
        T a;
        F f;

        MapWrapper(T a, F f) {
            this.a = a;
            this.f = f;
        }

        public Iterator<S> iterator() {
            return new Iterator<S>() {
                private Iterator<T> it = a.iterator();

                public boolean hasNext() {
                    return it.hasNext();
                }

                public S next() {
                    return f(it.next());
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return a.size();
        }
    }

    static class _take {
        public static TakeWrapper<T> take(int cnt, T a) {
            return new TakeWrapper<T>(cnt, a);
        }
    }

    static class _pair<T1, T2> {
        T1 first;
        T2 second;

        _pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class id12<T1, T2> {
        T1 name1;
        T2 name2;

        id12(T1 name1, T2 name2) {
            this.name1 = name1;
            this.name2 = name2;
        }
    }

    static class id6<S1, S2> {
        S1 s1;
        S2 s2;

        id6(S1 s1, S2 s2) {
            this.s1 = s1;
            this.s2 = s2;
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return s1.size() * s2.size();
        }

        public _pair<s1_type, s2_type> operator[](int i) {
            int t = s2.size();
            return new _pair<s1_type, s2_type>(s1.get(i / t), s2.get(i % t));
        }
    }

    static class id9<T> {
        T a;

        id9(T a) {
            this.a = a;
        }

        public id6<T, T2> operator%(T2 b) {
            return new id6<T, T2>(a, b);
        }
    }

    static class _cprod {
    }

    static class FilterWrapper<T> implements Iterable<T> {
        T a;
        Filter filter;

        FilterWrapper(T a, Filter filter) {
            this.a = a;
            this.filter = filter;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private Iterator<T> it = a.iterator();
                private T current = it.next();

                public boolean hasNext() {
                    while (it.hasNext() && !filter(current)) {
                        current = it.next();
                    }
                    return it.hasNext();
                }

                public T next() {
                    return current;
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            int res = 0;
            for (T x : a) {
                if (filter(x)) {
                    res++;
                }
            }
            return res;
        }
    }

    static class TakeWrapper<T> implements Iterable<T> {
        T a;
        int cnt;

        TakeWrapper(int cnt, T a) {
            this.cnt = cnt;
            this.a = a;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private Iterator<T> it = a.iterator();
                private int count = 0;

                public boolean hasNext() {
                    return count < cnt && it.hasNext();
                }

                public T next() {
                    count++;
                    return it.next();
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return Math.min(cnt, a.size());
        }
    }

    static class SumFtr<T> {
        public T operator(T a, T b) {
            return a + b;
        }
    }

    static class _sum_neutral<T> {
        public static T value() {
            return 0;
        }
    }

    static class xlen_<T> {
        public static int size(T a, int mx) {
            return a.size();
        }
    }

    static class key_type<T> {
        public static class type {
        }
    }

    static class _count {
        public static int count(T a) {
            int res = 0;
            for (T x : a) {
                res++;
            }
            return res;
        }
    }

    static class StrictSize<T> {
        public static int size(T a) {
            return a.size();
        }
    }

    static class id11<T, F> {
        T a;
        F f;

        id11(T a, F f) {
            this.a = a;
            this.f = f;
        }

        public MapWrapper<T, F, zzz> operator%(zzz) {
            return new MapWrapper<T, F, zzz>(a, f);
        }
    }

    static class MapWrapper<T, F, S> implements Iterable<S> {
        T a;
        F f;

        MapWrapper(T a, F f) {
            this.a = a;
            this.f = f;
        }

        public Iterator<S> iterator() {
            return new Iterator<S>() {
                private Iterator<T> it = a.iterator();

                public boolean hasNext() {
                    return it.hasNext();
                }

                public S next() {
                    return f(it.next());
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return a.size();
        }
    }

    static class _take {
        public static TakeWrapper<T> take(int cnt, T a) {
            return new TakeWrapper<T>(cnt, a);
        }
    }

    static class _pair<T1, T2> {
        T1 first;
        T2 second;

        _pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class id12<T1, T2> {
        T1 name1;
        T2 name2;

        id12(T1 name1, T2 name2) {
            this.name1 = name1;
            this.name2 = name2;
        }
    }

    static class id6<S1, S2> {
        S1 s1;
        S2 s2;

        id6(S1 s1, S2 s2) {
            this.s1 = s1;
            this.s2 = s2;
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return s1.size() * s2.size();
        }

        public _pair<s1_type, s2_type> operator[](int i) {
            int t = s2.size();
            return new _pair<s1_type, s2_type>(s1.get(i / t), s2.get(i % t));
        }
    }

    static class id9<T> {
        T a;

        id9(T a) {
            this.a = a;
        }

        public id6<T, T2> operator%(T2 b) {
            return new id6<T, T2>(a, b);
        }
    }

    static class _cprod {
    }

    static class FilterWrapper<T> implements Iterable<T> {
        T a;
        Filter filter;

        FilterWrapper(T a, Filter filter) {
            this.a = a;
            this.filter = filter;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private Iterator<T> it = a.iterator();
                private T current = it.next();

                public boolean hasNext() {
                    while (it.hasNext() && !filter(current)) {
                        current = it.next();
                    }
                    return it.hasNext();
                }

                public T next() {
                    return current;
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            int res = 0;
            for (T x : a) {
                if (filter(x)) {
                    res++;
                }
            }
            return res;
        }
    }

    static class TakeWrapper<T> implements Iterable<T> {
        T a;
        int cnt;

        TakeWrapper(int cnt, T a) {
            this.cnt = cnt;
            this.a = a;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private Iterator<T> it = a.iterator();
                private int count = 0;

                public boolean hasNext() {
                    return count < cnt && it.hasNext();
                }

                public T next() {
                    count++;
                    return it.next();
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return Math.min(cnt, a.size());
        }
    }

    static class SumFtr<T> {
        public T operator(T a, T b) {
            return a + b;
        }
    }

    static class _sum_neutral<T> {
        public static T value() {
            return 0;
        }
    }

    static class xlen_<T> {
        public static int size(T a, int mx) {
            return a.size();
        }
    }

    static class key_type<T> {
        public static class type {
        }
    }

    static class _count {
        public static int count(T a) {
            int res = 0;
            for (T x : a) {
                res++;
            }
            return res;
        }
    }

    static class StrictSize<T> {
        public static int size(T a) {
            return a.size();
        }
    }

    static class id11<T, F> {
        T a;
        F f;

        id11(T a, F f) {
            this.a = a;
            this.f = f;
        }

        public MapWrapper<T, F, zzz> operator%(zzz) {
            return new MapWrapper<T, F, zzz>(a, f);
        }
    }

    static class MapWrapper<T, F, S> implements Iterable<S> {
        T a;
        F f;

        MapWrapper(T a, F f) {
            this.a = a;
            this.f = f;
        }

        public Iterator<S> iterator() {
            return new Iterator<S>() {
                private Iterator<T> it = a.iterator();

                public boolean hasNext() {
                    return it.hasNext();
                }

                public S next() {
                    return f(it.next());
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return a.size();
        }
    }

    static class _take {
        public static TakeWrapper<T> take(int cnt, T a) {
            return new TakeWrapper<T>(cnt, a);
        }
    }

    static class _pair<T1, T2> {
        T1 first;
        T2 second;

        _pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class id12<T1, T2> {
        T1 name1;
        T2 name2;

        id12(T1 name1, T2 name2) {
            this.name1 = name1;
            this.name2 = name2;
        }
    }

    static class id6<S1, S2> {
        S1 s1;
        S2 s2;

        id6(S1 s1, S2 s2) {
            this.s1 = s1;
            this.s2 = s2;
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return s1.size() * s2.size();
        }

        public _pair<s1_type, s2_type> operator[](int i) {
            int t = s2.size();
            return new _pair<s1_type, s2_type>(s1.get(i / t), s2.get(i % t));
        }
    }

    static class id9<T> {
        T a;

        id9(T a) {
            this.a = a;
        }

        public id6<T, T2> operator%(T2 b) {
            return new id6<T, T2>(a, b);
        }
    }

    static class _cprod {
    }

    static class FilterWrapper<T> implements Iterable<T> {
        T a;
        Filter filter;

        FilterWrapper(T a, Filter filter) {
            this.a = a;
            this.filter = filter;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private Iterator<T> it = a.iterator();
                private T current = it.next();

                public boolean hasNext() {
                    while (it.hasNext() && !filter(current)) {
                        current = it.next();
                    }
                    return it.hasNext();
                }

                public T next() {
                    return current;
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            int res = 0;
            for (T x : a) {
                if (filter(x)) {
                    res++;
                }
            }
            return res;
        }
    }

    static class TakeWrapper<T> implements Iterable<T> {
        T a;
        int cnt;

        TakeWrapper(int cnt, T a) {
            this.cnt = cnt;
            this.a = a;
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                private Iterator<T> it = a.iterator();
                private int count = 0;

                public boolean hasNext() {
                    return count < cnt && it.hasNext();
                }

                public T next() {
                    count++;
                    return it.next();
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return Math.min(cnt, a.size());
        }
    }

    static class SumFtr<T> {
        public T operator(T a, T b) {
            return a + b;
        }
    }

    static class _sum_neutral<T> {
        public static T value() {
            return 0;
        }
    }

    static class xlen_<T> {
        public static int size(T a, int mx) {
            return a.size();
        }
    }

    static class key_type<T> {
        public static class type {
        }
    }

    static class _count {
        public static int count(T a) {
            int res = 0;
            for (T x : a) {
                res++;
            }
            return res;
        }
    }

    static class StrictSize<T> {
        public static int size(T a) {
            return a.size();
        }
    }

    static class id11<T, F> {
        T a;
        F f;

        id11(T a, F f) {
            this.a = a;
            this.f = f;
        }

        public MapWrapper<T, F, zzz> operator%(zzz) {
            return new MapWrapper<T, F, zzz>(a, f);
        }
    }

    static class MapWrapper<T, F, S> implements Iterable<S> {
        T a;
        F f;

        MapWrapper(T a, F f) {
            this.a = a;
            this.f = f;
        }

        public Iterator<S> iterator() {
            return new Iterator<S>() {
                private Iterator<T> it = a.iterator();

                public boolean hasNext() {
                    return it.hasNext();
                }

                public S next() {
                    return f(it.next());
                }
            };
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return a.size();
        }
    }

    static class _take {
        public static TakeWrapper<T> take(int cnt, T a) {
            return new TakeWrapper<T>(cnt, a);
        }
    }

    static class _pair<T1, T2> {
        T1 first;
        T2 second;

        _pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class id12<T1, T2> {
        T1 name1;
        T2 name2;

        id12(T1 name1, T2 name2) {
            this.name1 = name1;
            this.name2 = name2;
        }
    }

    static class id6<S1, S2> {
        S1 s1;
        S2 s2;

        id6(S1 s1, S2 s2) {
            this.s1 = s1;
            this.s2 = s2;
        }

        public void process(Object f) {
            // TODO: Implement process method
        }

        public int size() {
            return s1.size() * s2.size();
        }

        public _pair<s1_type, s2_type> operator[](int i) {
            int t = s2.size();
            return new _pair<s1_type, s2_type>(s1.get(i / t), s2.get(i % t));
        }
    }

    static class id9<T> {
        T a;

        id9(T a) {
            this.a = a;
        }

        public id6<T, T2> operator%(T2 b) {
            return new id6<T, T2>(a, b);
        }
    }

    static class _cprod {
    }

    static class FilterWrapper<T> implements Iterable<T> {
        T a;
        Filter filter;

        FilterWrapper(T a, Filter filter) {
