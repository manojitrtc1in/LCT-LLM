


import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Stack;





public class Main
{
    static long mod = 1000000007;
    static class Reader { static BufferedReader reader; static StringTokenizer tokenizer; static void init() { reader = new BufferedReader(new InputStreamReader(System.in)); tokenizer = new StringTokenizer(""); }static String next() throws IOException { while (! tokenizer.hasMoreTokens()) { tokenizer = new StringTokenizer(reader.readLine()); }return tokenizer.nextToken(); }static long nextLong() throws IOException { return Long.parseLong(next()); }static int nextInt() throws IOException { return Integer.parseInt(next()); }}
    public static int totalPrimeFactors(int n) { int ans  = 0; while (n%2==0) { ans++; n /= 2; } for (int i = 3; i <= Math.sqrt(n); i+= 2) { while (n%i == 0) { ans+=1; n /= i; } } if (n > 2) { ans++; }return ans; }
    public static long gcd(long a, long b) { if (b == 0) return a; return gcd(b, a % b); }
    public static long bigModulo(long base, long expo, long modulo) { long res = 1; while (expo > 0) { if (expo % 2 == 1) { res = (res * base) % modulo; } expo /= 2; base = (base * base) % modulo; } return res; }

    static class Pair {
        int index;
        int value;

        public Pair(int index, int value) {
            this.index = index;
            this.value = value;
        }
    }
    static class Pair2 {
        int index;
        boolean value;

        public Pair2(int index, boolean value) {
            this.index = index;
            this.value = value;
        }

        public void setValue(boolean b) {
            this.value = b;
        }
    }
    static class Pair3 {
        int x;
        int b;

        public Pair3(int x, int b) {
            this.x = x;
            this.b = b;
        }

    }

    static class Graph {

        public void removeEdges(int n) {
            for (int i = 1; i <= n; i++) {
                adjacencyList.get(nodes.get(i + "")).clear();
            }
        }

        private class Node {
            private String label;

            public Node(String label) {
                this.label = label;
            }

            @Override
            public String toString() {
                return label;
            }
        }

        private Map<String, Node> nodes = new HashMap<>();
        private Map<Node, List<Node>> adjacencyList = new HashMap<>();

        public void addNode(String label) {
            Node node = new Node(label);
            nodes.putIfAbsent(label, node);
            adjacencyList.putIfAbsent(node, new ArrayList<>());
        }

        public void addEdge(String from, String to) {
            Node fromNode = nodes.get(from);
            Node toNode = nodes.get(to);

            adjacencyList.get(fromNode).add(toNode);
            adjacencyList.get(toNode).add(fromNode);
        }


        private boolean traverseDepthFirstRec(Stack<String> stack) {
            Node root = nodes.get(stack.peek());
            return traverseDepthFirstRec(root, stack, new HashSet<>());
        }

        private boolean traverseDepthFirstRec(Node root, Stack<String> stack, HashSet<Node> visited) {

            if (stack.peek().equals(root.label)) {
                stack.pop();
            }

            if (stack.isEmpty()) {
                return true;
            }

            visited.add(root);

            for (Node node : adjacencyList.get(root)) {
                int m = stack.size();
                if (! visited.contains(node)) {
                    if (traverseDepthFirstRec(node, stack, visited)) return true;
                }
                if (m > stack.size()) {
                    break;
                }
            }

            return false;

        }
    }

