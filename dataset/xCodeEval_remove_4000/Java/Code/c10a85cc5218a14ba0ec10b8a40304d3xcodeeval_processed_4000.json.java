
import java.util.*;
import java.io.*;

public class Main {

    static int mod = 1000000007;

    static void read(int arr[], int start, int end, FastReader in) {
        for (int i = start; i < end; i++) {
            arr[i] = in.nextInt();
        }
    }

    static int sumArr(int arr[]) {
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        return sum;
    }
    static final int MAX = 10000000;

    static int prefix[] = new int[MAX + 1];

    static void buildPrefix() {

        

        

        

        boolean prime[] = new boolean[MAX + 1];
        Arrays.fill(prime, true);

        for (int p = 2; p * p <= MAX; p++) {

            

            

            if (prime[p] == true) {

                

                for (int i = p * 2; i <= MAX; i += p) {
                    prime[i] = false;
                }
            }
        }

        

        prefix[0] = prefix[1] = 0;
        for (int p = 2; p <= MAX; p++) {
            prefix[p] = prefix[p - 1];
            if (prime[p]) {
                prefix[p]++;
            }
        }
    }

    static int query(int L, int R) {
        return prefix[R] - prefix[L - 1];
    }

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static Long gcd(Long a, Long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static int min(int arr[]) {
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length; i++) {
            min = Math.min(min, arr[i]);
        }
        return min;
    }

    public static void sort(int[] arr) {
        ArrayList<Integer> ls = new ArrayList<>();
        for (int x : arr) {
            ls.add(x);
        }
        Collections.sort(ls);
        for (int i = 0; i < arr.length; i++) {
            arr[i] = ls.get(i);
        }
    }
    public static void sortrev(int[] arr) {
        ArrayList<Integer> ls = new ArrayList<>();
        for (int x : arr) {
            ls.add(x);
        }
        Collections.sort(ls,Collections.reverseOrder());
        for (int i = 0; i < arr.length; i++) {
            arr[i] = ls.get(i);
        }
    }
    public static void sort(long[] arr) {
        ArrayList<Long> ls = new ArrayList<>();
        for (long x : arr) {
            ls.add(x);
        }
        Collections.sort(ls);
        for (int i = 0; i < arr.length; i++) {
            arr[i] = ls.get(i);
        }
    }

