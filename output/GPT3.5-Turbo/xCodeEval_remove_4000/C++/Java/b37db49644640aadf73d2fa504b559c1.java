import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int q = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int m = Arrays.stream(a).max().getAsInt();

        List<Tuple<Integer, Integer, Double>> itrv = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            int l = scanner.nextInt() - 1;
            int r = scanner.nextInt();
            double p = scanner.nextDouble();
            itrv.add(new Tuple<>(l, r, p));
        }
        itrv.sort(Comparator.comparingInt(i -> i.second - i.first));
        itrv.add(new Tuple<>(0, n, 0.0));

        Map<Integer, Pair<Integer, List<Double>>> cur = new HashMap<>();

        for (Tuple<Integer, Integer, Double> tuple : itrv) {
            int l = tuple.first;
            int r = tuple.second;
            double p = tuple.third;

            Map.Entry<Integer, Pair<Integer, List<Double>>> be = cur.floorEntry(l);
            Map.Entry<Integer, Pair<Integer, List<Double>>> en = cur.floorEntry(r);

            List<Double> nv = new ArrayList<>(Collections.nCopies(q * 2 + 1, 1.0));
            int pv = l;
            for (Map.Entry<Integer, Pair<Integer, List<Double>>> entry : cur.subMap(be.getKey(), en.getKey()).entrySet()) {
                int zer = 0;
                while (pv < entry.getKey()) {
                    int dif = a[pv] - m + q;
                    if (dif > zer) {
                        zer = dif;
                    }
                    pv++;
                }
                for (int i = 0; i < zer; i++) {
                    nv.set(i, 0.0);
                }
                List<Double> tmp = entry.getValue().second;
                for (int i = 0; i <= q * 2; i++) {
                    nv.set(i, nv.get(i) * tmp.get(i));
                }
            }

            int zer = 0;
            while (pv < r) {
                int dif = a[pv] - m + q;
                if (dif > zer) {
                    zer = dif;
                }
                pv++;
            }
            for (int i = 0; i < zer; i++) {
                nv.set(i, 0.0);
            }

            List<Double> nx = new ArrayList<>(Collections.nCopies(q * 2 + 1, 0.0));
            for (int i = 0; i <= q * 2; i++) {
                nx.set(i, nx.get(i) + (1 - p) * nv.get(i));
            }
            for (int i = 0; i < q * 2; i++) {
                nx.set(i + 1, nx.get(i + 1) + p * nv.get(i));
            }
            cur.subMap(be.getKey(), en.getKey()).clear();
            cur.put(l, new Pair<>(r, nx));
        }

        double ans = m;
        double sum = 0;
        Map.Entry<Integer, Pair<Integer, List<Double>>> entry = cur.firstEntry();
        int ren = entry.getValue().first;
        List<Double> top = entry.getValue().second;
        assert ren == n;
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

    static class Tuple<A, B, C> {
        A first;
        B second;
        C third;

        Tuple(A first, B second, C third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

    static class Pair<A, B> {
        A first;
        B second;

        Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }
}
