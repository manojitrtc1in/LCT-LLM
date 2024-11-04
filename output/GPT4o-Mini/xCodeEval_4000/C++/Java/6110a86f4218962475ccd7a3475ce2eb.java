import java.util.*;

public class 6110a86f4218962475ccd7a3475ce2eb_nc {
    static final int N = 100 * 1000 + 13;
    static long h;
    static int n, m, k;
    static Pair<Long, Integer>[] a = new Pair[N];
    static boolean[] used = new boolean[N];
    static long[] mn = new long[N];
    static TreeSet<Pair<Integer, Integer>> cur = new TreeSet<>(Collections.reverseOrder());

    static boolean read(Scanner scanner) {
        if (!scanner.hasNextLong()) return false;
        h = scanner.nextLong();
        n = scanner.nextInt();
        m = scanner.nextInt();
        k = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = new Pair<>(scanner.nextLong(), scanner.nextInt());
        }
        return true;
    }

    static void add(long x) {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < k; i++) q.add(i);
        while (!q.isEmpty()) {
            int v = q.poll();
            if (mn[v] + x < mn[(int) ((v + x) % k)]) {
                mn[(int) ((v + x) % k)] = mn[v] + x;
                q.add((int) ((v + x) % k));
            }
        }
    }

    static void recalc() {
        cur.clear();
        for (int i = 0; i < n; i++) {
            if (!used[i] && mn[(int) (a[i].getKey() % k)] <= a[i].getKey()) {
                cur.add(new Pair<>(a[i].getValue(), -i));
            }
        }
    }

    static void solve(Scanner scanner) {
        Arrays.fill(mn, h + 1);
        mn[1] = 1;
        Arrays.fill(used, false);
        recalc();
        for (int i = 0; i < m; i++) {
            int t = scanner.nextInt();
            if (t == 1) {
                long x = scanner.nextLong();
                add(x);
                recalc();
            } else if (t == 2) {
                int x = scanner.nextInt() - 1;
                int y = scanner.nextInt();
                if (mn[(int) (a[x].getKey() % k)] <= a[x].getKey()) {
                    cur.remove(new Pair<>(a[x].getValue(), -x));
                }
                a[x] = new Pair<>(a[x].getKey(), a[x].getValue() - y);
                if (mn[(int) (a[x].getKey() % k)] <= a[x].getKey()) {
                    cur.add(new Pair<>(a[x].getValue(), -x));
                }
            } else if (!cur.isEmpty()) {
                System.out.println(cur.first().getKey());
                used[-cur.first().getValue()] = true;
                cur.pollFirst();
            } else {
                System.out.println("0");
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (read(scanner)) {
            solve(scanner);
        }
        scanner.close();
    }

    static class Pair<K, V> implements Comparable<Pair<K, V>> {
        private final K key;
        private final V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        @Override
        public int compareTo(Pair<K, V> o) {
            return ((Comparable<K>) this.key).compareTo(o.key);
        }
    }
}
