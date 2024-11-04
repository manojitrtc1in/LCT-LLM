import java.io.BufferedReader;
    import java.io.IOException;
    import java.io.InputStreamReader;
    import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.*;
public class Main{
    static class FastScanner {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer("");

            String next() {
                while (!st.hasMoreTokens())
                    try {
                        st = new StringTokenizer(br.readLine());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                return st.nextToken();
            }

            int nextInt() {
                return Integer.parseInt(next());
            }

            int[] nextArray(int n) {
                int[] a = new int[n];
                for (int i = 0; i < n; i++) a[i] = nextInt();
                return a;
            }
            long[] nextArray(long n) {
                long[] a = new long[(int) n];
                for (int i = 0; i < n; i++) a[i] = nextLong();
                return a;
            }

            long nextLong() {
                return Long.parseLong(next());
            }
        }
    static class FastWriter extends PrintWriter {
            FastWriter(){
                super(System.out);
            }
            void println(int[] array) {
                for(int i=0; i<array.length; i++) {
                    print(array[i]+" ");
                }
                println();
            }
            void println(long [] array) {
                for(int i=0; i<array.length; i++) {
                    print(array[i]+" ");
                }
                println();
            }
        }
    static int MOD=1000003;
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        FastWriter out = new FastWriter();
        int t=in.nextInt();
        

