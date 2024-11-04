

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class id0 {


	


	
	public static int r1=0;
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
	static long[][] f=new long[501][501];
	public static void main(String[] args)  {
		OutputStream outputStream =System.out;
	    PrintWriter out =new PrintWriter(outputStream);
		FastReader s=new FastReader();






int t=s.nextInt();
while(t>0) {
	int n=s.nextInt();
	int[] a=new int[n+1];
	int ans=0;
	for(int i=1;i<=n;i++) {
		a[i]=s.nextInt();
	}
	int[] pre=new int[n+1];
	if(a[n]<a[n-1]) {
		out.println(-1);
	}else {
	int i=n;
	while(i>0 && a[i]<0) {
		i--;
	}
	ArrayList<pair3> e=new ArrayList<>();
	int d=i-1;
	int g=i;
	for(int j=1;j<i-1;j++) {
		e.add(new pair3(j,i-1,i));
		a[j]=a[i-1]-a[i];
	}
	boolean p=true;
	for(int j=1;j<n;j++) {
		if(a[j]>a[j+1]) {p=false;}
	}
	if(!p) {out.println(-1);}else {
		out.println(e.size());
		for( i=0;i<e.size();i++) {
			out.println(e.get(i).a+" "+e.get(i).b+" "+e.get(i).c);
		}
	}
	}
	
	t--;
}
out.close();
	}
	static class pair3{
		int a;
		int b;
		int c;
		pair3(int a,int b,int c){
			this.a=a;
			this.b=b;
			this.c=c;
		}
	}


























































































































































































































































































































































































































































































































































































































































































































































































































































































































        static class pair{
            TreeNode a;
            int b;
            pair(TreeNode a,int b){
                this.a=a;
                this.b=b;
            }
        }


















        static class TreeNode {
        	      int val;
        	      TreeNode left;
        	      TreeNode right;
        	      TreeNode() {}
        	      TreeNode(int val) { this.val = val; }
        	      TreeNode(int val, TreeNode left, TreeNode right) {
        	          this.val = val;
        	         this.left = left;
        	          this.right = right;
        	      }
        	  }
       
        public static List<List<Integer>> verticalTraversal(TreeNode root) {
        	TreeMap<Integer,PriorityQueue<Integer>> e=new TreeMap<>();
            Stack<pair> st=new Stack<>();
            

            while(!st.isEmpty()) {
            	pair d=st.pop();
                if(!e.containsKey(d.b)){
                    e.put(d.b,new PriorityQueue<>());
                    e.get(d.b).add(d.a.val);
                }else{
                     e.get(d.b).add(d.a.val);
                }
                st.add(new pair(d.a.left,d.b-1));
                st.add(new pair(d.a.right,d.b+1));
            }
           List<List<Integer>> ans=new ArrayList<>();
           for(Map.Entry<Integer, PriorityQueue<Integer>> um:e.entrySet()) {
        	   List<Integer> f=new ArrayList<>();
        	   while(!um.getValue().isEmpty()) {
        		   f.add(um.getValue().poll());
        	   }
           }
           return ans;
         }
}









