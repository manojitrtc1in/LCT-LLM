import java.io.*;
import java.util.*;
import java.lang.*;
import java.util.HashMap;
public class templ implements Runnable {
    class pair
    {
        int v,val;
        pair(int f,int s)
        {
            v=f;
            val=s;
        }
    }
    

    

    public static int M=1000000007;
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
    public int justsmall(int a[],int l,int r,int x)
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
    public int justlarge(int a[],int l,int r,int x)
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
    long pow(long a,long b,long p)
    {
        if(b==1)
            return a;
        if(b==0)
            return 1;
        long ans=pow(a,b/2,p)%(p);
        if(b%2==0)
            return (ans*ans)%(p);
        else
            return ((ans*ans)%(p)*a)%(p);
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
            int x1[]=new int[n];
            int x2[]=new int[n];
            int y1[]=new int[n];
            int y2[]=new int[n];
            int a[]=new int[n];
            int b[]=new int[n];
            int c[]=new int[n];
            int d[]=new int[n];
            for(int i=0;i<n;i++)
            {
                x1[i]=in.ni();
                y1[i]=in.ni();
                x2[i]=in.ni();
                y2[i]=in.ni();
                a[i]=b[i]=c[i]=d[i]=i;
            }
            sort2(x1,a,0,n-1);
            sort2(x2,b,0,n-1);
            sort2(y1,c,0,n-1);
            sort2(y2,d,0,n-1);
            int r1=-1,r2=-1;
            if(x1[n-1]>x2[0])
            {
                if(x1[n-2]<=x2[0])
                    r1=a[n-1];
                if(x1[n-1]<=x2[1])
                    r2=b[0];
            }
            int r3=-1,r4=-1;
            if(y1[n-1]>y2[0])
            {
                if(y1[n-2]<=y2[0])
                    r3=c[n-1];
                if(y1[n-1]<=y2[1])
                    r4=d[0];
            }
            int k=0,k1=0,k2=0;
            if(r1==-1)
                k++;
            if(r2==-1)
                k++;
            k1=k;
            if(r3==-1)
                k++;
            if(r4==-1)
                k++;
            k2=k-k1;
            if(k==4)
                out.println(x1[n-1]+" "+y1[n-1]);
            if(k==3)
            {
                int x;
                if(r1!=-1)
                    x=r1;
                else if(r2!=-1)
                    x=r2;
                else if(r3!=-1)
                    x=r3;
                else
                    x=r4;
                int xx=-1,yy=-1;
                for(int i=n-1;i>=0;i--)
                {
                    if(a[i]!=x)
                    {
                        xx=x1[i];
                        break;
                    }
                }
                for(int i=n-1;i>=0;i--)
                {
                    if(c[i]!=x)
                    {
                        yy=y1[i];
                        break;
                    }
                }
                out.println(xx+" "+yy);
            }
            if(k==2)
            {
                if(k1==2||k2==2)
                {
                    int x;
                    if(r1!=-1)
                        x=r1;
                    else if(r2!=-1)
                        x=r2;
                    else if(r3!=-1)
                        x=r3;
                    else
                        x=r4;
                    int xx=-1,yy=-1;
                    for(int i=n-1;i>=0;i--)
                    {
                        if(a[i]!=x)
                        {
                            xx=x1[i];
                            break;
                        }
                    }
                    for(int i=n-1;i>=0;i--)
                    {
                        if(c[i]!=x)
                        {
                            yy=y1[i];
                            break;
                        }
                    }
                    out.println(xx+" "+yy);
                }
                else
                {
                    int x=-1;
                    if(r1!=-1)
                        x=r1;
                    else if(r2!=-1)
                        x=r2;
                    int xx=-1,yy=-1;
                    for(int i=n-1;i>=0;i--)
                    {
                        if(a[i]!=x)
                        {
                            xx=x1[i];
                            break;
                        }
                    }
                    for(int i=n-1;i>=0;i--)
                    {
                        if(c[i]!=x)
                        {
                            yy=y1[i];
                            break;
                        }
                    }
                    out.println(xx+" "+yy);
                }
            }
            if(k<=1)
            {
                int x=-1;
                if(r1==r3||r1==r4)
                    x=r1;
                else
                    x=r2;
                int xx=-1,yy=-1;
                for(int i=n-1;i>=0;i--)
                {
                    if(a[i]!=x)
                    {
                        xx=x1[i];
                        break;
                    }
                }
                for(int i=n-1;i>=0;i--)
                {
                    if(c[i]!=x)
                    {
                        yy=y1[i];
                        break;
                    }
                }
                out.println(xx+" "+yy);
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