
import java.io.*;
import java.util.*;
import java.util.function.Predicate;
import java.util.stream.Collectors;

import static java.lang.Math.*;
import static java.lang.String.format;

public class Main {
    public static void main(String[] args) {
        solve();
    }
    final static int INF= Integer.MAX_VALUE>>2;
    final static int MOD = 1_000_000_007;
    final static int[] dx4 = { 0, 1, 0, -1 };
    final static int[] dy4 = { 1, 0, -1, 0 };
    final static int[] dx9 = {-1, -1, -1,  0,  0, 0, 1, 1,1};
    final static int[] dy9 = {-1, 0, 1, -1, 0, 1, -1, 0,1};
    final static Runnable me=()->{};
    public static void solve(){
        

        Scanner sc=new Scanner();
        int casesT = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        outer:for (int cases_i = 0; cases_i < casesT; cases_i++) {
            int n = sc.nextInt();
            long[] b = new long[n];
            for (int i = 0; i < n; i++) {
                b[i] = sc.nextLong();
            }
            long b1=0;
            for (int i = 0; i < n; i++) {
                b1 ^= b[i];
            }

            long b2=0;
            for (int i = 0; i < n; i++) {
                b2 += b[i];
            }
            b2 += b1;
            sb.append(2);
            sb.append("\n");
            sb.append(b1);
            sb.append(" ");
            sb.append(b2);
            sb.append("\n");


        }
        print(sb);


    }





    static class Encoder {
        final int m;

        public Encoder(int m) {
            this.m = m;
        }
        public int encode(int x,int y){
            assert y<m;
            return x * m + y;
        }
        public int decodeX(int z){
            return z / m;
        }
        public int decodeY(int z){
            return z % m;
        }
    }

    static class Accepter<T>{
        private T val;
        private final Predicate p;
        public Accepter(T defaultValue,Predicate p){
            this.val=defaultValue;
            this.p=p;
        }

        
        public boolean replace(T newVal){
            if(p.test(newVal)){
                this.val=newVal;
                return true;
            }
            return false;
        }
    }
    

    private static Runnable func(Object... objects){
        try{
            assert false;
            return me;
        }catch(AssertionError e){
            return ()->{put(objects);};
        }
    }
    private static void print(Object... objects){
        if(objects.length==1){
            System.out.print(objects[0]);
        }else{
            System.out.print(Arrays.toString(objects));
        }
    }
    private static void put(Object... objects) {
        print(objects);
        put();
    }
    private static void put(){
        System.out.println();
    }


    private static void runWhenEA(Runnable runnable){
        try{
            assert false;
        }catch(AssertionError e){
            PrintStream ps=System.out;
            PrintStream pse=System.err;
            System.setOut(pse);
            runnable.run();
            System.setOut(ps);
        }
    }
    private static void putM(String name,char[][] mat){
        put("---------------------"+name+"-----------------");
        for (int i = 0; i < mat.length; i++) {
            put(Arrays.toString(mat[i]));
        }
    }
    private static void putM(String name,int[][] mat){
        put("---------------------"+name+"-----------------");
        for (int i = 0; i < mat.length; i++) {
            put(Arrays.toString(mat[i]));
        }
    }
    private static void putM(String name,long[][] mat){
        put("---------------------"+name+"-----------------");
        for (int i = 0; i < mat.length; i++) {
            put(Arrays.toString(mat[i]));
        }
    }
    private static void putM(String name,boolean[][] mat){
        put("---------------------"+name+"-----------------");
        for (int i = 0; i < mat.length; i++) {
            put(Arrays.toString(mat[i]));
        }
    }
    final static private class Scanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

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
            if (hasNextByte())
                return buffer[ptr++];
            else
                return -1;
        }

        private boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }

        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr]))
                ptr++;
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
                    n *= 10;
                    n += b - '0';
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
    }
    static private class FixedIntPair {
        final public int x, y;
        final static public FixedIntPair ZEROS=new FixedIntPair(0,0);
        FixedIntPair(int x, int y) {
            this.x = x;
            this.y = y;
        }
        @Override
        public String toString() {
            return format(FixedIntPair.class.getSimpleName()+":(%d,%d)", x, y);
        }
    }
    final static private class FixedLongPair {
        final public long x, y;
        final static public FixedLongPair ZEROS=new FixedLongPair(0,0);
        FixedLongPair(long x, long y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int hashCode() {
            return (int)x+(int)y;
        }

        @Override
        public boolean equals(Object obj) {
            if(obj==null)return false;
            if(!(obj instanceof FixedLongPair)) return false;
            FixedLongPair pair=(FixedLongPair)obj;
            return this.x==pair.x&&this.y==pair.y;
        }

        @Override
        public String toString() {
            return format(FixedLongPair.class.getSimpleName()+":(%d,%d)", x, y);
        }
    }
    final static private class Binary{
        public static String toZeroPadding(int i){
            return format("%"+Integer.toBinaryString(-1).length()+"s",Integer.toBinaryString(i)).replace(' ','0');
        }
        public static String toZeroPadding(long i){
            return format("%"+Long.toBinaryString(-1).length()+"s",Long.toBinaryString(i)).replace(' ','0');
        }
    }
    public static class BinaryIndexedTree {
        final int n;
        final long[] array;
        BinaryIndexedTree(long[] array){
            this.n=array.length;
            this.array=new long[n];
            for(int i=0;i<array.length;i++){
                add(i,array[i]);
            }
        }
        BinaryIndexedTree(int[] array){
            this.n=array.length;
            this.array=new long[n];
            for(int i=0;i<array.length;i++){
                add(i,array[i]);
            }
        }
        public void add(int index,long val){
            for(;index<n;index|=index+1){
                array[index]+=val;
            }
        }
        public long sum(int index){
            long result=0;
            for(;index>=0;index=(index&(index+1))-1){
                result+=array[index];
            }
            return result;
        }

        
        public static int inv(int[] array){
            int[] a=new int[array.length];
            BinaryIndexedTree bit=new BinaryIndexedTree(a);
            bit.add(array[0]-1,1);
            int result=0;
            for(int i=1;i<array.length;i++){
                System.out.println(bit);
                result+=i-bit.sum(array[i]-1);
                bit.add(array[i]-1,1);
            }
            return result;
        }

        @Override
        public String toString() {
            long[] array=new long[n];
            for(int i=0;i<n;i++){
                array[i]=sum(i);
            }
            String result="";
            result+="ruiseki:"+ Arrays.toString(array)+"\n";
            array[0]=sum(0);
            for(int i=1;i<n;i++){
                array[i]=sum(i)-sum(i-1);
            }
            result+="source::"+Arrays.toString(array);
            return result;
        }
    }

    final static private class Util {
        static long gcd(long a,long b){
            a= abs(a);
            b= abs(b);
            if(a<b){
                long tmp=a;
                a=b;
                b=tmp;
            }
            while(b!=0){
                long r=a%b;
                a=b;
                b=r;
            }
            return a;
        }
        static int gcd(int a,int b){
            a= abs(a);
            b= abs(b);
            if(a<b){
                int tmp=a;
                a=b;
                b=tmp;
            }
            while(b!=0){
                int r=a%b;
                a=b;
                b=r;
            }
            return a;
        }
        static long lcm(long a,long b){
            long gcd=gcd(a,b);
            long result=b/gcd;
            return a*result;
        }
        static boolean isValidCell(int i,int j,int h,int w){
            return i>=0&&i<h&&j>=0&&j<w;
        }
    }
}
































































