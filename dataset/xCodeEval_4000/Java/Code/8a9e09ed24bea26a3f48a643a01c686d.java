

import static java.lang.Math.log;

import java.io.*;
import java.util.*;
import java.util.Map.Entry;




public class Main {
    

    static final int mod = 1000000007;
    static final long temp = 998244353;
    static final long MOD = 1000000007;
    static final long M = (long)1e9+7;

    static final int MAXN = 100001;

    

    static int spf[] = new int[MAXN];

    public static void main(String[] args) {

        FastReader in = new FastReader(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        int test= in.nextInt();

        for(int tt=1;tt<=test;tt++){
            int n = in.nextInt();

            ArrayList<Integer> l =new ArrayList<>();

            for(int i = 0;i<n;i++){
                int v = in.nextInt();

                l.add(v%10);
            }

            Collections.sort(l);


            int zero = 0,one = 0,two = 0,three = 0,four = 0,five = 0,six = 0,seven = 0,eight = 0 ,nine = 0;
            for(int i = 0;i<n;i++){
                if(l.get(i)==0){
                    zero++;
                }
                else if(l.get(i)==1){
                    one++;
                }
                else if(l.get(i)==2){
                    two++;
                }
                else if(l.get(i)==3){
                    three++;
                }
                else if(l.get(i)==4){
                    four++;
                }
                else if(l.get(i)==5){
                    five++;
                }
                else if(l.get(i)==6){
                    six++;
                }
                else if(l.get(i)==7){
                    seven++;
                }
                else if(l.get(i)==8){
                    eight++;
                }
                else{
                    nine++;
                }
            }

            if(one>=3){
                pw.println("YES");
            }
            else if(one>=1 && three>=1 && nine>=1){
                pw.println("YES");
            }
            else if(one>=1 && four>=1 && eight>=1){
                pw.println("YES");
            }
            else if(one>=1 && five>=1 && seven>=1){
                pw.println("YES");
            }
            else if(one>=1 && six>=2){
                pw.println("YES");
            }
            else if(one>=1 && two>=1 && zero>=1){
                pw.println("YES");
            }
            else if(two>=2 && nine>=1){
                pw.println("YES");
            }
            else if(two>=1 && three>=1 && eight>=1){
                pw.println("YES");
            }
            else if(two>=1 && four>=1 && seven>=1){
                pw.println("YES");
            }
            else if(two>=1 && five>=1 && six>=1){
                pw.println("YES");
            }
            else if(three>=1 && zero>=2){
                pw.println("YES");
            }
            else if(three>=2 && seven>=1){
                pw.println("YES");
            }
            else if(three>=1 && four>=1 && six>=1){
                pw.println("YES");
            }
            else if(three>=1 && five>=2){
                pw.println("YES");
            }
            else if(three>=1 && zero>=2){
                pw.println("YES");
            }
            else if(four>=1 && nine>=1 && zero>=1){
                pw.println("YES");
            }
            else if(four>=2 && five>=1){
                pw.println("YES");
            }
            else if(five>=2 && three>=1){
                pw.println("YES");
            }
            else if(five>=1 && eight>=1 && zero>=1){
                pw.println("YES");
            }
            else if(five>=1 && nine>=2){
                pw.println("YES");
            }
            else if(six>=2 && one>=1){
                pw.println("YES");
            }
            else if(six>=1 && seven>=1 &&  zero>=1){
                pw.println("YES");
            }
            else if(six>=1 && eight>=1 && nine>=1){
                pw.println("YES");
            }
            else if(seven>=2 && nine>=1){
                pw.println("YES");
            }
            else if(seven>=1 && eight>=2){
                pw.println("YES");
            }
            else {
                pw.println("NO");
            }







        }
        pw.close();
    }


    static void sieve()
    {
        spf[1] = 1;
        for (int i=2; i<MAXN; i++)
            spf[i] = i;
        for (int i=4; i<MAXN; i+=2)
            spf[i] = 2;
        for (int i=3; i*i<MAXN; i++)
        {

            if (spf[i] == i)
            {

                for (int j=i*i; j<MAXN; j+=i)
                    if (spf[j]==j)
                        spf[j] = i;
            }
        }
    }

    static Vector<Integer> getFactorization(int x)
    {
        Vector<Integer> ret = new Vector<>();
        while (x != 1)
        {
            ret.add(spf[x]);
            x = x / spf[x];
        }
        return ret;
    }

    static  boolean isSquare(int n){
        int v = (int)Math.sqrt(n);

        return v*v==n;
    }
    static int findIntSqrt(int value) {
        int l = 1,r = value,res= value;

        while(l<=r) {
            int mid = l + (r-l)/2;

            if(mid *mid <= value) {
                res = mid;
                l =mid +1;
            }
            else {
                r = mid -1;
            }
        }
        return res;
    }
    static double findsqrt(double value) {
        double l = 1,r=value,res=value;
        int trial = 70;
        while(l<=r && trial-->0) {
            double mid = l + (r-l)/2;

            if(mid * mid <= value) {
                res = mid;
                l=mid;
            }
            else {
                r= mid;
            }
        }

        return res;
    }
    static int findLower(int a[] ,int x) { 

        int left  = 0,right = a.length-1, pos = -1;;

        while(left<=right) {
            int mid  = left+ (right-left)/2;

            if(a[mid]<x) {
                pos  = mid;
                left = mid+1;
            }
            else {
                right  = mid  -1;
            }

        }
        return pos;
    }

    static int findUpper(int a[] ,int x) { 

        int left  = 0,right = a.length-1, pos = -1;;

        while(left<=right) {
            int mid  = left+ (right-left)/2;

            if(a[mid]>x) {
                pos  = mid;
                right  = mid -1;;
            }
            else {
                left = mid +1;;
            }

        }
        if(pos != -1) {
            return a[pos];
        }
        return pos;
    }

    static int binary_Search(int a[] ,int x)
    {
        int left = 0,right = a.length-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(a[mid] >x){
                right = mid -1;
            }
            else if(a[mid] <x){
                left = mid + 1;
            }
            else {
                return mid;
            }

        }
        return-1;
    }
    public static int findFirst(int[] A, int x)
    {
        int left = 0,right = A.length - 1, pos = -1;

        while (left <= right)
        {
            int mid =left + (right - left)/2;


            if (x == A[mid]) {
                pos = mid;
                right = mid - 1;
            }

            else if (A[mid]>x) {
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }
        return pos;
    }
    public static int gcd(int a, int b)
    {
        if(b == 0)
            return a;

        else
            return gcd(b,a%b);
    }

    public static long lcm(long a, long b)
    {
        return (a / LongGCD(a, b)) * b;
    }

    public static long LongGCD(long a, long b)
    {
        if(b == 0)
            return a;

        else
            return LongGCD(b,a%b);
    }

    public static long LongLCM(long a, long b)
    {
        return (a / LongGCD(a, b)) * b;
    }

    static void upper_bound(int a[], int element,int size) {

        int low = 0,high = size-1;

        while(high-low>1) {
            int mid = (low+high)/2;

            if(a[mid]<=element) {
                low =  mid+1;
            }
            else {
                high = mid;
            }
        }

        if(a[low]>element) {
            System.out.println(a[low]);
            return ;
        }
        if(a[high]>element) {
            System.out.println(a[high]);
        }
        else {
            System.out.println(-1);
        }

    }

    static void lower_bound(int a[], int element,int size) {

        int low = 0,high = size-1;

        while(high-low>1) {
            int mid = (low+high)/2;

            if(a[mid]<element) {
                low =  mid+1;
            }
            else {
                high = mid;
            }
        }

        if(a[low]>=element) {
            System.out.println(a[low]);
        }
        if(a[high]>=element) {
            System.out.println(a[high]);
        }
        else {
            System.out.println(-1);
        }

    }
    public static int LowerBound(long a[], long x)
    {
        int l=-1,r=a.length;
        while(l+1<r)
        {
            int m=(l+r)>>>1;
            if(a[m]>=x) r=m;
            else l=m;
        }
        return r;
    }

    public static int UpperBound(long a[], long x)
    {
        int l=-1, r=a.length;
        while(l+1<r)
        {
            int m=(l+r)>>>1;
            if(a[m]<=x) l=m;
            else r=m;
        }
        return l+1;
    }
    static int binarySearchCount(int arr[],int n, int key){

        int left = 0;

        int right = n - 1;
        int count = 0;


        while (left <= right){

            int mid = (right + left) / 2;


            if (arr[mid] <= key){

                count = mid + 1;
                left = mid + 1;
            }


            else
                right = mid - 1;
        }
        return count;
    }
    public static long phi(long n)  

    {
        long ans = n;



























        for(long i = 2;i<=n;i++)
        {
            if(isPrime(i))
            {
                ans -= (ans/i);
            }
        }

        return ans;

    }
    public static long nCrModP(long n, long r,long p)
    {
        if (n<r)
            return 0;

        if (r == 0)
            return 1;

        long[] fac = new long[(int)(n) + 1];
        fac[0] = 1;

        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % p;

        return (fac[(int)(n)] * modInverse(fac[(int)(r)], p)
                % p * modInverse(fac[(int)(n - r)], p)
                % p)
                % p;
    }

    public static long fact(long n)
    {
        long[] fac = new long[(int)(n) + 1];
        fac[0] = 1;

        for (long i = 1; i <= n; i++)
            fac[(int)(i)] = fac[(int)(i - 1)] * i;

        return fac[(int)(n)];
    }

    public static long nCr(long n, long k)
    {
        long ans = 1;
        for(long i = 0;i<k;i++)
        {
            ans *= (n-i);
            ans /= (i+1);
        }
        return ans;
    }

    

    public static long perfomMod(long x)
    {
        return ((x%M + M)%M);
    }
    public static long addMod(long a, long b)
    {
        return perfomMod(perfomMod(a)+perfomMod(b));
    }

    public static long subMod(long a, long b)
    {
        return perfomMod(perfomMod(a)-perfomMod(b));
    }

    public static long mulMod(long  a, long b)
    {
        return perfomMod(perfomMod(a)*perfomMod(b));
    }

    public static boolean isPrime(long n)
    {
        if(n == 1)
        {
            return false;
        }
        for(int i = 2;i*i<=n;i++)
        {
            if(n%i == 0)
            {
                return false;
            }
        }
        return true;
    }

    public static long fastPow(long x, long n)
    {
        if(n == 0)
            return 1;
        else if(n%2 == 0)
            return fastPow(x*x,n/2);
        else
            return x*fastPow(x*x,(n-1)/2);
    }

    public static long modPow(long x, long y, long p)
    {
        long res = 1;
        x = x % p;

        while (y > 0) {
            if (y % 2 == 1)
                res = (res * x) % p;

            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    static long modInverse(long n, long p)
    {
        return modPow(n, p - 2, p);
    }

    static boolean sqrt(long n) {
        long div = (long)Math.sqrt(n);

        if(div*div==n) {
            return true;
        }
        else {
            return false;
        }
    }


    static int countDivisors(int num) {
        int divisors = 0;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                divisors++;
                if (num / i != i) {
                    divisors++;
                }
            }
        }
        return divisors;
    }
    public static List<Long> SieveList(int n)
    {
        boolean prime[] = new boolean[(int)(n+1)];
        Arrays.fill(prime, true);

        List<Long> l = new ArrayList<>();
        for (long p=2; p*p<=n; p++)
        {
            if (prime[(int)(p)] == true)
            {
                for(long i=p*p; i<=n; i += p)
                {
                    prime[(int)(p)] = false;
                }
            }
        }

        for (long p=2; p<=n; p++)
        {
            if (prime[(int)(p)] == true)
            {
                l.add(p);
            }
        }

        return l;
    }
    static long trailingZeros(long N) {
        long zeros = 0;
        for (long i = 5; N / i > 0; i *= 5) {
            zeros += N / i;
        }
        return zeros;
    }
    static boolean isPrime(int num) {
        if (num < 2) {
            return false;
        }
        if (num == 2) {
            return true;
        }
        if (num % 2 == 0) {
            return false;
        }
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }

    public static void Sort(long[] a)
    {
        List<Long> l = new ArrayList<>();
        for (long i : a) l.add(i);
        Collections.sort(l);


        for (int i=0; i<a.length; i++) a[i]=l.get(i);
    }

    public static void ssort(char[] a)
    {
        List<Character> l = new ArrayList<>();
        for (char i : a) l.add(i);
        Collections.sort(l);
        for (int i=0; i<a.length; i++) a[i]=l.get(i);
    }

    public static long log2(long n)
    {
        long ans = (long)(log(n)/log(2));
        return ans;
    }

    public static boolean isPow2(long n)
    {
        return (n  != 0 && ((n & (n-1))) == 0);
    }

    private static boolean isSorted(int[] arr) {
        for (int i = 1; i < arr.length; i++)
            if (arr[i] < arr[i - 1])
                return false;
        return true;
    }


    static class FastReader {
        InputStream is;
        private byte[] inbuf = new byte[1024];
        private int lenbuf = 0, ptrbuf = 0;

        public FastReader(InputStream is) {
            this.is = is;
        }

        public int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        public boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        private boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        public int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b)) ;
            return b;
        }

        public String next() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(isSpaceChar(b))) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }


        public String nextLine() {
            int c = skip();
            StringBuilder sb = new StringBuilder();
            while (!isEndOfLine(c)) {
                sb.appendCodePoint(c);
                c = readByte();
            }
            return sb.toString();
        }

        public int nextInt() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            while (true) {
                if (b >= '0' && b <= '9') {
                    num = (num << 3) + (num << 1) + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

        public long nextLong() {
            long num = 0;
            int b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = (num << 3) + (num << 1) + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public char[] next(int n) {
            char[] buf = new char[n];
            int b = skip(), p = 0;
            while (p < n && !(isSpaceChar(b))) {
                buf[p++] = (char) b;
                b = readByte();
            }
            return n == p ? buf : Arrays.copyOf(buf, p);
        }

        public char readChar() {
            return (char) skip();
        }
    }
    static class Pair implements Comparable<Pair>
    {
        int first, second;

        public Pair(int first, int second)
        {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair ob)
        {
            return (int)(first - ob.first);
        }
    }


    static class Tuple implements Comparable<Tuple>
    {
        int first, second,third;
        public Tuple(int first, int second, int third)
        {
            this.first = first;
            this.second = second;
            this.third = third;
        }
        public int compareTo(Tuple o)
        {
            return (int)(o.third - this.third);
        }
    }

    public static class DSU
    {
        int[] parent;
        int[] rank; 

        public DSU(int n)
        {
            parent = new int[n];
            rank = new int[n];
            Arrays.fill(parent, -1);
            Arrays.fill(rank, 1);
        }

        public int find(int i) 

        {
            return parent[i] < 0 ? i : (parent[i] = find(parent[i]));
        }

        public boolean union(int a, int b) 

        {
            a = find(a);
            b = find(b);

            if(a == b) return false; 


            

            if(rank[a] < rank[b])
            {
                

                parent[a] = b;
            }
            

            else if(rank[a] > rank[b])
            {
                

                parent[b] = a;
            }
            

            else
            {
                

                parent[b] = a;
                rank[a] = 1 + rank[a];
            }
            return true;
        }
    }

}
