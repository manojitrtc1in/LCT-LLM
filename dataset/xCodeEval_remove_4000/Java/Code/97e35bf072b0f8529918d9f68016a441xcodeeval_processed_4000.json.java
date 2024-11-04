import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class Main {
    static int mod = (int) (1e9) + 7;

    
    static class dsu {
        static int parent[], n;

        static long size[];

        dsu(int n) {
            parent = new int[n + 1];
            size = new long[n + 1];
            

            

            Main.dsu.n = n;
            makeSet();
        }

        static void makeSet() {
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
                

            }
        }

        static int find(int a) {
            if (parent[a] == a)
                return a;
            else {
                return parent[a] = find(parent[a]);

            }
        }

        static void union(int a, int b) {
            int setA = find(a);
            int setB = find(b);
            if (setA == setB)
                return;
            if (size[setA] >= size[setB]) {
                parent[setB] = setA;
                size[setA] += size[setB];
            } else {
                parent[setA] = setB;
                size[setB] += size[setA];
            }
        }
    }

    
    static class Pair<X extends Number, Y extends Number> implements Comparator<Pair> {
        X x;
        Y y;

        

        public Pair(X x, Y y) {
            this.x = x;
            this.y = y;
        }

        public Pair() {

        }

        @Override
        public int compare(Main.Pair o1, Main.Pair o2) {
            return ((int) (o1.y.intValue() - o2.y.intValue()));

        }
    }

    
    static class TrieNode {
        private HashMap<Character, TrieNode> children = new HashMap<>();
        public int size;
        boolean id4;

        public void id2(char ch) {
            children.putIfAbsent(ch, new TrieNode());
        }

        public TrieNode getChild(char ch) {
            return children.get(ch);
        }
    }

    static private TrieNode root;

    public static void insert(String str) {
        TrieNode curr = root;
        for (char ch : str.toCharArray()) {
            curr.id2(ch);
            curr = curr.getChild(ch);
            curr.size++;
        }
        

        curr.id4 = true;
    }

    public static int search(String word) {
        TrieNode curr = root;

        for (char ch : word.toCharArray()) {
            curr = curr.getChild(ch);
            if (curr == null) {
                return 0;
            }
        }
        

        return curr.size;
    }

    public boolean delete(TrieNode current, String word, int index) {
        if (index == word.length()) {
            

            if (!current.id4) {
                return false;
            }
            current.id4 = false;
            

            return current.children.size() == 0;
        }
        char ch = word.charAt(index);
        TrieNode node = current.children.get(ch);
        if (node == null) {
            return false;
        }
        boolean id6 = delete(node, word, index + 1);

        

        

        if (id6) {
            current.children.remove(ch);
            

            return current.children.size() == 0;
        }
        return false;
    }

    

    static boolean isPrime(long n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (long i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }

    static Pair<Integer, Integer> lowerBound(long[] a, long x) { 

                                                                 

        int l = -1, r = a.length;
        while (l + 1 < r) {
            int m = (l + r) >>> 1;
            if (a[m] == x) {
                return new Pair<>(m, 1);
            }
            if (a[m] >= x)
                r = m;
            else
                l = m;
        }
        return new Pair<>(r, 0);
    }

    static Pair<Integer, Integer> upperBound(long[] a, long x) {

        int l = -1, r = a.length;
        while (l + 1 < r) {
            int m = (l + r) >>> 1;
            if (a[m] == x) {
                return new Pair<>(m, 1);
            }
            if (a[m] <= x)
                l = m;
            else
                r = m;
        }
        return new Pair<>(l + 1, 0);
    }

    static long gcd(long a, long b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    static long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    static long power(long x, long y) {
        long res = 1;
        while (y > 0) {
            if (y % 2 == 1)
                res = (res * x);
            y >>= 1;
            x = (x * x);
        }
        return res;
    }

    public double binPow(double x, int n) {

        if (n == 0)
            return 1.0;
        double binPow = binPow(x, n / 2);
        if (n % 2 == 0) {
            return binPow * binPow;
        } else {
            return n > 0 ? (binPow * binPow * x) : (binPow * binPow / x);
        }
    }

    static long ceil(long x, long y) {
        return (x % y == 0 ? x / y : (x / y + 1));
    }

    
    static long modPower(long x, long y, long p) {
        long res = 1;
        x = x % p;
        while (y > 0) {
            if (y % 2 == 1)
                res = (res * x) % p;
            y = y >> 1; 

            x = (x * x) % p;
        }
        return res;
    }

    static long modInverse(long n, long p) {
        return modPower(n, p - 2, p);
    }

    static long modAdd(long a, long b) {
        return ((a + b + mod) % mod);
    }

    static long modMul(long a, long b) {
        return ((a % mod) * (b % mod)) % mod;
    }

    static long[] fac = new long[200000 + 5];
    static long[] invFac = new long[200000 + 5];

    static long id9(int n, int r) {
        if (r == 0)
            return 1;
        

        

        return (fac[n] * invFac[r] % mod * invFac[n - r] % mod) % mod;
    }

    

    static void id0(long[] a) {
        int n = a.length;
        Random r = new Random();
        for (int i = 0; i < a.length; i++) {
            int oi = r.nextInt(n);
            long temp = a[i];
            a[i] = a[oi];
            a[oi] = temp;
        }
        Arrays.sort(a);
    }

    static void id0(int[] a) {
        int n = a.length;
        Random r = new Random();
        for (int i = 0; i < a.length; i++) {
            int oi = r.nextInt(n);
            int temp = a[i];
            a[i] = a[oi];
            a[oi] = temp;
        }
        Arrays.sort(a);
    }

    static boolean id5(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    static String id1(int n) {
        StringBuilder str = new StringBuilder("");
        String bin = Integer.toBinaryString(n);
        if (bin.length() != 32) {
            for (int k = 0; k < 32 - bin.length(); k++) {
                str.append("0");
            }
            str.append(bin);
        }
        return str.toString();
    }

    static class id7 {
        public static int st[][];
        public static int log = 4;

        static int func(int a, int b) {

            return (int) gcd(a, b);
        }

        void makeTable(int n, int a[]) {

            st = new int[n][log];
            for (int i = 0; i < n; i++) {
                st[i][0] = a[i];
            }
            for (int j = 1; j < log; j++) {
                for (int i = 0; i + (1 << j) <= n; i++) {
                    st[i][j] = func(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
                }
            }
        }

        static int query(int l, int r) {
            int length = r - l + 1;
            int k = 0;
            while ((1 << (k + 1)) <= length) {
                k++;
            }
            return func(st[l][k], st[r - (1 << k) + 1][k]);
        }

        static void printTable(int n) {
            for (int j = 0; j < log; j++) {
                for (int i = 0; i < n; i++) {
                    System.out.print(st[i][j] + " ");
                }
                System.out.println();
            }
        }
    }

    

    


    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    


    

    

    


    public static long id3(long[] A, long k) {
        int l = 0, r = A.length, m;
        while (l < r) {
            m = (l + r) / 2;
            if (A[m] - 1 - m < k)
                l = m + 1;
            else
                r = m;
        }
        return l + k;
    }

    static int[] z_function(char ar[]) {
        int[] z = new int[ar.length];
        z[0] = ar.length;
        int l = 0;
        int r = 0;
        for (int i = 1; i < ar.length; i++) {
            if (r < i) {
                l = i;
                r = i;
                while (r < ar.length && ar[r - l] == ar[r])
                    r++;
                z[i] = r - l;
                r--;
            } else {
                int k = i - l;
                if (z[k] < r - i + 1) {
                    z[i] = z[k];
                } else {
                    l = i;
                    while (r < ar.length && ar[r - l] == ar[r])
                        r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }

    static void mergeSort(int a[]) {
        int n = a.length;
        if (n >= 2) {
            int mid = n / 2;
            int left[] = new int[mid];
            int right[] = new int[n - mid];
            for (int i = 0; i < mid; i++) {
                left[i] = a[i];
            }
            for (int i = mid; i < n; i++) {
                right[i - mid] = a[i];
            }
            mergeSort(left);
            mergeSort(right);
            id8(left, right, a);
        }
    }

    static void id8(int left[], int right[], int a[]) {
        int i = 0, j = 0, k = 0, n = left.length, m = right.length;
        while (i != n && j != m) {
            if (left[i] < right[j]) {
                a[k++] = left[i++];
            } else {
                a[k++] = right[j++];
            }
        }
        while (i != n) {
            a[k++] = left[i++];
        }
        while (j != m) {
            a[k++] = right[j++];
        }
    }

    

    

    

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
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

        int[] intArr(int n) {
            int res[] = new int[n];
            for (int i = 0; i < n; i++)
                res[i] = nextInt();
            return res;
        }

        long[] longArr(int n) {
            long res[] = new long[n];
            for (int i = 0; i < n; i++)
                res[i] = nextLong();
            return res;
        }
    }

    static FastReader f = new FastReader();
    static BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));
    static long dp[][];

    public static void main(String args[]) throws Exception {
        int t = 1;
        t = f.nextInt();
        int tc = 1;
        

        

        

        

        

        while (t-- != 0) {
            int n = f.nextInt();
            int flag = 0;
            ArrayList<String> ar = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String q = f.next();
                ar.add(q);
                String rev = new StringBuilder(q).reverse().toString();
                if ((rev.equals(q))) {
                    flag = 1;
                }
            }
            if (flag == 1) {
                w.write("YES\n");
            } else {
                

                HashMap<String, HashSet<String>> map = new HashMap<>();
                for (String i : ar) {
                    String rev = new StringBuilder(i).reverse().toString();
                    if (i.length() == 2) {
                        if (map.get(rev) != null) {
                            flag = 1;
                            break;
                        } 
                    } else {
                        String x = rev.substring(0, 2);
                        if (map.get(x) != null) {
                            if (map.get(x).contains(rev) || map.get(x).contains(rev.subSequence(0, 2))) {
                                flag = 1;
                                break;
                            } 
                        } 
                    }
                    if (map.get(i.substring(0, 2)) == null)
                        map.put(i.substring(0, 2), new HashSet<>());
                    map.get(i.substring(0, 2)).add(i);
                }
                if (flag == 1) {
                    w.write("YES\n");
                } else {
                    w.write("NO\n");
                }
            }

        }
        w.flush();
    }
}
