import java.io.*;
import java.util.*;

public class Solution {


    static PrintWriter out = new PrintWriter(System.out);
    static FastReader in = new FastReader();
    static long mod = (long) 1e9 + 7;
    static Pair[] moves = new Pair[]{new Pair(-1, 0), new Pair(1, 0), new Pair(0, -1), new Pair(0, 1)};
    private static PrintWriter pw;
   
      static final int IBIG = 1000000007;
   static final int IMAX = 2147483647;
     static final int IMIN = -2147483648;
    static final long LMAX = 9223372036854775807L;
     static final long LMIN = -9223372036854775808L;
    static boolean arr[] = sieve(1000001);
     static ArrayList<Long> primes = new ArrayList<>();
    static ArrayList<Long> sumList = new ArrayList<>();
     static ArrayList<Integer> divisors = new ArrayList<>();
    static ArrayList<Long> divisorsL = new ArrayList<>();
     static ArrayList<Integer> primedivisors = new ArrayList<>();
    static ArrayList<Integer> perfectSquares = new ArrayList<>();
     static int freq[] = new int[200005];
    static ArrayList<Integer> primefactorsofN = new ArrayList<>();;
    

    

    

    

    


    

    public static void main(String[] args) {

    

        int tc = in.nextInt();
        int t=1;

        out:
        while (t<= tc) {
          int n = in.nextInt();
          int k=0;
         if(n>=10){
              k=n/10;
          }else{
              k=0;
          }
         if(n%10==9)  k+=1;
          out.println(k);
      
         t++;
         out.flush();
      
    }
    }
    static long[]  dp;
     public static  long dfs(long[]  arr,int n ,int xor,int ind,int len,int count){
         int pow= (int)Math.pow(2,len-1);
         if(ind==n){
       

             if(count!=0&&xor%pow==0){
             
                 return 1;
             }
             return 0;
         }
     
         xor^= arr[ind];
         

         if(dp[ind]!=-1)  return dp[ind];
        long ans=0;
         if(xor%pow==0){
             ans+=dfs(arr,n,xor,ind+1,len,count+1);
             ans=ans%mod;
             ans+=dfs(arr,n,0,ind+1,len+1,0);
              ans=ans%mod;
        }else{
                ans+=dfs(arr,n,xor,ind+1,len,count+1);
                 ans=ans%mod;
         }
         ans=ans%mod;
       return dp[ind]=ans;
         
     }
  
   
     static int nextPowerOf2(int n)
    {
        n--;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        n++;
         
        return n;
    }
    public static boolean isPS(int x) {
        if (x == 1) {
            return true;
        }
        for (int i = 2; i <= x / 2; i++) {
            if (i * i == x) {
                return true;
            }
        }
        return false;
    }

    public static long calc(int type, long X, long K) {
        if (type == 1) {
            return (X + 99999) / 100000 + K;
        } else {
            return (K * X + 99999) / 100000;
        }
    }

    static int sd(long i) {
        int d = 0;
        while (i > 0) {
            d += i % 10;
            i = i / 10;
        }
        return d;
    }


    static int lower(long A[], long x) {
        int l = -1, r = A.length;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (A[m] >= x) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }

    static int upper(long A[], long x) {
        int l = -1, r = A.length;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (A[m] <= x) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }

    static void swap(int A[], int a, int b) {
        int t = A[a];
        A[a] = A[b];
        A[b] = t;
    }

    static int lowerBound(int A[], int low, int high, int x) {
        if (low > high) {
            if (x >= A[high]) {
                return A[high];
            }
        }

        int mid = (low + high) / 2;

        if (A[mid] == x) {
            return A[mid];
        }

        if (mid > 0 && A[mid - 1] <= x && x < A[mid]) {
            return A[mid - 1];
        }

        if (x < A[mid]) {
            return lowerBound(A, low, mid - 1, x);
        }

        return lowerBound(A, mid + 1, high, x);
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

    static int i() {
        return in.nextInt();
    }

    static long l() {
        return in.nextLong();
    }

    static String s() {
        return in.nextLine();
    }

    static int[] input(int N) {
        int A[] = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = in.nextInt();
        }
        return A;
    }

