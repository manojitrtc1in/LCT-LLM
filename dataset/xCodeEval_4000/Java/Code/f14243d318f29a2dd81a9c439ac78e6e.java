
import java.io.*;
import java.lang.reflect.Array;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;


public class Main {



    static FastReader sc;
    static StringBuilder sb = new StringBuilder();
    static int mod = (int) (Math.pow(10, 9)+7);
    static final int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
    static final int[] dx8 = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy8 = { -1, 0, 1, -1, 1, -1, 0, 1 };
    static final int[] dx9 = { -1, -1, -1, 0, 0, 0, 1, 1, 1 }, dy9 = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
    static HashSet<Character> set;
    static final double eps = 1e-10;
    static long [] arr = new long[100001];
    static List<Integer> primeNumbers = new ArrayList<>();
    public static void main(String[] args){
        sc = new FastReader();
        int testCases=1;
        

        testCases=sc.nextInt();
        while (testCases-->0) compute();
        System.out.println(sb.toString());
    }

    public static void compute() {
        

        


        

        int x=sc.nextInt();
        int k=sc.nextInt();
        int [] arr = readArray(x);
        boolean flag = false,fo=false;
        for(int i:arr){
            if(i==1){
                flag=true;
                break;
            }
            else
                fo=true;
        }

        sb.append(!(flag||(k==1&&fo))?"NO":"YES");
        sb.append("\n");
    }
    public int[] deckRevealedIncreasing(int[] deck) {
        int l=deck.length;
        int [] res = new int[l];
        int j=1;
        Arrays.sort(deck);
        for(int i=0;i<l;i++){
            if(i*2<l)
                res[2*i]=deck[i];
            else{
                res[j]=deck[i];
                j+=2;
            }
        }
        return res;
    }

    public int garbageCollection(String[] garbage, int[] travel) {
        int res=0;
        int gi=-1,mi=-1,pi=-1;
        int gl =garbage.length;
        for(int i=gl-1;i>=0;i--){
            if(garbage[i].contains("G")){
                gi=i;
                break;
            }
        }
        for(int i=gl-1;i>=0;i--){
            if(garbage[i].contains("P")){
                pi=i;
                break;
            }
        }
        for(int i=gl-1;i>=0;i--){
            if(garbage[i].contains("M")){
                mi=i;
                break;
            }
        }
        System.out.println(gi+" "+pi+" "+mi);
        for(int i=1;i<=gi;i++){
            res+=travel[i-1];
            if(garbage[i].contains("G"))
                res+=count(garbage[i],'G');
        }
        for(int i=1;i<=mi;i++){
            res+=travel[i-1];
            if(garbage[i].contains("M"))
                res+=count(garbage[i],'M');
        }
        for(int i=1;i<=pi;i++){
            res+=travel[i-1];
            if(garbage[i].contains("P"))
                res+=count(garbage[i],'P');
        }
        if(garbage[0].contains("P"))
            res+=count(garbage[0],'P');
        if(garbage[0].contains("M"))
            res+=count(garbage[0],'M');
        if(garbage[0].contains("G"))
            res+=count(garbage[0],'G');
        return res;
    }
    public int count(String s,char p){
        int res=0;
        for(char c:s.toCharArray()){
            if(c==(p))
                res++;
        }
        return res;
    }
    public int reverseInt(int n){
        StringBuffer sbr = new StringBuffer(String.valueOf(n));
        return Integer.parseInt(sbr.reverse().toString());
    }
    public boolean equalFrequency(String word) {
        int [] arr = new int[26];
        for(char c:word.toCharArray())
            arr[c-'a']++;
        HashSet<Integer> set = new HashSet<>();
        int max=-1;
        for(int i:arr){
            if(i>0)
                set.add(i);
            max=Math.max(max,i);
        }
        Integer[] inset = set.toArray(new Integer[set.size()]);
        if(set.size()!=2) return false;
        if(Math.abs(inset[0]-inset[1])!=1) return false;
        int maxcnt=0;
        for(int i:arr){
            if(i==max)
                maxcnt++;
        }
        return maxcnt==1?true:false;

    }
    public List<Boolean> prefixesDivBy5(int[] nums) {
        int l = nums.length;
        List<Boolean> ar = new ArrayList<>();
        StringBuilder res = new StringBuilder();
        for(int i:nums){
            res.append(i);
            if(Integer.parseInt(res.toString(),2)%5==0)
                ar.add(true);
            else
                ar.add(false);
        }
        return ar;
    }
    static long factorial(int i){
        long result = 1;

        for (int factor = 2; factor <= i; factor++) {
            result *= factor;
        }

        return result;
    }
    static void reverseRange(int [] arr , int start , int end){
        int [] res= new int[end-start+1];
        for(int i=start;i<end;i++)
            res[i-start]=arr[i];
        reverse(res);
        for(int i:res)
            System.out.print(i+"--");
        System.out.println("");
        for(int i=start;i<end;i++)
            arr[i]=res[i-start];
    }

