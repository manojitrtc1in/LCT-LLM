import java.util.*;
import static java.lang.Math.*;
import java.util.stream.LongStream;
import java.io.*;
import java.math.*;

public class Main{

	public static void main(String[] args) {
		FastReader fr = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        Scanner sc= new Scanner (System.in);
        
        

		StringBuilder answer = new StringBuilder();
		int t = fr.nextInt();

		for (int tt = 1; tt <=t; tt++) {
			 int n = fr.nextInt();
			

			

			

			

			

			

			

			

			

			

			

			


			


			

			

			

			

			

			

			

			

			


			int [] a = fr.readArray(n);
			if(n%2==1)
				{
					answer.append("NO\n");
					continue;
				}
			Arrays.sort(a);
			int [] b = new int [n];
			int begin = n/2-1;
			int end = n-1;
			int index = 0;
			while (index<n-1) {
				b[index]=a[end--];
				b[index+1]=a[begin--];
				index+=2;
			}
			boolean ans = true;
			for (int i = 0; i < b.length; i++) {
				ans&=((b[i]>b[(i+1)%n] && b[i]>b[(i-1+n)%n]) || (b[i]<b[(i+1)%n] && b[i]<b[(n+i-1)%n]));
			}
			answer.append(ans?"YES\n":"NO\n");
			if(ans){
				for (int i : b) {
					answer.append(i+" ");
				}
				answer.append("\n");
			}
			

			

			

			

			

			

			

			

			

			

			

			


		}
		out.println(answer.toString());
        out.flush();
        sc.close();
	
    }



	
	private static boolean rec(char[] arr, int a, int b, int c, int d , int index ) {
		if(index >= arr.length)
		{
			return true;
		}
		boolean ans = false;
		if(index<arr.length-1 && arr[index]!=arr[index+1])
		{
			if(c>0 && arr[index]=='A' && arr[index+1]=='B')
			{
				ans|= rec(arr, a, b, c-1, d, index+2);

			}
			else if(d>0 &&arr[index]=='B' && arr[index+1]=='A')
			{
				ans|= rec(arr, a, b, c, d-1 , index+2);
			}
		}
		if(a>0 && arr[index]=='A')
			ans|=rec(arr, a-1, b, c, d, index+1);
		if(b>0 && arr[index]=='B')
			ans|=rec(arr, a, b-1, c, d, index+1);
		return ans;

	}




	public static void push(HashMap<String,Integer> map , String val)
	{
		if(map.containsKey(val))
			map.put(val, map.get(val)+1);
		else
			{
				map.put(val, 1);
			}
	}
	public static void delete(HashMap<Integer,Integer> map, int key)
	{
		if(map.get(key)>1)
			map.put(key, map.get(key)-1);
		else
			{
				map.remove(key);
			}
	}
	public static boolean isSorted(int [] arr )
	{
		for (int i = 1; i < arr.length; i++) {
			if(arr[i]<arr[i-1]) return false;
		}
		return true;
	}


	public static TreeSet<Long> maxPrimeFactors(long n)
    {	
		TreeSet <Long> set = new TreeSet<>();
        long maxPrime = -1;
        while (n % 2 == 0) {
			maxPrime=2;
            n >>= 1;
        }    
        while (n % 3 == 0) {
			maxPrime=3;
            n = n / 3;
        }
        for (long i = 5; i <= Math.sqrt(n); i += 6) {
            while (n % i == 0) {
				maxPrime=i;
                n = n / i;
            }
            while (n % (i + 2) == 0) {
				set.add((long)(i+2));
                n = n / (i + 2);
            }
        }
        if (n > 4)
		{
			set.add((long)n);

		}
 
        return set;
    }

	public static int nSquaresFor(int n) {
		

        

        

		
        int sqrt = (int)Math.sqrt(n);
        if(sqrt*sqrt==n)
            return 1;
        
        while ((n&3)==0)
          n>>=2;
        if((n&7)==7)
          return 4;
        int x = (int)Math.sqrt(n);
        for(int i =1;i<=x;i++)
          {
            int temp = n-(i*i);
            int tempsqrt = (int)Math.sqrt(temp);
            if(tempsqrt*tempsqrt == temp) return 2;
          
        }
        return 3;
	}

	public static BigInteger Factorial(BigInteger number){
		if(number.compareTo(BigInteger.ONE)!=1)
		  {
		  return BigInteger.ONE;
		}
		return number.multiply(Factorial(number.subtract(BigInteger.ONE)));
	  }

	  private static boolean isPrime(int count) {
		if(count==1) return false;  
		if(count==2 || count ==3) return true;	
		if(count%2 == 0) return false;			
		if(count%3 ==0) return false;			
		for (int i = 5; i*i<=count; i+=6) {
				if(count%(i)==0 || count%(i+2)==0)
					return false;}
			return true;
		}
	  

	static ArrayList<Integer> sieveOfEratosthenes(int n)
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
        ArrayList <Integer> list = new ArrayList<>();
        

