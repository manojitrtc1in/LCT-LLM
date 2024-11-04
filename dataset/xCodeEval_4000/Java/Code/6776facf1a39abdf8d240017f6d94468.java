import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.reflect.Constructor;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;


public class CodeE 
{
	static class Scanner
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");
		
		public String nextLine()
		{
			try
			{
				return br.readLine();
			}
			catch(Exception e)
			{
				throw(new RuntimeException());
			}
		}
		
		public String next()
		{
			while(!st.hasMoreTokens())
			{
				String l = nextLine();
				if(l == null)
					return null;
				st = new StringTokenizer(l);
			}
			return st.nextToken();
		}
		
		public int nextInt()
		{
			return Integer.parseInt(next());
		}
		
		public long nextLong()
		{
			return Long.parseLong(next());
		}
		
		public double nextDouble()
		{
			return Double.parseDouble(next());
		}
		
		public int[] nextIntArray(int n)
		{
			int[] res = new int[n];
			for(int i = 0; i < res.length; i++)
				res[i] = nextInt();
			return res;
		}
		
		public long[] nextLongArray(int n)
		{
			long[] res = new long[n];
			for(int i = 0; i < res.length; i++)
				res[i] = nextLong();
			return res;
		}
		
		public double[] nextDoubleArray(int n)
		{
			double[] res = new double[n];
			for(int i = 0; i < res.length; i++)
				res[i] = nextDouble();
			return res;
		}
		public void sortIntArray(int[] array)
		{
			Integer[] vals = new Integer[array.length];
			for(int i = 0; i < array.length; i++)
				vals[i] = array[i];
			Arrays.sort(vals);
			for(int i = 0; i < array.length; i++)
				array[i] = vals[i];
		}
		
		public void sortLongArray(long[] array)
		{
			Long[] vals = new Long[array.length];
			for(int i = 0; i < array.length; i++)
				vals[i] = array[i];
			Arrays.sort(vals);
			for(int i = 0; i < array.length; i++)
				array[i] = vals[i];
		}
		
		public void sortDoubleArray(double[] array)
		{
			Double[] vals = new Double[array.length];
			for(int i = 0; i < array.length; i++)
				vals[i] = array[i];
			Arrays.sort(vals);
			for(int i = 0; i < array.length; i++)
				array[i] = vals[i];
		}

		public String[] nextStringArray(int n) 
		{	
			String[] vals = new String[n];
			for(int i = 0; i < n; i++)
				vals[i] = next();
			return vals;
		}
		
		Integer nextInteger()
		{
			String s = next();
			if(s == null)
				return null;
			return Integer.parseInt(s);
		}
		
		int[][] nextIntMatrix(int n, int m)
		{
			int[][] ans = new int[n][];
			for(int i = 0; i < n; i++)
				ans[i] = nextIntArray(m);
			return ans;
		}
		
		static <T> T fill(T arreglo, int val)
		{
			if(arreglo instanceof Object[])
			{
				Object[] a = (Object[]) arreglo;
				for(Object x : a)
					fill(x, val);
			}
			else if(arreglo instanceof int[])
				Arrays.fill((int[]) arreglo, val);
			else if(arreglo instanceof double[])
				Arrays.fill((double[]) arreglo, val);
			else if(arreglo instanceof long[])
				Arrays.fill((long[]) arreglo, val);
			return arreglo;
		}
		
