

import java.util.*;
import java.io.*;
public class InVoker {
	

	static long mod = 1000000007;
	static long mod2 = 998244353;
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
	   	InVoker g=new InVoker();
	   	g.main();
	   	out.close();
	}
	
	

	void main() {
			
			int n=inp.nextInt();
			int m=inp.nextInt();
			long x=inp.nextLong();
			long k=inp.nextLong();
			long y=inp.nextLong();
			long a[]=new long[n];
			boolean req[]=new boolean[n];
			boolean can=true;
			input(a,n);
			long b[]=new long[m];
			input(b,m);
			long gg=0;
			long costForK=Math.min(x,y*k);
			int j=0;
			int start=-1;
			long count=0;
			for(int i=0;i<n && j<m;i++) {
				if(a[i]==b[j]) {
					req[i]=true;
					j++;
					if(count>0) {
						if(count>=k) {
							

							boolean greaterPres=false;
							long maxBorder=-1;
							if(start==-1) {
								maxBorder=a[i];
							}else {
								maxBorder=a[start]>a[i]?a[start]:a[i];
							}
							for(int p=start+1;p<i;p++) {
								if(a[p]>maxBorder) {
									greaterPres=true;
									break;
								}
							}
							if(!greaterPres) {
								

								gg+=(costForK*(count/k))+(y*(count%k));
							}else {
								count-=k;
								gg+=x;
								gg+=(costForK*(count/k))+(y*(count%k));
							}
						}else {
							gg+=count*y;
							long maxBorder=-1;
							if(start==-1) {
								maxBorder=a[i];
							}else {
								maxBorder=a[start]>a[i]?a[start]:a[i];
							}
							for(int p=start+1;p<i;p++) {
								if(a[p]>maxBorder) {
									can=false;
									break;
								}
							}
						}
						count=0;
					}else {
						

					}
					start=i;
				}else {
					count++;
				}
			}
			

			int end=n-1;
			while(!req[end]) {
				end--;
			}
			count=n-end-1;
			if(count>=k) {
				boolean greaterPres=false;
				for(int i=end+1;i<n;i++) {
					if(a[i]>a[end]) {
						greaterPres=true;
						break;
					}
				}
				if(!greaterPres) {
					gg+=(costForK*(count/k))+(y*(count%k));
				}else {
					count-=k;
					gg+=x;
					gg+=(costForK*(count/k))+(y*(count%k));
				}
				
			}else {
				gg+=count*y;
				for(int i=end+1;i<n;i++) {
					if(a[i]>a[end]) {
						can=false;
						break;
					}
				}
			}
			can= can && j==m;
			if(!can) {
				out.println(-1);
			}else {
				out.println(gg);
			}
		
	}

	
	
	
	
	
	
	

	static class Edge implements Comparable<Edge>{
		int l,r;
		Edge(){}
		Edge(int l,int r){
			this.l=l;
			this.r=r;
		}
		@Override
		public int compareTo(Edge e) {
			return (l-e.l)!=0?l-e.l:r-e.r;
		}
	}
	
    static class Segment implements Comparable<Segment> {
		long l, r, initialIndex;
		Segment () {}
		Segment (long l_, long r_, long d_) {
		    this.l = l_;
		    this.r = r_;
		    this.initialIndex = d_;
		}
		@Override
		public int compareTo(Segment o) {
		    return (int)((l - o.l) !=0 ? l-o.l : initialIndex - o.initialIndex);
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
	
	static void reverse(long[] A,int l,int r) {
        int i=l,j=r-1;
        while(i<j) {
            long t=A[i];
            A[i]=A[j];
            A[j]=t;
            i++;j--;
        }
    }
    static void reverse(int[] A,int l,int r) {
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
	static void input(int a[][], int n, int m) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				a[i][j]=inp.nextInt();
			}
		}
	}
	static void input(long a[][], int n, int m) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				a[i][j]=inp.nextLong();
			}
		}
	}
		
}
