import java.util.*;

class Idx2<T> {
    T i, j;
    Idx2(T i, T j) {
        this.i = i;
        this.j = j;
    }
    Idx2() {
        this.i = null;
        this.j = null;
    }
    void _write() {
        System.out.print("(" + i + ", " + j + ")");
    }
    void _read(int idx) {
        // Read i and j from input
    }
    boolean equals(Idx2<T> other) {
        return i.equals(other.i) && j.equals(other.j);
    }
}

class SepComma {
    static void Print() {
        System.out.print(", ");
    }
}

class Range<T> implements Iterable<T> {
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
            public void remove() {
                throw new UnsupportedOperationException();
            }
        };
    }
    int size(int mx) {
        return b < a ? 0 : b - a;
    }
    T get(int i) {
        return a + i;
    }
    void process(Consumer<T> f) {
        for (T i = a; i < b; i++) {
            if (!f.accept(i)) {
                break;
            }
        }
    }
}

class _null<T> {
    static T value() {
        return null;
    }
}

class cmap<T> {
    static <K, V> void write(T a, K i, V value) {
        // Write value to a at index i
    }
    static <K, V> V read(T a, K i) {
        // Read value from a at index i
        return null;
    }
}

class ANMap<T1, T2> {
    Map<T1, T2> m;
    ANMap() {
        m = new HashMap<>();
    }
    T2 get(T1 idx) {
        return m.get(idx);
    }
    void set(T1 idx, T2 value) {
        m.put(idx, value);
    }
    void _write() {
        System.out.print(m);
    }
}

class ArrWrapper<T> implements Iterable<T> {
    T[] a;
    int n;
    ArrWrapper(T[] a, int n) {
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
                return a[current++];
            }
            public void remove() {
                throw new UnsupportedOperationException();
            }
        };
    }
    int size(int mx) {
        return n;
    }
    T get(int i) {
        return a[i];
    }
    void erase(int p) {
        assert p < n;
        for (int i = p + 1; i < n; i++) {
            a[i - 1] = a[i];
        }
        n--;
    }
    void process(Consumer<T> f) {
        for (int i = 0; i < n; i++) {
            if (!f.accept(a[i])) {
                break;
            }
        }
    }
}

class Mul {
    static class _mul<T> {
        T a;
        _mul(T a) {
            this.a = a;
        }
        T mod(T b) {
            // Perform a % b
            return null;
        }
    }
    static <T> _mul<T> mod(T a) {
        return new _mul<>(a);
    }
}

class int_abc {
    int a, b, c;
    int_abc(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    boolean equals(int_abc other) {
        return a == other.a && b == other.b && c == other.c;
    }
}

class Graph {
    int n, vol, e;
    int[] a, b;
    int_uv[] ee;
    Graph(int n, int vol, int e, int[] a, int[] b, int_uv[] ee) {
        this.n = n;
        this.vol = vol;
        this.e = e;
        this.a = a;
        this.b = b;
        this.ee = ee;
    }
}

class _io<T> {
    static void read(T x, int i) {
        // Read x from input
    }
    static void write(T x) {
        System.out.print(x);
    }
}

class _IsIterable<T> {
    static final boolean value = false;
}

class _CleanType<T> {
    static class _type {
        static final T type = null;
    }
    static _type value() {
        return new _type();
    }
}

class _seq<T> {
    static void process(T t, Consumer<Object> f) {
        // Process t using f
    }
}

class _seq_const<T> {
    static void process(T t, Consumer<Object> f) {
        // Process t using f
    }
}

class _seq_vector<T> {
    static void process(List<T> t, Consumer<Object> f) {
        for (T item : t) {
            if (!f.accept(item)) {
                break;
            }
        }
    }
}

class _seq_set<T> {
    static void process(Set<T> t, Consumer<Object> f) {
        for (T item : t) {
            if (!f.accept(item)) {
                break;
            }
        }
    }
}

class _seq_map<T1, T2> {
    static void process(Map<T1, T2> t, Consumer<Object> f) {
        for (Map.Entry<T1, T2> entry : t.entrySet()) {
            if (!f.accept(entry)) {
                break;
            }
        }
    }
}

class _seq_string {
    static void process(String s, Consumer<Object> f) {
        for (int i = 0; i < s.length(); i++) {
            if (!f.accept(s.charAt(i))) {
                break;
            }
        }
    }
}

class _io_int {
    static void read(int x, int i) {
        // Read x from input
    }
    static void write(int x) {
        System.out.print(x);
    }
}

class _io_long {
    static void read(long x, int i) {
        // Read x from input
    }
    static void write(long x) {
        System.out.print(x);
    }
}

class _io_double {
    static void read(double x, int i) {
        // Read x from input
    }
    static void write(double x) {
        System.out.print(x);
    }
}

class _io_char {
    static void read(char c, int i) {
        // Read c from input
    }
    static void write(char c) {
        System.out.print(c);
    }
}

class _io_bool {
    static void read(boolean b, int i) {
        // Read b from input
    }
    static void write(boolean b) {
        System.out.print(b);
    }
}

class _io_string {
    static void read(String s, int i) {
        // Read s from input
    }
    static void write(String s) {
        System.out.print(s);
    }
}

class _io_pair<T1, T2> {
    static void write(Pair<T1, T2> x) {
        System.out.print("(" + x.first + ", " + x.second + ")");
    }
}

class _io_map<T1, T2> {
    static void write(Map<T1, T2> x) {
        System.out.print(x);
    }
}

class _io_tup0 {
    static void write() {
        System.out.print("()");
    }
}

class _io_tup1 {
    static <T> void write(T x) {
        System.out.print("(");
        _io<T>._write(x);
        System.out.print(")");
    }
}

class _io_tup2 {
    static <T1, T2> void write(Pair<T1, T2> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(")");
    }
}

class _io_tup3 {
    static <T1, T2, T3> void write(Triple<T1, T2, T3> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(")");
    }
}

class _io_tup4 {
    static <T1, T2, T3, T4> void write(Quad<T1, T2, T3, T4> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(")");
    }
}

class _io_tup5 {
    static <T1, T2, T3, T4, T5> void write(Quint<T1, T2, T3, T4, T5> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(")");
    }
}

class _io_tup6 {
    static <T1, T2, T3, T4, T5, T6> void write(Sextuple<T1, T2, T3, T4, T5, T6> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(")");
    }
}

class _io_tup7 {
    static <T1, T2, T3, T4, T5, T6, T7> void write(Septuple<T1, T2, T3, T4, T5, T6, T7> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(")");
    }
}

class _io_tup8 {
    static <T1, T2, T3, T4, T5, T6, T7, T8> void write(Octuple<T1, T2, T3, T4, T5, T6, T7, T8> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(")");
    }
}

class _io_tup9 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9> void write(Nonuple<T1, T2, T3, T4, T5, T6, T7, T8, T9> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(")");
    }
}

