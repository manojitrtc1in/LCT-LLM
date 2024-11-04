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

    public static void merge(int[] parent, int[] rank, int x, int y) {
        int x1 = find(parent, x);
        int y1 = find(parent, y);
        if (rank[x1] > rank[y1]) {
            parent[y1] = x1;

        } else if (rank[y1] > rank[x1]) {
            parent[x1] = y1;
        } else {
            parent[y1] = x1;
            rank[x1]++;
        }
    }

    public static int check(ArrayList<ArrayList<Integer>> arr, int e1, int e2, int N) {
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

    static int N;

    static void rotate90Clockwise(String a[][]) {

        

        for (int i = 0; i < N / 2; i++) {
            for (int j = i; j < N - i - 1; j++) {

                

                

                String temp = a[i][j];
                a[i][j] = a[N - 1 - j][i];
                a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
                a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
                a[j][N - 1 - i] = temp;
            }
        }
    }


    public static void moves(String s, int i, int[] movx, int[] movy, int x, int y) {
        if (i >= s.length())
            return;
        

        if (s.charAt(i) == 'L') {
            movy[i] = y;
            movx[i] = x - 1;
            moves(s, i + 1, movx, movy, x - 1, y);
        } else if (s.charAt(i) == 'R') {
            movy[i] = y;
            movx[i] = x + 1;
            moves(s, i + 1, movx, movy, x + 1, y);
        } else if (s.charAt(i) == 'U') {
            movy[i] = y + 1;
            movx[i] = x;
            moves(s, i + 1, movx, movy, x, y + 1);
        } else {
            movy[i] = y - 1;
            movx[i] = x;
            moves(s, i + 1, movx, movy, x, y - 1);
        }

    }


    public static boolean check(String s, int i, int x, int y, int obsx, int obsy) {
        if (i >= s.length()) {
            if (x == 0 && y == 0)
                return true;
            return false;
        }
        boolean status1 = false, status2 = false, status3 = false, status4 = false;
        

        if (s.charAt(i) == 'L') {
            if (x - 1 == obsx && y == obsy)
                status1 = check(s, i + 1, x, y, obsx, obsy);
            else
                status1 = check(s, i + 1, x - 1, y, obsx, obsy);
            

        } else if (s.charAt(i) == 'R') {
            if (x + 1 == obsx && y == obsy)
                status2 = check(s, i + 1, x, y, obsx, obsy);
            else
                status2 = check(s, i + 1, x + 1, y, obsx, obsy);
            

        } else if (s.charAt(i) == 'U') {
            if (y + 1 == obsy && x == obsx)
                status3 = check(s, i + 1, x, y, obsx, obsy);
            else
                status3 = check(s, i + 1, x, y + 1, obsx, obsy);
            

        } else {
            if (y - 1 == obsy && x == obsx)
                status4 = check(s, i + 1, x, y, obsx, obsy);
            else
                status4 = check(s, i + 1, x, y - 1, obsx, obsy);
        }
        return status1 || status2 || status3 || status4;
    }

    public static int mergeAndCount1(div[] arr, int l,
                                     int m, int r,int[] answer) {

        


        div[] left = Arrays.copyOfRange(arr, l, m + 1);

        

        div[] right = Arrays.copyOfRange(arr, m + 1, r + 1);

        int i = 0, j = 0, k = l, swaps = 0;
        for(int x=0;x<right.length;x++)
            answer[right[x].y]+=binse(left,right[x].x,left.length);

        while (i < left.length && j < right.length) {
            if (left[i].x <= right[j].x)
                arr[k++] = left[i++];
            else {
                

                arr[k++] = right[j++];

            }
        }
        while (i < left.length)
            arr[k++] = left[i++];
        while (j < right.length)
            arr[k++] = right[j++];








        return swaps;
    }

    

    public static int mergeSortAndCount(div[] arr, int l,
                                        int r,int[] answer) {

        

        

        int count = 0;

        if (l < r) {
            int m = (l + r) / 2;

            

            


            

            count += mergeSortAndCount(arr, l, m,answer);

            

            count += mergeSortAndCount(arr, m + 1, r,answer);

            

            count += mergeAndCount1(arr, l, m, r,answer);
        }

        return count;
    }


    public static boolean checker(String s1, String s2, int[] arr, int mid) {
        String s = "";
        int N = s1.length();
        boolean[] visited = new boolean[N];
        for (int i = 0; i <= mid; i++)
            visited[arr[i] - 1] = true;
        for (int i = 0; i < N; i++) {
            if (!visited[i])
                s += s1.charAt(i);
        }

        int l = 0, index = -1;
        while (l < s2.length()) {
            if (s.indexOf(s2.charAt(l), index + 1) == -1)
                return false;
            else {
                index = s.indexOf(s2.charAt(l), index + 1);
                ++l;
            }
        }

        return true;
    }

    public static int check(ArrayList<Integer> possible, int X, int start) {
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


    public static int binse(div[] arr, int X, int N) {
        int l = 0, r = N - 1;

        if(arr[N-1].x<=X)
            return N;
        if(arr[0].x>X)
            return 0;
        while (l <= r) {
            int mid = (l + r) / 2;








            if(arr[mid].x<=X)
            {
                if(mid+1<N && arr[mid+1].x<=X)
                    l=mid+1;
                else
                {
                    


                    return mid+1;
                }
            }

            else
                r=mid-1;
        }
        return -1;
    }


    public static long dp(long[][] dp, int X, int[] arr, int index, long mod) {
        

        if (dp[index][X] != -1)
            return dp[index][X];
        int index1 = index + 1;
        int plus = (X - arr[index1] + 10) % 10;
        long ans = dp(dp, plus, arr, index - 1, mod) % mod;
        for (int i = 0; i < 10; i++) {
            if ((arr[index1] * i) % 10 == X)
                ans = (ans % mod + dp(dp, i, arr, index - 1, mod) % mod) % mod;
        }

        dp[index][X] = ans;
        return ans;


    }

    public static long gcd(long a, long b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

    public static int check(int x, ArrayList<ArrayList<Integer>> arr, int parent, int dist, long[] ans, int[] child) {
        ans[0] += dist;
        int c = 0;
        for (int i : arr.get(x)) {
            if (i != parent)
                c += check(i, arr, x, dist + 1, ans, child);
        }

        child[x] = c + 1;
        return c + 1;
    }

    public static void check(int x, int parent, ArrayList<ArrayList<Integer>> arr, int[] child, long[] ans) {
        ans[x] = ans[parent] - (child[x]) + (arr.size() - child[x]);

        for (int i : arr.get(x)) {
            if (i != parent) {
                check(i, x, arr, child, ans);
            }
        }
    }

    public static void leftRotatebyOne(int arr[], int n) {
        int i, temp;
        temp = arr[0];
        for (i = 0; i < n - 1; i++)
            arr[i] = arr[i + 1];
        arr[n - 1] = temp;
    }

    public static void tick(char[][] ch, int N, int M, int x, int y, int k, int[][] copy) {

        int c = 1, size = 0;
        

        while (x - c >= 0 && y - c >= 0 && y + c < M && ch[x - c][y - c] == '*' && ch[x - c][y + c] == '*') {
            ++size;

            ++c;

        }
        

        c -= 1;
        while (c >= 0) {

            copy[x - c][y - c] = Math.max(copy[x - c][y - c], size);
            copy[x - c][y + c] = Math.max(copy[x - c][y + c], size);

            --c;
        }


    }

    public static long dp(ArrayList<Integer> arr,HashMap<Integer,Long> hp)
    {
        if(arr.size()==0)
            return 0;
        long[]dp=new long[arr.size()];
        dp[0]=hp.get(arr.get(0))*arr.get(0);
        if(arr.size()==1)
            return dp[0];
        dp[1]=Math.max(arr.get(1)*(hp.get(arr.get(1))),arr.get(0)*(hp.get(arr.get(0))));
        for(int i=2;i<arr.size();i++)
        {
            int X=arr.get(i);
            dp[i]=Math.max(X*(hp.get(X))+dp[i-2],dp[i-1]);
            dp[i]=Math.max(dp[i],dp[i-2]+X*hp.get(X));
        }





        return dp[arr.size()-1];
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

    public static int check(int N,int[] dp)
    {
        if(N==0)
            return 0;
        if(dp[N]!=-1)
            return dp[N];

        if(N<10)
            return 1;
        int max=Integer.MAX_VALUE;
        int X=N;
        while(X>0)
        {
            int digit=X%10;
            if(digit!=0)
            {
                if(dp[N-digit]==-1)
                    max=Math.min(max,check(N-digit,dp));
                else
                    max=Math.min(max,dp[N-digit]);
            }
            X=X/10;

        }
        dp[N]=max+1;
        return max+1;
    }

    public static int check(int a,int b,int k,int[][] dp,int index,int N,int[] length)
    {
        if(index>=N)
            return 0;
        if(k==1)
        {
            if(N-index<a || N-index>b)
            {
                dp[index][k]=0;
                return 0;
            }
            else
            {
                dp[index][k]=1;
                length[index]=N-index;
                return 1;
            }
        }
        if(dp[index][k]!=-1)
            return dp[index][k];

        int ans=0;
        for(int i=a;i<=b;i++)
        {
            if(check(a,b,k-1,dp,index+i,N,length)==1)
            {
                length[index]=i;
                ans=1;
            }
        }
        if(ans>=1)
        {
            dp[index][k]=1;
            return 1;
        }
        else
        {
            dp[index][k]=0;
            return 0;
        }
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
    public static String answer(String s1,String s2)
    {
        int index=0;
        boolean status=true;
        for(int i=0;i<s2.length();i++)
        {
            if(s1.indexOf(s2.charAt(i),index)==-1)
            {
                status=false;
            }
            else
            {
                index=s1.indexOf(s2.charAt(i),index)+1;
            }
        }
        if(status)
            return "automaton";


        String arr1[]=s1.split("");
        String arr2[]=s2.split("");
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        if(Arrays.equals(arr1,arr2))
            return "array";

        HashMap<Character,Integer> hp=new HashMap<>();
        for(int i=0;i<s2.length();i++)
        {
            hp.put(s2.charAt(i),0);
        }
        for(int i=0;i<s2.length();i++)
        {
            if(s1.indexOf(s2.charAt(i),hp.get(s2.charAt(i)))==-1)
            {
                return "need tree";
            }
            else
            {
                hp.put(s2.charAt(i),s1.indexOf(s2.charAt(i),hp.get(s2.charAt(i)))+1);
            }
        }

        return "both";



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

    public static boolean check(int N)
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






    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));


        int T=Reader.nextInt();
        A:for(int m=1;m<=T;m++)
        {
            int N=Reader.nextInt();
            int K=Reader.nextInt();
            ArrayList<ArrayList<Integer>> arr=new ArrayList<>();
            for(int i=0;i<N;i++)
                arr.add(new ArrayList<>());
            int[] in=new int[N];
            for(int i=0;i<N-1;i++)
            {
                int x=Reader.nextInt()-1;
                int y=Reader.nextInt()-1;
                arr.get(x).add(y);
                arr.get(y).add(x);
                in[x]++;
                in[y]++;
            }

            int req=0;
            if(K==0)
            {
                output.write(N+"\n");
                continue;
            }
            Queue<Integer> queue=new LinkedList<>();
            int minus=0;

            for(int i=0;i<N;i++)
            {
                if(in[i]<2)
                {
                    queue.add(i);
                    in[i]=0;
                }
            }
            queue.add(-1);
            while(queue.size()>0)
            {
                int temp=queue.poll();
                if(temp==-1)
                {
                    ++req;
                    if(req==K || queue.size()==0)
                        break;
                    else if(queue.size()>0)
                    {
                        queue.add(-1);
                        continue ;
                    }

                }
                ++minus;
                for(int i:arr.get(temp))
                {
                    if(in[i]==2 || in[i]==1)
                    {
                        in[i]=0;
                        queue.add(i);
                    }
                    else
                        in[i]--;
                }

            }

            output.write(N-minus+"\n");




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

class div {
    int x, y;

    div(int x1, int y1) {
        x = x1;
        y = y1;
    }
}