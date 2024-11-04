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
            int n = ri();
            char s[] = rac();
            
            boolean last = false;
            String x = new String(s);
            if(x.indexOf("WBW") != -1) {
                System.out.println("NO");
                return;
            }if(x.indexOf("WRW") != -1) {
                System.out.println("NO");
                return;
            }
            String arr[] = x.split("W");
            for(String cur : arr) {
                if(!valid(cur)) {
                    System.out.println("NO");
                    return;
                }
            }
            System.out.println("YES");


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
        public static int callfun(int arr[],int move , int index , Integer memo[][]) {
            

            if(index >= arr.length-1) return 0;
            if(memo[index][move] != null) return memo[index][move];
            if(move == 0) {
                int next = getNext(arr[index] , arr , index + 1);
                int dif = getNextDIF(arr[index] ,arr , index + 1);
                int ans = Integer.MAX_VALUE;
                if(next != -1) {
                    int curans  = callfun(arr,move ,next , memo);
                    if(curans != Integer.MAX_VALUE)  ans = Math.min(ans , curans + 1);
                }
                if(dif != -1){
                    int curans = callfun(arr , move + 1 , dif ,memo);
                    if(curans != Integer.MAX_VALUE)  ans = Math.min(ans , curans + 1);
                } 
                return memo[index][move] = ans;
            }
            else {
                int next = getNext(arr[index] , arr , index + 1);
                int ans = Integer.MAX_VALUE;
                if(next != -1)  {
                    ans = callfun(arr,move , next , memo);
                    if(ans != Integer.MAX_VALUE) ans++;
                }
                return memo[index][move] = ans;
            }
            
        }
        public static int getNext(int same , int arr[],int index) {
            for(int i = index;i<arr.length;i++) {
                if(arr[i]%2 == same%2) return i;
            }
            return -1;
        }
        public static int getNextDIF(int same , int arr[],int index) {
            for(int i = index;i<arr.length;i++) {
                if(arr[i]%2 != same%2) return i;
            }
            return -1;
        }

        public static boolean hasAll(String  a , String b) {
            for(int i =0;i<b.length();i++) {
                boolean cur = false;
                for(int j =0;j<a.length();j++) {
                    if(b.charAt(i) == a.charAt(j)) cur = true;
                }
                if(cur == false) return false;
            }
            return true;
        }
        public static String getAbsent(String s) {
            char arr[] = {'a' , 'e' , 'i' , 'o' ,'u'};
            StringBuilder res = new StringBuilder();
            for(int i =0;i<5;i++) {
                boolean has = false;
                for(int j =0;j<s.length();j++) {
                    if(s.charAt(j) == arr[i]) has = true;
                }
                if(has == false)res.append(arr[i]);
            }
            return res.toString();
        }
        public static String getCompressed(String x) {
            char s[] = x.toCharArray();
            Arrays.sort(s);
            StringBuilder res = new StringBuilder();
            HashSet<Character> set = new HashSet<>();
            for(char ch : s) {
                if(set.contains(ch)) continue;
                set.add(ch);
                res.append(ch);
            }
            return res.toString();
        }
        public static boolean callfun(char s[] , char t[] , int f1[] , int f2[]) {
            for(int i = 0;i<26;i++) {
                if(f1[i] > 0 && f2[i] == 0) {
                    f1[i]--;
                    return !callfun(s  , t,f2 , f1);
                }
            }
            return false;
        }
        public static void primeFactors(long x  ,HashMap<Long, Integer> map )  {
            int cnt= 0;
            while(x%2 == 0) {
                cnt++;
                x /=2;
            }
            if(cnt > 0) map.put(2l , cnt );
            cnt = 0;
            for(long i =3;i*i<=x;i+=2) {
                cnt = 0;

                while(x%i == 0) {
                    cnt++;
                    x /= i;
                }
                if(cnt > 0) {
                    map.put(i ,cnt);   
                }
                cnt = 0;
            }
            if(x > 2) map.put(x , 1);
        }
        public static long callfun(long  x,long c,HashMap<Long,Long> set , HashSet<Long> vis) {
            if(x == 1) return 1;
            long ans = x;
            long i = 1;
            while (pow(i ,c) <= pow(10l , 3l) * x) {
                long gc = gcd(pow(i,c), x);
                ans = Math.min(ans, pow(i,c)*x/(gc*gc));
                i += 1;
            }
                

            return ans;
            

            

            

            

            

            

            

            

            

            

            

        }
        public static long callfun(int cursum , int n , int k , int m ,int index ,Long memo[][]) {
            if(n == 0 ) {
                if(cursum > k)  return 0;
                return 1;
            }
            if(memo[index][cursum] != null)  return memo[index][cursum];
            long mod = (long)998244353;
            long ans = 0;
            for(int i =1;i<=m;i++) {
                long curans = callfun(cursum + i , n-1 ,k , m,index + 1,memo )%mod;
                ans = (ans + curans)%mod;
            }
            return memo[index][cursum] = ans;
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