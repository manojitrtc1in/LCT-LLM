

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class b{
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
  
	
	public static void main(String[] args) throws Exception 
	{
		Reader s=new Reader();
	
		int n=s.nextInt();
		StringBuilder sb=new StringBuilder();
		ArrayList[] arr=new ArrayList[n+1];
		for(int i=0;i<n+1;i++) {
			ArrayList<Integer> list=new ArrayList<>();
			arr[i]=list;
		}
		int[][] ne=new int[n-1][2];
		HashMap<String,Integer> map=new HashMap<>();
		for(int i=0;i<n-1;i++) {
			int a=s.nextInt();
			int b=s.nextInt();
			arr[a].add(b);
			ne[i][0]=a;
			ne[i][1]=b;
			
			arr[b].add(a);
		}
		int max=-1;
		int index=-1;
		for(int i=0;i<n+1;i++) {
			if(max<arr[i].size()) {
				max=(int)arr[i].size();
				index=i;
			}
		}
	
		
		

		

		int count=0;
		

		Queue<Integer> q=new LinkedList<>();
		int[] visited=new int[n+1];
		visited[index]=1;
		HashMap<Integer,Integer> map2=new HashMap<>();
		q.add(index);
		while(!q.isEmpty()) {
			
			int curr=q.poll();
			
			for(int i=0;i<arr[curr].size();i++) {
				
				int l=(int)arr[curr].get(i);
				if(visited[l]==0) {
					visited[l]=1;
					
					q.add(l);
					map.put(curr+" "+l, count);
					count++;
					
				}
			}
		}

		

		for(int i=0;i<n-1;i++) {
			if(map.containsKey(ne[i][0]+" "+ne[i][1])) {
				sb.append((map.get(ne[i][0]+" "+ne[i][1])+"\n"));
			}else  {
				sb.append((map.get(ne[i][1]+" "+ne[i][0])+"\n"));
			}
		}
		System.out.println(sb);
		
		
		
		
	}
}