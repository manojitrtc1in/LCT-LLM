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
		private SpaceCharFilter filter;
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
            
			while(isSpaceChar(c)) 
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
			while (!isSpaceChar(c)); 
        
			return res * sgn;
		}
        
		public long nextLong() 
		{
			int c = read();
			while (isSpaceChar(c))
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
			while (!isSpaceChar(c));
				return res * sgn;
		}
		
		public double nextDouble() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-')
			{
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') 
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
				while (!isSpaceChar(c))
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
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do 
			{
				res.appendCodePoint(c);
				c = read();
			} 
			while (!isSpaceChar(c));
            
			return res.toString();
		}
     
		public boolean isSpaceChar(int c) 
		{
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
     
		public String next()
		{
			return readString();
		}
        
		public interface SpaceCharFilter
		{
			public boolean isSpaceChar(int ch);
		}
		
		public int[] nextIntArray(int n)
		{
			int i;
			int arr[] = new int[n];
			for(i=0;i<n;i++)
			{
				arr[i] = nextInt();
			}
			return arr;
		}
		
		public long[] nextLongArray(int n)
		{
			int i;
			long arr[] = new long[n];
			for(i=0;i<n;i++)
			{
				arr[i] = nextLong();
			}
			return arr;
		}
		
		public double[] nextDoubleArray(int n)
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
				if(p1.x-p2.x==0)
				{
					return -1*(p1.y-p2.y);
				}
				return -1*(p1.x-p2.x);
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
				rank[yRoot] = rank[xRoot] + 1;
				map.put(yRoot,map.getOrDefault(yRoot,1)+map.getOrDefault(xRoot,1));
				if(map.getOrDefault(xRoot,0)!=0)
				{
					map.remove(xRoot);
				}
			}
			else if(rank[yRoot] < rank[xRoot])
			{
				parent[yRoot] = xRoot;
				rank[xRoot] = rank[yRoot] + 1;
				map.put(xRoot,map.getOrDefault(xRoot,1) + map.getOrDefault(yRoot,1));
				if(map.getOrDefault(yRoot,0)!=0)
				{
					map.remove(yRoot);
				}
			}
			else
			{
				parent[yRoot] = xRoot;
				rank[xRoot] = rank[yRoot] + 1;
				map.put(xRoot,map.getOrDefault(xRoot,1)+map.getOrDefault(yRoot,1));
				if(map.getOrDefault(yRoot,0)!=0)
				{
					map.remove(yRoot);
				}
			}
		}
	}
	
	static class SegmentTree
	{
		public static int tree[];
		public SegmentTree(int arr[], int n) 
		{
			int x = (int) (Math.ceil(Math.log(n) / Math.log(2))); 
			int size = 2 * (int) Math.pow(2, x) - 1; 
			tree = new int[size];
			constructTree(arr, 0, n - 1, 0);
		}
		
		public int getMid(int s, int e) 
		{ 
			return s + (e - s) / 2; 
		} 
		
		public int minVal(int x, int y) 
		{ 
			return (x < y) ? x : y; 
		} 
		
		public int constructTree(int arr[], int s, int e, int ind) 
		{ 
			if (s == e) 
			{ 
				tree[ind] = arr[s]; 
				return arr[s]; 
			} 
			int mid = getMid(s, e); 
			tree[ind] = constructTree(arr, s, mid, ind * 2 + 1) +  constructTree(arr, mid + 1, e, ind * 2 + 2); 
			return tree[ind]; 
		}
		
		public long getSum(int n, int l, int r) 
		{ 
			if (l < 0 || r > n - 1 || l > r) 
			{				
				return -1; 
			} 
			return getSumR(0, n - 1, l, r, 0); 
		}
		
		public long getSumR(int s, int e, int l, int r, int ind) 
		{ 
			if (l <= s && r >= e)
			{
				return tree[ind]; 
			}
			if (e < l || s > r) 
			{
				return 0; 
			}
			int mid = getMid(s, e); 
			return getSumR(s, mid, l, r, 2 * ind + 1) + getSumR(mid + 1, e, l, r, 2 * ind + 2); 
		} 
		
		public  void updateValue(int arr[], int n, int i, int val) 
		{ 
			if (i < 0 || i > n - 1) 
			{ 
				return; 
			} 
			int diff = val - arr[i]; 
			arr[i] = val; 
			updateValueR(0, n - 1, i, diff, 0); 
		} 
		
		public void updateValueR(int s, int e, int i, int diff, int ind) 
		{ 
			if (i < s || i > e) 
			{
				return; 
			}
			tree[ind] = tree[ind] + diff; 
			if (e != s) 
			{ 
				int mid = getMid(s, e); 
				updateValueR(s, mid, i, diff, 2 * ind + 1); 
				updateValueR(mid + 1, e, i, diff, 2 * ind + 2); 
			} 
		}
		
		

		public int constructMinTree(int arr[], int s, int e, int ind) 
		{ 
			if (s == e) 
			{ 
				tree[ind] = arr[s]; 
				return arr[s]; 
			} 
			int mid = getMid(s, e); 
			tree[ind] = minVal(constructMinTree(arr, s, mid, ind * 2 + 1), constructMinTree(arr, mid + 1, e, ind * 2 + 2)); 
			return tree[ind]; 
		} 
		
		
		public int getMin(int n,int l,int r)
		{
			if (l < 0 || r > n - 1 || l > r) 
			{				
				return -1; 
			} 
			return getMinR(0, n - 1, l, r, 0); 
		}
	
		public void updateValueMin(int arr[],int s, int e, int index, int value, int node) 
		{ 
			if (index < s || index > e) 
			{ 
				return; 
			} 
			if (s == e) 
			{  
				arr[index] = value; 
				tree[node] = value; 
			}  
			else
			{ 
				int mid = getMid(s, e); 
				if (index >= s && index <= mid)
				{					
					updateValueMin(arr,s, mid, index, value, 2 * node + 1); 
				}
				else
				{
					updateValueMin(arr,mid + 1, e, index, value, 2 * node + 2);   
				}
				tree[node] = Math.min(tree[2 * node + 1], tree[2 * node + 2]); 
			} 
			return; 
		} 
	
		public int getMinR(int s, int e, int l, int r, int index) 
		{ 
			if (l <= s && r >= e) 
			{
				return tree[index]; 
			}
			if (e < l || s > r) 
			{
				return Integer.MAX_VALUE; 
			}
			int mid = getMid(s, e); 
			return minVal(getMinR(s, mid, l, r, 2 * index + 1) , getMinR(mid + 1, e, l, r, 2 * index + 2));
		}
	}
	
	public static int gcd(int a, int b)
	{
		if (a == 0)
			return b; 
		return gcd(b % a, a); 
	}

	public static int lcm(int a, int b)
	{
		return (a / gcd(a, b)) * b;
	}
	
	public static void main(String args[]) throws Exception 
	{
		new Thread(null, new Cf294(),"Main",1<<27).start();
	}	
	
	public void run()	
	{
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		int TESTCASES = in.nextInt();
		while(TESTCASES-->0)
		{
			int n = in.nextInt();
			double k = in.nextDouble();
			double arr[] = in.nextDoubleArray(n);
			double till = k/100;
			long res = 0;
			PriorityQueue<Double> pq = new PriorityQueue<>(Collections.reverseOrder());
			int i,j;
			double sum = arr[0];
			for(i=1;i<n;i++)
			{
				double inf = arr[i]/(sum);
				if(inf<=till)
				{
					sum+=arr[i];
				}
				else
				{
					double x = (arr[i]*100)/(k);
					x = x - sum;
					x = Math.ceil(x);
					pq.add(x);
					sum+=arr[i];
					
				}
			}
			w.println((pq.size()==0?0:(long)Math.ceil(pq.poll())));
		}
		w.flush();
		w.close();
	}
}