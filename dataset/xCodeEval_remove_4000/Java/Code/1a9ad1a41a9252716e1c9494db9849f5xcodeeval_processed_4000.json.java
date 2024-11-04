import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class id0 {

	static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
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
	static long[] x= {1,1,1,0,0,0,-1,-1,-1};
	static long[] y= {1,-1,0,-1,0,1,1,-1,0};
	public static void main(String[] args) {
		OutputStream outputStream =System.out;
	    PrintWriter out =new PrintWriter(outputStream);
		FastReader s=new FastReader();
int t=s.nextInt();
while(t>0) {
long n=s.nextLong();
if(n<=6) {
	out.println(15);
}else {
	if(n%2!=0) {
		n++;
	}
	long d=5;
	n/=2;
	n*=d;
	out.println(n);
}

	t--;
}
			out.close();
	}
	public static void CS(long[] arr,long[] id4,int low,int high,int pos,int c,int n) {
		if(low==high) {
			id4[pos]=arr[low];


			return;
		}
		int mid=(low+high)/2;
		CS(arr,id4,low,mid,2*pos+1,c+1,n);
		CS(arr,id4,mid+1,high,2*pos+2,c+1,n);
		if((n-c)%2!=0) {
		id4[pos]=(id4[2*pos+1]|id4[2*pos+2]);
	}else {
		id4[pos]=(id4[2*pos+1]^id4[2*pos+2]);
	}
		}
	public static void US(long[] id4,int low,int high,int pos ,long new_val,int index,long prev_val,int c,int n) {






		if(low==high) {
			id4[pos]=new_val;
			return;
		}




		if(high!=low) {
			int mid=(high+low)/2;
			if(index<=mid) {
			US(id4,low,mid,2*pos+1,new_val,index,prev_val,c+1,n);}else {
			US(id4,mid+1,high,2*pos+2,new_val,index,prev_val,c+1,n);}
			if((n-c)%2!=0) {
				id4[pos]=(id4[2*pos+1]|id4[2*pos+2]);
			}else {
				id4[pos]=(id4[2*pos+1]^id4[2*pos+2]);
			}
		}
	}
	public static long RS(long[] id4,int qlow,int qhigh,int low,int high,int pos) {
		if(low>=qlow && high<=qhigh) {
			return id4[pos];
		}
		if(qhigh<low || qlow>high) {
			return 0;
		}
		int mid=(low+high)/2;
	return RS(id4,qlow,qhigh,low,mid,2*pos+1)^RS(id4,qlow,qhigh,mid+1,high,2*pos+2);
	}
	static int id5(int n) 
	{ 
	    n--; 
	    n |= n >> 1; 
	    n |= n >> 2; 
	    n |= n >> 4; 
	    n |= n >> 8; 
	    n |= n >> 16; 
	    n++; 
	      
	    return n; 
	} 

	public static int id3(String str,int n) {
		int[][] dp=new int[n+1][n+1];
		
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(str.charAt(i-1)==str.charAt(j-1) &&  i!=j) {
					dp[i][j]=1+dp[i-1][j-1];
				}else {
					dp[i][j]=Math.max(dp[i][j-1], dp[i-1][j]);
				}
			}
		}	
		return dp[n][n];
	}
	public static int d1(ArrayList<Integer> e,int n,int i) {
		int l=-1;
		int r=n;
				;
		while(r>l+1) {
			int mid=(l+r)/2;




			if(e.get(mid)>i) {
				r=mid;
			}else {
				l=mid;
			}
		}
		return r;
				
	}
	public static int upper_bound(long[] a ,long x,int n) {
		int l=-1;
		int r=n;
		while(r>l+1) {
			int mid=(l+r)/2;
			if(a[mid]>=x) {
				r=mid;
			}else {
				l=mid;
			}
		}
		return r;
				
	}
	public static int lower_bound(long[] a ,long x,int n) {
		int l=0;
		int r=n+1;
		while(r>l+1) {
			int mid=(l+r)/2;
			if(a[mid]<=x) {
				l=mid;
			}else {
				r=mid;
			}
		}
		return l;
				
	}
	static long get=0;
	static int[] ans=new int[200001];





































	static int[] h=new int[200001];
	static int[] subtree=new int[200001];
	static int[] vis=new int[200001];
	static HashMap<Integer,pair> e=new HashMap<>();
	static ArrayList<Integer>[] f1=new ArrayList[200001];	
	static PriorityQueue<pair> q=new PriorityQueue<>();	
	static ArrayList<pair>[] f=new ArrayList[200001];   
	static void bfs() {
		Queue<node> q=new LinkedList<>();
		q.add(new node(1,0));
		h[1]=0;
		vis[1]=1;
		while(!q.isEmpty()) {
			node p=q.poll();


			for(int i=0;i<f1[p.a].size();i++) {
				if(vis[f1[p.a].get(i)]==0) {
					q.add(new node(f1[p.a].get(i),p.b+1));
					h[f1[p.a].get(i)]=p.b+1;
					vis[f1[p.a].get(i)]=1;
				}
			}
		}
	}
	static int dfs(int node) {
		int c=1;
		vis[node]=1;
		for(int i=0;i<f1[node].size();i++) {
			if(vis[f1[node].get(i)]==0) {
				c+=dfs(f1[node].get(i));
			}
		}
		subtree[node]=c;
		return c;
	}
	static void dfs2(int node,int v) {
		vis[node]=1;
		if(ans[node]==1) {
			get+=v;
		}
		for(int i=0;i<f1[node].size();i++) {
			if(vis[f1[node].get(i)]==0) {
				dfs2(f1[node].get(i),v+((ans[node]==0)?1:0));
			}
		}
	}
