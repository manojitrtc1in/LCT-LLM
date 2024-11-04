import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskE {
    StringTokenizer st;
    BufferedReader in;
    PrintWriter out;
    long res00, res01, res10, res11;

    public static void main(String[] args) throws IOException {
        TaskE taskA = new TaskE();
        taskA.open();
        taskA.solve();
        taskA.close();
    }

    String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String str = in.readLine();
            if (str == null) return null;
            else st = new StringTokenizer(str);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private void close() {
        try {
            out.close();
            in.close();
        } catch (IOException ignore) {
        }
    }

    final int MOD = (int) (1e9) + 7;

    class Matr {
        int a[][] = new int[2][2];

        public Matr(int i) {
            switch (i) {
                case 0:
                    break;
                case 1:
                    a[0][0] = a[1][1] = 1;
                    break;
                case 2:
                    a[0][1] = a[1][0] = a[1][1] = 1;
                    break;
            }
        }

        void makePow(int n) {
            Matr res = new Matr(1);
            while (n > 0) {
                if (n % 2 == 1) {
                    res00 = ((1L * res.a[0][0] * a[0][0] + 1L * res.a[0][1] * a[1][0]) % MOD);
                    res01 = ((1L * res.a[0][0] * a[0][1] + 1L * res.a[0][1] * a[1][1]) % MOD);
                    res10 = ((1L * res.a[1][0] * a[0][0] + 1L * res.a[1][1] * a[1][0]) % MOD);
                    res11 = ((1L * res.a[1][0] * a[0][1] + 1L * res.a[1][1] * a[1][1]) % MOD);

                    res.a[0][0] = (int) res00;
                    res.a[0][1] = (int) res01;
                    res.a[1][0] = (int) res10;
                    res.a[1][1] = (int) res11;
                }
                res00 = ((1L * a[0][0] * a[0][0] + 1L * a[0][1] * a[1][0]) % MOD);
                res01 = ((1L * a[0][0] * a[0][1] + 1L * a[0][1] * a[1][1]) % MOD);
                res10 = ((1L * a[1][0] * a[0][0] + 1L * a[1][1] * a[1][0]) % MOD);
                res11 = ((1L * a[1][0] * a[0][1] + 1L * a[1][1] * a[1][1]) % MOD);

                a[0][0] = (int) res00;
                a[0][1] = (int) res01;
                a[1][0] = (int) res10;
                a[1][1] = (int) res11;
                n /= 2;
            }
            this.a = res.a;
        }

        @Override
        public String toString() {
            return "Matr{" +
                    "a=" + Arrays.toString(a[0]) + " // " + Arrays.toString(a[1]) +
                    '}';
        }

    }

    class Node {
        Matr mul;
        Matr fib;

        public Node(int ai) {
            fib = new Matr(2);
            fib.makePow(ai);
            mul = new Matr(1);
        }

        public Node(Node a, Node b) {
            mul = new Matr(1);
            fib = new Matr(0);
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    fib.a[i][j] = (a.fib.a[i][j] + b.fib.a[i][j]);
                    if (fib.a[i][j] > MOD) fib.a[i][j] -= MOD;
                }
            }
        }
    }

    Node[] tree;
    int[] a;

    void build(int v, int tl, int tr) {
        if (tl > tr) return;
        if (tl == tr) tree[v] = new Node(a[tl]);
        else {
            int m = (tl + tr) / 2;
            build(v * 2, tl, m);
            build(v * 2 + 1, m + 1, tr);
            tree[v] = new Node(tree[v * 2], tree[v * 2 + 1]);
        }
        tree[v].mul = new Matr(1);

    }

    int sum(int v, int tl, int tr, int left, int right) {
        if (left > right) return 0;
        if (tl == left && tr == right) return tree[v].fib.a[0][1];
        int tm = (tl + tr) / 2;
        if (!(tree[v].mul.a[0][0] == 1 && tree[v].mul.a[1][1] == 1 && tree[v].mul.a[1][0] == 0 && tree[v].mul.a[0][1] == 0)) {
            int s1 = v * 2;
            int s2 = s1 + 1;
            res00 = ((1L * tree[s1].mul.a[0][0] * tree[v].mul.a[0][0] + 1L * tree[s1].mul.a[0][1] * tree[v].mul.a[1][0]) % MOD);
            res01 = ((1L * tree[s1].mul.a[0][0] * tree[v].mul.a[0][1] + 1L * tree[s1].mul.a[0][1] * tree[v].mul.a[1][1]) % MOD);
            res10 = ((1L * tree[s1].mul.a[1][0] * tree[v].mul.a[0][0] + 1L * tree[s1].mul.a[1][1] * tree[v].mul.a[1][0]) % MOD);
            res11 = ((1L * tree[s1].mul.a[1][0] * tree[v].mul.a[0][1] + 1L * tree[s1].mul.a[1][1] * tree[v].mul.a[1][1]) % MOD);

            tree[s1].mul.a[0][0] = (int) res00;
            tree[s1].mul.a[0][1] = (int) res01;
            tree[s1].mul.a[1][0] = (int) res10;
            tree[s1].mul.a[1][1] = (int) res11;
            res00 = ((1L * tree[s1].fib.a[0][0] * tree[v].mul.a[0][0] + 1L * tree[s1].fib.a[0][1] * tree[v].mul.a[1][0]) % MOD);
            res01 = ((1L * tree[s1].fib.a[0][0] * tree[v].mul.a[0][1] + 1L * tree[s1].fib.a[0][1] * tree[v].mul.a[1][1]) % MOD);
            res10 = ((1L * tree[s1].fib.a[1][0] * tree[v].mul.a[0][0] + 1L * tree[s1].fib.a[1][1] * tree[v].mul.a[1][0]) % MOD);
            res11 = ((1L * tree[s1].fib.a[1][0] * tree[v].mul.a[0][1] + 1L * tree[s1].fib.a[1][1] * tree[v].mul.a[1][1]) % MOD);

            tree[s1].fib.a[0][0] = (int) res00;
            tree[s1].fib.a[0][1] = (int) res01;
            tree[s1].fib.a[1][0] = (int) res10;
            tree[s1].fib.a[1][1] = (int) res11;
            res00 = ((1L * tree[s2].mul.a[0][0] * tree[v].mul.a[0][0] + 1L * tree[s2].mul.a[0][1] * tree[v].mul.a[1][0]) % MOD);
            res01 = ((1L * tree[s2].mul.a[0][0] * tree[v].mul.a[0][1] + 1L * tree[s2].mul.a[0][1] * tree[v].mul.a[1][1]) % MOD);
            res10 = ((1L * tree[s2].mul.a[1][0] * tree[v].mul.a[0][0] + 1L * tree[s2].mul.a[1][1] * tree[v].mul.a[1][0]) % MOD);
            res11 = ((1L * tree[s2].mul.a[1][0] * tree[v].mul.a[0][1] + 1L * tree[s2].mul.a[1][1] * tree[v].mul.a[1][1]) % MOD);

            tree[s2].mul.a[0][0] = (int) res00;
            tree[s2].mul.a[0][1] = (int) res01;
            
            tree[s2].mul.a[1][0] = (int) res10;
            tree[s2].mul.a[1][1] = (int) res11;
            res00 = ((1L * tree[s2].fib.a[0][0] * tree[v].mul.a[0][0] + 1L * tree[s2].fib.a[0][1] * tree[v].mul.a[1][0]) % MOD);
            res01 = ((1L * tree[s2].fib.a[0][0] * tree[v].mul.a[0][1] + 1L * tree[s2].fib.a[0][1] * tree[v].mul.a[1][1]) % MOD);
            res10 = ((1L * tree[s2].fib.a[1][0] * tree[v].mul.a[0][0] + 1L * tree[s2].fib.a[1][1] * tree[v].mul.a[1][0]) % MOD);
            res11 = ((1L * tree[s2].fib.a[1][0] * tree[v].mul.a[0][1] + 1L * tree[s2].fib.a[1][1] * tree[v].mul.a[1][1]) % MOD);

            tree[s2].fib.a[0][0] = (int) res00;
            
            tree[s2].fib.a[0][1] = (int) res01;
            tree[s2].fib.a[1][0] = (int) res10;
            tree[s2].fib.a[1][1] = (int) res11;
            tree[v].mul.a[0][0] = 1;
            tree[v].mul.a[1][1] = 1;
            tree[v].mul.a[1][0] = 0;
            tree[v].mul.a[0][1] = 0;
        }
        tree[v].mul = tree[v].mul;
        int res = sum(v * 2, tl, tm, left, right < tm ? right : tm) +
                sum(v * 2 + 1, tm + 1, tr, left > tm + 1 ? left : tm + 1, right);
        return res > MOD ? res - MOD : res;
    }

    void upd(int v, int tl, int tr, int left, int right, Matr mul) {
        if (left > right) return;
        Matr curMul = tree[v].mul;
        Matr curFib = tree[v].fib;
        if (tl == left && tr == right) {
            res00 = ((1L * curMul.a[0][0] * mul.a[0][0] + 1L * curMul.a[0][1] * mul.a[1][0]) % MOD);
            res01 = ((1L * curMul.a[0][0] * mul.a[0][1] + 1L * curMul.a[0][1] * mul.a[1][1]) % MOD);
            res10 = ((1L * curMul.a[1][0] * mul.a[0][0] + 1L * curMul.a[1][1] * mul.a[1][0]) % MOD);
            res11 = ((1L * curMul.a[1][0] * mul.a[0][1] + 1L * curMul.a[1][1] * mul.a[1][1]) % MOD);

            curMul.a[0][0] = (int) res00;
            curMul.a[0][1] = (int) res01;
            curMul.a[1][0] = (int) res10;
            curMul.a[1][1] = (int) res11;
            res00 = ((1L * curFib.a[0][0] * mul.a[0][0] + 1L * curFib.a[0][1] * mul.a[1][0]) % MOD);
            res01 = ((1L * curFib.a[0][0] * mul.a[0][1] + 1L * curFib.a[0][1] * mul.a[1][1]) % MOD);
            res10 = ((1L * curFib.a[1][0] * mul.a[0][0] + 1L * curFib.a[1][1] * mul.a[1][0]) % MOD);
            res11 = ((1L * curFib.a[1][0] * mul.a[0][1] + 1L * curFib.a[1][1] * mul.a[1][1]) % MOD);

            curFib.a[0][0] = (int) res00;
            curFib.a[0][1] = (int) res01;
            curFib.a[1][0] = (int) res10;
            curFib.a[1][1] = (int) res11;
        } else {
            int m = (tl + tr) / 2;
            if (!(curMul.a[0][0] == 1 && curMul.a[1][1] == 1 && curMul.a[1][0] == 0 && curMul.a[0][1] == 0)) {
                int s1 = v * 2;
                int s2 = s1 + 1;
                res00 = ((1L * tree[s1].mul.a[0][0] * curMul.a[0][0] + 1L * tree[s1].mul.a[0][1] * curMul.a[1][0]) % MOD);
                res01 = ((1L * tree[s1].mul.a[0][0] * curMul.a[0][1] + 1L * tree[s1].mul.a[0][1] * curMul.a[1][1]) % MOD);
                res10 = ((1L * tree[s1].mul.a[1][0] * curMul.a[0][0] + 1L * tree[s1].mul.a[1][1] * curMul.a[1][0]) % MOD);
                res11 = ((1L * tree[s1].mul.a[1][0] * curMul.a[0][1] + 1L * tree[s1].mul.a[1][1] * curMul.a[1][1]) % MOD);
    
                tree[s1].mul.a[0][0] = (int) res00;
                tree[s1].mul.a[0][1] = (int) res01;
                tree[s1].mul.a[1][0] = (int) res10;
                tree[s1].mul.a[1][1] = (int) res11;
                res00 = ((1L * tree[s1].fib.a[0][0] * curMul.a[0][0] + 1L * tree[s1].fib.a[0][1] * curMul.a[1][0]) % MOD);
                res01 = ((1L * tree[s1].fib.a[0][0] * curMul.a[0][1] + 1L * tree[s1].fib.a[0][1] * curMul.a[1][1]) % MOD);
                res10 = ((1L * tree[s1].fib.a[1][0] * curMul.a[0][0] + 1L * tree[s1].fib.a[1][1] * curMul.a[1][0]) % MOD);
                res11 = ((1L * tree[s1].fib.a[1][0] * curMul.a[0][1] + 1L * tree[s1].fib.a[1][1] * curMul.a[1][1]) % MOD);
    
                tree[s1].fib.a[0][0] = (int) res00;
                tree[s1].fib.a[0][1] = (int) res01;
                tree[s1].fib.a[1][0] = (int) res10;
                tree[s1].fib.a[1][1] = (int) res11;
                res00 = ((1L * tree[s2].mul.a[0][0] * curMul.a[0][0] + 1L * tree[s2].mul.a[0][1] * curMul.a[1][0]) % MOD);
                res01 = ((1L * tree[s2].mul.a[0][0] * curMul.a[0][1] + 1L * tree[s2].mul.a[0][1] * curMul.a[1][1]) % MOD);
                res10 = ((1L * tree[s2].mul.a[1][0] * curMul.a[0][0] + 1L * tree[s2].mul.a[1][1] * curMul.a[1][0]) % MOD);
                res11 = ((1L * tree[s2].mul.a[1][0] * curMul.a[0][1] + 1L * tree[s2].mul.a[1][1] * curMul.a[1][1]) % MOD);
    
                tree[s2].mul.a[0][0] = (int) res00;
                tree[s2].mul.a[0][1] = (int) res01;
                
                tree[s2].mul.a[1][0] = (int) res10;
                tree[s2].mul.a[1][1] = (int) res11;
                res00 = ((1L * tree[s2].fib.a[0][0] * curMul.a[0][0] + 1L * tree[s2].fib.a[0][1] * curMul.a[1][0]) % MOD);
                res01 = ((1L * tree[s2].fib.a[0][0] * curMul.a[0][1] + 1L * tree[s2].fib.a[0][1] * curMul.a[1][1]) % MOD);
                res10 = ((1L * tree[s2].fib.a[1][0] * curMul.a[0][0] + 1L * tree[s2].fib.a[1][1] * curMul.a[1][0]) % MOD);
                res11 = ((1L * tree[s2].fib.a[1][0] * curMul.a[0][1] + 1L * tree[s2].fib.a[1][1] * curMul.a[1][1]) % MOD);
    
                tree[s2].fib.a[0][0] = (int) res00;
                
                tree[s2].fib.a[0][1] = (int) res01;
                tree[s2].fib.a[1][0] = (int) res10;
                tree[s2].fib.a[1][1] = (int) res11;
                curMul.a[0][0] = 1;
                curMul.a[1][1] = 1;
                curMul.a[1][0] = 0;
                curMul.a[0][1] = 0;
            }
            upd(v * 2, tl, m, left, right < m ? right : m, mul);
            upd(v * 2 + 1, m + 1, tr, left > m + 1 ? left : m + 1, right, mul);
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    tree[v].fib.a[i][j] = (tree[v * 2].fib.a[i][j] + tree[v * 2 + 1].fib.a[i][j]);
                    if (tree[v].fib.a[i][j] > MOD) tree[v].fib.a[i][j] -= MOD;
                }
            }
            tree[v].mul = curMul;
        }
    }

    private void solve() throws IOException {
        int n = nextInt(), m = nextInt();
        tree = new Node[n * 4 + 4];
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        build(1, 0, n - 1);
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < m; i++) {
            int t = nextInt();
            int l = nextInt() - 1, r = nextInt() - 1;
            if (t == 1) {
                Matr matr = new Matr(2);
                matr.makePow(nextInt());
                upd(1, 0, n - 1, l, r, matr);
            } else {
                sb.append(sum(1, 0, n - 1, l, r)).append("\n");
            }
        }
        out.print(sb);
    }

    private void open() {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new BufferedOutputStream(System.out));
    }
}