import java.util.*;
import java.io.*;

class Main {
    static final String INPUT_FILE = "input.txt";
    static final String OUTPUT_FILE = "output.txt";

    static class popu {
        int[] v;
        TreeSet<Pair<Integer, Integer>> q;
        int p;
        int z;

        void add(int t) {
            q.add(new Pair<>(v[t], t));
        }

        void remove(int t) {
            q.remove(new Pair<>(v[t], t));
        }

        popu(int n, int p) {
            v = new int[n];
            this.p = p;
            z = 0;
            q = new TreeSet<>((a, b) -> {
                if (a.first.equals(b.first)) {
                    return a.second - b.second;
                }
                return a.first - b.first;
            });
            for (int i = 0; i < n; i++) {
                if (i != p) {
                    add(i);
                }
            }
        }

        int max_el() {
            return q.last().second;
        }

        boolean is_popu() {
            return v[max_el()] >= z;
        }

        int change(int t, int val) {
            if (t == p) {
                z += val;
            } else {
                remove(t);
                v[t] += val;
                add(t);
            }
            return 0;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(INPUT_FILE));
        PrintWriter pw = new PrintWriter(new FileWriter(OUTPUT_FILE));

        int n = Integer.parseInt(br.readLine());
        if (n == 1) {
            pw.println("0");
        } else {
            int[] v = new int[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                v[i] = Integer.parseInt(st.nextToken()) - 1;
            }
            int[] q = new int[n];
            int[] qq = new int[n];
            Pair<Integer, Integer> mx = new Pair<>(0, 0);
            for (int i = 0; i < n; i++) {
                q[v[i]]++;
                mx = new Pair<>(Math.max(mx.first, q[v[i]]), v[i]);
            }
            int p = mx.second;
            List<List<Integer>> u = new ArrayList<>(n + 1);
            for (int i = 0; i <= n; i++) {
                u.add(new ArrayList<>());
            }
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
            List<List<Integer>> leftmost = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                leftmost.add(new ArrayList<>(Collections.nCopies(q[i] + 1, n + 1)));
                leftmost.get(i).set(0, 0);
            }
            int ans = 0;
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
            pw.println(ans);
        }

        br.close();
        pw.close();
    }
}
