

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class k {
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
  
	 

	public static void main(String[] args) throws Exception {
		Reader s = new Reader();
		int t=s.nextInt();
		StringBuilder sb=new StringBuilder();
		for(int ie=0;ie<t;ie++) {
			int n=s.nextInt();
			int[] arr=new int[n];
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
			}
			
			ArrayList[] graph=new ArrayList[n+1];
			for(int i=0;i<n+1;i++) {
				ArrayList<Integer> list=new ArrayList<>();
				graph[i]=list;
			}
			
			for(int i=0;i<n;i++) {
				graph[i+1].add(arr[i]);
				
			}
			int [] visited=new int[n+1];
			int[] crr=new int[n+1];
			for(int i=1;i<n+1;i++) {
				int count=0;
			  ArrayList<Integer> list=new ArrayList<>();
			  if(visited[i]==0) {
				 
				  dfs(graph,i,count,visited,list,crr);
				  for(int j=0;j<list.size();j++)
					{
						crr[list.get(j)]=list.size();
					}
			  }
			 
			}
			for(int i=1;i<n+1;i++) {
				
				sb.append(crr[i]+" ");
			}
			sb.append("\n");
			
		}
		
		System.out.println(sb);
		
	}
	
	
	public static void dfs(ArrayList[] graph,int start,int count,int[] visited,ArrayList<Integer> list,int[] crr) {
		visited[start]=1;
		list.add(start);
		for(int i=0;i<graph[start].size();i++) {
			int curr=(int)graph[start].get(i);
			if(visited[curr]==0) {
				
				
				dfs(graph,curr,count,visited,list,crr);
			}
		}
		
		
		
		
		
	}
	
}