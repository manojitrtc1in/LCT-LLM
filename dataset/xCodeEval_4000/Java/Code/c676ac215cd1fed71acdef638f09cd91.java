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
        static final int MAXN = 500001;
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

        void sieveOfEratosthenes(int n)
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

        

        

        public Set<Integer> getFactorization(int x)
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

        

        public int countInRange(List<Integer> arr, int n, int x, int y)
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

        
        public int lowerBoundNormalArray(int[] arr, int x){
            TreeSet<Integer> set= new TreeSet<>();
            for(int num: arr) set.add(num);
            return set.lower(x);
        }
        
        public int upperBoundNormalArray(int[] arr, int x){
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
        
        public void suffleSort(int[] arr){
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
        CustomFileReader cin;
        int[] xor= new int[3*100000+5];
        int[] pow2= new int[1000000+1];
        public void solve(InputReader in, PrintWriter out) {
            this.in=in; this.out=out;
            

            

            

            

            

            int t=1;
            

            

            

            for(int i=1;i<=t;i++) solveE(i);
        }
    
        final double pi= Math.acos(-1);
        static Point base;

        
        
        void solveE(int t) {
            ListNode[] head= new ListNode[MAXN], tail= new ListNode[MAXN];
            int curIdx=0;
            int q= in.nextInt();
            while(q-->0){
                int c= in.nextInt();
                if(c==1){
                    int num= in.nextInt();
                    ListNode newNode= new ListNode(curIdx);
                    if(tail[num]==null) tail[num]= newNode;
                    else{ tail[num].next= newNode; tail[num]= tail[num].next; }
                    if(head[num]==null) head[num]= newNode;
                    
                    curIdx++;
                }
                else{
                    int num1= in.nextInt(), num2= in.nextInt();
                    if(num1==num2) continue;
                    if(tail[num2]!=null) tail[num2].next= head[num1];
                    else tail[num2]= head[num1];
                    if(head[num2]==null) head[num2]= head[num1];
                    if(tail[num1]!= null) tail[num2]= tail[num1];
                    head[num1]= null; tail[num1]= null;
                }
            }
            int[] res= new int[curIdx];
            for(int i=0;i<MAXN;i++){
                ListNode cur= head[i];
                while(cur!=null){
                    res[cur.idx]=i;
                    cur= cur.next;
                }
            }
            for(int i=0;i<res.length;i++) out.print(res[i]+" ");
            out.println();
            
        }
        static class ListNode{
            int idx=-1;
            ListNode next= null;
            public ListNode(int idx){
                this.idx= idx;
            }
        }
        

        static class Node implements Comparable<Node>{
            char op;
            int s;
            public Node (char op, int s) {
                this.op= op;
                this.s= s;
            }
            @Override
            public int compareTo(Node o) {
                if (this.s==o.s) return (int)(this.op-o.op);
                return this.s-o.s;
            }

        }

        private long distance(Point p1, Point p2) {
            long x= p1.x-p2.x, y= p1.y-p2.y;
            return x*x+y*y;
        }


        private boolean eqPoint(Point p1, Point p2){
            return p1.x==p2.x && p1.y==p2.y;
        }

        private double polarAngle(Point p1, Point p2) {
            

            if (p1.x==p2.x) return pi/2;
            else if (p1.y==p2.y){
                if(p1.x<p2.x) return 0;
                else return pi;
            }
            else {
                double y= (double)p2.y-(double)p1.y;
                double x= (double)p2.x-(double)p1.x;
                BigDecimal alpha1= new BigDecimal(y);
                BigDecimal alpha2= new BigDecimal(x);
                BigDecimal val= alpha1.divide(alpha2);

                double angle= Math.atan(val.doubleValue());
                if (angle<0) angle+= pi;
                out.println("angle: "+angle);
                return angle;
            }
        }

        private boolean isRightTurn(Point p1, Point p2, Point p3){
            Vector v1= new Vector(p1,p2), v2= new Vector(p1,p3);
            if(crossProd(v1,v2)<0) return true;
            else return false;
        }

        private long crossProd(Vector v1, Vector v2){
            

            return v1.x*v2.y - v2.x*v1.y;
        }

        static class PointAngle implements Comparable<PointAngle>{
            Point p;
            double angle;
            long dis;
            public PointAngle(Point p, double angle, long dis) {
                this.p= p;
                this.angle= angle;
                this.dis= dis;

            }

            @Override
            public int compareTo(PointAngle o) {
                double dif= this.angle-o.angle;
                if (dif <0) return -1;
                else if(dif >0) return 1;
                else {
                    long dif2r= this.dis-o.dis;
                    long dif2l= o.dis-this.dis;

                    if (base.x < this.p.x) return intDif(dif2r);
                    else return intDif(dif2l); 
                    
                }
            }

            private int intDif(long a){
                if (a>0) return 1;
                else if(a<0) return -1;
                else return 0;
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
        public long x;
        public long y;
        public Point(long x, long y){
            this.x= x;
            this.y= y;
        }

        @Override
        public int compareTo(Point o) {
            if(this.y!=o.y) return (int)(this.y-o.y);
            return (int)(this.x-o.x);
        }
    }

    static class Vector {
        public long x;
        public long y;

        

        public Vector(Point p1, Point p2){
            this.x= p2.x-p1.x;
            this.y= p2.y-p1.y;
        }
    }

    static class Pair implements Comparable<Pair>{
        public int x;
        public int y;
        public Pair(int x, int y){
            this.x= x;
            this.y= y;
        }

        @Override
        public int compareTo(Pair o) {
            if(this.x!=o.x) return this.x-o.x;
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
        public int[] nextIntArr(int n){
            int[] arr= new int[n];
            for(int i=0;i<n;i++) arr[i]= nextInt();
            return arr;
        }
        public long[] nextLongArr(int n){
            long[] arr= new long[n];
            for(int i=0;i<n;i++) arr[i]= nextLong();
            return arr;
        }
        public List<Integer> nextIntList(int n){
            List<Integer> arr= new ArrayList<>();
            for(int i=0;i<n;i++) arr.add(nextInt());
            return arr;
        }
        public int[][] nextIntMatArr(int n, int m){
            int[][] mat= new int[n][m];
            for(int i=0;i<n;i++) for(int j=0;j<m;j++) mat[i][j]= nextInt();
            return mat;
        }
        public List<List<Integer>> nextIntMatList(int n, int m){
            List<List<Integer>> mat= new ArrayList<>();
            for(int i=0;i<n;i++){
                List<Integer> temp= new ArrayList<>();
                for(int j=0;j<m;j++) temp.add(nextInt());
                mat.add(temp);
            }
            return mat;
        }
        public char[] nextStringCharArr(){
            return nextToken().toCharArray();
        }
    }

    static class CustomFileReader{
        String path="";
        Scanner sc;
        public CustomFileReader(String path){
            this.path=path;
            try{
                sc= new Scanner(new File(path));
            }
            catch(Exception e){}
        }
        public String nextLine(){
            return sc.nextLine();
        }
        public int[] nextIntArrLine(){
            String line= sc.nextLine();
            String[] part= line.split("[\\s+]");
            int[] res= new int[part.length];
            for(int i=0;i<res.length;i++) res[i]= Integer.parseInt(part[i]);
            return res;
        }
    }
}