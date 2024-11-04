import java.util.*;
import java.io.*;
import java.math.*;

public class Codechef {
    static id4 sc=new id4();
	static PrintWriter out=new PrintWriter(System.out);
	static long mod=1000000007;
	

	static int MAX=Integer.MAX_VALUE;
	static int MIN=Integer.MIN_VALUE;
	static long MAXL=Long.MAX_VALUE;
	static long MINL=Long.MIN_VALUE;
	static ArrayList<pair> graph[];
	static StringBuffer sb;
	static long fact[];
	static int a,b,max;
	static int dp[];
	public static void main (String[] args) throws java.lang.Exception
	{
		

		int t=I();
		outer:while(t-->0)
		{
			int n=I(),m=I();
			setGraph(n,m);
			boolean v[]=new boolean[n+1];
			dp=new int[n+1];
			long ans=0;
			max=0;
			for(int i=1;i<=n;i++){
				if(!v[i]){
					a=0;
					b=0;
					DFS(i,v,0);
					ans+=Math.max(a,b);
				}
			}
			if(max==-1)out.println("-1");
			else out.println(ans);
		}
		out.close();
	}
	public static void DFS(int s,boolean visited[],int d)
	{
		visited[s]=true;
		dp[s]=d;
		if(d==0)a++;
		else b++;
		for(pair i:graph[s]){
			if(!visited[i.a]){
				DFS(i.a,visited,d^i.b);
			}else{
				if((d^i.b)!=dp[i.a]){
					max=-1;
					return;
				}
			}
		}
	}
	public static class pair
    {
    	int a;
    	int b;
    	public pair(int val,int index)
    	{
    	    a=val;
    	    b=index;
    	}
    }
	public static class myComp implements Comparator<pair>
	{
		

		

		

		

    	

    	

    	

    	

    	

		

		

