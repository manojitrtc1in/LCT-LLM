

import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.*;
public class ll
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

    static final int MAXN = 100001;
    

    static int spf[] = new int[MAXN];
    

    

    

    static void sieve()
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
    

    

    static int id0(int x)
    {
        int c=0;
        while (x != 1)
        {
            c++;
            x = x / spf[x];
        }
        return c;
    }
    
    
    public static int findIndex(long arr[], long t) 
    { 
        if (arr == null) { 
            return -1; 
        } 
        int len = arr.length; 
        int i = 0; 
        while (i < len) { 
            if (arr[i] == t) { 
                return i; 
            } 
            else { 
                i = i + 1; 
            } 
        } 
        return -1; 
    }

    static int gcd(int a, int b)
    {
        if (a == 0)
            return b; 
        return gcd(b % a, a); 
    }

    

    static int lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }

    public static int[] swap(int a[], int left, int right)
    {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        return a;
    }

    public static int[] reverse(int a[], int left, int right)
    {
        

        while (left < right) {
            int temp = a[left];
            a[left++] = a[right];
            a[right--] = temp;
        }
        return a;
    }

    public static int[] id1(int a[])
    {
        int last = a.length - 2;

        

        

        while (last >= 0) {
            if (a[last] < a[last + 1]) {
                break;
            }
            last--;
        }

        

        

        if (last < 0)
            return a;

        int nextGreater = a.length - 1;

        

        for (int i = a.length - 1; i > last; i--) {
            if (a[i] > a[last]) {
                nextGreater = i;
                break;
            }
        }

        

        a = swap(a, nextGreater, last);

        

        a = reverse(a, last + 1, a.length - 1);

        

        return a;
    }

    static void sort(int[] a) {
        ArrayList<Integer> l = new ArrayList<>();
        for (int i : a)
            l.add(i);
        Collections.sort(l);
        for (int i = 0; i < a.length; i++)
            a[i] = l.get(i);
    }

    static double pow(double p,double tt)
    {
        double ii,q,r;
        q=1;
        r=p;
        while(tt>1)
        {
            for(ii=1;2*ii<=tt;ii*=2)
                p*=p;
            tt-=ii;
            q*=p;
            p=r;
        }
        if(tt==1)
            q*=r;
        return q;
    }

    static int factorial(int n)
    {
        return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
    }

    public static long primeFactors(long n)
    {
        long c=0l;
        long max=0l;
        long z=0l;
        

        

        while (n%2==0)
        {
            c++;
            n /= 2l;
            

        }
        if(c>max)
        {
            max=c;
            z=2;
        }
        

        

        for (int i = 3; i <= Math.sqrt(n); i+= 2)
        {
            

            c=0;
            while (n%i == 0)
            {
                c++;
                n /= i;
                

            }
            if(c>max)
            {
                max=c;
                z=i;
            }
        }
        c=0;
        

        

        if (n > 2)
        {
            c++;
            

        }
        if(c>max)
        {
            max=c;
            z=n;
        }
        return z;
    }

    static void PrimeList(){
        int i,j;
        int sieve[]=new int[100001];
        for(i=2;i*i<=100000;i++)
        {
            if(sieve[i]==0)
            {
                for(j=i*i;j<=100000;j+=i)
                    sieve[j]=1;
            }
        }
        ArrayList<Integer> primes=new ArrayList<>();
        for(i=2;i<=100000;i++)
        {
            if(sieve[i]==0)
                primes.add(i);
        }
    }

    static int comp(int a[],int b[],int n)
    {
        int z=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                z=1;
                break;
            }
        }
        if(z==0)
            return 1;
        else
            return 0;
    }
    static int ab[]=new int[101];
    static void pt (int ab[],int a[],int l,int r,int h)
    {
        int max=0;
        int z=-1;
        for(int i=l;i<r;i++)
        {
            if(a[i]>max)
            {
                max=a[i];
                z=i;
            }
        }
        if(z!=-1)
        {
            ab[z]=h;
            a[z]=0;
            pt(ab,a,l,z,h+1);
            pt(ab,a,z,r,h+1);
        }
        else
            return;
    }

    static int ck(char a[][],int n,int m)
    {
        int z=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='.')
                    z=1;
                break;
            }
            if(z==1)
                break;
        }
        if(z==1)
            return 0;
        else 
            return 1;
    }

    public static void main(String[] args) 
    {
        

        

        FastReader d=new FastReader();
        int t,i,j,c,z,k,l,r,n,q;
        int mod = (int) 1e9 + 7;

        int Inf=Integer.MAX_VALUE;
        int negInf=Integer.MIN_VALUE;
        t=d.nextInt();
        

        

        

        long ans;
        while(t-->0)
        {
            z=c=0;
            ans=0l;
            n=d.nextInt();
            int m=d.nextInt();
            String s[]=new String[n];
            for(i=0;i<n;i++)
                s[i]=d.nextLine();
            char a[][]=new char[n][m];
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    a[i][j]=s[i].charAt(j);
                }
            }
            int cc=0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(a[i][j]=='R')
                    {
                        c=1;
                        cc=j;
                        

                        if(i!=0 && a[i-1][j]=='R' || i!=n-1 && a[i+1][j]=='R' || j!=0 && a[i][j-1]=='R' || j!=m-1 && a[i][j+1]=='R')
                        {
                            z=1;
                            break;
                        }
                        else
                        {
                            if(i!=0 )
                            {
                                k=1;
                                while(i-k>=0 )
                                {
                                    if(k%2==1 && a[i-k][j]!='R')
                                        a[i-k][j]='W';
                                    else if(k%2==1)
                                    {
                                        z=1;
                                        break;
                                    }
                                    else if(a[i-k][j]!='W')
                                        a[i-k][j]='R';
                                    else
                                    {
                                        z=1;
                                        break;
                                    }

                                    k++;
                                }
                            }
                            if(i!=n-1 )
                            {
                                

                                k=1;
                                while(i+k<=n-1 )
                                {
                                    if(k%2==1 && a[i+k][j]!='R')
                                        a[i+k][j]='W';
                                    else if(k%2==1)
                                    {
                                        z=1;
                                        break;
                                    }
                                    else if(a[i+k][j]!='W')
                                        a[i+k][j]='R';
                                    else
                                    {
                                        z=1;
                                        break;
                                    }
                                    k++;
                                }
                            }
                        }
                    }
                    else if(a[i][j]=='W')
                    {
                        

                        c=1;
                        cc=j;
                        if(i!=0 && a[i-1][j]=='W' || i!=n-1 && a[i+1][j]=='W' || j!=0 && a[i][j-1]=='W' || j!=m-1 && a[i][j+1]=='W')
                        {
                            z=1;
                            break;
                        }

                        else
                        {
                            if(i!=0 )
                            {
                                k=1;
                                while(i-k>=0 )
                                {
                                    if(k%2==1 && a[i-k][j]!='W')
                                        a[i-k][j]='R';
                                    else if(k%2==1)
                                    {
                                        z=1;
                                        break;
                                    }
                                    else if(a[i-k][j]!='R')
                                        a[i-k][j]='W';
                                    else
                                    {
                                        z=1;
                                        break;
                                    }

                                    k++;
                                }
                            }
                            if(i!=n-1 )
                            {
                                

                                k=1;
                                while(i+k<=n-1 )
                                {
                                    if(k%2==1 && a[i+k][j]!='W')
                                        a[i+k][j]='R';
                                    else if(k%2==1)
                                    {
                                        z=1;
                                        

                                        break;
                                    }
                                    else if(a[i+k][j]!='R')
                                        a[i+k][j]='W';
                                    else
                                    {
                                        z=1;
                                        break;
                                    }
                                    k++;
                                }
                            }
                        }
                    }
                    if(z==1 || c==1)
                        break;
                }
                if(z==1 || c==1)
                    break;
            }
            if(z==0){
            for(i=0;i<n;i++)
            {

                if(a[i][cc]=='R')
                {
                    

                    j=cc;
                    if(j!=0 )
                    {
                        

                        k=1;
                        while(j-k>=0 )
                        {
                            if(k%2==1 && a[i][j-k]!='R')
                                a[i][j-k]='W';
                            else if(k%2==1)
                            {
                                z=1;
                                break;
                            }
                            else if(a[i][j-k]!='W')
                                a[i][j-k]='R';
                            else
                            {
                                z=1;
                                break;
                            }

                            k++;
                        }
                        if(z==1)
                        break;
                    }
                    j=cc;
                    if(j!=m-1 )
                    {
                        

                        k=1;
                        while(j+k<=m-1 )
                        {
                            if(k%2==1 && a[i][j+k]!='R')
                                a[i][j+k]='W';
                            else if(k%2==1)
                            {
                                z=1;
                                break;
                            }
                            else if(a[i][j+k]!='W')
                                a[i][j+k]='R';
                            else
                            {
                                z=1;
                                break;
                            }

                            k++;
                        }
                        if(z==1)
                        break;
                    }
                }
                else if(a[i][cc]=='W')
                {
                    j=cc;
                    if(j!=0 )
                    {
                        

                        k=1;
                        while(j-k>=0 )
                        {
                            if(k%2==1 && a[i][j-k]!='W')
                                a[i][j-k]='R';
                            else if(k%2==1)
                            {
                                z=1;
                                break;
                            }
                            else if(a[i][j-k]!='R')
                                a[i][j-k]='W';
                            else
                            {
                                z=1;
                                break;
                            }

                            k++;
                        }
                        if(z==1)
                        break;
                    }
                    j=cc;
                    if(j!=m-1 )
                    {
                        

                        k=1;
                        while(j+k<=m-1 )
                        {
                            if(k%2==1 && a[i][j+k]!='W')
                                a[i][j+k]='R';
                            else if(k%2==1)
                            {
                                z=1;
                                break;
                            }
                            else if(a[i][j+k]!='R')
                                a[i][j+k]='W';
                            else
                            {
                                z=1;
                                break;
                            }

                            k++;
                        }
                        if(z==1)
                        break;
                    }
                }
            }
        }
        
            if(z==1)
                System.out.println("NO");
            else
            {
                System.out.println("YES");
                char ch1='R';
                char ch2='W';
                for(i=0;i<n;i++)
                {
                    
                    for(j=0;j<m;j++)
                    {
                        if(a[i][j]!='.')
                        System.out.print(a[i][j]);
                        else
                        {
                            a[i][j]=ch1;
                            System.out.print(ch1);
                            if(ch1=='R')
                            {ch1='W';}
                            else
                            {ch1='R';}
                        }
                        

                    }
                    System.out.println();
                    ch2=a[i][0];
                    if(ch2=='R')
                    {ch1='W';}
                    else
                    {ch1='R';}
                }
            }
            

        }
        
    }
}
 