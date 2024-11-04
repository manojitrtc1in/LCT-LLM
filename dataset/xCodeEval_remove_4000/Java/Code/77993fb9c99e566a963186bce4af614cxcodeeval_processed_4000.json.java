import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedOutputStream;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            BigInt a = new BigInt(in.nextString()), b = new BigInt(in.nextString());
            final int LOG = 64;
            int[] A = new int[LOG], B = new int[LOG];
            for (int i = 0; i < LOG; i++) {
                A[i] = a.testBit(i) ? 1 : 0;
                B[i] = b.testBit(i) ? 1 : 0;
            }
            int[][] dp = new int[LOG][2], pre = new int[LOG][2];
            dp[0][0] = A[0] == B[0] ? 0 : -1;
            dp[0][1] = A[0] == 0 && B[0] == 0 ? 1 : -1;
            for (int i = 1; i < LOG; i++)
                for (int j = 0; j < 2; j++) {
                    int carry = j, xor = B[i], sum = A[i];
                    if (carry == 0) {
                        if (xor == 0) {
                            if (sum == 0) {
                                dp[i][j] = dp[i - 1][0] == -1 ? -1 : 0;
                                pre[i][j] = 0;
                            } else {
                                dp[i][j] = dp[i - 1][1] == -1 ? -1 : 0;
                                pre[i][j] = 1;
                            }
                        } else {
                            if (sum == 0) {
                                dp[i][j] = dp[i - 1][1] == -1 ? -1 : 0;
                                pre[i][j] = 1;
                            } else {
                                dp[i][j] = dp[i - 1][0] == -1 ? -1 : 0;
                                pre[i][j] = 0;
                            }
                        }
                    } else {
                        if (xor == 0) {
                            if (sum == 0) {
                                dp[i][j] = dp[i - 1][0] == -1 ? -1 : 1;
                                pre[i][j] = 0;
                            } else {
                                dp[i][j] = dp[i - 1][1] == -1 ? -1 : 1;
                                pre[i][j] = 1;
                            }
                        } else {
                            if (sum == 0) {
                                dp[i][j] = dp[i - 1][1] == -1 ? -1 : 0;
                                pre[i][j] = 1;
                            } else {
                                dp[i][j] = -1;
                            }
                        }
                    }
                }
            if (dp[LOG - 1][0] == -1) out.println(-1);
            else {
                BigInt X = new BigInt(0);
                for (int i = LOG - 1, j = 0; i >= 0; i--) {
                    if (dp[i][j] == 1) X.setBit(i);
                    j = pre[i][j];
                }
                BigInt Y = a;
                Y.sub(X);
                out.println(X + " " + Y);
            }
        }

    }

    static class BigInt extends Number implements Comparable<BigInt> {
        private static final long mask = (1L << 32) - 1;
        private int sign;
        private int len;
        private int[] dig;

        public BigInt(final int sign, final int[] v, final int len) {
            assign(sign, v, len);
        }

        public BigInt(final int sign, final byte[] v, int vlen) {
            while (vlen > 1 && v[vlen - 1] == 0) --vlen;
            dig = new int[(vlen + 3) / 4];
            assign(sign, v, vlen);
        }

        public BigInt(final int sign, final int val) {
            dig = new int[1];
            uassign(sign, val);
        }

        public BigInt(final int sign, final long val) {
            dig = new int[2];
            uassign(sign, val);
        }

        public BigInt(final int val) {
            dig = new int[1];
            assign(val);
        }

        public BigInt(final long val) {
            dig = new int[2];
            assign(val);
        }

        public BigInt(final String s) {
            assign(s);
        }

        public BigInt(final char[] s) {
            assign(s);
        }

        private int parse(final char[] s, int from, final int to) {
            int res = s[from] - '0';
            while (++from < to) res = res * 10 + s[from] - '0';
            return res;
        }

        private void mulAdd(final int mul, final int add) {
            long carry = 0;
            for (int i = 0; i < len; i++) {
                carry = mul * (dig[i] & mask) + carry;
                dig[i] = (int) carry;
                carry >>>= 32;
            }
            if (carry != 0) dig[len++] = (int) carry;
            carry = (dig[0] & mask) + add;
            dig[0] = (int) carry;
            if ((carry >>> 32) != 0) {
                int i = 1;
                for (; i < len && ++dig[i] == 0; ++i) ;
                if (i == len) dig[len++] = 1; 

            }
        }

        private void realloc() {
            final int[] res = new int[dig.length * 2];
            System.arraycopy(dig, 0, res, 0, len);
            dig = res;
        }

        private void realloc(final int newLen) {
            final int[] res = new int[newLen];
            System.arraycopy(dig, 0, res, 0, len);
            dig = res;
        }

        public void assign(final int sign, final int[] v, final int len) {
            this.sign = sign;
            this.len = len;
            dig = v;
        }

        public void assign(final int sign, final byte[] v, final int vlen) {
            len = (vlen + 3) / 4;
            if (len > dig.length) dig = new int[len + 2];
            this.sign = sign;
            int tmp = vlen / 4, j = 0;
            for (int i = 0; i < tmp; i++, j += 4)
                dig[i] = v[j + 3] << 24 | (v[j + 2] & 0xFF) << 16 | (v[j + 1] & 0xFF) << 8 | v[j] & 0xFF;
            if (tmp != len) {
                tmp = v[j++] & 0xFF;
                if (j < vlen) {
                    tmp |= (v[j++] & 0xFF) << 8;
                    if (j < vlen) tmp |= (v[j] & 0xFF) << 16;
                }
                dig[len - 1] = tmp;
            }
        }

        public void assign(final String s) {
            assign(s.toCharArray());
        }

        public void assign(final char[] s) {
            sign = s[0] == '-' ? -1 : 1;

            len = s.length + (sign - 1 >> 1);
            final int alloc = len < 10 ? 1 : (int) (len * 3402L >>> 10) + 32 >>> 5; 

            if (dig == null || alloc > dig.length) dig = new int[alloc];

            int j = len % 9;
            if (j == 0) j = 9;
            j -= (sign - 1 >> 1);

            dig[0] = parse(s, 0 - (sign - 1 >> 1), j);
            for (len = 1; j < s.length; )
                mulAdd(1_000_000_000, parse(s, j, j += 9));
        }

        public void uassign(final int s, final int val) {
            sign = s;
            len = 1;
            dig[0] = val;
        }

        public void uassign(final int s, final long val) {
            sign = s;
            len = 2;
            if (dig.length < 2) realloc(2);
            dig[0] = (int) (val & mask);
            dig[1] = (int) (val >>> 32);
            if (dig[1] == 0) --len;
        }

        public void assign(final int val) {
            uassign(val < 0 ? -1 : 1, val < 0 ? -val : val);
        }

        public void assign(final long val) {
            uassign(val < 0 ? -1 : 1, val < 0 ? -val : val);
        }

        public boolean isZero() {
            return len == 1 && dig[0] == 0;
        }

        public int id0(final BigInt a) {
            if (len > a.len) return 1;
            if (len < a.len) return -1;
            for (int i = len - 1; i >= 0; i--)
                if (dig[i] != a.dig[i])
                    if ((dig[i] & mask) > (a.dig[i] & mask)) return 1;
                    else return -1;
            return 0;
        }

        public int compareTo(final BigInt a) {
            if (sign < 0) {
                if (a.sign < 0 || a.isZero()) return -id0(a);
                return -1;
            }
            if (a.sign > 0 || a.isZero()) return id0(a);
            return 1;
        }

        public boolean equals(final BigInt a) {
            if (len != a.len) return false;
            if (isZero() && a.isZero()) return true;
            if ((sign ^ a.sign) < 0) return false; 

            for (int i = 0; i < len; i++) if (dig[i] != a.dig[i]) return false;
            return true;
        }


        public boolean equals(final Object o) {
            if (o instanceof BigInt) return equals((BigInt) o);
            return false;
        }


        public int hashCode() {
            int hash = 0; 

            for (int i = 0; i < len; i++) hash = (int) (31 * hash + (dig[i] & mask));
            return sign * hash; 

        }


        public byte byteValue() {
            return (byte) (sign * (dig[0] & 0x7F));
        }


        public short shortValue() {
            return (short) (sign * (dig[0] & 0x7FFF));
        }


        public int intValue() {
            return sign * (dig[0] & 0x7FFFFFFF); 

        }


        public long longValue() {
            return len == 1 ? sign * (dig[0] & mask) : sign * ((dig[1] & 0x7FFFFFFFL) << 32 | (dig[0] & mask));
        }


        public float floatValue() {
            final int s = Integer.numberOfLeadingZeros(dig[len - 1]);
            if (len == 1 && s >= 8) return sign * dig[0];

            int bits = dig[len - 1]; 

            if (s <= 8) bits >>>= 8 - s;
            else bits = bits << s - 8 | dig[len - 2] >>> 32 - (s - 8); 

            bits ^= 1L << 23; 


            final int exp = (int) (((32 - s + 32L * (len - 1)) - 1 + 127) & 0xFF);
            bits |= exp << 23; 

            bits |= sign & (1 << 31); 


            return Float.intBitsToFloat(bits);
        }


        public double doubleValue() {
            if (len == 1) return sign * (dig[0] & mask);

            final int s = Integer.numberOfLeadingZeros(dig[len - 1]);
            if (len == 2 && 32 - s + 32 <= 53) return sign * ((long) dig[1] << 32 | (dig[0] & mask));

            long bits = (long) dig[len - 1] << 32 | (dig[len - 2] & mask); 

            if (s <= 11) bits >>>= 11 - s;
            else bits = bits << s - 11 | dig[len - 3] >>> 32 - (s - 11); 

            bits ^= 1L << 52; 


            final long exp = ((32 - s + 32L * (len - 1)) - 1 + 1023) & 0x7FF;
            bits |= exp << 52; 

            bits |= (long) sign & (1L << 63); 


            return Double.longBitsToDouble(bits);
        }

        private void addMag(int[] v, int vlen) {
            int ulen = len;
            int[] u = dig; 

            if (vlen < ulen) {
                u = v;
                v = dig;
                ulen = vlen;
                vlen = len;
            }
            if (vlen > dig.length) realloc(vlen + 1);

            long carry = 0;
            int i = 0;
            for (; i < ulen; i++) {
                carry = (u[i] & mask) + (v[i] & mask) + carry;
                dig[i] = (int) carry;
                carry >>>= 32;
            }
            if (vlen > len) {
                System.arraycopy(v, len, dig, len, vlen - len);
                len = vlen;
            }
            if (carry != 0) 

            {
                for (; i < len && ++dig[i] == 0; i++) ;
                if (i == len) 

                {
                    if (len == dig.length) realloc();
                    dig[len++] = 1;
                }
            }
        }

        private void subMag(final int[] u, final int ulen) {
            final int vlen = len;
            final int[] v = dig; 


            

            long dif = 0;
            int i = 0;
            for (; i < ulen; i++) {
                dif = (v[i] & mask) - (u[i] & mask) + dif;
                dig[i] = (int) dif;
                dif >>= 32;
            }
            if (dif != 0) {
                for (; dig[i] == 0; i++) --dig[i];
                if (--dig[i] == 0 && i + 1 == len) len = ulen;
            }
            while (len > 1 && dig[len - 1] == 0) --len;
        }

        public void sub(final BigInt a) {
            if (sign != a.sign) {
                addMag(a.dig, a.len);
                return;
            }
            if (id0(a) >= 0) {
                subMag(a.dig, a.len);
                

                return;
            }

            final int[] v = a.dig;
            final int vlen = a.len;
            if (dig.length < vlen) realloc(vlen + 1);

            sign = -sign;
            long dif = 0;
            int i = 0;
            for (; i < len; i++) {
                dif = (v[i] & mask) - (dig[i] & mask) + dif;
                dig[i] = (int) dif;
                dif >>= 32;
            }
            if (vlen > len) {
                System.arraycopy(v, len, dig, len, vlen - len);
                len = vlen;
            }
            if (dif != 0) {
                for (; i < vlen && dig[i] == 0; i++) --dig[i];
                if (--dig[i] == 0 && i + 1 == len) --len;
            }
            

        }

        public String toString() {
            if (isZero()) return "0";

            int top = len * 10 + 1;
            final char[] buf = new char[top];
            Arrays.fill(buf, '0');
            final int[] cpy = Arrays.copyOf(dig, len);
            while (true) {
                final int j = top;
                for (long tmp = id1(); tmp > 0; tmp /= 10)
                    buf[--top] += tmp % 10; 

                if (len == 1 && dig[0] == 0) break;
                else top = j - 13;
            }
            if (sign < 0) buf[--top] = '-';
            System.arraycopy(cpy, 0, dig, 0, len = cpy.length);
            return new String(buf, top, buf.length - top);
        }

        private long id1() {
            final int pow5 = 1_220_703_125, pow2 = 1 << 13;
            int nextq = 0;
            long rem = 0;
            for (int i = len - 1; i > 0; i--) {
                rem = (rem << 32) + (dig[i] & mask);
                final int q = (int) (rem / pow5);
                rem = rem % pow5;
                dig[i] = nextq | q >>> 13;
                nextq = q << 32 - 13;
            }
            rem = (rem << 32) + (dig[0] & mask);
            final int mod2 = dig[0] & pow2 - 1;
            dig[0] = nextq | (int) (rem / pow5 >>> 13);
            rem = rem % pow5;
            

            

            final long pow10 = (long) pow5 * pow2;
            rem = (rem - pow5 * (mod2 - rem) % pow10 * 67) % pow10;
            if (rem < 0) rem += pow10;
            if (dig[len - 1] == 0 && len > 1)
                if (dig[--len - 1] == 0 && len > 1)
                    --len;
            return rem;
        }

        public boolean testBit(final int bit) {
            final int bigBit = bit >>> 5, smallBit = bit & 31;
            if (bigBit >= len) return sign < 0;
            if (sign > 0) return (dig[bigBit] & 1 << smallBit) != 0;
            int j = 0;
            for (; j <= bigBit && dig[j] == 0; ) ++j;
            if (j > bigBit) return false;
            if (j < bigBit) return (dig[bigBit] & 1 << smallBit) == 0;
            j = -dig[bigBit];
            return (j & 1 << smallBit) != 0;
        }

        public void setBit(final int bit) {
            final int bigBit = bit >>> 5, smallBit = bit & 31;
            if (sign > 0) {
                if (bigBit >= dig.length) {
                    realloc(bigBit + 1);
                    len = bigBit + 1;
                } else if (bigBit >= len) {
                    for (; len <= bigBit; len++) dig[len] = 0;
                    

                }
                dig[bigBit] |= 1 << smallBit;
            } else {
                if (bigBit >= len) return;
                int j = 0;
                for (; j <= bigBit && dig[j] == 0; ) ++j;
                if (j > bigBit) {
                    dig[bigBit] = -1 << smallBit;
                    for (; dig[j] == 0; j++) dig[j] = -1;
                    dig[j] = ~-dig[j];
                    if (j == len - 1 && dig[len - 1] == 0) --len;
                    return;
                }
                if (j < bigBit) {
                    dig[bigBit] &= ~(1 << smallBit);
                    while (dig[len - 1] == 0) --len;
                    return;
                }
                j = Integer.lowestOneBit(dig[j]); 

                final int k = 1 << smallBit;
                if (k - j > 0) dig[bigBit] &= ~k; 

                else {
                    dig[bigBit] ^= ((j << 1) - 1) ^ (k - 1);
                    dig[bigBit] |= k;
                }
            }
        }

    }

    static class OutputWriter extends PrintWriter {
        public OutputWriter(OutputStream outputStream) {
            super(new BufferedOutputStream(outputStream));
        }

        public OutputWriter(Writer writer) {
            super(writer);
        }

        public void close() {
            super.close();
        }

    }

    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream));
        }

        private String next() {
            while (st == null || !st.hasMoreElements()) {
                st = new StringTokenizer(nextLine());
            }
            return st.nextToken();
        }

        public String nextString() {
            return next();
        }

        public String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

    }
}

