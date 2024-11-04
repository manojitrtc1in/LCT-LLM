import java.util.*;
import java.io.*;

class BigInteger {
    private List<Long> val;
    private boolean pos;
    private static final int WSIZE = 32;
    private static final long BASE = 1L << WSIZE;

    public BigInteger() {
        this.val = new ArrayList<>();
        this.pos = true;
    }
}

class ScopeTimer {
    private long tic;
    private String msg;

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

class Main {
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

        List<Map<Pair<Integer, Integer>, String>> cache = new ArrayList<>(str[0].length());
        for (int i = 0; i < str[0].length(); i++) {
            cache.add(new HashMap<>());
        }

        String val = id28(0, 0, 0, str, vir, cache);
        return val.isEmpty() ? "0" : val;
    }

    static String id28(int i, int j, int offset, String[] str, String vir, List<Map<Pair<Integer, Integer>, String>> cache) {
        if (i == str[0].length() || j == str[1].length() || offset == vir.length()) {
            return "";
        }

        Pair<Integer, Integer> pr = new Pair<>(j, offset);
        Map<Pair<Integer, Integer>, String> iter = cache.get(i);
        if (iter.containsKey(pr)) {
            return iter.get(pr);
        }

        if (str[0].charAt(i) != str[1].charAt(j)) {
            String a = id28(i + 1, j, offset, str, vir, cache);
            String b = id28(i, j + 1, offset, str, vir, cache);
            return cache.get(i).put(pr, a.length() < b.length() ? b : a);
        } else {
            String b = id28(i + 1, j, offset, str, vir, cache);
            String c = id28(i, j + 1, offset, str, vir, cache);
            String d = b.length() < c.length() ? c : b;

            char chr = str[0].charAt(i);
            String a = chr == vir.charAt(offset)
                    ? chr + id28(i + 1, j + 1, offset + 1, str, vir, cache)
                    : chr + id28(i + 1, j + 1, chr == vir.charAt(0) ? 1 : 0, str, vir, cache);

            boolean fail = a.length() < d.length() || startswith(a, vir);
            return cache.get(i).put(pr, fail ? d : a);
        }
    }

    static boolean startswith(String a, String b) {
        if (a.length() < b.length()) return false;
        for (int i = 0; i < b.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) return false;
        }
        return true;
    }
}
