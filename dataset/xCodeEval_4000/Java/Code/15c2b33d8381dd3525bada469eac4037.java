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
	
	
	
	
	
	
	public static void main(String[] args) throws IOException{
		TreeMap<Character, Long> map= new TreeMap<Character, Long>();
		TreeMap<Character, TreeMap<Long,Long>> mapList= new TreeMap<Character, TreeMap<Long,Long>>();
		for (char c = 'a'; c <= 'z'; c++) {
			map.put(c, (long) sc.nextInt());
		}
		
		String s=sc.next();
		long sum=0;
		long[] a = new long[s.length()];
		for (int i = 0; i < a.length; i++) {
			sum+=map.get(s.charAt(i));
			a[i]=sum;
			if(!mapList.containsKey(s.charAt(i)))
			{
				mapList.put(s.charAt(i), new TreeMap<Long,Long>());
			}
			if(!mapList.get(s.charAt(i)).containsKey(a[i]))
			{
				mapList.get(s.charAt(i)).put(a[i], (long)1);
			}
			else
			{
				mapList.get(s.charAt(i)).put(a[i], mapList.get(s.charAt(i)).get(a[i])+1);
			}
		}
		

		
		long count=0;
		for (int i=0; i<s.length(); i++) {
			long temp=a[i];
			if(mapList.get(s.charAt(i)).get(temp)==1)
			{
				mapList.get(s.charAt(i)).remove(temp);
			}
			else
			{
				mapList.get(s.charAt(i)).put(temp, mapList.get(s.charAt(i)).get(temp)-1);
			}
			temp+=map.get(s.charAt(i));
			if(mapList.get(s.charAt(i)).containsKey(temp))
			{
				count+=mapList.get(s.charAt(i)).get(temp);
			}
		}
		System.out.println(count);
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
