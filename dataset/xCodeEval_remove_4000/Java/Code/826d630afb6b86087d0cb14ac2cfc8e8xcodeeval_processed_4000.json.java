

import java.io.*;
import java.util.*;

import static java.util.Arrays.sort;


public class id7 {

    static Reader scan = new Reader();
    static FastPrinter out = new FastPrinter();

    static ArrayList<Integer>[] li;
    static int[] vis;static String s;
    static int ans;
    public static void main(String[] args) throws IOException {
        int tt = scan.nextInt();


        StringBuilder sb = new StringBuilder();
        outer:
        for (int tc = 1; tc <= tt; tc++) {
            int n=scan.nextInt();
            int[] arr=scan.id6(n-1);
             s= scan.next();
            li=new ArrayList[n+1];
            ans=0;
            for (int i = 0; i <=n ; i++) li[i]=new ArrayList<>();
            for (int i = 2; i <=n; i++) {
                li[i].add(arr[i-2]);
                li[arr[i-2]].add(i);
            }
            vis=new int[n+1];
            dfs(1);
            sb.append(ans);
            sb.append("\n");
        }
        out.println(sb.toString());
        out.flush();
        out.close();
    }

    private static Pair dfs(int v) {
        vis[v]=1;
        Pair p1=new Pair(0,0);
        for (int i = 0; i < li[v].size(); i++) {
            int nv=li[v].get(i);
            if(vis[nv]==1)continue;
            else {
                Pair p2=dfs(nv);
                p1.w+=p2.w;
                p1.b+=p2.b;
            }
        }
        if(s.charAt(v-1)=='W')p1.w+=1;
        else p1.b+=1;
        if(p1.w==p1.b)++ans;
        return p1;
    }

    static class Pair{
        int w;
        int b;
        Pair(int w,int b){
            this.w=w;
            this.b=b;
        }
    }

    static class Reader {
        private final InputStream in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        private static final long id9 = 922337203685477580L;
        private static final int id3 = 7;
        private static final int id2 = 8;

        public Reader(InputStream in) {
            this.in = in;
        }

        public Reader() {
            this(System.in);
        }

        private boolean id13() {
            if (ptr < buflen) {
                return true;
            } else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (buflen <= 0) {
                    return false;
                }
            }
            return true;
        }

        private int readByte() {
            if (id13()) return buffer[ptr++];
            else return -1;
        }

        private static boolean id15(int c) {
            return 33 <= c && c <= 126;
        }

        public boolean hasNext() {
            while (id13() && !id15(buffer[ptr])) ptr++;
            return id13();
        }

        public String next() {
            if (!hasNext())
                throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (id15(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public long nextLong() {
            if (!hasNext())
                throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) {
                throw new NumberFormatException();
            }
            while (true) {
                if ('0' <= b && b <= '9') {
                    int digit = b - '0';
                    if (n >= id9) {
                        if (n == id9) {
                            if (minus) {
                                if (digit <= id2) {
                                    n = -n * 10 - digit;
                                    b = readByte();
                                    if (!id15(b)) {
                                        return n;
                                    } else if (b < '0' || '9' < b) {
                                        throw new NumberFormatException(
                                                String.format("not number"));
                                    }
                                }
                            } else {
                                if (digit <= id3) {
                                    n = n * 10 + digit;
                                    b = readByte();
                                    if (!id15(b)) {
                                        return n;
                                    } else if (b < '0' || '9' < b) {
                                        throw new NumberFormatException(
                                                String.format("not number"));
                                    }
                                }
                            }
                        }
                        throw new ArithmeticException(
                                String.format(" overflows long."));
                    }
                    n = n * 10 + digit;
                } else if (b == -1 || !id15(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }

        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
                throw new NumberFormatException();
            return (int) nl;
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long[] id14(long length) {
            long[] array = new long[(int) length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextLong();
            return array;
        }

        public long[] id14(int length, java.util.function.LongUnaryOperator map) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsLong(this.nextLong());
            return array;
        }

        public int[] id6(int length) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextInt();
            return array;
        }

        public Integer[] id1(int length) {
            Integer[] array = new Integer[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextInt();
            return array;
        }

        public int[][] id5(int length, int width) {
            int[][] arrays = new int[width][length];
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < width; j++)
                    arrays[j][i] = this.nextInt();
            }
            return arrays;
        }

        public int[] id6(int length, java.util.function.IntUnaryOperator map) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsInt(this.nextInt());
            return array;
        }

        public double[] id11(int length) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextDouble();
            return array;
        }

        public double[] id11(int length, java.util.function.DoubleUnaryOperator map) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsDouble(this.nextDouble());
            return array;
        }

        public long[][] id4(int height, int width) {
            long[][] mat = new long[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextLong();
                }
            return mat;
        }

        public int[][] id0(int height, int width) {
            int[][] mat = new int[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextInt();
                }
            return mat;
        }

        public double[][] id10(int height, int width) {
            double[][] mat = new double[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextDouble();
                }
            return mat;
        }

