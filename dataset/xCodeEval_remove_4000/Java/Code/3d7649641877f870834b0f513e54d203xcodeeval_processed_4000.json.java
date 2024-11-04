import java.io.*;
import java.util.*;

public class id12
{
    public static final Random RANDOM = new Random(System.currentTimeMillis());
    private static BufferedReader id6 = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer stringTokenizer = null;
    private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

    private static String next() throws IOException
    {
        while ((stringTokenizer == null) || (!stringTokenizer.hasMoreTokens()))
        {
            stringTokenizer = new StringTokenizer(id6.readLine());
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
        return id6.readLine();
    }

    public static void close()
    {
        out.close();
    }

    public static final long[] POWER2 = id10();

    public static long[] id10()
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

    static class id2
    {
        public long x;
        public long y;
        public long z;

        public id2(long x, long y, long z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public long manhattan(long x, long y, long z)
        {
            return Math.abs(this.x - x) + Math.abs(this.y - y) + Math.abs(this.z - z);
        }

        public void id4(long x, long y, long z, long step, long[] result)
        {
            long xMinus = x - step;
            long xPlus = x + step;
            long yMinus = y - step;
            long yPlus = y + step;
            long zMinus = z - step;
            long zPlus = z + step;
            long id7 = Math.abs(this.x - xMinus);
            long absX = Math.abs(this.x - x);
            long id5 = Math.abs(this.x - xPlus);
            long id3 = Math.abs(this.y - yMinus);
            long absY = Math.abs(this.y - y);
            long id9 = Math.abs(this.y - yPlus);
            long id11 = Math.abs(this.z - zMinus);
            long absZ = Math.abs(this.z - z);
            long id1 = Math.abs(this.z - zPlus);

            result[0 * 9 + 0] = Math.max(result[0 * 9 + 0], id7 + id3 + id11);
            result[0 * 9 + 1] = Math.max(result[0 * 9 + 1], id7 + id3 + absZ);
            result[0 * 9 + 2] = Math.max(result[0 * 9 + 2], id7 + id3 + id1);
            result[0 * 9 + 3] = Math.max(result[0 * 9 + 3], id7 + absY + id11);
            result[0 * 9 + 4] = Math.max(result[0 * 9 + 4], id7 + absY + absZ);
            result[0 * 9 + 5] = Math.max(result[0 * 9 + 5], id7 + absY + id1);
            result[0 * 9 + 6] = Math.max(result[0 * 9 + 6], id7 + id9 + id11);
            result[0 * 9 + 7] = Math.max(result[0 * 9 + 7], id7 + id9 + absZ);
            result[0 * 9 + 8] = Math.max(result[0 * 9 + 8], id7 + id9 + id1);

            result[1 * 9 + 0] = Math.max(result[1 * 9 + 0], absX + id3 + id11);
            result[1 * 9 + 1] = Math.max(result[1 * 9 + 1], absX + id3 + absZ);
            result[1 * 9 + 2] = Math.max(result[1 * 9 + 2], absX + id3 + id1);
            result[1 * 9 + 3] = Math.max(result[1 * 9 + 3], absX + absY + id11);
            result[1 * 9 + 4] = Math.max(result[1 * 9 + 4], absX + absY + absZ);
            result[1 * 9 + 5] = Math.max(result[1 * 9 + 5], absX + absY + id1);
            result[1 * 9 + 6] = Math.max(result[1 * 9 + 6], absX + id9 + id11);
            result[1 * 9 + 7] = Math.max(result[1 * 9 + 7], absX + id9 + absZ);
            result[1 * 9 + 8] = Math.max(result[1 * 9 + 8], absX + id9 + id1);

            result[2 * 9 + 0] = Math.max(result[2 * 9 + 0], id5 + id3 + id11);
            result[2 * 9 + 1] = Math.max(result[2 * 9 + 1], id5 + id3 + absZ);
            result[2 * 9 + 2] = Math.max(result[2 * 9 + 2], id5 + id3 + id1);
            result[2 * 9 + 3] = Math.max(result[2 * 9 + 3], id5 + absY + id11);
            result[2 * 9 + 4] = Math.max(result[2 * 9 + 4], id5 + absY + absZ);
            result[2 * 9 + 5] = Math.max(result[2 * 9 + 5], id5 + absY + id1);
            result[2 * 9 + 6] = Math.max(result[2 * 9 + 6], id5 + id9 + id11);
            result[2 * 9 + 7] = Math.max(result[2 * 9 + 7], id5 + id9 + absZ);
            result[2 * 9 + 8] = Math.max(result[2 * 9 + 8], id5 + id9 + id1);
        }
    }

    public static long manhattan(id2[] roses, long x, long y, long z)
    {
        long result = 0;
        for (int index = 0; index < roses.length; index++)
        {
            long manhattan = roses[index].manhattan(x, y, z);
            result = Math.max(result, manhattan);
        }
        return result;
    }

    public static void id4(id2[] roses, long x, long y, long z, long step, long[] result)
    {
        Arrays.fill(result, 0);
        for (int index = 0; index < roses.length; index++)
        {
            roses[index].id4(x, y, z, step, result);
        }
    }

    public static void moveVector(id2[] roses, long step, id2 result, long[] manhattan)
    {
        long x = result.x;
        long y = result.y;
        long z = result.z;
        id4(roses, x, y, z, step, manhattan);
        long id8 = manhattan[1 * 9 + 4];

        if (manhattan[0 * 9 + 0] < id8)
        {
            id8 = manhattan[0 * 9 + 0];
            result.x = x - step;
            result.y = y - step;
            result.z = z - step;
        }
        if (manhattan[0 * 9 + 1] < id8)
        {
            id8 = manhattan[0 * 9 + 1];
            result.x = x - step;
            result.y = y - step;
            result.z = z;
        }
        if (manhattan[0 * 9 + 2] < id8)
        {
            id8 = manhattan[0 * 9 + 2];
            result.x = x - step;
            result.y = y - step;
            result.z = z + step;
        }
        if (manhattan[0 * 9 + 3] < id8)
        {
            id8 = manhattan[0 * 9 + 3];
            result.x = x - step;
            result.y = y;
            result.z = z - step;
        }
        if (manhattan[0 * 9 + 4] < id8)
        {
            id8 = manhattan[0 * 9 + 4];
            result.x = x - step;
            result.y = y;
            result.z = z;
        }
        if (manhattan[0 * 9 + 5] < id8)
        {
            id8 = manhattan[0 * 9 + 5];
            result.x = x - step;
            result.y = y;
            result.z = z + step;
        }
        if (manhattan[0 * 9 + 6] < id8)
        {
            id8 = manhattan[0 * 9 + 6];
            result.x = x - step;
            result.y = y + step;
            result.z = z - step;
        }
        if (manhattan[0 * 9 + 7] < id8)
        {
            id8 = manhattan[0 * 9 + 7];
            result.x = x - step;
            result.y = y + step;
            result.z = z;
        }
        if (manhattan[0 * 9 + 8] < id8)
        {
            id8 = manhattan[0 * 9 + 8];
            result.x = x - step;
            result.y = y + step;
            result.z = z + step;
        }

        if (manhattan[1 * 9 + 0] < id8)
        {
            id8 = manhattan[1 * 9 + 0];
            result.x = x;
            result.y = y - step;
            result.z = z - step;
        }
        if (manhattan[1 * 9 + 1] < id8)
        {
            id8 = manhattan[1 * 9 + 1];
            result.x = x;
            result.y = y - step;
            result.z = z;
        }
        if (manhattan[1 * 9 + 2] < id8)
        {
            id8 = manhattan[1 * 9 + 2];
            result.x = x;
            result.y = y - step;
            result.z = z + step;
        }
        if (manhattan[1 * 9 + 3] < id8)
        {
            id8 = manhattan[1 * 9 + 3];
            result.x = x;
            result.y = y;
            result.z = z - step;
        }














        if (manhattan[1 * 9 + 5] < id8)
        {
            id8 = manhattan[1 * 9 + 5];
            result.x = x;
            result.y = y;
            result.z = z + step;
        }
        if (manhattan[1 * 9 + 6] < id8)
        {
            id8 = manhattan[1 * 9 + 6];
            result.x = x;
            result.y = y + step;
            result.z = z - step;
        }
        if (manhattan[1 * 9 + 7] < id8)
        {
            id8 = manhattan[1 * 9 + 7];
            result.x = x;
            result.y = y + step;
            result.z = z;
        }
        if (manhattan[1 * 9 + 8] < id8)
        {
            id8 = manhattan[1 * 9 + 8];
            result.x = x;
            result.y = y + step;
            result.z = z + step;
        }

        if (manhattan[2 * 9 + 0] < id8)
        {
            id8 = manhattan[2 * 9 + 0];
            result.x = x + step;
            result.y = y - step;
            result.z = z - step;
        }
        if (manhattan[2 * 9 + 1] < id8)
        {
            id8 = manhattan[2 * 9 + 1];
            result.x = x + step;
            result.y = y - step;
            result.z = z;
        }
        if (manhattan[2 * 9 + 2] < id8)
        {
            id8 = manhattan[2 * 9 + 2];
            result.x = x + step;
            result.y = y - step;
            result.z = z + step;
        }
        if (manhattan[2 * 9 + 3] < id8)
        {
            id8 = manhattan[2 * 9 + 3];
            result.x = x + step;
            result.y = y;
            result.z = z - step;
        }
        if (manhattan[2 * 9 + 4] < id8)
        {
            id8 = manhattan[2 * 9 + 4];
            result.x = x + step;
            result.y = y;
            result.z = z;
        }
        if (manhattan[2 * 9 + 5] < id8)
        {
            id8 = manhattan[2 * 9 + 5];
            result.x = x + step;
            result.y = y;
            result.z = z + step;
        }
        if (manhattan[2 * 9 + 6] < id8)
        {
            id8 = manhattan[2 * 9 + 6];
            result.x = x + step;
            result.y = y + step;
            result.z = z - step;
        }
        if (manhattan[2 * 9 + 7] < id8)
        {
            id8 = manhattan[2 * 9 + 7];
            result.x = x + step;
            result.y = y + step;
            result.z = z;
        }
        if (manhattan[2 * 9 + 8] < id8)
        {
            id8 = manhattan[2 * 9 + 8];
            result.x = x + step;
            result.y = y + step;
            result.z = z + step;
        }
    }

    public static long move(id2[] roses, id2 pointCurrent, long result, long x, long y, long z)
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

    public static void move(id2[] roses, long step, id2 result)
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

    public static id2 solveTest(id2[] roses)
    {
        id2 result = new id2(0, 0, 0);
        long[] manhattan = new long[3 * 9];
        for (int stepIndex = 59; stepIndex >= 0; stepIndex--)
        {
            long step = POWER2[stepIndex];
            moveVector(roses, step, result, manhattan);
        }
        moveVector(roses, 1, result, manhattan);
        return result;
    }

    public static id2 solveTest() throws IOException
    {
        int n = nextInt();
        id2[] roses = new id2[n];
        for (int index = 0; index < n; index++)
        {
            roses[index] = new id2(nextLong(), nextLong(), nextLong());
        }
        return solveTest(roses);
    }

    public static void solve() throws IOException
    {
        int t = nextInt();
        for (int test = 0; test < t; test++)
        {
            id2 id0 = solveTest();

            out.println(id0.x + " " + id0.y + " " + id0.z);

        }
    }
}