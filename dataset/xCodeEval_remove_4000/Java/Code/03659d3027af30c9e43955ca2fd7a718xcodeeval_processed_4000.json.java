import java.util.*;
import java.io.*;
import java.lang.Math.*;

public class MainA
{

	static int mod = (int) 1e9 + 7;
	static int prime[]=new int[100000+1];
	static int count=0,n,m;
	static int flag=0;
	static boolean cycle;
	static int h[];
	
	static void BFS(int s,boolean visited[],ArrayList adj[])
    {
       
		h[s]=1;
        

        LinkedList<Integer> queue = new LinkedList<Integer>();
 
        

        visited[s]=true;
        queue.add(s);
 
        while (queue.size() != 0)
        {
            

            s = queue.poll();
            
            Iterator<Integer> i = adj[s].listIterator();
            while (i.hasNext())
            {
                int n = i.next();
                if (!visited[n])
                {
                    visited[n] = true;
                    h[n]=h[s]+1;
                    queue.add(n);
                }
            }
        }
    }
	static int dfs(int v, boolean visited[], boolean recStack[],ArrayList<Integer> adj[],int min)
	{
		int lowest=-1;
	    if(visited[v] == false)
	    {
	        

	        visited[v] = true;
	        recStack[v] = true;
	 
	        

	        
	        for(int i =0; i < adj[v].size(); ++i)
	        {
	        	

	            if (!visited[adj[v].get(i)])
	            {
	            	int r=dfs(adj[v].get(i),visited,recStack,adj,min);
	            	System.out.println(v+" "+adj[v].get(i)+" "+r+" min="+min+" i="+i);
	            	lowest=Math.max(lowest,r);
	            	if(r!=-1)
	            	{
	            		if(r>=h[v])
	            		{
	            			min=-1;
	            		}
	            		else
	            		{
	            			if(min!=-1)min=h[v]-1;
	            		}	            		
	            	}
	            	

	            }
	            else if (recStack[adj[v].get(i)])
	            {
	            	cycle=true;
	            	int height=h[adj[v].get(i)];
	            	System.out.println(v+" "+adj[v].get(i)+" hei="+height+" "+i+" min="+min);
	            	if(height>min)
	            	{
	            		flag=1;
	            		return Integer.MAX_VALUE;
	            	}
	            	lowest=Math.max(lowest,height);
	            	
	            }
	        }
	 
	    }
	    recStack[v] = false;  

	    return lowest;
	}
	 
	
	public static void main(String[] args) throws java.lang.Exception
	{
		InputReader in = new InputReader(System.in);
		PrintWriter out=new PrintWriter(System.out);
		int n=in.nextInt();
		int min=Integer.MAX_VALUE;
		int a[]=new int[n];
		for(int i=0;i<n;i++)
		{
			a[i]=in.nextInt();
			min=Math.min(a[i],min);
		}
		ArrayList<Integer> arr=new ArrayList();
		for(int i=0;i<n;i++)
		{
			if(a[i]==min)arr.add(i);
		}
		int ans=Integer.MAX_VALUE;
		for(int i=1;i<arr.size();i++)
		{
			if(arr.get(i)-arr.get(i-1)<ans)ans=arr.get(i)-arr.get(i-1);
		}
		out.println(ans);
		out.close();
	}
	
