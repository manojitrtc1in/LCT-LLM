

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.*;
import static java.util.Arrays.sort;



public class id6 {

    static Reader scan = new Reader();
    static FastPrinter out = new FastPrinter();

     public static void main(String[] args) throws IOException {
        int tt = scan.nextInt();


        for (int tc = 1; tc <= tt; tc++) {
            int n= scan.nextInt();
            int[] arr= scan.id5(n);
            int one=0;
            boolean zero=false;
            int[] prefix=new int[n];
            int gz=0;
            int ind2=-1;
            int got=0;
            for (int i = 0; i < n; i++) {
                if(arr[i]==1){
                    one++;
                    if(gz%2==0){
                        gz=0;
                        ind2=-1;
                    }else got=1;
                }
                else{
                    zero=true;
                    if(got==0)gz++;
                    if(ind2==-1)ind2=i;
                }
                prefix[i]=arr[i];
                if(i!=0){
                    prefix[i]+=prefix[i-1];
                }
            }
            if(one==0){
                out.println("YES");
                out.println("0");
                out.flush();
                continue;
            }
            if(one%2==1 || !zero ){
                out.println("NO");
                out.flush();
                continue;
            }
            int ind1=-1;
            for (int i = 0; i < n  ; i++) {
                if(arr[i]==0){
                    int left=0;
                    int right=0;
                    if(i!=0){
                        left=prefix[i];
                    }
                    if(i!=n-1){
                        right=prefix[n-1]-prefix[i];
                    }
                    if(left%2==0 && right%2==0){
                        ind1=i;
                        break;
                    }
                }
            }
            List<Integer> li=new ArrayList<>();
            if(ind1!=-1){
                dorest(arr,ind1,li,false);
            }else{
                if(gz%2==0 && ind2==-1){
                    out.println("NO");
                    out.flush();
                    continue;
                }
                dorest(arr,ind2,li,true);
            }
            out.flush();
        }
        out.close();
    }

    private static void dorest(int[] arr, int ind, List<Integer> li,boolean flag) {
        out.println("YES");
        makeone(arr,ind,li);
        if(flag){
            li.add(ind);
            arr[ind-1]=arr[ind]=arr[ind+1]=0;
        }
        makezero(arr,ind,li);
        out.println(li.size());
        for (int i = 0; i < li.size(); i++) {
            out.print(li.get(i)+" ");
        }
        out.println();
        out.flush();
    }

    private static void makezero(int[] arr, int ind, List<Integer> li) {
         int n=arr.length;
        for (int i = ind-2; i >=0 ; i--) {
            int cnt_one=(arr[i]+arr[i+1]+arr[i+2]);
            if(cnt_one==2){
                li.add(i+1);
                arr[i]=arr[i+1]=arr[i+2]=0;
            }
        }
        for (int i = ind; i < n-2 ; i++) {
            int cnt_one=(arr[i]+arr[i+1]+arr[i+2]);
            if(cnt_one==2){
                li.add(i+1);
                arr[i]=arr[i+1]=arr[i+2]=0;
            }
        }
    }

    private static void makeone(int[] arr, int ind,List<Integer> li) {
         int n=arr.length;
        for (int i = ind-3; i >=0 ; i--) {
            int cnt_one=(arr[i]+arr[i+1]+arr[i+2]);
            if(cnt_one==1){
                li.add(i+1);
                arr[i]=arr[i+1]=arr[i+2]=1;
            }
        }




























        for (int i = n-1; i-2 >ind ; i--) {
            int cnt_one=(arr[i]+arr[i-1]+arr[i-2]);
            if(cnt_one==1){
                li.add(i-1);
                arr[i]=arr[i-1]=arr[i-2]=1;
            }
        }
    }

    static class Reader {
        private final InputStream in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        private static final long id8 = 922337203685477580L;
        private static final int id2 = 7;
        private static final int id1 = 8;

        public Reader(InputStream in) {
            this.in = in;
        }

        public Reader() {
            this(System.in);
        }

        private boolean id12() {
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
            if (id12()) return buffer[ptr++];
            else return -1;
        }

        private static boolean id14(int c) {
            return 33 <= c && c <= 126;
        }

        public boolean hasNext() {
            while (id12() && !id14(buffer[ptr])) ptr++;
            return id12();
        }

        public String next() {
            if (!hasNext())
                throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (id14(b)) {
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
                    if (n >= id8) {
                        if (n == id8) {
                            if (minus) {
                                if (digit <= id1) {
                                    n = -n * 10 - digit;
                                    b = readByte();
                                    if (!id14(b)) {
                                        return n;
                                    } else if (b < '0' || '9' < b) {
                                        throw new NumberFormatException(
                                                String.format("not number"));
                                    }
                                }
                            } else {
                                if (digit <= id2) {
                                    n = n * 10 + digit;
                                    b = readByte();
                                    if (!id14(b)) {
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
                } else if (b == -1 || !id14(b)) {
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

        public long[] id13(long length) {
            long[] array = new long[(int) length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextLong();
            return array;
        }

        public long[] id13(int length, java.util.function.LongUnaryOperator map) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsLong(this.nextLong());
            return array;
        }

        public int[] id5(int length) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextInt();
            return array;
        }

        public int[][] id4(int length, int width) {
            int[][] arrays = new int[width][length];
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < width; j++)
                    arrays[j][i] = this.nextInt();
            }
            return arrays;
        }

        public int[] id5(int length, java.util.function.IntUnaryOperator map) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsInt(this.nextInt());
            return array;
        }

        public double[] id10(int length) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextDouble();
            return array;
        }

        public double[] id10(int length, java.util.function.DoubleUnaryOperator map) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsDouble(this.nextDouble());
            return array;
        }

        public long[][] id3(int height, int width) {
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

        public double[][] id9(int height, int width) {
            double[][] mat = new double[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextDouble();
                }
            return mat;
        }

        public char[][] id7(int height, int width) {
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

        public void id11(char[][] arr, int n, int m) {
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
