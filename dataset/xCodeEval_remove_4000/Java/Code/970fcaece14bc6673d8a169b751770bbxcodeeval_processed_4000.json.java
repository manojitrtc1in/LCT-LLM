import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.BitSet;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        id3 solver = new id3();
        solver.solve(1, in, out);
        out.close();
    }

    static class id3 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int mod = IntMath.pow(10, 9) + 7;
            Modular.initialize(mod);
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                long n = in.nextLong();
                long k = in.nextLong();
                

                long[] l = new long[1];
                l[0] = k;
                BitSet b = BitSet.valueOf(l);
                long accum = 0;
                for (int j = 0; j < b.length(); j++) {
                    if (b.get(j)) {
                        accum = Modular.add(accum, Modular.pow(n, j));
                    }
                }
                out.println(accum);
            }
        }

    }

    static final class id1 {
        static int id4(String role, int x) {
            if (x < 0) {
                throw new IllegalArgumentException(role + " (" + x + ") must be >= 0");
            }
            return x;
        }

        static long id4(String role, long x) {
            if (x < 0) {
                throw new IllegalArgumentException(role + " (" + x + ") must be >= 0");
            }
            return x;
        }

        private id1() {
        }

    }

    static final class id9 {
        private id9() {
        }

        private static long flip(long a) {
            return a ^ Long.MIN_VALUE;
        }

        public static int compare(long a, long b) {
            return Longs.compare(flip(a), flip(b));
        }

        public static long remainder(long dividend, long divisor) {
            if (divisor < 0) { 

                if (compare(dividend, divisor) < 0) {
                    return dividend; 

                } else {
                    return dividend - divisor; 

                }
            }

            

            if (dividend >= 0) {
                return dividend % divisor;
            }

            
            long quotient = ((dividend >>> 1) / divisor) << 1;
            long rem = dividend - quotient * divisor;
            return rem - (compare(rem, divisor) >= 0 ? divisor : 0);
        }

    }

    static final class Longs {
        private Longs() {
        }

        public static int compare(long a, long b) {
            return (a < b) ? -1 : ((a > b) ? 1 : 0);
        }

    }

    static final class LongMath {
        static final long id6 = 3037000499L;
        private static final int id8 = ~((1 << 1) | (1 << 7) | (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19) | (1 << 23)
                | (1 << 29));
        private static final long[][] id0 = {
                {291830, 126401071349994536L},
                {885594168, 725270293939359937L, 3569819667048198375L},
                {273919523040L, 15, 7363882082L, 992620450144556L},
                {47636622961200L, 2, 2570940, 211991001, 3749873356L},
                {
                        7999252175582850L,
                        2,
                        4130806001517L,
                        149795463772692060L,
                        186635894390467037L,
                        3967304179347715805L
                },
                {
                        585226005592931976L,
                        2,
                        123635709730000L,
                        9233062284813009L,
                        43835965440333360L,
                        761179012939631437L,
                        1263739024124850375L
                },
                {Long.MAX_VALUE, 2, 325, 9375, 28178, 450775, 9780504, 1795265022}
        };

        public static boolean isPrime(long n) {
            if (n < 2) {
                id1.id4("n", n);
                return false;
            }
            if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13) {
                return true;
            }

            if ((id8 & (1 << (n % 30))) != 0) {
                return false;
            }
            if (n % 7 == 0 || n % 11 == 0 || n % 13 == 0) {
                return false;
            }
            if (n < 17 * 17) {
                return true;
            }

            for (long[] baseSet : id0) {
                if (n <= baseSet[0]) {
                    for (int i = 1; i < baseSet.length; i++) {
                        if (!LongMath.id7.test(baseSet[i], n)) {
                            return false;
                        }
                    }
                    return true;
                }
            }
            throw new AssertionError();
        }

        private LongMath() {
        }

        private enum id7 {
            
            SMALL {
                long mulMod(long a, long b, long m) {
                    
                    return (a * b) % m;
                }


                long squareMod(long a, long m) {
                    return (a * a) % m;
                }
            },
            
            LARGE {
                
                private long plusMod(long a, long b, long m) {
                    return (a >= m - b) ? (a + b - m) : (a + b);
                }

                
                private long id5(long a, long m) {
                    int id11 = 32;
                    do {
                        int shift = Math.min(id11, Long.numberOfLeadingZeros(a));
                        

                        

                        a = id9.remainder(a << shift, m);
                        id11 -= shift;
                    } while (id11 > 0);
                    return a;
                }


                long mulMod(long a, long b, long m) {
                    long aHi = a >>> 32; 

                    long bHi = b >>> 32; 

                    long aLo = a & 0xFFFFFFFFL; 

                    long bLo = b & 0xFFFFFFFFL; 


                    
                    long result = id5(aHi * bHi , m); 

                    result += aHi * bLo; 

                    if (result < 0) {
                        result = id9.remainder(result, m);
                    }
                    

                    result += aLo * bHi; 

                    result = id5(result, m); 

                    return plusMod(result, id9.remainder(aLo * bLo , m), m);
                }


                long squareMod(long a, long m) {
                    long aHi = a >>> 32; 

                    long aLo = a & 0xFFFFFFFFL; 


                    
                    long result = id5(aHi * aHi , m); 

                    long hiLo = aHi * aLo * 2;
                    if (hiLo < 0) {
                        hiLo = id9.remainder(hiLo, m);
                    }
                    

                    result += hiLo; 

                    result = id5(result, m); 

                    return plusMod(result, id9.remainder(aLo * aLo , m), m);
                }
            },
            ;

            static boolean test(long base, long n) {
                

                

                return ((n <= id6) ? SMALL : LARGE).testWitness(base, n);
            }

            abstract long mulMod(long a, long b, long m);

            abstract long squareMod(long a, long m);

            private long powMod(long a, long p, long m) {
                long res = 1;
                for (; p != 0; p >>= 1) {
                    if ((p & 1) != 0) {
                        res = mulMod(res, a, m);
                    }
                    a = squareMod(a, m);
                }
                return res;
            }

            private boolean testWitness(long base, long n) {
                int r = Long.numberOfTrailingZeros(n - 1);
                long d = (n - 1) >> r;
                base %= n;
                if (base == 0) {
                    return true;
                }
                

                long a = powMod(base, d, n);
                

                

                

                if (a == 1) {
                    return true;
                }
                int j = 0;
                while (a != n - 1) {
                    if (++j == r) {
                        return false;
                    }
                    a = squareMod(a, n);
                }
                return true;
            }

        }

    }

    static final class IntMath {
        public static int pow(int b, int k) {
            id1.id4("exponent", k);
            switch (b) {
                case 0:
                    return (k == 0) ? 1 : 0;
                case 1:
                    return 1;
                case (-1):
                    return ((k & 1) == 0) ? 1 : -1;
                case 2:
                    return (k < Integer.SIZE) ? (1 << k) : 0;
                case (-2):
                    if (k < Integer.SIZE) {
                        return ((k & 1) == 0) ? (1 << k) : -(1 << k);
                    } else {
                        return 0;
                    }
                default:
                    

            }
            for (int accum = 1; ; k >>= 1) {
                switch (k) {
                    case 0:
                        return accum;
                    case 1:
                        return b * accum;
                    default:
                        accum *= ((k & 1) == 0) ? 1 : b;
                        b *= b;
                }
            }
        }

        private IntMath() {
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id10 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (id2(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id2(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = read();
            while (id2(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id2(c));
            return res * sgn;
        }

        public boolean id2(int c) {
            if (filter != null) {
                return filter.id2(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id10 {
            public boolean id2(int ch);

        }

    }

    static class Modular {
        public static int MOD;
        public static int SAVE_INV = 1000005;
        public static long[] save_inv = new long[SAVE_INV];

        public static long add(long val, long other) {
            return Math.floorMod(val + other, MOD);
        }

        public static long multiply(long val, long other) {
            return Math.floorMod(val * other, MOD);
        }

        public static void initialize(int mod) {
            MOD = mod;
            

            assert LongMath.isPrime(mod);

            save_inv[0] = 0;
            save_inv[1] = 1;

            for (int i = 2; i < SAVE_INV; i++)
                save_inv[i] = multiply(save_inv[MOD % i], (MOD - MOD / i));
        }

        public static long getInverse(long val) {
            if (val < SAVE_INV)
                return save_inv[(int) val];

            long product = 1;
            long v = val;

            while (v >= SAVE_INV) {
                product = (long) multiply(product, MOD - MOD / v);
                v = MOD % v;
            }

            return multiply(product, save_inv[(int) v]);
        }

        public static final long pow(long val, long k) {
            long result = 1;
            if (k < 0)
                return pow(getInverse(val), -k);
            while (k > 0) {
                if (k % 2 == 1)
                    result = multiply(result, val);
                k >>= 1;
                if (k > 0)
                    val = multiply(val, val);
            }
            return result;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }
}

