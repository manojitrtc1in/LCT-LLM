import java.io.*;
import java.util.*;

public class f512d483d0ce56dde6a1f203b130fbaf_nc {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
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

    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        public Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Triple<T1, T2, T3> {
        T1 first;
        T2 second;
        T3 third;

        public Triple(T1 first, T2 second, T3 third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

    static class Quadruple<T1, T2, T3, T4> {
        T1 first;
        T2 second;
        T3 third;
        T4 fourth;

        public Quadruple(T1 first, T2 second, T3 third, T4 fourth) {
            this.first = first;
            this.second = second;
            this.third = third;
            this.fourth = fourth;
        }
    }

    static class Vector<T> {
        ArrayList<T> v;

        public Vector() {
            v = new ArrayList<>();
        }

        public void add(T x) {
            v.add(x);
        }

        public void add(int index, T x) {
            v.add(index, x);
        }

        public void remove(int index) {
            v.remove(index);
        }

        public void set(int index, T x) {
            v.set(index, x);
        }

        public T get(int index) {
            return v.get(index);
        }

        public int size() {
            return v.size();
        }

        public boolean isEmpty() {
            return v.isEmpty();
        }

        public void clear() {
            v.clear();
        }

        public boolean contains(T x) {
            return v.contains(x);
        }

        public int indexOf(T x) {
            return v.indexOf(x);
        }

        public int lastIndexOf(T x) {
            return v.lastIndexOf(x);
        }

        public void sort(Comparator<? super T> c) {
            Collections.sort(v, c);
        }

        public void reverse() {
            Collections.reverse(v);
        }

        public void shuffle() {
            Collections.shuffle(v);
        }

        public T[] toArray(T[] a) {
            return v.toArray(a);
        }

        public Object[] toArray() {
            return v.toArray();
        }

        public ArrayList<T> toArrayList() {
            return new ArrayList<>(v);
        }

        @Override
        public String toString() {
            return v.toString();
        }
    }

    static class Array<T> {
        T[] a;
        int n;

        public Array(int size) {
            a = (T[]) new Object[size];
            n = size;
        }

        public T get(int index) {
            return a[index];
        }

        public void set(int index, T x) {
            a[index] = x;
        }

        public int size() {
            return n;
        }
    }

    static class Map<K, V> {
        HashMap<K, V> map;

        public Map() {
            map = new HashMap<>();
        }

        public void put(K key, V value) {
            map.put(key, value);
        }

        public V get(K key) {
            return map.get(key);
        }

        public boolean containsKey(K key) {
            return map.containsKey(key);
        }

        public boolean containsValue(V value) {
            return map.containsValue(value);
        }

        public void remove(K key) {
            map.remove(key);
        }

        public int size() {
            return map.size();
        }

        public boolean isEmpty() {
            return map.isEmpty();
        }

        public void clear() {
            map.clear();
        }

        public Set<K> keySet() {
            return map.keySet();
        }

        public Collection<V> values() {
            return map.values();
        }

        public Set<Map.Entry<K, V>> entrySet() {
            return map.entrySet();
        }

        @Override
        public String toString() {
            return map.toString();
        }
    }

    static class PriorityQueue<T> {
        PriorityQueue<T> pq;
        Comparator<T> c;

        public PriorityQueue() {
            pq = new PriorityQueue<>();
        }

        public PriorityQueue(Comparator<T> c) {
            pq = new PriorityQueue<>(c);
        }

        public void add(T x) {
            pq.add(x);
        }

        public T remove() {
            return pq.remove();
        }

        public T peek() {
            return pq.peek();
        }

        public boolean isEmpty() {
            return pq.isEmpty();
        }

        public int size() {
            return pq.size();
        }

        public void clear() {
            pq.clear();
        }

        @Override
        public String toString() {
            return pq.toString();
        }
    }

    static class Stack<T> {
        Stack<T> s;

        public Stack() {
            s = new Stack<>();
        }

        public void push(T x) {
            s.push(x);
        }

        public T pop() {
            return s.pop();
        }

        public T peek() {
            return s.peek();
        }

        public boolean isEmpty() {
            return s.isEmpty();
        }

        public int size() {
            return s.size();
        }

        public void clear() {
            s.clear();
        }

        @Override
        public String toString() {
            return s.toString();
        }
    }

    static class Queue<T> {
        LinkedList<T> q;

        public Queue() {
            q = new LinkedList<>();
        }

        public void add(T x) {
            q.add(x);
        }

        public T remove() {
            return q.remove();
        }

        public T peek() {
            return q.peek();
        }

        public boolean isEmpty() {
            return q.isEmpty();
        }

        public int size() {
            return q.size();
        }

        public void clear() {
            q.clear();
        }

        @Override
        public String toString() {
            return q.toString();
        }
    }

    static class Deque<T> {
        ArrayDeque<T> dq;

        public Deque() {
            dq = new ArrayDeque<>();
        }

        public void addFirst(T x) {
            dq.addFirst(x);
        }

        public void addLast(T x) {
            dq.addLast(x);
        }

        public T removeFirst() {
            return dq.removeFirst();
        }

        public T removeLast() {
            return dq.removeLast();
        }

        public T getFirst() {
            return dq.getFirst();
        }

        public T getLast() {
            return dq.getLast();
        }

        public boolean isEmpty() {
            return dq.isEmpty();
        }

        public int size() {
            return dq.size();
        }

        public void clear() {
            dq.clear();
        }

        @Override
        public String toString() {
            return dq.toString();
        }
    }

    static class LinkedList<T> {
        Node<T> head;
        Node<T> tail;
        int size;

        public LinkedList() {
            head = null;
            tail = null;
            size = 0;
        }

        public void add(T x) {
            Node<T> newNode = new Node<>(x);
            if (isEmpty()) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                newNode.prev = tail;
                tail = newNode;
            }
            size++;
        }

        public void add(int index, T x) {
            if (index < 0 || index > size) {
                throw new IndexOutOfBoundsException();
            }
            if (index == 0) {
                addFirst(x);
            } else if (index == size) {
                addLast(x);
            } else {
                Node<T> newNode = new Node<>(x);
                Node<T> cur = getNode(index);
                Node<T> prev = cur.prev;
                prev.next = newNode;
                newNode.prev = prev;
                newNode.next = cur;
                cur.prev = newNode;
                size++;
            }
        }

        public void addFirst(T x) {
            Node<T> newNode = new Node<>(x);
            if (isEmpty()) {
                head = newNode;
                tail = newNode;
            } else {
                newNode.next = head;
                head.prev = newNode;
                head = newNode;
            }
            size++;
        }

        public void addLast(T x) {
            add(x);
        }

        public void remove(int index) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException();
            }
            if (index == 0) {
                removeFirst();
            } else if (index == size - 1) {
                removeLast();
            } else {
                Node<T> cur = getNode(index);
                Node<T> prev = cur.prev;
                Node<T> next = cur.next;
                prev.next = next;
                next.prev = prev;
                size--;
            }
        }

