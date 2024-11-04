
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

 public class Main{
	 
	
	  public static void main (String[] args) {
		 
		  Scanner s=new Scanner(System.in);
	
		  int t=s.nextInt();
		  for(int ie=0;ie<t;ie++) {
	
			  int n=s.nextInt();
			  int k=s.nextInt();
			  
			  char[] arr=s.next().toCharArray();
			  
			 
			  ArrayList<pair> list=new ArrayList<>();
			  
			  int c=0;
			  int st=0;
			  int end=0;
			  int flag=0;
			  for(int i=0;i<n;i++) {
				  if(arr[i]=='L') {
					  if(flag==1) {
						  flag=0;
						  c++;
						  st=i;
						  end=i;
					  }else {
					  c++;
					  end++;
					  }
				  }else {
					  if(c>0 &&st!=0 )
					  list.add(new pair(c,st,end));
					  c=0;
					  flag=1;
					  
					  
				  }
			  }
			  if(c>0 &&end!=n-1) {
				  list.add(new pair(c,st,end));
			  }
			  Collections.sort(list,new comp());
			 
			  int in=0;
			  while(k>0) {
				  if(in==list.size()) {
					  break;
				  }else {
					  for(int i=list.get(in).st;i<=list.get(in).end;i++) {
						  if(k==0) {
							  break;
						  }else {
							  arr[i]='W';
							  k--;
						  }
					  }
					  
					  in++;
				  }
				  
				  
			  }
			  
			  int g=n;
			  int l=-1;
			  for(int i=0;i<n;i++) {
				  if(arr[i]=='W') {
					  g=i;
					  break;
				  }
			  }
			  
			  for(int i=n-1;i>=0;i--) {
				  if(arr[i]=='W') {
					  l=i;
					  break;
				  }
			  }
			  
			  if(k>0) {
				  
				  for(int i=g-1;i>=0;i--) {
					  if(k==0) {
						  break;
					  }else {
						  arr[i]='W';
						  k--;
					  }
						  
				  }
				  
			  }
			  if(k>0) {
				  
				  for(int i=l+1;i<n;i++) {
					  if(k==0) {
						  break;
					  }else {
						  arr[i]='W';
						  k--;
					  }
						  
				  }
				  
			  }
			  
			  
			  
			 
			  int[] pre=new int[n];
			  
				 
			  if(arr[0]=='W') {
				  pre[0]=1;
				  
			  }
			  
			  for(int i=1;i<n;i++) {
				  if(arr[i]=='W') {
					  if(arr[i-1]=='W') {
						  pre[i]=pre[i-1]+2;
					  }else {
						  pre[i]=pre[i-1]+1;
					  }
				  }else {
					  pre[i]=pre[i-1];
				  }
			  }
			  
			  System.out.println(pre[n-1]);
			  
			  
			  
			  
		  }
	  }
 }
 class pair{
	 
	 int count;
	 int st;
	 int end;
	 
	 public pair(int count,int st,int end) {
		 this.count=count;
		 this.st=st;
		 this.end=end;
	 }
 }
 class comp implements Comparator<pair>{
	 public int compare(pair h,pair j) {
		 return h.count-j.count;
	 }
 }
 