		public int compare(pair p1,pair p2)
    	{
    	    if(p1.a==p2.a)
    	    return 0;
    	    else if(p1.a<p2.a)
    	    return 1;
    	    else
    	    return -1;
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
	public static void setGraph(int n,int m)
	{
		graph=new ArrayList[n+1];
		for(int i=0;i<=n;i++){
			graph[i]=new ArrayList<>();
		}
		for(int i=0;i<m;i++){
			String s[]=S().trim().split(" ");
			int u=Integer.parseInt(s[0]),v=Integer.parseInt(s[1]);
			char ch=s[2].charAt(0);
			

			

			int x=0;
			if(ch=='i'){
				x=1;
			}
			pair p1=new pair(u,x);
			pair p2=new pair(v,x);
			graph[u].add(p2);
			graph[v].add(p1);
		}
	}
	public static int BS(int a[],int x,int ii,int jj)
	{
		

		int mid=0;
		int i=ii,j=jj,in=0;
		while(i<=j)
		{
			mid=(i+j)/2;
			if(a[mid]<x){
				in=mid+1;
				i=mid+1;
			}
			else
			j=mid-1;
		}
		return in;
	}

	


	public static int lower_bound(long arr[],int start, int end, long X)   

	{
		if(arr[end]<X)return end;
		if(arr[start]>X)return -1;
		int left=start,right=end;
		while(left<right){
			int mid=(left+right)/2;
			if(arr[mid]==X){                                      

				if(mid<end && arr[mid+1]==X){
					left=mid+1;
				}else{
					return mid;
				}
			}
			

			

			

			

			

			

			

			else if(arr[mid]>X){
				if(mid>start && arr[mid-1]<X){
					return mid-1;
				}else{
					right=mid-1;
				}
			}else{
				if(mid<end && arr[mid+1]>X){
					return mid;
				}else{
					left=mid+1;
				}
			}
		}
		return left;
	}
	public static int upper_bound(long arr[],int start,int end,long X)			

	{
		if(arr[0]>=X)return start;
		if(arr[arr.length-1]<X)return -1;
		int left=start,right=end;
		while(left<right){
			int mid=(left+right)/2;
			if(arr[mid]==X){                                   

				if(mid>start && arr[mid-1]==X){
					right=mid-1;
				}else{
					return mid;
				}
			}
			

			

			

			

			

			

			

			else if(arr[mid]>X){
				if(mid>start && arr[mid-1]<X){
					return mid;
				}else{
					right=mid-1;
				}
			}else{
				if(mid<end && arr[mid+1]>X){
					return mid+1;
				}else{
					left=mid+1;
				}
			}
		}
		return left;
	}

	


	public static boolean isSorted(int a[])
	{
		int n=a.length;
		for(int i=0;i<n-1;i++){
			if(a[i]>a[i+1])return false;
		}
		return true;
	}
	public static boolean isSorted(long a[])
	{
		int n=a.length;
		for(int i=0;i<n-1;i++){
			if(a[i]>a[i+1])return false;
		}
		return true;
	}
	public static ArrayList<Integer> id0(int n)
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

	

	public static class id8
	{
		long farr[];
		int n;
		public id8(int c)
		{
			n=c+1;
			farr=new long[n];
		}
		

		

		

		

		

		public void update(int x)
		{
			for(;x<=n;x+=x&(-x))
			{
				farr[x]++;
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
	    static int par[],rank[];
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
	    public static int find(int a)
	    {
	        if(a==par[a])
	        return a;
	        return par[a]=find(par[a]);
	    }
	    public static void union(int a,int b)
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
    public static class id6 implements Comparator<pair1>
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
	public static ArrayList<Long> primeFact(long a)
	{
	    ArrayList<Long> arr=new ArrayList<>();
	    while(a%2==0){
	        arr.add(2L);
	        a=a/2;
	    }
	    for(long i=3;i*i<=a;i+=2){
	        while(a%i==0){
	            arr.add(i);
	            a=a/i;
	        }
	    }
	    if(a>2)arr.add(a);
	    return arr;
	}
	public static boolean isInteger(double N)
	{
		int X = (int)N;
		double temp2 = N - X;
		if (temp2 > 0)
		{
			return false;
		}
		return true;
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
	public static void id3(ArrayList<Long> arr)
	{
		for(int i=0;i<arr.size();i++){
			out.print(arr.get(i)+" ");
		}
		out.println();
	}
	public static void id9(ArrayList<Integer> arr)
	{
		for(int i=0;i<arr.size();i++){
			out.print(arr.get(i)+" ");
		}
		out.println();
	}
	public static void id5(ArrayList<String> arr)
	{
		for(int i=0;i<arr.size();i++){
			out.print(arr.get(i)+" ");
		}
		out.println();
	}
	public static void id1(HashMap<Integer,Integer> hm){
		for(Map.Entry<Integer,Integer> e:hm.entrySet()){
			out.println(e.getKey()+"->"+e.getValue());
		}out.println();
	}
	public static void id2(HashMap<Long,Long> hm){
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
		long g=id10(a,m,p);
		if(g!=1){
			out.println("inverse does not exists");
			return -1;
		}else{
			long res=((p.a%m)+m)%m;
			return res;
		}
	}
	public static long id10(long a,long b,own p)
	{
		if(b==0){
			p.a=1;
			p.b=0;
			return a;
		}
		int x1=0,y1=0;
		own p1=new own(x1,y1);
		long gcd=id10(b,a%b,p1);
		p.b=p1.a - (a/b) * p1.b;
		p.a=p1.b;
		return gcd;
	}
	public static long pwr(long m,long n)
	{
		long res=1;
		if(m==0)
		return 0;
		while(n>0)
		{
			if((n&1)!=0)
			{
				res=(res*m);
			}
			n=n>>1;
			m=(m*m);
		}
		return res;
	}
	public static long id7(long m,long n)
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
	public static void sort(char[] A)
	{
        int n = A.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i)
		{
            char tmp = A[i];
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
	public static int i(char ch){return Integer.parseInt(String.valueOf(ch));}
	public static int I(){return sc.I();}
    public static long L(){return sc.L();}
    public static String S(){return sc.S();}
    public static double D(){return sc.D();}
}
class id4 {  
    BufferedReader br;
    StringTokenizer st;
    public id4(){
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

