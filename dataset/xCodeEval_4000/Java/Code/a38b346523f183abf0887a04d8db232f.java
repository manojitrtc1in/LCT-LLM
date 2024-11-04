import com.sun.security.jgss.GSSUtil;

import java.io.*;
import java.util.*;

public class Main {
    private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
    private FastWriter wr;
    private Reader rd;
    public final int MOD = 1000000007;

    
    class Reader {
        BufferedReader br;
        StringTokenizer st;

        public Reader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        public Reader(String path) throws FileNotFoundException {
            br = new BufferedReader(
                    new InputStreamReader(new FileInputStream(path)));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public int ni() throws IOException {
        return rd.nextInt();
    }

    public long nl() throws IOException {
        return rd.nextLong();
    }

    public void yOrn(boolean flag) {
        if (flag) {
            wr.println("YES");
        } else {
            wr.println("NO");
        }
    }

    char nc() throws IOException {
        return rd.next().charAt(0);
    }

    public String ns() throws IOException {
        return rd.nextLine();
    }

    public Double nd() throws IOException {
        return rd.nextDouble();
    }

    public int[] nai(int n) throws IOException {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = ni();
        }
        return arr;
    }

    public long[] nal(int n) throws IOException {
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nl();
        }
        return arr;
    }

    
    public static class FastWriter {
        private static final int BUF_SIZE = 1 << 13;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private FastWriter() {
            out = null;
        }

        public FastWriter(OutputStream os) {
            this.out = os;
        }

        public FastWriter(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public FastWriter write(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerflush();
            return this;
        }

        public FastWriter write(char c) {
            return write((byte) c);
        }

        public FastWriter write(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            }
            return this;
        }

        public FastWriter write(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            });
            return this;
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