	public static void lcs(String X, String Y, int m, int n)
    {
        int[][] L = new int[m+1][n+1];
  
        

        

        for (int i=0; i<=m; i++)
        {
            for (int j=0; j<=n; j++)
            {
                if (i == 0 || j == 0)
                    L[i][j] = 0;
                else if (X.charAt(i-1) == Y.charAt(j-1))
                    L[i][j] = L[i-1][j-1] + 1;
                else
                    L[i][j] = Math.max(L[i-1][j], L[i][j-1]);
            }
        }
  
        

        int index = L[m][n];
        int temp = index;
        int ax[]=new int[m];
        ax[0]=1;
        for(int i=1;i<m;i++)
        {
        	if(X.charAt(i)==X.charAt(i-1))ax[i]=ax[i-1]+1;
        	else ax[i]=1;
        	

        }
        

        int bx[]=new int[n];
        bx[0]=1;
        for(int i=1;i<n;i++)
        {
        	if(Y.charAt(i)==Y.charAt(i-1))bx[i]=bx[i-1]+1;
        	else bx[i]=1;
        	

        }
        

        

        int a[]=new int[index];
        int b[]=new int[index];
        char[] lcs = new char[index+1];
        lcs[index] = '\0'; 

  
        

        

        int i = m, j = n;
        while (i > 0 && j > 0)
        {
            

            

            if (X.charAt(i-1) == Y.charAt(j-1))
            {
                

                lcs[index-1] = X.charAt(i-1); 
                a[index-1] =i-1;
                b[index-1]=j-1;
                

                i--; 
                j--; 
                index--;     
            }
  
            

            

            else if (L[i-1][j] > L[i][j-1])
                i--;
            else
                j--;
        }
  
        

        

        

        

       
        int sum=0;
        for(int k=0;k<temp;k++)
        {
        	if(k==0)
        	{
        		sum+=(a[k]-(ax[a[k]]-1)+b[k]-(bx[b[k]]-1));
        		

        	}
        	else
        	{
        		
        		int temp1=a[k]+b[k]-a[k-1]-b[k-1];
        		

        		if(temp1==2)
        		{
        			if(X.charAt(a[k])!=X.charAt(a[k-1]))sum++;
        			

        		}
        		else
        		{
        			if(a[k]-a[k-1]<ax[a[k]])
        			{
        				if(b[k]-b[k-1]>bx[b[k]])
        				{
        					sum+=(b[k]-(bx[b[k]]-1)-b[k-1]);
        				}
        				else if(b[k]-b[k-1]==bx[b[k]])sum++;
        				

        			}
        			else if(a[k]-a[k-1]==ax[a[k]])
        			{
        				

        				if(b[k]-b[k-1]>bx[b[k]])
        				{
        					sum+=(b[k]-(bx[b[k]]-1)-b[k-1]);
        				}
        				else if(b[k]-b[k-1]==bx[b[k]])sum++;
        				

        			}
        			else
        			{
        				if(b[k]-b[k-1]>bx[b[k]])
        				{
        					sum=sum+(b[k]-(bx[b[k]]-1)-b[k-1])+(a[k]-(ax[a[k]]-1)-a[k-1])-1;
        				}
        				else if(b[k]-b[k-1]<=bx[b[k]])sum=sum+(a[k]-(ax[a[k]]-1)-a[k-1]);
        				

        			}
        		}
        	}
        	
        	if(k==temp-1){
        		sum+=(n+m-2-a[k]-b[k]);
        	}
        }
        if(sum==0)sum=n+m;
        System.out.println(sum+1);
        
    }
	public static long id1(int a[])
    {
        int size = a.length;
        long id6 = Long.MIN_VALUE, id2 = 0;
 
        for (int i = 0; i < size; i++)
        {
            id2 = id2 + a[i];
            if (id6 < id2)
                id6 = id2;
            if (id2 < 0)
                id2 = 0;
        }
        return id6;
    }
	public static int binarySearch(int a[],int x)
	{
		int l=0,r=a.length-1,result=-1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(a[mid]<x)
			{
				result=mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		return result;
	}
	public static void permute(String str, int l, int r,String s[],int startx,int starty,String dir)
    {
        if (l == r)
            count+=poss(str,s,startx,starty,dir);
        else
        {
            for (int i = l; i <= r; i++)
            {
                str = swap(str,l,i);
                permute(str, l+1, r,s,startx,starty,dir);
                str = swap(str,l,i);
            }
        }
    }
 
    public static String swap(String a, int i, int j)
    {
        char temp;
        char[] charArray = a.toCharArray();
        temp = charArray[i] ;
        charArray[i] = charArray[j];
        charArray[j] = temp;
        return String.valueOf(charArray);
    }
    
    public static int poss(String str,String s[],int startx,int starty,String dir)
    {
    	if(fun(str,s,startx,starty,dir))
    	{
    		return 1;
    	}
    	else return 0;
    }
    
    public static boolean fun(String str, String s[],int startx, int starty,String dir)
    {
    	int id9=startx,id0=starty;
    	

    	for(int i=0;i<dir.length();i++)
    	{
    		int c=dir.charAt(i)-'0';
    		
    		if(str.charAt(c)=='U'){id9--;}
    		else if(str.charAt(c)=='D'){id9++;}
    		else if(str.charAt(c)=='L'){id0--;}
    		else if(str.charAt(c)=='R'){id0++;}
    		if(id9<0||id9>=n||id0<0||id0>=m)return false;
    		else if(s[id9].charAt(id0)=='E')return true;
    		else if(s[id9].charAt(id0)=='
    	}
    	return false;
    }
    
	static class Pairs implements Comparable<Pairs>
	{
		int x;
		int y;
		int z;
		
		Pairs(int a, int b, int c)
		{
			x = a;
			y = b;
			z=c;
		}

		@Override
		public boolean equals(Object o)
		{
			Pairs other=(Pairs)o;
			return x==other.x && y==other.y;
		}
		@Override
		public int compareTo(Pairs o)
		{
			

			if(x==o.x)
			return Integer.compare(y,o.y);
			else return Integer.compare(x,o.x);
		}
		@Override
		public int hashCode()
		{
			return  Objects.hash(x,y);
		}

	}

	public static void debug(Object... o) 
	{
		System.out.println(Arrays.deepToString(o));
	}

	public static boolean isPal(String s) 
	{
		for (int i = 0, j = s.length() - 1; i <= j; i++, j--)
		{
			if (s.charAt(i) != s.charAt(j))
				return false;
		}
		return true;
	}

	public static String rev(String s)
	{
		StringBuilder sb = new StringBuilder(s);
		sb.reverse();
		return sb.toString();
	}

	public static long gcd(long x, long y)
	{
		if (y == 0)
			return x;
		if (x % y == 0)
			return y;
		else
			return gcd(y, x % y);
	}

	public static int gcd(int x, int y)
	{
		if(y==0)
			return x;
		if (x % y == 0)
			return y;
		else
			return gcd(y, x % y);
	}

	public static long id4(long a, long b, long[] x) 
	{

		if (a == 0) 
		{
			x[0] = 0;
			x[1] = 1;
			return b;
		}
		long[] y = new long[2];
		long gcd = id4(b % a, a, y);

		x[0] = y[1] - (b / a) * y[0];
		x[1] = y[0];

		return gcd;
	}

	
	

	public static long max(long a, long b) 
	{
		if (a > b)
			return a;
		else
			return b;
	}

	public static long min(long a, long b)
	{
		if (a > b)
			return b;
		else
			return a;
	}

	public static long[][] mul(long a[][], long b[][])
	{
		long c[][] = new long[2][2];
		c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
		c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
		c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
		c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];

		return c;
	}

	public static long[][] pow(long n[][], long p, long m)
	{
		long result[][] = new long[2][2];
		result[0][0] = 1;
		result[0][1] = 0;
		result[1][0] = 0;
		result[1][1] = 1;

		if (p == 0)
			return result;
		if (p == 1)
			return n;
		while (p != 0)
		{
			if (p % 2 == 1)
				result = mul(result, n);
			

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					if (result[i][j] >= m)
						result[i][j] %= m;
				}
			}

			p >>= 1;
			n = mul(n, n);
			

			for (int i = 0; i < 2; i++) 
			{
				for (int j = 0; j < 2; j++)
				{
					if (n[i][j] >= m)
						n[i][j] %= m;
				}
			}
		}
		return result;
	}
	public static long pow(long n,long p, long m)
	{
		long result=1;
		if(p==0)return 1;
		if(p==1)return n%m;
		while(p!=0)
		{
			if(p%2==1)result=(result*n)%m;
			p >>=1;
			n=(n*n)%m;
		}
		return result;
	}
	public static int pow(int n, int p) 
	{
		int result = 1;
		if (p == 0)
			return 1;
		if (p == 1)
			return n;
		while (p != 0)
		{
			if (p % 2 == 1)
				result *= n;
			p >>= 1;
			n *= n;
		}
		return result;
	}

	static class InputReader {

		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, id5;
		private id10 filter;

		public InputReader(InputStream stream)
		{
			this.stream = stream;
		}

		public int snext()
		{
			if (id5 == -1)
				throw new InputMismatchException();
			if (curChar >= id5)
			{
				curChar = 0;
				try 
				{
					id5 = stream.read(buf);
				}
				catch (IOException e)
				{
					throw new InputMismatchException();
				}
				if (id5 <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt()
		{
			int c = snext();
			while (id3(c))
			{
				c = snext();
			}
			int sgn = 1;
			if (c == '-')
			{
				sgn = -1;
				c = snext();
			}
			int res = 0;
			do
			{
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			}
			while (!id3(c));
			return res * sgn;
		}

		public long nextLong()
		{
			int c = snext();
			while (id3(c))
			{
				c = snext();
			}
			int sgn = 1;
			if (c == '-') 
			{
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do 
			{
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			}
			while (!id3(c));
			return res * sgn;
		}

		public int[] id7(int n)
		{
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
			{
				a[i] = nextInt();
			}
			return a;
		}

		public long[] id11(int n)
		{
			long a[] = new long[n];
			for (int i = 0; i < n; i++) 
			{
				a[i] = nextInt();
			}
			return a;
		}

		public String readString()
		{
			int c = snext();
			while (id3(c))
			{
				c = snext();
			}
			StringBuilder res = new StringBuilder();
			do 
			{
				res.appendCodePoint(c);
				c = snext();
			} 
			while (!id3(c));
			return res.toString();
		}

		public String nextLine()
		{
			int c = snext();
			while (id3(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do
			{
				res.appendCodePoint(c);
				c = snext();
			}
			while (!id8(c));
			return res.toString();
		}

		public boolean id3(int c) 
		{
			if (filter != null)
				return filter.id3(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean id8(int c)
		{
			return c == '\n' || c == '\r' || c == -1;
		}

		public interface id10 
		{
			public boolean id3(int ch);
		}
	}
}