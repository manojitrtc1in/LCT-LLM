import java.util.*;
import java.io.*;
public class d3
{
  static class pair{
   int row;
   int col;
   pair(int row,int col){
    this.col = col;
    this.row = row;
   }
   }
   static class Node{
    long starting = 0;
    long len = 0;

   }
  

 

   static int answer = 0;
   static int tak = 0;
   static int aok = 0;
 
    public static void main(String[] args) throws Exception
    {       
          BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
          BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
          StringTokenizer st;
          st = new StringTokenizer(br.readLine());
          int t = Integer.parseInt(st.nextToken());
        while(t-->0){
            st = new StringTokenizer(br.readLine());
           int n = Integer.parseInt(st.nextToken());
           st = new StringTokenizer(br.readLine());
           long[] arr = new long[n];
           long[] prefix = new long[n];
           long cur = 0;
           for(int i = 0;i<n;i++){
            arr[i] = Long.parseLong(st.nextToken());
            cur += arr[i];
            prefix[i] = cur;
           }
           int val = recu(arr,1,n,1);
           if(val < 0){
            bw.write("-1\n");
            continue;
           }
           bw.write(val+"\n");
        }
        bw.flush();
    }
    public static int recu(long[] arr,int low,int high,int starting){
        if(low >= high || low <= 0 || high > arr.length){
            return 0;
        }
        long n1 = (high-low+1)/2;
        long sum1 = (long)((0.5)*(n1) * (2*starting + (n1-1)));
        long sum2 = (n1)*(2*starting+(2*n1-1));
        long cur = 0L;
        long start = starting;
        for(int i = low-1;i<low+n1-1;i++){
           cur += arr[i];
        }
        

        int ret = 0;
        if(cur == sum2-sum1){
           ret = 1;
           ret += recu(arr, (int)(low+n1), high,starting);
           ret += recu(arr, low, (int)(high-n1),(int)(starting+n1));
        }
        else if(cur != sum1){
            return -99999;
        }
        else{
            ret += recu(arr, (int)(low+n1), high,(int)(starting+n1));
            ret += recu(arr, low, (int)(high-n1),starting);
        }
        return ret;
    }
    public static int check(ArrayList<Integer> al,int k,int size){
        int max = 0;
        int cur = 0;
        int id0 = 0;
        int set = 0;
        for(int i = 0;i<al.size();i++){
            cur += al.get(i);
            id0++;
           if(cur == k){
            max = Math.max(max,id0);
            set++;
            cur = 0;
            id0 = 0;
           }
        }
        if(cur == k){
            max = Math.max(max,id0);
            set++;
           }
           if(set != size){
            return -1;
           }
           return max;
    }
    public static boolean check1(long[] arr,int k){
        int start = arr.length-k+2;
        int prev = start-1;
        while(start < arr.length){
             if(arr[prev] <= arr[start]){
                prev = start;
                start++;
             }
             else{
                return false;
             }
        }
        return true;
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    public static int dfs(ArrayList<ArrayList<Integer>> graph,int cur,boolean[] visited,int height){
       if(visited[cur]){
        return height;
       }
        visited[cur] = true;
        int max = height;
        for(int child : graph.get(cur)){
            if(!visited[child]){
                max = Math.max(max,dfs(graph,child,visited,height+1));
            }
        }
        return max;
  }
    public static void rec(int[][] mat,int i,int j,ArrayList<Integer> al){
        int n = mat.length;
        int m = mat[0].length;
        if(i < 0 || j < 0 || i >= n || j >= m){
            return;
        }
        

        

        

        

        

       

        al.add(mat[i][j]);
        rec(mat,i-1,j+1,al);
        long max = 0;
       long cur = 0;
        int size = al.size();
        for(int k = 0;k<size;k++){
           cur += al.get(k);
           if(cur < 0){
            cur = 0;
           }
           max = Math.max(max,cur);
        }
       

    }
    public static boolean recur(int[][] mat,int i,int j,int n,int m){
            if(i < 0 || j < 0 || i >= n || j  >= m){
                return true;
            }
            if(mat[i][j] == 0){
                return false;
            }
            return recur(mat, i-1, 1+j, n, m);
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

     public static int id3(int[] al,int val,int low,int high){
        int index = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(al[mid] <= val){
                index = Math.max(mid,index);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return index;
    }
     public static void id2(int cur,int n,int start,int m,ArrayList<Integer> temp){
         if(start-1 > m){
            return;
         }
           if(temp.size() == n){
            for(int i = 0;i<n;i++){
                System.out.print(temp.get(i)+" ");
            }
            System.out.println();
            return;
           }
           for(int i = start;i<=m;i++){
            temp.add(i);
           id2(cur+1,n,i+1,m,temp);
           temp.remove(temp.size()-1);
           }
          

     }
     public static void fill(int x,int l,int r,long[] arr,long[] seg){
        if(l == r){
            seg[x] = arr[l]; 

            return;
        }
        int mid = (l+r)/2;
        fill(2*x,l,mid,arr,seg);
        fill(2*x+1,mid+1,r,arr,seg);
        seg[x] =seg[2*x]+seg[2*x+1];
     }
     public static long sum(int x,int l,int r,int lr,int rr,long[] arr,long[] seg){
        

        if(r < lr || rr < l){
            return 0;
        }
        

        if(lr <= l && r <= rr){
             return seg[x];
        }
        int mid = (l+r)/2;
        long a = 0;
        a += sum(2*x,l,mid,lr,rr,arr,seg);
        a += sum(2*x+1,mid+1,r,lr,rr,arr,seg);
        return a;
     }
     public static void update(int x,int l,int r,int i,int val,long[] arr,long seg[]){
        if(l == r){
            seg[x] = val;
            return;
        }
        int mid = (l+r)/2;
        if(l <= i && i <= mid){
            update(2*x,l,mid,i,val,arr,seg);
        }
        else{
            update(2*x+1,mid+1,r,i,val,arr,seg);
        }
        seg[x] = (seg[2*x]+seg[2*x+1]);
     }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

     public static boolean check2(long mid,long n,long r,long c){
        long id1 = mid/r;
        long percolumn = mid/c;
        long cur = id1*percolumn;
         if(cur >= n){
             return true;
         }
         return false;
     }
     public static int ceil1(int[] arr,int low,int high,int ele){
         while(low <= high){
         int mid = (low+high)/2;
         if(arr[mid] < ele){
             low = mid+1;
         }
         else{
             high = mid-1;
         }
        }
        return low;
     }
     public static int floor1(int[] arr,int low,int high,int ele){
        while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] <= ele){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
       }
       return low;
    }
 
  
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

      
        public static long power(long a,long b,long mod){
            long res = 1L;
            while(b > 0){
                if(b%2 == 1){
                    res = (res%mod * a%mod)%mod;
                }
                b /= 2;
                a = (a*a)%mod;
            }
            return res;
        }
       public static boolean comp(String s1,String s2){
           int count = 0;
           for(int i = 0;i<2;i++){
               if(s1.charAt(i) == s2.charAt(1-i)){
                   count++;
               }
               else{
                   return false;
               }
           }
         

           return true;
       }


    public static int ceil(ArrayList<Integer> al,int val){
           int  low = 0;
           int high = al.size()-1;
           int pos = 0;
           while(low <= high){
               int mid = (low+high)/2;
               if(al.get(mid) == val){
                   pos = Math.max(pos,mid);
                   low = mid+1;
               }
               else if(al.get(mid) < val){
                   low = mid+1;
               }
               else{
                   high = mid-1;
               }
           }
          return low;
    }
    public static int floor(ArrayList<Integer> al,int val){
        int  low = 0;
        int high = al.size()-1;
        int pos = high;
        while(low <= high){
            int mid = (low+high)/2;
            if(al.get(mid) == val){
                pos = Math.min(pos,mid);
                high = mid-1;
            }
            else if(al.get(mid) < val){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
       return pos;
 }
    public static long gcd(long a,long b){
        if(b == 0L){
            return a;
        }
        return gcd(b,a%b);
    }
    public static int bceil(ArrayList<Integer> al,int val,int low,int high){
        int index = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(al.get(mid) <= val){
                index = Math.max(mid,index);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return index;
    }
    public static int bfloor(ArrayList<Integer> al,int val){
        int low = 0;
        int high = al.size()-1;
        int index = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int mval = al.get(mid);
           if(mval >= val){
               high = mid-1;
               index = Math.max(index,mid);
            }
            else{
                low = mid+1;
            }
        }
        return index;
  }
    public static void primefact(int n){
        for(int i = 2;i*i<=n;i++){
            if(n%i == 0){
                while(n%i == 0){
                    n /= i;
                    System.out.println(i);
                }
            }
        }
        System.out.println(n);
    }
    public static boolean prime(long n){
        int count = 0;
        for(long i = 1;i*i <= n;i++){
            if(n%i == 0){
                if(i*i == n){
                    count++;
                }
                else{
                    count += 2;
                }
            }
        }
        if(count == 2){
            return true;
        }
        return false;
    }   
}