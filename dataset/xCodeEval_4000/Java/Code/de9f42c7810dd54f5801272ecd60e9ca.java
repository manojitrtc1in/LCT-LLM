import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;


public class Main {
	static Scanner sc = new Scanner(System.in);
	
	
	
	
	
	
	
	
	
	
	
	
	static int[] a;
	static int[] b;
	static int moves;
	public static void solve(int indx)
	{
		if(indx==b.length)
		{
			int count=0;
			for (int i = 0; i < b.length; i++) {
				if(b[i]!=a[i])
				{
					count++;
				}
			}
			
			if(moves==-1 || moves>count)
			{
				moves=count;
			}
			return;
		}
		w: for (int i = 0; i < b.length; i++) {
			for (int j = 0; j < indx; j++) {
				if (b[j]==i || j+b[j]==indx + i || j-b[j]==indx - i){
					continue w;
				}
			}
			b[indx]=i;
			solve(indx+1);
		}
	}
	
	
	
	
	
	
	public static void main(String[] args) throws IOException {
		TreeMap<String, String> map= new TreeMap<String, String>();
		
		int n=sc.nextInt();
		
		for (int i = 0; i < n; i++) {
			String operation= sc.next();
		
			String A=sc.next();
			String B="";
			if (operation.equals("typedef")) {
				B=sc.next();
			}
			int ampersand=0;
			int asterisk=0;
			int f=-1;
			int l=-1;
			for (int j = 0; j < A.length(); j++) {
				

				if(f==-1 && A.charAt(j)!='&')
				{
					f=j;
				}
				else if (l==-1 && A.charAt(j)=='*') {
					l=j;
				}
				if (A.charAt(j)=='&') {
					ampersand++;
				}
				else if (A.charAt(j)=='*') {
					asterisk++;
				}
			}
			int tot=asterisk-ampersand;
			if(f==-1)
			{
				f=0;
			}
			if(l==-1)
			{
				l=A.length();
			}
			if(A.substring(f,l).equals("void"))
			{
				if(tot<0)
				{
					if (operation.equals("typedef")) {
						map.put(B, "errtype");
					}
					else
					{
						System.out.println("errtype");
					}
				}
				else
				{
					String temp="void";
					for (int j = 0; j < tot; j++) {
						temp+="*";
					}
					if (operation.equals("typedef")) {
						map.put(B, temp);
					}
					else
					{
						System.out.println(temp);
					}
				}
			}
			else
			{
				if(!map.containsKey(A.substring(f,l)))
				{
					if (operation.equals("typedef")) {
						map.put(B, "errtype");
					}
					else
					{
						System.out.println("errtype");
					}
				}
				else
				{
					String actualType=map.get(A.substring(f,l));
					asterisk=0;
					l=-1;
					for (int j = 0; j < actualType.length(); j++) {
						if (l==-1 && actualType.charAt(j)=='*') {
							l=j;
						}
						if (actualType.charAt(j)=='*') {
							asterisk++;
						}
					}
					if(l==-1)
					{
						l=actualType.length();
					}
					if(actualType.substring(0,l).equals("errtype"))
					{
						if (operation.equals("typedef")) {
							map.put(B, "errtype");
						}
						else
						{
							System.out.println("errtype");
						}
					}
					else
					{
						tot+=asterisk;
						if(tot<0)
						{
							if(operation.equals("typedef"))
							{
								map.put(B, "errtype");
							}
							else {
								System.out.println("errtype");
							}
						}
						else
						{
							String temp="void";
							for (int j = 0; j < tot; j++) {
								temp+="*";
							}
							if(operation.equals("typedef"))
							{
								map.put(B, temp);
							}
							else
							{
								System.out.println(temp);
							}
						}
					}
				}
				
			}
			

				
		}
	}
	
	static class person
	{
		int element;
		int team;
		
		public person(int e, int t) {
			element=e;
			team=t;
		}
		
		public String toString()
		{
			return "(" + element + "," + team +")";
			
		}
		
		
	}
	static class Scanner {
		StringTokenizer st;
		BufferedReader br;
 
		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}
 
		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
 
		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
 
		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}
 
		public String nextLine() throws IOException {
			return br.readLine();
		}
 
		public double nextDouble() throws IOException {
			String x = next();
			StringBuilder sb = new StringBuilder("0");
			double res = 0, f = 1;
			int start = 0;
			boolean dec = false, neg = false;
			if (x.charAt(0) == '-') {
				neg = true;
				start++;
			}
			for (int i = start; i < x.length(); i++)
				if (x.charAt(i) == '.') {
					res = Long.parseLong(sb.toString());
					sb = new StringBuilder("0");
					dec = true;
				} else {
					sb.append(x.charAt(i));
					if (dec)
						f *= 10;
				}
			res += Long.parseLong(sb.toString()) / f;
			return res * (neg ? -1 : 1);
		}
 
		public boolean ready() throws IOException {
			return br.ready();
		}
 
	}
}
