import java.util.*;

public class 3178bb488b9fe69eb4a6102c146768a4_nc {
    static final int nax = 1000 + 44;
    static List<Integer>[] graf = new ArrayList[nax];
    static int[] siz = new int[nax];
    static int[] dep = new int[nax];
    static List<Pair<Pair<Integer, Integer>, Integer>> ans = new ArrayList<>();
    static Deque<Integer> ava = new ArrayDeque<>();
    static List<Pair<Integer, Integer>>[] graf2 = new ArrayList[nax];
    static Set<Integer> seen = new HashSet<>();
    static int n;

    static {
        for (int i = 0; i < nax; i++) {
            graf[i] = new ArrayList<>();
            graf2[i] = new ArrayList<>();
        }
    }

    static void dfs1(int x, int y, int d) {
        siz[x] = 1;
        dep[x] = d;
        for (int v : graf[x]) {
            if (v != y) {
                dfs1(v, x, d + 1);
                siz[x] += siz[v];
            }
        }
    }

    static void dfs2(int x, int y, int d) {
        int t = ava.pollFirst();
        assert t > d;
        ans.add(new Pair<>(new Pair<>(x, y), t - d));
        for (int v : graf[x]) {
            if (v != y) dfs2(v, x, t);
        }
    }

    static void dfs3(int x, int y, int d) {
        seen.add(d);
        for (Pair<Integer, Integer> e : graf2[x]) {
            if (e.first != y) dfs3(e.first, x, d + e.second);
        }
    }

    static void test_ans() {
        for (Pair<Pair<Integer, Integer>, Integer> x : ans) {
            graf2[x.first.first].add(new Pair<>(x.first.second, x.second));
            graf2[x.first.second].add(new Pair<>(x.first.first, x.second));
        }
        for (int i = 1; i <= n; i++) {
            dfs3(i, -1, 0);
        }
        for (int i = 1; i <= n * n * 2 / 9; i++) {
            assert seen.contains(i);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        if (n == 1) return;

        for (int i = 0; i < n - 1; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            graf[a].add(b);
            graf[b].add(a);
        }

        dfs1(1, -1, 0);
        int M = n * 2 / 3;

        for (int i = 1; i <= n; i++) {
            List<Pair<Integer, Integer>> sizes = new ArrayList<>();
            sizes.add(new Pair<>(1, i));
            int p = -1;

            for (int v : graf[i]) {
                if (dep[v] == dep[i] + 1) {
                    sizes.add(new Pair<>(siz[v], v));
                } else {
                    p = v;
                }
            }

            if (i != 1) sizes.add(new Pair<>(n - siz[i], p));

            boolean good = true;
            for (Pair<Integer, Integer> x : sizes) {
                if (x.first > M) good = false;
            }

            if (good) {
                List<Pair<Integer, Integer>> v1 = new ArrayList<>();
                List<Pair<Integer, Integer>> v2 = new ArrayList<>();
                sizes.sort((a, b) -> b.first - a.first);
                int sum1 = 0, sum2 = 0, whme = 0;

                for (Pair<Integer, Integer> c : sizes) {
                    if (sum1 + c.first > M) {
                        v2.add(c);
                        sum2 += c.first;
                        if (c.second == i) whme = 2;
                    } else {
                        v1.add(c);
                        sum1 += c.first;
                        if (c.second == i) whme = 1;
                    }
                }

                assert sum1 * sum2 >= n * n * 2 / 9;
                assert whme != 0;

                if (whme == 2) {
                    Collections.swap(v1, v2);
                    int temp = sum1;
                    sum1 = sum2;
                    sum2 = temp;
                }

                for (int j = 1; j < sum1; j++) ava.addLast(j);
                for (Pair<Integer, Integer> x : v1) {
                    if (x.second != i) dfs2(x.second, i, 0);
                }
                assert ava.isEmpty();

                for (int j = 0; j < sum2; j++) ava.addLast(1 + j * sum1);
                for (Pair<Integer, Integer> x : v2) dfs2(x.second, i, 0);
                assert ava.isEmpty();

                for (Pair<Pair<Integer, Integer>, Integer> x : ans) {
                    System.out.printf("%d %d %d\n", x.first.first, x.first.second, x.second);
                }
                test_ans();
                return;
            }
        }
        assert false;
    }

    static class Pair<A, B> {
        A first;
        B second;

        Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }
}
