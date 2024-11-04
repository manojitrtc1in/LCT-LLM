import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.Math.sqrt;
import static java.lang.Math.pow;
import static java.lang.System.out;
import static java.lang.System.err;
import java.util.*;
import java.io.*;
import java.math.*;

public class Main
{

    static FastReader sc;
    static long mod=((long)1e9)+7;
    

    public static void main(String hi[]){
        initializeIO();
        sc=new FastReader();
        

        

        

        int t=1;
        while(t--!=0){
            int n=sc.nextInt();
            int m1=sc.nextInt();
            int m2=sc.nextInt();
            debug(n+" "+m1+" "+m2);
            Dsu first=new Dsu(n);
            Dsu sec=new Dsu(n);
            int[][] f=new int[m1][2];
            int[][] s=new int[m2][2];
            
            for(int i=0;i<m1;i++){
                int u=sc.nextInt();
                int v=sc.nextInt();
                f[i]=new int[]{u,v};
                first.union(u,v);
            }
            for(int i=0;i<m2;i++){
                int u=sc.nextInt();
                int v=sc.nextInt();
                s[i]=new int[]{u,v};
                sec.union(u,v);
            }
            List<int[]> res=new ArrayList<>();
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if((first.findParent(i)==first.findParent(j))||(sec.findParent(i)==sec.findParent(j)))continue;
                    first.union(i,j);
                    sec.union(i,j);
                    

                    res.add(new int[]{i,j});                    
                }
            }
            print(res.size());
            for(int i=0;i<res.size();i++){
                out.println(res.get(i)[0]+" "+res.get(i)[1]);
            }
        }
        

    }
    private static int lessThen(long[] nums,long val){
        int i=0,l=0,r=nums.length-1;
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
    private static int greaterThen(long[] nums,long val){
        int i=nums.length-1,l=0,r=nums.length-1;
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
    private static long id4(long a,long n,long d){
       long val=(n*( 2*a+((n-1)*d)));
        return val/2;
    }
    

    private static double id1(double x1,double y1,double x2,double y2,double x3,double y3){
        double[] mid_point=id2(x1,y1,x2,y2);
        

        double height=id13(mid_point[0],mid_point[1],x3,y3);
        double wight=id13(x1,y1,x2,y2);
        

        return (height*wight)/2;
    }
    private static double id13(double x1,double y1,double x2,double y2){
        double x=x2-x1;
        double y=y2-y1;
        return sqrt(Math.pow(x,2)+Math.pow(y,2));
    }
    private static double[] id2(double x1,double y1,double x2,double y2){
        double[] mid=new double[2];
        mid[0]=(x1+x2)/2;
        mid[1]=(y1+y2)/2;
        return mid;
    }
    private static long id9(long n){
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
    static int lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }
    static long lcm(long a, long b){
        return (a / gcd(a, b)) * b;
    }
    private static String id14(int x){
        return Integer.toBinaryString(x);
    }
    private static  boolean id8(String s){
        int l=0,r=s.length()-1;
        while(l<r){
            if(s.charAt(l)!=s.charAt(r))return false;
            l++;
            r--;
        }
        return true;
    }
    private static StringBuilder id12(StringBuilder sb){
        int i=0;
        while(i<sb.length()&&sb.charAt(i)=='0')i++;
        

        if(i==sb.length())return new StringBuilder();
        return new StringBuilder(sb.substring(i,sb.length()));
    }
    private static int id5(String binaryString){
        

        return Integer.parseInt(binaryString,2);
    }

    private static int id18(String s){
        return Integer.parseInt(s);
    }
    private static String toString(int val){
        return String.valueOf(val);
    }

    private static void print(String s){
        out.println(s);
    }
    private static void debug(String s){
        err.println(s);
    }
    private static int id17(char c){
        return ((((int)(c-'0'))%48));
    }
    private static void print(double s){
        out.println(s);
    }
    private static void print(float s){
        out.println(s);
    }
    private static void print(long s){
        out.println(s);
    }
    private static void print(int s){
        out.println(s);
    }
    private static void debug(double s){
        err.println(s);
    }
    private static void debug(float s){
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
    

    private static List<List<Integer>> id19(int n){
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
    private static List<List<Integer>> id19(int[][] intervals,int n){
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
    private static List<List<Integer>> id16(int[][] intervals,int n){
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
    private static List<List<Integer>> id16(int n){
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
    static String[] id20(int n){
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
    static boolean[] id15(long n){
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
    static int[] id22(long n){
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
        int[] arr=new int[li.size()+1];
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
    static boolean id21(int a, int d, int x){

        

        

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

    private static long id11(long n){
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
            System.setIn(new FileInputStream("input.txt"));
            System.setOut(new PrintStream(new FileOutputStream("output.txt")));
            System.setErr(new PrintStream(new FileOutputStream("error.txt")));
        } catch (Exception e) {
            

        }
    }
    private static int id6(int[] arr){
        int max=Integer.MIN_VALUE;
        for(int x:arr){
            max=Math.max(max,x);

        }
        return max;
    }
    private static long id6(long[] arr){
        long max=Long.MIN_VALUE;
        for(long x:arr){
            max=Math.max(max,x);

        }
        return max;
    }
    private static  int[][] id10(int n,int m){
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
    private static double[] id3(int n){
        double[] arr=new double[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextDouble();
        }
        return arr;
    }
    private static long[] id7(int n){
        long[] arr=new long[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextLong();
        }
        return arr;
    }


    private static void print(int[] arr){
        out.println(Arrays.toString(arr));
    }
    private static void print(long[] arr){
        out.println(Arrays.toString(arr));
    }
    private static void print(String[] arr){
        out.println(Arrays.toString(arr));
    }
    private static void print(double[] arr){
        out.println(Arrays.toString(arr));
    }
    private static void debug(String[] arr){
        err.println(Arrays.toString(arr));
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
        private final BufferedWriter bw;

        public FastWriter() {
            this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        public void print(Object object) throws IOException {
            bw.append("" + object);
        }

        public void println(Object object) throws IOException {
            print(object);
            bw.append("\n");
        }

        public void close() throws IOException {
            bw.close();
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