import java.io.*;
import java.math.BigInteger;

import java.util.*;


public class id7 {

    static class id8 extends PrintWriter {

        private BufferedReader r;
        private StringTokenizer st;
        


        public id8() {
            this(System.in, System.out);
        }

        public id8(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }
        


        public id8(String problemName) throws IOException {
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

    

    static id8 input = new id8();
    static BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
    static ArrayList<ArrayList<Integer>> powerSet = new ArrayList<>();
    static ArrayList<LinkedList<Integer>> allprem = new ArrayList<>();
    static int mod = (int) (Math.pow(10, 9) + 7);
    static int dp[][];
    static long a[] = new long[100000];

    public static void main(String[] args) throws IOException {
        int t = input.nextInt();
        loop:
        while (t-- > 0) {
            int n = input.nextInt();
            log.write("2\n");
            TreeSet<Integer> s = new TreeSet<>();
            for (int i = 0; i < n; i++) {
                s.add(i + 1);
            }

            while (!s.isEmpty()) {
                int v = s.pollFirst();
                while (v <= n) {
                    log.write(v + " ");
                    s.remove(v);
                    v *= 2;
                }
            }
            log.write("\n");
        }
        log.flush();
    }

    public static void id16(LinkedList<Integer> l, boolean visited[], int a[]) {
        if (l.size() == a.length) {
            allprem.add(l);
        }
        for (int i = 0; i < 5; i++) {
            if (!visited[i]) {
                visited[i] = true;
                LinkedList<Integer> nl = new LinkedList<>();
                for (Integer x : l) {
                    nl.add(x);
                }
                nl.add(a[i]);
                id16(nl, visited, a);
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

    public static int id6(long v) {
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

    public static int log2(long n) {
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

    public static ArrayList<Integer> id10(int n) {
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

    public static int rev(int n) {
        int t = n;
        int ans = 0;
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

    public static long id14(String w) {
        long r = 0;
        long l = 0;
        for (int i = w.length() - 1; i > -1; i--) {
            long x = (w.charAt(i) - '0') * (long) Math.pow(2, l);
            r = r + x;
            l++;
        }
        return r;
    }

    public static String id3(long n) {
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

    public static void print(int a[]) throws IOException {
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
        double y;

        public pair(int x, double y) {
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

    public static void id11(long a, long b) {
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


    static class id5<T extends Comparable<T>> {

        

        private id0<T> nil = new id0<T>();
        private id0<T> root = nil;

        public id5() {
            root.left = nil;
            root.right = nil;
            root.parent = nil;
        }

        

        

        private void leftRotate(id0<T> x) {

            

            

            id19(x);

            

            

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


        

        

        private void id19(id0 x) {

            

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

            

            id13(y);

            

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


        

        

        private void id13(id0 y) {

            

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

            

            id9(z);

        }


        

        

        

        

        private void id9(id0<T> z) {

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

            

            

            id2(x, y);

            

            

            if (y.color == id0.BLACK) {
                id12(x);
            }
        }


        

        

        private void id2(id0<T> x, id0<T> y) {

            

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


        

        

        

        private void id12(id0<T> x) {

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

            

            

            return id4(root, key);

        }


        

        

        public int id18(T key) {

            

            

            return id17(root, key);

        }


        

        

        

        public int id4(id0<T> node, T key) {

            

            if (isNil(node)) {
                return 0;
            } 

            

            else if (key.compareTo(node.key) < 0) {
                return 1 + node.numRight + id4(node.left, key);
            } 

            

            else {
                return id4(node.right, key);
            }

        }


        
        public List<T> id15(T key, Integer maxReturned) {
            List<T> list = new ArrayList<T>();
            id15(root, key, list);
            return list.subList(0, Math.min(maxReturned, list.size()));
        }

        private void id15(id0<T> node, T key,
                List<T> list) {
            if (isNil(node)) {
                return;
            } else if (node.key.compareTo(key) > 0) {
                id15(node.left, key, list);
                list.add(node.key);
                id15(node.right, key, list);
            } else {
                id15(node.right, key, list);
            }
        }

        

        

        

        public int id17(id0<T> node, T key) {

            

            if (isNil(node)) {
                return 0;
            } 

            

            else if (key.compareTo(node.key) <= 0) {
                return id17(node.left, key);
            } 

            

            

            else {
                return 1 + node.numLeft + id17(node.right, key);
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
