import java.util.*;
import java.util.stream.Collectors;

class Geometry2D {
    static class Id6 {
        long x, y;

        Id6(long x, long y) {
            this.x = x;
            this.y = y;
        }

        static double angle(Id6 a) {
            return Math.atan2((double) a.x, (double) a.y);
        }

        static long id2(Id6 a) {
            return a.x * a.x + a.y * a.y;
        }

        static double id3(Id6 a) {
            return Math.sqrt(id2(a));
        }

        static long crossProduct(Id6 a, Id6 b) {
            return a.x * b.y - b.x * a.y;
        }

        static long dotProduct(Id6 a, Id6 b) {
            return a.x * b.x + b.y * a.y;
        }

        static Id6 add(Id6 a, Id6 b) {
            return new Id6(a.x + b.x, a.y + b.y);
        }

        static Id6 subtract(Id6 a, Id6 b) {
            return new Id6(a.x - b.x, a.y - b.y);
        }

        static Id6 multiply(Id6 a, long b) {
            return new Id6(a.x * b, a.y * b);
        }

        static Id6 divide(Id6 a, long b) {
            return new Id6(a.x / b, a.y / b);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Id6> a = new ArrayList<>();
        Map<Pair, Integer> index = new HashMap<>();

        for (int i = 0; i < n; i++) {
            long x = scanner.nextLong();
            long y = scanner.nextLong();
            a.add(new Id6(x, y));
            index.put(new Pair(x, y), i);
        }

        a.sort(Comparator.comparingLong(u -> u.x));
        String d = scanner.next();
        StringBuilder reversedD = new StringBuilder(d).reverse();
        List<Id6> ans = new ArrayList<>();
        ans.add(a.get(0));
        a.remove(0);

        while (!a.isEmpty()) {
            int td;
            if (reversedD.length() == 0) {
                td = 1;
            } else if (reversedD.charAt(reversedD.length() - 1) == 'L') {
                td = 1;
            } else {
                td = -1;
            }
            if (reversedD.length() > 0) {
                reversedD.deleteCharAt(reversedD.length() - 1);
            }

            int cur = 0;
            for (int i = 0; i < a.size(); i++) {
                if (Geometry2D.crossProduct(Geometry2D.subtract(a.get(cur), ans.get(ans.size() - 1)),
                        Geometry2D.subtract(a.get(i), ans.get(ans.size() - 1))) * td < 0) {
                    cur = i;
                }
            }
            ans.add(a.get(cur));
            a.remove(cur);
        }

        List<Integer> aaa = ans.stream()
                .map(t -> index.get(new Pair(t.x, t.y)) + 1)
                .collect(Collectors.toList());

        System.out.println(aaa.stream().map(String::valueOf).collect(Collectors.joining(" ")));
    }

    static class Pair {
        long first, second;

        Pair(long first, long second) {
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
