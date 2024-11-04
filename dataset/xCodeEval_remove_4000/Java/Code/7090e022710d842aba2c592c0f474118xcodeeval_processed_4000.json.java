import java.io.*;
import java.util.*;

public class CodeChef2 {
   
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
	










































































































	
	static class Pair{
		int dest;
		long cost;
		
		Pair(int y,long v){
			this.dest=y;
			this.cost=v;
		}

		@Override
		public String toString() {
			return "(" + dest +" "+ cost+")";
		} 
		
		
	}

	static int MAX =100001;
    
    

    

    

    

    

    static long[][]lookup = new long[MAX][22];
      
    static void id1(long[] arr, long n)
    {
        

        for (int i = 0; i < n; i++)
            lookup[i][0] = arr[i];
      
        

        for (int j = 1; (1 << j) <= n; j++) {
      
            

            

            for (int i = 0; (i + (1 << j) - 1) < n; i++) {
      
                

                

                if (lookup[i][j - 1] > lookup[i + (1 << (j - 1))][j - 1])
                    lookup[i][j] = lookup[i][j - 1];
                else
                    lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
            }
        }
    }
      
    

    static int query(int L, int R)
    {
        

        

        

        

        int j = (int)Math.log(R - L + 1);
      
        

        

        

        

        if (lookup[L][j] >= lookup[R - (1 << j) + 1][j])
            return (int) lookup[L][j];
      
        else
            return (int) lookup[R - (1 << j) + 1][j];
    }
	
    public static void main(String[] args) throws Exception {
        FastReader sc=new FastReader();
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
        
        


















        


        int t=sc.nextInt();
        long M=1000000007l;
        int po=1;
                
        outer:while(t-- >0) {
        	long n=sc.nextLong();

        	long[] arr=new long[(int) n];
        	ArrayList<Long> odd=new ArrayList<>();
        	ArrayList<Long> even=new ArrayList<>();
         	
        	for(int i=0;i<n;i++) {
        		arr[i]=sc.nextLong();
        		if(arr[i]%2 == 0) {
        			even.add(arr[i]);
        		}else {
        			odd.add(arr[i]);
        		}
        	}
        	
        	int i=0;
        	while(i<odd.size()) {
        		bw.append(odd.get(i)+" ");
        		i++;
        	}
        	i=0;
        	while(i<even.size()) {
        		bw.append(even.get(i)+" ");
        		i++;
        	}
        	bw.append("\n");
        }
        bw.close();
    }

	private static void rightmax(long[] arr, long n,int[] res,int[] rightmax) {
    	
		Deque<Integer> stack=new ArrayDeque<>();
		
		stack.clear();
		for(int i=(int) (n-1);i>=0;i--) {
			while(!stack.isEmpty() && arr[stack.peek()] <= arr[i]) {
				stack.pop();
			}
			
			rightmax[i]=(stack.isEmpty()?Integer.MAX_VALUE:stack.peek());
			stack.addFirst(i);
		}
	}
	
	

	private static boolean id3(long[] arr, int min) {
		reverse(arr,0,min-1);
		reverse(arr,min,arr.length-1);
		reverse(arr,0,arr.length-1);
		
		if(isSorted(arr)) {
			return true;
		}
		return false;
	}

	private static boolean isSorted(long[] arr) {
		for(int i=1;i<arr.length;i++) {
			if(arr[i] < arr[i-1]) {
				return false;
			}
		}
		return true;
	}

	private static int countDigit(long x) {
		int count=0;
		while(x > 0) {
			x/=10;
			count++;
		}
		return count;
	}

	private static boolean isSub(String s, String c) {
		int l=0;
		
		for(int i=0;i<s.length();i++) {
			if(l < c.length() && c.charAt(l)==s.charAt(i)) {
				l++;
			}
			if(l==c.length()) {
				break;
			}
		}
		if(l==c.length()) {
			return true;
		}
		return false;
	}


	private static long power(long a, long d,long n) {
		long res=1;
		while(d != 0) {
			if((d&1)==1) {
				res=(res*a)%n;
			}
			d>>=1;
			a=(a*a)%n;
		}
		return res;
	}

