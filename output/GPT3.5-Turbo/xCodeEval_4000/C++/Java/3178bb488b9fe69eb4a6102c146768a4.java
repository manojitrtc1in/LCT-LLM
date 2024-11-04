import java.util.*;

class Main {
    static class Pair {
        int first;
        int second;
        
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    
    static List<Integer>[] graf;
    static int[] siz;
    static int[] dep;
    static List<Pair> ans;
    static Deque<Integer> ava;
    static int n;
    
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
        int t = ava.getFirst();
        ava.removeFirst();
        assert t > d;
        ans.add(new Pair(x, y), t - d);
        for (int v : graf[x]) {
            if (v != y) {
                dfs2(v, x, t);
            }
        }
    }
    
    static void dfs3(int x, int y, int d) {
        seen.add(d);
        for (Pair e : graf2[x]) {
            if (e.first != y) {
                dfs3(e.first, x, d + e.second);
            }
        }
    }
    
    static void test_ans() {
        for (Pair x : ans) {
            graf2[x.first.first].add(new Pair(x.first.second, x.second));
            graf2[x.first.second].add(new Pair(x.first.first, x.second));
        }
        for (int i = 1; i <= n; i++) {
            dfs3(i);
        }
        System.out.println(seen);
        for (int i = 1; i <= n * n * 2 / 9; i++) {
            assert seen.contains(i);
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        if (n == 1) {
            return;
        }
        graf = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            graf[i] = new ArrayList<>();
        }
        siz = new int[n + 1];
        dep = new int[n + 1];
        ans = new ArrayList<>();
        ava = new ArrayDeque<>();
        for (int i = 1; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            graf[a].add(b);
            graf[b].add(a);
        }
        dfs1(1, -1, 0);
        int M = n * 2 / 3;
        for (int i = 1; i <= n; i++) {
            List<Pair> sizes = new ArrayList<>();
            sizes.add(new Pair(1, i));
            int p = -1;
            for (int v : graf[i]) {
                if (dep[v] == dep[i] + 1) {
                    sizes.add(new Pair(siz[v], v));
                } else {
                    p = v;
                }
            }
            if (i != 1) {
                sizes.add(new Pair(n - siz[i], p));
            }
            boolean good = true;
            for (Pair x : sizes) {
                if (x.first > M) {
                    good = false;
                }
            }
            if (good) {
                List<Pair> v1 = new ArrayList<>();
                List<Pair> v2 = new ArrayList<>();
                sizes.sort((a, b) -> b.first - a.first);
                int sum1 = 0, sum2 = 0;
                int whme = 0;
                for (Pair c : sizes) {
                    if (sum1 + c.first > M) {
                        v2.add(c);
                        sum2 += c.first;
                        if (c.second == i) {
                            whme = 2;
                        }
                    } else {
                        v1.add(c);
                        sum1 += c.first;
                        if (c.second == i) {
                            whme = 1;
                        }
                    }
                    assert sum1 <= M && sum2 <= M;
                }
                assert sum1 * sum2 >= n * n * 2 / 9;
                assert whme != 0;
                if (whme == 2) {
                    List<Pair> temp = v1;
                    v1 = v2;
                    v2 = temp;
                    int tempSum = sum1;
                    sum1 = sum2;
                    sum2 = tempSum;
                }
                for (int j = 1; j < sum1; j++) {
                    ava.add(j);
                }
                for (Pair x : v1) {
                    if (x.second != i) {
                        dfs2(x.second, i, 0);
                    }
                }
                assert ava.isEmpty();
                for (int j = 0; j < sum2; j++) {
                    ava.add(1 + j * sum1);
                }
                for (Pair x : v2) {
                    dfs2(x.second, i, 0);
                }
                assert ava.isEmpty();
                for (Pair x : ans) {
                    System.out.println(x.first + " " + x.second + " " + x.third);
                }
                test_ans();
                return;
            }
        }
        assert false;
    }
}