static long m=-1;
static void sf(long[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
            long tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }   
}

	static class pair implements Comparable<pair>{
		private long a;
		private long b;
		private long c;
		
		pair(long a,long b,long c){
			this.a=a;


			this.b=b;
			this.c=c;




		}
		public int compareTo(pair o) {
			if(o.c!=this.c) {




				return Long.compare(this.c,o.c);
			}else {
				return Long.compare(this.a*this.b,o.a*o.b);
			}
		}


		
	}
	static class node{
		private int a;
		private int b;
		node(int a,int b){
			this.a=a;
			this.b=b;
		}
	}

























































	public static long lb(int n,long[] pre,long k,long a,long b,long x,long y) {
		long l=0;
		long r=n+1;
		while(l<r) {
			long mid=(l+r)/2;
			long sum=0;
			long gcd=GCD(a,b);
			long g=mid/(a*b/gcd);
			long a1=mid/a;
			long b1=mid/b;
			sum+=(pre[(int) g]*(x+y))/100;
			if(x>=y) {
				sum+=((pre[(int) a1]-pre[(int) g])*x)/100;
				sum+=(((pre[(int)(a1+b1-g)]-pre[(int)(a1)])*y))/100;
			}else {
				sum+=((pre[(int) b1]-pre[(int) g])*y)/100;
				sum+=(((pre[(int)(a1+b1-g)]-pre[(int)(b1)])*x))/100;
			}
			if(sum>=k) {
				r=mid;
			}else {
				l=mid+1;
			}


		}
		
		return r;
				
	}
	
	
	
	public static long[] merge_sort(long[] A, int start, int end) {
		if (end > start) {
			int mid = (end + start) / 2;
			long[] v = merge_sort(A, start, mid);
			long[] o = merge_sort(A, mid + 1, end);
			return (merge(v, o));
		} else {
			long[] y = new long[1];
			y[0] = A[start];
			return y;
		}
	}
	public static long[] merge(long a[], long b[]) {
		
		long[] temp = new long[a.length + b.length];
		int m = a.length;
		int n = b.length;
		int i = 0;
		int j = 0;
		int c = 0;
		while (i < m && j < n) {
			if (a[i] < b[j]) {
				temp[c++] = a[i++];
			
			} else {
				temp[c++] = b[j++];
			}
		}
		while (i < m) {
			temp[c++] = a[i++];
		}
		while (j < n) {
			temp[c++] = b[j++];
		}
		return temp;
	}	
	public static int[] Create(int[] a,int n) {
		int[] b=new int[n+1];
		for(int i=1;i<=n;i++) {
			int j=i;
			int h=a[i];
			while(i<=n) {
				b[i]+=h;
				i=get_next(i);
			}
			i=j;
		}
		return b;
	}
