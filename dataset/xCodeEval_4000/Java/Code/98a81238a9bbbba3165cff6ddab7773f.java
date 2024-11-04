

import java.io.*;
import java.util.*;

import static java.util.Arrays.sort;


public class CodeforcesTemp {

    static Reader scan = new Reader();
    static FastPrinter out = new FastPrinter();

    static ArrayList<Integer>[] m;
    static ArrayList<Integer>[] d;
    static int[] pm;static int[] pd;
    static int[] visM;static int[] visD;
    static int[] cnt_p; static int[] cnt_m;
    public static void main(String[] args) throws IOException {


        int tt = 1;
        StringBuilder sb=new StringBuilder();
        outer:
        for (int tc = 1; tc <= tt; tc++) {
            int n= scan.nextInt();
            int m1= scan.nextInt();
            int m2= scan.nextInt();
            m=new ArrayList[n+1];
            d=new ArrayList[n+1];
            pm=new int[n+1];pd=new int[n+1];
            cnt_p=new int[n+1];    cnt_m=new int[n+1];
            for (int i = 0; i <=n; i++) {
                m[i]=new ArrayList<>();d[i]=new ArrayList<>();
                pm[i]=i;pd[i]=i;
            }
            for (int i = 0; i < m1; i++) {
                int u= scan.nextInt();int v= scan.nextInt();
                m[u].add(v);
                m[v].add(u);
            }
            for (int i = 0; i < m2; i++) {
                int u= scan.nextInt();int v= scan.nextInt();
                d[u].add(v);
                d[v].add(u);
            }
             visM=new int[n+1];
             visD=new int[n+1];

            for (int i = 1; i <=n; i++) {
                if(visM[i]==0){
                    int cnt=dfsM(i,i);
                    cnt_m[i]=cnt;
                }
                if(visD[i]==0){
                    int cnt=dfsD(i,i);
                    cnt_p[i]=cnt;
                }
            }
            int[] vs=new int[n+1];
            ArrayList<P> ans=new ArrayList<>();
            for (int i = 1; i <=n; i++) {
                if(vs[i]==1)continue ;
                for (int j = i+1; j <= n; j++) {
                    int u=i;int v=j;
                    if(pd[u]!=pd[v] && pm[u]!=pm[v]){
                        ans.add(new P(u,v));
                         m[u].add(v);
                         m[v].add(u);
                         d[u].add(v);
                         d[v].add(u);
                         vs[j]=1;
                         if(cnt_p[pd[u]]>cnt_p[pd[v]]){
                             cnt_p[pd[u]]+=cnt_p[pd[v]];
                             np(pd[v],pd[u],-1);

                         }else{
                             cnt_p[pd[v]]+=cnt_p[pd[u]];
                             np(pd[u],pd[v],-1);
                         }
                        {
                            if(cnt_m[pm[u]]>cnt_m[pm[v]]){
                                cnt_m[pm[u]]+=cnt_m[pm[v]];
                                np1(pm[v],pm[u],-1);

                            }else{
                                cnt_m[pm[v]]+=cnt_m[pm[u]];
                                np1(pm[u],pm[v],-1);
                            }
                        }
                    }
                }
            }
            sb.append(ans.size());sb.append("\n");
            for (int i = 0; i < ans.size(); i++) {
                sb.append(ans.get(i).x+" "+ans.get(i).y);sb.append("\n");
            }
        }
        out.println(sb.toString());
        out.flush();
        out.close();
    }

    private static void np1(int v, int p,int last) {
        pm[v]=p;
        for (int i = 0; i < m[v].size(); i++) {
            int v1=m[v].get(i);
            if(v1==last)continue;
            np1(v1,p,v);
        }
    }

    static class P{
        int x;
        int y;
        P(int x,int y){
            this.x=x;this.y=y;
        }
    }
    private static void np(int v, int p,int last) {
        pd[v]=p;
        for (int i = 0; i < d[v].size(); i++) {
             int v1=d[v].get(i);
             if(v1==last)continue;
             np(v1,p,v);
        }
    }

