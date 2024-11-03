import java.io.*;


import java.util.*;

public final class Main extends Solution {
    final int mod = 1000000007;

    void init() {

    }

    void solve() {
        int n = 2 * sc.nextInt();
        int[] f = new int[2];
        for (int i = 0; i < n; i++) {
            f[sc.nextInt() % 2]++;
        }
        if (f[0] == f[1])
            print("YES");
        else
            print("NO");
    }

    void main() {
        

        tcases();
        

        pw.flush();
        pw.close();
    }

    void stresstest() {

    }

    void tcases() {
        int t = sc.nextInt();
        init();
        while (t-- > 0) {
            solve();
            

        }
    }

    void oneCase() {
        init();
        solve();
    }

    Scanner sc;
    PrintWriter pw;
    File file;

    Main() {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
    }

    Main(String filename) throws IOException {
        sc = new Scanner(System.in);
        file = new File(filename);
        if (file.exists())
            file.delete();
        file.createNewFile();
        pw = new PrintWriter(file);
    }

    void print() {
        pw.write("\n");
    }

    void print(char[][] a) {
        for (int i = 0; i < a.length; i++)
            pw.write(new String(a[i]) + "\n");
    }

    void print(int[][] a) {
        for (int i = 0; i < a.length; i++)
            pw.write(Arrays.toString(a[i]) + "\n");
    }

    void print(int... a) {
        for (int i = 0; i < a.length - 1; i++)
            pw.write(a[i] + " ");
        pw.write(a[a.length - 1] + "\n");
    }

    void print(char... a) {
        for (int i = 0; i < a.length - 1; i++)
            pw.write(a[i] + " ");
        pw.write(a[a.length - 1] + "\n");
    }

    void print(long... a) {
        for (int i = 0; i < a.length - 1; i++)
            pw.write(a[i] + " ");
        pw.write(a[a.length - 1] + "\n");
    }

    void print(double... a) {
        for (int i = 0; i < a.length - 1; i++)
            pw.write(a[i] + " ");
        pw.write(a[a.length - 1] + "\n");
    }

    void print(String... a) {
        for (int i = 0; i < a.length - 1; i++)
            pw.write(a[i] + " ");
        pw.write(a[a.length - 1] + "\n");
    }

    void print(Iterator<int[]> a) {
        StringBuilder sb = new StringBuilder();
        while (a.hasNext()) {
            sb.append(Arrays.toString(a.next()));
        }
        print(sb.toString());
    }

    String toString(int[] arr) {
        return Arrays.toString(arr);
    }

    int[][] scanMatrix(int n, int m) {
        int[][] mat = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = sc.nextInt();
            }
        }
        return mat;
    }

    int[][] scanMatrix(int n) {
        int[][] mat = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = sc.nextInt();
            }
        }
        return mat;
    }

    int[] scanArray(int n) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        return arr;
    }

    int[] randArray(int n, Random rand, int l, int r) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = l + rand.nextInt(r - l + 1);
        }
        return arr;
    }

    Graph scanGraph(int n, int m, boolean directed) {
        Graph g = new Graph(n);
        if (directed)
            for (int i = 0; i < m; i++)
                g.addEdge(sc.nextInt(), sc.nextInt());
        else
            for (int i = 0; i < m; i++)
                g.addBiEdge(sc.nextInt(), sc.nextInt());
        return g;
    }

    Tree scanTree(int n) {
        Tree g = new Tree(n);
        for (int i = 1; i < n; i++)
            g.addBiEdge(sc.nextInt(), sc.nextInt());
        return g;
    }

    public static void main(String[] args) {
        Main ob = new Main();
        ob.main();
    }
}

class Solution {
    long pow(long a, long b, long mod) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    int pow(int a, long b, int mod) {
        int res = 1;
        while (b > 0) {
            if ((b & 1) == 1)
                res = (int) (((long) res * a) % mod);
            a = (int) (((long) a * a) % mod);
            b >>= 1;
        }
        return res;
    }

    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int gcd(int... a) {
        int g = a[0];
        for (int i = 1; i < a.length; i++)
            g = gcd(g, a[i]);
        return g;
    }

    long gcd(long... a) {
        long g = a[0];
        for (int i = 1; i < a.length; i++)
            g = gcd(g, a[i]);
        return g;
    }

