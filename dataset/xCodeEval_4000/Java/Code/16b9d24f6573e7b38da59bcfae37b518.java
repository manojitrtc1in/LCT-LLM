




import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


 
public class TryB
{
    
    static class InputReader {
 
		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, snumChars;
 
		public InputReader(InputStream st) {
			this.stream = st;
		}
 
		public int read() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}
 
		public int ni() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}
 
		public long nl() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}
 
		public int[] nia(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = ni();
			}
			return a;
		}
 
		public String rs() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}
 
		public String nextLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}
 
		public boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
 
		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
 
	}
	

	
	
	
    static long mod=1000000007;
    static BigInteger bigInteger = new BigInteger("1000000007");
    static int n = (int)1e6;
    static boolean[] prime;
    static ArrayList<Integer> as;
     static ArrayList<Integer> []as1;
    static void sieve() {
			Arrays.fill(prime	, true);
			prime[0] = prime[1] = false;
			for(int i = 2 ; i * i <= n ; ++i) {
				if(prime[i]) {
					for(int k = i * i; k< n ; k+=i) {
						prime[k] = false;
					}
				}
			}
			
		}
		static PrintWriter w = new PrintWriter(System.out);
                static int p = 0;
 static char [][]sol;
    public static void main(String[] args)
    {
        
        InputReader sc = new InputReader(System.in);
        

    
        
        prime  = new boolean[n + 1];
		sieve();
		prime[1] = false;
		
		
		
       
          
         

       

       
    

   

     



   

 int x = sc.ni();
 int []a = sc.nia(x);
 int q = sc.ni();
  MergeSort ob = new MergeSort();
  ob.sort(a, 0, a.length-1);
  long []a1 = new long[x];
  for(int i=0;i<x;i++)
  {
      a1[i] = (long)a[i];
  }
  
  for(int i=1;i<x;i++)
  {
      a1[i] += a1[i-1];
  }
  while(q-- > 0)
  {
      int p = sc.ni();
      if(p!=x)
      w.println(a1[x-1] - (a1[x-p]-a1[x-p-1]));
      else
          w.println(a1[x-1]-a1[0]);
  }
 
   
   
   w.close();
        
  
    
    }
    
    static int []a;
    static long a1,b;
    public static int searchlow(int x) {
		int lo=0, hi=a.length-1;
		int res=Integer.MIN_VALUE;
		while(lo<=hi){
	        int mid = (lo+hi)/2;
	        if(a[mid]==x){
	            res = mid;
	            hi = mid - 1;
	        }
	        else if(a[mid]>x){
	            hi = mid - 1;
	        }
	        else{
	            lo = mid + 1;
	        }
	    }
	    return res==Integer.MIN_VALUE?lo:res;
	}
	public static int searchhigh(int x) {
		int lo=0, hi=a.length-1;
		int res=Integer.MIN_VALUE;
		while(lo<=hi){
	        int mid = (lo+hi)/2;
	        if(a[mid]==x){
	            res = mid;
	            lo=mid+1;
	        }
	        else if(a[mid]>x){
	            hi = mid - 1;
	        }
	        else{
	            lo = mid + 1;
	        }
	    }
	    return res==Integer.MIN_VALUE?hi:res;
	}
	public static long ct(int l, int r) {
		int lo=searchlow(l), hi=searchhigh(r);
		return hi-lo+1;
	}
    static long log2(long value) {
    return Long.SIZE-Long.numberOfLeadingZeros(value);
}
   
    static class Student
    {
        int id;
        

       String s;
        int y;
        
        Student(int id,String s,int y)
        {
            this.id = id;
            

            this.s = s;
            this.y = y;
            
            
            
        }
        
    }
     
     public static long modMultiply(long one, long two) {
 
		return (one % mod * two % mod) % mod;
	}
    static long fx(int m)
    {
        long re = 0;
        for(int i=1;i<=m;i++)
        {
            re += (long) (i / gcd(i,m));
        }
        return re;
    }
     static int gcd(int a, int b)
    {
	 if (a == 0)
	  return b;
				         
	return gcd(b%a, a);
    }
    
   
    
     static long phi(long nx)
    {
        

        double result = nx; 
        
     
        

        

        

        for (int p = 0; as.get(p) * as.get(p) <= nx; ++p)
        {
            

            if (nx % as.get(p) == 0)
            {
                

                while (nx % as.get(p) == 0)
                    nx /= as.get(p);
                result *= (1.0 - (1.0 / (double) as.get(p)));
            }
        }
     
        

        

        if (nx > 1)
            result *= (1.0 - (1.0 / (double) nx));
     
        return (long)result;
    
        
        

        
    }
    
    public static void primeFactors(int n,int x)
    {
        as = new ArrayList<>();
       
        

        while (n%2==0)
        {
            
        
            as.add(2);
            

            n /= 2;
            
        }
 
        

        

        for (int i = 3; i <= Math.sqrt(n); i+= 2)
        {
            

            while (n%i == 0)
            {
            
               

                
                as.add(i);
                n /= i;
             
                
            }
            
        }
 
        

        

        if (n >= 2)
        {
          
            as.add(n);
        }
           
    }
    static int digitsum(int x)
    
    {    
 
        int sum = 0;
        while(x > 0)
        {
            int temp = x % 10;
            sum += temp;
            x /= 10;
        }
        return sum;
        
    }
    static int countDivisors(int n)
    {
        int cnt = 0;
        for (int i = 1; i*i <=n; i++)
        {
             if (n % i == 0 && i<=1000000)
             {
                

                

                if (n / i == i)
                   cnt++;
      
                else 

                    cnt = cnt + 2;
             }
         }
        return cnt;
    }
   
    static boolean isprime(long n)
    {
    
    if(n == 2)
        return true;
    if(n == 3)
        return true;
    if(n % 2 == 0)
        return false;
    if(n % 3 == 0)
        return false;
 
    long i = 5;
   long w = 2;
 
    while(i * i <= n)
    {
        if(n % i == 0)
            return false;
    
 
        i += w;
        w = 6 - w;
    }
 
    return true;
    }
    
   
 
 
    
    
    static boolean binarysearch(int []arr,int p,int n)
    {
        

        

        

        boolean re = false;
        int st = 0;
        int end = n-1;
        
        
        
        while(st <= end)
        { 
            int mid = (st+end)/2;
        
            if(p > arr[mid])
            {
                st = mid+1;
                
            }
            else if(p < arr[mid])
            {
                end = mid-1;
                
            }
            else if(p == arr[mid])
            {
            
            re = true;
            break;
            }
           
            
            
        }
         return re;
        
    }
    
   
    
    
