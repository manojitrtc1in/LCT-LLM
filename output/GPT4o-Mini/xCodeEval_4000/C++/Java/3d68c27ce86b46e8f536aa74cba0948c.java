import java.io.*;
import java.util.*;

public class 3d68c27ce86b46e8f536aa74cba0948c_nc {
    static final int LITTLE_BORDER = 400;
    static final String INPUT_FILE = "input.txt";
    static final String OUTPUT_FILE = "output.txt";
    static final Random rng = new Random(2391);
    
    static class Popu {
        int[] v;
        TreeSet<Pair> q;
        int p;
        int z;

        public Popu(int n, int p) {
            v = new int[n];
            q = new TreeSet<>();
            this.p = p;
            this.z = 0;
            for (int i = 0; i < n; i++) {
                if (i != p) add(i);
            }
        }

        void add(int t) {
            q.add(new Pair(v[t], t));
        }

        void remove(int t) {
            q.remove(new Pair(v[t], t));
        }

        int maxEl() {
            return q.last().y;
        }

        boolean isPopu() {
            return v[maxEl()] >= z;
        }

        void change(int t, int val) {
            if (t == p) z += val;
            else {
                remove(t);
                v[t] += val;
                add(t);
            }
        }
    }

    static class Pair implements Comparable<Pair> {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pair o) {
            return Integer.compare(this.x, o.x);
        }
    }

    static int anotherMain() throws IOException {
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
            Pair mx = new Pair(0, 0);
            for (int i = 0; i < n; i++) {
                q[v[i]]++;
                mx = max(mx, new Pair(q[v[i]], v[i]));
            }
            int p = mx.y;
            List<Integer>[] u = new ArrayList[n + 1];
            for (int i = 0; i <= n; i++) {
                u[i] = new ArrayList<>();
            }
            for (int i = 0; i < n; i++) {
                if (i != p) {
                    u[q[i]].add(i);
                }
            }
            List<Integer> uu = new ArrayList<>();
            for (int i = n; i >= 0; i--) {
                if (!u[i].isEmpty()) {
                    uu.add(i);
                }
            }
            int last = 0;
            int[] leftmost = new int[n];
            for (int i = 0; i < n; i++) {
                leftmost[i] = n + 1;
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
                    int b = 0;
                    for (int i = 0; i < n; i++) {
                        if (v[i] == p) {
                            ans = Math.max(ans, i - g[g.length - b - 1] - 1);
                            if (b > 0) {
                                b--;
                            } else {
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
        return 0;
    }

    public static void main(String[] args) throws IOException {
        anotherMain();
    }
}
