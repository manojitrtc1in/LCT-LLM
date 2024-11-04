

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
			


			String str = s.next();
			int n= str.length();




























			boolean removed[] = new boolean[n];
			Stack<Integer> stack = new Stack<>();
			Queue<Integer> ques = new LinkedList<>();
			
			for(int i = 0;i < str.length();i++) {
				if(stack.isEmpty() && ques.size()==1) {
					int ind = ques.remove();
					stack.push(ind);
					removed[ind] = true;
				}
				if(str.charAt(i)=='(') {
					stack.push(i);
					removed[i] = true;
					continue;
				}
				if(str.charAt(i)==')'){
					if(stack.isEmpty()) {
						int ind  = ques.remove();
						removed[ind] = true;
						removed[i] = true;
					}else {
						removed[i] = true;
						stack.pop();
					}
				}else {
					ques.add(i);
				}
			}
			if(ques.size() == stack.size() || ques.size()==0) {
				System.out.print("YES ");
			}else {
				System.out.print("NO ");
			}
			




















































		    
			
			
			








































		}	
	}
	
	static String getRand(String str,int n) {
		if(n==0) {
			return str;
		}
		Random rand = new Random();
		int ind = rand.nextInt(str.length());
		str = str.substring(0,ind) + "?" + str.substring(ind+1,str.length());
		return getRand(str,n-1);
	}
	
	static void flag(boolean flag)
	   {
	       System.out.println(flag ? "YES" : "NO");
	   }

static boolean isRBS(char a[])
{
   int pre=0;
   for(char e : a)
   {
      if(e=='(') pre++;
      else pre--;
      
      if(pre<0) return false;
   }
  return pre==0;
}

	public static long solve(int arr[],int start,int end,long dp[]) {
		int n = arr.length;


		if(end - start == 1) {
			long ans = Long.MAX_VALUE;
			long curr = 0;
			


				curr = Math.max(0,Math.max(arr[start-1], arr[start+1])-arr[start]+1);



			ans = Math.min(ans, curr);
			curr = 0;


				curr += Math.max(0,Math.max(arr[end-1], arr[end+1])-arr[end]+1);


			ans = Math.min(ans, curr);
			return ans;
		}
		
		long ans = Long.MAX_VALUE;
		long curr = 0;
		ans = Math.min(ans,Math.max(0,Math.max(arr[start-1], arr[start+1])-arr[start]+1) + solve(arr,start+2,end,dp));
		








		ans = Math.min(ans, dp[start+1]);
		return ans;
	}
	
	public static int brute(int start,int end) {
		int ans = 0;
		if(start > end) {
			return 0;
		}else if(start==end) {
			return 1;
		}
		int mid = (start+end)/2;
		ans += brute(start,mid-1) + brute(mid+1,end);
		return ans;
	}
	
	public static int gcd(int a,int b) {
		
		if(a<b) {
			int temp = a;
			a = b;
			b = temp;
		}
		
		if(b==0) return a;
		
		while(a%b!=0) {
			int temp = a%b; 
			a = b;
			b = temp;
			if(b==0) return a;
		}
		return b;
	}
	
	public static int myGcd(int a,int b) {
		if(a<b) {
			int temp = a;
			a = b;
			b = temp;
		}
		
		while(b!=0) {
			int temp = a;
			a = b;
			b = temp%b;
		}
		return a;
	}
	
	public static Vector<Integer> sieveOfEratosthenes(int n)
	{
		

		

		

		

		

		

		

		boolean prime[] = new boolean[n + 1];
		for (int i = 0; i <= n; i++)
			prime[i] = true;

		for (int p = 2; p * p <= n; p++)
		{
			

			

			if (prime[p] == true)
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
	public static int logbase2(long n) {
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
	

	static long binomialCoeff(long n, long k)
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

	
	static long power(long x, long y, long p)
	{
		long res = 1; 


		x = x % p; 

		


		if (x == 0)
			return 0; 


		while (y > 0)
		{

			

			if ((y & 1) != 0)
				res = (res * x) % p;

			

			y = y >> 1; 

		x = (x * x) % p;
		}
		return res;
	}



	static long getPairsCount(int n, long sum,long arr[])
	{
		HashMap<Long, Integer> hm = new HashMap<>();

		

		for (int i = 0; i < n; i++) {

			

			if (!hm.containsKey(arr[i]))
				hm.put(arr[i], 0);

			hm.put(arr[i], hm.get(arr[i]) + 1);
		}
		long twice_count = 0;

		

		

		for (int i = 0; i < n; i++) {
			if (hm.get(sum - arr[i]) != null)
				twice_count += hm.get(sum - arr[i]);

			

			

			

			

			if (sum - arr[i] == arr[i])
				twice_count--;
		}

		

		return twice_count / 2;
	}

	public static<T,V> HashMap<T,V>
	sortByValue(HashMap<T,V> hm)
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
	sortByValueDescending(HashMap<T,Integer> unSortedMap)
	{
		LinkedHashMap<T,Integer> reverseSortedMap = new LinkedHashMap<>();
		unSortedMap.entrySet().stream().sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
		.forEachOrdered(x -> reverseSortedMap.put(x.getKey(), x.getValue()));

		return reverseSortedMap;
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

class Pair{
	int lastOcc;
	char ch;
	public Pair(int lastOcc,char ch) {
		this.lastOcc = lastOcc;
		this.ch = ch;
	}
	
	static class PairComparator implements Comparator<Pair>{

		public int compare(Pair p1,Pair p2) {
			return (p1.lastOcc < p2.lastOcc) ? -1 : 1;
		}
		
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

