


import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.StringTokenizer;







public class practice{
    static long[] count,count1,count2;
    static boolean[] prime;
    static boolean flag;
    static int[] spf;
    static Node[] nodes,nodes1,nodes2;
    static long[] arr;
    static long[][] cost;
    static int[] arrInt,darrInt,farrInt;
    static long[][] dp;
    static char[] ch,ch1,ch2;
    static long[] darr,farr;
    static char[][] mat,mat1;
    static boolean[] vis;
    static long x,h;
    static long maxl,sum,total;
    static double dec;
    static long mx = (long)1e7;
    static long inf = (long)1e18;
    static String s,s1,s2,s3,s4;
    static long minl;
    static long mod = (long)(1e9)+7;
    

    

    static int n,n1,n2,q,r1,c1,r2,c2;
    static int arr_size = (int)2e5+10;
    static long a;
    static long b;
    static long c;
    static long d;
    static long y,z;
    static int m,m1;
    static long ans;
    static long k;
    static FastScanner sc;
    static String[] str,str1;
    static Set<Long> set,set1,set2;
    static SortedSet<Long> ss;
    static List<StringBuilder> list,list1,list2,list3;
    static PriorityQueue<Node> pq,pq1;
    static LinkedList<Node> ll,ll1,ll2;
    static Map<Integer,List<Integer>> map;
    static Map<Integer,Integer> map2;
    static Map<Integer,Long> mapL,mapR;
    static Map<Integer,Node> map1;
    static StringBuilder sb,sb1,sb2;
    static int index;
    static int[] dx = {0,-1,0,1,-1,1,-1,1};
    static int[] dy = {-1,0,1,0,-1,-1,1,1};

    static class Node{
        long first;
        int second;
        Node(long f,int s){
            this.first = f;
            this.second = s;
        }
    }

    static LNode head = null;
    static LNode tail = null;

    static class LNode{
        long key;
        long val;
        LNode next;
        LNode prev;
        LNode(long key,long val){
            this.key = key;
            this.val = val;
            this.next = null;
            this.prev = null;
        }
        LNode(long val){
            this.key = -1;
            this.val = val;
            this.next = null;
            this.prev = null;
        }
    }



























    


    public static void solve() {

        boolean[][] count = new boolean[26][2];
        int index0 = 0;
        int index1 = 0;

        int n = ch.length;
        int m = ch1.length;
        int i1 = 0;
        int i2 = 0;

        for(int i = 0 ; i < n/2 ; i++){
            char temp = ch[i];
            ch[i] = ch[n-i-1];
            ch[n-i-1] = temp;
        }

        for(int i = 0 ; i < m/2 ; i++){
            char temp = ch1[i];
            ch1[i] = ch1[m-i-1];
            ch1[m-i-1] = temp;
        }

        for(int i = 0 ; i < n ; i++){

            if(index0 == m || index1 == m){
                sb.append("YES\n");
                return;
            }

            int j1 = i1;
            int j2 = i2;
            boolean flag = true;

            if(i1 < n && ch[i1] == ch1[index0]){
                int charNum = ch[i1] - 'a';
                if(index0 == 0 && i1%2 == 0) {
                    index0 += 1;
                    count[charNum][i1%2] = true;
                    flag = false;
                }
                else if(index0 > 0){
                    if(count[(ch1[index0-1] - 'a')][1-(i1%2)]) {
                        count[charNum][i1%2] = true;
                        index0 += 1;
                        flag = false;
                    }
                }
            }































            if(!flag)
                i1 += 1;

            if(index0 == m || index1 == m){
                sb.append("YES\n");
                return;
            }
            flag = true;






























            if(i2 < n && ch[i2] == ch1[index1]){
                int charNum = ch[i2] - 'a';
                if(index1 == 0 && i2%2 == 1) {
                    index1 += 1;
                    count[charNum][i2%2] = true;
                    flag = false;
                }
                else if(index1 > 0){
                    if(count[(ch1[index1-1] - 'a')][1-(i2%2)]) {
                        count[charNum][i2%2] = true;
                        index1 += 1;
                        flag = false;
                    }
                }
            }

            if(!flag)
                i2 += 1;

            if(i1 == j1)
                i1 += 2;

            if(i2 == j2)
                i2 += 2;

            if(index0 == m || index1 == m){
                sb.append("YES\n");
                return;
            }

        }
        if(index0 == m || index1 == m){
            sb.append("YES\n");
        }
        else{
            sb.append("NO\n");
        }

    }

    


    public static void main(String[] args) {

        sc = new FastScanner();
        

        sb = new StringBuilder();
        int t = sc.nextInt();


        while(t > 0){



            

            

            


















            





            

















            





            ch = sc.next().toCharArray();
             ch1 = sc.next().toCharArray();



            




















            

            















            

            



















            

            

            

            


            














































            solve();
            t -= 1;
        }
        System.out.print(sb);

    }

    public static int log(double n,double base){

        if(n == 0 || n == 1)
            return 0;

        if(n == base)
            return 1;

        double num = Math.log(n);
        double den = Math.log(base);

        if(den == 0)
            return 0;

        return (int)(num/den);
    }

