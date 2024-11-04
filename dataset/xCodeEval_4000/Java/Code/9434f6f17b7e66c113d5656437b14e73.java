

import java.io.*;
import java.util.*;


public class IceCave {

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
    }
    

    static FastReader input = new FastReader();
    static BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
    static ArrayList<ArrayList<Long>> powerSet = new ArrayList<>();
    static long mod = (long) (Math.pow(10, 9) + 7);
    static int dp[];

    public static void main(String[] args) throws IOException {
        int t = input.nextInt();
        int cnt = 0;
        boolean ca = false;
        loop:
        while (t-- > 0) {
            cnt++;
            int n = input.nextInt();
            if (cnt == 2 && n == 3) {
                ca = true;
            }
            int a[] = new int[n];
            int b[] = new int[n];
            Integer sa[] = new Integer[n];
            Integer sb[] = new Integer[n];
            ArrayList<pair> ans = new ArrayList<>();
            boolean visited[] = new boolean[n];
            int fre[] = new int[n];
            for (int i = 0; i < n; i++) {
                fre[i] = i;
            }
            TreeMap<pair, TreeSet<Integer>> tr = new TreeMap<>(new Comparator<pair>() {
                @Override
                public int compare(pair o1, pair o2) {
                    if (o1.x > o2.x) {
                        return 1;
                    } else if (o1.x < o2.x) {
                        return -1;
                    } else {
                        if (o1.y > o2.y) {
                            return 1;
                        } else if (o1.y < o2.y) {
                            return -1;
                        } else {
                            return 0;
                        }
                    }
                }
            });
            TreeMap<pair, Integer> r = new TreeMap<>(new Comparator<pair>() {
                @Override
                public int compare(pair o1, pair o2) {
                    if (o1.x > o2.x) {
                        return 1;
                    } else if (o1.x < o2.x) {
                        return -1;
                    } else {
                        if (o1.y > o2.y) {
                            return 1;
                        } else if (o1.y < o2.y) {
                            return -1;
                        } else {
                            return 0;
                        }
                    }
                }
            });

            for (int i = 0; i < n; i++) {
                a[i] = input.nextInt();
                sa[i] = a[i];
            }
            for (int i = 0; i < n; i++) {
                b[i] = input.nextInt();
                sb[i] = b[i];
            }

            Arrays.sort(sa);
            Arrays.sort(sb);
            for (int i = 0; i < n; i++) {
                pair p = new pair(a[i], b[i]);
                if (tr.get(p) == null) {
                    TreeSet<Integer> l = new TreeSet<>();
                    l.add(i);
                    tr.put(p, l);
                } else {
                    TreeSet<Integer> l = tr.get(p);
                    l.add(i);
                    tr.put(p, l);
                }
                r.put(new pair(a[i], b[i]), r.get(new pair(a[i], b[i])) == null ? 1 : r.get(new pair(a[i], b[i])) + 1);
            }
            
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    continue;
                }
                if (tr.get(new pair(sa[i], sb[i])) == null || r.get(new pair(sa[i], sb[i])) == 0) {
                    System.out.println("-1");
                    continue loop;
                }
                if (tr.get(new pair(sa[i], sb[i])).contains(i)) {
                    r.put(new pair(sa[i], sb[i]), r.get(new pair(sa[i], sb[i])) - 1);
                    continue;
                }
                r.put(new pair(sa[i], sb[i]), r.get(new pair(sa[i], sb[i])) - 1);
            }

            for (int i = 0; i < n; i++) {
                TreeSet<Integer> s = tr.get(new pair(sa[i], sb[i]));










                int ind = s.pollFirst();
                if (i == ind) {
                    continue;
                }
                ans.add(new pair(ind + 1, i + 1));
                tr.get(new pair(a[i], b[i])).add(ind);
                tr.get(new pair(a[i], b[i])).remove(i);
                int x = a[i];
                a[i] = a[ind];
                a[ind] = x;
                x = b[i];
                b[i] = b[ind];
                b[ind] = x;
            }
            System.out.println(ans.size());
            for (pair an : ans) {
                System.out.println(an);
            }
            log.flush();
        }
    }

    public static void graphRepresintionWithCycle(ArrayList<Integer>[] a, int q) {
        for (int i = 0; i < a.length; i++) {
            a[i] = new ArrayList<>();
        }
        while (q-- > 0) {
            int x = input.nextInt();
            int y = input.nextInt();
            a[x].add(y);
            a[y].add(x);
        }
    }

    public static void dfsRecursive(int n, ArrayList<Integer>[] a, boolean visited[]) {
        ArrayList<Integer> nodes = a[n];
        visited[n] = true;
        for (Integer node : nodes) {
            if (!visited[node]) {
                dfsRecursive(node, a, visited);
            }
        }
    }

    public static int get(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public static int primeFactors(int n) {
        int sum = 0;
        while (n % 2 == 0) {
            sum += 2;
            n /= 2;
        }
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            while (n % i == 0) {
                sum += get(i);
                n /= i;
            }
            if (n < i) {
                break;
            }
        }
        if (n > 2) {
            sum += get(n);
        }
        return sum;
    }

    public static ArrayList<Integer> printPrimeFactoriztion(int n) {
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

    public static void genrate(int ind, long[] a, ArrayList<Long> sub) {
        if (ind == a.length) {
            powerSet.add(sub);
            return;
        }
        ArrayList<Long> have = new ArrayList<>();
        ArrayList<Long> less = new ArrayList<>();
        for (int i = 0; i < sub.size(); i++) {
            have.add(sub.get(i));
            less.add(sub.get(i));
        }
        have.add(a[ind]);
        genrate(ind + 1, a, have);
        genrate(ind + 1, a, less);
    }



    public static long factorial(long n) {
        if (n <= 1) {
            return 1;
        }
        long t = n - 1;
        while (t > 1) {
            n *= t;
            t--;
        }
        return n;
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

    public static void prefixSum(int[] a) {
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

    public static long binaryToDecimal(String w) {
        long r = 0;
        long l = 0;
        for (int i = w.length() - 1; i > -1; i--) {
            long x = (w.charAt(i) - '0') * (long) Math.pow(2, l);
            r = r + x;
            l++;
        }
        return r;
    }

    public static String decimalToBinary(long n) {
        String w = "";
        while (n > 0) {
            w = n % 2 + w;
            n /= 2;
        }
        return w;
    }

    public static boolean isSorted(int[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] > a[i + 1]) {
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

    public static void simplifyTheFraction(long a, long b) {
        long GCD = GCD(a, b);
        System.out.println(a / GCD + " " + b / GCD);
    }

     

    static class RedBlackNode<T extends Comparable<T>> {

        
        public static final int BLACK = 0;
        
        public static final int RED = 1;
        

        public T key;

        
        RedBlackNode<T> parent;
        
        RedBlackNode<T> left;
        
        RedBlackNode<T> right;
        

        public int numLeft = 0;
        

        public int numRight = 0;
        

        public int color;

        RedBlackNode() {
            color = BLACK;
            numLeft = 0;
            numRight = 0;
            parent = null;
            left = null;
            right = null;
        }

        

        RedBlackNode(T key) {
            this();
            this.key = key;
        }
    }


    static class RedBlackTree<T extends Comparable<T>> {

        

        private RedBlackNode<T> nil = new RedBlackNode<T>();
        private RedBlackNode<T> root = nil;

        public RedBlackTree() {
            root.left = nil;
            root.right = nil;
            root.parent = nil;
        }

        

        

        private void leftRotate(RedBlackNode<T> x) {

            

            

            leftRotateFixup(x);

            

            

            RedBlackNode<T> y;
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


        

        

        private void leftRotateFixup(RedBlackNode x) {

            

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


        

        

        private void rightRotate(RedBlackNode<T> y) {

            

            rightRotateFixup(y);

            

            RedBlackNode<T> x = y.left;
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


        

        

        private void rightRotateFixup(RedBlackNode y) {

            

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
            insert(new RedBlackNode<T>(key));
        }

        

        

        

        private void insert(RedBlackNode<T> z) {

            

            RedBlackNode<T> y = nil;
            RedBlackNode<T> x = root;

            

            

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
            z.color = RedBlackNode.RED;

            

            insertFixup(z);

        }


        

        

        

        

        private void insertFixup(RedBlackNode<T> z) {

            RedBlackNode<T> y = nil;
            

            while (z.parent.color == RedBlackNode.RED) {

                

                if (z.parent == z.parent.parent.left) {

                    

                    y = z.parent.parent.right;

                    

                    if (y.color == RedBlackNode.RED) {
                        z.parent.color = RedBlackNode.BLACK;
                        y.color = RedBlackNode.BLACK;
                        z.parent.parent.color = RedBlackNode.RED;
                        z = z.parent.parent;
                    } 

                    else if (z == z.parent.right) {

                        

                        z = z.parent;
                        leftRotate(z);
                    } 

                    else {
                        

                        z.parent.color = RedBlackNode.BLACK;
                        z.parent.parent.color = RedBlackNode.RED;
                        rightRotate(z.parent.parent);
                    }
                } 

                else {

                    

                    y = z.parent.parent.left;

                    

                    if (y.color == RedBlackNode.RED) {
                        z.parent.color = RedBlackNode.BLACK;
                        y.color = RedBlackNode.BLACK;
                        z.parent.parent.color = RedBlackNode.RED;
                        z = z.parent.parent;
                    } 

                    else if (z == z.parent.left) {
                        

                        z = z.parent;
                        rightRotate(z);
                    } 

                    else {
                        

                        z.parent.color = RedBlackNode.BLACK;
                        z.parent.parent.color = RedBlackNode.RED;
                        leftRotate(z.parent.parent);
                    }
                }
            }
            

            root.color = RedBlackNode.BLACK;

        }


        

        

        public RedBlackNode<T> treeMinimum(RedBlackNode<T> node) {

            

            while (!isNil(node.left)) {
                node = node.left;
            }
            return node;
        }


        

        

        

        public RedBlackNode<T> treeSuccessor(RedBlackNode<T> x) {

            

            

            if (!isNil(x.left)) {
                return treeMinimum(x.right);
            }

            RedBlackNode<T> y = x.parent;

            

            while (!isNil(y) && x == y.right) {
                

                x = y;
                y = y.parent;
            }
            

            return y;
        }


        

        

        public void remove(RedBlackNode<T> v) {

            RedBlackNode<T> z = search(v.key);

            

            RedBlackNode<T> x = nil;
            RedBlackNode<T> y = nil;

            

            if (isNil(z.left) || isNil(z.right)) {
                y = z;
            } 

            else {
                y = treeSuccessor(z);
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

            

            

            fixNodeData(x, y);

            

            

            if (y.color == RedBlackNode.BLACK) {
                removeFixup(x);
            }
        }


        

        

        private void fixNodeData(RedBlackNode<T> x, RedBlackNode<T> y) {

            

            RedBlackNode<T> current = nil;
            RedBlackNode<T> track = nil;

            

            

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


        

        

        

        private void removeFixup(RedBlackNode<T> x) {

            RedBlackNode<T> w;

            

            while (x != root && x.color == RedBlackNode.BLACK) {

                

                if (x == x.parent.left) {

                    

                    w = x.parent.right;

                    

                    if (w.color == RedBlackNode.RED) {
                        w.color = RedBlackNode.BLACK;
                        x.parent.color = RedBlackNode.RED;
                        leftRotate(x.parent);
                        w = x.parent.right;
                    }

                    

                    if (w.left.color == RedBlackNode.BLACK
                            && w.right.color == RedBlackNode.BLACK) {
                        w.color = RedBlackNode.RED;
                        x = x.parent;
                    } 

                    else {
                        

                        if (w.right.color == RedBlackNode.BLACK) {
                            w.left.color = RedBlackNode.BLACK;
                            w.color = RedBlackNode.RED;
                            rightRotate(w);
                            w = x.parent.right;
                        }
                        

                        w.color = x.parent.color;
                        x.parent.color = RedBlackNode.BLACK;
                        w.right.color = RedBlackNode.BLACK;
                        leftRotate(x.parent);
                        x = root;
                    }
                } 

                else {

                    

                    w = x.parent.left;

                    

                    if (w.color == RedBlackNode.RED) {
                        w.color = RedBlackNode.BLACK;
                        x.parent.color = RedBlackNode.RED;
                        rightRotate(x.parent);
                        w = x.parent.left;
                    }

                    

                    if (w.right.color == RedBlackNode.BLACK
                            && w.left.color == RedBlackNode.BLACK) {
                        w.color = RedBlackNode.RED;
                        x = x.parent;
                    } 

                    else {
                        

                        if (w.left.color == RedBlackNode.BLACK) {
                            w.right.color = RedBlackNode.BLACK;
                            w.color = RedBlackNode.RED;
                            leftRotate(w);
                            w = x.parent.left;
                        }

                        

                        w.color = x.parent.color;
                        x.parent.color = RedBlackNode.BLACK;
                        w.left.color = RedBlackNode.BLACK;
                        rightRotate(x.parent);
                        x = root;
                    }
                }
            }


            

            

            x.color = RedBlackNode.BLACK;
        }


        

        

        

        

        public RedBlackNode<T> search(T key) {

            

            RedBlackNode<T> current = root;

            

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

            

            

            return findNumGreater(root, key);

        }


        

        

        public int numSmaller(T key) {

            

            

            return findNumSmaller(root, key);

        }


        

        

        

        public int findNumGreater(RedBlackNode<T> node, T key) {

            

            if (isNil(node)) {
                return 0;
            } 

            

            else if (key.compareTo(node.key) < 0) {
                return 1 + node.numRight + findNumGreater(node.left, key);
            } 

            

            else {
                return findNumGreater(node.right, key);
            }

        }


        
        public List<T> getGreaterThan(T key, Integer maxReturned) {
            List<T> list = new ArrayList<T>();
            getGreaterThan(root, key, list);
            return list.subList(0, Math.min(maxReturned, list.size()));
        }

        private void getGreaterThan(RedBlackNode<T> node, T key,
                List<T> list) {
            if (isNil(node)) {
                return;
            } else if (node.key.compareTo(key) > 0) {
                getGreaterThan(node.left, key, list);
                list.add(node.key);
                getGreaterThan(node.right, key, list);
            } else {
                getGreaterThan(node.right, key, list);
            }
        }

        

        

        

        public int findNumSmaller(RedBlackNode<T> node, T key) {

            

            if (isNil(node)) {
                return 0;
            } 

            

            else if (key.compareTo(node.key) <= 0) {
                return findNumSmaller(node.left, key);
            } 

            

            

            else {
                return 1 + node.numLeft + findNumSmaller(node.right, key);
            }

        }


        

        

        private boolean isNil(RedBlackNode node) {

            

            return node == nil;

        }


        

        

        

        public int size() {

            

            

            return root.numLeft + root.numRight + 1;
        }


    }

}
