import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public static final int MAXN = (int) 1e5;
        int np;
        int[] div = new int[MAXN];
        int[] prime = new int[100];
        int nprime = 0;
        int[] lprime = new int[100];
        int[] lcnt = new int[100];
        int ndiv;

        void getDiv(int n) {
            np = 0;
            for (int i = 0; i < nprime; ++i) {
                if (n % prime[i] == 0) {
                    lprime[np] = prime[i];
                    lcnt[np] = 0;

                    while (n % prime[i] == 0) {
                        n /= prime[i];
                        lcnt[np]++;

                    }
                    np++;
                    if (n == 1) break;
                }
            }
            if (n > 1) {
                lprime[np] = n;
                lcnt[np] = 1;
                np++;
            }

            ndiv = 0;
            rec(1, 0);
            

        }

        private void rec(int mul, int id) {
            if (mul != 1) {
                div[ndiv++] = mul;

            }
            for (int i = id; i < np; ++i) {
                int lastMul = 1;
                for (int mu = 1; mu <= lcnt[i]; mu++) {
                    lastMul *= lprime[i];
                    rec(mul * lastMul, i + 1);

                }
            }
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int sqrt = (int) Math.sqrt(MAXN) + 1;
            nprime = 0;
            for (int i = 2; i <= sqrt; ++i)
                if (IntMath.isPrime(i)) {
                    prime[nprime++] = i;
                }

            int n = in.nextInt();
            int[] cnt = new int[MAXN + 1];
            for (int i = 0; i < n; ++i) {
                int val = in.nextInt();
                getDiv(val);
                for (int j = 0; j < ndiv; ++j) {
                    cnt[div[j]]++;
                }
            }

            int[] pow2 = new int[MAXN + 1];
            pow2[0] = 1;
            for (int i = 1; i < MAXN + 1; ++i) {
                pow2[i] = Mod.mulMod(pow2[i - 1], 2);
            }
            int[] f = new int[MAXN + 1];
            for (int i = 0; i < MAXN + 1; ++i) {
                f[i] = pow2[cnt[i]] - 1;
            }
            int su = 0;
            for (int i = MAXN; i > 1; --i)
                if (f[i] != 0) {
                    getDiv(i);
                    for (int j = 0; j < ndiv; ++j)
                        if (div[j] != i) {
                            f[div[j]] = Mod.subMod(f[div[j]], f[i]);
                        }
                    su = Mod.addMod(su, f[i]);
                }

            out.println(Mod.subMod(Mod.subMod(pow2[n], 1), su));
        }

    }

    static final class UnsignedLongs {
        private UnsignedLongs() {
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

    static class Mod {
        public static final long MOD = 1000000007L;
        public static final boolean DEBUG = false;

        public static int addMod(int a, int b) {
            if (DEBUG) return a + b;

            while (a < 0)
                a += MOD;
            while (b < 0)
                b += MOD;
            return (int) (((long) a + (long) b) % MOD);
        }

        public static int subMod(int a, int b) {
            if (DEBUG) return a - b;

            while (a < 0)
                a += MOD;
            while (b < 0)
                b += MOD;
            long temp = (long) a - (long) b;

            while (temp < 0)
                temp += MOD;
            return (int) temp;
        }

        public static int mulMod(int a, int b) {
            if (DEBUG) return a * b;

            while (a < 0)
                a += MOD;
            while (b < 0)
                b += MOD;
            return (int) (((long) a) * ((long) b) % MOD);
        }

    }

    static final class IntMath {
        public static boolean isPrime(int n) {
            return LongMath.isPrime(n);
        }

        private IntMath() {
        }

    }

    static final class LongMath {
        static final long FLOOR_SQRT_MAX_LONG = 3037000499L;
        private static final int SIEVE_30 = ~((1 << 1) | (1 << 7) | (1 << 11) | (1 << 13)
                | (1 << 17) | (1 << 19) | (1 << 23) | (1 << 29));
        private static final long[][] millerRabinBaseSets = {
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
                MathPreconditions.checkNonNegative("n", n);
                return false;
            }
            if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13) {
                return true;
            }

            if ((SIEVE_30 & (1 << (n % 30))) != 0) {
                return false;
            }
            if (n % 7 == 0 || n % 11 == 0 || n % 13 == 0) {
                return false;
            }
            if (n < 17 * 17) {
                return true;
            }

            for (long[] baseSet : millerRabinBaseSets) {
                if (n <= baseSet[0]) {
                    for (int i = 1; i < baseSet.length; i++) {
                        if (!LongMath.MillerRabinTester.test(baseSet[i], n)) {
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

        private enum MillerRabinTester {
            
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

                
                private long times2ToThe32Mod(long a, long m) {
                    int remainingPowersOf2 = 32;
                    do {
                        int shift = Math.min(remainingPowersOf2, Long.numberOfLeadingZeros(a));
                        

                        

                        a = UnsignedLongs.remainder(a << shift, m);
                        remainingPowersOf2 -= shift;
                    } while (remainingPowersOf2 > 0);
                    return a;
                }


                long mulMod(long a, long b, long m) {
                    long aHi = a >>> 32; 

                    long bHi = b >>> 32; 

                    long aLo = a & 0xFFFFFFFFL; 

                    long bLo = b & 0xFFFFFFFFL; 


        
                    long result = times2ToThe32Mod(aHi * bHi , m); 

                    result += aHi * bLo; 

                    if (result < 0) {
                        result = UnsignedLongs.remainder(result, m);
                    }
                    

                    result += aLo * bHi; 

                    result = times2ToThe32Mod(result, m); 

                    return plusMod(
                            result,
                            UnsignedLongs.remainder(aLo * bLo , m),
                            m);
                }


                long squareMod(long a, long m) {
                    long aHi = a >>> 32; 

                    long aLo = a & 0xFFFFFFFFL; 


        
                    long result = times2ToThe32Mod(aHi * aHi , m); 

                    long hiLo = aHi * aLo * 2;
                    if (hiLo < 0) {
                        hiLo = UnsignedLongs.remainder(hiLo, m);
                    }
                    

                    result += hiLo; 

                    result = times2ToThe32Mod(result, m); 

                    return plusMod(
                            result,
                            UnsignedLongs.remainder(aLo * aLo , m),
                            m);
                }
            },;

            static boolean test(long base, long n) {
                

                

                return ((n <= FLOOR_SQRT_MAX_LONG) ? SMALL : LARGE).testWitness(base, n);
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

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c))
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
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static final class MathPreconditions {
        static long checkNonNegative(String role, long x) {
            if (x < 0) {
                throw new IllegalArgumentException(role + " (" + x + ") must be >= 0");
            }
            return x;
        }

        private MathPreconditions() {
        }

    }

    static final class Longs {
        private Longs() {
        }

        public static int compare(long a, long b) {
            return (a < b) ? -1 : ((a > b) ? 1 : 0);
        }

    }
}

