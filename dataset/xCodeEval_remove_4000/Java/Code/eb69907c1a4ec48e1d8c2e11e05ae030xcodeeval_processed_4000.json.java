import java.io.*;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;
import java.math.*;



public class Solution{
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }
    

    static class Task{

        double eps= 0.00000001;
        static final int MAXN = 10015;
        static final int MOD= 998244353;

        

        static int spf[] = new int[MAXN];

        static boolean[] prime;

        Map<Integer,Set<Integer>> dp= new HashMap<>();

        

        

        

        public void sieve()
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

        void id7(int n)
        {
            

            

            

            

            

            

            

            prime= new boolean[n + 1];
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
        }

        

        

        public Set<Integer> id12(int x)
        {
            if(dp.containsKey(x)) return dp.get(x);
            Set<Integer> ret = new HashSet<>();
            while (x != 1)
            {
                if(spf[x]!=2) ret.add(spf[x]);
                x = x / spf[x];
            }
            dp.put(x,ret);
            return ret;
        }
        

        public int lowerIndex(List<Integer> arr, int n, int x)
        {
            int l = 0, h = n - 1;
            while (l <= h)
            {
                int mid = (l + h) / 2;
                if (arr.get(mid) >= x)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            return l;
        }
        public int lowerIndex(int[] arr, int n, int x)
        {
            int l = 0, h = n - 1;
            while (l <= h)
            {
                int mid = (l + h) / 2;
                if (arr[mid] >= x)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            return l;
        }

        

        public int upperIndex(List<Integer> arr, int n, int y)
        {
            int l = 0, h = n - 1;
            while (l <= h)
            {
                int mid = (l + h) / 2;
                if (arr.get(mid) <= y)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            return h;
        }
        public int upperIndex(int[] arr, int n, int y)
        {
            int l = 0, h = n - 1;
            while (l <= h)
            {
                int mid = (l + h) / 2;
                if (arr[mid] <= y)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            return h;
        }

        

        public int id2(List<Integer> arr, int n, int x, int y)
        {
            

            int count = 0;
            count = upperIndex(arr, n, y) -
                    lowerIndex(arr, n, x) + 1;
            return count;
        }

        public int add(int a, int b){
            a+=b;
            while(a>=MOD) a-=MOD;
            while(a<0) a+=MOD;
            return a;
        }

        public int mul(int a, int b){
            long res= (long)a*(long)b;
            return (int)(res%MOD);
        }

        public int power(int a, int b) {
            int ans=1;
            while(b>0){
                if((b&1)!=0) ans= mul(ans,a);
                b>>=1;
                a= mul(a,a);
            }
            return ans;
        }

        int[] fact= new int[MAXN];
        int[] inv= new int[MAXN];

        public int Ckn(int n, int k){
            if(k<0 || n<0) return 0;
            if(n<k) return 0;
            return mul(mul(fact[n],inv[k]),inv[n-k]);
        }

        public int inverse(int a){
            return power(a,MOD-2);
        }

        public void preprocess() {
            fact[0]=1;
            for(int i=1;i<MAXN;i++) fact[i]= mul(fact[i-1],i);
            inv[MAXN-1]= inverse(fact[MAXN-1]);
            for(int i=MAXN-2;i>=0;i--){
                inv[i]= mul(inv[i+1],i+1);
            }
        }

        
        public int id5(int[] arr, int x){
            TreeSet<Integer> set= new TreeSet<>();
            for(int num: arr) set.add(num);
            return set.lower(x);
        }
        
        public int id10(int[] arr, int x){
            TreeSet<Integer> set= new TreeSet<>();
            for(int num: arr) set.add(num);
            return set.higher(x);
        }

        public void debugArr(int[] arr){
            for(int i: arr) out.print(i+" ");
            out.println();
        }

        public int rand(){
            int min=0, max= MAXN;
            int random_int = (int)Math.floor(Math.random()*(max-min+1)+min);
            return random_int;
        }
        
        public void id0(int[] arr){
            shuffleArray(arr);
            Arrays.sort(arr);
        }


        public void shuffleArray(int[] ar)
        {
            

            Random rnd = ThreadLocalRandom.current();
            for (int i = ar.length - 1; i > 0; i--)
            {
            int index = rnd.nextInt(i + 1);
            

            int a = ar[index];
            ar[index] = ar[i];
            ar[i] = a;
            }
        }
        
        InputReader in; PrintWriter out;
        Scanner sc= new Scanner(System.in);
        id8 cin;
        int[] xor= new int[3*100000+5];
        int[] pow2= new int[1000000+1];
        public void solve(InputReader in, PrintWriter out) {
            this.in=in; this.out=out;
            

            

            

            

            

            int t=1;
            preprocess();
            

            

            for(int i=1;i<=t;i++) solveD(i);
        }
    
        final double pi= Math.acos(-1);
        static Point base;

        void hack(int t){
            for(int n=1;n<=1000000000;n++){
                if(test3(n)!=test2(n)) System.out.println(n);
            }
        }
        int test1(int n){
            return (int)Math.sqrt(n) + (int)Math.cbrt(n) - (int)Math.pow(n, (double)1.0/6);
        }
        int test2(int n){
            int temp = (int)Math.cbrt(n);
            return (int)Math.sqrt(n) + temp - (int)(Math.sqrt(temp));
        }
        int test3(int n) {
            Set<Integer> res= new HashSet<>();
            for(int i=1;i*i<=n;i++) res.add(i*i);
            for(int i=1;i*i*i<=n;i++) res.add(i*i*i);
            return res.size();
        }
        void solveA(int t) {
            String s= in.nextToken();
            if (s.length() % 2 == 1) {
                out.println("NO");
                return;
            }
            int m = s.length() / 2;
            boolean ok = (s.substring(0, m).equals(s.substring(m,s.length())));
            if(ok) out.println("YES");
            else out.println("NO");
        }
         
        void solveB(int t) {
            int n= in.nextInt();
            int temp = (int)Math.cbrt(n);
            out.println((int)Math.sqrt(n) + temp - (int)(Math.sqrt(temp)));
        }

        void solveC(int t){
            char[] a= in.nextToken().toCharArray(), s= in.nextToken().toCharArray();
            int i= s.length-1;
            String b="";
            for(int j=a.length-1;j>=0;j--){
                if(i<0){out.println(-1); return;}
                if(s[i]>=a[j]) b= ""+(s[i]-a[j])+b;
                else{
                    i--;
                    if(i<0 || i+1>=s.length) {out.println(-1); return;}
                    int num= Integer.parseInt(""+s[i]+s[i+1]);
                    int num2= Integer.parseInt(""+a[j]);
                    if(num-num2>9 || num-num2<0){out.println(-1); return;}
                    b= ""+(num-num2)+b;
                    

                }
                i--;
            }
            while(i>=0) {
                b= ""+s[i]+b;
                i--;
            }
            if(b.length()==0) out.println(-1);
            else {
                out.println(Long.parseLong(b));
            }
        }

        void solveD(int t) {
            int N= (int)1000000;
            boolean[] vis= new boolean[(int)1e6+1];
            int n= in.nextInt();
            for (int i = 0; i <n ;i++){
                vis[in.nextInt()]= true;
            }
            int cnt = 0;
            for (int i = 1; i <= N; i++){
                int g = 0;
                if(!vis[i]){
                    for (int j = i*2; j <= N; j+=i){
                        if (vis[j]){
                            g = (int)_gcd(j, g);
                            if (g==i){
                                cnt++;
                                break;
                            }
                        }
                    }
                }
            }
            out.println(cnt);
        }

        void solveE(int t){
            int n= in.nextInt(), m= in.nextInt();
            int[] a= in.id9(n);
            List<Pair>[] s= new List[m];
            int cnt=1;
            int size=0;
            for(int i=0;i<m;i++){
                int k= in.nextInt();
                size+=k;
                s[i]= new ArrayList<>();
                for(int j=0;j<k;j++){
                    s[i].add(new Pair(in.nextInt(), cnt++));
                }
            }
            id0(a);
            List<Pair> average= new ArrayList<>();
            for(int i=0;i<m;i++){
                long sum=0;
                for(Pair p: s[i]){
                    sum += p.x;
                }
                average.add(new Pair((double)sum/s[i].size(), i));
            }
            Collections.sort(average, Collections.reverseOrder());
            List<Integer> p= new ArrayList<>();
            for(int i=0;i<m;i++) p.add(a[n-1-i]);
            int[] larger= new int[m];
            for(int i=0;i<m;i++){
                larger[i]= search(p, average.get(i).x);
            }

            List<Integer> wrong= new ArrayList<>();
            for(int i=0;i<m;i++){
                if(average.get(i).x>p.get(i)) wrong.add(i);
            }

            int max= 0;
            for(int i: wrong){
                max= Math.max(max, i-larger[i]);
            }

            int[] res= new int[size+1];

            for(int i=0;i<m;i++){
                int idx= average.get(i).y;
                for(int j=0;j<s[idx].size();j++){
                    double newAvg= (average.get(i).x*s[idx].size()-s[idx].get(j).x)/(s[idx].size()-1);
                    int newIdx= search(p, newAvg);
                    if(newIdx==-1){
                        res[s[idx].get(j).y]=0; continue;
                    }
                    if(max<=1 && newIdx >= wrong.get(wrong.size()-1)) res[s[idx].get(j).y]=1;
                    else res[s[idx].get(j).y]=0;
                }
            }

            for(int i=1;i<=size;i++) out.print(i);
            out.println();


        }

        private int search(List<Integer> values, double key){
            int l=0, r= values.size()-1;
            int res=-1;
            while(l<=r){
                int mid= (l+r)/2;
                if(values.get(mid)< key){
                    r=mid-1;
                }
                else{
                    l= mid+1;
                    res= l;
                }
            }
            return res;
        }

            
    
        static class ListNode{
            int idx=-1;
            ListNode next= null;
            public ListNode(int idx){
                this.idx= idx;
            }
        }
        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        



        

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        


        

        

        

        

        


        

        

        

        


        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        


        

        

                    
        

        


        

        

        

        

        

        



    
        
        public long _gcd(long a,  long b)
        {

            if(b == 0) {
                return a;
            }
            else {
                return _gcd(b, a % b);
            }
        }
        public long _lcm(long a, long b){
            return (a*b)/_gcd(a,b);
        }

    }


    


    

        
    

            
    

    

    

    

    

    

    

    

    

    

    

    

    

        
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

        
    

    

    

    

    

    

    

    

    

    

            
    

        
        
    


    static class Venice{
        public Map<Long,Long> m= new HashMap<>();
        public long base=0;
        public long totalValue=0;
        private int M= 1000000007;

        private long addMod(long a, long b){
            a+=b;
            if(a>=M) a-=M;
            return a;
        }

        public void reset(){
            m= new HashMap<>();
            base=0;
            totalValue=0;
        }
        public void update(long add){
            base= base+ add;
        }
        public void add(long key, long val){
            long newKey= key-base;
            m.put(newKey, addMod(m.getOrDefault(newKey,(long)0),val));
        }
    }



    static class Tuple implements Comparable<Tuple>{
        int x, y, z;
        public Tuple(int x, int y, int z){
            this.x= x;
            this.y= y;
            this.z=z;
        }
        @Override
        public int compareTo(Tuple o){
            return this.z-o.z;
        }
    }

    static class Point implements Comparable<Point>{
        public double x;
        public long y;
        public Point(double x, long y){
            this.x= x;
            this.y= y;
        }

        @Override
        public int compareTo(Point o) {
            if(this.y!=o.y) return (int)(this.y-o.y);
            return (int)(this.x-o.x);
        }
    }

    

    

    


    

    

    

    

    

    


    static class Pair implements Comparable<Pair>{
        public double x;
        public int y;
        public Pair(double x, int y){
            this.x= x;
            this.y= y;
        }

        @Override
        public int compareTo(Pair o) {
            if(this.x!=o.x) return (int)(this.x-o.x);
            return (int)(this.y-o.y);
        }
    }

    

    

    

    

    

    


    

    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (line == null) {
                    return null;
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }
        public double nextDouble(){
            return Double.parseDouble(nextToken());
        }
        public long nextLong(){
            return Long.parseLong(nextToken());
        }
        public int[] id9(int n){
            int[] arr= new int[n];
            for(int i=0;i<n;i++) arr[i]= nextInt();
            return arr;
        }
        public long[] id13(int n){
            long[] arr= new long[n];
            for(int i=0;i<n;i++) arr[i]= nextLong();
            return arr;
        }
        public List<Integer> id11(int n){
            List<Integer> arr= new ArrayList<>();
            for(int i=0;i<n;i++) arr.add(nextInt());
            return arr;
        }
        public int[][] id6(int n, int m){
            int[][] mat= new int[n][m];
            for(int i=0;i<n;i++) for(int j=0;j<m;j++) mat[i][j]= nextInt();
            return mat;
        }
        public List<List<Integer>> id4(int n, int m){
            List<List<Integer>> mat= new ArrayList<>();
            for(int i=0;i<n;i++){
                List<Integer> temp= new ArrayList<>();
                for(int j=0;j<m;j++) temp.add(nextInt());
                mat.add(temp);
            }
            return mat;
        }
        public char[] id3(){
            return nextToken().toCharArray();
        }
    }

    static class id8{
        String path="";
        Scanner sc;
        public id8(String path){
            this.path=path;
            try{
                sc= new Scanner(new File(path));
            }
            catch(Exception e){}
        }
        public String nextLine(){
            return sc.nextLine();
        }
        public int[] id1(){
            String line= sc.nextLine();
            String[] part= line.split("[\\s+]");
            int[] res= new int[part.length];
            for(int i=0;i<res.length;i++) res[i]= Integer.parseInt(part[i]);
            return res;
        }
    }
}