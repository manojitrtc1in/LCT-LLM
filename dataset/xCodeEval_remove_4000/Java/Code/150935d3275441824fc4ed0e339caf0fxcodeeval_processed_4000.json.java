			import java.io.*;
			import java.lang.*;
			import java.util.*;
			public class id1 {
				static int dp[][];
				static boolean mnans;
				static int x[]= {-1,0,0,1};
				static int y[]= {0,1,-1,0};
				public static void main(String[] args) throws Exception{
					

			

					FastReader sc=new FastReader();
					BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
			



					 int tc=1;
					 while(tc--!=0) {
						 	int n=sc.nextInt();
						 	int m=sc.nextInt();
						 	
						 	int a[]=new int[m];
						 	for(int i=0;i<m;i++)a[i]=sc.nextInt();
						 	int st[][]=new int[m][32];
						 	build(st,a);
						 	int q=sc.nextInt();
						 	

						 	for(int i=0;i<q;i++) {
						 		int x1=sc.nextInt();
						 		int y1=sc.nextInt();
						 		int x2=sc.nextInt();
						 		int y2=sc.nextInt();
						 		int k=sc.nextInt();
						 		if(Math.abs(x1-x2)%k==0 && Math.abs(y2-y1)%k==0) {
						 			
						 		int top=x1+((n-x1)/k)*k;
						 		int mn=Math.min(y1, y2);
						 		int mx=Math.max(y2, y1);
						 		int max=serst(st,mn-1,mx-1);


						 		if(max<top)log.write("YES\n");
						 		else log.write("NO\n");
						 			
						 		}
						 		else log.write("NO\n");
						 		
						 	}
						 	
					}
						 
					 log.flush();
					 
					 
					 }
	static void dfs(int a[][],int i,int j,int tm,int cnt,boolean vis[][]) {
		boolean fg=true;
		for(int k=0;k<4;k++) {
			if(i+x[k]<=1 && i+x[k]>=0 && j+y[k]<a[0].length && j+y[k]>=0 && !vis[i+x[k]][j+y[k]] && (a[i+x[k]][j+y[k]]==0 || a[i+x[k]][j+y[k]]<=tm && !mnans)) {
				fg=false;
				vis[i][j]=true;
				dfs(a,i+x[k],j+y[k],tm+1,cnt+1,vis);
				vis[i][j]=false;
			}
		}
		if(fg && cnt==2*a[0].length)mnans=true;
	}			
		static int mod=998244853;			
			static int[] lps(int a[],String s) {
				int i=1;
				int j=0;
				a[0]=0;
				while(i<s.length()) {
					if(s.charAt(i)==s.charAt(j)) {
						a[i]=j+1;
						i++;
						j++;
					}
					else {
						if(j!=0) {
			            j=a[j-1];
						}
						else {
						a[i]=0;
						i++;
						}
					}
				}
				return a;
			}	
			
			static int[] zed(char a[]) {
				int z[]=new int[a.length];
				int l=0;
				int r=0;
				for(int i=0;i<a.length;i++) {
					if(i>r) {
						l=r=i;
						while(r<a.length && a[r]==a[r-l])r++;
						z[i]=r-l;
						r--;
					}
					else {
						int k1=i-l;
						if(z[k1]<r-i+1) {
							z[i]=z[k1];
						}
						else {
							l=i;
							while(r<a.length && a[r]==a[r-l])r++;
							z[i]=r-l;
							r--;
						}
					}
				}
				return z;
			}
				
			
			public static class pair2{
				int a,b,c,d;
				public pair2(int a,int b,int c,int d) {
					this.a=a;
					this.b=b;
					this.c=c;
					this.d=d;
				}
			}
			static boolean dfs(ArrayList<ArrayList<Integer>> ar,int src,int pr,HashSet<Integer> hs) {
			    int cnt=0;
			    boolean an=false;
				for(int k:ar.get(src)) {
					if(k==pr)continue;
					boolean p=dfs(ar,k,src,hs);
					an|=p;
					if(p)cnt++;
				}
				if(cnt>1)mnans=false;
				if(hs.contains(src))an=true;
				return an;
			}
			static int find(int el,int p[]) {
					if(p[el]<0)return el;
					return p[el]=find(p[el],p);
				}
			static boolean union(int a,int b,int p[]) {
					int p1=find(a,p);
					int p2=find(b,p);
					if(p1>=0 && p1==p2)return false;
					else {
						if(p[p1]<p[p2]) {
							p[p1]+=p[p2];
							p[p2]=p1;
						}
						else {
							p[p2]+=p[p1];
							p[p1]=p2;
						}
						return true;
					}
					
			}
				public static void build(int a[][],int b[]) {
					for(int i=0;i<b.length;i++) {
						a[i][0]=b[i];
					}
					int jmp=2;
					   while(jmp<=b.length) {
						for(int j=0;j<b.length;j++) {
							int ind=(int)(Math.log(jmp/2)/Math.log(2));
							int ind2=(int)(Math.log(jmp)/Math.log(2));
							if(j+jmp-1<b.length) {
							a[j][ind2]=Math.max(a[j][ind],a[j+(jmp/2)][ind]);
							}
						}
						jmp*=2;
					}   
				

				

				

				

				

				

				}
				public static void build2(int a[][],int b[]) {
					for(int i=0;i<b.length;i++) {
						a[i][0]=b[i];
					}
					int jmp=2;
					   while(jmp<=b.length) {
						for(int j=0;j<b.length;j++) {
							int ind=(int)(Math.log(jmp/2)/Math.log(2));
							int ind2=(int)(Math.log(jmp)/Math.log(2));
							if(j+jmp-1<b.length) {
							a[j][ind2]=Math.min(a[j][ind],a[j+(jmp/2)][ind]);
							}
						}
						jmp*=2;
					}   
				

				

				

				

				

				

				}
				public static int serst(int a[][],int i,int j) {
					int len=j-i+1;
					int hp=1;
					int tlen=len>>=1;
				

					while(tlen!=0) {
						tlen>>=1;
						hp<<=1;
					}
				

					int ind=(int)(Math.log(hp)/Math.log(2));
					int i2=j+1-hp;
					return Math.max(a[i][ind], a[i2][ind]);
				}
				public static int id3(int a[][],int i,int j) {
					int len=j-i+1;
					int hp=1;
					int tlen=len>>=1;
				

					while(tlen!=0) {
						tlen>>=1;
						hp<<=1;
					}
				

					int ind=(int)(Math.log(hp)/Math.log(2));
					int i2=j+1-hp;
					return Math.min(a[i][ind], a[i2][ind]);
				}
						static void update(long f[],long upd,int ind) {
							int vl=ind;
							while(vl<f.length) {
								f[vl]+=upd;
								int tp=~vl;
								tp++;
								tp&=vl;
								vl+=tp;
							}
						}	
						static long ser(long f[],int ind) {
							int vl=ind;
							long sm=0;
							while(vl!=0) {
								sm+=f[vl];
								int tp=~vl;
								tp++;
								tp&=vl;
								vl-=tp;
							}
							return sm;
						}
			
			
						
				public static void id4(int a[]) {
					int n=a.length;
					int res[]=new int[n];
					
					int p=1;
				
					for(int i=0;i<=8;i++) {
						int cnt[]=new int[10];
					     for(int j=0;j<n;j++) {
					    	 a[j]=res[j];
					    	 cnt[(a[j]/p)%10]++;
					    	
					     }
					     for(int j=1;j<=9;j++) {
					    	 cnt[j]+=cnt[j-1];
					     }
					     
					     for(int j=n-1;j>=0;j--) {
					        res[cnt[(a[j]/p)%10]-1]=a[j];
					        cnt[(a[j]/p)%10]--;
					     }
					     
					     p*=10;
						
					}
					
					
				}	
				static int bits(long n) {
					int ans=0;
					while(n!=0) {
						if((n&1)==1)ans++;
						n>>=1;
					}
					return ans;
				}	
				public static int kadane(int a[]) {
					int sum=0,mx=Integer.MIN_VALUE;
					for(int i=0;i<a.length;i++) {
						sum+=a[i];
						mx=Math.max(mx, sum);
						if(sum<0) sum=0;
						 
					}
					return mx;
				}	
					
				public static int m=(int)(1e9+7);	
				public static int mul(int a, int b) {
					return ((a%m)*(b%m))%m;
				}
				public static long mul(long a, long b) {
					return ((a%m)*(b%m))%m;
				}
				public static int add(int a, int b) {
					return ((a%mod)+(b%mod))%mod;
				}
				public static long add(long a, long b) {
					return ((a%m)+(b%m))%m;
				}
				
				
				

				public static <E> void p(E[][] a,String s) {
					   System.out.println(s);
					   for(int i=0;i<a.length;i++) {
						   for(int j=0;j<a[0].length;j++) {
							   System.out.print(a[i][j]+" ");
						   }
						   System.out.println();
					   }
					  
				}
				public static  void p(int[] a,String s) {
					System.out.print(s+"=");
					for(int i=0;i<a.length;i++)System.out.print(a[i]+" ");
					System.out.println();
				}
				public static  void p(long[] a,String s) {
					System.out.print(s+"=");
					for(int i=0;i<a.length;i++)System.out.print(a[i]+" ");
					System.out.println();
				}
				public static <E> void p(E a,String s){
					System.out.println(s+"="+a);
				}
				public static <E> void p(ArrayList<E> a,String s){
					System.out.println(s+"="+a);
				}
				public static <E> void p(LinkedList<E> a,String s){
					System.out.println(s+"="+a);
				}
				public static <E> void p(HashSet<E> a,String s){
					System.out.println(s+"="+a);
				}
				public static <E> void p(Stack<E> a,String s){
				  System.out.println(s+"="+a);
				}
				public static <E> void p(Queue<E> a,String s){
					System.out.println(s+"="+a);
				}
				
				

				static ArrayList<Integer> id0(int n){
					
					ArrayList<Integer> ar=new ArrayList<>();
				     for (int i=2; i<=Math.sqrt(n); i++){
					        if (n%i == 0){
					            if (n/i == i) {
					            	ar.add(i);
					            }
					            else {
					               ar.add(i);
					               ar.add(n/i);
					            }
					         }
				       }
					return ar;
				}
				static ArrayList<Integer> prime(int n){
					ArrayList<Integer> ar=new ArrayList<>();
					int cnt=0;
					boolean pr=false;
					while(n%2==0) {
						ar.add(2);
						n/=2;	
					}
					for(int i=3;i*i<=n;i+=2) {
						pr=false;
						while(n%i==0) {
							n/=i;
							ar.add(i);
							pr=true;
						}
					
					}
					if(n>2) ar.add(n);
					return ar;
					
				}
				
				static long gcd(long a,long b) {
					if(b==0)return a;
					else return gcd(b,a%b);
				}
				static int gcd(int a,int b) {
					if(b==0)return a;
					else return gcd(b,a%b);
				}
				static long factmod(long n,long mod) {
					if(n==0)return 0;
					long ans=1;
					long temp=1;
					while(temp<=n) {
						ans=((ans%mod)*((temp)%mod))%mod;
						temp++;
					}
					return ans%mod;
				}		
				static int ncr(int n, int r){
				    if(r>n-r)r=n-r;
				    int ans=1;
				    for(int i=0;i<r;i++){
				          ans*=(n-i);
				          ans/=(i+1);
				    }
				    return ans;
				} 
				
				public static class trip{
					int a;
					int b;
					int c;
					public trip(int a,int b,int  c) {
						this.a=a;
						this.b=b;
						this.c=c;
					}
			

			

			

				}	
						static void id2(int[] a,int start,int end) {
								if(start>=end)return ;
								int mid=start+(end-start)/2;
								id2(a,start,mid);
								id2(a,mid+1,end);
								merge(a,start,mid,end);
								
							}
						static void merge(int[] a, int start,int mid,int end) {
								int ptr1=start;
								int ptr2=mid+1;
								int b[]=new int[end-start+1];
								int i=0;
								while(ptr1<=mid && ptr2<=end) {
									if(a[ptr1]<=a[ptr2]) {
										b[i]=a[ptr1];
										ptr1++;
										i++;
									}
									else {
										b[i]=a[ptr2];
										ptr2++;
										i++;
									}
								}
								while(ptr1<=mid) {
									b[i]=a[ptr1];
									ptr1++;
									i++;
								}
								while(ptr2<=end) {
									b[i]=a[ptr2];
									ptr2++;
									i++;
								}
								for(int j=start;j<=end;j++) {
									a[j]=b[j-start];
								}
							}
				public static class FastReader {
				
						BufferedReader b;
						StringTokenizer s;
						public FastReader() {
							b=new BufferedReader(new InputStreamReader(System.in));
						}
						String next() {
							while(s==null ||!s.hasMoreElements()) {
								try {
									s=new StringTokenizer(b.readLine());
								}
								catch(IOException e) {
									e.printStackTrace();
								}
							}
							return s.nextToken();
						}
						public int nextInt() {
							return Integer.parseInt(next());
						}
						public long nextLong() {
							return Long.parseLong(next());
						}
						public double nextDouble() {
							return Double.parseDouble(next());
						}
						String nextLine() {
							String str="";
							try {
								str=b.readLine();
							}
							catch(IOException e) {
								e.printStackTrace();
							}
							return str;
						}
						boolean hasNext() {
						    if (s != null && s.hasMoreTokens()) {
						        return true;
						    }
						    String tmp;
						    try {
						        b.mark(1000);
						        tmp = b.readLine();
						        if (tmp == null) {
						            return false;
						        }
						        b.reset();
						    } catch (IOException e) {
						        return false;
						    }
						    return true;
						}
				}
				public static class pair{
					int a;
			        int b;
					public pair(int a,int b) {
						this.a=a;
						this.b=b;
					}
					
			

			

			

			

			

				

				

					@Override
					public String toString() {
						return "{"+this.a+" "+this.b+"}";
						}
					}	
					static long pow(long a, long pw) {
						long temp;
						if(pw==0)return 1;
						temp=pow(a,pw/2);
						if(pw%2==0)return temp*temp;
						return a*temp*temp;
						
					}
					public static int md=998244353;
					static long mpow(long a, long pw) {
						long temp;
						if(pw==0)return 1;
						temp=pow(a,pw/2)%md;
						if(pw%2==0)return mul(temp,temp);
						return mul(a,mul(temp,temp));
						
					}
					
					static int pow(int a, int pw) {
						int temp;
						if(pw==0)return 1;
						temp=pow(a,pw/2);
						if(pw%2==0)return temp*temp;
						return a*temp*temp;
						
					}
				
			}