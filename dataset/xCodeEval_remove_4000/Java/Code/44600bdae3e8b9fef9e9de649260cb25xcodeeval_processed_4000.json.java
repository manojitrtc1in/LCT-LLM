import java.util.*;
import java.io.*;
import java.util.function.*;









public class Main {

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int t = sc.nextInt();
        for (int sample = 0; sample < t; sample++) {
            int n = sc.nextInt();
            int[] odd = new int[n / 2];
            int[] even = new int[n / 2];
            if (n % 4 != 0) {
                System.out.println("NO");
                continue;
            }
            System.out.println("YES");
            for (int i = 0; i < n / 2; i++) {
                odd[i] = 2 * (i + 1) + 1;
                even[i] = 2 * (i + 1);
            }
            even[n / 2 - 1] += n / 2;
            for (int i = 0; i < n / 2; i++) {
                System.out.print(even[i] + " ");
            }
            for (int i = 0; i < n / 2; i++) {
                System.out.print(odd[i] + " ");
            }
            System.out.println();

            out.flush();
        }
    }

}

class id6 {
    int[] root;
    int[] rank;
    int[] size;
    int m;

    public id6(int n) {
        this.root = new int[n];
        this.rank = new int[n];
        this.size = new int[n];
        this.m = n;
        for (int i = 0; i < n; i++) {
            root[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (root[x] == x)
            return x;
        else {
            return root[x] = find(root[x]);
        }
    }

    public void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (rank[x] < rank[y]) {
            size[find(y)] = size[find(x)];
            root[x] = y;
        } else {
            size[find(x)] = size[find(y)];
            root[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
        m--;
    }

    public boolean same(int x, int y) {
        return find(x) == find(y);
    }

    public int size(int i) {
        return this.size[find(i)];
    }
}

class Dijkstra {
    private static int prev[];
    private static long dist[];

    public Dijkstra(AbstractGraph graph, int s) {
        prev = new int[graph.n];
        dist = new long[graph.n];
        Arrays.fill(prev, -1);
        Arrays.fill(dist, Long.MAX_VALUE);
        PriorityQueue<Integer> searching = new PriorityQueue<>((x, y) -> Long.compare(dist[x], dist[y]));
        dist[s] = 0;
        searching.add(s);
        while (searching.size() > 0) {
            int now = searching.poll();
            for (Edge e : graph.getEdges(now)) {
                int next = e.to;
                long c = e.cost;
                if (dist[now] + c < dist[next]) {
                    dist[next] = dist[now] + c;
                    prev[next] = now;
                    searching.add(next);
                }
            }
        }
    }

    public int[] path(int to) {
        ArrayList<Integer> rev = new ArrayList<>();
        for (int now = to; now != -1; now = this.prev[now]) {
            rev.add(now);
        }
        int[] path = new int[rev.size()];
        for (int i = 0; i < path.length; i++) {
            path[i] = rev.get(path.length - i - 1);
        }
        return path;
    }
}

class WF {
    private static long[][] dist;

    public WF(AbstractGraph graph) {
        dist = new long[graph.n][graph.n];
        for (int i = 0; i < dist.length; i++) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        }
        for (int i = 0; i < graph.n; i++) {
            for (Edge e : graph.getEdges(i)) {
                dist[i][e.to] = e.cost;
            }
            dist[i][i] = 0;
        }
        for (int k = 0; k < graph.n; k++) {
            for (int i = 0; i < graph.n; i++) {
                for (int j = 0; j < graph.n; j++) {
                    if (dist[i][k] != Integer.MAX_VALUE && dist[k][j] != Integer.MAX_VALUE) {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }

    public static long getShortest(int s, int t) {
        return dist[s][t];
    }

    public static long[][] id0() {
        return dist;
    }

    public static boolean id3() {
        for (int i = 0; i < dist.length; i++) {
            if (dist[i][i] < 0) {
                return true;
            }
        }
        return false;
    }
}

class Edge {
    int from, to;
    long cost;

    public Edge(int from, int to, long cost) {
        this.from = from;
        this.to = to;
        this.cost = cost;
    }

    public Edge(int from, int to) {
        this.from = from;
        this.to = to;
        this.cost = 1;
    }

    public Edge reverse() {
        return new Edge(to, from, cost);
    }
}

@SuppressWarnings("unchecked")
abstract class AbstractGraph {
    int n;
    int m;
    ArrayList<Edge>[] edges;

    public AbstractGraph(int n) {
        this.n = n;
        this.m = 0;
        this.edges = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            this.edges[i] = new ArrayList<Edge>();
        }
    }

    public void addEdge(Edge e) {
        this.m++;
        this.edges[e.from].add(e);
    }

    public int getV() {
        return this.n;
    }

    public int getE() {
        return this.m;
    }

    public ArrayList<Edge> getEdges(int v) {
        return this.edges[v];
    }

    abstract public boolean id4();

    public boolean isTree() {
        

        return false;
    }
}

class Graph extends AbstractGraph {
    int n;
    int m;
    

    ArrayList<Edge>[] edges;

    public Graph(int n) {
        super(n);
    }

    public void addEdge(int from, int to, int cost) {
        Edge e = new Edge(from, to, cost);
        super.addEdge(e);
        super.addEdge(e.reverse());
        this.m++;
    }

    @Override
    public void addEdge(Edge e) {
        this.edges[e.from].add(e);
        this.edges[e.to].add(e.reverse());
        this.m++;
    }

    public int getV(int v) {
        return n;
    }

    public int getE() {
        return m;
    }

    public boolean id4() {
        int[] color = new int[n];
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        HashSet<Integer> visited = new HashSet<>();
        queue.add(0);
        color[0] = 1;
        while (queue.size() > 0) {
            int now = queue.poll();
            visited.add(now);
            for (Edge e : getEdges(now)) {
                if (visited.contains(e.to)) {
                    continue;
                }
                if (color[e.to] == color[now])
                    return false;
                queue.add(e.to);
                if (color[e.to] == 0)
                    color[e.to] = -1 * color[now];
            }
        }
        return true;
    }
}

class DirectedGraph extends AbstractGraph {
    int n;
    int m;
    

    ArrayList<Edge>[] edges;

    public DirectedGraph(int n) {
        super(n);
    }

    public void addEdge(int from, int to, int cost) {
        Edge e = new Edge(from, to, cost);
        super.addEdge(e);
        this.m++;
    }

    @Override
    public void addEdge(Edge e) {
        this.edges[e.from].add(e);
        this.m++;
    }

    public int getV(int v) {
        return this.n;
    }

    public int getE() {
        return this.m;
    }

    public boolean id4() {
        

        return false;
    }

}

class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private boolean id11() {
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
        if (id11())
            return buffer[ptr++];
        else
            return -1;
    }

    private static boolean id12(int c) {
        return 33 <= c && c <= 126;
    }

    public boolean hasNext() {
        while (id11() && !id12(buffer[ptr]))
            ptr++;
        return id11();
    }

    public String next() {
        if (!hasNext())
            throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (id12(b)) {
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
            } else if (b == -1 || !id12(b)) {
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

class MyMath {
    public static long gcm(long a, long b) {

        

        


        

        


        

        if (a < b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        long r = -1;
        while (r != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    public static long summation(long a, long b) {
        return b * (b + 1) / 2 - a * (a - 1) / 2;
    }

    public static long factorial(long n) {

        if (n <= 1)
            return 1;
        else
            return factorial(n - 1) * n;
    }

    public static long[][] id8(int a, long m) {
        long[][] table = new long[a + 1][a + 1];
        for (int i = 0; i < a + 1; i++) {
            table[0][a] = 0;
            table[i][0] = 1;
            table[i][i] = 1;
        }
        for (int i = 1; i < a + 1; i++) {
            for (int j = 1; j < a + 1; j++) {
                if (i < j)
                    table[i][j] = 0;
                else {
                    table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % m;
                }
            }
        }
        return table;
    }

    public static long binomial(int n, int k, long m) {
        long res = 1;
        for (int l = n - k + 1; l <= n; l++) {
            res = (res % m) * (l % m) % m;
        }
        for (int r = 1; r <= k; r++) {
            res = (res % m) * modinv(r, m) % m;
        }
        return res;
    }

    public static long id10(long a, long n, long p) {
        if (n == 0)
            return 1;
        if (n == 1)
            return a % p;
        if (n % 2 == 1)
            return a * id10(a, n - 1, p) % p;
        long tmp = id10(a, n / 2, p) % p;
        return tmp * tmp % p;
    }

    public static long modinv(long a, long p) {
        long b, x, u, q, abs_p, tmp;
        abs_p = Math.abs(p);
        b = p;
        x = 1;
        u = 0;
        while (b > 0) {
            q = a / b;
            tmp = u;
            u = x - q * u;
            x = tmp;
            tmp = b;
            b = a - q * b;
            a = tmp;
        }
        return (x < 0) ? abs_p + x : x;
    }

    public static Long[] id1(int n) {
        Long[] factor_table = new Long[n];
        for (long i = 1; i <= n; i++) {
            factor_table[(int) (i - 1)] = i;
        }
        for (long i = 1; i <= n; i++) {
            if (factor_table[(int) (i - 1)] == i) {
                int j = 2;
                while (i * j <= n) {
                    factor_table[(int) (i * j - 1)] = i;
                    j++;
                }
            }
        }

        return factor_table;
    }

    public static HashMap<Long, Integer> id2(long n) {
        HashMap<Long, Integer> primes = new HashMap<>();
        for (long p = 2; p * p <= n; p++) {
            int q = 0;
            while (n % p == 0) {
                n /= p;
                q++;
            }
            if (q > 0)
                primes.put(p, q);
        }
        if (n > 1)
            primes.put(n, 1);
        return primes;
    }

    public static ArrayList<Integer> divisor(int n) {
        ArrayList<Integer> ret = new ArrayList<Integer>();
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ret.add(i);
                

                if (i != n / i)
                    ret.add(n / i);
            }
        }
        return ret;
    }
}

class nextPermutation {
    public static int[] swap(int data[], int left, int right) {

        

        int temp = data[left];
        data[left] = data[right];
        data[right] = temp;

        

        return data;
    }

    

    

    

    public static int[] reverse(int data[], int left, int right) {

        

        while (left < right) {
            int temp = data[left];
            data[left++] = data[right];
            data[right--] = temp;
        }

        

        return data;
    }

    

    

    public static boolean id7(int data[]) {

        

        

        

        if (data.length <= 1)
            return false;

        int last = data.length - 2;

        

        

        while (last >= 0) {
            if (data[last] < data[last + 1]) {
                break;
            }
            last--;
        }

        

        

        if (last < 0)
            return false;

        int nextGreater = data.length - 1;

        

        for (int i = data.length - 1; i > last; i--) {
            if (data[i] > data[last]) {
                nextGreater = i;
                break;
            }
        }

        

        data = swap(data, nextGreater, last);

        

        data = reverse(data, last + 1, data.length - 1);

        

        return true;
    }
}

class ArrayUtil {
    private static long INF = 1_000_000_000_0L;

    public static int UpperBound(long[] array, long obj) {
        int l = 0, r = array.length - 1;
        while (r - l >= 0) {
            int c = (l + r) / 2;
            if (obj < array[c]) {
                r = c - 1;
            } else {
                l = c + 1;
            }
        }
        return l;
    }

    public static int LowerBound(long[] array, long obj) {
        int l = 0, r = array.length - 1;
        while (r - l >= 0) {
            int c = (l + r) / 2;
            if (obj <= array[c]) {
                r = c - 1;
            } else {
                l = c + 1;
            }
        }
        return l;
    }

    

    public static int LIS(long[] array) {
        long[] dp = new long[array.length + 1];
        Arrays.fill(dp, INF);
        for (int i = 0; i < array.length; i++) {
            int idx = LowerBound(dp, array[i]);
            dp[idx] = array[i];
        }
        return LowerBound(dp, INF - 1);
    }

    public static int id5(long[] array) {
        long[] dp = new long[array.length + 1];
        Arrays.fill(dp, INF);
        for (int i = 0; i < array.length; i++) {
            int idx = UpperBound(dp, array[i]);
            dp[idx] = array[i];
        }
        return UpperBound(dp, INF - 1);
    }
}

class id9 {
    int[] data;
    long[] tree;
    int n;

    public id9(int[] data) {
        this.data = data;
        this.n = data.length;
        this.tree = new long[n + 1];
        buildTree();
    }

    public void buildTree() {
        for (int i = 0; i < n; i++) {
            add(i + 1, data[i]);
        }
    }

    public void add(int index, int value) {
        for (int i = index; i <= n; i += i & -i) {
            tree[i] += value;
        }
    }

    public long sum(int from, int to) {
        return sum(to) - sum(from - 1);
    }

    public long sum(int index) {
        int sum = 0;
        for (int i = index; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }
}