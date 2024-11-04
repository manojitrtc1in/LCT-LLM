import java.io.*;
import java.math.BigInteger;
import java.util.*;



public class Solution {

    public static void main(String[] args) {





























        MyInput in = new MyInput(System.in);
        PrintWriter out = new PrintWriter(System.out);

        TreeMap <YO, Double> mp = new TreeMap<YO, Double>();
        int n = in.nextInt();
        int k = in.nextInt();
        YO yo = new YO(n);
        for (int i = 0; i < n; i++) {
            yo.array[i] = in.nextInt();
        }
        yo.array[n] = k;

        double ans = probab(yo, n, mp);
        out.printf("%.10f\n", ans);

        out.flush();
        out.close();
    }



    static double probab(YO yo, int n, TreeMap<YO, Double> mp) {
        if (mp.containsKey(yo)) {








            return mp.get(yo);
        }
        int sz = yo.array.length;
        int k = yo.array[sz - 1];
        if (k == 0) {
            int inversion = id5(yo.array);










            mp.put(yo, (double)inversion);
            return inversion;
        }

        double ret = 0;
        double id3 = n * (n + 1) / 2;
        for (int i = 0; i < sz - 1; i++) {
            for (int j = i; j < sz - 1; j++) {
                swap(yo.array, i, j);
                yo.array[sz - 1] = k - 1;

                YO yoyo = new YO(n);
                for (int l = 0; l < n + 1; l++) {
                    yoyo.array[l] = yo.array[l];
                }

                ret += probab(yoyo, n, mp) / id3;

                yo.array[sz - 1] = k;
                swap(yo.array, i, j);
            }
        }

        mp.put(yo, ret);
        return ret;
    }

    static void swap(int[] array, int le, int ri) {
        while (le < ri) {
            int temp = array[le];
            array[le] = array[ri];
            array[ri] = temp;
            le++;
            ri--;
        }
    }

    static int id5(int[] array) {
        int cnt = 0;
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = i + 1; j < array.length - 1; j++) {
                cnt += array[i] > array[j] ? 1 : 0;
            }
        }
        return cnt;
    }

}


class YO implements Comparable <YO> {
    int[] array;

    public YO(int n) {
        array = new int[n + 1];
    }

    @Override
    public int compareTo(YO o) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == o.array[i]) {
                continue;
            }
            return array[i] - o.array[i];
        }
        return 0;
    }
}


class MyInput {
    private BufferedReader br;
    private StringTokenizer st;

    MyInput (InputStream inputStream) {
        br = new BufferedReader(new InputStreamReader(inputStream));
        st = null;
    }

    public String next() {
        if (st == null || !st.hasMoreElements()) {
            try {
                String line = br.readLine();
                if (line == null) {
                    throw new UnknownError();
                }
                while (line.trim().equals("")) {
                    line = br.readLine();
                    if (line == null) {
                        throw new UnknownError();
                    }
                }
                st = new StringTokenizer(line);
            } catch (IOException e) {
                throw new UnknownError();
            }
        }
        return st.nextToken();
    }

    public String nextLine() {
        try {
            String line = br.readLine();
            if (line == null) {
                throw new UnknownError();
            }
            return line;
        }
        catch (IOException e) {
            throw new UnknownError();
        }
    }

    public void id6() {
        try {
            br.readLine();
        }
        catch (IOException e) {
            throw new UnknownError();
        }
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

}


class MyMath {

    
    public static int[] sieve(int n){
        int[] pr = new int[n + 1];
        Arrays.fill(pr, 1);
        ArrayList <Integer> prime = new ArrayList<Integer>();
        pr[0] = pr[1] = 0;
        for(int i = 2; i <= n; i++) {
            if(pr[i] == 1) {
                prime.add(i);
                if((long)i * i <= n)
                    for(long j = (long)i * i; j <= n; j += i)
                        pr[(int)j] = 0;
            }
        }
        int [] ret = new int[prime.size()];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = prime.get(i);
        }
        return ret;
    }

    
    public static int GCD(int a, int b){return b!=0 ? GCD(b, a % b) : a;}

    
    public static int fastPow(int a, int b, int m){
        int ans = 1;
        while(b != 0){
            if((b & 1) == 1)
                ans = mul(ans, a, m);
            a = mul(a, a, m);
            b >>= 1;
        }
        return ans%m;
    }

