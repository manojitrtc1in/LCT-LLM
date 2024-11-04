import java.math.*;
import java.util.*;
import java.io.*;



public class Main
{
    static Map<String,Integer> map=new HashMap<>();
    static int[] parent;
    static  int[] size;
    public static void main(String[] args)
    {
        InputReader in = new InputReader(System.in);
        PrintWriter pw = new PrintWriter(System.out);













        final int mod=1000000007;
        

        int test_case=in.nextInt();
        

        StringBuilder sb=new StringBuilder();
        

        long[] fact=new long[100001];
        fact[0]=1;
        fact[1]=1;
        fact[2]=1;
        for(int i=3;i<fact.length;i++)
        {
            fact[i]=((fact[i-1])%mod*(i%mod))%mod;
            

        }

        for(int t1=0;t1<test_case;t1++) {

            int n = in.nextInt();

            if(n%2 == 1){
                System.out.println("-1");
            }else{
                System.out.println("0 "+n/2+" "+(n/2+n%2));
            }

        }

        pw.flush();
        pw.close();
    }

    private static void dfss(List<List<Integer>> ls, List<Integer> stack, boolean[] visited) {

        int x=stack.get(stack.size()-1);
        for(int child:ls.get(x))
        {

            if(!visited[child])
            {
                stack.add(child);
                visited[child]=true;
                dfss(ls,stack,visited);
                stack.remove(stack.size()-1);
            }
        }


    }

    static  boolean id8(int x,int y,TreeSet<Integer> set)
    {
        if(set.contains(x))return false;

        if(set.higher(x)!=null&&set.higher(x)<=y) return  false;

        return  true;
    }

    static boolean id12(String ans,String max)
    {
        if(ans.length()>max.length())
        {
            return true;
        }else if(max.length()>ans.length())
        {
            return false;
        }else{
            for(int i=0;i<ans.length();i++)
            {
                


                if(ans.charAt(i)==max.charAt(i))
                {
                    continue;
                }

                if(ans.charAt(i)<max.charAt(i))
                {
                    

                    return false;
                }else{
                    return true;
                }
            }

            return true;
        }
    }

    static  void solve(int[] a,List<Integer>  ls,int n,boolean[] f,int ans,int c,int r,int k)
    {
        if(k==n)
        {
            ls.add(ans);
            max=Math.max(ans,max);
            return  ;
        }

        for(int i=0;i<n;i++)
        {

            if(f[i])
            {
                continue;
            }
            f[i]=true;
            for(int j=0;j<n;j++)
            {

                if(f[j])
                {
                    continue;
                }
                int ans1=(GCD(a[i],a[j])*r);
                ans+=ans1;
                f[j]=true;
                solve(a,ls,n,f,ans,0,r+1,k+2);
                ans-=ans1;
                f[j]=false;

            }
            f[i]=false;

        }

    }





    static int LowerBound(int a[], int key) { 

        int low=0;
        int   high=a.length-1;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(key<=a[mid])
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return high;
    }

