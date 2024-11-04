import java.io.BufferedInputStream;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.*;

import java.util.Arrays;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.InputStream;


public class Cinema {
    public static class id8 {
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = System.in.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public String nextLine() {
            int c = read();
            while (id2(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!id7(c));
            return res.toString();
        }

        public String nextString() {
            int c = read();
            while (id2(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!id2(c));
            return res.toString();
        }

        public long nextLong() {
            int c = read();
            while (id2(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id2(c));
            return res * sgn;
        }

        public int nextInt() {
            int c = read();
            while (id2(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id2(c));
            return res * sgn;
        }

        public int[] id3(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        public long[] id12(int n) {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }
            return arr;
        }

        private boolean id2(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private boolean id7(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }
    }

    private static void run1()
    {
        Scanner in = new Scanner(new BufferedInputStream(System.in));

        int N = in.nextInt();
        int M = in.nextInt();
        int K = in.nextInt();

        

        boolean[][] seats = new boolean[2000][2000];
        for( int i = 0; i < 2000; i++ )
        {
            for( int j = 0; j < 2000; j++ )
            {
                seats[i][j] = false;
            }
        }
        int[] id1 = new int[100000];
        int[] id0 = new int[100000];

        for( int i = 0; i < K; i++ )
        {
            int row = in.nextInt();
            int col = in.nextInt();
            int number = 10000*row+col;
            

            if( seats[row-1][col-1] )
            {
                

                

                int a = row-1;
                int b = N-row;
                int c = col-1;
                int d = M-col;
                int limit = Math.max(Math.max(Math.max(a+c, b+d), c+b), d+a);
                int dist;
                for( dist = 1; dist <= limit; dist++ )
                {
                    

                    int dRow;
                    for( dRow = -dist; dRow <= dist; dRow++ )
                    {
                        

                        int limit2 = dist-Math.abs(dRow);
                        int dCol;
                        if( limit2 == 0 ) {
                            dCol = 3 * limit2;
                            int nextRow = row + dRow;
                            int nextCol = col + 0;
                            if (nextRow >= 1 && nextRow <= N && nextCol >= 1 && nextCol <= M) {
                                

                                

                                

                                if (!seats[nextRow - 1][nextCol - 1]) {
                                    

                                    

                                    seats[nextRow - 1][nextCol - 1] = true;
                                    id1[i] = nextRow;
                                    id0[i] = nextCol;
                                    dCol = -1;
                                }
                            }
                        }
                        else {
                            for (dCol = -limit2; dCol <= limit2; dCol += 2 * limit2) {
                                int nextRow = row + dRow;
                                int nextCol = col + dCol;
                                if (nextRow >= 1 && nextRow <= N && nextCol >= 1 && nextCol <= M) {
                                    

                                    

                                    

                                    if (!seats[nextRow-1][nextCol-1]) {
                                        

                                        

                                        seats[nextRow-1][nextCol-1] = true;
                                        id1[i] = nextRow;
                                        id0[i] = nextCol;
                                        break;
                                    }
                                }
                            }
                        }
                        if( dCol != 3*limit2 )
                        {
                            break;
                        }
                    }
                    if( dRow != dist+1 )
                    {
                        break;
                    }
                }
                

                if( dist == limit+1 )
                {
                    System.out.printf("No seats to offer\n");
                }
            }
            else
            {
                

                

                seats[row-1][col-1] = true;
                id1[i] = row;
                id0[i] = col;
            }
        }

        for( int i = 0; i < K; i++ )
        {
            System.out.printf("%d %d\n", id1[i], id0[i]);
        }
    }

    


    private static boolean[][] marked = new boolean[2001][2001];
    private static int[][] id11 = new int[2001][2001];
    private static int[][] id10 = new int[2001][2001];

    

    private static void id5(int rRow, int rCol, int cRow, int cCol, int N, int M, BufferedWriter out)
    {
        


        int dRow = cRow - rRow;
        int dCol = cCol - rCol;
        int dist = Math.abs(dRow) + Math.abs(dCol);

        if( cRow == 0 )
        {
            dist = 0;
            dRow = 0;
            dCol = 0;
        }

        while( true )
        {
            int row = rRow+dRow;
            int col = rCol+dCol;

            


            if( row >= 1 && row <= N && col >=1 && col <= M && !marked[row][col] ) {
                

                marked[row][col] = true;

                

                try {
                    out.write(row + " " + col + "\n");
                }catch (IOException e)
                {
                    e.printStackTrace();
                }

                id11[rRow][rCol] = row;
                id10[rRow][rCol] = col;
                return;
            }

            if( dRow == dist )
            {
                dist++;
                dRow = -dist;
                dCol = 0;
            }
            else if( dCol >= 0 )
            {
                dRow++;
                dCol = -dist+Math.abs(dRow);
            }
            else
            {
                dCol = -dCol;
            }
        }
    }

    private static void run2()
    {
        

        id8 in = new id8();

        int N = in.nextInt();
        int M = in.nextInt();
        int K = in.nextInt();

        

        

        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

        for( int i = 0; i < K; i++ )
        {
            int rRow = in.nextInt();
            int rCol = in.nextInt();

            id5(rRow, rCol, id11[rRow][rCol], id10[rRow][rCol], N, M, out);
        }

        

        try {
            out.flush();
        }catch (IOException e)
        {
            e.printStackTrace();
        }

    }

    private static void run3()
    {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    public static void main(String[] args) {
        

        

        run3();
    }

    private static class TaskA {
        private static int n;
        private static int m;

        private static boolean[][] used;
        private static int[][] aNext;
        private static int[][] bNext;

        private static boolean swapped = false;

        public static void solve(int testNumber, InputReader jin, PrintWriter jout) {
            n = jin.int32();
            m = jin.int32();
            swapped = m < n;
            if(swapped) {
                n ^= m;
                m ^= n;
                n ^= m;
            }

            used = new boolean[n][m];

            aNext = new int[n][m]; ArrayUtils.init(aNext, -2);
            bNext = new int[n][m]; ArrayUtils.init(bNext, -2);

            for(int i = 0; i < n; i++) {
                aNext[i][m - 1] = -1;
                bNext[i][0] = -1;
            }

            int k = jin.int32();
            for(int i = 0; i < k; i++) {
                int x = jin.int32() - 1;
                int y = jin.int32() - 1;
                if(swapped && (x != y)) {
                    x ^= y; y ^= x; x ^= y;
                }
                int[] p = getNext(x, y);
                used[p[0]][p[1]] = true;
                if(swapped) {
                    jout.println((p[1] + 1) + " " + (p[0] + 1));
                } else {
                    jout.println((p[0] + 1) + " " + (p[1] + 1));
                }
            }

        }

        private static int[] getNext(int x, int y) {
            if(!used[x][y]) return new int[]{x, y};

            int gx = -1;
            int gy = -1;
            int diff = Integer.MAX_VALUE;
            for(int i = 0; i < n; i++) {
                if(i > diff) break;
                for(int j = -1; j <= 1; j++) {
                    if(j == 0) continue;
                    int nx = x + (j * i);
                    if(nx < 0 || nx >= n) continue;
                    int ny = after(nx, y);
                    if(ny != -1) {
                        if (isBetter(nx, ny, gx, gy, x, y)) {
                            gx = nx;
                            gy = ny;
                            diff = dist(gx, gy, x, y);
                        }
                    }
                    ny = before(nx, y);
                    if(ny != -1) {
                        if (isBetter(nx, ny, gx, gy, x, y)) {
                            gx = nx;
                            gy = ny;
                            diff = dist(gx, gy, x, y);
                        }
                    }
                }
            }

            return new int[]{gx, gy};
        }

        private static boolean isBetter(int nx, int ny, int gx, int gy, int x, int y) {
            if(nx == -1 || ny == -1) return false;
            if(gx == -1 || gy == -1) return true;
            int d1 = dist(nx, ny, x, y);
            int d2 = dist(gx, gy, x, y);
            if(d1 == d2) {
                if(!swapped) {
                    if (nx == gx) {
                        return ny < gy;
                    }
                    return nx < gx;
                } else {
                    if (ny == gy) {
                        return nx < gx;
                    }
                    return ny < gy;
                }

            }
            return d1 < d2;
        }

        private static int dist(int nx, int ny, int x, int y) {
            return Math.abs(nx - x) + Math.abs(ny - y);
        }

        private static int before(int x, int y) {
            if(!used[x][y]) return y;
            if(bNext[x][y] == -1) return -1;
            if(bNext[x][y] == -2) bNext[x][y] = y - 1;
            if(used[x][bNext[x][y]])
                return bNext[x][y] = before(x, bNext[x][y]);
            return bNext[x][y];
        }

        private static int after(int x, int y) {
            if(!used[x][y]) return y;
            if(aNext[x][y] == -1) return -1;
            if(aNext[x][y] == -2) aNext[x][y] = y + 1;
            if(used[x][aNext[x][y]])
                return aNext[x][y] = after(x, aNext[x][y]);
            return aNext[x][y];
        }

    }

    private static class InputReader {
        private static final int id4 = 1024;
        private InputStream in;
        private byte[] buffer;
        private int id9;
        private int id6;
        private static final String tokenizers = " \t\r\f\n";

        public InputReader(InputStream stream) {
            this.in = stream;
            buffer = new byte[id4];
            id9 = 0;
            id6 = 0;
        }

        private boolean refill() {
            try {
                this.id9 = this.in.read(this.buffer);
                this.id6 = 0;
            } catch(Exception e) {}
            return this.id9 > 0;
        }


        public Byte readChar() {
            if(id6 < id9) {
                return this.buffer[this.id6++];
            } else {
                if(!this.refill()) {
                    return null;
                } else {
                    return readChar();
                }
            }
        }

        public String token()  {
            StringBuffer tok = new StringBuffer();
            Byte first;
            while((first = readChar()) != null && (tokenizers.indexOf((char) first.byteValue()) != -1));
            if(first == null) return null;
            tok.append((char)first.byteValue());
            while((first = readChar()) != null && (tokenizers.indexOf((char) first.byteValue()) == -1)) {
                tok.append((char)first.byteValue());
            }
            return tok.toString();
        }


        public String next() {
            return token();
        }

        public Integer int32() throws NumberFormatException {
            String tok = token();
            return tok == null? null : Integer.parseInt(tok);
        }

        public Long int64() throws NumberFormatException {
            String tok = token();
            return tok == null? null : Long.parseLong(tok);
        }
    }

    private static class  ArrayUtils {

        public static void init(int[][][] arr, int val) {
            for(int[][] subarr: arr)
                ArrayUtils.init(subarr, val);
        }

        public static void init(int[][] arr, int val) {
            for(int[] subarr: arr)
                ArrayUtils.init(subarr, val);
        }

        public static void init(int[] arr, int val) {
            Arrays.fill(arr, val);
        }

        public static int accumulate(int[] arr) {
            int res = 0;
            for(int xx: arr)
                res += xx;
            return res;
        }

        public static void init(double[][] arr, double val) {
            for(double[] subarr: arr)
                ArrayUtils.init(subarr, val);
        }

        private static void init(double[] arr, double val) {
            Arrays.fill(arr, val);
        }

        public static void init(long[][] arr, long val) {
            for(long[] subarr: arr)
                ArrayUtils.init(subarr, val);
        }

        private static void init(long[] subarr, long val) {
            Arrays.fill(subarr, val);
        }
    }

}
