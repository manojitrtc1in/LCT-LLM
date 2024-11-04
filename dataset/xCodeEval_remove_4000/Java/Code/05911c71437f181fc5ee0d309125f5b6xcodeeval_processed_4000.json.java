
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.*;

import static java.util.Arrays.sort;


public class id6 {

    static Reader scan = new Reader();
    static FastPrinter out = new FastPrinter();

    static int[] vis;
    static List<Integer>[] li;
    static HashSet<Integer>[] rm;
    static int n;
    static List<Pair> removeEdge;
    static int[][] arr;
    static List<Pair> result;
    public static void main(String[] args) throws IOException {
        int tt = scan.nextInt();


        outer:
        for (int tc = 1; tc <= tt; tc++) {
            n = scan.nextInt();
            li = new List[n + 1];
            rm=new HashSet[n+1];
            removeEdge=new ArrayList<>();
            arr=new int[n+1][2];
            result=new ArrayList<>();
             for (int i = 0; i <= n; i++) {
                li[i] = new ArrayList<>();
                rm[i]=new HashSet<>();
            }
            for (int i = 0; i < n - 1; i++) {
                int a = scan.nextInt();
                int b = scan.nextInt();
                li[a].add(b);
                li[b].add(a);
            }
            dfs(1, -1);
            if(removeEdge.size()==0) {
                out.println("0");
                out.flush();
                continue;
            }
            out.println(removeEdge.size());
            int prev=result.get(0).u;
            for (int i = 0; i <removeEdge.size(); i++) {
                int a=removeEdge.get(i).u;
                int b=removeEdge.get(i).v;
                int v=result.get(i+1).u;
                out.println(a+" "+b+" "+prev+" "+v);
                prev=result.get(i+1).v;
            }
            out.flush();
        }
        out.close();
    }

    private static void dfs(Integer v, Integer p) {
        if (li[v].size() == 1 && p!=-1) {
            arr[v][0]=arr[v][1]=v;
            return ;
        }
        for (int i = 0; i < li[v].size();i++ ) {
            int next = li[v].get(i);
            if (next == p || rm[v].contains(next)){
                continue;
            }
            dfs(next, v);
        }
        int cs = li[v].size()-rm[v].size();
        if (p != -1) {
            cs -= 1;
        }
        boolean flag=false;
        int l = 0;
        if (p != -1 && cs>=2) {
            removeEdge.add(new Pair(p, v));
            int leaf1=-1;
            int leaf2=-1;
            while (true){
                Integer v1 = li[v].get(l);
                if(rm[v].contains(v1) || v1.equals(p)){
                    l++;
                    continue;
                }
                else{
                    if(leaf1==-1) leaf1=v1;
                    else leaf2=v1;
                    l++;
                }
                if(leaf1!=-1 && leaf2!=-1)break;
            }
            result.add(new Pair(arr[leaf1][1],arr[leaf2][1]));

            rm[p].add(v);
            rm[v].add(p);
            arr[p][0]=arr[p][1]=p;
            flag=true;
        }
        if (cs >2) {
            while (cs >= 3) {
                Integer v1 = li[v].get(l);
                if(rm[v].contains(v1) || v1.equals(p)){
                    l++;
                    continue;
                }
                removeEdge.add(new Pair(v, v1));
                result.add(new Pair(arr[v1][0],arr[v1][1]));
                flag=true;
                rm[v].add(v1);
                rm[v1].add(v);
                cs--;
                l++;
            }
        }
        if(p==-1 && cs==2){
            arr[v][0]=v;
            arr[v][1]=v;
            for (int i = 0; i < li[v].size(); i++) {
                Integer k=li[v].get(i);
                if(rm[v].contains(k) ){
                    continue;
                }else{
                    if(arr[v][0]==v)arr[v][0]=arr[k][1];
                    else arr[v][1]=arr[k][1];
                }
            }
            result.add(new Pair(arr[v][0],arr[v][1]));
            return;
        }
        if(!flag){
            arr[v][0]=v;
            arr[v][1]=v;
            for (int i = 0; i < li[v].size(); i++) {
                Integer k=li[v].get(i);

                if(rm[v].contains(k) || k.equals(p)){
                    continue;
                }else{
                    arr[v][1]=arr[k][1];
                    break;
                }
            }
            if(p==-1){
                result.add(new Pair(arr[v][0],arr[v][1]));
            }
        }

    }

    static class Pair {
        int u;
        int v;

        Pair(int u, int v) {
            this.u = u;
            this.v = v;
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