        public char[][] id8(int height, int width) {
            char[][] mat = new char[height][width];
            for (int h = 0; h < height; h++) {
                String s = this.next();
                for (int w = 0; w < width; w++) {
                    mat[h][w] = s.charAt(w);
                }
            }
            return mat;
        }
    }


    static class FastPrinter extends PrintWriter {
        public FastPrinter(PrintStream stream) {
            super(stream);
        }

        public FastPrinter() {
            super(System.out);
        }

        private static String dtos(double x, int n) {
            StringBuilder sb = new StringBuilder();
            if (x < 0) {
                sb.append('-');
                x = -x;
            }
            x += Math.pow(10, -n) / 2;
            sb.append((long) x);
            sb.append(".");
            x -= (long) x;
            for (int i = 0; i < n; i++) {
                x *= 10;
                sb.append((int) x);
                x -= (int) x;
            }
            return sb.toString();
        }

        @Override
        public void print(float f) {
            super.print(dtos(f, 20));
        }

        @Override
        public void println(float f) {
            super.println(dtos(f, 20));
        }

        @Override
        public void print(double d) {
            super.print(dtos(d, 20));
        }

        @Override
        public void println(double d) {
            super.println(dtos(d, 20));
        }

        public void printArray(int[] array, String separator) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(array[i]);
                super.print(separator);
            }
            super.println(array[n - 1]);
        }

        public void printArray(int[] array) {
            this.printArray(array, " ");
        }

        public void printArray(int[] array, String separator, java.util.function.IntUnaryOperator map) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(map.applyAsInt(array[i]));
                super.print(separator);
            }
            super.println(map.applyAsInt(array[n - 1]));
        }

        public void printArray(int[] array, java.util.function.IntUnaryOperator map) {
            this.printArray(array, " ", map);
        }

        public void printArray(long[] array, String separator) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(array[i]);
                super.print(separator);
            }
            super.println(array[n - 1]);
        }

        public void printArray(long[] array) {
            this.printArray(array, " ");
        }

        public void printArray(long[] array, String separator, java.util.function.LongUnaryOperator map) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(map.applyAsLong(array[i]));
                super.print(separator);
            }
            super.println(map.applyAsLong(array[n - 1]));
        }

        public void printArray(long[] array, java.util.function.LongUnaryOperator map) {
            this.printArray(array, " ", map);
        }

        public void printMatrix(int[][] arr) {
            for (int i = 0; i < arr.length; i++) {
                this.printArray(arr[i]);
            }
        }

        public void id12(char[][] arr, int n, int m) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    this.print(arr[i][j] + " ");
                }
                this.println();
            }
        }

    }

    static Random __r = new Random();

    static int randInt(int min, int max) {
        return __r.nextInt(max - min + 1) + min;
    }

    static void reverse(int[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            int swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static void reverse(long[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            long swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static void reverse(double[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            double swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static void reverse(char[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            char swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static void reverse(char[] arr, int i, int j) {
        while (i < j) {
            char temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            j--;
        }
    }

    static void reverse(int[] arr, int i, int j) {
        while (i < j) {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            j--;
        }
    }

    static void reverse(long[] arr, int i, int j) {
        while (i < j) {
            long temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            j--;
        }
    }

    static void shuffle(int[] a) {
        int n = a.length - 1;
        for (int i = 0; i < n; ++i) {
            int ind = randInt(i, n);
            int swap = a[i];
            a[i] = a[ind];
            a[ind] = swap;
        }
    }

    static void shuffle(long[] a) {
        int n = a.length - 1;
        for (int i = 0; i < n; ++i) {
            int ind = randInt(i, n);
            long swap = a[i];
            a[i] = a[ind];
            a[ind] = swap;
        }
    }

    private static int countDigits(int l) {
        if (l >= 1000000000) return 10;
        if (l >= 100000000) return 9;
        if (l >= 10000000) return 8;
        if (l >= 1000000) return 7;
        if (l >= 100000) return 6;
        if (l >= 10000) return 5;
        if (l >= 1000) return 4;
        if (l >= 100) return 3;
        if (l >= 10) return 2;
        return 1;
    }

    private static int getlowest(int l) {
        if (l >= 1000000000) return 1000000000;
        if (l >= 100000000) return 100000000;
        if (l >= 10000000) return 10000000;
        if (l >= 1000000) return 1000000;
        if (l >= 100000) return 100000;
        if (l >= 10000) return 10000;
        if (l >= 1000) return 1000;
        if (l >= 100) return 100;
        if (l >= 10) return 10;
        return 1;
    }

    static void shuffle(double[] a) {
        int n = a.length - 1;
        for (int i = 0; i < n; ++i) {
            int ind = randInt(i, n);
            double swap = a[i];
            a[i] = a[ind];
            a[ind] = swap;
        }
    }

    static void rsort(int[] a) {
        shuffle(a);
        sort(a);
    }

    static void rsort(long[] a) {
        shuffle(a);
        sort(a);
    }

    static void rsort(double[] a) {
        shuffle(a);
        sort(a);
    }

    static int[] copy(int[] a) {
        int[] ans = new int[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }

    static long[] copy(long[] a) {
        long[] ans = new long[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }

    static double[] copy(double[] a) {
        double[] ans = new double[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }

    static char[] copy(char[] a) {
        char[] ans = new char[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }
}