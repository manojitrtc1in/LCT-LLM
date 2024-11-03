import java.util.*;

class Main {
    public static void main(String[] args) {
        b444();
    }

    static void b444() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        long x = scanner.nextLong();

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

        PriorityQueue<Pair<Long, Integer>> minHeap = new PriorityQueue<>(Comparator.comparing(Pair::getKey));
        int budget = 1000000;

        for (int i = 0; i < n; i++) {
            minHeap.add(new Pair<>(a.get(i), i));
            if (budget < minHeap.size() * idx.size()) {
                minHeap.poll();
            }
        }

        PriorityQueue<Pair<Long, Integer>> heap = new PriorityQueue<>(Comparator.comparing(Pair::getKey));
        while (!minHeap.isEmpty()) {
            heap.add(minHeap.poll());
        }

        while (!heap.isEmpty()) {
            Pair<Long, Integer> pair = heap.poll();
            long val = pair.getKey();
            int i = pair.getValue();

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
                    if (j < i) {
                        break;
                    } else {
                        soln[j] = Math.max(soln[j], a.get(j - i));
                    }
                }
            }
        }

        for (long val : soln) {
            System.out.println(val);
        }
    }
}