    public static void main(String[] args) throws IOException {
        Reader.init();
        int t = Reader.nextInt();
        int[] a = new int[100];
        int[] b = new int[100];
        int[] c = new int[301];

        for (int i = 0; i < t; i++) {
            int k = Reader.nextInt();
            int n = Reader.nextInt();
            int m = Reader.nextInt();
            boolean possible = true;
            for (int j = 0; j < n; j++) {
                a[j] = Reader.nextInt();
            }
            for (int j = 0; j < m; j++) {
                b[j] = Reader.nextInt();
            }

            int u = 0;
            int v = 0;
            int w = 0;
            while (u < n && v < m) {
                if (a[u] > k && b[v] > k) {
                    possible = false;
                    break;
                }

                else if (a[u] > k) {
                    c[w] = b[v];
                    w++;
                    if (b[v] == 0){
                        k++;
                    }
                    v++;
                }
                else if (b[v] > k) {
                    c[w] = a[u];
                    w++;
                    if (a[u] == 0){
                        k++;
                    }
                    u++;
                }


                else if (a[u] == 0 && b[v] == 0) {
                    c[w] = 0;
                    w++;
                    k++;
                    u++;
                }

                else {
                    if (a[u] < b[v]) {
                        if (a[u] == 0) {
                            k++;
                        }
                        c[w] = a[u];
                        u++;
                    }
                    else {
                        if (b[v] == 0) {
                            k++;
                        }
                        c[w] = b[v];
                        v++;
                    }
                    w++;
                }
            }

            while (u < n && possible) {
                if (a[u] > k) {
                    possible = false;
                    break;
                }

                else if (a[u] <= k && a[u] != 0) {
                    c[w] = a[u];
                    w++;
                    u++;
                }
                else  {
                    c[w] = 0;
                    w++;
                    k++;
                    u++;
                }
            }
            while (v < m && possible) {
                if (b[v] > k) {
                    possible = false;
                    break;
                }

                else if (b[v] <= k && b[v] != 0) {
                    c[w] = b[v];
                    w++;
                    v++;
                }
                else  {
                    c[w] = 0;
                    w++;
                    k++;
                    v++;
                }
            }


            if (!possible) {
                System.out.println(-1);
            }

            else {
                for (int j = 0; j < m + n - 1; j++) {
                    System.out.print(c[j] + " ");
                }
                System.out.println(c[m + n - 1]);
            }

        }
    }


    public static void main731_3B(String[] args) throws IOException {
        Reader.init();
        int t = Reader.nextInt();

        for (int i = 0; i < t; i++) {
            Stack<Character> s = new Stack<>();
            String k = Reader.next();
            int start = 0;
            int end = k.length() - 1;
            boolean temp = false;
            while (start < end) {
                if (k.charAt(start) > k.charAt(end)) {
                    s.push(k.charAt(start));
                    start++;
                }

                else if (k.charAt(start) < k.charAt(end)) {
                    s.push(k.charAt(end));
                    end--;
                }
                else {
                    System.out.println("NO");
                    temp = true;
                    break;
                }
            }

            if (start == end) {
                s.push(k.charAt(start));
            }

            if (!temp) {
                int index = 97;
                while (!s.isEmpty()) {
                    if (index != s.peek()) {
                        System.out.println("No");
                        break;
                    }
                    s.pop();
                    index++;

                }
                if (s.isEmpty()) {
                    System.out.println("Yes");

                }
            }
        }
    }

    public static void main731_3A(String[] args) throws IOException {
        Reader.init();

        int t = Reader.nextInt();

        for (int i = 0; i < t; i++) {
            int a = Reader.nextInt();
            int b = Reader.nextInt();
            int c = Reader.nextInt();
            int d = Reader.nextInt();
            int e = Reader.nextInt();
            int f = Reader.nextInt();

            int diffX =  Math.abs(c - a);
            int difY = Math.abs(d - b);

            if (diffX != 0 && difY != 0) {
                System.out.println(diffX + difY);
            }

            else if (diffX == 0 && difY == 0) {
                System.out.println(0);
            }

            else if (diffX == 0){
                if (a == e && ((f > b && f < d) ||(f < b && f > d) )) {
                    System.out.println(difY + 2);
                }


                else { System.out.println(difY); }
            }

            else  {
                if (b == f && ((e > a && e < c) ||(e < a && e > c) )) {
                    System.out.println(diffX + 2);
                }

                else { System.out.println(diffX); }
            }
        }
    }

