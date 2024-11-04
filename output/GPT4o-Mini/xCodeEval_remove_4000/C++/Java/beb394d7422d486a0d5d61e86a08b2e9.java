import java.util.*;
import java.util.stream.*;

class Main {
    static int p = 998244353;
    static List<List<Integer>> policy;

    static class Statistic {
        int[][] p = new int[2][2];
        int l, r;

        Statistic(int pr, int pos) {
            p[0][0] = 1 - pr;
            p[1][1] = pr;
            l = r = pos;
        }

        void merge(Statistic a, Statistic b) {
            l = a.l;
            r = b.r;
            int m = a.r;
            for (int i = 0; i <= 1; i++) {
                for (int j = 0; j <= 1; j++) {
                    p[i][j] = 0;
                    for (int k = 0; k <= 1; k++) {
                        for (int l = 0; l <= 1; l++) {
                            if (k == 0 && l == 1 && policy.get(m).get(3) == 1)
                                p[i][j] += a.p[i][k] * b.p[l][j];
                            else if (k == 0 && l == 0 && policy.get(m).get(0) == 1)
                                p[i][j] += a.p[i][k] * b.p[l][j];
                            else if (k == 1 && l == 1 && policy.get(m).get(1) == 1)
                                p[i][j] += a.p[i][k] * b.p[l][j];
                            else if (k == 1 && l == 0 && policy.get(m).get(2) == 1)
                                p[i][j] += a.p[i][k] * b.p[l][j];
                        }
                    }
                }
            }
        }

        int ans() {
            int tmp = 0;
            for (int i = 0; i <= 1; i++) {
                for (int j = 0; j <= 1; j++) {
                    tmp += p[i][j];
                }
            }
            return tmp;
        }
    }

    static class Col implements Comparable<Col> {
        int i, tp;
        int t1, t2;

        int ans() {
            return t1 / t2;
        }

        @Override
        public int compareTo(Col other) {
            return Long.compare((long) t1 * other.t2, (long) other.t1 * t2);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        policy = new ArrayList<>(n - 1);
        for (int i = 0; i < n - 1; i++) {
            policy.add(new ArrayList<>(Arrays.asList(1, 1, 1, 1)));
        }

        List<Statistic> s = new ArrayList<>();
        int[] x = new int[n], v = new int[n], p = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
            v[i] = scanner.nextInt();
            p[i] = scanner.nextInt();
            s.add(new Statistic(p[i] / 100, i));
        }

        long ans = 0;
        List<Col> cols = new ArrayList<>();
        for (int i = 0; i < n - 2; i++) {
            Col tmp = new Col();
            tmp.i = i;
            tmp.t1 = x[i + 1] - x[i];
            tmp.tp = 2;
            tmp.t2 = v[i] + v[i + 1];
            cols.add(tmp);

            if (v[i] > v[i + 1]) {
                tmp.tp = 1;
                tmp.t2 = v[i] - v[i + 1];
                cols.add(tmp);
            }
            if (v[i] < v[i + 1]) {
                tmp.tp = 0;
                tmp.t2 = v[i + 1] - v[i];
                cols.add(tmp);
            }
        }

        Collections.sort(cols);
        for (Col c : cols) {
            List<Integer> old = new ArrayList<>(policy.get(c.i));
            Collections.fill(policy.get(c.i), 0);
            policy.get(c.i).set(c.tp, 1);
            ans += s.get(c.i).ans() * c.ans();
            policy.set(c.i, old);
            policy.get(c.i).set(c.tp, 0);
            if (s.get(c.i).ans() == 0)
                break;
        }

        System.out.println(ans);
    }
}
