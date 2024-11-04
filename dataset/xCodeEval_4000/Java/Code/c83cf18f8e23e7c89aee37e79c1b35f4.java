import java.io.*; 
import java.util.*; 
import java.text.*; 
import java.math.*; 
import java.util.regex.*; 
import java.lang.*; 


public class Main{
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    FastReader in = new FastReader();
    int mod = 1000000007;

    void solve(int t) throws Exception{
        long a =0, b= 0, c=0, d=0;
        a = inl(); b = inl();
        c = inl();
        d = inl();

         

        if(a*d==c*b){
            out.println(0);
            return;
        }else{
            long x = a*d; long y = c*b;
            if(y!=0 && x%y==0){
                out.println(1); return;
            }else if(x!=0 && y%x==0){
                out.println(1); return;
            }else{
                out.println(2); return;
            }
        }
        
    }

    void run() throws Exception{
        int tc = in(), t=1;
        while(t<=tc){solve(t);t++;}
        out.flush();out.close();System.gc();
    }

    public static void main(String[] args) throws Exception{
        try {
            new Main().run();
        } catch (Exception e) {
            e.printStackTrace();
            return;
        }
    }
    class FastReader{
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
    int countOccur(StringBuilder ct){
        String mySubstring = "01";
        String myString = String.valueOf(ct);
        int count = 0, index = 0;
        List<Integer> indices=new ArrayList<>();
        while ((index = myString.indexOf(mySubstring, index)) != -1 ){count++;indices.add(index);index++;}
        return count;
    }

    void sort(int[] arr){
        ArrayList<Integer> ls = new ArrayList<Integer>();
        for(int x: arr)ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++)arr[i] = ls.get(i);
    }

