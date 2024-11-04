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

        List<Triple<Integer, Integer, Double>> itrv = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            int l = scanner.nextInt() - 1;
            int r = scanner.nextInt();
            double p = scanner.nextDouble();
            itrv.add(new Triple<>(l, r, p));
        }
        itrv.sort(Comparator.comparingInt(i -> i.second - i.first));
        itrv.add(new Triple<>(0, n, 0.0));

        TreeMap<Integer, Pair<Integer, List<Double>>> cur = new TreeMap<>();

        for (Triple<Integer, Integer, Double> triple : itrv) {
            int l = triple.first;
            int r = triple.second;
            double p = triple.third;

            Map.Entry<Integer, Pair<Integer, List<Double>>> be = cur.lowerEntry(l);
            Map.Entry<Integer, Pair<Integer, List<Double>>> en = cur.lowerEntry(r);

            List<Double> nv = new ArrayList<>(Collections.nCopies(q * 2 + 1, 1.0));
            int pv = l;
            for (Map.Entry<Integer, Pair<Integer, List<Double>>> entry : cur.subMap(l, r).entrySet()) {
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
            cur.subMap(l, r).clear();
            cur.put(l, new Pair<>(r, nx));
        }

        double ans = m;
        double sum = 0.0;
        Map.Entry<Integer, Pair<Integer, List<Double>>> entry = cur.firstEntry();
        assert entry.getKey() == 0;
        Pair<Integer, List<Double>> top = entry.getValue();
        assert top.first == n;
        for (int i = 0; i <= q * 2; i++) {
            if (i < q) {
                assert top.second.get(i) < 1e-6;
            }
            ans += (i - q) * (top.second.get(i) - sum);
            sum = top.second.get(i);
        }
        assert top.second.get(top.second.size() - 1) > 1 - 1e-6;
        System.out.println(ans);
    }

    static class Triple<F, S, T> {
        F first;
        S second;
        T third;

        Triple(F first, S second, T third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

    static class Pair<F, S> {
        F first;
        S second;

        Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    }
}
