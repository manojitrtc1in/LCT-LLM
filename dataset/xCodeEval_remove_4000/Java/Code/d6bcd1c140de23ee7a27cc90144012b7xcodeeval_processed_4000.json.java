

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class d {
	static int v=0;
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
		 String str=s.next();
		 int[] tree=new int[4*str.length()];
		 int q=s.nextInt();
		 build(str,tree,0,str.length()-1,1);
		 for(int i=0;i<q;i++) {
			 int a=s.nextInt();
			 if(a==2) {
				 int l=s.nextInt();
				 int r=s.nextInt();
				 int o=query(tree,0,str.length()-1,1,l-1,r-1);
				 System.out.println(Integer.bitCount(o));
			 }else {
				 int f=s.nextInt();
				 char ch=s.next().charAt(0);
				
				update(str,tree,0,str.length()-1,1,ch,f-1);
			 }
		 }
		 
		
		 
	 }
	 
		public static void build(String str,int[] tree, int start, int end ,int pos) {
			
			
			if(start==end) {
				tree[pos]=(1<<(str.charAt(start)-'a'));
				return;
			}
			
			int mid=(start+end)/2;
			
			build(str,tree,start,mid,2*pos);
			build(str,tree, mid+1,end,2*pos+1);
			
			tree[pos]=tree[2*pos+0]|tree[2*pos+1];
			return;
			
		}
		
		public static void update(String str,int[] tree, int start, int end,int pos,char val,int index ) {
			
			if(start==end) {
				
				tree[pos]=1<<(val-'a');
				return;
			}
			int mid=(start+end)/2;
			if(start<=index && index<=mid) {
				update(str,tree,start,mid,2*pos+0,val,index);
			}else {
				update(str,tree,mid+1,end,2*pos+1,val,index);
			}
			
			tree[pos]=(tree[2*pos+0]|tree[2*pos+1]);
			return;
		}
		
		public static int query(int[] tree,int start,int end,int pos,int l,int r) {
			
			if(r<start||l>end) {
				return 0;
			}
			if(l<=start&&r>=end) {
				return tree[pos];
			}
			
			int mid=(start+end)/2;
			int p1=query(tree,start,mid,2*pos,l,r);
			int p2=query(tree,mid+1,end,2*pos+1,l,r);
			return (p1|p2);
			
		}
	 
}