

import java.io.*;
import java.util.*;
public class id0 {
	

	static long mod = 998244353;
	static long mod2 = 998244353;	
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);	
	public static void main(String args[]) {		    	
	   	id0 g=new id0();
	   	g.main();
	   	out.close();
	}	
	
	long fact[];
	void init(int n) {
		fact=new long[n+1];
		fact[0]=1;
		for(int i=1;i<=n;i++) {
			fact[i]=mul(fact[i-1],1l*i);
		}
	}
	
	PriorityQueue<Long> pq=new PriorityQueue<>();
	
	

	void main() {
		
		int n=inp.nextInt();
		int k=inp.nextInt();
		init(n);
		Pair points[]=new Pair[n];
		for(int i=0;i<n;i++) {
			long x=inp.nextLong();
			long y=inp.nextLong();
			points[i]=new Pair(x,y);
		}
		Arrays.sort(points);
		long gg=0;
		if(k==1) {
			out.println(n);
			return;
		}
		pq.add(points[0].s);
		for(int i=1;i<n;i++) {
			if(points[i].f>pq.peek()) {
				while(!pq.isEmpty() && points[i].f>pq.peek()) {
					int x=pq.size();
					gg=add(gg,nCr(x-1,k-1));
					pq.poll();
				}
			}
			pq.add(points[i].s);
		}
		while(!pq.isEmpty()) {
			int x=pq.size();
			gg=add(gg,nCr(x-1,k-1));
			pq.poll();
		}
		out.println(gg);
		

	}
	
	long add(long a, long b) {
		return (a+b)%mod;
	}
	
	long mul(long a, long b) {
		return (a*b)%mod;
	}
	
	long nCr(int n, int r) {
		if(n<r) return 0;
		return mul(fact[n],mul(power(fact[r],mod-2),power(fact[n-r],mod-2)));
	}
	
	long power(long x, long y) {
		if(y==0) return 1;
		if(y==1) return x;
		long a=power(x,y/2);
		a=mul(a,a);
		return mul(a,power(x,y%2));
	}
	
	static class Pair implements Comparable<Pair> {
		long f, s;
		Pair () {}
		Pair (long l_, long r_) {
		    this.f = l_;
		    this.s = r_;
		}
		@Override
        public int compareTo(Pair other) {
        	if(this.f==other.f) {
        		return Long.compare(this.s,other.s);
        	}
			return Long.compare(this.f, other.f);
		}
    }

	static void print(long a[]) {
		int n=a.length;
		for(int i=0;i<n;i++) {
			out.print(a[i]+" ");
		}
	}
		
	
	
	public class DSU {
        int n;
        int parent[];
        int totalSets;
        DSU(int n){
            this.n=n;
            parent=new int[n];
            for(int i=0;i<n;i++)parent[i]=i;
            totalSets=n;
        }
        int find(int i){
            int x=parent[i];
            if(x==i) return x;
            return parent[i]=find(x);
        }
        boolean union(int a, int b){
            int pa=find(a);
            int pb=find(b);
            if(pa==pb) return false;
            parent[pa]=pb;
            totalSets--;
            return true;
        }
    }
	
	class SegTree {
		int n;
		int seg[];
		SegTree(int n){
			this.n=n;
			seg=new int[4*n];
		}
		void build(int x,int lx, int rx) {
			if(lx==rx) {
				seg[x]=0;
				return;
			}
			int mid=lx+rx>>1;
			build(2*x,lx,mid);
			build(2*x+1,mid+1,rx);
			seg[x]=merge(seg[2*x],seg[2*x+1]);
		}
		void set(int i) {
			set(i,1,0,n-1);
		}
		void set(int i, int x, int lx, int rx) {
			if(lx==rx) {
				seg[x]=1;
				return;
			}
			int mid=lx+rx>>1;
			if(i<=mid) set(i,2*x,lx,mid);
			else set(i,2*x+1,mid+1,rx);
			seg[x]=merge(seg[2*x],seg[2*x+1]);
		}
		int merge(int x, int y) {
			return x+y;
		}
		int query(int l, int r) {
			return query(l,r,1,0,n-1);
		}
		int query(int l, int r, int x, int lx, int rx) {
			if(l<=lx && r>=rx) return seg[x];
			if(l>rx || r<lx) return 0;
			int mid=lx+rx>>1;
			return merge(query(l,r,2*x,lx,mid),query(l,r,2*x+1,mid+1,rx));
		}
		
	}
		
	    static class Segment implements Comparable<Segment> {
			int l, r, initialIndex;
			Segment () {}
			Segment (int l_, int r_, int d_) {
			    this.l = l_;
			    this.r = r_;
			    this.initialIndex = d_;
			}
			@Override
			public int compareTo(Segment o) {
			    return l - o.l;
			}
	    }
	    
	    static class FastReader { 
	        BufferedReader br; 
	        StringTokenizer st; 
	  
	        public FastReader() { 
	            br = new BufferedReader(new InputStreamReader(System.in)); 
	        } 
	        String next() { 
	            while (st==null || !st.hasMoreElements()) { 
	                try { 
	                    st = new StringTokenizer(br.readLine()); 
	                } 
	                catch (IOException  e) { 
	                    e.printStackTrace(); 
	                } 
	            } 
	            return st.nextToken(); 
	        } 
	        int nextInt() { 
	            return Integer.parseInt(next()); 
	        } 
	        long nextLong() { 
	            return Long.parseLong(next()); 
	        } 
	        double nextDouble() { 
	            return Double.parseDouble(next()); 
	        } 
	        String nextLine() { 
	            String s=""; 
	            try { 
	                s=br.readLine(); 
	            } 
	            catch (IOException e) { 
	                e.printStackTrace(); 
	            } 
	            return s; 
	        } 
	    } 
	    
		

		public static void sort(long arr[], int start, int end) { 		
				if(start>=end)
					return;		
				int mid=(start+end)/2;
				sort(arr,start,mid);
				sort(arr,mid+1,end);
				merge(arr,start,mid,end);	
		}	
		private static void merge(long arr[], int start, int mid, int end) {		
				int i, j=mid+1,c=0;
				long temp[]= new long[end-start+1];
				for(i=start;i<=mid && j<=end;c++) {
					if(arr[i]<=arr[j]) {
						temp[c]=arr[i];
						i++;
					}
					else {
						temp[c]=arr[j];
						j++;
					}
				}
				while(i<=mid) temp[c++]=arr[i++];
				while(j<=end) temp[c++]=arr[j++];
				c=0;
				while(start<=end) arr[start++]=temp[c++];
		}
		
		void reverse(long[] A,int l,int r) {
	        int i=l,j=r-1;
	        while(i<j) {
	            long t=A[i];
	            A[i]=A[j];
	            A[j]=t;
	            i++;j--;
	        }
	    }
	    void reverse(int[] A,int l,int r) {
	        int i=l,j=r-1;
	        while(i<j) {
	            int t=A[i];
	            A[i]=A[j];
	            A[j]=t;
	            i++;j--;
	        }
	    }
	    
	    

		static void input(long a[], int n) {
			for(int i=0;i<n;i++) {
				a[i]=inp.nextLong();
			}
		}
		static void input(int a[], int n) {
			for(int i=0;i<n;i++) {
				a[i]=inp.nextInt();
			}
		}	
		static void input(String s[],int n) {
			for(int i=0;i<n;i++) {
				s[i]=inp.next();
			}
		}
		
}
