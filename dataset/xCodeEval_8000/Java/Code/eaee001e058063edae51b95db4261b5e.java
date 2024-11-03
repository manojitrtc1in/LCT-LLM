import java.util.*;
import java.lang.*;
import java.io.*;
import java.awt.Point;
































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
	




 public static int countDigit(long n) 
    { 
        return (int)Math.floor(Math.log10(n) + 1); 
    } 



 
 public static int sumOfDigits(long n)
 {
  
  if( n< 0)return -1 ;
  
  int sum = 0;
  
  while( n > 0)
  {
      sum = sum + (int)( n %10) ;
      
      n /= 10 ;
  }
     
  return sum ;  
 
 
 
 }
 
 


public static long arraySum(int[] arr , int start , int end)
{
    long ans = 0 ;
    
    for(int i = start ; i <= end  ; i++)ans += arr[i] ;
    
    return ans  ;
}




public static int mod(int x)
{
      if(x <0)return -1*x ;
      else return x ;
}
public static long mod(long x)
{
      if(x <0)return -1*x ;
      else return x ;
}




public static void swapArray(int[] arr , int start , int end)
{
    while(start < end)
    {
        int temp = arr[start] ;
        arr[start] = arr[end];
        arr[end] = temp;
        start++ ;end-- ;
    }
}






public static int[][] rotate(int[][] input){

int n =input.length;
int m = input[0].length ;
int[][] output = new int [m][n];

for (int i=0; i<n; i++)
	for (int j=0;j<m; j++)
		output [j][n-1-i] = input[i][j];
return output;
}



public static int countBits(long n) 
    {  
        int count = 0; 
        while (n != 0) 
        { 
            count++; 
            n = (n) >> (1L) ;
        } 
          
        return count;   
        
    } 



public static boolean isPowerOfTwo(long n) 
{ 
    if(n==0) 
    return false; 
  
if(((n ) & (n-1)) == 0 ) return true ;
else return false  ;

} 




public static int  min(int a ,int b , int c, int d)
{
     int[] arr = new int[4] ;
      arr[0] = a;arr[1] = b ;arr[2] = c;arr[3] = d;Arrays.sort(arr) ;
      
      return arr[0];
}
 

