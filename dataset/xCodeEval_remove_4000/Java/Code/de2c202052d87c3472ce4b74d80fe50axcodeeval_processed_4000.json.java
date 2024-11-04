import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.SortedMap;
import java.util.StringTokenizer;
import java.util.TreeMap;




public class Main {

	public static void main(String[] args) {

		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		solve(in, out);
		out.close();
	}

	static String reverse(String s) {
		return (new StringBuilder(s)).reverse().toString();
	}

	static void id1(int n, Integer factors[], ArrayList<Integer> ar) 
    { 
		Arrays.fill(factors, 0);
        factors[1]=1;
        int p;
        for(p = 2; p*p <=n; p++) 
        { 
            if(factors[p] == 0) 
            { 
                ar.add(p);
                factors[p]=p;
                for(int i = p*p; i <= n; i += p) 
                    factors[i] = p; 
            } 
        } 
        for(;p<=n;p++){
            if(factors[p] == 0) 
            { 
                ar.add(p);
            } 
        }
    }

    static int lower_bound(int val, int high,Integer[] arr) {
        int low = 0;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= val) {
                low = mid + 1;
                ans = mid;
            } else
                high = mid - 1;
        }
        return ans;
    }

    static int upper_bound(int val, int high, Integer[] a) {
        int low = 0;
        int ans = high + 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] >= val) {
                high = mid - 1;
                ans = mid;
            } else
                low = mid + 1;
        }
        return ans;
    }

	static void sort(int ar[]) {
		int n = ar.length;
		ArrayList<Integer> a = new ArrayList<>();
		for (int i = 0; i < n; i++)
			a.add(ar[i]);
		Collections.sort(a);
		for (int i = 0; i < n; i++)
			ar[i] = a.get(i);
	}

	static void sort1(long ar[]) {
		int n = ar.length;
		ArrayList<Long> a = new ArrayList<>();
		for (int i = 0; i < n; i++)
			a.add(ar[i]);
		Collections.sort(a);
		for (int i = 0; i < n; i++)
			ar[i] = a.get(i);
	}

	static long ncr(long n, long r, long mod) {
		if (r == 0)
			return 1;
		long val = ncr(n - 1, r - 1, mod);
		val = (n * val) % mod;
		val = (val * modInverse(r, mod)) % mod;
		return val;
	}

	public static int convert(String a, String b) {
		int T = 0;
		if (b.charAt(0) == 'P') {
			if (a.charAt(0) == '1' && a.charAt(1) == '2')
				T = 12;
			else
				T = (a.charAt(0) - '0') * 10 + (a.charAt(1) - '0') + 12;
		} else if (b.charAt(0) == 'A') {
			if (a.charAt(0) == '1' && a.charAt(1) == '2')
				T = 0;
			else
				T = (a.charAt(0) - '0') * 10 + (a.charAt(1) - '0');
		}

		T = T * 100 + (a.charAt(3) - '0') * 10 + (a.charAt(4) - '0');
		return T;

	}

	static boolean id2(String expr) {
		

		Deque<Character> stack = new ArrayDeque<Character>();

		

		for (int i = 0; i < expr.length(); i++) {
			char x = expr.charAt(i);

			if (x == '(' || x == '[' || x == '{') {
				

				stack.push(x);
				continue;
			}

			

			

			

			if (stack.isEmpty())
				return false;
			char check;
			switch (x) {
			case ')':
				check = stack.pop();
				if (check == '{' || check == '[')
					return false;
				break;

			case '}':
				check = stack.pop();
				if (check == '(' || check == '[')
					return false;
				break;

			case ']':
				check = stack.pop();
				if (check == '(' || check == '{')
					return false;
				break;
			}
		}

		

		return (stack.isEmpty());
	}

	public static int hr(String s) {
		int hh = 0;
		hh = (s.charAt(0) - '0') * 10 + (s.charAt(1) - '0');
		return hh;
	}

	public static int mn(String s) {
		int mm = 0;
		mm = (s.charAt(3) - '0') * 10 + (s.charAt(4) - '0');
		return mm;
	}

	

	public static String rev(String s) {
		char[] temp = s.toCharArray();
		for (int i = 0; i < s.length() / 2; i++) {
			char tmp = temp[i];
			temp[i] = temp[s.length() - 1 - i];
			temp[s.length() - 1 - i] = tmp;

		}
		String str = "";
		for (char ch : temp) {
			str += ch;
		}
		return str;
	}

	static boolean isP(String str) {

		

		

		int i = 0, j = str.length() - 1;

		

		while (i < j) {

			

			if (str.charAt(i) != str.charAt(j))
				return false;

			

			

			i++;
			j--;
		}

		

		return true;
	}

	public static boolean isSorted(List<Integer> l) {
		int n = l.size(), i = 0;
		for (i = 1; i < l.size(); i++) {
			if (l.get(i - 1) < l.get(i))
				return false;
		}
		return true;
	}

	public static boolean ln(long n, int c) {
		int l = 0;
		long t = n;
		while (t != 0) {

			t /= 10;
			l++;
		}
		return l == c;
	}
	public static Integer dp[];
	
	
	
	static int getPrev(int n)
	{
	    

	    

	    int temp = n;
	    int c0 = 0;
	    int c1= 0;
	 
	    while((temp & 1) == 1)
	    {
	        c1++;
	        temp = temp >> 1;
	    }
	 
	    if(temp == 0)
	        return -1;
	 
	    while(((temp & 1) == 0) &&
	           (temp!= 0))
	    {
	        c0++;
	        temp = temp >> 1;
	    }
	 
	    

	    

	    int p = c0 + c1;
	 
	    

	    n = n & ((~0) << (p + 1));
	 
	    

	    int mask = (1 << (c1 + 1)) - 1;
	 
	    n = n | mask << (c0 - 1);
	 
	    return n;
	}
	 static boolean id0(int n)
	    {
	        if (n == 0)
	            return false;
	  
	        while (n != 1) {
	            if (n % 2 != 0)
	                return false;
	            n = n / 2;
	        }
	        return true;
	    }
