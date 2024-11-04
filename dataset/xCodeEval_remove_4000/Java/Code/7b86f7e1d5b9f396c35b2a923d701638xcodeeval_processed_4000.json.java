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



 
 public static int id1(long n)
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



public static boolean id4(long n) 
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
      if(a %2 ==0 && b % 2 == 0)return true ;
      else return false  ;
}




public static boolean id7(int a  ,int b , int c)
{
      if( a + b > c && c+b > a && a +c > b)return true  ;
      else return false  ;
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

public static void id6() 
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





public static long id0(long[] arr ,long sum )
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




 

    

    

    

    
    public static void id3(int[] arr ,int n )
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
    long ans=1;
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



  static final int MAXN = 100001; 
       
    
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
       























    static Vector<Integer> id8(int x) 
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









public static long id5(long[] arr)
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


public static long id5(int[] arr)
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

      

























public static long id2(int[] arr , int start , int end , int val)
{
      
      

      
      
      if(start >  end)return  0 ; 

      
      
      int mid = (start + end)/2  ;
      
      if(arr[mid] <=val)
      {
          return id2(arr,mid+1, end ,val) ; 
            
      }
      else{
            
         return id2(arr,start , mid -1,val) + end-mid+1 ;    
            
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







public static long power(int x  ,int n)
    {
        

        
        if(n==0)return 1 ;
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
	













public static void solve()
{
FastReader scn = new FastReader() ;









ArrayList<Long> list = new ArrayList<>() ;
ArrayList<Integer> lista = new ArrayList<>() ;
ArrayList<Integer> listb = new ArrayList<>() ;



HashMap<Long,Long> map = new HashMap<>() ;
HashMap<Integer,Integer> map1  = new HashMap<>() ;
HashMap<Integer,Integer> map2  = new HashMap<>() ;







Set<Integer> set = new HashSet<>() ;
Set<Integer> setx = new HashSet<>() ;
Set<Integer> sety = new HashSet<>() ;



















int t = 1; 




while(t-- > 0)
{

 



  

  

  

 
 
 int n = scn.nextInt() ;
 long x = scn.nextLong();


 



 











for(int i = 0;i <n ; i++)
{
    long temp = scn.nextLong() ;
    
   if(map.containsKey(temp))map.put(temp , map.get(temp) +1L ) ;
   else map.put(temp,1L) ;  
}


long ans  = 0L;

for(Long y:map.keySet())
{
    long cal = y ^x ;
    
    
    if(x==0)
    {
        ans = ans + (map.get(y)*(map.get(y) -1))/2 ;
    }
    
    else if(map.containsKey(cal))
    {
        
        ans = ans + (map.get(cal)*map.get(y));
        
        
       map.put(cal,0L) ; 
    }
    
    map.put(y , 0L) ;
}


out.println(ans) ;
























 
list.clear() ;
map.clear() ;
map1.clear() ;
map2.clear() ;
set.clear() ;
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


 