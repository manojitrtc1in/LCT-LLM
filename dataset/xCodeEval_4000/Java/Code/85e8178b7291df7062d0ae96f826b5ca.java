import java.util.*;
import java.io.*;





public class Codeforces {
    static FastReader sc=new FastReader();
	static PrintWriter out=new PrintWriter(System.out);
	static long mod=1000000007;
	

	static int MAX=Integer.MAX_VALUE;
	static int MIN=Integer.MIN_VALUE;
	static long MAXL=Long.MAX_VALUE;
	static long MINL=Long.MIN_VALUE;
	static ArrayList<Integer> graph[];
	static long sz=(long)Math.pow(10,16);
	public static void main (String[] args) throws java.lang.Exception
	{
		

		int t=I();
		while(t-->0)
		{
			int n=I();
			if(n%2==1)out.println("Bob");
			else{
				int cnt=0;
				while(n%2==0){
					cnt++;
					n=n/2;
				}
				if(n==1){
					if(cnt%2==0)out.println("Alice");
					else out.println("Bob");
				}else{
					out.println("Alice");
				}
			}	
		}
		out.close();
	}
	public static class pair
    {
    	long a;
    	long b;
    	public pair(long val,long index)
    	{
    	    a=val;
    	    b=index;
    	}
    }
	public static class myComp implements Comparator<pair>
	{
		

		public int compare(pair p1,pair p2)
		{
			if(p1.b==p2.b)
    	    return 0;
    	    else if(p1.b<p2.b)
    	    return -1;
    	    else
    	    return 1;
		}
		

		

    	

    	

    	

    	

    	

    	

    	

    	

	}
	public static long kadane(long a[],int n)
	{
		long max_sum=Long.MIN_VALUE,max_end=0;
		for(int i=0;i<n;i++){
			max_end+=a[i];
			if(max_sum<max_end){max_sum=max_end;}
			if(max_end<0){max_end=0;}
		}
		return max_sum;
	}
	public static void DFS(int s,boolean visited[])
	{
		visited[s]=true;
		for(int i:graph[s]){
			if(!visited[i]){
				DFS(i,visited);
			}
		}
	}
	public static void setGraph(int n,int m)
	{
		graph=new ArrayList[n+1];
		for(int i=0;i<=n;i++){
			graph[i]=new ArrayList<>();
		}
		for(int i=0;i<m;i++){
			int u=I(),v=I();
			graph[u].add(v);
			graph[v].add(u);
		}
	}
	public static int BS(long a[],long x,int ii,int jj)
	{
		

		int mid=0;
		int i=ii,j=jj;
		while(i<=j)
		{
			mid=(i+j)/2;
			if(a[mid]<x){
				i=mid+1;
			}else if(a[mid]>x){
				j=mid-1;
			}else{
				return mid;
			}
		}
		return -1;
	}
	public static int lower_bound(int arr[],int s, int N, int X)
	{
		if(arr[N]<X)return N;
		if(arr[0]>X)return -1;
		int left=s,right=N;
		while(left<right){
			int mid=(left+right)/2;
			if(arr[mid]==X)
			return mid;
			else if(arr[mid]>X){
				if(mid>0 && arr[mid]>X && arr[mid-1]<=X){
					return mid-1;
				}else{
					right=mid-1;
				}
			}else{
				if(mid<N && arr[mid+1]>X && arr[mid]<=X){
					return mid;
				}else{
					left=mid+1;
				}
			}
		}
		return left;
	}
	public static ArrayList<Integer> primeSieve(int n)
	{
	    ArrayList<Integer> arr=new ArrayList<>();
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
        for (int i = 2; i <= n; i++)
        {
            if (prime[i] == true)
            arr.add(i);
        }
        return arr;
	}

	

	public static class FenwickTree
	{
		int farr[];
		int n;
		public FenwickTree(int c)
		{
			n=c+1;
			farr=new int[n];
		}
		

		

		

		

		

		public void update(int x,int p)
		{
			for(;x<=n;x+=x&(-x))
			{
				farr[x]+=p;
			}
		}
		public long get(int x)
		{
			long ans=0;
			for(;x>0;x-=x&(-x))
			{
				ans=ans+farr[x];
			}
			return ans;
		}
	}

	

