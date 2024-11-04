

import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class cp
{		
	
	public static void main(String[] args) throws IOException
	{	
		

		

		FastReader s = new FastReader();


		int t = s.nextInt();
		for(int p = 0;p < t;p++) {
			
			int n = s.nextInt();
			int x = s.nextInt();
			int y = s.nextInt();
			
			if(x==0 && y==0) {
				System.out.println(-1);
			}else if(x==0) {
				if((n-1)%y==0) {
					int div = (n-1)/y;
					ArrayList<Integer> ans = new ArrayList<>();
					int cnt = 0;
					int curr = 1;
					for(int i = 0;i < n-1;i++) {
						if(cnt==y) {
							cnt = 0;
							curr = i+2;
						}
						ans.add(curr);
						cnt++;
					}


					for(int an:ans) {
						System.out.print(an+" ");
					}

					System.out.println();
				}else {
					System.out.println(-1);
				}
			}else if(y==0) {
				if((n-1)%x==0) {
					int div = (n-1)/x;
					ArrayList<Integer> ans = new ArrayList<>();
					int cnt = 0;
					int curr = 1;
					for(int i = 0;i < n-1;i++) {
						if(cnt==x) {
							cnt = 0;
							curr = i+2;
						}
						ans.add(curr);
						cnt++;
					}


					for(int an:ans) {
						System.out.print(an+" ");
						
					}
					System.out.println();
				}else {
					System.out.println(-1);
				}
			}else {
				System.out.println(-1);


































































				
			}
			
			
		}	
	}
	
	public static int id7(long a,int m) {
		

		if(gcd(a,m)!=1) {
			return -1;

		}
		
		

		
		return power(a,m-2,m);
	}
	
	public static int binaryExpo(int a,int b,int m) {
		if(b==0) {
			return 1;
		}
		if(b==1) {
			return a;
		}
		
		long smallAns = binaryExpo(a, b/2, m);
		
		if(b%2==0) {
			return Math.floorMod(smallAns*smallAns,m);
		}else {
			return Math.floorMod(smallAns*smallAns*a, m);
		}
	}
	
	public static int divModulo(long a,long b,int m) {
		

		

		long A = a;
		long Binverse = id7(b, m);
		
		return Math.floorMod(A*Binverse,m);
	}
	
	public static long gcd(long a,long b) {
		if(b>a) {
			long temp = a;
			a = b;
			b = temp;
		}
		
		while(b>0) {
			long temp = a;
			a = b;
			b = temp%b;
		}
		return a;
	}
	
	public static Vector<Integer> id4(int n)
	{
		

		

		

		

		

		

		

		boolean prime[] = new boolean[n + 1];
		for (int i = 0; i <= n; i++)
			prime[i] = true;

		for (int p = 2; p * p <= n; p++)
		{
			

			

			if (prime[p] == true && (long)p*p <= n)
			{
				

				for (int i = p * p; i <= n; i += p)
					prime[i] = false;
			}
		}
		Vector<Integer> v = new Vector<>();
		

		for (int i = 2; i <= n; i++)
		{
			if (prime[i] == true)
				v.add(i);
		}
		return v;
	}
	
	
	public static int id3(long n) {
		int count = 0;
		if(n==0) {
			return -1;
		}
		while(n >= 2) {
			n /= 2;
			count++;
		}
		return count;
	}
	
	public static boolean isPrime(int n)
	{
	    

	    if (n <= 1)  return false;
	    if (n <= 3)  return true;
	   
	    

	    

	    if (n%2 == 0 || n%3 == 0) return false;
	   
	    for (int i=5; i*i<=n; i=i+6)
	        if (n%i == 0 || n%(i+2) == 0)
	           return false;
	   
	    return true;
	}
	

	static long id6(long n, long k)
	{
		long res = 1;

		

		if (k > n - k)
			k = n - k;

		

		

		for (int i = 0; i < k; ++i) {
			res *= (n - i);
			res /= (i + 1);
		}

		return res;
	}

	public static void shuffleArray(int[] ar)
	{
		

		Random rnd = new Random();
		for (int i = ar.length - 1; i > 0; i--)
		{
			int index = rnd.nextInt(i + 1);
			

			int a = ar[index];
			ar[index] = ar[i];
			ar[i] = a;
		}
	}

	
	static int power(long a, long b, int m)
	{
		int res = 1; 

		long x = a;
		long y = b;
		x = x % m; 

		

		
		if (x == 0)
			return 0; 


		while (y > 0)
		{

			

			if ((y & 1) != 0)
				res = (int)((res * x) % m);

			

			y = y >> 1; 

			x = (x * x) % m;
		}
		return res;
	}



	static long id5(int n, long sum,long arr[])
	{
		HashMap<Long, Integer> hm = new HashMap<>();

		

		for (int i = 0; i < n; i++) {

			

			if (!hm.containsKey(arr[i]))
				hm.put(arr[i], 0);

			hm.put(arr[i], hm.get(arr[i]) + 1);
		}
		long id8 = 0;

		

		

		for (int i = 0; i < n; i++) {
			if (hm.get(sum - arr[i]) != null)
				id8 += hm.get(sum - arr[i]);

			

			

			

			

			if (sum - arr[i] == arr[i])
				id8--;
		}

		

		return id8 / 2;
	}

	public static<T,V> HashMap<T,V>
	id0(HashMap<T,V> hm)
	{
		

		List<Map.Entry<T,V> > list
		= new LinkedList<Map.Entry<T,V> >(
				hm.entrySet());

		

		Collections.sort(
				list,
				(i1,
						i2) -> ((String) i1.getValue()).compareTo((String) i2.getValue()));

		

		HashMap<T,V> temp
		= new LinkedHashMap<T,V>();
		for (Map.Entry<T,V> aa : list) {
			temp.put(aa.getKey(), aa.getValue());
		}
		return temp;
	}

	public static<T> HashMap<T,Integer>
	id1(HashMap<T,Integer> id9)
	{
		LinkedHashMap<T,Integer> id2 = new LinkedHashMap<>();
		id9.entrySet().stream().sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
		.forEachOrdered(x -> id2.put(x.getKey(), x.getValue()));

		return id2;
	}


	static int lower_bound(long array[], long key,long start,long end)
	{
		

		

		long low = start, high = end;
		long mid;

		

		while (low < high) {

			

			mid = low + (high - low) / 2;

			

			

			

			if (key <= array[(int)mid]) {
				high = mid;
			}

			

			

			else {

				low = mid + 1;
			}
		}

		

		

		

		if (low < end && array[(int)low] < key) {
			low++;
		}

		

		return (int)low;
	}

	static int upper_bound(long array[], long key,long start,long end)
	{
		

		

		long low = start, high = end;
		long mid;

		

		while (low < high) {

			

			mid = low + (high - low) / 2;

			

			

			

			if (key >= array[(int)mid]) {
				low = mid+1;
			}

			

			

			else {

				high = mid;
			}
		}

		

		

		

		if (low < end && array[(int)low] <= key) {
			low++;
		}

		

		return (int)low;
	}

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader()
		{
			br = new BufferedReader(
					new InputStreamReader(System.in));
		}

		String next()
		{
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				}
				catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() { return Integer.parseInt(next()); }

		long nextLong() { return Long.parseLong(next()); }

		double nextDouble()
		{
			return Double.parseDouble(next());
		}

		String nextLine()
		{
			String str = "";
			try {
				str = br.readLine();
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
	static class Reader {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public Reader()
		{
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public Reader(String file_name) throws IOException
		{
			din = new DataInputStream(
					new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public String readLine() throws IOException
		{
			byte[] buf = new byte[64]; 

			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n') {
					if (cnt != 0) {
						break;
					}
					else {
						continue;
					}
				}
				buf[cnt++] = (byte)c;
			}
			return new String(buf, 0, cnt);
		}

		public int nextInt() throws IOException
		{
			int ret = 0;
			byte c = read();
			while (c <= ' ') {
				c = read();
			}
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}

		public long nextLong() throws IOException
		{
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}

		public double nextDouble() throws IOException
		{
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();

			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (c == '.') {
				while ((c = read()) >= '0' && c <= '9') {
					ret += (c - '0') / (div *= 10);
				}
			}

			if (neg)
				return -ret;
			return ret;
		}

		private void fillBuffer() throws IOException
		{
			bytesRead = din.read(buffer, bufferPointer = 0,
					BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}

		private byte read() throws IOException
		{
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}

		public void close() throws IOException
		{
			if (din == null)
				return;
			din.close();
		}
	}


}

class Pair implements Comparable<Pair>{
	int lastOcc;
	char ch;
	public Pair(int lastOcc,char ch) {
		this.lastOcc = lastOcc;
		this.ch = ch;
	}
	
	public int compareTo(Pair p) {
		return (this.lastOcc<p.lastOcc)?-1:1;
	}
	
	
}



































class Domino{
	int a,b;
	boolean visited;
	public Domino(int a,int b) {
		this.a = a;
		this.b = b;
		visited = false;
	}
}