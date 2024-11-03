

import java.io.*;
import java.util.*;
public class _InVoker_ {
	

	static long mod = (long)1e9+7;
	static long mod2 = 998244353;	
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);	
	public static void main(String args[]) {		    	
	   	_InVoker_ g=new _InVoker_();
	   	g.main();
	   	out.close();
	}	
	
	
	
	

	void main() {
		
		int t=inp.nextInt();
		while(t-->0) {
			int n=inp.nextInt();
			int a[]=new int[n];
			for(int i=0;i<n;i++) a[i]=inp.nextInt()-1;
			int gg[]=new int[n];
			for(int i=0;i<n;i++) {
				if(gg[i]==0) {
					ArrayList<Integer> indexes=new ArrayList<>();
					int start=i,cur=i,c=1;
					indexes.add(i);
					while(a[cur]!=start) {
						cur=a[cur];
						indexes.add(cur);
						c++;
					}
					for(int x: indexes) gg[x]=c;
				}
			}
			print(gg);
		}
		
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

	static void print(int a[]) {
		int n=a.length;
		for(int i=0;i<n;i++) {
			out.print(a[i]+" ");
		}
		out.println();
	}
		
	
	
	
	
	

	PriorityQueue<Integer> dpq =new PriorityQueue<>((x, y) -> Integer.compare(y, x));
	
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
		
		long fact[];
		void init() {
			fact=new long[1000001];
			fact[0]=1;
			for(int i=1;i<=1000000;i++) {
				fact[i]=mul(i,fact[i-1]);
			}
		}
		
		long gcd(long a, long b) {
			return b==0?a:gcd(b,a%b);
		}
		
		long nCr(int n, int r) {
			if(n==r) return 1;
			return mul(fact[n],mul(power(r,mod-2),power(n-r,mod-2)));
			
		}
		
		long mul(long a, long b) {
			return (a*b)%mod;
		}
		
		long add(long a, long b) {
			return (a+b)%mod;
		}
		
		long power(long x, long y) {
			if(y==1) return x;
			if(y==0) return 1;
			long gg=power(x,y/2);
			gg=mul(gg,gg);
			return mul(gg,power(x,y%2));
		}
		
}
