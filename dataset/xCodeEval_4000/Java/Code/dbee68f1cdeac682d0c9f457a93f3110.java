import java.util.*;
import java.util.Map.Entry;


import java.io.*;
import java.math.*;
import static java.util.stream.Collectors.*;
import static java.util.Map.Entry.*;


public class Main
{
	public static void main (String[] args) throws Exception
	{
		final long mod=(long) (1e9+7);  
		final long mod1=(long) 998244353;
		Reader s=new Reader();
		  PrintWriter pt=new PrintWriter(System.out);
		  
		  BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		  int T=s.nextInt();




		  while(T-->0)
		  {
			  int n=s.nextInt();
			  int arr[]=new int[n];
			  int brr[]=new int[n];
			  int e=-1;
			  for(int i=0;i<n;i++) {
				  arr[i]=s.nextInt();
				  if(e==-1) {
					  brr[e+1]=arr[i];
					  e++;
				  }
				  else {
					  if(arr[i]==1) {
						  e++;
						  brr[e]=arr[i];
					  }
					  else {
						  int j=e;
						  for(j=e;j>=0;j--) {
							  if((arr[i]-1)==brr[j])
								  break;
						  }
						  e=j;
						  brr[e]=arr[i];
					  }
				  }
				  pt.print(brr[0]);
				  for(int j=1;j<=e;j++) {
					  pt.print("."+brr[j]);
				  }
				  pt.println();
			  }
			  
			  
			  
			  
		      
	    	  
		  }
			  
		      
		  
		  pt.close();
	}
	
	static boolean allOne(String str) {
		for(int i=0;i<str.length();i++) {
			if(str.charAt(i)=='0')
				return false;
		}
		return true;
	}
    
	
	static boolean isPartition(int arr[], int n) {
		int sum = 0;
	    int i, j;
	 
	    

	    for (i = 0; i < n; i++)
	        sum += arr[i];
	 
	    if (sum % 2 != 0)
	        return false;
	 
	    boolean part[][]=new boolean[sum/2+1][n+1];
	 
	    

	    for (i = 0; i <= n; i++)
	        part[0][i] = true;
	 
	    

	    for (i = 1; i <= sum / 2; i++)
	        part[i][0] = false;
	 
	    

	    for (i = 1; i <= sum / 2; i++) {
	        for (j = 1; j <= n; j++) {
	            part[i][j] = part[i][j - 1];
	            if (i >= arr[j - 1])
	                part[i][j] = part[i][j]
	                             || part[i - arr[j - 1]][j - 1];
	        }
	    }
	    return part[sum / 2][n];
	}
	
	static int setBit(int S, int j) { return S | 1 << j; }

	static int clearBit(int S, int j) { return S & ~(1 << j); }

	static int toggleBit(int S, int j) { return S ^ 1 << j; }

	static boolean isOn(int S, int j) { return (S & 1 << j) != 0; }

	static int turnOnLastZero(int S) { return S | S + 1; }
	
	static int turnOnLastConsecutiveZeroes(int S) { return S | S - 1; }
	
	static int turnOffLastBit(int S) { return S & S - 1; }
	
	static int turnOffLastConsecutiveBits(int S) { return S & S + 1; }

	static int lowBit(int S) { return S & -S; }

	static int setAll(int N) { return (1 << N) - 1; }

	static int modulo(int S, int N) { return (S & N - 1); }		 


	static boolean isPowerOfTwo(int S) { return (S & S - 1) == 0; }
	
	static boolean isWithin(long x, long y, long d, long k) {
		return x*k*x*k + y*k*y*k <= d*d;
	}
	
	static long modFact(long n, 
            long p) 
	{ 
		if (n >= p) 
		 return 0; 
		
		long result = 1; 
		for (int i = 1; i <= n; i++) 
		 result = (result * i) % p; 
		
		return result; 
	} 
	static int sum(int[] arr, int n)
	{
	    int inc[]=new int[n+1];
	    int dec[]=new int[n+1];
	    inc[0] = arr[0];
	    dec[0] = arr[0];

	    for (int i = 1; i < n; i++) {
	        for (int j = 0; j < i; j++) {
	            if (arr[j] > arr[i]) {
	                dec[i] = max(dec[i], inc[j] + arr[i]);
	            }
	            else if (arr[i] > arr[j]) {
	                inc[i] = max(inc[i], dec[j] + arr[i]);
	            }
	        }
	    }
	    return max(inc[n - 1], dec[n - 1]);
	}
	static long nc2(long a) {
		return a*(a-1)/2;
	}
	public static int numberOfprimeFactors(int n) 
    { 
        

		HashSet<Integer> hs = new HashSet<Integer>();
        while (n%2==0) 
        { 
            hs.add(2);
            n /= 2; 
        } 
  
        

        

        for (int i = 3; i <= Math.sqrt(n); i+= 2) 
        { 
            

            while (n%i == 0) 
            { 
                hs.add(i);
                n /= i; 
            } 
        } 
  
        

        

        if (n > 2) 
            hs.add(n);
        return hs.size();
    } 
	static long gcd(long a, long b) 
    { 
      if (b == 0) 
        return a; 
      return gcd(b, a % b);  
    } 




	

