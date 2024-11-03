import java.util.*;
import java.io.*;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class Main{
    static class Node {
        long sum, pre;
        Node(long a, long b) {
            this.sum = a;
            this.pre = b;
        }
    }
    static  class SegmentTree {
        int l , r; 

        SegmentTree left , right;
        List<Integer> list;
        SegmentTree(int l,int r,int a[]) {
            this.l = l;
            this.r = r;
            list= new ArrayList<>();
            if(l == r) {
                list.add(a[l]);
                return ;
            }
            int mid = l + (r-l)/2;
            this.left = new SegmentTree(l ,mid , a);
            this.right = new SegmentTree(mid + 1 , r,a);
            add(this.left.list , this.right.list);
        }
        public void add(List<Integer>l1  , List<Integer> l2) {
            list = new ArrayList<>();
            int i =0 , j = 0;
            while(i < l1.size() && j < l2.size()) {
                if(l1.get(i) <= l2.get(j))  {
                    list.add(l1.get(i++));
                }
                else list.add(l2.get(j++));
            }
            while(i < l1.size()) {
                list.add(l1.get(i++));
            }
            while(j < l2.size()) {
                list.add(l2.get(j++));   
            }
            

        }
        public  long query(int left ,int right,int q) {
            if(this.l > right || this.r < left) {
                return 0l;
            }
            if(this.l >= left && this.r <= right) {
                int  L =  0 , R = list.size()-1;
                while(L <= R) {
                    int mid = L + (R-L)/2;
                    if(list.get(mid) <= q) L = mid + 1;
                    else R = mid-1;
                }
                

                return list.size() - L;
            }
            return this.left.query(left , right , q) + this.right.query(left , right , q);
        }
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        public int join(int a ,int b) {
            return a + b;
        }
    }
    
    static class Hash {
        long hash[] ,mod = (long)1e9 + 7 , powT[] , prime , inverse[];
        Hash(char []s)  {
            prime = 131;
            int n = s.length;
            powT = new long[n];
            hash = new long[n];
            inverse = new long[n];
            powT[0] = 1;
            inverse[n-1] = pow(pow(prime  , n-1 ,mod), mod-2 , mod);
            for(int i = 1;i < n; i++ ) {
                powT[i] = (powT[i-1]*prime)%mod;
            }
            for(int i = n-2; i>= 0;i-=1)  {
                inverse[i] = (inverse[i+1]*prime)%mod;
            }
            hash[0] = (s[0] - 'a' + 1);
            for(int i = 1; i < n;i++ ) {
                hash[i] = hash[i-1] + ((s[i]-'a' + 1)*powT[i])%mod;
                hash[i] %= mod;
            }
        }
        public long hashValue(int l , int r) {
            if(l == 0) return hash[r]%mod;
            long ans = hash[r]  - hash[l-1] +mod;
            ans %= mod;
            

            ans *= inverse[l];
            ans %= mod;
            return ans;
        }
    }

    static class Kattio extends PrintWriter {
        private BufferedReader r;
        private StringTokenizer st;
    
        

        public Kattio() { this(System.in, System.out); }
        public Kattio(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }
        

        public Kattio(String problemName) throws IOException {
            super(new FileWriter(problemName + ".out"));
            r = new BufferedReader(new FileReader(problemName + ".in"));
        }
    
        

        public String next() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(r.readLine());
                return st.nextToken();
            } catch (Exception e) { }
            return null;
        }
    
        public int nextInt() { return Integer.parseInt(next()); }
        public double nextDouble() { return Double.parseDouble(next()); }
        public long nextLong() { return Long.parseLong(next()); }
    }   
    
    static Kattio sc = new Kattio();
    static long  mod  = 998244353l;
    

 
    

    public static void swap(int i,int j,int arr[]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static long max(long ...a) {
        return maxArray(a);
    }
    public static void swap(int i,int j,long arr[]) {
        long temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static void swap(int i,int j,char arr[]) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    static String endl = "\n" , gap = " ";
    static int size[];
    static int parent[];
    static HashMap<Integer , Long> value;
    

    
    


    static boolean vis[];
    static int answer;
    static HashSet<String> guess;
    static long primePow[];
    

    static int N;
    static int dis[];
    static int height[];
    static long p[];
    static long fac[];
    static long inv[];
    static HashMap<Integer ,List<int[]>> graph;
    public static void main(String[] args)throws IOException {
        int t  = ri();

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

            
        

        

        

        

        

        int test_case = 1;
        while(t-->0) {
            

            solve();
        }
        sc.close();
    }
    public static void solve()throws IOException {          
        int n = ri();
        long k = rl( ) , a[] = ral(n);
        long ans = 0 , sum = 0;
        for(int i = 0;i < n;i++) {
            long p = 1;
            long cur = sum;
            for(int j = i; j < n  && p <= 31;j++) {
                cur += (a[j]>>p);
                p++;
            }
            ans = Math.max(ans, cur);
            sum += a[i] - k;
        }
        ans = Math.max(ans , sum);
        System.out.println(ans);

    }
    public static List<Integer>  get(char s[]) {
        List<Integer> l = new ArrayList<>();
        for(int i =0;i < s.length-1;i++) {
            if(s[i] != s[i+1]) l.add(i);
        }
        return l;
    }
    public static void dfs(int node , int time) {
        vis[node]= true;
        for(int next[] : graph.get(node)) {
            if(vis[next[0]]) continue;
            if(time > next[1]) continue;
            dfs(next[0] , next[1]);
        }
    }
    
    
    
    
    
    
    public static int lis(int A[], int size) {
        int[] tailTable = new int[size];    
        int len;
        tailTable[0] = A[0];
        len = 1;
        for (int i = 1; i < size; i++) {
            if (A[i] < tailTable[0]) tailTable[0] = A[i];
            else if (A[i] > tailTable[len - 1]) tailTable[len++] = A[i];
            else tailTable[CeilIndex(tailTable, -1, len - 1, A[i])] = A[i];
        }
        return len;
    }
    public static int CeilIndex(int A[], int l, int r, int key) {
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (A[m] >= key) r = m;
            else l = m;
        }
        return r;
    }
    public static long unset(long n, long k) {
       long ans =  (n & (~(1l << (k - 1l))));
       return ans;
    }
    public static long setKthBit(long n, long k) {
        return ((1l << k) | n);
    }
    

    

    

    

    

    

    

    

    

    

    

    public static int lcs(char a[] , char b[]) {
        int n = a.length , m = b.length;
        int dp[][] = new int[n + 1][m + 1];
        for(int i =1;i <= n;i++) {
            for(int j =1;j <= m;j++) {
                if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = Math.max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    public static int find(int node) {
        if(node == parent[node]) return node;
        return parent[node]  = find(parent[node]);
    }
    public static void merge(int a ,int b ) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(size[a] >= size[b]) {
            parent[b] = a;
            size[a] += size[b];
            primePow[a] += primePow[b];
            primePow[b] = 0;
        }
        else {
            parent[a] = b;
            size[b] += size[a];   
            primePow[b] += primePow[a];
            primePow[a] = 0;
        }
    }
    public static  void processPowerOfP(long arr[]) {
        int n = arr.length;
        arr[0] = 1;
        long mod  = (long)1e9 + 7;
        for(int i =1;i<n;i++) {
            arr[i] = arr[i-1]*51;
            arr[i] %= mod;
        }
    }
    public static long hashValue(char s[]) {
        int n = s.length;
        long powerOfP[] = new long[n];
        processPowerOfP(powerOfP);
        long ans =0;
        long mod  = (long)1e9 + 7;
        for(int i =0;i<n;i++) {
            ans += (s[i]-'a'+1)*powerOfP[i];
            ans %= mod;
        }
        return ans;
    }
    public static void dfs(int r,int c,char arr[][]) {
        int n  = arr.length , m = arr[0].length;
        arr[r][c] = '#';
        for(int i =0;i<4;i++) {
            int nr = r + colx[i] , nc = c + coly[i];
            if(nr < 0 || nc < 0 || nc >= m || nr>=n) continue;
            if(arr[nr][nc] == '#') continue;
            dfs(nr,nc,arr);
        }
    }
    
    public static double getSlope(int a , int b,int x,int y) {
        if(a-x == 0) return Double.MAX_VALUE;
        if(b-y == 0) return 0.0;
        return ((double)b-(double)y)/((double)a-(double)x);
    }
    
    public static boolean collinearr(long a[] , long b[] , long c[]) {
        return (b[1]-a[1])*(b[0]-c[0]) == (b[0]-a[0])*(b[1]-c[1]);
    }
    public static boolean isSquare(long sum) {
        long root = (int)Math.sqrt(sum);
        return root*root == sum;
    }
    
    public static boolean isPalindrome(String s) {
        int i =0 , j = s.length() -1;
        while(i <= j && s.charAt(i) == s.charAt(j)) {
            i++;
            j--;
        }
        return i>j;
    }
    

    public static long callfun(String num , int N, int last ,int secondLast ,int bound ,long dp[][][][]) {
        if(N == 1) {
            if(last == -1 || secondLast == -1) return 0;
            long answer = 0;
            int max = (bound==1)?(num.charAt(num.length()-N)-'0') : 9;
            for(int i = 0;i<=max;i++) {
                if(last > secondLast && last > i) {
                    answer++;
                }
                if(last < secondLast && last < i) {
                    answer++;
                }
            }
            return answer;
        }
        if(secondLast == -1 || last == -1 ){
            long answer = 0l;
            int max = (bound==1)?(num.charAt(num.length()-N)-'0') : 9;
            for(int i =0;i<=max;i++)  {
                int nl , nsl , newbound = bound==0?0:i==max?1:0;
                if(last == - 1&& secondLast == -1 && i == 0) {
                    nl = -1 ; nsl = -1;
                }
                else {
                    nl = i;nsl = last;
                }

                long temp = callfun(num , N-1 , nl , nsl ,newbound, dp);
                answer += temp;
                if(last != -1 && secondLast != -1 &&((last > secondLast && last > i)||(last < secondLast && last < i))) answer++;
            }
            return answer;    
        }
        if(dp[N][last][secondLast][bound] != -1)  return dp[N][last][secondLast][bound];
        long answer = 0l;
        int max = (bound==1)?(num.charAt(num.length()-N)-'0') : 9;
        for(int i =0;i<=max;i++)  {
            int nl , nsl , newbound = bound==0?0:i==max?1:0;
            if(last == - 1&& secondLast == -1 && i == 0) {
                nl = -1 ; nsl = -1;
            }
            else {
                nl = i;nsl = last;
            }
            long temp = callfun(num , N-1 , nl , nsl ,newbound,dp);
            answer += temp;
            if(last != -1 && secondLast != -1 &&((last > secondLast && last > i)||(last < secondLast && last < i))) answer++;
        }
        return dp[N][last][secondLast][bound]  = answer;
    }
    public static Long callfun(int index ,int pair,int arr[],Long dp[][]) {
        long mod = 998244353l;
        if(index >= arr.length) return 1l;
        if(dp[index][pair] != null) return dp[index][pair]; 
        Long sum = 0l , ans = 0l;
        if(arr[index]%2 == pair) {
            return dp[index][pair] = callfun(index + 1,pair^1 , arr,dp)%mod + callfun(index + 1 ,pair , arr , dp)%mod;
        }
        else {
            return dp[index][pair] = callfun(index + 1,pair ,  arr,dp)%mod;
        }
        

        

        

        

        

        

        

        

    }
    public static boolean callfun(int index , int n,int neg , int pos , String s) {
        if(neg < 0 || pos < 0) return false;
        if(index >= n) return true;
        
        if(s.charAt(0) == 'P') {
            if(neg <= 0) return false;
            return callfun(index + 1,n , neg-1 , pos , s.charAt(1)  + "N");
        }
        else  {
            if(pos <= 0) return false;
            return callfun(index + 1 , n , neg , pos-1 , s.charAt(1) + "P");
        }
    }
    
    public static void getPerm(int n , char arr[] , String s ,List<String>list) {
        if(n == 0) {
            list.add(s);
            return;
        }
        for(char ch : arr) {
            getPerm(n-1 , arr , s+ ch,list);
        }
    }
    public static int getLen(int i  ,int j , char s[]) {
        while(i >= 0 && j < s.length && s[i] == s[j]) {
            i--;
            j++;
        }
        i++;
        j--;
        if(i>j) return 0;
        return j-i + 1;
    }
    public static int getMaxCount(String x) {
        char s[] = x.toCharArray();
        int max = 0;
        int n = s.length;
        for(int i =0;i<n;i++) {
            max = Math.max(max,Math.max(getLen(i , i,s) , getLen(i ,i+1,s)));
        }
        return max;
    }
    public static double getDis(int arr[][] , int  x, int y) {
        double ans = 0.0;
        for(int a[] : arr) {
            int x1 = a[0] , y1 = a[1];
            ans += Math.sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
        }
        return ans;
    }
    public static boolean valid(String x ) {
        if(x.length() == 0) return true;
        if(x.length() == 1) return false;
        char s[] = x.toCharArray();
        if(x.length()  == 2) {
            if(s[0] == s[1]) {
                return false;
            }
            return true;
        }
        int r = 0 , b = 0;
        for(char ch : x.toCharArray()) {
            if(ch == 'R') r++;
            else b++;
        }
        return (r >0 && b >0);


    }

    public static void primeDivisor(HashMap<Long , Long >cnt , long num) {
        for(long i = 2;i*i<=num;i++) {
            while(num%i == 0) {
                cnt.put(i ,(cnt.getOrDefault(i,0l) + 1));
                num /= i;
            }
        }
        if(num > 2) {
            cnt.put(num ,(cnt.getOrDefault(num,0l) + 1));
        }
    }
    
    
    public static boolean isSubsequene(char a[],  char b[] ) {
        int i =0 , j = 0;
        while(i < a.length && j  <b.length) {
            if(a[i] == b[j]) {
                j++;
            }
            i++;
        }
        return  j >= b.length;
    }
    public static long fib(int n ,long M) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            long[][] mat = {{1, 1}, {1, 0}};
            mat = pow(mat, n-1 , M);
            return mat[0][0];
        }
    }
    public static long[][] pow(long[][] mat, int n ,long M) {
        if (n == 1) return mat;
        else if (n % 2 == 0) return pow(mul(mat, mat , M), n/2 , M);
        else return mul(pow(mul(mat, mat,M), n/2,M), mat , M);
    }
    static long[][] mul(long[][] p, long[][] q,long M) {
        long a = (p[0][0]*q[0][0] + p[0][1]*q[1][0])%M;
        long b = (p[0][0]*q[0][1] + p[0][1]*q[1][1])%M;
        long c = (p[1][0]*q[0][0] + p[1][1]*q[1][0])%M;
        long d = (p[1][0]*q[0][1] + p[1][1]*q[1][1])%M;
        return new long[][] {{a, b}, {c, d}};
    }
    public static long[] kdane(long arr[]) {
        int n = arr.length;
        long dp[] = new long[n];
        dp[0] = arr[0];
        long ans = dp[0];
        for(int i = 1;i<n;i++) {
            dp[i] = Math.max(dp[i-1] + arr[i] , arr[i]);
            ans = Math.max(ans , dp[i]);
        }
        return dp;
    }
    
   
    public static void update(int low , int high , int l , int r, int val , int treeIndex ,int tree[]) {

        if(low > r || high < l || high < low) return;
        if(l <= low && high <= r) {
            System.out.println("At " +low + " and " + high + " ans ttreeIndex  " + treeIndex);
            tree[treeIndex] += val;
            return;
        }
        int mid = low + (high - low)/2;
        update(low , mid , l , r , val , treeIndex*2  + 1, tree);
        update(mid + 1 , high , l , r , val , treeIndex*2 + 2 , tree);
    }
    static int colx[] = {1 ,1, -1,-1 , 2,2,-2,-2};
    static int coly[] = {-2 ,2, 2,-2,1,-1,1,-1};
    

    

    public static void reverse(char arr[])  {
        int i =0 , j = arr.length-1;
        while(i < j) {
            swap(i , j , arr);
            i++;
            j--;
        }
    }
    public static void reverse(long arr[])  {
        int i =0 , j = arr.length-1;
        while(i < j) {
            swap(i , j , arr);
            i++;
            j--;
        }
    }
    public static void reverse(int arr[])  {
        int i =0 , j = arr.length-1;
        while(i < j) {
            swap(i , j , arr);
            i++;
            j--;
        }
    }
    
    public static long inverse(long x  , long mod) {
        return pow(x , mod -2 , mod);
    }
    public static int maxArray(int arr[]) {
        int ans = arr[0] ,  n = arr.length;
        for(int i =1;i<n;i++) {
            ans = Math.max(ans , arr[i]);
        }
        return ans;
    }
    public static long maxArray(long arr[]) {
        long ans = arr[0];
        int  n = arr.length;
        for(int i =1;i<n;i++) {
            ans = Math.max(ans , arr[i]);
        }
        return ans;
    }
    public static int minArray(int arr[]) {
        int ans = arr[0] , n = arr.length;
        for(int i =0;i<n;i++ ) {
            ans = Math.min(ans ,arr[i]);
        }
        return ans;
    }
    public static long minArray(long arr[]) {
        long ans = arr[0];
        int n = arr.length;
        for(int i =0;i<n;i++ ) {
            ans = Math.min(ans ,arr[i]);
        }
        return ans;
    }
    public static int sumArray(int arr[]) {
        int ans = 0;
        for(int x : arr) {
            ans  += x;
        }
        return ans;
    }
    public static long sumArray(long arr[]) {
        long ans = 0;
        for(long x : arr) {
            ans  += x;
        }
        return ans;
    }
    public static long rl() {
        return sc.nextLong();
    }
    public static char[] rac() {
        return sc.next().toCharArray();
    }
    public static String rs() {
        return sc.next();
    }
    public static char rc() {
        return sc.next().charAt(0);
    }
    public static  int [] rai(int n) {
        int ans[] = new int[n];
        for(int i =0;i<n;i++) {
            ans[i] = sc.nextInt();
        }
        return ans;
    }
    public static  long [] ral(int n) {
        long ans[] = new long[n];
        for(int i =0;i<n;i++) {
            ans[i] = sc.nextLong();
        }
        return ans;
    }
    public static int ri() {
        return sc.nextInt();
    }

    public static int getValue(int num ) {
        int ans = 0;
        while(num > 0) {
            ans++;
            num = num&(num-1);
        }
        return ans;
    }
    public static boolean isValid(int x ,int y , int n,char arr[][],boolean visited[][][][])  {
        return x>=0 && x<n && y>=0 && y <n && !(arr[x][y] == '#');
    }
    

    

    

    

    
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    public static long pow(long a , long b  , long mod) {
        if(b == 1) return a;
        if(b == 0) return 1;
        long ans = pow(a , b/2 , mod)%mod;
        if(b%2 == 0) {
            return (ans*ans)%mod;
        }
        else {
            return ((ans*ans)%mod*a)%mod;
        }
    }
    public static long pow(long a , long b ) {
        if(b == 1) return a;
        if(b == 0) return 1;
        long ans = pow(a , b/2);
        if(b%2 == 0) {
            return (ans*ans);
        }
        else {
            return ((ans*ans)*a);
        }
    }
    
    
    public static boolean isVowel(char ch) {
        if(ch == 'a' || ch == 'e'||ch == 'i' || ch == 'o' || ch == 'u') return true;
        if((ch == 'A' || ch == 'E'||ch == 'I' || ch == 'O' || ch == 'U'))  return true;
        return false;
    }

    
    
    

    

    

    

    

    

    

    

    


    public static int[] readarr()throws IOException {
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i =0;i<n;i++) {
            arr[i] =  sc.nextInt();
        }
        return arr;
    }
 
    public static boolean isPowerOfTwo (long x) {
        return x!=0 && ((x&(x-1)) == 0);
    }
    public static boolean isPrime(long num) {
        if(num==1) return false;
        if(num<=3) return true;
        if(num%2==0||num%3==0) return false;
        for(long i =5;i*i<=num;i+=6) {
            if(num%i==0 || num%(i+2) == 0) return false;
        }
        return true;
    }
    public static boolean isPrime(int num) {
        

        if(num==1) return false;
        if(num<=3) return true;
        if(num%2==0||num%3==0) return false;
        for(int i =5;i*i<=num;i+=6) {
            if(num%i==0 || num%(i+2) == 0) return false;
        }
        return true;
    }
    

    

    

    

    

    

    

    

    

    public static long gcd(long a , long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public static int gcd(int a , int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public static int get_gcd(int a , int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public static long get_gcd(long a , long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    

    

    

    

    

    

    

    

}
