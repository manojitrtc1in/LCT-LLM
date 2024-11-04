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
        HashSet<Integer> set;
        int min , max , inf = (int)1e8;
        SegmentTree(int l,int r,int a[][]) {
            this.l = l;
            this.r = r;
            if(l == r) {
                min = a[l][0] ; max = a[l][1];
                return ;
            }
            int mid = l + (r-l)/2;
            this.left = new SegmentTree(l ,mid , a);
            this.right = new SegmentTree(mid + 1 , r,a);
            this.min = Math.max(this.left.min , this.right.min);
            this.max = Math.min(this.right.max , this.left.max);
        }
        public  int[] query(int left ,int right,int len) {
            if(this.l > right || this.r < left) {
                return new int[]{0 , inf};
            }
            if(this.l >= left && this.r <= right) {
                return new int[]{this.min , this.max};
            }
            int a1[] = this.left.query(left , right,len);
            if(a1[1]-a1[0] + 1 < len) return new int[]{0,0};
            int a2[] = this.right.query(left , right,len);
            return new int[]{Math.max(a1[0] , a2[0]) , Math.min(a1[1] , a2[1])};
            
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

    static class id10 extends PrintWriter {
        private BufferedReader r;
        private StringTokenizer st;
    
        

        public id10() { this(System.in, System.out); }
        public id10(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }
        

        public id10(String problemName) throws IOException {
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
    
    static id10 sc = new id10();
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
    

    static ArrayList<Integer> graph[];
    


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
        int a[] = rai(n);
        int b[] = rai(n);
        for(int i =0;i < n;i++) {
            while(a[i]%2 == 0) a[i]/=2;
        }
        HashMap<Integer , Integer >map = new HashMap<>();
        

        

        


        for(int x : a) {
            map.put(x , map.getOrDefault(x ,0)+ 1);
        }
        

        for(int y : b) {
            boolean flag = false;
            int  x= y;
            while(x > 0) {
                if(map.containsKey(x)) {
                    map.put(x , map.get(x)-1);
                    if(map.get(x) == 0) map.remove(x);
                    flag = true;
                    break;
                }
                else x /= 2;
            }
            if(!flag)  {System.out.println("NO");return ;}
        }
        System.out.println("YES");

    }
    public static boolean solve(int a[][]) {
        HashSet<Integer> set = new HashSet<>();
        int n = a.length;
        for(int i =0;i < n;i++) {
            int  b[] = a[i];
            if(vis[i]) continue;
            if(b[0] == b[1]) return false;
            if(set.contains(b[0]) || set.contains(b[1])) continue;
            set.add(b[0]);
            set.add(b[1]);
            vis[i] = true;
        }
        for(int i =1;i <= n;i++) {
            if(!set.contains(i)) return false;
        }
        return true;
    }
    
    public static int lis(int A[], int size) {
        int[] tailTable = new int[size];    
        int len;
        tailTable[0] = A[0];
        len = 1;
        for (int i = 1; i < size; i++) {
            if (A[i] < tailTable[0]) tailTable[0] = A[i];
            else if (A[i] > tailTable[len - 1]) tailTable[len++] = A[i];
            else tailTable[id11(tailTable, -1, len - 1, A[i])] = A[i];
        }
        return len;
    }
    public static int id11(int A[], int l, int r, int key) {
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
    public static long id1(long n, long k) {
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
    public static  void id5(long arr[]) {
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
        long id9[] = new long[n];
        id5(id9);
        long ans =0;
        long mod  = (long)1e9 + 7;
        for(int i =0;i<n;i++) {
            ans += (s[i]-'a'+1)*id9[i];
            ans %= mod;
        }
        return ans;
    }
    public static void dfs(int r,int c,char arr[][]) {
        int n  = arr.length , m = arr[0].length;
        arr[r][c] = '
        for(int i =0;i<4;i++) {
            int nr = r + colx[i] , nc = c + coly[i];
            if(nr < 0 || nc < 0 || nc >= m || nr>=n) continue;
            if(arr[nr][nc] == '
            dfs(nr,nc,arr);
        }
    }
    
    public static double getSlope(int a , int b,int x,int y) {
        if(a-x == 0) return Double.MAX_VALUE;
        if(b-y == 0) return 0.0;
        return ((double)b-(double)y)/((double)a-(double)x);
    }
    
    public static boolean id0(long a[] , long b[] , long c[]) {
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
    public static int id7(String x) {
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

    public static void id8(HashMap<Long , Long >cnt , long num) {
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
    
    
    public static boolean id6(char a[],  char b[] ) {
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
        return x>=0 && x<n && y>=0 && y <n && !(arr[x][y] == '
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
    
    
    public static boolean id4(char ch) {
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
 
    public static boolean id3 (long x) {
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
    public static int id2(int a , int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public static long id2(long a , long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    

    

    

    

    

    

    

    

}