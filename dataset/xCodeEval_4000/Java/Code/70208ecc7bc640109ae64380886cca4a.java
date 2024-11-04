


import static java.lang.Math.*;

import java.util.*;

import javax.naming.ContextNotEmptyException;
import javax.swing.ImageIcon;
import javax.swing.table.TableStringConverter;

import java.io.*;
import java.math.*;
import java.rmi.ConnectIOException;

public class Main {

    static FastReader sc;
    static long mod = ((long) 1e9) + 7;
    static Tree tree;
    static PrintWriter out, err;
    static int imax = Integer.MAX_VALUE;
    static int imin = Integer.MIN_VALUE;
    static long lmax = Long.MAX_VALUE;
    static long lmin = Long.MIN_VALUE;
    static double dmax = Double.MAX_VALUE;
    static double dmin = Double.MIN_VALUE;

    private static void solve() throws IOException {
        int n=sc.nextInt();
        int m=sc.nextInt();
        String s=sc.next();
        String t=sc.next();
        int i=n-1;
        int j=m-1;
        while(j>=0&&i>=0)
        {
            if(s.charAt(i)!=t.charAt(j))break;
            i--;
            j--;
        }
        if(j>=1)print("No");
        else{
            int val=t.charAt(0)-'0';
            if(n==m){
                if(j<0)print("yes");
                else print("No");
                return;
            }
            m--;
            n-=m;
            boolean done=false;
            int cur=s.charAt(0)-'0';
            int first=s.charAt(0)-'0';
            for(i=1;i<n;i++){
                int sec=s.charAt(i)-'0';
                if(val==0){
                   if(min(first,sec)==0)done=true; 
                   first=min(first,sec);
                }else{
                   if(max(first,sec)==1)done=true; 
                   first=max(first,sec);
                }    
            }
            if(done)print("yes");
            else print("No");
        }
    }

    public static void main(String hi[]) throws IOException {
        initializeIO();
        out = new PrintWriter(System.out);
        err = new PrintWriter(System.err);
        sc = new FastReader();
        long startTimeProg = System.currentTimeMillis();
        long endTimeProg;
        int testCase = 1;
        testCase = sc.nextInt();
        while (testCase-- != 0) {
            solve();
        }
        endTimeProg = System.currentTimeMillis();
        debug("[finished : " + (endTimeProg - startTimeProg) + ".ms ]");
        out.flush();
        err.flush();
        

    }

    private static class Pair {
        int first = 0;
        int sec = 0;
        int[] arr;
        char ch;
        String s;
        Map<Integer, Integer> map;

        Pair(int first, int sec) {
            this.first = first;
            this.sec = sec;
        }

        Pair(int[] arr) {
            this.map = new HashMap<>();
            for (int x : arr)
                this.map.put(x, map.getOrDefault(x, 0) + 1);
            this.arr = arr;
        }

        Pair(char ch, int first) {
            this.ch = ch;
            this.first = first;
        }

        Pair(String s, int first) {
            this.s = s;
            this.first = first;
        }
    }

    private static Set<Long> factors(long n) {
        Set<Long> res = new HashSet<>();
        

        for (long i = 1; i * i <= (n); i++) {
            if (n % i == 0) {
                res.add(i);
                if (n / i != i) {
                    res.add(n / i);
                }
            }
        }

        return res;
    }

    

    private static double areaOftriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        double[] mid_point = midOfaLine(x1, y1, x2, y2);
        

        

        double height = distanceBetweenPoints(mid_point[0], mid_point[1], x3, y3);
        double wight = distanceBetweenPoints(x1, y1, x2, y2);
        

