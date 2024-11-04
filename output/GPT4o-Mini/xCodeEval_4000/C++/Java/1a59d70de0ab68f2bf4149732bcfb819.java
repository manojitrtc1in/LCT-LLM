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
    protected void finalize() throws Throwable {
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

class RandInt {
    private final int m;
    private final double f;

    public RandInt(int a, int b) {
        this.m = a;
        this.f = (double) (b - a) / Integer.MAX_VALUE;
    }

    public int next() {
        return m + (int) Math.ceil(f * new Random().nextInt());
    }
}

class RandDouble {
    private final double m;
    private final double f;

    public RandDouble(double a, double b) {
        this.m = a;
        this.f = (b - a) / Integer.MAX_VALUE;
    }

    public double next() {
        return m + f * new Random().nextInt();
    }
}

class Noisy {
    private final String msg;

    public Noisy(String str) {
        this.msg = str;
        System.out.println(" Noisy ( " + msg + " )\t@ " + this);
    }

    @Override
    protected void finalize() throws Throwable {
        System.out.println("~Noisy ( " + msg + " )\t@ " + this);
    }

    public void beep() {
        System.out.println(" beep ( " + msg + " )\t@ " + this);
    }

    public void beep() {
        System.out.println(" const beep ( " + msg + " )\t@ " + this);
    }
}

class UnionFind {
    private final int[] parent;
    private final int[] rank;

    public UnionFind(int n) {
        this.parent = new int[n];
        this.rank = new int[n];
        for (int j = 0; j < n; j++) {
            parent[j] = j;
        }
    }

    public int find(int s) {
        int p = parent[s];
        return parent[p] == p ? p : (parent[s] = find(p));
    }

    public void lazyUnion(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (rank[i] < rank[j]) {
                parent[i] = j;
            } else {
                parent[j] = i;
                rank[i] += rank[i] == rank[j] ? 1 : 0;
            }
        }
    }
}

public class 1a59d70de0ab68f2bf4149732bcfb819_nc {
    public static void main(String[] args) {
        System.out.println(a442());
    }

    private static int a442() {
        Scanner scanner = new Scanner(System.in);
        List<String> cards = Arrays.asList(scanner.nextLine().split(" "));

        long cntUnqChar = countUnique(cards, 0);
        long cntUnqDigit = countUnique(cards, 1);

        Map<Character, Integer> charMap = new HashMap<>();
        charMap.put('R', 0);
        charMap.put('G', 1);
        charMap.put('B', 2);
        charMap.put('Y', 3);
        charMap.put('W', 4);

        List<Tuple> xs = new ArrayList<>();
        for (String a : cards) {
            xs.add(new Tuple(1 << charMap.get(a.charAt(0)), 1 << (a.charAt(1) - '0')));
        }

        long val = cntUnqChar + cntUnqDigit - 2;

        for (int i = 0; i < (1 << 6) - 1; i++) {
            long icnt = countBars(i);
            if (icnt < val) {
                for (int j = 0; j < (1 << 6) - 1; j++) {
                    long jcnt = countBars(j);
                    if (icnt + jcnt < val) {
                        boolean flag = true;

                        for (Tuple a : xs) {
                            for (Tuple b : xs) {
                                if (!a.equals(b)) {
                                    boolean u = a.first == b.first || (icnt + 1 < cntUnqChar && (a.first & i) == 0 && (b.first & i) == 0);
                                    boolean v = a.second == b.second || (jcnt + 1 < cntUnqDigit && (a.second & j) == 0 && (b.second & j) == 0);
                                    if (v && u) {
                                        flag = false;
                                        break;
                                    }
                                }
                            }
                        }
                        if (flag) {
                            val = icnt + jcnt;
                        }
                    }
                }
            }
        }

        return (int) val;
    }

    private static long countUnique(List<String> xs, int k) {
        Set<Character> s = new HashSet<>();
        for (String a : xs) {
            s.add(a.charAt(k));
        }
        return s.size();
    }

    private static long countBars(long a) {
        long k = 0;
        while (a > 0) {
            k += a & 1;
            a >>= 1;
        }
        return k;
    }

    static class Tuple {
        int first;
        int second;

        Tuple(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