public static int  max(int a ,int b , int c, int d)
{
     int[] arr = new int[4] ;
      arr[0] = a;arr[1] = b ;arr[2] = c;arr[3] = d;Arrays.sort(arr) ;
      
      return arr[3];
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



public static boolean sameParity(long a  ,long b )
{
     long x = a% 2L; long y = b%2L ;
     if(x==y)return true  ;
     else return false  ;
}




public static boolean isPossibleTriangle(int a  ,int b , int c)
{
      if( a + b > c && c+b > a && a +c > b)return true  ;
      else return false  ;
}




static long xnor(long num1, long num2) {
		if (num1 < num2) {
			long temp = num1;
			num1 = num2;
			num2 = temp;
		}
		num1 = togglebit(num1);
		return num1 ^ num2;
	}

	static long togglebit(long n) {
		if (n == 0)
			return 1;
		long i = n;
		n |= n >> 1;
		n |= n >> 2;
		n |= n >> 4;
		n |= n >> 8;
		n |= n >> 16;
		return i ^ n;
	}




public static int xorOfFirstN(int n)
{
 
 
 if( n % 4 ==0)return n ;
 
 else if( n % 4 == 1)return 1 ;
 
 else if( n % 4 == 2)return n+1 ;
 
 else return 0 ;
 
    
}



public static int gcd(int a, int b )
{

if(b==0)return a ;

else return gcd(b,a%b) ; 

}


public static long gcd(long a, long b )
{

if(b==0)return a ;

else return gcd(b,a%b) ; 

}




public static int lcm(int a, int b ,int c , int d )
{

int temp = lcm(a,b , c) ;


 
 int ans = lcm(temp ,d ) ;

return ans  ;


}




public static int lcm(int a, int b ,int c )
{

int temp = lcm(a,b) ;

int ans =  lcm(temp ,c) ;

return ans  ;


}



    
public static int lcm(int a , int b )
{

int gc = gcd(a,b);

return (a*b)/gc ;
}


public static long lcm(long a , long b )
{

long gc = gcd(a,b);

return (a*b)/gc ;
}




static boolean isPrime(long n)
{
      if(n==1)
      {
            return false  ;
      }
      
      boolean ans =  true  ;
      
      for(long i = 2L; i*i <= n ;i++)
      {
            if(n% i ==0)
            {
                  ans = false  ;break ;
            }
      }
      
      
      return ans  ;
}      



static int sieve =  1000000 ;

 
static boolean[] prime =  new boolean[sieve + 1] ;

public static void sieveOfEratosthenes() 
    { 
        

        
        

        
        

       
        
        

        
        

        
        for(int i = 4; i<= sieve ; i++)
        {
            prime[i] = true  ;
            i++ ;
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
      
      while( i < j)
      {
            int temp = arr[i] ;
            arr[i] =arr[j] ;
            arr[j] = temp ;
            i++ ; j-- ;
      }
      
      
      
      return ;
}

public static void sortD(long[] arr , int s  , int e)
{
      sort(arr ,s , e) ;
      
      int i =s ; int j = e  ;
      
      while( i < j)
      {
            long temp = arr[i] ;
            arr[i] =arr[j] ;
            arr[j] = temp ;
            i++ ; j-- ;
      }
      
      
      
      return ;
}





public static long countSubarraysSumToK(long[] arr ,long sum )
    {
      HashMap<Long,Long> map = new HashMap<>() ;
       
      int n = arr.length ;
       
      long prefixsum = 0 ;
       
      long count = 0L ;
      for(int i  = 0; i < n ; i++)
      {
          prefixsum  = prefixsum +  arr[i] ;
           
          if(sum == prefixsum)count = count+1 ;
           
          if(map.containsKey(prefixsum -sum))
          {
              count = count + map.get(prefixsum -sum) ;
          }
          
          
          if(map.containsKey(prefixsum ))
          {
              map.put(prefixsum , map.get(prefixsum) +1 );
          }
          
          else{
              map.put(prefixsum , 1L );
          }
           
           
      }
        
        
        
      return count  ;  
        
    }















public static ArrayList<Integer> kmpAlgorithm(String str , String pat)
     {
        ArrayList<Integer> list =new ArrayList<>();
        
        int n = str.length() ;
        int m = pat.length() ;
        
        String q = pat + "#" + str ;
        
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
          {
              l++ ;
          }
            
           
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
        
      return  ;  
        
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
              if(i*i == n)
              {
                    list.add(i) ;
              }
              else{
                    list.add(i) ;
                    list.add(n/i) ;
                    
              }
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
              if(i*i == n)
              {
                    list.add(i) ;
              }
              else{
                    list.add(i) ;
                    list.add(n/i) ;
                    
              }
          }
    }
      
     return list ; 
      
      
}



  static final int MAXN = 10000001; 
       
    
    static int spf[] = new int[MAXN]; 
   
    static void sieve() 
    { 
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
       























    static Vector<Integer> getFactorization(int x) 
    { 
        Vector<Integer> ret = new Vector<>(); 
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
      long[] dp = new long[arr.length] ;
      
      dp[0] = arr[0] ;
      long max =  dp[0] ;
      
      
      for(int i = 1; i <  arr.length ; i++)
      {
            if(dp[i-1] > 0)
            {
                  dp[i] = dp[i-1] + arr[i] ;
            }
            else{
                  dp[i] = arr[i] ;
            }
            
            if(dp[i] >  max)max = dp[i] ;
            
      }
      
      return max  ;
      
}


public static long kadanesAlgorithm(int[] arr)
{
      long[] dp = new long[arr.length] ;
      
      dp[0] = arr[0] ;
      long max =  dp[0] ;
      
      
      for(int i = 1; i <  arr.length ; i++)
      {
            if(dp[i-1] > 0)
            {
                  dp[i] = dp[i-1] + arr[i] ;
            }
            else{
                  dp[i] = arr[i] ;
            }
            
            if(dp[i] >  max)max = dp[i] ;
            
      }
      
      return max  ;
      
}

      








public static long binarySerachGreater(int[] arr , int start , int end , int val)
{
      
      

      
      
      if(start >  end)return  0 ; 

      
      
      int mid = (start + end)/2  ;
      
      if(arr[mid] <=val)
      {
          return binarySerachGreater(arr,mid+1, end ,val) ; 
            
      }
      else{
            
         return binarySerachGreater(arr,start , mid -1,val) + end-mid+1 ;    
            
      }
      
      
}















    public static String swapString(String a, int i, int j) {  
        char[] b =a.toCharArray();  
        char ch;  
        ch = b[i];  
        b[i] = b[j];  
        b[j] = ch;  
        return String.valueOf(b);  
    }  
      


    public static void generatePermutation(String str, int start, int end)  
    {  
        

        if (start == end-1)  
            System.out.println(str);  
        else  
        {  
            for (int i = start; i < end; i++)  
            {  
                

                str = swapString(str,start,i);  
                

                generatePermutation(str,start+1,end);  
                

                str = swapString(str,start,i);  
            }  
        }  
    }  








public static long factMod(long n, long mod) {
    if (n <= 1) return 1;
    long ans = 1;
    for (int i = 1; i <= n; i++) {
      ans = (ans * i) % mod;
    }
    return ans;
  }







public static long power(long x  ,long n)
    {
        

        
        if(n==0)return 1L ;
        if(n==1)return x;
        
        long ans =1L  ;
       
      while(n>0)
      {
          if(n % 2 ==1)
          {
              ans = ans *x ;
          }
           
          n /= 2 ;
           
          x =  x*x ;
           
      }
       
      return ans ;
    }



public static long powerMod(long x, long n, long mod) {
    

    
    if(n==0)return 1L ;
        if(n==1)return x;
        
    
    long ans = 1;
    while (n > 0) {
      if (n % 2 == 1) ans = (ans * x) % mod;
      x = (x * x) % mod;
      n /= 2;
    }
    return ans;
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
		int ans=-1;
		
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
	
	
	public static long upperBound(long[] arr,long k)
	{
		long ans=-1;
		
		int start=0;
		int end=arr.length-1;
		
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
		int ans=-1;
		
		int start=0;
		int end=arr.length-1;
		
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
	




public static void printArray(int[] arr , int si ,int ei)
{
    for(int i = si  ; i  <= ei ; i++)
    {
        out.print(arr[i] +" ") ;
    }
    
}

public static void printArrayln(int[] arr , int si ,int ei)
{
    for(int i = si  ; i  <= ei ; i++)
    {
        out.print(arr[i] +" ") ;
    }
    out.println() ;
}


public static void printLArray(long[] arr , int si , int ei)
{
    for(int i = si ; i  <= ei ; i++)
    {
        out.print(arr[i] +" ") ;
    }
   
}




public static void printLArrayln(long[] arr , int si , int ei)
{
    for(int i = si ; i  <= ei ; i++)
    {
        out.print(arr[i] +" ") ;
    }
    out.println() ;
   
}

public static void printtwodArray(int[][] ans)
{
    for(int i = 0; i< ans.length ; i++)
    {
        for(int j  = 0 ; j <  ans[0].length ; j++)out.print(ans[i][j] +" ");
        out.println() ;
    }
    out.println() ;
   
}

  
  static long modPow(long a, long x, long p) {
    

    long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}
 
 
 
  static long modInverse(long a, long p) {
    

    

    return modPow(a, p-2, p);
}
 
 
 
static long modBinomial(long n, long k, long p) {


 
    long numerator = 1; 

    for (int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }
 
    long denominator = 1; 

    for (int i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }
 
    

    return ( numerator* modInverse(denominator,p) ) % p;
}
 








 static ArrayList<Integer>[] tree ;












 public static void countNoOfNodesInsubtree(int child ,int par , int[] dp)
 {
     int count = 1 ;
     
     for(int x : tree[child])
     {
         
         if(x== par)continue  ;
         
         countNoOfNodesInsubtree(x,child,dp) ;
         
         count= count +  dp[x]   ;
     }
     
     dp[child] = count ;
 
 }

public static void depth(int child ,int par , int[] dp , int d )
 {
    dp[child] =d ;
     
     for(int x : tree[child])
     {
         
         if(x== par)continue  ;
         
         depth(x,child,dp,d+1) ;
         
     }
 
 }

public static void dfs(int sv , boolean[] vis)
{
    vis[sv] = true  ;
    
    
    for(int x : tree[sv])
    {
        if( !vis[x])
        {
            dfs(x ,vis) ;
        }
    }
    
    
    
    
}









public static void solve()
{
FastReader scn = new FastReader() ;










ArrayList<Long> list = new ArrayList<>() ;
ArrayList<Long> listl = new ArrayList<>() ;
ArrayList<Integer> lista = new ArrayList<>() ;
ArrayList<Integer> listb = new ArrayList<>() ;



HashMap<Integer,Integer> map = new HashMap<>() ;




HashMap<Integer,Integer> map1  = new HashMap<>() ;
HashMap<Integer,Integer> map2  = new HashMap<>() ;









Set<Integer> set = new HashSet<>() ;


 Set<Integer> setx = new HashSet<>() ;
 Set<Integer> sety = new HashSet<>() ;

StringBuilder sb =new StringBuilder("") ;








































int testcases = 1; 
 testcases = scn.nextInt() ;
for(int testcase =1  ; testcase <= testcases ;testcase++)
{
    
 

 

 












 


































long n= scn.nextLong() ; long k = scn.nextLong() ;
long d1 = scn.nextLong() ; long d2 = scn.nextLong() ;
 

if(n %3 !=0)out.println("no") ;

else{
    
   
   int[] arr1 ={1,-1} ; int[] arr2 = {1,-1} ;
    
    boolean ans = false  ;
    
    for(int x : arr1)
    {
        for(int y :  arr2)
        {
            
            long x1 = k+ (2*x*d1)+(y*d2)  ;
            
            long x2 = k-(x*d1)+(y*d2) ;
            
            long x3 = k-(x*d1)-(2*y*d2) ; 
            
            
            
            
            if(x1 % 3 != 0 || x2 % 3 != 0 || x3 % 3 != 0 )continue  ;
            
            x1/=3;x2/=3 ;x3/=3 ;
            
            if(x1 <0 || x2 <0 ||x3 <0 || x1 >k ||x2 >k || x3 >k)continue ;
            
            
            
            if(x1 <=n/3 && x2 <=n/3 && x3 <=n/3)
            {
                ans = true  ;
            }
            
        }
        
        
    }
    
   
   if(ans)out.println("yes") ;else out.println("no") ; 
}
 


sb.delete(0 , sb.length()) ;
list.clear() ;listb.clear() ;
map.clear() ;
map1.clear() ;
map2.clear() ;
set.clear() ;sety.clear() ;

} 



out.flush() ;  
} 



public static void main (String[] args) throws java.lang.Exception
{
  

solve() ;
      
}


}
  
 class Pair 
{
  int first ;
  
  int second  ;
  
  
 
    
      
@Override
	public String toString() {
	
	String ans = "" ;
	ans  += this.first ;
	ans += " ";
	ans += this.second ;
	
	return ans  ;
	}


}


