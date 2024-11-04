



import java.io.*;

import java.math.BigInteger;
import java.util.*;



public class LoveJava {
    

    


    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        

        String arr1[];


        try {

             int t = Integer.parseInt(br.readLine());

            while (t-->0) {
                 int n=Integer.parseInt(br.readLine());

            arr1 = (br.readLine().replaceAll("//s+$", " ").split(" "));






           int[]a=new int[arr1.length];
            for (int i=0;i<arr1.length;i++)
               a[i]=(Integer.parseInt(arr1[i]));
            Arrays.sort(a);
              fn(a);
           }

            pw.close();


        } catch (IOException ex) {
            System.out.println("input mismatch");
        }

    }

    public static void fn(int[]a){
        int[]b=new int[a.length];
        HashSet<Integer>set=new HashSet<>();
        int j=0;
    for(int i=0;i<a.length;i++){
       if(i>0&&a[i]==a[i-1])
           ;
       else b[j++]=a[i];
    }
   for(int i=0;i<a.length;i++){
       if(i>0&&a[i]==a[i-1])
           b[j++]=a[i];
       else ;
    }

    for(int e:b)
        System.out.print(e+" ");
    System.out.println();

      return;
    }
    public static int function(String s,long[]factors){
        int min=100000;
        int j;
       for(int i=0;i<factors.length;i++){
           String str=String.valueOf(factors[i]);
           for( j=0;j<s.length()&&j<str.length();j++){
               if(s.charAt(j)==str.charAt(j))
                   ;
               else break;
           }
           min=Math.min(str.length()-j+s.length()-j,min);
       }
       return min;
    }
    public  static boolean func(int[]a,long[]dp,int i) {
        if(a[i]<=dp[i+1])
            return true;
        else return false;
    }
    public static int helper(int[]dp,int[]a,int i){
        if(dp[i]!=0)
            return dp[i];
        else {
            return (dp[i]=helper(dp,a,a[i])+1);
        }
    }

    public static int maxArea(ArrayList<Integer> A) {
        int i=0,j=A.size()-1;
        int max=0;
        while (i<j){
            max=Math.max(max,Math.min(A.get(i),A.get(j))*(j-i));
            if(A.get(i)<A.get(j))
                i++;
            else j--;
        }
        return max;
    }

    

    public static int gcd(int a,int b){
        if(b==0)
            return a;
        else return gcd(b,a%b);
    }
    

    public static void fun(int[]a,int k){
        int max=-1,countpeaks=0;

        int[]peaks=new int[a.length];

        for(int i=0;i<peaks.length;i++){
            if(i==0||i==peaks.length-1)
                peaks[i]=0;
            else {
                if(a[i]>a[i-1]&&a[i]>a[i+1])
                    peaks[i]=1;
                else peaks[i]=0;
            }
        }
        int r=a.length-1,l=r-k+1,i=0;
        if(l<0){
            System.out.println(-1);
            return;}
        for(int j=r;l>=0;){
            if(i==r)
            for (i=r;i>=l;i--){
                if((i==r||i==l)&&peaks[i]==1)
                    ;
                else
                    countpeaks+=peaks[i];
            }
            max=max>countpeaks?max:countpeaks;
            r--;l--;

        }
    }
    
}
