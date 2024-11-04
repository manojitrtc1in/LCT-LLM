



import java.io.*;

import java.math.BigInteger;
import java.util.*;



public class LoveJava {
    

    


    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        String arr[];
        String arr1[];


        try {

             int t = Integer.parseInt(br.readLine());
            while (t-->0) {
                 int n=Integer.parseInt(br.readLine());
               

            

                String str=br.readLine();



               StringBuilder s=new StringBuilder(str);
               pw.println(fn(s));
           }

            pw.close();


        } catch (IOException ex) {
            System.out.println("input mismatch");
        }

    }
    public static int fn(StringBuilder str){
        int l=0,r=str.length()-1-l;
        int min=1000000 , count=0;
        for(int i=0;i<26;i++){

            StringBuilder s=new StringBuilder(str);
          count =0;
            boolean flag=true;
            l=0;r=str.length()-1-l;
            while (l<=r){
                if(s.charAt(l)==s.charAt(r))
                {
                    l++;
                    r--;
                }
                else {
                    if(s.charAt(l)==i+'a')
                    {  s.delete(l,l+1);
                        r--;
                    count++;}
                        else if(s.charAt(r)==i+'a'){
                        s.delete(r,r+1);
                        r--;
                        count++;
                    }
                    else
                        {flag=false;
                    break;}
                }
            }
            if(flag==true)
                min=Math.min(min,count);

        }
        if(min==1000000)
            return -1;
        return min;
    }
    public static void function(long[]dp,int[]a,int n){
        int l=0,h=a.length-1;
        while (l+1<h){
            int mid=l+(h-l)/2;
            if(func(a,dp,mid)==true)

                l=mid;
            else h=mid-1;
        }

        if(func(a,dp,h)==true)
            System.out.println(a.length-1-h);
        else if(func(a,dp,l)==true)
            System.out.println(a.length-1-l);
        else System.out.println(a.length-1-(l-1));
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
        int max=-1,id0=0;

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
                    id0+=peaks[i];
            }
            max=max>id0?max:id0;
            r--;l--;

        }
    }
    
}
