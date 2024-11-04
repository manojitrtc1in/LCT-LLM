import java.io.*;
import java.util.*;
import java.lang.*;

public class test {
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
            

            while (t-- > 0) {
                solve();
            }
            out.flush();
        }
    }

    public static void solve() {
        int n = sc.nextInt();
        long count = n;
        int m = sc.nextInt();
        int[] dp = new int[n];
        Arrays.fill(dp, 0);
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            a = Math.min(a, b);
            if (dp[a] == 0)
                count--;
            dp[a]++;
        }
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int con = sc.nextInt();
            if (con == 1) {
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;
                a = Math.min(a, b);
                if (dp[a] == 0)
                    count--;
                dp[a]++;
            } else if (con == 2) {
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;
                a = Math.min(a, b);
                dp[a]--;
                if (dp[a] == 0)
                    count++;
            } else if (con == 3)
                out.println(count);
        }

    }

    
    

    

    

    

    

    

    


    

    


    


    public static int inf = Integer.MAX_VALUE;
    public static int minf = Integer.MIN_VALUE;
    public static int mod = 1000000007;
    public static int ml = (int) 1e9;
    public static InputReader sc;
    public static PrintWriter out;
    public static PrintWriter pr;

    


    static class Pair {
        int first, second;

        Pair(int x, int y) {
            this.first = x;
            this.second = y;
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
        Node next;
        int data;

        Node(int x) {
            next = null;
            this.data = x;
        }
    }

    


    static class Tree {
        Tree left, right;
        int data;

        Tree(int x) {
            this.data = x;
            left = null;
            right = null;
        }
    }

    


    public static int id8(int n) {
        int count = 0;
        while (n != 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }

    public static int id8(long n) {
        int count = 0;
        while (n != 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
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

    static long nCr(int n, int r) {
        return fact(n) / (fact(r) * fact(n - r));
    }

    static long fact(int n) {
        int res = 1;
        for (int i = 2; i <= n; i++)
            res = res * i;
        return res;
    }

    static long nCr(long n, long r) {
        return fact(n) / (fact(r) * fact(n - r));
    }

    static long fact(long n) {
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

    public static int id9(int x, int y, int z) {
        return Math.max(x, Math.max(y, z));
    }

    public static int id10(int x, int y, int z) {
        return Math.min(x, Math.min(y, z));
    }

    public static long id9(long x, long y, long z) {
        return Math.max(x, Math.max(y, z));
    }

    public static long id10(long x, long y, long z) {
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

    public static void id3(HashMap<Long, Integer> map) {
        if (sysFlag) {
            for (Map.Entry<Long, Integer> entry : map.entrySet())
                pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
        }
    }

    public static void id4(HashMap<Long, Long> map) {
        if (sysFlag) {
            for (Map.Entry<Long, Long> entry : map.entrySet())
                pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
        }
    }

    public static void id7(HashMap<Integer, Long> map) {
        if (sysFlag) {
            for (Map.Entry<Integer, Long> entry : map.entrySet())
                pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
        }
    }

    public static void id5(HashMap<String, Long> map) {
        if (sysFlag) {
            for (Map.Entry<String, Long> entry : map.entrySet())
                pr.println("Key => " + entry.getKey() + ", Value => " + entry.getValue());
        }
    }

    public static void id6(HashMap<Character, Long> map) {
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

    public static void id11(HashMap<Character, Integer> map) {
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
                pr.println("first:" + pair[i].first + " second:" + pair[i].second);
            }
        }
    }
}