    long lcm(int a, int b) {
        return ((long) a * b) / gcd(a, b);
    }

    long lcm(int... a) {
        long g = a[0];
        for (int i = 1; i < a.length; i++)
            g = lcm(g, a[i]);
        return g;
    }

    long lcm(long... a) {
        long g = a[0];
        for (int i = 1; i < a.length; i++)
            g = lcm(g, a[i]);
        return g;
    }

    long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long modInverse(long a, long mod) {
        return pow(a, mod - 2, mod);
    }

    int ceilLog2(long x) {
        int c = 0;
        if ((x & -x) == x)
            c--;
        while (x != 0) {
            x >>= 1;
            c++;
        }
        return c;
    }

    int max(int... a) {
        int m = Integer.MIN_VALUE;
        for (int i : a) {
            if (i > m)
                m = i;
        }
        return m;
    }

    long max(long... a) {
        long m = Long.MIN_VALUE;
        for (long i : a) {
            if (i > m)
                m = i;
        }
        return m;
    }

    double max(double... a) {
        double m = Double.MIN_VALUE;
        for (double i : a) {
            if (i > m)
                m = i;
        }
        return m;
    }

    int min(int... a) {
        int m = Integer.MAX_VALUE;
        for (int i : a) {
            if (i < m)
                m = i;
        }
        return m;
    }

    long min(long... a) {
        long m = Long.MAX_VALUE;
        for (long i : a) {
            if (i < m)
                m = i;
        }
        return m;
    }

    double min(double... a) {
        double m = Double.MAX_VALUE;
        for (double i : a) {
            if (i < m)
                m = i;
        }
        return m;
    }

    long sum(int... a) {
        long s = 0L;
        for (int i : a) {
            s += i;
        }
        return s;
    }

    long sum(long... a) {
        long s = 0;
        for (long i : a) {
            s += i;
        }
        return s;
    }

    int sum(int[] a, int l, int r) {
        int s = 0;
        for (int i = l; i <= r; i++) {
            s += a[i];
        }
        return s;
    }

    long sum(long[] a, int l, int r) {
        long s = 0;
        for (int i = l; i <= r; i++) {
            s += a[i];
        }
        return s;
    }

    double sum(double... a) {
        double s = 0;
        for (double i : a) {
            s += i;
        }
        return s;
    }

    double sum(double[] a, int l, int r) {
        double s = 0;
        for (int i = l; i <= r; i++) {
            s += a[i];
        }
        return s;
    }

    int modPos(int a, int b) {
        return (a % b + b) % b;
    }

    long modPos(long a, long b) {
        return (a % b + b) % b;
    }

    void print() {
        System.out.println();
    }

    void print(int... a) {
        for (int i = 0; i < a.length - 1; i++)
            System.out.print(a[i] + " ");
        System.out.println(a[a.length - 1]);
    }

    void print(char... a) {
        for (int i = 0; i < a.length - 1; i++)
            System.out.print(a[i] + " ");
        System.out.println(a[a.length - 1] + "\n");
    }

    void print(long... a) {
        for (int i = 0; i < a.length - 1; i++)
            System.out.print(a[i] + " ");
        System.out.println(a[a.length - 1]);
    }

    void print(double... a) {
        for (int i = 0; i < a.length - 1; i++)
            System.out.print(a[i] + " ");
        System.out.println(a[a.length - 1]);
    }

    void print(String... a) {
        for (int i = 0; i < a.length - 1; i++)
            System.out.print(a[i] + " ");
        System.out.println(a[a.length - 1]);
    }

    void print(char[][] a) {
        for (int i = 0; i < a.length - 1; i++)
            System.out.println(new String(a[i]));
        System.out.println(new String(a[a.length - 1]));
    }

    void print(int[][] a) {
        System.out.println(Arrays.deepToString(a));
    }

    void print(Iterator<int[]> a) {
        StringBuilder sb = new StringBuilder();
        while (a.hasNext()) {
            sb.append(Arrays.toString(a.next()));
        }
        print(sb.toString());
    }

    void sort(int[] arr, int l, int r) {
        Arrays.sort(arr, l, r + 1);
    }

    int[] sorted(int[] arr) {
        int[] brr = arr.clone();
        Arrays.sort(brr);
        return brr;
    }

