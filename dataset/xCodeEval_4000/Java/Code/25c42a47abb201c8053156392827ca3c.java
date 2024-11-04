import java.util.*;
import java.lang.*;






import java.io.*;

@SuppressWarnings("unchecked")
public class Main implements Runnable {
    static FastReader in;
    static PrintWriter out;

    static int bit(long n) {
        return (n == 0) ? 0 : (1 + bit(n & (n - 1)));
    }

    static void p(Object o) {
        out.print(o);
    }

    static void pn(Object o) {
        out.println(o);
    }

    static void pni(Object o) {
        out.println(o);
        out.flush();
    }

    static String n() throws Exception {
        return in.next();
    }

    static String nln() throws Exception {
        return in.nextLine();
    }

    static int ni() throws Exception {
        return Integer.parseInt(in.next());
    }

    static long nl() throws Exception {
        return Long.parseLong(in.next());
    }

    static double nd() throws Exception {
        return Double.parseDouble(in.next());
    }

    static class FastReader {
        static BufferedReader br;
        static StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(String s) throws Exception {
            br = new BufferedReader(new FileReader(s));
        }

        String next() throws Exception {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new Exception(e.toString());
                }
            }
            return st.nextToken();
        }

        String nextLine() throws Exception {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                throw new Exception(e.toString());
            }
            return str;
        }
    }

    static long power(long a, long b) {
        if (a == 0L)
            return 0L;
        if (b == 0)
            return 1;
        long val = power(a, b / 2);
        val = val * val;
        if ((b % 2) != 0)
            val = val * a;
        return val;
    }

    static long power(long a, long b, long mod) {
        if (a == 0L)
            return 0L;
        if (b == 0)
            return 1;
        long val = power(a, b / 2L, mod) % mod;
        val = (val * val) % mod;
        if ((b % 2) != 0)
            val = (val * a) % mod;
        return val;
    }

    static ArrayList<Long> prime_factors(long n) {
        ArrayList<Long> ans = new ArrayList<Long>();
        while (n % 2 == 0) {
            ans.add(2L);
            n /= 2L;
        }
        for (long i = 3; i <= Math.sqrt(n); i++) {
            while (n % i == 0) {
                ans.add(i);
                n /= i;
            }
        }
        if (n > 2) {
            ans.add(n);
        }
        return ans;
    }

    static void sort(ArrayList<Long> a) {
        Collections.sort(a);
    }

    static void reverse_sort(ArrayList<Long> a) {
        Collections.sort(a, Collections.reverseOrder());
    }

    static void swap(long[] a, int i, int j) {
        long temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    static void swap(List<Long> a, int i, int j) {
        long temp = a.get(i);
        a.set(j, a.get(i));
        a.set(j, temp);
    }

    static void sieve(boolean[] prime) {
        int n = prime.length - 1;
        Arrays.fill(prime, true);
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
    }

    static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    

    public static void sort(long[] arr, int l, int r) {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        sort(arr, l, mid);
        sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    public static void sort(int[] arr, int l, int r) {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        sort(arr, l, mid);
        sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    static void merge(int[] arr, int l, int mid, int r) {
        int[] left = new int[mid - l + 1];
        int[] right = new int[r - mid];
        for (int i = l; i <= mid; i++) {
            left[i - l] = arr[i];
        }
        for (int i = mid + 1; i <= r; i++) {
            right[i - (mid + 1)] = arr[i];
        }
        int left_start = 0;
        int right_start = 0;
        int left_length = mid - l + 1;
        int right_length = r - mid;
        int temp = l;
        while (left_start < left_length && right_start < right_length) {
            if (left[left_start] < right[right_start]) {
                arr[temp] = left[left_start++];
            } else {
                arr[temp] = right[right_start++];
            }
            temp++;
        }
        while (left_start < left_length) {
            arr[temp++] = left[left_start++];
        }
        while (right_start < right_length) {
            arr[temp++] = right[right_start++];
        }
    }

    static void merge(long[] arr, int l, int mid, int r) {
        long[] left = new long[mid - l + 1];
        long[] right = new long[r - mid];
        for (int i = l; i <= mid; i++) {
            left[i - l] = arr[i];
        }
        for (int i = mid + 1; i <= r; i++) {
            right[i - (mid + 1)] = arr[i];
        }
        int left_start = 0;
        int right_start = 0;
        int left_length = mid - l + 1;
        int right_length = r - mid;
        int temp = l;
        while (left_start < left_length && right_start < right_length) {
            if (left[left_start] < right[right_start]) {
                arr[temp] = left[left_start++];
            } else {
                arr[temp] = right[right_start++];
            }
            temp++;
        }
        while (left_start < left_length) {
            arr[temp++] = left[left_start++];
        }
        while (right_start < right_length) {
            arr[temp++] = right[right_start++];
        }
    }

    static HashMap<Long, Integer> map_prime_factors(long n) {
        HashMap<Long, Integer> map = new HashMap<>();
        while (n % 2 == 0) {
            map.put(2L, map.getOrDefault(2L, 0) + 1);
            n /= 2L;
        }
        for (long i = 3; i <= Math.sqrt(n); i++) {
            while (n % i == 0) {
                map.put(i, map.getOrDefault(i, 0) + 1);
                n /= i;
            }
        }
        if (n > 2) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }
        return map;
    }

    static List<Long> divisor(long n) {
        List<Long> ans = new ArrayList<>();
        ans.add(1L);
        long count = 0;
        for (long i = 2L; i * i <= n; i++) {
            if (n % i == 0) {
                if (i == n / i)
                    ans.add(i);
                else {
                    ans.add(i);
                    ans.add(n / i);
                }
            }
        }
        return ans;
    }

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    


    
    

    

    

    

    

    


    static class Segment_Tree {
        private long[] segment_tree;

        public Segment_Tree(int n) {
            this.segment_tree = new long[4 * n + 1];
        }

        void build(int index, int left, int right, int[] a) {
            if (left == right) {
                segment_tree[index] = a[left];
                return;
            }
            int mid = (left + right) / 2;
            build(2 * index + 1, left, mid, a);
            build(2 * index + 2, mid + 1, right, a);
            segment_tree[index] = segment_tree[2 * index + 1] + segment_tree[2 * index + 2];
        }

        long query(int index, int left, int right, int l, int r) {
            if (left > right)
                return 0;
            if (left >= l && r >= right) {
                return segment_tree[index];
            }
            if (l > right || left > r)
                return 0;
            int mid = (left + right) / 2;
            return query(2 * index + 1, left, mid, l, r) + query(2 * index + 2, mid + 1, right, l, r);
        }

        void update(int index, int left, int right, int node, int val) {
            if (left == right) {
                segment_tree[index] += val;
                return;
            }
            int mid = (left + right) / 2;
            if (node <= mid)
                update(2 * index + 1, left, mid, node, val);
            else
                update(2 * index + 2, mid + 1, right, node, val);
            segment_tree[index] = segment_tree[2 * index + 1] + segment_tree[2 * index + 2];
        }
    }

    static class min_Segment_Tree {
        private long[] segment_tree;

        public min_Segment_Tree(int n) {
            this.segment_tree = new long[4 * n + 1];
        }

        void build(int index, int left, int right, int[] a) {
            if (left == right) {
                segment_tree[index] = a[left];
                return;
            }
            int mid = (left + right) / 2;
            build(2 * index + 1, left, mid, a);
            build(2 * index + 2, mid + 1, right, a);
            segment_tree[index] = Math.min(segment_tree[2 * index + 1], segment_tree[2 * index + 2]);
        }

        long query(int index, int left, int right, int l, int r) {
            if (left > right)
                return Integer.MAX_VALUE;
            if (left >= l && r >= right) {
                return segment_tree[index];
            }
            if (l > right || left > r)
                return Integer.MAX_VALUE;
            int mid = (left + right) / 2;
            return Math.min(query(2 * index + 1, left, mid, l, r), query(2 * index + 2, mid + 1, right, l, r));
        }
    }

    static class max_Segment_Tree {
        public long[] segment_tree;

        public max_Segment_Tree(int n) {
            this.segment_tree = new long[4 * n + 1];
        }

        void build(int index, int left, int right, int[] a) {
            

            if (left == right) {
                segment_tree[index] = a[left];
                return;
            }
            int mid = (left + right) / 2;
            build(2 * index + 1, left, mid, a);
            build(2 * index + 2, mid + 1, right, a);
            segment_tree[index] = Math.max(segment_tree[2 * index + 1], segment_tree[2 * index + 2]);
        }

        long query(int index, int left, int right, int l, int r) {
            if (left >= l && r >= right) {
                return segment_tree[index];
            }
            if (l > right || left > r)
                return Integer.MIN_VALUE;
            int mid = (left + right) / 2;
            long max = Math.max(query(2 * index + 1, left, mid, l, r), query(2 * index + 2, mid + 1, right, l, r));
            

            return max;
        }
    }

    

    

    static class dsu {
        private int[] parent;
        private int[] rank;
        private int[] size;

        public dsu(int n) {
            this.parent = new int[n + 1];
            this.rank = new int[n + 1];
            this.size = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                rank[i] = 1;
                size[i] = 1;
            }
        }

        int findParent(int a) {
            if (parent[a] == a)
                return a;
            else
                return parent[a] = findParent(parent[a]);
        }

        void join(int a, int b) {
            int parent_a = findParent(a);
            int parent_b = findParent(b);
            if (parent_a == parent_b)
                return;
            if (rank[parent_a] > rank[parent_b]) {
                parent[parent_b] = parent_a;
                size[parent_a] += size[parent_b];
            } else if (rank[parent_a] < rank[parent_b]) {
                parent[parent_a] = parent_b;
                size[parent_b] += size[parent_a];
            } else {
                parent[parent_a] = parent_b;
                size[parent_b] += size[parent_a];
                rank[parent_b]++;
            }
        }
    }

    


    public static class rectangle {
        int x1, x3, y1, y3;

        int x2, y2, x4, y4;

        

        public rectangle(int x1, int y1, int x3, int y3) {
            this.x1 = x1;
            this.y1 = y1;
            this.x3 = x3;
            this.y3 = y3;
            this.x2 = x3;
            this.y2 = y1;
            this.x4 = x1;
            this.y4 = y3;
        }

        public long area() {
            if (x3 < x1 || y3 < y1)
                return 0;
            return (long) Math.abs(x1 - x3) * (long) Math.abs(y1 - y3);
        }
    }

    static long intersection(rectangle a, rectangle b) {
        if (a.x3 < a.x1 || a.y3 < a.y1 || b.x3 < b.x1 || b.y3 < b.y1)
            return 0;
        long l1 = ((long) Math.min(a.x3, b.x3) - (long) Math.max(a.x1, b.x1));
        long l2 = ((long) Math.min(a.y3, b.y3) - (long) Math.max(a.y1, b.y1));
        if (l1 < 0 || l2 < 0)
            return 0;
        long area = ((long) Math.min(a.x3, b.x3) - (long) Math.max(a.x1, b.x1))
                * ((long) Math.min(a.y3, b.y3) - (long) Math.max(a.y1, b.y1));
        if (area < 0)
            return 0;
        return area;
    }

    static class pair implements Comparable<pair> {
        int a;
        int b;
        int dir;

        public pair(int a, int b, int dir) {
            this.a = a;
            this.b = b;
            this.dir = dir;
        }

        public int compareTo(pair p) {
            

            

            return (int) (this.a - p.a);
        }

    }

    static class pair2 implements Comparable<pair2> {
        long a;
        int index;

        public pair2(long a, int index) {
            this.a = a;
            this.index = index;
        }

        public int compareTo(pair2 p) {
            return (int) (this.a - p.a);
        }

    }

    static class node implements Comparable<node> {
        int l;
        int r;

        public node(int l, int r) {
            this.l = l;
            this.r = r;
        }

        public int compareTo(node a) {
            return this.l - a.l;
        }
    }

    static int ans = 0;
    static int leaf = 0;
    static boolean poss = true;
    static long mod = 998244353L;
    static int[] dx = { -1, 0, 0, 1 };
    static int[] dy = { 0, -1, 1, 0 };
    static long[] sub = new long[300001];
    static boolean cycle;
    int count = 0;
    
    public static void main(String[] args) throws Exception {
        

        long start = System.nanoTime();
        in = new FastReader();
        out = new PrintWriter(System.out, false);
        int tc =ni();
        int[] dp=new int[10000001];
        Arrays.fill(dp,Integer.MAX_VALUE);
        dp[1]=1;
        for(int i=2;i<=10000000;i++){
            dp[i]=Math.min(i,dp[i]);
            for(int j=i+i;j<10000000;j+=i){
                dp[j]=Math.min(dp[j],i);
            }
        }
        while (tc-- > 0) {
            int n = ni();
            int k=ni();
            int[] a=new int[n];
            for(int i=0;i<n;i++){
                a[i]=ni();
            }
            int[] mask=new int[n];
            for(int i=0;i<n;i++)
            {
                int val=a[i];
                Map<Integer,Integer> map=new HashMap<>();
                while(val!=1){
                    map.put(dp[val], map.getOrDefault(dp[val], 0)+1);
                    

                    val/=dp[val];
                }
                int ans=1;
                for(int key:map.keySet()){
                    if((map.get(key)%2)==0)continue;
                    ans*=key;
                }
                mask[i]=ans;
                

            }
            int count=1;
            Set<Integer> set=new HashSet<>();
            for(int i=0;i<n;i++){
                if(set.contains(mask[i])){
                    count++;
                    set.clear();
                    set.add(mask[i]);
                }else set.add(mask[i]);
            }
            pn(count);

            
        }
        long end = System.nanoTime();
        

        out.flush();
        out.close();

    }

    static void dp(int i,int j, int[] a, boolean[][] dp,int w) {
        int n = a.length;
        if (i >= n)
            return ;
        if (dp[i][j] == true)
            return ;
        dp(i+1, j, a, dp, w);
        if(j+a[i]<=w)dp(i+1, j+a[i], a, dp, w);
        dp[i][j] = true;
    }

    public void run() {
        try {
            in = new FastReader();
            out = new PrintWriter(System.out);
            int tc = ni();
            while (tc-- > 0) {

            }

            out.flush();
        } catch (Exception e) {

        }
    }

    static long dfs(int i, int p, int[] a, boolean[] visited, List<List<Integer>> arr, long s, long curr) {
        visited[i] = true;
        long val = a[i];
        for (int nei : arr.get(i)) {
            if (nei == p)
                continue;
            if (visited[nei]) {
                continue;
            }
            val ^= dfs(nei, i, a, visited, arr, s, curr);
        }
        pn(i + " " + (s) + " " + val);
        if (val == s) {
            cycle = true;
        }
        return val;
    }

    static boolean inside(int i, int j, int n, int m) {
        if (i >= 0 && j >= 0 && i < n && j < m)
            return true;
        return false;
    }

    static int binary_search(int[] a, int val) {
        int l = 0;
        int r = a.length - 1;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] <= val) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans;
    }

    static int[] longest_common_prefix(String s) {
        int m = s.length();
        int[] lcs = new int[m];
        int len = 0;
        int i = 1;
        lcs[0] = 0;
        while (i < m) {
            if (s.charAt(i) == s.charAt(len)) {
                lcs[i++] = ++len;
            } else {
                if (len == 0) {
                    lcs[i] = 0;
                    i++;
                } else
                    len = lcs[len - 1];
            }
        }
        return lcs;
    }

    static void swap(char[] a, char[] b, int i, int j) {
        char temp = a[i];
        a[i] = b[j];
        b[j] = temp;
    }

    static void factorial(long[] fact, long[] fact_inv, int n, long mod) {
        fact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = (i * fact[i - 1]) % mod;
        }
        for (int i = 0; i < n; i++) {
            fact_inv[i] = power(fact[i], mod - 2, mod);

                                                       

        }

        

        

    }

    static void find(int i, int n, int[] row, int[] col, int[] d1, int[] d2) {
        if (i >= n) {
            ans++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (col[j] == 0 && d1[i - j + n - 1] == 0 && d2[i + j] == 0) {
                col[j] = 1;
                d1[i - j + n - 1] = 1;
                d2[i + j] = 1;
                find(i + 1, n, row, col, d1, d2);
                col[j] = 0;
                d1[i - j + n - 1] = 0;
                d2[i + j] = 0;
            }
        }
    }

    static int answer(int l, int r, int[][] dp) {
        if (l > r)
            return 0;
        if (l == r) {
            dp[l][r] = 1;
            return 1;
        }
        if (dp[l][r] != -1)
            return dp[l][r];
        int val = Integer.MIN_VALUE;
        int mid = l + (r - l) / 2;
        val = 1 + Math.max(answer(l, mid - 1, dp), answer(mid + 1, r, dp));
        return dp[l][r] = val;
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    static void print(int[] a) {
        for (int i = 0; i < a.length; i++)
            p(a[i] + " ");
        pn("");
    }

    static long count(long n) {
        long count = 0;
        while (n != 0) {
            count += n % 10;
            n /= 10;
        }
        return count;
    }

    static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    static int LcsOfPrefix(String a, String b) {
        int i = 0;
        int j = 0;
        int count = 0;
        while (i < a.length() && j < b.length()) {
            if (a.charAt(i) == b.charAt(j)) {
                j++;
                count++;
            }
            i++;
        }
        return a.length() + b.length() - 2 * count;
    }

    static void reverse(int[] a, int n) {
        for (int i = 0; i < n / 2; i++) {
            int temp = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = temp;
        }
    }

    static char get_char(int a) {
        return (char) (a + 'A');
    }

    static int find1(int[] a, int val) {
        int ans = -1;
        int l = 0;
        int r = a.length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] <= val) {
                l = mid + 1;
                ans = mid;
            } else
                r = mid - 1;
        }
        return ans;
    }

    static int find2(int[] a, int val) {
        int l = 0;
        int r = a.length - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] <= val) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans;
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

}