	static void reverse(int arr[],int start, int end) 
	{ 
		int temp; 
		   
		while (start < end) 
		{ 
		    temp = arr[start];  
		    arr[start] = arr[end]; 
		    arr[end] = temp; 
		    start++; 
		    end--; 
		}  
	}  
	static void reverse(long arr[],int start, int end) 
	{ 
		long temp; 
		   
		while (start < end) 
		{ 
		    temp = arr[start];  
		    arr[start] = arr[end]; 
		    arr[end] = temp; 
		    start++; 
		    end--; 
		}  
	}  
	static boolean isPrime(int n) 
    { 
        

        if (n <= 1) return false; 
        if (n <= 3) return true; 
      
        

        

        if (n % 2 == 0 || n % 3 == 0) return false; 
      
        for (int i = 5; i * i <= n; i = i + 6) 
            if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
      
        return true; 
    } 
	static int p2(int n) {
		int k=0;
		while(n>1) {
			if(n%2!=0)
				return k;
			n/=2;
			k++;
		}
		return k;
	}
	static boolean isp2(int n) {
		while(n>1) {
			if(n%2==1)
				return false;
			n/=2;
		}
		return true;
	}
	static int binarySearch(int arr[], int first, int last, int key){  
		   int mid = (first + last)/2;  
		   while( first <= last ){  
		      if ( arr[mid] < key ){  
		        first = mid + 1;     
		      }else if ( arr[mid] == key ){  
		        return mid;  
		      }else{  
		         last = mid - 1;  
		      }  
		      mid = (first + last)/2;  
		   }  
		   return -1;
		 }  

	static void print(int a[][]) {
		for(int i=0;i<a.length;i++)
		{
			for(int j=0;j<a[0].length;j++)
				System.out.print(a[i][j]+" ");
			System.out.println();
		}
	}
	static int max (int x, int y) {
		return (x > y)? x : y;
	} 
	static int search(Pair[] p, Pair pair) {
		int l=0, r=p.length;
		while (l <= r) { 
	        int m = l + (r - l) / 2;
	        if (p[m].compareTo(pair)==0) 
	            return m; 
	        if (p[m].compareTo(pair)<0) 
	            l = m + 1; 
	        else
	            r = m - 1;
	    }
	    return -1;
	}
	static void pa(int a[])
	{
		for(int i=0;i<a.length;i++)
			System.out.print(a[i]+" ");
		System.out.println();
		
	}
	static void pa(long a[])
	{
		for(int i=0;i<a.length;i++)
			System.out.print(a[i]+" ");
		System.out.println();
		
	}
	static void reverseArray(int arr[], 
            int start, int end) 
	{ 
		int temp; 
		   
		while (start < end) 
		{ 
		    temp = arr[start];  
		    arr[start] = arr[end]; 
		    arr[end] = temp; 
		    start++; 
		    end--; 
		}  
	}     
	static boolean isPalindrome(String s) {
		int l=s.length();
		for(int i=0;i<l/2;i++)
		{
			if(s.charAt(i)!=s.charAt(l-i-1))
				return false;
		}
		return true;
	}
	static long nc2(long n, long m) {
		return (n*(n-1)/2)%m;
	}
	static long c(long a) {
		return a*(a+1)/2;
	}
	static int next(long[] arr, long target)  
    {  
        int start = 0, end = arr.length - 1;  
    
        int ans = -1;  
        while (start <= end) {  
            int mid = (start + end) / 2;  
    
            

            

            if (arr[mid] < target) {
                start = mid + 1;  
            }  
    
            

            else {  
                ans = mid;  
                end = mid - 1;  
            }  
        }  
        return ans;  
    } 
	
