import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Triple<T1, T2, T3> {
        T1 first;
        T2 second;
        T3 third;

        Triple(T1 first, T2 second, T3 third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

    static class Quad<T1, T2, T3, T4> {
        T1 first;
        T2 second;
        T3 third;
        T4 fourth;

        Quad(T1 first, T2 second, T3 third, T4 fourth) {
            this.first = first;
            this.second = second;
            this.third = third;
            this.fourth = fourth;
        }
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

    static final int MOD = (int) 1e9 + 7;
    static final long INF = (long) 1e18;

    static void yes() {
        System.out.println("Yes");
    }

    static void no() {
        System.out.println("No");
    }

    static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    static void main(String[] args) {
        FastReader sc = new FastReader();

        long a = sc.nextLong();
        long n = (long) 1e17;
        n *= 18;

        n %= a;
        long k = n;

        for (int i = 0; i < 44; i++) {
            n = (n + k) % a;
        }

        if (n < 0) {
            n += a;
        }
        long c = a - n;
        long d = c + (long) 1e18 - 1L;
        System.out.println(c + " " + d);
    }
}
