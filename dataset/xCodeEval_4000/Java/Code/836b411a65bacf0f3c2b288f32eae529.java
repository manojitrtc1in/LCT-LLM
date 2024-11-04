

    


import java.util.*;
import java.math.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

     


public class a{ 
     static long[] count,count1,count2;
     static boolean[] prime;
     static int[] spf;
     static Node[] nodes,nodes1,nodes2;
     static NodeInt[] nodesInt,nodesInt1;
     static long[] arr;
     static long[][] cost;
     static int[] arrInt,darrInt,farrInt;
     static long[][] dp;
     static char[] ch,ch1;
     static long[] darr,farr;
     static long[][] mat,mat1;
     static boolean[] vis;
     static long x,h;
     static long maxl,sum,total;
     static double dec;
     static long mx = (long)1e7;
     static long inf = (long)1e9	;
     static String s,s1,s2,s3,s4;
     static long minl;   
     static long mod = inf+7;
     

     

     static int n,n1,n2,q,r1,c1,r2,c2;
     static int arr_size = (int)2e5+10;
     static long a;
     static long b;
     static long c;
     static long d;
     static long y,z;
     static int m;
     static int ans;
     static long k;
     static FastScanner sc;
     static String[] str,str1;
     static Set<Long> set,set1,set2;
     static SortedSet<Long> ss;
     static List<Integer> list,list1,list2,list3;
     static PriorityQueue<Node> pq,pq1;
     static LinkedList<Node> ll,ll1,ll2;
     static Map<Integer,List<Integer>> map;
     static Map<Integer,Integer> map2;
     static Map<Integer,Node> map1;
     static StringBuilder sb,sb1,sb2;
     static int index;
     static int[] dx = {0,-1,0,1,-1,1,-1,1};
     static int[] dy = {-1,0,1,0,-1,-1,1,1};

     


     

     

     

     


            
     


     

        
     


     


     public static void solve(){

     	if(k == 1){
            System.out.println("1");
            return;
        }

        if(k == 2){
            System.out.println(n+1);
            return;
        }

        long currTillNow  = 0;
        long runningTym = 1;

        long sum = 0;

        long[] count = new long[(int)n];

        for(long i = n-1 ; i > 0 ; i--){
            count[(int)i] = (n-i);
            currTillNow = (currTillNow + count[(int)i])%mod;
        }

        sum = currTillNow;
        for(long j = k-2 ; j > 1 ; j--){

            long sum1 = 0;

     

     

     


            
     


     


            if(runningTym%2 == 1){
                for(long i = n-1; i > 0 ; i--){
                    sum = (sum + currTillNow)%mod;

                    long temp = count[(int)i];

                    count[(int)i] = currTillNow;

                    currTillNow = ((currTillNow - temp)+mod)%mod;
                    


                    sum1 = (sum1 + count[(int)i])%mod;
                }

            }
            else{

                for(long i = 1; i <= n-1; i++){

                    sum = (sum + currTillNow)%mod;

                    


                     

	                


	                


	                

	                


	                

	                


                    long temp = count[(int)i];

                    count[(int)i] = currTillNow;

                    currTillNow = ((currTillNow - temp)+mod)%mod;

                    sum1 = (sum1 + count[(int)i])%mod;

                }

            }
            currTillNow = sum1;

            runningTym += 1;
        }
        sum = (sum + n+1)%mod;

        System.out.println(sum%mod);

     }
     

        
     public static void main(String[] args) {

            sc = new FastScanner();
            

            int t = sc.nextInt();
            

            

            while(t > 0){
                
                

                

                

                


                

                

                

                


                

                

                

                


                n = sc.nextInt();

                


                

                


                

                


                k = sc.nextLong();

                

                


                


                

                


                

                


                

                

                

                


                

                

                

                

                

                

                

                

                

                

                

                

                

                

                

                

                

                

                


                

                

                

                


                

                

                

                


                

                

                

                

                

                

                


                

                

                

                

                

                

                

                


                

                

                


                

                

                


                

                

                


                 solve();       
                 t -= 1;
            }

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

    public static void swapF(int[] currTillNow,int l,int r){
         for(int i = l ; i < (r-l+1)/2 ; i++){
            swap(currTillNow,i,r-i);
         }
     }

     public static void swap(int[] currTillNow,int i,int j){
         int temp = currTillNow[j];
         currTillNow[j] = currTillNow[i];
         currTillNow[i] = temp;
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

    public static long pow(long n,long p,long m){
     long  result = 1;
      if(p==0)
        return 1;
          
    while(p!=0)
    {
        if(p%2==1)
            result *= n;
        if(result>=m)
        result%=m;
        p >>=1;
        n*=n;
        if(n>=m)
        n%=m;
    }
    return result;
    }

    static void sieve(int n){ 

        prime = new boolean[n+1]; 
        for(int i=2;i<n;i++) 
            prime[i] = true; 
          
        for(int p = 2; p*p <=n; p++) 
        { 
            if(prime[p] == true) 
            { 
                for(int i = p*p; i <= n; i += p) 
                    prime[i] = false; 
            } 
        } 

    }

    static class Node{
        int first;
        long second;
        Node(int f,long s){
            this.first = f;
            this.second = s;
        }
    }

    static class Node1{
        double first;
        double second;
        int third;
        Node1(double f,double s,int t){
            this.first = f;
            this.second = s;
            this.third = t;
        }
    }

    static class NodeInt{
        int first;
        int second;
        int third;
        NodeInt(int f,int s,int third){
            this.first = f;
            this.second = s;
            this.third = third;
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
                int[] readArray(int n) {
                        int[] a=new int[n];
                        for (int i=0; i<n; i++) a[i]=nextInt();
                        return a;
                }
                long nextLong() {
                        return Long.parseLong(next());
                }
        }

}