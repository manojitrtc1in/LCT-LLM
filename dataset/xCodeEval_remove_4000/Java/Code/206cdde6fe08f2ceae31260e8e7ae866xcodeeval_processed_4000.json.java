import java.util.*;
import java.util.Map.Entry;


import java.io.*;
import java.math.*;
import static java.util.stream.Collectors.*;
import static java.util.Map.Entry.*;


public class Main
{
	public static void main (String[] args) throws IOException
	{
		final long mod=1000000007;  


		  PrintWriter pt=new PrintWriter(System.out);
		  BufferedReader br=new BufferedReader(new InputStreamReader(System.in));


		  int T=Integer.parseInt(br.readLine());


		  while(T-->0)
		  {
			  int n=Integer.parseInt(br.readLine());
			  char ch[]=br.readLine().toCharArray();
			  int k=0;
			  for(int i=0;i<n-6;i++) {
				  if(y(ch,i))
					  k++;
			  }
			  if(k>1) {
				  pt.println("No");
			  }
			  else {
				  if(k==1)
				  {
					  pt.println("Yes");
					  for(int i=0;i<n;i++)
						  pt.print(ch[i]=='?'?'x':ch[i]);
					  pt.println();
				  }
				  else {
					  int i;
					  for(i=0;i<n-6;i++) {


						  if(yy(ch,i)) {
							  if(abac(ch,i-4)||abacab(ch,i-6)||caba(ch,i+4)||bacaba(ch,i+6))
								  continue;
							  else
								  break;
						  }
							  
					  }
					  if(i==n-6)
						  pt.println("No");
					  else
					  {
						  pt.println("Yes");
						  for(int j=0;j<i;j++)
							  pt.print(ch[j]=='?'?'x':ch[j]);
						  pt.print("abacaba");
						  for(int j=i+6+1;j<n;j++)
							  pt.print(ch[j]=='?'?'x':ch[j]);
						  pt.println();
					  }
				  }
			  }
			  
			  
		  }
		  pt.close();
	}
	static boolean y(char ch[], int i) {
		return x(ch,i)&&x(ch,i+4)&&ch[i+3]=='c';
	}
	static boolean x(char ch[], int p) {
		return ch[p]=='a'&&ch[p+1]=='b'&&ch[p+2]=='a';
	}
	static boolean yy(char ch[], int i) {
		if(i>=ch.length-6)
			return false;
		else
		return xx(ch,i)&&xx(ch,i+4)&&(ch[i+3]=='c'||ch[i+3]=='?');
	}
	static boolean caba(char ch[], int p) {
		if(p>=ch.length-6)
			return false;
		else
		return ch[p+3]=='c'&&ch[p+4]=='a'&&ch[p+5]=='b'&&ch[p+6]=='a';
	}
	static boolean bacaba(char ch[], int p) {
		if(p>=ch.length-6)
			return false;
		else
		return ch[p+1]=='b'&&ch[p+2]=='a'&&ch[p+3]=='c'&&ch[p+4]=='a'&&ch[p+5]=='b'&&ch[p+6]=='a';
	}
	static boolean abac(char ch[], int p) {
		if(p<0)
			return false;
		else
		return ch[p]=='a'&&ch[p+1]=='b'&&ch[p+2]=='a'&&ch[p+3]=='c';
	}
	static boolean abacab(char ch[], int p) {
		if(p<0)
			return false;
		else
		return ch[p]=='a'&&ch[p+1]=='b'&&ch[p+2]=='a'&&ch[p+3]=='c'&&ch[p+4]=='a'&&ch[p+5]=='b';
	}
	static boolean xx(char ch[], int p) {
		return (ch[p]=='a'||ch[p]=='?')&&(ch[p+1]=='b'||ch[p+1]=='?')&&(ch[p+2]=='a'||ch[p+2]=='?');
	}
	static int g(char ch[], int l, int r, char c) {
		int n=r-l+1;


		if(n==2)
		{
			if(ch[r]==c&&ch[l]==c+1)
				return 0;
			else if(ch[r]==c+1&&ch[l]==c)
				return 0;
			else if(ch[r]==c||ch[l]==c||ch[r]==c+1||ch[l]==c+1)
				return 1;
			else
				return 2;
		}
		else
		{
			Pair p = f(ch, l, r, c);


			return Math.min(p.a+g(ch, l+n/2, r, (char)(c+1)), p.b+g(ch, l, r-n/2, (char)(c+1)));




		}
		
	}
	static Pair f(char ch[], int l, int r, char c) {
		int k=0;
		int n=(r-l+1);


		for(int i=l;i<l+n/2;i++)
		{
			if(ch[i]==c)
				k++;
		}
		int j=0;
		for(int i=l+n/2;i<=r;i++)
		{
			if(ch[i]==c)
				j++;
		}
		int a=n/2-k;
		int b=n/2-j;


		return new Pair(a,b);
		
	}
	static boolean check(int arr[], int n) {
		for(int i=0;i<n;i++)
			if(arr[i]!=i)
				return false;
		return true;
	}
	static int mex(int arr[], int n) {
		HashSet<Integer> hs=new HashSet<Integer>();
		for(int i=0;i<n;i++)
			hs.add(arr[i]);
		for(int i=0;i<n;i++)
			if(!hs.contains(i))
				return i;
		return n;
	}
	
	static long no(long n) {
		return n*(n+1)/2;
	}
	static void reverse(int arr[], 
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
	static double gt(double x, double h, double c, double t) {
		return (x*h+(x-1)*c)/(2*x-1);
	}
	static long sq(long x) {
		return x*(x+1)*(2*x+1)/6;
	}
	static long cu(long x) {
		return x*x*(x+1)*(x+1)/4;
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
	static int next(int[] arr, int target)  
    {  
        int start = 0, end = arr.length - 1;  
    
        int ans = -1;  
        while (start <= end) {  
            int mid = (start + end) / 2;  
    
            

            

            if (arr[mid] <= target) {  
                start = mid + 1;  
            }  
    
            

            else {  
                ans = mid;  
                end = mid - 1;  
            }  
        }  
        return ans;  
    }  
	static String toString(char [] c)
	{
		StringBuffer b=new StringBuffer("");
		for(int i=0;i<c.length;i++)
			b.append(c[i]);
		return b.toString();
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
    static long id1(long n, long r, 
                                    long p) 
    { 
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
	static String rev(String str)
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
	
	static boolean id0(long l)
	{
		return Math.pow((long)Math.sqrt(l),2)==l;
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
            byte[] buf = new byte[64]; 

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