import java.util.*;
import java.lang.*;
import java.io.*;

























public class cf105 {
     static int[] valid={1,1,1,0,0,1,0,0,1,0},rev={0,1,5,0,0,2,0,0,8,0};
    public static boolean check(int cm){
        boolean f=true;
        while(cm>0){
            int r=cm%10;
            cm=cm/10;
            if(r==0 || r==1 || r==2 || r==5 || r==8){}
            else{f=false; break;}
        }

        return f;
    }
    

    public static int refn(int i){
        StringBuilder sb=new StringBuilder();
        sb.append(""+i);
        String ref1=sb.reverse().toString();
        while(ref1.length()<2){ref1+='0';}
        String revs="";
        for(char ch:ref1.toCharArray()){
            revs+=rev[ch-'0'];
        }
        int val=Integer.valueOf(revs);
        return val;
    }
    public static void main(String[] args) throws Exception{
        InputStreamReader ip=new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(ip);
        

        int t= Integer.parseInt(br.readLine());

        while(t-->0){
        

            

            String[] strs=(br.readLine()).trim().split(" ");
            

            

            int h=Integer.parseInt(strs[0]),m=Integer.parseInt(strs[1]);


            strs=(br.readLine()).trim().split(":");
            int hh=Integer.parseInt(strs[0]),mm=Integer.parseInt(strs[1]);

            int i=hh;
            int j=mm;
            boolean of=false;
            int ah=0,am=0;
            int run=0;
            while(i<h && !of){
                boolean f11=check(i);
                boolean f22=check(j);
                int hr2=refn(j),mn2=refn(i);
                    if(f11 && f22 && hr2<h && mn2<m && i<h && j<m){
                        ah=i; am=j; of=true; break;
                    }

                while(j<m){
                    j++;  run++;
                    boolean f1=check(i);
                    boolean f2=check(j);
                    
                    int hr=refn(j),mn=refn(i);
                    if(f1 && f2 && hr<h && mn<m && i<h && j<m){
                        ah=i; am=j; of=true; break;
                    }
                }
                if(of){break;}
                if(j==m){i++; j=0; run++;}
            }

            

            

            

            
            

            

            

            

            

            

            


            

            

            

            

            

            

            

            

            

            

            

            String s1=""+ah,s2=""+am; 
            while(s1.length()<2){s1='0'+s1;}   while(s2.length()<2){s2='0'+s2;}

            

                System.out.println(s1+":"+s2);
            

            

            

           
        }
    }
}


















































































































            











































    

    

    

    

    


    

    

    

    

    

    

    


    

    

    

    

    

    

            
    

    

    

    

    

    

    

    

    

    

    

            
    

    

    


    

    


    

    

    

    

    

    

    

    

            
    

    

    


    

    

    

    

    


    

    

    

    

    

    

    

            
    

    

    

    


    

    

    

    

    


    


    

    

    

    































            




















































































            




























































    

    

    

    

    


    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    


    

    

    

    

    










































































































































































            
























            










            

            

            

            


            

            

            

            

            

    

    

    
































































                    


















    

    

    

    

    


    

    

    

    

    

    

    

    

    

    



    

    

    

            
    

    


    

    


    


    

    

    

    

    

    


    

    

    


    

    

    

    

    

    

           
    

    

    

    


    

    

    

    

    

    

    


    

    

    

                
    

    

    

    

    

    


    

    






            

            

            

            

            

            

            


            

            

            

            

            

            

            

            


            

            

            

            

            

            

            


            

            

            

            

            

            

            

            

            

            

            

            

            

            


            

            

            

            

            

            


            

            

            

            

            

            

            

            


            

            

            

            

            

            

            


            

            





























            























































































            