    public static void id4(int[][] pas, int MOD) {
        int n = pas.length;
        for (int i = 0; i < n; i++) {
            pas[i][0] = 0;
        }
        for (int i = 0; i < n; i++) {
            pas[0][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                pas[i][j] = (pas[i][j-1] + pas[i-1][j-1]) % MOD;
            }
        }
    }

    

    

    public static long id11 (long a, long b, long[] x, long[] y) {
        if (a == 0) {
            x[0] = 0; y[0] = 1;
            return b;
        }
        long[] x1 = new long[1];
        long[] y1 = new long[1];

        long d = id11(b % a, a, x1, y1);
        x[0] = y1[0] - (b / a) * x1[0];
        y[0] = x1[0];
        return d;
    }

    

    

    public static long invMod(long a, long m){
        long[] x = new long[1];
        long[] q = new long[1];
        if(id11(a, m, x, q) == 1){
            x[0] = x[0] % m;
            if (x[0] < m) {
                x[0] = (x[0] + m) % m;
            }
            return x[0];
        }
        return -1;
    }

    
    public static ArrayList<int[]> getFactors(int n, int[] primes) {
        ArrayList <int[]> factors = new ArrayList<int[]>();
        for (int prime: primes) {
            if (n % prime == 0) {
                int cnt = 0;
                while (n % prime == 0) {
                    n /= prime;
                    cnt++;
                }
                factors.add(new int[] {prime, cnt});
            }
        }
        if (n != 1) {
            factors.add(new int[] {n, 1});
        }
        return factors;
    }

    public static int add(int a, int b, int MOD) {
        return ((a + b) % MOD + MOD) % MOD;
    }

    public static int mul(int a, int b, int MOD) {
        return ((int)(((long) a * b) % MOD) + MOD) % MOD;
    }

}



