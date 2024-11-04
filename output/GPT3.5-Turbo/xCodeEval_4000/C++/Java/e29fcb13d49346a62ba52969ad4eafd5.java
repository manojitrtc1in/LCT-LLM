import java.io.*;
import java.util.*;

class Main {
    static final int mod = 998244353;
    static class Mint {
        static int modValue;
        int value;
        Mint(int value) {
            this.value = value;
        }
        static void setMod(int mod) {
            modValue = mod;
        }
        static Mint add(Mint a, Mint b) {
            return new Mint((a.value + b.value) % modValue);
        }
        static Mint subtract(Mint a, Mint b) {
            return new Mint((a.value - b.value + modValue) % modValue);
        }
        static Mint multiply(Mint a, Mint b) {
            return new Mint((int) ((long) a.value * b.value % modValue));
        }
        static Mint divide(Mint a, Mint b) {
            return multiply(a, inverse(b));
        }
        static Mint inverse(Mint a) {
            int m = modValue;
            int x = 0, y = 1;
            while (a.value > 1) {
                int q = a.value / m;
                int t = m;
                m = a.value % m;
                a.value = t;
                t = x;
                x = y - q * x;
                y = t;
            }
            if (y < 0) {
                y += modValue;
            }
            return new Mint(y);
        }
        static Mint power(Mint a, long n) {
            Mint result = new Mint(1);
            while (n > 0) {
                if ((n & 1) == 1) {
                    result = multiply(result, a);
                }
                a = multiply(a, a);
                n >>= 1;
            }
            return result;
        }
        static Mint[] inv;
        static void calculateInverse(int max) {
            inv = new Mint[max + 1];
            inv[1] = new Mint(1);
            for (int i = 2; i <= max; i++) {
                inv[i] = subtract(new Mint(0), multiply(new Mint(modValue / i), inv[modValue % i]));
            }
        }
        static Mint getInverse(int value) {
            if (inv == null) {
                calculateInverse(modValue);
            }
            return inv[value];
        }
        static Mint[] factorial;
        static void calculateFactorial(int max) {
            factorial = new Mint[max + 1];
            factorial[0] = new Mint(1);
            for (int i = 1; i <= max; i++) {
                factorial[i] = multiply(factorial[i - 1], new Mint(i));
            }
        }
        static Mint getFactorial(int value) {
            if (factorial == null) {
                calculateFactorial(modValue);
            }
            return factorial[value];
        }
        static Mint[] inverseFactorial;
        static void calculateInverseFactorial(int max) {
            inverseFactorial = new Mint[max + 1];
            inverseFactorial[0] = new Mint(1);
            for (int i = 1; i <= max; i++) {
                inverseFactorial[i] = multiply(inverseFactorial[i - 1], getInverse(i));
            }
        }
        static Mint getInverseFactorial(int value) {
            if (inverseFactorial == null) {
                calculateInverseFactorial(modValue);
            }
            return inverseFactorial[value];
        }
        static Mint[] binomial;
        static void calculateBinomial(int max) {
            binomial = new Mint[max + 1];
            binomial[0] = new Mint(1);
            for (int i = 1; i <= max; i++) {
                binomial[i] = multiply(binomial[i - 1], subtract(new Mint(modValue + i), new Mint(i)));
            }
        }
        static Mint getBinomial(int n, int k) {
            if (binomial == null) {
                calculateBinomial(modValue);
            }
            return multiply(binomial[n], multiply(getInverseFactorial(k), getInverseFactorial(n - k)));
        }
        @Override
        public boolean equals(Object obj) {
            if (obj instanceof Mint) {
                Mint other = (Mint) obj;
                return value == other.value;
            }
            return false;
        }
        @Override
        public int hashCode() {
            return Integer.hashCode(value);
        }
        @Override
        public String toString() {
            return Integer.toString(value);
        }
    }
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }
        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
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
    }
    static class OutputWriter {
        PrintWriter writer;
        OutputWriter(OutputStream stream) {
            writer = new PrintWriter(stream);
        }
        void printLine(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
            writer.println();
        }
        void close() {
            writer.close();
        }
    }
    static class Pair<F, S> {
        F first;
        S second;
        Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    }
    static class Utils {
        static final int[] DX4 = {1, 0, -1, 0};
        static final int[] DY4 = {0, 1, 0, -1};
        static final int[] DX8 = {1, 1, 0, -1, -1, -1, 0, 1};
        static final int[] DY8 = {0, 1, 1, 1, 0, -1, -1, -1};
        static boolean isValidCell(int row, int column, int rowCount, int columnCount) {
            return row >= 0 && row < rowCount && column >= 0 && column < columnCount;
        }
        static <T> void swapElements(T[] array, int i, int j) {
            T temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        static void decreaseByOne(int[]... arrays) {
            for (int[] array : arrays) {
                for (int i = 0; i < array.length; i++) {
                    array[i]--;
                }
            }
        }
    }
    static class MathUtils {
        static long gcd(long a, long b) {
            while (b != 0) {
                long t = b;
                b = a % b;
                a = t;
            }
            return a;
        }
        static long lcm(long a, long b) {
            return a / gcd(a, b) * b;
        }
    }
    static class Task {
        void solve(InputReader in, OutputWriter out) {
            Mint.setMod(mod);
            int n = in.nextInt();
            int m = in.nextInt();
            boolean[] a = new boolean[n];
            int[] w = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt() == 1;
            }
            for (int i = 0; i < n; i++) {
                w[i] = in.nextInt();
            }
            int zw = 0, ow = 0;
            for (int i = 0; i < n; i++) {
                if (a[i]) {
                    ow += w[i];
                } else {
                    zw += w[i];
                }
            }
            int s = zw + ow;
            Mint[] inv = new Mint[2 * m + 1];
            for (int d = -m; d <= m; d++) {
                if (s + d > 0) {
                    inv[d + m] = Mint.divide(new Mint(1), new Mint(s + d));
                }
            }
            Mint[][] dp = new Mint[m + 1][2];
            for (int i = 0; i <= m; i++) {
                dp[i][0] = new Mint(0);
                dp[i][1] = new Mint(0);
            }
            dp[0][0] = new Mint(1);
            for (int i = 0; i < m; i++) {
                Mint[][] ndp = new Mint[m + 1][2];
                for (int z = 0; z <= i; z++) {
                    int o = i - z;
                    int wz = zw - z;
                    int wo = ow + o;
                    if (wz < 0) {
                        continue;
                    }
                    for (int dz = -1; dz <= 0; dz++) {
                        int nwz = wz + dz;
                        int nz = z + (-dz);
                        if (nwz < 0) {
                            continue;
                        }
                        Mint eps = inv[wz + wo - s + m];
                        Mint p = Mint.multiply(new Mint(dz == -1 ? wz : wo), eps);
                        ndp[nz][-dz] = Mint.add(ndp[nz][-dz], Mint.multiply(dp[z][-dz], p));
                        ndp[nz][1 + dz] = Mint.add(ndp[nz][1 + dz], Mint.multiply(Mint.add(p, Mint.multiply(new Mint(2 * dz + 1), eps)), dp[z][1 + dz]));
                    }
                }
                dp = ndp;
            }
            Mint cz = new Mint(0), co = new Mint(0);
            for (int i = 0; i <= m; i++) {
                cz = Mint.add(cz, dp[i][0]);
                co = Mint.add(co, dp[i][1]);
            }
            for (int i = 0; i < n; i++) {
                out.printLine(Mint.multiply(new Mint(w[i]), a[i] ? co : cz));
            }
        }
    }
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Task task = new Task();
        task.solve(in, out);
        out.close();
    }
}
