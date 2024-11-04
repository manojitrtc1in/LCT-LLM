import javax.swing.text.DateFormatter;
import java.io.*;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.time.DateTimeException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.*;
import java.util.List;
import java.util.function.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.pow;
import static java.lang.Math.abs;

import static java.lang.String.format;


public class Main {
    final static int INF = Integer.MAX_VALUE>>1;
    final static int MOD = 1_000_000_007;
    final static int[] dx4 = { 0, 1, 0, -1 };
    final static int[] dy4 = { 1, 0, -1, 0 };
    final static int[] dx8 = {0, 1, 1,  1,  0, -1, -1, -1};
    final static int[] dy8 = {1, 1, 0, -1, -1, -1, 0, 1};
    public static void main(String[] args) {
        Scanner sc=new Scanner();
        int time = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        main:for (int t = 0; t < time; t++) {
            int n = sc.nextInt();
            long m = sc.nextInt();
            long k=sc.nextInt();
            long[] h=new long[n];
            for (int i = 0; i < n; i++) {
                h[i] = sc.nextInt();
            }
            long current = h[0];
            for (int i = 1; i < n; i++) {
                long next = h[i];
                if(next-k<=current){
                    m+=current-max(0,next-k);
                }else{
                    m-=(next-k)-current;
                }
                if(m<0){
                    sb.append("NO\n");
                    continue main;
                }
                current=next;
            }
            sb.append("YES\n");
        }
        put(sb);



    }


    public static void print(Object object){
        System.out.print(object);
    }
    public static void put(Object object) {
        System.out.println(object);
    }
    public static void put(){
        System.out.println();
    }

    public static void printE(Object object){
        System.err.print("DEBUG:"+object);
    }
    public static void putE(Object object){
        System.err.println("DEBUG:"+object);
    }
    public static void putE(){
        System.err.println("DEBUG:");
    }

    public static void print(String format,Object... args){
        System.out.print(String.format(format,args));
    }
    public static void put(String format,Object... args) {
        System.out.println(String.format(format,args));
    }
    public static void printE(String format,Object... args){
        System.err.print("DEBUG:"+String.format(format,args));
    }
    public static void putE(String format,Object... args){
        System.err.println("DEBUG:"+String.format(format,args));
    }

    final static private class Scanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        private boolean id8() {
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
            if (id8())
                return buffer[ptr++];
            else
                return -1;
        }

        private boolean id7(int c) {
            return 33 <= c && c <= 126;
        }

        public boolean hasNext() {
            while (id8() && !id7(buffer[ptr]))
                ptr++;
            return id8();
        }

        public String next() {
            if (!hasNext())
                throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (id7(b)) {
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
                } else if (b == -1 || !id7(b)) {
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
    final static private class id4 {
        final public int x, y;
        final static public id4 ZEROS=new id4(0,0);
        id4(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public static double distance(id4 id1,id4 id6){
            double x = (double) id1.x - id6.x;
            double y = (double) id1.y - id6.y;
            return Math.sqrt(x*x+y*y);
        }

        @Override
        public int hashCode() {
            return x+y;
        }

        @Override
        public boolean equals(Object obj) {
            if(obj==null)return false;
            if(!(obj instanceof id4)) return false;
            id4 pair=(id4) obj;
            return this.x==pair.x&&this.y==pair.y;
        }

        @Override
        public String toString() {
            return String.format(id4.class.getSimpleName()+":(%d,%d)", x, y);
        }
    }
    final static private class id3 {
        final public long x, y;
        final static public id3 ZEROS=new id3(0,0);
        id3(long x, long y) {
            this.x = x;
            this.y = y;
        }
        public static double distance(id3 id5,id3 id0){
            double x = (double) id5.x - id0.x;
            double y = (double) id5.y - id0.y;
            return Math.sqrt(x*x+y*y);
        }

        @Override
        public int hashCode() {
            return (int)x+(int)y;
        }

        @Override
        public boolean equals(Object obj) {
            if(obj==null)return false;
            if(!(obj instanceof id3)) return false;
            id3 pair=(id3)obj;
            return this.x==pair.x&&this.y==pair.y;
        }

        @Override
        public String toString() {
            return String.format(id3.class.getSimpleName()+":(%d,%d)", x, y);
        }
    }
    final static private class Binary{
        public static String id2(int i){
            return String.format("%"+Integer.toBinaryString(-1).length()+"s",Integer.toBinaryString(i)).replace(' ','0');
        }
        public static String id2(long i){
            return String.format("%"+Long.toBinaryString(-1).length()+"s",Long.toBinaryString(i)).replace(' ','0');
        }
    }

    final static private class Util {
        static long gcd(long a,long b){
            a=Math.abs(a);
            b=Math.abs(b);
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
            a=Math.abs(a);
            b=Math.abs(b);
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
        static boolean id9(int i,int j,int h,int w){
            return i>=0&&i<h&&j>=0&&j<w;
        }
    }
}































































