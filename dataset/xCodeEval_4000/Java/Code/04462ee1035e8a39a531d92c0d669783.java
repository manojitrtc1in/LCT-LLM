import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Codeforces_611D_v8 {
    
    static long[] k;
    static int[] numbers;
    static int[][] common_prefix; 
    
    
    static int crawl(int a, int b)
    {
        if (a+1 > numbers.length || b+1 > numbers.length)
            return 0;
        
        if (common_prefix[a][b] == 0 && numbers[a]==numbers[b])
            common_prefix[a][b] = crawl(a+1,b+1) + 1;
        else if(common_prefix[a][b] != 0)
            return common_prefix[a][b];
        return common_prefix[a][b];
    }
    
    static int strCmp(int currentI, int currentJ, int compareI, int compareJ)
    {        
        int currentLen = currentI+1;
        
        int compareLen = compareI+1;
        
        
        int currentStart = (currentJ-currentI) >= 0 ? (currentJ-currentI) : 0;
        int compareStart = (compareJ-compareI) >= 0 ? (compareJ-compareI) : 0;        
        if (numbers[currentStart] == 0)
                return 0;
        
        if (numbers[compareStart] == 0)
                return 1;
                
        if (currentLen > compareLen)
            return 1;
        
        else if (currentLen == compareLen)
        {        	
        	int i;
        	i=common_prefix[compareStart][currentStart];
        	


        	if (i < (currentStart-compareStart))


            {
                if (numbers[currentStart+i]<numbers[compareStart+i])
                    return -1;                
                else if (numbers[currentStart+i]==numbers[compareStart+i])
                    

                	return -1;
                else
                    return 1;
                    
            }
        }
        return -1;    
    }
   
    public static void main(String[] args)
    {	
		
        Scanner scanIn = new Scanner(System.in);	
        String testCase = scanIn.nextLine();
        testCase = scanIn.nextLine();


















        
        int testCaseLen = testCase.length();


        long[][] dpTable =  new long[testCaseLen][testCaseLen];
	
        numbers =  new int[testCaseLen];
        k =  new long[testCaseLen];
        
        for (int i = 0; i<testCaseLen; i++)
            numbers[i] = (int) (testCase.charAt(i))- 48;
        
        
        common_prefix = new int[testCaseLen][testCaseLen]; 
        
        for (int i = 0 ; i < testCaseLen; i++)
        {
            for (int j = i+1 ; j < testCaseLen; j++)
            {
                crawl(i,j);
















            }
        }
        
        
        
        for (int i = 0 ; i < testCaseLen; i++)
        {
            for (int j = 0 ; j < testCaseLen; j++)
            {
            	

            	if (i>j)
                {
            		dpTable[i][j] = 0;
                }
                else if(i==j)
                {
                    dpTable[i][j] = 1;
                }
                else
                {
                    int ni = 0, nj = 0;
                    if((j+1)-(i+1)>i)
                        ni = i;
                    else
                        ni = ((j+1)-(i+1))-1;	
                    nj = j-(i+1);

                    int strCmpResult = strCmp(i, j, ni, nj);                    
                    if (strCmpResult == 1)
                    {
                        dpTable[i][j] = k[nj];
                    }
                    else if (strCmpResult == -1)
                    {
                    	if (i==0)
                    		dpTable[i][j]=0;
                    	else
                    		dpTable[i][j] = k[nj] - dpTable[ni][nj];
                    }
                    else if (strCmpResult == 0)
                    {
                        dpTable[i][j] = 0;
                    }
                    else
                        continue;
                }        			
                k[j]+= dpTable[i][j];
                k[j] = k[j]%1000000007;
            }                
        }






































































		

                System.out.print(k[testCaseLen-1]);
        return;
    }
}