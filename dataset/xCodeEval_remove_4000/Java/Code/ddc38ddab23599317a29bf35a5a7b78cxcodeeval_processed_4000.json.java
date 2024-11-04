import java.io.*;
import java.util.Arrays;
import java.util.*;
import java.util.StringTokenizer;




public class copy {

    static int log=30;
    static int[][] ancestor;
    static int[] depth;

    static void id8(int n, ArrayList<Integer> arr) {
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

    

    

    static long id12(int n, int r,
                              long p,long[] fac) {

        if (n < r)
            return 0;
        

        if (r == 0)
            return 1;

        return ((fac[n] % p * (modInverse(fac[r], p)
                % p)) % p * (modInverse(fac[n-r], p)
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

    

    

    static int id12(int n, int r,
                             int p,int[] fac)
    {

        if (n<r)
            return 0;
        

        if (r == 0)
            return 1;

        

        

        












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


    public static int id10(ArrayList<ArrayList<Integer>> arr,int x,int parent,int[] child)
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
                c+=id10(arr,i,x,child);
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

        x=id7(depth[x]-depth[y],x);
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

    public static int id7(int K,int x)
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






    public static void primeFactors(int n,HashSet<Integer> hp)
    {
        

        ArrayList<Integer> factors=new ArrayList<>();
        if(n%2==0)
            hp.add(2);
        while (n%2==0)
        {

            n /= 2;
        }

        

        

        for (int i = 3; i <= Math.sqrt(n); i+= 2)
        {
            

            if(n%i==0)
                hp.add(i);
            while (n%i == 0)
            {

                n /= i;
            }
        }

        

        

        if (n > 2)
        {
            hp.add(n);

        }


    }

    public static boolean check(String s)
    {
        HashSet<Character> hp=new HashSet<>();
        char ch=s.charAt(0);
        for(int i=1;i<s.length();i++)
        {


            if(hp.contains(s.charAt(i)))
            {






                return false;
            }
            if(s.charAt(i)!=ch)
            {
                hp.add(ch);
                ch=s.charAt(i);

            }
        }

        return true;
    }

    public static int check_end(String[] arr,boolean[] st,char ch)
    {
        for(int i=0;i<arr.length;i++)
        {
            if(ch==arr[i].charAt(0) && !st[i] && ch==arr[i].charAt(arr[i].length()-1))
                return i;
        }

        for(int i=0;i<arr.length;i++)
        {
            if(ch==arr[i].charAt(0) && !st[i])
                return i;
        }



        return -1;
    }


    public static int check_start(String[] arr,boolean[] st,char ch)
    {
        for(int i=0;i<arr.length;i++)
        {










            if(ch==arr[i].charAt(arr[i].length()-1) && !st[i] && ch==arr[i].charAt(0))
                return i;
        }

        for(int i=0;i<arr.length;i++)
        {










            if(ch==arr[i].charAt(arr[i].length()-1) && !st[i])
                return i;
        }

        return -1;
    }

    public static boolean palin(int N)
    {
        String s="";
        while(N>0)
        {
            s+=N%10;
            N/=10;
        }
        int l=0,r=s.length()-1;
        while(l<=r)
        {
            if(s.charAt(l)!=s.charAt(r))
                return false;

            ++l;
            --r;
        }

        return true;
    }

    public static boolean check(long org_s,long org_d,long org_n,long check_ele)
    {
        if(check_ele<org_s)
            return false;

        if((check_ele-org_s)%org_d!=0)
            return false;



        long num=(check_ele-org_s)/org_d;





        return num+1<=org_n;
    }

    public static long check(long c,long c_diff,long mod,long b_start,long c_start, long c_end,long b_end,long b_diff)
    {


        long max=Math.max(c,b_diff);
        long min=Math.min(c,b_diff);
        long lcm=(max/gcd(max,min))*min;











        long start_point=c_diff/c-c_diff/lcm;


















        return (start_point%mod*start_point%mod)%mod;



    }

    public static boolean check_bounds(int x, int y, int N, int M)
    {
        return x>=0 && x<N && y>=0 && y<M;
    }
    static boolean found=false;
    public static void check(int x,int y,int[][] arr,boolean status[][])
    {
        if(arr[x][y]==9)
        {
            found=true;
            return;
        }

        status[x][y]=true;
        if(check_bounds(x-1,y, arr.length,arr[0].length)&& !status[x-1][y])
            check(x-1,y,arr,status);
        if(check_bounds(x+1,y, arr.length,arr[0].length)&& !status[x+1][y])
            check(x+1,y,arr,status);
        if(check_bounds(x,y-1, arr.length,arr[0].length)&& !status[x][y-1])
            check(x,y-1,arr,status);
        if(check_bounds(x,y+1, arr.length,arr[0].length)&& !status[x][y+1])
            check(x,y+1,arr,status);

    }

    public static int check(String s1,String s2,int M)
    {
        int ans=0;
        for(int i=0;i<M;i++)
        {
            ans+=Math.abs(s1.charAt(i)-s2.charAt(i));
        }

        return ans;
    }

    public static int check(int[][] arr,int dir1,int dir2,int x1,int y1)
    {
        int sum=0,N=arr.length,M=arr[0].length;
        int x=x1+dir1,y=y1+dir2;
        while(x<N && x>=0 && y<M && y>=0)
        {
            sum+=arr[x][y];
            x=x+dir1;
            y+=dir2;
        }

        return sum;
    }

    public static int check(long[] pref,long X,int N)
    {
        if(X>pref[N-1])
            return -1;


        if(X<=pref[0])
            return 1;
        int l=0,r=N-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(pref[mid]>=X)
            {
                if(mid-1>=0 && pref[mid-1]<X)
                    return mid+1;
                else
                    r=mid-1;
            }
            else
                l=mid+1;
        }

        return -1;
    }



    private static long id6(long[] arr, int l,
                                      int m, int r)
    {

        

        long[] left = Arrays.copyOfRange(arr, l, m + 1);

        

        long[] right = Arrays.copyOfRange(arr, m + 1, r + 1);

        int i = 0, j = 0, k = l;long swaps = 0;

        while (i < left.length && j < right.length) {
            if (left[i] < right[j])
                arr[k++] = left[i++];
            else {
                arr[k++] = right[j++];
                swaps += (m + 1) - (l + i);
            }
        }
        while (i < left.length)
            arr[k++] = left[i++];
        while (j < right.length)
            arr[k++] = right[j++];
        return swaps;
    }

    

    private static long id9(long[] arr, int l,
                                          int r)
    {

        

        

        long count = 0;

        if (l < r) {
            int m = (l + r) / 2;

            

            


            

            count += id9(arr, l, m);

            

            count += id9(arr, m + 1, r);

            

            count += id6(arr, l, m, r);
        }

        return count;
    }

    public static long check(long L,long R)
    {
        long ans=0;
        for(int i=1;i<=Math.pow(10,8);i++)
        {
            long A=i*(long)i;
            if(A<L)
                continue;

            long upper=(long)Math.floor(Math.sqrt(A-L));
            long lower=(long)Math.ceil(Math.sqrt(Math.max(A-R,0)));

            if(upper>=lower)
                ans+=upper-lower+1;
        }

        return ans;
    }

    public static int check(ArrayList<ArrayList<Integer>> arr,int x,int parent,int[]store)
    {
        int index=0;

        ArrayList<Integer> temp=arr.get(x);
        for(int i:temp)
        {
            if(i!=parent)
            {
                index+=check(arr,i,x,store);
            }
        }
        store[x]=index;

        return index+1;
    }

    public static void finans(int[][] store,ArrayList<ArrayList<Integer>> arr,int x,int parent)
    {




        if(store[x][0]==0 && store[x][1]==0)
            return;

        if(store[x][0]!=0 && store[x][1]==0)
        {
            ++delete;
            ans+=store[x][0];
            return;
        }

        if(store[x][0]==0 && store[x][1]!=0)
        {
            ++delete;
            ans+=store[x][1];
            return;
        }
        ArrayList<Integer> temp=arr.get(x);

        if(store[x][0]!=0 && store[x][1]!=0)
        {
            ++delete;
            if(store[x][0]>store[x][1])
            {
                ans+=store[x][0];
                for(int i=temp.size()-1;i>=0;i--)
                {
                    if(temp.get(i)!=parent)
                    {
                        finans(store,arr,temp.get(i),x);
                        break;
                    }
                }
            }
            else
            {
                ans+=store[x][1];
                for(int i=0;i<temp.size();i++)
                {
                    if(temp.get(i)!=parent)
                    {
                        finans(store,arr,temp.get(i),x);
                        break;
                    }
                }
            }
        }

    }

    public static int dfs(ArrayList<ArrayList<Integer>> arr,int x,int parent,int[] store)
    {

        int index1=-1,index2=-1;

        for(int i=0;i<arr.get(x).size();i++)
        {
            if(arr.get(x).get(i)!=parent)
            {
                if(index1==-1)
                {
                    index1=i;
                }
                else
                    index2=i;
            }

        }

        if(index1==-1)
        {
            return 0;
        }

        if(index2==-1)
        {
            return store[arr.get(x).get(index1)];
        }





        return Math.max(store[arr.get(x).get(index1)]+dfs(arr,arr.get(x).get(index2),x,store),store[arr.get(x).get(index2)]+dfs(arr,arr.get(x).get(index1),x,store));


    }


    static int delete=0;

    public static boolean bounds(int x,int y,int N,int M)
    {
        return x>=0 && x<N && y>=0 && y<M;
    }


    public static int id0(ArrayList<Integer> temp,char[] ch, int[] arr)
    {
        ArrayList<Integer> ini=new ArrayList<>(temp);
        for(int i=0;i<temp.size();i++)
        {
            for(int j=0;j<temp.size();j++)
            {
                int req=temp.get(j);
                temp.set(j,arr[req-1]);
            }

            boolean status=true;

            for(int j=0;j<temp.size();j++)
            {
                if(ch[ini.get(j)-1]!=ch[temp.get(j)-1])
                    status=false;
            }

            if(status)
                return i+1;
        }

        return temp.size();
    }

    static long id4(int[] arr, int idx)
    {

        

        if (idx == arr.length - 1){
            return arr[idx];
        }
        int a = arr[idx];
        long b = id4(arr, idx+1);
        return (a*b/gcd(a,b)); 

    }

    public static boolean check(ArrayList<Integer> arr,int sum)
    {
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                for(int k=j+1;k<arr.size();k++)
                {
                    if(arr.get(i)+arr.get(j)+arr.get(k)==sum)
                        return true;
                }
            }
        }

        return false;
    }




    

    static boolean id13(String str1, String str2)
    {
        

        int n1 = str1.length(), n2 = str2.length();
        if (n1 < n2)
            return true;
        if (n2 < n1)
            return false;

        for (int i = 0; i < n1; i++)
            if (str1.charAt(i) < str2.charAt(i))
                return true;
            else if (str1.charAt(i) > str2.charAt(i))
                return false;

        return false;
    }



    public static int check(List<String> history)
    {
        int[][] arr=new int[history.size()][history.get(0).length()];
        for(int i=0;i<arr.length;i++)
        {
            for(int j=0;j<arr[0].length;j++)
            {
                arr[i][j]=history.get(i).charAt(j)-48;
            }
        }

        for(int i=0;i<arr.length;i++)
            Arrays.sort(arr[i]);
        int sum=0;
        for(int i=0;i<arr[0].length;i++)
        {
            int max=0;
            for(int j=0;j<arr.length;j++)
                max=Math.max(max,arr[j][i]);
            sum+=max;
        }

        return sum;
    }

    

    static String findDiff(String str1, String str2)
    {
        

        

        if (id13(str1, str2)) {
            String t = str1;
            str1 = str2;
            str2 = t;
        }

        

        String str = "";

        

        int n1 = str1.length(), n2 = str2.length();

        

        str1 = new StringBuilder(str1).reverse().toString();
        str2 = new StringBuilder(str2).reverse().toString();

        int carry = 0;

        

        

        for (int i = 0; i < n2; i++) {
            

            

            int sub
                    = ((int)(str1.charAt(i) - '0')
                    - (int)(str2.charAt(i) - '0') - carry);

            

            

            

            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;

            str += (char)(sub + '0');
        }

        

        for (int i = n2; i < n1; i++) {
            int sub = ((int)(str1.charAt(i) - '0') - carry);

            

            

            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;

            str += (char)(sub + '0');
        }

        

        return new StringBuilder(str).reverse().toString();
    }





    static int nCr(int n, int r)
    {
        return fact(n) / (fact(r) *
                fact(n - r));
    }

    

    static int fact(int n)
    {
        int res = 1;
        for (int i = 2; i <= n; i++)
            res = res * i;
        return res;
    }


    public static void fill(int[][] dp,int[] arr,int N)
    {
        for(int i=1;i<=N;i++)
            dp[i][0]=arr[i];

        for (int j = 1; j <= dp[0].length; j++)
            for (int i = 1; i + (1 << j) <= N; i++)
                dp[i][j] = Math.max(dp[i][j-1], dp[i + (1 << (j - 1))][j - 1]);
    }

    static int start=0;




    public static void dfs(ArrayList<ArrayList<Integer>> arr,int[] A,int[] B,int x,int time,int parent,int K,int coins)
    {
        if(time>K)
            return;

        ans=Math.max(ans,coins);



        for(int i:arr.get(x))
        {
            if(i!=parent)
            {
                dfs(arr,A,B,i,time+1,x,K,coins);
                dfs(arr,A,B,i,time+1+B[i],x,K,coins+A[i]);
            }
        }
    }


    public static boolean id11(ArrayList<ArrayList<Integer>> arr,int x,int parent,int node1,int node2,int[] child)
    {
        boolean status=false;
        for(int i:arr.get(x))
        {
            if(i!=parent)
            {
                boolean ch=id11(arr,i,x,node1,node2,child);
                status= status || ch;
                if(!ch && x==node1)
                    ans+=child[i];
                child[x]+=child[i];


            }
        }
        child[x]+=1;

        return status || (x==node2);
    }

    public static boolean id1(int x,int y,int sx,int sy,int di)
    {




        return (Math.abs(x-sx)+Math.abs(y-sy))<=di;
    }


    public static int lower_index(ArrayList<Integer> arr, int x)
    {


        int l=0,r=arr.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(arr.get(mid)<x)
                l=mid+1;
            else
            {
                if(mid-1>=0 && arr.get(mid-1)>= x)
                    r=mid-1;
                else
                    return mid;
            }

        }
        return -1;
    }

    public static int higher_index(ArrayList<Integer> arr, int  x)
    {
        int l=0,r=arr.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(arr.get(mid)>x)
                r=mid-1;
            else
            {
                if(mid+1<arr.size() && arr.get(mid+1)<=x )
                    l=mid+1;
                else
                    return mid;
            }

        }
        return -1;
    }
    static int time;
    static void bridgeUtil(int u, boolean visited[], int disc[], int low[], int parent[],ArrayList<ArrayList<Integer>> adj,HashMap<Integer,Integer> hp)
    {

        

        visited[u] = true;

        

        disc[u] = low[u] = ++time;

        

        Iterator<Integer> i = adj.get(u).iterator();
        while (i.hasNext())
        {
            int v = i.next();  


            

            

            

            if (!visited[v])
            {
                parent[v] = u;
                bridgeUtil(v, visited, disc, low, parent,adj,hp);

                

                

                low[u]  = Math.min(low[u], low[v]);

                

                

                

                if (low[v] < disc[u])
                {
                    hp.put(u,v);
                    hp.put(v,u);
                }

            }

            

            else if (v != parent[u])
                low[u]  = Math.min(low[u], disc[v]);
        }
    }
    static int r;
    static int b;

