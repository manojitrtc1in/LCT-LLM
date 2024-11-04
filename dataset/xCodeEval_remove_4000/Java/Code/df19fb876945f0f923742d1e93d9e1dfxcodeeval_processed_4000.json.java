import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
import java.util.LinkedList;
import java.util.Queue;
import static java.lang.Math.*;

public class Cf294 implements Runnable 
{
	static class InputReader 
	{
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private id5 filter;
		private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		public InputReader(InputStream stream) 
		{
			this.stream = stream;
		}
		
		public int read()
		{
			if (numChars==-1) 
				throw new InputMismatchException();
            
			if (curChar >= numChars) 
			{
				curChar = 0;
				try
				{
					numChars = stream.read(buf);
				}
				catch (IOException e)
				{
					throw new InputMismatchException();
				}
                
				if(numChars <= 0)               
					return -1;
			}
			return buf[curChar++];
		}
     
		public String nextLine()
		{
			String str = "";
			try
			{
				str = br.readLine();
			}
			catch (IOException e)
			{
				e.printStackTrace();
			}	
			return str;
		}
		public int[] nextArray(int n)
		{
			int arr[] = new int[n];
			int i;
			for(i=0;i<n;i++)
			{
				arr[i] = nextInt();
			}
			return arr;
		}
		public int nextInt() 
		{
			int c = read();
            
			while(id1(c)) 
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
				if(c<'0'||c>'9') 
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			while (!id1(c)); 
        
			return res * sgn;
		}
        
		public long nextLong() 
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
			long res = 0;
			
			do 
			{
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}	
			while (!id1(c));
				return res * sgn;
		}
		
