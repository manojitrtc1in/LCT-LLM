												import java.math.BigInteger;
												import java.sql.Array;
											    import java.util.ArrayList;
												import java.util.Arrays;
												import java.util.Collection;
												import java.util.Collections;
												import java.util.Comparator;
												import java.util.HashMap;
	import java.util.HashSet;
	import java.util.InputMismatchException;
												import java.util.Iterator;
												import java.util.LinkedHashSet;
												import java.util.LinkedList;
												import java.util.List;
												import java.util.Map;
												import java.util.Map.Entry;	
												import java.util.PriorityQueue;
												import java.util.Queue;
												import java.util.Scanner;
												import java.util.Set;
												import java.util.Stack;
												import java.io.BufferedReader;
												import java.io.IOException;
												import java.io.InputStream;
												import java.io.InputStreamReader;
												import java.util.Scanner;
												import java.util.StringTokenizer;
												import java.util.TreeMap;
												import java.util.TreeSet;
												
												
												
												public class Main {
													
												static long l[];	
												static int k;	
														static int cycle=0;
													static InputReader rd=new InputReader(System.in);
												static	HashMap<Integer,Integer> hs=new HashMap<>();
													public static void main(String[] args) {
														Scanner sc=new Scanner(System.in);
														
														
														
														
														int t=sc.nextInt();
														
														
														
														while(t-->0) {
														
															int n=sc.nextInt();
															int a[]=new int [n];
																int m=sc.nextInt();
															
															int x=sc.nextInt();
															for(int i=0;i<n;i++) {
																a[i]=sc.nextInt();
																
															}
															
															
															long s=0;
															for(int i=0;i<n;i++) {
																s+=a[i];
																
																
															}
															
															s=s/m;
															
															
															if(s==0)System.out.println("NO");
															int curr=0;
														
															int prev=-1;
															int b=1;
															int k=0;
															boolean flag=false;
															int ans[]=new int[n];
															
															
															PriorityQueue<Blocks>q=new PriorityQueue<Main.Blocks>(
																	new Comparator<Blocks>() {
																		
																		public int compare(Blocks o1, Blocks o2) {
																			return o1.a-o2.a;
																			
																		}
																	}
																	);
															
															
															for(int i=0;i<m;i++) {
																
																q.add(new Blocks(0,i+1));
															}
															
															
															for(int i=0;i<n;i++) {
																
																Blocks sm=q.poll();
																
																ans[k++]=sm.i;
																
																sm.a=sm.a+a[i];
																q.add(sm);
																
															}
															
															System.out.println("YES");
															
															
															for(int i=0;i<n;i++)System.out.print(ans[i]+" ");
															
															System.out.println();
															
															
															
														}
														
														
														
															
													}
													
													
													
													
												static class Blocks{
													int a;int i;
													
													Blocks(int a,int i){
														this.a=a;
														this.i=i;
													}
													
												}
													
													 static int gcd(int a, int b)
													    {
													        if (a == 0)
													            return b; 
													        return gcd(b % a, a); 
													    }
													     
													    

													    static int lcm(int a, int b)
													    {
													        return (a / gcd(a, b)) * b;
													    }
													
													    public String repeatedSubstringPattern(String str) {
													        for (int i = str.length() / 2; i >= 1; i--) {
													            if(str.length() % i == 0){
													                StringBuilder tempStr = new StringBuilder();
													                String partStr = str.substring(0, i);
													                for (int j = 0; j < str.length() / i; j++) {
													                    tempStr.append(partStr);
													                }
													                if(tempStr.toString().equals(str)){
													                   tempStr.toString();
													                }
													            }
													        }
													        return "";
													    }
													    
													    static int[] computeLPSArray(String pat ) 
													    { 
													        

													        int M=pat.length();
													        int lps[]=new int [M];
													    	int len = 0; 
													        int i = 1; 
													        lps[0] = 0; 

													  
													        

													        while (i < M) { 
													            if (pat.charAt(i) == pat.charAt(len)) { 
													                len++; 
													                lps[i] = len; 
													                i++; 
													            } 
													            else 

													            { 
													                

													                

													                

													                if (len != 0) { 
													                    len = lps[len - 1]; 
													  
													                    

													                    

													                } 
													                else 

													                { 
													                    lps[i] = len; 
													                    i++; 
													                } 
													            } 
													        } 
													        return lps;
													    } 
													
													static boolean isValid(int a[],int ans,int m,int n) {
														
														for(int i=0;i<n;i++) {
														double d=1.0+(8.0*ans/a[i]);
														
														
															System.out.println(ans+" "+a[i]+" "+(long)(0.5*(1+(int)Math.pow(d,0.5))));
															m-=(long)(0.5*(1+Math.pow(d,0.5)));
															
														
															
														}
														

														return m<=0;
													}
													
													int teams(int a[],int size,int n,int x) {
														
														int i=0;
														for( i=0;i<n;i++) {
															if(a[i]*size>=x)break;
														}
														return(n-i)/size;
													}
													
													static class gift{
														int p;int index;
														
														public gift (int p,int index) {
															
															this.index=index;
															this.p=p;
															

														}
														
													}
													
													static boolean isDup(int a[],int n) {
														HashMap<Integer,Integer> hs=new HashMap<>();
														
														for(int j=0;j<n;j++) {
															
															if(hs.containsKey(a[j])) {
															

																return false;
															}
															hs.put(a[j],1);
														
														}
														return true;
													}
												static 	boolean isVal(int a[],int seg,int n) {
													HashMap<Integer,Integer> hs=new HashMap<>();
													boolean	flag =false;
												outer:	for(int i=0;i<=n-seg;i++) {
														flag =true;
														hs.clear();
														for(int j=0;j<i;j++) {
															
																
																	if(hs.containsKey(a[j])) {
																	

																		flag=false;
																		break;
																	}
																	hs.put(a[j],1);
																
														
														
														
													}
														for(int j=i+seg;j<n;j++) {
												

															
															
															if(hs.containsKey(a[j])) {
																

																	flag=false;
																	break;
																}
																hs.put(a[j],1);
														}		
													if(flag)return flag;	
														
												}
												return flag;	
												}static void findCycle(ArrayList<Integer> adj[],int v,int visited[],boolean visitedc[]) {
														
														
														visited[v]=1;
														visitedc[v]=true;
														
														
														for(int i:adj[v]) {
															 if(visited[i]==1) { 
																	

																	cycle++;}
																
															if(visited[i]==0)findCycle(adj, i, visited,visitedc);
														}
														
														visited[v]=2;
													}
													
													
													static class post{
														
														int pos;int min;int max;
														public post(int min,int max) {
															
															
															this.min=min;
															this.max=max;
															

														}
														
														
													}
													
													
													
													
													static long gcd(long a, long b) 
													{ 
													    if (a == 0) 
													        return b; 
													    return gcd(b % a, a); 
													} 
													  
													

													

													static int printAllDivisors(long arr[], int N) 
													{ 
													    

													    

													    long g = arr[0]; 
													  
													    

													    

													    HashSet<Long> divisors = new HashSet<Long>(); 
													  
													    

													    

													    for (int i = 1; i < N; i++)  
													    { 
													        g = gcd(arr[i], g); 
													    } 
													  
													    

													    

													    for (long i = 1; i * i <= g; i++) 
													    { 
													        if (g % i == 0)  
													        { 
													            divisors.add(i); 
													            if (g / i != i) 
													                divisors.add(g / i); 
													        } 
													    } 
													  
													    

													
													    return divisors.size();
													} 
													
													
													
													
													
													
													
													
													
													
													static class Node{
														
														int p;int c;
														
														public Node(int p,int c) {
															

														
															this.p=p;
															this.c=c;
																
														}
														
														
														
														
														
														
													}
													
													
													
													
													
													
													static class delivery{
														
														
														
														long a;long b;
														public delivery(long a, long b) {
															
															
															this.a=a;
															this.b=b;
															

														}
														
														
													}
																
													public static int removeDuplicateElementsFromArray(int array[], int arrayLength){
												        

												        if (arrayLength==0 || arrayLength==1){
												            return arrayLength;
												        }
												        

												        int[] temp = new int[arrayLength];
												        int j = 0;
												        

												        for (int i=0; i<arrayLength-1; i++){
												            if (array[i] != array[i+1]){
												                temp[j++] = array[i];
												            }
												         }
												        

												        temp[j++] = array[arrayLength-1];
												        

												        for (int i=0; i<j; i++){
												            array[i] = temp[i];
												        }
												        return j;
												    }	
															
															
														static class Naruto{
															
															int a;int i;
															
															public Naruto(int a ,int i) {
																

															this.a=a;
															this.i=i;
															}
															
														}
														
														
														
														
												
														
													static long power1(long x, long y, long p) 
												    { 
												        

												        long res = 1;      
												         
												        

												        

												        x = x % p;  
												  
												       if (x == 0) return 0; 

												  
												        while (y > 0) 
												        { 
												            

												            

												            if((y & 1)==1) 
												                res = (res * x) % p; 
												      
												            

												            

												            y = y >> 1;  
												            x = (x * x) % p;  
												        } 
												        return res; 
												    } 	
										static void dfs(ArrayList<ArrayList<graph>> g,int v,boolean visited[]) {
											
											visited[v]=true;
											l[k]+=1;
											for(graph j:g.get(v)) {
												if(j.c==0) {
													

													if(!visited[j.v])
													dfs(g,j.v,visited);  
												}
												
											}
											
											
										}
													
													
										static class graph{
											int v;int c;
											public graph(int v,int c) {
												

												this.v=v;
												this.c=c;
											
											}
											
										}
													
													
														
													
											static		long fact(long n) {
														
														if(n<=1)return 1;
														else return n*fact(n-1);
													}
													
									 static long maxCrossingSum(long arr[], int l, 
								                                int m, int h) 
								    { 
								        

								       long sum = 0; 
								        long left_sum = Integer.MIN_VALUE; 
								        for (int i = m; i >= l; i--) 
								        { 
								            sum = sum + arr[i]; 
								            if (sum > left_sum) 
								            left_sum = sum; 
								        } 
								  
								        

								        sum = 0; 
								        long right_sum = Integer.MIN_VALUE; 
								        for (int i = m + 1; i <= h; i++) 
								        { 
								            sum = sum + arr[i]; 
								            if (sum > right_sum) 
								            right_sum = sum; 
								        } 
								  
								        

								        

								       

								        return Math.max(left_sum + right_sum, Math.max(left_sum, right_sum)); 
								    } 
								  
								    

								    

								    static long maxSubArraySum(long arr[], int l,  
								                                      int h) 
								    { 
								    

								    if (l == h) 
								        return arr[l]; 
								  
								    

								    int m = (l + h)/2; 
								  
								    
								    return Math.max(Math.max(maxSubArraySum(arr, l, m), 
								                    maxSubArraySum(arr, m+1, h)), 
								                    maxCrossingSum(arr, l, m, h)); 
								    } 
													
													static long abs(long a) {
														return Math.abs(a);
													}
													
													static class seg{
														
														int x;int y;int l;
														public seg(int x,int y,int l) {
															this.x=x;
															this.y=y;
															this.l=l;
															

														}
														
														
													}
												static	boolean isPresent(int j,int p) {
														
														int i=(j/50)%475;
														
														for(int k=0;k<25;k++) {
														    i = (i * 96 + 42)% 475;
														    if(26+i==p)return true;
															}
														return false;
														
													}
																					
													static class Helper{
														int val;int index;
														public Helper(int  val,int index) {
															
															this.val=val;
															this.index=index;
															

														}
													}
												
											
													
									
												    static boolean isPrime(long n) 
												    { 
												        

												        if (n <= 1) 
												            return false; 
												        if (n <= 3) 
												            return true; 
												  
												        

												        

												        if (n % 2 == 0 || n % 3 == 0) 
												            return false; 
												  
												        for (long i = 5l; i * i <= n; i = i + 6) 
												            if (n % i == 0 || n % (i + 2) == 0) 
												                return false; 
												  
												        return true; 
												    } 
											
													      
													    
													    static long power(long x, long y, long p) 
													    { 
													        

													        long res = 1;      
													         
													        

													        

													        x = x % p;  
													  
													       if (x == 0) return 0; 

													  
													        while (y > 0) 
													        { 
													            

													            

													            if((y & 1)==1) 
													                res = (res * x) % p; 
													      
													            

													            

													            y = y >> 1;  
													            x = (x * x) % p;  
													        } 
													        return res; 
													    } 
										
													
													
													
													  static class InputReader {
													        private InputStream stream;
													        private byte[] buf = new byte[1024];
													        private int curChar;
													        private int numChars;
													        private SpaceCharFilter filter;
												
													        public InputReader(InputStream stream) {
													            this.stream = stream;
													        }
												
													        public int read() {
													            if (numChars == -1)
													                throw new InputMismatchException();
													            if (curChar >= numChars) {
													                curChar = 0;
													                try {
													                    numChars = stream.read(buf);
													                } catch (IOException e) {
													                    throw new InputMismatchException();
													                }
													                if (numChars <= 0)
													                    return -1;
													            }
													            return buf[curChar++];
													        }
												
													        public int readInt() {
													            int c = read();
													            while (isSpaceChar(c))
													                c = read();
													            int sgn = 1;
													            if (c == '-') {
												    sgn = -1;
												    c = read();
												}
												int res = 0;
												do {
												    if (c < '0' || c > '9')
												        throw new InputMismatchException();
												    res *= 10;
												    res += c - '0';
												        c = read();
												    } while (!isSpaceChar(c));
												    return res * sgn;
												}
												
												public String readString() {
												    int c = read();
												    while (isSpaceChar(c))
												        c = read();
												    StringBuilder res = new StringBuilder();
												    do {
												        res.appendCodePoint(c);
												        c = read();
												    } while (!isSpaceChar(c));
												    return res.toString();
												}
												
												public boolean isSpaceChar(int c) {
												    if (filter != null)
												        return filter.isSpaceChar(c);
												    return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
													        }
												
													        public String next() {
													            return readString();
													        }
												
													    }
													
													  public interface SpaceCharFilter {
													        public boolean isSpaceChar(int ch);
													    }	
													
													
																						
																						
																						
																			
												}
												    