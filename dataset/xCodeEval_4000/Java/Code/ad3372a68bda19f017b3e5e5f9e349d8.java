import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
public final class E_Binary_Inversions {
 
    

    static PrintWriter out = new PrintWriter(System.out);
    static FastReader fs = new FastReader();
    static Pair[] moves = new Pair[]{new Pair(-1, 0), new Pair(0, 1), new Pair(1, 0), new Pair(0, -1)};
    static Pair[] movesDiagonal = new Pair[]{new Pair(-1, -1), new Pair(-1, 1), new Pair(1, -1), new Pair(1, 1)};
 
    static int mod = (int) (1e9 + 7);
    static int mod2 = 998244353;
 
    public static void main(String[] args) {
        int tt = fs.nextInt();
        while (tt-- > 0) {
            solve();
        }
        out.flush();
    }
 public static void solve() {
int n=fs.nextInt();
int[]a=new int[n];
int[]temp1=new int[n];
int[]temp3=new int[n];
int[]temp4=new int[n];
int[]temp2=new int[n];
for(int i=0;i<n;i++)
{
    int x=fs.nextInt();
    a[i]=x;
    temp1[i]=x;
    temp2[i]=x;
    temp3[i]=x;
    temp4[i]=x;
}
for(int i=0;i<n;i++)
{
    if(a[i]==0)
    {
        temp1[i]=1;
        
        break;
    }
}
for(int i=n-1;i>=0;i--)
{
    if(a[i]==0)
    {
        temp3[i]=1;
        
        break;
    }
}
for(int i=n-1;i>=0;i--)
{
    if(a[i]==1)
    {
        temp4[i]=0;
        
        break;
    }
}
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            temp2[i]=0;
            break;
        }
    }
}
long val3=mergeSortAndCount(a,0,a.length-1);
long val1=Math.max(mergeSortAndCount(temp1,0,temp1.length-1),mergeSortAndCount(temp2,0,temp2.length-1));
long val2=Math.max(mergeSortAndCount(temp3,0,temp3.length-1),mergeSortAndCount(temp4,0,temp4.length-1));
out.println(Math.max(val3,Math.max(val1,val2)));
}
public static long mergeAndCount(int[] arr, int l,
                                     int m, int r)
    {
 
        

        int[] left = Arrays.copyOfRange(arr, l, m + 1);
 
        

        int[] right = Arrays.copyOfRange(arr, m + 1, r + 1);
 
        int i = 0, j = 0, k = l; long swaps = 0;
 
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j])
                arr[k++] = left[i++];
            else {
                arr[k++] = right[j++];
                swaps += (m + 1) - (l + i);
            }
        }
        while (i < left.length)
            arr[k++] = left[i++];
        while (j < right.length)
            arr[k++] = right[j++];
        return swaps;
    }
 
    

    public static long mergeSortAndCount(int[] arr, int l,
                                         int r)
    {
 
        

        

        long count = 0;
 
        if (l < r) {
            int m = (l + r) / 2;
 
            

            

 
            

            count += mergeSortAndCount(arr, l, m);
 
            

            count += mergeSortAndCount(arr, m + 1, r);
 
            

            count += mergeAndCount(arr, l, m, r);
        }
 
        return count;
    }
 
    

    static long upperDiv(long a, long b) {
        return (a / b) + ((a % b == 0) ? 0 : 1);
    }
 
    static long sum(int[] a) {
        long sum = 0;
        for (int x : a) {
            sum += x;
        }
        return sum;
    }
 
    static int[] preint(int[] a) {
        int[] pre = new int[a.length + 1];
        pre[0] = 0;
        for (int i = 0; i < a.length; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        return pre;
    }
 
    static long[] pre(int[] a) {
        long[] pre = new long[a.length + 1];
        pre[0] = 0;
        for (int i = 0; i < a.length; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        return pre;
    }
 
    static long[] post(int[] a) {
        long[] post = new long[a.length + 1];
        post[0] = 0;
        for (int i = 0; i < a.length; i++) {
            post[i + 1] = post[i] + a[a.length - 1 - i];
        }
        return post;
    }
 
    static long[] pre(long[] a) {
        long[] pre = new long[a.length + 1];
        pre[0] = 0;
        for (int i = 0; i < a.length; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        return pre;
    }
 
    static void print(char A[]) {
        for (char c : A) {
            out.print(c);
        }
        out.println();
    }
 
    static void print(boolean A[]) {
        for (boolean c : A) {
            out.print(c + " ");
        }
        out.println();
    }
 
    static void print(int A[]) {
        for (int c : A) {
            out.print(c + " ");
        }
        out.println();
    }
 
    static void print(long A[]) {
        for (long i : A) {
            out.print(i + " ");
        }
        out.println();
    }
 
    static void print(List<Integer> A) {
        for (int a : A) {
            out.print(a + " ");
        }
    }
 
static long mul(long a, long b) {
        return (a*b)%mod;
    }
    static long exp(long base, long exp) {
        if (exp==0) return 1;
        long half=exp(base, exp/2);
        if (exp%2==0) return mul(half, half);
        return mul(half, mul(half, base));
    }
   static long[] factorials=new long[2_000_001];
    static long[] invFactorials=new long[2_000_001];
    static void precompFacts() {
        factorials[0]=invFactorials[0]=1;
        for (int i=1; i<factorials.length; i++) factorials[i]=mul(factorials[i-1], i);
        invFactorials[factorials.length-1]=exp(factorials[factorials.length-1], mod-2);
        for (int i=invFactorials.length-2; i>=0; i--)
            invFactorials[i]=mul(invFactorials[i+1], i+1);
    }

    static long nCk(int n, int k) {
        return mul(factorials[n], mul(invFactorials[k], invFactorials[n-k]));
    }

 
    static int[][] inputWithIdx(int N) {
        int A[][] = new int[N][2];
        for (int i = 0; i < N; i++) {
            A[i] = new int[]{i, fs.nextInt()};
        }
        return A;
    }
 
    static int[] input(int N) {
        int A[] = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = fs.nextInt();
        }
        return A;
    }
 
    static long[] inputLong(int N) {
        long A[] = new long[N];
        for (int i = 0; i < A.length; i++) {
            A[i] = fs.nextLong();
        }
        return A;
    }
 
    static int GCD(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return GCD(b, a % b);
        }
    }
 
    static long GCD(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return GCD(b, a % b);
        }
    }
 
    static long LCM(int a, int b) {
        return (long) a / GCD(a, b) * b;
    }
 
    static long LCM(long a, long b) {
        return a / GCD(a, b) * b;
    }
 
    

    static int lowerbound(int[] a, int x) {
        int l = 0;
        int r = a.length - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (a[m] <= x) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
 
    static void shuffle(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int rand = (int) (Math.random() * arr.length);
            int temp = arr[rand];
            arr[rand] = arr[i];
            arr[i] = temp;
        }
    }
 
    static void shuffleAndSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int rand = (int) (Math.random() * arr.length);
            int temp = arr[rand];
            arr[rand] = arr[i];
            arr[i] = temp;
        }
        Arrays.sort(arr);
    }
 
    static void shuffleAndSort(int[][] arr, Comparator<? super int[]> comparator) {
        for (int i = 0; i < arr.length; i++) {
            int rand = (int) (Math.random() * arr.length);
            int[] temp = arr[rand];
            arr[rand] = arr[i];
            arr[i] = temp;
        }
        Arrays.sort(arr, comparator);
    }
 
    static void shuffleAndSort(long[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int rand = (int) (Math.random() * arr.length);
            long temp = arr[rand];
            arr[rand] = arr[i];
            arr[i] = temp;
        }
        Arrays.sort(arr);
    }
 
    static boolean isPerfectSquare(double number) {
        double sqrt = Math.sqrt(number);
        return ((sqrt - Math.floor(sqrt)) == 0);
    }
 
    static void swap(int A[], int a, int b) {
        int t = A[a];
        A[a] = A[b];
        A[b] = t;
    }
 
    static void swap(char A[], int a, int b) {
        char t = A[a];
        A[a] = A[b];
        A[b] = t;
    }
 
    static long pow(long a, long b, int mod) {
        long pow = 1;
        long x = a;
        while (b != 0) {
            if ((b & 1) != 0) {
                pow = (pow * x) % mod;
            }
            x = (x * x) % mod;
            b /= 2;
        }
        return pow;
    }
 
    static long pow(long a, long b) {
        long pow = 1;
        long x = a;
        while (b != 0) {
            if ((b & 1) != 0) {
                pow *= x;
            }
            x = x * x;
            b /= 2;
        }
        return pow;
    }
 
    static long modInverse(long x, int mod) {
        return pow(x, mod - 2, mod);
    }
 
    static boolean isPrime(long N) {
        if (N <= 1) {
            return false;
        }
        if (N <= 3) {
            return true;
        }
        if (N % 2 == 0 || N % 3 == 0) {
            return false;
        }
        for (int i = 5; i * i <= N; i = i + 6) {
            if (N % i == 0 || N % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
 
    public static String reverse(String str) {
        if (str == null) {
            return null;
        }
        return new StringBuilder(str).reverse().toString();
    }
 
    public static void reverse(int[] arr) {
        int l = 0;
        int r = arr.length - 1;
        while (l < r) {
            swap(arr, l, r);
            l++;
            r--;
        }
    }
 
    public static String repeat(char ch, int repeat) {
        if (repeat <= 0) {
            return "";
        }
        final char[] buf = new char[repeat];
        for (int i = repeat - 1; i >= 0; i--) {
            buf[i] = ch;
        }
        return new String(buf);
    }
 
    public static int[] manacher(String s) {
        char[] chars = s.toCharArray();
        int n = s.length();
        int[] d1 = new int[n];
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : Math.min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && chars[i - k] == chars[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        return d1;
    }
 
    public static int[] kmp(String s) {
        int n = s.length();
        int[] res = new int[n];
        for (int i = 1; i < n; ++i) {
            int j = res[i - 1];
            while (j > 0 && s.charAt(i) != s.charAt(j)) {
                j = res[j - 1];
            }
            if (s.charAt(i) == s.charAt(j)) {
                ++j;
            }
            res[i] = j;
        }
        return res;
    }
}
 
class Pair {
 
    int i;
    int j;
 
    Pair(int i, int j) {
        this.i = i;
        this.j = j;
    }
 
    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        Pair pair = (Pair) o;
        return i == pair.i && j == pair.j;
    }
 
    @Override
    public int hashCode() {
        return Objects.hash(i, j);
    }
}
 
class ThreePair {
 
    int i;
    int j;
    int k;
 
    ThreePair(int i, int j, int k) {
        this.i = i;
        this.j = j;
        this.k = k;
    }
 
    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        ThreePair pair = (ThreePair) o;
        return i == pair.i && j == pair.j && k == pair.k;
    }
 
    @Override
    public int hashCode() {
        return Objects.hash(i, j);
    }
}
 
class FastReader {
 
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
 
class Node {
 
    int val;
 
    public Node(int val) {
        this.val = val;
    }
}
 
 
class ST {
 
    int n;
    Node[] st;
 
    ST(int n) {
        this.n = n;
        st = new Node[4 * Integer.highestOneBit(n)];
    }
 
    void build(Node[] nodes) {
        build(0, 0, n - 1, nodes);
    }
 
    private void build(int id, int l, int r, Node[] nodes) {
        if (l == r) {
            st[id] = nodes[l];
            return;
        }
        int mid = (l + r) >> 1;
        build((id << 1) + 1, l, mid, nodes);
        build((id << 1) + 2, mid + 1, r, nodes);
        st[id] = comb(st[(id << 1) + 1], st[(id << 1) + 2]);
    }
 
    void update(int i, Node node) {
        update(0, 0, n - 1, i, node);
    }
 
    private void update(int id, int l, int r, int i, Node node) {
        if (i < l || r < i) {
            return;
        }
        if (l == r) {
            st[id] = node;
            return;
        }
        int mid = (l + r) >> 1;
        update((id << 1) + 1, l, mid, i, node);
        update((id << 1) + 2, mid + 1, r, i, node);
        st[id] = comb(st[(id << 1) + 1], st[(id << 1) + 2]);
    }
 
    Node get(int x, int y) {
        return get(0, 0, n - 1, x, y);
    }
 
    private Node get(int id, int l, int r, int x, int y) {
        if (x > r || y < l) {
            return new Node(0);
        }
        if (x <= l && r <= y) {
            return st[id];
        }
        int mid = (l + r) >> 1;
        return comb(get((id << 1) + 1, l, mid, x, y), get((id << 1) + 2, mid + 1, r, x, y));
    }
 
    Node comb(Node a, Node b) {
        if (a == null) {
            return b;
        }
        if (b == null) {
            return a;
        }
        return new Node(GCD(a.val, b.val));
    }
 
    static int GCD(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return GCD(b, a % b);
        }
    }
}