        while (t-->0){
            int n=in.nextInt();
            int m=in.nextInt();
            int k=in.nextInt();
            int max=(n*m)/2;
            if(n%2!=0){
                if(k<m/2){
                    out.println("NO");
                }else {
                    k-=m/2;
                    if(k%2!=0){
                        out.println("NO");
                    }else {
                        out.println("YES");
                        boolean flag=true;
                        char[][] ar=new char[n][m];
                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < m; j++) {
                                ar[i][j]='z';
                            }
                        }
                        for(int i=0;i<m;i+=2){
                            if(flag){
                                ar[0][i]='h';
                                ar[0][i+1]='h';
                            }else {
                                ar[0][i]='j';
                                ar[0][i+1]='j';
                            }
                            flag=!flag;
                        }
                        flag=true;
                        outer:for (int i = 1; i < n; i+=2) {
                            flag=true;
                            for (int j = 0; j < m; j+=2) {
                                if(k==0){
                                    break outer;
                                }
                                if(flag){
                                    ar[i][j]='a';ar[i][j+1]='a';
                                    ar[i+1][j]='b';ar[i+1][j+1]='b';
                                    k-=2;
                                    flag=false;
                                }else {
                                    ar[i][j]='b';ar[i][j+1]='b';
                                    ar[i+1][j]='a';ar[i+1][j+1]='a';
                                    k-=2;
                                    flag=true;
                                }
                                if(k==0){
                                    break outer;
                                }
                            }
                        }
                        flag=false;
                        outer:for (int i = 1; i < n; i+=2) {
                            flag=!flag;
                            for (int j = 0; j < m; j+=2) {
                                if(ar[i][j]=='z'){
                                    if(flag){
                                        ar[i][j]='c';ar[i+1][j]='c';
                                        ar[i][j+1]='d';ar[i+1][j+1]='d';
                                    }else {
                                        ar[i][j]='d';ar[i+1][j]='d';
                                        ar[i][j+1]='c';ar[i+1][j+1]='c';
                                    }
                                }
                            }
                        }
                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < m; j++) {
                                out.print(ar[i][j]);
                            }
                            out.println();
                        }
                    }
                }
            }else if(m%2!=0){
                int hh=max-n/2;
                if(k>hh){
                    out.println("NO");
                }else {
                    if(k%2!=0){
                        out.println("NO");
                    }else {
                        out.println("YES");
                        boolean flag=true;
                        char[][] ar=new char[n][m];
                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < m; j++) {
                                ar[i][j]='z';
                            }
                        }
                        for(int i=0;i<n;i+=2){
                            if(flag){
                                ar[i][0]='h';
                                ar[i+1][0]='h';
                            }else {
                                ar[i][0]='j';
                                ar[i+1][0]='j';
                            }
                            flag=!flag;
                        }
                        flag=true;
                        outer:for (int i = 0; i < n; i+=2) {
                            flag=true;
                            for (int j = 1; j < m; j+=2) {
                                if(k==0){
                                    break outer;
                                }
                                if(flag){
                                    ar[i][j]='a';ar[i][j+1]='a';
                                    ar[i+1][j]='b';ar[i+1][j+1]='b';
                                    k-=2;
                                    flag=false;
                                }else {
                                    ar[i][j]='b';ar[i][j+1]='b';
                                    ar[i+1][j]='a';ar[i+1][j+1]='a';
                                    k-=2;
                                    flag=true;
                                }
                                if(k==0){
                                    break outer;
                                }
                            }
                        }
                        flag=false;
                        outer:for (int i = 0; i < n; i+=2) {
                            flag=!flag;
                            for (int j = 1; j < m; j+=2) {
                                if(ar[i][j]=='z'){
                                    if(flag){
                                        ar[i][j]='c';ar[i+1][j]='c';
                                        ar[i][j+1]='d';ar[i+1][j+1]='d';
                                    }else {
                                        ar[i][j]='d';ar[i+1][j]='d';
                                        ar[i][j+1]='c';ar[i+1][j+1]='c';
                                    }
                                }
                            }
                        }
                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < m; j++) {
                                out.print(ar[i][j]);
                            }
                            out.println();
                        }
                    }
                }
            }else {
                if(k%2!=0){
                    out.println("NO");
                }else {
                    out.println("YES");
                    boolean flag=true;
                    char[][] ar=new char[n][m];
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            ar[i][j]='z';
                        }
                    }
                    outer:for (int i = 0; i < n; i+=2) {
                        flag=true;
                        for (int j = 0; j < m; j+=2) {
                            if(k==0){
                                break outer;
                            }
                            if(flag){
                                ar[i][j]='a';ar[i][j+1]='a';
                                ar[i+1][j]='b';ar[i+1][j+1]='b';
                                k-=2;
                            }else {
                                ar[i][j]='r';ar[i][j+1]='r';
                                ar[i+1][j]='s';ar[i+1][j+1]='s';
                                k-=2;
                            }
                            flag=!flag;
                            if(k==0){
                                break outer;
                            }
                        }
                    }
                    flag=false;
                    outer:for (int i = 0; i < n; i+=2) {
                        flag=!flag;
                        for (int j = 0; j < m; j+=2) {
                            if(ar[i][j]=='z'){
                                if(flag){
                                    ar[i][j]='c';ar[i+1][j]='c';
                                    ar[i][j+1]='d';ar[i+1][j+1]='d';
                                }else {
                                    ar[i][j]='e';ar[i+1][j]='e';
                                    ar[i][j+1]='f';ar[i+1][j+1]='f';
                                }
                            }
                        }
                    }
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            out.print(ar[i][j]);
                        }
                        out.println();
                    }
                }
            }
        }
        out.close();
    }
    

    static int totalPrimeFactors(int n) {
        int cnt=0;
        while (n%2==0) {
            cnt++;
            n /= 2;
        }
        int num= (int) Math.sqrt(n);
        for (int i = 3; i <= num; i+= 2) {
            while (n%i == 0) {
                cnt++;
                n /= i;
                num=(int)Math.sqrt(n);
            }
        }
        if (n > 2){
            cnt++;
        }
        return cnt;
    }
    static char get(int i){
        return (char)(i+'a');
    }
    static boolean distinct(int num){
        HashSet<Integer> set=new HashSet<>();
        int len=String.valueOf(num).length();
        while (num!=0){
            set.add(num%10);
            num/=10;
        }
        return set.size()==len;
    }
    static int maxSubArraySum(int a[],int st,int en) {
        int max_s = Integer.MIN_VALUE, max_e = 0,ind=0,ind1=1;
        for (int i = st; i <= en; i++) {
            max_e+= a[i];
            if (max_s < max_e){
                max_s = max_e;
                ind=ind1;
            }
            if (max_e < 0){
                max_e = 0;
                ind1=i+1;
            }
        }
        if(st==0){
            return max_s;
        }
        if(ind==1){
            return a[0]+2*max_s;
        }else {
            return 2*max_s+maxSubArraySum(a,0,ind-1);
        }
        

    }
    static void segmentedSieve(ArrayList<Integer> res,int low, int high) {
        if(low < 2){
            low = 2;
        }
        ArrayList<Integer> prime = new ArrayList<>();
        sS2(high, prime);
        boolean[] mark = new boolean[high - low + 1];
        Arrays.fill(mark, true);
        for (int i = 0; i < prime.size(); i++) {
            int loLim = (low / prime.get(i)) * prime.get(i);
            if (loLim < low){
                loLim += prime.get(i);
            }
            if (loLim == prime.get(i)){
                loLim += prime.get(i);
            }
            for (int j = loLim; j <= high; j += prime.get(i)) {
                mark[j - low] = false;
            }
        }
        for (int i = low; i <= high; i++) {
            if (mark[i - low]){
                System.out.println(i);
                res.add(i);
            }
        }
    }
    static void sS2(int limit, ArrayList<Integer> prime) {
        int bound = (int)Math.sqrt(limit);
        boolean[] mark = new boolean[bound + 1];
        for (int i = 0; i <= bound; i++){
            mark[i] = true;
        }
        for (int i = 2; i * i <= bound; i++) {
            if (mark[i]) {
                for (int j = i * i; j <= bound; j += i){
                    mark[j] = false;
                }
            }
        }
        for (int i = 2; i <= bound; i++) {
            if (mark[i]){
                prime.add(i);
            }
        }
    }
    static boolean[] sieveOfEratosthenes(int n){
        boolean[] prime = new boolean[n + 1];
        Arrays.fill(prime,true);
        prime[0]=false;prime[1]=false;
        for (int p = 2; p * p <= n; p++) {
            if(prime[p]){
                for (int i = p * p; i <= n; i += p){
                    prime[i] = false;
                }
            }
        }
        return prime;
    }
    static int highestPowerOf2(int n) {
        if (n < 1){ return 0; }
        int res = 1;
        for (int i = 0; i < 8 * Integer.BYTES; i++) {
            int curr = 1 << i;
            if (curr > n){ break; }
            res = curr;
        }
        return res;
    }
    static int reduceFraction(int x, int y) {
        int d= gcd(x, y);
        return x/d+y/d;
    }
    static boolean subset(int[] ar,int n,int sum){
        if(sum==0){
            return true;
        }
        if(n<0||sum<0){
            return false;
        }
        return subset(ar,n-1,sum)||subset(ar,n-1,sum-ar[n]);
    }
    static boolean isPrime(int n){
        if(n<=1) return false;
        for(int i = 2;i<=Math.sqrt(n);i++){
            if (n % i == 0) return false;
        }
        return true;
    }
    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    static long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }
    static int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
    static boolean isPowerOfTwo(long n) {
        if(n==0){
            return false;
        }
        while (n%2==0){
            n/=2;
        }
        return n==1;
    }
    static boolean isPerfectSquare(int x){
        if (x >= 0) {
            int sr = (int)Math.sqrt(x);
            return ((sr * sr) == x);
        }
        return false;
    }
    static int lower_bound(int[] arr, int x) {
        int low_limit = 0, high_limit = arr.length, mid;
        while (low_limit < high_limit) {
            mid = (low_limit + high_limit) / 2;
            if (arr[mid] >= x){
                high_limit = mid;
            }else{
                low_limit = mid + 1;
            }
        }
        return low_limit;
    }
    static int upper_bound(int[] arr, int x) {
        int low_limit = 0, high_limit = arr.length, mid;
        while (low_limit < high_limit) {
            mid = (low_limit + high_limit) / 2;
            if (arr[mid] > x){
                high_limit = mid;
            }else{
                low_limit = mid + 1;
            }
        }
        return low_limit;
    }
    static int binarySearch(int[] ar,int n,int num){
        int low=0,high=n-1;
        while (low<=high){
            int mid=(low+high)/2;
            if(ar[mid]==num){
                return mid;
            }else if(ar[mid]>num){
                high=mid-1;
            }else {
                low=mid+1;
            }
        }
        return -1;
    }
    static int fib(int n) {
        long[][] F = new long[][]{{1,1},{1,0}};
        if (n == 0){
            return 0;
        }
        power(F, n-1);
        return (int)F[0][0];
    }
    static void multiply(long F[][], long M[][]) {
        long x =  (F[0][0]*M[0][0])%1000000007 + (F[0][1]*M[1][0])%1000000007;
        long y =  (F[0][0]*M[0][1])%1000000007 + (F[0][1]*M[1][1])%1000000007;
        long z =  (F[1][0]*M[0][0])%1000000007 + (F[1][1]*M[1][0])%1000000007;
        long w =  (F[1][0]*M[0][1])%1000000007 + (F[1][1]*M[1][1])%1000000007;
        F[0][0] = x%1000000007;
        F[0][1] = y%1000000007;
        F[1][0] = z%1000000007;
        F[1][1] = w%1000000007;
    }
    static void power(long F[][], int n) {
        if( n == 0 || n == 1){
            return;
        }
        long M[][] = new long[][]{{1,1},{1,0}};
        power(F, n/2);
        multiply(F, F);
        if (n%2 != 0){
            multiply(F, M);
        }
    }
    static int binaryExponentiation(int x,int n){
        int ans=1;
        while (n>0){
            if(n%2!=0){
                ans=(ans*x)%MOD;
            }
            x=(x*x)%MOD;
            n/=2;
        }
        return ans;
    }
    static void bfs(ArrayList<Integer>[] ar,int node){
        boolean[] visited=new boolean[ar.length];
        Queue<Integer> queue=new LinkedList<>();
        visited[node]=true;
        queue.add(node);
        while(!queue.isEmpty()){
            int nn=queue.poll();
            System.out.print(nn+" ");
            for(int n : ar[nn]) {
                if (!visited[n]) {
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }
        System.out.println();
    }
    static void dfs(ArrayList<Integer>[] ar,int node){
        boolean[] visited=new boolean[ar.length];
        dfsUtil(ar,node,visited);
        System.out.println();
    }
    static void dfsUtil(ArrayList<Integer>[] ar,int node,boolean[] visited){
        visited[node]=true;
        

        for(Integer n:ar[node]){
            if(!visited[n]){
                dfsUtil(ar,n,visited);
            }
        }
    }
}