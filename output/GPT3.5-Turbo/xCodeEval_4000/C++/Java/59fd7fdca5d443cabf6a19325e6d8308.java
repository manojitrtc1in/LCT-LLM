import java.util.*;

class Main {
    static int n, t;
    static int[] c;
    static Set<Integer>[] s, st;
    static Set<Pair<Integer, Integer>>[] deg, degt;

    static void removeLeaf(Set<Integer>[] s, Set<Pair<Integer, Integer>>[] deg, int v) {
        if (s[v].isEmpty()) {
            deg[c[v]].remove(new Pair<>(0, v));
            return;
        }
        int u = s[v].iterator().next();
        assert v != 0;
        deg[c[v]].remove(new Pair<>(s[v].size(), v));
        deg[c[u]].remove(new Pair<>(s[u].size(), u));
        s[u].remove(v);
        s[v].remove(u);
        deg[c[u]].add(new Pair<>(s[u].size(), u));
    }

    static void eraseGrey(Set<Integer>[] s, Set<Pair<Integer, Integer>>[] deg) {
        while (true) {
            if (deg[0].isEmpty()) break;
            Pair<Integer, Integer> ret = deg[0].iterator().next();
            if (ret.getFirst() > 1) break;
            removeLeaf(s, deg, ret.getSecond());
        }
    }

    static int solve(Set<Integer>[] s, Set<Pair<Integer, Integer>>[] deg, int beg) {
        int res = 0;
        eraseGrey(s, deg);
        while (true) {
            if (deg[0].isEmpty() && deg[1].isEmpty() && deg[2].isEmpty()) break;
            if (deg[beg].isEmpty()) {
                beg = 3 - beg;
                continue;
            }
            res++;
            while (true) {
                if (deg[beg].isEmpty()) break;
                Pair<Integer, Integer> ret = deg[beg].iterator().next();
                if (ret.getFirst() > 1) break;
                removeLeaf(s, deg, ret.getSecond());
                eraseGrey(s, deg);
            }
            beg = 3 - beg;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        while (t-- > 0) {
            n = sc.nextInt();
            c = new int[n + 1];
            s = new Set[n + 1];
            st = new Set[n + 1];
            deg = new Set[3];
            degt = new Set[3];
            for (int i = 0; i < 3; i++) {
                deg[i] = new TreeSet<>();
                degt[i] = new TreeSet<>();
            }
            for (int i = 1; i <= n; i++) {
                c[i] = sc.nextInt();
                s[i] = new TreeSet<>();
                st[i] = new TreeSet<>();
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
}

class Pair<T, U> implements Comparable<Pair<T, U>> {
    private T first;
    private U second;

    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public U getSecond() {
        return second;
    }

    public void setFirst(T first) {
        this.first = first;
    }

    public void setSecond(U second) {
        this.second = second;
    }

    @Override
    public int compareTo(Pair<T, U> other) {
        if (this.first.equals(other.first)) {
            return ((Comparable<U>) this.second).compareTo(other.second);
        } else {
            return ((Comparable<T>) this.first).compareTo(other.first);
        }
    }
}
