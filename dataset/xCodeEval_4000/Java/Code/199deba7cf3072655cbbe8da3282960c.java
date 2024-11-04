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
import java.util.LinkedList;
import java.util.Map.Entry;
import java.util.Queue;
import java.util.Random;
import java.util.Set;
import java.util.SortedSet;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main
{	
	
	private MyScanner scan = new MyScanner();
	private PrintWriter out = new PrintWriter(System.out);
	private final long INF = Long.MAX_VALUE;
	private final double PI = Math.acos(-1.0);
	private final int SIZEN = (int)(1e5);
	private final int MOD = (int)(1e9 + 7);
	private final int[] DX = {0, 1, 0, -1}, DY = {-1, 0, 1, 0};
	private ArrayList<Integer>[] edge;
	
	public int divide(int x, int p)
	{
		int ans = 0;
		while(x > 0 && 0 == x % p)
		{
			x /= p;
			++ans;
		}
		return ans;
	}
	
	public void printPath(int[][] path, int n)
	{
		int r = n - 1, c = n - 1;
		StringBuilder ans = new StringBuilder();
		while(r != 0 || c != 0)
		{
			if(1 == path[r][c])
			{
				--c;
				ans.append('R');
			}
			else
			{
				--r;
				ans.append('D');
			}
		}
		out.println(ans.reverse());
	}
	
	public void doHasZero(int[][] a, int n)
	{
		int[][][] dp = new int[n][n][3];
		for(int i = 0;i < n;++i)
		{
			for(int j = 0;j < n;++j)
			{
				dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
				if(a[i][j] % 10 != 0)
				{
					if(0 == a[i][j] % 2)
					{
						if(0 == i && 0 == j)
						{
							dp[i][j][1] = 1;
						} 
						if(j > 0 && (dp[i][j - 1][0] != -1 || dp[i][j - 1][1] != -1))
						{
							dp[i][j][1] = 1;
						}
						else if(i > 0 && (dp[i - 1][j][0] != -1 || dp[i - 1][j][1] != -1))
						{
							dp[i][j][1] = 2;
						}
					}
					else if(0 == a[i][j] % 5)
					{
						if(0 == i && 0 == j)
						{
							dp[i][j][2] = 1;
						} 
						if(j > 0 && (dp[i][j - 1][0] != -1 || dp[i][j - 1][2] != -1))
						{
							dp[i][j][2] = 1;
						}
						else if(i > 0 && (dp[i - 1][j][0] != -1 || dp[i - 1][j][2] != -1))
						{
							dp[i][j][2] = 2;
						}
					}
					else
					{
						if(0 == i && 0 == j)
						{
							dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 1;
						} 
						if(j > 0 && dp[i][j - 1][0] != -1)
						{
							dp[i][j][0] = 1;
						}
						else if(i > 0 && dp[i - 1][j][0] != -1 )
						{
							dp[i][j][0] = 2;
						}
						if(j > 0 && (dp[i][j - 1][0] != -1 || dp[i][j - 1][1] != -1))
						{
							dp[i][j][1] = 1;
						}
						else if(i > 0 && (dp[i - 1][j][0] != -1 || dp[i - 1][j][1] != -1))
						{
							dp[i][j][1] = 2;
						}
						if(j > 0 && (dp[i][j - 1][0] != -1 || dp[i][j - 1][2] != -1))
						{
							dp[i][j][2] = 1;
						}
						else if(i > 0 && (dp[i - 1][j][0] != -1 || dp[i - 1][j][2] != -1))
						{
							dp[i][j][2] = 2;
						}
					}
				}
			}
		}
		int index = -1;
		for(int i = 0;i < 3;++i)
		{
			if(dp[n - 1][n - 1][i] != -1)
			{
				index = i;
				break;
			}
		}
		if(index != -1)
		{
			out.println(0);
			int r = n - 1, c = n - 1;
			StringBuilder ans = new StringBuilder();
			while(r != 0 || c != 0)
			{
				if(1 == dp[r][c][index])
				{
					--c;
					ans.append('R');
				}		
				else
				{
					--r;
					ans.append('D');
				}
			}
			out.println(ans.reverse());
		}
		else
		{
			out.println(1);
			int r0 = -1, c0 = -1;
			for(int i = 0;i < n && -1 == r0;++i)
			{
				for(int j = 0;j < n && -1 == r0;++j)
				{
					if(0 == a[i][j])
					{
						r0 = i;
						c0 = j;
					}
				}
			}
			StringBuilder ans = new StringBuilder();
			for(int i = 0;i < r0;++i)
			{
				ans.append('D');
			}
			for(int i = 0;i < c0;++i)
			{
				ans.append('R');
			}
			for(int i = r0 + 1;i < n;++i)
			{
				ans.append('D');
			}
			for(int i = c0 + 1;i < n;++i)
			{
				ans.append('R');
			}
			out.println(ans);
		}
	}
	
	public void doNotHasZero(int[][] a, int n)
	{
		int[][] dp2 = new int[n][n];
		int[][] path2 = new int[n][n];
		int[][] dp5 = new int[n][n];
		int[][] path5 = new int[n][n];
		for(int i = 0;i < n;++i)
		{
			for(int j = 0;j < n;++j)
			{
				int num2 = divide(a[i][j], 2);
				int num5 = divide(a[i][j], 5);
				if(0 == i && 0 == j)
				{
					path2[i][j] = 1;
					dp2[i][j] = num2;
					path5[i][j] = 1;
					dp5[i][j] = num5;
				}
				else if(0 == i)
				{
					path2[i][j] = 1;
					dp2[i][j] = num2 + dp2[i][j - 1];
					path5[i][j] = 1;
					dp5[i][j] = num5 + dp5[i][j - 1];
				}
				else if(0 == j)
				{
					path2[i][j] = 2;
					dp2[i][j] = num2 + dp2[i - 1][j];
					path5[i][j] = 2;
					dp5[i][j] = num5 + dp5[i - 1][j];
				}
				else
				{
					if(dp2[i][j - 1] < dp2[i - 1][j])
					{
						path2[i][j] = 1;
						dp2[i][j] = num2 + dp2[i][j - 1];
					}
					else
					{
						path2[i][j] = 2;
						dp2[i][j] = num2 + dp2[i - 1][j];
					}
					if(dp5[i][j - 1] < dp5[i - 1][j])
					{
						path5[i][j] = 1;
						dp5[i][j] = num5 + dp5[i][j - 1];
					}
					else
					{
						path5[i][j] = 2;
						dp5[i][j] = num5 + dp5[i - 1][j];
					}
				}
			}
		}
		if(dp2[n - 1][n - 1] < dp5[n - 1][n - 1])
		{
			out.println(dp2[n - 1][n - 1]);
			printPath(path2, n);
		}
		else
		{
			out.println(dp5[n - 1][n - 1]);
			printPath(path5, n);
		}
	}
	
	public void foo()
	{
		int n = scan.nextInt();
		int[][] a = new int[n][n];
		boolean hasZero = false;
		for(int i = 0;i < n;++i)
		{
			for(int j = 0;j < n;++j)
			{
				a[i][j] = scan.nextInt();
				if(0 == a[i][j])
				{
					hasZero = true;
				}
			}
		}
		if(hasZero)
		{
			doHasZero(a, n);
		}
		else
		{
			doNotHasZero(a, n);
		}
	}

	public static void main(String[] args)
	{
		Main m = new Main();
		m.foo();
		m.out.close();
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