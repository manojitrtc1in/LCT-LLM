

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;
public class Main {

	static PrintWriter pw = new PrintWriter(System.out);
 static ArrayList<Integer>[] adjList;

	public static void main(String[] args) throws IOException, InterruptedException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n=Integer.parseInt(bf.readLine());
		int[] p=new int[n+1];
		st=new StringTokenizer(bf.readLine());
		for(int i=1;i<p.length;i++) 
			p[i]=Integer.parseInt(st.nextToken());
		int q= Integer.parseInt(bf.readLine());
		int[] maxQ=new int[q+1];
		int[] lastupdate=new int[n+1];
		for(int i=1;i<maxQ.length;i++) {
		st =new StringTokenizer(bf.readLine());
		int t=Integer.parseInt(st.nextToken());
		if(t==1) {
			int person=Integer.parseInt(st.nextToken());
			int x=Integer.parseInt(st.nextToken());
			p[person]=x;
			lastupdate[person]=i;
		}else {
			int c=Integer.parseInt(st.nextToken());
			maxQ[i]=c;
		}
			
		}
		for(int i=q-1;i>=0;i--)
			maxQ[i]=Math.max(maxQ[i], maxQ[i+1]);
		for(int i=1;i<=n;i++) {
			if(i!=n)
				pw.print(Math.max(p[i], maxQ[lastupdate[i]])+" ");
			else

				pw.println(Math.max(p[i], maxQ[lastupdate[i]]));
		}
		pw.flush();
		pw.close();

}
 public static void shuffle(int[] a)
	{
		int n = a.length;
		for(int i = 0; i < n; i++)
		{
			int r = i + (int)(Math.random() * (n - i));
			int tmp = a[i];
			a[i] = a[r];
			a[r] = tmp;
		}
	}

public static double readDouble(String s) {
		StringBuilder sb =new StringBuilder("0");
		boolean neg=false;
		boolean dec=false;
		double div=1;
		int start=0;
		if(s.charAt(0)=='-') {
			neg=true;start++;
		}
		double result=0;
	for(int i=start;i<s.length();i++) {
		if(s.charAt(i)=='.') {
			result+=Long.parseLong(sb.toString());
	
			sb =new StringBuilder("0");
			dec=true;
		}else {
			sb.append(s.charAt(i));
			if(dec)
				div*=10;
		}
	}

	result+=Long.parseLong(sb.toString()) / div;
	return (neg)?-1*result:result;
}
public static int gcd(int a,int b) {
	if(a==0)return b;
	return gcd(b%a,a);
}
public static int pow(int a, int n) {
	int res=1;
	while(n>0) {
		if((n&1)==1)
			res*=a;
		a*=a;
		n>>=1;
	}
	return res;
}























































































	static boolean[] isPrime;
	static ArrayList<Integer> primes;
	static ArrayList<Integer>[] factors;


	
public static void ModifiedSieveForFactors(int N) {

		isPrime= new boolean[N+1];

	primes= new ArrayList<>(N+1);
		Arrays.fill(isPrime, true);
		factors = new ArrayList[N+1];
		for(int i=0;i<=N;i++)
			factors[i]=new ArrayList<>();
		isPrime[0]=isPrime[1]=false;
		factors[1].add(2);
		factors[1].add(0);
		for(int i=2;i<=N;i++) {
			if(isPrime[i]) {
				for(int j=i;j<=N;j+=i) {
					isPrime[j]=false;
					int k=j;
					int count=0;
					while(k%i==0) {
						count++;
						k/=i;
					}
					factors[j].add(i);
					factors[j].add(count);
				}
				isPrime[i]=true;
			}
		}
		for(int i=0;i<isPrime.length;i++) {
			if(isPrime[i])primes.add(i);
		}
	}
