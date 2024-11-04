import java.util.*;
import java.util.function.*;
import java.io.*;

class Item {
    Pair<Integer, Integer> key;
    int prior;
    long cnt;
    Item l, r;

    Item(Pair<Integer, Integer> key) {
        this.key = key;
        this.prior = new Random().nextInt();
        this.cnt = 1;
        this.l = null;
        this.r = null;
    }
}

class Pair<A, B> {
    A first;
    B second;

    Pair(A first, B second) {
        this.first = first;
        this.second = second;
    }
}

public class c985a9eab69e1d2c5b6b0a4a14eaf7bexcodeeval_processed_4000.json {
    static void update(Item t) {
        if (t == null) return;
        t.cnt = (t.l == null ? 0 : t.l.cnt) + (t.r == null ? 0 : t.r.cnt) + 1;
    }

    static void split(Item t, Pair<Integer, Integer> key, Item[] l, Item[] r) {
        if (t == null) {
            l[0] = r[0] = null;
        } else if (keyLessThan(t.key, key) || (keyEqual(t.key, key) && new Random().nextBoolean())) {
            split(t.l, key, l, r);
            r[0] = t;
        } else {
            split(t.r, key, r, l);
            l[0] = t;
        }
        update(l[0]);
        update(r[0]);
    }

    static void wsplit(Item t, Pair<Integer, Integer> key, Item[] l, Item[] r) {
        if (t == null) {
            l[0] = r[0] = null;
        } else if (keyLessThan(t.key, key) || keyEqual(t.key, key)) {
            wsplit(t.l, key, l, r);
            r[0] = t;
        } else {
            wsplit(t.r, key, r, l);
            l[0] = t;
        }
        update(l[0]);
        update(r[0]);
    }

    static void insert(Item[] t, Item it) {
        if (t[0] == null) {
            t[0] = it;
        } else if (it.prior > t[0].prior) {
            Item[] l = new Item[1], r = new Item[1];
            split(t[0], it.key, l, r);
            t[0] = it;
            t[0].l = l[0];
            t[0].r = r[0];
        } else {
            insert(it.keyLessThan(t[0].key) || (keyEqual(it.key, t[0].key) && new Random().nextBoolean()) ? t[0].l : t[0].r, it);
        }
        update(t[0]);
    }

    static void merge(Item[] t, Item l, Item r) {
        if (l == null || r == null) {
            t[0] = (l != null) ? l : r;
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
        if (t[0].keyEqual(key)) {
            Item[] merged = new Item[1];
            merge(merged, t[0].l, t[0].r);
            t[0] = merged[0];
        } else {
            erase(keyLessThan(key, t[0].key) ? t[0].l : t[0].r, key);
        }
        update(t[0]);
    }

    static long ans(List<Pair<Pair<Integer, Integer>, Pair<Integer, Integer>>> a) {
        Item[] t = new Item[1];
        long ans = 0;
        for (Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> i : a) {
            Item[] l = new Item[1], r = new Item[1];
            wsplit(t[0], i.second, l, r);
            ans += (r[0] == null ? 0 : r[0].cnt);
            merge(t, l[0], r[0]);
            insert(t, new Item(i.second));
        }
        return ans;
    }

    static boolean keyLessThan(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (long) a.first * b.second < (long) a.second * b.first;
    }

    static boolean keyEqual(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return (long) a.first * b.second == (long) a.second * b.first;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        List<Pair<Pair<Integer, Integer>, Pair<Integer, Integer>>> b = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            b.add(new Pair<>(new Pair<>(Math.abs(a), Math.abs(v - w)), new Pair<>(Math.abs(a), Math.abs(v + w))));
        }
        b.sort((a1, b1) -> {
            if (keyLessThan(a1.first, b1.first)) return -1;
            if (keyLessThan(b1.first, a1.first)) return 1;
            return keyLessThan(b1.second, a1.second) ? 1 : -1;
        });
        out.println(ans(b));
        out.flush();
    }
}
