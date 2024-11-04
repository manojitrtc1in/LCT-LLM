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

public class e4411d4393b9c0c76c612cc437611459xcodeeval_processed_4000.json {
    public static void main(String[] args) {
        c253();
    }

    private static void c253() {
        try (Scanner fin = new Scanner(new File("input.txt"));
             PrintWriter fout = new PrintWriter(new File("output.txt"))) {

            List<Integer> len = new ArrayList<>();
            while (fin.hasNextInt()) {
                len.add(fin.nextInt());
            }

            int nrow = len.size();
            Pair first = new Pair(fin.nextInt() - 1, fin.nextInt() - 1);
            Pair last = new Pair(fin.nextInt() - 1, fin.nextInt() - 1);

            if (first.equals(last)) {
                fout.println(0);
                return;
            }

            final int INF = Integer.MAX_VALUE;
            List<List<Integer>> dist = new ArrayList<>();
            for (int j = 0; j < nrow; j++) {
                dist.add(new ArrayList<>(Collections.nCopies(len.get(j) + 1, INF)));
            }

            Queue<Pair> q = new LinkedList<>();
            q.add(first);
            dist.get(first.first).set(first.second, 0);

            while (!q.isEmpty()) {
                Pair p = q.poll();
                int r = p.first;
                int c = p.second;
                int d = dist.get(r).get(c) + 1;

                if (0 < r && last.equals(touch(r - 1, c, d, len, dist, q))) break;
                if (r + 1 < nrow && last.equals(touch(r + 1, c, d, len, dist, q))) break;
                if (0 < c && last.equals(touch(r, c - 1, d, len, dist, q))) break;
                if (c < len.get(r) && last.equals(touch(r, c + 1, d, len, dist, q))) break;
            }
            fout.println(dist.get(last.first).get(last.second));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static Pair touch(int r, int c, int d, List<Integer> len, List<List<Integer>> dist, Queue<Pair> q) {
        Pair pos = new Pair(r, Math.min(c, len.get(r)));
        if (d < dist.get(r).get(pos.second)) {
            dist.get(r).set(pos.second, d);
            q.add(pos);
        }
        return pos;
    }

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair pair = (Pair) o;
            return first == pair.first && second == pair.second;
        }

        @Override
        public int hashCode() {
            return Objects.hash(first, second);
        }
    }
}
