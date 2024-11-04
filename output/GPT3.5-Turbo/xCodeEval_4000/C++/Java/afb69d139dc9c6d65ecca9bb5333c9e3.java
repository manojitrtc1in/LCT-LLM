import java.io.*;
import java.util.*;

class Main {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
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

    static class HashedString {
        String s;
        List<Long> MOD, POW;
        List<List<Long>> hash;
        List<List<Long>> pows;

        String substr(int L, int n) {
            return s.substring(L, L + n);
        }

        int size() {
            return s.length();
        }

        char charAt(int n) {
            return s.charAt(n);
        }

        List<Long> getHash(int L, int R) {
            List<Long> ret = new ArrayList<>();
            for (int i = 0; i < hash.size(); ++i) {
                ret.add(nmod(hash.get(i).get(R) - hash.get(i).get(L) * pows.get(i).get(R - L), MOD.get(i)));
            }
            return ret;
        }

        boolean equal(int L1, int R1, int L2, int R2) {
            return getHash(L1, R1).equals(getHash(L2, R2));
        }

        void addChar(char c) {
            s += c;
            for (int i = 0; i < hash.size(); ++i) {
                long m = MOD.get(i), p = POW.get(i), cp = pows.get(i).get(pows.get(i).size() - 1), cm = hash.get(i).get(hash.get(i).size() - 1);
                cm = (cm * p + c) % m;
                cp = cp * p % m;
                hash.get(i).add(cm);
                pows.get(i).add(cp);
            }
        }

        void addString(String oth) {
            for (int i = 0; i < hash.size(); ++i) {
                for (char c : oth.toCharArray()) {
                    addChar(c);
                }
            }
        }

