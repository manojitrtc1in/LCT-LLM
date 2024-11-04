import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.awt.geom.Point2D;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            double a = in.nextDouble();
            double b = in.nextDouble();
            double c = in.nextDouble();

            double x1 = in.nextInt();
            double y1 = in.nextInt();
            double x2 = in.nextInt();
            double y2 = in.nextInt();

            StraightLine2D d = StraightLine2D.createCartesian(a, b, c);

            


            math_geom2d_Point2D p1 = new math_geom2d_Point2D(x1, y1);
            math_geom2d_Point2D p2 = new math_geom2d_Point2D(x2, y2);

            double dist;

            

            StraightLine2D l1h = StraightLine2D.createHorizontal(p1);
            StraightLine2D l1v = StraightLine2D.createVertical(p1);

            StraightLine2D l2h = StraightLine2D.createHorizontal(p2);
            StraightLine2D l2v = StraightLine2D.createVertical(p2);


            

            math_geom2d_Point2D intersection = l1h.intersection(l2v);

            dist = intersection.distance(p1) + intersection.distance(p2);

            

            math_geom2d_Point2D intersection2 = l1h.intersection(d);
            math_geom2d_Point2D intersection3 = l1v.intersection(d);
            math_geom2d_Point2D intersection4 = l2h.intersection(d);
            math_geom2d_Point2D intersection5 = l2v.intersection(d);

            try {
                dist = Math.min(dist, intersection2.distance(p1) + intersection2.distance(intersection4) + intersection4.distance(p2));
            } catch (Exception e) {

            }

            try {
                dist = Math.min(dist, intersection3.distance(p1) + intersection3.distance(intersection4) + intersection4.distance(p2));
            } catch (Exception e) {

            }

            try {
                dist = Math.min(dist, intersection2.distance(p1) + intersection2.distance(intersection5) + intersection5.distance(p2));
            } catch (Exception e) {

            }

            try {
                dist = Math.min(dist, intersection3.distance(p1) + intersection3.distance(intersection5) + intersection5.distance(p2));
            } catch (Exception e) {

            }

            out.println(dist);


        }

    }

    static interface PointShape2D extends CirculinearShape2D, Iterable<math_geom2d_Point2D> {
    }

    static interface CirculinearBoundary2D extends CirculinearCurve2D, Boundary2D {
    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static interface LinearElement2D extends CirculinearElement2D, LinearShape2D {
    }

    static interface SmoothOrientedCurve2D extends SmoothCurve2D,
            ContinuousOrientedCurve2D {
    }

    static class StraightLine2D extends AbstractLine2D implements
            SmoothContour2D, Cloneable, CircleLine2D {
        public static StraightLine2D createHorizontal(math_geom2d_Point2D origin) {
            return new StraightLine2D(origin, new Vector2D(1, 0));
        }

        public static StraightLine2D createVertical(math_geom2d_Point2D origin) {
            return new StraightLine2D(origin, new Vector2D(0, 1));
        }

        public static StraightLine2D createCartesian(double a, double b, double c) {
            double d = a * a + b * b;
            double x0 = -a * c / d;
            double y0 = -b * c / d;
            double theta = Math.atan2(-a, b);
            double dx = Math.cos(theta);
            double dy = Math.sin(theta);

            return new StraightLine2D(x0, y0, dx, dy);
        }

        public StraightLine2D() {
            this(0, 0, 1, 0);
        }

        public StraightLine2D(math_geom2d_Point2D point1, math_geom2d_Point2D point2) {
            this(point1, new Vector2D(point1, point2));
        }

        public StraightLine2D(math_geom2d_Point2D point, Vector2D direction) {
            this(point.x(), point.y(), direction.x(), direction.y());
        }

        public StraightLine2D(math_geom2d_Point2D point, double dx, double dy) {
            this(point.x(), point.y(), dx, dy);
        }

        public StraightLine2D(math_geom2d_Point2D point, double angle) {
            this(point.x(), point.y(), Math.cos(angle), Math.sin(angle));
        }

        public StraightLine2D(double xp, double yp, double dx, double dy) {
            super(xp, yp, dx, dy);

            

            if (Math.hypot(dx, dy) < Shape2D.ACCURACY) {
                throw new IllegalArgumentException("Straight lines can not have direction vector with zero norm");
            }
        }

        public StraightLine2D(LinearShape2D line) {
            this(line.origin(), line.direction());
        }

        public StraightLine2D(LinearShape2D line, math_geom2d_Point2D point) {
            this(point, line.direction());
        }

        @Deprecated
        public StraightLine2D(double a, double b, double c) {
            this(0, 0, 1, 0);
            double d = a * a + b * b;
            x0 = -a * c / d;
            y0 = -b * c / d;
            double theta = Math.atan2(-a, b);
            dx = Math.cos(theta);
            dy = Math.sin(theta);
        }

        public double t0() {
            return Double.NEGATIVE_INFINITY;
        }

        public double t1() {
            return Double.POSITIVE_INFINITY;
        }


        public String toString() {
            return new String("StraightLine2D(" + x0 + "," + y0 + "," +
                    dx + "," + dy + ")");
        }


        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (!(obj instanceof StraightLine2D))
                return false;
            StraightLine2D that = (StraightLine2D) obj;

            

            if (!EqualUtils.areEqual(this.x0, that.x0))
                return false;
            if (!EqualUtils.areEqual(this.y0, that.y0))
                return false;
            if (!EqualUtils.areEqual(this.dx, that.dx))
                return false;
            if (!EqualUtils.areEqual(this.dy, that.dy))
                return false;

            return true;
        }


        public int hashCode() {
            int hash = 1;
            hash = hash * 31 + Double.valueOf(this.x0).hashCode();
            hash = hash * 31 + Double.valueOf(this.y0).hashCode();
            hash = hash * 31 + Double.valueOf(this.dx).hashCode();
            hash = hash * 31 + Double.valueOf(this.dy).hashCode();
            return hash;
        }

        @Deprecated

        public StraightLine2D clone() {
            return new StraightLine2D(x0, y0, dx, dy);
        }

    }

    static interface Contour2D extends Boundary2D, ContinuousOrientedCurve2D {
    }

    static interface GeometricObject2D {
    }

    static interface CircleLine2D extends CirculinearContour2D,
            CirculinearElement2D, SmoothContour2D {
    }

    static interface Curve2D extends Shape2D, Cloneable {
        public abstract double t0();

        public abstract double t1();

        @Deprecated
        public abstract Curve2D clone();

    }

    static class Vector2D implements GeometricObject2D, Cloneable {
        protected double x;
        protected double y;

        public Vector2D() {
            this(1, 0);
        }

        public Vector2D(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public Vector2D(math_geom2d_Point2D point) {
            this(point.x, point.y);
        }

        public Vector2D(math_geom2d_Point2D point1, math_geom2d_Point2D point2) {
            this(point2.x - point1.x, point2.y - point1.y);
        }

        public double x() {
            return this.x;
        }

        public double y() {
            return this.y;
        }


        public boolean equals(Object obj) {
            if (this == obj)
                return true;

            if (!(obj instanceof Vector2D))
                return false;
            Vector2D that = (Vector2D) obj;

            

            if (!EqualUtils.areEqual(this.x, that.x))
                return false;
            if (!EqualUtils.areEqual(this.y, that.y))
                return false;

            return true;
        }


        public int hashCode() {
            int hash = 1;
            hash = hash * 31 + Double.valueOf(this.x).hashCode();
            hash = hash * 31 + Double.valueOf(this.y).hashCode();
            return hash;
        }


        public String toString() {
            return new String("x=" + x + " y=" + y);
        }

        @Deprecated

        public Vector2D clone() {
            return new Vector2D(x, y);
        }

    }

    static interface ContinuousOrientedCurve2D extends ContinuousCurve2D,
            OrientedCurve2D {
    }

    static abstract class AbstractSmoothCurve2D extends AbstractContinuousCurve2D implements SmoothCurve2D, Cloneable {
        @Deprecated

        public abstract SmoothCurve2D clone();

    }

    static final class EqualUtils {
        static public boolean areEqual(double aThis, double aThat) {
            

            return Double.doubleToLongBits(aThis) == Double.doubleToLongBits(aThat);
        }

    }

    static interface ContinuousCurve2D extends Curve2D {
    }

    static interface CirculinearElement2D extends CirculinearContinuousCurve2D,
            SmoothOrientedCurve2D {
    }

    static interface SmoothContour2D extends SmoothOrientedCurve2D, Contour2D {
    }

    static interface Shape2D extends GeometricObject2D {
        public final static double ACCURACY = 1e-12;

    }

    static interface CirculinearContinuousCurve2D extends CirculinearCurve2D, ContinuousOrientedCurve2D {
    }

    static abstract class AbstractContinuousCurve2D implements ContinuousCurve2D, Cloneable {
        @Deprecated

        public abstract ContinuousCurve2D clone();

    }

    static interface OrientedCurve2D extends Curve2D {
    }

    static interface CirculinearShape2D extends Shape2D {
    }

    static interface LinearShape2D extends CirculinearCurve2D {
        public abstract math_geom2d_Point2D origin();

        public abstract Vector2D direction();

        public boolean containsProjection(math_geom2d_Point2D point);

    }

    static class DegeneratedLine2DException extends RuntimeException {
        protected LinearShape2D line;

        public DegeneratedLine2DException(String msg, LinearShape2D line) {
            super(msg);
            this.line = line;
        }

        public DegeneratedLine2DException(LinearShape2D line) {
            super();
            this.line = line;
        }

    }

    static interface CirculinearCurve2D extends CirculinearShape2D, Curve2D {
    }

    static interface SmoothCurve2D extends ContinuousCurve2D {
    }

    static abstract class AbstractLine2D extends AbstractSmoothCurve2D implements SmoothOrientedCurve2D, LinearElement2D {
        protected double x0;
        protected double y0;
        protected double dx;
        protected double dy;

        protected AbstractLine2D(double x0, double y0, double dx, double dy) {
            this.x0 = x0;
            this.y0 = y0;
            this.dx = dx;
            this.dy = dy;
        }

        protected AbstractLine2D(math_geom2d_Point2D point, Vector2D vector) {
            this.x0 = point.x();
            this.y0 = point.y();
            this.dx = vector.x();
            this.dy = vector.y();
        }

        public double positionOnLine(math_geom2d_Point2D point) {
            return positionOnLine(point.x(), point.y());
        }

        public double positionOnLine(double x, double y) {
            double denom = dx * dx + dy * dy;
            if (Math.abs(denom) < Shape2D.ACCURACY)
                throw new DegeneratedLine2DException(this);
            return ((y - y0) * dy + (x - x0) * dx) / denom;
        }

        public math_geom2d_Point2D origin() {
            return new math_geom2d_Point2D(x0, y0);
        }

        public Vector2D direction() {
            return new Vector2D(dx, dy);
        }

        public math_geom2d_Point2D intersection(LinearShape2D line) {
            Vector2D vect = line.direction();
            double dx2 = vect.x();
            double dy2 = vect.y();

            

            double denom = this.dx * dy2 - this.dy * dx2;
            if (Math.abs(denom) < Shape2D.ACCURACY)
                return null;

            

            math_geom2d_Point2D origin = line.origin();
            double x2 = origin.x();
            double y2 = origin.y();
            double t = ((y0 - y2) * dx2 - (x0 - x2) * dy2) / denom;

            

            math_geom2d_Point2D point = new math_geom2d_Point2D(x0 + t * dx, y0 + t * dy);

            

            

            if (containsProjection(point) && line.containsProjection(point))
                return point;
            return null;
        }


        public boolean containsProjection(math_geom2d_Point2D point) {
            double pos = this.positionOnLine(point);
            return pos > (this.t0() - Shape2D.ACCURACY) && pos < (this.t1() + Shape2D.ACCURACY);
        }

        @Deprecated

        public abstract AbstractLine2D clone();

    }

    static interface CirculinearContour2D extends Contour2D,
            CirculinearContinuousCurve2D, CirculinearBoundary2D {
    }

    static class math_geom2d_Point2D implements GeometricObject2D, PointShape2D, Cloneable, CirculinearShape2D {
        protected double x;
        protected double y;

        public math_geom2d_Point2D() {
        }

        public math_geom2d_Point2D(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public math_geom2d_Point2D(java.awt.geom.Point2D point) {
            this(point.getX(), point.getY());
        }

        @Deprecated
        public math_geom2d_Point2D(math_geom2d_Point2D point) {
            this(point.x, point.y);
        }

        public double x() {
            return x;
        }

        public double y() {
            return y;
        }

        public Collection<math_geom2d_Point2D> points() {
            ArrayList<math_geom2d_Point2D> array = new ArrayList<math_geom2d_Point2D>(1);
            array.add(this);
            return array;
        }

        public double distance(math_geom2d_Point2D point) {
            return distance(point.x, point.y);
        }

        public double distance(double x, double y) {
            return Math.hypot(this.x - x, this.y - y);
        }

        public Iterator<math_geom2d_Point2D> iterator() {
            return this.points().iterator();
        }


        public String toString() {
            return new String("Point2D(" + x + ", " + y + ")");
        }


        public boolean equals(Object obj) {
            if (this == obj)
                return true;

            if (!(obj instanceof math_geom2d_Point2D))
                return false;
            math_geom2d_Point2D that = (math_geom2d_Point2D) obj;

            

            if (!EqualUtils.areEqual(this.x, that.x))
                return false;
            if (!EqualUtils.areEqual(this.y, that.y))
                return false;

            return true;
        }

        @Deprecated

        public math_geom2d_Point2D clone() {
            return new math_geom2d_Point2D(x, y);
        }


        public int hashCode() {
            int hash = 1;
            hash = hash * 31 + Double.valueOf(this.x).hashCode();
            hash = hash * 31 + Double.valueOf(this.y).hashCode();
            return hash;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public double nextDouble() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, nextInt());
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, nextInt());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static interface Boundary2D extends OrientedCurve2D {
    }
}