    class LRU{

    }
    class Bitset {

        int [] arr;
        boolean allv;
        boolean onev;
        int cnt;
        int l;
        public Bitset(int size) {
            arr = new int[size];
            l=size;
            Arrays.fill(arr,0);
            allv=false;
            onev=false;
            cnt=0;
        }

        public void fix(int idx) {
            if(idx<=this.arr.length && arr[idx]==0){
                arr[idx]=1;
                onev=true;
                cnt++;
            }
            if(cnt==l)
                allv=true;

        }

        public void unfix(int idx) {
            if(idx<=this.arr.length && arr[idx]==1){
                arr[idx]=0;
                allv=false;
                cnt--;
            }
            if(cnt==0)
                onev=false;

        }

        public void flip() {

            for(int i=0;i<l;i++){
                if(arr[i]==0)
                    arr[i]=1;
                else
                    arr[i]=0;
            }
            cnt=l-cnt;
            if(cnt==0)
                onev=false;
            else
                onev=true;
            if(cnt==l)
                allv=true;
            else
                allv=false;
        }

        public boolean all() {

            return this.allv;
        }

        public boolean one() {

            return this.onev;
        }

        public int count() {

            return cnt;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            for(int i:arr)
                sb.append(i);
            return sb.toString();
        }
    }
    public long smallestNumber(long num) {
        long res=0;
        

        ArrayList<Long> arr = new ArrayList<>();
        long n=Math.abs(num);
        int zc=0;
        if(num==0)
            return 0;
        StringBuilder sb = new StringBuilder();
        while(n>0){
            arr.add(n%10);
            if(n%10==0)
                zc++;
            n/=10;
        }
        if(num>0){
            Collections.sort(arr);
            sb.append(arr.get(zc));
            for(int i=0;i<zc;i++)
                sb.append(0);
            for(int i=zc+1;i<arr.size();i++)
                sb.append(arr.get(i));

        }
        else{
            Collections.sort(arr,Collections.reverseOrder());
            for(int i=0;i<arr.size();i++)
                sb.append(arr.get(i));
        }
        res=Long.parseLong(sb.toString());
        if(num<0)
            res*=(-1);
        return res;
    }
    static int getDigitSum(int n){
        int t=0;
        while(n>0){
            t+=(n%10);
            n/=10;
        }
        return t;
    }
    static class Node{
        int n;
        int a;
        int s;

        public int getA() {
            return a;
        }

        public int getAvg() {
            return s;
        }

        Node(int a, int s,int n){
            this.a=a;
            this.s=s;
            this.n=n;
        }
    }



    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    


    

    

    

    

    