    boolean isSorted(int[] arr, int l, int r) {
        while (l < r) {
            if (arr[l] > arr[l + 1])
                return false;
            l++;
        }
        return true;
    }

    List<Integer> sorted(List<Integer> arr) {
        List<Integer> brr = new ArrayList<>(arr);
        Collections.sort(brr);
        return brr;
    }

    List<Integer> sorted(Set<Integer> arr) {
        List<Integer> brr = new ArrayList<>(arr);
        Collections.sort(brr);
        return brr;
    }

    String sorted(String S) {
        char[] s = S.toCharArray();
        Arrays.sort(s);
        return new String(s);
    }

    boolean allSame(int[] arr) {
        for (int i : arr)
            if (i != arr[0])
                return false;
        return true;
    }

    int mergeSortCountInversions(int[] arr, int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            int[] A = new int[m - l + 1], B = new int[r - m];
            for (int i = l; i <= m; i++)
                A[i - l] = arr[i];
            for (int i = m + 1; i <= r; i++)
                B[i - m - 1] = arr[i];
            return mergeSortCountInversions(A, 0, A.length - 1) +
                    mergeSortCountInversions(B, 0, B.length - 1) +
                    merge(arr, A, B, l, m, r);
        }
        return 0;
    }

    int bisectRight(int[] A, int x) {
        int l = 0, r = A.length - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (A[m] > x && (m == 0 || A[m - 1] <= x)) {
                return m;
            } else if (A[m] > x) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return A.length;
    }

    int merge(int[] arr, int[] A, int[] B, int l, int m, int r) {
        int swaps = 0;
        for (int j = 0; j < B.length; j++) {
            swaps += A.length - bisectRight(A, B[j]);
        }
        int i = 0, j = 0, k = l;
        while (i < A.length && j < B.length) {
            if (A[i] < B[j]) {
                arr[k++] = A[i++];
            } else {
                arr[k++] = B[j++];
            }
        }
        while (i < A.length) {
            arr[k++] = A[i++];
        }
        while (j < B.length) {
            arr[k++] = B[j++];
        }
        return swaps;
    }

    int minSwapsToSort(int arr[]) {
        int[] brr = sorted(arr);
        Map<Integer, Integer> reqPos = new Hashtable<>();
        for (int i = 0; i < brr.length; i++) {
            reqPos.put(brr[i], i);
        }
        byte[] vis = new byte[arr.length];
        int ans = 0;
        for (int i = 0; i < arr.length; i++) {
            if (vis[i] == 0) {
                int x = 0;
                Queue<Integer> q = new LinkedList<>();
                q.add(i);
                while (!q.isEmpty()) {
                    int u = q.remove();
                    x++;
                    if (vis[u] == 1)
                        continue;
                    vis[u] = 1;
                    if (vis[reqPos.get(arr[u])] == 0)
                        q.add(reqPos.get(arr[u]));
                }
                ans += x - 1;
            }
        }
        return ans;
    }

    void cyclicFlip(int[] arr, int n) {
        for (int i = 0; i < n; i++)
            arr[i]++; 


        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                int j = i, t = arr[i];
                while (j >= 0 && arr[j] >= 0) {
                    int y = arr[j];
                    arr[j] = -arr[y - 1];
                    if (arr[j] > 0)
                        arr[j] = -t;
                    j = y - 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
            arr[i]--;
    }

    int findPeak(int arr[], int low, int high, int n) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
            return mid;
        else if (mid > 0 && arr[mid - 1] > arr[mid])
            return findPeak(arr, low, (mid - 1), n);
        else
            return findPeak(arr, (mid + 1), high, n);
    }

    int[] computePrefixFunction(char[] P) {
        int[] s = new int[P.length];
        s[0] = 0;
        int border = 0;
        for (int i = 1; i < P.length; i++) {
            while (border > 0 && P[i] != P[border])
                border = s[border - 1];
            if (P[i] == P[border])
                border++;
            else
                border = 0;
            s[i] = border;
        }
        return s;
    }

    public List<Integer> KMP(String pattern, String text) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        int[] s = computePrefixFunction((pattern + "$" + text).toCharArray());
        int pn = pattern.length();
        for (int i = pn + 1; i < s.length; i++) {
            if (s[i] == pn)
                result.add(i - 2 * pn);
        }
        return result;
    }
}

class Graph {
    List<Integer>[] adj;
    int n;

