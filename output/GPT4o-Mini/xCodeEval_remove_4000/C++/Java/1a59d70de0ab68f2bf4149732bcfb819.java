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

class RandInt {
    private final int m;
    private final double f;

    public RandInt(int a, int b) {
        this.m = a;
        this.f = (double) (b - a) / RAND_MAX;
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
        this.f = (b - a) / RAND_MAX;
    }

    public double next() {
        return m + f * new Random().nextDouble();
    }
}

class Noisy {
    private final String msg;

    public Noisy(String str) {
        this.msg = str;
        System.out.println(" Noisy ( " + msg + " )\t@ " + this);
    }

    @Override
    protected void finalize() {
        System.out.println("~Noisy ( " + msg + " )\t@ " + this);
    }

    public void beep() {
        System.out.println(" beep ( " + msg + " )\t@ " + this);
    }

    public void beep() {
        System.out.println(" const beep ( " + msg + " )\t@ " + this);
    }
}

public class 1a59d70de0ab68f2bf4149732bcfb819xcodeeval_processed_4000.json {
    private static final int RAND_MAX = 32767;

    public static void main(String[] args) {
        System.out.println(a442());
    }

    private static int a442() {
        List<String> cards = Arrays.asList("R0", "G1", "B2"); // Example input
        int id25 = countUnique(cards, 0);
        int id21 = countUnique(cards, 1);

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

        int val = id25 + id21 - 2;

        for (int i = 0; i < (1 << 6) - 1; i++) {
            int icnt = id12(i);
            if (icnt < val) {
                for (int j = 0; j < (1 << 6) - 1; j++) {
                    int jcnt = id12(j);
                    if (icnt + jcnt < val) {
                        boolean flag = true;

                        for (Tuple a : xs) {
                            for (Tuple b : xs) {
                                if (!a.equals(b)) {
                                    boolean u = a.getFirst() == b.getFirst() || (icnt + 1 < id25 && (a.getFirst() & i) == 0 && (b.getFirst() & i) == 0);
                                    boolean v = a.getSecond() == b.getSecond() || (jcnt + 1 < id21 && (a.getSecond() & j) == 0 && (b.getSecond() & j) == 0);

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

        return val;
    }

    private static int countUnique(List<String> xs, int k) {
        Set<Character> s = new HashSet<>();
        for (String a : xs) {
            s.add(a.charAt(k));
        }
        return s.size();
    }

    private static int id12(int a) {
        int k = 0;
        while (a > 0) {
            k += a & 1;
            a >>= 1;
        }
        return k;
    }

    static class Tuple {
        private final int first;
        private final int second;

        public Tuple(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int getFirst() {
            return first;
        }

        public int getSecond() {
            return second;
        }
    }
}
