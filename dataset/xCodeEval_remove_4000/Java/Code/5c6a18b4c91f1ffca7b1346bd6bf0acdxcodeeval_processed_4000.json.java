import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;
import java.util.Set;
import java.util.SortedSet;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;

import javax.net.ssl.SSLContext;

public class Main
{	
	
	private MyScanner scan = new MyScanner();
	private PrintWriter out = new PrintWriter(System.out);
	private final double PI = Math.acos(-1.0);
	private final double EPS = 1e-6;
	private final int id0 = (int)(1e5);
	private final int MOD = (int)(1e9 + 7);
	private final long MODH = 10000000007L, BASE = 10007;
	private final int[] DX = {0, 1, 0, -1}, DY = {-1, 0, 1, 0};
	private ArrayList<Integer>[] edge;
	private int[] head, match;
	private int[] index;
	private int cnt;
	private ArrayList<Integer> vex, next;
	
	public void addEdge(int u, int v)
	{
		vex.add(v);
		next.add(head[u]);
		head[u] = vex.size() - 1;
	}
	
	public boolean dfs(int u)
	{
		if(index[u] == cnt) return false;
		index[u] = cnt;
		for(int v : edge[u])
		

		{
		

			if(-1 == match[v] || dfs(match[v]))
			{
				match[v] = u;
				return true;
			}
		}
		return false;
	}

	public void foo()
	{
		int n = scan.nextInt();
		Shoe[] s = new Shoe[n];
		for(int i = 0;i < n;++i)
		{
			s[i] = new Shoe(i, scan.nextInt(), scan.nextInt());
		}
		int m = scan.nextInt();
		Shoe[] p = new Shoe[m];
		for(int i = 0;i < m;++i)
		{
			p[i] = new Shoe(i, scan.nextInt(), scan.nextInt());
		}
		Arrays.sort(s);
		Arrays.sort(p);
		int ptr = 0;
		head = new int[n];
		Arrays.fill(head, -1);
		vex = new ArrayList<Integer>();
		next = new ArrayList<Integer>();
		edge = new ArrayList[n];
		for(int i = 0;i < n;++i) edge[i] = new ArrayList<Integer>();
		for(int i = 0;i < m;++i)
		{
			while(ptr < n && s[ptr].size < p[i].size)
			{
				++ptr;
			}
			if(ptr == n) break;
			if(s[ptr].size - p[i].size > 1) continue;
			if(s[ptr].size == p[i].size)
			{
				

				if(s[ptr].price <= p[i].price) edge[s[ptr].id].add(p[i].id);
				if(ptr + 1 < n && 1 == s[ptr + 1].size - p[i].size)
				{
					

					if(s[ptr + 1].price <= p[i].price) edge[s[ptr + 1].id].add(p[i].id);
				}
			}
			else
			{
				

				if(s[ptr].price <= p[i].price) edge[s[ptr].id].add(p[i].id);
			}
		}
		Arrays.sort(s, new Comparator<Shoe>()
		{
			public int compare(Shoe s1, Shoe s2)
			{
				return s2.price - s1.price;
			}
		});
		long ans = 0;
		match = new int[m];
		Arrays.fill(match, -1);
		index = new int[n];
		Arrays.fill(index, -1);
		cnt = 1;
		for(int i = 0;i < n;++i)
		{
			++cnt;
			if(dfs(s[i].id))
			{
				ans += s[i].price;
			}
		}
		ArrayList<int[]> arr = new ArrayList<int[]>();
		for(int i = 0;i < m;++i)
		{
			if(match[i] != -1)
			{
				arr.add(new int[]{i + 1, match[i] + 1});
			}
		}
		out.println(ans);
		out.println(arr.size());
		for(int[] a : arr) out.println(a[0] + " " + a[1]);
  	}

	public static void main(String[] args)
	{
		Main m = new Main();
		m.foo();
		m.out.close();
	}
	
	class Shoe implements Comparable<Shoe>
	{
		private int id;
		private int price;
		private int size;
		public Shoe(int aId, int aPrice, int aSize)
		{
			id = aId;
			price = aPrice;
			size = aSize;
		}
		public int compareTo(Shoe s)
		{
			return size - s.size;
		}
	}
	
	class Point
	{
		private int x;
		private int y;
		public Point(int aX, int aY)
		{
			x = aX;
			y = aY;
		}
	}

	
	