	static int prev(long[] arr, long target)  
    {  
        int start = 0, end = arr.length - 1;  
    
        int ans = -1;  
        while (start <= end) {  
            int mid = (start + end) / 2;  
    
            

            

            if (arr[mid] > target) {
                end = mid - 1;  
            }  
    
            

            else {  
                ans = mid;  
                start = mid + 1;  
            }  
        }  
        return ans;  
    } 

	static long power(long x, long y, long p) 
    { 
        long res = 1; 
        x = x % p; 
                      
        while (y > 0) 
        { 
            if (y % 2 == 1) 
                res = (res * x) % p; 
            y = y >> 1;
            x = (x * x) % p; 
        } 
        return  res; 
    } 
    static long modInverse(long n, long p) 
    { 
        return power(n, p-2, p); 
    } 
    static long nCrModP(long n, long r, 
                                    long p) 
    { 
        if(r>n)
        	return 0;
    	if (r == 0) 
            return 1; 
        long[] fac = new long[(int) (n+1)]; 
        fac[0] = 1; 
        for (int i = 1 ;i <= n; i++) 
            fac[i] = fac[i-1] * i % p;
        return (fac[(int) n]* modInverse(fac[(int) r], p) 
                % p * modInverse(fac[(int) (n-r)], p) 
                                    % p) % p; 
    } 
	static String reverse(String str)
	{
		return new StringBuffer(str).reverse().toString();
	}



	static long fastpow(long x, long y, long m)  
    { 
        if (y == 0) 
            return 1; 
          
        long p = fastpow(x, y / 2, m) % m; 
        p = (p * p) % m; 
      
        if (y % 2 == 0) 
            return p; 
        else
            return (x * p) % m; 
    } 
	
	static boolean isPerfectSquare(long l)
	{
		return Math.pow((long)Math.sqrt(l),2)==l;
	}
	
	
	static void merge(long[] arr, int l, int m, int r) 
    { 
        

        int n1 = m - l + 1; 
        int n2 = r - m; 
  
        
        long L[] = new long [n1]; 
        long R[] = new long [n2]; 
  
        
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
  
    

    

    static void sort(int arr[], int l, int r) 
    { 
        if (l < r) 
        { 
            

            int m = (l+r)/2; 
  
            

            sort(arr, l, m); 
            sort(arr , m+1, r); 
  
            

            merge(arr, l, m, r); 
        } 
    } 
	static void merge(int arr[], int l, int m, int r) 
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
  
    

    

    static void sort(long arr[], int l, int r) 
    { 
        if (l < r) 
        { 
            

            int m = (l+r)/2; 
  
            

            sort(arr, l, m); 
            sort(arr , m+1, r); 
  
            

            merge(arr, l, m, r); 
        } 
    } 
    static class Pair implements Comparable<Pair>{
        int a;
        int b;
        Pair(int a,int b){
            this.a=a;
 
            this.b=b;
        }   
        public int compareTo(Pair p){
            if(a>p.a)
                return 1;
            if(a==p.a)
                return (b-p.b);
            return -1;
        }
    }
	static class Reader 
    { 
        final private int BUFFER_SIZE = 1 << 16; 
        private DataInputStream din; 
        private byte[] buffer; 
        private int bufferPointer, bytesRead; 
  
        public Reader() 
        { 
            din = new DataInputStream(System.in); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public Reader(String file_name) throws IOException 
        { 
            din = new DataInputStream(new FileInputStream(file_name)); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public String readLine() throws IOException 
        { 
            byte[] buf = new byte[128]; 

            int cnt = 0, c; 
            while ((c = read()) != -1) 
            { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt); 
        } 
  
        public int nextInt() throws IOException 
        { 
            int ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do
            { 
                ret = ret * 10 + c - '0'; 
            }  while ((c = read()) >= '0' && c <= '9'); 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public long nextLong() throws IOException 
        { 
            long ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public double nextDouble() throws IOException 
        { 
            double ret = 0, div = 1; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
  
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
  
            if (c == '.') 
            { 
                while ((c = read()) >= '0' && c <= '9') 
                { 
                    ret += (c - '0') / (div *= 10); 
                } 
            } 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        private void fillBuffer() throws IOException 
        { 
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
            if (bytesRead == -1) 
                buffer[0] = -1; 
        } 
  
        private byte read() throws IOException 
        { 
            if (bufferPointer == bytesRead) 
                fillBuffer(); 
            return buffer[bufferPointer++]; 
        } 
  
        public void close() throws IOException 
        { 
            if (din == null) 
                return; 
            din.close(); 
        } 
    } 
}