import java.io.*;
import java.util.*;



import java.math.*;
import java.math.BigInteger;


public final class B
{    
	static PrintWriter out = new PrintWriter(System.out); 
	static StringBuilder ans=new StringBuilder();
	static FastReader in=new FastReader();
	static ArrayList<Integer> g[];
	static long mod=(long) 998244353,INF=Long.MAX_VALUE;
	static boolean set[];
	static int par[],col[],D[];
	static long A[];
	static int inv_count=0;
	public static void main(String args[])throws IOException
	{	
		
		int T=i();
		outer:while(T-->0)
		{
			int N=i();			
			int A[]=input(N);
			HashSet<Integer> set=new HashSet<>();
			boolean duplicate=false;
			if(N==1)
			{
				ans.append("YES\n");
				continue outer;
			}
			if(N==2)
			{
				if(A[0]<=A[1])
					ans.append("YES\n");
				else ans.append("NO\n");
				continue outer;
			}
			if(N==3) 
			{
				

				int a=A[0],b=A[1],c=A[2];
				if(a<=b && b<=c)ans.append("YES\n");
				else if(c<=a && a<=b)ans.append("YES\n");
				else if(b<=c && c<=a)ans.append("YES\n");
				else ans.append("NO\n");
				continue outer;
			}
			int B[]=new int[N];
			HashMap<Integer,Integer> mp=new HashMap<>();
			for(int i=0; i<N; i++) 
			{
				if(set.contains(A[i]))duplicate=true;
				set.add(A[i]);
				B[i]=A[i];
			}
			if(duplicate)
			{
				ans.append("YES\n");
				continue;
			}
			

			

			inv_count=0;
			merge_Sort(0,N-1,A);
			



			if(inv_count%2==0)ans.append("YES\n");
			else ans.append("NO\n");		
		}
		out.println(ans);
		out.close();
	}	
	static void merge_Sort(int l,int r,int A[])
	{
		if(r-l>=1)
		{
			int m=(l+r)/2;
			merge_Sort(l,m,A);
			merge_Sort(m+1,r,A);
		    merge(l,m,r,A);
		}
		
	}
	static void merge(int l,int m,int r,int A[])
	{
		int a[]=new int[m-l+1];for(int x=l; x<=m; x++)a[x-l]=A[x];
		int b[]=new int[r-m];for(int x=m+1; x<=r; x++)b[x-(m+1)]=A[x];
		

		

		int n1=a.length,n2=b.length;
		int X[]=new int[r-l+1];
		int i=0,j=0,it=0;
		int sz=n1;
		while(i<n1 && j<n2)
		{
			if(a[i]>b[j])
			{
				X[it++]=b[j++];
				inv_count+=sz;
			}
			else
			{
				sz--;
				X[it++]=a[i++];
			}
		}
		

		while(i<n1)X[it++]=a[i++];
		while(j<n2)X[it++]=b[j++];
	

		for(it=l; it<=r; it++)
		{
			A[it]=X[it-l];
		}
	}
	static boolean f(int a,int b,int c)
	{
		if(a<=b && b<=c)return true;
		else if(c<=a && a<=b)return true;
		else if(b<=c && c<=a)return true;
		else return false;
	}
	static int f(int l,int r,long A[],long x)
	{
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A[m]>=x)l=m;
			else r=m;
		}
		return r;

	}
	static boolean f(long m,long H,long A[],int N)
	{
		long s=m;
		for(int i=0; i<N-1;i++)
		{
			s+=Math.min(m, A[i+1]-A[i]);
		}
		return s>=H;
	}
	static boolean f(int i,int j,long last,boolean win[])
	{
		if(i>j)return false;
		if(A[i]<=last && A[j]<=last)return false;
		long a=A[i],b=A[j];
		

		if(a==b)
		{
			return win[i] | win[j];
		}
		else if(a>b)
		{
			boolean f=false;
			if(b>last)f=!f(i,j-1,b,win);
			return win[i] | f;
		}
		else
		{
			boolean f=false;
			if(a>last)f=!f(i+1,j,a,win);
			return win[j] | f;
		}
	}
	static long ask(long l,long r)
	{
		System.out.println("? "+l+" "+r);
		return l();
	}
	static long f(long N,long M)
	{
		long s=0;
		if(N%3==0)
		{
			N/=3;
			s=N*M;
		}
		else
		{
			long b=N%3;
			N/=3;
			N++;
			s=N*M;
			N--;
			long a=N*M;
			if(M%3==0)
			{
				M/=3;
				a+=(b*M);
			}
			else
			{
				M/=3;
				M++;
				a+=(b*M);
			}
			s=Math.min(s, a);
		}
		return s;
	}
	static int ask(StringBuilder sb,int a)
	{
		System.out.println(sb+""+a);
		return i();
	}
	static void swap(char X[],int i,int j)
	{
		char x=X[i];
		X[i]=X[j];
		X[j]=x;
	}
	static int min(int a,int b,int c)
	{
		return Math.min(Math.min(a, b), c);
	}


	static long and(int i,int j)
	{
		System.out.println("and "+i+" "+j);
		return l();
	}
	static long or(int i,int j)
	{
		System.out.println("or "+i+" "+j);
		return l();
	}
	static int len=0,number=0;
	static void f(char X[],int i,int num,int l)
	{
		if(i==X.length)
		{
			if(num==0)return;
			

			if(isPrime(num))return;
			if(l<len)
			{
				len=l;
				number=num;				
			}
			return;
		}
		int a=X[i]-'0';
		f(X,i+1,num*10+a,l+1);
		f(X,i+1,num,l);
	}
	static boolean is_Sorted(int A[])
	{
		int N=A.length;
		for(int i=1; i<=N; i++)if(A[i-1]!=i)return false;
		return true;
	}
	static boolean f(StringBuilder sb,String Y,String order)
	{
		StringBuilder res=new StringBuilder(sb.toString());
		HashSet<Character> set=new HashSet<>();
		for(char ch:order.toCharArray())
		{
			set.add(ch);
			for(int i=0; i<sb.length(); i++)
			{
				char x=sb.charAt(i);
				if(set.contains(x))continue;
				res.append(x);
			}
		}

		String str=res.toString();
		return str.equals(Y);
	}
	static boolean all_Zero(int f[])
	{
		for(int a:f)if(a!=0)return false;
		return true;
	}
	static long form(int a,int l)
	{
		long x=0;
		while(l-->0)
		{
			x*=10;
			x+=a;
		}
		return x;
	}
	static int count(String X)
	{
		HashSet<Integer> set=new HashSet<>();
		for(char x:X.toCharArray())set.add(x-'0');
		return set.size();
	}

	static int f(long K)
	{
		long l=0,r=K;
		while(r-l>1)
		{
			long m=(l+r)/2;
			if(m*m<K)l=m;
			else r=m;
		}
		return (int)l;
	}
	

	

	

	

	

	

	

	

	

	

	

	

	

	


	static int [] sub(int A[],int B[])
	{
		int N=A.length;
		int f[]=new int[N];
		for(int i=N-1; i>=0; i--)
		{
			if(B[i]<A[i])
			{
				B[i]+=26;
				B[i-1]-=1;
			}
			f[i]=B[i]-A[i];
		}
		for(int i=0; i<N; i++)
		{
			if(f[i]%2!=0)f[i+1]+=26;
			f[i]/=2;
		}
		return f;
	}
	static int[] f(int  N)
	{
		char X[]=in.next().toCharArray();
		int A[]=new int[N];
		for(int i=0; i<N; i++)A[i]=X[i]-'a';
		return A;
	}




	static int max(int a ,int b,int c,int d)
	{
		a=Math.max(a, b);
		c=Math.max(c,d);
		return Math.max(a, c);
	}
	static int min(int a ,int b,int c,int d)
	{
		a=Math.min(a, b);
		c=Math.min(c,d);
		return Math.min(a, c);
	}



	static HashMap<Integer,Integer> Hash(int A[])
	{
		HashMap<Integer,Integer> mp=new HashMap<>();
		for(int a:A)
		{
			int f=mp.getOrDefault(a,0)+1;
			mp.put(a, f);
		}
		return mp;
	}
	static long mul(long a, long b)
	{
		return ( a %mod * 1L * b%mod )%mod;
	}
	static void swap(int A[],int a,int b)
	{
		int t=A[a];
		A[a]=A[b];
		A[b]=t;
	}


	static int find(int a)
	{
		if(par[a]<0)return a;
		return par[a]=find(par[a]);
	}
	static void union(int a,int b)
	{
		a=find(a);
		b=find(b);
		if(a!=b)
		{
			par[a]+=par[b];
			par[b]=a;
		}
	}
	static boolean isSorted(int A[])
	{
		for(int i=1; i<A.length; i++)
		{
			if(A[i]<A[i-1])return false;
		}
		return true;
	}

	static boolean isDivisible(StringBuilder X,int i,long num)
	{
		long r=0;
		for(; i<X.length(); i++)
		{
			r=r*10+(X.charAt(i)-'0');
			r=r%num;
		}
		return r==0;
	}    



	static int lower_Bound(int A[],int low,int high, int x) 
	{ 
		if (low > high) 
			if (x >= A[high]) 
				return A[high]; 

		int mid = (low + high) / 2; 

		if (A[mid] == x) 
			return A[mid]; 

		if (mid > 0 && A[mid - 1] <= x && x < A[mid]) 
			return A[mid - 1]; 

		if (x < A[mid]) 
			return lower_Bound( A, low, mid - 1, x); 

		return lower_Bound(A, mid + 1, high, x); 
	} 

	static String f(String A)
	{
		String X="";
		for(int i=A.length()-1; i>=0; i--)
		{
			int c=A.charAt(i)-'0';
			X+=(c+1)%2;
		}
		return X;
	}

	static void sort(long[] a) 

	{
		ArrayList<Long> l=new ArrayList<>();
		for (long i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

	static String swap(String X,int i,int j)
	{
		char ch[]=X.toCharArray();
		char a=ch[i];
		ch[i]=ch[j];
		ch[j]=a;
		return new String(ch);
	}

	static int sD(long n)  
	{  

		if (n % 2 == 0 )  
			return 2;  

		for (int i = 3; i * i <= n; i += 2) {  
			if (n % i == 0 )  
				return i;  
		}  

		return (int)n;  
	}  

	static void setGraph(int N)
	{
		par=new int[N+1];
		D=new int[N+1];
		g=new ArrayList[N+1];
		set=new boolean[N+1];
		col=new int[N+1];
		for(int i=0; i<=N; i++)
		{
			col[i]=-1;
			g[i]=new ArrayList<>();		
			D[i]=Integer.MAX_VALUE;
		}
	}



	static  long pow(long a,long b)
	{
		

		long pow=1;
		long x=a;
		while(b!=0)
		{
			if((b&1)!=0)pow=(pow*x)%mod;
			x=(x*x)%mod;
			b/=2;
		}
		return pow;
	}

	static long toggleBits(long x)

	{
		int n=(int)(Math.floor(Math.log(x)/Math.log(2)))+1;

		return ((1<<n)-1)^x;
	}

	static int countBits(long a)
	{
		return (int)(Math.log(a)/Math.log(2)+1);
	}

	static long fact(long N)
	{ 
		long n=2; 
		if(N<=1)return 1;
		else
		{
			for(int i=3; i<=N; i++)n=(n*i)%mod;
		}
		return n;
	}

	static int kadane(int A[])
	{
		int lsum=A[0],gsum=A[0];
		for(int i=1; i<A.length; i++)
		{
			lsum=Math.max(lsum+A[i],A[i]);
			gsum=Math.max(gsum,lsum);
		}
		return gsum;
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

	static boolean isPrime(long N)
	{
		if (N<=1)  return false; 
		if (N<=3)  return true; 
		if (N%2 == 0 || N%3 == 0) return false; 
		for (int i=5; i*i<=N; i=i+6) 
			if (N%i == 0 || N%(i+2) == 0) 
				return false; 
		return true; 
	}
	static void print(char A[])
	{
		for(char c:A)System.out.print(c+" ");
		System.out.println();
	}
	static void print(boolean A[])
	{
		for(boolean c:A)System.out.print(c+" ");
		System.out.println();
	}
	static void print(int A[])
	{
		for(int a:A)System.out.print(a+" ");
		System.out.println();	
	}
	static void print(long A[])
	{
		for(long i:A)System.out.print(i+ " ");
		System.out.println();

	}
	static void print(boolean A[][])
	{
		for(boolean a[]:A)print(a);
	}
	static void print(long A[][])
	{
		for(long a[]:A)print(a);
	}
	static void print(int A[][])
	{
		for(int a[]:A)print(a);
	}
	static void print(ArrayList<Integer> A)
	{
		for(int a:A)System.out.print(a+" ");
		System.out.println();
	}

	static int i()
	{
		return in.nextInt();
	}

	static long l()
	{
		return in.nextLong();
	}

	static int[] input(int N){
		int A[]=new int[N];
		for(int i=0; i<N; i++)
		{
			A[i]=in.nextInt();
		}
		return A;
	}

	static long[] inputLong(int N)     {
		long A[]=new long[N];
		for(int i=0; i<A.length; i++)A[i]=in.nextLong();
		return A;
	}

	static long GCD(long a,long b) 
	{
		if(b==0)
		{
			return a;
		}
		else return GCD(b,a%b );
	}

}
class player implements Comparable<player>
{
	int index;
	long a,b;
	player(long a,long b,int i)
	{
		this.a=a;
		this.b=b;
		index=i;
	}
	public int compareTo(player x)
	{
		long a=this.a,b=x.a;
		if(a>b)return 1;
		else if(b>a)return -1;
		return 0;
	}
}










class FastReader
{
	BufferedReader br;
	StringTokenizer st;
	public FastReader()
	{
		br=new BufferedReader(new InputStreamReader(System.in));
	}

	String next()
	{
		while(st==null || !st.hasMoreElements())
		{
			try
			{
				st=new StringTokenizer(br.readLine());
			}
			catch(IOException e)
			{
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int nextInt()
	{
		return Integer.parseInt(next());
	}

	long nextLong()
	{
		return Long.parseLong(next());
	}

	double nextDouble()
	{
		return Double.parseDouble(next());
	}

	String nextLine()
	{
		String str="";
		try
		{
			str=br.readLine();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		return str;
	}

}