import java.util.*;
import java.lang.*;
import java.io.*;

























public class cf105 {






























            











































    public static void main(String[] args) throws Exception{
        InputStreamReader ip=new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(ip);
        

        


        

        

            

            String[] strs=(br.readLine()).trim().split(" ");
            

            

            int n=Integer.parseInt(strs[0]),q=Integer.parseInt(strs[1]),k=Integer.parseInt(strs[2]);

            long[] arr=new long[n+1];
            

            strs=(br.readLine()).trim().split(" ");
            for(int i=0;i<n;i++){
                arr[i+1]=Long.parseLong(strs[i]);
            }
            
            long[] psum=new long[n+1];
            Arrays.fill(psum, 0L);
            for(int i=1;i<=(n);i++){
                if(i>1 && i<(n)){
                    psum[i]+=psum[i-1]+  (arr[i]-arr[i-1])+(arr[i+1]-arr[i])-2 ;
                }else if(i==1 && n>1){
                    psum[i]+=(arr[i+1]-2);
                }else if(i==(n) && n>1){
                    psum[i]+=psum[i-1]+k-(arr[i-1])-1;
                }
            }
            
            for(int j=0;j<q;j++){
                strs=(br.readLine()).trim().split(" ");
                long ans=0L;

                int l=Integer.parseInt(strs[0]),r=Integer.parseInt(strs[1]);
                 if(l==r){System.out.println(k-1); continue;}

                if((r-1)>l){
                    ans+=psum[r-1]-psum[l];
                } 
                ans+=(arr[l+1]-2);
                ans+=k-(arr[r-1])-1;
                System.out.println(ans);
                

            }
            
        

        }
    }

    

    

    

    

    


    

    

    

    

    

    

    

            
    

    

    

    


    

    

    

    

    


    


    

    

    

    































            




















































































            




























































    

    

    

    

    


    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    


    

    

    

    

    










































































































































































            
























            










            

            

            

            


            

            

            

            

            

    

    

    
































































                    


















    

    

    

    

    


    

    

    

    

    

    

    

    

    

    



    

    

    

            
    

    


    

    


    


    

    

    

    

    

    


    

    

    


    

    

    

    

    

    

           
    

    

    

    


    

    

    

    

    

    

    


    

    

    

                
    

    

    

    

    

    


    

    






            

            

            

            

            

            

            


            

            

            

            

            

            

            

            


            

            

            

            

            

            

            


            

            

            

            

            

            

            

            

            

            

            

            

            

            


            

            

            

            

            

            


            

            

            

            

            

            

            

            


            

            

            

            

            

            

            


            

            





























            























































































            





