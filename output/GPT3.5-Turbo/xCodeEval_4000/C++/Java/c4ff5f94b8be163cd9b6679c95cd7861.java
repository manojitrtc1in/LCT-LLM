import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    static class Modular<T> {
        public static final int MOD = 998244353;
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
            return new Modular<>((T) (Integer.valueOf(value.toString()) + Integer.valueOf(other.getValue().toString())) % MOD);
        }

        public Modular<T> subtract(Modular<T> other) {
            return new Modular<>((T) (Integer.valueOf(value.toString()) - Integer.valueOf(other.getValue().toString()) + MOD) % MOD);
        }

        public Modular<T> multiply(Modular<T> other) {
            return new Modular<>((T) (Integer.valueOf(value.toString()) * Integer.valueOf(other.getValue().toString())) % MOD);
        }

        public Modular<T> divide(Modular<T> other) {
            return new Modular<>((T) (Integer.valueOf(value.toString()) / Integer.valueOf(other.getValue().toString())));
        }

        public Modular<T> power(int exponent) {
            Modular<T> result = new Modular<>(value);
            for (int i = 1; i < exponent; i++) {
                result = result.multiply(new Modular<>(value));
            }
            return result;
        }

        public boolean equals(Modular<T> other) {
            return value.equals(other.getValue());
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

        public T[][] getMatrix() {
            return m;
        }

        public Mat<T> multiply(Mat<T> b) {
            int rowsA = m.length;
            int colsA = m[0].length;
            int rowsB = b.getMatrix().length;
            int colsB = b.getMatrix()[0].length;

            if (colsA != rowsB) {
                throw new IllegalArgumentException("Matrices cannot be multiplied");
            }

            T[][] result = (T[][]) new Object[rowsA][colsB];

            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < colsB; j++) {
                    result[i][j] = (T) (Integer.valueOf(0));
                    for (int k = 0; k < colsA; k++) {
                        result[i][j] = (T) (Integer.valueOf(result[i][j].toString()) + Integer.valueOf(m[i][k].toString()) * Integer.valueOf(b.getMatrix()[k][j].toString()));
                    }
                }
            }

            return new Mat<>(result);
        }
    }

    static class Frac implements Comparable<Frac> {
        private int p;
        private int q;

        public Frac(int p, int q) {
            this.p = p;
            this.q = q;
        }

        public int getP() {
            return p;
        }

        public int getQ() {
            return q;
        }

        public Modular<Integer> toModular() {
            return new Modular<>((p * Modular.MOD) / q);
        }

        public int compareTo(Frac other) {
            return Integer.compare(p * other.getQ(), q * other.getP());
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
            return frac.compareTo(other.getFrac());
        }
    }

    static Modular<Integer> getProb(Mat<Modular<Integer>> mat, Modular<Integer> toRight) {
        return toRight.multiply(mat.getMatrix()[1][0].add(mat.getMatrix()[1][1])).add(Modular.MOD - toRight).multiply(mat.getMatrix()[0][0].add(mat.getMatrix()[0][1]));
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
        Modular<Integer> inv100 = new Modular<>(100).divide(new Modular<>(Modular.MOD));
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            x[i] = Integer.parseInt(input[i]);
        }
        input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(input[i]);
        }
        input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            p[i] = new Modular<>(Integer.parseInt(input[i])).multiply(inv100);
        }

        Mat<Modular<Integer>>[] allowedCollisions = new Mat[n - 1];
        for (int i = 0; i < n - 1; i++) {
            allowedCollisions[i] = new Mat<>(new Modular[][]{{new Modular<>(0), p[i + 1]}, {new Modular<>(0), new Modular<>(1).subtract(p[i + 1])}});
        }

        Mat<Modular<Integer>>[] a = new Mat[2 * (n - 1) - 1];
        Modular<Integer> toRight = p[0];
        a[0] = allowedCollisions[0];
        for (int i = 1; i < n - 1; i++) {
            a[2 * i - 1] = allowedCollisions[i];
            a[2 * i] = a[2 * i - 2].multiply(a[2 * i - 1]);
        }

        Frac prevProb = getProb(a[0], toRight).toModular();
        Modular<Integer> ans = new Modular<>(0);

        Event[] events = new Event[3 * (n - 1)];
        for (int i = 0; i < n - 1; i++) {
            int d = x[i + 1] - x[i];
            events[i * 3] = new Event(new Frac(d, v[i + 1] + v[i]), i << 2 | 1);
            events[i * 3 + 1] = new Event(v[i] < v[i + 1] ? new Frac(d, v[i + 1] - v[i]) : new Frac(1, 0), i << 2 | 0);
            events[i * 3 + 2] = new Event(v[i] > v[i + 1] ? new Frac(d, v[i] - v[i + 1]) : new Frac(1, 0), i << 2 | 3);
        }

        Arrays.sort(events);

        for (int i = events.length - 1; i >= 0; i--) {
            int index = events[i].getIndex();
            int dir1 = (index >> 0) & 1;
            int dir2 = (index >> 1) & 1;
            allowedCollisions[index >> 2].getMatrix()[dir1][dir2] = dir2 == 1 ? p[(index >> 2) + 1] : new Modular<>(1).subtract(p[(index >> 2) + 1]);
            toRight = p[0];
            a[0] = allowedCollisions[0];
            for (int j = 1; j < n - 1; j++) {
                a[2 * j - 1] = allowedCollisions[j];
                a[2 * j] = a[2 * j - 2].multiply(a[2 * j - 1]);
            }
            Modular<Integer> prob = getProb(a[0], toRight).toModular();
            if (events[i].getFrac().getQ() != 0) {
                ans = ans.add(prob.subtract(prevProb).multiply(events[i].getFrac().toModular()));
            }
            prevProb = prob;
        }

        System.out.println(ans);
    }
}
