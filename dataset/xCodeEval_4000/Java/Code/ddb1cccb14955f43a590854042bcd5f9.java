import java.io.*;
import java.util.*;

public class E_359_div2
{
    public static final Random RANDOM = new Random(System.currentTimeMillis());
    private static BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer stringTokenizer = null;
    private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

    private static String next() throws IOException
    {
        while ((stringTokenizer == null) || (!stringTokenizer.hasMoreTokens()))
        {
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        }
        return stringTokenizer.nextToken();
    }

    public static int nextInt() throws IOException
    {
        return Integer.parseInt(next());
    }

    public static double nextDouble() throws IOException
    {
        return Double.parseDouble(next());
    }

    public static long nextLong() throws IOException
    {
        return Long.parseLong(next());
    }

    public static String nextLine() throws IOException
    {
        return bufferedReader.readLine();
    }

    public static void close()
    {
        out.close();
    }

    public static final long[] POWER2 = generatePOWER2();

    public static long[] generatePOWER2()
    {
        long[] result = new long[63];
        for (int x = 0; x < result.length; x++)
        {
            result[x] = 1L << x;
        }
        return result;
    }

    public static class Tuple2<T0, T1>
    {
        public final T0 v0;
        public final T1 v1;

        public Tuple2(T0 v0, T1 v1)
        {
            this.v0 = v0;
            this.v1 = v1;
        }
    }

    public static void main(String[] args)
    {
        try
        {
            solve();
        } catch (IOException exception)
        {
            exception.printStackTrace();
        }
        close();
    }

    static class Point3D
    {
        public long x;
        public long y;
        public long z;

        public Point3D(long x, long y, long z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public long manhattan(long x, long y, long z)
        {
            return Math.abs(this.x - x) + Math.abs(this.y - y) + Math.abs(this.z - z);
        }

        public void manhattanVector(long x, long y, long z, long step, long[] result)
        {
            long xMinus = x - step;
            long xPlus = x + step;
            long yMinus = y - step;
            long yPlus = y + step;
            long zMinus = z - step;
            long zPlus = z + step;
            long absXMinus = Math.abs(this.x - xMinus);
            long absX = Math.abs(this.x - x);
            long absXPlus = Math.abs(this.x - xPlus);
            long absYMinus = Math.abs(this.y - yMinus);
            long absY = Math.abs(this.y - y);
            long absYPlus = Math.abs(this.y - yPlus);
            long absZMinus = Math.abs(this.z - zMinus);
            long absZ = Math.abs(this.z - z);
            long absZPlus = Math.abs(this.z - zPlus);

            result[0 * 9 + 0] = Math.max(result[0 * 9 + 0], absXMinus + absYMinus + absZMinus);
            result[0 * 9 + 1] = Math.max(result[0 * 9 + 1], absXMinus + absYMinus + absZ);
            result[0 * 9 + 2] = Math.max(result[0 * 9 + 2], absXMinus + absYMinus + absZPlus);
            result[0 * 9 + 3] = Math.max(result[0 * 9 + 3], absXMinus + absY + absZMinus);
            result[0 * 9 + 4] = Math.max(result[0 * 9 + 4], absXMinus + absY + absZ);
            result[0 * 9 + 5] = Math.max(result[0 * 9 + 5], absXMinus + absY + absZPlus);
            result[0 * 9 + 6] = Math.max(result[0 * 9 + 6], absXMinus + absYPlus + absZMinus);
            result[0 * 9 + 7] = Math.max(result[0 * 9 + 7], absXMinus + absYPlus + absZ);
            result[0 * 9 + 8] = Math.max(result[0 * 9 + 8], absXMinus + absYPlus + absZPlus);

            result[1 * 9 + 0] = Math.max(result[1 * 9 + 0], absX + absYMinus + absZMinus);
            result[1 * 9 + 1] = Math.max(result[1 * 9 + 1], absX + absYMinus + absZ);
            result[1 * 9 + 2] = Math.max(result[1 * 9 + 2], absX + absYMinus + absZPlus);
            result[1 * 9 + 3] = Math.max(result[1 * 9 + 3], absX + absY + absZMinus);
            result[1 * 9 + 4] = Math.max(result[1 * 9 + 4], absX + absY + absZ);
            result[1 * 9 + 5] = Math.max(result[1 * 9 + 5], absX + absY + absZPlus);
            result[1 * 9 + 6] = Math.max(result[1 * 9 + 6], absX + absYPlus + absZMinus);
            result[1 * 9 + 7] = Math.max(result[1 * 9 + 7], absX + absYPlus + absZ);
            result[1 * 9 + 8] = Math.max(result[1 * 9 + 8], absX + absYPlus + absZPlus);

            result[2 * 9 + 0] = Math.max(result[2 * 9 + 0], absXPlus + absYMinus + absZMinus);
            result[2 * 9 + 1] = Math.max(result[2 * 9 + 1], absXPlus + absYMinus + absZ);
            result[2 * 9 + 2] = Math.max(result[2 * 9 + 2], absXPlus + absYMinus + absZPlus);
            result[2 * 9 + 3] = Math.max(result[2 * 9 + 3], absXPlus + absY + absZMinus);
            result[2 * 9 + 4] = Math.max(result[2 * 9 + 4], absXPlus + absY + absZ);
            result[2 * 9 + 5] = Math.max(result[2 * 9 + 5], absXPlus + absY + absZPlus);
            result[2 * 9 + 6] = Math.max(result[2 * 9 + 6], absXPlus + absYPlus + absZMinus);
            result[2 * 9 + 7] = Math.max(result[2 * 9 + 7], absXPlus + absYPlus + absZ);
            result[2 * 9 + 8] = Math.max(result[2 * 9 + 8], absXPlus + absYPlus + absZPlus);
        }

        @Override
        public String toString()
        {
            return this.x + " " + this.y + " " + this.z;
        }
    }

