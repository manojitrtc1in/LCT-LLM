import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.FileReader;
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
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main
{	
	
	private MyScanner scan = new MyScanner();


	private final double PI = Math.PI;
	private final int INF = (int)(1e9);
	private final double EPS = 1e-6;
	private final int SIZEN = (int)(1e5);
	private final int MOD = (int)(1e9 + 7);
	private final long MODH = 10000000007L, BASE = 10007;
	private final int[] DX = {0, 1, 0, -1}, DY = {-1, 0, 1, 0};
	StringTokenizer str = null;
	BufferedReader  in;
	PrintWriter  out;
	private int n, kk;
	private long tt;
	private Task[] tsk;
	private long [] ans;
	
	private String next() throws Exception{
		while (str == null || !str.hasMoreElements())
			str = new StringTokenizer(in.readLine());
		return str.nextToken();
	}
	
	private int nextInt() throws Exception{
		return Integer.parseInt(next());
	}
	
	private long nextLong() throws Exception{
		return Long.parseLong(next());
	}
	
	private double nextDouble() throws Exception{
		return Double.parseDouble(next());
	}
	
	public long simulatePrint()
	{
		Arrays.sort(tsk, new Comparator<Task>()
		{
			public int compare(Task tsk1, Task tsk2) 
			{
				return tsk1.t - tsk2.t;
			}
		});
		PriorityQueue<Task> q = new PriorityQueue<Task>(n, new Comparator<Task>()
		{
			public int compare(Task tsk1, Task tsk2) 
			{
				return tsk2.p - tsk1.p;
			}
		});
		int k = 0;
		long t0 = tsk[0].t;
		while(!q.isEmpty() || k < n)
		{
			if(!q.isEmpty())
			{
				Task tmp = q.poll();
				if(k == n || tmp.s + t0 <= tsk[k].t)
				{
					t0 += tmp.s;
					ans[tmp.id] = t0;
					if(tmp.id == kk && ans[tmp.id] != tt) break;
					continue;
				}
				else
				{
					tmp.s -= tsk[k].t - t0;
					q.add(tmp);
				}
			}
			t0 = tsk[k].t;
			while(k < n && tsk[k].t == t0)
			{
				q.add(new Task(tsk[k].t, tsk[k].s, tsk[k].p, tsk[k].id));
				++k;
			}
		}
		return ans[kk];
	}
	
  	public void foo () throws Exception
  	{
  		in =  new BufferedReader(new FileReader("input.txt"));
  		out = new PrintWriter("output.txt");
  		n = nextInt();
  		tsk = new Task[n];
  		int[] pr = new int[n];
  		for(int i = 0;i < n;++i)
  		{
  			tsk[i] = new Task(nextInt(), nextInt(), nextInt(), i);
  			if(tsk[i].p != -1) pr[i] = tsk[i].p;
  			else kk = i;
  		}
  		tt = nextLong();
  		Arrays.sort(pr);
  		ArrayList<Integer> pCand = new ArrayList<Integer>();
  		for(int i = 0;i < n - 1;++i)
  		{
  			if(pr[i] + 1 != pr[i + 1]) pCand.add(pr[i] + 1);
  		}
  		if(pr[n - 1] + 1 <= 1e9) pCand.add(pr[n - 1] + 1);
  		int left = 0, right = pCand.size() - 1;
  		ans = new long[n];
  		while(left <= right)
  		{
  			int mid = (left + right) >> 1;
  			for(int i = 0;i < n;++i)
  			{
  				if(tsk[i].id == kk)
  				{
  					tsk[i].p = pCand.get(mid);
  					break;
  				}
  			}
  			long tmp = simulatePrint();
  			if(tmp == tt)
  			{
  				out.println(pCand.get(mid));
  				for(int i = 0;i < n;++i) out.print(ans[i] + " ");
  				return;
  			}
  			else if(tmp < tt) right = mid - 1;
  			else left = mid + 1;
  		}
  	}  
  	
  	class Task
  	{
  		private int t, s, p, id;
  		public Task(int aT, int aS, int aP, int aId)
  		{
  			t = aT;
  			s = aS;
  			p = aP;
  			id = aId;
  		}
  	}

	public static void main(String[] args) throws Exception
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