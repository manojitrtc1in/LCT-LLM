import java.util.*; 
public class id0{
public static void main(String[] args)
{
   Scanner omkar = new Scanner(System.in);
   int cases = omkar.nextInt();
   int n;
   int[] arr; 
   int temp;
   boolean boolin;
   for(int i = 0; i < cases; i++)
   {
      n = omkar.nextInt();
      arr = new int[n];
      boolin = false;
      for(int j = 0; j < n; j++)
      {
         temp = omkar.nextInt() % n;
         temp = (j + temp) % n;
         if(temp < 0)
         {
            temp = temp + n;
         }
         arr[temp] = arr[temp] + 1;
         if(arr[temp] >= 2)
         {
            boolin = true;
         }
      }
      if(boolin)
      {
         System.out.println("NO");
      }
      else
      {
         System.out.println("YES");
      }
      
   } 
   
     
   }
   
   
      }
      
      
























