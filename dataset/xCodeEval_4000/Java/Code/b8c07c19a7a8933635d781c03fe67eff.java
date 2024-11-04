import java.io.*;
import java.util.*;
public class P1493B2 {
    static InputReader in = new InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    static long mod = (long) (Math.pow(10, 9)) + 7;
    static HashMap<Integer, List<Integer>> adjList = new HashMap<>();
    static boolean[] visited;
    static HashMap<String, String> map;
    public static void main(String[] args) {
        int test = in.nextInt();
        map = new HashMap<>();
        map.put("0", "0");
        map.put("1", "1");
        map.put("2", "5");
        map.put("5", "2");
        map.put("8", "8");
        while (test --> 0) {
            solve();
        }
        pw.close();
    }

    static void solve() {
        int h = in.nextInt(), m = in.nextInt();
        String[] line = in.nextLine().split(":");
        int hour = Integer.parseInt(line[0]), minute = Integer.parseInt(line[1]);
        int secs = hour * m + minute;
        int increase = secs + 1;
        if (check(secs, h, m)) {
            print(secs, h, m);
            return;
        }
        while (true) {
            if (check(increase, h, m)) {
                print(increase, h, m);
                return;
            }
            increase++;
        }
    }

    static void print(int secs, int h, int m) {
        secs = (secs + (h * m)) % (h * m);
        int hour = secs / m;
        int minutes = secs % m;
        String hourString, minuteString;
        if (hour < 10) {
            hourString = "0" + Integer.toString(hour);
        } else {
            hourString = Integer.toString(hour);
        }
        if (minutes < 10) {
            minuteString = "0" + minutes;
        } else {
            minuteString = Integer.toString(minutes);
        }
        pw.println(hourString + ":" + minuteString);
    }

    static boolean check(int secs, int h, int m) {
        secs = (secs + (h * m)) % (h * m);
        int hour = secs / m;
        int minutes = secs % m;
        String hourString, minuteString;
        if (hour < 10) {
            hourString = "0" + Integer.toString(hour);
        } else {
            hourString = Integer.toString(hour);
        }
        if (minutes < 10) {
            minuteString = "0" + minutes;
        } else {
            minuteString = Integer.toString(minutes);
        }
        String h1 = hourString.substring(0, 1);
        String h2 = hourString.substring(1, 2);
        String m1 = minuteString.substring(0, 1);
        String m2 = minuteString.substring(1, 2);
        if (!map.containsKey(h1) || !map.containsKey(h2) || !map.containsKey(m1) || !map.containsKey(m2)) {
            return false;
        }
        String reversedHour = map.get(m2) + map.get(m1);
        String reversedMinute = map.get(h2) + map.get(h1);
        int hourVal, minuteVal;
        if (reversedHour.substring(0, 1).equals("0")) {
            hourVal = Integer.parseInt(reversedHour.substring(1, 2));
        } else {
            hourVal = Integer.parseInt(reversedHour);
        }
        if (reversedMinute.substring(0, 1).equals("0")) {
            minuteVal = Integer.parseInt(reversedMinute.substring(1, 2));
        } else {
            minuteVal = Integer.parseInt(reversedMinute);
        }
        return hourVal < h && minuteVal < m;
    }

    static void print(int[] time) {
        pw.println(time[0] + ":" + time[1]);
    }





    static void ruffleSort(int[] a) {
        int n=a.length;
        Random r=new Random();
        for (int i=0; i<a.length; i++) {
            int oi=r.nextInt(n), temp=a[i];
            a[i]=a[oi];
            a[oi]=temp;
        }
        Arrays.sort(a);
    }

    public static List<Long> getFactors(long num) {
        List<Long> res = new ArrayList();
        res.add(num);

        for (long d = 2; d <= (long)Math.sqrt(num); d++) {
            if (num % d == 0) {
                res.add(d);
                if ((num / d) != d) {
                    res.add(num / d);
                }
            }
        }

        return res;
    }


    static long choose(long a, long b) {
        if(b > a - b)
            return choose(a, a - b);
        long m = 1;
        long d = 1;
        long i;
        for(i = 0; i < b; i++) {
            m *= (a - i);
            m %= mod;
            d *= (i + 1);
            d %= mod;
        }
        long ans = m * fast_pow(d, mod - 2) % mod;
        return ans;
    }


    static long fast_pow(long a, long b) {
        if(b == 0) return 1L;
        long val = fast_pow(a, b / 2);
        if(b % 2 == 0)
            return val * val % mod;
        else
            return val * val % mod * a % mod;
    }

    static void sort(long[] a) 

    {
        ArrayList<Long> l=new ArrayList<>();
        for (long i:a) l.add(i);
        Collections.sort(l);
        for (int i=0; i<a.length; i++) a[i]=l.get(i);
    }

    static void sort(int[] a) {
        ArrayList<Integer> l=new ArrayList<>();
        for (int i:a) l.add(i);
        Collections.sort(l);
        for (int i=0; i<a.length; i++) a[i]=l.get(i);
    }


