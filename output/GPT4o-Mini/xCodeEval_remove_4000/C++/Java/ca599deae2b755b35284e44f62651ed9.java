import java.util.*;
import java.io.*;

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

class BigInteger {
    private static final int WSIZE = 32;
    private static final long BASE = 1L << WSIZE;
    private List<Long> val;
    private boolean pos;

    public BigInteger() {
        this.val = new ArrayList<>();
        this.pos = true;
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

    public void beepConst() {
        System.out.println(" const beep ( " + msg + " )\t@ " + this);
    }
}

public class ca599deae2b755b35284e44f62651ed9xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        String str;
        int n;
        Scanner scanner = new Scanner(System.in);
        str = scanner.next();
        n = scanner.nextInt();

        int[][] soln = new int[2][n + 1];
        int[][] id12 = new int[2][n + 1];

        if (str.charAt(str.length() - 1) == 'F') {
            for (int j = 0; j < n + 1; j++) {
                soln[0][j] = j % 2 == 0 ? 1 : 0;
            }
        } else {
            for (int j = 0; j < n + 1; j++) {
                soln[0][j] = j % 2 == 0 ? 0 : 1;
            }
        }

        System.arraycopy(soln[0], 0, soln[1], 0, soln[0].length);

        for (int iter = str.length() - 2; iter >= 0; iter--) {
            System.arraycopy(soln, 0, id12, 0, soln.length);
            if (str.charAt(iter) == 'F') {
                soln[0][0] = 1 + id12[0][0];
                soln[1][0] = 1 + id12[1][0];

                for (int j = 1; j < n + 1; j++) {
                    soln[0][j] = Math.max(1 + id12[0][j], -id12[1][j - 1]);
                    soln[1][j] = Math.min(1 + id12[1][j], -id12[0][j - 1]);
                }
            } else {
                soln[0][0] = -id12[1][0];
                soln[1][0] = -id12[0][0];

                for (int j = 1; j < n + 1; j++) {
                    soln[0][j] = Math.max(-id12[1][j], 1 + id12[0][j - 1]);
                    soln[1][j] = Math.min(-id12[0][j], 1 + id12[1][j - 1]);
                }
            }
        }

        System.out.println(Math.max(soln[0][n], -soln[1][n]));
    }
}