public static boolean check(int x, int y)
{
 boolean a[]=new boolean[10];
 while(x!=0)
 {
	 a[x%10]=true;
	 x/=10;
 }
 while(y!=0)
 {
	 if(a[y%10]) return true;
	 y/=10;
 }
 return false;
	
}
	static boolean alleq(int a[],int n)
	{
		for(int i=0;i<n-1;i++)
		{
			if(a[i]!=a[i+1])
				return false;
		}
		return true;
	}




	public static void solve(InputReader sc, PrintWriter pw) {
		
		int t=sc.nextInt();
		
		
		while(t-->0)
		{
			
			int n=sc.nextInt();
			int m=sc.nextInt();
			String[] s=new String[n];
			char c[][]=new char[n][m];
			for(int i=0;i<n;i++)
			{
				s[i]=sc.next();
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					c[i][j]=s[i].charAt(j);
				}
			}
			boolean f=true;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(j+2<m&&s[i].charAt(j)!='.'&&s[i].charAt(j+2)!='.'&&s[i].charAt(j)!=s[i].charAt(j+2)) {
						f=false;
						break;
					}
					if(j+1<m&&s[i].charAt(j)!='.'&&s[i].charAt(j+1)!='.'&&s[i].charAt(j)==s[i].charAt(j+1)) {
						f=false;
						break;
					}
				}
				if(!f) break;
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(i+2<n&&s[i].charAt(j)!='.'&&s[i+2].charAt(j)!='.'&&s[i].charAt(j)!=s[i+2].charAt(j)) {
						f=false;
						break;
					}
					if(i+1<n&&s[i].charAt(j)!='.'&&s[i+1].charAt(j)!='.'&&s[i].charAt(j)==s[i+1].charAt(j)) {
						f=false;
						break;
					}
				}
				if(!f) break;
			}
			boolean dt=true;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(s[i].charAt(j)=='R'||s[i].charAt(j)=='W') {
						dt=false;
						break;
					}
				}
				if(!dt) break;
			}
			if(dt)
			{
				pw.println("YES");
				for(int i=0;i<n;i++)
				{
					if(i%2==0)
					{
						
					for(int j=0;j<m;j++)
					{
						if(j%2==0)
							pw.print('W');
						else
							pw.print('R');
					}
					}
					else
					{
						for(int j=0;j<m;j++)
						{
							if(j%2!=0)
								pw.print('W');
							else
								pw.print('R');
						}
					}
					
					pw.print("\n");
					
				}
				

				continue;
				
				
			}
			
			boolean r=false;
			boolean w=false;
			if(f)
			{
				
				int j=0;
				boolean re=false;
				boolean we=false;
				for(int i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						
						if(c[i][j]=='R')
						{
						  r=true;
						  if((i+j)%2==0) re=true;
						  
						  
						  break;
						  
						}
						
						
					}
					if(re) break;
					
				}
				for(int i=0;i<n;i++)
				{
					for(j=0;j<m;j++)
					{
						if(c[i][j]=='W')
						{
							w=true;
							if((i+j)%2==0) we=true;
							
							
							break;
						}
						
						
					}
					if(we) break;
					
				}
				
				
				
				
				
				
				
				
				
				
				
				
				
				for(int i=0;i<n;i++)
				{
					for( j=0;j<m;j++)
					{
						if(r)
						{
							if(re)
							{
								if((i+j)%2==0) {
									if(c[i][j]=='.')
									 c[i][j]='R';
								}
								else { 
									if(c[i][j]=='.')
									  c[i][j]='W';
								}
							}
							else
							{
								if((i+j)%2!=0) {if(c[i][j]=='.') c[i][j]='R';}
								else
									if(c[i][j]=='.') {
									c[i][j]='W';
									}
							}
						}
						
						
					}
				}
				for(int i=0;i<n;i++)
				{
					for( j=0;j<m;j++)
					{
						 if(w)
						   {
							   if(we)
								{
								   
									if((i+j)%2==0) {if(c[i][j]=='.') c[i][j]='W';}
									else { if(c[i][j]=='.') c[i][j]='R';}
								}
								else
								{
									if((i+j)%2!=0) {if(c[i][j]=='.') c[i][j]='W';}
									else {
										if(c[i][j]=='.')
										 c[i][j]='R';
									}
								}
						   }
				         
						
						
					}
				}
				
				
				
			}
			for(int i=0;i<n-1;i++)
			{
				for(int j=0;j<m-1;j++)
				{
					if(c[i][j]==c[i][j+1]||c[i][j]==c[i+1][j]) {
						f=false;
						break;
					}
				}
				if(!f) break;
			}
				
			
			if(f) {
				pw.print("YES"+"\n");
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					pw.print(c[i][j]);
				}
				pw.print("\n");
			}
		

			}
			else
				pw.print("NO"+"\n");
			}
			
 }

	 
	 
	
 
		
			

		
         

			
			
    	
			
	 
	
		
	public static int fun(int x)
	{
		
	int lod=0;
		  while(x!=0)
		  {
			  x/=10;
			  lod++;
			  
		  }
		  return lod;
	}
 public static String funs(int n)
 {
	 String s="1";
	 while(n-->1)
	 {
		 s+="0";
	 }
	 return s;
 }




	static class Pair1 {
		long a;
		long b;

		Pair1(long a, long b) {
			this.a = a;
			this.b = b;
		}
	}

	static class Pair implements Comparable<Pair> {
		int a;
		int b;

		Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}

		public int compareTo(Pair p) {
			if (a != p.a)
				return p.a - a;
			return b - p.b;
		}
	}

	static boolean isPrime(int n) {
		if (n <= 1)
			return false;
		if (n <= 3)
			return true;
		if (n % 2 == 0 || n % 3 == 0)
			return false;
		for (int i = 5; i * i <= n; i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;
		return true;
	}

	static long gcd(long a, long b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	static int _gcd(int a, int b) {
		if (b == 0)
			return a;
		return _gcd(b, a % b);
	}

	static long fast_pow(long base, long n, long M) {
		if (n == 0)
			return 1;
		if (n == 1)
			return base % M;
		long halfn = fast_pow(base, n / 2, M);
		if (n % 2 == 0)
			return (halfn * halfn) % M;
		else
			return (((halfn * halfn) % M) * base) % M;
	}

	static long modInverse(long n, long M) {
		return fast_pow(n, M - 2, M);
	}

	public static int LowerBound(int a[], int x) {
		int l = -1, r = a.length;
		while (l + 1 < r) {
			int m = (l + r) >>> 1;
			if (a[m] >= x)
				r = m;
			else
				l = m;
		}
		return r;
	}

	public static int UpperBound(int a[], int x) {
		int l = -1, r = a.length;
		while (l + 1 < r) {
			int m = (l + r) >>> 1;
			if (a[m] <= x)
				l = m;
			else
				r = m;
		}
		return l + 1;
	}
	

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String nextLine() {
			return null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
