import java.util.*;
import java.io.*;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.math.BigInteger;



public final class Main{
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
 
        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public Reader(String file_name) throws IOException {
            din = new DataInputStream(
                new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public String readLine() throws IOException {
            byte[] buf = new byte[64]; 

            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                buf[cnt++] = (byte)c;
            }
            return new String(buf, 0, cnt);
        }
 
        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
 
            if (neg)
                return -ret;
            return ret;
        }
 
        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
 
        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ') c = read();
            boolean neg = (c == '-');
            if (neg) c = read();
 
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }
            if (neg) return -ret;
            return ret;
        }
 
        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0,
                                 BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
 
        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }
    static class id7 extends PrintWriter {
        private BufferedReader r;
        private StringTokenizer st;
    
        

        public id7() { this(System.in, System.out); }
        public id7(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }
        

        public id7(String problemName) throws IOException {
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
    
    static id7 sc = new id7();
    static long  mod  = 998244353l;
    static PrintWriter out =new PrintWriter(System.out);
 
    

    public static void swap(int i,int j,int arr[]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
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
    public static void main(String[] args)throws IOException {
        int t =ri();
        

        

        

        

        

        

        


        

        

        

        int test_case = 1;
        while(t-->0) {
            

            solve();
        }
        out.close();
    }
    public static void solve()throws IOException {       
        int n = ri() , m = ri();
        char arr[][] = new char[n][];
        for(int i =0;i<n;i++) {
            arr[i] = rac();
        }
        if(arr[0][0] == '1') {
            out.write(-1 + endl);
            return;
        }
        List<int[]> list = new ArrayList<>();
        

        for(int i =n-1;i>=0;i--) {
            for(int j = m-1;j>=0;j--) {
                if(arr[i][j] == '1') {
                    if(j-1>=0) list.add(new int[]{i,j-1, i,j});
                    else  list.add(new int[]{i-1,j, i,j});
                }
            }
        }
        

        out.write(list.size() + endl);
        for(int a[]  : list) {
            for(int x  :a) {
                out.write((x+1) + " ");
            }
            out.write(endl);
        }
        

    }
    
    public static boolean id0(long a[] , long b[] , long c[]) {
        return (b[1]-a[1])*(b[0]-c[0]) == (b[0]-a[0])*(b[1]-c[1]);
    }
    public static boolean isSquare(int sum) {
        int root = (int)Math.sqrt(sum);
        return root*root == sum;
    }
    public static boolean id8(int prev,int len , int sum,int arr[],int idx) {
        

        if(len == 0) {
            if(isSquare(sum)) return true;
            return false;
        }
        for(int i = prev;i<=9;i++) {
            arr[idx] = i;
            if(id8(i, len-1,sum + i*i,arr,idx  + 1)) {
                return true;
            }
        }
        return false;
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
        long mod = (long)998244353l;
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
    public static int id5(String x) {
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
    public static long callfun(int day , int k,  int limit,int n) {
        if(k > limit) return 0;
        if(day > n) return 1;
        long ans = callfun(day + 1 , k , limit, n)*k + callfun(day + 1,k+1,limit,n)*(k+1);
        return  ans;
    }

    public static void id6(HashMap<Long , Long >cnt , long num) {
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
    
    
    public static boolean id4(char a[],  char b[] ) {
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
    static int colx[] = {1 ,-1, 0,0 , 1,1,-1,-1};
    static int coly[] = {0 ,0, 1,-1,1,-1,1,-1};
    public static void reverse(char arr[])  {
        int i =0 , j = arr.length-1;
        while(i < j) {
            swap(i , j , arr);
            i++;
            j--;
        }
    }
    public static long[] reverse(long arr[])  {
        long newans[] = arr.clone();
        int i =0 , j = arr.length-1;
        while(i < j) {
            swap(i , j , newans);
            i++;
            j--;
        }
        return newans;
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
    
    
    public static boolean id3(char ch) {
        if(ch == 'a' || ch == 'e'||ch == 'i' || ch == 'o' || ch == 'u') return true;
        if((ch == 'A' || ch == 'E'||ch == 'I' || ch == 'O' || ch == 'U'))  return true;
        return false;
    }

    
    
    public static int getFactor(int num) {
        if(num==1) return 1;
        int ans = 2;
        int k = num/2;
        for(int i = 2;i<=k;i++) {
            if(num%i==0) ans++;
        }
        return Math.abs(ans);
    }

    public static int[] readarr()throws IOException {
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i =0;i<n;i++) {
            arr[i] =  sc.nextInt();
        }
        return arr;
    }
 
    public static boolean id2 (long x) {
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
    public static int id1(int a , int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public static long id1(long a , long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    

    

    

    

    

    

    

    

}