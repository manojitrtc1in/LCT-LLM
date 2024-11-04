




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
		private int curChar, id2;
 
		public InputReader(InputStream st) {
			this.stream = st;
		}
 
		public int read() {
			if (id2 == -1)
				throw new InputMismatchException();
			if (curChar >= id2) {
				curChar = 0;
				try {
					id2 = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (id2 <= 0)
					return -1;
			}
			return buf[curChar++];
		}
 
		public int ni() {
			int c = read();
			while (id1(c)) {
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
			} while (!id1(c));
			return res * sgn;
		}
 
		public long nl() {
			int c = read();
			while (id1(c)) {
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
			} while (!id1(c));
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
			while (id1(c)) {
				c = read();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id1(c));
			return res.toString();
		}
 
		public String nextLine() {
			int c = read();
			while (id1(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id4(c));
			return res.toString();
		}
 
		public boolean id1(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
 
		private boolean id4(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
 
	}
	
 
	
	
	
    static long mod=1000000007;
    static BigInteger bigInteger = new BigInteger("1000000007");
    static int n = (int)1e7;
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
        static int x1;
        static int y1;
        static int x2;
        static int y2;
    public static void main(String[] args)
    {
        
        InputReader sc = new InputReader(System.in);
        

    
        
        prime  = new boolean[n + 1];
		sieve();
		prime[1] = false;
		
		
		
       
          
         

       

       
    

   

     



   

 
        int x = sc.ni();
        
                int []a = sc.nia(2*x);
                ArrayList<Integer> a1 = new ArrayList<>();
                 ArrayList<Integer> p = new ArrayList<>();
                ArrayList<Integer> a2 = new ArrayList<>();
                
                  
                for(int i=2;i<10000000;i++)
                {
                    if(prime[i])
                    {
                        p.add(i);
                    }
                }
                
                ArrayList<Integer> res = new ArrayList<>();
                
                
                HashMap<Integer,Integer> hm = new HashMap<>();
                for(int i=1;i<=2750131;i++)
                {
                    hm.put(i, 0);
                }
                for(int i=0;i<2*x;i++)
                {
                    a2.add(a[i]);
                    if(!hm.containsKey(a[i]))
                        hm.put(a[i], 1);
                    else
                        hm.put(a[i], hm.get(a[i])+1);
                }
                int []primei = new int[2750132];
              

                Collections.sort(a2);
            for(int i=2;i<=2750131;i++)
            {
                if(prime[i])
                {
                    for(int j = 2;i*j<=2750131;j++)
                    {
                        if(primei[i*j] == 0)
                        primei[i*j] = i; 
                    }
                }
            }
            int []prime2 = new int[2750132];
            int index = 1;
            for(int i=2;i<=2750131;i++)
            {
                if(prime[i])
                {
                    prime2[i] = index++;
                }
            }
            

            for(int i = 2750131; i >= 2; i--)
		{
			if(hm.get(i) > 0)
			{
				if(prime[i])
				{
					for(int j = 0; j < hm.get(i); j++)
						res.add(prime2[i]);
					hm.put(prime2[i],hm.get(prime2[i])-hm.get(i));
					hm.put(i, 0);
				}
				else
				{
					for(int j = 0; j < hm.get(i); j++)
					     res.add(i);
                                        hm.put(i/primei[i],hm.get(i/primei[i])-hm.get(i));
					hm.put(i, 0);
				}
			}
		}
		for(int i=0;i<res.size();i++)
                {
                    w.print(res.get(i) + " ");
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
        

       
        int y;
        int z;
        
        Student(int id,int y,int z)
        {
            this.id = id;
            

            

            this.y = y;
          this.z = z;
            
            
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
    static int id3(int n)
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
 






 
static class id6 { 
	boolean id7(String pat, String txt) 
	{ 
            int f = 0;
		int M = pat.length(); 
		int N = txt.length(); 
 
		

		

		int lps[] = new int[M]; 
		int j = 0; 

 
		

		

		id0(pat, M, lps); 
 
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
 
	void id0(String pat, int M, int lps[]) 
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
 
   static class id5 implements Comparator<Student>{
    public int compare(Student a, Student b)
    {
        if(a.y < b.y)
            return -1;
        else if(a.y > b.y)
            return 1;
        else
        {
            if(a.z < b.z)
                return -1;
            else
                return 1;
              
        }
    }
   }
   static void checkCollision(int a, int b, int c,  
                               int x, int y, int radius) 
    { 
        

        double dist = (Math.abs(a * x + b * y + c)) /  
                        Math.sqrt(a * a + b * b); 
      
        

        

        if (radius == dist) 
        {
           double dis = (double)Math.sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
           DecimalFormat df = new DecimalFormat("0.000000");
        w.println(df.format(dis));
        

        }
        else if (radius > dist)
        {
            
        double x11 = (double)x1;
        double y11 = (double)y1;
        double x22 = (double)x2;
        double y22 = (double)y2;
        double up = 2*x11*y11/(((x11*x11) - ((double)radius*(double)radius)));
        up *= up;
        
     double denm = ((y11*y11) - ((double)radius*(double)radius))/((x11*x11) - ((double)radius*(double)radius));
     up -= (4*denm);
     up = Math.sqrt(up);
     double theta = 0.0;
     
     denm += 1.0;
     if(denm!=0.00000000)
      theta = Math.atan(up/denm);
     else 
         theta = Math.PI/(double)2;
     

     

     
       up = 2*x22*y22/(((x22*x22) - ((double)radius*(double)radius)));
       up *= up;
     denm = ((y22*y22) - ((double)radius*(double)radius))/((x22*x22) - ((double)radius*(double)radius));
      up -= (4*denm);
     up = Math.sqrt(up);
     denm += 1.0;
      double theta1 = 0.0;
     
    

     if(denm!=0.00000000)
      theta1 = Math.atan(up/denm);
     else 
         theta1 = Math.PI/(double)2;
     theta /= 2;
     theta1 /= 2;
     double re = theta +theta1;
     re = re * (double) radius;
     double eq1 = (x11*x11) + (y11*y11) - ((double)radius*(double)radius);
     double eq2 = (x22*x22) + (y22*y22) - ((double)radius*(double)radius);
     double t1 = Math.sqrt(eq1);
     double t2 = Math.sqrt(eq2);
     double res = re + t1 + t2;
    

     

     
     
     DecimalFormat df = new DecimalFormat("0.000000");
        w.println(df.format(res));
        
     
     
    
     
        
        }
        else
        {
             double x11 = (double)x1;
              double y11 = (double)y1;
               double x22 = (double)x2;
                double y22 = (double)y2;
                double midx = (x11+x22)/4;
                double midy = (y11+y22)/4;
                 double dis = (double)Math.sqrt(((x22-midx)*(x22-midx)) + ((y22-midy)*(y22-midy)));
                 double dis1 = (double)Math.sqrt(((x11-midx)*(x11-midx)) + ((y11-midy)*(y11-midy)));
                 dis += dis1;
                  DecimalFormat df = new DecimalFormat("0.000000");
        w.println(df.format(dis));
             
        }
    } 
					 
}