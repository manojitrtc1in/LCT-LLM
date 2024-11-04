import java.io.*;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.*;
import java.util.Scanner;
import java.util.StringTokenizer;




public class copy {

    static int log=18;
    static int[][] ancestor;
    static int[] depth;

    static void sieveOfEratosthenes(int n, ArrayList<Integer> arr) {
        boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;

        for (int p = 2; p * p <= n; p++) {
            

            

            if (prime[p]) {

                

                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        


        for (int i = 2; i <= n; i++) {
            if (prime[i]) {

                arr.add(i);


            }

        }

    }



    public static long fac(long N, long mod) {
        if (N == 0)
            return 1;
        if(N==1)
            return 1;
        return ((N % mod) * (fac(N - 1, mod) % mod)) % mod;
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



    public static int find(int[] parent, int x) {
        if (parent[x] == x)
            return x;
        return find(parent, parent[x]);
    }

    public static void merge(int[] parent, int[] rank, int x, int y,int[] child) {
        int x1 = find(parent, x);
        int y1 = find(parent, y);

        if (rank[x1] > rank[y1]) {
            parent[y1] = x1;
            child[x1]+=child[y1];


        } else if (rank[y1] > rank[x1]) {
            parent[x1] = y1;
            child[y1]+=child[x1];

        } else {
            parent[y1] = x1;
            child[x1]+=child[y1];
            rank[x1]++;

        }


    }


    public static long gcd(long a, long b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
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


    public static int sparse_ancestor_table(ArrayList<ArrayList<Integer>> arr,int x,int parent,int[] child)
    {

        int c=0;
        for(int i:arr.get(x))
        {
            if(i!=parent)
            {


                depth[i]=depth[x]+1;

                ancestor[i][0]=x;




                for(int j=1;j<log;j++)
                    ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1];
                c+=sparse_ancestor_table(arr,i,x,child);
            }
        }

        child[x]=1+c;
        return child[x];


    }


    public static int lca(int x,int y)
    {
        if(depth[x]<depth[y])
        {
            int temp=x;
            x=y;
            y=temp;
        }

        x=get_kth_ancestor(depth[x]-depth[y],x);
        if(x==y)
            return x;


        for(int i=log-1;i>=0;i--)
        {
            if(ancestor[x][i]!=ancestor[y][i])
            {
                x=ancestor[x][i];
                y=ancestor[y][i];
            }
        }

        return ancestor[x][0];

    }

    public static int get_kth_ancestor(int K,int x)
    {

        if(K==0)
            return x;
        int node=x;
        for(int i=0;i<log;i++)
        {
            if(K%2!=0)
            {
                node=ancestor[node][i];
            }
            K/=2;
        }

        return node;
    }

    public static ArrayList<Integer> primeFactors(int n)
    {
        

        ArrayList<Integer> factors=new ArrayList<>();
        if(n%2==0)
            factors.add(2);
        while (n%2==0)
        {

            n /= 2;
        }

        

        

        for (int i = 3; i <= Math.sqrt(n); i+= 2)
        {
            

            if(n%i==0)
                factors.add(i);
            while (n%i == 0)
            {

                n /= i;
            }
        }

        

        

        if (n > 2)
        {
            factors.add(n);

        }

        return factors;
    }

    static long ans=1,mod=1000000007;
    public static void recur(long X,long N,int index,ArrayList<Integer> temp)
    {


        if(index==temp.size())
        {

            System.out.println(X);

            ans=((ans%mod)*(X%mod))%mod;
            return;
        }
        for(int i=0;i<=60;i++)
        {

            if(X*Math.pow(temp.get(index),i)<=N)
                recur(X*(long)Math.pow(temp.get(index),i),N,index+1,temp);
            else
                break;

        }





    }

    public static int upper(ArrayList<Integer> temp,int X)
    {
        int l=0,r=temp.size()-1;


        while(l<=r)
        {
            int mid=(l+r)/2;
            if(temp.get(mid)==X)
                return mid;


            if(temp.get(mid)<X)
                l=mid+1;
            else
            {
                if(mid-1>=0 && temp.get(mid-1)>=X)
                    r=mid-1;
                else
                    return mid;
            }
        }

        return -1;
    }


    public static int lower(ArrayList<Integer> temp,int X)
    {
        int l=0,r=temp.size()-1;


        while(l<=r)
        {
            int mid=(l+r)/2;
            if(temp.get(mid)==X)
                return mid;


            if(temp.get(mid)>X)
                r=mid-1;
            else
            {
                if(mid+1<temp.size() && temp.get(mid+1)<=X)
                    l=mid+1;
                else
                    return mid;
            }
        }

        return -1;
    }

    public static int[] check(String shelf,int[][] queries)
    {
        int[] arr=new int[queries.length];
        ArrayList<Integer> indices=new ArrayList<>();
        for(int i=0;i<shelf.length();i++)
        {
            char ch=shelf.charAt(i);
            if(ch=='|')
                indices.add(i);
        }

        for(int i=0;i<queries.length;i++)
        {
            int x=queries[i][0]-1;
            int y=queries[i][1]-1;
            int left=upper(indices,x);
            int right=lower(indices,y);

            if(left<=right && left!=-1 && right!=-1)
            {
                arr[i]=indices.get(right)-indices.get(left)+1-(right-left+1);
            }
            else
                arr[i]=0;

        }

        return arr;


    }

    static boolean check;

    public static void check(ArrayList<ArrayList<Integer>> arr,int x,int[] color,boolean[] visited)
    {
        visited[x]=true;
        PriorityQueue<Integer> pq=new PriorityQueue<>();
        for(int i:arr.get(x))
        {
            if(color[i]<color[x])
                pq.add(color[i]);
            if(color[i]==color[x])
                check=false;


            if(!visited[i])
                check(arr,i,color,visited);
        }

        int start=1;
        while(pq.size()>0)
        {
            int temp=pq.poll();
            if(temp==start)
                ++start;
            else
                break;
        }
        if(start!=color[x])
            check=false;
    }
    static boolean cycle;
    public static void cycle(boolean[] stack,boolean[] visited,int x,ArrayList<ArrayList<Integer>> arr)
    {
        if(stack[x])
        {
            cycle=true;
            return;

        }

        visited[x]=true;
        for(int i:arr.get(x))
        {
            if(!visited[x])
            {
                cycle(stack,visited,i,arr);
            }
        }

        stack[x]=false;
    }

    public static div check(int[] arr,int index1,int index2,int count) {
        int cnt = 0, cnt2 = 0;
        for (int i = index1; i <= index2; i++) {

            if (arr[i] < 0)
                ++cnt;
            if (Math.abs(arr[i]) == count)
                ++cnt2;

        }


        if (cnt % 2 == 0) {
            int s=-1,e=-1;
            if(arr[index1]==0)
                s=index1+1;
            else
                s=index1;

            if(arr[index2]==0)
                e=index2-1;
            else
                e=index2;

            return new div(cnt2,s,e);
        } else {
            int twos = 0, twoe = 0;
            int i1 = -1, i2 = -1;
            for (int i = index1; i <= index2; i++) {
                if (arr[i] < 0) {
                    if (arr[i] == -1*count)
                        ++twos;
                    i1 = i;
                    break;
                }

                if (arr[i] == count)
                    ++twos;
            }

            for (int i = index2; i >= index1; i--) {
                if (arr[i] < 0) {
                    if (arr[i] == -1*count)
                        ++twoe;
                    i2 = i;
                    break;
                }

                if (arr[i] == count)
                    ++twoe;
            }





            int s=-1,e=-1;
            if(twos<twoe)
            {
                s=i1+1;
                if(arr[index2]==0)
                    e=index2-1;
                else
                    e=index2;
                return new div(cnt2-twos,s,e);
            }
            else
            {
                e=i2-1;
                if(arr[index1]==0)
                    s=index1+1;
                else
                    s=index1;
                return new div(cnt2-twoe,s,e);

            }


        }


    }

    public static int check(char[][] ch,int x,int y)
    {
        int cnt=0;

        int c=0;
        int N=ch.length;
        int x1=x,y1=y;
        while(c<ch.length)
        {
            if(ch[x][y]=='1')
                ++cnt;




            x=(x+1)%N;
            y=(y+1)%N;
            ++c;

        }

        return cnt;
    }

    public static void s(char[][] arr,int x)
    {
        char start=arr[arr.length-1][x];
        for(int i=arr.length-1;i>0;i--)
        {
            arr[i][x]=arr[i-1][x];
        }

        arr[0][x]=start;

    }

    public static void shuffle(char[][] arr,int x,int down)
    {
        int N= arr.length;
        down%=N;
        char[] store=new char[N-down];
        for(int i=0;i<N-down;i++)
            store[i]=arr[i][x];

        for(int i=0;i<arr.length;i++)
        {
            if(i<down)
            {
                

                

                arr[i][x]=arr[N + i - down][x];

            }
            else
            {
                

                

                arr[i][x]=store[i-down];
            }
        }
    }

    public static String form(int C1,char ch1,char ch2)
    {
        char ch=ch1;
        String s="";
        for(int i=1;i<=C1;i++)
        {
            s+=ch;
            if(ch==ch1)
                ch=ch2;
            else
                ch=ch1;
        }

        return s;
    }

    public static void printArray(long[] arr)
    {
        for(int i=0;i<arr.length;i++)
            System.out.print(arr[i]+" ");
        System.out.println();
    }

    public static boolean check(long mid,long[] arr,long K)
    {
        long[] arr1=Arrays.copyOfRange(arr,0,arr.length);
        long ans=0;
        for(int i=0;i<arr1.length-1;i++)
        {

                if(arr1[i]+arr1[i+1]>=mid)
                {
                    long check=(arr1[i]+arr1[i+1])/mid;




                    long left=check*mid;
                    left-=arr1[i];
                    if(left>=0)
                    arr1[i+1]-=left;
                    ans+=check;
                }





        }







            ans+=arr1[arr1.length-1]/mid;
        return ans>=K;
    }

    public static long search(long sum,long[] arr,long K)
    {
        long l=1,r=sum/K;
        while(l<=r)
        {
            long mid=(l+r)/2;
            if(check(mid,arr,K))
            {
                if(mid+1<=sum/K && check(mid+1,arr,K))
                    l=mid+1;
                else
                    return mid;
            }
            else
                r=mid-1;
        }

        return -1;
    }





    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
        int T=Reader.nextInt();
        for(int m=1;m<=T;m++)
        {

            int N=Reader.nextInt();
            long[] c=new long[N];
            for(int i=0;i<N;i++)
                c[i]=Reader.nextInt();

            long[] a=new long[N];
            long[] b=new long[N];
            for(int i=0;i<N;i++)
                a[i]=Reader.nextInt();

            for(int i=0;i<N;i++)
                b[i]=Reader.nextInt();





            long[] dp=new long[N];
            dp[0]=0;
            dp[1]=Math.abs(a[1]-b[1])+1+c[1];


            for(int i=2;i<N;i++)
            {
                long a1=Math.min(a[i],b[i]);
                long b1=Math.max(a[i],b[i]);
                if(a1==b1)
                {
                    dp[i]=1+c[i];


                    continue;
                }
                dp[i]=Math.max(dp[i-1]-(b1-a1-1)+c[i],b1-a1+1+c[i]);


            }
            long max=0;
            for(int i=0;i<N;i++)
                max=Math.max(max,dp[i]);
            output.write(max+"\n");





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


class div {
    int x;
    int y;
    int z;


    div(int x,int y, int z) {
        this.x = x;
        this.y=y;
        this.z=z;


    }
}