		public double nextDouble() 
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
			double res = 0;
			while (!id1(c) && c != '.') 
			{
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') 
			{
				c = read();
				double m = 1;
				while (!id1(c))
				{
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, nextInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
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
			} 
			while (!id1(c));
            
			return res.toString();
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
        
		public interface id5
		{
			public boolean id1(int ch);
		}
		
		public int[] id3(int n)
		{
			int i;
			int arr[] = new int[n];
			for(i=0;i<n;i++)
			{
				arr[i] = nextInt();
			}
			return arr;
		}
		
		public long[] id7(int n)
		{
			int i;
			long arr[] = new long[n];
			for(i=0;i<n;i++)
			{
				arr[i] = nextLong();
			}
			return arr;
		}
		
		public double[] id4(int n)
		{
			int i;
			double arr[] = new double[n];
			for(i=0;i<n;i++)
			{
				arr[i] = nextDouble();
			}
			return arr;
		}
		
		public Integer[] IntegerArray(int n)
		{
			int i;
			Integer arr[] = new Integer[n];
			for(i=0;i<n;i++)
			{
				arr[i] = nextInt();
			}
			return arr;
		}
		
		public Long[] LongArray(int n)
		{
			int i;
			Long arr[] = new Long[n];
			for(i=0;i<n;i++)
			{
				arr[i] = nextLong();
			}
			return arr;
		}
		
		public Double[] DoubleArray(int n)
		{
			int i;
			Double arr[] = new Double[n];
			for(i=0;i<n;i++)
			{
				arr[i] = nextDouble();
			}
			return arr;
		}
		
		public ArrayList<ArrayList<Integer>> getGraph(int n,int m)
		{
			ArrayList<ArrayList<Integer>> g =new ArrayList<>();
			int i;
			for(i=0;i<=n;i++)
			{
				g.add(new ArrayList<>());
			}
			for(i=0;i<m;i++)
			{
				int x = nextInt();
				int y = nextInt();
				g.get(x).add(y);
				g.get(y).add(x);
			}
			return g;
		}
		
		public ArrayList<ArrayList<Integer>> getTree(int n)
		{
			ArrayList<ArrayList<Integer>> g =new ArrayList<>();
			int i;
			for(i=0;i<=n;i++)
			{
				g.add(new ArrayList<>());
			}
			for(i=0;i<n-1;i++)
			{
				int x = nextInt();
				int y = nextInt();
				g.get(x).add(y);
				g.get(y).add(x);
			}
			return g;
		}
	}
	
	public static int maxInt(int arr[])
	{
		int max = Integer.MIN_VALUE;
		for(int i : arr)
		{
			max = Math.max(i,max);
		}
		return max;
	}
	
	public static int minInt(int arr[])
	{
		int min = Integer.MAX_VALUE;
		for(int i : arr)
		{
			min = Math.min(i,min);
		}
		return min;
	}
	
	public static long maxLong(long arr[])
	{
		long max = Long.MIN_VALUE;
		for(long i : arr)
		{
			max = Math.max(i,max);
		}
		return max;
	}
	
	public static long minLong(long arr[])
	{
		long min = Long.MAX_VALUE;
		for(long i : arr)
		{
			min = Math.min(i,min);
		}
		return min;
	}
	
	public static double maxDouble(double arr[])
	{
		double max = Double.MIN_VALUE;
		for(double i : arr)
		{
			max = Math.max(i,max);
		}
		return max;
	}
	
	public static double minDouble(double arr[])
	{
		double min = Double.MAX_VALUE;
		for(double i : arr)
		{
			min = Math.min(i,min);
		}
		return min;
	}
	
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
	
	static class Pair
	{
		int x,y;
		public Pair(int x,int y)
		{
			this.x = x;
			this.y = y;
		}
		public static Comparator<Pair> sortX = new Comparator<Pair>(){
			public int compare(Pair p1,Pair p2)
			{
				if(p1.x==p2.x)
				{
					return (int)(p1.y-p2.y);
				}
				return (int)(p1.x-p2.x);
			}
		};
		
		public static Comparator<Pair> sortY = new Comparator<Pair>(){
			public int compare(Pair p1,Pair p2)
			{
				if(p1.y==p2.y)
				{
					return (int)(p1.x-p2.x);
				}
				return (int)(p1.y-p2.y);
			}
		};
		
		public static Comparator<Pair> custom = new Comparator<Pair>(){
			public int compare(Pair p1,Pair p2)
			{
				if((p1.y-p1.x==p2.y-p2.x))
					return (int)(p1.x-p2.x);
				return (int)((p2.y-p2.x)-(p1.y-p2.x));
			}
		};
		
		public boolean equals(Object obj) 
		{
			if (obj == null) return false;
			if (!(obj instanceof Pair))
				return false;
			return (this.x == ((Pair) obj).x && this.y == ((Pair)obj).y);
		}

		public int hashCode()
		{
			if(x<0 || y<0)
			{
				return (int)(-5*x+-32*y);
			}
			return (int)(5*(x+y));
		}
	}
	
	static class DPair
	{
		Pair s,d;
		public DPair(Pair s,Pair d)
		{
			this.s = s;
			this.d = d;
		}
		
		public boolean equals(Object obj) 
		{
			if (obj == null) return false;
			if (!(obj instanceof DPair))
				return false;
			return (this.s.x == ((DPair) obj).s.x && this.s.y == ((DPair) obj).s.y && this.d.x == ((DPair)obj).d.x && this.d.y == ((DPair) obj).d.y);
		}
		public int hashCode()
		{
			return 5*(s.x+s.y+d.x+d.y);
		}
	}
	
	static class DSU
	{
		public static int rank[],parent[];
		int n;
		HashMap<Integer,Integer> map = new HashMap<>();
		
		public DSU(int n)
		{
			rank = new int[n+1];
			parent = new int[n+1];
			this.n = n;
			makeSet(n);
		}
		
		public void makeSet(int n)
		{
			for(int i=1;i<=n;i++)
			{
				parent[i] = i;
				map.put(i,1);
			}
		}
		
		public static int find(int x)
		{
			if(parent[x]!=x)
			{
				parent[x] = find(parent[x]);
			}
			return parent[x];
		}
		
		public void union(int x,int y)
		{
			int xRoot = find(x);
			int yRoot = find(y);
			
			if(xRoot==yRoot)
			{
				return;
			}
			
			if(rank[xRoot] < rank[yRoot])
			{
				parent[xRoot] = yRoot;
				map.put(yRoot,map.getOrDefault(yRoot,1)+map.getOrDefault(xRoot,1));
				if(map.getOrDefault(xRoot,0)!=0)
				{
					map.remove(xRoot);
				}
			}
			else if(rank[yRoot] < rank[xRoot])
			{
				parent[yRoot] = xRoot;
				map.put(xRoot,map.getOrDefault(xRoot,1) + map.getOrDefault(yRoot,1));
				if(map.getOrDefault(yRoot,0)!=0)
				{
					map.remove(yRoot);
				}
			}
			else
			{
				parent[yRoot] = xRoot;
				rank[xRoot] = rank[xRoot] + 1;
				map.put(xRoot,map.getOrDefault(xRoot,1)+map.getOrDefault(yRoot,1));
				if(map.getOrDefault(yRoot,0)!=0)
				{
					map.remove(yRoot);
				}
			}
		}
	}
		
	public static void main(String args[]) throws Exception 
	{
		new Thread(null, new Cf294(),"Main",1<<27).start();
	}	
	
	public static int stringMerge(String s,char c)
	{
		if(s.length()==1)
		{
			if(s.charAt(0)==c)
			{
				return 0;
			}
			return 1;
		}
		int i,j,k;
		int id0 = 0,id2 = 0;
		for(i=0;i<s.length();i++)
		{
			if(s.charAt(i)==c)
			{
				id2++;
			}
		}
		for(i=s.length()/2;i<s.length();i++)
		{
			if(s.charAt(i)==c)
			{
				id0++;
			}
		}
		int left = stringMerge(s.substring(0,s.length()/2),(char)(c+1));
		int right = stringMerge(s.substring(s.length()/2,s.length()),(char)(c+1));
		return (Math.min(s.length()/2 - id0 + left,s.length()/2 - id2 + right));
	}
		
	public static void DFS(int i,boolean visited[],ArrayList<ArrayList<Integer>> g,ArrayList<Integer> sort)
	{
		visited[i] = true;
		for(int it : g.get(i))
		{
			if(!visited[it])
			{
				DFS(it,visited,g,sort);
			}
		}
		sort.add(i);
	}
	
	public void run()	
	{
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		int id6 = in.nextInt();
		while(id6-->0)
		{
			int n = in.nextInt();
			int m = in.nextInt();
			ArrayList<ArrayList<Integer>> g = new ArrayList<>();
			ArrayList<ArrayList<Integer>> edge = new ArrayList<>();
			int i,j,k;
			for(i=0;i<=n;i++)
			{
				g.add(new ArrayList<>());
			}
			for(i=0;i<m;i++)
			{
				int t = in.nextInt();
				int x = in.nextInt();
				int y = in.nextInt();
				if(t==1)
				{
					g.get(x).add(y);
				}
				edge.add(new ArrayList<>());
				edge.get(edge.size()-1).add(x);
				edge.get(edge.size()-1).add(y);
			}
			ArrayList<Integer> sort = new ArrayList<>();
			boolean visited[] = new boolean[n+1];
			for(i=1;i<=n;i++)
			{
				if(!visited[i])
				{
					DFS(i,visited,g,sort);
				}
			}
			Collections.reverse(sort);
			int rank[] = new int[n+1];
			for(i=0;i<n;i++)
			{
				rank[sort.get(i)] = i;
			}
			boolean flag = false;
			for(i=1;i<=n;i++)
			{
				for(int it : g.get(i))
				{
					if(rank[i]>rank[it])
					{
						flag = true;
					}
				}
			}
			if(flag)
			{
				w.println("NO");
			}
			else
			{
				w.println("YES");
				for(ArrayList<Integer> it : edge)
				{
					if(rank[it.get(0)]<rank[it.get(1)])
					{
						w.println(it.get(0) + " " + it.get(1));
					}
					else
					{
						w.println(it.get(1) + " " + it.get(0));
					}
				}
			}
		}
		w.flush();
		w.close();
	}
}