	public static class DSU
	{
	    int par[],rank[];
	    public DSU(int c)
	    {
	        par=new int[c+1];
	        rank=new int[c+1];
	        for(int i=0;i<=c;i++)
	        {
	            par[i]=i;
	            rank[i]=0;
	        }
	    }
	    public int find(int a)
	    {
	        if(a==par[a])
	        return a;
	        return par[a]=find(par[a]);
	    }
	    public void union(int a,int b)
	    {
	        int a_rep=find(a),b_rep=find(b);
	        if(a_rep==b_rep)
	        return;
	        if(rank[a_rep]<rank[b_rep])
	        par[a_rep]=b_rep;
	        else if(rank[a_rep]>rank[b_rep])
	        par[b_rep]=a_rep;
	        else
	        {
	            par[b_rep]=a_rep;
	            rank[a_rep]++;
	        }
	    }
	}

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	
    public static class myComp1 implements Comparator<pair1>
    {
		

    	public int compare(pair1 p1,pair1 p2)
    	{
    	    if(p1.a==p2.a)
    	    return 0;
    	    else if(p1.a<p2.a)
    	    return -1;
    	    else
    	    return 1;
    	}
		

		

    	

    	

    	

    	

    	

    	

    	

    	

    }
	public static class pair1
    {
    	long a;
    	long b;
    	public pair1(long val,long index)
    	{
    	    a=val;
    	    b=index;
    	}
    }
    public static ArrayList<pair1> mergeIntervals(ArrayList<pair1> arr)
	{
	    

	    ArrayList<pair1> a1=new ArrayList<>();
	    if(arr.size()<=1)
	    return arr;
	    a1.add(arr.get(0));
	    int i=1,j=0;
	    while(i<arr.size())
	    {
	        if(a1.get(j).b<arr.get(i).a)
	        {
	           a1.add(arr.get(i));
	           i++;
	           j++;
	        }
	        else if(a1.get(j).b>arr.get(i).a && a1.get(j).b>=arr.get(i).b)
	        {
	            i++;
	        }
	        else if(a1.get(j).b>=arr.get(i).a)
	        {
	            long a=a1.get(j).a;
	            long b=arr.get(i).b;
	            a1.remove(j);
	            a1.add(new pair1(a,b));
	            i++;
	        }
	    }
	    return a1;
	}
	public static boolean isPalindrome(String s,int n)
	{
		for(int i=0;i<=n/2;i++){
			if(s.charAt(i)!=s.charAt(n-i-1)){
				return false;
			}
		}
		return true;
	}
	public static int gcd(int a,int b)
	{
	    if(b==0)
	    return a;
	    else
	    return gcd(b,a%b);
	}
	public static long gcd(long a,long b)
	{
	    if(b==0)
	    return a;
	    else
	    return gcd(b,a%b);
	}
	public static long fact(long n)
	{
		long fact=1;
		for(long i=2;i<=n;i++){
			fact=((fact%mod)*(i%mod))%mod;
		}
		return fact;
	}
	public static long fact(int n)
	{
		long fact=1;
		for(int i=2;i<=n;i++){
			fact=((fact%mod)*(i%mod))%mod;
		}
		return fact;
	} 
	public static boolean isPrime(int n) 
	{ 
	    if (n <= 1) 
	        return false; 
	    if (n <= 3) 
	        return true; 
	    if (n % 2 == 0 || n % 3 == 0) 
	        return false; 
	    double sq=Math.sqrt(n);
	  
	    for (int i = 5; i <= sq; i = i + 6) 
	        if (n % i == 0 || n % (i + 2) == 0) 
	            return false; 
	    return true; 
	} 
    public static boolean isPrime(long n) 
	{ 
	    if (n <= 1) 
	        return false; 
	    if (n <= 3) 
	        return true; 
	    if (n % 2 == 0 || n % 3 == 0) 
	        return false; 
	    double sq=Math.sqrt(n);
	
	    for (int i = 5; i <= sq; i = i + 6) 
	        if (n % i == 0 || n % (i + 2) == 0) 
	            return false; 
	    return true; 
	}
	public static void printArray(long a[])
	{
		for(int i=0;i<a.length;i++){
			out.print(a[i]+" ");
		}
		out.println();
	}
	public static void printArray(int a[])
	{
		for(int i=0;i<a.length;i++){
			out.print(a[i]+" ");
		}
		out.println();
	}
	public static void printArray(pair a[])
	{
		for(int i=0;i<a.length;i++){
			out.print(a[i].a+"->"+a[i].b+" ");
		}
		out.println();
	}
	public static void printArray(char a[])
	{
		for(int i=0;i<a.length;i++){
			out.print(a[i]);
		}
		out.println();
	}
	public static void printArray(String a[])
	{
		for(int i=0;i<a.length;i++){
			out.print(a[i]+" ");
		}
		out.println();
	}
	public static void printArray(boolean a[])
	{
		for(int i=0;i<a.length;i++){
			out.print(a[i]+" ");
		}
		out.println();
	}
	public static void printArray(int a[][])
	{
		for(int i=0;i<a.length;i++){
			for(int j=0;j<a[i].length;j++){
				out.print(a[i][j]+" ");
			}out.println();
		}
	}
	public static void printArray(long a[][])
	{
		for(int i=0;i<a.length;i++){
			for(int j=0;j<a[i].length;j++){
				out.print(a[i][j]+" ");
			}out.println();
		}
	}
	public static void printArray(char a[][])
	{
		for(int i=0;i<a.length;i++){
			for(int j=0;j<a[i].length;j++){
				out.print(a[i][j]+" ");
			}out.println();
		}
	}
	public static void printArrayL(ArrayList<Long> arr)
	{
		for(int i=0;i<arr.size();i++){
			out.print(arr.get(i)+" ");
		}
		out.println();
	}
	public static void printArrayI(ArrayList<Integer> arr)
	{
		for(int i=0;i<arr.size();i++){
			out.print(arr.get(i)+" ");
		}
		out.println();
	}
	public static void printArrayS(ArrayList<String> arr)
	{
		for(int i=0;i<arr.size();i++){
			out.print(arr.get(i)+" ");
		}
		out.println();
	}
	public static void printMapInt(HashMap<Integer,Integer> hm){
		for(Map.Entry<Integer,Integer> e:hm.entrySet()){
			out.println(e.getKey()+"->"+e.getValue());
		}out.println();
	}
	public static void printMapLong(HashMap<Long,Long> hm){
		for(Map.Entry<Long,Long> e:hm.entrySet()){
			out.println(e.getKey()+"->"+e.getValue());
		}out.println();
	}

	


