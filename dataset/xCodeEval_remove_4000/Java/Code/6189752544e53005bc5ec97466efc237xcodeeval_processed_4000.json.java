import java.io.*;
import java.math.BigInteger;
import java.util.*;





public class Solution {

    public static void main(String[] args) {
        IOHandler IO = new IOHandler();
        IO.init("std", "std", "input.txt", "output.txt");
        boolean id2 = false;

        Solver solver = new Solver();
        if (id2) {
            int testCase = IO.getInput().nextInt();
            for (int test = 0; test < testCase; test++) {
                solver.solve(IO.in, IO.out, test + 1);
                IO.flush();
            }
        }
        else {
            int test = 1;
            try {
                while (true) {
                    solver.solve(IO.in, IO.out, test++);
                    IO.flush();
                }
            } catch (UnknownError unknownError) {
                IO.close();
            }
        }

        IO.close();
    }
}

class Solver {
    public void solve (MyInput in, PrintWriter out, int testCase) {
        ArrayList <PairInt> loves = new ArrayList<PairInt>();
        ArrayList <PairInt> hates = new ArrayList<PairInt>();
        int n = in.nextInt();
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            int c = in.nextInt();
            if (c == 1) {
                loves.add(new PairInt(u, v));
            } else {
                hates.add(new PairInt(u, v));
            }
        }

        DJS id11 = new DJS(n);
        for (PairInt lovers : loves) {
            id11.union(lovers.X, lovers.Y);
        }

        TreeMap <Integer, Integer> map = new TreeMap<Integer, Integer>();
        TreeSet < Integer > heads = new TreeSet<Integer>();
        for (int i = 0; i < n; i++) {
            heads.add(id11.find(i));
        }
        int cnt = 0;
        for (int head : heads) {
            map.put(head, cnt++);
        }

        TreeSet < Integer > adj[] = new TreeSet[cnt];
        for (int i = 0; i < cnt; i++) {
            adj[i] = new TreeSet<Integer>();
        }
        boolean zero = false;
        for (PairInt haters : hates) {
            if (id11.find(haters.X) == id11.find(haters.Y)) {
                zero = true;
                break;
            } else {
                int u = map.get(id11.find(haters.X));
                int v = map.get(id11.find(haters.Y));
                adj[u].add(v);
                adj[v].add(u);
            }
        }

        if (!zero) {
            int component = 0;
            int[] color = new int[cnt];
            for (int i = 0; i < cnt; i++) {
                if (color[i] == 0) {
                    boolean loopFound = DFS(i, -1, adj, color, 1);
                    if (loopFound) {
                        zero = true;
                        break;
                    }
                    component++;
                }
            }
            if (!zero) {
                out.println(MyMath.fastPow(2, component - 1, 1000 * 1000 * 1000 + 7));
            }
        }
        if (zero) {
            out.println(0);
        }
    }

    private boolean DFS(int u, int par, TreeSet<Integer>[] adj, int[] color, int level) {
        boolean ret = false;
        color[u] = level;
        for (int v : adj[u]) if (v != par && v != u) {
            if (color[v] == 0) {
                ret |= DFS(v, u, adj, color, level + 1);
            } else if ((color[u] - color[v]) % 2 == 0) {
                return true;
            }
        }
        return ret;
    }
}

class DJS{
    int[] jad;
    int[] child;
    int n;

    public void initialize(int n) {
        this.n = n;
        jad = new int[n];
        child = new int[n];
        for (int i = 0; i < n; i++) {
            jad[i] = i;
            child[i] = 1;
        }
    }

    public DJS(int n) {
        initialize(n);
    }

    public int find(int i){
        if(jad[i] != i){
            jad[i] = find(jad[i]);
        }
        return jad[i];
    }

    public int union(int u, int v){
        int jadU = find(u);
        int jadV = find(v);
        if(jadU == jadV)
            return child[jadU];
        if (jadU > jadV) {
            int temp = jadU;
            jadU = jadV;
            jadV = temp;
        }

        jad[jadV] = jadU;
        child[jadU] += child[jadV];
        return child[jadU];
    }

}

class MultiSet <K> extends TreeMap<K, Integer>{
    private int size;

    public MultiSet(){
        super();
        size = 0;
    }

    public void put(K key) {
        Integer temp = super.get(key);
        if (temp == null) {
            temp = 1;
        }
        else {
            temp ++;
        }
        size++;
        super.put(key, temp);
    }

    public int getNumber(K key) {
        Integer temp = super.get(key);
        if (temp == null) {
            return 0;
        }
        return temp;
    }

    public int size() {
        return size;
    }

