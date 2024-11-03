




using namespace std;
int n,k,i,j;
char charin[20][20][20];
int ngto[20][20];
int check[20][MAX2];
vector<int> V[MAX];
int tinh[MAX];
int main()
{
    int l,kt1,kt2,tmp1;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%s",charin[0][i]);
    }
    for(i=0;i<k;i++)
    {
        scanf("%s",charin[1][i]);
    }
    j=0;
    for(i=0;i<n;i++)
    {
        if(strlen(charin[j][i])==1&&charin[j][i][0]=='H')
            ngto[j][i]=1;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='H'&&charin[j][i][1]=='e')
            ngto[j][i]=2;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='L'&&charin[j][i][1]=='i')
            ngto[j][i]=3;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='B'&&charin[j][i][1]=='e')
            ngto[j][i]=4;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='B')
            ngto[j][i]=5;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='C')
            ngto[j][i]=6;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='N')
            ngto[j][i]=7;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='O')
            ngto[j][i]=8;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='F')
            ngto[j][i]=9;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='N'&&charin[j][i][1]=='e')
            ngto[j][i]=10;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='N'&&charin[j][i][1]=='a')
            ngto[j][i]=11;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='M'&&charin[j][i][1]=='g')
            ngto[j][i]=12;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='l')
            ngto[j][i]=13;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='S'&&charin[j][i][1]=='i')
            ngto[j][i]=14;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='P')
            ngto[j][i]=15;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='S')
            ngto[j][i]=16;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='l')
            ngto[j][i]=17;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='r')
            ngto[j][i]=18;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='K')
            ngto[j][i]=19;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='a')
            ngto[j][i]=20;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='S'&&charin[j][i][1]=='c')
            ngto[j][i]=21;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='i')
            ngto[j][i]=22;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='V')
            ngto[j][i]=23;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='r')
            ngto[j][i]=24;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='M'&&charin[j][i][1]=='n')
            ngto[j][i]=25;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='F'&&charin[j][i][1]=='e')
            ngto[j][i]=26;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='o')
            ngto[j][i]=27;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='N'&&charin[j][i][1]=='i')
            ngto[j][i]=28;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='u')
            ngto[j][i]=29;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='Z'&&charin[j][i][1]=='n')
            ngto[j][i]=30;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='G'&&charin[j][i][1]=='a')
            ngto[j][i]=31;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='G'&&charin[j][i][1]=='e')
            ngto[j][i]=32;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='s')
            ngto[j][i]=33;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='S'&&charin[j][i][1]=='e')
            ngto[j][i]=34;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='B'&&charin[j][i][1]=='r')
            ngto[j][i]=35;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='K'&&charin[j][i][1]=='r')
            ngto[j][i]=36;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='R'&&charin[j][i][1]=='b')
            ngto[j][i]=37;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='S'&&charin[j][i][1]=='r')
            ngto[j][i]=38;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='Y')
            ngto[j][i]=39;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='Z'&&charin[j][i][1]=='r')
            ngto[j][i]=40;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='N'&&charin[j][i][1]=='b')
            ngto[j][i]=41;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='M'&&charin[j][i][1]=='o')
            ngto[j][i]=42;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='c')
            ngto[j][i]=43;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='R'&&charin[j][i][1]=='u')
            ngto[j][i]=44;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='R'&&charin[j][i][1]=='h')
            ngto[j][i]=45;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='d')
            ngto[j][i]=46;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='g')
            ngto[j][i]=47;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='d')
            ngto[j][i]=48;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='I'&&charin[j][i][1]=='n')
            ngto[j][i]=49;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='S'&&charin[j][i][1]=='n')
            ngto[j][i]=50;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='S'&&charin[j][i][1]=='b')
            ngto[j][i]=51;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='e')
            ngto[j][i]=52;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='I')
            ngto[j][i]=53;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='X'&&charin[j][i][1]=='e')
            ngto[j][i]=54;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='s')
            ngto[j][i]=55;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='B'&&charin[j][i][1]=='a')
            ngto[j][i]=56;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='L'&&charin[j][i][1]=='a')
            ngto[j][i]=57;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='e')
            ngto[j][i]=58;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='r')
            ngto[j][i]=59;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='N'&&charin[j][i][1]=='d')
            ngto[j][i]=60;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='m')
            ngto[j][i]=61;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='S'&&charin[j][i][1]=='m')
            ngto[j][i]=62;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='E'&&charin[j][i][1]=='u')
            ngto[j][i]=63;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='G'&&charin[j][i][1]=='d')
            ngto[j][i]=64;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='b')
            ngto[j][i]=65;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='D'&&charin[j][i][1]=='y')
            ngto[j][i]=66;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='H'&&charin[j][i][1]=='o')
            ngto[j][i]=67;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='E'&&charin[j][i][1]=='r')
            ngto[j][i]=68;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='m')
            ngto[j][i]=69;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='Y'&&charin[j][i][1]=='b')
            ngto[j][i]=70;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='L'&&charin[j][i][1]=='u')
            ngto[j][i]=71;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='H'&&charin[j][i][1]=='f')
            ngto[j][i]=72;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='a')
            ngto[j][i]=73;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='W')
            ngto[j][i]=74;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='R'&&charin[j][i][1]=='e')
            ngto[j][i]=75;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='O'&&charin[j][i][1]=='s')
            ngto[j][i]=76;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='I'&&charin[j][i][1]=='r')
            ngto[j][i]=77;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='t')
            ngto[j][i]=78;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='u')
            ngto[j][i]=79;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='H'&&charin[j][i][1]=='g')
            ngto[j][i]=80;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='l')
            ngto[j][i]=81;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='b')
            ngto[j][i]=82;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='B'&&charin[j][i][1]=='i')
            ngto[j][i]=83;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='o')
            ngto[j][i]=84;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='t')
            ngto[j][i]=85;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='R'&&charin[j][i][1]=='n')
            ngto[j][i]=86;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='F'&&charin[j][i][1]=='r')
            ngto[j][i]=87;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='R'&&charin[j][i][1]=='a')
            ngto[j][i]=88;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='c')
            ngto[j][i]=89;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='h')
            ngto[j][i]=90;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='a')
            ngto[j][i]=91;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='U')
            ngto[j][i]=92;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='N'&&charin[j][i][1]=='p')
            ngto[j][i]=93;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='u')
            ngto[j][i]=94;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='m')
            ngto[j][i]=95;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='m')
            ngto[j][i]=96;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='B'&&charin[j][i][1]=='k')
            ngto[j][i]=97;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='f')
            ngto[j][i]=98;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='E'&&charin[j][i][1]=='s')
            ngto[j][i]=99;
        else
            ngto[j][i]=100;
    }
    j=1;
    for(i=0;i<k;i++)
    {
        if(strlen(charin[j][i])==1&&charin[j][i][0]=='H')
            ngto[j][i]=1;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='H'&&charin[j][i][1]=='e')
            ngto[j][i]=2;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='L'&&charin[j][i][1]=='i')
            ngto[j][i]=3;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='B'&&charin[j][i][1]=='e')
            ngto[j][i]=4;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='B')
            ngto[j][i]=5;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='C')
            ngto[j][i]=6;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='N')
            ngto[j][i]=7;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='O')
            ngto[j][i]=8;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='F')
            ngto[j][i]=9;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='N'&&charin[j][i][1]=='e')
            ngto[j][i]=10;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='N'&&charin[j][i][1]=='a')
            ngto[j][i]=11;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='M'&&charin[j][i][1]=='g')
            ngto[j][i]=12;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='l')
            ngto[j][i]=13;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='S'&&charin[j][i][1]=='i')
            ngto[j][i]=14;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='P')
            ngto[j][i]=15;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='S')
            ngto[j][i]=16;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='l')
            ngto[j][i]=17;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='r')
            ngto[j][i]=18;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='K')
            ngto[j][i]=19;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='a')
            ngto[j][i]=20;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='S'&&charin[j][i][1]=='c')
            ngto[j][i]=21;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='i')
            ngto[j][i]=22;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='V')
            ngto[j][i]=23;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='r')
            ngto[j][i]=24;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='M'&&charin[j][i][1]=='n')
            ngto[j][i]=25;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='F'&&charin[j][i][1]=='e')
            ngto[j][i]=26;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='o')
            ngto[j][i]=27;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='N'&&charin[j][i][1]=='i')
            ngto[j][i]=28;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='u')
            ngto[j][i]=29;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='Z'&&charin[j][i][1]=='n')
            ngto[j][i]=30;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='G'&&charin[j][i][1]=='a')
            ngto[j][i]=31;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='G'&&charin[j][i][1]=='e')
            ngto[j][i]=32;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='s')
            ngto[j][i]=33;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='S'&&charin[j][i][1]=='e')
            ngto[j][i]=34;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='B'&&charin[j][i][1]=='r')
            ngto[j][i]=35;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='K'&&charin[j][i][1]=='r')
            ngto[j][i]=36;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='R'&&charin[j][i][1]=='b')
            ngto[j][i]=37;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='S'&&charin[j][i][1]=='r')
            ngto[j][i]=38;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='Y')
            ngto[j][i]=39;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='Z'&&charin[j][i][1]=='r')
            ngto[j][i]=40;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='N'&&charin[j][i][1]=='b')
            ngto[j][i]=41;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='M'&&charin[j][i][1]=='o')
            ngto[j][i]=42;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='c')
            ngto[j][i]=43;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='R'&&charin[j][i][1]=='u')
            ngto[j][i]=44;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='R'&&charin[j][i][1]=='h')
            ngto[j][i]=45;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='d')
            ngto[j][i]=46;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='g')
            ngto[j][i]=47;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='d')
            ngto[j][i]=48;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='I'&&charin[j][i][1]=='n')
            ngto[j][i]=49;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='S'&&charin[j][i][1]=='n')
            ngto[j][i]=50;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='S'&&charin[j][i][1]=='b')
            ngto[j][i]=51;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='e')
            ngto[j][i]=52;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='I')
            ngto[j][i]=53;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='X'&&charin[j][i][1]=='e')
            ngto[j][i]=54;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='s')
            ngto[j][i]=55;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='B'&&charin[j][i][1]=='a')
            ngto[j][i]=56;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='L'&&charin[j][i][1]=='a')
            ngto[j][i]=57;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='e')
            ngto[j][i]=58;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='r')
            ngto[j][i]=59;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='N'&&charin[j][i][1]=='d')
            ngto[j][i]=60;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='m')
            ngto[j][i]=61;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='S'&&charin[j][i][1]=='m')
            ngto[j][i]=62;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='E'&&charin[j][i][1]=='u')
            ngto[j][i]=63;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='G'&&charin[j][i][1]=='d')
            ngto[j][i]=64;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='b')
            ngto[j][i]=65;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='D'&&charin[j][i][1]=='y')
            ngto[j][i]=66;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='H'&&charin[j][i][1]=='o')
            ngto[j][i]=67;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='E'&&charin[j][i][1]=='r')
            ngto[j][i]=68;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='m')
            ngto[j][i]=69;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='Y'&&charin[j][i][1]=='b')
            ngto[j][i]=70;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='L'&&charin[j][i][1]=='u')
            ngto[j][i]=71;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='H'&&charin[j][i][1]=='f')
            ngto[j][i]=72;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='a')
            ngto[j][i]=73;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='W')
            ngto[j][i]=74;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='R'&&charin[j][i][1]=='e')
            ngto[j][i]=75;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='O'&&charin[j][i][1]=='s')
            ngto[j][i]=76;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='I'&&charin[j][i][1]=='r')
            ngto[j][i]=77;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='t')
            ngto[j][i]=78;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='u')
            ngto[j][i]=79;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='H'&&charin[j][i][1]=='g')
            ngto[j][i]=80;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='l')
            ngto[j][i]=81;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='b')
            ngto[j][i]=82;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='B'&&charin[j][i][1]=='i')
            ngto[j][i]=83;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='o')
            ngto[j][i]=84;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='t')
            ngto[j][i]=85;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='R'&&charin[j][i][1]=='n')
            ngto[j][i]=86;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='F'&&charin[j][i][1]=='r')
            ngto[j][i]=87;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='R'&&charin[j][i][1]=='a')
            ngto[j][i]=88;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='c')
            ngto[j][i]=89;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='T'&&charin[j][i][1]=='h')
            ngto[j][i]=90;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='a')
            ngto[j][i]=91;
        else if(strlen(charin[j][i])==1&&charin[j][i][0]=='U')
            ngto[j][i]=92;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='N'&&charin[j][i][1]=='p')
            ngto[j][i]=93;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='P'&&charin[j][i][1]=='u')
            ngto[j][i]=94;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='A'&&charin[j][i][1]=='m')
            ngto[j][i]=95;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='m')
            ngto[j][i]=96;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='B'&&charin[j][i][1]=='k')
            ngto[j][i]=97;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='C'&&charin[j][i][1]=='f')
            ngto[j][i]=98;
        else if(strlen(charin[j][i])==2&&charin[j][i][0]=='E'&&charin[j][i][1]=='s')
            ngto[j][i]=99;
        else
            ngto[j][i]=100;
    }
    int sum;
    for(i=0;i<(1<<n);i++)
    {
        sum=0;
        for(j=0;j<n;j++)
        {
            if(((1<<j)&i)!=0)
            {
                sum+=ngto[0][j];
            }
        }
        V[sum].push_back(i);
        tinh[sum]++;
    }
    check[0][0]=1;
    for(i=0;i<k;i++)
    {
        for(j=0;j<(1<<n);j++)
        {
            if(check[i][j])
            {
                for(l=0;l<tinh[ngto[1][i]];l++)
                    if((V[ngto[1][i]][l]&j)==0)check[i+1][V[ngto[1][i]][l]+j]=1;
            }
        }
    }
    if(check[k][(1<<n)-1])
    {
        printf("YES\n");
        tmp1=(1<<n)-1;
        for(i=k-1;i>=0;i--)
        {
            kt1=1;
            for(j=tinh[ngto[1][i]]-1;j>=0;j--)
            {
                if(kt1&&((V[ngto[1][i]][j]&tmp1)==V[ngto[1][i]][j])&&check[i][tmp1-V[ngto[1][i]][j]])
                {
                    kt1=0;
                    kt2=1;
                    for(l=0;l<n;l++)
                    {
                        if(((1<<l)&V[ngto[1][i]][j])==(1<<l))
                        {
                            if(kt2)
                            {
                                kt2=0;
                            }
                            else
                            {
                                printf("+");
                            }
                            printf("%s",charin[0][l]);
                        }
                    }
                    printf("->%s\n",charin[1][i]);
                    tmp1-=V[ngto[1][i]][j];
                }
            }
        }
    }
    else printf("NO\n");
}
