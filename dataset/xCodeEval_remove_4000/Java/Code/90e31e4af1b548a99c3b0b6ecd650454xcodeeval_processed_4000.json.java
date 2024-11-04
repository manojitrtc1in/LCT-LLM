import java.io.*;
import java.util.*;

import javax.sound.midi.SysexMessage;

import java.math.*;


public class Main
 {












 
































 














 


































 


























 








 
































 


















 






 










 








 














 












 















    
public String ns() throws IOException
    {
        return(read.nextLine());
    }
    public String wrd() throws IOException
    {
        return(read.next());
    }
    public int ni() throws IOException
    {
        return(read.nextInt());
    }
    public double nd() throws IOException
    {
        return(read.nextDouble());
    }
    public long nl() throws IOException
    {
        return(read.nextLong());
    }
    public int[] ai(int n) throws IOException
    {
        int arr[] = new int[n];
        for(int i = 0; i<n; i++)
            arr[i] = read.nextInt();
        return(arr);
    }
    public double[] ad(int n) throws IOException
    {
        double arr[] = new double[n];
        for(int i = 0; i<n; i++)
            arr[i] = read.nextDouble();
        return(arr);
    }
    public long[] al(int n) throws IOException
    {
        long arr[] = new long[n];
        for(int i = 0; i<n; i++)
            arr[i] = read.nextLong();
        return(arr);
    }




    class FastReader 
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new InputStreamReader(System.in));
            if (System.getProperty("ONLINE_JUDGE") == null) 
            {
                 try 
                {
                    InputStream inputStream = new FileInputStream("input.txt");
                    InputStreamReader id4 = new InputStreamReader(inputStream);
                    System.setOut(new PrintStream(new FileOutputStream("output.txt")));
                     br = new BufferedReader(id4);
                }
               catch (Exception e) 
               {
                e.printStackTrace();
               }
            }
        }

    String next()
    {
        while (st == null || !st.hasMoreElements()) 
        {
            try 
            {
                st = new StringTokenizer(br.readLine());
            }
            catch (IOException e) 
            {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() { return Integer.parseInt(next()); }

    long nextLong() { return Long.parseLong(next()); }

    double nextDouble(){return Double.parseDouble(next());}

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
public static void main(String[] args) throws IOException
    
    {
        Main obj = new Main();
        obj.solve();
        

        
    }
    public int getParent(int parent[], int src)
    {
        if(parent[src] != src)
        {
            int ultimateparent = getParent(parent, parent[src]);
            parent[src] = ultimateparent;
            return ultimateparent;
        }
        return src;
    }

    public boolean union(int i, int j, int parent[] , int rank[])
    {

        int root1 = getParent(parent, i);
        int root2 = getParent(parent, j);
        if(root1 == root2)
            return false;

        if(rank[root1] == rank[root2])
        {
            parent[root1] = root2;
            rank[root2]++ ;
        }
        else if(rank[root1] > rank[root2])
        {
            parent[root2] = root1;
        }
        else 

        {
            parent[root1] = root2;
        }
        return true;
    }


    public int log(long x)
    {
        return (int) (Math.log(x) / Math.log(2) + 1e-10);
    }

    public int fact(int n)
    {
        if (n <= 1)
            return 1;
        return n * fact(n - 1);
    }
 
    public int nPr(int n, int r)
    {
        return fact(n) / fact(n - r);
    }

    public long id6(long n, long r)
    {
        

        long ans = 1;
        for(long i = (n-r+1); i<=n; i++)
            ans *= i;

        for(long i = 2; i<=r; i++)
            ans /= i;

        return ans;
    }
    public long id0(long n, long r)
    {
        

        long ans = 1;
        for(long i = r+1; i<=n; i++)
            ans *= i;

        for(long i = 2; i<=(n-r); i++)
            ans /= i;

        return ans; 
    }

    public long binomial(int n, int r, long dp[][])
    {
        

        

        

        

        if(dp[n][r] != 0l)
            return dp[n][r];
        if(r == 0)
            return 1;
        if(n < r)
            return 0;
        dp[n][r] = ( ((n*1l)* binomial(n-1, r-1, dp) )/ r);
        return(dp[n][r]);
        
    }
    long gcd (long a, long b) 
    {
        

      long r, i;
      while(b!=0)
      {
        r = a % b;
        a = b;
        b = r;
      }
      

      return a;
    }
    public int getParent(int root, int parent[])
    {
        if(parent[root] == root)
        {
            return(root);
        }
        parent[root] = getParent(parent[root], parent);
        return(parent[root]);
    }

    public void buildtree(long segmentTree[], int idx, int start, int end, long arr[])
    {
        if(start == end)
        {
            segmentTree[idx] = arr[start];
            return;
        }

        int mid = (end + start)/2;

        buildtree(segmentTree, 2*idx, start, mid, arr);
        buildtree(segmentTree, 2*idx + 1, mid+1, end, arr);

        segmentTree[idx] = gcd(segmentTree[2*idx] , segmentTree[2*idx +1]);
    }

    public long query(long segmentTree[] , int idx, int start, int end, int id7, int queryend)
    {
        if(start >= id7 && end <= queryend)
            return(segmentTree[idx]);
        else if(end < id7 || start > queryend)
            return 0;
        else
        {
            int mid = (end + start)/2;
            long leftQuery = query(segmentTree, 2*idx, start, mid, id7, queryend);
            long rightQuery = query(segmentTree, 2*idx + 1, mid+1, end, id7, queryend);
            return(gcd(leftQuery , rightQuery));
        }
    }

    void reverse(char arr[])
    {
        int mid = arr.length/2;
        int len = arr.length;

        for(int i = 0; i<mid; i++)
        {
            char temp = arr[i];
            arr[i] = arr[len - i - 1];
            arr[len - i - 1] = temp;
        }}
    String reverse(String s)
    {
        StringBuilder sb = new StringBuilder(s);
        return(sb.reverse().toString());
    }

    class Trie
    {
        Trie children[];
        int count;

        Trie()
        {
            children = new Trie[2];
            count = 0;
        }
    }

    void insertTrie(Trie head, char arr[])
    {
        int idx = 0;
        Trie curr = head;
        while( idx < arr.length)
        {
            int mod = (arr[idx]-'0')%2;
            if(curr.children[mod] == null)
            {
                curr.children[mod] = new Trie();
            }
            curr = curr.children[mod];
            curr.count++;
            idx++;

        }
    }

    void removeTrie(Trie head, char arr[])
    {
        int idx = 0;
        Trie curr = head;
        while( idx < arr.length)
        {
            int mod = (arr[idx]-'0')%2;
            curr = curr.children[mod];
            curr.count--;
            idx++;
        }
    }

    int query(Trie head, char pattern[])
    {
        int idx = 0;
        Trie curr = head;

        while( idx < pattern.length)
        {
            int mod = (pattern[idx]-'0');
            if(curr.children[mod] == null)
                return 0;
            curr = curr.children[mod];
            idx++;
        }
        return (curr == null ? 0 : curr.count);
    }


    void id8(boolean prime[], int n)
    {
        

        for (int i = 0; i <= n; i++)
            prime[i] = true;
 
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        } }
    long power(long x, long y, long p) 
    {
         
        long res = 1;
        x = x % p;
 
        while (y > 0) {
             
            

            if ((y & 1) == 1)
                res = (res * x) % p;
         
            

            y = y >> 1; 

            x = (x * x) % p;
        }
         
        return res;
    }
    boolean id1(long d, long n) 
    {
         
        

        

        long a = 2 + (int)(Math.random() % (n - 4));
     
        

        long x = power(a, d, n);
     
        if (x == 1 || x == n - 1)
            return true;
     
        

        

        

        

        

        while (d != n - 1) {
            x = (x * x) % n;
            d *= 2;
         
            if (x == 1)
                return false;
            if (x == n - 1)
                return true;
        }
     
        

        return false;
    }
    boolean isPrime(long n, int k) 
    {
         
        

        if (n <= 1 || n == 4)
            return false;
        if (n <= 3)
            return true;
     
        

        

        long d = n - 1;
         
        while (d % 2 == 0)
            d /= 2;
     
        

        for (long i = 0; i < k; i++)
            if (!id1(d, n))
                return false;
     
        return true;
    }

    ArrayList<Long> id2(long n)
    {
        ArrayList<Long> list = new ArrayList<>();

        for (long i = 2; i <= Math.sqrt(n); i++) 
        {
            if (n % i == 0) 
            {
                 if (n / i == i)
                {
                    list.add(i);
                }
                else 
                {
                    list.add(i);
                    list.add(n/i);
                }
            }
        }

        return(list);
    }


    public boolean isPalindrome(char arr[], int startIndex, int endIndex) 
    {
        for(int i = startIndex, j = endIndex; i <= j; i++, j--) 
                {
                    if (arr[i] != arr[j]) 
                        return false;
                }
        return true;
    }

public int id9(char arr[], int left, int right) 
{
    int n = right - left + 1;
    int id5 = 0;
    int id3 = 0;
    
    for(int currentIndex = left; currentIndex < n; currentIndex++) 
    {
        if(isPalindrome(arr,currentIndex - id5, currentIndex))
        {
            id5 += 1;
            id3 = currentIndex;
        } 
        else if(currentIndex - id5 - 1 >= 0 && isPalindrome(arr, currentIndex - id5 - 1, currentIndex)) 
        {
            id5 += 2;
            id3 = currentIndex;
        }   
    }
    id3++;
    return(id5);
}






    long MODULO = 1000000007;
    FastReader read;
    StringBuilder sb;


    
    public void solve() throws IOException
    {
        sb = new StringBuilder();
        read = new FastReader();

        int t = ni();
        for(int tt = 0; tt < t; tt++)
        {
            int n = ni();
            long arr1[] = new long[n];
            long arr2[] = new long[n];
            int greater[] = new int[n];
            Arrays.fill(greater, -1);

            for(int i = 0; i<n; i++)
                arr1[i] = nl();
            for(int i = 0; i<n; i++)
                arr2[i] = nl();

            


            


            for(int i = 0; i<n; i++)
            {
                for(int j = (int) ((arr2[i]-2)/2); j>=0; j--)
                    {
                        if(greater[j] == -1)
                            greater[j] = i;
                        else
                            break;
                    }
            }

            long min = Long.MAX_VALUE;

            for(int i = 0; i<n; i++)
            {
                min = Math.min(min, i + greater [(int) ((arr1[i] -1 )/2)]   ) ;
                

            }

            

            sb.append(min).append("\n");


        }

        System.out.println(sb);


    }


}