    public boolean removeOne(K key) {
        Integer temp = super.get(key);
        if (temp == null) {
            return false;
        }
        size--;
        if (temp == 1) {
            super.remove(key);
            return true;
        }
        super.put(key, temp - 1);
        return true;
    }
}


class id12 {
    int n;
    PairInt[] father;

    public id12(int nn){
        n = nn;
        father = new PairInt[n];
        for(int i=0; i<n; i++)
            father[i] = new PairInt(i, 0);
    }

    public int find(int i){
        if(father[i].X !=i)
            father[i].X = find(father[i].X);
        return father[i].X;
    }


    public void union(int i, int j){
        int xroot = find(i);
        int yroot = find(j);
        if(xroot == yroot)
            return;
        if(father[xroot].Y < father[yroot].Y)
            father[xroot].X = yroot;
        else if(father[xroot].Y > father[yroot].Y)
            father[yroot].X = xroot;
        else{
            father[yroot].X = xroot;
            father[xroot].Y = father[xroot].Y + 1;
        }
    }
}


class SuffixArray {
    char str[];
    int N, m, SA[], LCP[];
    int[] x, y, w, c;

    boolean cmp(int a, int b, int l) {
        return (y[a] == y[b] && y[a + l] == y[b + l]);
    }

    void Sort() {
        for (int i = 0; i < m; ++i) w[i] = 0;
        for (int i = 0; i < N; ++i) ++w[x[y[i]]];
        for (int i = 0; i < m - 1; ++i) w[i + 1] += w[i];
        for (int i = N - 1; i >= 0; --i) SA[--w[x[y[i]]]] = y[i];
    }

    void DA() {
        ++N;
        for (int i = 0; i < N; ++i) {
            x[i] = str[i];
            y[i] = i;
        }
        Sort();
        for (int i, j = 1, p = 1; p < N; j <<= 1, m = p) {
            for (p = 0, i = N - j; i < N; i++) y[p++] = i;
            for (int k = 0; k < N; ++k) if (SA[k] >= j) y[p++] = SA[k] - j;
            Sort();
            {
                int[] temp = Arrays.copyOf(x, x.length);
                x = Arrays.copyOf(y, y.length);
                y = Arrays.copyOf(temp, temp.length);
            }
            for (p = 1, x[SA[0]] = 0, i = 1; i < N; ++i)
                x[SA[i]] = cmp(SA[i - 1], SA[i], j) ? p - 1 : p++;
        }
        for (int i = 1; i < N; ++i)
            SA[i - 1] = SA[i];
        --N;
    }

    void id19() {
        for (int i = 0; i < N; ++i)
            c[SA[i]] = i;
        LCP[0] = 0;
        for (int i = 0, h = 0; i < N; ++i) {
            if (c[i] > 0) {
                int j = SA[c[i] - 1];
                while (i + h < N && j + h < N && str[i + h] == str[j + h]) ++h;
                LCP[c[i]] = h;
                if (h > 0) --h;
            }
        }
    }


    public SuffixArray(String string) {
        this.str = string.toCharArray();
        N = str.length;
        SA = new int[N];
        LCP = new int[N];
        x = new int[N];
        y = new int[N];
        w = new int[N];
        c = new int[N];
        m = 256;
        id16();
    }

    public void id16() {
        DA();
        id19();
    }

}


class OSValidator {
    private String OS_Name;

    public OSValidator() {
        OS_Name = System.getProperty("os.name").toLowerCase();
    }

    public boolean isMac() {
        return OS_Name.contains("mac");
    }

    public boolean isWindows() {
        return OS_Name.indexOf("win") >= 0;
    }

    public boolean isLinux() {
        return OS_Name.indexOf("nix") >= 0 || OS_Name.indexOf("nux") >= 0 || OS_Name.indexOf("aix") > 0;
    }

    public String append(String ... names) {
        String ret = "";
        for (String str : names) {
            ret += str;
            if (isMac() || isLinux()) {
                ret += "/";
            }
            else {
                ret += "\\";
            }
        }
        return ret;
    }

    public String correctPath(String path) {
        if (isWindows()) {
            return path;
        }
        return "\"" + path + "\"";
    }
}



class id0 {
    int test;
    public id0(int test) {
        this.test = test;
    }
    private OSValidator OS = new OSValidator();

