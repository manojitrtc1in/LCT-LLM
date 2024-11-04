import java.util.*;


import java.io.*;

public class Solution {
    static long[] fac;

    static int m = (int)1e9+7;
    static int c = 1;






    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));






















        int te = 1;

        while(te-->0) {
            int n = Reader.nextInt();
            int m = Reader.nextInt();

            String s = Reader.next();
            int l = s.length();
            int[] abc,acb,bac,bca,cab,cba;
            abc = new int[l];
            acb = new int[l];
            bac = new int[l];
            bca = new int[l];
            cab = new int[l];
            cba = new int[l];

            

            for(int i = 0;i<l;i++){
                if(s.charAt(i)!='a'){
                    abc[i] = 1 + (i>0 ? abc[i-1] : 0);
                }
                else abc[i] = (i>0 ? abc[i-1] : 0);
                i++;
                if(i<l){
                    if(s.charAt(i)!='b'){
                        abc[i] = 1 + abc[i-1];
                    }
                    else abc[i] = abc[i-1];
                }
                i++;
                if(i<l){
                    if(s.charAt(i)!='c'){
                        abc[i] = 1 + abc[i-1];
                    }
                    else abc[i] = abc[i-1];
                }
            }

            

            for(int i = 0;i<l;i++){
                if(s.charAt(i)!='a'){
                    acb[i] = 1 + (i>0 ? acb[i-1] : 0);
                }
                else acb[i] = (i>0 ? acb[i-1] : 0);
                i++;
                if(i<l){
                    if(s.charAt(i)!='c'){
                        acb[i] = 1 + acb[i-1];
                    }
                    else acb[i] = acb[i-1];
                }
                i++;
                if(i<l){
                    if(s.charAt(i)!='b'){
                        acb[i] = 1 + acb[i-1];
                    }
                    else acb[i] = acb[i-1];
                }
            }
            

            for(int i = 0;i<l;i++){
                if(s.charAt(i)!='b'){
                    bac[i] = 1 + (i>0 ? bac[i-1] : 0);
                }
                else bac[i] = (i>0 ? bac[i-1] : 0);
                i++;
                if(i<l){
                    if(s.charAt(i)!='a'){
                        bac[i] = 1 + bac[i-1];
                    }
                    else bac[i] = bac[i-1];
                }
                i++;
                if(i<l){
                    if(s.charAt(i)!='c'){
                        bac[i] = 1 + bac[i-1];
                    }
                    else bac[i] = bac[i-1];
                }
            }
            

            for(int i = 0;i<l;i++){
                if(s.charAt(i)!='b'){
                    bca[i] = 1 + (i>0 ? bca[i-1] : 0);
                }
                else bca[i] = (i>0 ? bca[i-1] : 0);
                i++;
                if(i<l){
                    if(s.charAt(i)!='c'){
                        bca[i] = 1 + bca[i-1];
                    }
                    else bca[i] = bca[i-1];
                }
                i++;
                if(i<l){
                    if(s.charAt(i)!='a'){
                        bca[i] = 1 + bca[i-1];
                    }
                    else bca[i] = bca[i-1];
                }
            }
            

            for(int i = 0;i<l;i++){
                if(s.charAt(i)!='c'){
                    cab[i] = 1 + (i>0 ? cab[i-1] : 0);
                }
                else cab[i] = (i>0 ? cab[i-1] : 0);
                i++;
                if(i<l){
                    if(s.charAt(i)!='a'){
                        cab[i] = 1 + cab[i-1];
                    }
                    else cab[i] = cab[i-1];
                }
                i++;
                if(i<l){
                    if(s.charAt(i)!='b'){
                        cab[i] = 1 + cab[i-1];
                    }
                    else cab[i] = cab[i-1];
                }
            }
            

            for(int i = 0;i<l;i++){
                if(s.charAt(i)!='c'){
                    cba[i] = 1 + (i>0 ? cba[i-1] : 0);
                }
                else cba[i] = (i>0 ? cba[i-1] : 0);
                i++;
                if(i<l){
                    if(s.charAt(i)!='b'){
                        cba[i] = 1 + cba[i-1];
                    }
                    else cba[i] = cba[i-1];
                }
                i++;
                if(i<l){
                    if(s.charAt(i)!='a'){
                        cba[i] = 1 + cba[i-1];
                    }
                    else cba[i] = cba[i-1];
                }
            }


            for(int i = 0;i<m;i++){
                int st = Reader.nextInt()-1;
                int en = Reader.nextInt()-1;

                int min = Integer.MAX_VALUE;
                min = Math.min(min,abc[en]-(st>0 ? abc[st-1] : 0));
                min = Math.min(min,acb[en]-(st>0 ? acb[st-1] : 0));
                min = Math.min(min,bac[en]-(st>0 ? bac[st-1] : 0));
                min = Math.min(min,bca[en]-(st>0 ? bca[st-1] : 0));
                min = Math.min(min,cab[en]-(st>0 ? cab[st-1] : 0));
                min = Math.min(min,cba[en]-(st>0 ? cba[st-1] : 0));

                output.write(min+"\n");
            }

        }

        output.close();
    }


    

    static long modexp(long x, long n)
    {
        if (n == 0) {
            return 1;
        }
        else if (n % 2 == 0) {
            return modexp((x * x) % m, n / 2);
        }
        else {
            return (x * modexp((x * x) % m, (n - 1) / 2) % m);
        }
    }

    

    static long id3(long a, long b)
    {
        long c = gcd(a, b);

        a = a / c;
        b = b / c;

        

        long  d = modexp(b, m - 2);

        

        long ans = ((a % m) * (d % m)) % m;

        return ans;
    }
    public static boolean isP(String n){
        StringBuilder s1 = new StringBuilder(n);
        StringBuilder s2 = new StringBuilder(n);
        s2.reverse();

        for(int i = 0;i<s1.length();i++){
            if(s1.charAt(i)!=s2.charAt(i)) return false;
        }
        return true;
    }
    public static long[] factorial(int n){
        long[] factorials = new long[n+1];
        factorials[0] = 1;
        factorials[1] = 1;
        for(int i = 2;i<=n;i++){
            factorials[i] = (factorials[i-1]*i)%1000000007;
        }
        return factorials;
    }
    public static long id7(long n){
        long ans = 0;

        while(n>0){
            n = n & (n-1);
            ans++;
        }
        return ans;
    }
    public static long id0(long x, long y){
        

        

        return (x+y-1)/y;
    }
    public static long power(long x, long y, long p) {

        long res = 1;

        x = x % p;

        while (y > 0) {
            if (y % 2 == 1) res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    

    public static long modInverse(long n, long p) {
        return power(n, p - 2, p);
    }

    

    

    public static long id10(int n, int r, int p) {

        if (n<r) return 0;
        if (r == 0) return 1;

        

        

        



        return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
    }
    public static long ncr(long n, long r) {

        long p = 1, k = 1;

        if (n - r < r) {
            r = n - r;
        }

        if (r != 0) {
            while (r > 0) {
                p *= n;
                k *= r;

                long m = gcd(p, k);

                p /= m;
                k /= m;

                n--;
                r--;
            }

        } else {
            p = 1;
        }
        return p;
    }
    public static boolean isPrime(long n){
        if (n <= 1) return false;
        if (n <= 3) return true;

        if (n % 2 == 0 || n % 3 == 0) return false;

        for (int i = 5; (long) i * i <= n; i = i + 6){
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    public static int id1(int n) {
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;

        return n ^ (n >> 1);
    }

    public static long merge(int[] arr, int[] aux, int low, int mid, int high)
    {
        int k = low, i = low, j = mid + 1;
        long id5 = 0;

        

        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j]) {
                aux[k++] = arr[i++];
            }
            else {
                aux[k++] = arr[j++];
                id5 += (mid - i + 1);    

            }
        }

        

        while (i <= mid) {
            aux[k++] = arr[i++];
        }

        

        

        for (i = low; i <= high; i++) {
            arr[i] = aux[i];
        }

        return id5;
    }


    public static long id8(int[] arr, int[] aux, int low, int high)
    {

        if (high <= low) {        

            return 0;
        }

        int mid = (low + ((high - low) >> 1));
        long id5 = 0;

        

        


        

        id5 += id8(arr, aux, low, mid);

        

        id5 += id8(arr, aux, mid + 1, high);

        

        id5 += merge(arr, aux, low, mid, high);

        return id5;
    }

    public static void reverseArray(int[] arr,int start, int end) {
        int temp;

        while (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    public static long gcd(long a, long b){
        if(a==0){
            return b;
        }

        return gcd(b%a,a);
    }

    public static long lcm(long a, long b){
        if(a>b) return a/gcd(b,a) * b;
        return b/gcd(a,b) * a;
    }

    public static long id9(long x,long y,long mod){
        

        x%=mod;
        long ans = 1;
        while(y>0){
            if((y&1)==1){
                ans = (ans*x)%mod;
            }
            x = (x*x)%mod;
            y = y >> 1;
        }
        return ans;
    }

    public static boolean[] id2(long L, long R){
        boolean[] isPrime = new boolean[(int) (R-L+1)];
        Arrays.fill(isPrime,true);
        long lim = (long) Math.sqrt(R);
        for (long i = 2; i <= lim; i++){
            for (long j = Math.max(i * i, (L + i - 1) / i * i); j <= R; j += i){
                isPrime[(int) (j - L)] = false;
            }
        }
        if (L == 1) isPrime[0] = false;
        return isPrime;
    }

    public static ArrayList<Long> primeFactors(long n){
        ArrayList<Long> factorization = new ArrayList<>();
        if(n%2==0){
            factorization.add(2L);
        }
        while(n%2==0){
            n/=2;
        }
        if(n%3==0){
            factorization.add(3L);
        }
        while(n%3==0){
            n/=3;
        }
        if(n%5==0){
            factorization.add(5L);
        }
        while(n%5==0){


            n/=5;
        }

        int[] increments = {4, 2, 4, 2, 4, 6, 2, 6};
        int i = 0;
        for (long d = 7; d * d <= n; d += increments[i++]) {
            if(n%d==0){
                factorization.add(d);
            }
            while (n % d == 0) {


                n /= d;
            }
            if (i == 8)
                i = 0;
        }
        if (n > 1)
            factorization.add(n);
        return factorization;
    }
}

class DSU {
    int[] size, parent;
    int n;

    public DSU(int n){
        this.n = n;
        size = new int[n];
        parent = new int[n];

        for(int i = 0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    public int find(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    public void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u!=v){
            if(size[u]>size[v]){
                parent[v] = u;
                size[u] += size[v];
            }
            else{
                parent[u] = v;
                size[v] += size[u];
            }
        }
    }
}

class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    
    static void init(InputStream input) {
        reader = new BufferedReader(
                new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    
    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            

            tokenizer = new StringTokenizer(
                    reader.readLine() );
        }
        return tokenizer.nextToken();
    }
    static String nextLine() throws IOException {
        return reader.readLine();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }
    static long nextLong() throws IOException{
        return Long.parseLong(next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }
}

class SegTree{
    int n; 


    

    public int[] tree;

    public SegTree(int n){
        this.n = n;
        tree = new int[4*n];
    }
    

    void update(int pos, int val, int s, int e, int treeIdx){
        if(pos < s || pos > e){
            return;
        }
        if(s == e){
            tree[treeIdx] = val;
            return;
        }
        int mid = s + (e - s) / 2;
        update(pos, val, s, mid, 2 * treeIdx);
        update(pos, val, mid + 1, e, 2 * treeIdx + 1);
        tree[treeIdx] = tree[2 * treeIdx] + tree[2 * treeIdx + 1];
    }

    void update(int pos, int val){
        update(pos, val, 1, n, 1);
    }

    int query(int qs, int qe, int s, int e, int treeIdx){
        if(qs <= s && qe >= e){
            return tree[treeIdx];
        }
        if(qs > e || qe < s){
            return 0;
        }
        int mid = s + (e - s) / 2;
        int id6 = query(qs, qe, s, mid, 2 * treeIdx);
        int id4 = query(qs, qe, mid + 1, e, 2 * treeIdx + 1);
        int res = id6 + id4;
        return res;
    }

    int query(int l, int r){
        return query(l, r, 1, n, 1);
    }
}