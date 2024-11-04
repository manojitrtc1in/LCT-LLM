import java.io.*;
import java.math.BigInteger;

import java.util.*;


public class id9 {

    static class id11 extends PrintWriter {

        private BufferedReader r;
        private StringTokenizer st;
        


        public id11() {
            this(System.in, System.out);
        }

        public id11(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }
        


        public id11(String problemName) throws IOException {
            super(problemName + ".out");
            r = new BufferedReader(new FileReader(problemName + ".in"));
        }
        


        String nextLine() {
            String str = "";
            try {
                str = r.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        public String next() {
            try {
                while (st == null || !st.hasMoreTokens()) {
                    st = new StringTokenizer(r.readLine());
                }
                return st.nextToken();
            } catch (Exception e) {
            }
            return null;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    

    static id11 input = new id11();
    static BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
    static ArrayList<ArrayList<Integer>> powerSet = new ArrayList<>();
    static ArrayList<LinkedList<Integer>> allprem = new ArrayList<>();
    static ArrayList<LinkedList<String>> id7 = new ArrayList<>();
    static ArrayList<Long> luc = new ArrayList<>();
    static long mod = (long) (Math.pow(10, 9) + 7);
    static long dp[][];
    static int ind = 0;

    public static void main(String[] args) throws IOException {
        int test = input.nextInt();
        loop:
        while (test-- > 0) {
            int n = input.nextInt();
            int a[] = new int[n];
            int sum = 2 + 4 + 6 + 8;
            TreeSet<Integer> s = new TreeSet<>();
            boolean ca = false;
            for (int i = 0; i < n; i++) {
                a[i] = input.nextInt();
                s.add(a[i]);
                if (a[i] == 0) {
                    ca = true;
                }
            }
            if (ca && s.size() > 1) {
                log.write("No\n");
                continue;
            } else if (ca || s.size() == 1) {
                log.write("Yes\n");
                continue;
            }
            ca = false;
            s = new TreeSet<>();
            for (int i = 0; i < n; i++) {
                if (a[i] % 10 == 5) {
                    ca = true;
                    a[i] += 5;

                } else if (a[i] % 10 == 0) {
                    ca = true;
                }
                s.add(a[i]);
            }
            if (ca) {
                if (s.size() > 1) {
                    log.write("No\n");
                } else {
                    log.write("Yes\n");
                }
                continue;
            }
            int max = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] % 10 == 7) {
                    a[i] += 7;
                    a[i] += (4 + 6 + 8);
                } else if (a[i] % 10 == 9) {
                    a[i] += 9;
                    a[i] += 8;
                    a[i] += 6;
                } else if (a[i] % 10 == 8) {
                    a[i] += 8;
                    a[i] += 6;
                } else if (a[i] % 10 == 6) {
                    a[i] += 6;
                } else if (a[i] % 10 == 3) {
                    a[i] += 3;
                    a[i] += 6;
                } else if (a[i] % 10 == 1) {
                    a[i]++;
                } else if (a[i] % 10 == 4) {
                    a[i] += (sum - 2);
                }
                max = Math.max(a[i], max);
            }
            for (int i = 0; i < n; i++) {
                int d = max - a[i];
                int l = d / sum;
                a[i] += (l * sum);
                while (a[i] < max) {
                    a[i] += (a[i] % 10);
                }
                if (a[i] != max) {
                    log.write("No\n");
                    continue loop;
                }
            }
            log.write("Yes\n");
        }
        log.flush();
    }

    public static void id10(Queue<Integer> a) {
        int n = a.poll();
        if (!a.isEmpty()) {
            id10(a);
        }
        int s = powerSet.size();
        for (int i = 0; i < s; i++) {
            ArrayList<Integer> ne = new ArrayList<>();
            ne.add(n);
            for (int j = 0; j < powerSet.get(i).size(); j++) {
                ne.add(powerSet.get(i).get(j));
            }

            powerSet.add(ne);
        }
        ArrayList<Integer> p = new ArrayList<>();
        p.add(n);
        powerSet.add(p);
    }