    public long runTest(){
        long time = 0;



        StopWatch stopWatch = new StopWatch();
        final Process[] process = {null};
        Runnable runnable = new Runnable() {
            @Override
            public void run() {
                String cmd[] = new String[0];
                if (OS.isWindows()) {
                    cmd = new String[] {"j1.com"};
                }
                else {
                    

                }
                try {
                    process[0] = Runtime.getRuntime().exec(cmd);





                    PrintWriter out = new PrintWriter(process[0].getOutputStream());
                    out.println(test);
                    out.flush();
                    out.close();

                    try {
                        process[0].waitFor();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        };

        Thread thread = new Thread(runnable);
        thread.start();
        stopWatch.start();
        while(true) {
            time = stopWatch.id9();
            if(!thread.isAlive()) {
                break;
            }
        }
        MyInput in = new MyInput(process[0].getInputStream());
        if (!in.nextLine().equals("You are not our student!You are not our student!")) {
            try {
                PrintWriter out = new PrintWriter(new FileOutputStream("ramz.txt"));
                out.println("yo bro, ans = " + test);
                out.flush();
                out.close();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
        if(thread.isAlive()) {
            kill(process);
        }
        return (time);
    }

    public void kill(final Process[] process) {








        process[0].destroy();
    }

}

class StopWatch {
    long beginTime;

    public StopWatch() {
        beginTime = System.currentTimeMillis();
    }

    public void start() {
        beginTime = System.currentTimeMillis();
    }

    public long id9() {
        return System.currentTimeMillis() - beginTime;
    }

    public double id10() {
        return (double)id9() / 1000.;
    }

}

class IOHandler {
    MyInput in;
    PrintWriter out;

    
    public void init(String input_type, String output_type, String id7, String id21) {
        if (input_type.toLowerCase().equals("std")) {
            in = new MyInput(System.in);
        }
        else {
            

            try {
                in = new MyInput(new FileInputStream(id7));
            }
            catch (IOException e) {
                throw new UnknownError();
            }
        }
        if (output_type.toLowerCase().equals("std")) {
            out = new PrintWriter(System.out);
        }
        else {
            

            try {
                out = new PrintWriter(new FileOutputStream(id21));
            }
            catch (IOException e) {
                throw new UnknownError();
            }
        }
    }

    public MyInput getInput() {
        return in;
    }

    public PrintWriter getOutput() {
        return out;
    }

    public void flush() {
        out.flush();
    }

    public void close() {
        out.flush();
        out.close();
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

    public void id8() {
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

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public BigInteger id5() {
        return new BigInteger(next());
    }

    public boolean hasNext() {
        try {
            return st != null && st.hasMoreElements() || br.ready();
        } catch (IOException e) {
            throw new UnknownError();
        }
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

    public static void id6(int[][] pas, int MOD) {
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

    

    

    public static long id17 (long a, long b, long[] x, long[] y) {
        if (a == 0) {
            x[0] = 0; y[0] = 1;
            return b;
        }
        long[] x1 = new long[1];
        long[] y1 = new long[1];

        long d = id17(b % a, a, x1, y1);
        x[0] = y1[0] - (b / a) * x1[0];
        y[0] = x1[0];
        return d;
    }

    

    

    public static long invMod(long a, long m){
        long[] x = new long[1];
        long[] q = new long[1];
        if(id17(a, m, x, q) == 1){
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

class id20 {
    private int[] tree;
    private int maxVal;

    public id20(int n) {
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

    public int id14() {
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

class PairInt implements Comparable <PairInt> {
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
























    public static Integer[] selfOrder(int n) {
        Integer[] self = new Integer[n];
        for (int i = 0; i < n; i++) {
            self[i] = i;
        }
        return self;
    }

    public static int[] id13(Integer[] box) {
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
                return arr[o1] - arr[o2];
            }
        });
        return id13(order);
    }

    public static boolean id15(int[] c){
        

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
        while (id4(c))
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
        } while (!id4(c));
        return res * sgn;
    }

    public long nextLong() {
        int c = read();
        while (id4(c))
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
        } while (!id4(c));
        return res * sgn;
    }

    public String nextString() {
        int c = read();
        while (id4(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!id4(c));
        return res.toString();
    }

    public static boolean id4(int c) {
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

    public String nextLine() {
        String s = id1();
        while (s.trim().length() == 0)
            s = id1();
        return s;
    }

    public String readLine(boolean id18) {
        if (id18)
            return nextLine();
        else
            return id1();
    }

    public BigInteger id5() {
        try {
            return new BigInteger(nextString());
        } catch (NumberFormatException e) {
            throw new UnknownError();
        }
    }

    public char nextCharacter() {
        int c = read();
        while (id4(c))
            c = read();
        return (char) c;
    }

    public double nextDouble() {
        int c = read();
        while (id4(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!id4(c) && c != '.') {
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
            while (!id4(c)) {
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

    public boolean id3() {
        int value;
        while (id4(value = peek()) && value != -1)
            read();
        return value == -1;
    }

    public String next() {
        return nextString();
    }
}
