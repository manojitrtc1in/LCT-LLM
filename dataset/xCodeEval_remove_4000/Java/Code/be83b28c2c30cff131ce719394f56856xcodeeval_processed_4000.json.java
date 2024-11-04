import java.util.Arrays;
import java.util.Scanner;

public class Main {


        static final double INF = 1e9;
        static final double EPS = 1e-9;
        


        double id4(double d) { return d * Math.PI / 180.0; }

        double id1(double r) { return r * 180.0 / Math.PI; }

        


        static class point implements Comparable<point>{
            double x, y;                   

            point() { x = y = 0.0; }                         

            point(double _x, double _y) { x = _x; y = _y; }         

            

            public int compareTo(point other) {      

                if (Math.abs(x - other.x) > EPS)                

                    return (int)Math.ceil(x - other.x);       

                else if (Math.abs(y - other.y) > EPS)
                    return (int)Math.ceil(y - other.y);      

                else
                    return 0; } };                                    


        static double dist(point p1, point p2) {                   

            

            return Math.hypot(p1.x - p2.x, p1.y - p2.y); }         


        

        point rotate(point p, double theta) {
            double rad = id4(theta);       

            return new point(p.x * Math.cos(rad) - p.y * Math.sin(rad),
                    p.x * Math.sin(rad) + p.y * Math.cos(rad)); }

        class line { double a, b, c; };              


        

        void id2(point p1, point p2, line l) {
            if (Math.abs(p1.x - p2.x) < EPS) {             

                l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;
            } else {
                l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
                l.b = 1.0;                 

                l.c = -(double)(l.a * p1.x) - p1.y;
            } }

        

        class line2 { double m, c; };          


        int id0(point p1, point p2, line2 l) {
            if (Math.abs(p1.x - p2.x) < EPS) {        

                l.m = INF;                       

                l.c = p1.x;                     

                return 0;      

            }
            else {
                l.m = (double)(p1.y - p2.y) / (p1.x - p2.x);
                l.c = p1.y - l.m * p1.x;
                return 1;        

            } }

        boolean areParallel(line l1, line l2) {       

            return (Math.abs(l1.a-l2.a) < EPS) && (Math.abs(l1.b-l2.b) < EPS); }

        boolean areSame(line l1, line l2) {           

            return areParallel(l1 ,l2) && (Math.abs(l1.c - l2.c) < EPS); }

        

