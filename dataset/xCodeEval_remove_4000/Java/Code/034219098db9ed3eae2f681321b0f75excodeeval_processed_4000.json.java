import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.math.BigInteger;
import java.util.Collections;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        id3 solver = new id3();
        solver.solve(1, in, out);
        out.close();
    }

    static class id3 {
        int np;
        static final int MAXN = 200000;
        static int nprime = 0;
        static int[] prime;
        int[] lprime = new int[100];
        int[] lcnt = new int[100];
        int ndiv = 0;
        int[] div = new int[MAXN + 1];
        int n;
        int m;
        boolean[] black;
        int[] pr;
        int[] sv;
        int[] best;

        static {
            int sqrt = (int) Math.sqrt(MAXN) + 1;
            prime = new int[sqrt + 1];
            for (int i = 2; i < sqrt; ++i)
                if (IntMath.isPrime(i)) {
                    prime[nprime++] = i;
                }
        }

        void id4(int n) {
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
            div[ndiv++] = 1;
            

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

            n = in.nextInt();
            m = in.nextInt();
            black = new boolean[m];
            for (int i = 0; i < n; ++i) {
                black[in.nextInt()] = true;
            }
            ArrayList<Pair<Integer, Integer>> lp = new ArrayList<>();

            for (int i = 0; i < m; ++i)
                if (!black[i]) {
                    

                    lp.add(new Pair<>(IntMath.gcd(i, m), i));
                }
            Collections.sort(lp);

            pr = new int[m + 1];
            sv = new int[m + 1];
            Arrays.fill(pr, -1);
            best = new int[m + 1];
            for (Pair<Integer, Integer> pa : lp) {
                int nn = pa.second;
                int gg = pa.first;
                if (nn != 0) {
                    id4(nn);
                } else {


                    ndiv = m - 1;
                    for (int i = 1; i <= m - 1; ++i) {
                        div[i - 1] = i;
                    }
                }
                int be = 1;

                for (int i = 0; i < ndiv; ++i) {
                    if (best[div[i]] + 1 > be) {
                        be = best[div[i]] + 1;
                        pr[nn] = sv[div[i]];
                    }
                }

                if (be > best[gg]) {
                    best[gg] = be;
                    sv[gg] = nn;
                }
            }

            int be = 0;
            int s = -1;
            for (int i = 1; i <= m; ++i) {
                if (best[i] > be) {
                    be = best[i];
                    s = i;
                }
            }

            if (be == 0) throw new RuntimeException();
            

            int[] re = new int[m];
            int nre = 0;

            int bd = sv[s];
            while (bd != -1) {
                

                re[nre++] = bd;
                bd = pr[bd];
            }

            MathUtils.reverseArray(re, 0, nre);
            out.println(nre);
            out.print(re[0]);
            for (int i = 1; i < nre; ++i) {
                int a = re[i - 1];
                int b = re[i];
                int g = IntMath.gcd(a, m);
                int aa = a / g;
                int bb = b / g;
                int mm = m / g;
                int x = (int) ((1l * MathUtils.modInverse(aa, mm) * bb) % mm);
                out.print(" " + x);
            }
        }

    }

    static final class id1 {
        static int id6(String role, int x) {
            if (x < 0) {
                throw new IllegalArgumentException(role + " (" + x + ") must be >= 0");
            }
            return x;
        }

        static long id6(String role, long x) {
            if (x < 0) {
                throw new IllegalArgumentException(role + " (" + x + ") must be >= 0");
            }
            return x;
        }

        private id1() {
        }

    }

    static final class LongMath {
        static final long id9 = 3037000499L;
        private static final int id12 = ~((1 << 1) | (1 << 7) | (1 << 11) | (1 << 13)
                | (1 << 17) | (1 << 19) | (1 << 23) | (1 << 29));
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
                id1.id6("n", n);
                return false;
            }
            if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13) {
                return true;
            }

            if ((id12 & (1 << (n % 30))) != 0) {
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
                        if (!LongMath.id10.test(baseSet[i], n)) {
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

        private enum id10 {
            
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

                
                private long id8(long a, long m) {
                    int id14 = 32;
                    do {
                        int shift = Math.min(id14, Long.numberOfLeadingZeros(a));
                        

                        

                        a = id13.remainder(a << shift, m);
                        id14 -= shift;
                    } while (id14 > 0);
                    return a;
                }


                long mulMod(long a, long b, long m) {
                    long aHi = a >>> 32; 

                    long bHi = b >>> 32; 

                    long aLo = a & 0xFFFFFFFFL; 

                    long bLo = b & 0xFFFFFFFFL; 


        
                    long result = id8(aHi * bHi , m); 

                    result += aHi * bLo; 

                    if (result < 0) {
                        result = id13.remainder(result, m);
                    }
                    

                    result += aLo * bHi; 

                    result = id8(result, m); 

                    return plusMod(
                            result,
                            id13.remainder(aLo * bLo , m),
                            m);
                }


                long squareMod(long a, long m) {
                    long aHi = a >>> 32; 

                    long aLo = a & 0xFFFFFFFFL; 


        
                    long result = id8(aHi * aHi , m); 

                    long hiLo = aHi * aLo * 2;
                    if (hiLo < 0) {
                        hiLo = id13.remainder(hiLo, m);
                    }
                    

                    result += hiLo; 

                    result = id8(result, m); 

                    return plusMod(
                            result,
                            id13.remainder(aLo * aLo , m),
                            m);
                }
            },;

            static boolean test(long base, long n) {
                

                

                return ((n <= id9) ? SMALL : LARGE).testWitness(base, n);
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
        public static int gcd(int a, int b) {
    
            id1.id6("a", a);
            id1.id6("b", b);
            if (a == 0) {
                

                

                return b;
            } else if (b == 0) {
                return a; 

            }
    
            int id11 = Integer.numberOfTrailingZeros(a);
            a >>= id11; 

            int id5 = Integer.numberOfTrailingZeros(b);
            b >>= id5; 

            while (a != b) { 

                

                

                


                

                


                int delta = a - b; 


                int id7 = delta & (delta >> (Integer.SIZE - 1));
                


                a = delta - id7 - id7; 

                


                b += id7; 

                a >>= Integer.numberOfTrailingZeros(a); 

            }
            return a << Math.min(id11, id5);
        }

        public static boolean isPrime(int n) {
            return LongMath.isPrime(n);
        }

        private IntMath() {
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

        public static boolean id2(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static final class id13 {
        private id13() {
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

    static class MathUtils {
        static long _invMod(long a, long b) {
            return 1 < a ? b - _invMod(b % a, a) * b / a : 1;
        }

        public static int modInverse(int a, int m) {













            return (int) _invMod(a, m);

        }

        public static void swap(int[] a, int i, int j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }

        public static void reverseArray(int[] a, int first, int last) {
            while ((first != last) && (first != --last)) {
                swap(a, first, last);
                ++first;
            }
        }

    }

    static final class Longs {
        private Longs() {
        }

        public static int compare(long a, long b) {
            return (a < b) ? -1 : ((a > b) ? 1 : 0);
        }

    }

    static class Pair<T1 extends Comparable<T1>, T2 extends Comparable<T2>> implements Comparable<Pair<T1, T2>> {
        public T1 first;
        public T2 second;

        public Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }


        public int compareTo(Pair<T1, T2> o) {
            int _c1 = first.compareTo(o.first);
            if (_c1 != 0)
                return _c1;
            return second.compareTo(o.second);
        }

        public String toString() {
            return first + " " + second;
        }


        public int hashCode() {
            return first.hashCode() ^ second.hashCode();
        }

        public boolean equals(Object obj) {
            if (obj instanceof Pair) {
                Pair p = (Pair) obj;
                return first.equals(p.first) && second.equals(p.second);
            }
            return false;
        }

    }
}

