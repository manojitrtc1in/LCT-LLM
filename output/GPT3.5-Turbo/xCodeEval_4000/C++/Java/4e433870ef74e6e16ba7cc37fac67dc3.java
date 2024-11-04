import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        List<Integer> c = new ArrayList<>();
        List<Integer> pf = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int v = sc.nextInt();
            if (v < 0) {
                c.add(-v);
            } else {
                pf.add(v);
            }
        }

        Collections.sort(pf, Collections.reverseOrder());
        long ini = 0;
        long base = 0;
        for (int e : pf) {
            base += ini;
            ini += e;
        }
        Collections.sort(c, Collections.reverseOrder());

        if (k == 0) {
            for (int e : c) {
                base += ini;
                ini -= e;
            }
            System.out.println(base);
            return;
        }

        long[] cs = new long[c.size() + 1];
        for (int i = 0; i < c.size(); i++) {
            cs[i + 1] = cs[i] + (i / (k + 1) * c.get(i));
        }
        long[] sf = new long[c.size() + 1];
        long[] sf2 = new long[c.size() + 1];
        for (int i = c.size() - 1; i >= 0; i--) {
            sf[i] = sf[i + 1] + c.get(i);
            sf2[i] = sf2[i + 1] + c.get(i) * i;
        }

        long ans = -1e18;
        for (int j = 0; j <= c.size(); j++) {
            if (j * (k + 1) < c.size()) continue;
            int cd = (int) Math.ceil((c.size() - j) / (double) k);
            int tp = j - cd;
            long now = ini * j;
            now -= sf2[c.size() - tp] + sf[tp] * (cd - (c.size() - tp));
            now -= cs[c.size() - tp];
            ans = Math.max(ans, now);
        }

        ans += base;
        System.out.println(ans);
    }
}
