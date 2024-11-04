import java.util.*;
import java.util.stream.*;

public class b37db49644640aadf73d2fa504b559c1xcodeeval_processed_4000.json {
    static final double EPS = 1e-6;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int m = Arrays.stream(a).max().getAsInt();

        List<Tuple> itrv = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            int l = scanner.nextInt() - 1;
            int r = scanner.nextInt();
            double p = scanner.nextDouble();
            itrv.add(new Tuple(l, r, p));
        }
        itrv.sort(Comparator.comparingInt((Tuple t) -> t.r - t.l));
        itrv.add(new Tuple(0, n, 0.0));

        TreeMap<Integer, Pair> cur = new TreeMap<>();

        for (Tuple t : itrv) {
            int l = t.l, r = t.r;
            double p = t.p;

            Map.Entry<Integer, Pair> be = cur.lowerEntry(l);
            Map.Entry<Integer, Pair> en = cur.lowerEntry(r);

            double[] nv = new double[q * 2 + 1];
            Arrays.fill(nv, 1.0);
            int pv = l;

            for (Map.Entry<Integer, Pair> itr = be; itr != null && itr.getKey() < r; itr = cur.higherEntry(itr.getKey())) {
                int zer = 0;
                while (pv < itr.getKey()) {
                    int dif = a[pv] - m + q;
                    zer = Math.max(zer, dif);
                    pv++;
                }
                Arrays.fill(nv, 0, zer, 0);
                double[] tmp = itr.getValue().second;
                for (int i = 0; i <= q * 2; i++) {
                    nv[i] *= tmp[i];
                }
            }

            {
                int zer = 0;
                while (pv < r) {
                    int dif = a[pv] - m + q;
                    zer = Math.max(zer, dif);
                    pv++;
                }
                Arrays.fill(nv, 0, zer, 0);
            }

            double[] nx = new double[q * 2 + 1];
            for (int i = 0; i <= q * 2; i++) {
                nx[i] += (1 - p) * nv[i];
            }
            for (int i = 0; i < q * 2; i++) {
                nx[i + 1] += p * nv[i];
            }
            cur.subMap(be.getKey(), en.getKey()).clear();
            cur.put(l, new Pair(r, nx));
        }

        double ans = m, sum = 0;
        assert cur.firstKey() == 0;
        Pair firstPair = cur.firstEntry().getValue();
        assert firstPair.first == n;
        double[] top = firstPair.second;

        for (int i = 0; i <= q * 2; i++) {
            if (i < q) assert top[i] < EPS;
            ans += (i - q) * (top[i] - sum);
            sum = top[i];
        }
        assert top[top.length - 1] > 1 - EPS;
        System.out.println(ans);
    }

    static class Tuple {
        int l, r;
        double p;

        Tuple(int l, int r, double p) {
            this.l = l;
            this.r = r;
            this.p = p;
        }
    }

    static class Pair {
        int first;
        double[] second;

        Pair(int first, double[] second) {
            this.first = first;
            this.second = second;
        }
    }
}
