

import java.io.*;
import java.util.*;
public class id1 {
	

	static long mod = 1000000007;
	static long mod2 = 998244353;	
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);	
	public static void main(String args[]) {		    	
	   	id1 g=new id1();
	   	g.main();
	   	out.close();
	}	
	
	static int n=inp.nextInt();
	static int m=inp.nextInt();
	static ArrayList<Integer> edges[]=new ArrayList[n];
	static boolean vis[]=new boolean[n];
	static int group[]=new int[n],groups=0;
	static int maxDist=0,id5=0;
	
	

	void main() {
		
		for(int i=0;i<n;i++) {
			edges[i]=new ArrayList<Integer>();
		}
		for(int i=0;i<m;i++) {
			int x=inp.nextInt()-1;
			int y=inp.nextInt()-1;
			edges[x].add(y);
			edges[y].add(x);
		}
		Arrays.fill(group, -1);
		for(int i=0;i<n;i++) {
			if(group[i]==-1) {
				markGroup(i,groups++);
			}
		}
		int id4[]=new int[groups];
		int id2[]=new int[groups];
		int diameter=0;
		Arrays.fill(id4, n);
		for(int i=0;i<n;i++) {
			Arrays.fill(vis, false);
			int id3=dfs(i,0);
			diameter=Math.max(diameter, id3);
			if(id3<id4[group[i]]) {
				id4[group[i]]=id3;
				id2[group[i]]=i;
			}
		}
		int bestGroup=0;
		for(int i=0;i<groups;i++) {
			if(id4[i]>id4[bestGroup]) {
				bestGroup=i;
			}
		}
		int gg=id4[bestGroup];
		ArrayList<Integer> id0 = new ArrayList<>();
		for(int i=0;i<groups;i++) {
			if(i!=bestGroup) {
				id0.add(id4[i]);
			}
		}
		Collections.sort(id0);
		Collections.reverse(id0);
		if(!id0.isEmpty()) {
			gg= id4[bestGroup]+1+id0.get(0);
			if(id0.size()>1) {
				gg=Math.max(gg, 2+id0.get(0)+id0.get(1));
			}
		}
		gg=Math.max(gg, diameter);
		out.println(gg);
		for(int i=0;i<groups;i++) {
			if(i!=bestGroup) {
				out.println((id2[i]+1)+" "+(id2[bestGroup]+1));
			}
		}
	}
	
	static int dfs(int i,int count) {
		vis[i]=true;
		int max=count;
		for(int x:edges[i]) {
			if(!vis[x]) {
				max=Math.max(max, dfs(x,count+1));
			}	
		}
		return max;
	}
	
	static void markGroup(int i,int num) {
		group[i]=num;
		for(int x:edges[i]) {
			if(group[x]==-1) {
				markGroup(x,num);
			}
		}
	}
		
	
	
		
		

		static class Pair implements Comparable<Pair> {
			long l, r;
			int initIndex;
			Pair () {}
			Pair (long l_, long r_, int i) {
			    this.l = l_;
			    this.r = r_;
			    this.initIndex=i;
			}
			@Override
	        public int compareTo(Pair other) {
	        	if(this.l==other.l) {
	        		return Long.compare(other.initIndex,this.initIndex);
	        	}
				return Long.compare(this.l, other.l);
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
	    
	    

	    static long gcd(long a, long b) { 
			return b==0?a:gcd(b,a%b);
		}
		static int gcd(int a, int b) { 
			return b==0?a:gcd(b,a%b);
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
				while(i<=mid) {
					temp[c]=arr[i];
					i++;c++;
				}
				while(j<=end) {
					temp[c]=arr[j];
					j++;c++;
				}
				c=0;
				for(i=start;i<=end;i++,c++)
					arr[i]=temp[c];
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
