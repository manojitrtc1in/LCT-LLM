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
    final static int INF = Integer.MAX_VALUE >> 1;
    final static int MOD = 1_000_000_007;
    final static int[] dx4 = {0, 1, 0, -1};
    final static int[] dy4 = {1, 0, -1, 0};
    final static int[] dx8 = {0, 1, 1, 1, 0, -1, -1, -1};
    final static int[] dy8 = {1, 1, 0, -1, -1, -1, 0, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner();
        boolean[] ela = new boolean[100000];
        Arrays.fill(ela, true);
        for (int i = 2; i < ela.length; i++) {
            int j = 2 * i;
            while (j < ela.length) {
                ela[j] = false;
                j += i;
            }
        }
        int n = sc.nextInt();

        StringBuilder sb=new StringBuilder();
        if (n == 7) {
            sb.append(7 + "\n");
            for (int i = 1; i < 7; i++) {
                sb.append(i+" "+(i+1)+"\n");
            }
            sb.append("7 1");
        } else if (n == 8) {
            sb.append(11+"\n");
            for (int i = 1; i < 8; i++) {
                sb.append(i+" "+(i+1)+"\n");
            }
            sb.append("8 1\n");
            sb.append("1 3\n");
            sb.append("3 7\n");
            sb.append("3 8");
        } else if (n == 9) {
            sb.append(11+"\n");
            for (int i = 1; i < 9; i++) {
                sb.append(i+" "+(i+1)+"\n");
            }
            sb.append("9 1\n");
            sb.append("1 3\n");
            sb.append("4 6");
        } else {
            main:for (int a3 = 0; 3 * a3 <= n; a3++) {
                for (int a4 = 0; 3 * a3 + 4 * a4 <= n; a4++) {
                    for (int a5 = 0; 3 * a3 + 4 * a4 + 5 * a5 <= n; a5++) {
                        for (int a6 = 0; 3 * a3 + 4 * a4 + 5 * a5 + 6 * a6 <= n; a6++) {
                            if(3 * a3 + 4 * a4 + 5 * a5 + 6 * a6 != n)continue ;
                            if(!ela[3 * a3 + 5 * a4 + 5 * a5 + 7 * a6])continue ;
                            int current=1;
                            sb.append(3 * a3 + 5 * a4 + 5 * a5 + 7 * a6+"\n");
                            for (int i = 0; i < a3; i++) {
                                sb.append(current+" "+(current+1)+"\n");
                                sb.append((current+1)+" "+(current+2)+"\n");
                                sb.append((current+2)+" "+(current)+"\n");
                                current+=3;
                            }
                            for (int i = 0; i < a4; i++) {
                                sb.append(current+" "+(current+1)+"\n");
                                sb.append(current + " " + (current + 2)+"\n");
                                sb.append((current+1)+" "+(current+2)+"\n");
                                sb.append((current+1)+" "+(current+3)+"\n");
                                sb.append((current+2)+" "+(current+3)+"\n");
                                current+=4;
                            }
                            for (int i = 0; i < a5; i++) {
                                sb.append(current+" "+(current+1)+"\n");
                                sb.append((current+1)+" "+(current+2)+"\n");
                                sb.append((current+2)+" "+(current+3)+"\n");
                                sb.append((current+3)+" "+(current+4)+"\n");
                                sb.append((current+4)+" "+(current)+"\n");
                                current+=5;
                            }
                            for (int i = 0; i < a6; i++) {
                                sb.append(current+" "+(current+1)+"\n");
                                sb.append((current+1)+" "+(current+2)+"\n");
                                sb.append((current+2)+" "+(current+3)+"\n");
                                sb.append((current+3)+" "+(current+4)+"\n");
                                sb.append((current+4)+" "+(current+5)+"\n");
                                sb.append((current+5)+" "+(current)+"\n");
                                sb.append((current)+" "+(current+2)+"\n");
                                current+=6;
                            }
                            break main;
                        }
                    }
                }
            }
        }
        put(sb);


    }


    public static void print(Object object) {
        System.out.print(object);
    }

    public static void put(Object object) {
        System.out.println(object);
    }

    public static void put() {
        System.out.println();
    }

    public static void printE(Object object) {
        System.err.print("DEBUG:" + object);
    }

    public static void putE(Object object) {
        System.err.println("DEBUG:" + object);
    }

    public static void putE() {
        System.err.println("DEBUG:");
    }

    public static void print(String format, Object... args) {
        System.out.print(String.format(format, args));
    }

    public static void put(String format, Object... args) {
        System.out.println(String.format(format, args));
    }

    public static void printE(String format, Object... args) {
        System.err.print("DEBUG:" + String.format(format, args));
    }

    public static void putE(String format, Object... args) {
        System.err.println("DEBUG:" + String.format(format, args));
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

    final static private class FixedIntPair {
        final public int x, y;
        final static public FixedIntPair ZEROS = new FixedIntPair(0, 0);

        FixedIntPair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public static double distance(FixedIntPair fip1, FixedIntPair fip2) {
            double x = (double) fip1.x - fip2.x;
            double y = (double) fip1.y - fip2.y;
            return Math.sqrt(x * x + y * y);
        }

        @Override
        public int hashCode() {
            return x + y;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null) return false;
            if (!(obj instanceof FixedIntPair)) return false;
            FixedIntPair pair = (FixedIntPair) obj;
            return this.x == pair.x && this.y == pair.y;
        }

        @Override
        public String toString() {
            return String.format(FixedIntPair.class.getSimpleName() + ":(%d,%d)", x, y);
        }
    }

    final static private class FixedLongPair {
        final public long x, y;
        final static public FixedLongPair ZEROS = new FixedLongPair(0, 0);

        FixedLongPair(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public static double distance(FixedLongPair flp1, FixedLongPair flp2) {
            double x = (double) flp1.x - flp2.x;
            double y = (double) flp1.y - flp2.y;
            return Math.sqrt(x * x + y * y);
        }

        @Override
        public int hashCode() {
            return (int) x + (int) y;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null) return false;
            if (!(obj instanceof FixedLongPair)) return false;
            FixedLongPair pair = (FixedLongPair) obj;
            return this.x == pair.x && this.y == pair.y;
        }

        @Override
        public String toString() {
            return String.format(FixedLongPair.class.getSimpleName() + ":(%d,%d)", x, y);
        }
    }

    final static private class Binary {
        public static String toZeroPadding(int i) {
            return String.format("%" + Integer.toBinaryString(-1).length() + "s", Integer.toBinaryString(i)).replace(' ', '0');
        }

        public static String toZeroPadding(long i) {
            return String.format("%" + Long.toBinaryString(-1).length() + "s", Long.toBinaryString(i)).replace(' ', '0');
        }
    }

    final static private class Util {
        static long gcd(long a, long b) {
            a = Math.abs(a);
            b = Math.abs(b);
            if (a < b) {
                long tmp = a;
                a = b;
                b = tmp;
            }
            while (b != 0) {
                long r = a % b;
                a = b;
                b = r;
            }
            return a;
        }

        static int gcd(int a, int b) {
            a = Math.abs(a);
            b = Math.abs(b);
            if (a < b) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            while (b != 0) {
                int r = a % b;
                a = b;
                b = r;
            }
            return a;
        }

        static long lcm(long a, long b) {
            long gcd = gcd(a, b);
            long result = b / gcd;
            return a * result;
        }

        static boolean isValidCell(int i, int j, int h, int w) {
            return i >= 0 && i < h && j >= 0 && j < w;
        }
    }
}































































