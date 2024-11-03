import java.util.*;
import java.io.*;

class Main {
    static class popu {
        int[] v;
        TreeSet<Pair<Integer, Integer>> q;
        int p;
        int z;

        public popu(int n, int p) {
            v = new int[n];
            q = new TreeSet<>((a, b) -> a.first.equals(b.first) ? a.second - b.second : a.first - b.first);
            this.p = p;
            z = 0;
            for (int i = 0; i < n; i++) {
                if (i != p) {
                    add(i);
                }
            }
        }

        public void add(int t) {
            q.add(new Pair<>(v[t], t));
        }

        public void remove(int t) {
            q.remove(new Pair<>(v[t], t));
        }

        public int max_el() {
            return q.last().second;
        }

        public boolean is_popu() {
            return v[max_el()] >= z;
        }

        public void change(int t, int val) {
            if (t == p) {
                z += val;
            } else {
                remove(t);
                v[t] += val;
                add(t);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) {
            System.out.println("0");
        } else {
            int[] v = new int[n];
            String[] input = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                v[i] = Integer.parseInt(input[i]) - 1;
            }
            int[] q = new int[n];
            int[] qq = new int[n];
            Pair<Integer, Integer> mx = new Pair<>(0, 0);
            for (int i = 0; i < n; i++) {
                q[v[i]]++;
                mx = new Pair<>(Math.max(mx.first, q[v[i]]), v[i]);
            }
            int p = mx.second;
            List<List<Integer>> u = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (i != p) {
                    u.get(q[i]).add(i);
                }
            }
            List<Integer> uu = new ArrayList<>();
            for (int i = n; i >= 0; i--) {
                if (!u.get(i).isEmpty()) {
                    uu.add(i);
                }
            }
            int last = 0;
            List<List<Integer>> leftmost = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                leftmost.get(i).addAll(Collections.nCopies(q[i] + 1, n + 1));
                leftmost.get(i).set(0, 0);
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (v[i] != p) {
                    q[v[i]]++;
                }
            }
            for (int y = 0; y < Math.min(n, 100); y++) {
                if (y != p) {
                    int[] g = new int[n + 1];
                    Arrays.fill(g, -1);
                    int b = 0;
                    for (int i = 0; i < n; i++) {
                        if (v[i] == p) {
                            ans = Math.max(ans, i - g[g.length - b - 1] - 1);
                            if (b > 0) {
                                b--;
                            } else {
                                g = Arrays.copyOf(g, g.length + 1);
                                g[g.length - 1] = i;
                            }
                        } else if (v[i] == y) {
                            b++;
                        }
                    }
                    ans = Math.max(ans, n - g[g.length - b - 1] - 1);
                }
            }
            System.out.println(ans);
        }
    }

    static class Pair<T, U> {
        T first;
        U second;

        public Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }
}