static class MergeSort
{
    

    

    

    void merge(int arr[], int l, int m, int r)
    {
        

        int n1 = m - l + 1;
        int n2 = r - m;
 
        
        int L[] = new int [n1];
        int R[] = new int [n2];
 
        
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
 
    

    

    void sort(int arr[], int l, int r)
    {
        if (l < r)
        {
            

            int m = (l+r)/2;
 
            

            sort(arr, l, m);
            sort(arr , m+1, r);
 
            

            merge(arr, l, m, r);
        }
    }
 
    
    
 
   
}
    

    
    
    
    public static int ip(String s){
		return Integer.parseInt(s);
	}
	 public static String ips(int s){
		return Integer.toString(s);
	}
	
         



static class HeapAlgo
{
   

	

	void printArr(int a[], int n)
	{
	    
	    
		for (int i=0; i<n; i++)
		{
			System.out.print(a[i] + " ");
		as1[p].add(a[i]);
		}
                p++;
                
		

	}

	

	void heapPermutation(int a[], int size, int n)
	{
		

		

		
		if (size == 1)
		{
			printArr(a,n);
			
		}

		for (int i=0; i<size; i++)
		{
			heapPermutation(a, size-1, n);
                        p++;

			

			

			if (size % 2 == 1)
			{
				int temp = a[0];
				a[0] = a[size-1];
				a[size-1] = temp;
			}

			

			

			else
			{
				int temp = a[i];
				a[i] = a[size-1];
				a[size-1] = temp;
			}
		}
	}
        public static int lowerBound(int[] array, int length, int value) {
        int low = 0;
        int high = length-1;
        while (low < high) {
            final int mid = (low + high) / 2;
            if (value <= array[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
  }
  public static int upperBound(int[] array, int length, int value) {
        int low = 0;
        int high = length-1;
        while (low < high) {
            final int mid = (low + high) / 2;
            if (value >= array[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

	

	
		
	
}








static class KMP_String_Matching { 
	boolean KMPSearch(String pat, String txt) 
	{ 
            int f = 0;
		int M = pat.length(); 
		int N = txt.length(); 

		

		

		int lps[] = new int[M]; 
		int j = 0; 


		

		

		computeLPSArray(pat, M, lps); 

		int i = 0; 

		while (i < N) { 
			if (pat.charAt(j) == txt.charAt(i)) { 
				j++; 
				i++; 
			} 
			if (j == M) { 
                            
                            f = 1;
                           

				j = lps[j - 1]; 
			} 

			

			else if (i < N && pat.charAt(j) != txt.charAt(i)) { 
				

				

				if (j != 0) 
					j = lps[j - 1]; 
				else
					i = i + 1; 
			} 
		} 
                if(f==0)
                    return false;
                else
                    return true;
	} 

	void computeLPSArray(String pat, int M, int lps[]) 
	{ 
		

		int len = 0; 
		int i = 1; 
		lps[0] = 0; 


		

		while (i < M) { 
			if (pat.charAt(i) == pat.charAt(len)) { 
				len++; 
				lps[i] = len; 
				i++; 
			} 
			else 

			{ 
				

				

				

				if (len != 0) { 
					len = lps[len - 1]; 

					

					

				} 
				else 

				{ 
					lps[i] = len; 
					i++; 
				} 
			} 
		} 
	} 

	

        
} 


static class multipliers implements Comparator<Integer>{
  
  public int compare(Integer a,Integer b) {
   if(a<b)
    return -1;
   else if(b<a)
    return 1;
   else
    return 0;
  }
 }

    
					 
}
