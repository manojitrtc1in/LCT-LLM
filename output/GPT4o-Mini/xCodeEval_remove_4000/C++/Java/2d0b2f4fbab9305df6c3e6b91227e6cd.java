import java.util.*;
import java.util.stream.Collectors;

class Main {
    static class Tuple {
        int first, second, third;

        Tuple(int first, int second, int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

    static class Heap {
        private List<Integer> heap;
        private Comparator<Integer> comparator;

        Heap(Comparator<Integer> comparator) {
            this.heap = new ArrayList<>();
            this.comparator = comparator;
        }

        void push(int value) {
            heap.add(value);
            siftUp(heap.size() - 1);
        }

        int pop() {
            if (heap.isEmpty()) return -1;
            int value = heap.get(0);
            heap.set(0, heap.get(heap.size() - 1));
            heap.remove(heap.size() - 1);
            siftDown(0);
            return value;
        }

        boolean isEmpty() {
            return heap.isEmpty();
        }

        private void siftUp(int index) {
            while (index > 0) {
                int parent = (index - 1) / 2;
                if (comparator.compare(heap.get(index), heap.get(parent)) >= 0) break;
                Collections.swap(heap, index, parent);
                index = parent;
            }
        }

        private void siftDown(int index) {
            int size = heap.size();
            while (index < size) {
                int left = 2 * index + 1;
                int right = 2 * index + 2;
                int smallest = index;

                if (left < size && comparator.compare(heap.get(left), heap.get(smallest)) < 0) {
                    smallest = left;
                }
                if (right < size && comparator.compare(heap.get(right), heap.get(smallest)) < 0) {
                    smallest = right;
                }
                if (smallest == index) break;
                Collections.swap(heap, index, smallest);
                index = smallest;
            }
        }
    }

    static int refill(int k, List<Tuple> left, List<Tuple> right) {
        Comparator<Integer> comp = (i, j) -> (right.get(i).second - left.get(i).first) - (right.get(j).second - left.get(j).first);
        List<Integer> idx = new ArrayList<>();
        for (int i = 0; i < left.size(); i++) idx.add(i);
        Heap heap = new Heap(comp);
        for (int i : idx) heap.push(i);

        int val = 0;
        while (!heap.isEmpty() && k > 0) {
            int i = heap.pop();
            if (left.get(i).first < right.get(i).second) {
                int w = Math.min(k, left.get(i).third);
                k -= w;
                val += w * (right.get(i).second - left.get(i).first);
            }
        }
        return val;
    }

    static int a176() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int k = scanner.nextInt();
        List<List<Tuple>> a = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            List<Tuple> tuples = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                String str = scanner.next();
                int first = scanner.nextInt();
                int second = scanner.nextInt();
                int third = scanner.nextInt();
                tuples.add(new Tuple(first, second, third));
            }
            a.add(tuples);
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