class _io_tup10 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> void write(Decuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(", ");
        _io<T10>._write(x.tenth);
        System.out.print(")");
    }
}

class _io_tup11 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11> void write(Undecuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(", ");
        _io<T10>._write(x.tenth);
        System.out.print(", ");
        _io<T11>._write(x.eleventh);
        System.out.print(")");
    }
}

class _io_tup12 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12> void write(Duodecuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(", ");
        _io<T10>._write(x.tenth);
        System.out.print(", ");
        _io<T11>._write(x.eleventh);
        System.out.print(", ");
        _io<T12>._write(x.twelfth);
        System.out.print(")");
    }
}

class _io_tup13 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13> void write(Tridecuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(", ");
        _io<T10>._write(x.tenth);
        System.out.print(", ");
        _io<T11>._write(x.eleventh);
        System.out.print(", ");
        _io<T12>._write(x.twelfth);
        System.out.print(", ");
        _io<T13>._write(x.thirteenth);
        System.out.print(")");
    }
}

class _io_tup14 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14> void write(Tetradecuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(", ");
        _io<T10>._write(x.tenth);
        System.out.print(", ");
        _io<T11>._write(x.eleventh);
        System.out.print(", ");
        _io<T12>._write(x.twelfth);
        System.out.print(", ");
        _io<T13>._write(x.thirteenth);
        System.out.print(", ");
        _io<T14>._write(x.fourteenth);
        System.out.print(")");
    }
}

class _io_tup15 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15> void write(Pentadecuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(", ");
        _io<T10>._write(x.tenth);
        System.out.print(", ");
        _io<T11>._write(x.eleventh);
        System.out.print(", ");
        _io<T12>._write(x.twelfth);
        System.out.print(", ");
        _io<T13>._write(x.thirteenth);
        System.out.print(", ");
        _io<T14>._write(x.fourteenth);
        System.out.print(", ");
        _io<T15>._write(x.fifteenth);
        System.out.print(")");
    }
}

class _io_tup16 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16> void write(Hexadecuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(", ");
        _io<T10>._write(x.tenth);
        System.out.print(", ");
        _io<T11>._write(x.eleventh);
        System.out.print(", ");
        _io<T12>._write(x.twelfth);
        System.out.print(", ");
        _io<T13>._write(x.thirteenth);
        System.out.print(", ");
        _io<T14>._write(x.fourteenth);
        System.out.print(", ");
        _io<T15>._write(x.fifteenth);
        System.out.print(", ");
        _io<T16>._write(x.sixteenth);
        System.out.print(")");
    }
}

class _io_tup17 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17> void write(Heptadecuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(", ");
        _io<T10>._write(x.tenth);
        System.out.print(", ");
        _io<T11>._write(x.eleventh);
        System.out.print(", ");
        _io<T12>._write(x.twelfth);
        System.out.print(", ");
        _io<T13>._write(x.thirteenth);
        System.out.print(", ");
        _io<T14>._write(x.fourteenth);
        System.out.print(", ");
        _io<T15>._write(x.fifteenth);
        System.out.print(", ");
        _io<T16>._write(x.sixteenth);
        System.out.print(", ");
        _io<T17>._write(x.seventeenth);
        System.out.print(")");
    }
}