    static int UpperBound(int a[], int key) {

        int low=0;
        int high=a.length-1;

        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(key>=a[mid])
            {
                low=mid+1;
            }else{
                high=mid-1;
            }
        }    return low;
    }

    static   int max=0;



    static boolean backtrack(int i,int j,int[][] a,int[][] gol,int n,Set<String> set,int parentx,int parenty)
    {
        System.out.println(i+" "+j);

        if(Arrays.equals(a,gol))
        {
            return true;
        }

        boolean f=false;

        int[] dx={-1,0,0,1};
        int[] dy={0,-1,1,0};
        set.add(i+"root"+j);
        for(int k=0;k<dx.length;k++)
        {



            if((i+dx[k])>=0&&(i+dx[k])<n&&(j+dy[k])>=0&&(j+dy[k])<n)
            {
                if(i+dx[k]==parentx&&j+dy[k]==parenty||set.contains((i+dx[k])+"root"+(j+dy[k])))
                {
                    continue;
                }

                

                int temp=a[i][j];
                a[i][j]=a[i+dx[k]][j+dy[k]];
                a[i+dx[k]][j+dy[k]]=temp;
                f=backtrack(i+dx[k],j+dy[k],a,gol,n,set,i,j);
                if(f)
                {
                    System.out.println(temp+" "+a[i][j]);
                    return f;
                }
                temp=a[i][j];
                a[i][j]=a[i+dx[k]][j+dy[k]];
                a[i+dx[k]][j+dy[k]]=temp;
            }
        }
        

        return f;



    }

    static int find_parent(int p)
    {
      if(p==parent[p])
        {
            return p;
        }
        return parent[p]=find_parent(parent[p]);
    }

    static void set_union(int x,int y)
    {

        if(size[x]<size[y])
        {
            swap(x,y);
        }

        parent[y]=x;

        size[x]+=size[y];
        size[y]=0;
    }

    static boolean id15(int i,List<List<Integer>> ls,boolean[] visited,int[] color, int x)
    {

        color[i]=x;
        visited[i]=true;

        for(int x1:ls.get(i))
        {

            


            if(visited[x1]&&color[x1]==x)
            {
                return false;
            }

            if(!visited[x1])
            {
                return  id15(x1,ls,visited,color,(x==-1?1:-1));
            }
        }

        return true;

    }


    static boolean id5(List<Integer> stack,boolean[] visited,List<List<Integer>>  ls)
    {
        int i=stack.get(stack.size()-1);
        visited[i]=true;
        for(int x:ls.get(i))
        {
            stack.add(x);
            if(!visited[x]&&id5(stack,visited,ls))
            {
                return true;
            }

            if(stack.contains(x))
            {
                return true;
            }
            stack.remove(stack.size()-1);


        }

        return false;
    }

    static boolean id3(int i,List<List<Integer>> ls,boolean[] visited,int parent)
    {
        visited[i]=true;
        for(int x:ls.get(i))
        {
            if(x!=parent){

                if(visited[x])
                {
                    return true;
                }

                if(!visited[x]&&id3(x,ls,visited,i))
                {
                    return true;
                }

            }


        }

        return false;
    }

    static void dfs(List<List<Integer>> ls,boolean[] f,List<Integer> stack)
    {
        int x=stack.remove(stack.size()-1);
        System.out.print(x+"->");
        f[x]=true;
        for(int x1:ls.get(x))
        {
            if(!f[x1])
            {
                stack.add(x1);
                dfs(ls,f,stack);
            }

        }

    }

    static int factorial(int n,int mod)
    {
        long res = 1;
        for (int i=2; i<=n; i++)
            res=((res%mod)*(i%mod))%mod;
        return (int)res;
    }




    static int length(long l)
    {
        int c=0;
        while(l>0)
        {
            c++;
            l/=2;
        }

        return c;
    }


    static int id16(int A[], int l, int r, int key)
    {
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (A[m] <= key)
                r = m;
            else
                l = m;
        }

        return r;
    }
    static int id2(int A[], int size)
    {
        


        int[] tailTable = new int[size];
        int len; 


        tailTable[0] = A[0];
        len = 1;
        for (int i = 1; i < size; i++) {
            if (A[i] > tailTable[0])

                tailTable[0] = A[i];

            else if (A[i] <= tailTable[len - 1])

                tailTable[len++] = A[i];

            else

                tailTable[id16(tailTable, -1, len - 1, A[i])] = A[i];
        }

        return len;
    }



    static int[] next(int arr[], int n) {

        Stack<Integer> S = new Stack<>();

        int[] next=new int[n];

        for (int i = n-1; i >= 0; i--) {

            while (!S.empty() && arr[S.peek()] <= arr[i]) {
                S.pop();

            }
            if (S.empty()) {
                next[i]=-1;
            }
            else
            {

                next[i]=S.peek();
            }
            S.push(i);
        }
        return next;
    }
    static int[] back(int arr[], int n) {

        Stack<Integer> S = new Stack<>();

        int[] back=new int[n];

        for (int i = 0; i < n; i++) {

            while (!S.empty() && arr[S.peek()] < arr[i]) {
                S.pop();
            }
            if (S.empty()) {
                back[i]=-1;
            }
            else
            {
                back[i]=S.peek();
            }
            S.push(i);
        }

        return back;
    }




    static class InputReader
    {

        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, id6;
        private id14 filter;

        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }

        public int snext()
        {
            if (id6 == -1)
                throw new InputMismatchException();
            if (curChar >= id6)
            {
                curChar = 0;
                try
                {
                    id6 = stream.read(buf);
                }
                catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                if (id6 <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt()
        {
            int c = snext();
            while (id1(c))
            {
                c = snext();
            }
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = snext();
            }
            int res = 0;
            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!id1(c));
            return res * sgn;
        }

        public long nextLong()
        {
            int c = snext();
            while (id1(c))
            {
                c = snext();
            }
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = snext();
            }
            long res = 0;
            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!id1(c));
            return res * sgn;
        }

        public int[] id7(int n)
        {
            int a[] = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = nextInt();
            }
            return a;
        }
        public long[] id0(int n)
        {
            long a[] = new long[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = nextLong();
            }
            return a;
        }

        public String readString()
        {
            int c = snext();
            while (id1(c))
            {
                c = snext();
            }
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c = snext();
            } while (!id1(c));
            return res.toString();
        }

        public String nextLine()
        {
            int c = snext();
            while (id1(c))
                c = snext();
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c = snext();
            } while (!id9(c));
            return res.toString();
        }

        public boolean id1(int c)
        {
            if (filter != null)
                return filter.id1(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private boolean id9(int c)
        {
            return c == '\n' || c == '\r' || c == -1;
        }

        public interface id14
        {
            public boolean id1(int ch);
        }
    }

    public static long mod = 1000000007;
    public static int d;
    public static int p;
    public static int q;

    public static int[] suffle(int[] a,Random gen)
    {
        int n = a.length;
        for(int i=0;i<n;i++)
        {
            int ind = gen.nextInt(n-i)+i;
            int temp = a[ind];
            a[ind] = a[i];
            a[i] = temp;
        }
        return a;
    }

    public static void swap(int a, int b){
        int temp = a;
        a = b;
        b = temp;
    }

    public static HashSet<Integer> id4(int n)
    {
        HashSet<Integer> a =new HashSet<Integer>();
        for(int i=2;i*i<=n;i++)
        {
            while(n%i==0)
            {
                a.add(i);
                n/=i;
            }
        }
        if(n!=1)
            a.add(n);
        return a;
    }

    public static void sieve(boolean[] isPrime,int n)
    {
        for(int i=1;i<n;i++)
            isPrime[i] = true;

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i=2;i*i<n;i++)
        {
            if(isPrime[i] == true)
            {
                for(int j=(2*i);j<n;j+=i)
                    isPrime[j] = false;
            }
        }
    }

    public static int GCD(int a,int b)
    {
        if(b==0)
            return a;
        else
            return GCD(b,a%b);
    }

    public static long GCD(long a,long b)
    {
        if(b==0)
            return a;
        else
            return GCD(b,a%b);
    }

    public static void id10(int A,int B)
    {
        if(B==0)
        {
            d = A;
            p = 1 ;
            q = 0;
        }
        else
        {
            id10(B, A%B);
            int temp = p;
            p = q;
            q = temp - (A/B)*q;
        }
    }

    public static long LCM(long a,long b)
    {
        return (a*b)/GCD(a,b);
    }

    public static int LCM(int a,int b)
    {
        return (a*b)/GCD(a,b);
    }

    public static int id13(int x,int n)
    {
        int result=1;
        while(n>0)
        {
            if(n % 2 ==1)
                result=result * x;
            x=x*x;
            n=n/2;
        }
        return result;
    }
    int binarySearch(int arr[], int l, int r, int x)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;


            if (arr[mid] == x)
                return mid;


            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);


            return binarySearch(arr, mid + 1, r, x);
        }


        return -1;
    }


    public static long id13(long x,long n)
    {
        long result=1;
        while(n>0)
        {
            if(n % 2 ==1)
                result=result * x;
            x=x*x;
            n=n/2;
        }
        return result;
    }

    public static int id11(int x,int n,int M)
    {
        int result=1;
        while(n>0)
        {
            if(n % 2 ==1)
                result=(result * x)%M;
            x=(x*x)%M;
            n=n/2;
        }
        return result;
    }

    public static long id11(long x,long n,long M)
    {
        long result=1;
        while(n>0)
        {
            if(n % 2 ==1)
                result=(result * x)%M;
            x=(x*x)%M;
            n=n/2;
        }
        return result;
    }

    public static int modInverse(int A,int M)
    {
        return id11(A,M-2,M);
    }

    public static long modInverse(long A,long M)
    {
        return id11(A,M-2,M);
    }

    public static boolean isPrime(int n)
    {

        if (n <= 1)  return false;
        if (n <= 3)  return true;

        if (n%2 == 0 || n%3 == 0)
            return false;

        for (int i=5; i*i<=n; i=i+6)
        {
            if (n%i == 0 || n%(i+2) == 0)
                return false;
        }

        return true;
    }
    static class Pair
    {
        int  x;
        int  y;
    }

    static class pair implements Comparable<pair>
    {
        Integer x, y;
        pair(int x,int y)
        {
            this.x=x;
            this.y=y;
        }

        public int compareTo(pair o) {
            int result = x.compareTo(o.x);
            if(result==0)
                result = y.compareTo(o.y);

            return result;
        }

        public String toString()
        {
            return x+" "+y;
        }

        public boolean equals(Object o)
        {
            if (o instanceof pair)
            {
                pair p = (pair)o;
                return (Math.abs(p.x-x)==0 && Math.abs(p.y-y)==0);
            }
            return false;
        }









    }
}