import java.util.*;
import java.lang.*;
import java.io.*;
import java.awt.*;































 public class Main
 

{
    static PrintWriter out;
    
	static class FastReader{
		BufferedReader br;
		StringTokenizer st;
		public FastReader(){
			br=new BufferedReader(new InputStreamReader(System.in));
			out=new PrintWriter(System.out);
		}
		String next(){
			while(st==null || !st.hasMoreElements()){
				try{
					st= new StringTokenizer(br.readLine());
				}
				catch (IOException e){
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
			String str = "";
			try{
				str=br.readLine();
			}
			catch(IOException e){
				e.printStackTrace();
			}
			return str;
		}
	}
	


 public static int id1(long n)
 {
  if( n< 0)return -1 ;
  int sum = 0;
  while( n > 0){ sum = sum + (int)( n %10) ; n /= 10 ; } 
  return sum ;  
 }
 


public static void swapArray(int[] arr , int start , int end)
{
    while(start<end){ int temp = arr[start] ;arr[start] = arr[end]; arr[end] = temp;  start++ ;end-- ;}
   
}



static long factorial(long a)
{
    if(a== 0L || a==1L)return 1L ;
   return a*factorial(a-1L) ;
}


public static int[][] rotate(int[][] input){

int n =input.length;int m = input[0].length ;
int[][] output = new int [m][n];
for (int i=0; i<n; i++)
	for (int j=0;j<m; j++)
		output [j][n-1-i] = input[i][j];
return output;
}


public static String reverse(String input)
{
  StringBuilder str  = new StringBuilder("") ;
   
    for(int i =input.length()-1 ; i >= 0  ; i-- )
    {
        str.append(input.charAt(i));
    }
    
return str.toString() ;
}



public static int id4(int n)
{
  if( n % 4 ==0)return n ; else if( n % 4 == 1)return 1 ;
  else if( n % 4 == 2)return n+1 ; else return 0 ;
 }



public static int gcd(int a, int b )
{
   if(b==0)return a ;else return gcd(b,a%b) ; 
}

public static long gcd(long a, long b )
{
if(b==0)return a ;else return gcd(b,a%b) ; 
}



public static int lcm(int a, int b ,int c )
{
int temp = lcm(a,b) ;int ans =  lcm(temp ,c) ;return ans  ;
}



    
public static int lcm(int a , int b )
{
   int gc = gcd(a,b);return (a/gc)*b ;
}


public static long lcm(long a , long b )
{
    long gc = gcd(a,b);return (a/gc)*b;
}




static boolean isPrime(long n)
{ 
   if(n==1)return false  ;  
    for(long i = 2L; i*i <= n ;i++){ if(n% i ==0){return false; } }
    return true ;
} 

static boolean isPrime(int n)
{
    if(n==1)return false  ;  
    for(int i = 2; i*i <= n ;i++){ if(n% i ==0){return false ; } }
    return true ;
}      






static int sieve =  1000000 ;

 
static boolean[] prime =  new boolean[sieve + 1] ;

public static void id3() 
    { 
        

        
        

        
        

        
        for(int i = 4; i<= sieve ; i++)
        {
            prime[i] = true  ; i++ ;
           
        }
        
        for(int p = 3; p*p <= sieve; p++) 
        { 
           if(prime[p] == false) 
            { 
                    for(int i = p*p; i <= sieve; i += p) 
                    prime[i] = true; 
            } 
            
            p++ ;
        } 
          
    } 
 


public static void sortD(int[] arr , int s  , int e)
{
      sort(arr ,s , e) ;
      int i =s ; int j = e  ;
      while( i < j){  int temp = arr[i] ;arr[i] =arr[j] ; arr[j] = temp ; i++ ; j-- ;}
}




public static long id0(long[] arr ,long sum )
    {
      HashMap<Long,Long> map = new HashMap<>() ;
       
      int n = arr.length ; long prefixsum = 0 ; long count = 0L ;
        for(int i  = 0; i < n ; i++)
      {
          prefixsum  = prefixsum +  arr[i] ;
           
          if(sum == prefixsum)count = count+1 ;
           
          if(map.containsKey(prefixsum -sum))count = count + map.get(prefixsum -sum) ;
         
          if(map.containsKey(prefixsum )) map.put(prefixsum , map.get(prefixsum) +1 );
          else map.put(prefixsum , 1L );
      }
        
      return count  ;  
    }















public static ArrayList<Integer> id2(String str , String pat)
     {
        ArrayList<Integer> list =new ArrayList<>();
        
        int n = str.length() ;
        int m = pat.length() ;
        
        String q = pat + "
        
        int[] lps  =new int[n+m+1] ;
        
         longestPefixSuffix(lps, q,(n+m+1)) ;
         
         
         for(int i =m+1 ; i < (n+m+1) ; i++ )
         {
             if(lps[i] == m)
             {
                 list.add(i-2*m) ;
             }
         }
        
        return list ; 
         
        
    }
    

public static void longestPefixSuffix(int[] lps ,String str , int n)
    {
        lps[0] =  0 ;
        
        for(int i = 1  ; i<= n-1; i++)
        {
          int l = lps[i-1] ;
           
          while( l > 0 && str.charAt(i) != str.charAt(l))
          {
              l = lps[l-1] ;
          }
           
          if(str.charAt(i) == str.charAt(l))
          {l++ ;}
              
              lps[i] = l ; 
        }
        
    }
    
 


 

    

    

    

    
    public static void eulerTotientFunction(int[] arr ,int n )
    {
      for(int i = 1; i <= n  ;i++)arr[i] =i  ;
      
       for(int i= 2 ; i<= n ;i++)
      {
          if(arr[i] == i)
          {
              arr[i] =i-1 ;
              
              for(int j =2*i ; j<= n  ; j+= i )
              {
                  arr[j] = (arr[j]*(i-1))/i ;
              }
              
          }
      }
        
    }
	


public static long nCr(int n,int k)
{
    long ans=1L;
    k=k>n-k?n-k:k;
    int j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}




public static ArrayList<Integer> allFactors(int n)
{   
      ArrayList<Integer> list = new ArrayList<>() ;
      
    for(int i = 1; i*i <= n ;i++)
    {
          if( n % i == 0)
          {
              if(i*i == n)list.add(i) ;
              else{ list.add(i) ;list.add(n/i) ; }
          }
    }
      
     return list ; 
}


public static ArrayList<Long> allFactors(long n)
{   
      ArrayList<Long> list = new ArrayList<>() ;
      
    for(long i = 1L; i*i <= n ;i++)
    {
          if( n % i == 0)
          {
              if(i*i == n) list.add(i) ;
              else{  list.add(i) ; list.add(n/i) ; }
             
          }
    }
      
     return list ; 
}



  static final int MAXN = 1000001; 
       
    
    static int spf[] = new int[MAXN]; 
   
    static void sieve() 
    { 
       for (int i=1; i<MAXN; i++) spf[i] = i; 

       
        for (int i=4; i<MAXN; i+=2) 

            spf[i] = 2; 
       
        for (int i=3; i*i<MAXN; i++) 
        { 
           if (spf[i] == i) 
            { 
               for (int j=i*i; j<MAXN; j+=i) 
       
                    if (spf[j]==j) spf[j] = i;  
            } 
        } 
    } 
       

    static ArrayList<Integer> getPrimeFactorization(int x) 
    { 
        ArrayList<Integer> ret = new ArrayList<Integer>(); 
        while (x != 1) 
        { 
            ret.add(spf[x]); 
            x = x / spf[x]; 
        } 
        return ret; 
    } 
       
 

 

   
public static void merge(int arr[], int l, int m, int r)
    {
        

        int n1 = m - l + 1;
        int n2 = r - m;
 
        
        int L[] = new int[n1];
        int R[] = new int[n2];
 
       

        for (int i=0; i<n1; ++i)
            L[i] = arr[l + i];
        for (int j=0; j<n2; ++j)
            R[j] = arr[m + 1+ j];
 
 
        
 
        

        int i = 0, j = 0;
 
        

        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
 
        
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
 
        
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
 
    

    

  public static void sort(int arr[], int l, int r)
    {
        if (l < r)
        {
            

            int m = (l+r)/2;
 
            

            sort(arr, l, m);
            sort(arr , m+1, r);
 
            

            merge(arr, l, m, r);
        }
    }

public static void sort(long arr[], int l, int r)
    {
        if (l < r)
        {
            

            int m = (l+r)/2;
 
            

            sort(arr, l, m);
            sort(arr , m+1, r);
 
            

            merge(arr, l, m, r);
        }
    }


public static void merge(long arr[], int l, int m, int r)
    {
        

        int n1 = m - l + 1;
        int n2 = r - m;
 
        
        long L[] = new long[n1];
        long R[] = new long[n2];
 
        

        for (int i=0; i<n1; ++i)
            L[i] = arr[l + i];
        for (int j=0; j<n2; ++j)
            R[j] = arr[m + 1+ j];
 
 
        
 
        

        int i = 0, j = 0;
 
        

        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
 
        
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
 
        
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
 

 

 
	public static long knapsack(int[] weight,long value[],int maxWeight){

        int n=  value.length ;

	

  long []dp = new long[maxWeight+1]; 
      
    

    Arrays.fill(dp, 0); 
  
    

    for(int i=0; i < n; i++)  
      
        

        for(int j = maxWeight; j >= weight[i]; j--) 
            dp[j] = Math.max(dp[j] , value[i] + dp[j - weight[i]]); 
              
    
    return dp[maxWeight]; 
	}









public static long kadanesAlgorithm(long[] arr)
{
    if(arr.length == 0)return  0 ;    
    
    long[] dp = new long[arr.length] ; dp[0] = arr[0] ;long max =  dp[0] ;
      
    for(int i = 1; i <  arr.length ; i++)
      {
            if(dp[i-1] > 0) dp[i] = dp[i-1] + arr[i] ; else  dp[i] = arr[i] ;
            if(dp[i] >  max)max = dp[i] ;
    }
       return max  ;
      
}


public static long kadanesAlgorithm(int[] arr)
{    if(arr.length == 0)return  0 ;
    
      long[] dp = new long[arr.length] ;dp[0] = arr[0] ; long max =  dp[0] ;
      for(int i = 1; i <  arr.length ; i++)
      {
            if(dp[i-1] > 0) dp[i] = dp[i-1] + arr[i] ;  else  dp[i] = arr[i] ;
           if(dp[i] >  max)max = dp[i] ;
      }
      
      return max  ;
}



    public static long power(int a  ,int b)
    {
        

        long x = (long)(a) ; long n = (long)(b) ;
        if(n==0)return 1 ;if(n==1)return x;
         long ans =1L  ;
 
      while(n>0)
      {
          if(n % 2 ==1)ans = ans *x ;
         n = n/2L ;x =  x*x ; 
      }    
      return ans ;
    }
    
    public static long power(long a  ,long b)
    {
        

        long x = (a) ;long n = (b) ;
         if(n==0)return 1L ;if(n==1)return x;
         long ans =1L  ;
        
      while(n>0)
      {
          if(n % 2 ==1)ans = ans *x ;
        
          n = n/2L ; x =  x*x ;
      }
       
      return ans ;
    }
    





public static long lowerBound(long[] arr,long k)
	{
		long ans=-1;
		
		int start=0;
		int end=arr.length-1;
		
		while(start<=end)
		{
			int mid=(start+end)/2;
			
			if(arr[mid]<=k)
			{
				ans=arr[mid];
				start=mid+1;
			}
			else
			{
				end=mid-1;
			}
			
		}
		
		return ans;
		
	}
	
	public static int lowerBound(int[] arr,int k)
	{
		int ans=-1;int start=0;int end=arr.length-1;
	
		while(start<=end)
		{
			int mid=(start+end)/2;
			
			if(arr[mid]<=k)
			{
				ans=arr[mid];
				start=mid+1;
			}
			else
			{
				end=mid-1;
			}
			
		}
		
		return ans;
		
	}
	
	
	public static long upperBound(long[] arr,long k)
	{
		long ans=-1;int start=0;int end=arr.length-1;
	
		while(start<=end)
		{
			int mid=(start+end)/2;
			
			if(arr[mid]>=k)
			{
				ans=arr[mid];
				end=mid-1;
			}
			else
			{
				start=mid+1;
			}
			
		}
		
		return ans;
	}
	
	
	public static int upperBound(int[] arr,int k)
	{
		int ans=-1; int start=0; 	int end=arr.length-1;

		while(start<=end)
		{
			int mid=(start+end)/2;
			
			if(arr[mid]>=k)
			{
				ans=arr[mid];
				end=mid-1;
			}
			else
			{
				start=mid+1;
			}
			
		}
		
		return ans;
	}
	





public static void printArray(int[] arr , int si ,int ei, int f)
{
    for(int i = si  ; i  <= ei ; i++){ out.print(arr[i] +" ") ; }  if(f==1)out.println() ;
}

public static void printArray(long[] arr , int si ,int ei, int f)
{
    for(int i = si  ; i  <= ei ; i++){ out.print(arr[i] +" ") ; }  if(f==1)out.println() ;
}


public static void printtwodArray(int[][] ans)
{
    for(int i = 0; i< ans.length ; i++)
    {
        for(int j  = 0 ; j <  ans[0].length ; j++)out.print(ans[i][j] +" "); out.println() ;
    }
    out.println() ;
}


 

 
   static long modPow(long a, long x, long p) {
    

    
    a = a % p ;
    
    if(a == 0)return 0L ;
    if(x==0)return 1L;
    if(x==1)return a;
    
    long res = 1L;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x =x/2;
    }
    return res;
}
 
 
  static long modInverse(long a, long p) {
    

    return modPow(a, p-2, p);
}
 
 static long[] factorial =  new long[1000001] ;
 
 static void modfac(long mod)
 {
     factorial[0]=1L ; factorial[1]=1L ;
     
     for(int i = 2; i<= 1000000 ;i++)
     {
         factorial[i] = factorial[i-1] *(long)(i) ;
          factorial[i] = factorial[i] % mod ;
     }
    
     
 }
 
static long modBinomial(long n, long r, long p) {


 
  if(n < r) return 0L ; 
 
    long num = factorial[(int)(n)] ;
    
    long den = (factorial[(int)(r)]*factorial[(int)(n-r)]) %  p ;
    
    
    long ans  = num*(modInverse(den,p)) ;
    
    ans = ans % p ;
    
    return ans  ;
 
    
}
 
 
 static void update(int val , long[] bit ,int n)
 {
     for( ; val <= n ; val += (val &(-val)) )
     {
         bit[val]++ ;
     }
    
     
 }
 
 
 static long query(int val , long[] bit , int n)
 {
     long ans = 0L; 
     for( ; val >=1 ; val-=(val&(-val))  )ans += bit[val];
     
     return ans ;
 }



 static int countSetBits(long n) 
    { 
        int count = 0; 
        while (n > 0) { 
            n = (n) & (n - 1L);  count++; 
            
        } 
        return count; 
    } 


static int abs(int x)
{ if(x<0)x=-x ; return x ; }
    
static long abs(long x)
{  if(x<0)x=-x ; return x ; }




 

 
static  int bs(int[] arr, int s ,int e  ,int key)
{
        if( s> e)return 0 ;
        int mid = (s+e)/2 ;
        
        if(arr[mid] <key) return bs(arr ,mid+1,e , key) ;
        else  {return bs(arr ,s ,mid-1, key)  + e-mid+1;}
   
}
 






static class pair {
		int u;
	     int v;
 
	public	pair(int u,int v) {
			this.u = u ; this.v=v;
		
		}
	}
 
static class Dsu
{
    int n ;int[] par ; int[] size ;
    
    public Dsu(int n)
    {
        this.n = n ;
        par = new int[n] ;
        size = new int[n] ;
        
        for(int i = 0 ; i< n ;i++)
        {
            par[i] =i ;size[i] =1 ;
        }
    }
    
    

    public boolean isRoot(int x)
    {
        return par[x] == x ;
    }
    
    

   public int findRoot(int x)
   {
       if(par[x] == x)
       {
          return par[x] ; 
       }
       
       par[x] = findRoot(par[x]) ; 

       return par[x] ;
   }
   
   
   public boolean unionSet(int a, int b)
   {
       int rootA = findRoot(a);
       int rootB=findRoot(b) ;
       
       if(rootA==rootB)return true ;

       
       if(size[rootA] > size[rootB])
       {
           size[rootA] += size[rootB] ;
           par[rootB] =rootA ;
       }
       
       else{
           
           size[rootB] += size[rootA] ;
           par[rootA] =rootB ;
       }
       
       return false ;     

   }
   
}









public static void solve()
{
FastReader scn = new FastReader() ;























ArrayList<Integer> list = new ArrayList<>() ;
ArrayList<Integer> listx = new ArrayList<>() ;
ArrayList<Integer> listy = new ArrayList<>() ;

HashMap<Integer,Integer> map = new HashMap<>() ;
HashMap<Integer,Integer> mapx  = new HashMap<>() ;
HashMap<Integer,Integer> mapy  = new HashMap<>() ;



 Set<Integer> set = new HashSet<>() ;
 Set<Integer> setx = new HashSet<>() ;
 Set<Integer> sety = new HashSet<>() ;

StringBuilder sb =new StringBuilder("") ;



























 

 
int testcase = 1;
 testcase = scn.nextInt() ;
for(int testcases =1  ; testcases <= testcase ;testcases++)
{
 

long n =scn.nextLong() ;
long m =scn.nextLong() ;
long k =scn.nextLong() ;

k=k-2;

String yes = "YES" ;
String no = "NO";

if(n==1)
{
     if(m != 0 || k < 0)out.println(no) ;
     else out.println(yes) ;
}

else if(n==2)
{
      if(m != 1 || k < 1)out.println(no) ;
        else out.println(yes) ;
      
      
}

else{
      
      long min = (n-1) ;
      long max = (n)*(n-1)/2;
      
      if(m < min || m > max )out.println(no) ;
      else{
            
            if(m==max)
            {
                 if(k < 1)out.println(no) ;
                 else out.println(yes) ;
            }
            else{
                  
                   if(k < 2)out.println(no) ;
                 else out.println(yes) ;
            }
            
      }
      
}



sb.delete(0 , sb.length()) ;
list.clear() ;listx.clear() ;listy.clear() ;
map.clear() ;mapx.clear() ;mapy.clear() ;
set.clear() ;setx.clear() ;sety.clear() ;

} 



out.flush() ;  
} 



public static void main (String[] args) throws java.lang.Exception
{     solve() ;    }
      
}
  
 class Pair 
{
  int first ;int second  ;
 
  public  Pair(int x, int y)
  {
      this.first = x ;this.second = y ;
  }
  
  @Override
 public boolean equals(Object obj)
 {
     if(obj == this)return true  ;
     
     if(obj == null)return false  ;
     
     if(this.getClass() != obj.getClass()) return false ;
     
     Pair other  = (Pair)(obj) ;
     
     if(this.first != other.first)return false  ;
     if(this.second != other.second)return false  ;
     
     return true  ;
     
 }
    
    @Override
    
    public int hashCode()
    {
        return this.first^this.second  ;
    }
      
@Override
	public String toString() {
	
	String ans = "" ;ans  += this.first ;	ans += " ";	ans += this.second ;
	return ans  ;
	}

}


