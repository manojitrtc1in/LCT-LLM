import java.util.ArrayList;
import java.math.*;
import java.awt.*;
import java.io.*;
import java.util.Iterator;
import java.util.*;

public class Main implements Runnable {
    @Override
    public void run() {
        try {
            new Solver().solve();
            System.exit(0);
        } catch (Exception | Error e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static void main(String[] args) {
        new Thread(null, new Main(), "Solver", 1l << 27).start();
        

    }
}


class Solver {
    final Helper hp;
    final int MAXN = 1000_006;
    final long MOD = (long) 1e9 + 7;

    final Timer timer;
    final TimerTask task;

    Solver() {
        hp = new Helper(MOD, MAXN);
        hp.initIO(System.in, System.out);

        timer = new Timer();
        task = new TimerTask() {
            @Override
            public void run() {
                try {
                    hp.flush();
                    System.exit(0);
                } catch (Exception e) {
                }
            }
        };
        

    }

    int N;
    ArrayList<Integer>[] graph;
    int[] color;

    void solve() throws Exception {
        int i, j, k;
        boolean testCases = false;

        int tc = testCases ? hp.nextInt() : 1;
        for (int tce = 1; tce <= tc; tce++) {
            N = hp.nextInt();
            color = hp.id7(N);
            graph = new ArrayList[N];
            for (i = 0; i < N; ++i) graph[i] = new ArrayList<>();
            for (i = 0; i < N - 1; ++i) {
                int a = hp.nextInt() - 1, b = hp.nextInt() - 1;
                graph[a].add(b); graph[b].add(a);
            }

            for (ArrayList<Integer> ar : graph) Collections.sort(ar);
            rec = new int[N][];

            decompose(0, -7);
            id5(0, -7, 0);

            for (i = 0; i < N; ++i) {
                int cnt = color[i] == 1 ? 1 : -1;
                for (int itr : rec[i]) cnt += Math.max(0, itr);
                hp.printsp(cnt);
            }
        }

        timer.cancel();
        hp.flush();
    }

    int[][] rec;

    int decompose(int node, int par) {
        rec[node] = new int[graph[node].size()];
        Arrays.fill(rec[node], -7);

        for (int i = 0; i < graph[node].size(); ++i) if (graph[node].get(i) != par) {
            rec[node][i] = decompose(graph[node].get(i), node);
        }

        int ret = color[node] == 1 ? 1 : -1;
        for (int i = 0; i < graph[node].size(); ++i) if (graph[node].get(i) != par) {
            ret += Math.max(0, rec[node][i]);
        }
        return ret;
    }

    void id5(int node, int par, int fromTop) {
        int idx = Collections.binarySearch(graph[node], par);
        if (idx >= 0) {
            rec[node][idx] = fromTop;
        }

        int n = graph[node].size();
        int thisNode = color[node] == 1 ? 1 : -1;
        int[] prefix = new int[n], suffix = new int[n];

        for (int i = 0; i < n; ++i) prefix[i] = suffix[i] = Math.max(0, rec[node][i]);
        for (int i = 1; i < n; ++i) prefix[i] += prefix[i - 1];
        for (int i = n - 2; i >= 0; --i) suffix[i] += suffix[i + 1];

        for (int i = 0; i < n; ++i) if (graph[node].get(i) != par) {
            int tmp = 0;
            if (i > 0) tmp += prefix[i - 1];
            if (i + 1 < n) tmp += suffix[i + 1];
            id5(graph[node].get(i), node, thisNode + tmp);
        }
    }
}

class id0 implements Iterable<Long> {
    Node root;

    id0() {
        root = null;
    }

    public boolean add(long value) {
        return add(new Node(value));
    }

    public boolean remove(long value) {
        Node actual = new Node(value), toRemove = floor(actual);
        if (toRemove.compareTo(actual) != 0) return false;
        return remove(toRemove);
    }

    public boolean id10(int index) {
        if (index < 0 || index >= size()) return false;
        else return remove(navigateTo(root, index));
    }

    public long floor(long value) {
        return floor(new Node(value)).value;
    }

    public long ceiling(long value) {
        return ceiling(new Node(value)).value;
    }

    public long lower(long value) {
        return lower(new Node(value)).value;
    }

    public long higher(long value) {
        return higher(new Node(value)).value;
    }

    public long id12(int index) {
        if (index < 0 || index >= size()) return 7 / 0;
        else return navigateTo(root, index).value;
    }

    public int id9(long value) {
        return id9(root, new Node(value));
    }

    public int size() {
        return root == null ? 0 : root.size();
    }

    private boolean add(Node toAdd) {
        if (root == null) {
            root = toAdd;
            return true;
        }

        Node tr = root;
        while (true) {
            if (toAdd.compareTo(tr) < 0) {
                if (tr.left == null) {
                    tr.left = toAdd;
                    toAdd.parent = tr;
                    break;
                } else tr = tr.left;
            } else { 

                if (tr.right == null) {
                    tr.right = toAdd;
                    toAdd.parent = tr;
                    break;
                } else tr = tr.right;
            } 

        }

        while (toAdd != null) {
            root = toAdd.id2(root);
            toAdd = toAdd.parent;
        }
        return true;
    }

    private boolean remove(Node node) {
        if (root.size() == 1) {
            root = null;
            return true;
        }
        Node p;

        if (node.left != null) {
            p = prev(node);
            if (p.parent != null) {
                if (p.parent.left == p) p.parent.left = p.left;
                else if (p.parent.right == p) p.parent.right = p.left;
                else System.exit(7 / 0);
            }
            if (p.left != null) p.left.parent = p.parent;
        } else if (node.right != null) {
            p = next(node);
            if (p.parent != null) {
                if (p.parent.left == p) p.parent.left = p.right;
                else if (p.parent.right == p) p.parent.right = p.right;
                else System.exit(7 / 0);
            }
            if (p.right != null) p.right.parent = p.parent;
        } else {
            if (node.parent.left == node) node.parent.left = null;
            else if (node.parent.right == node) node.parent.right = null;
            else System.exit(7 / 0);

            Node tr = node.parent;
            while (tr != null) {
                root = tr.id2(root);
                tr = tr.parent;
            }
            return true;
        }


        Node tr = p.parent;
        while (tr != node) {
            root = tr.id2(root);
            tr = tr.parent;
        }

        p.parent = node.parent;
        node.parent = null;
        p.left = node.left;
        node.left = null;
        p.right = node.right;
        node.right = null;

        if (p.parent != null) {
            if (p.parent.left == node) p.parent.left = p;
            else if (p.parent.right == node) p.parent.right = p;
            else System.exit(7 / 0);
        }
        if (p.left != null) p.left.parent = p;
        if (p.right != null) p.right.parent = p;

        if (root == node) root = p;
        while (p != null) {
            root = p.id2(root);
            p = p.parent;
        }

        return true;
    }

    private Node floor(Node node) {
        if (root == null) return null;

        Node tr = root;
        while (true) {
            if (node.compareTo(tr) < 0) {
                if (tr.left == null) return prev(tr);
                else tr = tr.left;
            } else if (node.compareTo(tr) > 0) {
                if (tr.right == null) return tr;
                else tr = tr.right;
            } else return tr;
        }
    }

    private Node ceiling(Node node) {
        if (root == null) return null;

        Node tr = root;
        while (true) {
            if (node.compareTo(tr) < 0) {
                if (tr.left == null) return tr;
                else tr = tr.left;
            } else if (node.compareTo(tr) > 0) {
                if (tr.right == null) return next(tr);
                else tr = tr.right;
            } else return tr;
        }
    }

    private Node lower(Node node) {
        Node fl = floor(node);
        if (fl != null && node.compareTo(fl) == 0) fl = prev(fl);
        return fl;
    }

    private Node higher(Node node) {
        Node cl = ceiling(node);
        if (cl != null && node.compareTo(cl) == 0) cl = next(cl);
        return cl;
    }

    private Node navigateTo(Node node, int ind) {
        if (Node.findSize(node.left) > ind) return navigateTo(node.left, ind);
        ind -= Node.findSize(node.left);
        if (ind == 0) return node;
        ind -= 1;
        return navigateTo(node.right, ind);
    }

    private int id9(Node node, Node key) {
        if (node == null) return 0;
        else if (node.compareTo(key) > 0)
            return id9(node.left, key);
        else
            return Node.findSize(node.left) + 1 + id9(node.right, key);
    }

    private Node prev(Node node) {
        Node parent;

        if (node.left != null) {
            node = node.left;
            while (node.right != null) node = node.right;
            return node;
        }

        while (true) {
            parent = node.parent;
            if (parent == null) return null;
            else if (parent.right == node) return parent;
            else node = parent;
        }
    }

    private Node next(Node node) {
        Node parent;

        if (node.right != null) {
            node = node.right;
            while (node.left != null) node = node.left;
            return node;
        }

        while (true) {
            parent = node.parent;
            if (parent == null) return null;
            else if (parent.left == node) return parent;
            else node = parent;
        }
    }

    private int itrInd;
    private ArrayList<Node> dfsTrav = new ArrayList<>();

    public Iterator<Long> iterator() {
        dfsTrav.clear();
        dfs(root);
        itrInd = 0;
        Iterator<Long> iterator = new Iterator<Long>() {
            @Override
            public boolean hasNext() {
                return itrInd < size();
            }

            @Override
            public Long next() {
                return dfsTrav.get(itrInd++).value;
            }
        };
        return iterator;
    }

    private void dfs(Node node) {
        if (node == null) return;
        dfs(node.left);
        dfsTrav.add(node);
        dfs(node.right);
    }

    public String toString() {
        dfsTrav.clear();
        dfs(root);
        if (dfsTrav.isEmpty()) return "[]";
        else return dfsTrav.toString();
    }
}

class Node {
    Node parent, left, right;
    long value;
    int size, height;

    Node(long v) {
        value = v;
        size = height = 1;
    }

    Node id2(Node root) {
        int lheight = findDepth(left), rheight = findDepth(right);

        if (lheight > rheight + 1) {
            if (findDepth(left.right) > findDepth(left.left))
                root = left.rotateLeft(root);
            root = rotateRight(root);
        } else if (lheight + 1 < rheight) {
            if (findDepth(right.left) > findDepth(right.right))
                root = right.rotateRight(root);
            root = rotateLeft(root);
        } else {
            setParameters();
        }

        return root;
    }

    Node rotateRight(Node root) {
        Node A = this, B = left, P = parent;

        if (P != null) {
            if (P.left == this) P.left = B;
            else if (P.right == this) P.right = B;
            else System.exit(7 / 0);
        } else root = B;
        B.parent = A.parent;

        A.left = B.right;
        if (B.right != null) B.right.parent = A;
        B.right = A;
        A.parent = B;

        A.setParameters();
        B.setParameters();

        return root;
    }

    Node rotateLeft(Node root) {
        Node A = this, B = right, P = parent;

        if (P != null) {
            if (P.left == this) P.left = B;
            else if (P.right == this) P.right = B;
            else System.exit(7 / 0);
        } else root = B;
        B.parent = A.parent;

        A.right = B.left;
        if (B.left != null) B.left.parent = A;
        B.left = A;
        A.parent = B;

        A.setParameters();
        B.setParameters();

        return root;
    }

    void setParameters() {
        size = 1 + findSize(left) + findSize(right);
        height = 1 + Math.max(findDepth(left), findDepth(right));
    }

    int size() {
        return size;
    }

    static int findDepth(Node node) {
        return node == null ? 0 : node.height;
    }

    static int findSize(Node node) {
        return node == null ? 0 : node.size();
    }

    public int compareTo(Node node) {
        return Long.compare(value, node.value);
    }

    public String toString() {
        return value + "";
    }
}

class Helper {
    final long MOD;
    final int MAXN;
    final Random rnd;

    public Helper(long mod, int maxn) {
        MOD = mod;
        MAXN = maxn;
        rnd = new Random();
    }


    public static int[] sieve;
    public static ArrayList<Integer> primes;

    public void id3() {
        primes = new ArrayList<>();
        sieve = new int[MAXN];
        int i, j;
        for (i = 2; i < MAXN; ++i)
            if (sieve[i] == 0) {
                primes.add(i);
                for (j = i; j < MAXN; j += i) {
                    sieve[j] = i;
                }
            }
    }


    public static long[] factorial;

    public void id6() {
        factorial = new long[MAXN];
        factorial[0] = 1;
        for (int i = 1; i < MAXN; ++i) factorial[i] = factorial[i - 1] * i % MOD;
    }

    public long id1(int n) {
        if (factorial == null) id6();
        return factorial[n];
    }

    public long ncr(int n, int r) {
        if (r > n) return 0;
        if (factorial == null) id6();
        long numerator = factorial[n];
        long denominator = factorial[r] * factorial[n - r] % MOD;
        return numerator * pow(denominator, MOD - 2, MOD) % MOD;
    }


    public long[] id4(int size) throws Exception {
        long[] ar = new long[size];
        for (int i = 0; i < size; ++i) ar[i] = nextLong();
        return ar;
    }

    public int[] id7(int size) throws Exception {
        int[] ar = new int[size];
        for (int i = 0; i < size; ++i) ar[i] = nextInt();
        return ar;
    }

    public String[] id11(int size) throws Exception {
        String[] ar = new String[size];
        for (int i = 0; i < size; ++i) ar[i] = next();
        return ar;
    }

    public String joinElements(long... ar) {
        StringBuilder sb = new StringBuilder();
        for (long itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }


    public String joinElements(int... ar) {
        StringBuilder sb = new StringBuilder();
        for (int itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }

    public String joinElements(String... ar) {
        StringBuilder sb = new StringBuilder();
        for (String itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }

    public String joinElements(Object... ar) {
        StringBuilder sb = new StringBuilder();
        for (Object itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }


    public long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }


    public long max(long... ar) {
        long ret = ar[0];
        for (long itr : ar) ret = Math.max(ret, itr);
        return ret;
    }

    public int max(int... ar) {
        int ret = ar[0];
        for (int itr : ar) ret = Math.max(ret, itr);
        return ret;
    }

    public long min(long... ar) {
        long ret = ar[0];
        for (long itr : ar) ret = Math.min(ret, itr);
        return ret;
    }

    public int min(int... ar) {
        int ret = ar[0];
        for (int itr : ar) ret = Math.min(ret, itr);
        return ret;
    }


    public long sum(long... ar) {
        long sum = 0;
        for (long itr : ar) sum += itr;
        return sum;
    }

    public long sum(int... ar) {
        long sum = 0;
        for (int itr : ar) sum += itr;
        return sum;
    }

    public void shuffle(int[] ar) {
        int r;
        for (int i = 0; i < ar.length; ++i) {
            r = rnd.nextInt(ar.length);
            if (r != i) {
                ar[i] ^= ar[r];
                ar[r] ^= ar[i];
                ar[i] ^= ar[r];
            }
        }
    }

    public void shuffle(long[] ar) {
        int r;
        for (int i = 0; i < ar.length; ++i) {
            r = rnd.nextInt(ar.length);
            if (r != i) {
                ar[i] ^= ar[r];
                ar[r] ^= ar[i];
                ar[i] ^= ar[r];
            }
        }
    }

    public void reverse(int[] ar) {
        int r;
        for (int i = 0; i < ar.length; ++i) {
            r = ar.length - 1 - i;
            if (r > i) {
                ar[i] ^= ar[r];
                ar[r] ^= ar[i];
                ar[i] ^= ar[r];
            }
        }
    }

    public void reverse(long[] ar) {
        int r;
        for (int i = 0; i < ar.length; ++i) {
            r = ar.length - 1 - i;
            if (r > i) {
                ar[i] ^= ar[r];
                ar[r] ^= ar[i];
                ar[i] ^= ar[r];
            }
        }
    }

    public long pow(long base, long exp, long MOD) {
        base %= MOD;
        long ret = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) ret = ret * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return ret;
    }


    static final int id8 = 1 << 20;
    static byte[] buf;
    static int index, total;
    static InputStream in;
    static BufferedWriter bw;


    public void initIO(InputStream is, OutputStream os) {
        try {
            in = is;
            bw = new BufferedWriter(new OutputStreamWriter(os));
            buf = new byte[id8];
        } catch (Exception e) {
        }
    }

    public void initIO(String inputFile, String outputFile) {
        try {
            in = new FileInputStream(inputFile);
            bw = new BufferedWriter(new OutputStreamWriter(
                    new FileOutputStream(outputFile)));
            buf = new byte[id8];
        } catch (Exception e) {
        }
    }

    private int scan() throws Exception {
        if (index >= total) {
            index = 0;
            total = in.read(buf);
            if (total <= 0)
                return -1;
        }
        return buf[index++];
    }

    public String next() throws Exception {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        StringBuilder sb = new StringBuilder();
        for (; c > 32; c = scan())
            sb.append((char) c);
        return sb.toString();
    }

    public int nextInt() throws Exception {
        int c, val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        boolean neg = c == '-';
        if (c == '-' || c == '+')
            c = scan();
        for (; c >= '0' && c <= '9'; c = scan())
            val = (val << 3) + (val << 1) + (c & 15);
        return neg ? -val : val;
    }

    public long nextLong() throws Exception {
        int c;
        long val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        boolean neg = c == '-';
        if (c == '-' || c == '+')
            c = scan();
        for (; c >= '0' && c <= '9'; c = scan())
            val = (val << 3) + (val << 1) + (c & 15);
        return neg ? -val : val;
    }

    public void print(Object a) throws Exception {
        bw.write(a.toString());
    }

    public void printsp(Object a) throws Exception {
        print(a);
        print(" ");
    }

    public void println() throws Exception {
        bw.write("\n");
    }

    public void println(Object a) throws Exception {
        print(a);
        println();
    }

    public void flush() throws Exception {
        bw.flush();
    }
}
