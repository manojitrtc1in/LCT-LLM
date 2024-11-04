import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static PrintWriter out = new PrintWriter(System.out);
    static DecimalFormat df = new DecimalFormat("0.0000000");
    final static int mod = (int) (1e9 + 7);
    final static int MAX = Integer.MAX_VALUE;
    final static int MIN = Integer.MIN_VALUE;
    static Random rand = new Random();
    static int[] s = new int[2010];

    


    public static void main(String[] args) throws IOException {
        

    	
        int t = readInt();
        

        preprocess();
        while (t-- > 0) {
            solve();
        }
        out.flush();


    }

    private static void solve() throws IOException {
        int blen = readInt();
        int k = readInt();
        k = Math.min(k , 13*blen);
        int[] b = new int[blen+1];
        int[] c = new int[blen+1];
        for(int i = 1 ; i <= blen ; i++){
        	b[i] = readInt();
        }
        for(int i = 1 ; i <= blen; i++){
        	c[i] = readInt();
        }
        out.println(deal(blen , b , k , c));
    }

    static int deal(int blen , int[] b , int k , int[] c) {
    	

        int[] dp = new int[k+1];
        for(int i = 1 ; i <= blen ; i++){
        	for(int j = k ; j >= s[b[i]] ; j--){
        		
        		dp[j] = Math.max(dp[j] , dp[j-s[b[i]]] + c[i]);
        		
        	}
        }
        return dp[k];
        
    }

    private static void preprocess() {
		Arrays.fill(s , 1001);
        s[1] = 0;
        for(int i = 1 ; i < 1000 ; i++){
            for(int j = 1 ; j <= i ; j++){

                s[i+i/j] = Math.min(s[i+i/j] , s[i]+1);

            }
        }
    }

    

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(readLine());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readString() throws IOException {
        return next();
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }

    static int[] readIntArray(int n) throws IOException {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = readInt();
        return arr;
    }

    static int[][] read2DIntArray(int n, int m) throws IOException {
        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++)
            arr[i] = readIntArray(m);
        return arr;
    }

    static List<Integer> readIntList(int n) throws IOException {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(readInt());
        return list;
    }

    static long[] readLongArray(int n) throws IOException {
        long[] arr = new long[n];
        for (int i = 0; i < n; i++)
            arr[i] = readLong();
        return arr;
    }

    static long[][] read2DLongArray(int n, int m) throws IOException {
        long[][] arr = new long[n][m];
        for (int i = 0; i < n; i++)
            arr[i] = readLongArray(m);
        return arr;
    }

    static List<Long> readLongList(int n) throws IOException {
        List<Long> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(readLong());
        return list;
    }

    static char[] readCharArray(int n) throws IOException {
        return readString().toCharArray();
    }

    static char[][] readMatrix(int n, int m) throws IOException {
        char[][] mat = new char[n][m];
        for (int i = 0; i < n; i++)
            mat[i] = readCharArray(m);
        return mat;
    }

    


    private static void printIList(List<Integer> list) {
        for (int i = 0; i < list.size(); i++)
            out.print(list.get(i) + " ");
        out.println(" ");
    }

    private static void printLList(List<Long> list) {
        for (int i = 0; i < list.size(); i++)
            out.print(list.get(i) + " ");
        out.println(" ");
    }

    private static void printIArray(int[] arr) {
        for (int i = 0; i < arr.length; i++)
            out.print(arr[i] + " ");
        out.println(" ");
    }

    private static void print2DIArray(int[][] arr) {
        for (int i = 0; i < arr.length; i++)
            printIArray(arr[i]);
    }

    private static void printLArray(long[] arr) {
        for (int i = 0; i < arr.length; i++)
            out.print(arr[i] + " ");
        out.println(" ");
    }

    private static void print2DLArray(long[][] arr) {
        for (int i = 0; i < arr.length; i++)
            printLArray(arr[i]);
    }

    


    private static boolean isInteger(String s) {
        try {
            Integer.parseInt(s);
        } catch (NumberFormatException e) {
            return false;
        } catch (NullPointerException e) {
            return false;
        }
        return true;
    }

    private static boolean isLong(String s) {
        try {
            Long.parseLong(s);
        } catch (NumberFormatException e) {
            return false;
        } catch (NullPointerException e) {
            return false;
        }
        return true;
    }

    


    private static void sort(int[] arr) {
        int n = arr.length;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(arr[i]);
        Collections.sort(list);
        for (int i = 0; i < n; i++)
            arr[i] = list.get(i);
    }

    private static void reverseSort(int[] arr) {
        int n = arr.length;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(arr[i]);
        Collections.sort(list, Collections.reverseOrder());
        for (int i = 0; i < n; i++)
            arr[i] = list.get(i);
    }

    private static void sort(long[] arr) {
        int n = arr.length;
        List<Long> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(arr[i]);
        Collections.sort(list);
        for (int i = 0; i < n; i++)
            arr[i] = list.get(i);
    }

    private static void reverseSort(long[] arr) {
        int n = arr.length;
        List<Long> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(arr[i]);
        Collections.sort(list, Collections.reverseOrder());
        for (int i = 0; i < n; i++)
            arr[i] = list.get(i);
    }

    


    private static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    private static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    private static int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    private static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    private static long power(long a, long b) {
        if (b == 0)
            return 1L;
        long ans = power(a, b >> 1);
        ans *= ans;
        if ((b & 1) == 1)
            ans *= a;
        return ans;
    }

    private static int mod_power(int a, int b) {
        if (b == 0)
            return 1;
        int temp = mod_power(a, b / 2);
        temp %= mod;
        temp = (int) ((1L * temp * temp) % mod);
        if ((b & 1) == 1)
            temp = (int) ((1L * temp * a) % mod);
        return temp;
    }

    private static int multiply(int a, int b) {
        return (int) ((((1L * a) % mod) * ((1L * b) % mod)) % mod);
    }

    private static boolean isPrime(long n) {
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    private static long nCr(long n, long r) {
        if (n - r > r)
            r = n - r;
        long ans = 1L;
        for (long i = r + 1; i <= n; i++)
            ans *= i;
        for (long i = 2; i <= n - r; i++)
            ans /= i;
        return ans;
    }

    


    private static List<Integer> getPrime(int n) {
        boolean[] prime = new boolean[n + 1];
        Arrays.fill(prime, true);
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    prime[j] = false;
            }
        }
        

        List<Integer> list = new ArrayList<>();
        for (int i = 2; i <= n; i++)
            if (prime[i])
                list.add(i);
        return list;
    }

    private static int[] SeivePrime() {
        int n = (int) 1e6 + 1;
        int[] primes = new int[n];
        for (int i = 0; i < n; i++)
            primes[i] = i;
        for (int i = 2; i * i < n; i++) {
            if (primes[i] != i)
                continue;
            for (int j = i * i; j < n; j += i) {
                if (primes[j] == j)
                    primes[j] = i;
            }
        }
        return primes;
    }

    


    private static boolean isPalindrome(String str) {
        int i = 0, j = str.length() - 1;
        while (i < j)
            if (str.charAt(i++) != str.charAt(j--))
                return false;
        return true;
    }

    private static String reverseString(String str) {
        StringBuilder sb = new StringBuilder(str);
        return sb.reverse().toString();
    }

    private static String sortString(String str) {
        int[] arr = new int[256];
        for (char ch : str.toCharArray())
            arr[ch]++;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 256; i++)
            while (arr[i]-- > 0)
                sb.append((char) i);
        return sb.toString();
    }

    


    private static int LIS(int arr[], int n) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int idx = find(list, arr[i]);
            if (idx < list.size())
                list.set(idx, arr[i]);
            else
                list.add(arr[i]);
        }
        return list.size();
    }

    private static int find(List<Integer> list, int val) {
        int ret = list.size(), i = 0, j = list.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (list.get(mid) >= val) {
                ret = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return ret;
    }

    private static int LNDS(int[] arr, int n) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int idx = find2(list, arr[i]);
            if (idx < list.size())
                list.set(idx, arr[i]);
            else
                list.add(arr[i]);
        }
        return list.size();
    }

    private static int find2(List<Integer> list, int val) {
        int ret = list.size(), i = 0, j = list.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (list.get(mid) <= val) {
                i = mid + 1;
            } else {
                ret = mid;
                j = mid - 1;
            }
        }
        return ret;
    }

    


    private static int find(int x, int[] parent) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x], parent);
    }

    private static boolean union(int x, int y, int[] parent, int[] rank) {
        int lx = find(x, parent), ly = find(y, parent);
        if (lx == ly)
            return true;
        if (rank[lx] > rank[ly])
            parent[ly] = lx;
        else if (rank[lx] < rank[ly])
            parent[lx] = ly;
        else {
            parent[lx] = ly;
            rank[ly]++;
        }
        return false;
    }

    


    public static class SegmentTree {
        int n;
        int[] arr, tree, lazy;

        SegmentTree(int arr[]) {
            this.arr = arr;
            this.n = arr.length;
            this.tree = new int[(n << 2)];
            this.lazy = new int[(n << 2)];
            build(1, 0, n - 1);
        }

        void build(int id, int start, int end) {
            if (start == end)
                tree[id] = arr[start];
            else {
                int mid = (start + end) / 2, left = (id << 1), right = left + 1;
                build(left, start, mid);
                build(right, mid + 1, end);
                tree[id] = tree[left] + tree[right];
            }
        }

        void update(int l, int r, int val) {
            update(1, 0, n - 1, l, r, val);
        }

        void update(int id, int start, int end, int l, int r, int val) {
            distribute(id, start, end);
            if (end < l || r < start)
                return;
            if (start == end)
                tree[id] += val;
            else if (l <= start && end <= r) {
                lazy[id] += val;
                distribute(id, start, end);
            } else {
                int mid = (start + end) / 2, left = (id << 1), right = left + 1;
                update(left, start, mid, l, r, val);
                update(right, mid + 1, end, l, r, val);
                tree[id] = tree[left] + tree[right];
            }
        }

        int query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }

        int query(int id, int start, int end, int l, int r) {
            if (end < l || r < start)
                return 0;
            distribute(id, start, end);
            if (start == end)
                return tree[id];
            else if (l <= start && end <= r)
                return tree[id];
            else {
                int mid = (start + end) / 2, left = (id << 1), right = left + 1;
                return query(left, start, mid, l, r) + query(right, mid + 1, end, l, r);
            }
        }

        void distribute(int id, int start, int end) {
            if (start == end)
                tree[id] += lazy[id];
            else {
                tree[id] += lazy[id] * (end - start + 1);
                lazy[(id << 1)] += lazy[id];
                lazy[(id << 1) + 1] += lazy[id];
            }
            lazy[id] = 0;
        }
    }

    


    static class Trie {
        class Node {
            Node[] children;
            boolean isEnd;

            Node() {
                children = new Node[26];
            }
        }

        Node root;

        Trie() {
            root = new Node();
        }

        public void insert(String word) {
            Node curr = root;
            for (char ch : word.toCharArray()) {
                if (curr.children[ch - 'a'] == null)
                    curr.children[ch - 'a'] = new Node();
                curr = curr.children[ch - 'a'];
            }
            curr.isEnd = true;
        }

        public boolean find(String word) {
            Node curr = root;
            for (char ch : word.toCharArray()) {
                if (curr.children[ch - 'a'] == null)
                    return false;
                curr = curr.children[ch - 'a'];
            }
            return curr.isEnd;
        }
    }

    


    static class FT {
        long[] tree;
        int n;

        FT(int[] arr, int n) {
            this.n = n;
            this.tree = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                update(i, arr[i - 1]);
            }
        }

        void update(int idx, int val) {
            while (idx <= n) {
                tree[idx] += val;
                idx += idx & -idx;
            }
        }

        long query(int l, int r) {
            return getSum(r) - getSum(l - 1);
        }

        long getSum(int idx) {
            long ans = 0L;
            while (idx > 0) {
                ans += tree[idx];
                idx -= idx & -idx;
            }
            return ans;
        }
    }

    


    static class BIT {
        long[][] tree;
        int n, m;

        BIT(int[][] mat, int n, int m) {
            this.n = n;
            this.m = m;
            tree = new long[n + 1][m + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    update(i, j, mat[i - 1][j - 1]);
                }
            }
        }

        void update(int x, int y, int val) {
            while (x <= n) {
                int t = y;
                while (t <= m) {
                    tree[x][t] += val;
                    t += t & -t;
                }
                x += x & -x;
            }
        }

        long query(int x1, int y1, int x2, int y2) {
            return getSum(x2, y2) - getSum(x1 - 1, y2) - getSum(x2, y1 - 1) + getSum(x1 - 1, y1 - 1);
        }

        long getSum(int x, int y) {
            long ans = 0L;
            while (x > 0) {
                int t = y;
                while (t > 0) {
                    ans += tree[x][t];
                    t -= t & -t;
                }
                x -= x & -x;
            }
            return ans;
        }
    }

    


    static class Pair implements Comparable<Pair> {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair o) {
            return this.first - o.first;
        }
    }

    static class DequeNode {
        DequeNode prev, next;
        int val;

        DequeNode(int val) {
            this.val = val;
        }

        DequeNode(int val, DequeNode prev, DequeNode next) {
            this.val = val;
            this.prev = prev;
            this.next = next;
        }
    }
}