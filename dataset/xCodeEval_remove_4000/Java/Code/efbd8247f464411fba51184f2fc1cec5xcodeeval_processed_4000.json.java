

import static java.lang.Math.*;
import static java.lang.System.*;

import java.util.*;
import java.io.*;
import java.math.*;

public class Main
{

    static FastReader sc;
    static long mod=((long)1e9)+7;
    

    static FastWriter out;
    public static void main(String hi[]) throws IOException {


        out=new FastWriter();
        sc=new FastReader();
        long id21=System.currentTimeMillis();
        long id28=Long.MAX_VALUE;
        int t=sc.nextInt();






        while(t--!=0) {
            int n=sc.nextInt();
            int[] arr=id0(n);
            sort(arr);
            print(arr[n-1]+arr[n-2]);
        }
        id28=System.currentTimeMillis();
        debug("[finished : "+(id28-id21)+".ms ]");
        

    }

    private static String solve(int[] arr, int n,int k) {
        Map<Integer,Integer> map=freq(arr);
        for(int i=0;i<n;i++){
            map.put(arr[i],map.get(arr[i])-1);
            if(map.getOrDefault(k+arr[i],0)>0)return "yes";
            map.put(arr[i],map.get(arr[i])+1);

        }
        return "no";
    }

    private static int[] solve(List<Integer> close, String s, int n) {
        int[] res=new int[2];
        int ind=0,i=0;
        while (i<n){
            if(s.charAt(i)=='('&&i+1<n) {
                if(s.charAt(i+1)==')')ind++;
                i+=2;
                res[0]++;
            }else if(s.charAt(i)==')'){

                ind++;
               while (ind<close.size()&&!id14(s,i,close.get(ind))){
                   ind++;
               }
               if(ind>=close.size()){
                   res[1]=n-i;
                   return res;
               }else{
                   res[0]++;
                   i=close.get(ind)+1;
                   ind++;
               }
            }else{
                res[1]=n-i;
                return res;
            }
        }
        return res;
    }

