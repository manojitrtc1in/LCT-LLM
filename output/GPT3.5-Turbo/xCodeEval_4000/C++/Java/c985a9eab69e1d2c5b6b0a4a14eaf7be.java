import java.util.*;

class Main {
    static class Item {
        Pair<Integer, Integer> key;
        int prior;
        int cnt;
        Item l, r;

        Item(Pair<Integer, Integer> key) {
            this.key = key;
            this.prior = (int) (Math.random() * Integer.MAX_VALUE);
            this.cnt = 1;
            this.l = null;
            this.r = null;
        }
    }

    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }

    static boolean lessThan(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (long) a.first * b.second < (long) a.second * b.first;
    }

    static boolean greaterThan(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (long) a.first * b.second > (long) a.second * b.first;
    }

    static boolean equalTo(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (long) a.first * b.second == (long) a.second * b.first;
    }

    static void update(Item t) {
        if (t == null) return;
        t.cnt = (t.l == null ? 0 : t.l.cnt) + (t.r == null ? 0 : t.r.cnt) + 1;
    }

    static void split(Item t, Pair<Integer, Integer> key, Item[] l, Item[] r) {
        if (t == null) {
            l[0] = null;
            r[0] = null;
        } else if (lessThan(key, t.key) || (equalTo(key, t.key) && Math.random() < 0.5)) {
            split(t.l, key, l, new Item[1]);
            r[0] = t;
        } else {
            split(t.r, key, new Item[1], r);
            l[0] = t;
        }
        update(l[0]);
        update(r[0]);
    }

    static void weakSplit(Item t, Pair<Integer, Integer> key, Item[] l, Item[] r) {
        if (t == null) {
            l[0] = null;
            r[0] = null;
        } else if (lessThan(key, t.key) || equalTo(key, t.key)) {
            weakSplit(t.l, key, l, new Item[1]);
            r[0] = t;
        } else {
            weakSplit(t.r, key, new Item[1], r);
            l[0] = t;
        }
        update(l[0]);
        update(r[0]);
    }

    static void insert(Item[] t, Item it) {
        if (t[0] == null) {
            t[0] = it;
        } else if (it.prior > t[0].prior) {
            split(t[0], it.key, it.l, it.r);
            t[0] = it;
        } else {
            insert(it.key.compareTo(t[0].key) < 0 || (it.key.compareTo(t[0].key) == 0 && Math.random() < 0.5) ? t[0].l : t[0].r, it);
        }
        update(t[0]);
    }

    static void merge(Item[] t, Item l, Item r) {
        if (l == null || r == null) {
            t[0] = l != null ? l : r;
        } else if (l.prior > r.prior) {
            merge(l.r, l.r, r);
            t[0] = l;
        } else {
            merge(r.l, l, r.l);
            t[0] = r;
        }
        update(t[0]);
    }

    static void erase(Item[] t, Pair<Integer, Integer> key) {
        if (t[0].key.equals(key)) {
            merge(t, t[0].l, t[0].r);
        } else {
            erase(key.compareTo(t[0].key) < 0 ? t[0].l : t[0].r, key);
        }
        update(t[0]);
    }

    static long ans(List<Pair<Pair<Integer, Integer>, Pair<Integer, Integer>>> a) {
        Item t = null;
        long ans = 0;
        for (Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> i : a) {
            Item[] l = new Item[1];
            Item[] r = new Item[1];
            weakSplit(t, i.second, l, r);
            ans += r[0] == null ? 0 : r[0].cnt;
            merge(t, l[0], r[0]);
            insert(new Item[]{t}, new Item(i.second));
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int w = sc.nextInt();
        List<Pair<Pair<Integer, Integer>, Pair<Integer, Integer>>> b = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int v = sc.nextInt();
            b.add(new Pair<>(new Pair<>(Math.abs(a), Math.abs(v - w)), new Pair<>(Math.abs(a), Math.abs(v + w))));
        }
        b.sort((a, b) -> {
            if (a.first.first.equals(b.first.first)) {
                return a.first.second.compareTo(b.first.second);
            }
            return a.first.first.compareTo(b.first.first);
        });
        System.out.println(ans(b));
    }
}