    static long[] inputLong(int N) {
        long A[] = new long[N];
        for (int i = 0; i < A.length; i++) {
            A[i] = in.nextLong();
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
     
 private static int countDigits(int l) {
        if (l >= 1000000000)
            return 10;
        if (l >= 100000000)
            return 9;
        if (l >= 10000000)
            return 8;
        if (l >= 1000000)
            return 7;
        if (l >= 100000)
            return 6;
        if (l >= 10000)
            return 5;
        if (l >= 1000)
            return 4;
        if (l >= 100)
            return 3;
        if (l >= 10)
            return 2;
        return 1;
    }

    private static int countDigits(long l) {
        if (l >= 1000000000000000000L)
            return 19;
        if (l >= 100000000000000000L)
            return 18;
        if (l >= 10000000000000000L)
            return 17;
        if (l >= 1000000000000000L)
            return 16;
        if (l >= 100000000000000L)
            return 15;
        if (l >= 10000000000000L)
            return 14;
        if (l >= 1000000000000L)
            return 13;
        if (l >= 100000000000L)
            return 12;
        if (l >= 10000000000L)
            return 11;
        if (l >= 1000000000L)
            return 10;
        if (l >= 100000000L)
            return 9;
        if (l >= 10000000L)
            return 8;
        if (l >= 1000000L)
            return 7;
        if (l >= 100000L)
            return 6;
        if (l >= 10000L)
            return 5;
        if (l >= 1000L)
            return 4;
        if (l >= 100L)
            return 3;
        if (l >= 10L)
            return 2;
        return 1;
    }
      private static boolean exist(int[] a, int x) {
        for (int e : a) {
            if (e == x)
                return true;
        }
        return false;
    }
 private static int digitsum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            sum += digit;
        }
        return sum;
    }

    private static long digitsum(long n) {
        long sum = 0;
        while (n > 0) {
            long digit = n % 10;
            n /= 10;
            sum += digit;
        }
        return sum;
    }

    private static long factorial(int n) {
        if (n == 0)
            return 1;
        else
            return (long) ((n * factorial(n - 1)) % mod);
    }
   private static int countPalindromicSubsequence(String str) {
        int N = str.length();

        

        

        int[][] cps = new int[N][N];

        

        for (int i = 0; i < N; i++)
            cps[i][i] = 1;

        

        

        for (int L = 2; L <= N; L++) {
            for (int i = 0; i <= N - L; i++) {
                int k = L + i - 1;
                if (str.charAt(i) == str.charAt(k)) {
                    cps[i][k] = cps[i][k - 1] + cps[i + 1][k] + 1;
                } else {
                    cps[i][k] = cps[i][k - 1] + cps[i + 1][k] - cps[i + 1][k - 1];
                }
            }
        }
        

        return cps[0][N - 1];
    }

    private static int LCSubStr(char X[], char Y[], int m, int n) {
        

        

        

        

        

        

        

        

        

        

        

        int LCStuff[][] = new int[m + 1][n + 1];

        

        

        int result = 0;

        

        

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    LCStuff[i][j] = 0;
                else if (X[i - 1] == Y[j - 1]) {
                    LCStuff[i][j] = LCStuff[i - 1][j - 1] + 1;
                    result = Integer.max(result, LCStuff[i][j]);
                } else
                    LCStuff[i][j] = 0;
            }
        }
        return result;
    }

    private static List<String> subStrings(String s) {
        ArrayList<String> al = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                al.add(s.substring(i, j));
            }
        }
        return al;
    }

    private static boolean isSubSequence(String str1, String str2, int m, int n) {
        

        if (m == 0)
            return true;
        if (n == 0)
            return false;

        

        if (str1.charAt(m - 1) == str2.charAt(n - 1))
            return isSubSequence(str1, str2, m - 1, n - 1);

        

        return isSubSequence(str1, str2, m, n - 1);
    }

    private static boolean number_Is_Divisible_By_Its_Digits(long n) {
        long temp = n;
        while (temp > 0) {
            long digit = temp % 10;
            temp /= 10;
            if (digit != 0 && n % digit != 0)
                return false;
        }
        return true;
    }

    private static int countDivisors(int n) {
        int cnt = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0)
                cnt++;
            divisors.add(i);
        }
        return cnt;
    }

    private static ArrayList<Integer> divisorsList(int n) {
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (!divisors.contains(i))
                    divisors.add(i);
                if (!divisors.contains(n / i))
                    divisors.add(n / i);
            }
        }
        return divisors;
    }

    private static ArrayList<Long> divisorsList(long n) {
        for (long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisorsL.add(i);
                divisorsL.add(n / i);
            }
        }
        return divisorsL;
    }

    private static ArrayList<Integer> primeFactorList(int n) {
        for (int i = 2; i <= n; i++) {
            if ((n % i) == 0 && primedivisors.contains(i) == false)
                primedivisors.add(i);
        }
        return primedivisors;
    }

    private static boolean isStringSorted(String s) {
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) > s.charAt(i + 1))
                return false;
        }
        return true;
    }

    private static boolean isPalindromeString(String s) {
        String temp = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            temp += s.charAt(i) + "";
        }
        return ((s.equals(temp)) ? true : false);
    }

    private static boolean isPalindrome(int[] a) {
        for (int i = 0; i < a.length / 2; i++) {
            if (a[i] != a[a.length - 1 - i])
                return false;
        }
        return true;
    }

    private static boolean isSorted(int[] a) {
        int n = a.length;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i])
                return false;
        }
        return true;
    }

    private static boolean isSortedStrictly(int[] a) {
        int n = a.length;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] >= a[i])
                return false;
        }
        return true;
    }

    private static boolean isSorted(long[] a) {
        int n = a.length;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i])
                return false;
        }
        return true;
    }

    private static boolean isSortedStrictly(long[] a) {
        int n = a.length;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] >= a[i])
                return false;
        }
        return true;
    }

    private static boolean solution(int n, int x) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            sum += digit;
        }
        return (sum == x) ? true : false;
    }

    private static ArrayList<Integer> perfectSquares(int n) {
        ArrayList<Integer> al = new ArrayList<Integer>();
        for (int i = 1; i <= n; i++) {
            al.add(i * i);
        }
        return al;
    }

    private static boolean checkDuplicateAll(String s) {
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) != s.charAt(i - 1))
                return false;
        }
        return true;
    }

    private static String reverseString(String s, int x) {
        String ans = "", temp = s.substring(0, x);
        for (int i = x; i < s.length(); i++) {
            ans = s.charAt(i) + ans;
        }
        return temp + ans;
    }

    private static boolean number_Is_Not_Divisible_By_Its_Digits(int num) {
        String s = num + "";
        if (s.contains("0"))
            return false;
        int temp = num;
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            if (temp % digit == 0)
                return false;
        }
        return true;
    }

    private static boolean palindrome(int n) {
        int temp = n, rev = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            rev = rev * 10 + digit;
        }
        return (temp == rev) ? true : false;
    }

    private static boolean checkparanthesis(String s)

    {
        Stack<Character> st = new Stack<>();
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(')
                st.push('(');
            else {
                if (st.size() == 0)
                    return false;
                else
                    st.pop();
            }
        }
        return (st.size() == 0) ? true : false;
    }

    private static boolean[] sieve(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
        return isPrime;
    }

    private static int pow(int base, int exp) {
        int result = 1;
        while (exp != 0) {
            if ((exp & 1) == 1)
                result *= base;
            exp >>= 1;
            base *= base;
        }
        return result;
    }

    private static long pow(long n, long m) {
        long mod = 1000000007;
        if (m == 0)
            return 1;
        if (m == 1)
            return n;
        if (m % 2 == 0) {
            long ans = pow(n, m / 2);
            return (ans * ans) % mod;
        } else {
            long ans = pow(n, ((m - 1) / 2));
            return ((n * ans) % mod * ans) % mod;
        }
    }