public static int get_next(int a) {
	return a+(a&-a);
}
public static int get_parent(int a) {
	return a-(a&-a);
}
public static int id1(int[] b,int index) {
	int sum=0;
	if(index<=0) {
		return 0;
	}
	while(index>0) {
		sum+=b[index];
		index=get_parent(index);
	}
	return sum;
}
public static int query(int[] b,int n,int l,int r) {
	int sum=0;
	sum+=id1(b,r);
	sum-=id1(b,l-1);
	return sum;
}
public static void update(int[] a,int[] b,int n,int index,int val) {
	int diff=val-a[index];
	a[index]+=diff;
	while(index<=n) {
		b[index]+=diff;
		index=get_next(index);
	}	
}
	


















































































































































































	public static int lower_bound(ArrayList<Long> a ,int n,long x) {
		int l=0;
		int r=n;
		while(r>l+1) {
			int mid=(l+r)/2;
			if(a.get(mid)<=x) {
				l=mid;
			}else {
				r=mid;
			}
		}
		return l;		
	}
	public static int[] is_prime=new int[1000001];
	public static ArrayList<Long> primes=new ArrayList<>();
 	public static void sieve() {
		long maxN=1000000;
		for(long i=1;i<=maxN;i++) {
			is_prime[(int) i]=1;
		}
		is_prime[0]=0;
		is_prime[1]=0;
		for(long i=2;i*i<=maxN;i++) {
			if(is_prime[(int) i]==1) {


				for(long j=i*i;j<=maxN;j+=i) {
					is_prime[(int) j]=0;
				}
			}
		}
		for(long i=0;i<=maxN;i++) {
			if(is_prime[(int) i]==1) {
				primes.add(i);
			}
		}		
	}






































































	public static long im(long a) {
		return id2(a,mod-2)%mod;
	}
	public static long id2(long a,long n) {
		long res=1;
		while(n>0) {
			if(n%2!=0) {
				res=((res)%(mod) * (a)%(mod))%(mod);
				n--;
			}else {
				a=((a)%(mod) *(a)%(mod))%(mod);
				n/=2;
			}
		}
		return (res)%(mod);
		
	}
	public static long b1(long a,long n) {
		long res=1;
		while(n>0) {
			if(n%2!=0) {
				res=((res)%(mod) * (a)%(mod))%(mod);
				n--;
			}else {
				a=((a)%(mod) *(a)%(mod))%(mod);
				n/=2;
			}
		}
		return (res)%(mod);
		
	}

	public static double bn1(double a,double n) {
		double res=1;
		while(n>0) {
			if(n%2!=0) {


				res=(res*a);
				n--;
			}else {


				a=(a*a);
				n/=2;
			}
		}
		return (res);	
	}
	public static long bn(long a,long n) {
		long res=1;
		while(n>0) {
			if(n%2!=0) {
				res=res*a;
				n--;
			}else {
				a*=a;
				n/=2;
			}
		}
		return res;
		
	}
public static long[] fac=new long[300001];
public static void ff() {
		fac[0]=(long)1;
		fac[1]=(long)1;
		for(long i=2;i<=300000;i++) {
			fac[(int) i]=(fac[(int) (i-1)]*i)%(m);
		}
	}	
public static long mod=1000000007;
public static long GCD(long a,long b) {
		if(b==(long)0) {
			return a;
		}
		return GCD(b , a%b);
	}
public static long c=0;	
}