public static int getPth(long M) {
	if(M<factors.length) {
		ArrayList<Integer>factor= factors[(int)M];
		int prev=factor.get(1);
		for(int i=3;i<factor.size();i+=2) {
			prev=gcd(prev,factor.get(i));
		}
		return prev;
	}else {
		int p=primes.get(0);
		int idx=0;
		boolean firstTime=true;
		int prev=1;
		while(p*1l*p<=M) {
			int count=0;
			boolean entered=false;
			while(M%p==0) {
				M/=p;
				count++;
				entered=true;
				
			}
			if(firstTime&&entered) {
				prev=count;
				firstTime=false;
			}else if(entered)prev=gcd(prev,count);
				
			p=primes.get(++idx);
			}
			
			if(M!=1)
				return 1;
			return prev;
	}
		
	}

	public static void sieve(int N) {

		isPrime= new boolean[N+1];

		primes= new ArrayList<>(N);
		Arrays.fill(isPrime, true);
		isPrime[0]=isPrime[1]=false;
		for(int i=2;i*i<=N;i++) {
			if(isPrime[i]) {
				for(int j=i*i;j<=N;j+=i) {
					isPrime[j]=false;
				}
			}
		}
		
		for(int i=2;i<=N;i++)
			if(isPrime[i])
				primes.add(i);
		
	}

	static long[] lcmCard;
	public static void LCMCard(int N) {

		lcmCard=new long[N+1];
		Arrays.fill(lcmCard,1);
		primes=new ArrayList<>();
		for(int i=2;i<=N;i++) {
			if(lcmCard[i]==1) {
				primes.add(i);
				for(int j =i;j<=N;j+=i) {
					int k=j;
					int count=0;
					while(k%i==0) {
						k/=i;
						count++;
					}
					lcmCard[j]*=((count<<1)+1);
				}
			}
		}
		
	}
	public static long findCard(int N) {
		if(N<lcmCard.length)return lcmCard[N];
		int p=primes.get(0);
		int idx=0;
		long r=1;
		while(p*p<=N) {
			int count=0;
			while(N%p==0) {
				N/=p;
				count++;
			}
			r*=((count<<1)+1);
			p=primes.get(++idx);
		}
		
		if(N!=1) {
			r*=3;
		}
		return r;
		
	}


	public static void addEdge(int a, int b) {
		adjList[a].add(b);
		adjList[b].add(a);
	}
	static class FenwickTree {

	

	
int[] ft;



int n;

public FenwickTree(int n) {
	this.n=n;
	ft= new int[n+1];
}

public int LSONE(int i) {
	return i&(-i);
}

public void update_point(int  k ,int val) {

	

	while(k<=n) {
		ft[k]+=val;
		k+=LSONE(k);
	}
}
public void update_range(int i , int j ,int val) {
	update_point(i, val);
	update_point(j+1, -val);

	
}
public int query(int k) {

	int sum =0;
	while(k>0) {
		sum+=ft[k];
		k-=LSONE(k);
	}
	return sum;
}

public int query(int i , int j) {
	return query(j) - ((i<=1)?0:query(i-1));
}

public int pointQuery(int i) { 

		int sum=ft[i];
		
		if(i>0) {
		

			int z= i ^(i&-i); 

			i--;
		while(i!=z) {
			sum-=ft[i];
			i-=LSONE(i);
		}
		
		}
		return sum;
}



}


	
static public class SegmentTree {

		int N;
		int[] array;
		int[] lazy;
		int[] sTree;
		int[] idx;








	
	public SegmentTree(int[] arr) {

			array = arr;
			N = arr.length - 1;

			sTree = new int[N << 1]; 

			lazy = new int[N << 1];
			idx=new int[N<<1];
			build(1, 1, N);

		}

	
	public void build(int v, int b, int e) {

			if (b == e) {
				sTree[v] = array[b];
				idx[v]=b;
			} else {
				int mid = (b + e) >> 1;
				build((v << 1), b, mid);
				build((v << 1) | 1, mid + 1, e);
				sTree[v] =Math.max( sTree[v << 1] , sTree[(v << 1) | 1]);
				idx[v]=(sTree[v<<1|1]>=sTree[v<<1])?idx[v<<1|1]:idx[v<<1];
			}
		}

		public int query(int i, int j) {

			return query(1, 1, N, i, j);
		}

