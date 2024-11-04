







using namespace std;

int n,k;
int i,j;
char in[2][20][5];
int val[2][20];
bool is[18][POW2_17];
vector<int> V[MAX_SUM];
int deg[MAX_SUM];

void compute()
{
	j=0;
	for(i=0;i<n;i++)
	{
		if(strlen(in[j][i])==1&&in[j][i][0]=='H')
			val[j][i]=1;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='H'&&in[j][i][1]=='e')
			val[j][i]=2;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='L'&&in[j][i][1]=='i')
			val[j][i]=3;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='B'&&in[j][i][1]=='e')
			val[j][i]=4;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='B')
			val[j][i]=5;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='C')
			val[j][i]=6;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='N')
			val[j][i]=7;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='O')
			val[j][i]=8;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='F')
			val[j][i]=9;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='N'&&in[j][i][1]=='e')
			val[j][i]=10;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='N'&&in[j][i][1]=='a')
			val[j][i]=11;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='M'&&in[j][i][1]=='g')
			val[j][i]=12;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='l')
			val[j][i]=13;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='S'&&in[j][i][1]=='i')
			val[j][i]=14;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='P')
			val[j][i]=15;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='S')
			val[j][i]=16;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='l')
			val[j][i]=17;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='r')
			val[j][i]=18;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='K')
			val[j][i]=19;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='a')
			val[j][i]=20;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='S'&&in[j][i][1]=='c')
			val[j][i]=21;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='i')
			val[j][i]=22;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='V')
			val[j][i]=23;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='r')
			val[j][i]=24;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='M'&&in[j][i][1]=='n')
			val[j][i]=25;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='F'&&in[j][i][1]=='e')
			val[j][i]=26;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='o')
			val[j][i]=27;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='N'&&in[j][i][1]=='i')
			val[j][i]=28;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='u')
			val[j][i]=29;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='Z'&&in[j][i][1]=='n')
			val[j][i]=30;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='G'&&in[j][i][1]=='a')
			val[j][i]=31;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='G'&&in[j][i][1]=='e')
			val[j][i]=32;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='s')
			val[j][i]=33;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='S'&&in[j][i][1]=='e')
			val[j][i]=34;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='B'&&in[j][i][1]=='r')
			val[j][i]=35;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='K'&&in[j][i][1]=='r')
			val[j][i]=36;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='R'&&in[j][i][1]=='b')
			val[j][i]=37;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='S'&&in[j][i][1]=='r')
			val[j][i]=38;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='Y')
			val[j][i]=39;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='Z'&&in[j][i][1]=='r')
			val[j][i]=40;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='N'&&in[j][i][1]=='b')
			val[j][i]=41;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='M'&&in[j][i][1]=='o')
			val[j][i]=42;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='c')
			val[j][i]=43;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='R'&&in[j][i][1]=='u')
			val[j][i]=44;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='R'&&in[j][i][1]=='h')
			val[j][i]=45;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='d')
			val[j][i]=46;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='g')
			val[j][i]=47;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='d')
			val[j][i]=48;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='I'&&in[j][i][1]=='n')
			val[j][i]=49;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='S'&&in[j][i][1]=='n')
			val[j][i]=50;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='S'&&in[j][i][1]=='b')
			val[j][i]=51;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='e')
			val[j][i]=52;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='I')
			val[j][i]=53;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='X'&&in[j][i][1]=='e')
			val[j][i]=54;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='s')
			val[j][i]=55;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='B'&&in[j][i][1]=='a')
			val[j][i]=56;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='L'&&in[j][i][1]=='a')
			val[j][i]=57;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='e')
			val[j][i]=58;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='r')
			val[j][i]=59;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='N'&&in[j][i][1]=='d')
			val[j][i]=60;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='m')
			val[j][i]=61;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='S'&&in[j][i][1]=='m')
			val[j][i]=62;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='E'&&in[j][i][1]=='u')
			val[j][i]=63;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='G'&&in[j][i][1]=='d')
			val[j][i]=64;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='b')
			val[j][i]=65;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='D'&&in[j][i][1]=='y')
			val[j][i]=66;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='H'&&in[j][i][1]=='o')
			val[j][i]=67;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='E'&&in[j][i][1]=='r')
			val[j][i]=68;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='m')
			val[j][i]=69;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='Y'&&in[j][i][1]=='b')
			val[j][i]=70;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='L'&&in[j][i][1]=='u')
			val[j][i]=71;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='H'&&in[j][i][1]=='f')
			val[j][i]=72;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='a')
			val[j][i]=73;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='W')
			val[j][i]=74;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='R'&&in[j][i][1]=='e')
			val[j][i]=75;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='O'&&in[j][i][1]=='s')
			val[j][i]=76;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='I'&&in[j][i][1]=='r')
			val[j][i]=77;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='t')
			val[j][i]=78;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='u')
			val[j][i]=79;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='H'&&in[j][i][1]=='g')
			val[j][i]=80;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='l')
			val[j][i]=81;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='b')
			val[j][i]=82;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='B'&&in[j][i][1]=='i')
			val[j][i]=83;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='o')
			val[j][i]=84;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='t')
			val[j][i]=85;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='R'&&in[j][i][1]=='n')
			val[j][i]=86;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='F'&&in[j][i][1]=='r')
			val[j][i]=87;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='R'&&in[j][i][1]=='a')
			val[j][i]=88;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='c')
			val[j][i]=89;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='h')
			val[j][i]=90;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='a')
			val[j][i]=91;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='U')
			val[j][i]=92;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='N'&&in[j][i][1]=='p')
			val[j][i]=93;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='u')
			val[j][i]=94;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='m')
			val[j][i]=95;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='m')
			val[j][i]=96;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='B'&&in[j][i][1]=='k')
			val[j][i]=97;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='f')
			val[j][i]=98;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='E'&&in[j][i][1]=='s')
			val[j][i]=99;
		else
			val[j][i]=100;
	}
	j=1;
	for(i=0;i<k;i++)
	{
		if(strlen(in[j][i])==1&&in[j][i][0]=='H')
			val[j][i]=1;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='H'&&in[j][i][1]=='e')
			val[j][i]=2;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='L'&&in[j][i][1]=='i')
			val[j][i]=3;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='B'&&in[j][i][1]=='e')
			val[j][i]=4;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='B')
			val[j][i]=5;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='C')
			val[j][i]=6;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='N')
			val[j][i]=7;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='O')
			val[j][i]=8;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='F')
			val[j][i]=9;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='N'&&in[j][i][1]=='e')
			val[j][i]=10;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='N'&&in[j][i][1]=='a')
			val[j][i]=11;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='M'&&in[j][i][1]=='g')
			val[j][i]=12;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='l')
			val[j][i]=13;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='S'&&in[j][i][1]=='i')
			val[j][i]=14;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='P')
			val[j][i]=15;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='S')
			val[j][i]=16;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='l')
			val[j][i]=17;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='r')
			val[j][i]=18;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='K')
			val[j][i]=19;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='a')
			val[j][i]=20;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='S'&&in[j][i][1]=='c')
			val[j][i]=21;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='i')
			val[j][i]=22;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='V')
			val[j][i]=23;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='r')
			val[j][i]=24;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='M'&&in[j][i][1]=='n')
			val[j][i]=25;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='F'&&in[j][i][1]=='e')
			val[j][i]=26;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='o')
			val[j][i]=27;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='N'&&in[j][i][1]=='i')
			val[j][i]=28;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='u')
			val[j][i]=29;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='Z'&&in[j][i][1]=='n')
			val[j][i]=30;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='G'&&in[j][i][1]=='a')
			val[j][i]=31;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='G'&&in[j][i][1]=='e')
			val[j][i]=32;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='s')
			val[j][i]=33;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='S'&&in[j][i][1]=='e')
			val[j][i]=34;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='B'&&in[j][i][1]=='r')
			val[j][i]=35;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='K'&&in[j][i][1]=='r')
			val[j][i]=36;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='R'&&in[j][i][1]=='b')
			val[j][i]=37;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='S'&&in[j][i][1]=='r')
			val[j][i]=38;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='Y')
			val[j][i]=39;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='Z'&&in[j][i][1]=='r')
			val[j][i]=40;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='N'&&in[j][i][1]=='b')
			val[j][i]=41;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='M'&&in[j][i][1]=='o')
			val[j][i]=42;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='c')
			val[j][i]=43;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='R'&&in[j][i][1]=='u')
			val[j][i]=44;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='R'&&in[j][i][1]=='h')
			val[j][i]=45;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='d')
			val[j][i]=46;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='g')
			val[j][i]=47;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='d')
			val[j][i]=48;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='I'&&in[j][i][1]=='n')
			val[j][i]=49;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='S'&&in[j][i][1]=='n')
			val[j][i]=50;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='S'&&in[j][i][1]=='b')
			val[j][i]=51;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='e')
			val[j][i]=52;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='I')
			val[j][i]=53;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='X'&&in[j][i][1]=='e')
			val[j][i]=54;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='s')
			val[j][i]=55;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='B'&&in[j][i][1]=='a')
			val[j][i]=56;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='L'&&in[j][i][1]=='a')
			val[j][i]=57;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='e')
			val[j][i]=58;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='r')
			val[j][i]=59;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='N'&&in[j][i][1]=='d')
			val[j][i]=60;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='m')
			val[j][i]=61;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='S'&&in[j][i][1]=='m')
			val[j][i]=62;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='E'&&in[j][i][1]=='u')
			val[j][i]=63;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='G'&&in[j][i][1]=='d')
			val[j][i]=64;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='b')
			val[j][i]=65;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='D'&&in[j][i][1]=='y')
			val[j][i]=66;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='H'&&in[j][i][1]=='o')
			val[j][i]=67;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='E'&&in[j][i][1]=='r')
			val[j][i]=68;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='m')
			val[j][i]=69;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='Y'&&in[j][i][1]=='b')
			val[j][i]=70;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='L'&&in[j][i][1]=='u')
			val[j][i]=71;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='H'&&in[j][i][1]=='f')
			val[j][i]=72;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='a')
			val[j][i]=73;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='W')
			val[j][i]=74;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='R'&&in[j][i][1]=='e')
			val[j][i]=75;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='O'&&in[j][i][1]=='s')
			val[j][i]=76;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='I'&&in[j][i][1]=='r')
			val[j][i]=77;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='t')
			val[j][i]=78;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='u')
			val[j][i]=79;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='H'&&in[j][i][1]=='g')
			val[j][i]=80;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='l')
			val[j][i]=81;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='b')
			val[j][i]=82;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='B'&&in[j][i][1]=='i')
			val[j][i]=83;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='o')
			val[j][i]=84;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='t')
			val[j][i]=85;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='R'&&in[j][i][1]=='n')
			val[j][i]=86;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='F'&&in[j][i][1]=='r')
			val[j][i]=87;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='R'&&in[j][i][1]=='a')
			val[j][i]=88;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='c')
			val[j][i]=89;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='T'&&in[j][i][1]=='h')
			val[j][i]=90;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='a')
			val[j][i]=91;
		else if(strlen(in[j][i])==1&&in[j][i][0]=='U')
			val[j][i]=92;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='N'&&in[j][i][1]=='p')
			val[j][i]=93;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='P'&&in[j][i][1]=='u')
			val[j][i]=94;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='A'&&in[j][i][1]=='m')
			val[j][i]=95;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='m')
			val[j][i]=96;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='B'&&in[j][i][1]=='k')
			val[j][i]=97;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='C'&&in[j][i][1]=='f')
			val[j][i]=98;
		else if(strlen(in[j][i])==2&&in[j][i][0]=='E'&&in[j][i][1]=='s')
			val[j][i]=99;
		else
			val[j][i]=100;
	}
	return ;
}

