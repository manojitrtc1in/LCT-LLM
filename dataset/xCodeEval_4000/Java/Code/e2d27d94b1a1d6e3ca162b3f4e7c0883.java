


import javafx.util.Pair;

import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;

public class mainB {
    public static PrintWriter out = new PrintWriter(System.out);
    public static FastScanner enter = new FastScanner(System.in);
    public static BigInteger b=BigInteger.ONE;
    public static BigInteger c;
    public static BigInteger mod=BigInteger.ONE;
    public static BigInt ans;
    public static void main(String[] args) throws IOException {
        int n=enter.nextInt();
        ArrayList<pair> arr=new ArrayList<>();
        char[] wtf=new char[n];
        for (int i = 0; i <n ; i++) {
            wtf[i]=enter.nextChar();
        }
        String s=new String(wtf);



        for (int i = 1; i <s.length() ; i++) {
            if(s.charAt(i)-'0'==0) continue;
            arr.add(new pair(i,Math.max(i,s.length()-i)));
        }

        





        char[] tmp=new char[100001];
        for (int i = 0; i <tmp.length ; i++) {
            tmp[i]='1';
        }
        long g=System.currentTimeMillis();
        ans=new BigInt(new String(tmp));

        




        pair[] mass=new pair[arr.size()];
        for (int i = 0; i <mass.length ; i++) {
            mass[i]=arr.get(i);
        }
        long h=System.currentTimeMillis();
        

        for (int i = 0; i <Math.min(3,arr.size()) ; i++) {
            pair min=mass[i];
            int ind_min=i;
            for (int j = i; j <arr.size() ; j++) {
                if(min.f(mass[j])>0){
                    ind_min=j;
                    min=mass[j];
                }
            }
            pair tmp1=mass[i];
            mass[i]=mass[ind_min];
            mass[ind_min]=tmp1;
        }
        
        

        g=System.currentTimeMillis();
        for (int i = 0; i <Math.min(3,mass.length) ; i++) {
            BigInt a=new BigInt(s.substring(0,mass[i].x));
            BigInt b=new BigInt(s.substring(mass[i].x,s.length()));
            a.add(b);
            if(ans.compareTo(a)>0){
                ans=a;
            }
        }
        
        
        String j=ans.toString();
        for (int i = 0; i <j.length() ; i++) {
            out.print(j.charAt(i));
        }
        out.close();
    }
    static class BigInt extends Number implements Comparable<BigInt> {
        private static final long mask = (1L << 32) - 1;
        private int sign;
        private int len;
        private int[] dig;

        private BigInt(final int sign, final int[] v, final int len) {
            assign(sign, v, len);
        }

        private BigInt(final int sign, final int val) {
            dig = new int[1];
            uAssign(sign, val);
        }

        private int parse(final char[] s, int from, final int to) {
            int res = s[from] - '0';
            while (++from < to) res = res * 10 + s[from] - '0';
            return res;
        }