    public static long manhattan(Point3D[] roses, long x, long y, long z)
    {
        long result = 0;
        for (int index = 0; index < roses.length; index++)
        {
            long manhattan = roses[index].manhattan(x, y, z);
            result = Math.max(result, manhattan);
        }
        return result;
    }

    public static long manhattan(Point3D[] roses, Point3D point)
    {
        return manhattan(roses, point.x, point.y, point.z);
    }

    public static void manhattanVector(Point3D[] roses, long x, long y, long z, long step, long[] result)
    {
        Arrays.fill(result, 0);
        for (int index = 0; index < roses.length; index++)
        {
            roses[index].manhattanVector(x, y, z, step, result);
        }
    }

    public static void moveVector(Point3D[] roses, long step, Point3D result, long[] manhattan)
    {
        long x = result.x;
        long y = result.y;
        long z = result.z;
        manhattanVector(roses, x, y, z, step, manhattan);
        long manhattanMinimum = manhattan[1 * 9 + 4];

        if (manhattan[0 * 9 + 0] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[0 * 9 + 0];
            result.x = x - step;
            result.y = y - step;
            result.z = z - step;
        }
        if (manhattan[0 * 9 + 1] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[0 * 9 + 1];
            result.x = x - step;
            result.y = y - step;
            result.z = z;
        }
        if (manhattan[0 * 9 + 2] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[0 * 9 + 2];
            result.x = x - step;
            result.y = y - step;
            result.z = z + step;
        }
        if (manhattan[0 * 9 + 3] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[0 * 9 + 3];
            result.x = x - step;
            result.y = y;
            result.z = z - step;
        }
        if (manhattan[0 * 9 + 4] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[0 * 9 + 4];
            result.x = x - step;
            result.y = y;
            result.z = z;
        }
        if (manhattan[0 * 9 + 5] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[0 * 9 + 5];
            result.x = x - step;
            result.y = y;
            result.z = z + step;
        }
        if (manhattan[0 * 9 + 6] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[0 * 9 + 6];
            result.x = x - step;
            result.y = y + step;
            result.z = z - step;
        }
        if (manhattan[0 * 9 + 7] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[0 * 9 + 7];
            result.x = x - step;
            result.y = y + step;
            result.z = z;
        }
        if (manhattan[0 * 9 + 8] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[0 * 9 + 8];
            result.x = x - step;
            result.y = y + step;
            result.z = z + step;
        }

        if (manhattan[1 * 9 + 0] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[1 * 9 + 0];
            result.x = x;
            result.y = y - step;
            result.z = z - step;
        }
        if (manhattan[1 * 9 + 1] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[1 * 9 + 1];
            result.x = x;
            result.y = y - step;
            result.z = z;
        }
        if (manhattan[1 * 9 + 2] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[1 * 9 + 2];
            result.x = x;
            result.y = y - step;
            result.z = z + step;
        }
        if (manhattan[1 * 9 + 3] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[1 * 9 + 3];
            result.x = x;
            result.y = y;
            result.z = z - step;
        }














        if (manhattan[1 * 9 + 5] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[1 * 9 + 5];
            result.x = x;
            result.y = y;
            result.z = z + step;
        }
        if (manhattan[1 * 9 + 6] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[1 * 9 + 6];
            result.x = x;
            result.y = y + step;
            result.z = z - step;
        }
        if (manhattan[1 * 9 + 7] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[1 * 9 + 7];
            result.x = x;
            result.y = y + step;
            result.z = z;
        }
        if (manhattan[1 * 9 + 8] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[1 * 9 + 8];
            result.x = x;
            result.y = y + step;
            result.z = z + step;
        }

        if (manhattan[2 * 9 + 0] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[2 * 9 + 0];
            result.x = x + step;
            result.y = y - step;
            result.z = z - step;
        }
        if (manhattan[2 * 9 + 1] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[2 * 9 + 1];
            result.x = x + step;
            result.y = y - step;
            result.z = z;
        }
        if (manhattan[2 * 9 + 2] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[2 * 9 + 2];
            result.x = x + step;
            result.y = y - step;
            result.z = z + step;
        }
        if (manhattan[2 * 9 + 3] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[2 * 9 + 3];
            result.x = x + step;
            result.y = y;
            result.z = z - step;
        }
        if (manhattan[2 * 9 + 4] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[2 * 9 + 4];
            result.x = x + step;
            result.y = y;
            result.z = z;
        }
        if (manhattan[2 * 9 + 5] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[2 * 9 + 5];
            result.x = x + step;
            result.y = y;
            result.z = z + step;
        }
        if (manhattan[2 * 9 + 6] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[2 * 9 + 6];
            result.x = x + step;
            result.y = y + step;
            result.z = z - step;
        }
        if (manhattan[2 * 9 + 7] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[2 * 9 + 7];
            result.x = x + step;
            result.y = y + step;
            result.z = z;
        }
        if (manhattan[2 * 9 + 8] < manhattanMinimum)
        {
            manhattanMinimum = manhattan[2 * 9 + 8];
            result.x = x + step;
            result.y = y + step;
            result.z = z + step;
        }
    }

