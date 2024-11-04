import java.util.*;
import java.util.concurrent.CountDownLatch;

import javax.lang.model.element.QualifiedNameable;
import javax.swing.ViewportLayout;
import javax.swing.plaf.basic.BasicTreeUI.TreeCancelEditingAction;
import javax.swing.plaf.metal.MetalComboBoxUI.MetalPropertyChangeListener;
import javax.swing.text.html.HTMLDocument.HTMLReader.CharacterAction;

import org.w3c.dom.Node;

import java.lang.*;
import java.math.BigInteger;
import java.net.CookieHandler;
import java.security.cert.CollectionCertStoreParameters;
import java.text.BreakIterator;
import java.io.*;

@SuppressWarnings("unchecked")
public class Main {
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

    static long divisor(long n) {
        long count = 0;
        for (long i = 1L; i * i <= n; i++) {
            if (n % i == 0) {
                if (i == n / i)
                    count += i;
                else {
                    count += i;
                    count += n / i;
                }
            }
        }
        return count;
    }

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    


    
    static class pair implements Comparable<pair> {
        int a;
        int b;
        int index;

        public pair(int a, int b, int index) {
            this.a = a;
            this.b = b;
            this.index = index;
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

    static class node {
        long value;
        int index;

        public node(long value, int index) {
            this.value = value;
            this.index = index;
        }
    }

    static class comparator implements Comparator<node> {
        public int compare(node a, node b) {
            return a.value - b.value > 0 ? 1 : -1;
        }
    }

    static class Segment_Tree {
        static {
            final int val;
            val = 3;
            pn(val);
        }
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

    

    static int ans = 0;
    static int leaf = 0;
    static boolean poss = true;
    static int bottom = Integer.MAX_VALUE;
    static int right = Integer.MAX_VALUE;
    static int max_right;
    static int max_bottom;
    static long mod = 1000000007L;
    int glo = 0;

    public static void main(String[] args) throws Exception {
        in = new FastReader();
        out = new PrintWriter(System.out);
        int tc = ni();
        int[] ans=bfs();
        while (tc-- > 0) {
            int n=ni();
            int k=ni();
            int[] b=new int[n+1];
            int[] c=new int[n+1];
            for(int i=1;i<=n;i++){
                b[i]=ni();
            }
            for(int i=1;i<=n;i++){
                c[i]=ni();
            }
            int[] dp=new int[Math.min(12001,k+1)];
            int[] pre=new int[Math.min(12001,k+1)];
            for(int i=1;i<=n;i++){
                for(int j=0;j<=Math.min(12000,k);j++){
                    dp[j]=Math.max(dp[j],pre[j]);
                    if(ans[b[i]]<=j){
                        dp[j]=Math.max(dp[j],c[i]+pre[j-ans[b[i]]]);
                    }
                }
                for(int j=0;j<=Math.min(12000,k);j++)
                {
                    pre[j]=dp[j];
                }
            }
            

            

            

            

            

            

            pn(dp[Math.min(k, 12000)]);
        }

        out.flush();
        out.close();
    }
    static int[] bfs(){
        Queue<Integer> q=new LinkedList<>();
        q.add(1);
        int[] ans=new int[1001];
        int count=0;
        boolean[] visited=new boolean[1001];
        visited[1]=true;
        while(q.size()>0){
            int val=q.size();
            while(val>0){
                int v=q.poll();
                ans[v]=count;
                for(int i=1;i<=v;i++){
                    int curr=v+(v/i);
                    if(curr<1001 && !visited[curr]){
                        visited[curr]=true;
                        q.add(curr);
                    }
                }
                val--;
            }
            count++;
        }
        int max=-1;
        

        

        

        

        return ans;

    }

    static int find(Set<Integer> s1, Set<Integer> s2, int n) {
        for (Integer a : s1) {
            

            if (s2.contains(a) && a>=n)
                return a;
        }
        return -1;
    }

    void prin(int n) {
        pn(glo);
    }

    static void dfs(int i, List<List<Integer>> arr, boolean[] visited, int n, int m, int[] group, boolean val,
            int count) {
        

        visited[i] = true;
        if (count > m) {
            val = true;
        }
        int l = 0;
        for (int v : arr.get(i)) {
            if (val) {
                if (!visited[v]) {
                    l++;
                    dfs(v, arr, visited, n, m, group, val, count);
                }
            } else {
                if (!visited[v]) {
                    l++;
                    if (group[v] == 1) {
                        dfs(v, arr, visited, n, m, group, val, count + 1);
                    } else {
                        dfs(v, arr, visited, n, m, group, val, 0);
                    }
                }
            }
        }
        if (l == 0) {
            leaf++;
            if (val)
                ans++;
        }
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

    static TreeSet<Integer> ans(int n) {
        TreeSet<Integer> set = new TreeSet<>();
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                set.add(i);
                set.add(n / i);
            }
        }
        set.remove(1);
        return set;
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
        return (char) (a + 'a');
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
