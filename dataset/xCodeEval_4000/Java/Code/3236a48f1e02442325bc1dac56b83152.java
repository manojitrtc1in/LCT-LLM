

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

public class b {
	 static class Reader 
	    { 
	        final private int BUFFER_SIZE = 1 << 16; 
	        private DataInputStream din; 
	        private byte[] buffer; 
	        private int bufferPointer, bytesRead; 
	  
	        public Reader() 
	        { 
	            din = new DataInputStream(System.in); 
	            buffer = new byte[BUFFER_SIZE]; 
	            bufferPointer = bytesRead = 0; 
	        } 
	  
	        public Reader(String file_name) throws IOException 
	        { 
	            din = new DataInputStream(new FileInputStream(file_name)); 
	            buffer = new byte[BUFFER_SIZE]; 
	            bufferPointer = bytesRead = 0; 
	        } 
	  
	        public String readLine() throws IOException 
	        { 
	            byte[] buf = new byte[64]; 

	            int cnt = 0, c; 
	            while ((c = read()) != -1) 
	            { 
	                if (c == '\n') 
	                    break; 
	                buf[cnt++] = (byte) c; 
	            } 
	            return new String(buf, 0, cnt); 
	        } 
	  
	        public int nextInt() throws IOException 
	        { 
	            int ret = 0; 
	            byte c = read(); 
	            while (c <= ' ') 
	                c = read(); 
	            boolean neg = (c == '-'); 
	            if (neg) 
	                c = read(); 
	            do
	            { 
	                ret = ret * 10 + c - '0'; 
	            }  while ((c = read()) >= '0' && c <= '9'); 
	  
	            if (neg) 
	                return -ret; 
	            return ret; 
	        } 
	  
	        public long nextLong() throws IOException 
	        { 
	            long ret = 0; 
	            byte c = read(); 
	            while (c <= ' ') 
	                c = read(); 
	            boolean neg = (c == '-'); 
	            if (neg) 
	                c = read(); 
	            do { 
	                ret = ret * 10 + c - '0'; 
	            } 
	            while ((c = read()) >= '0' && c <= '9'); 
	            if (neg) 
	                return -ret; 
	            return ret; 
	        } 
	  
	        public double nextDouble() throws IOException 
	        { 
	            double ret = 0, div = 1; 
	            byte c = read(); 
	            while (c <= ' ') 
	                c = read(); 
	            boolean neg = (c == '-'); 
	            if (neg) 
	                c = read(); 
	  
	            do { 
	                ret = ret * 10 + c - '0'; 
	            } 
	            while ((c = read()) >= '0' && c <= '9'); 
	  
	            if (c == '.') 
	            { 
	                while ((c = read()) >= '0' && c <= '9') 
	                { 
	                    ret += (c - '0') / (div *= 10); 
	                } 
	            } 
	  
	            if (neg) 
	                return -ret; 
	            return ret; 
	        } 
	  
	        private void fillBuffer() throws IOException 
	        { 
	            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
	            if (bytesRead == -1) 
	                buffer[0] = -1; 
	        } 
	  
	        private byte read() throws IOException 
	        { 
	            if (bufferPointer == bytesRead) 
	                fillBuffer(); 
	            return buffer[bufferPointer++]; 
	        } 
	  
	        public void close() throws IOException 
	        { 
	            if (din == null) 
	                return; 
	            din.close(); 
	        } 
	    } 

	 
	public static void main(String[] args) throws Exception{

		Reader s=new Reader();

		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			int n=s.nextInt();
			ArrayList[] arr=new ArrayList[n+1];
			
			for(int i=0;i<n+1;i++) {
				arr[i]=new ArrayList<>();
			}
			
			for(int i=0;i<n-1;i++) {
				int a=s.nextInt();
				int b=s.nextInt();
				arr[a].add(b);
				arr[b].add(a);
			}
			
			HashMap<Integer,Integer> map=new HashMap<>();
			
			int[] visited=new int[n+1];
			
			dfs(arr,visited,1,map,n);
			
			ArrayList<Integer> list=new ArrayList<>();
			
			int min=Integer.MAX_VALUE;
			for(Map.Entry<Integer, Integer> entry: map.entrySet()) {
				
				min=Math.min(min, entry.getValue());
			}
			
			for(Map.Entry<Integer, Integer> entry: map.entrySet()) {
				
				if(entry.getValue().equals(min)) {
					list.add(entry.getKey());
				}
			}
			HashMap<Integer,Integer> pa=new HashMap<>();
			
			if(list.size()==1) {
				System.out.println(1+" "+arr[1].get(0));
				System.out.println(1+" "+arr[1].get(0));
			}else {
				
				int[] visited2=new int[n+1];
				int leaf=dfs2(arr,visited2,list.get(0),list.get(1),pa,0);
				
				System.out.println(leaf+" "+pa.get(leaf));
				System.out.println(leaf+" "+list.get(1));
				
			}
			
			
			
			
			
		}
				
		
	}
	public static int dfs(ArrayList[] arr,int[] visited,int start,HashMap<Integer,Integer> map,int n) {
		
		visited[start]=1;
		
		int sum=1;
		for(int i=0;i<arr[start].size();i++) {
			int curr=(int)arr[start].get(i);
			
			if(visited[curr]==0) {
				int a=dfs(arr,visited,curr, map,n);
				if(map.containsKey(start)) {
					map.put(start, Math.max(a, map.get(start)));
				}else{
					map.put(start, a);
				}
				sum=sum+a;
			}
			
		}
		
		if(map.containsKey(start)) {
			map.put(start, Math.max(n-sum, map.get(start)));
		}else {
			map.put(start, n-sum);
		}
		
		return sum;
		
		
	}
	public static int dfs2(ArrayList[] arr,int[] visited,int start,int avoid,HashMap<Integer,Integer> pa,int paa) {
		
		visited[start]=1;
		int p=0;
		int a=0;
		for(int i=0;i<arr[start].size();i++) {
			int curr=(int)arr[start].get(i);
			
			if(visited[curr]==0) {
				p=1;
				if(avoid!=curr) {
					a=dfs2(arr,visited,curr,avoid,pa,start);
				}
			}
			
		}
		
		pa.put(start, paa);
		
		if(p==0) {
			return start;
		}
		
		return a;
		
		
	}
	
}