    public static void traverse(ArrayList<ArrayList<Integer>> arr,int x,int parent,int[][] dp,int[] level,int K) {
        if(parent!=-1)
        level[x]=level[parent]+1;
        dp[x][0] += 1;
        for (int i : arr.get(x))
        {
            if(i!=parent)
            {
                traverse(arr,i,x,dp,level,K);
                for(int j=1;j<=K;j++)
                    dp[x][j]+=dp[i][j-1];
            }
        }




    }

    static long fin_ans;

    public static void calc_pairs(ArrayList<ArrayList<Integer>> arr,int x,int parent,int[][] dp,int[] level,int K,int[][] total)
    {

        if(parent!=-1)
        {



            total[x][1]+=1;
            for(int i=2;i<=K;i++)
                total[x][i]+=total[parent][i-1]-dp[x][i-2];


        }
        fin_ans+=total[x][K];


        for(int i:arr.get(x))
        {
            if(i!=parent)
            {
                calc_pairs(arr,i,x,dp,level,K,total);
            }
        }

    }

    static int[] id5(int n,int q,String s,int[][] queries)
    {
        ArrayList<ArrayList<Integer>> arr=new ArrayList<>();
        for(int i=0;i<26;i++)
            arr.add(new ArrayList<>());
        for(int i=0;i<n;i++)
        {
            arr.get(s.charAt(i)-97).add(i);
        }
        int[] ans=new int[q];

        for(int i=0;i<q;i++)
        {
            int l=queries[i][0]-1;
            int r=queries[i][1]-1;
            int cnt=0;
            for(int j=0;j<26;j++)
            {
                int index1=lower_index(arr.get(j),l);
                int index2=higher_index(arr.get(j),r);

                if(index1!=-1 && index2!=-1)
                {
                    int ele=index2-index1+1;
                    cnt+=((ele)*(ele-1))/2+ele;
                }
            }

            ans[i]=cnt;
        }
        return ans;
    }