    static boolean isPrime(long n) {
        if(n < 2) return false;
        if(n == 2 || n == 3) return true;
        if(n%2 == 0 || n%3 == 0) return false;
        long sqrtN = (long)Math.sqrt(n)+1;
        for(long i = 6L; i <= sqrtN; i += 6) {
            if(n%(i-1) == 0 || n%(i+1) == 0) return false;
        }
        return true;
    }
    static boolean isPalindrome(String str)
    {
        int i = 0, j = str.length() - 1;
        while (i < j) {
            if (str.charAt(i) != str.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
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
        }
    }

    

    public static class DisjointUnionSets {
        int[] rank, parent;
        int n;

        public DisjointUnionSets(int n)
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
        public long[] lazy;

        segmentTree(long[] array){
            int n = array.length;
            arr = new long[n];
            for(int i= 0; i < n; i++) arr[i] = array[i];
            tree = new long[4*n + 1];
            lazy = new long[4*n + 1];
        }

        public  void build(int[]arr, int s, int e, int[] tree, int index){

            if(s == e){
                tree[index] = arr[s];
                return;
            }

            

            int mid = (s+e)/2;
            build(arr, s, mid, tree, 2*index);
            build(arr, mid+1, e, tree, 2*index+1);

            

            tree[index] = Math.min(tree[2*index], tree[2*index+1]);
        }

        public  int query(int sr, int er, int sc, int ec, int index, int[] tree){

            if(lazy[index] != 0){
                tree[index] += lazy[index];

                if(sc != ec){
                    lazy[2*index+1] += lazy[index];
                    lazy[2*index] += lazy[index];
                }

                lazy[index] = 0;
            }

            

            if(sr > ec || sc > er) return Integer.MAX_VALUE;

            

            if(sr <= sc && ec <= er) return tree[index];

            

            int mid = (sc + ec)/2;
            int left = query(sr, er, sc, mid, 2*index, tree);
            int right = query(sr, er, mid+1, ec, 2*index + 1, tree);

            return Integer.min(left, right);
        }

        

        

        public  void update(int index, int indexr, int increment, int[] tree, int s, int e){

            if(lazy[index] != 0){
                tree[index] += lazy[index];

                if(s != e){
                    lazy[2*index+1] = lazy[index];
                    lazy[2*index] = lazy[index];
                }

                lazy[index] = 0;
            }

            

            if(indexr < s || indexr > e) return;

            

            if(s == e){
                tree[index] += increment;
                return;
            }

            

            int mid = (s+e)/2;
            update(2*index, indexr, increment, tree, s, mid);
            update(2*index+1, indexr, increment, tree, mid+1, e);

            

            tree[index] = Math.min(tree[2*index+1], tree[2*index]);
        }

        public  void rangeUpdate(int[] tree , int index, int s, int e, int sr, int er, int increment){

            

            if(e < sr || er < s) return;

            

            if(s == e){
                tree[index] += increment;
                return;
            }

            

            int mid = (s+e)/2;
            rangeUpdate(tree, 2*index, s, mid, sr, er, increment);
            rangeUpdate(tree, 2*index + 1, mid+1, e, sr, er, increment);

            

            

            tree[index] = Math.min(tree[2*index], tree[2*index + 1]);
        }

        public  void rangeUpdateLazy(int[] tree, int index, int s, int e, int sr, int er, int increment){

            

            

            if(lazy[index] != 0){
                tree[index] += lazy[index];

                if(s != e){
                    lazy[2*index+1] += lazy[index];
                    lazy[2*index] += lazy[index];
                }

                lazy[index] = 0;
            }

            

            if(sr > e || s > er) return;

            

            if(sr <= s && er >= e){
                tree[index] += increment;

                if(s != e){
                    lazy[2*index+1] += increment;
                    lazy[2*index] += increment;
                }
                return;
            }

            

            int mid = (s + e)/2;
            rangeUpdateLazy(tree, 2*index, s, mid, sr, er, increment);
            rangeUpdateLazy(tree, 2*index + 1, mid+1, e, sr, er, increment);

            tree[index] = Math.min(tree[2*index+1], tree[2*index]);
            return;

        }

    }

    

    static int ceil(int x, int y) {
        return (x % y == 0 ? x / y : (x / y + 1));
    }

    

    static long ceil(long x, long y) {
        return (x % y == 0 ? x / y : (x / y + 1));
    }

    

    static long sqrt(long z) {
        long sqz = (long) Math.sqrt(z);
        while (sqz * 1L * sqz < z) {
            sqz++;
        }
        while (sqz * 1L * sqz > z) {
            sqz--;
        }
        return sqz;
    }

    

    static int log2(int N) {
        int result = (int) (Math.log(N) / Math.log(2));
        return result;
    }

    

    static boolean isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;

        while (n != 1) {
            if (n % 2 != 0)
                return false;
            n = n / 2;
        }
        return true;
    }

