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
    
    static class Node {
        int index;
        int size;
        int depth;
        List<Integer> neighbors;
        
        Node(int index) {
            this.index = index;
            this.size = 0;
            this.depth = 0;
            this.neighbors = new ArrayList<>();
        }
    }
    
    static List<Integer>[] graph;
    static int[] size;
    static int[] depth;
    static List<Pair> answer;
    static Deque<Integer> available;
    static int n;
    
    static void dfs1(int x, int y, int d) {
        size[x] = 1;
        depth[x] = d;
        for (int v : graph[x]) {
            if (v != y) {
                dfs1(v, x, d + 1);
                size[x] += size[v];
            }
        }
    }
    
    static void dfs2(int x, int y, int d) {
        int t = available.getFirst();
        System.out.println("pop " + t);
        available.removeFirst();
        assert t > d;
        answer.add(new Pair(x, y), t - d);
        System.out.println(x + " " + y + " " + d + " " + answer.get(answer.size() - 1));
        for (int v : graph[x]) {
            if (v != y) {
                dfs2(v, x, t);
            }
        }
    }
    
    static void dfs3(int x, int y, int d) {
        seen.add(d);
        for (Pair e : graph2[x]) {
            if (e.first != y) {
                dfs3(e.first, x, d + e.second);
            }
        }
    }
    
    static void testAns() {
        for (Pair x : answer) {
            graph2[x.first.first].add(new Pair(x.first.second, x.second));
            graph2[x.first.second].add(new Pair(x.first.first, x.second));
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
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        if (n == 1) {
            return;
        }
        System.out.println(n * n * 2 / 9);
        graph = new List[n + 1];
        size = new int[n + 1];
        depth = new int[n + 1];
        answer = new ArrayList<>();
        available = new ArrayDeque<>();
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            graph[a].add(b);
            graph[b].add(a);
        }
        dfs1(1, -1, 0);
        int M = n * 2 / 3;
        for (int i = 1; i <= n; i++) {
            List<Pair> sizes = new ArrayList<>();
            sizes.add(new Pair(1, i));
            int p = -1;
            for (int v : graph[i]) {
                if (depth[v] == depth[i] + 1) {
                    sizes.add(new Pair(size[v], v));
                } else {
                    p = v;
                }
            }
            if (i != 1) {
                sizes.add(new Pair(n - size[i], p));
            }
            System.out.println(i + " " + sizes);
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
                int sum1 = 0;
                int sum2 = 0;
                int whme = 0;
                System.out.println(sizes);
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
                    System.out.println(sum1 + " " + sum2);
                }
                assert sum1 * sum2 >= n * n * 2 / 9;
                assert whme != 0;
                if (whme == 2) {
                    System.out.println("swap");
                    List<Pair> temp = v1;
                    v1 = v2;
                    v2 = temp;
                    int tempSum = sum1;
                    sum1 = sum2;
                    sum2 = tempSum;
                }
                for (int j = 1; j <= sum1 - 1; j++) {
                    available.add(j);
                }
                System.out.println(available);
                System.out.println(v1 + " " + v2);
                for (Pair x : v1) {
                    if (x.second != i) {
                        dfs2(x.second, i, 0);
                    }
                }
                assert available.isEmpty();
                for (int j = 0; j < sum2; j++) {
                    available.add(1 + j * sum1);
                }
                System.out.println(available);
                for (Pair x : v2) {
                    dfs2(x.second, i, 0);
                }
                assert available.isEmpty();
                for (Pair x : answer) {
                    System.out.println(x.first + " " + x.second);
                }
                testAns();
                return;
            } else {
                System.out.println("err");
            }
        }
        assert false;
    }
}