    static int id14(int[] pat, int[] txt)
    {
        int M = pat.length;
        int N = txt.length;

        

        

        int lps[] = new int[M];
        int j = 0; 


        

        

        id2(pat, M, lps);

        int i = 0; 

        while ((N - i) >= (M - j)) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }
            if (j == M) {
                return i-j;

            }

            

            else if (i < N && pat[j] != txt[i]) {
                

                

                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }

        return -1;
    }

    static void id2(int[] pat, int M, int lps[])
    {
        

        int len = 0;
        int i = 1;
        lps[0] = 0; 


        

        while (i < M) {
            if (pat[i] == pat[len]) {
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
    }


    public static long fill(ArrayList<Integer> trees,ArrayList<Integer> wells,long[] before_x)
    {
        int l=0,r=0;
        long mod=(long)1e9+7;
        long[] pref_dist=new long[before_x.length];
        int[] cnt=new int[before_x.length];
        while(l<trees.size() && r<wells.size())
        {
            if(trees.get(l)<=wells.get(r))
            {
                before_x[r]=(before_x[r]%mod+power(wells.get(r)-trees.get(l),2,mod)%mod)%mod;
                pref_dist[r]=(pref_dist[r]%mod+(wells.get(r)-trees.get(l))%mod)%mod;
                cnt[r]+=1;
                ++l;
            }
            else
                ++r;
        }



        for(int i=1;i<before_x.length;i++)
        {
            before_x[i]=(before_x[i]%mod+((before_x[i-1]%mod+(cnt[i-1]%mod*power(wells.get(i)-wells.get(i-1),2,mod)%mod)%mod)%mod+(2%mod*((wells.get(i)-wells.get(i-1))%mod*(pref_dist[i-1])%mod)%mod)%mod)%mod%mod);
            pref_dist[i]=(pref_dist[i]%mod+(pref_dist[i-1]%mod+(cnt[i-1]%mod*(long)(wells.get(i)-wells.get(i-1))%mod)%mod)%mod)%mod;
            cnt[i]+=cnt[i-1];

        }







        long ans=0;
        for(int i=0;i<before_x.length;i++)
            ans=(ans%mod+ before_x[i]%mod)%mod;
        return ans;

    }


    public static long fill_after(ArrayList<Integer> trees,ArrayList<Integer> wells,long[] before_x)
    {
        int l=trees.size()-1,r=wells.size()-1;
        long mod=(long)1e9+7;
        long[] pref_dist=new long[before_x.length];
        int[] cnt=new int[before_x.length];
        while(l>=0 && r>=0)
        {
            if(trees.get(l)>=wells.get(r))
            {
                before_x[r]=(before_x[r]%mod+power(wells.get(r)-trees.get(l),2,mod)%mod)%mod;
                pref_dist[r]=(pref_dist[r]%mod+(trees.get(l)-wells.get(r))%mod)%mod;
                cnt[r]+=1;
                --l;
            }
            else
                --r;
        }



        for(int i=before_x.length-2;i>=0;i--)
        {
            before_x[i]=(before_x[i]%mod+((before_x[i+1]%mod+(cnt[i+1]%mod*power(wells.get(i)-wells.get(i+1),2,mod)%mod)%mod)%mod+(2%mod*((wells.get(i+1)-wells.get(i))%mod*(pref_dist[i+1])%mod)%mod)%mod)%mod%mod);
            pref_dist[i]=(pref_dist[i]%mod+(pref_dist[i+1]%mod+(cnt[i+1]%mod*(long)(wells.get(i+1)-wells.get(i))%mod)%mod)%mod)%mod;
            cnt[i]+=cnt[i+1];


        }






        long ans=0;
        for(int i=0;i<before_x.length;i++)
            ans=(ans%mod+ before_x[i]%mod)%mod;
        return ans;



    }

    public static ArrayList<ArrayList<Integer>> graph_form(int N)
    {
        ArrayList<ArrayList<Integer>> arr=new ArrayList<>();
        for(int i=0;i<N;i++)
            arr.add(new ArrayList<>());
        return arr;
    }

    public static boolean check(int[] A,int mid)
    {
        for(int i=0;i<A.length;i++)
        {
            if(A[i]!=A[i%mid])
                return false;
        }
        return true;
    }

    public static boolean check(int[] A)
    {
        ArrayList<Integer> arr=new ArrayList<>();
        for(int i=2;i*i<=A.length;i++)
        {
            if(A.length%i==0)
            {
                arr.add(i);
                arr.add(A.length/i);
            }
        }

        boolean status=false;
        for(int i:arr)
        {
            status =status || check(A,i);
        }
        return status;
    }





















    public static void main(String[] args) throws IOException{
        Reader.init(System.in);


        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
        int T=Reader.nextInt();
        for(int m=1;m<=T;m++)
        {
            int N=Reader.nextInt();
            long[] x=new long[N];
            long[] y=new long[N];
            for(int i=0;i<N;i++)
                x[i]=Reader.nextLong();
            for(int i=0;i<N;i++)
                y[i]=Reader.nextLong();

            ArrayList<Long> positive=new ArrayList<>();
            ArrayList<Long> negative=new ArrayList<>();

            for(int i=0;i<N;i++)
            {
                if(y[i]-x[i]>=0)
                    positive.add(y[i]-x[i]);
                else
                    negative.add(y[i]-x[i]);
            }
            Collections.sort(positive,Collections.reverseOrder());
            Collections.sort(negative);




            int grp=0, left=positive.size();
            int l=0,r=0;
            while(l<positive.size() && r<negative.size())
            {
                if(positive.get(l)>=Math.abs(negative.get(r)))
                {
                    grp+=1;
                    --left;
                    ++l;
                    ++r;
                }
                else
                    ++r;
            }





























            output.write(grp+left/2+"\n");
























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

    div(int x,int y) {
        this.x=x;
        this.y=y;




    }
}

class kar implements Comparator<div>
{
    public int compare(div o1,div o2) {
        if (o1.x < o2.x)
            return -1;
        else if (o1.x > o2.x)
            return 1;
        else {
            if (o1.y < o2.y)
                return -1;
            else if (o1.y > o2.y)
                return 1;
            else
                return 0;
        }
    }
}
class id3
{
    id3[] arr;
    id3()
    {
        arr=new id3[26];
    }

    public static void insert(id3 root,String s)
    {
        id3 tmp=root;
        for(int i=0;i<s.length();i++)
        {
            if(tmp.arr[s.charAt(i)-97]!=null)
            {
                tmp=tmp.arr[s.charAt(i)-97];
            }
            else
            {
                tmp.arr[s.charAt(i)-97]=new id3();
                tmp=tmp.arr[s.charAt(i)-97];

            }

        }
    }

    public static boolean search(id3 root,String s)
    {
        id3 tmp=root;
        for(int i=0;i<s.length();i++)
        {
            if(tmp.arr[s.charAt(i)-97]!=null)
            {
                tmp=tmp.arr[s.charAt(i)-97];
            }
            else
            {
                return false;

            }

        }
        return true;
    }
}