        boolean areIntersect(line l1, line l2, point p) {
            if (areParallel(l1, l2)) return false;               

            

            p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
            

            if (Math.abs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
            else                      p.y = -(l2.a * p.x + l2.c);
            return true; }

        class vec { double x, y;     

            vec(double _x, double _y) { x = _x; y = _y; } };

        vec toVec(point a, point b) {               

            return new vec(b.x - a.x, b.y - a.y); }

        vec scale(vec v, double s) {           

            return new vec(v.x * s, v.y * s); }              


        point translate(point p, vec v) {           

            return new point(p.x + v.x , p.y + v.y); }

        

        void id6(point p, double m, line l) {
            l.a = -m;                                                  

            l.b = 1;                                                    

            l.c = -((l.a * p.x) + (l.b * p.y)); }                   


        void closestPoint(line l, point p, point ans) {
            line perpendicular = new line(); 

            if (Math.abs(l.b) < EPS) {             

                ans.x = -(l.c);   ans.y = p.y;      return; }

            if (Math.abs(l.a) < EPS) {           

                ans.x = p.x;      ans.y = -(l.c);   return; }

            id6(p, 1 / l.a, perpendicular);             

            

            

            areIntersect(l, perpendicular, ans); }

        

        void reflectionPoint(line l, point p, point ans) {
            point b = new point();
            closestPoint(l, p, b);                         

            vec v = toVec(p, b);                                 

            ans = translate(translate(p, v), v); }             


        double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

        double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

        

        

        

        double id3(point p, point a, point b, point c) {
            

            vec ap = toVec(a, p), ab = toVec(a, b);
            double u = dot(ap, ab) / norm_sq(ab);
            c = translate(a, scale(ab, u));                     

            return dist(p, c); }              


        

        

        

        double id5(point p, point a, point b, point c) {
            vec ap = toVec(a, p), ab = toVec(a, b);
            double u = dot(ap, ab) / norm_sq(ab);
            if (u < 0.0) { c = new point(a.x, a.y);                  

                return dist(p, a); }            

            if (u > 1.0) { c = new point(b.x, b.y);                  

                return dist(p, b); }            

            return id3(p, a, b, c); }             


        double angle(point a, point o, point b) {     

            vec oa = toVec(o, a), ob = toVec(o, b);
            return Math.acos(dot(oa, ob) / Math.sqrt(norm_sq(oa) * norm_sq(ob))); }

        double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

        

        

        

        

        

        


        

        

        boolean ccw(point p, point q, point r) {
            return cross(toVec(p, q), toVec(p, r)) > 0; }

        

        boolean collinear(point p, point q, point r) {
            return Math.abs(cross(toVec(p, q), toVec(p, r))) < EPS; }

        void run() {
            point P1 = new point(), P2 = new point(), P3 = new point(0, 1); 

            System.out.println(P1.compareTo(P2) == 0);                      

            System.out.println(P1.compareTo(P3) == 0);                     


            point[] P = new point[6];
            P[0] = new point(2, 2);
            P[1] = new point(4, 3);
            P[2] = new point(2, 4);
            P[3] = new point(6, 6);
            P[4] = new point(2, 6);
            P[5] = new point(6, 5);

            

            Arrays.sort(P);
            for (int i = 0; i < P.length; i++)
                System.out.printf("(%.2f, %.2f)\n", P[i].x, P[i].y);

            

            P = new point[7];
            P[0] = new point(2, 2);
            P[1] = new point(4, 3);
            P[2] = new point(2, 4);
            P[3] = new point(6, 6);
            P[4] = new point(2, 6);
            P[5] = new point(6, 5);
            P[6] = new point(8, 6);

    

            double d = dist(P[0], P[5]);
            System.out.printf("Euclidean distance between P[0] and P[5] = %.2f\n", d); 


            

            line l1 = new line(), l2 = new line(), l3 = new line(), l4 = new line();

            id2(P[0], P[1], l1);
            System.out.printf("%.2f * x + %.2f * y + %.2f = 0.00\n", l1.a, l1.b, l1.c); 


            id2(P[0], P[2], l2); 

            System.out.printf("%.2f * x + %.2f * y + %.2f = 0.00\n", l2.a, l2.b, l2.c); 


            

            id2(P[2], P[3], l3);
            System.out.printf("l1 & l2 are parallel? %b\n", areParallel(l1, l2)); 

            System.out.printf("l1 & l3 are parallel? %b\n", areParallel(l1, l3)); 


            id2(P[2], P[4], l4);
            System.out.printf("l1 & l2 are the same? %b\n", areSame(l1, l2)); 

            System.out.printf("l2 & l4 are the same? %b\n", areSame(l2, l4)); 


            point p12 = new point();
            boolean res = areIntersect(l1, l2, p12); 

            System.out.printf("l1 & l2 are intersect? %b, at (%.2f, %.2f)\n", res, p12.x, p12.y);

            

            point ans = new point();
            d = id3(P[0], P[2], P[3], ans);
            System.out.printf("Closest point from P[0] to line         (P[2]-P[3]): (%.2f, %.2f), dist = %.2f\n", ans.x, ans.y, d);
            closestPoint(l3, P[0], ans);
            System.out.printf("Closest point from P[0] to line V2      (P[2]-P[3]): (%.2f, %.2f), dist = %.2f\n", ans.x, ans.y, dist(P[0], ans));

            d = id5(P[0], P[2], P[3], ans);
            System.out.printf("Closest point from P[0] to line SEGMENT (P[2]-P[3]): (%.2f, %.2f), dist = %.2f\n", ans.x, ans.y, d); 

            d = id5(P[1], P[2], P[3], ans);
            System.out.printf("Closest point from P[1] to line SEGMENT (P[2]-P[3]): (%.2f, %.2f), dist = %.2f\n", ans.x, ans.y, d); 

            d = id5(P[6], P[2], P[3], ans);
            System.out.printf("Closest point from P[6] to line SEGMENT (P[2]-P[3]): (%.2f, %.2f), dist = %.2f\n", ans.x, ans.y, d); 


            reflectionPoint(l4, P[1], ans);
            System.out.printf("Reflection point from P[1] to line      (P[2]-P[4]): (%.2f, %.2f)\n", ans.x, ans.y); 


            System.out.printf("Angle P[0]-P[4]-P[3] = %.2f\n", id1(angle(P[0], P[4], P[3]))); 

            System.out.printf("Angle P[0]-P[2]-P[1] = %.2f\n", id1(angle(P[0], P[2], P[1]))); 

            System.out.printf("Angle P[4]-P[3]-P[6] = %.2f\n", id1(angle(P[4], P[3], P[6]))); 


            System.out.printf("P[0], P[2], P[3] form A left turn? %b\n", ccw(P[0], P[2], P[3])); 

            System.out.printf("P[0], P[3], P[2] form A left turn? %b\n", ccw(P[0], P[3], P[2])); 


            System.out.printf("P[0], P[2], P[3] are collinear? %b\n", collinear(P[0], P[2], P[3])); 

            System.out.printf("P[0], P[2], P[4] are collinear? %b\n", collinear(P[0], P[2], P[4])); 


            point p = new point(3, 7), q = new point(11, 13), r = new point(35, 30); 

            System.out.printf("r is on the %s of line p-r\n", ccw(p, q, r) ? "left" : "right"); 


    

            

            point A = new point(2.0, 2.0);
            point B = new point(4.0, 3.0);
            vec v = toVec(A, B); 

            point C = new point(3.0, 2.0);
            point D = translate(C, v); 

            System.out.printf("D = (%.2f, %.2f)\n", D.x, D.y);
            point E = translate(C, scale(v, 0.5)); 

            System.out.printf("E = (%.2f, %.2f)\n", E.x, E.y);

            

            System.out.printf("B = (%.2f, %.2f)\n", B.x, B.y); 

            point F = rotate(B, 90); 

            System.out.printf("F = (%.2f, %.2f)\n", F.x, F.y);
            point G = rotate(B, 180); 

            System.out.printf("G = (%.2f, %.2f)\n", G.x, G.y);
        }

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        String input = reader.nextLine();
        String[] nk = input.split(" ");
        String[] xy;
        int n = Integer.valueOf(nk[0]);
        int k = Integer.valueOf(nk[1]);
        int x, y;
        double distance = 0;
        point p = null;
        for(int i = 0; i< n; i++){
            input = reader.nextLine();
            xy = input.split(" ");
            x = Integer.valueOf(xy[0]);
            y = Integer.valueOf(xy[1]);
            if(i ==0){
                p = new point(x,y);
            }
            else{
                point p2 = p;
                p = new point(x,y);
                distance += dist(p2,p);
            }


        }
        distance = (distance/50) * k;
        System.out.println(distance);
    }
}