int main()
{
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%s",in[0][i]);
	}
	for(i=0;i<k;i++)
	{
		scanf("%s",in[1][i]);
	}
	compute();
	int sum;
	for(i=0;i<(1<<n);i++)
	{
		sum=0;
		for(j=0;j<n;j++)
		{
			if(((1<<j)&i)!=0)
			{
				sum+=val[0][j];
			}
		}
		V[sum].push_back(i);
		deg[sum]++;
	}
	int l;
	is[0][0]=1;
	for(i=0;i<k;i++)
	{
		for(j=0;j<(1<<n);j++)
		{
			if(is[i][j])
			{
				for(l=0;l<deg[val[1][i]];l++)
				{
					if((V[val[1][i]][l]&j)==0)
					{
						is[i+1][V[val[1][i]][l]+j]=1;
					}
				}
			}
		}
	}
	bool chk,chk2;
	int tmp1;
	if(is[k][(1<<n)-1])
	{
		printf("YES\n");
		tmp1=(1<<n)-1;
		for(i=k-1;i>=0;i--)
		{
			chk=1;
			for(j=deg[val[1][i]]-1;j>=0;j--)
			{
				if(chk&&((V[val[1][i]][j]&tmp1)==V[val[1][i]][j])&&is[i][tmp1-V[val[1][i]][j]])
				{
					chk=0;
					chk2=1;
					for(l=0;l<n;l++)
					{
						if(((1<<l)&V[val[1][i]][j])==(1<<l))
						{
							if(chk2)
							{
								chk2=0;
							}
							else
							{
								printf("+");
							}
							printf("%s",in[0][l]);
						}
					}
					printf("->%s\n",in[1][i]);
					tmp1-=V[val[1][i]][j];
				}
			}
		}
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}