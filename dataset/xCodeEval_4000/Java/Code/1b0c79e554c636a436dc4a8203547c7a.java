import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;


public class CODEFORCES {
     static HashMap<Integer, Integer> sortByValue(HashMap<Integer, Integer> hm)
    {
        

        List<Map.Entry<Integer, Integer> > list =
               new LinkedList<Map.Entry<Integer, Integer> >(hm.entrySet());
 
        

        Collections.sort(list, new Comparator<Map.Entry<Integer, Integer> >() {
            public int compare(Map.Entry<Integer, Integer> o1,
                               Map.Entry<Integer, Integer> o2)
            {
                return (o1.getValue()).compareTo(o2.getValue());
            }
        });
         
        

        HashMap<Integer, Integer> temp = new LinkedHashMap<Integer, Integer>();
        for (Map.Entry<Integer, Integer> aa : list) {
            temp.put(aa.getKey(), aa.getValue());
        }
        return temp;
    }
    static class FastReader {
        byte[] buf = new byte[2048];
        int index, total;
        InputStream in;
 
        FastReader(InputStream is) {
            in = is;
        }
 
        int scan() throws IOException {
            if (index >= total) {
                index = 0;
                total = in.read(buf);
                if (total <= 0) {
                    return -1;
                }
            }
            return buf[index++];
        }
 
        String next() throws IOException {
            int c;
            for (c = scan(); c <= 32; c = scan())
                ;
            StringBuilder sb = new StringBuilder();
            for (; c > 32; c = scan()) {
                sb.append((char) c);
            }
            return sb.toString();
        }
 
        String nextLine() throws IOException {
            int c;
            for (c = scan(); c <= 32; c = scan())
                ;
            StringBuilder sb = new StringBuilder();
            for (; c != 10 && c != 13; c = scan()) {
                sb.append((char) c);
            }
            return sb.toString();
        }
 
        char nextChar() throws IOException {
            int c;
            for (c = scan(); c <= 32; c = scan())
                ;
            return (char) c;
        }
 
        int nextInt() throws IOException {
            int c, val = 0;
            for (c = scan(); c <= 32; c = scan())
                ;
            boolean neg = c == '-';
            if (c == '-' || c == '+') {
                c = scan();
            }
            for (; c >= '0' && c <= '9'; c = scan()) {
                val = (val << 3) + (val << 1) + (c & 15);
            }
            return neg ? -val : val;
        }
 
        long nextLong() throws IOException {
            int c;
            long val = 0;
            for (c = scan(); c <= 32; c = scan())
                ;
            boolean neg = c == '-';
            if (c == '-' || c == '+') {
                c = scan();
            }
            for (; c >= '0' && c <= '9'; c = scan()) {
                val = (val << 3) + (val << 1) + (c & 15);
            }
            return neg ? -val : val;
        }
 
    }

    public static void main(String[] args) throws java.lang.Exception {
      FastReader sc=new FastReader(System.in);
        int w=sc.nextInt();
        for(int g=0;g<w;g++) {
            
           int size=sc.nextInt();
             int k=sc.nextInt();
             
             int arr[]=new int[size];
              int arr2[]=new int[size];
               int arr3[]=new int[size];
                 int arr4[]=new int[size];
               
              for(int i=0;i<size;i++){
                  arr[i]=sc.nextInt();
              }
              
              for(int i=0;i<size;i++){
                  arr3[i]=-1;
              }
              
               int count=0,m=1,count2=0;
               
               
    Map<Integer,Integer> list= new HashMap<>();
      
      Map<Integer,Integer> list2= new HashMap<>();
          
      Map<Integer,Integer> list3= new HashMap<>();
         HashMap<Integer,Integer> list4= new HashMap<Integer,Integer>();
	     for(int i=0;i<size;i++){
	       if(!list.containsKey(arr[i])){
	           list.put(arr[i],1);
	           
	            arr2[count++]=arr[i];
	       } else if(list.containsKey(arr[i])){
	          
	           list.put(arr[i],list.get(arr[i])+1);
	           
	       }
	     }
	     

	      int r=0;
	       for(int i=0;i<count;i++){
	           
	           if(list.get(arr2[i])>=k){
	               list2.put(arr2[i],1);
	              
	           }
	           else{
	                  arr4[r++]=arr2[i];  
                 list3.put(arr2[i],1);
	               count2+=list.get(arr2[i]);
	           }
	       }
	  
	       for(int j=0;j<size;j++){
	                if(list2.containsKey(arr[j])){
	                     if(list2.get(arr[j])>k){
	                         arr3[j]=0;
	                     }else{
	                        
	                          arr3[j]=list2.get(arr[j]); 
	                        list2.put(arr[j],list2.get(arr[j])+1); 
	                     }
	             }
	         }
	       count=0;
	       

	       

	       
	       
	       
	       
	       
	       
	   

	   

	   

	          int u=count2/k;
	    u=u*k;
	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	                     
	   

	   

	                 
	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	   

	    
	     for(int i=0;i<arr.length;i++){
	        if(list3.containsKey(arr[i])){
	            list4.put(i,arr[i]);
	        }
	     }
	       Map<Integer,Integer> list5= sortByValue(list4);
	       m=1;
	       for (Map.Entry<Integer, Integer> en : list5.entrySet()) {
	             if(count==u)break;
	           if(m>k)m=1;
	           count++;
	           
            arr3[en.getKey()]=m; 
             if(count==u)break;
            m++;
        } 
	       
	       




	       
	       
	         for(int i=0;i<size;i++){
	             if(arr3[i]==-1)arr3[i]=0;
	             System.out.print(arr3[i]+" ");
	         }
	         System.out.println();
	         
	         
	         
	         
	         
	    
                
}
}
}







































       

            

            

            

            

            

            

            

            

            

            

            

            

            

            

                              
            

                           
            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            










 

    

    

    

    

 
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

 
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

 
    

    

    

    

    

    

    

    

    

    

    

    

    

    

 
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

 
    

    

    

    

    

    

    

 
    

    

    

    

    



















                    


















                   


                 






                   










                              




















                               










                            


                      






















                      














             














    