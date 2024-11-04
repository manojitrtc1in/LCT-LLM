import java.util.*;
import java.io.*;

class Main {
    static class Pair<A, B> {
        A x;
        B y;

        Pair(A x, B y) {
            this.x = x;
            this.y = y;
        }
    }

    static class PtComparator implements Comparator<Pair<Integer, Integer>> {
        public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
            if (a.x.equals(b.x)) {
                return a.y.compareTo(b.y);
            }
            return b.x.compareTo(a.x);
        }
    }

    static final int N = 100 * 1000 + 13;
    static int n, m, k;
    static long h;
    static Pair<Long, Integer>[] a = new Pair[N];
    static boolean[] used = new boolean[N];
    static long[] mn = new long[N];
    static TreeSet<Pair<Integer, Integer>> cur = new TreeSet<>(new PtComparator());

    static boolean read() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String[] line = br.readLine().split(" ");
            h = Long.parseLong(line[0]);
            n = Integer.parseInt(line[1]);
            m = Integer.parseInt(line[2]);
            k = Integer.parseInt(line[3]);
            line = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = new Pair<>(Long.parseLong(line[2 * i]), Integer.parseInt(line[2 * i + 1]));
            }
            return true;
        } catch (IOException e) {
            return false;
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
        Arrays.fill(used, false);
        recalc();
        for (int i = 0; i < m; i++) {
            try {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                int t = Integer.parseInt(br.readLine());
                if (t == 1) {
                    long x = Long.parseLong(br.readLine());
                    add(x);
                    recalc();
                } else if (t == 2) {
                    String[] line = br.readLine().split(" ");
                    int x = Integer.parseInt(line[0]) - 1;
                    int y = Integer.parseInt(line[1]);
                    if (mn[(int) (a[x].x % k)] <= a[x].x) {
                        cur.remove(new Pair<>(a[x].y, -x));
                    }
                    a[x].y -= y;
                    if (mn[(int) (a[x].x % k)] <= a[x].x) {
                        cur.add(new Pair<>(a[x].y, -x));
                    }
                } else if (!cur.isEmpty()) {
                    System.out.println(cur.first().x);
                    used[-cur.first().y] = true;
                    cur.remove(cur.first());
                } else {
                    System.out.println(0);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int tt = (int) System.currentTimeMillis();
            while (read()) {
                solve();
            }
            System.err.println("TIME = " + ((int) System.currentTimeMillis() - tt));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