    @SuppressWarnings("unchecked")
    Graph(int n) {
        this.n = n;
        adj = new List[n + 1];
        for (int i = 0; i < n + 1; i++) {
            adj[i] = new ArrayList<Integer>();
        }
    }

    int[] dijkstra(int start) {
        int[] dist = new int[n + 1];
        boolean[] vis = new boolean[n + 1];
        Arrays.fill(dist, -1);
        dist[start] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[1] != b[1])
                return a[1] - b[1];
            else
                return a[0] - b[0];
        });
        pq.add(new int[] { start, 0 });
        while (!pq.isEmpty()) {
            int u = pq.remove()[0];
            if (!vis[u]) {
                vis[u] = true;
                for (int v : adj[u]) {
                    if (dist[v] == -1 || dist[u] + 1 < dist[v]) {
                        dist[v] = 1 + dist[u];
                        System.out.println(u + " " + v + " " + dist[v]);
                        pq.add(new int[] { v, dist[v] });
                    }
                }
            }
        }
        return dist;
    }

    void addEdge(int u, int v) {
        adj[u].add(v);
    }

    void addBiEdge(int u, int v) {
        adj[u].add(v);
        adj[v].add(u);
    }
}

class Tree extends Graph {
    int[] parent;

    Tree(int n) {
        super(n);
    }

    void makeRoot(int root) {
        if (parent == null)
            parent = new int[n + 1];
        dfsMakeRoot(root, root);

    }

    void dfsMakeRoot(int u, int p) {
        parent[u] = p;
        for (int v : adj[u]) {
            if (v != p)
                dfsMakeRoot(v, u);
        }
    }
}

class SubMatrixSum {
    int[][] dp;

    SubMatrixSum(int mat[][]) {
        int n = mat.length, m = mat[0].length;
        dp = new int[n][m];
        dp[0][0] = mat[0][0];
        for (int i = 1; i < n; i++)
            dp[i][0] = mat[i][0] + dp[i - 1][0];
        for (int i = 1; i < m; i++)
            dp[0][i] = mat[0][i] + dp[0][i - 1];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = mat[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }
        System.out.println(Arrays.deepToString(dp));
    }

    int query(int rs, int cs, int re, int ce) {
        if (rs > 0 && cs > 0)
            return dp[re][ce] - dp[rs - 1][ce] - dp[re][cs - 1] + dp[rs - 1][cs - 1];
        else if (rs > 0)
            return dp[re][ce] - dp[rs - 1][ce];
        else if (cs > 0)
            return dp[re][ce] - dp[re][cs - 1];
        else
            return dp[re][ce];
    }
}

class GCDExceptSelf {
    int[] arr, left, right;

    GCDExceptSelf(int[] arr) {
        this.arr = arr;
        left = new int[arr.length];
        right = new int[arr.length];
        left[0] = arr[0];
        right[arr.length - 1] = arr[arr.length - 1];
        for (int i = 1; i < arr.length; i++) {
            left[i] = gcd(left[i - 1], arr[i]);
        }
        for (int i = arr.length - 2; i >= 0; i--) {
            right[i] = gcd(right[i + 1], arr[i]);
        }
    }

    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int get(int i) {
        if (i > 0 && i < arr.length - 1) {
            return gcd(left[i - 1], right[i + 1]);
        } else if (i > 0)
            return left[i - 1];
        else if (i < arr.length - 1)
            return right[i + 1];
        else
            return 1;
    }
}

class SuffixTreeNode {
    SuffixTreeNode parent;
    TreeMap<Character, SuffixTreeNode> children;
    Integer stringDepth, edgeStart, edgeEnd;
    byte vis;

    SuffixTreeNode(SuffixTreeNode parent, Integer stringDepth, Integer edgeStart, Integer edgeEnd) {
        this.parent = parent;
        this.stringDepth = stringDepth;
        this.edgeStart = edgeStart;
        this.edgeEnd = edgeEnd;
        this.children = new TreeMap<>();
        this.vis = 0;
    }
}

class SuffixArray {
    int[] suffixarray;
    char[] S;

    SuffixTreeNode getSuffixTree() {
        return STfromSA(suffixarray, computeLCPArray());
    }

