

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
 public class d {
	
	
	public static void main(String[] args)  {
	   Scanner s = new Scanner( System.in);
	
	   StringBuilder sb=new StringBuilder();
	   int t=s.nextInt();
	   for(int ie=0;ie<t;ie++) {
		   
		   int r=s.nextInt();
		   int g=s.nextInt();
		   int b=s.nextInt();
		   
		   long[] red=new long[r];
		   long[] green=new long[g];
		   long[] blue=new long[b];
		   
		   for(int i=0;i<r;i++) {
			   red[i]=s.nextLong();
		   }
		   
		   for(int i=0;i<g;i++) {
			   green[i]=s.nextLong();
		   }
		   
		   for(int i=0;i<b;i++) {
			   blue[i]=s.nextLong();
		   }
		   
		   Arrays.sort(red);
		   Arrays.sort(green);
		   Arrays.sort(blue);
		   
		  long gmin=Long.MAX_VALUE;
		  
		  long min1=work(red,green,blue);
		   if(gmin>min1) {
			   gmin=min1;
		   }
		   long min2=work(red,blue,green);
		   if(gmin>min2) {
			   gmin=min2;
		   }
		   long min3=work(green,red,blue);
		   if(gmin>min3) {
			   gmin=min3;
		   }
		   long min4=work(green,blue,red);
		   if(gmin>min4) {
			   gmin=min4;
		   }
		   long min5=work(blue,green,red);
		   if(gmin>min5) {
			   gmin=min5;
		   }
		   long min6=work(blue,red,green);
		   if(gmin>min6) {
			   gmin=min6;
		   }
		   
		   sb.append(gmin+"\n");
		   
		   
		   
		   
	   }
	   System.out.println(sb);
	   
	}
	public static long fun(long x,long y,long z) {
		return pow(x-y)+pow(y-z)+pow(z-x);
	}
	
	public static long pow(long x) {
		return x*x;
	}
	
	public static long lbs(long a,long[] arr) {
		
		int st=0;
		int end=arr.length-1;
		long ans=0;
		
		
		while(st<=end) {
		
			int mid=(st+end)/2;
			
			if(a-arr[mid]>=0) {
			 	ans=arr[mid];
			 	st=mid+1;
			}else {
				end=mid-1;
			}
			
		}
		return ans;
	}
	public static long ubs(long a,long[] arr) {
		
		int st=0;
		int end=arr.length-1;
		long ans=0;
		
		
		while(st<=end) {
		
			int mid=(st+end)/2;
			
			if(arr[mid]-a>=0) {
			 	ans=arr[mid];
			 	end=mid-1;
			}else {
				st=mid+1;
			}
			
		}
		return ans;
	}
	
	public static long work(long[] arr,long[] brr,long[] crr) {
		
		long gmin=Long.MAX_VALUE;
		
		for(int i=0;i<arr.length;i++) {
			long one=ubs(arr[i],brr);
			long two=lbs(arr[i],brr);
			
			long three=ubs(one,crr);
			long four=lbs(one,crr);
			long five=ubs(two,crr);
			long six=lbs(two,crr);
			
			if(one!=0&&three!=0) {
			long min=fun(arr[i],one,three);
			if(gmin>min) {
				gmin=min;
			}
			}
			
			if(one!=0&&four!=0) {
			long min1=fun(arr[i],one,four);
			if(gmin>min1) {
				gmin=min1;
			}
			}
			
			if(two!=0&&five!=0) {
			long min2=fun(arr[i],two,five);
			if(gmin>min2) {
				gmin=min2;
			}
			}
			if(two!=0&&six!=0) {
			long min3=fun(arr[i],two,six);
			if(gmin>min3) {
				gmin=min3;
			}
			}
			
		}
		return gmin;
	}
	
	
 }
	