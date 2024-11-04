import java.util.*;
import java.util.stream.*;

public class 4e433870ef74e6e16ba7cc37fac67dc3xcodeeval_processed_4000.json {
    static final String eol = "\n";

    public static void main(String[] args) {
        iterateMain();
    }

    static void iterateMain() {
        for (int total = caseNumber(), counter = 1; counter <= total; counter++) {
            try {
                main();
            } catch (NullPointerException ignored) {
            }
        }
    }

    static int caseNumber() {
        return 1;
    }

    static void main() {
        Scanner cin = new Scanner(System.in);
        long n = cin.nextLong();
        long k = cin.nextLong();
        List<Long> c = new ArrayList<>();
        List<Long> pf = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            long v = cin.nextLong();
            if (v < 0) {
                c.add(-v);
            } else {
                pf.add(v);
            }
        }

        pf.sort(Comparator.reverseOrder());
        long ini = 0;
        long base = 0;
        for (long e : pf) {
            base += ini;
            ini += e;
        }

        c.sort(Comparator.reverseOrder());

        if (k == 0) {
            for (long e : reverse(c)) {
                base += ini;
                ini -= e;
            }
            System.out.print(base + eol);
            return;
        }

        long[] cs = new long[c.size() + 1];
        for (int i = 0; i < c.size(); i++) {
            cs[i + 1] = cs[i] + (i / (k + 1)) * c.get(i);
        }

        long[] sf = new long[c.size() + 1];
        long[] sf2 = new long[c.size() + 1];
        for (int i = c.size(); i-- > 0; ) {
            sf[i] = sf[i + 1] + c.get(i);
            sf2[i] = sf2[i + 1] + c.get(i) * i;
        }
        Collections.reverse(Arrays.asList(sf));

        long ans = Long.MIN_VALUE;
        for (int j = 0; j <= c.size(); j++) {
            if (j * (k + 1) < c.size()) continue;
            long cd = ceilDiv(c.size() - j, k);
            long tp = j - cd;
            long now = ini * j;
            now -= sf2[c.size() - (int) tp] + sf[(int) tp] * (cd - (c.size() - tp));
            now -= cs[c.size() - (int) tp];
            ans = Math.max(ans, now);
        }

        ans += base;
        System.out.print(ans + eol);
    }

    static long ceilDiv(long x, long y) {
        if (y == 0) throw new IllegalArgumentException("Division by zero");
        return (x + y - 1) / y;
    }

    static List<Long> reverse(List<Long> list) {
        List<Long> reversed = new ArrayList<>(list);
        Collections.reverse(reversed);
        return reversed;
    }
}