	private static void reverse(long[] arr,int l,int m) {
		while(l<m) {
			long temp=arr[l];
			arr[l]=arr[m];
			arr[m]=temp;
			l++;
			m--;
		}
	}

	
	 static int UpperBound(ArrayList<Integer> a, int x) {

		    int l=-1,r=a.size();
		    while(l+1<r) {
		       int m=(l+r)>>>1;
		       if(a.get(m)<=x) l=m;
		       else r=m;
		    }
		    return l+1;
	 }

	private static void printMat(int[][] dp) {
		
    	System.out.println("--------------------------------------------------------------------");
		for(int i=0;i<dp.length;i++) {
    		for(int j=0;j<dp[0].length;j++) {
    			System.out.print(dp[i][j]+" ");
    		}
    		System.out.println();
    	}
		System.out.println("--------------------------------------------------------------------");
	}
   
	private static int id0(long n) {
		long x=Long.id0(n);
		int c=0;
		while(x >0) {
			x=x/2;
			c++;
		}
		return c-1;
	}
	
	private static int bitcount(long l) {
		int count=0;
		
    	while(l>0) {
			l-=(l&(-l));
			count++;
		}
		return count;
	}


	private static void bfs(HashMap<Integer, HashSet<Integer>> tree, int start) {
    	Queue<Integer> q=new LinkedList<>();
		q.offer(start);
		HashSet<Integer> visited=new HashSet<>();
		
		System.out.print(q.peek()+"\n");
		
		while(!q.isEmpty()) {
			int parent=q.poll();
			
			if(visited.contains(parent)) {
				continue;
			}
			visited.add(parent);
			int flag=0;

			for(int child:tree.get(parent)) {
				if(!visited.contains(child)) {
					q.offer(child);
					System.out.print(child+" ");
					flag=1;
				}
			}
			
			if(flag==0) {
				continue;
			}
			System.out.println();
		}
	}

	static int par;
	private static HashMap<Integer, HashSet<Integer>> id2(StringTokenizer st) {
		Queue<Integer> q=new LinkedList<>();
		
		HashMap<Integer, HashSet<Integer>> tree=new HashMap<>();
		q.offer(Integer.parseInt(st.nextToken()));
		
		par=q.peek();
		
		while(!q.isEmpty()) {
			int parent=q.poll();
			
			if(!tree.containsKey(parent)) {
				tree.put(parent, new HashSet<Integer>());
			}
			
			int left=-1,right=-1;
			
			if(st.hasMoreElements())
				left=Integer.parseInt(st.nextToken());
			
			if(st.hasMoreElements())
				right=Integer.parseInt(st.nextToken());
			
			if(left != -1) {
				tree.get(parent).add(left);
				if(!tree.containsKey(left)) {
					tree.put(left, new HashSet<Integer>());
				}
				tree.get(left).add(parent);
				q.offer(left);
			}
			
			if(right != -1) {
				tree.get(parent).add(right);
				if(!tree.containsKey(right)) {
					tree.put(right, new HashSet<Integer>());
				}
				tree.get(right).add(parent);
				q.offer(right);
			}
			
		}
		tree.remove(-1);
		return tree;
	}






	private static int containsString(String s1,String s2) {
		String s=s1+"
		int[] z=getZfunc(s);
		
		boolean flag=false;
		for(int i=0;i<s.length();i++) {
			if(z[i]==s1.length()) {
				flag=true;
			}
		}
		int count=0;
		
		for(int i=s1.length();i<z.length;i++) {


			if(z[i]==s1.length()) {
				count++;
			}
		}


		return count;
	}


	private static int[] getZfunc(String s) {
		int[] z=new int[s.length()];
		 int l=0,r=0;
		 
		 for(int i=1;i<s.length();i++) {
			 
			 if(i <= r) {
				 z[i]=Math.min( z[i-l] , r-i+1);
			 }
			 while(i+z[i] < s.length() && s.charAt(z[i])==s.charAt(i+z[i])) {
				 z[i]++;
			 }
			 if(i+z[i] -1 > r) {
				 l=i;
				 r=i+z[i]-1;
			 }
			 
		 }
		return z;
	}


	
	private static long ceil(long n,long k) {
		long ans;
		if(n%k==0) {
			ans=n/k;
		}else {
			ans=n/k+1;
		}
		return ans;
	}


