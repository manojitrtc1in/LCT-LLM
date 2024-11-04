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

public class cdc9e591d32a046deb36898e6daaf46fxcodeeval_processed_4000.json {
    private static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private static void b303() {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long m = scanner.nextLong();
        long x = scanner.nextLong();
        long y = scanner.nextLong();
        long a = scanner.nextLong();
        long b = scanner.nextLong();

        long g = gcd(a, b);
        a /= g;
        b /= g;

        long k = Math.min(m / b, n / a);
        long width = k * a;
        long height = k * b;

        long x1 = Math.max(x - (width + 1) / 2, 0);
        long x2 = Math.min(x1 + width, n);
        x1 = x2 - width;

        long y1 = Math.max(y - (height + 1) / 2, 0);
        long y2 = Math.min(y1 + height, m);
        y1 = y2 - height;

        List<Long> soln = Arrays.asList(x1, y1, x2, y2);
        System.out.println(soln.stream().map(String::valueOf).collect(Collectors.joining(" ")));
    }

    private static boolean xsolve(int w, int j, int t, int jumpSize, List<String> wall, Set<Tuple> cache) {
        int n = wall.get(0).length();
        if (!(j < n)) return true;
        else if (j < t || wall.get(w).charAt(j) != '-') return false;
        else {
            Tuple tpl = new Tuple(w, j, t);
            if (!cache.add(tpl)) return false;

            if (xsolve(1 - w, j + jumpSize, t + 1, jumpSize, wall, cache) ||
                xsolve(w, j + 1, t + 1, jumpSize, wall, cache) ||
                (j > 0 && xsolve(w, j - 1, t + 1, jumpSize, wall, cache))) {
                return true;
            }

            return false;
        }
    }

    private static String b198() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        List<String> wall = new ArrayList<>(2);
        wall.add(scanner.next());
        wall.add(scanner.next());

        Set<Tuple> cache = new HashSet<>();
        cache.add(new Tuple(0, 0, Integer.MAX_VALUE));
        cache.add(new Tuple(1, n, Integer.MAX_VALUE));

        boolean flag = xsolve(1, k, 1, k, wall, cache) || xsolve(0, 1, 1, k, wall, cache);
        return flag ? "YES" : "NO";
    }

    private static long a442() {
        Scanner scanner = new Scanner(System.in);
        List<String> xs = new ArrayList<>();
        while (scanner.hasNext()) {
            xs.add(scanner.next());
        }

        Map<Character, Set<Character>> charMap = new HashMap<>();
        Map<Character, Set<Character>> digitMap = new HashMap<>();
        for (String a : xs) {
            charMap.computeIfAbsent(a.charAt(0), k -> new HashSet<>()).add(a.charAt(1));
            digitMap.computeIfAbsent(a.charAt(1), k -> new HashSet<>()).add(a.charAt(0));
        }

        long id17 = charMap.values().stream()
                .filter(pr -> pr.stream().allMatch(ch -> digitMap.get(ch).size() == 1))
                .count();

        long id19 = digitMap.values().stream()
                .filter(pr -> pr.stream().allMatch(ch -> charMap.get(ch).size() == 1))
                .count();

        return Math.min(digitMap.size() - 1 + (id17 < charMap.size() ? charMap.size() - id17 - 1 : 0),
                         charMap.size() - 1 + (id19 < digitMap.size() ? digitMap.size() - id19 - 1 : 0));
    }

    private static long a163() {
        Scanner scanner = new Scanner(System.in);
        String subj = scanner.next();
        String targ = scanner.next();

        Map<Character, List<Integer>> pos = new HashMap<>();
        for (int j = 0; j < targ.length(); j++) {
            pos.computeIfAbsent(targ.charAt(j), k -> new ArrayList<>()).add(j);
        }

        long val = 0;
        List<Long> soln = new ArrayList<>(Collections.nCopies(targ.length() + 1, 0L));
        List<Long> id12 = new ArrayList<>(Collections.nCopies(targ.length() + 1, 0L));
        long m = 1000000007L;

        for (char a : subj.toCharArray()) {
            Collections.swap(soln, id12);
            Collections.fill(soln, 0L);

            for (int j : pos.get(a)) {
                soln.set(j + 1, (1 + id12.get(j)) % m);
            }

            for (int i = 1; i < soln.size(); i++) {
                soln.set(i, (soln.get(i) + soln.get(i - 1)) % m);
            }
            val = (val + soln.get(soln.size() - 1)) % m;
        }
        return val;
    }

    public static void main(String[] args) {
        System.out.println(a163());
    }
}

class Tuple {
    private final int w;
    private final int j;
    private final int t;

    public Tuple(int w, int j, int t) {
        this.w = w;
        this.j = j;
        this.t = t;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Tuple)) return false;
        Tuple tuple = (Tuple) o;
        return w == tuple.w && j == tuple.j && t == tuple.t;
    }

    @Override
    public int hashCode() {
        return Objects.hash(w, j, t);
    }
}
