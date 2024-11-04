import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] c = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                c[i] = sc.nextInt();
            }
            Set<Integer>[] s = new HashSet[n + 1];
            Set<Integer>[] st = new HashSet[n + 1];
            for (int i = 1; i <= n; i++) {
                s[i] = new HashSet<>();
                st[i] = new HashSet<>();
            }
            Set<Pair<Integer, Integer>>[] deg = new TreeSet[3];
            Set<Pair<Integer, Integer>>[] degt = new TreeSet[3];
            for (int i = 0; i < 3; i++) {
                deg[i] = new TreeSet<>();
                degt[i] = new TreeSet<>();
            }
            for (int i = 1; i < n; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                s[u].add(v);
                s[v].add(u);
                st[u].add(v);
                st[v].add(u);
            }
            for (int i = 1; i <= n; i++) {
                deg[c[i]].add(new Pair<>(s[i].size(), i));
                degt[c[i]].add(new Pair<>(s[i].size(), i));
            }
            System.out.print(Math.max(Math.min(solve(s, deg, 1), solve(st, degt, 2)), 1) + " ");
        }
    }

    static void removeLeaf(Set<Integer>[] s, Set<Pair<Integer, Integer>>[] deg, int v) {
        if (s[v].size() == 0) {
            deg[c[v]].remove(new Pair<>(0, v));
            return;
        }
        int u = s[v].iterator().next();
        deg[c[v]].remove(new Pair<>(s[v].size(), v));
        deg[c[u]].remove(new Pair<>(s[u].size(), u));
        s[u].remove(v);
        s[v].remove(u);
        deg[c[u]].add(new Pair<>(s[u].size(), u));
    }

    static void id5(Set<Integer>[] s, Set<Pair<Integer, Integer>>[] deg) {
        while (true) {
            if (deg[0].size() == 0) {
                break;
            }
            Pair<Integer, Integer> ret = deg[0].iterator().next();
            if (ret.getKey() > 1) {
                break;
            }
            removeLeaf(s, deg, ret.getValue());
        }
    }

    static int solve(Set<Integer>[] s, Set<Pair<Integer, Integer>>[] deg, int beg) {
        int res = 0;
        id5(s, deg);
        while (true) {
            if (deg[0].size() == 0 && deg[1].size() == 0 && deg[2].size() == 0) {
                break;
            }
            if (deg[beg].size() == 0) {
                beg = 3 - beg;
                continue;
            }
            res++;
            while (true) {
                if (deg[beg].size() == 0) {
                    break;
                }
                Pair<Integer, Integer> ret = deg[beg].iterator().next();
                if (ret.getKey() > 1) {
                    break;
                }
                removeLeaf(s, deg, ret.getValue());
                id5(s, deg);
            }
            beg = 3 - beg;
        }
        return res;
    }
}

class Pair<K, V> implements Comparable<Pair<K, V>> {
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
    public int compareTo(Pair<K, V> other) {
        return key.equals(other.key) ? ((Comparable<V>) value).compareTo(other.value)
                : ((Comparable<K>) key).compareTo(other.key);
    }
}