	static ArrayList<Integer> getDivisor(int n){
    	ArrayList<Integer> div=new ArrayList<>();
    	
        for (int i=1; i*i <= n; i++) 
        { 
            if (n%i==0) 
            { 
                if (n/i == i) 
                    div.add(i); 
                else { 
                    div.add(i);
                    div.add(n/i);
                }
            } 
        }
        
        return div;
    }
	
    static int gcd(long x,long y) {
    	return (int) (y==0?x:gcd(y,x%y));
    }
    
	static int MAXN = 1000001;
	static int[] spf=new int[MAXN];
	
    static void sieveSmallestFactor() 
    { 
        spf[1] = 1;
        
        for (int i=2; i<MAXN; i++) 
        	spf[i] = i;
        
        for (int i=4; i<MAXN; i+=2) 
            spf[i] = 2; 
       
        
        for (int i=3; i*i<MAXN; i++) 
        { 
            if (spf[i] == i) 
            { 
                for (int j=i*i; j<MAXN; j+=i) 
                    if (spf[j]==j) 
                        spf[j] = i; 
            } 
        } 
    } 
    
    
	private static HashMap<Integer,Integer> PrimeFactorizationmap(long n) {
		int count=0;
		
		HashMap<Integer,Integer> factors=new HashMap<>();
		if(n==1) {
			factors.put( 1,1);
			return factors;
		}else {
			for(long i=2; i*i <= n ;i++) {
				long z=n;
				if(z%i==0) {
					count=0;
					while(z%i==0) {
						count++;
						z=z/i;
					}
					factors.put((int) (i+0),count);
				}
			}
			if(n>1) {
				factors.put((int) (n+0),1);
			}
		}
		return factors;
	}
	

    
    static HashMap<Integer,Integer> getprimeFactors(int n) 
    {
        HashMap<Integer,Integer> ret = new HashMap<>();
        while (n > 1) 
        { 
        	if(ret.containsKey(spf[n])) {
        		ret.put(spf[n],ret.get(spf[n])+1);
        	}else {
        		ret.put(spf[(int) n],1);
        	}
            n = n / spf[n]; 
        }
        
        return ret; 
    }
    
    static ArrayList<Integer> getPrimeSieve(){
		int primesieve[]=new int[1000005];
		
		Arrays.fill(primesieve,0);
		
		for(int i=2;i*i<primesieve.length;i++) {
			if(primesieve[i]==0)	
				for(int j=i*i;j<primesieve.length;j+=i) {	
						primesieve[j]=1;
				}
		}
		
		ArrayList<Integer> prime=new ArrayList<>();
		for(int i=2;i<primesieve.length;i++) {
			if(primesieve[i]==0) {
				prime.add(i);
			}
		}
		return prime;
    }
    
    
    
    
	private static boolean checkPrimeRM(long n,int k) {
		if(n<=4) {
			return n==2||n==3;
		}
		
		int s=0;
		long d=n-1;
		
		while((d&1) != 1) {
			d=d/2;
			s++;
		}
		
		for(int i=0;i<k;i++) {
			long a=2+(int)Math.random()*(n-4);
			if(isComposite(a,s,d,n)) {
				return false;
			}
		}

		return true;
	}

	private static boolean isComposite(long a, int s, long d, long n) {
		long x=power(a,d,n);
		
		if(x==1 || x==n-1) {
			return false;
		}
		
		for(int i=0;i<s;i++){
			if(x%(n-1)==0) {
				return false;
			}
			x=(x*x)%n;
		}
		
		return true;
	}
    
    public static HashSet<Long> getPrimeLtoR(int l,int r,List<Integer> prime) {
		if(l==1) l++;
		
		int[] arr=new int[r-l+1];
		
		Arrays.fill(arr,0);
		
		for(int i: prime ){

			if(i*i<=r) {
				
				int j=(l/i)*i;
				if(j<l) 
					j+=i;
				for(;j<=r;j+=i) {
					if(j!=i)
						arr[j-l]=1;
				}
			}else {
				break;
			}
			
		}
		
		HashSet<Long> primeLtoR=new HashSet<>();
		
		for(int i=0;i<arr.length;i++) {
			if(arr[i]==0) {
				primeLtoR.add((i+l+0l));
			}
		}
		return primeLtoR;
	}
}