        public void removeFirst() {
            if (isEmpty()) {
                throw new NoSuchElementException();
            }
            if (size == 1) {
                head = null;
                tail = null;
            } else {
                head = head.next;
                head.prev = null;
            }
            size--;
        }

        public void removeLast() {
            if (isEmpty()) {
                throw new NoSuchElementException();
            }
            if (size == 1) {
                head = null;
                tail = null;
            } else {
                tail = tail.prev;
                tail.next = null;
            }
            size--;
        }

        public T get(int index) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException();
            }
            return getNode(index).data;
        }

        public T getFirst() {
            if (isEmpty()) {
                throw new NoSuchElementException();
            }
            return head.data;
        }

        public T getLast() {
            if (isEmpty()) {
                throw new NoSuchElementException();
            }
            return tail.data;
        }

        public void set(int index, T x) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException();
            }
            getNode(index).data = x;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public int size() {
            return size;
        }

        public void clear() {
            head = null;
            tail = null;
            size = 0;
        }

        private Node<T> getNode(int index) {
            Node<T> cur = head;
            for (int i = 0; i < index; i++) {
                cur = cur.next;
            }
            return cur;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            Node<T> cur = head;
            while (cur != null) {
                sb.append(cur.data).append(" ");
                cur = cur.next;
            }
            return sb.toString();
        }

        private static class Node<T> {
            T data;
            Node<T> prev;
            Node<T> next;

            public Node(T data) {
                this.data = data;
                this.prev = null;
                this.next = null;
            }
        }
    }

    static class Tree {
        int n;
        ArrayList<Integer>[] adj;

        public Tree(int n) {
            this.n = n;
            adj = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<>();
            }
        }

        public void addEdge(int u, int v) {
            adj[u].add(v);
            adj[v].add(u);
        }

        public int[] bfs(int start) {
            int[] dist = new int[n];
            Arrays.fill(dist, -1);
            dist[start] = 0;
            Queue<Integer> q = new LinkedList<>();
            q.add(start);
            while (!q.isEmpty()) {
                int u = q.remove();
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.add(v);
                    }
                }
            }
            return dist;
        }

        public int[] dfs(int start) {
            int[] dist = new int[n];
            Arrays.fill(dist, -1);
            dist[start] = 0;
            dfsUtil(start, -1, dist);
            return dist;
        }

        private void dfsUtil(int u, int p, int[] dist) {
            for (int v : adj[u]) {
                if (v != p) {
                    dist[v] = dist[u] + 1;
                    dfsUtil(v, u, dist);
                }
            }
        }
    }

    static class DisjointSet {
        int[] parent;
        int[] rank;

        public DisjointSet(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        public void union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) {
                return;
            }
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    static class SegmentTree {
        int[] st;
        int n;

        public SegmentTree(int[] a) {
            n = a.length;
            st = new int[4 * n];
            build(a, 1, 0, n - 1);
        }

        private void build(int[] a, int v, int tl, int tr) {
            if (tl == tr) {
                st[v] = a[tl];
            } else {
                int tm = (tl + tr) / 2;
                build(a, 2 * v, tl, tm);
                build(a, 2 * v + 1, tm + 1, tr);
                st[v] = merge(st[2 * v], st[2 * v + 1]);
            }
        }

        private int merge(int x, int y) {
            return x + y;
        }

        public int query(int l, int r) {
            return queryUtil(1, 0, n - 1, l, r);
        }

        private int queryUtil(int v, int tl, int tr, int l, int r) {
            if (l > r) {
                return 0;
            }
            if (l == tl && r == tr) {
                return st[v];
            }
            int tm = (tl + tr) / 2;
            int left = queryUtil(2 * v, tl, tm, l, Math.min(r, tm));
            int right = queryUtil(2 * v + 1, tm + 1, tr, Math.max(l, tm + 1), r);
            return merge(left, right);
        }

        public void update(int index, int newValue) {
            updateUtil(1, 0, n - 1, index, newValue);
        }

        private void updateUtil(int v, int tl, int tr, int index, int newValue) {
            if (tl == tr) {
                st[v] = newValue;
            } else {
                int tm = (tl + tr) / 2;
                if (index <= tm) {
                    updateUtil(2 * v, tl, tm, index, newValue);
                } else {
                    updateUtil(2 * v + 1, tm + 1, tr, index, newValue);
                }
                st[v] = merge(st[2 * v], st[2 * v + 1]);
            }
        }
    }

    static class FenwickTree {
        int[] bit;
        int n;

        public FenwickTree(int n) {
            this.n = n;
            bit = new int[n + 1];
        }

        public int sum(int r) {
            int res = 0;
            for (; r > 0; r -= r & -r) {
                res += bit[r];
            }
            return res;
        }

        public int sum(int l, int r) {
            return sum(r) - sum(l - 1);
        }

        public void add(int index, int delta) {
            for (; index <= n; index += index & -index) {
                bit[index] += delta;
            }
        }
    }

    static class MathUtil {
        static long gcd(long a, long b) {
            while (b != 0) {
                long t = b;
                b = a % b;
                a = t;
            }
            return a;
        }

        static long lcm(long a, long b) {
            return a / gcd(a, b) * b;
        }

        static long pow(long x, long n) {
            long res = 1;
            while (n > 0) {
                if ((n & 1) == 1) {
                    res *= x;
                }
                x *= x;
                n >>= 1;
            }
            return res;
        }

        static long pow(long x, long n, long mod) {
            x %= mod;
            long res = 1;
            while (n > 0) {
                if ((n & 1) == 1) {
                    res = res * x % mod;
                }
                x = x * x % mod;
                n >>= 1;
            }
            return res;
        }

        static long modInverse(long x, long mod) {
            return pow(x, mod - 2, mod);
        }

        static long[] generateFactorial(int n, long mod) {
            long[] fact = new long[n + 1];
            fact[0] = 1;
            for (int i = 1; i <= n; i++) {
                fact[i] = fact[i - 1] * i % mod;
            }
            return fact;
        }

        static long[] generateModInverseFactorial(int n, long mod) {
            long[] invFact = new long[n + 1];
            invFact[0] = 1;
            for (int i = 1; i <= n; i++) {
                invFact[i] = modInverse(invFact[i - 1] * i % mod, mod);
            }
            return invFact;
        }

        static long[] generatePow2(int n, long mod) {
            long[] pow2 = new long[n + 1];
            pow2[0] = 1;
            for (int i = 1; i <= n; i++) {
                pow2[i] = pow2[i - 1] * 2 % mod;
            }
            return pow2;
        }

        static long[] generateModInversePow2(int n, long mod) {
            long[] invPow2 = new long[n + 1];
            invPow2[0] = 1;
            long pow2 = pow(2, mod - 2, mod);
            for (int i = 1; i <= n; i++) {
                invPow2[i] = invPow2[i - 1] * pow2 % mod;
            }
            return invPow2;
        }

        static long[] generatePow(long x, int n, long mod) {
            long[] pow = new long[n + 1];
            pow[0] = 1;
            for (int i = 1; i <= n; i++) {
                pow[i] = pow[i - 1] * x % mod;
            }
            return pow;
        }

        static long[] generateModInversePow(long x, int n, long mod) {
            long[] invPow = new long[n + 1];
            invPow[0] = 1;
            long inv = modInverse(x, mod);
            for (int i = 1; i <= n; i++) {
                invPow[i] = invPow[i - 1] * inv % mod;
            }
            return invPow;
        }

        static long sum(long[] a) {
            long res = 0;
            for (long x : a) {
                res += x;
            }
            return res;
        }

        static long sum(int[] a) {
            long res = 0;
            for (int x : a) {
                res += x;
            }
            return res;
        }

        static double log(double x, double base) {
            return Math.log(x) / Math.log(base);
        }

        static double log(double x, int base) {
            return Math.log(x) / Math.log(base);
        }

        static double log(int x, double base) {
            return Math.log(x) / Math.log(base);
        }

        static double log(int x, int base) {
            return Math.log(x) / Math.log(base);
        }
    }

    static class StringUtil {
        static String reverse(String s) {
            return new StringBuilder(s).reverse().toString();
        }

        static boolean isPalindrome(String s) {
            int n = s.length();
            for (int i = 0; i < n / 2; i++) {
                if (s.charAt(i) != s.charAt(n - 1 - i)) {
                    return false;
                }
            }
            return true;
        }

        static String join(Collection<?> c, String delimiter) {
            StringBuilder sb = new StringBuilder();
            Iterator<?> itr = c.iterator();
            while (itr.hasNext()) {
                sb.append(itr.next());
                if (itr.hasNext()) {
                    sb.append(delimiter);
                }
            }
            return sb.toString();
        }
    }

    static class PairUtil {
        static <T1 extends Comparable<? super T1>, T2 extends Comparable<? super T2>> Pair<T1, T2> min(Pair<T1, T2> p1, Pair<T1, T2> p2) {
            if (p1.first.compareTo(p2.first) < 0) {
                return p1;
            }
            if (p1.first.compareTo(p2.first) > 0) {
                return p2;
            }
            if (p1.second.compareTo(p2.second) < 0) {
                return p1;
            }
            if (p1.second.compareTo(p2.second) > 0) {
                return p2;
            }
            return p1;
        }

        static <T1 extends Comparable<? super T1>, T2 extends Comparable<? super T2>> Pair<T1, T2> max(Pair<T1, T2> p1, Pair<T1, T2> p2) {
            if (p1.first.compareTo(p2.first) > 0) {
                return p1;
            }
            if (p1.first.compareTo(p2.first) < 0) {
                return p2;
            }
            if (p1.second.compareTo(p2.second) > 0) {
                return p1;
            }
            if (p1.second.compareTo(p2.second) < 0) {
                return p2;
            }
            return p1;
        }
    }

    static class ArrayUtil {
        static void swap(int[] a, int i, int j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

        static void swap(long[] a, int i, int j) {
            long temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

        static void swap(double[] a, int i, int j) {
            double temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

        static void swap(char[] a, int i, int j) {
            char temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

        static void reverse(int[] a) {
            int n = a.length;
            for (int i = 0; i < n / 2; i++) {
                swap(a, i, n - 1 - i);
            }
        }

        static void reverse(long[] a) {
            int n = a.length;
            for (int i = 0; i < n / 2; i++) {
                swap(a, i, n - 1 - i);
            }
        }

        static void reverse(double[] a) {
            int n = a.length;
            for (int i = 0; i < n / 2; i++) {
                swap(a, i, n - 1 - i);
            }
        }

        static void reverse(char[] a) {
            int n = a.length;
            for (int i = 0; i < n / 2; i++) {
                swap(a, i, n - 1 - i);
            }
        }

        static void sort(int[] a) {
            shuffle(a);
            Arrays.sort(a);
        }

        static void sort(long[] a) {
            shuffle(a);
            Arrays.sort(a);
        }

        static void sort(double[] a) {
            shuffle(a);
            Arrays.sort(a);
        }

        static void sort(char[] a) {
            shuffle(a);
            Arrays.sort(a);
        }

        static void sort(int[] a, int fromIndex, int toIndex) {
            int[] b = Arrays.copyOfRange(a, fromIndex, toIndex);
            sort(b);
            for (int i = fromIndex; i < toIndex; i++) {
                a[i] = b[i - fromIndex];
            }
        }

        static void sort(long[] a, int fromIndex, int toIndex) {
            long[] b = Arrays.copyOfRange(a, fromIndex, toIndex);
            sort(b);
            for (int i = fromIndex; i < toIndex; i++) {
                a[i] = b[i - fromIndex];
            }
        }

        static void sort(double[] a, int fromIndex, int toIndex) {
            double[] b = Arrays.copyOfRange(a, fromIndex, toIndex);
            sort(b);
            for (int i = fromIndex; i < toIndex; i++) {
                a[i] = b[i - fromIndex];
            }
        }

        static void sort(char[] a, int fromIndex, int toIndex) {
            char[] b = Arrays.copyOfRange(a, fromIndex, toIndex);
            sort(b);
            for (int i = fromIndex; i < toIndex; i++) {
                a[i] = b[i - fromIndex];
            }
        }

        static void shuffle(int[] a) {
            Random random = new Random();
            for (int i = 0; i < a.length; i++) {
                int j = random.nextInt(i + 1);
                swap(a, i, j);
            }
        }

        static void shuffle(long[] a) {
            Random random = new Random();
            for (int i = 0; i < a.length; i++) {
                int j = random.nextInt(i + 1);
                swap(a, i, j);
            }
        }

        static void shuffle(double[] a) {
            Random random = new Random();
            for (int i = 0; i < a.length; i++) {
                int j = random.nextInt(i + 1);
                swap(a, i, j);
            }
        }

        static void shuffle(char[] a) {
            Random random = new Random();
            for (int i = 0; i < a.length; i++) {
                int j = random.nextInt(i + 1);
                swap(a, i, j);
            }
        }
    }

    static class IOUtil {
        static void fastIO() {
            try {
                System.setIn(new FileInputStream("input.txt"));
                System.setOut(new PrintStream(new FileOutputStream("output.txt")));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        static void close() {
            System.out.close();
            System.err.close();
        }
    }

    static class Timer {
        long startTime;

        public Timer() {
            startTime = System.currentTimeMillis();
        }

        public long getTime() {
            return System.currentTimeMillis() - startTime;
        }
    }

    static class Debug {
        static void debug(Object... args) {
            System.err.println(Arrays.deepToString(args));
        }
    }

    static class Constants {
        static final int INF = (int) 1e9 + 7;
        static final long LINF = (long) 1e18 + 7;
        static final double EPS = 1e-9;
        static final double PI = Math.PI;
    }

    static class Settings {
        static final int STACK_SIZE = 1 << 23;
    }

    static class Template {
        static int solve() {
            int maxh = 0;
            int[] vid = new int[1010101];
            ArrayList<Integer>[] vec = new ArrayList[1010101];
            for (int i = 0; i < 1010101; i++) {
                vec[i] = new ArrayList<>();
            }
            int[] pr = new int[1010101];
            ArrayList<Integer> primes = new ArrayList<>();
            for (int i = 2; i < 1010101; i++) {
                if (pr[i] == 0) {
                    pr[i] = i;
                    primes.add(i);
                }
                for (int p : primes) {
                    if (p * i >= 1010101 || p > pr[i]) {
                        break;
                    }
                    pr[p * i] = p;
                }
                int cnt = 1;
                int x = i;
                while (pr[x] == pr[x / pr[x]]) {
                    cnt++;
                    x /= pr[x];
                }
                x /= pr[x];
                vec[i].addAll(vec[x]);
                vec[i].add(cnt);
                long h = calc(vec[i]);
                maxh = Math.max(maxh, h);
                if (vid[(int) h] == 0) {
                    vid[(int) h] = w.size();
                    w.add(vec[i]);
                }
            }
            int ws = w.size();
            ArrayList<Integer>[] g = new ArrayList[2020];
            for (int i = 0; i < 2020; i++) {
                g[i] = new ArrayList<>();
            }
            int[] dc = new int[2020];
            for (int i = 0; i < ws; i++) {
                ArrayList<Integer> cur = w.get(i);
                for (int j = 0; j < cur.size(); j++) {
                    ArrayList<Integer> t = new ArrayList<>(cur);
                    t.set(j, t.get(j) - 1);
                    addUsed(g[i], t);
                    t.set(j, t.get(j) + 2);
                    addUsed(g[i], t);
                }
                cur.add(1);
                addUsed(g[i], cur);
                Collections.sort(g[i]);
                int[] dc = new int[2020];
                for (int j = 0; j < used.size(); j++) {
                    if (dc[j] < 2020) {
                        dist[i][dc[j]] = Math.min(dist[i][dc[j]], dp[j]);
                    }
                }
            }
            for (int i = 0; i < ws; i++) {
                dist[i][0] = INF;
                for (int j = 0; j < i; j++) {
                    int res = INF;
                    for (int k = 0; k < 2020; k++) {
                        res = Math.min(res, dist[i][k] + dist[j][k]);
                    }
                    ans[i][j] = res;
                }
            }
            int n = in.nextInt();
            while (n-- > 0) {
                int a = in.nextInt();
                int b = in.nextInt();
                a = vid[a];
                b = vid[b];
                if (a < b) {
                    int t = a;
                    a = b;
                    b = t;
                }
                out.println(ans[a][b]);
            }
            return 0;
        }

        static long calc(ArrayList<Integer> v) {
            Collections.sort(v);
            long res = 0;
            for (int x : v) {
                res = res * 30 + x;
            }
            return res;
        }

        static void addUsed(ArrayList<Integer> v, ArrayList<Integer> t) {
            long x = calc(t);
            if (used.get(x) == null) {
                int sz = used.size();
                used.put(x, sz);
                assert w.size() == sz;
                w.add(t);
                dc[sz] = calcd(t);
            }
            v.add(used.get(x));
        }

        static int calcd(ArrayList<Integer> v) {
            int res = 1;
            for (int x : v) {
                res *= x + 1;
            }
            return res;
        }
    }

    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        Template.solve();
        out.close();
    }
}
