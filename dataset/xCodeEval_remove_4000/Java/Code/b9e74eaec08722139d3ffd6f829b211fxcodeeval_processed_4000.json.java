

import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.Map.Entry;

public class Main {

    
    class id2 {

        
        private void id0(int root, int rl, int rr, int[] balance, int[] minTree) {
            if (rl == rr) {
                minTree[root] = balance[rl];
                return;
            }
            int rm = (rl + rr) / 2;
            id0(root * 2 + 1, rl, rm, balance, minTree);
            id0(root * 2 + 2, rm + 1, rr, balance, minTree);
            minTree[root] = Math.min(minTree[root * 2 + 1], minTree[root * 2 + 2]);
        }

        
        private int getMin(int[] minTree, int root, int rl, int rr, int l, int r) {
            

            if (l > r) {
                return Integer.MAX_VALUE;
            }
            if (l == rl && r == rr) {
                return minTree[root];
            }
            int rm = (rl + rr) / 2;
            return Math.min(getMin(minTree, root * 2 + 1, rl, rm, l, Math.min(r, rm)),
                    getMin(minTree, root * 2 + 2, rm + 1, rr, Math.max(rm + 1, l), r));
        }
    }
    

    int[] next;

    private int next(int i) {
        if (next[i] == i) {
            return i;
        }
        return next[i] = next(next[i]);
    }

    

    private void set(int[] t, int ind, int val) {
        ind += (t.length / 2);
        t[ind] = val;
        int curr = 0;
        while (ind > 1) {
            ind >>= 1;
            if (curr == 0) {
                t[ind] = t[ind * 2] | t[ind * 2 + 1];
            } else {
                t[ind] = t[ind * 2] ^ t[2 * ind + 1];
            }
            curr ^= 1;
        }
    }

    

    class id3 {

        int[] ft;
        int N;

        id3(int n) {
            this.N = n;
            ft = new int[N];
        }

        private int lowbit(int x) {
            return x & (-x);
        }

        void update(int pos, int val) {
            while (pos < N) {
                ft[pos] += val;
                pos |= pos + 1;

            }
        }

        int sum(int pos) {
            int sum = 0;
            while (pos >= 0) {
                sum += ft[pos];
                pos = (pos & (pos + 1)) - 1;
            }
            return sum;
        }

