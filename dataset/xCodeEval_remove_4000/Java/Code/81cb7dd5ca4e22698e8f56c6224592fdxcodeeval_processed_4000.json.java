import java.util.*;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.zip.ZipEntry;

import javax.imageio.stream.MemoryCacheImageInputStream;
import javax.security.auth.kerberos.KerberosKey;
import javax.swing.plaf.basic.BasicScrollPaneUI.HSBChangeListener;
import javax.tools.JavaCompiler;
import javax.xml.bind.SchemaOutputResolver;
import javax.xml.crypto.dsig.spec.DigestMethodParameterSpec;
 
import org.omg.CORBA.TRANSACTION_MODE;
import org.omg.IOP.TAG_CODE_SETS;
 
import java.awt.font.GraphicAttribute;
import java.io.*;
import java.nio.channels.AcceptPendingException;
import java.rmi.server.RMIClassLoader;
import java.security.spec.DSAGenParameterSpec;
import java.sql.PseudoColumnUsage;
import java.time.Period;
 


public class Main {

    public static void main(String[] args) throws Exception {
  
    	int n=sc.nextInt();
    	int [] a=sc.id6(n);
    	HashMap<Integer, Integer>hs=new HashMap<Integer, Integer>();
    	for(int i=0;i<n;i++) {
    		for(int j=i+1;j<n;j++) {
        		hs.put(a[i]+a[j],hs.getOrDefault(a[i]+a[j], 0)+1 );
        	}
    	}
    	int max=0;
    	for(int i:hs.values()) {
    		max=Math.max(max, i);
    	}
    	pw.println(max);
    	
    	
    	
    	
    	
       pw.close();
    }
 
	static class Scanner {
		StringTokenizer st;
		BufferedReader br;
 
		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}
 
