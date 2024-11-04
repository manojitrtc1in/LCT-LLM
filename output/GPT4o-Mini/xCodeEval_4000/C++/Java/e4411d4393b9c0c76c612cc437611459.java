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

class UnionFind {
    private final int[] parent;
    private final int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];
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

public class e4411d4393b9c0c76c612cc437611459_nc {
    public static void main(String[] args) {
        b444();
    }

    private static void b444() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long x = scanner.nextLong();
        long[] a = new long[n];
        boolean[] b = new boolean[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }

        for (int i = 0; i < n; i++) {
            x = (x * 37 + 10007) % 1000000007L;
            swap(a, i, (int) (x % (i + 1)));
        }

        Arrays.fill(b, 0, (int) x, true);
        for (int i = 0; i < n; i++) {
            x = (x * 37 + 10007) % 1000000007L;
            boolean c = b[i];
            b[i] = b[(int) (x % (i + 1))];
            b[(int) (x % (i + 1))] = c;
        }

        long[] soln = new long[n];
        List<Integer> idx = new ArrayList<>();
        for (int j = 0; j < n; j++) {
            if (b[j]) {
                idx.add(j);
            }
        }

        PriorityQueue<Pair> heap = new PriorityQueue<>(Comparator.comparingLong(p -> p.first));
        final int budget = 1000000;

        for (int j = 0; j < n; j++) {
            heap.add(new Pair(a[j], j));
            if (budget < heap.size() * idx.size()) {
                heap.poll();
            }
        }

        while (!heap.isEmpty()) {
            Pair pair = heap.poll();
            int i = pair.second;
            long val = pair.first;

            for (int j : idx) {
                if (j + i < n) {
                    soln[j + i] = val;
                } else {
                    break;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (soln[j] == 0) {
                for (int i : idx) {
                    if (j < i) break;
                    soln[j] = Math.max(soln[j], a[j - i]);
                }
            }
        }

        for (long value : soln) {
            System.out.println(value);
        }
    }

    private static void swap(long[] array, int i, int j) {
        long temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    static class Pair {
        long first;
        int second;

        Pair(long first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
