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

            id31 d = id31.createCartesian(a, b, c);

            


            id28 p1 = new id28(x1, y1);
            id28 p2 = new id28(x2, y2);

            double dist;

            

            id31 id16 = id31.createHorizontal(p1);
            id31 id15 = id31.createVertical(p1);

            id31 id1 = id31.createHorizontal(p2);
            id31 id11 = id31.createVertical(p2);


            

            id28 intersection = id16.intersection(id11);

            dist = intersection.distance(p1) + intersection.distance(p2);

            

            id28 intersection2 = id16.intersection(d);
            id28 intersection3 = id15.intersection(d);
            id28 intersection4 = id1.intersection(d);
            id28 intersection5 = id11.intersection(d);

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

    static interface id13 extends id6, Iterable<id28> {
    }

    static interface id17 extends id29, id9 {
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

    static interface id27 extends id7, id12 {
    }

    static interface id25 extends id32,
            id10 {
    }

    static class id31 extends id30 implements
            id19, Cloneable, id26 {
        public static id31 createHorizontal(id28 origin) {
            return new id31(origin, new id18(1, 0));
        }

        public static id31 createVertical(id28 origin) {
            return new id31(origin, new id18(0, 1));
        }

        public static id31 createCartesian(double a, double b, double c) {
            double d = a * a + b * b;
            double x0 = -a * c / d;
            double y0 = -b * c / d;
            double theta = Math.atan2(-a, b);
            double dx = Math.cos(theta);
            double dy = Math.sin(theta);

            return new id31(x0, y0, dx, dy);
        }

        public id31() {
            this(0, 0, 1, 0);
        }

        public id31(id28 point1, id28 point2) {
            this(point1, new id18(point1, point2));
        }

        public id31(id28 point, id18 direction) {
            this(point.x(), point.y(), direction.x(), direction.y());
        }

        public id31(id28 point, double dx, double dy) {
            this(point.x(), point.y(), dx, dy);
        }

        public id31(id28 point, double angle) {
            this(point.x(), point.y(), Math.cos(angle), Math.sin(angle));
        }

        public id31(double xp, double yp, double dx, double dy) {
            super(xp, yp, dx, dy);

            

            if (Math.hypot(dx, dy) < id3.id0) {
                throw new IllegalArgumentException("Straight lines can not have direction vector with zero norm");
            }
        }

        public id31(id12 line) {
            this(line.origin(), line.direction());
        }

        public id31(id12 line, id28 point) {
            this(point, line.direction());
        }

        @Deprecated
        public id31(double a, double b, double c) {
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
            return new String("id31(" + x0 + "," + y0 + "," +
                    dx + "," + dy + ")");
        }


        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (!(obj instanceof id31))
                return false;
            id31 that = (id31) obj;

            

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

        public id31 clone() {
            return new id31(x0, y0, dx, dy);
        }

    }

    static interface id2 extends id9, id10 {
    }

    static interface id33 {
    }

    static interface id26 extends id23,
            id7, id19 {
    }

    static interface id8 extends id3, Cloneable {
        public abstract double t0();

        public abstract double t1();

        @Deprecated
        public abstract id8 clone();

    }

    static class id18 implements id33, Cloneable {
        protected double x;
        protected double y;

        public id18() {
            this(1, 0);
        }

        public id18(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public id18(id28 point) {
            this(point.x, point.y);
        }

        public id18(id28 point1, id28 point2) {
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

            if (!(obj instanceof id18))
                return false;
            id18 that = (id18) obj;

            

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

        public id18 clone() {
            return new id18(x, y);
        }

    }

    static interface id10 extends id34,
            id14 {
    }

    static abstract class id21 extends id24 implements id32, Cloneable {
        @Deprecated

        public abstract id32 clone();

    }

    static final class EqualUtils {
        static public boolean areEqual(double aThis, double aThat) {
            

            return Double.doubleToLongBits(aThis) == Double.doubleToLongBits(aThat);
        }

    }

    static interface id34 extends id8 {
    }

    static interface id7 extends id20,
            id25 {
    }

    static interface id19 extends id25, id2 {
    }

    static interface id3 extends id33 {
        public final static double id0 = 1e-12;

    }

    static interface id20 extends id29, id10 {
    }

    static abstract class id24 implements id34, Cloneable {
        @Deprecated

        public abstract id34 clone();

    }

    static interface id14 extends id8 {
    }

    static interface id6 extends id3 {
    }

    static interface id12 extends id29 {
        public abstract id28 origin();

        public abstract id18 direction();

        public boolean containsProjection(id28 point);

    }

    static class id22 extends RuntimeException {
        protected id12 line;

        public id22(String msg, id12 line) {
            super(msg);
            this.line = line;
        }

        public id22(id12 line) {
            super();
            this.line = line;
        }

    }

    static interface id29 extends id6, id8 {
    }

    static interface id32 extends id34 {
    }

    static abstract class id30 extends id21 implements id25, id27 {
        protected double x0;
        protected double y0;
        protected double dx;
        protected double dy;

        protected id30(double x0, double y0, double dx, double dy) {
            this.x0 = x0;
            this.y0 = y0;
            this.dx = dx;
            this.dy = dy;
        }

        protected id30(id28 point, id18 vector) {
            this.x0 = point.x();
            this.y0 = point.y();
            this.dx = vector.x();
            this.dy = vector.y();
        }

        public double id4(id28 point) {
            return id4(point.x(), point.y());
        }

        public double id4(double x, double y) {
            double denom = dx * dx + dy * dy;
            if (Math.abs(denom) < id3.id0)
                throw new id22(this);
            return ((y - y0) * dy + (x - x0) * dx) / denom;
        }

        public id28 origin() {
            return new id28(x0, y0);
        }

        public id18 direction() {
            return new id18(dx, dy);
        }

        public id28 intersection(id12 line) {
            id18 vect = line.direction();
            double dx2 = vect.x();
            double dy2 = vect.y();

            

            double denom = this.dx * dy2 - this.dy * dx2;
            if (Math.abs(denom) < id3.id0)
                return null;

            

            id28 origin = line.origin();
            double x2 = origin.x();
            double y2 = origin.y();
            double t = ((y0 - y2) * dx2 - (x0 - x2) * dy2) / denom;

            

            id28 point = new id28(x0 + t * dx, y0 + t * dy);

            

            

            if (containsProjection(point) && line.containsProjection(point))
                return point;
            return null;
        }


        public boolean containsProjection(id28 point) {
            double pos = this.id4(point);
            return pos > (this.t0() - id3.id0) && pos < (this.t1() + id3.id0);
        }

        @Deprecated

        public abstract id30 clone();

    }

    static interface id23 extends id2,
            id20, id17 {
    }

    static class id28 implements id33, id13, Cloneable, id6 {
        protected double x;
        protected double y;

        public id28() {
        }

        public id28(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public id28(java.awt.geom.Point2D point) {
            this(point.getX(), point.getY());
        }

        @Deprecated
        public id28(id28 point) {
            this(point.x, point.y);
        }

        public double x() {
            return x;
        }

        public double y() {
            return y;
        }

        public Collection<id28> points() {
            ArrayList<id28> array = new ArrayList<id28>(1);
            array.add(this);
            return array;
        }

        public double distance(id28 point) {
            return distance(point.x, point.y);
        }

        public double distance(double x, double y) {
            return Math.hypot(this.x - x, this.y - y);
        }

        public Iterator<id28> iterator() {
            return this.points().iterator();
        }


        public String toString() {
            return new String("Point2D(" + x + ", " + y + ")");
        }


        public boolean equals(Object obj) {
            if (this == obj)
                return true;

            if (!(obj instanceof id28))
                return false;
            id28 that = (id28) obj;

            

            if (!EqualUtils.areEqual(this.x, that.x))
                return false;
            if (!EqualUtils.areEqual(this.y, that.y))
                return false;

            return true;
        }

        @Deprecated

        public id28 clone() {
            return new id28(x, y);
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
        private InputReader.id35 filter;

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
            while (id5(c)) {
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
            } while (!id5(c));
            return res * sgn;
        }

        public boolean id5(int c) {
            if (filter != null) {
                return filter.id5(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public double nextDouble() {
            int c = read();
            while (id5(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id5(c) && c != '.') {
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
                while (!id5(c)) {
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

        public interface id35 {
            public boolean id5(int ch);

        }

    }

    static interface id9 extends id14 {
    }
}

