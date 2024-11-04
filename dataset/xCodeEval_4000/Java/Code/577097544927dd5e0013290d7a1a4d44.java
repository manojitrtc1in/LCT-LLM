import java.io.*;
import java.util.Arrays;
import java.util.*;
import java.util.Scanner;
import java.util.StringTokenizer;




public class copy {


    public static boolean checker(long[] arr, long K, long diff) {
        long collect = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > diff)
                collect += arr[i] - diff;
        }

        if (collect >= K)
            return true;
        else
            return false;
    }

    public static long search(long[] arr, long K, long R) {
        long l = 0;
        long r = R;

        while (l <= r) {
            long mid = (l + r) / 2;

            if (checker(arr, K, mid)) {
                if (checker(arr, K, mid + 1))
                    l = mid + 1;
                else
                    return mid;
            } else
                r = mid - 1;
        }
        return -1;
    }

    static void sieveOfEratosthenes(int n, ArrayList<Integer> arr, ArrayList<Integer> arr1) {
        

        

        

        

        

        

        

        boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;

        for (int p = 2; p * p <= n; p++) {
            

            

            if (prime[p] == true) {

                

                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        

        int x = 0;
        for (int i = 2; i <= n; i++) {
            if (prime[i] == true) {

                arr.add(i);


            }

        }
        System.out.println(arr.size());
    }

    public static boolean check(String s, int K, char ch) {
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ch)
                arr.add(i);
        }




        if (arr.size() == 0)
            return false;
        if (arr.get(0) >= K)
            return false;
        if (s.length() - 1 - arr.get(arr.size() - 1) >= K)
            return false;
        for (int i = 1; i < arr.size(); i++) {
            if (arr.get(i) - arr.get(i - 1) > K)
                return false;
        }
        return true;
    }

    public static int check(long N) {
        int sum = 0;
        while (N > 0) {
            sum += N % 10;
            N = N / 10;
        }
        return sum;

    }

    public static long call(long N) {
        long l = 1;
        long r = (long) Math.floor(Math.sqrt(N));
        while (l <= r) {
            long mid = (l + r) / 2;
            double left = N / (double) (mid) - mid;
            int right = check(mid);
            System.out.println(mid + " " + left + " " + right);
            if (mid == 10)
                System.out.println(left + " " + right);
            if (left > right)
                l = mid + 1;
            else if (right > left)
                r = mid - 1;
            else
                return mid;
        }
        return -1;
    }

    public static int path(ArrayList<ArrayList<Integer>> arr, int X, int parent, int[] gold, PriorityQueue<Integer> pq) {
        int max = 0;
        ArrayList<Integer> ch = new ArrayList<>();
        for (int i : arr.get(X)) {
            if (i != parent) {
                ch.add(path(arr, i, X, gold, pq));
            }
        }
        Collections.sort(ch, Collections.reverseOrder());
        for (int i = 1; i < ch.size(); i++)
            pq.add(ch.get(i));


        if (ch.size() == 0)
            return gold[X];
        else
            return ch.get(0) + gold[X];

    }

    public static long fac(long N, long mod) {
        if (N == 0)
            return 1;
        if(N==1)
            return 1;
        return ((N % mod) * (fac(N - 1, mod) % mod)) % mod;
    }

    public static String form(char ch, int freq) {
        String s = "";
        for (int i = 1; i <= freq; i++)
            s += ch;
        return s;
    }

    static long power(long x, long y, long p) {

        

        long res = 1;

        

        

        x = x % p;

        while (y > 0) {

            

            

            if (y % 2 == 1)
                res = (res * x) % p;

            

            y = y >> 1; 

            x = (x * x) % p;
        }

        return res;
    }

    

    static long modInverse(long n, long p) {
        return power(n, p - 2, p);
    }

    

    

    static long nCrModPFermat(long n, long r,
                              long p) {

        if (n < r)
            return 0;
        

        if (r == 0)
            return 1;

        

        

        







        return ((fac(n, p) % p * (modInverse(fac(r, p), p)
                % p)) % p * (modInverse(fac(n - r, p), p)
                % p)) % p;
    }

    public static boolean check(long[] arr, long time, int M) {
        long sum = 0;
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            if (sum >= time) {
                ++count;
                sum = 0;
            }
        }

        if (sum >= time)
            ++count;

        return count >= M;
    }

    public static int check(ArrayList<Integer> arr, ArrayList<Integer> arr2) {
        int l = 0, r = 0, ans = 0;
        while (l < arr.size() && r < arr2.size()) {
            if (arr.get(l) < arr2.get(r))
                ++l;
            else if (arr.get(l) > arr2.get(r))
                ++r;
            else {
                ++ans;
                ++l;
                ++r;
            }
        }
        return ans;
    }


    public static int find(int[] parent, int x) {
        if (parent[x] == x)
            return x;
        return find(parent, parent[x]);
    }

    public static int merge(int[] parent, int[] rank, int x, int y,int[] child) {
        int x1 = find(parent, x);
        int y1 = find(parent, y);
        int c=0;
        if (rank[x1] > rank[y1]) {
            parent[y1] = x1;
            child[x1]+=child[y1];
            c=child[x1];

        } else if (rank[y1] > rank[x1]) {
            parent[x1] = y1;
            child[y1]+=child[x1];
            c=child[y1];
        } else {
            parent[y1] = x1;
            rank[x1]++;
            child[x1]+=child[y1];
            c=child[x1];
        }

        return c;
    }

    public static int bfs(ArrayList<ArrayList<Integer>> arr, int e1, int e2, int N) {
        boolean[] visited = new boolean[N];
        visited[0] = true;
        int[] dist = new int[N];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        Arrays.fill(dist, -1);
        dist[0] = 0;
        while (queue.size() > 0) {
            int x = queue.poll();
            for (int i : arr.get(x)) {
                if (!visited[i] || (e1 == x && e2 == i)) {
                    System.out.println(x + " " + dist[x]);
                    dist[i] = dist[x] + 1;
                    visited[i] = true;
                    queue.add(i);
                }
            }

        }


        return dist[N - 1];
    }








    public static int binarysearch(ArrayList<Integer> possible, int X, int start) {
        int l = start, r = possible.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (possible.get(mid) > X) {
                if (mid - 1 >= start && possible.get(mid - 1) > X)
                    r = mid - 1;
                else
                    return mid;
            } else
                l = mid + 1;
        }

        return -1;
    }







    public static long gcd(long a, long b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }


    public static void leftRotatebyOne(int arr[], int n) {
        int i, temp;
        temp = arr[0];
        for (i = 0; i < n - 1; i++)
            arr[i] = arr[i + 1];
        arr[n - 1] = temp;
    }



    static int power(int x, int y, int p)
    {

        

        int res = 1;

        

        

        x = x % p;

        while (y > 0) {

            

            

            if (y % 2 == 1)
                res = (res * x) % p;

            

            y = y >> 1; 

            x = (x * x) % p;
        }

        return res;
    }

    

    static int modInverse(int n, int p)
    {
        return power(n, p - 2, p);
    }

    

    

    static int nCrModPFermat(int n, int r,
                             int p)
    {

        if (n<r)
            return 0;
        

        if (r == 0)
            return 1;

        

        

        

        int[] fac = new int[n + 1];
        fac[0] = 1;

        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % p;

        return (fac[n] * modInverse(fac[r], p)
                % p * modInverse(fac[n - r], p)
                % p)
                % p;
    }



    public static long[][] ncr(int n,int r)
    {
        long[][] dp=new long[n+1][r+1];
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=r;j++)
            {
                if(j>i)
                    continue;
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }

        return dp;

    }

    static boolean status=false;
    static int x1=-1,y1=-1;
    public static int dfs(ArrayList<ArrayList<Integer>> arr,int X,int[] ans,int value,int parent)
    {
        int xor=ans[X];
        for(int i:arr.get(X))
        {
            if(i!=parent)
            {
                int x=dfs(arr,i,ans,value,X);
                if(x==-1)
                    return -1;
                if(x==value)
                {
                    x1=X;
                    y1=i;
                    return -1;
                }
                xor=xor^x;
            }
        }



        return xor;
    }

    public static boolean prime(long N)
    {
        int c=0;
        for(int i=2;i*i<=N;i++)
        {
            if(N%i==0)
                ++c;
        }

        return c==0;
    }
    static int[] c;
    static boolean sta=true;
    public static int dfs(ArrayList<ArrayList<Integer>> arr,int N,int j,int[] status,boolean[] visited)
    {
        Queue<Integer> queue=new LinkedList<>();
        queue.add(j);
        status[j]=1;
        visited[j]=true;
        int[] color=new int[2];
        while(queue.size()>0)
        {
            int temp=queue.poll();
            if(temp<N)
                color[status[temp]]++;
            for(int i:arr.get(temp))
            {
                if(visited[i])
                {
                    if(status[i]==status[temp])
                        return -1;
                }
                else
                {
                    queue.add(i);
                    status[i]=1-status[temp];
                    visited[i]=true;
                }
            }
        }

        return Math.max(color[0],color[1]);
    }

    public static boolean check(String s,int N,long D,long C,long M)
    {
        int index=s.lastIndexOf('D');
        for(int i=0;i<=index;i++)
        {
            if(s.charAt(i)=='D' && D>0)
            {
                D-=1;
                C+=M;
            }
            else if(s.charAt(i)=='C' && C>0)
            {
                C-=1;
            }
            else
                return false;
        }

        return true;
    }




    public static boolean checkbounds(int x,int y,int N,int M)
    {
        return x>=0 && x<N && y>=0 && y<M;
    }

    public static void dfs(int x,int y,char[][] grid,boolean[][] visited,int N,int M)
    {
        visited[x][y]=true;
        if(checkbounds(x+1,y,N,M) && !visited[x+1][y] && grid[x+1][y]=='.')
            dfs(x+1,y,grid,visited,N,M);
        if(checkbounds(x-1,y,N,M) && !visited[x-1][y] && grid[x-1][y]=='.')
            dfs(x-1,y,grid,visited,N,M);
        if(checkbounds(x,y+1,N,M) && !visited[x][y+1] && grid[x][y+1]=='.')
            dfs(x,y+1,grid,visited,N,M);
        if(checkbounds(x,y-1,N,M) && !visited[x][y-1] && grid[x][y-1]=='.')
            dfs(x,y-1,grid,visited,N,M);
    }

    public static int bin(ArrayList<Integer> arr,int search)
    {
        int l=0,r=arr.size()-1;
        if(search<arr.get(0))
            return -1;
        if(search>arr.get(r-1))
            return r+1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(arr.get(mid)>search)
            {
                if(mid-1>=0 && arr.get(mid-1)>search)
                    r=mid-1;
                else
                    return mid;
            }
            else
                l=mid+1;
        }

        return -1;
    }


    public static int mcbc(ArrayList<Long> arr,long search,int N,int lower)
    {
        if(search>=arr.get(N))
            return N;

        if(search<=arr.get(lower))
            return lower;
        int l=lower;
        int r=N;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(arr.get(mid)==search)
            {
                return mid;
            }

            if(arr.get(mid)>search)
            {
                if(mid-1>=lower && arr.get(mid-1)>=search)
                    r=mid-1;
                else
                {
                    if(mid-1>=lower)
                    {
                        if (Math.abs(search - arr.get(mid)) < Math.abs(search - arr.get(mid - 1)))
                            return mid;
                        else
                            return mid - 1;
                    }
                    else
                        return mid;
                }
            }

            else if(arr.get(mid)<search)
            {
                if(mid+1<=N && arr.get(mid+1)<=search)
                    l=mid+1;
                else
                {
                    if(mid+1<=N)
                    {
                        if (Math.abs(search - arr.get(mid)) < Math.abs(search - arr.get(mid + 1)))
                            return mid;
                        else
                            return mid + 1;
                    }
                    else
                        return mid;
                }
            }
        }

        return -1;

    }

    public static int check(String s,char ch)
    {
        int l=0,r=s.length()-1;
        int c=0;
        while(l<r)
        {
            if(s.charAt(l)!=s.charAt(r))
            {
                if(s.charAt(l)==ch)
                {
                    ++c;
                    ++l;
                }
                else if(s.charAt(r)==ch)
                {
                    ++c;
                    --r;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                ++l;
                --r;
            }
        }

        return c;

    }



    static boolean cycle=false;

    public static void check(int x1,int y1,String[][] s,boolean[][] visited,int N,int M,int[] xdiff,int[] ydiff,div[][] ans,int index)
    {
        Queue<div> queue1=new LinkedList<>();
        Queue<div> queue2=new LinkedList<>();
        visited[x1][y1]=true;
        queue1.add(new div(x1,y1));
        queue2.add(new div(x1,y1));
        int c=0;
        while(queue1.size()>0)
        {
            div temp=queue1.poll();
            

            int x=temp.x;
            int y=temp.y;
            ++c;
            for(int i=0;i<4;i++)
            {
                if(getbounds(x+xdiff[i],y+ydiff[i],N,M))
                {
                    if(!visited[x+xdiff[i]][y+ydiff[i]] && s[x+xdiff[i]][y+ydiff[i]].equals("."))
                    {
                        queue1.add(new div(x+xdiff[i],y+ydiff[i]));
                        queue2.add(new div(x+xdiff[i],y+ydiff[i]));
                        visited[x+xdiff[i]][y+ydiff[i]]=true;
                    }
                }
            }
        }

        div com=new div(index,c);

        while(queue2.size()>0)
        {

            div temp=queue2.poll();
            int x=temp.x;
            int y=temp.y;
            ans[x][y]=com;
        }

    }

    static int connected=0;

    public static int edges(ArrayList<ArrayList<Integer>> arr,int x,boolean[] visited)
    {
        ++connected;
        int sum=arr.get(x).size();
        visited[x]=true;
        for(int i:arr.get(x))
        {
            if(!visited[i])
                sum+=edges(arr,i,visited);
        }

        return sum;

    }





    public static boolean getbounds(int x,int y,int N,int M)
    {
        return x>=0 && x<N && y>=0 && y<M;
    }

    public static boolean drag(long h,ArrayList<Integer> interval,long mid)
    {
        long ans=0;
        for(int i=1;i<interval.size();i++)
        {
            ans+=Math.min(mid,interval.get(i)-interval.get(i-1));
        }
        ans+=mid;
        return ans>=h;
    }


    public static long search(ArrayList<Integer> interval,long h)
    {
        long l=1;long r=(long)Math.pow(10,18);
        while(l<=r)
        {
            long mid=(l+r)/2;
            if(drag(h,interval,mid))
            {
                if(mid-1>=1 && drag(h,interval,mid-1))
                    r=mid-1;
                else
                    return mid;
            }
            else
                l=mid+1;
        }

        return -1;

    }








    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
        int T=Reader.nextInt();
        A:for(int m=1;m<=T;m++) {

          int N=Reader.nextInt();
          long[] b=new long[N+1];
          long sum=0;
          for(int i=1;i<=N;i++)
          {
              b[i]=Reader.nextLong();
              sum+=b[i];
          }

          if(sum%(((long)(N)*(long)(N+1))/2)!=0)
          {
              output.write("NO"+"\n");
              continue;
          }

          long s=sum/(((long)(N)*(long)(N+1))/2);



            long[] ans=new long[N+1];
          for(int i=1;i<=N;i++)
          {
              int index=i-1;
              if(i-1==0)
                  index=N;
              if((s+b[index]-b[i])%N!=0)
              {
                  output.write("NO"+"\n");
                  continue A;
              }
              ans[i]=(s+b[index]-b[i])/N;
          }

          for(int i=1;i<=N;i++)
          {
              if(ans[i]<1 || ans[i]>Math.pow(10,9))
              {
                  output.write("NO"+"\n");
                  continue A;
              }
          }

          output.write("YES"+"\n");
          for(int i=1;i<=N;i++)
              output.write(ans[i]+" ");
          output.write("\n");


        }

















        output.flush();

    }
}



class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    static void init(InputStream input) {
        reader = new BufferedReader(
                new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }

    static String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(
                    reader.readLine());
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}


class sortat implements Comparator<div>
{
    public int compare(div o1,div o2)
    {
        return o1.x-o2.x;
    }
}

class div {
    int x, y;

    div(int x1,int z1) {
        x = x1;
        y=z1;

    }
}

class TreeNode
{
    int data;
    TreeNode left;
    TreeNode right;
    TreeNode(int data)
    {
        left=null;
        right=null;
        this.data=data;
    }
}