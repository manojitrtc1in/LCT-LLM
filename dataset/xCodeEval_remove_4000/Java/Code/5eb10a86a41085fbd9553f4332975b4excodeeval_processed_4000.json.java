import java.io.*;
import java.util.*;
import java.lang.*;

public class codeforces {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        if (System.getProperty("ONLINE_JUDGE") == null) {
            long startTime = System.currentTimeMillis();
            try {
                sc = new InputReader(new FileInputStream("input.txt"));
                out = new PrintWriter(new FileOutputStream("output.txt"));
                pr = new PrintWriter(new FileOutputStream("error.txt"));
            } catch (Exception ignored) {
            }
            int t = 1;
            int tt = t;
            t = sc.nextInt();
            while (t-- > 0) {
                solve();
            }
            long endTime = System.currentTimeMillis();
            System.out.println("Time: " + (endTime - startTime) / tt + " ms");
            out.flush();
            pr.flush();

        } else {
            sc = new InputReader(inputStream);
            out = new PrintWriter(outputStream);
            pr = new PrintWriter(outputStream);
            int t = 1;
            t = sc.nextInt();
            while (t-- > 0) {
                solve();
            }
            out.flush();
        }
    }

    public static void solve() {
        int n = sc.nextInt();
        long[] arr = new long[n];
        arrInput(arr, n);
        long id15 = 0, id3 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                id15 = gcd(arr[i], id15);
            } else {
                id3 = gcd(arr[i], id3);
            }
        }
        boolean f1 = true, f2 = true;
        for(int i = 0; i < n; i += 2){
			id15 = gcd(id15, arr[i]);
		}
		for(int i = 1; i < n; i += 2){
			id3 = gcd(id3, arr[i]);
		}
		for(int i = 0; i < n; i += 2){
			if(arr[i] % id3 == 0){
				f1 = false;
			}
		}
		for(int i = 1; i < n; i += 2){
			if(arr[i] % id15 == 0){
				f2 = false;
			}
		}
        if (!f1 && !f2)
            out.println(0);
        else if (!f2)
            out.println(id3);
        else
            out.println(id15);
    }

    
    

    

    


    

    


    


    public static int inf = Integer.MAX_VALUE;
    public static int minf = Integer.MIN_VALUE;
    public static long linf = 1L << 62;
    public static long mod = 998244353;
    public static InputReader sc;
    public static PrintWriter out;
    public static PrintWriter pr;
    public static String yes = "YES";
    public static String no = "NO";

    


    static class Pair {
        long f, s;

        Pair(long x, long y) {
            this.f = x;
            this.s = y;
        }
    }

    


    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
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
    }

    


    static class Node {
        int key;
        Node left, right;

        Node(int key) {
            this.key = key;
            left = null;
            right = null;
        }

    }

    static Node insertBST(Node root, int val) {
        if (root == null)
            return new Node(val);
        if (val < root.key)
            root.left = insertBST(root.left, val);
        else
            root.right = insertBST(root.right, val);
        return root;
    }

    static class Height {
        int height = 0;
    }

    static boolean isBalanced(Node root, Height height) {
        if (root == null) {
            height.height = 0;
            return true;
        }
        Height lheight = new Height(), rheight = new Height();
        boolean l = isBalanced(root.left, lheight);
        boolean r = isBalanced(root.right, rheight);
        int lh = lheight.height, rh = rheight.height;
        height.height = (lh > rh ? lh : rh) + 1;
        if (Math.abs(lh - rh) >= 2)
            return false;
        else
            return l && r;
    }

    static void dfs(int root, ArrayList<ArrayList<Integer>> edges, int parent) {
        out.print(root + 1 + " ");
        for (int i : edges.get(root)) {
            if (i != parent) {
                dfs(i, edges, root);
            }
        }
    }

    static Node LCA(Node root, int n1, int n2) {
        if (root == null)
            return null;
        if (root.key == n1 || n2 == root.key)
            return root;

        Node llca = LCA(root.left, n1, n2);
        Node rlca = LCA(root.right, n1, n2);

        if (llca != null && null != rlca)
            return root;
        return llca != null ? llca : rlca;
    }

    static int finddist(Node root, int k, int dist) {
        if (root == null)
            return -1;
        if (root.key == k)
            return dist;
        int left = finddist(root.left, k, 1 + dist);
        if (left != -1)
            return left;
        return finddist(root.right, k, dist + 1);
    }

    static int id11(Node root, int n1, int n2) {
        Node lca = LCA(root, n1, n2);
        int d1 = finddist(lca, n1, 0);
        int d2 = finddist(lca, n2, 0);
        return d1 + d2;
    }

    

    public static int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    public static int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    public static long gcd(long a, long b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    public static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    public static long nCr(int n, int r) {
        return fact(n) / (fact(r) * fact(n - r));
    }

    public static long fact(int n) {
        int res = 1;
        for (int i = 2; i <= n; i++)
            res = res * i;
        return res;
    }

    public static long[] fact = new long[(int) 2e5 + 1];

    public static void calc_fact() {
        fact[0] = 1;
        for (int i = 1; i < 2e5 + 1; i++)
            fact[i] = (i * fact[i - 1]) % mod;
    }

    public static long modpow(long x, long n) {
        if (n == 0)
            return 1 % mod;
        long u = modpow(x, n / 2);
        u = (u * u) % mod;
        if ((n & 1) != 0)
            u = (u * x) % mod;
        return u;
    }

    public static long inverse(long x) {
        return modpow(x, mod - 2);
    }

    public static long BC(long n, long k) {
        return ((fact[(int) n] * inverse(fact[(int) n - (int) k])) % mod * inverse(fact[(int) k]) % mod);
    }

    public static long nCr(long n, long r) {
        return fact(n) / (fact(r) * fact(n - r));
    }

    public static long fact(long n) {
        int res = 1;
        for (int i = 2; i <= n; i++)
            res = res * i;
        return res;
    }

    public static String reverseString(String input) {
        StringBuilder str = new StringBuilder("");

        for (int i = input.length() - 1; i >= 0; i--) {
            str.append(input.charAt(i));
        }
        return str.toString();
    }

    public static int id12(int x, int y, int z) {
        return Math.max(x, Math.max(y, z));
    }

    public static int id13(int x, int y, int z) {
        return Math.min(x, Math.min(y, z));
    }

    public static long id12(long x, long y, long z) {
        return Math.max(x, Math.max(y, z));
    }

    public static long id13(long x, long y, long z) {
        return Math.min(x, Math.min(y, z));
    }

    public static void arrInput(int[] arr, int n) {
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
    }

    public static void arrInput(long[] arr, int n) {
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextLong();
    }

    public static void arrInput(Pair[] pair, int n) {
        for (int i = 0; i < n; i++)
            pair[i] = new Pair(sc.nextInt(), sc.nextInt());
    }

    public static int lowerBound(int[] arr, int x) {
        int l = -1, r = arr.length;
        while (l + 1 < r) {
            int m = (l + r) >>> 1;
            if (arr[m] >= x)
                r = m;
            else
                l = m;
        }
        return r;
    }

    public static int upperBound(int[] arr, int x) {
        int l = -1, r = arr.length;
        while (l + 1 < r) {
            int m = (l + r) >>> 1;
            if (arr[m] <= x)
                l = m;
            else
                r = m;
        }
        return l + 1;
    }

    public static void fill(char[][] arr, char c) {
        int n = arr.length, m = arr[0].length;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = c;
    }

    public static void fill(int[][] arr, int c) {
        int n = arr.length, m = arr[0].length;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = c;
    }

    public static void fill(long[][] arr, long c) {
        int n = arr.length, m = arr[0].length;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = c;
    }

    public static void fillPrime(ArrayList<Integer> chprime, int high) {
        boolean[] ck = new boolean[high + 1];
        Arrays.fill(ck, true);
        ck[1] = false;
        ck[0] = false;

        for (int i = 2; (i * i) <= high; i++) {
            if (ck[i] == true) {
                for (int j = i * i; j <= high; j = j + i) {
                    ck[j] = false;
                }
            }
        }
        for (int i = 2; i * i <= high; i++) {
            if (ck[i] == true) {
                chprime.add(i);
            }
        }
    }

    public static void id6(int low, int high) {
        ArrayList<Integer> chprime = new ArrayList<Integer>();
        fillPrime(chprime, high);

        boolean[] prime = new boolean[high - low + 1];
        Arrays.fill(prime, true);
        for (int i : chprime) {
            int lower = (low / i);
            if (lower <= 1) {
                lower = i + i;
            } else if (low % i != 0) {
                lower = (lower * i) + i;
            } else {
                lower = (lower * i);
            }
            for (int j = lower; j <= high; j = j + i) {
                prime[j - low] = false;
            }
        }
        for (int i = low; i <= high; i++) {
            if (prime[i - low] == true) {
                primeNo.add(i);
            }
        }
    }

    public static ArrayList<Integer> primeNo = new ArrayList<>();

    public static void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[] = new int[n1];
        int R[] = new int[n2];
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] >= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    public static void id0(int arr[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            id0(arr, l, m);
            id0(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    public static void merge(long arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        long L[] = new long[n1];
        long R[] = new long[n2];
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] >= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    public static void id0(long arr[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            id0(arr, l, m);
            id0(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    public static void sort(int[] arr) {
        Arrays.sort(arr);
    }

    public static void sort(long[] arr) {
        Arrays.sort(arr);
    }

    public static void sort(ArrayList<Integer> list) {
        Collections.sort(list);
    }

    public static long sumint(int n) {
        long ans = 0;
        char[] s = String.valueOf(n).toCharArray();
        for (int i = 0; i < s.length; ++i)
            ans += s[i] - '0';
        return ans;
    }

    public static long sumint(long n) {
        long ans = 0;
        char[] s = String.valueOf(n).toCharArray();
        for (int i = 0; i < s.length; ++i)
            ans += s[i] - '0';
        return ans;
    }

    public static void arrInput(ArrayList<Integer> list, int n) {
        for (int i = 0; i < n; i++) {
            list.add(sc.nextInt());
        }
    }

    public static void id4(ArrayList<Long> list, int n) {
        for (int i = 0; i < n; i++) {
            list.add(sc.nextLong());
        }
    }

    


    public static void debug() {
        if (sysFlag)
            pr.println("");
    }

    public static boolean sysFlag = System.getProperty("ONLINE_JUDGE") == null;

    public static void debug(int[][] dp) {
        if (sysFlag) {
            for (int i = 0; i < dp.length; ++i) {
                pr.print(i + "--> ");
                for (int j = 0; j < dp[0].length; ++j) {
                    pr.print(dp[i][j] + " ");
                }
                pr.println("");
            }
        }
    }

    public static void debug(char[][] arr) {
        if (sysFlag) {
            for (int i = 0; i < arr.length; ++i) {
                for (int j = 0; j < arr[0].length; ++j) {
                    pr.print(arr[i][j]);
                }
                pr.println("");
            }
        }
    }

    public static void debug(long[][] dp) {
        if (sysFlag) {
            for (int i = 0; i < dp.length; ++i) {
                pr.print(i + "--> ");
                for (int j = 0; j < dp[0].length; ++j) {
                    pr.print(dp[i][j] + " ");
                }
                pr.println("");
            }
        }
    }

    public static void debug(int x) {
        if (sysFlag)
            pr.println("Int-Ele: " + x);
    }

    public static void debug(String x) {
        if (sysFlag)
            pr.println("String: " + x);
    }

    public static void debug(char x) {
        if (sysFlag)
            pr.println("Char: " + x);
    }

    public static void debug(long x) {
        if (sysFlag)
            pr.println("Long-Ele: " + x);
    }

    public static void debug(int[] arr) {
        if (sysFlag) {
            for (int i = 0; i < arr.length; ++i) {
                pr.println(i + " -> " + arr[i]);
            }
        }
    }

    public static void debug(char[] arr) {
        if (sysFlag) {
            for (int i = 0; i < arr.length; ++i) {
                pr.println(i + " -> " + arr[i]);
            }
        }
    }

    public static void debug(long[] arr) {
        if (sysFlag) {
            for (int i = 0; i < arr.length; ++i) {
                pr.println(i + " -> " + arr[i]);
            }
        }
    }

    public static void debug(ArrayList<Integer> list) {
        if (sysFlag) {
            for (int i = 0; i < list.size(); ++i) {
                pr.println(i + " -> " + list.get(i));
            }
        }
    }

    public static void Ldebug(ArrayList<Long> list) {
        if (sysFlag) {
            for (int i = 0; i < list.size(); ++i) {
                pr.println(i + " -> " + list.get(i));
            }
        }
    }

    public static void id2(HashMap<Integer, Integer> map) {
        if (sysFlag) {
            for (Map.Entry<Integer, Integer> entry : map.entrySet())
                pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
        }
    }

    public static void id5(HashMap<Long, Integer> map) {
        if (sysFlag) {
            for (Map.Entry<Long, Integer> entry : map.entrySet())
                pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
        }
    }

    public static void id7(HashMap<Long, Long> map) {
        if (sysFlag) {
            for (Map.Entry<Long, Long> entry : map.entrySet())
                pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
        }
    }

    public static void id10(HashMap<Integer, Long> map) {
        if (sysFlag) {
            for (Map.Entry<Integer, Long> entry : map.entrySet())
                pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
        }
    }

    public static void id8(HashMap<String, Long> map) {
        if (sysFlag) {
            for (Map.Entry<String, Long> entry : map.entrySet())
                pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
        }
    }

    public static void id9(HashMap<Character, Long> map) {
        if (sysFlag) {
            for (Map.Entry<Character, Long> entry : map.entrySet())
                pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
        }
    }

    public static void id1(HashMap<String, Integer> map) {
        if (sysFlag) {
            for (Map.Entry<String, Integer> entry : map.entrySet())
                pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
        }
    }

    public static void id14(HashMap<Character, Integer> map) {
        if (sysFlag) {
            for (Map.Entry<Character, Integer> entry : map.entrySet())
                pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
        }
    }

    public static void debug(Set<Integer> set) {
        if (sysFlag) {
            Iterator value = set.iterator();
            int i = 1;
            while (value.hasNext()) {
                pr.println((i++) + "-> " + value.next());
            }
        }
    }

    public static void debug(Pair[] pair, int n) {
        if (sysFlag) {
            for (int i = 0; i < n; i++) {
                pr.println("first:" + pair[i].f + " second:" + pair[i].s);
            }
        }
    }
}
