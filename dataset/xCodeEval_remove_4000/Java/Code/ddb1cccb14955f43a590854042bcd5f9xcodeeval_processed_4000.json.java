import java.io.*;
import java.util.*;

public class id11
{
    public static final Random RANDOM = new Random(System.currentTimeMillis());
    private static BufferedReader id5 = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer stringTokenizer = null;
    private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

    private static String next() throws IOException
    {
        while ((stringTokenizer == null) || (!stringTokenizer.hasMoreTokens()))
        {
            stringTokenizer = new StringTokenizer(id5.readLine());
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
        return id5.readLine();
    }

    public static void close()
    {
        out.close();
    }

    public static final long[] POWER2 = id9();

    public static long[] id9()
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

    static class id1
    {
        public long x;
        public long y;
        public long z;

        public id1(long x, long y, long z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public long manhattan(long x, long y, long z)
        {
            return Math.abs(this.x - x) + Math.abs(this.y - y) + Math.abs(this.z - z);
        }

        public void id3(long x, long y, long z, long step, long[] result)
        {
            long xMinus = x - step;
            long xPlus = x + step;
            long yMinus = y - step;
            long yPlus = y + step;
            long zMinus = z - step;
            long zPlus = z + step;
            long id6 = Math.abs(this.x - xMinus);
            long absX = Math.abs(this.x - x);
            long id4 = Math.abs(this.x - xPlus);
            long id2 = Math.abs(this.y - yMinus);
            long absY = Math.abs(this.y - y);
            long id8 = Math.abs(this.y - yPlus);
            long id10 = Math.abs(this.z - zMinus);
            long absZ = Math.abs(this.z - z);
            long id0 = Math.abs(this.z - zPlus);

            result[0 * 9 + 0] = Math.max(result[0 * 9 + 0], id6 + id2 + id10);
            result[0 * 9 + 1] = Math.max(result[0 * 9 + 1], id6 + id2 + absZ);
            result[0 * 9 + 2] = Math.max(result[0 * 9 + 2], id6 + id2 + id0);
            result[0 * 9 + 3] = Math.max(result[0 * 9 + 3], id6 + absY + id10);
            result[0 * 9 + 4] = Math.max(result[0 * 9 + 4], id6 + absY + absZ);
            result[0 * 9 + 5] = Math.max(result[0 * 9 + 5], id6 + absY + id0);
            result[0 * 9 + 6] = Math.max(result[0 * 9 + 6], id6 + id8 + id10);
            result[0 * 9 + 7] = Math.max(result[0 * 9 + 7], id6 + id8 + absZ);
            result[0 * 9 + 8] = Math.max(result[0 * 9 + 8], id6 + id8 + id0);

            result[1 * 9 + 0] = Math.max(result[1 * 9 + 0], absX + id2 + id10);
            result[1 * 9 + 1] = Math.max(result[1 * 9 + 1], absX + id2 + absZ);
            result[1 * 9 + 2] = Math.max(result[1 * 9 + 2], absX + id2 + id0);
            result[1 * 9 + 3] = Math.max(result[1 * 9 + 3], absX + absY + id10);
            result[1 * 9 + 4] = Math.max(result[1 * 9 + 4], absX + absY + absZ);
            result[1 * 9 + 5] = Math.max(result[1 * 9 + 5], absX + absY + id0);
            result[1 * 9 + 6] = Math.max(result[1 * 9 + 6], absX + id8 + id10);
            result[1 * 9 + 7] = Math.max(result[1 * 9 + 7], absX + id8 + absZ);
            result[1 * 9 + 8] = Math.max(result[1 * 9 + 8], absX + id8 + id0);

            result[2 * 9 + 0] = Math.max(result[2 * 9 + 0], id4 + id2 + id10);
            result[2 * 9 + 1] = Math.max(result[2 * 9 + 1], id4 + id2 + absZ);
            result[2 * 9 + 2] = Math.max(result[2 * 9 + 2], id4 + id2 + id0);
            result[2 * 9 + 3] = Math.max(result[2 * 9 + 3], id4 + absY + id10);
            result[2 * 9 + 4] = Math.max(result[2 * 9 + 4], id4 + absY + absZ);
            result[2 * 9 + 5] = Math.max(result[2 * 9 + 5], id4 + absY + id0);
            result[2 * 9 + 6] = Math.max(result[2 * 9 + 6], id4 + id8 + id10);
            result[2 * 9 + 7] = Math.max(result[2 * 9 + 7], id4 + id8 + absZ);
            result[2 * 9 + 8] = Math.max(result[2 * 9 + 8], id4 + id8 + id0);
        }

        @Override
        public String toString()
        {
            return this.x + " " + this.y + " " + this.z;
        }
    }

    public static long manhattan(id1[] roses, long x, long y, long z)
    {
        long result = 0;
        for (int index = 0; index < roses.length; index++)
        {
            long manhattan = roses[index].manhattan(x, y, z);
            result = Math.max(result, manhattan);
        }
        return result;
    }

    public static long manhattan(id1[] roses, id1 point)
    {
        return manhattan(roses, point.x, point.y, point.z);
    }

    public static void id3(id1[] roses, long x, long y, long z, long step, long[] result)
    {
        Arrays.fill(result, 0);
        for (int index = 0; index < roses.length; index++)
        {
            roses[index].id3(x, y, z, step, result);
        }
    }

    public static void moveVector(id1[] roses, long step, id1 result, long[] manhattan)
    {
        long x = result.x;
        long y = result.y;
        long z = result.z;
        id3(roses, x, y, z, step, manhattan);
        long id7 = manhattan[1 * 9 + 4];

        if (manhattan[0 * 9 + 0] < id7)
        {
            id7 = manhattan[0 * 9 + 0];
            result.x = x - step;
            result.y = y - step;
            result.z = z - step;
        }
        if (manhattan[0 * 9 + 1] < id7)
        {
            id7 = manhattan[0 * 9 + 1];
            result.x = x - step;
            result.y = y - step;
            result.z = z;
        }
        if (manhattan[0 * 9 + 2] < id7)
        {
            id7 = manhattan[0 * 9 + 2];
            result.x = x - step;
            result.y = y - step;
            result.z = z + step;
        }
        if (manhattan[0 * 9 + 3] < id7)
        {
            id7 = manhattan[0 * 9 + 3];
            result.x = x - step;
            result.y = y;
            result.z = z - step;
        }
        if (manhattan[0 * 9 + 4] < id7)
        {
            id7 = manhattan[0 * 9 + 4];
            result.x = x - step;
            result.y = y;
            result.z = z;
        }
        if (manhattan[0 * 9 + 5] < id7)
        {
            id7 = manhattan[0 * 9 + 5];
            result.x = x - step;
            result.y = y;
            result.z = z + step;
        }
        if (manhattan[0 * 9 + 6] < id7)
        {
            id7 = manhattan[0 * 9 + 6];
            result.x = x - step;
            result.y = y + step;
            result.z = z - step;
        }
        if (manhattan[0 * 9 + 7] < id7)
        {
            id7 = manhattan[0 * 9 + 7];
            result.x = x - step;
            result.y = y + step;
            result.z = z;
        }
        if (manhattan[0 * 9 + 8] < id7)
        {
            id7 = manhattan[0 * 9 + 8];
            result.x = x - step;
            result.y = y + step;
            result.z = z + step;
        }

        if (manhattan[1 * 9 + 0] < id7)
        {
            id7 = manhattan[1 * 9 + 0];
            result.x = x;
            result.y = y - step;
            result.z = z - step;
        }
        if (manhattan[1 * 9 + 1] < id7)
        {
            id7 = manhattan[1 * 9 + 1];
            result.x = x;
            result.y = y - step;
            result.z = z;
        }
        if (manhattan[1 * 9 + 2] < id7)
        {
            id7 = manhattan[1 * 9 + 2];
            result.x = x;
            result.y = y - step;
            result.z = z + step;
        }
        if (manhattan[1 * 9 + 3] < id7)
        {
            id7 = manhattan[1 * 9 + 3];
            result.x = x;
            result.y = y;
            result.z = z - step;
        }














        if (manhattan[1 * 9 + 5] < id7)
        {
            id7 = manhattan[1 * 9 + 5];
            result.x = x;
            result.y = y;
            result.z = z + step;
        }
        if (manhattan[1 * 9 + 6] < id7)
        {
            id7 = manhattan[1 * 9 + 6];
            result.x = x;
            result.y = y + step;
            result.z = z - step;
        }
        if (manhattan[1 * 9 + 7] < id7)
        {
            id7 = manhattan[1 * 9 + 7];
            result.x = x;
            result.y = y + step;
            result.z = z;
        }
        if (manhattan[1 * 9 + 8] < id7)
        {
            id7 = manhattan[1 * 9 + 8];
            result.x = x;
            result.y = y + step;
            result.z = z + step;
        }

        if (manhattan[2 * 9 + 0] < id7)
        {
            id7 = manhattan[2 * 9 + 0];
            result.x = x + step;
            result.y = y - step;
            result.z = z - step;
        }
        if (manhattan[2 * 9 + 1] < id7)
        {
            id7 = manhattan[2 * 9 + 1];
            result.x = x + step;
            result.y = y - step;
            result.z = z;
        }
        if (manhattan[2 * 9 + 2] < id7)
        {
            id7 = manhattan[2 * 9 + 2];
            result.x = x + step;
            result.y = y - step;
            result.z = z + step;
        }
        if (manhattan[2 * 9 + 3] < id7)
        {
            id7 = manhattan[2 * 9 + 3];
            result.x = x + step;
            result.y = y;
            result.z = z - step;
        }
        if (manhattan[2 * 9 + 4] < id7)
        {
            id7 = manhattan[2 * 9 + 4];
            result.x = x + step;
            result.y = y;
            result.z = z;
        }
        if (manhattan[2 * 9 + 5] < id7)
        {
            id7 = manhattan[2 * 9 + 5];
            result.x = x + step;
            result.y = y;
            result.z = z + step;
        }
        if (manhattan[2 * 9 + 6] < id7)
        {
            id7 = manhattan[2 * 9 + 6];
            result.x = x + step;
            result.y = y + step;
            result.z = z - step;
        }
        if (manhattan[2 * 9 + 7] < id7)
        {
            id7 = manhattan[2 * 9 + 7];
            result.x = x + step;
            result.y = y + step;
            result.z = z;
        }
        if (manhattan[2 * 9 + 8] < id7)
        {
            id7 = manhattan[2 * 9 + 8];
            result.x = x + step;
            result.y = y + step;
            result.z = z + step;
        }
    }

    public static long move(id1[] roses, id1 pointCurrent, long result, long x, long y, long z)
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

    public static void move(id1[] roses, long step, id1 result)
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

    public static id1 solve(id1[] roses)
    {
        id1 result = new id1(0, 0, 0);
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
            id1[] roses = new id1[n];
            for (int index = 0; index < n; index++)
            {
                roses[index] = new id1(nextLong(), nextLong(), nextLong());
            }
            id1 point = solve(roses);
            out.println(point);
        }
    }
}