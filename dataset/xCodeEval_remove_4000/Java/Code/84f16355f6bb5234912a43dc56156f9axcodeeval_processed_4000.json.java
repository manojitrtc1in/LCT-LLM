import java.io.*;
import java.util.*;



public class C{
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
        static final int MAXN = 2*100000+1;
        static final int MOD= 1000000007;

        

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

        void id8(int n)
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

        

        

        public Set<Integer> id17(int x)
        {
            if(dp.containsKey(x)) return dp.get(x);
            Set<Integer> ret = new HashSet<>();
            while (x != 1)
            {
                if(spf[x]!=2) ret.add(spf[x]);
                x = x / spf[x];
            }
            ret.add(1);
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
            if(a>=MOD) a-=MOD;
            else if(a<0) a+=MOD;
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
        
        public int id13(int[] arr, int x){
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

        public void reverseArr(int[] arr){
        
        }
        
        InputReader in; PrintWriter out;
        id11 cin;
        long[] pow2= new long[61];
        Scanner sc= new Scanner(System.in);
        public void solve(InputReader in, PrintWriter out) {
            this.in=in; this.out=out;
            

            

            

            pow2[0]=1;
            for(int i=1;i<pow2.length;i++) pow2[i]= 2*pow2[i-1];

            int t=in.nextInt();
            

            for(int i=1;i<=t;i++) solveA(i);
        }

        Map<Integer, List<Integer>> left, right;
        int[] leftVal, rightVal;
        public void solveA(int t){
                int n= in.nextInt();
                char[] s= in.nextToken().toCharArray();


                

                


                

                

                

                

                

                

                

                        
                


                

                

                

                


                

                

                

                

                

                

                

                

                

                

                

                

                

                    
                


                

                

                

                

                


                List<Integer> idx= new ArrayList<>();
                int[] preb= new int[n+1];
                int[] prec= new int[n+1];
                for(int i=0;i<n;i++){
                    preb[i+1]= preb[i];
                    prec[i+1]= prec[i];
                    if(s[i]=='a') idx.add(i);
                    else if(s[i]=='b'){
                        preb[i+1]++;
                        
                    }
                    else{
                        prec[i+1]++;
                    }
                }

                int res= Integer.MAX_VALUE;
                for(int i=1;i<idx.size();i++){
                    int l= idx.get(i-1), r= idx.get(i);
                    int numb= preb[r]-preb[l];
                    int numc= prec[r]-prec[l];
                    

                    if(numb<=1 && numc<=1){
                        res= Math.min(res, r-l+1);
                    }
                }

                for(int i=0;i+2<idx.size();i++){
                    int l1= idx.get(i);
                    int l2= idx.get(i+1);
                    int l3= idx.get(i+2);
                    int id7= preb[l2]-preb[l1];
                    int id0= prec[l2]-prec[l1];
                    int id15= preb[l3]-preb[l2];
                    int id10= prec[l3]-prec[l2];
                    

                    if(id7+id15<=2 && id0+id10<=2){
                        res= Math.min(res, l3-l1+1);
                    }
                }

                if(res==Integer.MAX_VALUE) out.println(-1);
                else out.println(res);


            
        }

        private void calc(int[] leftVal, int[] rightVal, int[] a, int[] p){
            int maxn=0;
            Set<Integer> set= new HashSet<>();
            for(int i: a) {
                maxn= Math.max(maxn,i);
                set.add(i);
            }
            for(int i: p) {
                maxn= Math.max(maxn,i);
                set.add(i);
            }
            BIT fen= new BIT(maxn);
            List<Integer> temp= new ArrayList<>();
            for(int i: set) temp.add(i);
            int n= temp.size();
            Collections.sort(temp);
            Map<Integer,Integer> idx= new HashMap<>();
            for(int i=0;i<temp.size();i++) idx.put(temp.get(i),i);
            


            for(int i=0;i<a.length;i++){
                fen.updateBIT(n, idx.get(a[i]), 1);
                if (left.containsKey(i)){
                    for(int j: left.get(i)) {
                        leftVal[j]= fen.getSum(idx.getOrDefault(p[j],1)-1);
                    }
                }
                if(right.containsKey(i)){
                    for(int j: right.get(i)) {
                        rightVal[j]= fen.getSum(idx.getOrDefault(p[j],1)-1);
                    }
                }
            }

        }
        

        

        private FenIndex buildBIT(int[] a){
            BIT fen= new BIT();
            int n= a.length;
            Set<Integer> set= new HashSet<>();
            for(int i: a) set.add(i);
            List<Integer> temp= new ArrayList<>();
            for(int i: set) temp.add(i);
            Collections.sort(temp);
            Map<Integer,Integer> idx= new HashMap<>();
            for(int i=0;i<temp.size();i++) idx.put(temp.get(i),i);
            for(int val: a) fen.updateBIT(n, idx.get(val), 1);
            return new FenIndex(fen, idx);

        }
        public int _gcd(int a,  int b)
        {

            if(b == 0) {
                return a;
            }
            else {
                return _gcd(b, a % b);
            }
        }
        public int _lcm(int a, int b){
            return (a*b)/_gcd(a,b);
        }

    }

    static class FenIndex {
        public BIT fen;
        public Map<Integer,Integer> idx;
        public FenIndex(BIT fen, Map<Integer,Integer> idx){
            this.fen= fen;
            this.idx= idx;
        }
    }

    static class PairMap {
        public Map<Integer,Integer> left= new HashMap<>();
        public Map<Integer,Integer> right= new HashMap<>();
    }


    static class SEG {
        public long _gcd(long a,  long  b)
        {

            if(b == 0) {
                return a;
            }
            else {
                return _gcd(b, a % b);
            }
        }
        long[] segs;
        public SEG(List<Long> a) {
            int n= a.size();
            segs= new long[4*n];
            build(0,a,0,n-1);
        }
        void build(int root, List<Long> a, int l, int r){
            if (l==r){
                segs[root] = a.get(l); return;
            }
            int m = (l+r) >> 1;
            build(root*2+1, a, l, m);
            build(root*2+2, a, m+1, r);
            segs[root] = _gcd(segs[root*2+1], segs[root*2+2]);
        }
        long query(int root, int l, int r, int lq, int rq){
            if (lq > r || rq < l) return 0l;
            if (l >= lq && rq >= r) return segs[root];
            int m = (l+r)>>1;
            return _gcd(query(root*2+1, l, m, lq, rq),
                         query(root*2+2, m+1, r, lq, rq));
        }
    }

    static class BIT {
        int MAXN= 400000+10;
        int BITree[] = new int[MAXN];

        public BIT(int maxn){
            MAXN= maxn+5;
            BITree = new int[MAXN];
        }

        public BIT(){}
     
        
    
        

        

        

        

        public int getSum(int index)
        {
            int sum = 0; 

        
            

            

            index = index + 1;
        
            

            while(index>0)
            {
                

                

                sum += BITree[index];
        
                

                

                index -= index & (-index);
            }
            return sum;
        }
    
        

        

        

        

        public void updateBIT(int n, int index,
                                            int val)
        {
            

            

            index = index + 1;
        
            

            while(index <= n)
            {
            

            BITree[index] += val;
        
            

            

            index += index & (-index);
            }
        }
    
        
        void id14(int arr[], int n)
        {
            

            for(int i=1; i<=n; i++)
                BITree[i] = 0;
        
            

            

            for(int i = 0; i < n; i++)
                updateBIT(n, i, arr[i]);
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
            if(this.x!=o.x) return this.x-o.x;
            if(this.y!=o.y) return this.y-o.y;
            return this.z-o.z;
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
            return this.x-o.x;
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
        public int[] id12(int n){
            int[] arr= new int[n];
            for(int i=0;i<n;i++) arr[i]= nextInt();
            return arr;
        }
        public long[] id9(int n){
            long[] arr= new long[n];
            for(int i=0;i<n;i++) arr[i]= nextLong();
            return arr;
        }
        public List<Integer> id16(int n){
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

    static class id11{
        String path="";
        Scanner sc;
        public id11(String path){
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