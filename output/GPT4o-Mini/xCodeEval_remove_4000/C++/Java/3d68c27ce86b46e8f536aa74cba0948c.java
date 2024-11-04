import java.util.*;
import java.io.*;

public class 3d68c27ce86b46e8f536aa74cba0948cxcodeeval_processed_4000.json {
    static final String INPUT_FILE = "input.txt";
    static final String OUTPUT_FILE = "output.txt";

    static class Popu {
        List<Integer> v;
        TreeSet<Pair<Integer, Integer>> q;
        int p;
        int z;

        public Popu(int n, int p) {
            v = new ArrayList<>(Collections.nCopies(n, 0));
            q = new TreeSet<>((a, b) -> {
                if (!a.first.equals(b.first)) return b.first - a.first;
                return a.second - b.second;
            });
            this.p = p;
            this.z = 0;
            for (int i = 0; i < n; i++) {
                if (i != p) add(i);
            }
        }

        void add(int t) {
            q.add(new Pair<>(v.get(t), t));
        }

        void remove(int t) {
            q.remove(new Pair<>(v.get(t), t));
        }

        int maxEl() {
            return q.first().second;
        }

        boolean isPopu() {
            return v.get(maxEl()) >= z;
        }

        void change(int t, int val) {
            if (t == p) z += val;
            else {
                remove(t);
                v.set(t, v.get(t) + val);
                add(t);
            }
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
            int[] qq = new int[n];
            Pair<Integer, Integer> mx = new Pair<>(0, 0);
            for (int i = 0; i < n; i++) {
                q[v[i]]++;
                mx = max(mx, new Pair<>(q[v[i]], v[i]));
            }
            int p = mx.second;
            List<List<Integer>> u = new ArrayList<>(Collections.nCopies(n + 1, new ArrayList<>()));
            for (int i = 0; i < n; i++) {
                if (i != p) u.get(q[i]).add(i);
            }
            List<Integer> uu = new ArrayList<>();
            for (int i = n; i >= 0; i--) {
                if (!u.get(i).isEmpty()) uu.add(i);
            }
            int last = 0;
            List<List<Integer>> leftmost = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                leftmost.add(new ArrayList<>(Collections.nCopies(q[i] + 1, n + 1)));
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
                            if (b > 0) b--;
                            else g[g.length] = i;
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
        long startTime = System.currentTimeMillis();
        anotherMain();
        long endTime = System.currentTimeMillis();
        System.err.printf("Execution time: %d ms%n", (endTime - startTime));
    }

    static <T, U> Pair<T, U> max(Pair<T, U> a, Pair<T, U> b) {
        return a.first.compareTo(b.first) >= 0 ? a : b;
    }

    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }
}
