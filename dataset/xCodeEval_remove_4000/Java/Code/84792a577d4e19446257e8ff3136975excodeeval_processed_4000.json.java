import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskE {
    StringTokenizer st;
    BufferedReader in;
    PrintWriter out;
    private int[][] res = new int[2][2];

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

    class Pair {
        long fibCur, fibNext;
    }

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
                    TaskE.this.res[0][0] = (int) ((1L * res.a[0][0] * a[0][0] + 1L * res.a[0][1] * a[1][0]) % MOD);
                    TaskE.this.res[0][1] = (int) ((1L * res.a[0][0] * a[0][1] + 1L * res.a[0][1] * a[1][1]) % MOD);
                    TaskE.this.res[1][0] = (int) ((1L * res.a[1][0] * a[0][0] + 1L * res.a[1][1] * a[1][0]) % MOD);
                    TaskE.this.res[1][1] = (int) ((1L * res.a[1][0] * a[0][1] + 1L * res.a[1][1] * a[1][1]) % MOD);

                    res.a[0][0] = TaskE.this.res[0][0];
                    res.a[0][1] = TaskE.this.res[0][1];
                    res.a[1][0] = TaskE.this.res[1][0];
                    res.a[1][1] = TaskE.this.res[1][1];
                }
                TaskE.this.res[0][0] = (int) ((1L * a[0][0] * a[0][0] + 1L * a[0][1] * a[1][0]) % MOD);
                TaskE.this.res[0][1] = (int) ((1L * a[0][0] * a[0][1] + 1L * a[0][1] * a[1][1]) % MOD);
                TaskE.this.res[1][0] = (int) ((1L * a[1][0] * a[0][0] + 1L * a[1][1] * a[1][0]) % MOD);
                TaskE.this.res[1][1] = (int) ((1L * a[1][0] * a[0][1] + 1L * a[1][1] * a[1][1]) % MOD);

                a[0][0] = TaskE.this.res[0][0];
                a[0][1] = TaskE.this.res[0][1];
                a[1][0] = TaskE.this.res[1][0];
                a[1][1] = TaskE.this.res[1][1];
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

        public boolean isOne() {
            return a[0][0] == 1 && a[1][1] == 1 && a[1][0] == 0 && a[0][1] == 0;
        }

        public void setOne() {
            a[0][0] = 1;
            a[1][1] = 1;
            a[1][0] = 0;
            a[0][1] = 0;
        }

        public void setSum(Matr fib, Matr fib1) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    a[i][j] = (fib.a[i][j] + fib1.a[i][j]);
                    if (a[i][j] > MOD) a[i][j] -= MOD;
                }
            }
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
            fib.setSum(a.fib, b.fib);
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
        tree[v].mul = push(v, tree[v].mul);
        int res = sum(v * 2, tl, tm, left, min(right, tm)) +
                sum(v * 2 + 1, tm + 1, tr, max(left, tm + 1), right);
        return res > MOD ? res - MOD : res;
    }

    void upd(int v, int tl, int tr, int left, int right, Matr mul) {
        if (left > right) return;
        Matr curMul = tree[v].mul;
        Matr curFib = tree[v].fib;
        if (tl == left && tr == right) {
            res[0][0] = (int) ((1L * curMul.a[0][0] * mul.a[0][0] + 1L * curMul.a[0][1] * mul.a[1][0]) % MOD);
            res[0][1] = (int) ((1L * curMul.a[0][0] * mul.a[0][1] + 1L * curMul.a[0][1] * mul.a[1][1]) % MOD);
            res[1][0] = (int) ((1L * curMul.a[1][0] * mul.a[0][0] + 1L * curMul.a[1][1] * mul.a[1][0]) % MOD);
            res[1][1] = (int) ((1L * curMul.a[1][0] * mul.a[0][1] + 1L * curMul.a[1][1] * mul.a[1][1]) % MOD);

            curMul.a[0][0] = res[0][0];
            curMul.a[0][1] = res[0][1];
            curMul.a[1][0] = res[1][0];
            curMul.a[1][1] = res[1][1];
            res[0][0] = (int) ((1L * curFib.a[0][0] * mul.a[0][0] + 1L * curFib.a[0][1] * mul.a[1][0]) % MOD);
            res[0][1] = (int) ((1L * curFib.a[0][0] * mul.a[0][1] + 1L * curFib.a[0][1] * mul.a[1][1]) % MOD);
            res[1][0] = (int) ((1L * curFib.a[1][0] * mul.a[0][0] + 1L * curFib.a[1][1] * mul.a[1][0]) % MOD);
            res[1][1] = (int) ((1L * curFib.a[1][0] * mul.a[0][1] + 1L * curFib.a[1][1] * mul.a[1][1]) % MOD);

            curFib.a[0][0] = res[0][0];
            curFib.a[0][1] = res[0][1];
            curFib.a[1][0] = res[1][0];
            curFib.a[1][1] = res[1][1];
        } else {
            int m = (tl + tr) / 2;
            curMul = push(v, curMul);
            upd(v * 2, tl, m, left, min(right, m), mul);
            upd(v * 2 + 1, m + 1, tr, max(left, m + 1), right, mul);
            tree[v].fib.setSum(tree[v * 2].fib, tree[v * 2 + 1].fib);
            tree[v].mul = curMul;
        }
    }

    final int min(int a, int b) {
        return a < b ? a : b;
    }

    final int max(int a, int b) {
        return a > b ? a : b;
    }


    private Matr push(int v, Matr curMul) {
        if (!curMul.isOne()) {
            res[0][0] = (int) ((1L * tree[v * 2].mul.a[0][0] * curMul.a[0][0] + 1L * tree[v * 2].mul.a[0][1] * curMul.a[1][0]) % MOD);
            res[0][1] = (int) ((1L * tree[v * 2].mul.a[0][0] * curMul.a[0][1] + 1L * tree[v * 2].mul.a[0][1] * curMul.a[1][1]) % MOD);
            res[1][0] = (int) ((1L * tree[v * 2].mul.a[1][0] * curMul.a[0][0] + 1L * tree[v * 2].mul.a[1][1] * curMul.a[1][0]) % MOD);
            res[1][1] = (int) ((1L * tree[v * 2].mul.a[1][0] * curMul.a[0][1] + 1L * tree[v * 2].mul.a[1][1] * curMul.a[1][1]) % MOD);

            tree[v * 2].mul.a[0][0] = res[0][0];
            tree[v * 2].mul.a[0][1] = res[0][1];
            tree[v * 2].mul.a[1][0] = res[1][0];
            tree[v * 2].mul.a[1][1] = res[1][1];
            res[0][0] = (int) ((1L * tree[v * 2].fib.a[0][0] * curMul.a[0][0] + 1L * tree[v * 2].fib.a[0][1] * curMul.a[1][0]) % MOD);
            res[0][1] = (int) ((1L * tree[v * 2].fib.a[0][0] * curMul.a[0][1] + 1L * tree[v * 2].fib.a[0][1] * curMul.a[1][1]) % MOD);
            res[1][0] = (int) ((1L * tree[v * 2].fib.a[1][0] * curMul.a[0][0] + 1L * tree[v * 2].fib.a[1][1] * curMul.a[1][0]) % MOD);
            res[1][1] = (int) ((1L * tree[v * 2].fib.a[1][0] * curMul.a[0][1] + 1L * tree[v * 2].fib.a[1][1] * curMul.a[1][1]) % MOD);

            tree[v * 2].fib.a[0][0] = res[0][0];
            tree[v * 2].fib.a[0][1] = res[0][1];
            tree[v * 2].fib.a[1][0] = res[1][0];
            tree[v * 2].fib.a[1][1] = res[1][1];
            res[0][0] = (int) ((1L * tree[v * 2 + 1].mul.a[0][0] * curMul.a[0][0] + 1L * tree[v * 2 + 1].mul.a[0][1] * curMul.a[1][0]) % MOD);
            res[0][1] = (int) ((1L * tree[v * 2 + 1].mul.a[0][0] * curMul.a[0][1] + 1L * tree[v * 2 + 1].mul.a[0][1] * curMul.a[1][1]) % MOD);
            res[1][0] = (int) ((1L * tree[v * 2 + 1].mul.a[1][0] * curMul.a[0][0] + 1L * tree[v * 2 + 1].mul.a[1][1] * curMul.a[1][0]) % MOD);
            res[1][1] = (int) ((1L * tree[v * 2 + 1].mul.a[1][0] * curMul.a[0][1] + 1L * tree[v * 2 + 1].mul.a[1][1] * curMul.a[1][1]) % MOD);

            tree[v * 2 + 1].mul.a[0][0] = res[0][0];
            tree[v * 2 + 1].mul.a[0][1] = res[0][1];
            tree[v * 2 + 1].mul.a[1][0] = res[1][0];
            tree[v * 2 + 1].mul.a[1][1] = res[1][1];
            res[0][0] = (int) ((1L * tree[v * 2 + 1].fib.a[0][0] * curMul.a[0][0] + 1L * tree[v * 2 + 1].fib.a[0][1] * curMul.a[1][0]) % MOD);
            res[0][1] = (int) ((1L * tree[v * 2 + 1].fib.a[0][0] * curMul.a[0][1] + 1L * tree[v * 2 + 1].fib.a[0][1] * curMul.a[1][1]) % MOD);
            res[1][0] = (int) ((1L * tree[v * 2 + 1].fib.a[1][0] * curMul.a[0][0] + 1L * tree[v * 2 + 1].fib.a[1][1] * curMul.a[1][0]) % MOD);
            res[1][1] = (int) ((1L * tree[v * 2 + 1].fib.a[1][0] * curMul.a[0][1] + 1L * tree[v * 2 + 1].fib.a[1][1] * curMul.a[1][1]) % MOD);

            tree[v * 2 + 1].fib.a[0][0] = res[0][0];
            tree[v * 2 + 1].fib.a[0][1] = res[0][1];
            tree[v * 2 + 1].fib.a[1][0] = res[1][0];
            tree[v * 2 + 1].fib.a[1][1] = res[1][1];
            curMul.setOne();
        }
        return curMul;
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