import java.util.*;
import java.io.*;

class Main {
    public static int refill(int k, List<Tuple<Integer, Integer, Integer>> left, List<Tuple<Integer, Integer, Integer>> right) {
        Comparator<Integer> comp = (i, j) -> right.get(i).getSecond() - left.get(i).getFirst() < right.get(j).getSecond() - left.get(j).getFirst();
        PriorityQueue<Integer> heap = new PriorityQueue<>(comp);
        int val = 0;

        for (int i = 0; i < left.size(); i++) {
            heap.add(i);
        }

        while (!heap.isEmpty() && k > 0) {
            int i = heap.poll();

            if (left.get(i).getFirst() < right.get(i).getSecond()) {
                int w = Math.min(k, left.get(i).getThird());
                k -= w;
                val += w * (right.get(i).getSecond() - left.get(i).getFirst());
            }
        }

        return val;
    }

    public static int a176() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int k = scanner.nextInt();

        List<List<Tuple<Integer, Integer, Integer>>> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String str = scanner.next();
            List<Tuple<Integer, Integer, Integer>> row = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                int x = scanner.nextInt();
                int y = scanner.nextInt();
                int z = scanner.nextInt();
                row.add(new Tuple<>(x, y, z));
            }
            a.add(row);
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

class Tuple<X, Y, Z> {
    private final X first;
    private final Y second;
    private final Z third;

    public Tuple(X first, Y second, Z third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }

    public X getFirst() {
        return first;
    }

    public Y getSecond() {
        return second;
    }

    public Z getThird() {
        return third;
    }
}