class _io_tup18 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18> void write(Octodecuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(", ");
        _io<T10>._write(x.tenth);
        System.out.print(", ");
        _io<T11>._write(x.eleventh);
        System.out.print(", ");
        _io<T12>._write(x.twelfth);
        System.out.print(", ");
        _io<T13>._write(x.thirteenth);
        System.out.print(", ");
        _io<T14>._write(x.fourteenth);
        System.out.print(", ");
        _io<T15>._write(x.fifteenth);
        System.out.print(", ");
        _io<T16>._write(x.sixteenth);
        System.out.print(", ");
        _io<T17>._write(x.seventeenth);
        System.out.print(", ");
        _io<T18>._write(x.eighteenth);
        System.out.print(")");
    }
}

class _io_tup19 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19> void write(Enneadecuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(", ");
        _io<T10>._write(x.tenth);
        System.out.print(", ");
        _io<T11>._write(x.eleventh);
        System.out.print(", ");
        _io<T12>._write(x.twelfth);
        System.out.print(", ");
        _io<T13>._write(x.thirteenth);
        System.out.print(", ");
        _io<T14>._write(x.fourteenth);
        System.out.print(", ");
        _io<T15>._write(x.fifteenth);
        System.out.print(", ");
        _io<T16>._write(x.sixteenth);
        System.out.print(", ");
        _io<T17>._write(x.seventeenth);
        System.out.print(", ");
        _io<T18>._write(x.eighteenth);
        System.out.print(", ");
        _io<T19>._write(x.nineteenth);
        System.out.print(")");
    }
}

class _io_tup20 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20> void write(Vigintuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(", ");
        _io<T10>._write(x.tenth);
        System.out.print(", ");
        _io<T11>._write(x.eleventh);
        System.out.print(", ");
        _io<T12>._write(x.twelfth);
        System.out.print(", ");
        _io<T13>._write(x.thirteenth);
        System.out.print(", ");
        _io<T14>._write(x.fourteenth);
        System.out.print(", ");
        _io<T15>._write(x.fifteenth);
        System.out.print(", ");
        _io<T16>._write(x.sixteenth);
        System.out.print(", ");
        _io<T17>._write(x.seventeenth);
        System.out.print(", ");
        _io<T18>._write(x.eighteenth);
        System.out.print(", ");
        _io<T19>._write(x.nineteenth);
        System.out.print(", ");
        _io<T20>._write(x.twentieth);
        System.out.print(")");
    }
}

class _io_tup21 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21> void write(Unvigintuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(", ");
        _io<T10>._write(x.tenth);
        System.out.print(", ");
        _io<T11>._write(x.eleventh);
        System.out.print(", ");
        _io<T12>._write(x.twelfth);
        System.out.print(", ");
        _io<T13>._write(x.thirteenth);
        System.out.print(", ");
        _io<T14>._write(x.fourteenth);
        System.out.print(", ");
        _io<T15>._write(x.fifteenth);
        System.out.print(", ");
        _io<T16>._write(x.sixteenth);
        System.out.print(", ");
        _io<T17>._write(x.seventeenth);
        System.out.print(", ");
        _io<T18>._write(x.eighteenth);
        System.out.print(", ");
        _io<T19>._write(x.nineteenth);
        System.out.print(", ");
        _io<T20>._write(x.twentieth);
        System.out.print(", ");
        _io<T21>._write(x.twentyfirst);
        System.out.print(")");
    }
}

class _io_tup22 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22> void write(Duvigintuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(", ");
        _io<T10>._write(x.tenth);
        System.out.print(", ");
        _io<T11>._write(x.eleventh);
        System.out.print(", ");
        _io<T12>._write(x.twelfth);
        System.out.print(", ");
        _io<T13>._write(x.thirteenth);
        System.out.print(", ");
        _io<T14>._write(x.fourteenth);
        System.out.print(", ");
        _io<T15>._write(x.fifteenth);
        System.out.print(", ");
        _io<T16>._write(x.sixteenth);
        System.out.print(", ");
        _io<T17>._write(x.seventeenth);
        System.out.print(", ");
        _io<T18>._write(x.eighteenth);
        System.out.print(", ");
        _io<T19>._write(x.nineteenth);
        System.out.print(", ");
        _io<T20>._write(x.twentieth);
        System.out.print(", ");
        _io<T21>._write(x.twentyfirst);
        System.out.print(", ");
        _io<T22>._write(x.twentysecond);
        System.out.print(")");
    }
}

class _io_tup23 {
    static <T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23> void write(Trevigintuple<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23> x) {
        System.out.print("(");
        _io<T1>._write(x.first);
        System.out.print(", ");
        _io<T2>._write(x.second);
        System.out.print(", ");
        _io<T3>._write(x.third);
        System.out.print(", ");
        _io<T4>._write(x.fourth);
        System.out.print(", ");
        _io<T5>._write(x.fifth);
        System.out.print(", ");
        _io<T6>._write(x.sixth);
        System.out.print(", ");
        _io<T7>._write(x.seventh);
        System.out.print(", ");
        _io<T8>._write(x.eighth);
        System.out.print(", ");
        _io<T9>._write(x.ninth);
        System.out.print(", ");
        _io<T10>._write(x.tenth);
        System.out.print(", ");
