import java.util.*;
import java.util.stream.*;

public class b37db49644640aadf73d2fa504b559c1_nc {
    static class Query {
        int l, r;
        double p;

        Query(int l, int r, double p) {
            this.l = l;
            this.r = r;
            this.p = p;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int m = Arrays.stream(a).max().orElse(0);

        List<Query> queries = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            int l = scanner.nextInt() - 1;
            int r = scanner.nextInt();
            double p = scanner.nextDouble();
            queries.add(new Query(l, r, p));
        }

        queries.sort(Comparator.comparingInt((Query query) -> query.r - query.l));
        queries.add(new Query(0, n, 0));

        TreeMap<Integer, Pair> cur = new TreeMap<>();

        for (Query query : queries) {
            int l = query.l;
            int r = query.r;
            double p = query.p;

            SortedMap<Integer, Pair> subMap = cur.subMap(l, r);
            List<Double> nv = new ArrayList<>(Collections.nCopies(q * 2 + 1, 1.0));
            int pv = l;

            for (Map.Entry<Integer, Pair> entry : subMap.entrySet()) {
                int key = entry.getKey();
                Pair value = entry.getValue();
                int zer = 0;

                while (pv < key) {
                    int dif = a[pv] - m + q;
                    zer = Math.max(zer, dif);
                    pv++;
                }

                for (int i = 0; i < zer; i++) {
                    nv.set(i, 0.0);
                }

                for (int i = 0; i <= q * 2; i++) {
                    nv.set(i, nv.get(i) * value.second.get(i));
                }
            }

            {
                int zer = 0;
                while (pv < r) {
                    int dif = a[pv] - m + q;
                    zer = Math.max(zer, dif);
                    pv++;
                }
                for (int i = 0; i < zer; i++) {
                    nv.set(i, 0.0);
                }
            }

            List<Double> nx = new ArrayList<>(Collections.nCopies(q * 2 + 1, 0.0));
            for (int i = 0; i <= q * 2; i++) {
                nx.set(i, nx.get(i) + (1 - p) * nv.get(i));
            }
            for (int i = 0; i < q * 2; i++) {
                nx.set(i + 1, nx.get(i + 1) + p * nv.get(i));
            }
            cur.subMap(l, r).clear();
            cur.put(l, new Pair(r, nx));
        }

        double ans = m, sum = 0;
        Map.Entry<Integer, Pair> entry = cur.firstEntry();
        int ren = entry.getValue().first;
        List<Double> top = entry.getValue().second;

        for (int i = 0; i <= q * 2; i++) {
            if (i < q) {
                assert top.get(i) < 1e-6;
            }
            ans += (i - q) * (top.get(i) - sum);
            sum = top.get(i);
        }
        assert top.get(top.size() - 1) > 1 - 1e-6;
        System.out.println(ans);
    }

    static class Pair {
        int first;
        List<Double> second;

        Pair(int first, List<Double> second) {
            this.first = first;
            this.second = second;
        }
    }
}
