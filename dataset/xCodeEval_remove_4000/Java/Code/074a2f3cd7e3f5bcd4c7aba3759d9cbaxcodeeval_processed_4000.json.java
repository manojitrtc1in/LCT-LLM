import java.util.*;

public class Tester {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int ttt = input.nextInt();
        input.nextLine();
        for(int testCase = 1; testCase <= ttt; testCase++){
            String n = input.nextLine();
            
            if(id4(n) || id4(n.substring(1)) || n.indexOf("11") == -1){
                System.out.println("YES");
            }else{
                String newString = n.substring(n.indexOf("11"));
                if(n.indexOf("00", n.indexOf("11"))>-1){
                    System.out.println("NO");
                }else{
                    System.out.println("YES");
                }
            }
            
            

            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            

            
            
            
            
            
            
            
            
            
            
            
        
            
            
            
            
            
            
            
            
            
            
            
           
            
            
            
            
            
            
            
            
            
            
            
            
            
        }
        
    }
    
    private static void printArr(int[] arr){
        System.out.print("[");
        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i]);
            if(i < arr.length - 1){
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }
    
    private static int gcd(int a, int b){
        int s;
        int l;
        
        if(a > b){
            s = b;
            l = a;
        }else{
            s = a;
            l = b;
        }
        int gcd = 1;
        for(int i = 1; i <= s; i++){
            if(s % i == 0 && b % i == 0){
                gcd = i;
            }
        }
        return gcd;
    }
    
    private static boolean id1(String s){
        String lastChar = s.substring(0, 1);
        for(int i = 1; i < s.length(); i++){
            if(!lastChar.equals(s.substring(i, i + 1))){
                return false;
            }
            lastChar = s.substring(i, i + 1);
        }
        return true;
    }
    
    private static boolean isPalindrome(String s){
        for(int i = 0; i < s.length() / 2; i++){
            if(!(s.charAt(i) == s.charAt(s.length() - (i + 1)))){
                return false;
            }
        }
        return true;
    }
    
    private static String id2(String str){
        String repStr = str;
        String id0 = str;
        
        
        return repStr;
    }
    
    private static ArrayList<Integer> id3(int n){
        ArrayList<Integer> a = new ArrayList<Integer>();
        
        
        
        return a;
    }
    
    private static boolean id4(String s){
        boolean zeros = true;
        int index = 0;
        while(index < s.length()){
            if(zeros){
                if(!s.substring(index, index + 1).equals("0")){
                    zeros = false;
                }
            }else{
                if(!s.substring(index, index + 1).equals("1")){
                    return false;
                }
            }
            index++;
        }
        return true;
    }
}