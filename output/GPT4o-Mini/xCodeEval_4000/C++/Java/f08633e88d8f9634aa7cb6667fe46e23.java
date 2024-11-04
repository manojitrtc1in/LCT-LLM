import java.util.*;
import java.io.*;

class Geometry2D {
    static class Vector2D {
        long x, y;

        Vector2D(long i, long j) {
            this.x = i;
            this.y = j;
        }

        Vector2D(long[] v) {
            this.x = v[0];
            this.y = v[1];
            assert v.length == 2;
        }

        int dir() {
            return x != 0 ? (x < 0 ? 1 : 0) : (y != 0 ? (y < 0 ? 1 : 0) : -1);
        }

        static double angle(Vector2D a) {
            return Math.atan2((double) a.x, (double) a.y);
        }

        static long squaredEuclideanNorm(Vector2D a) {
            return a.x * a.x + a.y * a.y;
        }

        static double euclideanNorm(Vector2D a) {
            return Math.sqrt(squaredEuclideanNorm(a));
        }

        static long crossProduct(Vector2D a, Vector2D b) {
            return a.x * b.y - b.x * a.y;
        }

        static long dotProduct(Vector2D a, Vector2D b) {
            return a.x * b.x + b.y * a.y;
        }

        static Vector2D add(Vector2D a, Vector2D b) {
            return new Vector2D(a.x + b.x, a.y + b.y);
        }

        static Vector2D subtract(Vector2D a, Vector2D b) {
            return new Vector2D(a.x - b.x, a.y - b.y);
        }

        static Vector2D multiply(Vector2D a, long b) {
            return new Vector2D(a.x * b, a.y * b);
        }

        static Vector2D divide(Vector2D a, long b) {
            return new Vector2D(a.x / b, a.y / b);
        }
    }

    static class Line2D {
        Vector2D p, q;
        double a;

        Line2D(Vector2D p_, Vector2D q_) {
            this.p = p_;
            this.q = q_;
            this.a = Vector2D.angle(Vector2D.subtract(p, q));
        }
    }

    static class Segment2D {
        Vector2D p, q;
        double a;

        Segment2D(Vector2D p_, Vector2D q_) {
            this.p = p_;
            this.q = q_;
            this.a = Vector2D.angle(Vector2D.subtract(p, q));
        }

        boolean contains(Vector2D b) {
            return Math.abs(Vector2D.crossProduct(Vector2D.subtract(q, p), Vector2D.subtract(b, p))) < 1e-8 &&
                   Vector2D.dotProduct(Vector2D.subtract(b, p), Vector2D.subtract(b, q)) < 1e-8;
        }
    }

    static List<Vector2D> intersection(Segment2D a, Segment2D b) {
        List<Vector2D> r = new ArrayList<>();
        Line2D lineA = new Line2D(a.p, a.q);
        Line2D lineB = new Line2D(b.p, b.q);
        double a1 = Vector2D.crossProduct(Vector2D.subtract(lineB.p, lineA.q), Vector2D.subtract(lineB.q, lineB.p));
        double a2 = Vector2D.crossProduct(Vector2D.subtract(lineA.p, lineB.q), Vector2D.subtract(lineB.q, lineB.p));

        if (Math.abs(a1 + a2) < 1e-8) {
            return r; // No intersection
        } else {
            r.add(Vector2D.divide(Vector2D.add(Vector2D.multiply(lineA.p, (long) a1), Vector2D.multiply(lineA.q, (long) a2)), (long) (a1 + a2)));
            return r;
        }
    }
}

public class f08633e88d8f9634aa7cb6667fe46e23_nc {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        Geometry2D.Vector2D[] a = new Geometry2D.Vector2D[n];
        Map<Geometry2D.Vector2D, Integer> index = new HashMap<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());
            a[i] = new Geometry2D.Vector2D(x, y);
            index.put(a[i], i);
        }

        Arrays.sort(a, Comparator.comparingLong(v -> v.x));
        String d = br.readLine();
        StringBuilder ans = new StringBuilder();
        List<Geometry2D.Vector2D> result = new ArrayList<>();
        result.add(a[0]);
        List<Geometry2D.Vector2D> remaining = new ArrayList<>(Arrays.asList(Arrays.copyOfRange(a, 1, a.length)));

        while (!remaining.isEmpty()) {
            int td = d.isEmpty() ? 1 : (d.charAt(d.length() - 1) == 'L' ? 1 : -1);
            if (!d.isEmpty()) d = d.substring(0, d.length() - 1);
            int cur = 0;

            for (int i = 0; i < remaining.size(); i++) {
                if (Geometry2D.Vector2D.crossProduct(Geometry2D.Vector2D.subtract(remaining.get(cur), result.get(result.size() - 1)),
                        Geometry2D.Vector2D.subtract(remaining.get(i), result.get(result.size() - 1))) * td < 0) {
                    cur = i;
                }
            }
            result.add(remaining.get(cur));
            remaining.remove(cur);
        }

        for (Geometry2D.Vector2D t : result) {
            ans.append(index.get(t) + 1).append(" ");
        }

        out.println(ans.toString().trim());
        out.flush();
    }
}
