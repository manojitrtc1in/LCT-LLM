import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.Math.log;
import static java.lang.Math.min;

public class Main {

    

    public static final int MOD = (int) (1e9 + 7);

    


    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void print(String s) {
        System.out.println(s);
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();

        int t = 1;
        t = sc.nextInt();
        prepare(sc);

        for(int i = 0; i<t; i++) {
            System.out.println(solve(sc));
        }
    }

    

    public static long solve(FastReader sc) {
        int n = sc.nextInt();
        int x = lowerBound(l, 0, l.size(), n);
        if (x == l.size()) return map.get(l.get(l.size()-1));
        if (n == l.get(x)) {
            return map.get(l.get(x));
        } else {
            if (x == 0)
                return 0;
            return map.get(l.get(x-1));
        }
    }


    public static void prepare(FastReader sc) {
        int n = (int)1e9;
        long a = 3;
        long cnt = 0;
        long id3 = a*a;
        long c = id3 - (id3/2);

        while (c <= n) {
            long b = id3/2;
                if (a <= b && b <= c) {
                    cnt++;
                    l.add(c);
                    map.put(c, cnt);
                }
            a+=2;
            id3 = a*a;
            c = id3 - id3/2;
        }
    }

    static List<Long> l = new ArrayList<>();
    static Map<Long, Long> map = new HashMap<>();

    


    public static String printArray(long[] a) {
        StringBuilder r = new StringBuilder("");

        for(int i = 0; i<a.length; i++) {
            r.append(a[i] + " ");
        }
        return r.toString();
    }

    public static <T> String printList(List<T> a) {
        StringBuilder r = new StringBuilder("");

        for (T x: a) {
            r.append(x.toString() + " ");
        }
        return r.toString();
    }

    

    public static int lowerBound(List<Long> arr, int begin, int end, int target) {
        while(begin < end) {
            int mid = begin + (end - begin) / 2;
            

            if(arr.get(mid) < target)
                

                begin = mid + 1;
                

            else if(arr.get(mid) >= target)
                end = mid;
        }
        return begin;
    }

    

    public static int upperBound(int[] arr, int begin, int end, int target) {
        while(begin < end) {
            int mid = begin + (end - begin) / 2;
            if(arr[mid] <= target)
                begin = mid + 1;
            else
                end = mid;
        }
        return begin;
    }

    

    public static class Permutations {
        List<List<Integer>> id1 = new ArrayList<>();
        List<Integer> permutation = new ArrayList<>();
        boolean[] taken;
        int[] a;

        public Permutations(int[] a) {
            this.a = a;
            taken = new boolean[a.length];
        }

        void search() {
            if (permutation.size()==a.length) {
                id1.add(new ArrayList<>(permutation));
            } else {
                for (int i = 0; i<a.length; i++) {
                    if (taken[i]) {
                        continue;
                    }
                    taken[i] = true;
                    permutation.add(a[i]);
                    search();
                    taken[i] = false;
                    permutation.remove(permutation.size()-1);
                }
            }
        }
    }

    

    public static class Subsets {
        List<List<Integer>> subsets = new ArrayList<>();
        List<Integer> subset = new ArrayList<>();

        void search(int[] a, int x) {
            if (x == a.length) {
                subsets.add(new ArrayList<>(subset));
            } else {
                subset.add(a[x]);
                search(a, x+1);
                subset.remove(subset.size() - 1);
                search(a, x+1);
            }
        }
    }

    


    public static int gcd(int a, int b) {  

        if (b==0) return a;
        return gcd(b, a%b);
    }

    public static int lcm(int a, int b) {
        return (a*b)/gcd(a, b);
    }

    public static boolean isPrime(int n) {
        if (n < 2) return false;
        for (int x = 2; x*x <= n; x++) {
            if (n % x == 0) return false;
        }
        return true;
    }

