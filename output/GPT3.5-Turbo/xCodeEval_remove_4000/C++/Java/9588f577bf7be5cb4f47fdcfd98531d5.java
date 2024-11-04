import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int d = in.nextInt();
        long x = in.nextLong();

        List<Long> a = new ArrayList<>();
        List<Boolean> b = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            a.add((long) i);
            b.add(false);
        }

        for (int i = 0; i < n; i++) {
            x = (x * 37 + 10007) % 1000000007;
            Collections.swap(a, i, (int) (x % (i + 1)));
        }

        for (int i = 0; i < n; i++) {
            x = (x * 37 + 10007) % 1000000007;
            boolean c = b.get(i);
            b.set(i, b.get((int) (x % (i + 1))));
            b.set((int) (x % (i + 1)), c);
        }

        long[] soln = new long[n];

        List<Integer> idx = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (b.get(i)) {
                idx.add(i);
            }
        }

        PriorityQueue<Pair<Long, Integer>> minHeap = new PriorityQueue<>(new Comparator<Pair<Long, Integer>>() {
            public int compare(Pair<Long, Integer> p1, Pair<Long, Integer> p2) {
                return Long.compare(p1.getKey(), p2.getKey());
            }
        });

        int budget = 1000000;

        for (int i = 0; i < n; i++) {
            minHeap.add(new Pair<>(a.get(i), i));
            if (budget < minHeap.size() * idx.size()) {
                minHeap.poll();
            }
        }

        PriorityQueue<Pair<Long, Integer>> heap = new PriorityQueue<>(new Comparator<Pair<Long, Integer>>() {
            public int compare(Pair<Long, Integer> p1, Pair<Long, Integer> p2) {
                return Long.compare(p2.getKey(), p1.getKey());
            }
        });

        while (!minHeap.isEmpty()) {
            heap.add(minHeap.poll());
        }

        while (!heap.isEmpty()) {
            Pair<Long, Integer> p = heap.poll();
            int i = p.getValue();
            long val = p.getKey();

            for (int j : idx) {
                if (j + i < n) {
                    soln[j + i] = Math.max(soln[j + i], val);
                } else {
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (soln[i] == 0) {
                for (int j : idx) {
                    if (j > i) {
                        break;
                    } else {
                        soln[i] = Math.max(soln[i], a.get(i - j));
                    }
                }
            }
        }

        for (long val : soln) {
            System.out.println(val);
        }
    }
}
