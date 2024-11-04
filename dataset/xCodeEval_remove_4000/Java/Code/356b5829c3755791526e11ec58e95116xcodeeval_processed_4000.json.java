import java.io.*;
import java.math.BigInteger;
import java.util.*;



public class Solution {

    public static void main(String[] args) {





























        MyInput in = new MyInput(System.in);
        PrintWriter out = new PrintWriter(System.out);

        Solver solver = new Solver();











        solver.solve(in, out, 1);














        out.flush();
        out.close();
    }
}

class Solver {
    public void solve (MyInput in, PrintWriter out, int testCase) {
        int n = in.nextInt();
        char a[] = in.next().toCharArray();
        char b[] = in.next().toCharArray();

        int left = 0;
        while (a[left] == b[left]) {
            left++;
        }
        int right = n - 1;
        while (a[right] == b[right]) {
            right--;
        }



        int ans = 0;
        if (left == right) {
            ans = 2;
        }
        else {
            StringBuilder sb = new StringBuilder();
            sb.append(b[left]);
            int leftCopy = left;
            while (left + 1 <= right && a[left] == b[left + 1]) {
                sb.append(a[left]);
                left++;
            }
            sb.append(a[right]);
            if (left == right) {


                ans++;
            }
            left = leftCopy;

            StringBuilder sb2 = new StringBuilder();
            sb2.append(a[left]);
            while (left + 1 <= right && b[left] == a[left + 1]) {
                sb2.append(b[left]);
                left++;
            }
            sb2.append(b[right]);
            if (left == right) {
                if (!sb.equals(sb2)) {


                    ans++;
                }
            }
        }
        out.println(ans);
    }


}


class LabelGenerator {
    Random random;

    LabelGenerator () {
        random = new Random(System.currentTimeMillis());
    }

    public String id12(int len) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len; i++) {
            sb.append((char)('a' + random.nextInt(26)));
        }
        return sb.toString();
    }
}

class GraphGenerator {

    public void printGraph(ArrayList<Integer>[] g, String[] name, int u, boolean[] color, PrintWriter out) {
        color[u] = true;
        for (int v : g[u]) {
            if (!color[v]) {
                out.println(name[u] + " " + name[v]);
                printGraph(g, name, v, color, out);
            }
        }
    }

    
    private void id6(int u, int nodeCnt, int id8, ArrayList <Integer>[] tree) {
        if (nodeCnt == 0) {
            return ;
        }
        int childCnt = new Random(System.currentTimeMillis()).nextInt(nodeCnt) + 1;
        int[] randomSequence = id4(childCnt, nodeCnt);
        for (int i = 0; i < childCnt; i++) {
            int curNode = id8;
            tree[u].add(curNode);
            tree[curNode].add(u);

            id6(curNode, randomSequence[i] - 1, id8 + 1, tree);
            id8 += randomSequence[i];
        }
    }

    public ArrayList<Integer>[] id0(int n) {
        ArrayList <Integer>[] tree = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        id6(0, n - 1, 1, tree);
        return tree;
    }

    
    int[] id4(int n, int sum) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = 1;
            sum--;
        }

        Random random = new Random(System.currentTimeMillis());
        for (int i = 0; i < sum; i++) {
            arr[random.nextInt(n)]++;
        }
        return arr;
    }


}


class LCA {
    ArrayList <Integer> adj[];
    int n;
    int level[];
    int jads[][];

    LCA (int n) {
        this.n = n;
        level = new int[n];
        jads = new int[n][22];
    }

    public void preProcess(int root) {
        setLevel(root, root, 0);

        for (int L = 1; (1 << L) <= n; L++) {
            for (int i = 0; i < n; i++) {
                jads[i][L] = jads[jads[i][L - 1]][L - 1];
            }
        }
    }

    public int id7(int u, int v) {
        if (level[u] < level[v]) {
            int temp = u;
            u = v;
            v = temp;
        }

        int len = u - v;
        for (int i = 0; i < 22; i++) {
            if ((len >> i & 1) != 0) {
                u = jads[u][i];
            }
        }
        if (u == v) {
            return u;
        }

        for (int i = 21; i >= 0; i--) {
            if (jads[u][i] != jads[v][i]) {
                u = jads[u][i];
                v = jads[v][i];
            }
        }
        return jads[u][0];
    }

    public void setLevel(int u, int par, int curLevel) {
        level[u] = curLevel;
        jads[u][0] = par;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u].get(i);
            if (v == par) {
                continue;
            }
            setLevel(v, u, curLevel + 1);
        }
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

    public void id9() {
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

    public static void id5(int[][] pas, int MOD) {
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

    

    

    public static long id15 (long a, long b, long[] x, long[] y) {
        if (a == 0) {
            x[0] = 0; y[0] = 1;
            return b;
        }
        long[] x1 = new long[1];
        long[] y1 = new long[1];

        long d = id15(b % a, a, x1, y1);
        x[0] = y1[0] - (b / a) * x1[0];
        y[0] = x1[0];
        return d;
    }

    

    

    public static long invMod(long a, long m){
        long[] x = new long[1];
        long[] q = new long[1];
        if(id15(a, m, x, q) == 1){
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
        while (id3(c))
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
        } while (!id3(c));
        return res * sgn;
    }

    public long nextLong() {
        int c = read();
        while (id3(c))
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
        } while (!id3(c));
        return res * sgn;
    }

    public String readString() {
        int c = read();
        while (id3(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!id3(c));
        return res.toString();
    }

    public static boolean id3(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private String id1() {
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
        String s = id1();
        while (s.trim().length() == 0)
            s = id1();
        return s;
    }

    public String readLine(boolean id16) {
        if (id16)
            return readLine();
        else
            return id1();
    }

    public BigInteger id13() {
        try {
            return new BigInteger(readString());
        } catch (NumberFormatException e) {
            throw new UnknownError();
        }
    }

    public char readCharacter() {
        int c = read();
        while (id3(c))
            c = read();
        return (char) c;
    }

    public double readDouble() {
        int c = read();
        while (id3(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!id3(c) && c != '.') {
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
            while (!id3(c)) {
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

    public boolean id2() {
        int value;
        while (id3(value = peek()) && value != -1)
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

class id17 {
    private int[] tree;
    private int maxVal;

    public id17(int n) {
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

    public int id11() {
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

    private static int[] id10(Integer[] box) {
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
        return id10(order);
    }

    public static boolean id14(int[] c){
        

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
