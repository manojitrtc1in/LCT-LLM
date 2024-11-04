import java.util.*;
import java.util.stream.Collectors;

public class cdc9e591d32a046deb36898e6daaf46f_nc {
    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static void b303() {
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

    static boolean xsolve(size_t w, size_t j, size_t t, size_t jump_size, List<String> wall, Set<Triple<size_t, size_t, size_t>> cache) {
        size_t n = wall.get(0).length();
        if (!(j < n)) return true;
        else if (j < t || wall.get(w).charAt(j) != '-') return false;
        else {
            Triple<size_t, size_t, size_t> tpl = new Triple<>(w, j, t);
            // Debugging output can be added here

            if (!cache.add(tpl)) return false;

            if (xsolve(1 - w, j + jump_size, t + 1, jump_size, wall, cache) ||
                xsolve(w, j + 1, t + 1, jump_size, wall, cache) ||
                (j > 0 && xsolve(w, j - 1, t + 1, jump_size, wall, cache))) {
                return true;
            }

            return false;
        }
    }

    static String b198() {
        Scanner scanner = new Scanner(System.in);
        size_t n = scanner.nextLong();
        size_t k = scanner.nextLong();
        List<String> wall = new ArrayList<>(2);
        wall.add(scanner.next());
        wall.add(scanner.next());

        Set<Triple<size_t, size_t, size_t>> cache = new HashSet<>();
        cache.add(new Triple<>(0, 0, Long.MAX_VALUE));
        cache.add(new Triple<>(1, n, Long.MAX_VALUE));

        boolean flag = xsolve(1, k, 1, k, wall, cache) || xsolve(0, 1, 1, k, wall, cache);

        return flag ? "YES" : "NO";
    }

    static size_t a442() {
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

        // Debugging output can be added here

        long digitOwn = charMap.entrySet().stream().filter(pr -> pr.getValue().stream().allMatch(ch -> digitMap.get(ch).size() == 1)).count();
        long charOwn = digitMap.entrySet().stream().filter(pr -> pr.getValue().stream().allMatch(ch -> charMap.get(ch).size() == 1)).count();

        return Math.min(digitMap.size() - 1 + (digitOwn < charMap.size() ? charMap.size() - digitOwn - 1 : 0),
                        charMap.size() - 1 + (charOwn < digitMap.size() ? digitMap.size() - charOwn - 1 : 0));
    }

    static long a163() {
        Scanner scanner = new Scanner(System.in);
        String subj = scanner.next();
        String targ = scanner.next();

        Map<Character, List<Integer>> pos = new HashMap<>();
        for (int j = 0; j < targ.length(); j++) {
            pos.computeIfAbsent(targ.charAt(j), k -> new ArrayList<>()).add(j);
        }

        long val = 0;
        List<Long> soln = new ArrayList<>(Collections.nCopies(targ.length() + 1, 0L));
        List<Long> xsoln = new ArrayList<>(Collections.nCopies(targ.length() + 1, 0L));
        long m = 1000000007;

        for (char a : subj.toCharArray()) {
            Collections.swap(soln, xsoln);
            Collections.fill(soln, 0L);

            for (int j : pos.get(a)) {
                soln.set(j + 1, (1 + xsoln.get(j)) % m);
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

class Triple<A, B, C> {
    public final A first;
    public final B second;
    public final C third;

    public Triple(A first, B second, C third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }
}
