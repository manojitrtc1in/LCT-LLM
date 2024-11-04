

import java.io.*;
import java.util.*;

public class T_class {
    static int m=2147483647;

    static int p=1000000007;
    static int max=(int)2e3+10;
    static boolean prime[]=new boolean[max+5];
    static  int dp[][]=new int[(int)max][max];
    static  List<Integer> total_prime=new ArrayList<>();
    public static class pr
    {
        int ai;
        int ti;
        pr(int a,int b)
        {
            ai=a;
            ti=b;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(FileDescriptor.out), "ASCII"), 512);
        FastReader sc=new FastReader();
        int t=sc.nextInt();
        StringBuilder sb2=new StringBuilder();

        while(t-- >0) {
            int n=sc.nextInt();
            int m=sc.nextInt();
            int mt[][]=new int[n][m];
            for(int i=0;i<n;i++)
            {
                char inp[]=sc.nextLine().toCharArray();
                for(int j=0;j<m;j++)
                {
                    mt[i][j]=inp[j]-'0';
                }
            }
            int tot=0;
            int step[]={0,3,2,1,4};
            int dx[]={0,0,1,1};
            int dy[]={0,1,0,1};
            StringBuilder ins=new StringBuilder();

            for(int i=0;i<n-2;i++)
            {
                for(int j=0;j<=m-1;j++)
                {
                    if(j==m-1)
                    {
                        if(mt[i][j]==0)
                            continue;
                        mt[i][j]=0;
                        mt[i+1][j]=1-mt[i+1][j];
                        mt[i+1][j-1]=1-mt[i+1][j-1];
                        StringBuilder indside=new StringBuilder();
                        indside.append((i+1)+" "+(1+j)+" "+(i+2)+" "+(j+1)+" "+(i+2)+" "+(j));
                        indside.append("\n");
                        ins.append(indside.toString());
                        tot++;
                        continue;
                    }
                    int ar[][]=new int[4][3];
                    int ones=0;
                    int st=1;
                    int end=3;
                    ar[0][0]=i;
                    ar[0][1]=j;
                    ar[0][2]=mt[i][j];
                    for(int k=1;k<=3;k++)
                    {
                        int x=i+dx[k];
                        int y=j+dy[k];
                        if(mt[x][y]==0) {
                            ar[st][0] = x;
                            ar[st][1] = y;
                            ar[st][2] = mt[x][y];
                        st++;
                        }
                        else
                        {
                            ar[end][0] = x;
                            ar[end][1] = y;
                            ar[end][2] = mt[x][y];
                            end--;
                        }
                        ones+=mt[x][y]==1?1:0;
                       

                    }
                    if(ar[0][2]==1) {
                        tot++;
                        StringBuilder indside=new StringBuilder();
                        indside.append((ar[0][0]+1)+" "+(1+ar[0][1])+" ");
                        mt[ar[0][0]][ar[0][1]]=0;
                        for(int k=3;k>=2;k--)
                        {
                            mt[ar[k][0]][ar[k][1]]=1-mt[ar[k][0]][ar[k][1]];
                            indside.append((ar[k][0]+1)+" "+(ar[k][1]+1)+" ");
                        }
                        indside.append("\n");
                        ins.append(indside.toString());
                    }
                }
            }
            for(int i=n-2;i<=n-2;i++)
            {
                for(int j=0;j<=m-2;j++)
                {
                    int ar[][]=new int[4][3];
                    int c=0;

                    if(j==m-2)
                    {
                        int ones=0;
                        for(int k=0;k<=3;k++)
                        {
                            int x=i+dx[k];
                            int y=j+dy[k];
                            ar[k][0]=x;
                            ar[k][1]=y;
                            ar[k][2]=mt[x][y];
                            ones+=mt[x][y]==1?1:0;
                            

                        }
                        if(ones>0) {
                            tot+=step[ones];
                            for(int k=0;k<=3;k++)
                            {
                                int x=i+dx[k];
                                int y=j+dy[k];
                                mt[x][y]=0;
                            }
                            String ret = sol(ar, ones);
                            ins.append(ret);
                        }
                    continue;
                    }
                    StringBuilder indside=new StringBuilder();
                    if(mt[i][j]==1)
                    {
                        mt[i][j]=1-mt[i][j];
                    indside.append((i+1)+" "+(j+1)+" ");
                        c++;
                    }
                    if(mt[i+1][j]==1)
                    {
                        mt[i+1][j]=1-mt[i+1][j];

                        indside.append((i+2)+" "+(j+1)+" ");
                        c++;
                    }
                    if(c>0)
                    {
                        if(c>0)
                        {
                            mt[i][j+1]=1-mt[i][j+1];

                            indside.append((i+1)+" "+(j+2)+" ");
                            c++;
                        }
                        if(c<3)
                        {
                            mt[i+1][j+1]=1-mt[i+1][j+1];
                            indside.append((i+2)+" "+(j+2)+" ");
                        }
                        tot++;
                        indside.append("\n");
                        ins.append(indside.toString());
                    }
                }
                for(int j=0;j<n;j++)
                {
                  

                }
            }

            for(int i=n+1;i<=n-2;i++)
            {
                for(int j=n-2;j<=m-2;j++)
                {
                    int ar[][]=new int[4][3];
                    int c=0;

                    if(i==n-2)
                    {
                        int ones=0;
                        for(int k=0;k<=3;k++)
                        {
                            int x=i+dx[k];
                            int y=j+dy[k];
                            ar[k][0]=x;
                            ar[k][1]=y;
                            ar[k][2]=mt[x][y];
                            ones+=mt[x][y]==1?1:0;
                            

                        }
                        if(ones>0) {
                            tot+=step[ones];
                            for(int k=0;k<=3;k++)
                            {
                                int x=i+dx[k];
                                int y=j+dy[k];
                                mt[x][y]=0;
                            }
                            String ret = sol(ar, ones);
                            ins.append(ret);
                        }
                        continue;
                    }
                    StringBuilder indside=new StringBuilder();
                    if(mt[i][j]==1)
                    {
                        mt[i][j]=1-mt[i][j];
                        indside.append((i+1)+" "+(j+1)+" ");
                        c++;
                    }
                    if(mt[i][j+1]==1)
                    {
                        mt[i][j+1]=1-mt[i][j+1];

                        indside.append((i+1)+" "+(j+2)+" ");
                        c++;
                    }
                    if(c>0)
                    {
                        if(c>0)
                        {
                            mt[i+1][j]=1-mt[i+1][j];

                            indside.append((i+2)+" "+(j+1)+" ");
                            c++;
                        }
                        if(c<3)
                        {
                            mt[i+1][j+1]=1-mt[i+1][j+1];
                            indside.append((i+2)+" "+(j+2)+" ");
                        }
                        tot++;
                        indside.append("\n");
                        ins.append(indside.toString());
                    }
                }

                for(int j=0;j<n;j++)
                {
               

                }
            }

           

            

        sb2.append(tot+"\n");
            sb2.append(ins.toString());
        }
        System.out.println(sb2.toString());
        out.flush();
    }

    private static String sol(int[][] ar,int ones) {
    if(ones==2)
    {
        StringBuilder sb=new StringBuilder();
        int zero=0;
        for(int i=0;i<=3;i++)
        {
            if(ar[i][2]==1&&ones==2)
            {
                ones--;
            }
            else
            {
                ar[i][2]=1-ar[i][2];
                sb.append((ar[i][0]+1)+" "+(ar[i][1]+1)+" ");
            }
        }
        sb.append("\n");
        for(int i=0;i<=3;i++)
        {
            if(ar[i][2]==0)
            {
            }
            else
            {
                ar[i][2]=1-ar[i][2];
                sb.append((ar[i][0]+1)+" "+(ar[i][1]+1)+" ");
            }
        }
        sb.append("\n");
        return  sb.toString();
    }
    else if(ones==1)
    {
        StringBuilder sb=new StringBuilder();
        int zero=0;
        for(int i=0;i<=3;i++)
        {
            if(ar[i][2]==0&&zero==0)
            {
                zero++;
            }
            else
            {
                ar[i][2]=1-ar[i][2];
                sb.append((ar[i][0]+1)+" "+(ar[i][1]+1)+" ");
            }
        }
        sb.append("\n");
        sb.append(sol(ar,2));
        return  sb.toString();
    }
    else if(ones==4)
    {

        StringBuilder sb=new StringBuilder();
        int zero=0;
        for(int i=0;i<=3;i++)
        {
            if(ar[i][2]==1&&zero<3)
            {
                zero++;
                ar[i][2]=1-ar[i][2];
                sb.append((ar[i][0]+1)+" "+(ar[i][1]+1)+" ");
            }
        }
        sb.append("\n");
        sb.append(sol(ar,1));
    return  sb.toString();
    }
    else
    {
        StringBuilder sb=new StringBuilder();
        int zero=0;
        for(int i=0;i<=3;i++)
        {
            if(ar[i][2]==1&&zero<3)
            {
                zero++;
                ar[i][2]=1-ar[i][2];
                sb.append((ar[i][0]+1)+" "+(ar[i][1]+1)+" ");
            }
        }
        sb.append("\n");
    return sb.toString();
    }
    }

    public static long gethash(long pow[], long hash[], int l, int r) {

        return (hash[r+1] - (hash[l ] * pow[r - l +1]) % m + m) % m;
    }
    private static String long_pre(char[] ch) {
        int n=ch.length;
        char cpy[]=new char[n];
        for(int i=n-1;i>=0;i--)
        {
            cpy[n-1-i]=ch[i];
        }
        long pow[] = new long[n + 1];
        long hash[] = new long[n + 1];
        pow[0] = 1;
        int p = 31;
        for (int i = 1; i <= n; i++) {
            pow[i] = (pow[i - 1] % m * p % m) % m;
        }

        for (int i = 1; i <= n; i++) {
            hash[i] = (hash[i - 1] * p % m + (ch[i - 1]) % m) % m;
        }

        long pow1[] = new long[n + 1];
        long hash1[] = new long[n + 1];
        pow1[0] = 1;
        

        for (int i = 1; i <= n; i++) {
            pow1[i] = (pow1[i - 1] % m * p % m) % m;
        }

        for (int i = 1; i <= n; i++) {
            hash1[i] = (hash1[i - 1] * p % m + (cpy[i - 1]) % m) % m;
        }


        int l=0,r=n-1,lst=0;
        for(int i=n-1;i>=1;i--)
        {
        int mid=i%2;
        int midp=i/2;
        if(mid==0&&gethash(pow,hash,0,midp-1)==gethash(pow1,hash1,n-1-i,n-1-(midp+1)))
        {
            lst=i;
            break;
        }
        else if(mid==1&&gethash(pow,hash,0,midp)==gethash(pow1,hash1,n-1-i,n-1-(midp+1)))
        {
            lst=i;
            break;
        }
        }
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<=lst;i++)
        {
            sb.append(ch[i]);
        }
        return sb.toString();
    }

    private static int Solve(int n, int l, int r,int h, int i, int s, int[] ar) {
        if(i==n)
            return 0;
        if(dp[i][s]!=-1)
            return dp[i][s];

        int ans=Math.max(con((s+ar[i])%h,l,r)+Solve(n,l,r, h,i+1,(s+ar[i])%h,ar)
                ,con((s+ar[i]-1)%h,l,r)+Solve(n,l,r,h,i+1,(s+ar[i]-1+h)%h,ar));
        dp[i][s]=ans;
        return dp[i][s];
    }

    private static int con(int i,int l,int r) {
        if(l<=i&&i<=r)
            return 1;
        else
            return 0;
    }

    static  long childs[]=new long[max];
    static long tot=0;
    public static void dfs_val(List<Integer> adj[],int u,int p,long val) {
        int in_max=-1;
        val=val+childs[u]+1;
        for(int v:adj[u])
        {
            if(v!=p)
            {
                in_max=v;
                dfs_val(adj,v,p,val);
            }
        }
        if(in_max==-1)
        {
            tot=Math.max(tot,val);
        }
    }
    public static void dfs(List<Integer> adj[],int u,int p)
    {

        for(int v:adj[u])
        {
            if(v!=p)
            {
                childs[u]++;
                dfs(adj,v,u);
                childs[u]+=childs[v];
            }
        }
    }
    public static int ans(int ar[],int i,int n,int t)
    {
        if(i>=n)
            return 0;
        if(t>=410)
            return 200000;
        if(dp[i][t]!=-1)
            return dp[i][t];
        

        int cur=Math.min(Math.abs(ar[i]-t)+ans(ar,i+1,n,t+1),ans(ar,i,n,t+1));
        dp[i][t]=cur;
        return dp[i][t];
    }

    private static long ncr(int n, int r, long[] fact) {
        if(r>n||n < 0 || r < 0)
            return 0;

        if(n==1||n==0)
            return 1;
        


        return (((fact[n]*pow_inverse(fact[n-r],p))%p)*pow_inverse(fact[r],p))%p;
    }
    static class BIT {
        long[] tree;
        public BIT(int size) {
            tree = new long[size + 1];
        }
        public long sum(int i) {
            long ans = 0;
            while (i > 0) {
                ans += tree[i];
                i -= i & -i;
            }
            return ans;
        }

        public long query(int i, int j) {
            return sum(j) - sum(i - 1);
        }

        public void add(int i, long val) {
            while (i < tree.length) {
                tree[i] += val;
                i += i & -i;
            }
        }

        public void set(int i, long val) {
            add(i, val - query(i, i));
        }
    }
    static class  vert implements Comparator<vert>
    {
        int v;
        TreeSet<Integer> set;

        public vert(int v, TreeSet<Integer> set) {
            this.v = v;
            this.set = set;
        }

        @Override
        public int compare(vert o1, vert o2) {
            return -(o1.set.size()-o2.set.size());
        }
    }
    public static long pow(long a,long b,long m)
    {
        long r=1;
        while(b!=1)
        {
            if(b%2!=0)
                r=(r*a)%m;
            b=b>>1;
            a=(a*a)%m;
        }
        return (r*a)%m;
    }
    public static long pow_inverse(long a,long m)
    {
        return pow(a,m-2,m);
    }public static long gcd(long a,long b)
    {
        if(b>a)
        {
            a=a^b;
            b=a^b;
            a=a^b;
        }
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    public static void id0(long a,long b)
    {
    }

    public static void seive()
    {
        for(int i=0;i<max;i++)
            prime[i] = true;

        for(int p = 2; p*p <=max; p++)
        {
            

            if(prime[p] == true)
            {
                

                for(int i = p*p; i <=max; i += p)
                    prime[i] = false;
            }
        }

        

        for(int i = 2; i <= max; i++)
        {
            if(prime[i] == true)
            {
                total_prime.add(i);
            }
        }
    }
    public static boolean union(int a, int b, int p[], int r[]){
        

        int pa=find(a,p,r);
        int pb=find(b,p,r);
        if(pa==pb)
            return true;
        if(pa!=pb)
        {
            if(r[pa]<r[pb])
            {
                p[pa]=pb;
            }
            else if(r[pa]>r[pb])
            {
                p[pb]=pa;
            }
            else
            {
                p[pa]=pb;
                r[pb]++;
            }
        }
        return false;
    }
    public static int find(int x,int p[],int r[])
    {
        if(p[x]==x)
            return x;
        p[x]=find(p[x],p,r);
        return p[x];
    }
    public static int id3(Integer[] ar, Integer x,int l,int r)
    {
        int res=-1,f=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(ar[mid]==x)
            {
                f=1;
                res=mid;
                l=mid+1;
            }
            else if(ar[mid]>x)
            {
                res=res!=-1&&ar[res]==x?res:mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return f==1?res:res+1;
    }
    public static int id2(int[] ar, long x, int l, int r)
    {
        int res=0,f=0;
        

        
        

        while(l<=r)
        {
            int mid=(l+r)>>1;
            

            if(ar[mid]==x)
            {
                f=1;
                res=mid;
                r=mid-1;
            }
            else if(ar[mid]>x)
            {
                r=mid-1;
            }
            else
            {
                res=res!=0&&ar[res]==x?res:mid;
                l=mid+1;
            }
        }

        

        return f==1?res:res+1;
    } public static int id1(int[] ar, int x,int l,int r)
    {
        int res=-1,f=0;
        

        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(ar[mid]==x)
            {
                f=1;
                res=mid;
                r=mid-1;
            }
            else if(ar[mid]<x)
            {
                r=mid-1;
            }
            else
            {
                

                l=mid+1;
            }
        }
        return f==0?res+1:res;
    }
    int bit[]=new int[(int)1e6];
    public void update(int n,int val,int i)
    {
        i++;
        while(i<n)
        {
            bit[i]+=val;
            i+=(i)&(-i);
        }

    }
    public long query(int n,int i)
    {
        i++;
        long sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i-=(i)&(-i);
        }
        return sum;
    }


    

    

    static class FastReader {

        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
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
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }


}