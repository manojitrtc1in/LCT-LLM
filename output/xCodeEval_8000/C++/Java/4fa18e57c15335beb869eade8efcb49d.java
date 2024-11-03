import java.util.*;

class Main {
    static class Tuple0 {
        public void _read(int i) {}
        public void _write() { System.out.print("("); }
        public void _write() { System.out.print(")"); }
        public boolean equals(Object other) { return true; }
    }

    static class Tuple1<T1> extends Tuple0 {
        public T1 a;
        public Tuple1(T1 a) { this.a = a; }
        public void _write() { super._write(); System.out.print("a:" + a); }
        public boolean equals(Object other) {
            if (this == other) return true;
            if (other == null || getClass() != other.getClass()) return false;
            Tuple1<?> tuple1 = (Tuple1<?>) other;
            return Objects.equals(a, tuple1.a);
        }
    }

    static class Tuple2<T1, T2> extends Tuple1<T1> {
        public T2 b;
        public Tuple2(T1 a, T2 b) { super(a); this.b = b; }
        public void _write() { super._write(); System.out.print(", b:" + b); }
        public boolean equals(Object other) {
            if (this == other) return true;
            if (other == null || getClass() != other.getClass()) return false;
            if (!super.equals(other)) return false;
            Tuple2<?, ?> tuple2 = (Tuple2<?, ?>) other;
            return Objects.equals(b, tuple2.b);
        }
    }

    static class Tuple3<T1, T2, T3> extends Tuple2<T1, T2> {
        public T3 c;
        public Tuple3(T1 a, T2 b, T3 c) { super(a, b); this.c = c; }
        public void _write() { super._write(); System.out.print(", c:" + c); }
        public boolean equals(Object other) {
            if (this == other) return true;
            if (other == null || getClass() != other.getClass()) return false;
            if (!super.equals(other)) return false;
            Tuple3<?, ?, ?> tuple3 = (Tuple3<?, ?, ?>) other;
            return Objects.equals(c, tuple3.c);
        }
    }

    static class Tuple3Comparator<T1 extends Comparable<T1>, T2 extends Comparable<T2>, T3 extends Comparable<T3>> implements Comparator<Tuple3<T1, T2, T3>> {
        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = a.a.compareTo(b.a);
            if (cmp != 0) return cmp;
            cmp = a.b.compareTo(b.b);
            if (cmp != 0) return cmp;
            return a.c.compareTo(b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

        public int compare(Tuple3<T1, T2, T3> a, Tuple3<T1, T2, T3> b) {
            int cmp = c1.compare(a.a, b.a);
            if (cmp != 0) return cmp;
            cmp = c2.compare(a.b, b.b);
            if (cmp != 0) return cmp;
            return c3.compare(a.c, b.c);
        }
    }

    static class Tuple3Comparator<T1, T2, T3> implements Comparator<Tuple3<T1, T2, T3>> {
        private Comparator<T1> c1;
        private Comparator<T2> c2;
        private Comparator<T3> c3;

        public Tuple3Comparator(Comparator<T1> c1, Comparator<T2> c2, Comparator<T3> c3) {
            this.c1 = c1;
            this.c2 = c2;
            this.c3 = c3;
        }

