import java.util.*;
import java.lang.*;
import java.io.*;

public class Solution {
    static long[] fac;

    static int m = (int)1e9+7;
    static int[] ans;
    static int[] ans2;
    



    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        



        int te = Reader.nextInt();


        while(te-->0) {
            int n = Reader.nextInt();
            int m = Reader.nextInt();

            Integer[][] arr = new Integer[n*m][2];

            for(int i = 0;i<n*m;i++){
                arr[i][0] = Reader.nextInt();
                arr[i][1] = i;
            }
            long a = 0;
            Arrays.parallelSort(arr,(n1,n2)-> Objects.equals(n1[0], n2[0]) ? n2[1]-n1[1] : n1[0]-n2[0]);
            ans = new int[n*m];
            int l = 0, r = 0;
            for(int i = 1;i<n*m;i++){
                if(Objects.equals(arr[i][0], arr[i - 1][0])){
                    r++;
                }
                else{
                    int idx = l;
                    int[] temp = new int[r-l+1];

                    for(int j = n-1;j>=0;j--){
                        if(j*m<=r){
                            for(int k = 0;k<m;k++){
                                if(idx>r) break;
                                if(j*m+k<l) continue;
                                if(j*m+k>r) break;
                                temp[j*m+k-l] = arr[idx++][1];
                            }
                        }
                        if(idx>r) break;
                    }
                    for(int j = 0;j<=r-l;j++){
                        arr[j+l][1] = temp[j];
                    }
                    l = i;
                    r = i;
                }
            }
            int idx = l;
            int[] temp1 = new int[r-l+1];

            for(int j = n-1;j>=0;j--){
                if(j*m<=r){
                    for(int k = 0;k<m;k++){
                        if(idx>r) break;
                        if(j*m+k<l) continue;
                        if(j*m+k>r) break;
                        temp1[j*m+k-l] = arr[idx++][1];
                    }

                }
                if(idx>r) break;
            }
            for(int j = 0;j<=r-l;j++){
                arr[j+l][1] = temp1[j];
            }
            int[][] copy = new int[n*m][2];
            for(int i = 0;i<n*m;i++){
                copy[i][0] = arr[i][1];
                copy[i][1] = i;


            }














            for(int i = 0;i<n;i++){
                for(int j = 0;j<m/2;j++){
                    int temp = copy[i*m+j][0];
                    copy[i*m+j][0] = copy[i*m+m-1-j][0];
                    copy[i*m+m-1-j][0] = temp;
                }




                divide(copy,i*m,i*m+m-1);
            }


            for(int i = 0;i<n*m;i++){
                a += ans[i];
            }
            output.write(a+"\n");
        }

        output.close();
    }

    public static void divide(int[][] arr, int l, int r){
        if(l<r){
            int mid = l + (r-l)/2;
            divide(arr,mid+1,r);
            divide(arr,l,mid);
            conquer(arr,l,mid,r);
        }
    }

    public static void conquer(int[][] arr, int l, int mid, int r){
        int[][] left = new int[mid-l+1][2];

        

        

        for(int i = 0 ;i<left.length;i++){
            left[i][0] = arr[i+l][0];
            left[i][1] = arr[i+l][1];
            

        }
        int[][] right = new int[r-mid][2];

        

        for(int i = 0 ;i<right.length;i++){
            right[i][0] = arr[mid+1+i][0];
            right[i][1] = arr[mid+1+i][1];
            

        }
        int le = l;

        int i = 0, j = 0;
        int lSize = left.length, rSize = right.length;
        int greater = 0;
        while(i<lSize && j<rSize){
            if(left[i][0]>right[j][0]){
                greater++;
                arr[le][0] = right[j][0];
                arr[le][1] = right[j][1];
                le++;
                j++;
            }
            else{
                ans[left[i][1]] += greater;
                

                arr[le][0] = left[i][0];
                arr[le][1] = left[i][1];
                le++;
                i++;

            }
        }
        while(i<lSize){
            ans[left[i][1]] += greater;
            arr[le][0] = left[i][0];
            arr[le][1] = left[i][1];
            le++;
            i++;
        }

        while(j<rSize){
            arr[le][0] = right[j][0];
            arr[le][1] = right[j][1];
            le++;
            j++;
        }
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
            factorials[i] = (factorials[i-1]*i);
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