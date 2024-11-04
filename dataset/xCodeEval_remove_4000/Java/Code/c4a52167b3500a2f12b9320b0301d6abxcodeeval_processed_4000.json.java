import java.awt.geom.Point2D;
import java.awt.geom.Point2D.Double;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;
import java.util.StringTokenizer;


public class id4 {
    public static final DecimalFormat DF = new DecimalFormat("0.00000", new DecimalFormatSymbols(Locale.US));
    public static void main(String[] args) {

        double xa=0, ya=0, ra=0;
        double xb=0, yb=0, rb=0;
        double xc=0, yc=0, rc=0;

        Scanner sc = new Scanner(System.in);
        sc.useLocale(Locale.US);
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            StringTokenizer st = new StringTokenizer(line, " \n\r");
            while (st.hasMoreTokens()) {
                xa = java.lang.Double.parseDouble(st.nextToken());
                ya = java.lang.Double.parseDouble(st.nextToken());
                ra = java.lang.Double.parseDouble(st.nextToken());
            }
            line = sc.nextLine();
            st = new StringTokenizer(line, " \n\r");
            while (st.hasMoreTokens()) {
                xb = java.lang.Double.parseDouble(st.nextToken());
                yb = java.lang.Double.parseDouble(st.nextToken());
                rb = java.lang.Double.parseDouble(st.nextToken());
            }
            line = sc.nextLine();
            st = new StringTokenizer(line, " \n\r");
            while (st.hasMoreTokens()) {
                xc = java.lang.Double.parseDouble(st.nextToken());
                yc = java.lang.Double.parseDouble(st.nextToken());
                rc = java.lang.Double.parseDouble(st.nextToken());
            }

            id13(xa, ya, ra, xb, yb, rb, xc, yc, rc);
        }
        

    }

    public static void id13(double xa, double ya, double ra,
            double xb, double yb, double rb, double xc, double yc, double rc) {
        

        Point2D A = new Point2D.Double(xa, ya);
        Point2D B = new Point2D.Double(xb, yb);
        Point2D C = new Point2D.Double(xc, yc);

        

        Point2D midAB = new Point2D.Double((A.getX() + B.getX()) / 2.0,
                (A.getY() + B.getY()) / 2.0);
        Point2D midAC = new Point2D.Double((A.getX() + C.getX()) / 2.0,
                (A.getY() + C.getY()) / 2.0);
        Point2D midBC = new Point2D.Double((C.getX() + B.getX()) / 2.0,
                (C.getY() + B.getY()) / 2.0);

        Point2D id8 = new Point2D.Double(midAB.getX()
                - (B.getY() - A.getY()), midAB.getY()
                + (B.getX() - A.getX()));
        Point2D id12 = new Point2D.Double(midAC.getX()
                - (C.getY() - A.getY()), midAC.getY()
                + (C.getX() - A.getX()));
        Point2D id11 = new Point2D.Double(midBC.getX()
                - (C.getY() - B.getY()), midBC.getY()
                + (C.getX() - B.getX()));

        
        Point2D[] ijAB = getIJ(A, B, ra, rb);
        Point2D centerAB = new Point2D.Double(
                (ijAB[0].getX() + ijAB[1].getX()) / 2.0,
                (ijAB[0].getY() + ijAB[1].getY()) / 2.0);
        double rAB = ijAB[0].distance(ijAB[1]) / 2.0;

        Point2D[] ijBC = getIJ(B, C, rb, rc);
        Point2D centerBC = new Point2D.Double(
                (ijBC[0].getX() + ijBC[1].getX()) / 2.0,
                (ijBC[0].getY() + ijBC[1].getY()) / 2.0);
        double rBC = ijBC[0].distance(ijBC[1]) / 2.0;

        Point2D[] ijAC = getIJ(A, C, ra, rc);
        Point2D centerAC = new Point2D.Double(
                (ijAC[0].getX() + ijAC[1].getX()) / 2.0,
                (ijAC[0].getY() + ijAC[1].getY()) / 2.0);
        double rAC = ijAC[0].distance(ijAC[1]) / 2.0;







        if (ra == rb && rb == rc) {
            

            

            Point2D[] id9 = id5(midAB,
                    id8, midAC, id12);








            printPoint(id9[0]);




            
        } else {
            

            if (ra == rb) {
                

                

                

                

                Point2D[] id10 = id2(
                        centerAC, centerBC, rAC, rBC);
                if (id10.length == 2) {
                    double angle1 = 0;
                    double angle2 = 0;
                    List<Point2D> selected = new ArrayList<Point2D>();
                    if (Math.abs(id10[0].distance(A) - id10[0]
                            .distance(B)) < 1e-7) {                     
                        

                        selected.add(id10[0]);
                    }
                    if (Math.abs(id10[1].distance(A) - id10[1]
                            .distance(B)) < 1e-7) {
                        

                        selected.add(id10[1]);
                    }
                    if (selected.size() == 2) {
                        angle1 = Math.asin(ra / selected.get(0).distance(A));
                        angle2 = Math.asin(ra / selected.get(1).distance(A));
                        if (angle1 > angle2) {
                            printPoint(selected.get(0));
                        } else {
                            printPoint(selected.get(1));
                        }
                    } else if (selected.size() == 1){
                        printPoint(selected.get(0));
                    } else {
                        

                        System.out.println();                       
                    }
                } else if (id10.length == 1) {
                    if (id10[0].distance(A) == id10[0]
                            .distance(B)) {
                        printPoint(id10[0]);
                    }
                } else {
                    

                    System.out.println();
                }

            } else if (rb == rc) {
                

                

                Point2D[] id1 = id2(
                        centerAC, centerAB, rAC, rAB);
                if (id1.length == 2) {
                    double angle1 = 0;
                    double angle2 = 0;
                    List<Point2D> selected = new ArrayList<Point2D>();
                    if (Math.abs(id1[0].distance(B) - id1[0]
                            .distance(C)) < 1e-7) {
                        

                        selected.add(id1[0]);
                    }
                    if (Math.abs(id1[1].distance(B) - id1[1]
                            .distance(C))< 1e-7) {
                        

                        selected.add(id1[1]);
                    }
                    if (selected.size() == 2) {
                        angle1 = Math.asin(ra / selected.get(0).distance(A));
                        angle2 = Math.asin(ra / selected.get(1).distance(A));
                        if (angle1 > angle2) {
                            printPoint(selected.get(0));
                        } else {
                            printPoint(selected.get(1));
                        }
                    } else if (selected.size() == 1){
                        printPoint(selected.get(0));
                    } else {
                        

                        System.out.println();                       
                    }
                } else if (id1.length == 1) {
                    if (id1[0].distance(B) == id1[0]
                            .distance(C)) {
                        printPoint(id1[0]);
                    }
                } else {
                    

                    System.out.println();
                }
            } else if (ra == rc) {
                

                

                Point2D[] id15 = id2(
                        centerAB, centerBC, rAB, rBC);
                if (id15.length == 2) {
                    double angle1 = 0;
                    double angle2 = 0;
                    List<Point2D> selected = new ArrayList<Point2D>();
                    if (Math.abs(id15[0].distance(A) - id15[0]
                            .distance(C)) < 1e-7) {
                        

                        selected.add(id15[0]);
                    }
                    if (Math.abs(id15[1].distance(A) - id15[1]
                            .distance(C)) < 1e-7) {
                        

                        selected.add(id15[1]);
                    }
                    if (selected.size() == 2) {
                        angle1 = Math.asin(ra / selected.get(0).distance(A));
                        angle2 = Math.asin(ra / selected.get(1).distance(A));
                        if (angle1 > angle2) {
                            printPoint(selected.get(0));
                        } else {
                            printPoint(selected.get(1));
                        }
                    } else if (selected.size() == 1){
                        printPoint(selected.get(0));
                    } else {
                        

                        System.out.println();                       
                    }
                } else if (id15.length == 1) {
                    if (id15[0].distance(A) == id15[0]
                            .distance(C)) {
                        printPoint(id15[0]);
                    }
                } else {
                    

                    System.out.println();
                }

            } else {
                

                

                Point2D[] id10 = id2(
                        centerAC, centerBC, rAC, rBC);

                Point2D[] id15 = id2(
                        centerAB, centerBC, rAB, rBC);

                Point2D[] id3 = id2(
                        centerAB, centerAC, rAB, rAC);
                

                if (id10.length == 2) {
                    

                    double angle1 = Math.asin(ra
                            / id10[0].distance(A));
                    double angle2 = Math.asin(ra
                            / id10[1].distance(A));
                    if (angle1 > angle2) {
                        printPoint(id10[0]);
                    } else {
                        printPoint(id10[1]);
                    }
                } else if (id10.length == 1) {
                    printPoint(id10[0]);
                } else {
                    

                    System.out.println();
                }
            }
        }
    }

    private static void printPoint(Point2D id6) {
        

        System.out.println(id6.getX() + " " + id6.getY());
    }

    

    static Point2D[] getIJ(Point2D A, Point2D B, double ra, double rb) {
        double k = rb / ra;
        return new Point2D[] { id7(A, B, k, 1),
                id7(A, B, -k, 1) };
    }

    

    static Point2D id7(Point2D p1, Point2D p2, double w1, double w2) {
        if (w1 + w2 == 0) {
            return new Point2D.Double(java.lang.Double.POSITIVE_INFINITY,
                    java.lang.Double.POSITIVE_INFINITY);
        } else {
            return new Point2D.Double((w1 * p1.getX() + w2 * p2.getX())
                    / (w1 + w2), (w1 * p1.getY() + w2 * p2.getY()) / (w1 + w2));
        }
    }

    static Point2D[] id2(Point2D A, Point2D B,
            double ra, double rb) {
        double dist = A.distance(B);
        if (dist < ra + rb) {
            

            double ux = 0;
            double uy = 0;
            ux = (B.getX() - A.getX()) / dist;
            uy = (B.getY() - A.getY()) / dist;
            double vx = -uy;
            double vy = ux;
            double x = (dist + (ra * ra - rb * rb) / dist) / 2.0;
            double y = Math.sqrt(ra * ra - x * x);
            return new Point2D.Double[] {
                    new Point2D.Double(A.getX() + ux * x + vx * y, A.getY()
                            + uy * x + vy * y),
                    new Point2D.Double(A.getX() + ux * x - vx * y, A.getY()
                            + uy * x - vy * y) };
        } else if (dist == ra + rb) {
            

            double ux = 0;
            double uy = 0;
            ux = (B.getX() - A.getX()) / dist;
            uy = (B.getY() - A.getY()) / dist;
            return new Point2D.Double[] { new Point2D.Double(
                    A.getX() + ux * ra, A.getY() + uy * ra) };
        } else {
            

            return new Point2D.Double[0];
        }

    }

    
    static Point2D[] getIntersection(Point2D A, Point2D B, double ra, double rb) {
        double a = 2 * (B.getX() - A.getX());
        double b = 2 * (B.getY() - A.getY());
        double c = (B.getX() - A.getX()) * (B.getX() - A.getX())
                + (B.getY() - A.getY()) * (B.getY() - A.getY()) - rb * rb + ra
                * ra;
        double delta = (2.0 * a * c) * (2.0 * a * c) - 4.0 * (a * a + b * b)
                * (c * c - b * b * ra * ra);
        if (delta < 0)
            return new Point2D[0];
        double xp = A.getX() + (2.0 * a * c - Math.sqrt(delta))
                / (2.0 * (a * a + b * b));
        double xq = A.getX() + (2.0 * a * c + Math.sqrt(delta))
                / (2.0 * (a * a + b * b));
        double yp = 0;
        double yq = 0;
        if (b == 0) {
            yp = A.getY()
                    + b
                    / 2.0
                    + Math.sqrt(rb * rb - ((2.0 * c - a * a) / (2.0 * a))
                            * ((2.0 * c - a * a) / (2.0 * a)));
            yq = A.getY()
                    + b
                    / 2.0
                    - Math.sqrt(rb * rb - ((2.0 * c - a * a) / (2.0 * a))
                            * ((2.0 * c - a * a) / (2.0 * a)));
        } else {
            yp = A.getY() + (c - a * (xp - A.getX())) / b;
            yq = A.getY() + (c - a * (xq - A.getX())) / b;
        }
        return new Point2D.Double[] { new Point2D.Double(xp, yp),
                new Point2D.Double(xq, yq) };
    }

    
    static Point2D[] id5(Point2D A1, Point2D A2,
            Point2D B1, Point2D B2) {
        

        

        

        double a1 = -(A2.getY() - A1.getY());
        double b1 = A2.getX() - A1.getX();
        double c1 = A1.getX() * a1 + A1.getY() * b1;

        double a2 = -(B2.getY() - B1.getY());
        double b2 = B2.getX() - B1.getX();
        double c2 = B1.getX() * a2 + B1.getY() * b2;

        double delta = (a1 * b2 - a2 * b1);
        double id14 = (c1 * b2 - c2 * b1);
        double id0 = (a1 * c2 - a2 * c1);

        if (delta == 0) {
            return new Point2D.Double[0];
        } else {
            return new Point2D.Double[] { new Point2D.Double(id14 / delta,
                    id0 / delta) };
        }

    }
}