    public static int getlo(int va) {
        int v = 1;
        while (v <= va) {
            if ((va&v) != 0) {
                return v;
            }
            v <<= 1;
        }
        return 0;
    }

    static long fast_pow(long a, long p) {
        long res = 1;
        while (p > 0) {
            if (p % 2 == 0) {
                a = (a * a) % mod;
                p /= 2;
            } else {
                res = (res * a) % mod;
                p--;
            }
        }
        return res;
    }

    public static int id20(int n, boolean isPrime[]) {
        int cnt = 0;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * 2; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                cnt++;
            }
        }
        return cnt;
    }

    public static void create(long num) {
        luc.add(num);
        if (num > power(10, 9)) {
            return;
        }
        create(num * 10 + 4);
        create(num * 10 + 7);
    }

    public static long ceil(long a, long b) {
        return (a + b - 1) / b;
    }

    public static long round(long a, long b) {
        if (a < 0) {
            return (a - b / 2) / b;
        }
        return (a + b / 2) / b;
    }

    public static void id2(LinkedList<String> l, boolean visited[], ArrayList<String> st) {
        if (l.size() == st.size()) {
            id7.add(l);
        }
        for (int i = 0; i < st.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                LinkedList<String> nl = new LinkedList<>();
                for (String x : l) {
                    nl.add(x);
                }
                nl.add(st.get(i));
                id2(nl, visited, st);
                visited[i] = false;
            }
        }
    }

    public static void id19(LinkedList<Integer> l, boolean visited[], int a[]) {
        if (l.size() == a.length) {
            allprem.add(l);
        }
        for (int i = 0; i < a.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                LinkedList<Integer> nl = new LinkedList<>();
                for (Integer x : l) {
                    nl.add(x);
                }
                nl.add(a[i]);
                id19(nl, visited, a);
                visited[i] = false;
            }
        }
    }

    public static int binarySearch(long[] a, long value) {
        int l = 0;
        int r = a.length - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] == value) {
                return m;
            } else if (a[m] > value) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }

    public static void reverse(int l, int r, char ch[]) {
        for (int i = 0; i < r / 2; i++) {
            char c = ch[i];
            ch[i] = ch[r - i - 1];
            ch[r - i - 1] = c;
        }
    }

    public static int logK(long v, long k) {
        int ans = 0;
        while (v > 1) {
            ans++;
            v /= k;
        }
        return ans;
    }

    public static long power(long a, long n) {
        if (n == 1) {
            return a;
        }
        long pow = power(a, n / 2);
        pow *= pow;
        if (n % 2 != 0) {
            pow *= a;
        }
        return pow;
    }

    public static long get(long max, long x) {
        if (x == 1) {
            return max;
        }
        int cnt = 0;
        while (max > 0) {
            cnt++;
            max /= x;
        }
        return cnt;
    }

    public static int id8(long v) {
        long x = 1;
        int cnt = 0;
        while (x <= v) {
            if ((x & v) == 0) {
                cnt++;
            }
            x <<= 1;
        }
        return cnt;
    }

    public static int log2(double n) {
        int cnt = 0;
        while (n > 1) {
            n /= 2;
            cnt++;
        }
        return cnt;
    }

    public static int[] bfs(int node, ArrayList<Integer> a[]) {
        Queue<Integer> q = new LinkedList<>();
        q.add(node);
        int distances[] = new int[a.length];
        Arrays.fill(distances, -1);
        distances[node] = 0;
        while (!q.isEmpty()) {
            int parent = q.poll();
            ArrayList<Integer> nodes = a[parent];
            int cost = distances[parent];
            for (Integer node1 : nodes) {
                if (distances[node1] == -1) {
                    q.add(node1);
                    distances[node1] = cost + 1;
                }
            }
        }
        return distances;
    }

    public static int get(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public static ArrayList<Integer> primeFactors(int n) {
        ArrayList<Integer> a = new ArrayList<>();
        while (n % 2 == 0) {
            a.add(2);
            n /= 2;
        }
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            while (n % i == 0) {
                a.add(i);
                n /= i;
            }
            if (n < i) {
                break;
            }
        }
        if (n > 2) {

            a.add(n);
        }
        return a;
    }

    public static ArrayList<Integer> id13(int n) {
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 1; i < Math.sqrt(n) + 1; i++) {
            if (n % i == 0) {
                if (isPrime(i)) {
                    a.add(i);
                    n /= i;
                    i = 0;
                } else if (isPrime(n / i)) {
                    a.add(n / i);
                    n = i;
                    i = 0;
                }
            }
        }
        return a;
    }



    public static BigInteger f(long n) {
        if (n <= 1) {
            return BigInteger.ONE;
        }
        long t = n - 1;
        BigInteger b = new BigInteger(t + "");
        BigInteger ans = new BigInteger(n + "");
        while (t > 1) {
            ans = ans.multiply(b);
            b = b.subtract(BigInteger.ONE);
            t--;
        }
        return ans;
    }

    public static long factorial(long n) {
        if (n <= 1) {
            return 1;
        }
        long t = n - 1;
        while (t > 1) {
            n = mod((mod(n, mod) * mod(t, mod)), mod);
            t--;
        }
        return n;
    }

    public static long rev(long n) {
        long t = n;
        long ans = 0;
        while (t > 0) {
            ans = ans * 10 + t % 10;
            t /= 10;
        }
        return ans;
    }

    public static boolean isPalindrome(int n) {
        int t = n;
        int ans = 0;
        while (t > 0) {
            ans = ans * 10 + t % 10;
            t /= 10;
        }
        return ans == n;

    }

    static class tri {

        int x, y, z;

        public tri(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

    }

    static boolean isPrime(long num) {
        if (num == 1) {
            return false;
        }
        if (num == 2) {
            return true;
        }
        if (num % 2 == 0) {
            return false;
        }
        if (num == 3) {
            return true;
        }
        for (int i = 3; i <= Math.sqrt(num) + 1; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void prefixSum(long[] a) {
        for (int i = 1; i < a.length; i++) {
            a[i] = a[i] + a[i - 1];
        }
    }

    public static void suffixSum(long[] a) {
        for (int i = a.length - 2; i > -1; i--) {
            a[i] = a[i] + a[i + 1];
        }
    }

    static long mod(long a, long b) {
        long r = a % b;
        return r < 0 ? r + b : r;
    }

    public static long id17(String w) {
        long r = 0;
        long l = 0;
        for (int i = w.length() - 1; i > -1; i--) {
            long x = (w.charAt(i) - '0') * (long) Math.pow(2, l);
            r = r + x;
            l++;
        }
        return r;
    }

    public static String id4(long n) {
        String w = "";
        while (n > 0) {
            w = n % 2 + w;
            n /= 2;
        }
        return w;
    }

    public static boolean isSorted(int[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] >= a[i + 1]) {
                return false;
            }
        }
        return true;
    }

    public static void print(int[] a) throws IOException {
        for (int i = 0; i < a.length; i++) {
            log.write(a[i] + " ");
        }
        log.write("\n");
    }

    public static void read(int[] a) {
        for (int i = 0; i < a.length; i++) {
            a[i] = input.nextInt();

        }
    }

    static class pair {

        int x;
        int y;

        public pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return x + " " + y;
        }
    }

    public static long LCM(long x, long y) {
        return x / GCD(x, y) * y;
    }

    public static long GCD(long x, long y) {
        if (y == 0) {
            return x;
        }
        return GCD(y, x % y);
    }

    public static void id14(long a, long b) {
        long GCD = GCD(a, b);
        System.out.println(a / GCD + " " + b / GCD);

    }

     

    static class id0<T extends Comparable<T>> {

        
        public static final int BLACK = 0;
        
        public static final int RED = 1;
        

        public T key;

        
        id0<T> parent;
        
        id0<T> left;
        
        id0<T> right;
        

        public int numLeft = 0;
        

        public int numRight = 0;
        

        public int color;

        id0() {
            color = BLACK;
            numLeft = 0;
            numRight = 0;
            parent = null;
            left = null;
            right = null;
        }

        

        id0(T key) {
            this();
            this.key = key;
        }
    }


    static class id6<T extends Comparable<T>> {

        

        private id0<T> nil = new id0<T>();
        private id0<T> root = nil;

        public id6() {
            root.left = nil;
            root.right = nil;
            root.parent = nil;
        }

        

        

        private void leftRotate(id0<T> x) {

            

            

            id23(x);

            

            

            id0<T> y;
            y = x.right;
            x.right = y.left;

            

            if (!isNil(y.left)) {
                y.left.parent = x;
            }
            y.parent = x.parent;

            

            if (isNil(x.parent)) {
                root = y;
            } 

            else if (x.parent.left == x) {
                x.parent.left = y;
            } 

            else {
                x.parent.right = y;
            }

            

            y.left = x;
            x.parent = y;
        }


        

        

        private void id23(id0 x) {

            

            if (isNil(x.left) && isNil(x.right.left)) {
                x.numLeft = 0;
                x.numRight = 0;
                x.right.numLeft = 1;
            } 

            else if (isNil(x.left) && !isNil(x.right.left)) {
                x.numLeft = 0;
                x.numRight = 1 + x.right.left.numLeft
                        + x.right.left.numRight;
                x.right.numLeft = 2 + x.right.left.numLeft
                        + x.right.left.numRight;
            } 

            else if (!isNil(x.left) && isNil(x.right.left)) {
                x.numRight = 0;
                x.right.numLeft = 2 + x.left.numLeft + x.left.numRight;

            } 

            else {
                x.numRight = 1 + x.right.left.numLeft
                        + x.right.left.numRight;
                x.right.numLeft = 3 + x.left.numLeft + x.left.numRight
                        + x.right.left.numLeft + x.right.left.numRight;
            }

        }


        

        

        private void rightRotate(id0<T> y) {

            

            id16(y);

            

            id0<T> x = y.left;
            y.left = x.right;

            

            if (!isNil(x.right)) {
                x.right.parent = y;
            }
            x.parent = y.parent;

            

            if (isNil(y.parent)) {
                root = x;
            } 

            else if (y.parent.right == y) {
                y.parent.right = x;
            } 

            else {
                y.parent.left = x;
            }
            x.right = y;

            y.parent = x;

        }


        

        

        private void id16(id0 y) {

            

            if (isNil(y.right) && isNil(y.left.right)) {
                y.numRight = 0;
                y.numLeft = 0;
                y.left.numRight = 1;
            } 

            else if (isNil(y.right) && !isNil(y.left.right)) {
                y.numRight = 0;
                y.numLeft = 1 + y.left.right.numRight
                        + y.left.right.numLeft;
                y.left.numRight = 2 + y.left.right.numRight
                        + y.left.right.numLeft;
            } 

            else if (!isNil(y.right) && isNil(y.left.right)) {
                y.numLeft = 0;
                y.left.numRight = 2 + y.right.numRight + y.right.numLeft;

            } 

            else {
                y.numLeft = 1 + y.left.right.numRight
                        + y.left.right.numLeft;
                y.left.numRight = 3 + y.right.numRight
                        + y.right.numLeft
                        + y.left.right.numRight + y.left.right.numLeft;
            }

        }


        public void insert(T key) {
            insert(new id0<T>(key));
        }

        

        

        

        private void insert(id0<T> z) {

            

            id0<T> y = nil;
            id0<T> x = root;

            

            

            while (!isNil(x)) {
                y = x;

                

                if (z.key.compareTo(x.key) < 0) {

                    

                    x.numLeft++;
                    x = x.left;
                } 

                else {

                    

                    x.numRight++;
                    x = x.right;
                }
            }
            

            z.parent = y;

            

            

            if (isNil(y)) {
                root = z;
            } else if (z.key.compareTo(y.key) < 0) {
                y.left = z;
            } else {
                y.right = z;
            }

            

            z.left = nil;
            z.right = nil;
            z.color = id0.RED;

            

            id12(z);

        }


        

        

        

        

        private void id12(id0<T> z) {

            id0<T> y = nil;
            

            while (z.parent.color == id0.RED) {

                

                if (z.parent == z.parent.parent.left) {

                    

                    y = z.parent.parent.right;

                    

                    if (y.color == id0.RED) {
                        z.parent.color = id0.BLACK;
                        y.color = id0.BLACK;
                        z.parent.parent.color = id0.RED;
                        z = z.parent.parent;
                    } 

                    else if (z == z.parent.right) {

                        

                        z = z.parent;
                        leftRotate(z);
                    } 

                    else {
                        

                        z.parent.color = id0.BLACK;
                        z.parent.parent.color = id0.RED;
                        rightRotate(z.parent.parent);
                    }
                } 

                else {

                    

                    y = z.parent.parent.left;

                    

                    if (y.color == id0.RED) {
                        z.parent.color = id0.BLACK;
                        y.color = id0.BLACK;
                        z.parent.parent.color = id0.RED;
                        z = z.parent.parent;
                    } 

                    else if (z == z.parent.left) {
                        

                        z = z.parent;
                        rightRotate(z);
                    } 

                    else {
                        

                        z.parent.color = id0.BLACK;
                        z.parent.parent.color = id0.RED;
                        leftRotate(z.parent.parent);
                    }
                }
            }
            

            root.color = id0.BLACK;

        }


        

        

        public id0<T> treeMinimum(id0<T> node) {

            

            while (!isNil(node.left)) {
                node = node.left;
            }
            return node;
        }


        

        

        

        public id0<T> id1(id0<T> x) {

            

            

            if (!isNil(x.left)) {
                return treeMinimum(x.right);
            }

            id0<T> y = x.parent;

            

            while (!isNil(y) && x == y.right) {
                

                x = y;
                y = y.parent;
            }
            

            return y;
        }


        

        

        public void remove(id0<T> v) {

            id0<T> z = search(v.key);

            

            id0<T> x = nil;
            id0<T> y = nil;

            

            if (isNil(z.left) || isNil(z.right)) {
                y = z;
            } 

            else {
                y = id1(z);
            }

            

            if (!isNil(y.left)) {
                x = y.left;
            } else {
                x = y.right;
            }

            

            x.parent = y.parent;

            

            if (isNil(y.parent)) {
                root = x;
            } 

            else if (!isNil(y.parent.left) && y.parent.left == y) {
                y.parent.left = x;
            } 

            else if (!isNil(y.parent.right) && y.parent.right == y) {
                y.parent.right = x;
            }

            

            if (y != z) {
                z.key = y.key;
            }

            

            

            id3(x, y);

            

            

            if (y.color == id0.BLACK) {
                id15(x);
            }
        }


        

        

        private void id3(id0<T> x, id0<T> y) {

            

            id0<T> current = nil;
            id0<T> track = nil;

            

            

            if (isNil(x)) {
                current = y.parent;
                track = y;
            } 

            

            else {
                current = x.parent;
                track = x;
            }

            

            while (!isNil(current)) {
                

                

                if (y.key != current.key) {

                    

                    

                    if (y.key.compareTo(current.key) > 0) {
                        current.numRight--;
                    }

                    

                    

                    if (y.key.compareTo(current.key) < 0) {
                        current.numLeft--;
                    }
                } 

                

                else {
                    

                    

                    if (isNil(current.left)) {
                        current.numLeft--;
                    } else if (isNil(current.right)) {
                        current.numRight--;
                    } 

                    

                    

                    else if (track == current.right) {
                        current.numRight--;
                    } else if (track == current.left) {
                        current.numLeft--;
                    }
                }

                

                track = current;
                current = current.parent;

            }

        }


        

        

        

        private void id15(id0<T> x) {

            id0<T> w;

            

            while (x != root && x.color == id0.BLACK) {

                

                if (x == x.parent.left) {

                    

                    w = x.parent.right;

                    

                    if (w.color == id0.RED) {
                        w.color = id0.BLACK;
                        x.parent.color = id0.RED;
                        leftRotate(x.parent);
                        w = x.parent.right;
                    }

                    

                    if (w.left.color == id0.BLACK
                            && w.right.color == id0.BLACK) {
                        w.color = id0.RED;
                        x = x.parent;
                    } 

                    else {
                        

                        if (w.right.color == id0.BLACK) {
                            w.left.color = id0.BLACK;
                            w.color = id0.RED;
                            rightRotate(w);
                            w = x.parent.right;
                        }
                        

                        w.color = x.parent.color;
                        x.parent.color = id0.BLACK;
                        w.right.color = id0.BLACK;
                        leftRotate(x.parent);
                        x = root;
                    }
                } 

                else {

                    

                    w = x.parent.left;

                    

                    if (w.color == id0.RED) {
                        w.color = id0.BLACK;
                        x.parent.color = id0.RED;
                        rightRotate(x.parent);
                        w = x.parent.left;
                    }

                    

                    if (w.right.color == id0.BLACK
                            && w.left.color == id0.BLACK) {
                        w.color = id0.RED;
                        x = x.parent;
                    } 

                    else {
                        

                        if (w.left.color == id0.BLACK) {
                            w.right.color = id0.BLACK;
                            w.color = id0.RED;
                            leftRotate(w);
                            w = x.parent.left;
                        }

                        

                        w.color = x.parent.color;
                        x.parent.color = id0.BLACK;
                        w.left.color = id0.BLACK;
                        rightRotate(x.parent);
                        x = root;
                    }
                }
            }


            

            

            x.color = id0.BLACK;
        }


        

        

        

        

        public id0<T> search(T key) {

            

            id0<T> current = root;

            

            while (!isNil(current)) {

                

                if (current.key.equals(key)) 

                {
                    return current;
                } 

                else if (current.key.compareTo(key) < 0) {
                    current = current.right;
                } 

                else {
                    current = current.left;
                }
            }

            

            return null;

        }


        

        

        public int numGreater(T key) {

            

            

            return id5(root, key);

        }


        

        

        public int id22(T key) {

            

            

            return id21(root, key);

        }


        

        

        

        public int id5(id0<T> node, T key) {

            

            if (isNil(node)) {
                return 0;
            } 

            

            else if (key.compareTo(node.key) < 0) {
                return 1 + node.numRight + id5(node.left, key);
            } 

            

            else {
                return id5(node.right, key);
            }

        }


        
        public List<T> id18(T key, Integer maxReturned) {
            List<T> list = new ArrayList<T>();
            id18(root, key, list);
            return list.subList(0, Math.min(maxReturned, list.size()));
        }

        private void id18(id0<T> node, T key,
                List<T> list) {
            if (isNil(node)) {
                return;
            } else if (node.key.compareTo(key) > 0) {
                id18(node.left, key, list);
                list.add(node.key);
                id18(node.right, key, list);
            } else {
                id18(node.right, key, list);
            }
        }

        

        

        

        public int id21(id0<T> node, T key) {

            

            if (isNil(node)) {
                return 0;
            } 

            

            else if (key.compareTo(node.key) <= 0) {
                return id21(node.left, key);
            } 

            

            

            else {
                return 1 + node.numLeft + id21(node.right, key);
            }

        }


        

        

        private boolean isNil(id0 node) {

            

            return node == nil;

        }


        

        

        

        public int size() {
            

            

            return root.numLeft + root.numRight + 1;
        }


    }

}