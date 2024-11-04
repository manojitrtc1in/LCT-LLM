

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.*;


public class Fourth{
	static long mod=1000000007;
	public static int lower_bound(long[] arr,int key) {
        int len = arr.length;
        int lo = 0;
        int hi = len-1;
        int mid = (lo + hi)/2;
        while (true) {
            long cmp = arr[mid]-key;
            if (cmp == 0 || cmp > 0) {
                hi = mid-1;
                if (hi < lo)
                    return mid;
            } else {
                lo = mid+1;
                if (hi < lo)
                    return mid<len-1?mid+1:-1;
            }
            mid = (lo + hi)/2;
        }
    }
    public static void main(String[] args) throws Exception{           	
    	 InputReader in = new InputReader(System.in);       
    	PrintWriter pw=new PrintWriter(System.out);   
    
    	

        

        	

        	int n=in.readInt();
        	int a=in.readInt();
        	int b=in.readInt();
        	

        	
    	long t=in.readLong();
    	
    	long ans=0;
    	long s1[]=new long[n];
        long s2[]=new long[n];
        long[] dp1=new long[n];
        long[] dp2=new long[n];
    	String a1=in.readString();
    	char c[]=a1.toCharArray();
    	long max=0;
       
    	   long[] dp=new long[n];
           for(int i=0;i<n;i++)
           {
               if(c[i]=='h')
               {
                   dp[i]=1;
               }
               else
               {
                   dp[i]=b+1;
               }
           }
     
           dp1[0]=dp[0];
           dp2[n-1]=dp[n-1];
           for(int i=n-2;i>0;i--)
           {
               dp2[i]=dp2[i+1]+dp[i];
           }
           for(int i=1;i<n;i++)
           {
               dp1[i]=dp1[i-1]+dp[i];
           }
          
           
           for(int i=0;i<n;i++)
           {
               ans=(long)(i*a)+dp1[i];
               int  r=n-1;
               int  l=i+1;
              
               int f=-1;
               
               while(l<=r)
               {
                   int mid=(l+r)/2;
                   if(l==r || r==l+1)
                   {
                	   int pos=min(i, n-l);
                       if(dp2[l]+ans+(long)pos*a+(long)(n-l)*a<=t)
                       {
                       f=l;
                       break;
                       }
                       int pos2=min(i, n-r);
                       if(dp2[r]+ans+pos2*a+(n-r)*a<=t)
                       {
                    	   
                           f=r;
                           break;
                       }
                       break;
                   }
                   if(dp2[mid]+ans+min(i,n-mid)*a+(n-mid)*a<=t)
                   {
                       f=mid;
                       r=mid-1;
                   }
                   else
                   {
                       l=mid+1;
                   }
                   
                   
               }
               if(ans<=t)
               {
                   max=max(max, i+1);
                   if(f!=-1)
                   {
                      
                       max=max(max, i+1+n-f);
                   }
               }
               
           }
           pw.println(max);

		  

    	
    	

    	    		
    	
    	pw.close();
    }
    
   
    public static BigInteger fact(int n)
    {
    	BigInteger x=BigInteger.valueOf(1);
    	for(int i=1;i<=n;i++)
    	{
    		x=x.multiply(BigInteger.valueOf(i));
    	}
    	return x;
    }
    
   	public static long comb(long n, long r, long m) 
   	{
   		long p1 = 1, p2 = 1;
   		for (long i = r + 1; i <= n; i++) {
   			p1 = (p1 * i) % m;
   		}
   		p2 = factMod(n - r, m);
   		p1 = divMod(p1, p2, m);
   		return p1 % m;
   	}
   
   	public static long divMod(long a, long b, long m) 
   	{
   		long c = powerMod(b, m - 2, m);
   		return ((a % m) * (c % m)) % m;
   	}
   
   	public static long factMod(long n, long m) {
   		long result = 1;
   		if (n <= 1)
   			return 1;
   		while (n != 1) {
   			result = ((result * n--) % m);
   		}
   		return result;
   	}
   
