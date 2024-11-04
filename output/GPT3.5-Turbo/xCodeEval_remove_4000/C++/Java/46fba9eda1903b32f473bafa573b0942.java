import java.util.*;
import java.io.*;

class Main {
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

    static class Pair {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Triple {
        Pair first;
        int second;

        public Triple(Pair first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Quad {
        long first, second;

        public Quad(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    static class OrderedSet {
        TreeSet<Integer> set;

        public OrderedSet() {
            set = new TreeSet<>();
        }

        void insert(int x) {
            set.add(x);
        }

        void erase(int x) {
            set.remove(x);
        }

        int orderOfKey(int x) {
            return set.headSet(x).size();
        }

        int findKthElement(int k) {
            return (int) set.toArray()[k - 1];
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

    public static void main(String[] args) {
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
