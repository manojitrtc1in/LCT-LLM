import java.util.*;
import java.io.*;

class Main {
    static class Point {
        long x, y;

        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Line {
        Point p, q;
        double angle;

        public Line(Point p, Point q) {
            this.p = p;
            this.q = q;
            this.angle = Math.atan2(p.x - q.x, p.y - q.y);
        }
    }

    static double crossProduct(Point a, Point b) {
        return a.x * b.y - b.x * a.y;
    }

    static double dotProduct(Point a, Point b) {
        return a.x * b.x + b.y * a.y;
    }

    static List<Point> intersection(Line a, Line b) {
        double a1 = crossProduct(subtract(b.p, a.q), subtract(b.q, b.p));
        double a2 = crossProduct(subtract(a.p, b.q), subtract(b.q, b.p));

        if (Math.abs(a1 + a2) < 1e-8) {
            return new ArrayList<>();
        } else {
            List<Point> result = new ArrayList<>();
            result.add(add(multiply(a.p, a1), multiply(a.q, a2)));
            return result;
        }
    }

    static boolean contains(Line a, Point b) {
        return Math.abs(crossProduct(subtract(a.q, a.p), subtract(b, a.p))) < 1e-8 &&
                dotProduct(subtract(b, a.p), subtract(b, a.q)) < 1e-8;
    }

    static Point subtract(Point a, Point b) {
        return new Point(a.x - b.x, a.y - b.y);
    }

    static Point add(Point a, Point b) {
        return new Point(a.x + b.x, a.y + b.y);
    }

    static Point multiply(Point a, double b) {
        return new Point((long) (a.x * b), (long) (a.y * b));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Point[] a = new Point[n];
        Map<Point, Integer> index = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            long x = Long.parseLong(input[0]);
            long y = Long.parseLong(input[1]);
            a[i] = new Point(x, y);
            index.put(a[i], i);
        }

        Arrays.sort(a, (p, q) -> Long.compare(p.x, q.x));
        String d = new StringBuilder(br.readLine()).reverse().toString();
        List<Point> ans = new ArrayList<>();
        ans.add(a[0]);
        List<Point> aList = new ArrayList<>(Arrays.asList(a));
        aList.remove(0);
        while (!aList.isEmpty()) {
            int td;
            if (d.isEmpty()) {
                td = 1;
            } else if (d.charAt(d.length() - 1) == 'L') {
                td = 1;
            } else {
                td = -1;
            }

            if (!d.isEmpty()) {
                d = d.substring(0, d.length() - 1);
            }

            int cur = 0;
            for (int i = 0; i < aList.size(); i++) {
                if (crossProduct(subtract(aList.get(cur), ans.get(ans.size() - 1)),
                        subtract(aList.get(i), ans.get(ans.size() - 1))) * td < 0) {
                    cur = i;
                }
            }

            ans.add(aList.get(cur));
            aList.remove(cur);
        }

        List<Integer> aaa = new ArrayList<>();
        for (Point t : ans) {
            aaa.add(index.get(t) + 1);
        }

        System.out.println(aaa);
    }
}
