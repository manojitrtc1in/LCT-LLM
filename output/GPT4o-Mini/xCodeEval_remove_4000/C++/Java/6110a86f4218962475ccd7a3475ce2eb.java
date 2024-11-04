import java.util.*;

public class 6110a86f4218962475ccd7a3475ce2ebxcodeeval_processed_4000.json {
    static long h;
    static int n, m, k;
    static Pair<Long, Integer>[] a = new Pair[100_013];
    static boolean[] used = new boolean[100_013];
    static long[] mn = new long[100_013];
    static TreeSet<Pair<Integer, Integer>> cur = new TreeSet<>((o1, o2) -> {
        if (!o1.getKey().equals(o2.getKey())) {
            return o2.getKey().compareTo(o1.getKey());
        }
        return o1.getValue().compareTo(o2.getValue());
    });

    static boolean read(Scanner scanner) {
        if (!scanner.hasNextLong()) return false;
        h = scanner.nextLong();
        n = scanner.nextInt();
        m = scanner.nextInt();
        k = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            long x = scanner.nextLong();
            int y = scanner.nextInt();
            a[i] = new Pair<>(x, y);
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
                if (mn[(int) (a[x].getKey() % k)] <= a[x].getKey())
                    cur.remove(new Pair<>(a[x].getValue(), -x));
                a[x] = new Pair<>(a[x].getKey(), a[x].getValue() - y);
                if (mn[(int) (a[x].getKey() % k)] <= a[x].getKey())
                    cur.add(new Pair<>(a[x].getValue(), -x));
            } else if (!cur.isEmpty()) {
                System.out.println(cur.first().getKey());
                used[-cur.first().getValue()] = true;
                cur.remove(cur.first());
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
    }
}

class Pair<K, V> {
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
}
