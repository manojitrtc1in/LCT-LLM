import java.util.*;
import java.io.*;
public class helloworld {
 static long fact[];
 static long max;
 static int ans;
	static class Reader 
    { 
        final private int BUFFER_SIZE = 1 << 16; 
        private DataInputStream din; 
        private byte[] buffer; 
        private int bufferPointer, bytesRead; 
  
        public Reader() 
        { 
            din = new DataInputStream(System.in); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public Reader(String file_name) throws IOException 
        { 
            din = new DataInputStream(new FileInputStream(file_name)); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public String readLine() throws IOException 
        { 
            byte[] buf = new byte[64]; 

            int cnt = 0, c; 
            while ((c = read()) != -1) 
            { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt); 
        } 
  
        public int nextInt() throws IOException 
        { 
            int ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do
            { 
                ret = ret * 10 + c - '0'; 
            }  while ((c = read()) >= '0' && c <= '9'); 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public long nextLong() throws IOException 
        { 
            long ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public double nextDouble() throws IOException 
        { 
            double ret = 0, div = 1; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
  
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
  
            if (c == '.') 
            { 
                while ((c = read()) >= '0' && c <= '9') 
                { 
                    ret += (c - '0') / (div *= 10); 
                } 
            } 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        private void fillBuffer() throws IOException 
        { 
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
            if (bytesRead == -1) 
                buffer[0] = -1; 
        } 
  
        private byte read() throws IOException 
        { 
            if (bufferPointer == bytesRead) 
                fillBuffer(); 
            return buffer[bufferPointer++]; 
        } 
  
        public void close() throws IOException 
        { 
            if (din == null) 
                return; 
            din.close(); 
        } 
    } 
	
	static long getSum(int index , long BITree[]) 
    { 
		
        long  sum = 0; 

      
        

        

    
      
        

        while(index>0) 
        { 
            

            

            sum += BITree[index]; 
      
            

            

            index -= index & (-index); 
        } 
        return sum; 
    } 
  
	static int getMid(int s, int e) 
    { 
        return s + (e - s) / 2; 
    } 
  
    
    static int MaxUtil(int[] st, int ss, int se,  
                        int l, int r, int node)  
    { 
          
        

        

        

        if (l <= ss && r >= se) 
            return st[node]; 
  
        

        

        if (se < l || ss > r) 
            return -1; 
  
        

        

        int mid = getMid(ss, se); 
  
        return Math.max(MaxUtil(st, ss, mid, l, r, 2 * node + 1), 
                    MaxUtil(st, mid + 1, se, l, r, 2 * node + 2)); 
    } 
  
    
    static void updateValue(int arr[], int[] st, int ss, 
                    int se, int index, int value, int node) 
    { 
        if (index < ss || index > se) 
        { 
            System.out.println("Invalid Input"); 
            return; 
        } 
  
        if (ss == se) 
        { 
  
            

            arr[index] = value; 
            st[node] = value; 
        }  
        else
        { 
            int mid = getMid(ss, se); 
  
            if (index >= ss && index <= mid) 
                updateValue(arr, st, ss, mid, index, value, 2 * node + 1); 
            else
                updateValue(arr, st, mid + 1, se, index, value, 2 * node + 2); 
  
            st[node] = Math.max(st[2 * node + 1], st[2 * node + 2]); 
        } 
        return; 
    } 
  
    

    

    static int getMax(int[] st, int n, int l, int r) 
    { 
  
        

        if (l < 0 || r > n - 1 || l > r)  
        { 
            System.out.printf("Invalid Input\n"); 
            return -1; 
        } 
  
        return MaxUtil(st, 0, n - 1, l, r, 0); 
    } 
  
    

    

    

    static int id0(int arr[], int ss, 
                        int se, int[] st, int si)  
    { 
          
        

        

        if (ss == se)  
        { 
            st[si] = arr[ss]; 
            return arr[ss]; 
        } 
  
        

        

        

        int mid = getMid(ss, se); 
  
        st[si] = Math.max(id0(arr, ss, mid, st, si * 2 + 1), 
                id0(arr, mid + 1, se, st, si * 2 + 2)); 
  
        return st[si]; 
    } 
  
    
    static int[] constructST(int arr[], int n) 
    { 
  
        

        int x = (int) Math.ceil(Math.log(n) / Math.log(2)); 
  
        

        int max_size = 2 * (int) Math.pow(2, x) - 1; 
  
        

        int[] st = new int[max_size]; 
  
        

        id0(arr, 0, n - 1, st, 0); 
  
        

        return st; 
    } 
    public static void updateBIT(int n, int index,  
                                        long val , long BITree[] ) 
    { 
        

        

       
        

        while(index <= n) 
        { 
        

        BITree[index] += val; 
      
        

        

        index += index & (-index); 
        } 
    } 
    static long mod = 1000000007;
   static long pow(long a , long b , long c)
   {
	   
	   if(b==0)
		   return 1;
	   
	   long ans = pow(a,b/2,c);
	   if(b%2 == 0)
		   return ans*ans%c;
	   
	   return ans*ans%c*a%c;
   }
   
   static long modInverse(long a , long b)
   {
	   return pow(a,b-2,mod);
   }
   
   
   static double d(int x1 , int y1 , int x2 , int y2)
   {
	   double d1 = x1-x2;
	   double d2 = y1-y2;
	   
	   return Math.sqrt(d1*d1-d2*d2);
   }
  

static int low[];
static int p[];
static int parent(int x , int k , int dp[][])
{
	if(k==0)
		return x;
while(k > 0)
{
	if(x == -1)
		break;
	
	int up = low[k];
	k -= p[up];
	x = dp[x][up];
}
return x;
}


static void d(int n , LinkedList<Integer> arr[] , boolean visited[] , int dp[][] , int h[] , int p,int lev)
{
	visited[n] = true;
	int lim = low[visited.length];
	
	dp[n][0] = p;
	int temp = n;
	for(int j = 1 ; j <= lim ; j++)
	{
		if(dp[n][j-1] == -1)
			break;
		
		dp[n][j] = dp[dp[n][j-1]][j-1];
	}
	
	h[n] = lev;
	
	for(Integer i : arr[n])
	{
		if(!visited[i])
		{
			d(i,arr,visited,dp,h,n,lev+1);
		}
	}
}

static int lca(int a , int b , int dp[][] , int h[])
{
	if(h[a] > h[b])
	{
		a = parent(a,h[a]-h[b],dp);
		
	}
	
	else if(h[b] > h[a])
	{
		b = parent(b,h[b]-h[a],dp);
	}
	
	if(a==b)
		return a;
	
	
	int l = 1 , r = h.length;
	
	while(l < r)
	{
		int mid = (l+r)/2;
		if(parent(a,mid,dp) == parent(b,mid,dp))
			r = mid;
		
		else
			l = mid+1;
	}
	
	return parent(a,l,dp);
}


static int check(int s , int f , int t , int dp[][] , int h[])
{
	int sf = lca(s,f,dp,h);
	
	if(lca(sf,t,dp,h) != sf)
	{
		
		
		return h[f]-h[sf]+1;
		
		
	}
	
	if(sf != s && sf != f)
	{
		int ans =  h[lca(s,t,dp,h)]-h[lca(s,f,dp,h)]+h[f]-h[lca(f,t,dp,h)]+1;
		
		
		
		return ans;
	}
	
	else
	{
		int ans = -1;
		
		if(sf == s)
		ans =  h[f]-h[lca(f,t,dp,h)]+1;
		
		else
		ans =   h[lca(s,t,dp,h)] - h[f]+1;
		
		
		
		return ans;
	}
}

static void dfs(int n , LinkedList<Integer> arr[] , boolean visited[] ,int dp[][][][], int zer , int one , int h[])
{
	visited[n] = true;
	ArrayList<Integer> temp = new ArrayList<Integer>();
	
	for(Integer i : arr[n])
	{
		if(!visited[i])
		{
			dfs(i,arr,visited,dp,zer,one,h);
			h[n] += h[i];
			temp.add(i);
		}
	}
	h[n]++;
	int two = visited.length-1-zer-one;
	
	for(int z = 0 ; z <= zer ; z++)
	{
		for(int o = 0 ; o <= one ; o++)
		{
			if(h[n]-z-o <= two && h[n]-z-o >= 0)
			{
				

			if(z > 0)
			{
				int mn = 1 , mn2 = 1;
				for(Integer i : temp)
				{
				    mn = Math.min(mn, dp[i][z-1][o][1]);
				    mn2 = Math.min(mn2, dp[i][z-1][o][0]);
				}
			
			
			if(mn == 1 || mn2 == 1)
				dp[n][z][o][0] = 1;
			
			}
			
			
			if(o > 0)
			{
				int mn1 = 1 , mn2 = 1 , mn3 = 1;
				for(Integer i : temp)
				{
					mn1 = Math.min(mn1, dp[i][z][o-1][0]);
				    mn2 = Math.min(mn2, dp[i][z][o-1][2]);
				    mn3 = Math.min(mn3, dp[i][z][o-1][1]);
				}
				
				if(mn1 == 1 || mn2 == 1 || mn3 == 1)
					dp[n][z][o][1] = 1;
				
				
			}
			
			
			if(h[n]-z-o > 0)
			{
				int mn1 = 1 , mn2 = 1;
				for(Integer i : temp)
				{
					mn1 = Math.min(mn1, dp[i][z][o][1]);
				   mn2 = Math.min(mn2, dp[i][z][o][2]);
				}
				
				if(mn1 == 1 || mn2 == 1)
					dp[n][z][o][2] = 1;
			}
			
			}
			
		}
	}
}
public static void main(String []args) throws IOException
{
     Reader sc = new Reader();
     int n = sc.nextInt();
     int len = sc.nextInt();
     int arr[] = new int[n];
     int pp = 0 , nn = 0;
     for(int i = 0 ; i < n ; i++)
     {
    	 arr[i] = sc.nextInt();
    	 if(arr[i] >= 0)
    		 pp++;
    	 
    	 else
    		 nn++;
     }
     int k = sc.nextInt();
     int ppp[] = new int[pp];
     int nnn[] = new int[nn];
     pp = 0 ; nn = 0;
     for(int i = 0 ; i < n ; i++)
     {
    	 if(arr[i] >= 0)
    		 ppp[pp++] = arr[i];
    	 
    	 else
    		 nnn[nn++] = (-arr[i]);
     }
     
     
     Arrays.sort(ppp);
     Arrays.sort(nnn);
     
     
    
     HashMap<Integer,Integer> pmap = new HashMap<Integer,Integer>();
     HashMap<Integer,Integer> nmap = new HashMap<Integer,Integer>();
     
     HashMap<Integer,Integer> revp = new HashMap<Integer,Integer>();
     HashMap<Integer,Integer> revn = new HashMap<Integer,Integer>();
     
     int i = 0;
     int tot = 1;
     while(i < pp)
     {
    	 int j = i;
    	 while(j+1 < pp && ppp[j] == ppp[j+1])
    	 {
    		 j++;
    	 }
    	 pmap.put(ppp[i],tot);
    	 revp.put(tot,ppp[i]);
    	 tot++;
    	 i = j+1;
     }
     i = 0;
     tot = 1;
     while(i < nn)
     {
    	 int j = i;
    	 while(j+1 < nn && nnn[j] == nnn[j+1])
    	 {
    		 j++;
    	 }
    	 nmap.put(nnn[i],tot);
    	 revn.put(tot,nnn[i]);
    	 tot++;
    	 i = j+1;
     }
     
    
     long ans = 0 , sum = 0;
     long cntpos[] = new long[100005];
     long cntneg[] = new long[100005];
     
     long sumpos[] = new long[100005];
     long sumneg[] = new long[100005];
     
    
     for(i = 0 ; i < len ; i++)
     {
    	if(arr[i] >= 0)
    	{
    		updateBIT(100004,pmap.get(arr[i]),1,cntpos);
    		updateBIT(100004,pmap.get(arr[i]),arr[i],sumpos);
    	}
    	
    	else
    	{
    		
    		updateBIT(100004,nmap.get(-arr[i]),1,cntneg);
    		updateBIT(100004,nmap.get(-arr[i]),-arr[i],sumneg);
    	}
    	
    	sum += arr[i];
     }
     for(i = 0 ; i < n ; i++)
     {
         long possum = 0 , id1 = 0;
         if(k > 0)
         {
        	if(getSum(100004,cntpos) <= k)
        	{
        		possum = getSum(100004,sumpos);
        	}
        	
        	else
        	{
        		int l = 1 , r = 100000;
        		while(l <= r)
        		{
        			int mid = (l+r)/2;
        			if(getSum(100004,cntpos)-getSum(mid-1,cntpos) >= k)
        				l = mid+1;
        			
        			else
        				r = mid-1;
        		}
        		
        		possum = getSum(100004,sumpos)-getSum(r-1,sumpos);
        		
        		long del = -k+(getSum(100004,cntpos)-getSum(r-1,cntpos));
        		possum -= del*(long)revp.get(r);
        	}
        	
        	
        	
        	
        	if(getSum(100004,cntneg) <= k)
        	{
        		id1 = getSum(100004,sumneg);
        	}
        	
        	else
        	{
        		int l = 1 , r = 100000;
        		while(l <= r)
        		{
        			int mid = (l+r)/2;
        			if(getSum(100004,cntneg)-getSum(mid-1,cntneg) >= k)
        				l = mid+1;
        			
        			else
        				r = mid-1;
        		}
        		
        		id1 = getSum(100004,sumneg)-getSum(r-1,sumneg);
        		long del = -k+(getSum(100004,cntneg)-getSum(r-1,cntneg));
        		id1 -= del*(long)revn.get(r);
        	}
         }
        

         ans = Math.max(ans,Math.abs(sum-2*possum));
         ans = Math.max(ans,Math.abs(sum+2*id1));
         
         if(i + len >= n)
        	 break;
         
          if(arr[i] >= 0)
          {
        	  updateBIT(100004,pmap.get(arr[i]),-1,cntpos);
        	  updateBIT(100004,pmap.get(arr[i]) , -arr[i] , sumpos);
          }
          
          else
          {
        	  updateBIT(100004,nmap.get(-arr[i]),-1,cntneg);
        	  updateBIT(100004,nmap.get(-arr[i]) , arr[i] , sumneg);
          }
          
          
          if(arr[i+len] >= 0)
          {
        	  updateBIT(100004,pmap.get(arr[i+len]),1,cntpos);
        	  updateBIT(100004,pmap.get(arr[i+len]) , arr[i+len] , sumpos);
          }
          
          else
          {
        	  updateBIT(100004,nmap.get(-arr[i+len]),1,cntneg);
        	  updateBIT(100004,nmap.get(-arr[i+len]) , -arr[i+len] , sumneg);
          }
          
          sum -= arr[i];
          sum += arr[i+len];
     }
     System.out.println(ans);
}
}