    public static long move(Point3D[] roses, Point3D pointCurrent, long result, long x, long y, long z)
    {

        long manhattan = manhattan(roses, x, y, z);
        if (manhattan < result)
        {
            result = manhattan;
            pointCurrent.x = x;
            pointCurrent.y = y;
            pointCurrent.z = z;
        }
        return result;
    }

    public static void move(Point3D[] roses, long step, Point3D result)
    {
        long x = result.x;
        long y = result.y;
        long z = result.z;
        long manhattan = manhattan(roses, x, y, z);

        manhattan = move(roses, result, manhattan, x - step, y - step, z - step);
        manhattan = move(roses, result, manhattan, x - step, y - step, z);
        manhattan = move(roses, result, manhattan, x - step, y - step, z + step);
        manhattan = move(roses, result, manhattan, x - step, y, z - step);
        manhattan = move(roses, result, manhattan, x - step, y, z);
        manhattan = move(roses, result, manhattan, x - step, y, z + step);
        manhattan = move(roses, result, manhattan, x - step, y + step, z - step);
        manhattan = move(roses, result, manhattan, x - step, y + step, z);
        manhattan = move(roses, result, manhattan, x - step, y + step, z + step);

        manhattan = move(roses, result, manhattan, x, y - step, z - step);
        manhattan = move(roses, result, manhattan, x, y - step, z);
        manhattan = move(roses, result, manhattan, x, y - step, z + step);
        manhattan = move(roses, result, manhattan, x, y, z - step);


        manhattan = move(roses, result, manhattan, x, y, z + step);
        manhattan = move(roses, result, manhattan, x, y + step, z - step);
        manhattan = move(roses, result, manhattan, x, y + step, z);
        manhattan = move(roses, result, manhattan, x, y + step, z + step);

        manhattan = move(roses, result, manhattan, x + step, y - step, z - step);
        manhattan = move(roses, result, manhattan, x + step, y - step, z);
        manhattan = move(roses, result, manhattan, x + step, y - step, z + step);
        manhattan = move(roses, result, manhattan, x + step, y, z - step);
        manhattan = move(roses, result, manhattan, x + step, y, z);
        manhattan = move(roses, result, manhattan, x + step, y, z + step);
        manhattan = move(roses, result, manhattan, x + step, y + step, z - step);
        manhattan = move(roses, result, manhattan, x + step, y + step, z);
        manhattan = move(roses, result, manhattan, x + step, y + step, z + step);
    }

    public static Point3D solve(Point3D[] roses)
    {
        Point3D result = new Point3D(0, 0, 0);
        long[] manhattan = new long[3 * 9];
        for (int stepIndex = 59; stepIndex >= 0; stepIndex--)
        {
            long step = POWER2[stepIndex];
            moveVector(roses, step, result, manhattan);
        }


        moveVector(roses, 1, result, manhattan);
        return result;
    }

    public static void solve() throws IOException
    {
        int t = nextInt();
        for (int test = 0; test < t; test++)
        {
            int n = nextInt();
            Point3D[] roses = new Point3D[n];
            for (int index = 0; index < n; index++)
            {
                roses[index] = new Point3D(nextLong(), nextLong(), nextLong());
            }
            Point3D point = solve(roses);
            out.println(point);
        }
    }
}