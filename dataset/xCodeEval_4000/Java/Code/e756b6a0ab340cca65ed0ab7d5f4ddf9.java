import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.*; 
import java.util.StringTokenizer; 
import java.io.PrintWriter;
import java.io.*;
import java.util.stream.Collectors.*;
import java.lang.*;
import static java.util.stream.Collectors.*;
import static java.util.Map.Entry.*;
public class Ideo
{ 
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
   
static int power(int x,int y) 
{ 
    int res = 1;      

  
      

                

  
    while (y > 0) 
    { 
        

        if (y%2==1) 
            res = (res*x); 
  
        

        y = y>>1; 

        x = (x*x);   
    } 
    return res; 
} 
 
 static long gcd(long a,long b) 
    { 
        if (a == 0) 
            return b; 
        return gcd(b % a, a); 
    } 
 
 
  static boolean compareSeq(char[] S, int x, int y, int n) 
    { 
        for (int i = 0; i < n; i++)
         {
 
            if (S[x] < S[y]) 
               return true;
            else if (S[x] > S[y]) 
                return false; 
            x = (x + 1) % n; 
            y = (y + 1) % n; 
        } 
        return true; 
    } 
 
    static void build(long[] sum,int[] arr,int n)
    {
      for(int i=0;i<(1<<n);i++)
      {
        long total=0;
        for(int j=0;j<n;j++)
        {
          if((i & (1 << j)) > 0)
            total+=arr[j];
        }
 
        sum[i]=total;
      }
    }
 
 
     static int count(long arr[], long x, int n) 
       {
 
        int l=0;
        int h=n-1;
 
        int res=-1;
        int mid=-1;
        while(l<=h)
        {
          mid=l+(h-l)/2;
          if(x==arr[mid])
          {
            res=mid;
            h=mid-1;
          }
          else if(x<arr[mid])
            h=mid-1;
          else
            l=mid+1;
        }
 
        if(res==-1)
          return 0;
 
        

 
        int res1=-1;
        l=0;
        h=n-1;
        while(l<=h)
        {
          mid=l+(h-l)/2;
          if(x==arr[mid])
          {
            res1=mid;
            l=mid+1;
          }
          else if(x<arr[mid])
            h=mid-1;
          else
            l=mid+1;
        }
 
 
 
        if(res1==-1)
          return 0;
        if(res!=-1 && res1!=-1)
          return (res1-res+1);
 
        return 0;
 
       } 
 
       static int parity(int a)
       {
    a^=a>>16;
    a^=a>>8;
    a^=a>>4;
    a^=a>>2;
    a^=a>>1;
    return a&1;
  }

static int power(int x, int y, int m)  
    { 
        if (y == 0) 
            return 1; 
          
        int p = power(x, y / 2, m) % m; 
        p = (p * p) % m; 
      
        if (y % 2 == 0) 
            return p; 
        else
            return (x * p) % m; 
    } 

 
static int[] product(int[] nums) {
    int[] result = new int[nums.length];
 
    int[] t1 = new int[nums.length];
    int[] t2 = new int[nums.length];
 
    t1[0]=1;
    t2[nums.length-1]=1;
 
    

    for(int i=0; i<nums.length-1; i++){
        t1[i+1] = nums[i] * t1[i];
    }
 
    

    for(int i=nums.length-1; i>0; i--){
        t2[i-1] = t2[i] * nums[i];
    }
 
    for(int i=0;i<nums.length;i++)
      {
        System.out.print(t1[i]+" "+t2[i]);
        System.out.println();
      }
 
    

    for(int i=0; i<nums.length; i++){
        result[i] = t1[i] * t2[i];
    }
 
    return result;
}
 
static int getsum(int[] bit,int ind)
{
  int sum=0;
  while(ind>0)
  {
    sum+=bit[ind];
    ind-= ind & (-ind);
  }
 
  return sum;
}
 
static void update(int[] bit,int max,int ind,int val)
{
  while(ind<=max)
  {
    bit[ind]+=val;
    ind+= ind & (-ind);
  }
}
 
    

 
    static boolean check(long mid,long a,long b)
    {
      long count=1;
      while(count<=mid)
      {
        count++;
        if(a<b)
          a+=count;
        else
          b+=count;
 
        if(a==b)
          return true;
      }
        return false;
    }
 