	public static long add(long a,long b)
	{
		a+=b;
		if(a>=mod)a-=mod;
		return a;
	}
	public static long sub(long a,long b)
	{
		a-=b;
		if(a<0)a+=mod;
		return a;
	}
	public static long mul(long a,long b)
	{
		return ((a%mod)*(b%mod))%mod;
	}
	public static long divide(long a,long b,long m)
	{
		a=mul(a,modInverse(b,m));
		return a;
	}
	public static long modInverse(long a,long m)
	{
		int x=0,y=0;
		own p=new own(x,y);
		long g=gcdExt(a,m,p);
		if(g!=1){
			out.println("inverse does not exists");
			return -1;
		}else{
			long res=((p.a%m)+m)%m;
			return res;
		}
	}
	public static long gcdExt(long a,long b,own p)
	{
		if(b==0){
			p.a=1;
			p.b=0;
			return a;
		}
		int x1=0,y1=0;
		own p1=new own(x1,y1);
		long gcd=gcdExt(b,a%b,p1);
		p.b=p1.a - (a/b) * p1.b;
		p.a=p1.b;
		return gcd;
	}
	public static long pwr(long m,long n)
	{
		long res=1;
		m=m%mod;
		if(m==0)
		return 0;
		while(n>0)
		{
			if((n&1)!=0)
			{
				res=(res*m)%mod;
			}
			n=n>>1;
			m=(m*m)%mod;
		}
		return res;
	}
	public static class own
    {
    	long a;
    	long b;
    	public own(long val,long index)
    	{
    	    a=val;
    	    b=index;
    	}
    }

	


	public static void sort(int[] A)
	{
        int n = A.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i)
		{
            int tmp = A[i];
            int randomPos = i + rnd.nextInt(n-i);
            A[i] = A[randomPos];
            A[randomPos] = tmp;
        }
        Arrays.sort(A);
    }
    public static void sort(long[] A)
	{
	    int n = A.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i)
		{
            long tmp = A[i];
            int randomPos = i + rnd.nextInt(n-i);
            A[i] = A[randomPos];
            A[randomPos] = tmp;
        }
	    Arrays.sort(A);
	}
	public static int I(){return sc.I();}
    public static long L(){return sc.L();}
    public static String S(){return sc.S();}
    public static double D(){return sc.D();}
}
class FastReader {  
    BufferedReader br;
    StringTokenizer st;
    public FastReader(){
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    String next(){
        while (st == null || !st.hasMoreElements()){
            try {
                st = new StringTokenizer(br.readLine());
            }
            catch (IOException e){
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
    int I(){ 
        return Integer.parseInt(next());
    }
    long L(){ 
        return Long.parseLong(next());
    }
    double D(){
         return Double.parseDouble(next());
    }
    String S(){
        String str = "";
        try 
        {
            str = br.readLine();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        return str;
    }
}