        int rangeSum(int left, int right) {
            return sum(right) - sum(left - 1);
        }
    }

    
    private int binarySearch(int l, int r, int at, int letter, id3[] ft) {
        while (r - l > 0) {
            int mid = (l + r) / 2;
            int sum = ft[letter].sum(mid);
            if (sum < at) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

    private int[] compress(int[] a) {
        int[] b = new int[a.length];
        for (int i = 0; i < a.length; i++) {
            b[i] = a[i];
        }
        Arrays.sort(b);
        int m = 0;
        for (int i = 0; i < b.length;) {
            int j = i;
            while (j < b.length && b[j] == b[i]) {
                j++;
            }
            b[m++] = b[i];
            i = j;
        }
        for (int i = 0; i < a.length; i++) {
            a[i] = Arrays.binarySearch(b, 0, m, a[i]);
        }
        return a;
    }

    class Dijkstra {

        class Edge implements Comparable<Edge> {

            int to;
            long weight;

            Edge(int t, long w) {
                to = t;
                weight = w;
            }

            public int compareTo(Edge other) {
                return (int) Math.signum(weight - other.weight);
            }
        }
        public static final long INF = (long) 1e17;
        private ArrayList<Edge> adj[];
        private int nodes;
        private long[] dist;
        private int[] prev;
        private boolean[] visited;

        public Dijkstra(int n) {
            nodes = n;
            adj = new ArrayList[nodes];
            dist = new long[nodes];
            prev = new int[nodes];
            visited = new boolean[nodes];
            for (int i = 0; i < nodes; i++) {
                adj[i] = new ArrayList<Edge>();
                dist[i] = INF;
                prev[i] = -1;
            }
        }

        public void add(int u, int v, long cost) {
            adj[u].add(new Edge(v, cost));
        }

        public void dist() {
            

            dist[0] = 0;
            Queue<Edge> q = new PriorityQueue<Edge>();
            q.add(new Edge(0, 0));
            while (!q.isEmpty()) {
                Edge e = q.poll();
                int ind = e.to;
                if (visited[ind]) {
                    continue;
                }
                visited[ind] = true;

                for (Edge edge : adj[ind]) {
                    long newDistance = e.weight + edge.weight;
                    if (newDistance < dist[edge.to]) {
                        dist[edge.to] = newDistance;
                        prev[edge.to] = ind;
                        q.add(new Edge(edge.to, dist[edge.to]));
                    }
                }
            }
        }

        public ArrayList<Integer> id1(int last) {
            ArrayList<Integer> al = new ArrayList<Integer>();
            while (last != -1) {
                al.add(last);
                last = prev[last];
            }
            return al;
        }

        public int[] getPrev() {
            return prev;
        }

        public long[] getDistance() {
            return dist;
        }

        public boolean[] getVisited() {
            return visited;
        }
    }
    int[] up;

    class Edge {

        int u, v, cap, flow, cost;
        Edge rev;

        Edge(int u, int v, int cap, int cost) {
            this.u = u;
            this.v = v;
            this.cap = cap;

            this.cost = cost;
        }
    }

    class Result {

        int cost, flow;

        Result(int cost, int flow) {
            this.cost = cost;
            this.flow = flow;
        }
    }

    int[] getAlphabet(String s) {
        int[] res = new int[totalLetters];
        for (int i = 0; i < s.length(); i++) {
            res[s.charAt(i) - 'a']++;
        }
        return res;
    }
    final int totalLetters = 26;
    final int id4 = 1 + 1 + 26 + 100;


    void addEdge(int u, int v, int cap, int cost, ArrayList<Edge>[] g) {
        Edge a = new Edge(u, v, cap, cost);
        Edge b = new Edge(v, u, 0, -cost);

        a.rev = b;
        b.rev = a;
        g[u].add(a);
        g[v].add(b);
    }

    void appendTestCase(int test) {
        out.print("Case 
        out.print(test);
        out.print(": ");
    }

    private void solve() throws IOException {
        int N = nextInt();
        int[][] v = new int[N][2];
        Queue<Integer> q = new ArrayDeque<Integer>();
        for (int i = 0; i < N; i++) {
            int dv = nextInt();
            int xv = nextInt();
            v[i][0] = dv;
            v[i][1] = xv;
            if (dv == 1) {
                q.add(i);
            }
        }
        while (!q.isEmpty()) {
            int curr = q.poll();
            if (v[curr][0] == 0) {
                continue;

            }
            int sv = v[curr][1];

            v[sv][1] = v[sv][1] ^ curr;
            v[sv][0] -= 1;

            if (v[sv][0] == 1) {
                q.offer(sv);
            }
        }
        int edges = 0;
        for (int i = 0; i < N; i++) {
            

            if (v[i][0] != 0) {
                edges++;
            }
        }
        out.println(edges);
        for (int i = 0; i < N; i++) {
            if (v[i][0] != 0) {
                out.println(i + " " + v[i][1]);
            }
        }
    }

    
    class RadixSort {

        void radixSort(int[] a) {
            int[] aux = new int[a.length];
            int r = 4;

            int b = 32;

            int[] count = new int[1 << r];

            int[] pref = new int[1 << r];

            int groups = (int) Math.ceil(b * 1.0 / r);

            int mask = (1 << r) - 1;

            

            for (int c = 0, shift = 0; c < groups; c++, shift += r) {
                

                Arrays.fill(count, 0);
                

                for (int i = 0; i < a.length; i++) {
                    count[(a[i] >> shift) & mask]++;
                }
                

                pref[0] = 0;
                for (int i = 1; i < count.length; i++) {
                    pref[i] = pref[i - 1] + count[i - 1];
                }
                

                for (int i = 0; i < a.length; i++) {
                    aux[pref[(a[i] >> shift) & mask]++] = a[i];
                }
                

                for (int i = 0; i < a.length; i++) {
                    a[i] = aux[i];
                }
            }
        }
    }

    
    class BST<Key extends Comparable<Key>, Value> {

        private class Node {

            Key key;
            Value value;
            Node left, right;
            int count;

            public Node(Key k, Value v) {
                key = k;
                value = v;
            }
        }
        private Node root;
        private int size = 0;

        public int size() {
            return size(root);
        }

        private int size(Node x) {
            if (x == null) {
                return 0;
            }
            return x.count;
        }

        public Value get(Key key) {
            Node x = root;
            while (x != null) {
                int cmp = key.compareTo(x.key);
                if (cmp < 0) {
                    x = x.left;
                } else if (cmp > 0) {
                    x = x.right;
                } else {
                    return x.value;
                }
            }
            return null;
        }

        public void put(Key k, Value v) {
            size++;
            root = put(root, k, v);
        }

        private Node put(Node root, Key key, Value value) {
            if (root == null) {
                return new Node(key, value);
            }
            int cmp = key.compareTo(root.key);
            if (cmp < 0) {
                root.left = put(root.left, key, value);
            } else if (cmp > 0) {
                root.right = put(root.right, key, value);
            } else

            {
                root.value = value;
            }
            root.count = 1 + size(root.left) + size(root.right);
            return root;
        }

        private Node leftMostNode(Node x) {
            if (x == null) {
                return null;
            }
            

            while (x.left != null) {
                x = x.left;
            }
            return x;
        }

        public Key smallestKey() {
            Node x = leftMostNode(root);
            return x == null ? null : x.key;
        }

        public Value smallestKeyValue() {
            Node x = leftMostNode(root);
            return x == null ? null : x.value;
        }

        private Node rightMostNode(Node x) {
            if (x == null) {
                return null;
            }
            

            while (x.right != null) {
                x = x.right;
            }
            return x;
        }

        public Key largestKey() {
            Node x = rightMostNode(root);
            return x == null ? null : x.key;
        }

        public Value largestKeyValue() {
            Node x = rightMostNode(root);
            return x == null ? null : x.value;
        }

        

        public Key floor(Key key) {
            

            

            Node x = root;
            Node floor = floor(x, key);
            return floor == null ? null : floor.key;
        }

        private Node floor(Node x, Key key) {
            if (x == null) {
                return null;
            }
            int cmp = key.compareTo(x.key);
            if (cmp == 0) {
                return x;
            } else if (cmp < 0) {
                return floor(x.left, key);
            }

            Node t = floor(x.right, key);
            if (t != null) {
                return t;
            } else {
                return x;
            }
        }

        public void deleteMin() {
            root = deleteMin(root);
        }

        private Node deleteMin(Node x) {
            if (x.left == null) {
                return x.right;
            }
            x.left = deleteMin(x.left);
            x.count = 1 + size(x.left) + size(x.right);
            return x;
        }

        public void delete(Key key) {
            root = delete(root, key);
        }

        private Node delete(Node x, Key key) {
            if (x == null) {
                return null;
            }
            int cmp = key.compareTo(x.key);
            if (cmp < 0) {
                x.left = delete(x.left, key);
            } else if (cmp > 0) {
                x.right = delete(x.right, key);
            } else {

                if (x.left == null) {
                    return x.right;
                }
                if (x.right == null) {
                    return x.left;
                }
                

                Node t = x;
                x = leftMostNode(t.right);
                x.right = deleteMin(t.right);
                x.left = t.left;
            }
            x.count = 1 + size(x.left) + size(x.right);
            return x;
        }
        


        public boolean isBinaryTreeBST() {
            return isBinaryBST(root, null, null);
        }

        private boolean isBinaryBST(Node root, Key min, Key max) {
            if (root == null) {
                return true;
            }
            boolean between = false;
            if (min == null && max == null) {
                between = true;
            } else if (min == null) {

                int cmp2 = root.key.compareTo(max);
                if (cmp2 < 0) {
                    between = true;
                }
            } else if (max == null) {
                int cmp1 = min.compareTo(root.key);
                if (cmp1 < 0) {
                    between = true;
                }
            } else {

                int cmp1 = min.compareTo(root.key);
                int cmp2 = root.key.compareTo(max);
                if (cmp1 < 0 && cmp2 < 0) {
                    between = true;
                }
            }
            if (!between) {
                return false;
            }
            return isBinaryBST(root.left, min, root.key) && isBinaryBST(root.right, root.key, max);
        }

        public Iterable<Key> keys() {
            ArrayDeque<Key> q = new ArrayDeque<>();
            inorder(root, q);
            return q;
        }

        private void inorder(Node x, ArrayDeque<Key> q) {
            if (x == null) {
                return;
            }
            if (x.left != null) {
                inorder(x.left, q);
            }
            q.addLast(x.key);
            if (x.right != null) {
                inorder(x.right, q);
            }
        }
    }

    
    class Heap {

        private int[] array;
        private int size;
        private int end;

        Heap(int size) {
            array = new int[size + 10];
            end = 0;
            this.size = size;
            Arrays.fill(array, -5);
        }

        
        private void swim(int k) {
            

            

            

            while (k > 1 && array[k / 2] <= array[k]) {
                int t = array[k / 2];
                array[k / 2] = array[k];
                array[k] = t;
                k = k / 2;
            }
        }

        public void insert(int value) {
            

            if (isFull()) {
                return;
            }
            array[++end] = value;
            swim(end);
        }

        private void sink(int k) {
            

            

            while (2 * k <= end) {
                int left = 2 * k;
                int right = 2 * k + 1;
                int swap = left;
                if (right <= end && array[right] > array[left]) {
                    swap = right;
                }
                

                if (array[k] > array[swap]) {
                    break;
                }
                int t = array[swap];
                array[swap] = array[k];
                array[k] = t;
                k = swap;
            }
        }

        public boolean isEmpty() {
            return end <= 0;
        }

        public boolean isFull() {
            return end >= size;
        }

        

        public int[] heapSort() {
            int[] sortedArray = new int[size];
            int curr = 0;
            while (!isEmpty()) {
                sortedArray[curr++] = deleteMax();
            }
            return sortedArray;
        }

        public int deleteMax() {
            

            if (isEmpty()) {
                return -1;
            }
            int value = array[1];
            

            array[1] = array[end];
            array[end] = -5;
            

            end--;
            

            sink(1);
            return value;
        }

        @Override
        public String toString() {
            return Arrays.toString(array);
        }
    }

    
    class QuickSort {

        
        void qsort(int[] a) {
            shuffle(a);
            

            


            

            quick3Sort(a, 0, a.length - 1);
        }

        void qsort(int[] a, int lo, int hi) {
            if (hi - lo <= 0) {
                return;
            }
            int m = (lo + hi) / 2;
            int t = a[m];
            a[m] = a[lo];
            a[lo] = t;

            int j = partition(a, lo, hi);
            qsort(a, lo, j - 1);
            qsort(a, j + 1, hi);
        }

        int partition(int[] a, int lo, int hi) {
            int i = lo;
            int j = hi + 1;
            while (true) {
                while (a[++i] < a[lo]) {
                    if (i >= hi) {
                        break;
                    }
                }

                while (a[--j] > a[lo]) {
                    if (j <= lo) {
                        break;
                    }
                }

                if (i >= j) {
                    break;
                }
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
            int t = a[lo];
            a[lo] = a[j];
            a[j] = t;
            return j;
        }

        
        void quick3Sort(int[] a, int lo, int hi) {
            if (hi - lo <= 0) {
                return;
            }
            int lt = lo, gt = hi;
            int i = lo;
            int v = a[lo];
            while (i <= gt) {
                int cmp = a[i] - v;
                if (cmp < 0) {
                    int t = a[lt];
                    a[lt] = a[i];
                    a[i] = t;
                    lt++;
                    i++;
                } else if (cmp > 0) {
                    int t = a[gt];
                    a[gt] = a[i];
                    a[i] = t;
                    gt--;
                } else {
                    i++;
                }
            }
            quick3Sort(a, lo, lt - 1);
            quick3Sort(a, gt + 1, hi);
        }

        
        int kthSelect(int[] a, int k) {
            int lo = 0;
            int hi = a.length - 1;
            shuffle(a);
            while (hi > lo) {
                int j = partition(a, lo, hi);
                if (j < k) {
                    lo = j + 1;
                } else if (j > k) {
                    hi = j - 1;
                } else {
                    return a[k];
                }
            }
            return a[k];
        }

        void shuffle(int[] a) {
            Random rnd = new Random();
            for (int i = 0; i < a.length; i++) {
                int j = rnd.nextInt(i + 1);
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    
    public class MergeSort {

        
        int inverse;

        void msort(int[] a) {
            int[] aux = new int[a.length];
            inverse = 0;
            inverse = msort(a, aux, 0, a.length - 1);
        }

        int msort(int[] a, int[] aux, int low, int high) {
            if (high - low <= 0) {
                return 0;
            }
            int mid = (low + high) / 2;
            int currInv = 0;
            currInv += msort(a, aux, low, mid);
            currInv += msort(a, aux, mid + 1, high);
            currInv += merge(a, aux, low, high, mid);
            return currInv;
        }

        int merge(int[] a, int[] aux, int low, int hi, int mid) {
            for (int i = low; i <= hi; i++) {
                aux[i] = a[i];
            }
            int cntInvr = 0;
            int i = low;
            int j = mid + 1;
            for (int k = low; k <= hi; k++) {
                if (i > mid) {
                    a[k] = aux[j++];
                } else if (j > hi) {
                    a[k] = aux[i++];
                } else if (aux[i] <= aux[j]) {
                    a[k] = aux[i++];
                } else {
                    a[k] = aux[j++];
                    cntInvr += (mid - i + 1);
                }
            }
            return cntInvr;
        }
    }

    
    Result minCostMaxFlow(int s, int t, ArrayList<Edge>[] g) {
        for (int i = 0; i < g.length; i++) {
            Collections.shuffle(g[i]);
        }
        int resFlow = 0, resCost = 0;
        int[] d = new int[g.length];
        Queue<Integer> q = new ArrayDeque<Integer>();
        Edge[] edgeUsed = new Edge[g.length];

        while (true) {
            Arrays.fill(d, Integer.MAX_VALUE);
            d[s] = 0;

            q.add(s);

            while (!q.isEmpty()) {
                int u = q.poll();
                for (Edge e : g[u]) {
                    if (e.cap - e.flow > 0 && d[u] + e.cost < d[e.v]) {
                        d[e.v] = d[u] + e.cost;
                        edgeUsed[e.v] = e;
                        q.add(e.v);
                    }
                }
            }
            if (d[t] == Integer.MAX_VALUE) {
                break;
            }

            ++resFlow;
            resCost += d[t];

            int ptr = t;
            while (ptr != s) {
                Edge e = edgeUsed[ptr];
                e.flow++;
                e.rev.flow--;
                ptr = e.u;
            }
        }
        return new Result(resCost, resFlow);
    }

    void merge(int a, int b) {
        a = get(a);
        b = get(b);
        if (a != b) {
            up[a] = b;
        }
    }

    int get(int a) {
        if (up[a] == a) {
            return a;
        }
        return up[a] = get(up[a]);










    }

    boolean isSorted(ArrayList<Integer> al) {
        int size = al.size();
        for (int i = 1; i < size - 2; i++) {
            if (al.get(i) > al.get(i + 1)) {
                return false;
            }
        }
        return true;
    }

    
    private void shuffle(int[] a, int N) {
        for (int i = 0; i < N; i++) {
            int r = i + (int) ((N - i) * Math.random());
            int t = a[i];
            a[i] = a[r];
            a[r] = t;
        }
    }

    
    
    public static void main(String[] args) {
        new Main().run();
    }

    public void run() {
        try {
            in = new BufferedReader(new FileReader("C-small-practice.in"));
            out = new PrintWriter(new BufferedWriter(new FileWriter("Main.out")));
            tok = null;
            solve();
            in.close();
            out.close();
            System.exit(0);
        } catch (IOException e) {

            try {
                in = new BufferedReader(new InputStreamReader(System.in));
                out = new PrintWriter(new OutputStreamWriter(System.out));
                tok = null;
                solve();
                in.close();
                out.close();
                System.exit(0);
            } catch (IOException ex) {
                System.out.println(ex.getMessage());
                System.exit(0);
            }
        }
    }

    private String nextToken() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
    BufferedReader in;
    StringTokenizer tok;
    PrintWriter out;
}
