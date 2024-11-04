import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        long x = sc.nextLong();

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

        PriorityQueue<Pair<Long, Integer>> heap = new PriorityQueue<>(Comparator.comparingLong(Pair::getKey));
        int budget = 1000000;

        for (int i = 0; i < n; i++) {
            heap.add(new Pair<>(a.get(i), i));
            if (budget < heap.size() * idx.size()) {
                heap.poll();
            }
        }

        while (!heap.isEmpty()) {
            Pair<Long, Integer> pair = heap.poll();
            long val = pair.getKey();
            int i = pair.getValue();

            for (int j : idx) {
                if (j + i < n) {
                    soln[j + i] = val;
                } else {
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (soln[i] == 0) {
                for (int j : idx) {
                    if (i < j) {
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