    public int minStepToReachTarget(int KnightPos[], int TargetPos[], int N)
    {
        if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]) {
            return 0;
        }
        else if (TargetPos[0] > N || TargetPos[1] > N || TargetPos[0] < 0 || TargetPos[1] < 0) {
            return Integer.MAX_VALUE;
        }
        int m = TargetPos[0];
        int n = TargetPos[1];
        int[][] arr = {{m + 2, n + 1},
        {m + 2, n - 1},
        {m - 2, n + 1},
        {m - 2, n - 1},
        {m + 1, n - 2},
        {m + 1, n + 2},
         {m - 1, n - 2},
        {m - 1, n + 2}};

        int min = Integer.MIN_VALUE;

        for (int i = 0; i < 8; i++) {
            min = Math.min(min, minStepToReachTarget(KnightPos, arr[i], N));
        }

        return min + 1;

    }

    public static void main730_2B(String[] args) throws IOException {
        Reader.init();
        int t = Reader.nextInt();

        for (int i = 0; i < t; i++) {
            int n = Reader.nextInt();
            long sum = 0;
            for (int j = 0; j < n; j++) {
                sum+= Reader.nextInt();
            }
            long avg = sum / n;
            long a = sum % n;
            long b = n - a;
            System.out.println(a * b);

        }
    }

    public static void main730_2A(String[] args) throws IOException {
        Reader.init();
        int t = Reader.nextInt();

        for (int i = 0; i < t; i++) {
            long a = Reader.nextLong();
            long b = Reader.nextLong();

            if (a == b) {
                System.out.println("0 0");
            }

            else {
                long k = Math.abs(a - b);
                long x = Math.min(a % k, k - a % k);
                System.out.println(k + " " + x);
            }

        }
    }

    public static void julyFWA(String[] args) throws  IOException {


        Reader.init();
        int t = Reader.nextInt();

        Graph graph = new Graph();

        for (int i = 1; i <= 100000; i++) {
            graph.addNode(i + "");
        }

        for (int i = 0; i < t; i++) {
            int n = Reader.nextInt();
            for (int j = 0; j < n - 1; j++) {
                graph.addEdge(Reader.nextInt() + "", Reader.nextInt() + "");
            }

            int q = Reader.nextInt();
            for (int j = 0; j < q; j++) {
                int k = Reader.nextInt();
                Stack<String> stack = new Stack<>();
                for (int l = 0; l < k; l++) {
                    stack.push(Reader.nextInt() + "");
                }
                if (graph.traverseDepthFirstRec(stack)) {
                    System.out.println("Yes");
                }

                else {
                    System.out.println("No");
                }
            }
            graph.removeEdges(n);

        }
    }

    public  static  void julyE(String[] args) throws IOException {
        Reader.init();
        ArrayList<String> arr = fillPalindromes();

        ArrayList<Long> arrSums =  new ArrayList<>();
        arrSums.add(1L);
        for (int i = 1; i < 100000; i++) {
            arrSums.add(arrSums.get(i - 1) + Long.parseLong(arr.get(i)));
        }

        int q = Reader.nextInt();
        for (int i = 0; i < q; i++) {
            int l = Reader.nextInt();
            int r = Reader.nextInt();
            System.out.println( Long.parseLong(arr.get(l - 1)));
            System.out.println(arrSums.get(r - 1) - arrSums.get(l - 1));
            System.out.println( bigModulo(Long.parseLong(arr.get(l - 1)), arrSums.get(r - 1) - arrSums.get(l - 1), mod));
        }

    }
    private static ArrayList<String> fillPalindromes() {
        ArrayList<String> arr =  new ArrayList<>();

        int[] helper = {0, 1, 2, 3, 4, 5};
        for (int i = 1; i < 6; i++) {
            helper[i] = (int) (helper[i - 1] + Math.pow(10, helper[i]));
        }

        for (int i = 1; i <= 9; i = i + 2) {
            if (i == 1) {
                for (int j = 0; j <= 9; j++) {
                    arr.add(j + "");
                }
            }
            else {
                for (int j = 0; j <= 9; j++) {
                    for (int k = helper[i / 2 - 1 ]; k < helper[ i / 2 ]; k++) {
                        arr.add(j + arr.get(k) + j);
                    }
                }
            }
        }

        arr.add("10000000001");
        ArrayList<String> arr2 = new ArrayList<>();

        for (String s: arr) {
            if (s.charAt(0) != '0') {
                arr2.add(s);
            }
        }

        return arr2;
    }

    public  static  void julyD(String[] args) throws IOException {
        Reader.init();
        int t = Reader.nextInt();
        int[] arr =  new int[100000];
        int[] gcd =  new int[100000];
        int[] a =  new int[100000];
        int[] b =  new int[100000];

        for (int i = 0; i < t; i++) {
            long sum = 0;
            int n = Reader.nextInt();
            for (int j = 0; j < n; j++) {
                arr[j] = Reader.nextInt();
                sum+= arr[j];
            }

            if (n <= 2) {
                System.out.println(n);
                continue;
            }

            fillGCD(arr, gcd, a, b, n);

            long ans = Long.MAX_VALUE;
            for (int j = 0; j < n; j++) {
                ans = Math.min(ans, (sum - arr[j]) / gcd[j] + 1);
            }

            System.out.println(ans);

        }
    }
    private static void fillGCD(int[] arr, int[] gcd, int[] a, int[] b, int n) {
        a[0] = 0;
        b[n - 1] = 0;

        for (int j = 1; j < n; j++) {
            a[j] = (int) gcd(a[j - 1], arr[j - 1]);
        }

        for (int j = n - 2; j >= 0; j--) {
            b[j] = (int) gcd(b[j + 1], arr[j + 1]);
        }

        for (int j = 0; j < n; j++) {
            gcd[j] = (int) gcd(a[j], b[j]);
        }
    }

    public  static  void julyC(String[] args) throws IOException {
            Reader.init();
            int t = Reader.nextInt();
            for (int i = 0; i < t; i++) {
                int[] ones = new int[32];
                int n = Reader.nextInt();
                int k = Reader.nextInt();
                for (int j = 0; j < n; j++) {
                    int x = Reader.nextInt();
                    int l = 0;
                    while (x > 0)
                    {
                        ones[l] = x % 2 == 1 ? ones[l]+ 1 : ones[l];
                        x = x / 2;
                        l++;
                    }
                }


                long ans = 0;
                for (int j = 0; j < 32; j++) {
                    ans += Math.ceil((double)ones[j] / k);
                }

                System.out.println(ans);

            }
        }

    public  static  void mainReading2C(String[] args) throws IOException {
        Reader.init();
        int l = Reader.nextInt();
        int n = Reader.nextInt();
        int[] cost = new int[n];
        int[] quantity = new int[n];

        for (int i = 0; i < n; i++) {
            quantity[i] = Reader.nextInt();
            cost[i] = Reader.nextInt();
        }

        System.out.println(knapsack(n, l, cost, quantity));

    }
    private static long knapsack(int n, int l, int[] cost, int[] quantity) {
        long[] dp = new long[l + 1];

        for (int i = 1; i <= l; i++) {
            dp[i] = Long.MAX_VALUE;
        }

        


        for (int i = 1; i <= l; i++) {
            for (int j = 0; j < n; j++) {
                if (quantity[j] <= i) {
                    dp[i] = Math.min(dp[i], dp[i - quantity[j]] + cost[j]);
                }
                else {
                    dp[i] = Math.min(dp[i], cost[j]);
                }
            }
        }
        return dp[l];
    }

    public  static  void mainReading2B(String[] args) throws IOException {
        Reader.init();
        int n = Reader.nextInt();
        int k = Reader.nextInt();

        Pair2[] arr = new Pair2[n];
        long[] dp = new long[n];

        for (int i = 0; i < n; i++) {
            arr[i] = new Pair2(i + 1, false);
            dp[i] = -1;
        }

        for (int i = 0; i < k; i++) {
            arr[Reader.nextInt() - 1].setValue(true);
        }

        System.out.println(helper_Reading2B(n - 1, arr, dp) % 1000000007);



    }
    private static long helper_Reading2B(int i, Pair2[] arr, long[] dp) {

        if (i == -1) {
            return 1;
        }

        if (dp[i] >= 0) {
            return dp[i];
        }

        if ( arr[i].value ) {
            dp[i] = 0;
            return 0;
        }

        if (i == 0) {
            return 1;
        }


        long c =  helper_Reading2B( i - 1, arr, dp) + helper_Reading2B( i - 2, arr, dp) % 1000000007;
        dp[i] = c ;
        return c;
    }

    public  static  void mainReading2A(String[] args) throws IOException {
        Reader.init();
        int n = Reader.nextInt();

        if (n%4 == 0 || n %7 == 0) {
            System.out.println("Yes");
            return;
        }

        for (int i = 0; i <= 14; i++) {
            n-=7;
            if (n < 0) {
                break;
            }
            if (n % 4 == 0) {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");

    }

    public  static  void main728CWA(String[] args) throws IOException {
            Reader.init();
            int t = Reader.nextInt();
            long[] arr  = new long[100000];
            for (int i = 0; i < t; i++) {
                int n = Reader.nextInt();


                for (int j = 0; j < n; j++) {
                    arr[j] = Reader.nextLong();
                }

                if (n == 1 || n == 2) {
                    System.out.println(0);
                    continue;
                }


                Arrays.sort(arr, 0, n - 1);
                long ans = 0;
                for (int j = 0; j < n; j++) {
                    for (int k = j + 2; k < n; k++) {
                        ans += arr[k] - arr[j];
                    }
                }

                System.out.println(-1*ans);
            }
        }

    public  static  void main728BTLE(String[] args) throws IOException {
            Reader.init();
            int t = Reader.nextInt();

            Pair[] arr = new Pair[100000];
            for (int i = 0; i < t; i++) {
                int n = Reader.nextInt();
                int p = 0;
                for (int j = 0; j <= n - 1; j++) {
                    int k =  Reader.nextInt();
                    if (k <= 2 * n) {
                        arr[p++] = new Pair(j + 1, k);
                    }
                }

                merge_sort(arr, 0, p - 1);

                int count  = 0;


                System.out.println(count);

            }
        }

    public  static  void main728A(String[] args) throws IOException {
            Reader.init();
            int t = Reader.nextInt();


            for (int i = 0; i < t; i++) {
                int n = Reader.nextInt();

                String s = "";

                if (n % 2 == 0) {
                    for (int j = 1; j <= n / 2 - 1; j++) {
                        s += 2 * j + " " + (2 * j - 1) + " ";
                    }
                    s += n + " " + (n - 1);
                }
                else  {
                    n -= 3;
                    for (int j = 1; j <= n / 2; j++) {
                        s += 2 * j + " " + (2 * j - 1) + " ";
                    }
                    s += (n +  2) + " " + (n + 3) + " " + (n + 1);
                }

                System.out.println(s);
            }
        }

    public  static  void main1234(String[] args) throws IOException {
            Reader.init();
            int n = Reader.nextInt();

            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Reader.nextInt();
            }

            long ans  = counting_inversion_1(arr, 0, n - 1);
            System.out.println(ans);
        }

    private static void merge(Pair[] arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        Pair[] L = new Pair[n1];
        Pair[] R = new Pair[n2];

        for (int i = 0; i < n1; i++) {
            L[i] = new Pair(arr[l + i].index, arr[l + i].value);
        }
        for (int j = 0; j < n2; j++) {
            R[j] = new Pair(arr[m + 1 + j].index, arr[m + 1 + j].value);

        }

        int i = 0; int j = 0; int k = l;

        while (i < n1 && j < n2) {

            if (L[i].value <= R[j].value) {
                arr[k] = L[i];
                i++;
            }
            else {
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

    private static void merge_sort(Pair[] arr, int start, int end) {
        if (start >= end) {
            return;
        }


        int mid = ( start + end ) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    private static long counting_inversion_1(int[] arr, int start, int end) {
        if (start >= end) {
            return 0;
        }

        int mid = ( start + end ) / 2;
        return counting_inversion_1(arr, start, mid) + counting_inversion_1(arr, mid + 1, end) + merge_1(arr, start, mid, end);
    }

    private static long merge_1(int[] arr, int l, int m, int r) {
        long ans = 0;
        int n1 = m - l + 1;
        int n2 = r - m;

        int[] L = new int[n1];
        int[] R = new int[n2];

        if (n1 >= 0) System.arraycopy(arr, l, L, 0, n1);
        if (n2 >= 0) System.arraycopy(arr, m + 1, R, 0, n2);

        int i = 0; int j = 0; int k = l;

        while (i < n1 && j < n2) {

            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                for (int n = i; n < n1; n++) {
                    ans+=L[n];
                }
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

        return ans;
    }

    public  static  void main727B(String[] args) throws IOException {

            Reader.init();
            int n = Reader.nextInt();
            int q = Reader.nextInt();
            String s = Reader.next();
            int[] arr = new int[n];

            for (int i = 0; i < n; i++) {
                arr[i] = s.charAt(i) -  96;
            }


            for (int i = 1; i < n; i++) {
                arr[i] += arr[i - 1];
            }

            for (int i = 0; i < q; i++) {

                int l = Reader.nextInt();
                int r = Reader.nextInt();

                System.out.println(arr[r - 1] - arr[l - 2]);
            }
        }

    public  static  void main727A(String[] args) throws IOException {
        Reader.init();
        int k = Reader.nextInt();
        long n, x, t;


        for (int i = 0; i < k; i++) {

            n = Reader.nextLong();
            x = Reader.nextLong();
            t = Reader.nextLong();

            if (x > t) {
                System.out.println(0);
                continue;
            }

            long temp = t / x;

            if (n <= temp ) {
                System.out.println((n - 1)  * n / 2);
            }
            else {
                System.out.println((n - temp) * temp + (temp - 1) * temp / 2);
            }

        }
    }


    static class P {
        int c;
        String book;
        int points;

        public P(String book, int points, int c) {
            this.c = c;
            this.book = book;
            this.points = points;
        }
    }

    static void relativeP(long x, long y) {
        long d;
        d =gcd(x, y);
        x = x / d;
        y = y / d;

        System.out.println(x + " " + y);
    }

    public  static  void mainReading1E(String[] args) throws IOException {


            Reader.init();
            int t = Reader.nextInt();
            long d;
            long n;
            String x, y;
            for (int i = 0; i < t; i++) {
                d = 1;
                x = Reader.next();

                if (x.equals(".")) {
                    x = "0.";
                }

                y = Reader.next();
                for (int j = 0; j < x.length() - x.indexOf('.') - 1; j++) {
                    d *= 10;
                }

                d = d * (long) Math.pow(10, y.length()) - d;

                n = (long) (Double.parseDouble(x.concat(y).replace(".", "")))
                        - (long) (Double.parseDouble(x.replace(".", "")));

                relativeP(n, d);

            }
        }

    public  static  void mainReading1C(String[] args) throws IOException {
        Reader.init();
        int n = Reader.nextInt();
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i <n ; i++) {
            priorityQueue.add(Reader.nextInt());
        }

        while (priorityQueue.size() > 1) {
            priorityQueue.add(priorityQueue.poll() - priorityQueue.poll());
        }

        System.out.println(priorityQueue.peek());
    }

    public static void mainReading1B(String[] args) throws IOException {
        Reader.init();
        int n = Reader.nextInt();
        P[] arr = new P[n];
        for (int i = 0; i <n ; i++) {
            arr[i] = new P(Reader.next(), Reader.nextInt(), i+1);
        }
        Arrays.sort(arr, new Comparator<P>() {
            @Override
            public int compare(P o1, P o2) {
                if (o1.book.compareTo(o2.book) == 0) {
                    return o2.points - o1.points;
                }
                return o1.book.compareTo(o2.book);
            }
        });

        for (int i = 0; i < n; i++) {
            System.out.println(arr[i].c);
        }
    }

    public static void mainReading1A(String[] args) throws IOException {
        Reader.init();
        int n = Reader.nextInt();
        int sum;
        int remainder;

        HashMap<Integer, Integer> hashMap =new HashMap<>();

        hashMap.put(1, 0);
        hashMap.put(5, 0);

        int k;

        for (int i = 0; i < n; i++) {
            k = Reader.nextInt();
            hashMap.put(k, hashMap.get(k) + 1);
        }

        sum = 5 * hashMap.get(5) + hashMap.get(1);

        if (sum < 9) {
            System.out.println(-1);
            return;
        }

        remainder = sum % 9;

        while (remainder != 0) {

            if (remainder >= 5 && hashMap.get(5) > 0) {
                hashMap.put(5, hashMap.get(5) - 1);
                remainder -= 5;
            }

            else if (remainder >= 5 && hashMap.get(5) <= 0 ) {

                if (hashMap.get(1) >= remainder) {
                    hashMap.put(1, hashMap.get(1) - remainder);
                    remainder = 0;
                }

                else {
                    System.out.println(-1);
                    return;
                }

            }

            else {

                if (hashMap.get(1) >= remainder) {
                    hashMap.put(1, hashMap.get(1) - remainder);
                    remainder = 0;
                }

                else {

                    if (hashMap.get(5) > 0) {
                        hashMap.put(5, hashMap.get(5) - 1);
                        remainder += 4;
                    }

                    else {
                        System.out.println(-1);
                        return;
                    }


                }

            }

        }

        if (hashMap.get(5) <= 0 && hashMap.get(1) <= 0) {
            System.out.println(-1);
            return;
        }

        System.out.println("5".repeat(Math.max(0, hashMap.get(5))) + "1".repeat(Math.max(0, hashMap.get(1))));

    }

    static boolean allPrefixesArePrime(boolean []sieve, int num) {
            while (num > 0) {
                if (sieve[num]) return false;
                num /= 10;
            }
            return true;

        }

    static int next(int[] arr, int target, int start, int end) {
        int ans = -1;
        while (start <= end) {
            int mid = (start + end) / 2;


            if (arr[mid] < target) {
                start = mid + 1;
            }


            else {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }

    static int next(ArrayList<Integer> arr, int target, int start, int end) {
        int ans = -1;
        while (start <= end) {
            int mid = (start + end) / 2;


            if (arr.get(mid) < target) {
                start = mid + 1;
            }


            else {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }

    public static void mainD_TLE(String[] args) throws IOException {

            Reader.init();
            int n = Reader.nextInt();

            boolean[] sieve = new boolean[5000001];  

            sieve[0] = sieve[1] = true;

            for (int i = 2; i <= 2300; i++) {
                if (!sieve[i])
                {
                    for (int j = i * i; j <= 5000000; j += i)
                    {
                        sieve[j] = true;
                    }
                }
            }

            ArrayList<Integer> pPrimes = new ArrayList<>();


            for (int j = 1; j <= 5000000; j++) {
                if (allPrefixesArePrime(sieve, j)) {
                    pPrimes.add(j);
                }
            }


            for (int i = 0; i < n; i++) {
                int s = Reader.nextInt();
                if (s > 5000000) {
                    System.out.println(-1);
                }
                else {
                    int index = next(pPrimes, s, 0, pPrimes.size() - 1);
                    if (index == -1) {
                        System.out.println(-1);
                    }
                    else {
                        System.out.println(pPrimes.get(index));
                    }
                }
            }

        }

    private static void recursePair(int[] arr, int remainder, int i, ArrayList<Integer> indices) {
        if (remainder < arr[i]) {
            return;
        }
        else if (remainder == arr[i]) {
            arr[i] = -1;
            return;
        }

        indices.add(i);
        recursePair(arr, remainder - arr[i], i  - 1, indices);

    }

    

    public static int hanoi(int n, int a, int b, int c) {
        if (a == 2 | n == 1) {
            return 1;
        }

        return hanoi(n - 1, a, c, b) + 1 + hanoi(n - 1, b, a, c);

    }

    public static void main2(String[] args) throws java.lang.Exception {

        Reader.init();
        long k = 1000000007;
        long t = Reader.nextLong();
        long n, m, res;
        for (int i = 0; i < t; i++) {
            n = Reader.nextLong();
            m = Reader.nextLong();

            res = bigModulo(2, n, k) - 1;
            res = res % k;
            res = bigModulo(res, m, k);
            System.out.println(res);
        }
    }
}