		public Scanner(FileReader r) {
			br = new BufferedReader(r);
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
			boolean dec = false, neg = false;
			int start = 0;
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
		public long[] id0(int n) throws IOException {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
		public Long[] id13(int n) throws IOException {
            Long[] a = new Long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
		public int[] id6(int n) throws IOException {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }
		public Integer[] id2(int n) throws IOException {
            Integer[] a = new Integer[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }
		public boolean ready() throws IOException {
			return br.ready();
		}
 
	}
 
	static class pair implements Comparable<pair> {
		long x;
		long y;
 
		public pair(long x, long y) {
			this.x = x;
			this.y = y;
		}
 
		public String toString() {
			return x + " " + y;
		}
		public boolean equals(Object o) {
            if (o instanceof pair) {
                pair p = (pair)o;
                return p.x == x && p.y == y;
            }
            return false;
        }
        public int hashCode() {
            return new Double(x).hashCode() * 31 + new Double(y).hashCode();
        }
        public int compareTo(pair other) {
        	if(this.x==other.x) {
        		return Long.compare(this.y, other.y);
        	}
			return Long.compare(this.x, other.x);
		}
	}
 
	static class tuble implements Comparable<tuble> {
		int x;
		int y;
		int z;
 
		public tuble(int x, int y, int z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}
 
		public String toString() {
			return x + " " + y + " " + z;
		}
 
		public int compareTo(tuble other) {
			if (this.x == other.x) {
				if(this.y==other.y) {
					return this.z - other.z;
				}
				return this.y - other.y;
			} else {
				return this.x - other.x;
			}
		}
	}
 
	public static long GCD(long a, long b) {
		if (b == 0)
			return a;
		if (a == 0)
			return b;
		return (a > b) ? GCD(a % b, b) : GCD(a, b % a);
	}
 
	public static long LCM(long a, long b) {
		return a * b / GCD(a, b);
	}
 
	static long Pow(long a, long e, long mod) 

	{
		a %= mod;
		long res = 1l;
		while (e > 0) {
			if ((e & 1) == 1)
				res = (res * a) % mod;
			a = (a * a) % mod;
			e >>= 1l;
		}
		return res;
	}
   public static long modinverse(long a,long mod) {
	   return Pow(a, mod-2, mod);
   }
	static long nc(int n, int r) {
		if (n < r)
			return 0;
		long v = fac[n];
		v *= Pow(fac[r], mod - 2, mod);
		v %= mod;
		v *= Pow(fac[n - r], mod - 2, mod);
		v %= mod;
		return v;
	}
 
	public static boolean isprime(long a) {
		if (a == 0 || a == 1) {
			return false;
		}
		if (a == 2) {
			return true;
		}
		for (int i = 2; i < Math.sqrt(a) + 1; i++) {
			if (a % i == 0) {
				return false;
			}
		}
		return true;
	}
 
	public static boolean isPal(String s) {
		boolean t = true;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
				t = false;
				break;
			}
		}
		return t;
	}
 
	public static long RandomPick(long[] a) {
		int n = a.length;
		int r = rn.nextInt(n);
		return a[r];
	}
 
	public static int RandomPick(int[] a) {
		int n = a.length;
		int r = rn.nextInt(n);
		return a[r];
	}
 
	public static void PH(String s, boolean reverse) {
		prelen = s.length();
		id5[id12] = new int[prelen + 1];
		prepow = new int[prelen];
		if (id12 == 0) {
			int[] mods = { 1173017693, 1173038827, 1173069731, 1173086977, 1173089783, 1173092147, 1173107093,
					1173114391, 1173132347, 1173144367, 1173150103, 1173152611, 1173163993, 1173174127, 1173204679,
					1173237343, 1173252107, 1173253331, 1173255653, 1173260183, 1173262943, 1173265439, 1173279091,
					1173285331, 1173286771, 1173288593, 1173298123, 1173302129, 1173308827, 1173310451, 1173312383,
					1173313571, 1173324371, 1173361529, 1173385729, 1173387217, 1173387361, 1173420799, 1173421499,
					1173423077, 1173428083, 1173442159, 1173445549, 1173451681, 1173453299, 1173454729, 1173458401,
					1173459491, 1173464177, 1173468943, 1173470041, 1173477947, 1173500677, 1173507869, 1173522919,
					1173537359, 1173605003, 1173610253, 1173632671, 1173653623, 1173665447, 1173675577, 1173675787,
					1173684683, 1173691109, 1173696907, 1173705257, 1173705523, 1173725389, 1173727601, 1173741953,
					1173747577, 1173751499, 1173759449, 1173760943, 1173761429, 1173762509, 1173769939, 1173771233,
					1173778937, 1173784637, 1173793289, 1173799607, 1173802823, 1173808003, 1173810919, 1173818311,
					1173819293, 1173828167, 1173846677, 1173848941, 1173853249, 1173858341, 1173891613, 1173894053,
					1173908039, 1173909203, 1173961541, 1173968989, 1173999193};
			mod = RandomPick(mods);
			int[] primes = { 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
			prime = RandomPick(primes);
		}
		prepow[0] = 1;
		if (!reverse) {
 
			for (int i = 1; i < prelen; i++) {
				prepow[i] = (int) ((1l * prepow[i - 1] * prime) % mod);
 
			}
			for (int i = 0; i < prelen; i++) {
				if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z')
					id5[id12][i + 1] = (int) ((1l * id5[id12][i]
							+ ((1l * s.charAt(i) - 'a' + 1) * prepow[i]) % mod) % mod);
				else
					id5[id12][i + 1] = (int) ((1l * id5[id12][i]
							+ ((1l * s.charAt(i) - 'A' + 27) * prepow[i]) % mod) % mod);
			}
 
		} else {
			for (int i = 1; i < prelen; i++) {
				prepow[i] = (int) ((1l * prepow[i - 1] * prime) % mod);
 
			}
			for (int i = 0; i < prelen; i++) {
				if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z')
					id5[id12][i + 1] = (int) ((1l * id5[id12][i]
							+ ((1l * s.charAt(i) - 'a' + 1) * prepow[prelen - 1 - i]) % mod) % mod);
				else
					id5[id12][i + 1] = (int) ((1l * id5[id12][i]
							+ ((1l * s.charAt(i) - 'A' + 27) * prepow[prelen - 1 - i]) % mod) % mod);
			}
 
		}
 
		id12++;
 
	}
 
	public static int PHV(int l, int r, int n, boolean reverse) {
		if (l > r) {
			return 0;
		}
		int val = (int) ((1l * id5[n - 1][r] + mod - id5[n - 1][l - 1]) % mod);
		if (!reverse) {
 
			val = (int) ((1l * val * prepow[prelen - l]) % mod);
		} else {
			val = (int) ((1l * val * prepow[r - 1]) % mod);
		}
		return val;
	}
 
    public static void genprime(int n) {
    	 boolean prime[] = new boolean[n+1]; 
         for(int i=0;i<n;i++) 
             prime[i] = true; 
           
         for(int p = 2; p*p <=n; p++) 
         { 
             if(prime[p] == true) 
             { 
                 for(int i = p*p; i <= n; i += p) 
                     prime[i] = false; 
             } 
         } 
         for(int i = 2; i <= n; i++) 
         { 
             if(prime[i] == true) {
                primes.put(i,primes.size());
                id1.put(id1.size(),i);
             }
             
         }
    }
   
   
    public static long LSB(long x) {
		return x&-x;
	}
	static class fenwick {
		long[] arr;
		public fenwick(Integer[] a) {
			arr=new long[a.length+1];
			for(int i=1;i<=a.length;i++) {
				arr[i]+=a[i-1];
				if(i+LSB(i)<=a.length) {
					arr[(int) (i+LSB(i))]+=arr[i];
				}
			}
		}
		public fenwick(int[] a) {
			arr=new long[a.length+1];
			for(int i=1;i<=a.length;i++) {
				arr[i]+=a[i-1];
				if(i+LSB(i)<=a.length) {
					arr[(int) (i+LSB(i))]+=arr[i];
				}
			}
		}public fenwick(long[] a) {
			arr=new long[a.length+1];
			for(int i=1;i<=a.length;i++) {
				arr[i]+=a[i];
				if(i+LSB(i)<=a.length) {
					arr[(int) (i+LSB(i))]+=arr[i];
				}
			}
		}
		public void update(int ind,long x) {
			int i=ind;
			while(i<arr.length) {
				arr[i]+=x;
				i+=LSB(i);
			}
		}
		public long PrefixSum(int ind) {
			long sum=0;
			int i=ind;
			while(i>0) {
				sum+=arr[i];
				i=(int) (i-LSB(i));
			}
			return sum;
		}
		public long id7(int l,int r) {
			return  this.PrefixSum(r+1)-this.PrefixSum(l);
		}
		public long id8(int k) {
			long max=Long.MIN_VALUE;
			for(int i=k-1;i<arr.length-1;i++) {
				
				max= Math.max(max,  this.id7(i-k+1, i));
				
			}
			return max;
		}
		public long id11(int k) {
			long min=Long.MAX_VALUE;
			
			for(int i=k-1;i<arr.length-1;i++) {
				
				min= Math.min(min,  this.id7(i-k+1, i));
				
			}
			return min;
		}
		public long value(int ind) {
			return arr[ind];
		}
	}
	static void id4(int N)
	{
		ArrayList<Integer> primes = new ArrayList<Integer>();
		lp = new int[N + 1];								

		for(int i = 2; i <= N; ++i)
		{
			if(lp[i] == 0)
			{
				primes.add(i);
				lp[i] = i;
			}
			int curLP = lp[i];
			for(int p: primes)

				if(p > curLP || p * 1l * i > N)
					break;
				else
					lp[p * i] = p;
		}
	}
	public static void id10(int n) {
		int x=n;
	while(x>1) {
		int id3=lp[x];
		while(x%id3==0) {
			id9.add(id3);
			x/=id3;
		}
	}
	}
	static LinkedList<Integer>id9=new LinkedList<>();
	static TreeMap<Integer,Integer>primes=new TreeMap<Integer, Integer>();
	static TreeMap<Integer,Integer>id1=new TreeMap<Integer, Integer>();
	static int[]lp;
 
	static int[][] id5;
	static int id12 = 0;
	static int[] prepow;
	static int prelen = 0;
	static int prime = 61;
	static long fac[];
	static int mod = 1000000007;
	static Random rn = new Random();
	static Scanner sc = new Scanner(System.in);
	static PrintWriter pw = new PrintWriter(System.out);
}