        for (int i = 2; i <= n; i++)
        {
            if (prime[i] == true)
                list.add(i);
        }
        return list;
    }

	    


    public static long[] radixSort(long[] f){ return radixSort(f, f.length); }
	public static long[] radixSort(long[] f, int n)
	{
		long[] to = new long[n];
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]>>>16&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]>>>16&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]>>>32&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]>>>32&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]>>>48&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]>>>48&0xffff)]++] = f[i];
			long[] d = f; f = to; to = d;
		}
		return f;
	}

	

	public static int[] radixSort2(int[] a)
	{
		int n = a.length;
		int[] c0 = new int[0x101];
		int[] c1 = new int[0x101];
		int[] c2 = new int[0x101];
		int[] c3 = new int[0x101];
		for(int v : a) {
			c0[(v&0xff)+1]++;
			c1[(v>>>8&0xff)+1]++;
			c2[(v>>>16&0xff)+1]++;
			c3[(v>>>24^0x80)+1]++;
		}
		for(int i = 0;i < 0xff;i++) {
			c0[i+1] += c0[i];
			c1[i+1] += c1[i];
			c2[i+1] += c2[i];
			c3[i+1] += c3[i];
		}
		int[] t = new int[n];
		for(int v : a)t[c0[v&0xff]++] = v;
		for(int v : t)a[c1[v>>>8&0xff]++] = v;
		for(int v : a)t[c2[v>>>16&0xff]++] = v;
		for(int v : t)a[c3[v>>>24^0x80]++] = v;
		return a;
	}


	
    static int lowerBound(long a[], long x) { 

        int l = -1, r = a.length;
        while (l + 1 < r) {
            int m = (l + r) >>> 1;
            if (a[m] >= x) r = m;
            else l = m;
        }
        return r;
    }

    static int upperBound(long a[], long x) {

        int l = -1, r = a.length;
        while (l + 1 < r) {
            int m = (l + r) >>> 1L;
            if (a[m] <= x) l = m;
            else r = m;
        }
        return l + 1;
    }

    static int upperBound(long[] arr, int start, int end, long k) {
        int N = end;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (k >= arr[mid]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        if (start < N && arr[start] <= k) {
            start++;
        }
        return start;
    }

    static long lowerBound(long[] arr, int start, int end, long k) {
        int N = end;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (k <= arr[mid]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        if (start < N && arr[start] < k) {
            start++;
        }
        return start;
    }
	

		

		public static long factorialStreams( long n )
		{
		return LongStream.rangeClosed( 1, n )
						 .reduce(1, ( long a, long b ) -> a * b);
		}
		
		

		public static long FastExp(long base, long exp) {
			long ans=1;
			long mod=998244353;
			while (exp>0) {
				if (exp%2==1) ans*=base;
				exp/=2;
				base*=base;
				base%=mod;
				ans%=mod;
			}
			return ans;
		}
		

		

		public static int gcd(int a, int b) 
			{ 

				if (a == 0) 
				return b;
	
				return gcd(b%a, a); 
	
			  }
	
		

		private static int gcdBinary(int x, int y)
		{
		  int shift;
	  
		  
		  if (x == 0)
			return y;
		  if (y == 0)
			return x;
	  
		  int gcdX = Math.abs(x);
		  int gcdY = Math.abs(y);
	  
		  if (gcdX == 1 || gcdY == 1)
			return 1;
	  
		  
		  for (shift = 0; ((gcdX | gcdY) & 1) == 0; ++shift)
		  {
			gcdX >>= 1;
			gcdY >>= 1;
		  }
	  
		  while ((gcdX & 1) == 0)
			gcdX >>= 1;
	  
		  
		  do
		  {
			
			
			while ((gcdY & 1) == 0)
			  
			  gcdY >>= 1;
	  
			
			if (gcdX > gcdY)
			{
			  final int t = gcdY;
			  gcdY = gcdX;
			  gcdX = t;
			}  

			gcdY = gcdY - gcdX;                       

		  }while (gcdY != 0);
	  
		  
		  return gcdX << shift;
		}
	




		

		public static boolean isPalindrome(String s)
		{
			return s.equals( new StringBuilder(s).reverse().toString());
		}



	

	public static class UnionFind {
        int[] p, rank, setSize;
        int numSets;
 
        public UnionFind(int N) {
            p = new int[numSets = N];
            rank = new int[N];
            setSize = new int[N];
            for (int i = 0; i < N; i++) {
                p[i] = i;
                setSize[i] = 1;
            }
        }
 
        public int findSet(int i) {
            return p[i] == i ? i : (p[i] = findSet(p[i]));
        }
 
        public boolean isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }
 
        public void unionSet(int i, int j) {
            if (isSameSet(i, j))
                return;
            numSets--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
                setSize[x] += setSize[y];
            } else {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
 
        public int numDisjointSets() {
            return numSets;
        }
 
        public int sizeOfSet(int i) {
            return setSize[findSet(i)];
        }
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
		
		double nextDouble(){ return Double.parseDouble(next()); }

		int[] readArray(int n) {
			int [] arr = new int [n];
			for (int i = 0; i < arr.length; i++) {
				arr[i]=nextInt();
			}
			return arr;
		}

		long[] readArray(long []arr , int n) {

			for (int i = 0; i < n; i++) {
				arr[i]=nextLong();
			}
			return arr;
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



    
}