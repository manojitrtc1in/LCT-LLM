

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import java.util.*;
import java.io.*;
import java.math.*;

















public class F{

    static int mod = (int) (Math.pow(10, 9)+7);
    static final int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
    static final int[] dx8 = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy8 = { -1, 0, 1, -1, 1, -1, 0, 1 };
    static final int[] dx9 = { -1, -1, -1, 0, 0, 0, 1, 1, 1 }, dy9 = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

    static final double eps = 1e-10;
    static List<Integer> primeNumbers = new ArrayList<>();
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();  

        out = new PrintWriter(new BufferedOutputStream(System.out));  


        

        int test = sc.nextInt();
        while(test --> 0){
            char[] inp = sc.nextLine().toCharArray();
            int w = sc.nextInt();
            int m = sc.nextInt();

            

            int n = inp.length;
            int[] psum = new int[n + 1];
            for(int i = 0; i < n; i++){
                psum[i + 1] = psum[i] + (inp[i] - '0');
            }

            

            

            ArrayList<ArrayList<Integer>> remPos = new ArrayList<>();
            for(int i = 0; i < 9; i++){
                remPos.add(new ArrayList<>());
            }

            for(int i = 0; i < n - w + 1; i++){
                int sum = psum[i + w] - psum[i];
                int rem = sum % 9;
                remPos.get(rem).add(i);
            }








            

            for(int i= 0; i < m; i++){
                int l = sc.nextInt();
                int r = sc.nextInt();
                int k = sc.nextInt();



                int csum = psum[r] - psum[l - 1];
                int rem = csum % 9;

                

                int L1 = -1;
                int L2 = -1;

                for(int j = 0; j < 9; j++){
                    

                    int req = ((k - (j * rem)) + 90)%9;
                    if(j == req){
                        if(remPos.get(j).size() < 2) continue;
                        if(L1 == -1 || remPos.get(j).get(0) < L1){
                            L1 = remPos.get(j).get(0);
                            L2 = remPos.get(j).get(1);
                        }
                    }else{
                        if(remPos.get(j).size() < 1 || remPos.get(req).size() < 1) continue;
                        if(L1 == -1 || remPos.get(j).get(0) < L1){
                            L1 = remPos.get(j).get(0);
                            L2 = remPos.get(req).get(0);
                        }
                    }
                }



                if(L1 != -1)
                    out.println((L1 + 1) + " " + (L2 + 1));
                else
                    out.println((L1) + " " + (L2 ));
            }

        }

