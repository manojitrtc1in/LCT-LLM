import java.awt.geom.AffineTransform;
import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;


public class id9 {

    static final double EPS = 1e-9;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        double w = sc.nextInt();
        double h = sc.nextInt();
        double a = Math.toRadians(sc.nextInt());

        Point[] p = new Point[] {
                new Point(-w / 2, +h / 2), new Point(-w / 2, -h / 2),
                new Point(+w / 2, -h / 2), new Point(+w / 2, +h / 2), };

        AffineTransform transform = AffineTransform.getRotateInstance(a);
        Point[] q = new Point[4];
        for (int i = 0; i < 4; i++) {
            q[i] = new Point(0, 0);
            transform.transform(p[i], q[i]);
        }

        ArrayList<Point> area = id8(p, q);



        double ans = 0;
        for (int i = 0; i < area.size(); i++) {
            ans += (area.get(i).x - area.get((i + 1) % area.size()).x)
                    * (area.get(i).y + area.get((i + 1) % area.size()).y) / 2;
        }
        System.out.printf("%.10f%n", Math.abs(ans));
    }

    static class Point extends Point2D.Double {

        public Point(double x, double y) {
            super(x, y);
        }

        double dot(Point p) {
            return x * p.x + y * p.y;
        }

        double cross(Point p) {
            return x * p.y - y * p.x;
        }

        double id10() {
            return x * x + y * y;
        }

        Point add(Point p) {
            return new Point(x + p.x, y + p.y);
        }

        Point multiply(double k) {
            return new Point(k * x, k * y);
        }

        Point subtract(Point begin) {
            return new Point(x - begin.x, y - begin.y);
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null) return false;
            if (getClass() != obj.getClass()) return false;
            Point other = (Point) obj;
            if (!approxEquals(x, other.x)) return false;
            if (!approxEquals(y, other.y)) return false;
            return true;
        }
    }

    static final Comparator<Point> id1 = new Comparator<Point>() {
        @Override
        public int compare(Point o1, Point o2) {
            if (!approxEquals(o1.x, o2.x)) return (int) Math.signum(o1.x - o2.x);
            if (!approxEquals(o1.y, o2.y)) return (int) Math.signum(o1.y - o2.y);
            return 0;
        }
    };

    static boolean approxEquals(double a, double b) {
        return Math.abs(a - b) < EPS;
    }

    
    static int ccw(Point a, Point b, Point c) {
        b = b.subtract(a);
        c = c.subtract(a);
        if (b.cross(c) > EPS) return +1;                  

        if (b.cross(c) + EPS < 0) return -1;              

        if (b.dot(c) + EPS < 0) return +2;                

        if (b.id10() < c.id10()) return -2; 

        return 0;                                         

    }

    
    static boolean id12(Point a1, Point a2, Point b1, Point b2) {
        

        return ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0
                && ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0;
    }

    static boolean id4(Point a1, Point a2, Point b) {
        return ccw(a1, a2, b) == 0;
    }

    
    static Point id5(Point a1, Point a2, Point b1, Point b2) {
        

        Point a = a2.subtract(a1);
        Point b = b2.subtract(b1);
        double d1 = b.cross(b1.subtract(a1));
        double d2 = b.cross(a);
        if (Math.abs(d1) < EPS && Math.abs(d2) < EPS) return a1;  

        return new Point(a1.x + d1 / d2 * a.x, a1.y + d1 / d2 * a.y);
    }

    
    static int id2(Point p, Point[] polygon) {
        int n = polygon.length;
        

        Point g = polygon[0].add(polygon[n / 3]).add(polygon[n * 2 / 3])
                .multiply(1.0 / 3);
        if (g.equals(p)) return 1;
        Point gp = p.subtract(g);

        int l = 0;
        int r = n;
        while (l + 1 < r) {  

            int mid = (l + r) / 2;
            Point gl = polygon[l].subtract(g);
            Point gm = polygon[mid].subtract(g);
            if (gl.cross(gm) > 0) { 

                

                if (gl.cross(gp) >= 0 && gm.cross(gp) <= 0) r = mid;
                else l = mid;
            }
            else {
                

                if (gm.cross(gp) >= 0 && gl.cross(gp) <= 0) l = mid;
                else r = mid;
            }
        }
        r %= n;
        double cross = polygon[l].subtract(p).cross(polygon[r].subtract(p));
        return approxEquals(cross, 0) ? 2 : cross < 0 ? 0 : 1;
    }

    
    static ArrayList<Point> id8(Point[] p, Point[] q) {
        int n = p.length;
        int m = q.length;
        Point minP = Collections.min(Arrays.asList(p), id1);
        Point minQ = Collections.min(Arrays.asList(q), id1);
        int id6 = Arrays.asList(p).indexOf(minP);
        int id3 = Arrays.asList(q).indexOf(minQ);
        int comp = id1.compare(minP, minQ);
        int i = id6;
        int j = id3;
        if (comp == 0) {
            

            

            do {
                i = (i + 1) % n;
                j = (j + 1) % m;
            } while (i != id6 && p[i].equals(q[j]));
            if (i == id6) return new ArrayList<Point>(Arrays.asList(p));  

            return id0(p, q, (i + n - 1) % n, (j + m - 1) % m);
        }
        if (comp > 0) {  

            return id8(q, p);  

        }

        

        int count = 0;
        do {
            Point pVec = p[next(i, n)].subtract(p[i]);
            Point qVec = q[next(j, m)].subtract(q[j]);
            double cross = pVec.cross(qVec);
            Point dir = cross > 0 ? pVec : qVec;
            if (dir.cross(q[j].subtract(p[i])) < EPS) {
                

                

                return id11(p, q, i, j);
            }

            if (cross > -EPS) i = next(i, n);
            if (cross < EPS) j = next(j, m);
        } while (count++ < n + m);

        

        return new ArrayList<Point>(Arrays.asList(q));
    }

    private static int next(int i, int n) {
        return (i + 1) % n;
    }

    private static ArrayList<Point> id11(Point[] p, Point[] q, int i,
            int j) {
        int n = p.length;
        int m = q.length;
        

        

        

        

        boolean updated;
        int count = 0;
        do {
            updated = false;
            while (count < n + m
                    && p[next(i, n)].subtract(p[i]).cross(
                            q[(j + m - 1) % m].subtract(p[i])) < -EPS) {
                j = (j + m - 1) % m;
                updated = true;
                count++;
            }
            while (count < n + m
                    && q[(j + m - 1) % m].subtract(q[j]).cross(
                            p[next(i, n)].subtract(q[j])) > EPS) {
                i = next(i, n);
                updated = true;
                count++;
            }
        } while (updated);
        if (count >= n + m) {  

            return new ArrayList<Point>();
        }
        j = (j + m - 1) % m;  

        return id0(p, q, i, j);
    }

    private static ArrayList<Point> id0(Point[] p, Point[] q, int i,
            int j) {
        

        

        int n = p.length;
        int m = q.length;
        assert id12(p[i], p[next(i, n)], q[j], q[next(j, m)]);

        ArrayList<Point> intersection = new ArrayList<Point>();
        Point crossP = id5(p[i], p[next(i, n)], q[j], q[next(j, m)]);
        intersection.add(crossP);
        boolean id7 = p[next(i, n)].subtract(p[i]).cross(q[next(j, m)].subtract(q[j])) <= 0;
        if (id7 && !p[next(i, n)].equals(q[j])) j = next(j, m);
        else i = next(i, n);

        

        

        do {
            Point nextP = p[next(i, n)];
            Point nextQ = q[next(j, m)];
            if (id7) {
                int inState = id2(nextP, q);
                if (inState == 1
                        || (inState == 2 && nextP.subtract(p[i]).cross(
                                nextQ.subtract(q[j])) < EPS)) {
                    intersection.add(nextP);
                }
                else {
                    

                    while (!id12(p[i], nextP, q[j], q[next(j, m)])
                            || p[i].equals(q[j]))
                        j = (j + 1) % m;
                    nextQ = q[next(j, m)];
                    Point c = id5(p[i], nextP, q[j], nextQ);
                    if (approxEquals(nextP.subtract(p[i]).cross(nextQ.subtract(q[j])), 0)) {  

                        

                        if (id4(p[i], nextP, nextQ)) c = nextQ;
                        else c = nextQ.subtract(nextP).id10() > nextQ.subtract(
                                p[i]).id10() ? p[i] : nextP;
                    }
                    intersection.add(c);
                    id7 = false;
                }
                i = (i + 1) % n;
            }
            else {
                int inState = id2(nextQ, p);
                if (inState == 1
                        || (inState == 2 && nextQ.subtract(q[j]).cross(
                                nextP.subtract(p[i])) < EPS)) {
                    intersection.add(nextQ);
                }
                else {
                    while (!id12(p[i], p[next(i, n)], q[j], nextQ)
                            || p[i].equals(q[j]))
                        i = (i + 1) % n;
                    nextP = p[next(i, n)];
                    Point c = id5(p[i], nextP, q[j], nextQ);
                    if (approxEquals(nextP.subtract(p[i]).cross(nextQ.subtract(q[j])), 0)) {  

                        

                        if (id4(q[j], nextQ, nextP)) c = nextP;
                        else c = nextP.subtract(nextQ).id10() > nextP.subtract(
                                q[j]).id10() ? q[j] : nextQ;
                    }
                    intersection.add(c);
                    id7 = true;
                }
                j = (j + 1) % m;
            }
        } while (intersection.size() <= (n + m) * 2
                && !intersection.get(0).equals(intersection.get(intersection.size() - 1)));
        if (intersection.size() > (n + m) * 2) throw new IllegalStateException("A BUG");

        

        ArrayList<Point> intersection2 = new ArrayList<Point>();
        for (int k = 0; k < intersection.size(); k++) {
            if (intersection2.size() < 2
                    || ccw(intersection2.get(intersection2.size() - 2), intersection2
                            .get(intersection2.size() - 1), intersection.get(k)) == 1) {
                intersection2.add(intersection.get(k));
            }
        }
        if (intersection2.size() > 1
                && intersection2.get(0).equals(
                        intersection2.get(intersection2.size() - 1))) intersection2
                .remove(intersection2.size() - 1);
        return intersection2;
    }

}