    public static int lower_bound(int[] arr, int x) {
        int low = 0, high = arr.length - 1, mid = -1;
        int ans = -1;
        while (low <= high) {
            mid = (low + high) / 2;

            if (arr[mid] > x) {
                high = mid - 1;
            } else {
                ans = mid;
                low = mid + 1;
            }
        }

        return ans;
    }

    public static int upper_bound(int[] arr, int x) {
        int low = 0, high = arr.length - 1, mid = -1;
        int ans = arr.length;
        while (low < high) {
            mid = (low + high) / 2;

            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    

    public static void primeSieve(int n){
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

    

    public static int countDivisors(long number){
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
        int totalDivisors = 1;
        int currentCount = 2;
        for (int i = 1; i < primeFactors.size(); i++) {
            if (primeFactors.get(i) == current) {
                currentCount++;
            } else {
                totalDivisors *= currentCount;
                currentCount = 2;
                current = primeFactors.get(i);
            }
        }
        totalDivisors *= currentCount;
        return totalDivisors;
    }

    

    public static boolean next_permutation(int[] p) {
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

    

    public static long getNcR(int n, int r)
    {
        long p = 1, k = 1;
        if (n - r < r) r = n - r;

        if (r != 0) {
            while (r > 0) {
                p *= n;
                k *= r;
                long m = __gcd(p, k);
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

    

    public static boolean isVowel(char c)
    {
        return (c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' ||     c=='u' || c=='U');
    }

    public static boolean isSingleHole(char c)
    {
        return ( c=='A' || c=='D' ||  c=='O' ||  c=='R' ||   c=='P' || c=='Q');
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

    

    public static int binomialCoeff(int n, int k)
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
        public String s;
        public long l;
        Pair(int a , int b){
            this.a = a;
            this.b = b;
        }
        Pair(long a , int b){
            this.l = a;
            this.b = b;
        }
        Pair(int a , String b){
            this.a = a;
            this.s = b;
        }
        @Override
        public String toString(){
            return a + " -> " + b;
        }
    }


    

    public static class Triplet{

        public int a;
        public int b;
        public int c;
        public String name;
        Triplet(String name,int a , int b, int c){
            this.a = a;
            this.b = b;
            this.c = c;
            this.name=name;
        }

        public int getA() {
            return a;
        }

        public int getB() {
            return b;
        }

        public int getC() {
            return c;
        }

        public String getName() {
            return name;
        }

        @Override
        public String toString() {
            return "Triplet{" +
                    "a=" + a +
                    ", b=" + b +
                    ", c=" + c +
                    ", name='" + name + '\'' +
                    '}';
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

    

    public static long __gcd(long n1, long n2)
    {
        long gcd = 1;
        for (int i = 1; i <= n1 && i <= n2; ++i) {
            

            if (n1 % i == 0 && n2 % i == 0) {
                gcd = i;
            }
        }
        return gcd;
    }

    static boolean isOddBitsSet(int n){
        if(Integer.bitCount(n)%2==0)
            return true;
        return false;
    }

    

    public static void swap(int[] arr, int left , int right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

    public static void swap(long[] arr, int left , int right){
        long temp = arr[left];
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

    public static void reverse(long[] arr){
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

    

    public static long mminvprime(long a, long b) {
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
        return (mod_mul(a, mminvprime(b, m), m) + m) % m;
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

    static int[] readArray(int N) {
        int[] res = new int[N];
        for (int i = 0; i < N; i++) {
            res[i] = (int) sc.nextInt();
        }
        return res;
    }

    static double[] readArrayDouble(int N) {
        double[] res = new double[N];
        for (int i = 0; i < N; i++) {
            res[i] = sc.nextDouble();
        }
        return res;
    }

    static long[] readArrayLong(int N) {
        long[] res = new long[N];
        for (int i = 0; i < N; i++) {
            res[i] = sc.nextLong();
        }
        return res;
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
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

        String nextLine() {
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