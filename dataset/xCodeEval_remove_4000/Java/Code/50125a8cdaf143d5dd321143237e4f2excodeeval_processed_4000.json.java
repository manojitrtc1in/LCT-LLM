

import java.util.*;
import java.io.*;
import java.lang.*;

public class practice {
    static FastInput scn;
    static PrintWriter out;
    final static int MOD = (int) (1e9 + 7);
    final static int MAX = Integer.MAX_VALUE;
    final static int MIN = Integer.MIN_VALUE;

    

    public static void main(String[] args) throws IOException {
        scn = new FastInput();
        out = new PrintWriter(System.out);
        int t = 1;
        t = scn.nextInt();
        while (t-- > 0) {
            solve();
        }
        out.flush();
    }

    private static void solve() throws IOException {
        int n = scn.nextInt(), m = scn.nextInt(), sx = scn.nextInt(), sy = scn.nextInt(), d = scn.nextInt();
        


        


        

        
        if (Math.abs(n - sx) + Math.abs(m - sy) <= d) {
            out.println(-1);
            return;
        }

        if ((sx - 1 > d && m - sy > d) || (n - sx > d && sy - 1 > d)) {
            out.println(n + m - 2);
        } else {
            out.println(-1);
        }

        
    }
    

    

    static class Pair implements Comparable<Pair> {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        Pair(Pair o) {
            this.first = o.first;
            this.second = o.second;
        }

        public int compareTo(Pair o) {
            return this.first - o.first;
        }

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

    

    private static void fastSort(int[] arr) {
        int n = arr.length;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(arr[i]);
        Collections.sort(list);
        for (int i = 0; i < n; i++)
            arr[i] = list.get(i);
    }

    private static void id3(int[] arr) {
        int n = arr.length;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(arr[i]);
        Collections.sort(list, Collections.reverseOrder());
        for (int i = 0; i < n; i++)
            arr[i] = list.get(i);
    }

    private static void fastSort(long[] arr) {
        int n = arr.length;
        List<Long> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(arr[i]);
        Collections.sort(list);
        for (int i = 0; i < n; i++)
            arr[i] = list.get(i);
    }

    private static void id3(long[] arr) {
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
        long ans = power(a, b / 2);
        ans *= ans;
        if ((b & 1) == 1)
            ans *= a;
        return ans;
    }

    private static int mod_power(int a, int b) {
        if (b == 0)
            return 1;
        int temp = mod_power(a, b / 2);
        temp %= MOD;
        temp = (int) ((1L * temp * temp) % MOD);
        if ((b & 1) == 1)
            temp = (int) ((1L * temp * a) % MOD);
        return temp;
    }

    private static int multiply(int a, int b) {
        return (int) ((((1L * a) % MOD) * ((1L * b) % MOD)) % MOD);
    }

    private static boolean isPrime(int n) {
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    private static boolean isPrime(long n) {
        for (long i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
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

    

    private static int LIS(int arr[]) {
        int n = arr.length;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int idx = find1(list, arr[i]);
            if (idx < list.size()) {
                list.set(idx, arr[i]);
            } else {
                list.add(arr[i]);
            }
        }
        return list.size();
    }

    private static int find1(List<Integer> list, int val) {
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

    private static int LNDS(int[] arr) {
        int n = arr.length;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int idx = find2(list, arr[i]);
            if (idx < list.size()) {
                list.set(idx, arr[i]);
            } else {
                list.add(arr[i]);
            }
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
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent[x], parent);
        return parent[x];
    }

    private static boolean union(int x, int y, int[] parent, int[] rank) {
        int lx = find(x, parent), ly = find(y, parent);
        if (lx == ly) {
            return true;
        } else if (rank[lx] > rank[ly]) {
            parent[ly] = lx;
        } else if (rank[lx] < rank[ly]) {
            parent[lx] = ly;
        } else {
            parent[lx] = ly;
            rank[ly]++;
        }
        return false;
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
                if (curr.children[ch - 'a'] == null) {
                    curr.children[ch - 'a'] = new Node();
                }
                curr = curr.children[ch - 'a'];
            }
            curr.isEnd = true;
        }

        public boolean find(String word) {
            Node curr = root;
            for (char ch : word.toCharArray()) {
                if (curr.children[ch - 'a'] == null) {
                    return false;
                }
                curr = curr.children[ch - 'a'];
            }
            return curr.isEnd;
        }
    }

    

    static class FastInput {
        BufferedReader br;
        StringTokenizer st;

        FastInput() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(nextLine());
            return st.nextToken();
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        char nextCharacter() throws IOException {
            return next().charAt(0);
        }

        String nextLine() throws IOException {
            return br.readLine().trim();
        }

        int[] id4(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextInt();
            return arr;
        }

        int[][] id9(int n, int m) throws IOException {
            int[][] arr = new int[n][m];
            for (int i = 0; i < n; i++)
                arr[i] = id4(m);
            return arr;
        }

        long[] id14(int n) throws IOException {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextLong();
            return arr;
        }

        long[][] id8(int n, int m) throws IOException {
            long[][] arr = new long[n][m];
            for (int i = 0; i < n; i++)
                arr[i] = id14(m);
            return arr;
        }

        List<Integer> id12(int n) throws IOException {
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < n; i++)
                list.add(nextInt());
            return list;
        }

        List<Long> id6(int n) throws IOException {
            List<Long> list = new ArrayList<>();
            for (int i = 0; i < n; i++)
                list.add(nextLong());
            return list;
        }

        char[] id5(int n) throws IOException {
            return next().toCharArray();
        }

        char[][] id10(int n, int m) throws IOException {
            char[][] mat = new char[n][m];
            for (int i = 0; i < n; i++)
                mat[i] = id5(m);
            return mat;
        }
    }

    

    private static void id1(List<Integer> list) {
        for (int i = 0; i < list.size(); i++)
            out.print(list.get(i) + " ");
        out.println(" ");
    }

    private static void id11(List<Long> list) {
        for (int i = 0; i < list.size(); i++)
            out.print(list.get(i) + " ");
        out.println(" ");
    }

    private static void id7(int[] arr) {
        for (int i = 0; i < arr.length; i++)
            out.print(arr[i] + " ");
        out.println(" ");
    }

    private static void id0(int[][] arr) {
        for (int i = 0; i < arr.length; i++)
            id7(arr[i]);
    }

    private static void id2(long[] arr) {
        for (int i = 0; i < arr.length; i++)
            out.print(arr[i] + " ");
        out.println(" ");
    }

    private static void id13(long[][] arr) {
        for (int i = 0; i < arr.length; i++)
            id2(arr[i]);
    }
}