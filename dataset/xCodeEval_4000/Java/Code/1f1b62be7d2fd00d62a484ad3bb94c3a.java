import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.lang.reflect.Array;
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

    static class SegTree {
        
        long tree[];
        long lz[];
        long r;
        
        long combine(long a, long b){
            return Math.min(a,b);
        }
    
        void build(long a[], int v, int tl, int tr) {
            if (tl == tr) {
                tree[v] = a[tl];
            } 
            else {
                int tm = (tl + tr) / 2;
                build(a, v*2, tl, tm);
                build(a, v*2+1, tm+1, tr);
                tree[v] = combine(tree[2*v], tree[2*v+1]);
            }
        }
    
        void pointUpdate(int v, int tl, int tr, int pos, long val) {
            if(tl>pos||tr<pos)
                return;
            if(tl==pos&&tr==pos){
                tree[v] = val;
                return;
            }
            int tm = ((tl + tr) >> 1);
            pointUpdate(v*2, tl, tm, pos, val);
            pointUpdate(v*2+1, tm+1, tr, pos, val);
            tree[v] = combine(tree[2*v],tree[2*v+1]);
        }
    
        

        

        

        

        

        

        

        

        

        

        

    
        

        

        

        

        

        

        

        

        

        

        

        

        

        


        long get(int v, int tl, int tr, int l, int r, long val) {
            if(l>tr||r<tl||tree[v]>val){
                return 0;
            }
            if (tl == tr) {
                tree[v] = Integer.MAX_VALUE;
                return 1;
            }
            int tm = ((tl + tr) >> 1);
            long al = get(2*v, tl, tm, l, r, val);
            long ar = get(2*v+1, tm+1, tr, l, r, val);
            tree[v] = combine(tree[2*v],tree[2*v+1]);
            return al+ar;
        }

    }

    static class BIT{
        int n;
        long tree[];
        long operate(long el, long val){
            return el+val;
        }
        void update(int x, long val){
            for(;x<n;x+=(x&(-x))){
                tree[x] = operate(tree[x], val);
            }
        }
        long get(int x){
            long sum = 0;
            for(;x>0;x-=(x&(-x))){
                sum = operate(sum, tree[x]);
            }
            return sum;
        }
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
        rank[v] = 1;
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
            

            

            rank[a] += rank[b];
            max1 = Math.max(max1,rank[a]);
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
        rank1[v] = 1;
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
            

            

            rank1[a] += rank1[b];
        }
    }

    static long max1 = 0;

    static int count = 0;
    static int count1 = 0;

    static boolean possible;

    public static void solve(InputReader sc, PrintWriter pw){
        int i, j = 0;
        long mod = 998244353;
        

        

        

        

        

        

        

        

        int t = sc.nextInt();
        u: while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int a[] = new int[n];
            HashMap<Integer,Integer> count = new HashMap<>();
            HashMap<Integer,HashSet<Integer>> map  = new HashMap<>();
            

            for(i=0;i<n;i++){
                a[i] = sc.nextInt();
                map.put(a[i], new HashSet<>());
                count.put(a[i], count.getOrDefault(a[i], 0)+1);
            }
            
            for(i=0;i<m;i++){
                int x = sc.nextInt();
                int y = sc.nextInt();
                map.get(x).add(y);
                map.get(y).add(x);
            }
            HashMap<Integer,ArrayList<Integer>> all = new HashMap<>();
            for(int x:count.keySet()){
                if(!all.containsKey(count.get(x))){
                    all.put(count.get(x), new ArrayList<>());
                }
                all.get(count.get(x)).add(x);
            }
            ArrayList<Integer> y = new ArrayList<>();
            for(int x:all.keySet()){
                y.add(x);
                Collections.sort(all.get(x));
            }
            Collections.sort(y);
            long max = 0;
            for(i=y.size()-1;i>=0;i--){
                for(j=i;j>=0;j--){
                    for(int k1=all.get(y.get(i)).size()-1;k1>=0;k1--){
                        for(int k2=all.get(y.get(j)).size()-1;k2>=0;k2--){
                            int xx = all.get(y.get(i)).get(k1);
                            int yy = all.get(y.get(j)).get(k2);
                            if(xx==yy)
                                continue;
                            if(map.get(xx).contains(yy)){
                                continue;
                            }
                            max = Math.max(max, 1L*(xx+yy)*(y.get(i)+y.get(j)));
                            break;
                        }
                    }
                    

                    

                }
            }
            pw.println(max);
        }
    }

    static void KMPSearch(char pat[], char txt[], long pres[]){
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

    static class CustomPair {
        long a[];
        
        CustomPair(long a[]) {
            this.a = a;
        }
    }

    static class Pair1 implements Comparable<Pair1> {
        long a;
        long b;
        
        Pair1(long a, long b) {
            this.a = a;
            this.b = b;
        }

        public int compareTo(Pair1 p) {
            if(a!=p.a)
                return (a<p.a?-1:1);
            return (b<p.b?-1:1);
        }
    }

    static class Pair implements Comparable<Pair> {
        int a;
        int b;
        int c;
        
        Pair(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
 
        public int compareTo(Pair p) {
            if(b!=p.b)
                return (b-p.b);
            return (a-p.a);
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