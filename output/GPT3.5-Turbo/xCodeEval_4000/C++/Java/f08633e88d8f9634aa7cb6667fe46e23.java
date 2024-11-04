import java.util.*;
import java.io.*;

class Main {
    static class Vector2D {
        long x, y;

        Vector2D(long i, long j) {
            x = i;
            y = j;
        }

        Vector2D(List<Long> v) {
            x = v.get(0);
            y = v.get(1);
        }

        int dir() {
            return x != 0 ? (x < 0 ? 0 : 1) : (y != 0 ? (y < 0 ? 2 : 3) : -1);
        }

        Vector2D add(Vector2D other) {
            return new Vector2D(x + other.x, y + other.y);
        }

        Vector2D subtract(Vector2D other) {
            return new Vector2D(x - other.x, y - other.y);
        }

        Vector2D multiply(long scalar) {
            return new Vector2D(x * scalar, y * scalar);
        }

        Vector2D divide(long scalar) {
            return new Vector2D(x / scalar, y / scalar);
        }
    }

    static double angle(Vector2D a) {
        return Math.atan2(a.x, a.y);
    }

    static long squaredEuclideanNorm(Vector2D a) {
        return a.x * a.x + a.y * a.y;
    }

    static long euclideanNorm(Vector2D a) {
        return (long) Math.sqrt(squaredEuclideanNorm(a));
    }

    static long crossProduct(Vector2D a, Vector2D b) {
        return a.x * b.y - b.x * a.y;
    }

    static long dotProduct(Vector2D a, Vector2D b) {
        return a.x * b.x + b.y * a.y;
    }

    static List<Vector2D> intersection(Line2D a, Line2D b) {
        long a1 = crossProduct(b.p.subtract(a.q), b.q.subtract(b.p));
        long a2 = crossProduct(a.p.subtract(b.q), b.q.subtract(b.p));
        if (Math.abs(a1 + a2) < 1e-8) {
            return new ArrayList<>();
        } else {
            List<Vector2D> result = new ArrayList<>();
            result.add(a.p.multiply(a1).add(a.q.multiply(a2)).divide(a1 + a2));
            return result;
        }
    }

    static class Line2D {
        Vector2D p, q;
        double a;

        Line2D(Vector2D p_, Vector2D q_) {
            p = p_;
            q = q_;
            a = angle(p.subtract(q));
        }
    }

    static class Segment2D {
        Vector2D p, q;
        double a;

        Segment2D(Vector2D p_, Vector2D q_) {
            p = p_;
            q = q_;
            a = angle(p.subtract(q));
        }

        Segment2D(List<Long> p_, List<Long> q_) {
            p = new Vector2D(p_);
            q = new Vector2D(q_);
            a = angle(p.subtract(q));
        }

        Line2D toLine2D() {
            return new Line2D(p, q);
        }

        boolean contains(Vector2D b) {
            return Math.abs(crossProduct(q.subtract(p), b.subtract(p))) < 1e-8 &&
                    dotProduct(b.subtract(p), b.subtract(q)) < 1e-8;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Vector2D> a = new ArrayList<>();
        Map<List<Long>, Integer> index = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            List<Long> point = new ArrayList<>();
            point.add(Long.parseLong(line[0]));
            point.add(Long.parseLong(line[1]));
            a.add(new Vector2D(point));
            index.put(point, i);
        }
        Collections.sort(a, (u, v) -> Long.compare(u.x, v.x));
        String d = br.readLine();
        StringBuilder sb = new StringBuilder(d);
        sb.reverse();
        d = sb.toString();
        List<Vector2D> ans = new ArrayList<>();
        ans.add(a.get(0));
        a.remove(0);
        while (!a.isEmpty()) {
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
            for (int i = 0; i < a.size(); i++) {
                if (crossProduct(a.get(cur).subtract(ans.get(ans.size() - 1)),
                        a.get(i).subtract(ans.get(ans.size() - 1))) * td < 0) {
                    cur = i;
                }
            }
            ans.add(a.get(cur));
            a.remove(cur);
        }
        List<Integer> aaa = new ArrayList<>();
        for (Vector2D t : ans) {
            aaa.add(index.get(List.of(t.x, t.y)) + 1);
        }
        System.out.println(aaa);
    }
}
