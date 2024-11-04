












int main(void)
{
    int g = 0;
    char str[255];
    char str2[255];
    int x = 0;
    
    int *pos;
     int c = 0;
    int m = 0;
    int *nbr;
    int t = 0;
    scanf("%d",&t);
    nbr = malloc(sizeof(int)* t);
    while(t-- > 0)
    {
        int i = 0;
        int total = 0;
        int temp = 0;
        int l = 0;
        scanf("%s",str);
        scanf("%s",str2);
        int rep = 0;
        pos = malloc(sizeof(int)*strlen(str2));
       int j =0;
        
        while(str2[i])
        {
            while(str[x])
            {
                if(str2[i] == str[x])
                    pos[j++] = x + 1;
                x++;
            }
            x = 0;
            i++;
        }
        rep = j - 1;
        j = 0;
        while(rep-- > 0)
        {
            temp = pos[j + 1] - pos[j];
            if(temp < 0)
                temp *= -1;
            total += temp;
            j++;
        }
        nbr[c++] = total;
    }
    while(c > g)
        printf("%d\n",nbr[g++]);
}











 













