		<T> T[] nextObjectArray(Class <T> clazz, int size)
		{
			@SuppressWarnings("unchecked")
			T[] result = (T[]) java.lang.reflect.Array.newInstance(clazz, size);
			for(int c = 0; c < 3; c++)
			{
				Constructor <T> constructor;
				try 
				{
					if(c == 0)
						constructor = clazz.getDeclaredConstructor(Scanner.class, Integer.TYPE);
					else if(c == 1)
						constructor = clazz.getDeclaredConstructor(Scanner.class);
					else
						constructor = clazz.getDeclaredConstructor();
				} 
				catch(Exception e)
				{
					continue;
				}
				try
				{
					for(int i = 0; i < result.length; i++)
					{
						if(c == 0)
							result[i] = constructor.newInstance(this, i);
						else if(c == 1)
							result[i] = constructor.newInstance(this);
						else
							result[i] = constructor.newInstance();	
					}
				}
				catch(Exception e)
				{
					throw new RuntimeException(e);
				}
				return result;
			}
			throw new RuntimeException("Constructor not found");
		}
	}
	
	static boolean leq(int a1, int a2,   int b1, int b2) 
	{
		return(a1 < b1 || a1 == b1 && a2 <= b2);
	}             

	static boolean leq(int a1, int a2, int a3,   int b1, int b2, int b3) 
	{
		return(a1 < b1 || a1 == b1 && leq(a2,a3, b2,b3));
	}

	static int[] c;

	static void radixPass(int[] a, int[] b, int[] r, int n, int K, int delta)
	{
		if(c == null || c.length != K + 1) c = new int[K + 1];
		for(int i = 0;  i <= K; i++) c[i] = 0;
		for(int i = 0;  i < n;  i++) c[r[a[i] + delta]]++;
		for(int i = 0, sum = 0;  i <= K;  i++) 
		{
			int t = c[i];
			c[i] = sum;
			sum += t;
		}
		for (int i = 0;  i < n;  i++) b[c[r[a[i] + delta]]++] = a[i];
	}

	

	

	static void suffixArray(int[] s, int[] SA, int n, int K) 
	{
		int n0=(n+2)/3, n1=(n+1)/3, n2=n/3, n02=n0+n2;
		int[] s12  = new int[n02 + 3];  s12[n02] = s12[n02+1] = s12[n02+2] = 0;
		int[] SA12 = new int[n02 + 3]; SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
		int[] s0   = new int[n0];
		int[] SA0  = new int[n0];
		for (int i=0, j=0; i < n + (n0 - n1); i++) if (i % 3 != 0) s12[j++] = i;
		radixPass(s12, SA12, s, n02, K, 2);
		radixPass(SA12, s12 , s, n02, K, 1);
		radixPass(s12, SA12, s, n02, K, 0);
		int name = 0, c0 = -1, c1 = -1, c2 = -1;
		for(int i = 0; i < n02; i++) 
		{
			if(s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) 
			{
				name++;
				c0 = s[SA12[i]];
				c1 = s[SA12[i] + 1];
				c2 = s[SA12[i] + 2];
			}
			if(SA12[i] % 3 == 1) s12[SA12[i] / 3] = name;
			else s12[SA12[i] / 3 + n0] = name;
		}
		if (name < n02) 
		{
			suffixArray(s12, SA12, n02, name);
			for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
		} 
		else for(int i = 0; i < n02; i++) SA12[s12[i] - 1] = i;
		for (int i = 0, j = 0; i < n02; i++) if (SA12[i] < n0) s0[j++] = 3 * SA12[i];
		radixPass(s0, SA0, s, n0, K, 0);
		for(int p = 0,  t = n0 - n1,  k = 0;  k < n;  k++) 
		{
			int i = (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2);
			int j = SA0[p];
			if (SA12[t] < n0 ? leq(s[i], s12[SA12[t] + n0], s[j], s12[j/3]) :
				leq(s[i],s[i+1],s12[SA12[t]-n0+1], s[j],s[j+1],s12[j/3+n0]))
			{
				SA[k] = i;
				t++;
				if (t == n02) for(k++; p < n0; p++, k++) SA[k] = SA0[p]; 
			} 
			else 
			{
				SA[k] = j;
				p++;
				if(p == n0) for(k++; t < n02; t++, k++) SA[k] = (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2); 
			}
		}
	}
	
	static class Pair
	{
		int a;
		int b;
		public Pair(int aa, int bb)
		{
			a = aa;
			b = bb;
		}
	}
	
	static class SuffixArray
	{
		int n;
		int[] g, b, sa, lcp, rmq, aux;
		char[] t;

		SuffixArray(String entrada)
		{
			int tamMax = entrada.length();
			g = new int[tamMax];
			b = new int[tamMax];
			sa = new int[tamMax];
			lcp = new int[tamMax];
			aux = new int[tamMax + 3];
			int logn = 1;
			int n = tamMax;
			for (int k = 1; k < n; k *= 2) ++logn;
			rmq = new int[n * logn];
			buildSA(entrada);
		}

		void buildSA(String sas)
		{
			n = sas.length();
			t = sas.toCharArray();
			for(int i = 0; i < n; i++)
				aux[i] = t[i];
			aux[n] = aux[n + 1] = aux[n + 2] = 0;
			suffixArray(aux, sa, n, 230);
			buildLCP();
			buildRMQ();
		}

		void buildLCP()
		{
			int[] a = sa;
			int h = 0;
			if(sa.length == 1)
			{
				lcp = new int[1];
				return;
			}
			for(int i = 0; i < n; i++) b[a[i]] = i;
			for(int i = 0; i < n; i++) 
			{
				if (b[i] != 0)
				{
					for(int j = a[b[i] - 1]; j + h < n && i + h < n && t[j + h] == t[i + h]; ++h);
					lcp[b[i]] = h;
				} 
				else lcp[b[i]] = -1;
				if(h > 0) --h;
			}
		}

		void buildRMQ() 
		{
			int[] b = rmq; 
			System.arraycopy(lcp, 0, b, 0, n);
			int delta = 0;
			for(int k = 1; k < n; k *= 2) 
			{
				System.arraycopy(b, delta, b, n + delta, n);
				delta += n;
				for(int i = 0; i < n - k; i++) b[i + delta] = Math.min(b[i + delta], b[i + k + delta]);
			}
		}
		
		

		int lcp(int x, int y)
		{
			return x == y ? n - sa[x] : x > y ? minimum(y + 1, x) : minimum(x + 1, y);
		}
		
		int lcpInverso(int x, int y)
		{
			return lcp(b[x], b[y]);
		}
		
		

		int minimum(int x, int y) 
		{
			int z = y - x, k = 0, e = 1, s;
			s = (((z & 0xffff0000) != 0) ? 1 : 0) << 4; z >>= s; e <<= s; k |= s;
			s = (((z & 0x0000ff00) != 0) ? 1 : 0) << 3; z >>= s; e <<= s; k |= s;
			s = (((z & 0x000000f0) != 0) ? 1 : 0) << 2; z >>= s; e <<= s; k |= s;
			s = (((z & 0x0000000c) != 0) ? 1 : 0) << 1; z >>= s; e <<= s; k |= s;
			s = (((z & 0x00000002) != 0) ? 1 : 0) << 0; z >>= s; e <<= s; k |= s;
			return Math.min(rmq[x + n * k], rmq[y + n * k - e + 1]);
		}
		
		

		int computeLCP(char[] t, int n, char[] p, int m, int o, int k) 
		{
			int i = o;
			for (; i < m && k + i < n && p[i] == t[k + i]; ++i);
			return i;
		}

		boolean COMP(int h, int k, int m, char[] p)
		{
			return (h == m || (k + h < n && p[h] < t[k + h]));
		}
		
		

		int find(String o) 
		{
			char[] p = o.toCharArray();
			int m = o.length();
			int l = -1, lh = 0, r = n - 1, rh = computeLCP(t, n, p, m, 0, sa[n - 1]);
			if(!COMP(rh, sa[r], m, p)) return -1;
			for(int k = (l + r) / 2; l + 1 < r; k = (l + r) / 2)
			{
				int A = minimum(l + 1, k), B = minimum(k + 1, r);
				if(A >= B) 
				{
					if(lh < A) l = k;
					else if(lh > A)
					{
						r = k;
						rh = A;
					}
					else
					{
						int i = computeLCP(t, n, p, m, A, sa[k]);
						if (COMP(i, sa[k], m, p)) 
						{
							r = k;
							rh = i;
						}
						else
						{
							l = k;
							lh = i;
						}
					}
				}
				else 
				{
					if (rh < B) r = k;
					else if (rh > B) 
					{
						l = k;
						lh = B;
					}
					else
					{
						int i = computeLCP(t, n, p, m, B, sa[k]);
						if(COMP(i, sa[k], m, p))
						{
							r = k;
							rh = i;
						}
						else 
						{
							l = k;
							lh = i;
						}
					}	
				}
			}
			return rh == m ? sa[r] : -1;
		}
	}
	
	static long[] hash;
	static long[] pows;
	static SuffixArray suffix;
	static int size;
	
	static long modSub(long a, long b)
	{
		return ((a - b) + mod) % mod;
	}
	
	static long modMul(long a, long b)
	{
		return (a * b) % mod;
	}
	
	static int hash(int from)
	{
		return (int) modSub(hash[from], (from + size) >= hash.length ? 0L : modMul(hash[from + size], pows[size]));  
	}
	
	static class Entrada
	{
		int from;
		
		
		public Entrada(int f) 
		{
			from = f;
		}

		@Override
		public int hashCode()
		{
			return hash(from);
		}
		
		@Override
		public boolean equals(Object obj)
		{
			Entrada otra = (Entrada) obj;
			return suffix.lcpInverso(from, otra.from) >= size;
		}
	}

	
	static final int base = 31;
	static final int mod = 1000000007;
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner();
		String a = sc.next();
		String b = sc.next();
		String c = sc.next();
		String[] subStrings = new String[a.length()];
		for(int i = 0; i < subStrings.length; i++)
			subStrings[i] = a.substring(i);
		boolean[] starts = new boolean[a.length()];
		boolean[] ends = new boolean[a.length()];
		for(int i = 0; i < starts.length; i++)
			starts[i] = subStrings[i].startsWith(b);
		for(int i = 0; i < starts.length; i++)
		{
			if(subStrings[i].startsWith(c))
				ends[i + c.length() - 1] = true;
		}
		hash = new long[a.length()];
		char[] vals = a.toCharArray();
		for(int i = a.length() - 1; i >= 0; i--)
			hash[i] = ((((i + 1) == a.length()) ? 0L : hash[i + 1]) * base + vals[i]) % mod;
		pows = new long[a.length() + 1];
		pows[0] = 1;
		for(int i = 1; i < pows.length; i++)
			pows[i] = (pows[i - 1] * base) % mod;
		suffix = new SuffixArray(a);
		int total = 0;
		for(int i = Math.max(b.length(), c.length()); i <= a.length(); i++)
		{
			size = i;
			HashSet <Entrada> entradas = new HashSet <Entrada> ();
			for(int j = 0; j + i - 1 < a.length(); j++)
			{
				if(starts[j] && ends[j + i - 1])
					entradas.add(new Entrada(j));
			}
			total += entradas.size();
		}
		System.out.println(total);
	}
}