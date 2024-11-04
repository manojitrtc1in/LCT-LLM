import java.io.*;
import java.util.*;
import java.lang.*;
import java.util.HashMap;
import java.util.PriorityQueue;
public class templ implements Runnable {
    class pair
    {
        int f,s;
        pair(int fi,int se)
        {
            f=fi;
            s=se;
        }
    }
    static int binarySearch(int arr[], int l, int r, int x)
    {
        if (r >= l)
        {
            int mid = l + (r - l)/2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] > x)
                return binarySearch(arr, l, mid-1, x);
            return binarySearch(arr, mid+1, r, x);
        }
        return -1;
    }
    void merge1(int arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[] = new int [n1];
        int R[] = new int [n2];
        for (int i=0; i<n1; ++i)
            L[i] = arr[l + i];
        for (int j=0; j<n2; ++j)
            R[j] = arr[m + 1+ j];
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i]<=R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    void sort1(int arr[], int l, int r)
    {
        if (l < r)
        {
            int m = (l+r)/2;
            sort1(arr, l, m);
            sort1(arr , m+1, r);
            merge1(arr, l, m, r);
        }
    }
    void merge3(int arr[],int arr1[],int arr2[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[] = new int [n1];
        int R[] = new int [n2];
        int L1[]=new int[n1];
        int R1[]=new int[n2];
        int L2[]=new int[n1];
        int R2[]=new int[n2];
        

        

        for (int i=0; i<n1; ++i)
        {
            L[i] = arr[l + i];
            L1[i]=arr1[l+i];
            L2[i]=arr2[l+i];
            

        }
        for (int j=0; j<n2; ++j)
        {
            R[j] = arr[m + 1+ j];
            R1[j]=arr1[m+1+j];
            R2[j]=arr2[m+1+j];
            

        }
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                arr1[k]=L1[i];
                arr2[k]=L2[i];
                

                i++;
            }
            else
            {
                arr[k] = R[j];
                arr1[k]=R1[j];
                arr2[k]=R2[j];
                

                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k] = L[i];
            arr1[k]=L1[i];
            arr2[k]=L2[i];
            

            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = R[j];
            arr1[k]=R1[j];
            arr2[k]=R2[j];
            

            j++;
            k++;
        }
    }
    void sort3(int arr[],int arr1[],int arr2[], int l, int r)
    {
        if (l < r)
        {
            int m = (l+r)/2;
            sort3(arr,arr1,arr2, l, m);
            sort3(arr ,arr1,arr2, m+1, r);
            merge3(arr,arr1,arr2,l, m, r);
        }
    }
    void merge2(int arr[],int arr1[],int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[] = new int [n1];
        int R[] = new int [n2];
        int L1[]=new int[n1];
        int R1[]=new int[n2];
        for (int i=0; i<n1; ++i)
        {
            L[i] = arr[l + i];
            L1[i]=arr1[l+i];
        }
        for (int j=0; j<n2; ++j)
        {
            R[j] = arr[m + 1+ j];
            R1[j]=arr1[m+1+j];
        }
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                arr1[k]=L1[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                arr1[k]=R1[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k] = L[i];
            arr1[k]=L1[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = R[j];
            arr1[k]=R1[j];
            j++;
            k++;
        }
    }
    void sort2(int arr[],int arr1[],int l, int r)
    {
        if (l < r)
        {
            int m = (l+r)/2;
            sort2(arr,arr1, l, m);
            sort2(arr ,arr1, m+1, r);
            merge2(arr,arr1,l, m, r);
        }
    }
    void merge4(int arr[],int arr1[],int arr2[],int arr3[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[] = new int [n1];
        int R[] = new int [n2];
        int L1[]=new int[n1];
        int R1[]=new int[n2];
        int L2[]=new int[n1];
        int R2[]=new int[n2];
        int L3[]=new int[n1];
        int R3[]=new int[n2];
        for (int i=0; i<n1; ++i)
        {
            L[i] = arr[l + i];
            L1[i]=arr1[l+i];
            L2[i]=arr2[l+i];
            L3[i]=arr3[l+i];
        }
        for (int j=0; j<n2; ++j)
        {
            R[j] = arr[m + 1+ j];
            R1[j]=arr1[m+1+j];
            R2[j]=arr2[m+1+j];
            R3[j]=arr3[m+1+j];
        }
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                arr1[k]=L1[i];
                arr2[k]=L2[i];
                arr3[k]=L3[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                arr1[k]=R1[j];
                arr2[k]=R2[j];
                arr3[k]=R3[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k] = L[i];
            arr1[k]=L1[i];
            arr2[k]=L2[i];
            arr3[k]=L3[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = R[j];
            arr1[k]=R1[j];
            arr2[k]=R2[j];
            arr3[k]=R3[j];
            j++;
            k++;
        }
    }
    void sort4(int arr[],int arr1[],int arr2[],int arr3[], int l, int r)
    {
        if (l < r)
        {
            int m = (l+r)/2;
            sort4(arr,arr1,arr2,arr3, l, m);
            sort4(arr ,arr1,arr2,arr3, m+1, r);
            merge4(arr,arr1,arr2,arr3,l, m, r);
        }
    }
    public int justsmall(long a[],int l,int r,long x)
    {
        int p=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[mid]<=x)
            {
                p=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return p;
    }
    public int justlarge(long a[],int l,int r,long x)
    {
        int p=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[mid]<x)
            {
                l=mid+1;
            }
            else
            {
                p=mid;
                r = mid - 1;
            }
        }
        return p;
    }
    long gcd(long x,long y)
    {
        if(x%y==0)
            return y;
        else
            return(gcd(y,x%y));
    }
    int fact(int n)
    {
        int ans=1;
        for(int i=1;i<=n;i++)
            ans*=i;
        return ans;
    }
    long bintoint(String s)
    {
        long a=0;
        int l=s.length();
        int k=0;
        for(int i=l-1;i>=0;i--)
        {
            char c=s.charAt(i);
            if(c=='1')
            {
                a=a+(long)Math.pow(2,k);
            }
            k++;
        }
        return a;
    }
    String inttobin(long x)
    {
        String s="";
        while(x!=0)
        {
            long k=x%2;
            if(k==1)
                s="1"+s;
            else
                s="0"+s;
            x=x/2;
        }
        return s;
    }
    public static void main(String args[])throws Exception
    {
        new Thread(null,new templ(),"templ",1<<26).start();
    }
    public void run() {
        try {
            InputReader in = new InputReader(System.in);
            PrintWriter out = new PrintWriter(System.out);
            int n=in.ni();
            int pos=0,neg=0,zer=0,z=-1;
            int m[]=new int[n+1];
            for(int i=1;i<=n;i++)
            {
                int x=in.ni();
                m[i]=x;
                if(x==0)
                {
                    zer++;
                    z=i;
                }
                else if(x>0)
                    pos++;
                else
                    neg++;
            }
            if(zer>1)
            {
                if(neg+pos==0||(neg==1&&pos==0))
                {
                    for (int i = 1; i <= n - 1; i++)
                        out.println("1 " + i + " " + n);
                }
                else if(neg%2==1)
                {
                    int k=-1000000004,ind=-1;
                    for(int i=1;i<=n;i++)
                    {
                        if(m[i]>=0)
                            continue;
                        if(m[i]>k)
                        {
                            k=m[i];
                            ind=i;
                        }
                    }
                    out.println("1 "+ind+" "+z);
                    ArrayList<Integer>a=new ArrayList<>();
                    int yy=-1;
                    for(int i=n;i>=0;i--)
                    {
                        if(i==ind)
                            continue;
                        if(m[i]!=0)
                        {
                            yy=i;
                            break;
                        }
                    }
                    for(int i=1;i<z;i++)
                    {
                        if(m[i]==0)
                            a.add(i);
                    }
                    for(int i=0;i<a.size();i++)
                    {
                        out.println("1 "+a.get(i)+" "+z);
                    }
                    out.println("2 "+z);
                    for(int i=1;i<yy;i++)
                    {
                        if(i==z||i==ind)
                            continue;
                        int pp=Collections.binarySearch(a,i);
                        if(pp>=0)
                            continue;
                        out.println("1 "+i+" "+yy);
                    }
                }
                else
                {
                    ArrayList<Integer>a=new ArrayList<>();
                    int yy=-1;
                    for(int i=n;i>=0;i--)
                    {
                        if(m[i]!=0)
                        {
                            yy=i;
                            break;
                        }
                    }
                    for(int i=1;i<z;i++)
                    {
                        if(m[i]==0)
                            a.add(i);
                    }
                    for(int i=0;i<a.size();i++)
                    {
                        out.println("1 "+a.get(i)+" "+z);
                    }
                    out.println("2 "+z);
                    for(int i=1;i<yy;i++)
                    {
                        if(i==z)
                            continue;
                        int pp=Collections.binarySearch(a,i);
                        if(pp>=0)
                            continue;
                        out.println("1 "+i+" "+yy);
                    }
                }
            }
            if(zer==1)
            {
                if(neg%2==0)
                {
                    int yy=-1;
                    for(int i=n;i>=1;i--)
                    {
                        if(i==z)
                            continue;
                        yy=i;
                        break;
                    }
                    out.println("2 "+z);
                    for(int i=1;i<yy;i++)
                    {
                        if(i==z)
                            continue;
                        out.println("1 "+i+" "+yy);
                    }
                }
                if(neg%2==1)
                {
                    int k=-1000000004,ind=-1;
                    for(int i=1;i<=n;i++)
                    {
                        if(m[i]>=0)
                            continue;
                        if(m[i]>k)
                        {
                            k=m[i];
                            ind=i;
                        }
                    }
                    out.println("1 "+ind+" "+z);
                    if(n>2)
                        out.println("2 "+z);
                    int yy=-1;
                    for(int i=n;i>=1;i--)
                    {
                        if(i==z||i==ind)
                            continue;
                        yy=i;
                        break;
                    }
                    for(int i=1;i<yy;i++)
                    {
                        if(i==z||i==ind)
                            continue;
                        out.println("1 "+i+" "+yy);
                    }
                }
            }
            if(zer==0)
            {
                if(neg%2==0)
                {
                    for(int i=1;i<=n-1;i++)
                        out.println("1 "+i+" "+n);
                }
                else
                {
                    int k=-1000000004,ind=-1;
                    for(int i=1;i<=n;i++)
                    {
                        if(m[i]>=0)
                            continue;
                        if(m[i]>k)
                        {
                            k=m[i];
                            ind=i;
                        }
                    }
                    int yy=-1;
                    for(int i=n;i>=1;i--)
                    {
                        if(i==ind)
                            continue;
                        yy=i;
                        break;
                    }
                    out.println("2 "+ind);
                    for(int i=1;i<yy;i++)
                    {
                        if(i==ind)
                            continue;
                        out.println("1 "+i+" "+yy);
                    }
                }
            }
            out.close();
        }
        catch(Exception e){
            return;
        }
    }
    static class InputReader {

        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, snumChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (snumChars == -1)
                throw new InputMismatchException();
            if (curChar >= snumChars) {
                curChar = 0;
                try {
                    snumChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (snumChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int ni() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nl() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[] nextIntArray(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = ni();
            }
            return a;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public String nextLine() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndOfLine(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

    }
}