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
    protected void finalize() {
        System.out.println("~Noisy ( " + msg + " )\t@ " + this);
    }

    public void beep() {
        System.out.println(" beep ( " + msg + " )\t@ " + this);
    }

    public void beepConst() {
        System.out.println(" const beep ( " + msg + " )\t@ " + this);
    }
}

class Main {
    public static void main(String[] args) {
        b444();
    }

    static void b444() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        long x = scanner.nextLong();

        long[] a = new long[n];
        boolean[] b = new boolean[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }

        for (int i = 0; i < n; i++) {
            x = (x * 37 + 10007) % 1000000007L;
            long temp = a[i];
            a[i] = a[(int) (x % (i + 1))];
            a[(int) (x % (i + 1))] = temp;
        }

        Arrays.fill(b, 0, d, true);
        for (int i = 0; i < n; i++) {
            x = (x * 37 + 10007) % 1000000007L;
            boolean temp = b[i];
            b[i] = b[(int) (x % (i + 1))];
            b[(int) (x % (i + 1))] = temp;
        }

        long[] soln = new long[n];
        List<Integer> idx = new ArrayList<>();
        for (int j = 0; j < n; j++) {
            if (b[j]) {
                idx.add(j);
            }
        }

        PriorityQueue<Pair<Long, Integer>> minHeap = new PriorityQueue<>(Comparator.comparingLong(Pair::getKey));
        final int budget = 1000000;

        for (int j = 0; j < n; j++) {
            minHeap.add(new Pair<>(a[j], j));
            if (budget < minHeap.size() * idx.size()) {
                minHeap.poll();
            }
        }

        PriorityQueue<Pair<Long, Integer>> heap = new PriorityQueue<>(Comparator.comparingLong(Pair::getKey));
        while (!minHeap.isEmpty()) {
            heap.add(minHeap.poll());
        }

        while (!heap.isEmpty()) {
            Pair<Long, Integer> front = heap.poll();
            int i = front.getValue();
            long val = front.getKey();

            for (int j : idx) {
                if (j + i < n) {
                    soln[j + i] = Math.max(soln[j + i], val);
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
}

class Pair<K, V> {
    private final K key;
    private final V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}