private static int lcm(int a, int b) {
        return a * b / gcf(a, b);
    }

    private static long lcm(long a, long b) {
        return a * b / gcf(a, b);
    }
    private static int gcf(int a, int b) {
        return b == 0 ? a : gcf(b, a % b);
    }

    private static long gcf(long a, long b) {
        return b == 0 ? a : gcf(b, a % b);
    }
  private static long minof(long a, long b, long c) {
        return Math.min(a, Math.min(b, c));
    }

    private static long minof(long... x) {
        if (x.length == 1)
            return x[0];
        if (x.length == 2)
            return Math.min(x[0], x[1]);
        if (x.length == 3)
            return Math.min(x[0], Math.min(x[1], x[2]));
        long min = x[0];
        for (int i = 1; i < x.length; ++i)
            if (x[i] < min)
                min = x[i];
        return min;
    }

    private static int maxof(int a, int b, int c) {
        return Math.max(a, Math.max(b, c));
    }

    private static int maxof(int... x) {
        if (x.length == 1)
            return x[0];
        if (x.length == 2)
            return Math.max(x[0], x[1]);
        if (x.length == 3)
            return Math.max(x[0], Math.max(x[1], x[2]));
        int max = x[0];
        for (int i = 1; i < x.length; ++i)
            if (x[i] > max)
                max = x[i];
        return max;
    }

    private static long maxof(long a, long b, long c) {
        return Math.max(a, Math.max(b, c));
    }

    private static long maxof(long... x) {
        if (x.length == 1)
            return x[0];
        if (x.length == 2)
            return Math.max(x[0], x[1]);
        if (x.length == 3)
            return Math.max(x[0], Math.max(x[1], x[2]));
        long max = x[0];
        for (int i = 1; i < x.length; ++i)
            if (x[i] > max)
                max = x[i];
        return max;
    }



 public static int binarySearch(int arr[], int l, int r, int x)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;
 
            

            

            if (arr[mid] == x)
                return mid;
 
            

            

            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
 
            

            

            return binarySearch(arr, mid + 1, r, x);
        }
 
        

        

        return -1;
    }

    private static int nextallonebinary(int prev) {
   ;
        int len=Integer.toBinaryString(prev).length()+1;
        String num="";
        for(int i=0;i<len;i++){
            num=num +1;
        }
      

        return Integer.parseInt(num,2);
        
    }

}

class SegmentTree {

    long[] t;

    public SegmentTree(int n) {
        t = new long[n + n];
        Arrays.fill(t, Long.MIN_VALUE);
    }

    public long get(int i) {
        return t[i + t.length / 2];
    }

    public void add(int i, long value) {
        i += t.length / 2;
        t[i] = value;
        for (; i > 1; i >>= 1) {
            t[i >> 1] = Math.max(t[i], t[i ^ 1]);
        }
    }

    

 
}

class Pair {

    int i, j;

    Pair(int i, int j) {
        this.i = i;
        this.j = j;
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