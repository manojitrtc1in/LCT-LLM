import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args){
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        solve(in, out);
        out.close();
    }

    static String reverse(String s) {
        return (new StringBuilder(s)).reverse().toString();
    }

    static void sieveOfEratosthenes(int n, int factors[], ArrayList<Integer> ar) 
    { 
        factors[1]=1;
        int p;
        for(p = 2; p*p <=n; p++) 
        { 
            if(factors[p] == 0) 
            { 
                ar.add(p);
                factors[p]=p;
                for(int i = p*p; i <= n; i += p) 
                    if(factors[i]==0)
                        factors[i] = p; 
            } 
        } 
        for(;p<=n;p++){
            if(factors[p] == 0) 
            { 
                factors[p] = p;
                ar.add(p);
            } 
        }
    }

    static void sort(int ar[]) {
        int n = ar.length;
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++)
            a.add(ar[i]);
        Collections.sort(a);
        for (int i = 0; i < n; i++)
            ar[i] = a.get(i);
    }

    static void sort1(long ar[]) {
        int n = ar.length;
        ArrayList<Long> a = new ArrayList<>();
        for (int i = 0; i < n; i++)
            a.add(ar[i]);
        Collections.sort(a);
        for (int i = 0; i < n; i++)
            ar[i] = a.get(i);
    }

    static void sort2(char ar[]) {
        int n = ar.length;
        ArrayList<Character> a = new ArrayList<>();
        for (int i = 0; i < n; i++)
            a.add(ar[i]);
        Collections.sort(a);
        for (int i = 0; i < n; i++)
            ar[i] = a.get(i);
    }

    static long ncr(long n, long r, long mod) {
        if (r == 0)
            return 1;
        long val = ncr(n - 1, r - 1, mod);
        val = (n * val) % mod;
        val = (val * modInverse(r, mod)) % mod;
        return val;
    }

    static long sum[];
    static long lz[];
    
    static void build(long a[], int v, int tl, int tr) {
        if (tl == tr) {
            sum[v] = a[tl];
            
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            sum[v] = sum[v*2] + sum[v*2+1];
        }
    }

    static void push(int v, int tl, int tr){
        if(tl==tr){
            lz[v] = 0;
            return;
        }
        sum[2*v] += lz[v];
        sum[2*v] %= m;
        sum[2*v+1] += lz[v];
        sum[2*v+1] %= m;
        lz[2*v] += lz[v];
        lz[2*v] %= m;
        lz[2*v+1] += lz[v];
        lz[2*v+1] %= m;
        lz[v] = 0;
    }

    static void update(int v, int tl, int tr, int l, int r, long val) {
        push(v,tl,tr);
        if(tl>r||tr<l)
            return;
        if(tl>=l&&tr<=r){
            sum[v] += val;
            sum[v] %= m;
            lz[v] += val;
            lz[v] %= m;
            return;
        }
        int tm = ((tl + tr) >> 1);
        update(v*2, tl, tm, l, r, val);
        update(v*2+1, tm+1, tr, l, r, val);
        sum[v] = sum[2*v]+sum[2*v+1];
        sum[v] %= m;
    }

    static long get(int v, int tl, int tr, int l, int r) {
        push(v,tl,tr);
        if (tl >= l && tr <= r) {
            return sum[v];
        }
        int tm = ((tl + tr) >> 1);
        if(l>tm){
            return get(2*v+1, tm+1, tr, l, r);
        }
        if(r<tm+1){
            return get(2*v, tl, tm, l, r);
        }
        return (get(2*v, tl, tm, l, r) + get(2*v+1, tm+1, tr, l, r)) % m;
    }

    


    static int parent[];
    static int rank[];

    static long m = 0;

    static int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
    }
    
    static void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }
    
    static void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b]){
                int tmp = a;
                a = b;
                b = tmp;
            }
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    static int parent1[];
    static int rank1[];

    static int find_set1(int v) {
        if (v == parent1[v])
            return v;
        return find_set1(parent1[v]);
    }
    
    static void make_set1(int v) {
        parent1[v] = v;
        rank1[v] = 0;
    }
    
    static void union_sets1(int a, int b) {
        a = find_set1(a);
        b = find_set1(b);
        if (a != b) {
            if (rank1[a] < rank1[b]){
                int tmp = a;
                a = b;
                b = tmp;
            }
            parent1[b] = a;
            if (rank1[a] == rank1[b])
                rank1[a]++;
        }
    }

    public static void solve(InputReader sc, PrintWriter pw){
        int i, j = 0;
        

        long mod = 998244353;
        int t = sc.nextInt();
        u: while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int k = sc.nextInt();
            int x[] = new int[n];
            int y[] = new int[m];
            HashSet<Integer> xs = new HashSet<>();
            HashSet<Integer> ys = new HashSet<>();
            for(i=0;i<n;i++){
                x[i] = sc.nextInt();
                xs.add(x[i]);
            }
            for(i=0;i<m;i++){
                y[i] = sc.nextInt();
                ys.add(y[i]);
            }
            sort(x);
            sort(y);
            HashMap<Integer,ArrayList<Integer> > xlist = new HashMap<>();
            HashMap<Integer,ArrayList<Integer> > ylist = new HashMap<>();
            ArrayList<Integer> allx = new ArrayList<>();
            ArrayList<Integer> ally = new ArrayList<>();
            for(i=0;i<k;i++){
                int p = sc.nextInt();
                int q = sc.nextInt();
                if(xs.contains(p)&&ys.contains(q)){
                    continue;
                }
                if(xs.contains(p)){
                    allx.add(q);
                    if(!xlist.containsKey(p)){
                        xlist.put(p,new ArrayList<>());
                    }
                    xlist.get(p).add(q);
                }
                else{
                    ally.add(p);
                    if(!ylist.containsKey(q)){
                        ylist.put(q,new ArrayList<>());
                    }
                    ylist.get(q).add(p);
                }
            }
            Collections.sort(allx);
            Collections.sort(ally);
            for(int h:x){
                if(xlist.containsKey(h))
                    Collections.sort(xlist.get(h));
            }
            for(int h:y){
                if(ylist.containsKey(h))
                    Collections.sort(ylist.get(h));
            }
            long count = 0;
            int last = -1, c = 0;
            for(i=0;i<allx.size();i++){
                if(c<m&&allx.get(i)>y[c]){
                    

                    count += 1L*(i-1-last)*(i-last-2)/2;
                    last = i-1;
                    int l = 0, r = m-1;
                    int ans = m;
                    while(l<=r){
                        int mid = (l+r)/2;
                        if(y[mid]<allx.get(i)){
                            l = mid + 1;
                        }
                        else{
                            ans = mid;
                            r = mid - 1;
                        }
                    }
                    c = ans;
                    i--;
                }
            }
            count += 1L*(allx.size()-1-last)*(allx.size()-last-2)/2;
            

            c = 0;
            last = -1;
            for(i=0;i<ally.size();i++){
                if(c<n&&ally.get(i)>x[c]){
                    

                    count += 1L*(i-1-last)*(i-last-2)/2;
                    last = i-1;
                    int l = 0, r = n-1;
                    int ans = n;
                    while(l<=r){
                        int mid = (l+r)/2;
                        if(x[mid]<ally.get(i)){
                            l = mid + 1;
                        }
                        else{
                            ans = mid;
                            r = mid - 1;
                        }
                    }
                    c = ans;
                    i--;
                }
            }
            

            count += 1L*(ally.size()-1-last)*(ally.size()-last-2)/2;
            

            

            

            

            

            

            

            

            

            

            

            for(int h:x){
                if(xlist.containsKey(h)){
                    ArrayList<Integer> part = xlist.get(h);
                    last = -1;
                    c = 0;
                    for(i=0;i<part.size();i++){
                        if(c<m&&part.get(i)>y[c]){
                            

                            count -= 1L*(i-1-last)*(i-last-2)/2;
                            last = i-1;
                            int l = 0, r = m-1;
                            int ans = m;
                            while(l<=r){
                                int mid = (l+r)/2;
                                if(y[mid]<part.get(i)){
                                    l = mid + 1;
                                }
                                else{
                                    ans = mid;
                                    r = mid - 1;
                                }
                            }
                            c = ans;
                            i--;
                        }
                    }
                    count -= 1L*(part.size()-1-last)*(part.size()-last-2)/2;
                }
            }
            for(int h:y){
                if(ylist.containsKey(h)){
                    ArrayList<Integer> part = ylist.get(h);
                    last = -1;
                    c = 0;
                    for(i=0;i<part.size();i++){
                        if(c<n&&part.get(i)>x[c]){
                            

                            count -= 1L*(i-1-last)*(i-last-2)/2;
                            last = i-1;
                            int l = 0, r = n-1;
                            int ans = n;
                            while(l<=r){
                                int mid = (l+r)/2;
                                if(x[mid]<part.get(i)){
                                    l = mid + 1;
                                }
                                else{
                                    ans = mid;
                                    r = mid - 1;
                                }
                            }
                            c = ans;
                            i--;
                        }
                    }
                    

                    count -= 1L*(part.size()-1-last)*(part.size()-last-2)/2;
                }
            }
            pw.println(count);
        }
    }

    static void KMPSearch(char pat[], char txt[], int pres[]){
        int M = pat.length;
        int N = txt.length;
        int lps[] = new int[M];
        int j = 0; 
        computeLPSArray(pat, M, lps);
        int i = 0;
        while (i < N) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }
            if (j == M) {
                pres[i-1] = 1;
                j = lps[j - 1];
            }
            else if (i < N && pat[j] != txt[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
    }
  
    static void computeLPSArray(char pat[], int M, int lps[])
    {
        int len = 0;
        int i = 1;
        lps[0] = 0; 
        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else 
            {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = len;
                    i++;
                }
            }
        }
    }

    static long[][] matrixMult(long a[][], long b[][], long mod){
        int n = a.length;
        int m = a[0].length;
        int p = b[0].length;
        long c[][] = new long[n][p];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<p;k++){
                    c[i][k] += a[i][j]*b[j][k];
                    c[i][k] %= mod;
                }
            }
        }
        return c;
    }

    static long[][] exp(long mat[][], long b, long mod){
        if(b==0){
            int n = mat.length;
            long res[][] = new long[n][n];
            for(int i=0;i<n;i++){
                res[i][i] = 1;
            }
            return res;
        }
        long half[][] = exp(mat, b/2, mod);
        long res[][] = matrixMult(half, half, mod);
        if(b%2==1){
            res = matrixMult(res, mat, mod);
        }
        return res;
    }

    static void countPrimeFactors(int num, int a[], HashMap<Integer,Integer> pos){
        for(int i=2;i*i<num;i++){
            if(num%i==0){
                int y = pos.get(i);
                while(num%i==0){
                    a[y]++;
                    num/=i;
                }
            }
        }
        if(num>1){
            int y = pos.get(num);
            a[y]++;
        }
    }

    static void assignAnc(ArrayList<Integer> ar[], int depth[], int sz[], int par[][] ,int curr, int parent, int d){
        depth[curr] = d;
        sz[curr] = 1;
        par[curr][0] = parent;
        for(int v:ar[curr]){
            if(parent==v)
                continue;
            assignAnc(ar, depth, sz, par, v, curr, d+1);
            sz[curr] += sz[v];
        }
    }

    static int findLCA(int a, int b, int par[][], int depth[]){
        if(depth[a]>depth[b]){
            a = a^b;
            b = a^b;
            a = a^b;
        }
        int diff = depth[b] - depth[a];
        for(int i=19;i>=0;i--){
            if((diff&(1<<i))>0){
                b = par[b][i];
            }
        }
        if(a==b)
            return a;
        for(int i=19;i>=0;i--){
            if(par[b][i]!=par[a][i]){
                b = par[b][i];
                a = par[a][i];
            }
        }
        return par[a][0];
    }

    static void formArrayForBinaryLifting(int n, int par[][]){
        for(int j=1;j<20;j++){
            for(int i=0;i<n;i++){
                if(par[i][j-1]==-1)
                    continue;
                par[i][j] = par[par[i][j-1]][j-1];
            }
        }
    }

    static long lcm(int a, int b){
        return a*b/gcd(a,b);
    }

    static class Pair1 {
        long a;
        long b;
        
        Pair1(long a, long b) {
            this.a = a;
            this.b = b;
        }
    }

    static class Pair implements Comparable<Pair> {
        int a;
        int b;
        

        
        Pair(int a, int b) {
            this.a = a;
            this.b = b;
            

        }
 
        public int compareTo(Pair p) {
            

            return a-p.a;
            

        }
    }

    static class Pair2 implements Comparable<Pair2> {
        int a;
        int b;
        int c;
        
        Pair2(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
 
        public int compareTo(Pair2 p) {
            return a-p.a;
        }
    }

    static boolean isPrime(int n) { 
        if (n <= 1) 
            return false; 
        if (n <= 3) 
            return true; 
        if (n % 2 == 0 ||  n % 3 == 0) 
            return false; 
        for (int i = 5; i * i <= n; i = i + 6) 
            if (n % i == 0 || n % (i + 2) == 0) 
                return false; 
        return true; 
    } 

    static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    static long fast_pow(long base, long n, long M) {
        if (n == 0)
            return 1;
        if (n == 1)
            return base % M;
        long halfn = fast_pow(base, n / 2, M);
        if (n % 2 == 0)
            return (halfn * halfn) % M;
        else
            return (((halfn * halfn) % M) * base) % M;
    }

    static long modInverse(long n, long M) {
        return fast_pow(n, M - 2, M);
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 9992768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }
}