class InputReader {
    

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new UnknownError();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new UnknownError();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }


    public boolean hasNext(){
        return peek()!=-1;
    }

    public int peek() {
        if (numChars == -1)
            return -1;
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                return -1;
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar];
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
                throw new UnknownError();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!id2(c));
        return res * sgn;
    }

    public long nextLong() {
        int c = read();
        while (id2(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new UnknownError();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!id2(c));
        return res * sgn;
    }

    public String readString() {
        int c = read();
        while (id2(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!id2(c));
        return res.toString();
    }

    public static boolean id2(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private String id0() {
        StringBuffer buf = new StringBuffer();
        int c = read();
        while (c != '\n' && c != -1) {
            if (c != '\r')
                buf.appendCodePoint(c);
            c = read();
        }
        return buf.toString();
    }

    public String readLine() {
        String s = id0();
        while (s.trim().length() == 0)
            s = id0();
        return s;
    }

    public String readLine(boolean id12) {
        if (id12)
            return readLine();
        else
            return id0();
    }

    public BigInteger id9() {
        try {
            return new BigInteger(readString());
        } catch (NumberFormatException e) {
            throw new UnknownError();
        }
    }

    public char readCharacter() {
        int c = read();
        while (id2(c))
            c = read();
        return (char) c;
    }

    public double readDouble() {
        int c = read();
        while (id2(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!id2(c) && c != '.') {
            if (c == 'e' || c == 'E')
                return res * Math.pow(10, nextInt());
            if (c < '0' || c > '9')
                throw new UnknownError();
            res *= 10;
            res += c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!id2(c)) {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new UnknownError();
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
        return res * sgn;
    }

    public boolean id1() {
        int value;
        while (id2(value = peek()) && value != -1)
            read();
        return value == -1;
    }

    public String next() {
        return readString();
    }
}

class Pair <P extends Comparable <? super P>, Q extends Comparable <? super Q> >
        implements Comparable <Pair <P, Q> > {
    P a;
    Q b;
    public Pair (P a, Q b) {
        this.a = a;
        this.b = b;
    }

    public Pair() {
    }

    public void setX(P a) {
        this.a = a;
    }

    public void setY(Q b) {
        this.b = b;
    }

    public P getX() {
        return a;
    }

    public Q getY() {
        return b;
    }

    public String toString() {
        return "(" + a.toString() + ", " + b.toString() + ")";
    }

    @Override
    public int compareTo(Pair<P, Q> o) {
        int cmp = a.compareTo(o.a);
        if (cmp == 0) {
            return b.compareTo(o.b);
        }
        return cmp;
    }
}

class id13 {
    private int[] tree;
    private int maxVal;

    public id13(int n) {
        maxVal = n;
        tree = new int[maxVal + 1];
    }

    
    public void update(int idx, int val) {
        idx++;
        while (idx <= maxVal) {
            tree[idx] += val;
            idx += (idx & (-idx));
        }
    }

    
    public int read(int idx) {
        idx++;
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    public int id8() {
        return maxVal;
    }

    public int rangeSum(int left, int right) {
        if(left > right)
            return 0;
        int sumLeft = read(left - 1);
        int sumRight = read(right);
        return sumRight - sumLeft;
    }


}

class PairInt implements Comparable <PairInt>{
    public int X, Y;

    public PairInt(int X, int Y){
        this.X = X;
        this.Y = Y;
    }

    public PairInt add(PairInt b) {
        return new PairInt(X + b.X, Y + b.Y);
    }

    public PairInt sub(PairInt b) {
        return new PairInt(X - b.X, Y - b.Y);
    }

    @Override
    public int compareTo(PairInt o) {
        if(X != o.X)
            return X - o.X;
        return Y - o.Y;
    }
}


class IntArrays {

    public static void reverse(int[] cur){
        int[] temp = new int[cur.length];
        int cnt = 0;
        for(int i=cur.length-1; i>=0; i--){
            temp[cnt++] = cur[i];
        }
        for(int i=0;i<cnt; i++)
            cur[i] = temp[i];
    }

    public static void swap(int[] arr, int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
























    private static Integer[] selfOrder(int n) {
        Integer[] self = new Integer[n];
        for (int i = 0; i < n; i++) {
            self[i] = i;
        }
        return self;
    }

    private static int[] id7(Integer[] box) {
        int[] primitive = new int[box.length];
        for (int i = 0; i < box.length; i++) {
            primitive[i] = box[i];
        }
        return primitive;
    }

    public static int[] getOrder(final int[] arr) {
        Integer[] order = selfOrder(arr.length);
        Arrays.sort(order, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if(arr[o1] > arr[o2])
                    return 1;
                if(arr[o1] < arr[o2])
                    return -1;
                return 0;
            }
        });
        return id7(order);
    }

    public static boolean id10(int[] c){
        

        int first = getFirst( c );
        if ( first == -1 ) return false; 

        

        int toSwap = c.length - 1;
        while ( c[ first ] >= c[ toSwap ] )
            --toSwap;
        

        swap( c, first++, toSwap );
        

        toSwap = c.length - 1;
        while ( first < toSwap )
            swap( c, first++, toSwap-- );
        return true;
    }

    

    

    private static int getFirst( final int[] c ) {
        for ( int i = c.length - 2; i >= 0; --i )
            if ( c[ i ] <  c[ i + 1 ] )
                return i;
        return -1;
    }

    
    public static int lowerBound(int[] order, int[] val, int need) {
        int s = 0;
        int e = order.length;
        while(e - s > 1) {
            int mid = (e + s) / 2;
            if(val[order[mid]] < need)
                s = mid;
            else
                e = mid;
        }
        if(val[order[s]] >= need)
            return s;
        return e;
    }

    public static int lowerBound(int[] val, int need) {
        int s = 0;
        int e = val.length;
        while(e - s > 1) {
            int mid = (e + s) / 2;
            if(val[mid] < need)
                s = mid;
            else
                e = mid;
        }
        if(val[s] >= need)
            return s;
        return e;
    }


}