    static class aksh implements Comparable<aksh>
    {
      int p;
      int q;
 
      public aksh(int p,int q)
      {
        this.p=p;
        this.q=q;
      }
 
      public int compareTo(aksh o)
      {
        if(p!=o.p)
          return p-o.p;
        else
          return q-o.p;
      }
    }
    static int get(int arr[], int n) 
    { 
        int result = 0; 
        int x, sum; 
          
        

        for(int i=0; i<32; i++) 
        { 
            

            

            sum = 0; 
            x = (1 << i); 
            for(int j=0; j<n; j++) 
            { 
                if((arr[j] & x)!=0) 
                sum++; 
            } 
            

            

            if ((sum % 3)!=0) 
            result |= x; 
        } 
        return result; 
    } 
    
 
 
    static boolean isPrime(int n)  
    {  
        

        if (n <= 1) return false;  
        if (n <= 3) return true;  
          
        

        

        if (n % 2 == 0 || n % 3 == 0) return false;  
          
        for (int i = 5; i * i <= n; i = i + 6)  
            if (n % i == 0 || n % (i + 2) == 0)  
            return false;  
          
        return true;  
    }  
      
    static int nextPrime(int N)  
    {  
      
        

        if (N <= 1)  
            return (2-N);  
      
        int prime = N;  
        boolean found = false;  
      
        

        

        while (!found)  
        {  
            if (isPrime(prime))  
                {
                  found = true;
                  break;
                }  
 
            prime++;
        }  
      
        return (prime-N);  
    }  
 
 
    static long product(long x) 
{ 
    long prod = 1; 
    while (x > 0)  
    { 
        prod *= (x % 10); 
        x /= 10; 
    } 
    return prod; 
} 
  




static long findNumber(long l, long r) 
{ 
    

    

    String b = Long.toString(r); 
  
    

    long ans = r; 
    for (int i = 0; i < b.length(); i++)  
    { 
        if (b.charAt(i) == '0') 
            continue; 
  
        

        

        

        char[] curr = b.toCharArray(); 
        curr[i] = (char)(((int)(curr[i] -  
                    (int)'0') - 1) + (int)('0')); 
  
        

        

        for (int j = i + 1; j < curr.length; j++) 
            curr[j] = '9'; 
  
        

        int num = 0; 
        for (int j = 0; j < curr.length; j++) 
            num = num * 10 + (curr[j] - '0'); 
  
        

        

        if (num >= l && product(ans) < product(num)) 
            ans = num; 
    } 
  
    return product(ans); 
} 
 
static long mod=998244353;
 
static long pow(long in, long pow) {
    if(pow == 0) return 1;
    long out = pow(in, pow / 2);
    out = (out * out) % mod;
    if(pow % 2 == 1) out = (out * in) % mod;
    return out;
  }
  static long inv(long in) {
    return pow(in, mod - 2);
  }
 
  static void swap(int x,int y)
  {
    int temp=x;
    x=y;
    y=temp;
  }
 
  static int[] par;
  static int[] size;
  static int find(int i) 
  {
     if (par[i] == i)
      return i;
 
    return par[i] = find(par[par[i]]);
  }
 
  static void union(int x, int y) 
  {
      x = find(x);
      y = find(y);
      if (x == y)
        return;
      if (size[x] < size[y])
        swap(x, y);
 
      par[y] = x;
      size[x] += size[y];
    }
 
 
    static void multisourcebfs(long[] arr,int n,int m)
    {
      

      HashMap<Long,Long> dis=new HashMap<>();
      Queue<Long> q=new LinkedList<>();
 
      for(int i=0;i<arr.length;i++)
      {
        dis.put(arr[i],(long)0);
        q.add(arr[i]);
        

      }
 
      long[] res=new long[m];
      long ans=0;
      int k=0;
      while(!q.isEmpty())
      {
        if(k==m)
          break;
        long x=q.remove();
        if(dis.get(x)!=0)
        {
          ans+=dis.get(x);
          res[k]=x;
          k++;
        }
 
        if(dis.get(x-1)==null)
        {
          dis.put(x-1, dis.get(x)+1);
          q.add(x-1);
          

        }
 
        if(dis.get(x+1)==null)
        {
          dis.put(x+1, dis.get(x)+1);
          q.add(x+1);
          

        }
      }
 
      System.out.println(ans);
 
      for(int i=0;i<m;i++)
        System.out.print(res[i]+" ");
 
    }
 