   	public static long powerMod(long a, long b, long c) {
   		long result = 1;
   		long temp = 1;
   		long mask = 1;
   		for (int i = 0; i < 64; i++) {
   			mask = (i == 0) ? 1 : (mask * 2);
   			temp = (i == 0) ? (a % c) : (temp * temp) % c;
   			
   			if ((b & mask) == mask) {
   				result = (result * temp) % c;
   			}
   		}
   		return result;
   	}
	static boolean isPrime(int number) {
        if (number <= 1) {
            return false;
        }
        if (number <= 3) {
            return true;
        }
        if (number % 2 == 0 || number % 3 == 0) {
            return false;
        }
        int i = 5;
        while (i * i <= number) {
            if (number % i == 0 || number % (i + 2) == 0) {
                return false;
            }
            i += 6;
        }
        return true;
    }
	
public static long gcd(long x,long y)
{
	if(x%y==0)
		return y;
	else
		return gcd(y,x%y);
}
	
public static int gcd(int x,int y)
{
	if(x%y==0)
		return y;
	else 
		return gcd(y,x%y);
}
public static int abs(int a,int b)
{
	return (int)Math.abs(a-b);
}
public static long abs(long a,long b)
{
	return (long)Math.abs(a-b);
}
public static int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
public static int min(int a,int b)
{
	if(a>b)
		return b;
	else 
		return a;
}
public static long max(long a,long b)
{
	if(a>b)
		return a;
	else
		return b;
}
public static long min(long a,long b)
{
	if(a>b)
		return b;
	else 
		return a;
}

static boolean id2 (long v) {
	return (v & (v - 1)) == 0;
}
public static long pow(long n,long p,long m)
{
	 long  result = 1;
	  if(p==0)
	    return 1;
	if (p==1)
	    return n;
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
public static long pow(long n,long p)
{
	long  result = 1;
	  if(p==0)
	    return 1;
	if (p==1)
	    return n;
	while(p!=0)
	{
	    if(p%2==1)
	        result *= n;	    
	    p >>=1;
	    n*=n;	    
	}
	return result;

}
static class Pair implements Comparable<Pair>
{
	int a,b;
	Pair (int a,int b)
	{
		this.a=a;
		this.b=b;
	}

	public int compareTo(Pair o) {
		

		if(this.a!=o.a)
		return Integer.compare(this.a,o.a);
		else
			return Integer.compare(this.b, o.b);
		

	}
	public boolean equals(Object o) {
        if (o instanceof Pair) {
            Pair p = (Pair)o;
            return p.a == a && p.b == b;
        }
        return false;
    }
    public int hashCode() {
        return new Integer(a).hashCode() * 31 + new Integer(b).hashCode();
    }
} 
    
static long sort(int a[],int n)
{  	int b[]=new int[n];	
	return mergeSort(a,b,0,n-1);}
static long mergeSort(int a[],int b[],long left,long right)
{ long c=0;if(left<right)
 {   long mid=left+(right-left)/2;
	 c= mergeSort(a,b,left,mid);
	 c+=mergeSort(a,b,mid+1,right);
	 c+=merge(a,b,left,mid+1,right); }	
	return c;	 }
static long merge(int a[],int  b[],long left,long mid,long right)
{long c=0;int i=(int)left;int j=(int)mid; int k=(int)left;
while(i<=(int)mid-1&&j<=(int)right)
{ if(a[i]<=a[j]) {b[k++]=a[i++]; }
else	{ b[k++]=a[j++];c+=mid-i;}}
while (i <= (int)mid - 1)   b[k++] = a[i++]; 
while (j <= (int)right) b[k++] = a[j++];
for (i=(int)left; i <= (int)right; i++) 
	a[i] = b[i];  return c;  }
    
    
   static  class InputReader
    {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id3 filter;

        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }

        public int read()
        {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars)
            {
                curChar = 0;
                try
                {
                    numChars = stream.read(buf);
                } catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int readInt()
        {
            int c = read();
            while (id1(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id1(c));
            return res * sgn;
        }

        public String readString()
        {
            int c = read();
            while (id1(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c = read();
            } while (!id1(c));
            return res.toString();
        }
        public double readDouble() {
            int c = read();
            while (id1(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id1(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, readInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!id1(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, readInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }
        public long readLong() {
            int c = read();
            while (id1(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id1(c));
            return res * sgn;
        }
        public boolean id1(int c)
        {
            if (filter != null)
                return filter.id1(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next()
        {
            return readString();
        }

        public interface id3
        {
            public boolean id1(int ch);
        }
    }

     static class OutputWriter
    {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream)
        {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer)
        {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects)
        {
            for (int i = 0; i < objects.length; i++)
            {
                if (i != 0)
                    writer.print(' ');
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects)
        {
            print(objects);
            writer.println();
        }

        public void close()
        {
            writer.close();
        }

        public void flush()
        {
            writer.flush();
        }

    }
    
  static   class IOUtils {

        public static int[] id0(InputReader in, int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++)
                array[i] = in.readInt();
            return array;
    }
    }


	

	 

  

	

	

	       	
	

  

  	

  	

	

	

  

	

	

	

	
	   

	
	

}