    private static int dfsM(int v,int p) {
        visM[v]=1;
        pm[v]=p;
        int cnt=0;
        for (int i = 0; i < m[v].size(); i++) {
            int v1=m[v].get(i);
            if(visM[v1]==1)continue;
            cnt+= dfsM(v1,p);
        }
        return cnt+1;
    }
    private static int  dfsD(int v,int p) {
        visD[v]=1;
        pd[v]=p;
        int cnt=0;
        for (int i = 0; i < d[v].size(); i++) {
            int v1=d[v].get(i);
            if(visD[v1]==1)continue;
            cnt+=dfsD(v1,p);
        }
        return cnt+1;
    }

    static class Pair{
        int len;
        int[] dp;
        Pair(int len,int[] a){
            this.len=len;
            this.dp=a;
        }
    }

    static class Reader {
        private final InputStream in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        private static final long LONG_MAX_TENTHS = 922337203685477580L;
        private static final int LONG_MAX_LAST_DIGIT = 7;
        private static final int LONG_MIN_LAST_DIGIT = 8;

        public Reader(InputStream in) {
            this.in = in;
        }

        public Reader() {
            this(System.in);
        }

        private boolean hasNextByte() {
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
            if (hasNextByte()) return buffer[ptr++];
            else return -1;
        }

        private static boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }

        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
            return hasNextByte();
        }

        public String next() {
            if (!hasNext())
                throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
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
                    if (n >= LONG_MAX_TENTHS) {
                        if (n == LONG_MAX_TENTHS) {
                            if (minus) {
                                if (digit <= LONG_MIN_LAST_DIGIT) {
                                    n = -n * 10 - digit;
                                    b = readByte();
                                    if (!isPrintableChar(b)) {
                                        return n;
                                    } else if (b < '0' || '9' < b) {
                                        throw new NumberFormatException(
                                                String.format("not number"));
                                    }
                                }
                            } else {
                                if (digit <= LONG_MAX_LAST_DIGIT) {
                                    n = n * 10 + digit;
                                    b = readByte();
                                    if (!isPrintableChar(b)) {
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
                } else if (b == -1 || !isPrintableChar(b)) {
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

        public long[] nextLongArray(long length) {
            long[] array = new long[(int) length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextLong();
            return array;
        }

        public long[] nextLongArray(int length, java.util.function.LongUnaryOperator map) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsLong(this.nextLong());
            return array;
        }

        public int[] nextIntArray(int length) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextInt();
            return array;
        }

        public Integer[] nextIntegerArray(int length) {
            Integer[] array = new Integer[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextInt();
            return array;
        }

        public int[][] nextIntArrayMulti(int length, int width) {
            int[][] arrays = new int[width][length];
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < width; j++)
                    arrays[j][i] = this.nextInt();
            }
            return arrays;
        }

        public int[] nextIntArray(int length, java.util.function.IntUnaryOperator map) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsInt(this.nextInt());
            return array;
        }

        public double[] nextDoubleArray(int length) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextDouble();
            return array;
        }

        public double[] nextDoubleArray(int length, java.util.function.DoubleUnaryOperator map) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsDouble(this.nextDouble());
            return array;
        }

        public long[][] nextLongMatrix(int height, int width) {
            long[][] mat = new long[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextLong();
                }
            return mat;
        }

        public int[][] nextIntMatrix(int height, int width) {
            int[][] mat = new int[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextInt();
                }
            return mat;
        }

        public double[][] nextDoubleMatrix(int height, int width) {
            double[][] mat = new double[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextDouble();
                }
            return mat;
        }

        public char[][] nextCharMatrix(int height, int width) {
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

        public void printCharMatrix(char[][] arr, int n, int m) {
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