    static long min=(long) (1e9);
    static Set<Long> set;
    static Map<Long,Long> map;
    private static void dfs(long n,long m,long c){
        if(n<=0||set.contains(n))return ;
        if (n >= m) {
            min=min(min,c+(n-m));
            return;
        }
        if(map.containsKey(n))return;
        map.put(n,c);
        dfs(n*2,m,c+1);
        dfs(n-1,m,c+1);

    }
    public static boolean isNumeric(String strNum) {
        if (strNum == null) {
            return false;
        }
        try {
            double d = Double.parseDouble(strNum);
        } catch (NumberFormatException nfe) {
            return false;
        }
        return true;
    }
    private static boolean isSorted(List<Integer> li){
        int n=li.size();
        if(n<=1)return true;
        for(int i=0;i<n-1;i++){
            if(li.get(i)>li.get(i+1))return false;
        }
        return true;
    }
    static boolean id10(long x)
    {
        return x != 0 && ((x & (x - 1)) == 0);
    }
    private static boolean id7(List<Integer> res){
        int l=0,r=res.size()-1;
        while(l<r){
            if(res.get(l)!=res.get(r))return false;
            l++;
            r--;
        }
        return true;
    }
    private static class Pair{
        int first=0;
        int sec=0;
        int[] arr;
        Map<Integer,Integer> map;
        Pair(int first,int sec){
            this.first=first;
            this.sec=sec;
        }
        Pair(int[] arr){
            this.map=new HashMap<>();
            for(int x:arr) this.map.put(x,map.getOrDefault(x,0)+1);
            this.arr=arr;
        }
    }
    private static int id13(int st,int e){
        int s=e-st+1;
        return (s*(s+1))/2;
    }
    private static Set<Long> factors(long n){
        Set<Long> res=new HashSet<>();
        

        for (long i=1; i*i<=(n); i++){
            if (n%i==0){
                res.add(i);
                if (n/i != i){
                    res.add(n/i);
                }
            }
        }

        return res;
    }
    private static long fact(long n){
        if(n<=2)return n;
        return n*fact(n-1);
    }
    private static long ncr(long n,long r){
        return fact(n)/(fact(r)*fact(n-r));
    }
    private static int lessThen(long[] nums,long val,boolean work,int l,int r){
        int i=-1;
        if(work)i=0;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(nums[mid]<=val){
                i=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return i;
    }
    private static int lessThen(List<Long> nums,long val,boolean work,int l,int r){
        int i=-1;
        if(work)i=0;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(nums.get(mid)<=val){
                i=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return i;
    }
    private static int lessThen(List<Integer> nums,int val,boolean work,int l,int r){
        int i=-1;
        if(work)i=0;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(nums.get(mid)<=val){
                i=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return i;
    }
    private static int greaterThen(List<Long> nums,long val,boolean work,int l,int r){
        int i=-1;
        if(work)i=r;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(nums.get(mid)>=val){
                i=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return i;
    }
    private static int greaterThen(List<Integer> nums,int val,boolean work){
        int i=-1,l=0,r=nums.size()-1;
        if(work)i=r;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(nums.get(mid)>=val){
                i=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return i;
    }
    private static int greaterThen(long[] nums,long val,boolean work,int l,int r){
        int i=-1;
        if(work)i=r;
        while(l<=r){
            int mid=l+((r-l)/2);
            if(nums[mid]>=val){
                i=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return i;
    }

    private static long gcd(long[] arr){
        long ans=0;
        for(long x:arr){
            ans=gcd(x,ans);
        }
        return ans;
    }
    private static int gcd(int[] arr){
        int ans=0;
        for(int x:arr){
            ans=gcd(x,ans);
        }
        return ans;
    }
    private static long id5(long a,long n,long d){
        long val=(n*( 2*a+((n-1)*d)));
        return val/2;
    }
    

    private static double id2(double x1,double y1,double x2,double y2,double x3,double y3){
        double[] mid_point=id3(x1,y1,x2,y2);
        

        double height=id20(mid_point[0],mid_point[1],x3,y3);
        double wight=id20(x1,y1,x2,y2);
        

        return (height*wight)/2;
    }
    private static double id20(double x1,double y1,double x2,double y2){
        double x=x2-x1;
        double y=y2-y1;
        return (Math.pow(x,2)+Math.pow(y,2));
    }
    public static boolean id11(long n) {
        if (n <= 0) {
            return false;
        }
        double squareRoot = Math.sqrt(n);
        long tst = (long)(squareRoot + 0.5);
        return tst*tst == n;
    }
    private static double[] id3(double x1,double y1,double x2,double y2){
        double[] mid=new double[2];
        mid[0]=(x1+x2)/2;
        mid[1]=(y1+y2)/2;
        return mid;
    }
    private static long id16(long n){
        return (n*(n+1))/2;
    }
    private static long power(long x,long y,long p){
        long res = 1; 


        x = x % p; 

        


        if (x == 0)
            return 0; 


        while (y > 0){

            

            if ((y & 1) != 0)
                res = (res * x) % p;

            

            y = y >> 1; 

            x = (x * x) % p;
        }
        return res;
    }

    
    static long power(long x, long y){
        long temp;
        if( y == 0)
            return 1l;
        temp = power(x, y / 2);
        if (y % 2 == 0)
            return (temp*temp);
        else
            return (x*temp*temp);
    }

    private static StringBuilder reverseString(String s){
        StringBuilder sb=new StringBuilder(s);
        int l=0,r=sb.length()-1;
        while(l<=r){
            char ch=sb.charAt(l);
            sb.setCharAt(l,sb.charAt(r));
            sb.setCharAt(r,ch);
            l++;
            r--;
        }
        return sb;
    }

    private static void swap(List<Integer> li,int i,int j){
        int t=li.get(i);
        li.set(i,li.get(j));
        li.set(j,t);
    }

    static int lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }
    static long lcm(long a, long b){
        return (a / gcd(a, b)) * b;
    }
    private static String id22(int x){
        return Integer.toBinaryString(x);
    }
    private static String id22(long x){
        return Long.toBinaryString(x);
    }
    private static  boolean id14(String s,int l,int r){
        while(l<r){
            if(s.charAt(l)!=s.charAt(r))return false;
            l++;
            r--;
        }
        return true;
    }
    private static boolean id9(String s, String t) {
        if (s == null || t == null) return false;

        Map<Character, List<Integer>> map = new HashMap<>(); 


        

        for (int i = 0; i < t.length(); i++) {
            char curr = t.charAt(i);
            if (!map.containsKey(curr)) {
                map.put(curr, new ArrayList<Integer>());
            }
            map.get(curr).add(i);
        }

        int prev = -1;  

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (map.get(c) == null)  {
                return false;
            } else {
                List<Integer> list = map.get(c);
                prev = lessThen( list, prev,false,0,list.size()-1);
                if (prev == -1) {
                    return false;
                }
                prev++;
            }
        }

        return true;
    }




    private static StringBuilder id19(StringBuilder sb){
        int i=0;
        while(i<sb.length()&&sb.charAt(i)=='0')i++;
        

        if(i==sb.length())return new StringBuilder();
        return new StringBuilder(sb.substring(i,sb.length()));
    }
    private static StringBuilder id1(StringBuilder sb){
        int i=sb.length()-1;
        while(i>=0&&sb.charAt(i)=='0')i--;
        

        if(i<0)return new StringBuilder();
        return new StringBuilder(sb.substring(0,i+1));
    }
    private static int id6(String binaryString){
        

        return Integer.parseInt(binaryString,2);
    }

    private static int id25(String s){
        return Integer.parseInt(s);
    }
    private static String toString(int val){
        return String.valueOf(val);
    }
    private static void debug(int[][] arr){
        for(int i=0;i<arr.length;i++){
            err.println(Arrays.toString(arr[i]));
        }
    }

    private static void debug(long[][] arr){
        for(int i=0;i<arr.length;i++){
            err.println(Arrays.toString(arr[i]));
        }
    }


    private static void debug(List<int[]> arr){
        for(int[] a:arr){
            err.println(Arrays.toString(a));
        }
    }

    private static void debug(float[][] arr){
        for(int i=0;i<arr.length;i++){
            err.println(Arrays.toString(arr[i]));
        }
    }

    private static void debug(double[][] arr){
        for(int i=0;i<arr.length;i++){
            err.println(Arrays.toString(arr[i]));
        }
    }

    private static void debug(boolean[][] arr){
        for(int i=0;i<arr.length;i++){
            err.println(Arrays.toString(arr[i]));
        }
    }

    private static void print(String s)throws IOException {
        out.println(s);
    }
    private static void debug(String s)throws IOException {
        err.println(s);
    }

    private static int id27(char c){
        return ((((int)(c-'0'))%48));
    }

    private static void print(double s)throws IOException {
        out.println(s);
    }
    private static void print(float s)throws IOException {
        out.println(s);
    }
    private static void print(long s)throws IOException {
        out.println(s);
    }
    private static void print(int s)throws IOException {
        out.println(s);
    }
    private static void debug(double s)throws IOException {
        err.println(s);
    }
    private static void debug(float s)throws IOException {
        err.println(s);
    }
    private static void debug(long s){
        err.println(s);
    }
    private static void debug(int s){
        err.println(s);
    }
    private static boolean isPrime(int n){

        

        

        if (n <= 1)
            return false;

            

        else if (n == 2)
            return true;

            

        else if (n % 2 == 0)
            return false;

        

        for (int i = 3; i <= Math.sqrt(n); i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    private static List<List<Integer>> id26(int n){
        List<List<Integer>> graph=new ArrayList<>();
        for(int i=0;i<=n;i++){
            graph.add(new ArrayList<>());
        }
        for(int i=0;i<n;i++){
            int x=sc.nextInt();
            int y=sc.nextInt();
            graph.get(x).add(y);
            graph.get(y).add(x);
        }
        return graph;
    }
    private static List<List<Integer>> id26(int[][] intervals,int n){
        List<List<Integer>> graph=new ArrayList<>();
        for(int i=0;i<=n;i++){
            graph.add(new ArrayList<>());
        }
        for(int i=0;i<intervals.length;i++){
            int x=intervals[i][0];
            int y=intervals[i][1];
            graph.get(x).add(y);
            graph.get(y).add(x);
        }
        return graph;
    }
    private static List<List<Integer>> id24(int[][] intervals,int n){
        List<List<Integer>> graph=new ArrayList<>();
        for(int i=0;i<=n;i++){
            graph.add(new ArrayList<>());
        }
        for(int i=0;i<intervals.length;i++){
            int x=intervals[i][0];
            int y=intervals[i][1];
            graph.get(x).add(y);
            

        }
        return graph;
    }
    private static List<List<Integer>> id24(int n){
        List<List<Integer>> graph=new ArrayList<>();
        for(int i=0;i<=n;i++){
            graph.add(new ArrayList<>());
        }
        for(int i=0;i<n;i++){
            int x=sc.nextInt();
            int y=sc.nextInt();
            graph.get(x).add(y);
            

        }
        return graph;
    }
    static String[] id29(int n){
        String[] arr=new String[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.next();
        }
        return arr;
    }
    private static Map<Character,Integer> freq(String s){
        Map<Character,Integer> map=new HashMap<>();
        for(char c:s.toCharArray()){
            map.put(c,map.getOrDefault(c,0)+1);
        }
        return map;
    }
    private static Map<Integer,Integer> freq(int[] arr){
        Map<Integer,Integer> map=new HashMap<>();
        for(int x:arr){
            map.put(x,map.getOrDefault(x,0)+1);
        }
        return map;
    }
    static boolean[] id23(long n){
        boolean prime[] = new boolean[(int)n + 1];
        for (int i = 2; i <= n; i++)
            prime[i] = true;

        for (int p = 2; p * p <= n; p++)
        {
            

            

            if (prime[p] == true){
                

                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        return prime;
    }
    static int[] id31(long n){
        boolean prime[] = new boolean[(int)n + 1];
        Set<Integer> li=new HashSet<>();
        for (int i = 1; i <= n; i++){
            prime[i] = true;
            li.add(i);
        }
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true){
                for (int i = p * p; i <= n; i += p){
                    li.remove(i);
                    prime[i] = false;
                }
            }
        }
        int[] arr=new int[li.size()];
        int i=0;
        for(int x:li){
            arr[i++]=x;
        }
        return arr;
    }
    public static long Kadens(List<Long> prices) {
        long sofar=0;
        long max_v=0;
        for(int i=0;i<prices.size();i++){
            sofar+=prices.get(i);
            if (sofar<0) {
                sofar=0;
            }
            max_v=Math.max(max_v,sofar);

        }
        return max_v;
    }
    public static int Kadens(int[] prices) {
        int sofar=0;
        int max_v=0;
        for(int i=0;i<prices.length;i++){
            sofar+=prices[i];
            if (sofar<0) {
                sofar=0;
            }
            max_v=Math.max(max_v,sofar);

        }
        return max_v;
    }
    static boolean id30(int a, int d, int x){

        

        

        if (d == 0)
            return (x == a);

        

        

        return ((x - a) % d == 0 && (x - a) / d >= 0);
    }
    static boolean id30(long a, long d, long x){

        

        

        if (d == 0)
            return (x == a);

        

        

        return ((x - a) % d == 0 && (x - a) / d >= 0);
    }
    private static void sort(int[] arr){
        int n=arr.length;
        List<Integer> li=new ArrayList<>();
        for(int x:arr){
            li.add(x);
        }
        Collections.sort(li);
        for (int i=0;i<n;i++) {
            arr[i]=li.get(i);
        }
    }
    private static void sortReverse(int[] arr){
        int n=arr.length;
        List<Integer> li=new ArrayList<>();
        for(int x:arr){
            li.add(x);
        }
        Collections.sort(li,Collections.reverseOrder());
        for (int i=0;i<n;i++) {
            arr[i]=li.get(i);
        }
    }
    private static void sort(double[] arr){
        int n=arr.length;
        List<Double> li=new ArrayList<>();
        for(double x:arr){
            li.add(x);
        }
        Collections.sort(li);
        for (int i=0;i<n;i++) {
            arr[i]=li.get(i);
        }
    }
    private static void sortReverse(double[] arr){
        int n=arr.length;
        List<Double> li=new ArrayList<>();
        for(double x:arr){
            li.add(x);
        }
        Collections.sort(li,Collections.reverseOrder());
        for (int i=0;i<n;i++) {
            arr[i]=li.get(i);
        }
    }
    private static void sortReverse(long[] arr){
        int n=arr.length;
        List<Long> li=new ArrayList<>();
        for(long x:arr){
            li.add(x);
        }
        Collections.sort(li,Collections.reverseOrder());

        for (int i=0;i<n;i++) {
            arr[i]=li.get(i);
        }
    }
    private static void sort(long[] arr){
        int n=arr.length;
        List<Long> li=new ArrayList<>();
        for(long x:arr){
            li.add(x);
        }
        Collections.sort(li);
        for (int i=0;i<n;i++) {
            arr[i]=li.get(i);
        }
    }
    private static long sum(int[] arr){
        long sum=0;
        for(int x:arr){
            sum+=x;
        }
        return sum;
    }
    private static long sum(long[] arr){
        long sum=0;
        for(long x:arr){
            sum+=x;
        }
        return sum;
    }

    private static long id18(long n){
        long l1=0,l2=2;
        long sum=0;
        while (l2<n) {
            long l3=(4*l2)+l1;
            sum+=l2;
            if(l3>n)break;
            l1=l2;
            l2=l3;
        }
        return sum;
    }
    private static void initializeIO(){
        try {
            System.setIn(new FileInputStream("input"));
            System.setOut(new PrintStream(new FileOutputStream("output.txt")));
            System.setErr(new PrintStream(new FileOutputStream("error.txt")));
        } catch (Exception e) {
             System.err.println(e.getMessage());
        }
    }
    private static int id8(int[] arr){
        int max=Integer.MIN_VALUE;
        for(int x:arr){
            max=Math.max(max,x);

        }
        return max;
    }
    private static long id8(long[] arr){
        long max=Long.MIN_VALUE;
        for(long x:arr){
            max=Math.max(max,x);

        }
        return max;
    }
    private static  int[][] id17(int n,int m){
        int[][] arr=new int[n][m];
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                arr[j][i]=sc.nextInt();
            }
        }
        return arr;
    }
    private static long gcd(long a,long b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    private static int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    private static int[] id0(int n){
        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        return arr;
    }
    private static double[] id4(int n){
        double[] arr=new double[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextDouble();
        }
        return arr;
    }
    private static long[] id12(int n){
        long[] arr=new long[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextLong();
        }
        return arr;
    }


    private static void print(int[] arr)throws IOException {
        out.println(Arrays.toString(arr));
    }
    private static void print(long[] arr)throws IOException {
        out.println(Arrays.toString(arr));
    }
    private static void print(String[] arr)throws IOException {
        out.println(Arrays.toString(arr));
    }
    private static void print(double[] arr)throws IOException {
        out.println(Arrays.toString(arr));
    }
    private static void debug(String[] arr){
        err.println(Arrays.toString(arr));
    }
    private static void debug(Boolean[][] arr){
        for(int i=0;i<arr.length;i++)err.println(Arrays.toString(arr[i]));
    }
    private static void debug(int[] arr){
        err.println(Arrays.toString(arr));
    }
    private static void debug(long[] arr){
        err.println(Arrays.toString(arr));
    }

    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null || !st.hasMoreTokens()){
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
        long nextLong(){
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str="";
            try {
                str=br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    static class FastWriter {
        BufferedWriter bw;
        List<String> list = new ArrayList<>();
        Set<String> set = new HashSet<>();

        FastWriter() {
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        <T> void print(T obj) throws IOException {
            bw.write(obj.toString());
            bw.flush();
        }

        void println() throws IOException {
            print("\n");
        }

        <T> void println(T obj) throws IOException {
            print(obj.toString() + "\n");
        }

        <T> void print(T[] arr) throws IOException {
            for (int i = 0; i < arr.length; i++) {
                print(arr[i] + " ");
            }
            println();
        }
        <T> void print(List<T> arr) throws IOException {
            for (int i = 0; i < arr.size(); i++) {
                print(arr.get(i) + " ");
            }
            println();
        }

        void id15(char c, int n) throws IOException {
            for (int i = 0; i < n; i++) {
                print(c);
            }
        }
    }

    static class Dsu {
        int[] parent, size;

        Dsu(int n) {
            parent = new int[n + 1];
            size = new int[n + 1];

            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        private int findParent(int u) {
            if (parent[u] == u) return u;
            return parent[u] = findParent(parent[u]);
        }

        private boolean union(int u, int v) {
            

            int pu = findParent(u);
            

            int pv = findParent(v);
            


            if (pu == pv) return false;
            if (size[pu] <= size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
            return true;
        }
    }


}