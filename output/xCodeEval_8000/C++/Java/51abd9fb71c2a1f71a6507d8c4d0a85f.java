import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static long Min = Long.MAX_VALUE, Max = Long.MIN_VALUE;
    static ArrayList<Pair<Long, Long>> A = new ArrayList<>();

    public static void main(String[] args) throws java.lang.Exception {
        FastReader sc = new FastReader();
        long n = sc.nextLong();
        Map<Long, Long> Map = new HashMap<>();
        long N = n;
        for (long i = 2; i <= Math.sqrt(n); i++) {
            while (n % i == 0) {
                if (Map.containsKey(i)) {
                    Map.put(i, Map.get(i) + 1);
                } else {
                    Map.put(i, 1L);
                }
                n /= i;
            }
        }
        if (n > 1) {
            Map.put(n, 1L);
        }
        for (Map.Entry<Long, Long> entry : Map.entrySet()) {
            long k = entry.getKey();
            long v = entry.getValue();
            A.add(new Pair<>(k, v));
        }
        Try(0, 1, 1, 1);
        System.out.println((Min - N) + " " + (Max - N));
    }

    static void Try(int id, long x1, long x2, long x3) {
        if (id == A.size()) {
            Min = Math.min(Min, (x1 + 1) * (x2 + 2) * (x3 + 2));
            Min = Math.min(Min, (x1 + 2) * (x2 + 1) * (x3 + 2));
            Min = Math.min(Min, (x1 + 2) * (x2 + 2) * (x3 + 1));
            Max = Math.max(Max, (x1 + 1) * (x2 + 2) * (x3 + 2));
            Max = Math.max(Max, (x1 + 2) * (x2 + 1) * (x3 + 2));
            Max = Math.max(Max, (x1 + 2) * (x2 + 2) * (x3 + 1));
            return;
        }
        long key = A.get(id).getKey();
        long v = A.get(id).getValue();
        for (long i = 0; i <= v; i++) {
            for (long j = 0; j <= v; j++) {
                for (long k = 0; k <= v; k++) {
                    if (i + j + k != v) {
                        continue;
                    }
                    Try(id + 1, x1 * Pow(key, i), x2 * Pow(key, j), x3 * Pow(key, k));
                }
            }
        }
    }

    static long Pow(long a, long b) {
        if (b == 0) {
            return 1;
        }
        long tmp = Pow(a, b / 2);
        if (b % 2 == 0) {
            return (tmp * tmp);
        }
        return (tmp * tmp * a);
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
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

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class Pair<T, U> {
        T first;
        U second;

        public Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }

        public T getKey() {
            return first;
        }

        public U getValue() {
            return second;
        }
    }
}
