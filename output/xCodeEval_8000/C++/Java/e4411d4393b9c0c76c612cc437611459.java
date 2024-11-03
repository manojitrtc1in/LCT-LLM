import java.util.*;

class Main {
    public static void main(String[] args) {
        b444();
    }

    public static void b444() {
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

        List<Long> soln = new ArrayList<>(Collections.nCopies(n, 0L));

        List<Integer> idx = new ArrayList<>();
        for (int j = 0; j < n; j++) {
            if (b.get(j)) {
                idx.add(j);
            }
        }

        PriorityQueue<Pair<Long, Integer>> heap = new PriorityQueue<>(Comparator.comparing(Pair::getKey));
        int budget = 1000000;

        for (int j = 0; j < n; j++) {
            heap.add(new Pair<>(a.get(j), j));
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
                    soln.set(j + i, val);
                } else {
                    break;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (soln.get(j) == 0) {
                for (int i : idx) {
                    if (j < i) {
                        break;
                    } else {
                        soln.set(j, Math.max(soln.get(j), a.get(j - i)));
                    }
                }
            }
        }

        for (long val : soln) {
            System.out.println(val);
        }
    }
}
