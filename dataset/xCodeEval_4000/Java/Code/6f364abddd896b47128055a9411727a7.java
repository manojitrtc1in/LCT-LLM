

    


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
     static long[] arr;
     static long[][] cost;
     static int[] arrInt,darrInt,farrInt;
     static long[][] dp;
     static char[] ch,ch1,ch2;
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
     static long mod = 998244353;
     

     

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

     static class Node{
        int first;
        int second;
        Node(int f,int s){
            this.first = f;
            this.second = s;
        }
    }

     


     

     

     

     


            
     


     

        
     


     


    static double nthRoot(long A, int N)
    {
         
        

        

        double xPre = Math.random() % 10;
     
        

        double eps = 0.001;
     
        

        

        double delX = 2147483647;
     
        

        double xK = 0.0;
     
        

        while (delX > eps)
        {
            

            

            xK = ((N - 1.0) * xPre +
            (double)A / Math.pow(xPre, N - 1)) / (double)N;
            delX = Math.abs(xK - xPre);
            xPre = xK;
        }
     
        return xK;
    }

     public static void solve(){

     	int countOnes = 0;

        for(int i = 0 ; i < n ; i++){
            if(ch[i] == '1')
                countOnes += 1;
        }

        boolean bracketFlag = true;
        sb1 = new StringBuilder();
        sb2 = new StringBuilder();

        int limitOfOnes = countOnes/2;
        ch1 = new char[n];
        ch2 = new char[n];

        if(countOnes%2 == 1){
            System.out.println("NO");
            return;
        }

        for(int i = 0 ; i < n ; i++){
            if(ch[i] == '1'){
            	

            	

                if(countOnes > limitOfOnes){
                    ch1[i] = '(';
                    ch2[i] = '(';
                }
                else{
                    ch1[i] = ')';
                    ch2[i] = ')';
                }
                countOnes -= 1;
             

            	

            }
            else{
            	

            	

                if(!bracketFlag){
                    ch1[i] = '(';
                    ch2[i] = ')';
                }
                else{
                    ch1[i] = ')';
                    ch2[i] = '(';
                }
                bracketFlag = !bracketFlag;
             

            	

            }
            sb1.append(ch1[i]);
            sb2.append(ch2[i]);
        }

        int parityFirstArray = 0;
        int paritySecondArray = 0;
        for(int i = 0 ; i < n ; i++){
        	

         

            if(ch1[i] == '('){
                parityFirstArray += 1;
            }
            else{
                parityFirstArray -= 1;
                if(parityFirstArray < 0){
                    System.out.println("NO");
                    return;
                }
            }
            

            

            if(ch2[i] == '(')
                paritySecondArray += 1;
            else{
                paritySecondArray -= 1;
                if(paritySecondArray < 0){
                    System.out.println("NO");
                    return;
                }
            }
            

            

        }

        if(paritySecondArray == 0 && parityFirstArray == paritySecondArray){
            System.out.println("YES");
            System.out.println(sb1);
            System.out.println(sb2);
        }
        else{
            System.out.println("NO");
        }

     }
     

        
     public static void main(String[] args) {

            sc = new FastScanner();
            

            int t = sc.nextInt();
            

            

            while(t > 0){
                
                

                

                

                


                

                

                

                


                

                

                

                


                n = sc.nextInt();

                


                

                


                

                


                


                

                


                


                ch = sc.next().toCharArray();
                


                

                


                

                

                

                


                

                

                

                


                

                

                

                

                

                

                

                

                

                

                

                

                

                

                


                

                

                

                


                

                

                

                


                

                

                

                

                

                

                


                

                

                

                

                

                

                

                


                

                

                


                

                

                


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

    public static void swapF(int[] curr,int l,int r){
         for(int i = l ; i < (r-l+1)/2 ; i++){
            swap(curr,i,r-i);
         }
     }

     public static void swap(int[] curr,int i,int j){
         int temp = curr[j];
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
    if (result < 0)
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