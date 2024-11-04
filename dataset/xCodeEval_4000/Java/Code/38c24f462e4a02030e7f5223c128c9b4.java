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
	private final int SIZEN = (int)(1e5);
	private final int MOD = (int)(1e9 + 7);
	private final long MODH = 10000000007L, BASE = 10007;
	private final int[] DX = {0, 1, 0, -1}, DY = {-1, 0, 1, 0};
	private ArrayList<Integer>[] edge;
	private final String dir2 = "v<^>";
	private int[] dir = new int[256];
	private int n, m, maxDist, curDist, index, i0, j0;
	private char[][] map;
	private int[][] vis;
	private boolean isLoop;
	
	public void dfs(int i, int j)
	{
	
		Queue<Point> q = new LinkedList<Point>();
		q.add(new Point(i, j, 0));
		while(!q.isEmpty())
		{
			Point p = q.poll();
			if('#' == map[p.x][p.y]) return;
			if(vis[p.x][p.y] != 0)
			{
				isLoop = true;
				return;
			}
			vis[p.x][p.y] = index;
			i0 = p.x;
			j0 = p.y;
			int k = dir[map[p.x][p.y]];
	 		q.add(new Point(p.x + DY[k], p.y + DX[k], 0));
		}
	}
	
	public void dfsBack(int i, int j, int step)
	{
		
		Stack<Point> q = new Stack<Point>();
		q.add(new Point(i, j, 1));
		while(!q.isEmpty())
		{
			Point p = q.pop();
			curDist = Math.max(curDist, p.step);
			vis[p.x][p.y] = index;
			for(int k = 0;k < 4;++k)
			{
				int iNext = p.x + DY[k], jNext = p.y + DX[k];
				if(map[iNext][jNext] == dir2.charAt(k))
				{
					

					q.push(new Point(iNext, jNext, p.step + 1));
				}
			}
		}
	}

  	public void foo()
  	{
  		dir['^'] = 0;
  		dir['>'] = 1;
  		dir['v'] = 2;
  		dir['<'] = 3;
  		n = scan.nextInt();
  		m = scan.nextInt();
  		map = new char[n][];
  		for(int i = 0;i < n;++i) map[i] = scan.next().toCharArray();
  		vis = new int[n][m];
  		maxDist = 0;
  		ArrayList<Integer> ending = new ArrayList<Integer>();
  		index = 0;
  		for(int i = 0;i < n;++i)
  		{
  			for(int j = 0;j < m;++j)
  			{
  				if(map[i][j] != '#' && 0 == vis[i][j])
  				{
  					++index;
  					isLoop = false;
  					i0 = i;
  					j0 = j;
  					dfs(i, j);
  					if(isLoop)
  					{
  						out.println(-1);
  						return;
  					}
  					curDist = 0;
  					dfsBack(i0, j0, 1);
  					

  					if(curDist > maxDist)
  					{
  						maxDist = curDist;
  						ending.clear();
  						ending.add(2001 * i0 + j0);
  					}
  					else if(curDist == maxDist)
  					{
  						ending.add(2001 * i0 + j0);
  					}
  				}
  			}
  		}
  	

  		out.println(Math.max(ending.size() >= 2 ? 2 * maxDist : 2 * maxDist - 1, 0));
  	}

	public static void main(String[] args)
	{
		Main m = new Main();
		m.foo();
		m.out.close();
	}
	
	class Point
	{
		private int x;
		private int y;
		private int step;
		public Point(int aX, int aY, int aStep)
		{
			x = aX;
			y = aY;
			step = aStep;
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
	
	
	public double ptToSeg(long x1, long y1, long x2, long y2, long x, long y)
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
	
	
	public int kmpMatch(char[] t, char[] p)
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
	
	
	
	
	
	public boolean isOnSeg(long x1, long y1, long x2, long y2, long x, long y)
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
	        while (isSpaceChar(c))
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
	        } while (!isSpaceChar(c));
	        return res * sgn;
	    }
	    
	    public long nextLong() 
	    {
	    	int c = read();
	    	while (isSpaceChar(c))
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
	    	} while (!isSpaceChar(c));
	    	return res * sgn;
	    }
	    
	    public double nextDouble() 
	    {
	        int c = read();
	        while (isSpaceChar(c))
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
	        while (!isSpaceChar(c) && c != '.') 
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
	            while (!isSpaceChar(c)) 
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
	        while (isSpaceChar(c))
	        {
	        	c = read();
	        }
	        StringBuilder res = new StringBuilder();
	        do 
	        {
	            res.appendCodePoint(c);
	            c = read();
	        } while (!isSpaceChar(c));
	        return res.toString();
	    }

	    private boolean isSpaceChar(int c) 
	    {
	        return ' ' == c || '\n' == c || '\r' == c || '\t' == c || -1 == c;
	    }
	}
}