    public static List<Integer> factors(int n) {
        List<Integer> f = new ArrayList<>();
        for (int x = 2; x*x <= n; x++) {
            while (n % x == 0) {
                f.add(x);
                n /= x;
            }
        }

        if (n > 1) f.add(n);
        return f;
    }

    public static int id2(int n) {
        List<Integer> fp = factors(n);
        int x = 1;
        int t = 0;
        for (int i = 0; i<fp.size()-1; i++) {
            t++;
            if (fp.get(i+1)!=fp.get(i)) {
                x *= (t+1);
                t = 0;
            }
        }
        t++;
        x *= (t+1);
        return x;
    }

    

    public static int[] sieve(int n) {
        int[] sieve = new int[n+1];
        for (int x = 2; x <= n; x++) {
            if (sieve[x] != 0) continue;
            for (int u = 2*x; u <= n; u += x) {
                sieve[u] = x;
            }
        }
        return sieve;
    }

    

    public static int totient(int n) {
        List<Integer> pf = factors(n);
        Map<Integer, Integer> fMap = new HashMap<>();
        for (int x: pf) {
            if (!fMap.containsKey(x)) {
                fMap.put(x, 0);
            }
            fMap.put(x, fMap.get(x) + 1);
        }
        int totient = 1;
        for (Map.Entry<Integer, Integer> e: fMap.entrySet()) {
            int p = e.getKey();
            int ex = e.getValue();
            totient *= Math.pow(p, ex-1)*(p-1);
        }
        return totient;
    }

    

    public static int modpow(int x, int p, int mod) {
        if (p == 0) return 1 % mod;
        long u = modpow(x, p / 2, mod); 

        u = (u * u) % mod;
        if (p % 2 == 1) u = (u * x) % mod;
        return (int)u;
    }
    


    public static int[][] id4(int[][] a) {
        int n = a.length;
        int m = a[0].length;
        int[][] ps = new int[n][m];
        ps[0][0] = a[0][0];

        for (int j = 1; j<m; j++) {
            ps[0][j] = ps[0][j-1] + a[0][j];
        }
        for (int i = 1; i<n; i++) {
            ps[i][0] = ps[i-1][0] + a[i][0];
        }

        for (int i = 1; i<n; i++) {
            for (int j = 1; j<m; j++) {
                ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + a[i][j];
            }
        }

        return ps;
    }

    public static double log2(double a) {
        return log(a)/log(2);
    }

    


    

    public static class SparseTable {
        int[][] st;
        int n;
        int k;

        public SparseTable(int[] a) {
            n = a.length;
            k = (int) log2(n);
            st = new int[n][k+1];

            for (int i = 0; i<n; i++) {
                st[i][0] = a[i];
            }

            

            for (int j = 1; j<=k; j++) {
                for (int i = 0; i + (1 << j) <= n; i++) {
                    st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
                }
            }
        }

        

        public long sumQuery(int l, int r) {
            long sum = 0;
            for (int j = k; j>=0; j--) {
                if ((1 << j) <= r - l + 1) {
                    sum += st[l][j];
                    l += 1 << j;
                }
            }

            return sum;
        }

        

        public int id10(int l, int r) {
            int j = (int) log2(r - l + 1);
            int min = min(st[l][j], st[r - (1 << j) + 1][j]);
            return min;
        }

    }

    

    public static class id6 {

        int[] bit;

        public id6(int[] a) {
            int n = a.length;
            bit = new int[n+1];
            

            

            for(int i = 0; i < n; i++)
                updateBit(i, a[i]);
        }

        

        public void updateBit(int index, int delta) {
            index += 1;

            while (index <= bit.length) {
                bit[index] += delta;

                index += index & (-index);
            }
        }

        

        public int getSum(int index) {
            int sum = 0;

            index += 1;

            while (index > 0) {
                sum += bit[index];

                index -= index & (-index);
            }

            return sum;
        }
    }

    public static class UnionFind {

        int[] link;
        int[] size;

        UnionFind(int n) {
            link = new int[n];
            size = new int[n];
            for (int i = 0; i<n; i++) {
                link[i] = i;
                size[i] = 1;
            }
        }