        public FastWriter write(int x) {
            if (x == Integer.MIN_VALUE) {
                return write((long) x);
            }
            if (ptr + 12 >= BUF_SIZE) innerflush();
            if (x < 0) {
                write((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }

        private static int countDigits(long l) {
            if (l >= 1000000000000000000L) return 19;
            if (l >= 100000000000000000L) return 18;
            if (l >= 10000000000000000L) return 17;
            if (l >= 1000000000000000L) return 16;
            if (l >= 100000000000000L) return 15;
            if (l >= 10000000000000L) return 14;
            if (l >= 1000000000000L) return 13;
            if (l >= 100000000000L) return 12;
            if (l >= 10000000000L) return 11;
            if (l >= 1000000000L) return 10;
            if (l >= 100000000L) return 9;
            if (l >= 10000000L) return 8;
            if (l >= 1000000L) return 7;
            if (l >= 100000L) return 6;
            if (l >= 10000L) return 5;
            if (l >= 1000L) return 4;
            if (l >= 100L) return 3;
            if (l >= 10L) return 2;
            return 1;
        }

        public FastWriter write(long x) {
            if (x == Long.MIN_VALUE) {
                return write("" + x);
            }
            if (ptr + 21 >= BUF_SIZE) innerflush();
            if (x < 0) {
                write((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }

        public FastWriter write(double x, int precision) {
            if (x < 0) {
                write('-');
                x = -x;
            }
            x += Math.pow(10, -precision) / 2;
            

            write((long) x).write(".");
            x -= (long) x;
            for (int i = 0; i < precision; i++) {
                x *= 10;
                write((char) ('0' + (int) x));
                x -= (int) x;
            }
            return this;
        }

        public FastWriter writeln(char c) {
            return write(c).writeln();
        }

        public FastWriter writeln(int x) {
            return write(x).writeln();
        }

        public FastWriter writeln(long x) {
            return write(x).writeln();
        }

        public FastWriter writeln(double x, int precision) {
            return write(x, precision).writeln();
        }

        public FastWriter write(int... xs) {
            boolean first = true;
            for (int x : xs) {
                if (!first) write(' ');
                first = false;
                write(x);
            }
            return this;
        }

        public FastWriter write(long... xs) {
            boolean first = true;
            for (long x : xs) {
                if (!first) write(' ');
                first = false;
                write(x);
            }
            return this;
        }

        public FastWriter writeln() {
            return write((byte) '\n');
        }

        public FastWriter writeln(int... xs) {
            return write(xs).writeln();
        }

        public FastWriter writeln(long... xs) {
            return write(xs).writeln();
        }

        public FastWriter writeln(char[] line) {
            return write(line).writeln();
        }

        public FastWriter writeln(char[]... map) {
            for (char[] line : map) write(line).writeln();
            return this;
        }

        public FastWriter writeln(String s) {
            return write(s).writeln();
        }

        private void innerflush() {
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
            } catch (IOException e) {
                throw new RuntimeException("innerflush");
            }
        }

        public void flush() {
            innerflush();
            try {
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException("flush");
            }
        }

        public FastWriter print(byte b) {
            return write(b);
        }

        public FastWriter print(char c) {
            return write(c);
        }

        public FastWriter print(char[] s) {
            return write(s);
        }

        public FastWriter print(String s) {
            return write(s);
        }

        public FastWriter print(int x) {
            return write(x);
        }

        public FastWriter print(long x) {
            return write(x);
        }

        public FastWriter print(double x, int precision) {
            return write(x, precision);
        }

        public FastWriter println(char c) {
            return writeln(c);
        }

        public FastWriter println(int x) {
            return writeln(x);
        }

        public FastWriter println(long x) {
            return writeln(x);
        }

        public FastWriter println(double x, int precision) {
            return writeln(x, precision);
        }

        public FastWriter print(int... xs) {
            return write(xs);
        }

        public FastWriter print(long... xs) {
            return write(xs);
        }

        public FastWriter println(int... xs) {
            return writeln(xs);
        }

        public FastWriter println(long... xs) {
            return writeln(xs);
        }

        public FastWriter println(char[] line) {
            return writeln(line);
        }

        public FastWriter println(char[]... map) {
            return writeln(map);
        }

        public FastWriter println(String s) {
            return writeln(s);
        }

        public FastWriter println() {
            return writeln();
        }
    }


    
    boolean[] SAPrimeGenerator(int n) {
        

        

        boolean[] primeMarker = new boolean[n + 1];
        Arrays.fill(primeMarker, true);
        primeMarker[0] = false;
        primeMarker[1] = false;
        for (int i = 2; i <= n; i++) {
            if (primeMarker[i]) {
                

                for (int j = 2 * i; j <= n; j += i) {
                    primeMarker[j] = false;
                }
            }
        }
        return primeMarker;
    }

    private void tr(Object... o) {
        if (!oj) System.out.println(Arrays.deepToString(o));
    }

    class Pair<F, S> {
        private F first;
        private S second;


        Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }


        public F getFirst() {
            return first;
        }

        public S getSecond() {
            return second;
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "first=" + first +
                    ", second=" + second +
                    '}';
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair<F, S> pair = (Pair<F, S>) o;
            return first == pair.first && second == pair.second;
        }

        @Override
        public int hashCode() {
            return Objects.hash(first, second);
        }
    }

    class PairThree<F, S, X> {
        private F first;
        private S second;

        private X third;


        PairThree(F first, S second, X third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }


        public F getFirst() {
            return first;
        }

        public void setFirst(F first) {
            this.first = first;
        }

        public S getSecond() {
            return second;
        }

        public void setSecond(S second) {
            this.second = second;
        }

        public X getThird() {
            return third;
        }

        public void setThird(X third) {
            this.third = third;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            PairThree<?, ?, ?> pair = (PairThree<?, ?, ?>) o;
            return first.equals(pair.first) && second.equals(pair.second) && third.equals(pair.third);
        }

        @Override
        public int hashCode() {
            return Objects.hash(first, second, third);
        }
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    public void run() throws IOException {
        if (oj) {
            rd = new Reader();
            wr = new FastWriter(System.out);
        } else {
            File input = new File("input.txt");
            File output = new File("output.txt");
            if (input.exists() && output.exists()) {
                rd = new Reader(input.getPath());
                wr = new FastWriter(output.getPath());
            } else {
                rd = new Reader();
                wr = new FastWriter(System.out);
                oj = true;
            }
        }
        long s = System.currentTimeMillis();
        solve();
        wr.flush();
        tr(System.currentTimeMillis() - s + "ms");
    }

    
    boolean[] sieve;

    public void solve() throws IOException {
        sieve=SAPrimeGenerator(100000+1);
        int t = 1;
        t = ni();
        while (t-- > 0) {
            go();
        }
    }

    
    long gcd(long a, long b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    static int lower_bound(int array[], int key) {

        int low = 0, high = array.length;
        int mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (key <= array[mid]) {
                high = mid;
            } else {

                low = mid + 1;
            }
        }
        if (low < array.length && array[low] < key) {
            low++;
        }
        return low;
    }


    boolean isPowerOfTwo(int n) {
        int counter = 0;
        while (n != 0) {
            if ((n & 1) == 1) {
                counter++;
            }
            n = n >> 1;
        }
        return counter <= 1;
    }

    int getNoOfChar(String no, String find) {
        int counter = 0;
        int pointer = 1;
        for (int i = no.length() - 1; i >= 0; i--) {
            if (no.charAt(i) == find.charAt(pointer)) {
                pointer--;
                if (pointer < 0) {
                    break;
                }
            } else {
                counter++;
            }
        }
        if (pointer < 0) {
            return counter;
        } else {
            return Integer.MAX_VALUE;
        }
    }

    public boolean isPrime(int n) {
        if (n == 2 || n == 3) return false;
        boolean flag = true;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                flag = false;
            }
        }
        return flag;
    }

    boolean isSmaller(String str1, String str2) {
        int n1 = str1.length(), n2 = str2.length();

        if (n1 < n2)
            return true;
        if (n2 < n1)
            return false;

        for (int i = 0; i < n1; i++) {
            if (str1.charAt(i) < str2.charAt(i))
                return true;
            else if (str1.charAt(i) > str2.charAt(i))
                return false;
        }
        return false;
    }

    String findDiff(String str1, String str2) {
        if (isSmaller(str1, str2)) {
            String t = str1;
            str1 = str2;
            str2 = t;
        }
        String str = "";
        int n1 = str1.length(), n2 = str2.length();
        int diff = n1 - n2;
        int carry = 0;
        for (int i = n2 - 1; i >= 0; i--) {
            int sub
                    = (((int) str1.charAt(i + diff) - (int) '0')
                    - ((int) str2.charAt(i) - (int) '0')
                    - carry);
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            } else
                carry = 0;

            str += String.valueOf(sub);
        }
        for (int i = n1 - n2 - 1; i >= 0; i--) {
            if (str1.charAt(i) == '0' && carry > 0) {
                str += "9";
                continue;
            }
            int sub = (((int) str1.charAt(i) - (int) '0')
                    - carry);
            if (i > 0 || sub > 0)
                str += String.valueOf(sub);
            carry = 0;
        }
        return new StringBuilder(str).reverse().toString();
    }


    public int power(int n, int p, int mod) {
        int ans = 1;
        for (int i = 1; i <= p; i++) {
            ans = (ans << 1) % mod;
        }
        return ans;
    }

    public boolean isPalindromeTime(int time) {
        time = (time) % 1440;
        String hour = String.valueOf((time / 60));
        String minute = String.valueOf((time % 60));

        if (hour.length() == 1) {
            hour = "0" + hour;
        }
        if (minute.length() == 1) {
            minute = "0" + minute;
        }

        if (hour.charAt(0) == minute.charAt(1) && hour.charAt(1) == minute.charAt(0)) {
            return true;
        } else {
            return false;
        }
    }


    public int getOddMaker(int n) {
        int ans = 0;
        while (n % 2 == 0) {
            ans++;
            n /= 2;
        }
        return ans;
    }

    public long getNum(long a, long b, long x, long bit) {
        if (bit == 0) {
            return x;
        }
        if ((a & bit) == (b & bit)) {
            if ((a & bit) == 0) {
                x = x | bit;
            } else {
                x = x & (~bit);
            }
            return getNum(a, b, x, bit >> 1);
        } else {
            long val1 = getNum(a, b, x | bit, bit >> 1);
            long val2 = getNum(a, b, x & (~bit), bit >> 1);
            if (((a * val1) * (b * val1)) >= ((a * val2) * (b * val2))) {
                return val1;
            } else {
                return val2;
            }
        }
    }



    boolean isPerfect(long val,long n){
        long ans=(val*(val+1))/2;
        return ans>=n;
    }
    public static boolean prCheck(int n, int mxDiv) {
        for(int i = 2; i<=mxDiv; i++) if(n%i!=0) return true;
        return false;
    }
    void swap(int[] arr,int i,int j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    public void go() throws IOException {
        int n=ni();
        int k=ni();
        ArrayList<Integer> al=new ArrayList<>();
        al.add(0);
        int pos=0,neg=0;
        for(int i=0;i<n;i++){
            int temp=ni();
            if(temp<0){
                neg++;
            }else if(temp>0){
                pos++;
            }
            if(temp!=0){
                al.add(temp);
            }
        }
        Collections.sort(al);
        int zero=0;
        while (al.get(zero)!=0)zero++;

        long sum=0;
        int rem=pos%k;
        int i=zero+rem;
        for(;i<al.size();i+=k){
            sum+=al.get(i)*2;
        }

        rem=neg%k;
        i=zero-rem;
        for(;i>=0;i-=k){
            sum+=Math.abs(al.get(i))*2;
        }

        sum-=Math.max(Math.abs(al.get(0)),Math.abs(al.get(al.size()-1)));
        wr.println(sum);


    }
}