        return (height * wight) / 2;
    }

    private static double distanceBetweenPoints(double x1, double y1, double x2, double y2) {
        double x = x2 - x1;
        double y = y2 - y1;
        return (Math.pow(x, 2) + Math.pow(y, 2));
    }

    private static double[] midOfaLine(double x1, double y1, double x2, double y2) {
        double[] mid = new double[2];
        mid[0] = (x1 + x2) / 2;
        mid[1] = (y1 + y2) / 2;
        return mid;
    }

    
    static long power(long x, long y) {
        long temp;
        if (y == 0)
            return 1l;
        temp = power(x, y / 2);
        if (y % 2 == 0)
            return (temp * temp);
        else
            return (x * temp * temp);
    }

    private static StringBuilder reverseString(String s) {
        StringBuilder sb = new StringBuilder(s);
        int l = 0, r = sb.length() - 1;
        while (l <= r) {
            char ch = sb.charAt(l);
            sb.setCharAt(l, sb.charAt(r));
            sb.setCharAt(r, ch);
            l++;
            r--;
        }
        return sb;
    }

    private static void swap(List<Integer> li, int i, int j) {
        int t = li.get(i);
        li.set(i, li.get(j));
        li.set(j, t);
    }

    private static void swap(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    static int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    private static boolean isPallindrome(String s, int l, int r) {
        while (l < r) {
            if (s.charAt(l) != s.charAt(r))
                return false;
            l++;
            r--;
        }
        return true;
    }

    private static StringBuilder removeLeadingZero(StringBuilder sb) {
        int i = 0;
        while (i < sb.length() && sb.charAt(i) == '0')
            i++;
        

        if (i == sb.length())
            return new StringBuilder();
        return new StringBuilder(sb.substring(i, sb.length()));
    }

    private static void print(int[][] arr) {
        int n = arr.length;
        int m = arr[0].length;
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                out.print(arr[i][j] + " ");
            }
            out.println();
        }
    }

    private static StringBuilder removeEndingZero(StringBuilder sb) {
        int i = sb.length() - 1;
        while (i >= 0 && sb.charAt(i) == '0')
            i--;
        if (i < 0)
            return new StringBuilder();
        return new StringBuilder(sb.substring(0, i + 1));
    }

    private static void debug(int[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            err.println(Arrays.toString(arr[i]));
        }
    }

    private static void debug(long[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            err.println(Arrays.toString(arr[i]));
        }
    }

    private static void debug(List<int[]> arr) {
        for (int[] a : arr) {
            err.println(Arrays.toString(a));
        }
    }

    private static void debug(float[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            err.println(Arrays.toString(arr[i]));
        }
    }

    private static void debug(double[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            err.println(Arrays.toString(arr[i]));
        }
    }

    private static void debug(boolean[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            err.println(Arrays.toString(arr[i]));
        }
    }

    

    

    


    private static void debug(String s) throws IOException {
        err.println(s);
    }

    private static void print(double s) throws IOException {
        out.println(s);
    }

    private static void print(float s) throws IOException {
        out.println(s);
    }

    private static void print(long s) throws IOException {
        out.println(s);
    }

    private static void print(int s) throws IOException {
        out.println(s);
    }

    private static void debug(double s) throws IOException {
        err.println(s);
    }

    private static void debug(float s) throws IOException {
        err.println(s);
    }

    private static void debug(long s) {
        err.println(s);
    }

    private static void debug(int s) {
        err.println(s);
    }

    private static boolean isPrime(long n) {

        

        

        if (n <= 1)
            return false;

        

        else if (n == 2)
            return true;

        

        else if (n % 2 == 0)
            return false;

        

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    private static List<List<Integer>> readUndirectedGraph(int n) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            graph.get(x).add(y);
            graph.get(y).add(x);
        }
        return graph;
    }

    private static List<List<Integer>> readUndirectedGraph(int[][] intervals, int n) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < intervals.length; i++) {
            int x = intervals[i][0];
            int y = intervals[i][1];
            graph.get(x).add(y);
            graph.get(y).add(x);
        }
        return graph;
    }

    private static List<List<Integer>> readDirectedGraph(int[][] intervals, int n) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < intervals.length; i++) {
            int x = intervals[i][0];
            int y = intervals[i][1];

            graph.get(x).add(y);
            

        }
        return graph;
    }

    private static List<List<Integer>> readDirectedGraph(int n) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            graph.get(x).add(y);
            

        }
        return graph;
    }

    static String[] readStringArray(int n) {
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.next();
        }
        return arr;
    }

    private static Map<Character, Integer> freq(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        return map;
    }

    private static Map<Long, Integer> freq(long[] arr) {
        Map<Long, Integer> map = new HashMap<>();
        for (long x : arr) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
        return map;
    }

    private static Map<Integer, Integer> freq(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int x : arr) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
        return map;
    }

    static boolean[] sieveOfEratosthenes(long n) {
        boolean prime[] = new boolean[(int) n + 1];
        for (int i = 2; i <= n; i++)
            prime[i] = true;

        for (int p = 2; p * p <= n; p++) {
            

            

            if (prime[p] == true) {
                

                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        return prime;
    }

    static int[] sieveOfEratosthenesInt(long n) {
        boolean prime[] = new boolean[(int) n + 1];
        Set<Integer> li = new HashSet<>();
        for (int i = 2; i <= n; i++) {
            prime[i] = true;
        }
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            if (prime[i])
                li.add(i);
        }
        int[] arr = new int[li.size()];
        int i = 0;
        for (int x : li) {
            arr[i++] = x;
        }
        return arr;
    }

    static boolean isMemberAC(int a, int d, int x) {

        

        

        if (d == 0)
            return (x == a);

        

        

        return ((x - a) % d == 0 && (x - a) / d >= 0);
    }

    static boolean isMemberAC(long a, long d, long x) {

        

        

        if (d == 0)
            return (x == a);

        

        

        return ((x - a) % d == 0 && (x - a) / d >= 0);
    }

    private static void sort(int[] arr) {
        int n = arr.length;
        List<Integer> li = new ArrayList<>();
        for (int x : arr) {
            li.add(x);
        }
        Collections.sort(li);
        for (int i = 0; i < n; i++) {
            arr[i] = li.get(i);
        }
    }

    private static void sortReverse(int[] arr) {
        int n = arr.length;
        List<Integer> li = new ArrayList<>();
        for (int x : arr) {
            li.add(x);
        }
        Collections.sort(li, Collections.reverseOrder());
        for (int i = 0; i < n; i++) {
            arr[i] = li.get(i);
        }
    }

    private static void sort(double[] arr) {
        int n = arr.length;
        List<Double> li = new ArrayList<>();
        for (double x : arr) {
            li.add(x);
        }
        Collections.sort(li);
        for (int i = 0; i < n; i++) {
            arr[i] = li.get(i);
        }
    }

    private static void sortReverse(double[] arr) {
        int n = arr.length;
        List<Double> li = new ArrayList<>();
        for (double x : arr) {
            li.add(x);
        }
        Collections.sort(li, Collections.reverseOrder());
        for (int i = 0; i < n; i++) {
            arr[i] = li.get(i);
        }
    }

    private static void sortReverse(long[] arr) {
        int n = arr.length;
        List<Long> li = new ArrayList<>();
        for (long x : arr) {
            li.add(x);
        }
        Collections.sort(li, Collections.reverseOrder());

        for (int i = 0; i < n; i++) {
            arr[i] = li.get(i);
        }
    }

    private static void sort(long[] arr) {
        int n = arr.length;
        List<Long> li = new ArrayList<>();
        for (long x : arr) {
            li.add(x);
        }
        Collections.sort(li);
        for (int i = 0; i < n; i++) {
            arr[i] = li.get(i);
        }
    }

    private static long sum(int[] arr) {
        long sum = 0;
        for (int x : arr) {
            sum += x;
        }
        return sum;
    }

    private static long sum(long[] arr) {
        long sum = 0;
        for (long x : arr) {
            sum += x;
        }
        return sum;
    }

    private static void initializeIO() {
        try {
            System.setIn(new FileInputStream("input.txt"));
            System.setOut(new PrintStream(new FileOutputStream("output.txt")));
            System.setErr(new PrintStream(new FileOutputStream("error.txt")));
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }

    private static int maxOfArray(int[] arr) {
        int max = Integer.MIN_VALUE;
        for (int x : arr) {
            max = Math.max(max, x);

        }
        return max;
    }

    private static long maxOfArray(long[] arr) {
        long max = Long.MIN_VALUE;
        for (long x : arr) {
            max = Math.max(max, x);

        }
        return max;
    }

    private static int[][] readIntIntervals(int n, int m) {
        int[][] arr = new int[n][m];
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                arr[j][i] = sc.nextInt();
            }
        }
        return arr;
    }

    private static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    private static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    private static int[] readIntArray(int n) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        return arr;
    }

    private static double[] readDoubleArray(int n) {
        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextDouble();
        }
        return arr;
    }

    private static long[] readLongArray(int n) {
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextLong();
        }
        return arr;
    }

    private static void print(int[] arr) throws IOException {
        out.println(Arrays.toString(arr));
    }

    private static void print(long[] arr) throws IOException {
        out.println(Arrays.toString(arr));
    }

    private static void print(String[] arr) throws IOException {
        out.println(Arrays.toString(arr));
    }

    private static void print(double[] arr) throws IOException {
        out.println(Arrays.toString(arr));
    }

    private static void debug(String[] arr) {
        err.println(Arrays.toString(arr));
    }

    private static void debug(Boolean[][] arr) {
        for (int i = 0; i < arr.length; i++)
            err.println(Arrays.toString(arr[i]));
    }

    private static void debug(int[] arr) {
        err.println(Arrays.toString(arr));
    }

    private static void debug(long[] arr) {
        err.println(Arrays.toString(arr));
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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
                str = br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class Tree {
        List<List<Integer>> adj = new ArrayList<>();
        int parent = 1;

        int[] arr;
        int n;
        Map<Integer, Integer> node_parent;
        List<Integer> leaf;

        public Tree(int n) {
            this.n = n;
            leaf = new ArrayList<>();
            node_parent = new HashMap<>();
            arr = new int[n + 2];
            for (int i = 0; i <= n + 1; i++) {
                adj.add(new ArrayList<>());
            }
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
                node_parent.put(i + 1, arr[i]);
                if ((i + 1) == arr[i])
                    parent = arr[i];
                else
                    adj.get(arr[i]).add(i + 1);
            }
        }

        private List<List<Integer>> getTree() {
            return adj;
        }

        private void formLeaf(int v) {
            boolean leaf = true;
            for (int x : adj.get(v)) {
                formLeaf(x);
                leaf = false;
            }
            if (leaf)
                this.leaf.add(v);
        }

        private List<Integer> getLeaf() {
            return leaf;
        }

        private Map<Integer, Integer> getParents() {
            return node_parent;
        }

        int[] getArr() {
            return arr;
        }
    }

    static class Dsu {
        int[] parent, size;

        Dsu(int n) {
            parent = new int[n + 1];
            size = new int[n + 1];

            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        private int findParent(int u) {
            if (parent[u] == u)
                return u;
            return parent[u] = findParent(parent[u]);
        }

        private boolean union(int u, int v) {
            

            int pu = findParent(u);
            

            int pv = findParent(v);
            


            if (pu == pv)
                return false;
            if (size[pu] <= size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
            return true;
        }
    }

    

    public static int log2(int N) {
        return (int) (Math.log(N) / Math.log(2));
    }

    private static long fact(long n) {
        if (n <= 2)
            return n;
        return n * fact(n - 1);
    }

    private static void print(String s) throws IOException {
        out.println(s);
    }

    public static boolean isNumeric(String strNum) {
        if (strNum == null) {
            return false;
        }
        try {
            double d = Double.parseDouble(strNum);
        } catch (NumberFormatException nfe) {
            return false;
        }
        return true;
    }

    private static boolean isSorted(List<Integer> li) {
        int n = li.size();
        if (n <= 1)
            return true;
        for (int i = 0; i < n - 1; i++) {
            if (li.get(i) > li.get(i + 1))
                return false;
        }
        return true;
    }

    private static boolean isSorted(int[] arr) {
        int n = arr.length;
        if (n <= 1)
            return true;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    private static boolean ispallindromeList(List<Integer> res) {
        int l = 0, r = res.size() - 1;
        while (l < r) {
            if (res.get(l) != res.get(r))
                return false;
            l++;
            r--;
        }
        return true;
    }

    private static long ncr(long n, long r) {
        return fact(n) / (fact(r) * fact(n - r));
    }

    private static void swap(char[] s, int i, int j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }

    static boolean isPowerOfTwo(long x) {
        return x != 0 && ((x & (x - 1)) == 0);
    }

    private static long gcd(long[] arr) {
        long ans = 0;
        for (long x : arr) {
            ans = gcd(x, ans);
        }
        return ans;
    }

    private static int gcd(int[] arr) {
        int ans = 0;
        for (int x : arr) {
            ans = gcd(x, ans);
        }
        return ans;
    }

    private static long power(long x, long y, long p) {
        long res = 1;
        x = x % p;
        if (x == 0)
            return 0;
        while (y > 0) {
            if ((y & 1) != 0)
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

}