    SuffixTreeNode STfromSA(int[] order, int[] lcpArray) {
        SuffixTreeNode root = new SuffixTreeNode(null, 0, -1, -1);
        int lcpPrev = 0;
        SuffixTreeNode curNode = root;
        for (int i = 0; i < S.length; i++) {
            int suffix = order[i];
            while (curNode.stringDepth > lcpPrev) {
                curNode = curNode.parent;
            }
            if (curNode.stringDepth == lcpPrev) {
                curNode = createNewLeaf(curNode, suffix);
            } else {
                int edgeStart = order[i - 1] + curNode.stringDepth,
                        offset = lcpPrev - curNode.stringDepth;
                SuffixTreeNode midNode = breakEdge(curNode, edgeStart, offset);
                curNode = createNewLeaf(midNode, suffix);
            }
            if (i < S.length - 1) {
                lcpPrev = lcpArray[i];
            }
        }
        return root;
    }

    SuffixTreeNode createNewLeaf(SuffixTreeNode node, int suffix) {
        SuffixTreeNode leaf = new SuffixTreeNode(node, S.length - suffix, suffix + node.stringDepth, S.length);
        node.children.put(S[leaf.edgeStart], leaf);
        leaf.parent = node;
        return leaf;
    }

    SuffixTreeNode breakEdge(SuffixTreeNode node, int start, int offset) {
        char startChar = S[start],
                midChar = S[start + offset];
        SuffixTreeNode midNode = new SuffixTreeNode(node, node.stringDepth + offset, start, start + offset);
        midNode.children.put(midChar, node.children.get(startChar));
        node.children.get(startChar).parent = midNode;
        node.children.get(startChar).edgeStart += offset;
        node.children.put(startChar, midNode);
        return midNode;
    }

    int lcpOfSuffixes(int i, int j, int equal) {
        int lcp = Math.max(0, equal);
        while (i + lcp < S.length && j + lcp < S.length && S[i + lcp] == S[j + lcp]) {
            lcp++;
        }
        return lcp;
    }

    int[] invertSuffixArray() {
        int[] pos = new int[suffixarray.length];
        for (int i = 0; i < suffixarray.length; i++) {
            pos[suffixarray[i]] = i;
        }
        return pos;
    }

    int[] computeLCPArray() {
        int[] lcpArray = new int[S.length - 1];
        int lcp = 0;
        int[] posInOrder = invertSuffixArray();
        int suffix = suffixarray[0];
        for (int i = 0; i < S.length; i++) {
            int orderIndex = posInOrder[suffix];
            if (orderIndex == S.length - 1) {
                lcp = 0;
                suffix = (suffix + 1) % S.length;
                continue;
            }
            int nextSuffix = suffixarray[orderIndex + 1];
            lcp = lcpOfSuffixes(suffix, nextSuffix, lcp - 1);
            lcpArray[orderIndex] = lcp;
            suffix = (suffix + 1) % S.length;
        }
        return lcpArray;
    }

    int[] sortCharacters() {
        int[] order = new int[S.length];
        TreeMap<Character, Integer> count = new TreeMap<>();
        for (int i = 0; i < S.length; i++) {
            count.put(S[i], count.getOrDefault(S[i], 0) + 1);
        }
        Character[] keys = count.keySet().toArray(new Character[0]);
        for (int i = 1; i < keys.length; i++) {
            count.put(keys[i], count.get(keys[i]) + count.get(keys[i - 1]));
        }
        for (int i = S.length - 1; i >= 0; i--) {
            count.put(S[i], count.get(S[i]) - 1);
            order[count.get(S[i])] = i;
        }
        return order;
    }

    int[] computeCharClasses(int[] order) {
        int[] classes = new int[S.length];
        classes[order[0]] = 0;
        for (int i = 1; i < S.length; i++) {
            if (S[order[i]] != S[order[i - 1]]) {
                classes[order[i]] = classes[order[i - 1]] + 1;
            } else {
                classes[order[i]] = classes[order[i - 1]];
            }
        }
        return classes;
    }

    int[] sortDoubled(int L, int[] order, int[] classes) {
        int[] count = new int[S.length];
        int[] newOrder = new int[S.length];
        for (int i = 0; i < S.length; i++)
            count[classes[i]]++;
        for (int i = 1; i < S.length; i++)
            count[i] += count[i - 1];
        for (int i = S.length - 1; i >= 0; i--) {
            int start = (order[i] - L + S.length) % S.length;
            int cl = classes[start];
            count[cl]--;
            newOrder[count[cl]] = start;
        }
        return newOrder;
    }

