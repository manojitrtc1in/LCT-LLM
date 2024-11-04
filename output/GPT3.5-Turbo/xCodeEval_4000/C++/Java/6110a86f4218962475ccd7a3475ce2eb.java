import java.util.*;
import java.io.*;

class Main {
    static final int N = 100 * 1000 + 13;
    static int n, m, k;
    static long h;
    static Pair[] a;
    static boolean[] used;
    static long[] mn;
    static TreeSet<Pair<Integer, Integer>> cur;

    static class Pair<A, B> {
        A x;
        B y;

        Pair(A x, B y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
        }
    }

    static void add(long x) {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < k; i++) {
            q.add(i);
        }
        while (!q.isEmpty()) {
            int v = q.poll();
            if (mn[v] + x < mn[(v + (int) x) % k]) {
                mn[(v + (int) x) % k] = mn[v] + x;
                q.add((v + (int) x) % k);
            }
        }
    }

    static void recalc() {
        cur.clear();
        for (int i = 0; i < n; i++) {
            if (!used[i] && mn[(int) (a[i].x % k)] <= a[i].x) {
                cur.add(new Pair<>(a[i].y, -i));
            }
        }
    }

    static void solve() {
        for (int i = 0; i < k; i++) {
            mn[i] = h + 1;
        }
        mn[1] = 1;
        used = new boolean[N];
        recalc();
        for (int i = 0; i < m; i++) {
            int t = in.nextInt();
            if (t == 1) {
                long x = in.nextLong();
                add(x);
                recalc();
            } else if (t == 2) {
                int x = in.nextInt();
                int y = in.nextInt();
                x--;
                if (mn[(int) (a[x].x % k)] <= a[x].x) {
                    cur.remove(new Pair<>(a[x].y, -x));
                }
                a[x].y -= y;
                if (mn[(int) (a[x].x % k)] <= a[x].x) {
                    cur.add(new Pair<>(a[x].y, -x));
                }
            } else if (!cur.isEmpty()) {
                out.println(cur.first().x);
                used[-cur.first().y] = true;
                cur.remove(cur.first());
            } else {
                out.println(0);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        while (read(br)) {
            solve();
        }
        out.close();
    }

    static boolean read(BufferedReader br) throws IOException {
        String[] line = br.readLine().split(" ");
        if (line.length != 4) {
            return false;
        }
        h = Long.parseLong(line[0]);
        n = Integer.parseInt(line[1]);
        m = Integer.parseInt(line[2]);
        k = Integer.parseInt(line[3]);
        a = new Pair[n];
        for (int i = 0; i < n; i++) {
            line = br.readLine().split(" ");
            a[i] = new Pair<>(Long.parseLong(line[0]), Integer.parseInt(line[1]));
        }
        return true;
    }
}