        private void mulAdd(final int add) {
            long carry = 0;
            for (int i = 0; i < len; i++) {
                carry = 1000000000 * (dig[i] & mask) + carry;
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

        private void reallocate() {
            final int[] res = new int[dig.length * 2];
            System.arraycopy(dig, 0, res, 0, len);
            dig = res;
        }

        private void reallocate(final int newLen) {
            final int[] res = new int[newLen];
            System.arraycopy(dig, 0, res, 0, len);
            dig = res;
        }

        private void assign(final int sign, final int[] v, final int len) {
            this.sign = sign;
            this.len = len;
            dig = v;
        }

        private void assign(final String s) {
            assign(s.toCharArray());
        }

        private void assign(final char[] s) {
            sign = s[0] == '-' ? -1 : 1;

            len = s.length + (sign - 1 >> 1);
            final int alloc = len < 10 ? 1 : (int) (len * 3402L >>> 10) + 32 >>> 5; 

            if (dig == null || alloc > dig.length) dig = new int[alloc];

            int j = len % 9;
            if (j == 0) j = 9;
            j -= (sign - 1 >> 1);

            dig[0] = parse(s, 0 - (sign - 1 >> 1), j);
            for (len = 1; j < s.length; )
                mulAdd(parse(s, j, j += 9));
        }

        private void uAssign(final int s, final int val) {
            sign = s;
            len = 1;
            dig[0] = val;
        }

        private void uAssign(final int s, final long val) {
            sign = s;
            len = 2;
            if (dig.length < 2) reallocate(2);
            dig[0] = (int) (val & mask);
            dig[1] = (int) (val >>> 32);
            if (dig[1] == 0) --len;
        }

        private void assign(final int val) {
            uAssign(val < 0 ? -1 : 1, val < 0 ? -val : val);
        }

        private void assign(final long val) {
            uAssign(val < 0 ? -1 : 1, val < 0 ? -val : val);
        }

        public boolean isZero() {
            return len == 1 && dig[0] == 0;
        }

        public int compareAbsTo(final BigInt a) {
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
                if (a.sign < 0 || a.isZero()) return -compareAbsTo(a);
                return -1;
            }
            if (a.sign > 0 || a.isZero()) return compareAbsTo(a);
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
            if (vlen > dig.length) reallocate(vlen + 1);

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
                    if (len == dig.length) reallocate();
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

        public void add(final BigInt a) {
            if (sign == a.sign) {
                addMag(a.dig, a.len);
                return;
            }
            if (compareAbsTo(a) >= 0) {
                subMag(a.dig, a.len);
                

                return;
            }

            final int[] v = a.dig;
            final int vlen = a.len;
            if (dig.length < vlen) reallocate(vlen + 1);

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
                for (long tmp = toStringDiv(); tmp > 0; tmp /= 10)
                    buf[--top] += tmp % 10; 

                if (len == 1 && dig[0] == 0) break;
                else top = j - 13;
            }
            if (sign < 0) buf[--top] = '-';
            System.arraycopy(cpy, 0, dig, 0, len = cpy.length);
            return new String(buf, top, buf.length - top);
        }

        private long toStringDiv() {
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

    }
    static class pair{
        int x;
        int y;

        public pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public int f(pair m){
            return Integer.compare(y,m.y);
        }

    }
    public static <T>  void sortMergeNoRecursive(T[] arr, int first, int last, Class<T> c, Comparator<T> comparator) {
        int len = last;
        int n = 1; 

        int shift; 

        int two_size; 

        T[] arr2;
        while (n < len) {
            shift = first;
            while (shift < len) {
                if (shift + n >= len) break;
                two_size = (shift + n * 2 > len) ? (len - (shift + n)) : n;
                arr2 = merge(Arrays.copyOfRange(arr, shift, shift + n),
                        Arrays.copyOfRange(arr, shift + n, shift + n + two_size),c,comparator);
                for (int i = 0; i < n + two_size; ++i)
                    arr[shift + i] = arr2[i]; 

                shift += n * 2;
            }
            n *= 2;
        }
    }

    public static <T> T[] merge(T[] arr_1, T[] arr_2,Class<T> c , Comparator<T> comparator) {
        int len_1 = arr_1.length, len_2 = arr_2.length;
        int a = 0, b = 0, len = len_1 + len_2; 

        

        T[] result=(T[]) Array.newInstance(c,len);


        for (int i = 0; i < len; i++) {
            if (b < len_2 && a < len_1) {
                if (comparator.compare(arr_1[a], arr_2[b]) > 0) result[i] = arr_2[b++];
                else result[i] = arr_1[a++];
            } else if (b < len_2) {
                result[i] = arr_2[b++];
            } else {
                result[i] = arr_1[a++];
            }
        }
        return result;
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer stok;

        FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        String next() throws IOException {
            while (stok == null || !stok.hasMoreTokens()) {
                String s = br.readLine();
                if (s == null) {
                    return null;
                }
                stok = new StringTokenizer(s);
            }
            return stok.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        char nextChar() throws IOException {
            return (char) (br.read());
        }

        String nextLine() throws IOException {
            return br.readLine();
        }
    }
}

