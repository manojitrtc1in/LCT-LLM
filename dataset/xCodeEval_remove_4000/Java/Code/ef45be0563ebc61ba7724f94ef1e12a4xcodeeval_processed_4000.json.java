
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
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
	static int flag=0;
	static int min=Integer.MAX_VALUE;
	public static void main(String[] args) throws Exception
	{
		Reader s=new Reader();

		int n=s.nextInt();
		int[] brr=new int[n+1];
		int[] arr=new int[n+1];
		
		for(int i=1;i<n+1;i++) {
			brr[i]=s.nextInt();
			
		}
		
		for(int i=1;i<n+1;i++) {
			arr[i]=s.nextInt();
		}
		int ans=0;
		int[] visited=new int[n+1];
		for(int i=1;i<n+1;i++) {
			if(visited[i]==0) {
				min=Integer.MAX_VALUE;
						flag=0;
				dfs(arr,brr,visited,i);
				if(flag==0) {
					ans=ans+min;
				}
			}
		}
		System.out.println(ans);
		
		
		  
		}
	public static int dfs(int[] arr,int[] brr,int[] visited,int start ) {
		
		visited[start]=1;
		if(visited[arr[start]]==0) {
			dfs(arr,brr,visited,arr[start]);
		}else {
			flag=arr[start];
			
			min=Math.min(min, brr[start]);
			
		}
		
		if(start==flag) {
			flag=0;
			min=Math.min(min, brr[start]);	
		}else if(flag!=0){
			min=Math.min(min, brr[start]);	
		}
		return min;
		
	}
		
	}
