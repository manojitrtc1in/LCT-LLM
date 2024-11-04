import java.util.*;
import java.util.stream.Collectors;

class ScopeTimer {
    private final long tic;
    private final String msg;

    public ScopeTimer(String msg) {
        this.tic = System.currentTimeMillis();
        this.msg = msg;
    }

    @Override
    protected void finalize() {
        long toc = System.currentTimeMillis();
        long dt = toc - tic;

        long mil = dt % 1000;
        long sec = (dt / 1000) % 60;
        long min = (dt / 60000) % 60;
        long hrs = (dt / 3600000);

        System.out.println("\n" + msg + "\n\telapsed time: ");
        if (hrs > 0) System.out.print(hrs + " hrs, ");
        if (min > 0) System.out.print(min + " min, ");
        if (sec > 0) System.out.print(sec + " sec, ");
        System.out.println(mil + " mil-sec");
    }
}

class BigInteger {
    private static final int WSIZE = 32;
    private static final long BASE = 1L << WSIZE;
    private List<Long> val;
    private boolean pos;

    // Constructor and other methods...
}

class UnionFind {
    private final List<Integer> parent;
    private final List<Integer> rank;

    public UnionFind(int n) {
        parent = new ArrayList<>(Collections.nCopies(n, 0));
        rank = new ArrayList<>(Collections.nCopies(n, 0));
        for (int j = 0; j < n; j++) {
            parent.set(j, j);
        }
    }

    public int find(int s) {
        int p = parent.get(s);
        return parent.get(p) == p ? p : (parent.set(s, find(p)));
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (rank.get(i) < rank.get(j)) {
                parent.set(i, j);
            } else {
                parent.set(j, i);
                rank.set(i, rank.get(i) + (rank.get(i) == rank.get(j) ? 1 : 0));
            }
        }
    }
}

public class dbc013aa4a34ab491cabaf67fd915737_nc {
    public static void main(String[] args) {
        System.out.println(b346());
    }

    static String b346() {
        Scanner scanner = new Scanner(System.in);
        String[] str = new String[2];
        String vir;
        str[0] = scanner.next();
        str[1] = scanner.next();
        vir = scanner.next();

        List<Map<Pair<Integer, Integer>, String>> cache = new ArrayList<>(Collections.nCopies(str[0].length(), new HashMap<>()));

        String val = revmatch(0, 0, 0, str, vir, cache);
        return val.isEmpty() ? "0" : val;
    }

    static String revmatch(int i, int j, int offset, String[] str, String vir, List<Map<Pair<Integer, Integer>, String>> cache) {
        if (i == str[0].length() || j == str[1].length() || offset == vir.length()) {
            return "";
        }

        Pair<Integer, Integer> pr = new Pair<>(j, offset);
        Map<Pair<Integer, Integer>, String> iter = cache.get(i);
        if (iter.containsKey(pr)) {
            return iter.get(pr);
        }

        if (str[0].charAt(i) != str[1].charAt(j)) {
            String a = revmatch(i + 1, j, offset, str, vir, cache);
            String b = revmatch(i, j + 1, offset, str, vir, cache);
            return cache.get(i).put(pr, a.length() < b.length() ? b : a);
        } else {
            String b = revmatch(i + 1, j, offset, str, vir, cache);
            String c = revmatch(i, j + 1, offset, str, vir, cache);
            String d = b.length() < c.length() ? c : b;

            char chr = str[0].charAt(i);
            String a = chr == vir.charAt(offset)
                    ? chr + revmatch(i + 1, j + 1, offset + 1, str, vir, cache)
                    : chr + revmatch(i + 1, j + 1, chr == vir.charAt(0) ? 1 : 0, str, vir, cache);

            boolean fail = a.length() < d.length() || startswith(a, vir.substring(offset)) || startswith(a, vir);
            return cache.get(i).put(pr, fail ? d : a);
        }
    }

    static boolean startswith(String a, String b) {
        if (a.length() < b.length()) return false;
        return a.startsWith(b);
    }
}