        int find(int x) {
            while (x != link[x]) x = link[x];
            return x;
        }

        boolean same(int a, int b) {
            return find(a) == find(b);
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (size[a] < size[b]) {
                int temp = a;
                a = b;
                b = temp;
            }

            size[a] += size[b];
            link[b] = a;
        }
    }

    public static class SegmentTree {

        int st[];

        public SegmentTree(int arr[]) {
            int n = arr.length;

            int x = (int) (Math.ceil(log2(n)));

            int maxSize = 2 * (int) Math.pow(2, x) - 1;

            st = new int[maxSize];

            build(arr, 0, n-1, 0);
        }

        int build(int arr[], int ss, int se, int si) {
            if (ss == se) {
                st[si] = arr[ss];
                return arr[ss];
            }

            int mid = ss + (se - ss) / 2; 


            st[si] = build(arr, ss, mid, si * 2 + 1) +
                    build(arr, mid + 1, se, si * 2 + 2);
            return st[si];
        }

        private int id9(int ss, int se, int l, int r, int si) {
            if (l <= ss && r >= se) {
                return st[si];
            }

            if (se < l || ss > r) {
                return 0;
            }

            int mid = ss + (se - ss) / 2;
            return id9(ss, mid, l, r, 2 * si + 1) +
                    id9(mid + 1, se, l, r, 2 * si + 2);
        }

        void id0(int ss, int se, int i, int diff, int si) {
            if (i < ss || i > se) {
                return;
            }

            st[si] = st[si] + diff;
            if (se != ss) {
                int mid = ss + (se - ss) / 2;
                id0(ss, mid, i, diff, 2 * si + 1);
                id0(mid + 1, se, i, diff, 2 * si + 2);
            }
        }

        int getSum(int n, int l, int r) {
            if (l < 0 || r > n - 1 || l > r) {
                return -1;
            }

            return id9(0, n-1, l, r, 0);
        }

        

        

        void updateValue(int arr[], int n, int i, int newValue) {
            if (i < 0 || i > n - 1) {
                return;
            }

            int diff = newValue - arr[i];

            arr[i] = newValue;

            id0(0, n - 1, i, diff, 0);
        }
    }

    

    public static class Pair<T extends Comparable<T>, Q extends Comparable<Q>> implements Comparable<Pair<T, Q>>{
        T a;
        Q b;

        public Pair(T a, Q b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return a.equals(pair.a) && b.equals(pair.b);
        }

        @Override
        public int hashCode() {
            return Objects.hash(a, b);
        }


        @Override
        public int compareTo(Pair<T, Q> id5) {
            int compareA = this.a.compareTo(id5.a);

            if (compareA == 0) {
                return this.b.compareTo(id5.b);
            } else {
                return compareA;
            }
        }
    }

    

    public static class id7<T extends Comparable<T>> {
        private final TreeSet<T> set = new TreeSet<>();
        private final Map<T, Integer> id8 = new HashMap<>();
        private int size = 0;

        public id7() {}

        public id7(List<T> a) {
            for (T x: a) {
                this.add(x);
                size++;
            }
        }

        public void add(T element) {
            set.add(element);
            if (!id8.containsKey(element)) {
                id8.put(element, 0);
            }
            id8.put(element, id8.get(element) + 1);
            size++;
        }

        public boolean remove(T element) {
            if (id8.containsKey(element)) {
                int x = id8.get(element);
                x--;
                if (x == 0) {
                    id8.remove(element);
                    set.remove(element);
                } else {
                    id8.put(element, id8.get(element) - 1);
                }
                size--;
                return true;
            }
            return false;
        }

        public int size() {
            return size;
        }

        public T first() {
            return set.first();
        }

        public T last() {
            return set.last();
        }

        public T pollFirst() {
            T t = set.first();
            remove(t);
            return t;
        }

        public T pollLast() {
            T t = set.last();
            set.
            remove(t);
            return t;
        }
    }
}