import java.util.*;
import java.util.stream.*;

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

    public void beep() {
        System.out.println(" const beep ( " + msg + " )\t@ " + this);
    }
}

class Main {
    public static int refill(int k, List<Tuple3<Integer, Integer, Integer>> left,
                              List<Tuple3<Integer, Integer, Integer>> right) {
        Comparator<Integer> comp = (i, j) -> (right.get(i).get1() - left.get(i).get0()) -
                (right.get(j).get1() - left.get(j).get0());

        List<Integer> idx = IntStream.range(0, left.size()).boxed().collect(Collectors.toList());
        PriorityQueue<Integer> heap = new PriorityQueue<>(comp);
        heap.addAll(idx);
        int val = 0;

        while (!heap.isEmpty() && k > 0) {
            int i = heap.poll();

            if (left.get(i).get0() < right.get(i).get1()) {
                int w = Math.min(k, left.get(i).get2());
                k -= w;
                val += w * (right.get(i).get1() - left.get(i).get0());
            }
        }
        return val;
    }

    public static int a176() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int k = scanner.nextInt();

        List<List<Tuple3<Integer, Integer, Integer>>> a = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            List<Tuple3<Integer, Integer, Integer>> list = new ArrayList<>(m);
            for (int j = 0; j < m; j++) {
                list.add(new Tuple3<>(scanner.nextInt(), scanner.nextInt(), scanner.nextInt()));
            }
            a.add(list);
        }

        int val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    val = Math.max(val, refill(k, a.get(i), a.get(j)));
                }
            }
        }

        return val;
    }

    public static void main(String[] args) {
        System.out.println(a176());
    }
}

class Tuple3<A, B, C> {
    private final A a;
    private final B b;
    private final C c;

    public Tuple3(A a, B b, C c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public A get0() {
        return a;
    }

    public B get1() {
        return b;
    }

    public C get2() {
        return c;
    }
}