        HashedString(String s, int n) {
            this.s = s;
            MOD = new ArrayList<>();
            POW = new ArrayList<>();
            hash = new ArrayList<>();
            pows = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                MOD.add(genRandomPrime());
                POW.add(genRandomPrime());
                hash.add(new ArrayList<>());
                pows.add(new ArrayList<>());
            }
            addString(s);
        }
    }

    static int allocator_pos = 0;
    static char[] allocator_memory = new char[(int) FAST_ALLOCATOR_MEMORY];

    static void* operator new(size_t n) {
        char* res = allocator_memory + allocator_pos;
        allocator_pos += n;
        assert(allocator_pos <= (int) FAST_ALLOCATOR_MEMORY);
        return (void*) res;
    }

    static void operator delete(void*) {
    }

    static final int MAXN = 3 * 100000 + 42;
    static int n;

    static class Treap {
        Treap left = null;
        Treap right = null;
        long t;
        int y;
        long prefix_sum;
        long speed;
        long push = 0;
        long min_prefix_sum_in_subtree;

        Treap(long t, long val, long speed) {
            this.t = t;
            this.y = mrand();
            this.prefix_sum = val;
            this.speed = speed;
            this.min_prefix_sum_in_subtree = val;
        }
    }

    static Treap merge(Treap a, Treap b) {
        if (a == null) return b;
        if (b == null) return a;
        if (a.y < b.y) {
            push(a);
            a.right = merge(a.right, b);
            recalc(a);
            return a;
        } else {
            push(b);
            b.left = merge(a, b.left);
            recalc(b);
            return b;
        }
    }

    static void vertex_add(Treap a, long push) {
        a.prefix_sum += push;
        a.min_prefix_sum_in_subtree += push;
        a.push += push;
    }

    static void push(Treap a) {
        long push = a.push;
        if (push == 0) return;
        if (a.left != null) {
            vertex_add(a.left, push);
        }
        if (a.right != null) {
            vertex_add(a.right, push);
        }
        a.push = 0;
    }

    static long smin(Treap a) {
        return a != null ? a.min_prefix_sum_in_subtree : INF;
    }

    static void recalc(Treap a) {
        a.min_prefix_sum_in_subtree = Math.min(Math.min(smin(a.left), smin(a.right)), a.prefix_sum);
    }

    static Treap getLeast(Treap a) {
        push(a);
        if (a.left == null) {
            return a;
        }
        return getLeast(a.left);
    }

    static Treap getGreatest(Treap a) {
        push(a);
        if (a.right == null) {
            return a;
        }
        return getGreatest(a.right);
    }

    static Treap findFirstLess(Treap a, long v) {
        push(a);
        if (smin(a.left) <= v) {
            return findFirstLess(a.left, v);
        }
        if (a.prefix_sum <= v) return a;
        return findFirstLess(a.right, v);
    }

    static void printTree(Treap a) {
        if (a == null) return;
        printTree(a.left);
        System.err.print(a.t + " ");
        printTree(a.right);
    }

    static final long INF = 1_000_000_000_000_000_000L;

    static long nmod(long a, long m) {
        return (a % m + m) % m;
    }

    static int mrand() {
        return Math.abs((1L * rand() << 15) + rand());
    }

    static long genRandomPrime() {
        long L = 1_000_000_000 + 42;
        L += rand() % 4242;
        while (!isPrime(L)) ++L;
        return L;
    }

    static boolean isPrime(long n) {
        for (long i = 2; i * i <= n; ++i)
            if (n % i == 0) return false;
        return true;
    }

    static List<Long> factor(long n) {
        List<Long> ans = new ArrayList<>();
        for (long i = 2; i * i <= n; ++i)
            while (n % i == 0)
                ans.add(i);
        if (n != 1)
            ans.add(n);
        return ans;
    }

    static List<Long> divisors(long n) {
        List<Long> ret = new ArrayList<>();
        for (long i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                ret.add(i);
                if (i * i != n)
                    ret.add(n / i);
            }
        }
        return ret;
    }

    static List<Pair<Long, Integer>> factorPows(long n) {
        List<Long> fac = factor(n);
        List<Pair<Long, Integer>> ret = new ArrayList<>();
        int L = 0;
        while (L < fac.size()) {
            int R = L;
            while (R < fac.size() && fac.get(R).equals(fac.get(L))) ++R;
            ret.add(new Pair<>(fac.get(L), R - L));
            L = R;
        }
        return ret;
    }

    static void init() {
        srand(System.currentTimeMillis());
    }

    static int readInt(FastScanner scanner) {
        return scanner.nextInt();
    }

    static long readLong(FastScanner scanner) {
        return scanner.nextLong();
    }

    static double readDouble(FastScanner scanner) {
        return scanner.nextDouble();
    }

    static int[] readIntArray(FastScanner scanner, int n) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        return arr;
    }

    static long[] readLongArray(FastScanner scanner, int n) {
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
        }
        return arr;
    }

    static double[] readDoubleArray(FastScanner scanner, int n) {
        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextDouble();
        }
        return arr;
    }

    static void writeInt(PrintWriter writer, int x, char end, int output_len) {
        if (x < 0) {
            writer.print('-');
            x = -x;
        }

        char[] s = new char[24];
        int n = 0;
        while (x > 0 || n == 0) {
            s[n++] = (char) ('0' + x % 10);
            x /= 10;
        }
        while (n < output_len) {
            s[n++] = '0';
        }
        while (n-- > 0) {
            writer.print(s[n]);
        }
        if (end != 0) {
            writer.print(end);
        }
    }

    static void writeWord(PrintWriter writer, String s) {
        writer.print(s);
    }

    static void writeDouble(PrintWriter writer, double x, int output_len) {
        if (x < 0) {
            writer.print('-');
            x = -x;
        }
        int t = (int) x;
        writeInt(writer, t, (char) 0, 0);
        x -= t;
        writer.print('.');
        for (int i = output_len - 1; i > 0; i--) {
            x *= 10;
            t = Math.min(9, (int) x);
            writer.print((char) ('0' + t));
            x -= t;
        }
        x *= 10;
        t = Math.min(9, (int) (x + 0.5));
        writer.print((char) ('0' + t));
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner();
        PrintWriter writer = new PrintWriter(System.out);
        init();
        Treap root = new Treap(0, 0, 0);
        root = merge(root, new Treap(2_000_000_000, 0, 0));
        int q = readInt(scanner);
        int t;
        int s, type;
        for (int i = 0; i < q; ++i) {
            type = readInt(scanner);
            if (type == 1) {
                t = readInt(scanner);
                s = readInt(scanner);
                Pair<Treap, Treap> lr = split(root, t);
                Treap vr = getLeast(lr.s);
                Treap vl = getGreatest(lr.f);
                long psum = vl.prefix_sum + (t - vl.t) * vl.speed;
                long new_psum = psum + (vr.t - t) * s;
                vertex_add(lr.s, new_psum - vr.prefix_sum);
                root = merge(lr.f, merge(new Treap(t, psum, s), lr.s));
            } else if (type == 2) {
                t = readInt(scanner);
                Pair<Treap, Treap> ltr = split(root, t);
                Pair<Treap, Treap> yr = split(ltr.s, t + 1);
                Treap vl = getGreatest(ltr.f);
                Treap vr = getLeast(yr.s);
                long new_psum = vl.prefix_sum + (vr.t - vl.t) * vl.speed;
                vertex_add(yr.s, new_psum - vr.prefix_sum);
                root = merge(ltr.f, yr.s);
            } else {
                int L = readInt(scanner);
                int R = readInt(scanner);
                long v = readInt(scanner);
                if (v == 0) {
                    writer.println(L);
                    continue;
                }
                Pair<Treap, Treap> ltr = split(root, L);
                Pair<Treap, Treap> yr = split(ltr.s, R + 1);
                if (yr.f == null) {
                    writer.println(-1);
                } else {
                    Treap vl = getLeast(yr.f);
                    Treap vr = getGreatest(yr.f);
                    long searching_v = vl.prefix_sum - v;
                    if (yr.f.min_prefix_sum_in_subtree > searching_v) {
                        long new_psum = vr.prefix_sum + (R - vr.t) * vr.speed;
                        if (new_psum > searching_v) {
                            writer.println(-1);
                        } else {
                            writer.println(vr.t + (double) (searching_v - vr.prefix_sum) / vr.speed);
                        }
                    } else {
                        Treap h = findFirstLess(yr.f, searching_v);
                        Pair<Treap, Treap> ylr = split(yr.f, h.t);
                        Treap vyl = getGreatest(ylr.f);
                        writer.println(vyl.t + (double) (searching_v - vyl.prefix_sum) / vyl.speed);
                        yr.f = merge(ylr.f, ylr.s);
                    }
                }
                root = merge(ltr.f, merge(yr.f, yr.s));
            }
        }
        writer.flush();
    }
}