    String sort(String s){
        char[] arr = s.toCharArray();
        ArrayList<Character> ls = new ArrayList<Character>();
        for(char x: arr)ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++)arr[i] = ls.get(i);
        return String.valueOf(arr);
    }

    void sort(long[] arr){
        ArrayList<Long> ls = new ArrayList<Long>();
        for(long x: arr)ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++)arr[i] = ls.get(i);
    }

    double pow(double a,long b){
        long ans = b;
        double res =1;
        if(b<0){
            ans = -1*b;
        }
        while(ans>0){
            if((ans&1)==1){
                res = (res*a);
                ans = ans -1;
            }else{
                a = (a*a);
                ans = ans>>1;
            }
        }
        if(b<0){
            res = 1/res;
        }
        return res;
    }

    long pow(long a,long b){
        long ans = b;
        long res =1;
        if(b<0){ans = -1*b;}
        while(ans>0){
            if((ans&1)==1){
                res = (res*a);
                ans = ans -1;
            }else{
                a = (a*a)%mod;
                ans = ans>>1;
            }
        }
        if(b<0){res = 1/res;}
        return res;
    }

    int msb(int n){
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        n = n + 1;
        return (n >> 1);
    }

    boolean isPrime(int a){
        if (a == 1) return false;
        if (a == 2 || a == 3) return true;
        if (a%2==0 || a%3==0) return false;
        for (int i=5;i*i<=a;i+=6){
            if (a%i==0 || a%(i+2)==0) return false;
        }
        return true;
    }

    ArrayList<Integer> getAllPrime(int n){

        ArrayList<Integer> ans = new ArrayList<Integer>();
        if(n <= 1)  return ans;

        boolean[] arr = new boolean[n+1];
        Arrays.fill(arr,true);
        for (int i=2;i*i<=n;i++){
            if (arr[i]){
                for (int j=i*i;j<=n;j+=i){
                    arr[j] = false;
                }
            }
        }
        for (int i=2;i<=n;i++){
            if (arr[i]){
                ans.add(i);
            }
        }
        return ans;
    }

    long totient(long n){
        long result = n;
        for (int p = 2; p*p <= n; ++p)
            if (n % p == 0)
            {
                while(n%p == 0)
                    n /= p;
                result -= result/p;
            }
        if (n > 1)
            result -= result/n;
        return result;
    }

    ArrayList<Integer> allDivisor(int n){
        int i=0;
        ArrayList<Integer> a = new ArrayList<Integer>();
        for (i=1;i*i<=n;i++){
            if (n%i==0){
                a.add(i);
            }
        }
        for (;i>=1;i--){
            if (n%i==0){
                a.add(n/i);
            }
        }
        return a;
    }

    void primeFactors(int a){
        if (a<=1) return;
        while (a%2==0) {System.out.printf(2+" "); a=a/2;}
        while (a%3==0) {System.out.printf(3+" "); a=a/3;}
        for (int i=5;i*i<=a;i+=6){
            while (a%i==0){
                System.out.printf(i+" ");
                a = a/i;
            }
            while (a%(i+2)==0){
                System.out.printf((i+2)+" ");
                a = a / (i+2);
            }
        }
        if (a>3){
            System.out.printf(a+" ");
        }
        System.out.println();
    }

    int egcd(int a, int b,int x,int y){
       if(b == 0){
           x = 1;
           y = 0;
           return a;
       }
        int x1=1,y1=1;
       int ans = egcd(b, a%b,x1,y1);
       x = y1;
       y = x1 - (a/b)*y1;
       System.out.println(x+" "+y);
       return ans;
    }


    

    



    long fib(long n) {    

        return (long) Math.round((Math.pow((1 + Math.sqrt(5)) / 2, n) - Math.pow((1 - Math.sqrt(5)) / 2, n)) / Math.sqrt(5));
    }   
    boolean isps(double number){double sqrt=Math.sqrt(number);return ((sqrt - Math.floor(sqrt)) == 0);}



    int in(){ return in.nextInt();}
    long inl(){ return in.nextLong();}
    String ins(){ return in.next();}
    double ind() { return Double.parseDouble(in.next());}
    long log2(long N){return (long)(Math.log(N) / Math.log(2));}
    int binaryToInt(String s){return Integer.parseInt(s,2);}
    long digitsum(long n){long sum = 0;while(n>0){sum += n%10;n = n/10;}return sum;}
    String toBinaryString(int s){return Integer.toBinaryString(s);}
    int lcm(int a,int b){return a*b/gcd(a,b);}
    long lcm(long a,long b){return a*b/gcd(a,b);}
    int gcd(int a, int b){ if (a==0) return b; return gcd(b%a,a);}
    long gcd(long a, long b){ if (a==0) return b; return gcd(b%a,a);}
    int bit(long n){return (n==0)?0:(1+bit(n&(n-1)));}
    int ctz(int f){int x = 0;for (int i=5;i<=f;i=i*5)x += f/i;return x;}
    void fill(int[] a){ for(int i=0;i<a.length;i++) a[i] = in.nextInt(); }
    void fill(long[] a){ for(int i=0;i<a.length;i++) a[i] = in.nextLong(); }
    void fill(String[] a){ for(int i=0;i<a.length;i++) a[i] = in.next(); }
    void fill(ArrayList<ArrayList<Integer>> a){for (int i=0;i<a.size()-1;i++){int u = in()-1;int v = in()-1;addEdge(a,u,v);}}
    void addEdge(ArrayList<ArrayList<Integer>> a,int u,int v){a.get(u).add(v);a.get(v).add(u);}
    void fill(int[][] m){for (int i=0;i<m.length;i++){for(int j=0;j<m[i].length;j++){m[i][j] = in();}}}
    void swap(char[] c,int i,int j){ char t = c[i]; c[i] = c[j]; c[j] = t;}
    void swap(int[] c,int i,int j){int t = c[i]; c[i] = c[j]; c[j] = t;}
    void swap(long[] c,int i,int j){long t = c[i]; c[i] = c[j]; c[j] = t;}
    void p(int[] a){ for(int i=0;i<a.length;i++) out.printf(a[i]+" "); out.println(); }
    void p(int[][] a){ for(int i=0;i<a.length;i++){for(int j=0;j<a[i].length;j++)out.printf(a[i][j]+" ");out.println();}}
    void p(long[] a){for(int i=0;i<a.length;i++) out.printf(a[i]+" "); out.println();}
    void p(char[] a){for(int i=0;i<a.length;i++) out.printf(a[i]+" "); out.println();}
    void p(String s){for(int i=0;i<s.length();i++) out.printf(s.charAt(i)+" "); out.println();}
    void p(ArrayList<Integer> a){a.forEach(e -> out.printf(e+" "));out.println();}
    void p(LinkedList<Integer> a){a.forEach(e -> out.printf(e+" "));out.println();}
    void p(HashSet<Integer> a){a.forEach(e -> out.printf(e+" "));out.println();}
    void p(HashMap<Integer,Integer> a){for(Map.Entry<Integer, Integer> mp : a.entrySet())out.println(mp.getKey()+" "+mp.getValue());}
    void reverse(int[] a,int i,int j){while(i<j){int t = a[i];a[i] = a[j];a[j]= t;i++;j--;}}
    String reverse(String s,int i,int j){char[] a = s.toCharArray();while(i<j){char t = a[i];a[i] = a[j];a[j]= t;i++;j--;}return String.valueOf(a);}
    boolean isok(int i,int j,int n,int m){return i >=0 && j>= 0 && i<n && j<m;}
    Pair[] alldir(){ return new Pair[]{new Pair(0,1),new Pair(1,0),new Pair(0,-1),new Pair(-1,0),
    new Pair(-1,1),new Pair(-1,-1),new Pair(1,-1),new Pair(1,1)};}
    Pair[] sides(){ return new Pair[]{new Pair(0,1),new Pair(1,0),new Pair(0,-1),new Pair(-1,0)};}
    Pair[] corners(){ return new Pair[]{new Pair(-1,1),new Pair(-1,-1),new Pair(1,-1),new Pair(1,1)};}

    int[] dijkstra(ArrayList<ArrayList<ArrayList<Integer>>> g, int source) {
        int n = g.size(); 
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[source] = 0;
        int[] prev = new int[n];
        Arrays.fill(prev, -1);
        prev[source] = source;
        PriorityQueue<ArrayList<Integer>> pq = new PriorityQueue<>(new Comparator<ArrayList<Integer>>() {
            public int compare(ArrayList<Integer> x, ArrayList<Integer> y) {
                if(x.get(1) == y.get(1)) return Integer.compare(x.get(0), y.get(0));
                return Integer.compare(x.get(1),y.get(1));
            }
        });
        ArrayList<Integer> x = new ArrayList<Integer>();
        x.add(source);
        x.add(0);
        pq.add(x);
        while(!pq.isEmpty()) {
            ArrayList<Integer> u = pq.poll();
            for(ArrayList<Integer> adj : g.get(u.get(0))) {
                if(dist[adj.get(0)] > dist[u.get(0)]+adj.get(1)) {
                    prev[adj.get(0)] = u.get(0);
                    dist[adj.get(0)] = dist[u.get(0)]+adj.get(1);
                    ArrayList<Integer> y = new ArrayList<Integer>();
                    y.add(adj.get(0));
                    y.add(dist[adj.get(0)]);
                    pq.add(y);
                }
            }
        }
        return dist;
    }

    class Triplet implements Comparable<Triplet> {
        long x;
        long y;
        long z;
        public Triplet(long x,long y,long z){
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public String toString() {
            return "(" + x + "," + y + "," + z + ")";
        }

        public int compareTo(Triplet a){
            long dif = this.z - a.z;
            if (dif > 0) return 1;
            if (dif < 0) return -1;
            return 0; 
        }
    }


    class Pair implements Comparable<Pair> {
        long k;long v;
        public Pair(long k, long v) {this.k = k;this.v = v;}
        public String toString() {return "(" + k + "," + v + ")";}
        public int compareTo(Pair a){
            long dif = this.v - a.v;
            if (dif > 0) return 1;
            if (dif < 0) return -1;
            return 0; 
        } 
    }
    class compare implements Comparator<Pair>{
        public int compare(Pair a,Pair b){
            long diff = a.v - b.v;
            if(diff>0) return 1;
            if(diff<0) return -1;
            return 0;
        }
    }
    class ncr{
        public int mod = 1000000007;
        public long[] fact = new long[mod+1];
        public long[] ifact = new long[mod+1];
        public int nCr(long n, long r)
        {
            preFactFermat();
            long ans = 1;
            

            

            

            

            

            

            

            

            

            ans = lucas(n,r,ans);
            
            return (int)ans;
        }
        public long lucas(long n,long r,long ans){
            if(r==0)return 1;
            long ni=n%mod,ri=r%mod;
            return (lucas(n/mod,r/mod,ans)*(fermat(ni,ri,ans)%mod))%mod;
        }
        
        public long fermat(long n,long r,long ans){
            if(n<r){
                return 0;
            }
            ans = (ans* (fact[(int)n]*((ifact[(int)r]*ifact[(int)(n-r)])%mod)%mod))%mod;
            return ans;
        }
        
        public void preFactFermat(){
            fact[1] = 1;
            fact[0] = 1;
            ifact[0] = expo(1,mod-2);
            ifact[1] = expo(1,mod-2);
            for(int i=2;i<=mod;i++){
                fact[i] = (i*(fact[i-1]%mod))%mod;
                ifact[i] = expo(fact[i],mod-2);
            }
        }
        
        public long expo(long a,long b){
            long ans = b;
            long res =1;
            if(b<0){
                ans = -1*b;
            }
            while(ans>0){
                if((ans&1)==1){
                    res = (res*a)%mod;
                }
                a = (a*a)%mod;
                ans = ans>>1;
            }
            if(b<0){
                res = 1/res;
            }
            return res;
        }
    }
    class ft{

        int[] ft;

        public void print(){
            for (int i=0;i<ft.length;i++){
                System.out.printf(ft[i]+" ");
            }
        }

        public ft(int[] a){
            ft = new int[a.length+1];
            for (int i=0;i<a.length;i++){
                this.update(i,a[i]);
            }
        }

        public int getSum(int i){
            int sum = 0;

            while(i>0){
                sum += ft[i];
                i = i - (i & (-i));
            }
            return sum;
        }

        public void update(int i,int d){
            i = i +1;
            while(i<ft.length){
                ft[i] += d;
                i = i + (i &(-i));
            }
        }
    }

    class st{
        
        int[] st;

        
        public st(int[] a){
            st = new int[a.length*4];
            construct(a,0,a.length-1,0);
        }

        void print(){
            for(int i=0;i<st.length;i++){
                System.out.printf(st[i]+" ");
            }
            System.out.println();
        }

        int construct(int[] a,int ss,int se,int si){
            if(ss==se){
                st[si] = a[ss];
                return a[ss];
            }
            int mid = (ss+se)/2;

            st[si] = construct(a,ss,mid,2*si+1) + construct(a,mid+1,se,2*si+2);
            return st[si];
        }
        
        int getSum(int qs,int qe,int ss,int se,int si){
            if(qe<ss || qs>se){
                return 0;
            }
            if(ss>=qs && se <= qe){
                return st[si];
            }
            int mid = (ss+se)/2;

            return getSum(qs,qe,ss,mid,2*si+1) + getSum(qs,qe,mid+1,se,2*si+2);
        }
        
        void update(int ss,int se,int si,int i,int diff){
            if(ss > i || i> se){
                return;
            }
            this.st[si] += diff;
            if(ss< se){
                int mid = (ss+se)/2;
                update(ss,mid,2*si+1,i,diff);
                update(mid+1,se,2*si+2,i,diff);
            }
        }
    }
    class uf {
        int count = 0;
        int[] parent, rank;

        public uf(int n) {
            count = n;
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        public boolean isConnected(int a, int b){return find(a) == find(b);}

        public int ct() {return count;}

        public int size() {return parent.length;}

        public int find(int n) {
            while (n != parent[n]) {
                parent[n] = parent[parent[n]];
                n = parent[n];
            }
            return n;
        }

        public void union(int a, int b) {
            int rep_a = find(a);
            int rep_b = find(b);
            if (rep_a == rep_b) return;
            if (rank[rep_b] > rank[rep_a]) {
                parent[rep_a] = rep_b;
            }else {
                parent[rep_b] = rep_a;
                if (rank[rep_a] == rank[rep_b]) {rank[rep_a]++;}
            }
            count--;
        }
    }

    class trie{
        trie[] child;
        boolean isEnd;
        int count;

        public trie(){
            child = new trie[26];
            isEnd = false;
        }

        public void add(String s){
            trie cur = this;
            for(int i=0;i<s.length();i++){
                int c = s.charAt(i) - 'a';
                if(cur.child[c]==null){cur.child[c] = new trie();}
                cur = cur.child[c];
            }
            count++;
            cur.isEnd=true;
        }

        public boolean contains(String s){
            trie cur = this;
            for(int i=0;i<s.length();i++){
                int c = s.charAt(i) - 'a';
                if(cur.child[c]==null){return false;}
                cur = cur.child[c];
            }
            return cur.isEnd;
        }

        public boolean containsPrefix(String s){
            trie cur = this;
            for(int i=0;i<s.length();i++){
                int c = s.charAt(i) - 'a';
                if(cur.child[c]==null){return false;}
                cur = cur.child[c];
            }
            return true;
        }

        public trie delete(String key,int i){
            trie root = this;
            if (root==null){return null;}
            if (i==key.length()){
                root.isEnd = false;
                if (root.isEmpty()){root = null;}
                return root;
            }
            int c = key.charAt(i)-'a';
            root.child[c]= delete(key,i+1);
            if (root.isEmpty() && root.isEnd==false){ root = null; }
            return root;
        }

        public trie remove(String s){return delete(s,0);}

        public boolean isEmpty(){return count==0;}

        public int size(){ return count;}
        
    }
}

