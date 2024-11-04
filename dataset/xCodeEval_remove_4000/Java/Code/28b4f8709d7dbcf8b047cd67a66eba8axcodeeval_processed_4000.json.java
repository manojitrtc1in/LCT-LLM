import java.io.*;
import java.util.*;
import java.math.BigInteger;



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
        static final int MAXN = 1010;
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

        void id5(int n)
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

        

        

        public Set<Integer> id9(int x)
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

        

        public int id0(List<Integer> arr, int n, int x, int y)
        {
            

            int count = 0;
            count = upperIndex(arr, n, y) -
                    lowerIndex(arr, n, x) + 1;
            return count;
        }

        public int _gcd(int a,  int  b)
        {

            if(b == 0) {
                return a;
            }
            else {
                return _gcd(b, a % b);
            }
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

        
        public int id3(int[] arr, int x){
            TreeSet<Integer> set= new TreeSet<>();
            for(int num: arr) set.add(num);
            return set.lower(x);
        }
        
        public int id7(int[] arr, int x){
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
        
        InputReader in; PrintWriter out;
        
        public void solve(InputReader in, PrintWriter out) {
            this.in=in; this.out=out;
            int t= in.nextInt();
            while(t-->0){
                solveD();
            }
        }
        
        public void solveB(){
            int h= in.nextInt(), w= in.nextInt();
            int[][] res= new int[h][w];
            for(int j=0;j<w;j+=2) res[0][j]=1;
            for(int i=2;i<h;i+=2) {
                res[i][0]=1;
                res[i][w-1]=1;
            }
            for(int j=2;j<=w-3;j+=2) res[h-1][j]=1;
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++) out.print(res[i][j]);
                out.println();
            }
            out.println();
        }

        public void solveA(){
            char[] s= in.id1();
            int res= 0;
            for(char ch: s){
                res= Math.max(res,Math.max(ch-'0',1));
            }
            out.println(res);
        }

        public void solveC(){
            int n= in.nextInt();
            int[] a= in.id6(n);
            int[] b= in.id6(n);
            Arrays.sort(a); Arrays.sort(b);
            int[] presuma= new int[n+1];
            int[] presumb= new int[n+1];
            for(int i=1;i<=n;i++){
                presuma[i]= presuma[i-1]+ a[n-i];
                presumb[i]= presumb[i-1]+ b[n-i]; 
            }
            

            for(int z=0;z<=4*n;z++){
                int total= z+n;
                int round= total - total/4;
                int scoreA= 100* z + presuma[round-z];
                int scoreB= presumb[Math.min(n,round)];
                if(scoreA>=scoreB){
                    out.println(z); return;
                }
            }
            out.println("FUCK");
        }

        public void solveD(){
            int n= in.nextInt();
            int[] b= in.id6(n);
            Set<Integer> set= new HashSet<>();
            Set<Integer> pos= new HashSet<>();
            TreeSet<Integer> lack= new TreeSet<>();
            int k=0;
            int[] res= new int[n];
            for(int i=0;i<n;i++){
                if(!set.contains(b[i])){
                    res[i]= b[i];
                    set.add(b[i]);
                    k++;
                }
            }
            for(int i=1;i<=n;i++){
                if(!set.contains(i)) lack.add(i);
                if(res[i-1]==0) pos.add(i);
            }
            for(int i=0;i<n;i++){
                if(pos.size()==2){
                    

                    

                    

                    

                    

                    

                    List<Integer> posList= new ArrayList<>();
                    for(int temp: pos) posList.add(temp);
                    List<Integer> lackList= new ArrayList<>();
                    for(int temp: lack) lackList.add(temp);
                    Collections.sort(lackList); Collections.sort(posList);
                    int pos1= posList.get(0), pos2= posList.get(1);
                    if(pos1!=lackList.get(0) && pos2!= lackList.get(1)){
                        res[pos1-1]= lackList.get(0);
                        res[pos2-1]= lackList.get(1);
                    }
                    else{
                        assert (pos1!=lackList.get(1));
                        assert (pos2!=lackList.get(0));
                        res[pos2-1]= lackList.get(0);
                        res[pos1-1]= lackList.get(1);
                    }

                    break;
                }
                if(pos.size()==1){
                    int pos1=-1;
                    for(int temp: pos) pos1= temp;
                    int lackNum=-1;
                    for(int temp: lack) lackNum= temp;
                    if(lackNum!= pos1) res[pos1-1]= lackNum;
                    else{
                        int swapIdx= -1;
                        for(int idx=0;idx<n;idx++){
                            if(b[idx]==b[pos1-1]){
                                swapIdx=idx+1;
                                break;
                            }
                        }
                        if(swapIdx==-1){
                            if(pos1==1) swapIdx= pos1+1;
                            else swapIdx= pos1-1;
                        }
                        int tempVal= res[swapIdx-1];
                        res[swapIdx-1]= pos1;
                        res[pos1-1]= tempVal;
                    }
                    break;
                }
                if(res[i]==0){
                    if(lack.higher(i+1)!=null){
                        int num= lack.higher(i+1);
                        res[i]= num;
                        lack.remove(num);
                        pos.remove(i+1);
                    }
                    else if(lack.lower(i+1)!=null){
                        int num= lack.lower(i+1);
                        res[i]= num;
                        lack.remove(num);
                        pos.remove(i+1);
                    }
                }
                
            }
            out.println(k);
            for(int i: res) out.print(i+" ");
            out.println();
        }

        class SEG {
            int n;
            int[] segs;
            public SEG (int[] a){
                this.n= a.length;
                segs= new int[4*n];
                build(a,0,0,n-1);
            }
            public void build(int[] a, int root, int l, int r){
                if(l==r){
                    segs[root]=a[l];
                    return;
                }
                int m= (l+r)/2;
                build(a,2*root+1,l,m);
                build(a,2*root+2,m+1,r);
                segs[root]= _gcd(segs[2*root+1], segs[2*root+2]);
            }
            public int query(int root, int l, int r, int lq, int rq){
                if(lq<=l && rq>=r) return segs[root];
                if(lq>r || rq<l) return 0;
                int m= (l+r)/2;
                int left= query(2*root+1, l, m, lq, rq);
                int right= query(2*root+2, m+1, r, lq, rq);
                return _gcd(left,right);
            }

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
            return this.x-o.x;
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
        public int[] id6(int n){
            int[] arr= new int[n];
            for(int i=0;i<n;i++) arr[i]= nextInt();
            return arr;
        }
        public long[] id10(int n){
            long[] arr= new long[n];
            for(int i=0;i<n;i++) arr[i]= nextLong();
            return arr;
        }
        public List<Integer> id8(int n){
            List<Integer> arr= new ArrayList<>();
            for(int i=0;i<n;i++) arr.add(nextInt());
            return arr;
        }
        public int[][] id4(int n, int m){
            int[][] mat= new int[n][m];
            for(int i=0;i<n;i++) for(int j=0;j<m;j++) mat[i][j]= nextInt();
            return mat;
        }
        public List<List<Integer>> id2(int n, int m){
            List<List<Integer>> mat= new ArrayList<>();
            for(int i=0;i<n;i++){
                List<Integer> temp= new ArrayList<>();
                for(int j=0;j<m;j++) temp.add(nextInt());
                mat.add(temp);
            }
            return mat;
        }
        public char[] id1(){
            return nextToken().toCharArray();
        }
    }
}