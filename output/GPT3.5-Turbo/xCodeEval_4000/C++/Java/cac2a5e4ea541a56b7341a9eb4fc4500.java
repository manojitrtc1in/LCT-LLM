import java.io.*;
import java.util.*;

class Main {
    static class Modular<T> {
        private T value;

        public Modular() {
            value = null;
        }

        public Modular(T value) {
            this.value = value;
        }

        public T getValue() {
            return value;
        }

        public void setValue(T value) {
            this.value = value;
        }

        public Modular<T> add(Modular<T> other) {
            return new Modular<>(value + other.getValue());
        }

        public Modular<T> subtract(Modular<T> other) {
            return new Modular<>(value - other.getValue());
        }

        public Modular<T> multiply(Modular<T> other) {
            return new Modular<>(value * other.getValue());
        }

        public Modular<T> divide(Modular<T> other) {
            return new Modular<>(value / other.getValue());
        }

        public boolean equals(Modular<T> other) {
            return value.equals(other.getValue());
        }

        public boolean lessThan(Modular<T> other) {
            if (value instanceof Integer) {
                return (Integer) value < (Integer) other.getValue();
            } else if (value instanceof Long) {
                return (Long) value < (Long) other.getValue();
            } else if (value instanceof Double) {
                return (Double) value < (Double) other.getValue();
            } else {
                throw new IllegalArgumentException("Unsupported type");
            }
        }

        public boolean greaterThan(Modular<T> other) {
            if (value instanceof Integer) {
                return (Integer) value > (Integer) other.getValue();
            } else if (value instanceof Long) {
                return (Long) value > (Long) other.getValue();
            } else if (value instanceof Double) {
                return (Double) value > (Double) other.getValue();
            } else {
                throw new IllegalArgumentException("Unsupported type");
            }
        }

        public boolean lessThanOrEqual(Modular<T> other) {
            return equals(other) || lessThan(other);
        }

        public boolean greaterThanOrEqual(Modular<T> other) {
            return equals(other) || greaterThan(other);
        }

        public String toString() {
            return value.toString();
        }
    }

    static class Mat<T> {
        private T[][] m;

        public Mat(T[][] m) {
            this.m = m;
        }

        public T[] getRow(int i) {
            return m[i];
        }

        public void setRow(int i, T[] row) {
            m[i] = row;
        }

        public Mat<T> multiply(Mat<T> other) {
            int n = m.length;
            int m = other.m[0].length;
            int p = other.m.length;
            Mat<T> result = new Mat<>(new Object[n][m]);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int k = 0; k < p; k++) {
                        result.m[i][j] = result.m[i][j].add(m[i][k].multiply(other.m[k][j]));
                    }
                }
            }
            return result;
        }
    }

    static class Frac {
        private int p;
        private int q;

        public Frac(int p, int q) {
            this.p = p;
            this.q = q;
        }

        public Modular<Integer> toModular() {
            return new Modular<>(p / q);
        }

        public boolean lessThan(Frac other) {
            return p * other.q < other.p * q;
        }

        public boolean greaterThan(Frac other) {
            return p * other.q > other.p * q;
        }

        public String toString() {
            return p + "/" + q;
        }
    }

    static class Event implements Comparable<Event> {
        private Frac frac;
        private int index;

        public Event(Frac frac, int index) {
            this.frac = frac;
            this.index = index;
        }

        public Frac getFrac() {
            return frac;
        }

        public int getIndex() {
            return index;
        }

        public int compareTo(Event other) {
            return frac.lessThan(other.frac) ? -1 : frac.greaterThan(other.frac) ? 1 : 0;
        }
    }

    static Modular<Integer> getProb(Mat<Modular<Integer>> a, Modular<Integer> toRight) {
        return toRight.multiply(a.getRow(1)[0].add(a.getRow(1)[1])).add(Modular.ONE.subtract(toRight).multiply(a.getRow(0)[0].add(a.getRow(0)[1])));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) {
            System.out.println(0);
            return;
        }
        int[] x = new int[n];
        int[] v = new int[n];
        Modular<Integer>[] p = new Modular[n];
        Modular<Integer> inv100 = new Modular<>(100).divide(new Modular<>(100));
        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            x[i] = Integer.parseInt(st.nextToken());
            v[i] = Integer.parseInt(st.nextToken());
            p[i] = new Modular<>(Integer.parseInt(st.nextToken())).multiply(inv100);
        }

        Mat<Modular<Integer>>[] allowedCollisions = new Mat[n - 1];
        for (int i = 0; i < n - 1; i++) {
            allowedCollisions[i] = new Mat<>(new Modular[][]{{Modular.ZERO, p[i + 1]}, {Modular.ZERO, Modular.ONE.subtract(p[i + 1])}});
        }

        Mat<Modular<Integer>>[] a = new Mat[2 * (n - 1) - 1];
        Modular<Integer>[][] m;
        for (int i = 0; i < n - 1; i++) {
            a[2 * i] = allowedCollisions[i];
        }

        for (int i = 0; i < 2 * (n - 1) - 1; i++) {
            m = new Modular[][]{{Modular.ZERO, Modular.ZERO}, {Modular.ZERO, Modular.ZERO}};
            a[i] = new Mat<>(m);
        }

        for (int i = 0; i < 2 * (n - 1) - 1; i++) {
            int l = i + 1;
            int r = i + 2;
            int mid = (l + r) / 2;
            while (l <= r) {
                a[i] = a[i].multiply(a[mid]);
                l++;
                mid++;
            }
        }

        Event[] events = new Event[3 * (n - 1)];
        int index = 0;
        for (int i = 0; i < n - 1; i++) {
            int d = x[i + 1] - x[i];
            events[index++] = new Event(new Frac(d, v[i + 1] + v[i]), i << 2 | 1);
            events[index++] = new Event(v[i] < v[i + 1] ? new Frac(d, v[i + 1] - v[i]) : new Frac(1, 0), i << 2 | 0);
            events[index++] = new Event(v[i] > v[i + 1] ? new Frac(d, v[i] - v[i + 1]) : new Frac(1, 0), i << 2 | 3);
        }

        Arrays.sort(events);

        Modular<Integer> prevProb = getProb(a[get_id(0, n - 2)], p[0]);
        Modular<Integer> ans = new Modular<>(0);

        for (int i = events.length - 1; i >= 0; i--) {
            int eventIndex = events[i].getIndex();
            int k = eventIndex >> 2;
            int dir1 = (eventIndex & 1) == 1 ? 1 : 0;
            int dir2 = (eventIndex & 2) == 2 ? 1 : 0;
            allowedCollisions[k].setRow(dir1, new Modular[]{Modular.ZERO, p[k + 1]});
            allowedCollisions[k].setRow(dir2, new Modular[]{Modular.ZERO, Modular.ONE.subtract(p[k + 1])});
            a[get_id(0, n - 2)] = allowedCollisions[k];
            Modular<Integer> prob = getProb(a[get_id(0, n - 2)], p[0]);
            if (events[i].getFrac().q != 0) {
                ans = ans.add(prob.subtract(prevProb).multiply(events[i].getFrac().toModular()));
            }
            prevProb = prob;
        }

        System.out.println(ans);
    }
}