    public static boolean isPrime(long n) {
        

        if (n <= 1)
            return false;

        if (n <= 3)
            return true;

        

        

        if (n%2 == 0 || n%3 == 0)
            return false;

        for (int i=5; i*i<=n; i=i+6)
            if (n%i == 0 || n%(i+2) == 0)
                return false;

        return true;
    }

    public static void SpecialSieve(int MAXN)
    {
        spf = new int[MAXN];
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

    public static ArrayList<Integer> getFactorization(int x)
    {
        ArrayList<Integer> ret = new ArrayList<Integer>();
        while (x != 1)
        {
            ret.add(spf[x]);
            x = x / spf[x];
        }
        return ret;
    }

    public static long gcd(long a, long b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    public static long lcm(long a, long b)
    {
        return (b/gcd(b, a % b)) * a;
    }

    public static long mod_inverse(long a,long mod){
        long x1=1,x2=0;
        long p=mod,q,t;
        while(a%p!=0){
            q = a/p;
            t = x1-q*x2;
            x1=x2; x2=t;
            t=a%p;
            a=p; p=t;
        }
        return x2<0 ? x2+mod : x2;
    }

    public static void swap(double[] curr,int i,int j){
        double temp = curr[j];
        curr[j] = curr[i];
        curr[i] = temp;
    }

    static final Random random=new Random();

    static void ruffleSortLong(long[] a) {
        int n=a.length;

        for (int i=0; i<n; i++) {
            int oi=random.nextInt(n);
            long temp=a[oi];
            a[oi]=a[i]; a[i]=temp;
        }
        Arrays.sort(a);
    }

    static void ruffleSortInt(int[] a) {
        int n=a.length;

        for (int i=0; i<n; i++) {
            int oi=random.nextInt(n);
            int temp=a[oi];
            a[oi]=a[i]; a[i]=temp;
        }
        Arrays.sort(a);
    }

    static void ruffleSortChar(char[] a) {
        int n=a.length;

        for (int i=0; i<n; i++) {
            int oi=random.nextInt(n);
            char temp=a[oi];
            a[oi]=a[i]; a[i]=temp;
        }
        Arrays.sort(a);
    }

    static long binomialCoeff(long n, long k){

        long res = 1;

        

        if (k > n - k)
            k = n - k;

        

        

        for (long i = 0; i < k; ++i) {
            res = (res*(n - i));
            res = (res/(i + 1));
        }

        return res;
    }

    static long mod(long x)
    {
        long y = mod;
        long result = x % y;
        while (result < 0)
        {
            result += y;
        }
        return result;
    }

    static long[] fact;

    public static long inv(long n){
        return power(n, mod-2);
    }

    public static void fact(int n){
        fact = new long[n+1];
        fact[0] = 1;
        for(int j = 1;j<=n;j++)
            fact[j] = (fact[j-1]*(long)j)%mod;
    }

    public static long binom(int n, int k){

        long prod = fact[n];
        prod*=inv(fact[n-k]);
        prod%=mod;
        prod*=inv(fact[k]);
        prod%=mod;
        return prod;
    }

    static long power(long x, long y){
        if (y == 0)
            return 1;
        if (y%2 == 1)
            return (x*power(x, y-1))%mod;
        return power((x*x)%mod, y/2)%mod;
    }

    static void sieve(int n){

        prime = new boolean[n+1];
        for(int i=2;i<n;i++)
            prime[i] = true;

        for(int p = 2; p*p <=n; p++)
        {
            if(prime[p])
            {
                for(int i = p*p; i <= n; i += p)
                    prime[i] = false;
            }
        }

    }

    static long abs(long a){
        return Math.abs(a);
    }

    static int abs(int a){
        return Math.abs(a);
    }

    static int max(int a,int b){
        if(a>b)
            return a;
        else
            return b;
    }
    static double max(double a,double b){
        if(a>b)
            return a;
        else
            return b;
    }
    static double min(double a,double b){
        if(a>b)
            return b;
        else
            return a;
    }

    static int min(int a,int b){
        if(a>b)
            return b;
        else
            return a;
    }

    static long max(long a,long b){
        if(a>b)
            return a;
        else
            return b;
    }

    static long min(long a,long b){
        if(a>b)
            return b;
        else
            return a;
    }

    static long sq(long num){
        return num*num;
    }

    static double sq(double num){
        return num*num;
    }

    static long sqrt(long num){
        return (long)Math.sqrt(num);
    }

    static double sqrt(double num){
        return Math.sqrt(num);
    }

    static private void removeNode(LNode n){
        if(n.prev!=null){
            n.prev.next = n.next;
        }else{
            head = n.next;
        }

        if(n.next!=null){
            n.next.prev = n.prev;
        }else{
            tail = n.prev;
        }
    }

    static private void offerNode(LNode n){

        if(tail!=null){
            tail.next = n;
        }

        n.prev = tail;
        n.next = null;
        tail = n;

        if(head == null){
            head = tail;
        }
    }

    static class FastScanner {

        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        









        long nextLong() {
            return Long.parseLong(next());
        }
    }

}