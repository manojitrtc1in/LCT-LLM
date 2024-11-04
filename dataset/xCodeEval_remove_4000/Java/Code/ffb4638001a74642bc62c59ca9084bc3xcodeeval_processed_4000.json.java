import java.util.*;

public class Tester {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int ttt = input.nextInt();
        

        for(int testCase = 1; testCase <= ttt; testCase++){
            int n = input.nextInt();
            ArrayList<Long> a = new ArrayList<Long>();
            for(int i = 0; i < n; i++){
                a.add(input.nextLong());
            }
            Collections.sort(a);
            long aScore = 0;
            long bScore = 0;
            boolean aTurn = true;
            for(int i = n - 1; i >= 0; i--){
                if(aTurn && a.get(i) % 2 == 0){
                    aScore += a.get(i);
                }else if(!aTurn && a.get(i) % 2 == 1){
                    bScore += a.get(i);
                }
                aTurn = !aTurn;
            }
            
            if(aScore > bScore){
                System.out.println("Alice");
            }else if(bScore > aScore){
                System.out.println("Bob");
            }else{
                System.out.println("Tie");
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
    
    private static boolean id0(String s){
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
}