	public long gcd(long a, long b)
	{
		return 0 == b ? a : gcd(b, a % b);
	}
	
	
	public double getDist(long x1, long y1, long x2, long y2, long x, long y)
	{
		long a = y2 - y1;
		long b = x1 - x2;
		long c = y1 * (x2 - x1) - x1 * (y2 - y1);
		return Math.abs(a * x + b * y + c) / Math.sqrt(a * a + b * b);
	}
	
	
	public double id3(long x1, long y1, long x2, long y2, long x, long y)
	{
		double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
		if(cross <= 0)
		{
			return (x - x1) * (x - x1) + (y - y1) * (y - y1);
		}
		double d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		if(cross >= d) 
		{
			return (x - x2) * (x - x2) + (y - y2) * (y - y2);
		}
		double r = cross / d;
		double px = x1 + (x2 - x1) * r;
		double py = y1 + (y2 - y1) * r;
		return (x - px) * (x - px) + (y - py) * (y - py);
	}
	
	
	public int id2(char[] t, char[] p)
	{
		int n = t.length;
		int m = p.length;
		int[] next = new int[m + 1];
		next[0] = -1;
		int j = -1;
		for(int i = 1;i < m;++i)
		{
			while(j >= 0 && p[i] != p[j + 1])
			{
				j = next[j];
			}
			if(p[i] == p[j + 1])
			{
				++j;
			}
			next[i] = j;
		}
		j = -1;
		for(int i = 0;i < n;++i)
		{
			while(j >= 0 && t[i] != p[j + 1])
			{
				j = next[j];
			}
			if(t[i] == p[j + 1])
			{
				++j;
			}
			if(j == m - 1)
			{
				return i - m + 1;
			}
		}
		return -1;
	}
	
	
	public long hash(String s)
	{
		long key = 0, t = 1;
		for(int i = 0;i < s.length();++i)
		{
			key = (key + s.charAt(i) * t) % MODH;
			t = t * BASE % MODH;
		}
		return key;
	}
	
	
	public long quickMod(long x, long n)
	{
		long ans = 1;
		while(n > 0)
		{
			if(1 == n % 2)
			{
				ans = ans * x % MOD;
 			}
			x = x * x % MOD;
			n >>= 1;
		}
		return ans;
	}
	
	
	
	
	
	public boolean id4(long x1, long y1, long x2, long y2, long x, long y)
	{
		return (x - x1) * (y2 - y1) == (x2 - x1) * (y - y1) && 
				x >= Math.min(x1, x2) && x <= Math.max(x1, x2) && 
				y >= Math.min(y1, y2) && y <= Math.max(y1, y2);
	}
	
	
	public long cross(Point p1, Point p2, Point p)
	{
		return (long)(p1.x - p.x) * (p2.y - p.y) - (long)(p2.x - p.x) * (p1.y - p.y);
	}
	
	class MyScanner
	{
	    private byte[] buf = new byte[1024];
	    private int curChar;
	    private int numChars;
	    BufferedInputStream bis = new BufferedInputStream(System.in);

	    public int read() 
	    {
	        if (-1 == numChars)
	        {
	        	throw new InputMismatchException();
	        }
	        if (curChar >= numChars)
	        {
	            curChar = 0;
	            try 
	            {
	                numChars = bis.read(buf);
	            }
	            catch (IOException e)
	            {
	                throw new InputMismatchException();
	            }
	            if (numChars <= 0)
	            {
	            	return -1;
	            }
	        }
	        return buf[curChar++];
	    }

	    public int nextInt() 
	    {
	        int c = read();
	        while (id1(c))
	        {
	        	c = read();
	        }
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
	            {
	            	throw new InputMismatchException();
	            }
	            res *= 10;
	            res += c - '0';
	            c = read();
	        } while (!id1(c));
	        return res * sgn;
	    }
	    
	    public long nextLong() 
	    {
	    	int c = read();
	    	while (id1(c))
	    	{
	    		c = read();
	    	}
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
	    		{
	    			throw new InputMismatchException();
	    		}
	    		res *= 10;
	    		res += c - '0';
	    		c = read();
	    	} while (!id1(c));
	    	return res * sgn;
	    }
	    
	    public double nextDouble() 
	    {
	        int c = read();
	        while (id1(c))
	        {
	        	c = read();
	        }
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
	            {
	            	return res * Math.pow(10, nextInt());
	            }
	            if (c < '0' || c > '9')
	            {
	            	throw new InputMismatchException();
	            }
	            res *= 10;
	            res += c & 15;
	            c = read();
	        }
	        if (c == '.') 
	        {
	            c = read();
	            double m = 1;
	            while (!id1(c)) 
	            {
	                if (c == 'e' || c == 'E')
	                {
	                	return res * Math.pow(10, nextInt());
	                }
	                if (c < '0' || c > '9')
	                {
	                	throw new InputMismatchException();
	                }
	                m /= 10;
	                res += (c & 15) * m;
	                c = read();
	            }
	        }
	        return res * sgn;
	    }
	    
	    public String next()
	    {
	        int c = read();
	        while (id1(c))
	        {
	        	c = read();
	        }
	        StringBuilder res = new StringBuilder();
	        do 
	        {
	            res.appendCodePoint(c);
	            c = read();
	        } while (!id1(c));
	        return res.toString();
	    }

	    private boolean id1(int c) 
	    {
	        return ' ' == c || '\n' == c || '\r' == c || '\t' == c || -1 == c;
	    }
	}
}