    static int max(int arr[]) {
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            max = Math.max(max, arr[i]);
        }
        return max;
    }
    static long max(long arr[]) {
        long max = Long.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            max = Math.max(max, arr[i]);
        }
        return max;
    }

    static int max(int a, int b) {
        return Math.max(a, b);
    }
    static long max(long a, long b){
        return (a>b)?a:b;
    }

    static int min(int a, int b) {
        return Math.min(a, b);
    }
    static long min(long a, long b){
        return Math.min(a, b);
    }

    public static boolean isPrime(long n) {
        if (n < 2) {
            return false;
        }
        if (n == 2 || n == 3) {
            return true;
        }
        if (n % 2 == 0 || n % 3 == 0) {
            return false;
        }
        long sqrtN = (long) Math.sqrt(n) + 1;
        for (long i = 6L; i <= sqrtN; i += 6) {
            if (n % (i - 1) == 0 || n % (i + 1) == 0) {
                return false;
            }
        }
        return true;
    }

    static class Pair {

        int first;
        int second;

        Pair(int f, int s) {
            first = f;
            second = s;
        }

        @Override
        public String toString() {
            return "first: " + first + " second: " + second;
        }
    }

    static class FastReader {

        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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
                str = br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }

        void read(int arr[]) {
            for (int i = 0; i < arr.length; i++) {
                arr[i] = nextInt();
            }
        }

        void read(long arr[]) {
            for (int i = 0; i < arr.length; i++) {
                arr[i] = nextLong();
            }
        }
        
        void read(char arr[][]){
            for(int i=0;i<arr.length;i++){
                String s=next();
                for(int j=0;j<s.length();j++)
                    arr[i][j]=s.charAt(j);
            }
        }
        
        void read(Pair arr[]) {
            for (int i = 0; i < arr.length; i++) {
                int x = nextInt();
                int y = nextInt();
                arr[i] = new Pair(x, y);
            }
        }
    }

    static class FastWriter {

        private final BufferedWriter bw;

        public FastWriter() {
            this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        public void println(Object object) throws IOException {
            print(object);
            bw.append("\n");
        }

        public void printarr(int arr[]) throws IOException {

            println(Arrays.toString(arr));
        }

        public void print(Object object) throws IOException {
            bw.append("" + object);
        }

        public void close() throws IOException {
            bw.close();
        }
    }

    public static int count(String s, char c) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == c) {
                count++;
            }
        }
        return count;
    }

    public static int stoi(String s) {
        return Integer.parseInt(s);
    }

    public static String itos(int n) {
        return Integer.toString(n);
    }

    public static int ctoi(char c) {
        return (int) c - 48;
    }

    public static long id5(long n) {
        long count = 0;
        while (n != 0) {
            count += (n & 1);    

            n >>= 1;
        }

        return count;
    }
    static long MOD = (long) (1e9 + 7);

    static long powerLL(long x, long n) {
        long result = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                result = result * x % MOD;
            }
            n = n / 2;
            x = x * x % MOD;
        }
        return result;
    }

    static long countBits(long number) {
        return (long) (Math.log(number)
                / Math.log(2) + 1);
    }

    static boolean id2(long n) {
        if (n == 0) {
            return false;
        }

        while (n != 1) {
            if (n % 2 != 0) {
                return false;
            }
            n = n / 2;
        }
        return true;
    }

    public static int LCS(String s1, String s2){
        int l1=s1.length();
        int l2=s2.length();
        int dp[][]=new int[l1+1][l2+1];
        for(int i=0;i<=l1;i++){
            for(int j=0;j<=l2;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else{
                    if(s1.charAt(i-1)==s2.charAt(j-1))
                        dp[i][j]=1+dp[i-1][j-1];
                    else
                        dp[i][j]=Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }




        return dp[l1][l2];
    }
    public static String id4(String s1, String s2){
        int l1=s1.length();
        int l2=s2.length();
        int dp[][]=new int[l1+1][l2+1];
        for(int i=0;i<=l1;i++){
            for(int j=0;j<=l2;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else{
                    if(s1.charAt(i-1)==s2.charAt(j-1))
                        dp[i][j]=1+dp[i-1][j-1];
                    else
                        dp[i][j]=Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        String ans="";
        int i=l1,j=l2;
        while(i>0 && j>0){
            if(s1.charAt(i-1)==s2.charAt(j-1)){
                ans=s1.charAt(i-1)+ans;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else
                j--;
        }
        
        return ans;
    }
    public static int factorial(int n)
    {
        return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
    }
    public static int nCr(int n, int r,int a) {
        return factorial(n) / (factorial(r) * factorial(n - r));
    }
    
    public static boolean[] sieve()
    {
        int n=10000000;
        

        

        

        

        

        

        

        boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;
 
        for (int p = 2; p * p <= n; p++)
        {
            

            

            if (prime[p] == true)
            {
                

                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        return prime;
    }
    static int id0(int a[])
    {
        int size = a.length;
        int id3 = Integer.MIN_VALUE, id1 = 0;
 
        for (int i = 0; i < size; i++)
        {
            id1 = id1 + a[i];
            if (id3 < id1)
                id3 = id1;
            if (id1 < 0)
                id1 = 0;
        }
        return id3;
    }
    public static int calc(int arr[],int n){
        if(n<0 || n<arr[0])
            return 0;
        if(n>=arr[2])
            return max(max(1+calc(arr,n-arr[2]),1+calc(arr,n-arr[1])),1+calc(arr,n-arr[0]));
        else if(n>=arr[1])
            return max(1+calc(arr,n-arr[1]),1+calc(arr,n-arr[0]));
        else if(n>=arr[0])
            return 1+calc(arr,n-arr[0]);
        else
            return 0;
    }
    static int dp[];
    public static int calc(int n, int org){
        if(n==org)
            return 0;
        else if(n>org)
            return 99999;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=Math.min(1+calc(n+1,org) , 1+calc(2*n,org));
    }
    public static int minOperation(int n)
    {
        dp=new int[n+1];
        for(int i=0;i<=n;i++)
            dp[i]=-1;
        int ans=calc(1,n);
        return ans+1;
    }
    static int nCr(int n, int r)
    {
        int mod=1000000007;
        if(r>n)
            return 0;
        int dp[][]=new int[n+1][n+1];
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || j==i)
                    dp[i][j]=1;
                else
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
            }
        }
        return dp[n][r];
    }
    public static int calc(String s1, String s2){
        int arr1[]=new int[26];
        int arr2[]=new int[26];
        for(char c:s1.toCharArray())
            arr1[c-'a']++;
        for(char c:s2.toCharArray())
            arr2[c-'a']++;
        int sum=0;
        for(int i=0;i<26;i++)
            sum+=((arr2[i]-arr1[i])>0)?(arr2[i]-arr1[i]):0;
        return sum;
    }
    public static boolean isSorted(int arr[]){
        int sor[]=new int[arr.length];
        for(int i=0;i<arr.length;i++)
            sor[i]=arr[i];
        sort(sor);
        boolean check=true;
        for(int i=0;i<arr.length;i++){
            if(sor[i]!=arr[i]){
                check=false;
                break;
            }
        }
        return check;
    }
    public static int find(int arr[], int n){
        for(int i=0;i<arr.length;i++)
            if(arr[i]==n)
                return i;
        return -1;
    }
    public static long calc(long n,long m, long mid,long k){
        long ans=0;
        for(int i=1;i<=n;i++)
            ans+=Math.min(mid/i,m);
        return ans;
    }
    public static boolean check(int arr[],int k){
        int count=0;
        for(int i=0;i<arr.length;i++)
            if(arr[i]%(i+1) == 0)
                count++;
        return count==k;
    }
    static int lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }
    static int limit=1000000;
    public static boolean same(String s){
        boolean check=true;
        for(int i=1;i<s.length();i++){
            if(s.charAt(i)!=s.charAt(i-1)){
                check=false;
                break;
            }
        }
        return check;
    }
    static int limit1=1000000000;
    public static void printCount(int arr[],FastWriter out){
        try{
        for(int p:arr)
            out.print(p+" ");
        out.println("");
        }
        catch ( Exception E){
            
        }
    }
    public static class item{
        int len;
        int cost;
        item(int l, int c){
            len=l;
            cost=c;
        }
        @Override
        public String toString() {
            return "len: " + len + " cost: " + cost;
        }
    }
    public static class comparator implements Comparator<item>{
        public int compare(item i, item j){
            if(i.len*i.cost != j.len*j.cost)
                return (-(i.len*i.cost - j.len*j.cost));
            else
                return (-(i.len-j.len));
            
        }
    }
    public static void cpy(int arr1[],int arr2[]){
        for(int i=0;i<arr1.length;i++)
            arr2[i]=arr1[i];
    }
    static int UpperBound(ArrayList<Integer> a, int x) {

    int l=-1,r=a.size();
    while(l+1<r) {
       int m=(l+r)>>>1;
       if(a.get(m)<=x) l=m;
       else r=m;
    }
    return l+1;
 }
static int LowerBound(ArrayList<Integer> a, int x) { 

  int l=-1,r=a.size();
  while(l+1<r) {
    int m=(l+r)>>>1;
    if(a.get(m)>=x) r=m;
    else l=m;
  }
  return r;
}
    public static void solve(FastReader in,FastWriter out){
        try{
            

            
            
            int n=in.nextInt();
            HashSet<Integer> hs=new HashSet<>();
            int count[]=new int[n+1];
            ArrayList<Integer> st=new ArrayList<>();
            for(int i=0;i<n;i++){
                int x=in.nextInt();
                hs.add(x);
                ++count[x];
            }
            for(int i=0;i<=n;i++)
                if(count[i]>1){
                    int temp=count[i];
                    while(temp>1){
                        st.add(i);
                        temp--;
                    }
                }
            long dp[]=new long[n+1];
            dp[0]=count[0];


            for(int i=1;i<=n;i++){


                if(dp[i-1]==-1){
                    dp[i]=-1;
                    continue;
                }
                dp[i]=dp[i-1]-count[i-1]+count[i];
                if(hs.contains(i-1)) continue;
                int index=LowerBound(st,i-1)-1;




                if(index==-1){
                    dp[i]=-1;
                    continue;
                }
                dp[i]+=(i-1)-st.get(index);




                st.remove(index);
            }
            for(int i=0;i<=n;i++)
                out.print(dp[i]+" ");
            out.println("");




            
                    
            
            
            
            
            
            
            
            

        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        try {
            FastReader in = new FastReader();
            FastWriter out = new FastWriter();
            int tc=1;
            tc=in.nextInt();
            while(tc-- != 0){
                solve(in,out);
                


























                


            }
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}