    int[] updateClasses(int[] newOrder, int[] classes, int L) {
        int n = newOrder.length;
        int[] newClasses = new int[n];
        newClasses[newOrder[0]] = 0;
        for (int i = 1; i < n; i++) {
            int cur = newOrder[i];
            int prev = newOrder[i - 1];
            int mid = (cur + L) % n;
            int midPrev = (prev + L) % n;
            if (classes[cur] != classes[prev] || classes[mid] != classes[midPrev]) {
                newClasses[cur] = newClasses[prev] + 1;
            } else {
                newClasses[cur] = newClasses[prev];
            }
        }
        return newClasses;
    }

    SuffixArray(String text) {
        char[] S = text.toCharArray();
        int[] order = sortCharacters();
        int[] classes = computeCharClasses(order);
        int L = 1;
        while (L < S.length) {
            order = sortDoubled(L, order, classes);
            classes = updateClasses(order, classes, L);
            L *= 2;
        }
        suffixarray = order;
    }
}

class LazySegmentTreeAdd {
    int[] tree, lazy;

    LazySegmentTreeAdd(int max) {
        tree = new int[4 * max];
        lazy = new int[4 * max];
    }

    void updateRangeUtil(int si, int ss, int se, int us,
            int ue, int diff) {
        if (lazy[si] != 0) {
            tree[si] += (se - ss + 1) * lazy[si];

            if (ss != se) {
                lazy[si * 2 + 1] += lazy[si];
                lazy[si * 2 + 2] += lazy[si];
            }

            lazy[si] = 0;
        }

        if (ss > se || ss > ue || se < us)
            return;

        if (ss >= us && se <= ue) {
            tree[si] += (se - ss + 1) * diff;

            if (ss != se) {
                lazy[si * 2 + 1] += diff;
                lazy[si * 2 + 2] += diff;
            }
            return;
        }

        int mid = (ss + se) / 2;
        updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
        updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);

        tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
    }

    void updateRange(int n, int us, int ue, int diff) {
        updateRangeUtil(0, 0, n - 1, us, ue, diff);
    }

    int getSumUtil(int ss, int se, int qs, int qe, int si) {
        if (lazy[si] != 0) {
            tree[si] += (se - ss + 1) * lazy[si];

            if (ss != se) {
                lazy[si * 2 + 1] += lazy[si];
                lazy[si * 2 + 2] += lazy[si];
            }

            lazy[si] = 0;
        }

        if (ss > se || ss > qe || se < qs)
            return 0;

        if (ss >= qs && se <= qe)
            return tree[si];

        int mid = (ss + se) / 2;
        return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
                getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
    }

    int getSum(int n, int qs, int qe) {
        return getSumUtil(0, n - 1, qs, qe, 0);
    }

    void constructSTUtil(int arr[], int ss, int se, int si) {
        if (ss > se)
            return;

        if (ss == se) {
            tree[si] = arr[ss];
            return;
        }

        int mid = (ss + se) / 2;
        constructSTUtil(arr, ss, mid, si * 2 + 1);
        constructSTUtil(arr, mid + 1, se, si * 2 + 2);

        tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
    }

    void constructST(int arr[], int n) {
        constructSTUtil(arr, 0, n - 1, 0);
    }
}

class LazySegmentTreeOR {
    int[] tree, lazy;

    LazySegmentTreeOR(int max) {
        tree = new int[4 * max];
        lazy = new int[4 * max];
    }

    void updateRangeUtil(int si, int ss, int se, int us,
            int ue, int newVal) {
        if (lazy[si] != 0) {
            tree[si] |= lazy[si];

            if (ss != se) {
                lazy[si * 2 + 1] |= lazy[si];
                lazy[si * 2 + 2] |= lazy[si];
            }

            lazy[si] = 0;
        }

        if (ss > se || ss > ue || se < us)
            return;

        if (ss >= us && se <= ue) {
            tree[si] = newVal;

            if (ss != se) {
                lazy[si * 2 + 1] = newVal;
                lazy[si * 2 + 2] = newVal;
            }
            return;
        }

        int mid = (ss + se) / 2;
        updateRangeUtil(si * 2 + 1, ss, mid, us, ue, newVal);
        updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, newVal);

