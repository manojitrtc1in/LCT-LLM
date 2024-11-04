import java.util.*;
import java.io.*;

class Main {
    static class popu {
        ArrayList<Integer> v;
        TreeSet<Pair<Integer, Integer>> q;
        int p;
        int z;

        public popu(int n, int p) {
            v = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                v.add(0);
            }
            this.p = p;
            this.z = 0;
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

        public void add(int t) {
            q.add(new Pair<>(v.get(t), t));
        }

        public void remove(int t) {
            q.remove(new Pair<>(v.get(t), t));
        }

        public int max_el() {
            return q.last().second;
        }

        public boolean is_popu() {
            return v.get(max_el()) >= z;
        }

        public int change(int t, int val) {
            if (t == p) {
                z += val;
            } else {
                remove(t);
                v.set(t, v.get(t) + val);
                add(t);
            }
            return 0;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine());
        if (n == 1) {
            pw.println("0");
        } else {
            StringTokenizer st = new StringTokenizer(br.readLine());
            ArrayList<Integer> v = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                v.add(Integer.parseInt(st.nextToken()) - 1);
            }
            ArrayList<Integer> q = new ArrayList<>();
            ArrayList<Integer> qq = new ArrayList<>();
            Pair<Integer, Integer> mx = new Pair<>(0, 0);
            for (int i = 0; i < n; i++) {
                q.add(0);
                qq.add(0);
            }
            for (int i = 0; i < n; i++) {
                q.set(v.get(i), q.get(v.get(i)) + 1);
                mx = new Pair<>(Math.max(mx.first, q.get(v.get(i))), v.get(i));
            }
            int p = mx.second;
            ArrayList<ArrayList<Integer>> u = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                u.add(new ArrayList<>());
            }
            for (int i = 0; i < n; i++) {
                if (i != p) {
                    u.get(q.get(i)).add(i);
                }
            }
            ArrayList<Integer> uu = new ArrayList<>();
            for (int i = n; i >= 0; i--) {
                if (!u.get(i).isEmpty()) {
                    uu.add(i);
                }
            }
            int last = 0;
            ArrayList<ArrayList<Integer>> leftmost = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                leftmost.add(new ArrayList<>());
                for (int j = 0; j <= q.get(i); j++) {
                    leftmost.get(i).add(n + 1);
                }
            }
            int ans = 0;
            for (int y = 0; y < Math.min(n, 100); y++) {
                if (y != p) {
                    ArrayList<Integer> g = new ArrayList<>();
                    for (int i = 0; i < n; i++) {
                        if (v.get(i) == p) {
                            ans = Math.max(ans, i - g.get(g.size() - qq.get(g.size() - 1) - 1) - 1);
                            if (qq.get(g.size() - 1) > 0) {
                                qq.set(g.size() - 1, qq.get(g.size() - 1) - 1);
                            } else {
                                g.add(i);
                            }
                        } else if (v.get(i) == y) {
                            qq.set(g.size() - 1, qq.get(g.size() - 1) + 1);
                        }
                    }
                    ans = Math.max(ans, n - g.get(g.size() - qq.get(g.size() - 1) - 1) - 1);
                }
            }
            pw.println(ans);
        }
        pw.flush();
        pw.close();
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