        out.close();
    }

    

    

    

    

    

    

    

    


    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    


    

    

    

    

    


    

    public static class Graph{
        public int V;
        public ArrayList<ArrayList<Integer>> edges;

        

        Graph(int V){
            this.V  = V;
            edges = new ArrayList<>(V+1);
            for(int i= 0; i <= V; i++){
                edges.add(new ArrayList<>());
            }
        }

        public void addEdge(int from , int to){
            edges.get(from).add(to);
            edges.get(to).add(from);
        }
    }

    

    public static class id0 {
        int[] rank, parent;
        int n;

        public id0(int n)
        {
            rank = new int[n];
            parent = new int[n];
            Arrays.fill(rank, 1);
            Arrays.fill(parent,-1);
            this.n = n;
        }

        public int find(int curr){
            if(parent[curr] == -1)
                return curr;

            

            return parent[curr] = find(parent[curr]);
        }

        public void union(int a, int b){
            int s1 = find(a);
            int s2 = find(b);

            if(s1 != s2){
                

                if(rank[s1] < rank[s2]){
                    parent[s1] = s2;
                    rank[s2] += rank[s1];
                }else{
                    parent[s2] = s1;
                    rank[s1] += rank[s2];
                }
            }
        }
    }

    

    public static long powerMOD(long x, long y)
    {
        long res = 1L;
        while (y > 0)
        {
            

            if ((y & 1) != 0){
                x %= mod;
                res %= mod;
                res = (res * x)%mod;
            }
            

            y = y >> 1; 

            x%= mod;
            x = (x * x)%mod;  

        }
        return res%mod;
    }

    

    public static long power(long x, long y)
    {
        long res = 1L;
        while (y > 0)
        {
            

            if ((y & 1) != 0){
                res = (res * x);
            }
            

            y = y >> 1; 

            x = (x * x);
        }
        return res;
    }

    public static class segmentTree{

        

        public long[] arr;
        public long[] tree;

        

        

        

        

        


        

        public segmentTree(long[] arr){
            int n = arr.length;
            this.arr = new long[n];
            for(int i= 0; i < n; i++){
                this.arr[i] = arr[i];
            }

            tree = new long[4*n + 1];
        }

        

        

        

        public void buildTree(int s, int e, int index){
            if(s == e){
                tree[index] = arr[s];
                return;
            }

            

            int mid = (s + e)/2;
            buildTree(s, mid, 2 * index);
            buildTree(mid + 1, e, 2*index + 1);

            

            tree[index] = min(tree[2 * index], tree[2 * index + 1]);
            return;
        }

        

        

        

        public long query(int s, int e, int qs , int qe, int index){
            

            if(s >= qs && e <= qe){
                return tree[index];
            }

            

            if(qe < s || qs > e){
                return Long.MAX_VALUE;
            }

            

            int mid = (s + e)/2;
            long left = query( s, mid , qs, qe, 2*index);
            long right = query( mid + 1, e, qs, qe, 2*index + 1);

            return min(left, right);
        }



        

        

        public void updateRange(int s, int e, int l, int r, long increment, int index){

            

            if(l > e || r < s){
                return;
            }

            

            if(s == e){
                tree[index] += increment;
                return;  

            }

            

            int mid = (s + e)/2;
            updateRange(s, mid, l, r, increment, 2 * index);
            updateRange(mid + 1, e, l, r, increment, 2 * index + 1);

            tree[index] = min(tree[2 * index], tree[2 * index + 1]);
        }

    }

    public static class id5{

        

        public long[] arr;
        public long[] tree;
        public long[] lazy;

        

        

        

        


        

        public id5(long[] arr){
            int n = arr.length;
            this.arr = new long[n];
            for(int i= 0; i < n; i++){
                this.arr[i] = arr[i];
            }

            tree = new long[4*n + 1];
            lazy = new long[1000000];  

        }

        

        

        

        public void buildTree(int s, int e, int index){
            if(s == e){
                tree[index] = arr[s];
                return;
            }

            

            int mid = (s + e)/2;
            buildTree(s, mid, 2 * index);
            buildTree(mid + 1, e, 2*index + 1);

            

            tree[index] = min(tree[2 * index], tree[2 * index + 1]);
            return;
        }

        

        

        

        public long queryLazy(int s, int e, int qs, int qe, int index){
            

            if(lazy[index] != 0){
                tree[index] += lazy[index];
                

                if(s != e){
                    lazy[2*index] += lazy[index];
                    lazy[2*index + 1] += lazy[index];
                }

                lazy[index] = 0; 

            }

            

            if(s > qe || e < qs){
                return Long.MAX_VALUE;
            }

            

            if(s >= qs && e <= qe){
                return tree[index];
            }

            

            int mid = (s + e)/2;
            long left = queryLazy(s, mid, qs, qe, 2 * index);
            long right = queryLazy(mid + 1, e, qs, qe, 2 * index + 1);

            return Math.min(left, right);
        }

        

        public void id12(int s, int e, int l, int r, int inc, int index){
            

            if(lazy[index] != 0){
                tree[index] += lazy[index];
                

                if(s != e){
                    lazy[2*index] += lazy[index];
                    lazy[2*index + 1] += lazy[index];
                }

                lazy[index] = 0; 

            }

            

            if(s > r || l > e){
                return;
            }

            

            if(l <= s && e <= r){
                tree[index] += inc;

                

                if(s != e){
                    lazy[2*index] += inc;
                    lazy[2*index + 1] += inc;
                }
                return;
            }


            

            int mid = (s + e)/2;
            id12(s, mid, l, r, inc, 2*index);
            id12(mid + 1, e, l, r, inc, 2*index + 1);

            

            tree[index] = Math.min(tree[2*index], tree[2*index + 1]);
            return;
        }

    }

    

    public static void id1(int n){
        BitSet bitset = new BitSet(n+1);
        for(long i = 0; i < n ; i++){
            if (i == 0 || i == 1) {
                bitset.set((int) i);
                continue;
            }
            if(bitset.get((int) i)) continue;
            primeNumbers.add((int)i);
            for(long j = i; j <= n ; j+= i)
                bitset.set((int)j);
        }
    }

    

    public static int id4(long number){
        if(number == 1) return 1;
        List<Integer> primeFactors = new ArrayList<>();
        int index = 0;
        long curr = primeNumbers.get(index);
        while(curr * curr <= number){
            while(number % curr == 0){
                number = number/curr;
                primeFactors.add((int) curr);
            }
            index++;
            curr = primeNumbers.get(index);
        }

        if(number != 1) primeFactors.add((int) number);
        int current = primeFactors.get(0);
        int id9 = 1;
        int currentCount = 2;
        for (int i = 1; i < primeFactors.size(); i++) {
            if (primeFactors.get(i) == current) {
                currentCount++;
            } else {
                id9 *= currentCount;
                currentCount = 2;
                current = primeFactors.get(i);
            }
        }
        id9 *= currentCount;
        return id9;
    }

    

    public static int id11(int n) {
        if (n <= 1)
            return 0;
        int sqrt = (int) Math.sqrt(n);
        int remainingNumber = n;
        int result = 0;
        for (int i = 2; i <= sqrt; i++) {
            while (remainingNumber % i == 0) {
                result++;
                remainingNumber /= i;
            }
        }
        

        if (remainingNumber > 1) {
            result++;
        }
        return result;
    }


    

    public static boolean id7(int[] p) {
        for (int a = p.length - 2; a >= 0; --a)
            if (p[a] < p[a + 1])
                for (int b = p.length - 1;; --b)
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        return false;
    }

    

    public static long id6(int n, int r)
    {
        long p = 1, k = 1;
        if (n - r < r) r = n - r;

        if (r != 0) {
            while (r > 0) {
                p *= n;
                k *= r;
                long m = id10(p, k);
                p /= m;
                k /= m;
                n--;
                r--;
            }
        }
        else {
            p = 1;
        }
        return p;
    }

    

    public static boolean id3(char c)
    {
        return (c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' ||     c=='u' || c=='U');
    }

    

    public static void sort(int[] a) {
        ArrayList<Integer> l=new ArrayList<>();
        for (int i:a) l.add(i);
        Collections.sort(l);
        for (int i=0; i<a.length; i++) a[i]=l.get(i);
    }

    

    public static void sort(long[] a) {
        ArrayList<Long> l=new ArrayList<>();
        for (long i:a) l.add(i);
        Collections.sort(l);
        for (int i=0; i<a.length; i++) a[i]=l.get(i);
    }

    

    public static int id8(int n, int k)
    {
        int C[] = new int[k + 1];
        

        C[0] = 1;
        for (int i = 1; i <= n; i++) {
            

            

            for (int j = Math.min(i, k); j > 0; j--)
                C[j] = C[j] + C[j - 1];
        }
        return C[k];
    }

    

    public static class Pair{
        public int a;
        public int b;
        public int hashCode;

        Pair(int a , int b){
            this.a = a;
            this.b = b;
            this.hashCode = Objects.hash(a, b);
        }

        @Override
        public String toString(){
            return a + " -> " + b;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair that = (Pair) o;
            return a == that.a && b == that.b;
        }

        @Override
        public int hashCode() {
            return this.hashCode;
        }
    }

    

    public static class Triplet{

        public int a;
        public int b;
        public int c;

        Triplet(int a , int b, int c){
            this.a = a;
            this.b = b;
            this.c = c;
        }

        @Override
        public String toString(){
            return a + " -> " + b;
        }
    }

    

    public static long lcm(long a , long b){
        return a * (b/gcd(a,b));
    }

    

    public static int lcm(int a , int b){
        return (a * b)/gcd(a,b);
    }

    

    public static int gcd(int a, int b){
        if(b == 0)
            return a;

        return gcd(b , a%b);
    }

    

    public static long gcd(long a, long b){
        if(b == 0)
            return a;

        return gcd(b , a%b);
    }

    

    public static long id10(long n1, long n2)
    {
        long gcd = 1;
        for (int i = 1; i <= n1 && i <= n2; ++i) {
            

            if (n1 % i == 0 && n2 % i == 0) {
                gcd = i;
            }
        }
        return gcd;
    }

    

    public static void swap(int[] arr, int left , int right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

    

    public static void swap(char[] arr, int left , int right){
        char temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

    

    public static void reverse(int[] arr){
        int left = 0;
        int right = arr.length-1;

        while(left <= right){
            swap(arr, left,right);
            left++;
            right--;
        }
    }


    public static long expo(long a, long b, long mod) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1L) res = (res * a) % mod;  

            a = (a * a) % mod;
            b = b >> 1;
        }
        return res;
    }

    

    public static long id2(long a, long b) {
        return expo(a, b - 2, b);
    }

    public static long mod_add(long a, long b, long m) {
        a = a % m;
        b = b % m;
        return (((a + b) % m) + m) % m;
    }

    public static long mod_sub(long a, long b, long m) {
        a = a % m;
        b = b % m;
        return (((a - b) % m) + m) % m;
    }

    public static long mod_mul(long a, long b, long m) {
        a = a % m;
        b = b % m;
        return (((a * b) % m) + m) % m;
    }

    public static long mod_div(long a, long b, long m) {
        a = a % m;
        b = b % m;
        return (mod_mul(a, id2(b, m), m) + m) % m;
    }

    

    public static long nCr(long N, long K , long mod){
        long upper = 1L;
        long lower = 1L;
        long lowerr = 1L;

        for(long i = 1; i <= N; i++){
            upper = mod_mul(upper, i, mod);
        }

        for(long i = 1; i <= K; i++){
            lower = mod_mul(lower, i, mod);
        }

        for(long i = 1; i <= (N - K); i++){
            lowerr = mod_mul(lowerr, i, mod);
        }

        

        long answer = mod_mul(lower, lowerr, mod);
        answer = mod_div(upper, answer, mod);

        return answer;
    }

    

    

    

    

    

    

    

    

    

    

    public static long combination(long n, long r, long m, long[] fact, long[] ifact) {
        long val1 = fact[(int)n];
        long val2 = ifact[(int)(n - r)];
        long val3 = ifact[(int)r];
        return (((val1 * val2) % m) * val3) % m;
    }




    

    public static PrintWriter out;

    

    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
    

}