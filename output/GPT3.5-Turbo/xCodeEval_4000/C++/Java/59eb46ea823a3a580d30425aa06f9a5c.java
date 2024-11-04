import java.util.*;
import java.io.*;

public class 59eb46ea823a3a580d30425aa06f9a5c_nc {
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

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        Pair[] p = new Pair[n];
        for (int i = 0; i < n; i++) {
            p[i] = new Pair(sc.nextLong(), sc.nextLong());
            p[i].index = i;
        }
        String s = sc.next();
        Pair[] perm = new Pair[n];
        int first_idx = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].compareTo(p[first_idx]) < 0) {
                first_idx = i;
            }
        }
        take(first_idx, perm, p);
        for (int i = 0; i < n - 2; i++) {
            Pair q = perm[perm.length - 1];
            int best = 0;
            for (int j = 1; j < p.length; j++) {
                if ((((p[best].sub(q)).cross(p[j].sub(q))) > 0) == (s.charAt(i) == 'R')) {
                    best = j;
                }
            }
            take(p[best].index, perm, p);
        }
        take(p[0].index, perm, p);
        for (int i = 0; i < perm.length; i++) {
            System.out.print((perm[i].index + 1) + " ");
        }
        System.out.println();
    }

    static class Pair implements Comparable<Pair> {
        long x, y;
        int index;

        public Pair(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public Pair sub(Pair p) {
            return new Pair(x - p.x, y - p.y);
        }

        public long cross(Pair p) {
            return x * p.y - y * p.x;
        }

        public int compareTo(Pair p) {
            if (x == p.x) {
                return Long.compare(y, p.y);
            }
            return Long.compare(x, p.x);
        }
    }

    static void take(int k, Pair[] perm, Pair[] points) {
        Pair temp = points[k];
        points[k] = points[points.length - 1];
        points[points.length - 1] = temp;
        perm[perm.length - points.length] = points[points.length - 1];
    }
}