		public int getIdx(long max, int node) {
			int r = node;
			while (node < N - 1) {
				if (sTree[node << 1] == max)
					node <<= 1;
				else if (sTree[node << 1 | 1] == max)
					node = node << 1 | 1;
			}
			return node - (N - 1);
		}

		public int query(int node, int b, int e, int i, int j) {
			if (b > j || e < i)
				return 0;
			if (b >= i && e <= j) {
				return idx[node];

			}
			int mid = (b + e) >> 1;

			

			int leftChild = query(node << 1, b, mid, i, j);
			int rightChild = query((node << 1) | 1, mid + 1, e, i, j);

			return  array[rightChild]>=array[leftChild]?rightChild:leftChild;

		}

		public void set_point(int idx, int val) {

			idx += N - 1;
			sTree[idx] = val;
			boolean or = true;
			while (idx > 1) {
				idx >>= 1;
				sTree[idx] = sTree[idx << 1] + sTree[idx << 1 | 1];
			}
		}

		public void update_point(int idx, int val) {
			idx += N - 1;
			sTree[idx] += val;
			while (idx > 1) {
				idx >>= 1;

				sTree[idx] = sTree[(idx << 1)] + sTree[(idx << 1) | 1];
			}

		}

		public void update_range(int i, int j, int val) {
			update_range(1, 1, N, i, j, val);
		}

		public void update_range(int node, int b, int e, int i, int j, int val) {
			if (e < i || b > j)
				return;
			if (b >= i && e <= j) {
				sTree[node] += (e - b + 1) * val;
				lazy[node] += val;

			} else {

				int mid = (b + e) >> 1;
				propagate(node, b, mid, e);
				update_range(node << 1, b, mid, i, j, val);
				update_range(node << 1 | 1, mid + 1, e, i, j, val);
				sTree[node] = sTree[node << 1] + sTree[node << 1 | 1];
			}
		}

		public void propagateAll() {
			propagateAll(1, 1, N);
		}

		public void propagateAll(int node, int b, int e) {

			if (b == e)
				return;
			int mid = (e + b) >> 1;
			propagate(node, b, mid, e);
			propagateAll(node << 1, b, mid);
			propagateAll((node << 1) | 1, mid + 1, e);

		}

		public void propagate(int node, int b, int mid, int e) { 

			if (lazy[node] == 0 || b == e)
				return;

			lazy[node << 1] += lazy[node];
			lazy[node << 1 | 1] += lazy[node];
			sTree[node << 1] += (mid - b + 1) * lazy[node];
			sTree[node << 1 | 1] += (e - mid) * lazy[node];
			sTree[node] = sTree[node << 1] + sTree[node << 1 | 1];

			lazy[node] = 0;
		}

	}

	static public class UDS {
		int[] parent, rank, setSize;
		int n;

		int maxSet = 1;

		public UDS(int n) {

			this.n = n;
			parent = new int[n];
			rank = new int[n];
			setSize = new int[n];
			Arrays.fill(setSize, 1);
			for (int i = 0; i < n; i++)
				parent[i] = i;
		}

		public boolean unionSet(int i, int j) {
			int p1 = findSet(i);
			int p2 = findSet(j);

			if (p1 != p2) {
				n--;
				if (rank[p1] < rank[p2]) {
					parent[p1] = p2;
					setSize[p2] += setSize[p1];
					maxSet = Math.max(maxSet, setSize[p2]);
				} else {
					parent[p2] = p1;
					setSize[p1] += setSize[p2];
					maxSet = Math.max(maxSet, setSize[p1]);
					if (rank[p1] == rank[p2])
						rank[p1]++;
				}
				return true;
			}
			return false;
		}

		public int sizeOfSet(int i) {
			return setSize[findSet(i)];
		}

		public int numDisjointSets() {
			return n;
		}

		public boolean isSameSet(int i, int j) {
			return findSet(i) == findSet(j);
		}

		public int findSet(int i) {
			return (parent[i] == i) ? i : (parent[i] = findSet(parent[i]));
		}
	}


}
