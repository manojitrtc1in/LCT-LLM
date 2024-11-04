import java.util.*;
import java.io.*;

public class 8cc4f790571eabdb5f0128f8ad1bd89b_nc {
    static class Pipe {
        int x, v, p;

        Pipe(int x, int v, int p) {
            this.x = x;
            this.v = v;
            this.p = p;
        }
    }

    static class Event {
        int i;
        Direction d;
        Fraction t;

        Event(int i, Direction d, Fraction t) {
            this.i = i;
            this.d = d;
            this.t = t;
        }
    }

    enum Direction { LL, RR, RL }

    static class Fraction {
        long n, d;

        Fraction(long n, long d) {
            assert n != 0 || d != 0;
            if (d < 0) {
                n *= -1;
                d *= -1;
            }
            long g = gcd(Math.abs(n), d);
            this.n = n / g;
            this.d = d / g;
        }

        static long gcd(long a, long b) {
            while (b != 0) {
                long temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
    }

    static class Node {
        long[] p = new long[4];
        boolean noLL = false, noRR = false, noRL = false, none = true;

        Node combine(Node b) {
            if (this.none) return b;
            if (b.none) return this;
            Node r = b;
            Arrays.fill(r.p, 0);
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    boolean iF = (i & 1) != 0, iB = (i >> 1 & 1) != 0;
                    boolean jF = (j & 1) != 0, jB = (j >> 1 & 1) != 0;
                    if (this.noLL && !iB && !jF) continue;
                    if (this.noRR && iB && jF) continue;
                    if (this.noRL && iB && !jF) continue;
                    r.p[iF ? 1 : 0 + 2 * (jB ? 1 : 0)] += this.p[i] * b.p[j];
                }
            }
            return r;
        }
    }

    static class SegmentTree {
        int SZ;
        Node id;
        BiFunction<Node, Node, Node> tt;
        Node[] table;

        SegmentTree(int _SZ, Node _id, BiFunction<Node, Node, Node> _tt) {
            this.SZ = _SZ;
            this.id = _id;
            this.tt = _tt;
            this.table = new Node[2 * SZ];
            Arrays.fill(this.table, id);
        }

        void setLeaves(Function<Integer, Node> create) {
            for (int i = 0; i < SZ; i++) {
                table[SZ + i] = create.apply(i);
            }
            for (int i = SZ - 1; i > 0; i--) {
                table[i] = tt.apply(table[2 * i], table[2 * i + 1]);
            }
        }

        void replace(int i, Node v) {
            table[i += SZ] = v;
            for (i /= 2; i > 0; i /= 2) {
                table[i] = tt.apply(table[2 * i], table[2 * i + 1]);
            }
        }

        Node query(int i, int j) {
            Node left = id, right = id;
            for (i += SZ, j += SZ; i < j; i /= 2, j /= 2) {
                if ((i & 1) != 0) left = tt.apply(left, table[i++]);
                if ((j & 1) != 0) right = tt.apply(table[--j], right);
            }
            return tt.apply(left, right);
        }

        Node get(int i) {
            return table[SZ + i];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        Pipe[] pipes = new Pipe[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            pipes[i] = new Pipe(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        List<Event> evs = new ArrayList<>();
        for (int i = 0; i < N - 1; i++) {
            int dx = pipes[i + 1].x - pipes[i].x;
            int dv = pipes[i + 1].v - pipes[i].v;

            evs.add(new Event(i, Direction.RL, new Fraction(dx, pipes[i + 1].v + pipes[i].v)));

            if (dv > 0) evs.add(new Event(i, Direction.LL, new Fraction(dx, dv)));
            if (dv < 0) evs.add(new Event(i, Direction.RR, new Fraction(dx, -dv)));
        }
        evs.sort(Comparator.comparing(e -> e.t.n));

        SegmentTree st = new SegmentTree(N, new Node(), Node::combine);
        st.setLeaves(i -> {
            long pR = pipes[i].p * smallInv(100);
            Node r = new Node();
            r.p[0] = 1 - pR;
            r.p[3] = pR;
            r.none = false;
            return r;
        });

        long ans = 0, prob = 1;
        for (Event e : evs) {
            Node c = st.get(e.i);
            switch (e.d) {
                case LL: c.noLL = true; break;
                case RR: c.noRR = true; break;
                case RL: c.noRL = true; break;
            }
            st.replace(e.i, c);

            Node u = st.query(0, st.SZ);
            long PROB = Arrays.stream(u.p).sum();
            ans += (prob - PROB) * e.t.n * smallInv(e.t.d);
            prob = PROB;
        }

        out.println(ans);
        out.flush();
    }

    static long smallInv(int n) {
        return factorial(n - 1) * inverseFactorial(n);
    }

    static long factorial(int n) {
        long res = 1;
        for (int i = 2; i <= n; i++) {
            res *= i;
        }
        return res;
    }

    static long inverseFactorial(int n) {
        return modInverse(factorial(n));
    }

    static long modInverse(long a) {
        return pow(a, 998244353 - 2);
    }

    static long pow(long x, long y) {
        long res = 1;
        x = x % 998244353;
        while (y > 0) {
            if ((y & 1) == 1) res = (res * x) % 998244353;
            y >>= 1;
            x = (x * x) % 998244353;
        }
        return res;
    }
}