        tree[si] = tree[si * 2 + 1] | tree[si * 2 + 2];
    }

    void updateRange(int n, int us, int ue, int newVal) {
        updateRangeUtil(0, 0, n - 1, us, ue, newVal);
    }

    int getSumUtil(int ss, int se, int qs, int qe, int si) {
        if (lazy[si] != 0) {
            tree[si] |= lazy[si];

            if (ss != se) {
                lazy[si * 2 + 1] |= lazy[si];
                lazy[si * 2 + 2] |= lazy[si];
            }

            lazy[si] = 0;
        }

        if (ss > se || ss > qe || se < qs)
            return 0;

        if (ss >= qs && se <= qe)
            return tree[si];

        int mid = (ss + se) / 2;
        return getSumUtil(ss, mid, qs, qe, 2 * si + 1) |
                getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
    }

    int getSum(int n, int qs, int qe) {
        return getSumUtil(0, n - 1, qs, qe, 0);
    }

    void constructSTUtil(int arr[], int ss, int se, int si) {
        if (ss > se)
            return;

        if (ss == se) {
            tree[si] = arr[ss];
            return;
        }

        int mid = (ss + se) / 2;
        constructSTUtil(arr, ss, mid, si * 2 + 1);
        constructSTUtil(arr, mid + 1, se, si * 2 + 2);

        tree[si] = tree[si * 2 + 1] | tree[si * 2 + 2];
    }

    void constructSTUtil(char arr[], int ss, int se, int si) {
        if (ss > se)
            return;

        if (ss == se) {
            tree[si] = 1 << (arr[ss] - 'a');
            return;
        }

        int mid = (ss + se) / 2;
        constructSTUtil(arr, ss, mid, si * 2 + 1);
        constructSTUtil(arr, mid + 1, se, si * 2 + 2);

        tree[si] = tree[si * 2 + 1] | tree[si * 2 + 2];
    }

    void constructST(int arr[], int n) {
        constructSTUtil(arr, 0, n - 1, 0);
    }

    void constructST(char arr[], int n) {
        constructSTUtil(arr, 0, n - 1, 0);
    }
}

class RangeMinQuery {
    class Node {
        int l, r;
        int[] min;
        Node left, right;

        Node() {
        }

        Node(int l, int r) {
            this.l = l;
            this.r = r;
            this.min = new int[] { Integer.MAX_VALUE, Integer.MAX_VALUE, -1 };
        }
    }

    Node root;

    public RangeMinQuery(int l, int r) {
        root = new Node(l, r);
    }

    void update(int index, int[] val) {
        update(root, index, val);
    }

    int[] getMin(int l, int r) {
        return getMin(root, l, r);
    }

    void update(Node root, int index, int[] val) {
        if (root == null)
            return;
        

        if (root.l == root.r && root.l == index) {
            root.min = val;
            return;
        }
        int m = (root.l + root.r) / 2;
        if (index > m) {
            if (root.right == null)
                root.right = new Node(m + 1, root.r);
            update(root.right, index, val);
        } else {
            if (root.left == null)
                root.left = new Node(root.l, m);
            update(root.left, index, val);
        }
        root.min = new int[] { Integer.MAX_VALUE, Integer.MAX_VALUE, -1 };
        if (root.left != null)
            root.min = min(root.min, root.left.min);
        if (root.right != null)
            root.min = min(root.min, root.right.min);
    }

    int[] getMin(Node root, int l, int r) {
        if (root == null || l > r || r < root.l || l > root.r)
            return new int[] { Integer.MAX_VALUE, Integer.MAX_VALUE, -1 };
        if (l <= root.l && r >= root.r)
            return root.min;
        return min(getMin(root.left, l, r), getMin(root.right, l, r));
    }

    void printLeaves(Node root) {
        if (root != null) {
            if (root.left == null && root.right == null) {
                System.out.println("[" + (root.l) + "," + (root.r) + "] -> min = " + Arrays.toString(root.min));
            }
            printLeaves(root.left);
            printLeaves(root.right);
        }
    }

    int[] min(int[] a, int[] b) {
        for (int i = 0; i < a.length && i < b.length; i++) {
            if (a[i] > b[i])
                return b;
            else if (a[i] < b[i])
                return a;
        }
        if (a.length < b.length)
            return a;
        return b;
    }
}