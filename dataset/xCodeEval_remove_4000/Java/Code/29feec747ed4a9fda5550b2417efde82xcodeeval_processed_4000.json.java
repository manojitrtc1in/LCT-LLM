

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.*;


public class Fourth{
	static long mod=1000000007;
	
    public static void main(String[] args) throws Exception{           	
    	 InputReader in = new InputReader(System.in);       
    	PrintWriter pw=new PrintWriter(System.out);   
    	
    	
    	

        

        

    	
        int n=in.readInt();
    	

        long ans=0;
        int p1=-1,p2=-1;
        HashMap<Pair,Pair>hm=new HashMap<Pair,Pair>();
    	int x[]=new int[n];
    	int y[]=new int[n];
    	int z[]=new int[n];
    	for(int i=0;i<n;i++)
    	{
    		x[i]=in.readInt();
    		y[i]=in.readInt();
    		z[i]=in.readInt();
    		int min=min(x[i],y[i]);
    		min=min(min,z[i]);
    		if(ans<min)
    		{
    			ans=min;
    			p1=i;
    		}
    		Pair d=new Pair(x[i],y[i],0);
    		if(!hm.containsKey(d))
    		{
    			hm.put(d,new Pair(z[i],0,i));
    		}
    		else
    		{
    			Pair e=hm.get(d);
    			int v2=e.b;
    			int v1=e.a;
    			if(z[i]==v1)
    			{
    				if(v2==0)
    					hm.put(d,new Pair(z[i],1,i));
    			}
    			else if(z[i]>v1)
    			{
    				hm.put(d,new Pair(z[i],0,i));
    			}
    		}
    		d=new Pair(y[i],x[i],0);
    		if(!hm.containsKey(d))
    		{
    			hm.put(d,new Pair(z[i],0,i));
    		}
    		else
    		{
    			Pair e=hm.get(d);
    			int v2=e.b;
    			int v1=e.a;
    			int v3=e.c;
    			if(z[i]==v1)
    			{
    				if(v2==0&&v3!=i)
    					hm.put(d,new Pair(z[i],1,i));
    			}
    			else if(z[i]>v1)
    			{
    				hm.put(d,new Pair(z[i],0,i));
    			}
    		}
    		d=new Pair(y[i],z[i],0);
    		if(!hm.containsKey(d))
    		{
    			hm.put(d,new Pair(x[i],0,i));
    		}
    		else
    		{
    			Pair e=hm.get(d);
    			int v2=e.b;
    			int v1=e.a;
    			int v3=e.c;
    			if(x[i]==v1)
    			{
    				if(v2==0&&v3!=i)
    					hm.put(d,new Pair(x[i],1,i));
    			}
    			else if(x[i]>v1)
    			{
    				hm.put(d,new Pair(x[i],0,i));
    			}
    		}
    		d=new Pair(z[i],y[i],0);
    		if(!hm.containsKey(d))
    		{
    			hm.put(d,new Pair(x[i],0,i));
    		}
    		else
    		{
    			Pair e=hm.get(d);
    			int v2=e.b;
    			int v1=e.a;
    			int v3=e.c;
    			if(x[i]==v1)
    			{
    				if(v2==0&&v3!=i)
    					hm.put(d,new Pair(x[i],1,i));
    			}
    			else if(x[i]>v1)
    			{
    				hm.put(d,new Pair(x[i],0,i));
    			}
    		}
    		d=new Pair(x[i],z[i],0);
    		if(!hm.containsKey(d))
    		{
    			hm.put(d,new Pair(y[i],0,i));
    		}
    		else
    		{
    			Pair e=hm.get(d);
    			int v2=e.b;
    			int v1=e.a;
    			int v3=e.c;
    			if(y[i]==v1)
    			{
    				if(v2==0&&v3!=i)
    					hm.put(d,new Pair(y[i],1,i));
    			}
    			else if(y[i]>v1)
    			{
    				hm.put(d,new Pair(y[i],0,i));
    			}
    		}
    		d=new Pair(z[i],x[i],0);
    		if(!hm.containsKey(d))
    		{
    			hm.put(d,new Pair(y[i],0,i));
    		}
    		else
    		{
    			Pair e=hm.get(d);
    			int v2=e.b;
    			int v1=e.a;
    			int v3=e.c;
    			if(y[i]==v1)
    			{
    				if(v2==0&&v3!=i)
    					hm.put(d,new Pair(y[i],1,i));
    			}
    			else if(y[i]>v1)
    			{
    				hm.put(d,new Pair(y[i],0,i));
    			}
    		}
    	}
    	
    	
    	for(int i=0;i<n;i++)
    	{
    		int x1=x[i];
    		int y1=y[i];
    		int z1=z[i];
    		Pair d=new Pair(x[i],y[i],0);
    		int min=min(x[i],y[i]);
    		if(hm.containsKey(d))
    		{
    			Pair e=hm.get(d);
    			int v1=e.a;
    			int v2=e.b;
    			int v3=e.c;
    			if(v1==z[i])
    			{
    				if(v2==1)
    				{
    					min=min(min,z[i]+z[i]);
    					if(ans<min&&v3!=i)
    					{
    						ans=min;
    						p1=i;
    						p2=v3;
    					}
    				}
    				else
    				{
    					
    				}
    			}
    			else
    			{
    				min=min(min,z[i]+v1);
    				if(ans<min)
					{
						ans=min;
						p1=i;
						p2=v3;
					}
    			}
    		}
    		min=min(x[i],y[i]);
    		d=new Pair(y[i],x[i],0);
    		if(hm.containsKey(d))
    		{
    			

    			Pair e=hm.get(d);
    			int v1=e.a;
    			int v2=e.b;
    			int v3=e.c;
    			if(v1==z[i])
    			{
    				if(v2==1)
    				{
    					min=min(min,z[i]+z[i]);
    					if(ans<min&&v3!=i)
    					{
    						ans=min;
    						p1=i;
    						p2=v3;
    					}
    				}
    				else
    				{
    					
    				}
    			}
    			else
    			{
    				min=min(min,z[i]+v1);
    				if(ans<min)
					{
						ans=min;
						p1=i;
						p2=v3;
					}
    			}
    		}
    		Pair d1=new Pair(y[i],z[i],0);
    		int min1=min(y[i],z[i]);
    		if(hm.containsKey(d1))
    		{
    			Pair e=hm.get(d1);
    			int v1=e.a;
    			int v2=e.b;
    			int v3=e.c;
    			if(v1==x[i])
    			{
    				if(v2==1)
    				{
    					min1=min(min1,x[i]+x[i]);
    					if(ans<min1&&v3!=i)
    					{
    						ans=min1;
    						p1=i;
    						p2=v3;
    					}
    					
    				}
    				else
    				{
    					
    				}
    			}
    			else
    			{
    				min1=min(min1,x[i]+v1);
    				if(ans<min1)
					{
						ans=min1;
						p1=i;
						p2=v3;
					}
    				
    			}
    		}
    		d1=new Pair(z[i],y[i],0);
    		min1=min(y[i],z[i]);
    		if(hm.containsKey(d1))
    		{
    			Pair e=hm.get(d1);
    			int v1=e.a;
    			int v2=e.b;
    			int v3=e.c;
    			if(v1==x[i])
    			{
    				if(v2==1)
    				{
    					min1=min(min1,x[i]+x[i]);
    					if(ans<min1&&v3!=i)
    					{
    						ans=min1;
    						p1=i;
    						p2=v3;
    					}
    					
    				}
    				else
    				{
    					
    				}
    			}
    			else
    			{
    				min1=min(min1,x[i]+v1);
    				if(ans<min1)
					{
						ans=min1;
						p1=i;
						p2=v3;
					}
    				
    			}
    		}
    		
    		Pair d2=new Pair(z[i],x[i],0);
    		int min2=min(z[i],x[i]);
    		if(hm.containsKey(d2))
    		{
    			Pair e=hm.get(d2);
    			int v1=e.a;
    			int v2=e.b;
    			int v3=e.c;
    			if(v1==y[i])
    			{
    				if(v2==1)
    				{
    					min2=min(min2,y[i]+y[i]);
    					if(ans<min2&&v3!=i)
    					{
    						ans=min2;
    						p1=i;
    						p2=v3;
    					}
    				}
    				else
    				{
    					
    				}
    			}
    			else
    			{
    				min2=min(min2,y[i]+v1);
    				if(ans<min2)
					{
						ans=min2;
						p1=i;
						p2=v3;
					}
    			}
    		}
    		d2=new Pair(x[i],z[i],0);
    		min2=min(z[i],x[i]);
    		if(hm.containsKey(d2))
    		{
    			Pair e=hm.get(d2);
    			int v1=e.a;
    			int v2=e.b;
    			int v3=e.c;
    			if(v1==y[i])
    			{
    				if(v2==1)
    				{
    					min2=min(min2,y[i]+y[i]);
    					if(ans<min2&&v3!=i)
    					{
    						ans=min2;
    						p1=i;
    						p2=v3;
    					}
    				}
    				else
    				{
    					
    				}
    			}
    			else
    			{
    				min2=min(min2,y[i]+v1);
    				if(ans<min2)
					{
						ans=min2;
						p1=i;
						p2=v3;
					}
    			}
    		}
    	}
    	

    
    	if(p2==-1)
    	{
    		p1++;
    		System.out.println(1);
    		System.out.println(p1);
    	}
    	else
    	{
    		p1++;
    		p2++;
    		System.out.println(2);
    		System.out.println(p1+" "+p2);
    	}
		

    	
    	

    	
    	pw.close();
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
	int a,b,c;
	Pair (int a,int b,int c)
	{
		this.a=a;
		this.b=b;
		this.c=c;
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
            return p.a == a && p.b == b &&p.c==c;
        }
        return false;
    }
    public int hashCode() {
        return new Integer(a).hashCode() * 31 + new Integer(b).hashCode()+new Integer(c).hashCode()*37;
    }
    
} 
    
static long sort(int a[])
{  int n=a.length;
	int b[]=new int[n];	
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
    
public static int[] id3(int[] f)
{
	int[] to = new int[f.length];
	{
		int[] b = new int[65537];
		for(int i = 0;i < f.length;i++)b[1+(f[i]&0xffff)]++;
		for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
		for(int i = 0;i < f.length;i++)to[b[f[i]&0xffff]++] = f[i];
		int[] d = f; f = to;to = d;
	}
	{
		int[] b = new int[65537];
		for(int i = 0;i < f.length;i++)b[1+(f[i]>>>16)]++;
		for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
		for(int i = 0;i < f.length;i++)to[b[f[i]>>>16]++] = f[i];
		int[] d = f; f = to;to = d;
	}
	return f;
}    
static  class InputReader
{
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id2 filter;

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
    public String readLine() {
        int c = read();
        while (id1(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!id0(c));
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

    public interface id2
    {
        public boolean id1(int ch);
    }
    public boolean id0(int c) {
        return c == '\n' || c == '\r' || c == -1;
    }
}

  


	

	 

	

	

	       	
	

  

  	

  	

	

	

  

	

	

	

	
	   

	
	

}
