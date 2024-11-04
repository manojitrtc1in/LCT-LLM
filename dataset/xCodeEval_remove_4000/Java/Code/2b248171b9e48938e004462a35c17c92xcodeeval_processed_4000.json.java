
import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class E {
    public static void main(String[] args) throws Exception {
        FastReader in = new FastReader(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = in.nextInt();
        Line lines[] = new Line[n];
        long p = 0;
        for (int i = 0; i < n; i++) {
            int x1 = in.nextInt(), y1 = in.nextInt(), x2 = in.nextInt(), y2 = in.nextInt();
            lines[i] = new Line(new P(x1, y1), new P(x2, y2));
            p += gcd(abs(x1-x2), abs(y1-y2)) + 1;
        }

        for (int i = 0; i < n; i++) {
            set = new TreeSet<>();
            for(int j = i+1; j < n; j++){
                id11(lines[i].id9(lines[j]));
            }
            p -= set.size();
        }

        pw.println(p);

        pw.close();
    }

    static TreeSet<P> set;
    static void id11(P p){
        if(p == null ) return;
        if(abs(p.x - round(p.x)) <= 1e-8 && abs(p.y - round(p.y)) <= 1e-8) set.add(new P(round(p.x), round(p.y)));
    }

    static int gcd(int p, int q) {
        if (q == 0) return p;
        else return gcd(q, p % q);
    }

    


    static boolean id6(P p1, P p2, P q1, P q2) {
        if (max(p1.x, p2.x) + EPS < min(q1.x, q2.x)) return false;
        if (max(q1.x, q2.x) + EPS < min(p1.x, p2.x)) return false;
        if (max(p1.y, p2.y) + EPS < min(q1.y, q2.y)) return false;
        if (max(q1.y, q2.y) + EPS < min(p1.y, p2.y)) return false;
        return sig(p2.sub(p1).det(q1.sub(p1))) * sig(p2.sub(p1).det(q2.sub(p1))) < EPS
                && sig(q2.sub(q1).det(p1.sub(q1))) * sig(q2.sub(q1).det(p2.sub(q1))) < EPS;
    }

    static double EPS = 1e-7;

    static P isLL(P p1, P p2, P q1, P q2) {
        double d = q2.sub(q1).det(p2.sub(p1));
        

        if (abs(d) < EPS) return null;
        return p1.add(p2.sub(p1).mult(q2.sub(q1).det(q1.sub(p1)) / d));
    }

    static int sig(double s){
        return s < -EPS ? -1 : s > EPS ? 1 : 0;
    }
    static class P implements Comparable<P>{
        final double x, y;

        P(double x, double y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(P o) {
            if(x == o.x) return Double.compare(y , o.y);
            return Double.compare(x, o.x);
        }

        P sub(P that) {
            return new P(x - that.x, y - that.y);
        }

        P add(P that) {
            return new P(x + that.x, y + that.y);
        }

        double dot(P that) {
            return x * that.x + y * that.y;
        }

        P mult(double s) {
            return new P(x * s, y * s);
        }

        

        double length() {
            return sqrt(x * x + y * y);
        }

        double length2() {
            return x * x + y * y;
        }

        P leftNormal() {
            return new P(-y, x);
        } 


        P rightNormal() {
            return new P(y, -x);
        } 


        P normalize() {
            double n = length();
            return n > 0 ? new P(x / n, y / n) : origin();
        }

        

        

        P scale(double l) {
            return normalize().mult(l);
        }

        P project(P a) {
            return mult(a.dot(this) / length2());
        }

        P reflect(P a) {
            return project(a).mult(2.0).sub(a);
        }

        

        P id14(double sinT, double cosT) {
            return new P(x * cosT - y * sinT, x * sinT + y * cosT);
        }

        P rotateCW(double sinT, double cosT) {
            return id14(-sinT, cosT);
        }

        P rotate(double theta) {
            return id14(sin(theta), cos(theta));
        }

        double theta() {
            return atan2(y, x);
        } 


        double angleTo(P a) {
            return acos(this.dot(a) / this.length() / a.length());
        }

        boolean isOrigin() {
            return x == 0 && y == 0;
        }

        public String toString() {
            return String.format("(%f,%f)", this.x, this.y);
        }

        static P read(Scanner s) {
            return new P(s.nextDouble(), s.nextDouble());
        }

        static P origin() {
            return new P(0, 0);
        }

        double det(P that) {
            return this.x * that.y - this.y * that.x;
        }

        double crossproduct(P that) {
            return this.det(that);
        }

        P half(P q) {
            return normalize().add(q.normalize());
        }

        double dist(P to) {
            return sub(to).length();
        }

        double id8(P b, P c) {
            return (b.sub(this).crossproduct(c.sub(this)));
        }

        boolean id7(P b, P c) {
            return abs(id8(b, c)) <= EPS;
        }

        

        

        boolean id10(P b, P c) {
            return id8(b, c) > 0;
        }

        double id12(P b, P c) {
            return id8(b, c) / 2.0;
        }

        

        

        double dist2(P to) {
            double dx = this.x - to.x;
            double dy = this.y - to.y;
            return dx * dx + dy * dy;
        }

        
        P[] id4(double b, double C) {
            P a = this;
            if (a.isOrigin())
                throw new Error("degenerate case");

            boolean transpose = abs(a.x) > abs(a.y);
            a = transpose ? new P(a.y, a.x) : a;

            Double[] x = id0(a.length2(), 2.0 * b * a.x, b * b - a.y
                    * a.y * C * C);
            P[] p = new P[x.length];
            for (int i = 0; i < x.length; i++) {
                double x1 = x[i];
                double x2 = ((-b - a.x * x1) / a.y);
                p[i] = transpose ? new P(x2, x1) : new P(x1, x2);
            }
            return p;
        }
    }

    static class HP extends P { 

        HP(double x, double y) {
            super(x, y);
        }

        @Override
        public int hashCode() {
            return Double.hashCode(x + 32768 * y);
        }

        @Override
        public boolean equals(Object _that) {
            HP that = (HP) _that;
            return this.x == that.x && this.y == that.y;
        }
    }

    
    static Comparator<P> id5(final P center) {
        return new Comparator<P>() {
            public int compare(P a, P b) {
                double thetaa = a.sub(center).theta();
                double thetab = b.sub(center).theta();
                if (thetaa < 0)
                    thetaa += 2 * PI;
                if (thetab < 0)
                    thetab += 2 * PI;
                int c = Double.compare(thetaa, thetab);
                if (c != 0)
                    return c;
                return Double.compare(b.x, a.x); 

            }
        };
    }

    
    static Comparator<P> id13(final P center) {
        return new Comparator<P>() {
            public int compare(P a, P b) {
                

                

                if (a.y >= center.y && b.y < center.y)
                    return -1;
                if (b.y >= center.y && a.y < center.y)
                    return 1;
                int orientation = (int) Math.signum(center
                        .id8(b, a));
                if (orientation != 0)
                    return orientation;
                return Double.compare(b.x, a.x); 

            }
        };
    }

    
    static Double[] id0(double a, double b, double c) {
        double D = b * b - 4 * a * c;
        if (D < -EPS)
            return new Double[] {};
        D = max(D, 0);
        if (D == 0)
            return new Double[] { -b / 2.0 / a };
        double d = sqrt(D);
        

        

        if (signum(b) == 0)
            return new Double[] { d / 2.0 / a, -d / 2.0 / a };
        double x1 = (-b - signum(b) * d) / (2 * a);
        double x2 = c / (a * x1);
        return new Double[] { Math.min(x1, x2), Math.max(x1, x2) };
    }

    
   


    
    static class Line {
        P p, q, d;

        Line(P p, P q) {
            this.p = p;
            this.q = q;
            d = q.sub(p);
        }

        P id2(double t) {
            return p.add(d.mult(t));
        }

        

        P reflect(P d2) {
            return d.reflect(d2);
        }

        

        P reflectPoint(P r) {
            return reflect(r.sub(p)).add(p);
        }

        

        P project(P a) {
            return p.add(d.project(a.sub(p)));
        }

        

        double distance(P a) {
            return project(a).dist(a);
        }

        @Override
        public String toString() {
            return String.format("[%s => %s]", p, q);
        }

        
        P id9(Line l) {
            double[] st = intersectionParameters(l);
            if (st == null)
                return null;

            

            

            double s = st[0];
            double t = st[1];
            if (s >= -EPS && s <= 1 + EPS && -EPS <= t && t <= 1 + EPS)
                return id2(s);

            return null;
        }

        
        P intersects(Line l) {
            double[] st = intersectionParameters(l);
            if (st != null)
                return id2(st[0]);
            return null;
        }

        
        double[] intersectionParameters(Line l) {
            P dneg = p.sub(q);
            double D = l.d.det(dneg);
            

            if (D == 0.0)
                return null;

            P rp = p.sub(l.p);

            return new double[] { l.d.det(rp) / D, rp.det(dneg) / D };
        }


        

        
        boolean contains(P r) {
            double t = p.id8(q, r);
            if (abs(t) > EPS) 

                return false;

            

            

            

            return p.dist(r) < p.dist(q) + EPS && r.sub(p).dot(d) >= EPS;
        }
    }

    static void debug(Object... obj) {
        System.err.println(Arrays.deepToString(obj));
    }

    static class FastReader {
        InputStream is;
        private byte[] inbuf = new byte[1024];
        private int lenbuf = 0, ptrbuf = 0, id3 = (int) 1e3;

        public FastReader(InputStream is) {
            this.is = is;
        }

        public FastReader(InputStream is, int id3) {
            this.is = is;
            this.id3 = id3;
        }

        public int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        public boolean id1(int c) {
            return !(c >= 33 && c <= 126);
        }

        public int skip() {
            int b;
            while ((b = readByte()) != -1 && id1(b)) ;
            return b;
        }

        public int nextInt() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            while (true) {
                if (b >= '0' && b <= '9') {
                    num = (num << 3) + (num << 1) + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }
    }
}