    static void addEdge(int u, int v) {
        adjList.putIfAbsent(u, new ArrayList<>());
        adjList.get(u).add(v);
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int lcm (int a, int b) {
        return a / gcd(a, b) * b;
    }

    static boolean[] sieve(int n) {
        boolean[] isPrime = new boolean[n + 1];
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i] && i * i <= n) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[i] = false;
                }
            }
        }
        return isPrime;
    }

    static boolean isPrime(int n) {
        for (int d = 2; d * d <= n; d++) {
            if (n % d == 0) {
                return false;
            }
        }
        return true;
    }

    

    static int high(int[] a) {
        int lo = 0, hi = a.length - 1;
        int error = 3;
        while (hi - lo > error) {
            int right = hi - (hi - lo) / 3;
            int left = lo + (hi - lo) / 3;
            if (a[left] < a[right]) {
                lo = left;
            } else {
                hi = right;
            }
        }
        

        int ans = lo;
        for (int i = lo; i <= hi; i++) {
            if (a[ans] < a[i]) {
                ans = i;
            }
        }
        return ans;
    }

    

    static int low(int[] a) {
        int lo = 0, hi = a.length - 1;
        int error = 3;
        while (hi - lo > error) {
            int right = hi - (hi - lo) / 3;
            int left = lo + (hi - lo) / 3;
            if (a[left] < a[right]) {
                hi = right;
            } else {
                lo = left;
            }
        }
        

        int ans = lo;
        for (int i = lo; i <= hi; i++) {
            if (a[ans] > a[i]) {
                ans = i;
            }
        }
        return ans;
    }

    static boolean contains(int[] a, int key) {
        int ans = 0;
        int low = 0, high = a.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int midVal = a[mid];

            if (midVal < key) {
                low = mid + 1;
            } else if (midVal > key) {
                high = mid - 1;
            }
            else if (midVal == key) {
                ans = 1;
                break;
            }
        }
        return ans == 1;
    }

    static int first(int[] a, int key) {
        int ans = -1;
        int low = 0, high = a.length - 1;
        while (low <= high) {
            int mid = low + (high - low + 1) / 2;
            int midVal = a[mid];
            if (midVal < key) {
                low = mid + 1;
            } else if (midVal > key) {
                high = mid - 1;
            } else if (midVal == key) {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }

    static int last(int[] a, int key) {
        int ans = -1;
        int low = 0, high = a.length - 1;
        while (low <= high) {
            int mid = low + (high - low + 1) / 2;
            int midVal = a[mid];
            if (midVal < key) {
                low = mid + 1;
            }
            else if (midVal > key) {
                high = mid - 1;
            }
            else if (midVal == key) {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }

    static int greaterOrEqual(int[] a, int key)
    {
        int ans = -1;
        int low = 0, high = a.length - 1;
        while (low <= high) {
            int mid = low + (high - low + 1) / 2;
            int midVal = a[mid];
            if (midVal < key) {
                low = mid + 1;
            }
            else if (midVal >= key) {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }

    static int lesserOrEqual(int[] a, int key) {
        int ans = -1;
        int low = 0, high = a.length - 1;
        while (low <= high) {
            int mid = low + (high - low + 1) / 2;
            int midVal = a[mid];
            if (midVal <= key) {
                ans = mid;
                low = mid + 1;
            }
            else if (midVal > key) {
                high = mid - 1;
            }
        }
        return ans;
    }

    static class SegTree
    {
        long st[];
        public SegTree(long[] arr, int n) {
            int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
            int max_size = 2 * (int) Math.pow(2, x) - 1;
            st = new long[max_size];
            constructSTUtil(arr, 0, n - 1, 0);
        }

        int getMid(int s, int e) {
            return s + (e - s) / 2;
        }

        long getSumUtil(int ss, int se, int qs, int qe, int si) {
            if (qs <= ss && qe >= se)
                return st[si];
            if (se < qs || ss > qe)
                return 0;
            int mid = getMid(ss, se);
            return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
                    getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
        }

        void updateValueUtil(int ss, int se, int i, long diff, int si) {
            if (i < ss || i > se)
                return;
            st[si] = st[si] + diff;
            if (se != ss) {
                int mid = getMid(ss, se);
                updateValueUtil(ss, mid, i, diff, 2 * si + 1);
                updateValueUtil(mid + 1, se, i, diff, 2 * si + 2);
            }
        }

        void updateValue(long arr[], int n, int i, int new_val) {
            if (i < 0 || i > n - 1) {
                System.out.println("Invalid Input");
                return;
            }
            long diff = new_val - arr[i];
            arr[i] = new_val;
            updateValueUtil(0, n - 1, i, diff, 0);
        }

        long getSum(int n, int qs, int qe) {
            if (qs < 0 || qe > n - 1 || qs > qe) {
                System.out.println("Invalid Input");
                return -1;
            }
            return getSumUtil(0, n - 1, qs, qe, 0);
        }

        long constructSTUtil(long arr[], int ss, int se, int si) {
            if (ss == se) {
                st[si] = arr[ss];
                return arr[ss];
            }
            int mid = getMid(ss, se);
            st[si] = constructSTUtil(arr, ss, mid, si * 2 + 1) +
                    constructSTUtil(arr, mid + 1, se, si * 2 + 2);
            return st[si];
        }
    }


    static class UnionFind {
        

        private int count;
        

        private int[] parent;
        

        private int[] size;

        public UnionFind(int n) {
            this.count = n;
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        public void union(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ)
                return;

            

            if (size[rootP] > size[rootQ]) {
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            } else {
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }
            count--;
        }

        public boolean connected(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            return rootP == rootQ;
        }

        private int find(int x) {
            while (parent[x] != x) {
                

                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        public int count() {
            return count;
        }
    }
    static class InputReader {

        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, snumChars;

        public InputReader(InputStream st) {
            this.stream = st;
        }

        public int read() {
            if (snumChars == -1)
                throw new InputMismatchException();
            if (curChar >= snumChars) {
                curChar = 0;
                try {
                    snumChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (snumChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[] nextIntArray(int n) {
            int [] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }
        public long[] nextLongArray(int n) {
            long [] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextLong();
            }
            return a;
        }

        public static int[] shuffle(int[] a, Random gen)
        { for(int i = 0, n = a.length;i < n;i++)
        { int ind = gen.nextInt(n-i)+i;
            int d = a[i];
            a[i] = a[ind];
            a[ind] = d;

        }
            return a;
        }


        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public String nextLine() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndOfLine(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }
    }
}