    static int x; 
    static int maxcount=0;
    static void dfs(int node,int par,int dist)
    {
        if(dist>=maxcount)
        {
           maxcount=dist;
           x=node;
        }
 
        List<Integer> l = adj[node]; 
        for(Integer i: l)
        {
          if(i!=par)
          dfs(i,node,dist+1);
        }
    }

    static boolean func(int mid, aksh[] a, int n)
    {
      for(int i=0;i<n;i++)
      {
        

        int x=a[i].p;
        int y=a[i].p;

        if(a[i].q!=0)
          x=(int)(a[i].p/a[i].q);
        if((n-a[i].q-1)!=0)
           y=(int)(a[i].p/(n-a[i].q-1));
        int temp=Math.min(x,y);
         if(temp<mid)
          return false;
      }
      return true;
    }

    static int h;
    static int w;
    static int bfs(char[][] ch,int i,int j)
    {
        Queue<aksh> q=new LinkedList<>();
        q.add(new aksh(i,j));

        int[][] dis=new int[h][w];
        int[][] vis=new int[h][w];
        vis[i][j]=1;
        dis[i][j]=0;
 
        while(!q.isEmpty())
        {
          aksh arr=q.poll();
          int x1=arr.p;
          int y1=arr.q;
 
          if((x1-1)>=0 && ch[x1-1][y1]!='#' && vis[x1-1][y1]==0)
          {
            vis[x1-1][y1]=1;
            q.add(new aksh(x1-1, y1));
            dis[x1-1][y1]=Math.max(dis[x1-1][y1],dis[x1][y1]+1);
          }
 
          if((x1+1)<h && ch[x1+1][y1]!='#' && vis[x1+1][y1]==0)
          {
            vis[x1+1][y1]=1;
            dis[x1+1][y1]=Math.max(dis[x1+1][y1],dis[x1][y1]+1);
            q.add(new aksh(x1+1, y1));
          }
 
          if((y1-1)>=0 && ch[x1][y1-1]!='#' && vis[x1][y1-1]==0)
          {
            vis[x1][y1-1]=1;
            dis[x1][y1-1]=Math.max(dis[x1][y1-1],dis[x1][y1]+1);
            q.add(new aksh(x1,y1-1));
          }
 
    
          if((y1+1)<w && ch[x1][y1+1]!='#' && vis[x1][y1+1]==0)
          {
            vis[x1][y1+1]=1;
            dis[x1][y1+1]=Math.max(dis[x1][y1+1],dis[x1][y1]+1);
            q.add(new aksh(x1,y1+1));
          }
        }
        int max=Integer.MIN_VALUE;

        for(int x=0;x<h;x++)
        {
          for(int y=0;y<w;y++)
            max=Math.max(dis[x][y],max);
        }

        return max;
    }

    static final long INF = Long.MAX_VALUE/5;
    static ArrayList<Integer>[] adj;
    public static void main(String args[] ) throws Exception 
    {
        
 
        FastReader sc=new FastReader();
        int t=sc.nextInt();

        while(t-->0)
        {

          long n=sc.nextLong();
          ArrayList<Long> arr=new ArrayList<>();

          while(n>0)
          {
            arr.add(n%3);
            n/=3;
          }

          Collections.reverse(arr);

          for(int i=0;i<arr.size();i++)
          {
            if(arr.get(i)==2)
            {
              int ok=0;
              for(int j=i-1;j>=0;j--)
              {
                if(arr.get(j)==1)
                {
                  continue;
                }

                


                arr.set(j,1L*1);
                ok=1;

                for(int k=j+1;k<arr.size();k++)
                {
                  arr.set(k,1L*0);
                }
                break;
              }

              if(ok==0)
              {
                Collections.reverse(arr);
                arr.add(1L*1);
                

                Collections.reverse(arr);

                for(int j=1;j<arr.size();j++)
                  arr.set(j,1L*0);
              }
            }
          }

          long ans=0;
          for(int i=0;i<arr.size();i++)
          {
            

            ans=ans*3 + arr.get(i);
          }

          System.out.println(ans);

        }
       
        
        }
 
    }
 