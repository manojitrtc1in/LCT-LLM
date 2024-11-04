#include              <algorithm>
#include               <iostream>
#include                <cstring>
#include                <stdio.h>
#include                 <string>
#include                 <vector>
#include                 <time.h>
#include                  <queue>
#include                  <cmath>
#include                    <map>
#include                    <set>
using   namespace            std;
typedef	long long             vt;
typedef unsigned long long   vt2;
typedef	pair<vt,vt>          PVV;
typedef	pair<char,vt>        PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt,vt>           MVV;
typedef map<char,vt>         MCV;
typedef map<string,vt>       MSV;
#define sd(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(x)   scanf("%s",&x)
#define fi(x,y) for(int i=x;i<y;i++)
#define fj(x,y) for(int j=x;j<y;j++)
#define fk(x,y) for(int k=x;k<y;k++)
const int MAXN = 1e6 + 9, INF = 0x3f3f3f3f;
vt HASHprime = 1333331;



void add(char a[], char b[], char back[])
{
	int i, j, k, up, x, y, z, l;
	char* c;
	if (strlen(a) > strlen(b)) l = strlen(a) + 2; else l = strlen(b) + 2; c = (char*)malloc(l * sizeof(char)); i = strlen(a) - 1;
	j = strlen(b) - 1;
	k = 0; up = 0;
	while (i >= 0 || j >= 0)
	{
		if (i < 0) x = '0'; else x = a[i];
		if (j < 0) y = '0'; else y = b[j];
		z = x - '0' + y - '0';
		if (up) z += 1;
		if (z > 9) { up = 1; z %= 10; }
		else up = 0;
		c[k++] = z + '0';
		i--; j--;
	}
	if (up) c[k++] = '1';
	i = 0;
	c[k] = '\0';
	for (k -= 1; k >= 0; k--)
		back[i++] = c[k];
	back[i] = '\0';
}
int main()
{
	int l;
	cin >> l;
	char n[MAXN];
	cin >> n;
	int mid1, mid2;
	for (mid1 = l % 2 ? l / 2 : l / 2 - 1; mid1 >= 0 && n[mid1] == '0'; mid1--)
		;
	for (mid2 = l % 2 ? l / 2 + 1 : l / 2; mid1 < l && n[mid2] == '0'; mid2++)
		;
	char a1[MAXN], b1[MAXN],a2[MAXN],b2[MAXN];
	int cnt = 0;
	fi(0, mid1)
		a1[cnt++] = n[i];
	a1[cnt] = '\0';
	cnt = 0;
	fi(mid1, l)
		b1[cnt++] = n[i];
	b1[cnt]= '\0';
	cnt = 0;
	fi(0, mid2)
		a2[cnt++] = n[i];
	a2[cnt]= '\0';
	cnt = 0;
	fi(mid2, l)
		b2[cnt++] = n[i];
	b2[cnt]= '\0';
	char ans1[MAXN], ans2[MAXN];
	add(a1, b1, ans1);
	add(a2, b2, ans2);
	if (strlen(ans1) != strlen(ans2))
	{
		if (strlen(ans1) > strlen(ans2))
			cout << ans2 << endl;
		else
			cout << ans1 << endl;
	}
	else
	{
		if (strcmp(ans1, ans2) >= 0)
			cout << ans2 << endl;
		else
			cout << ans1 << endl;
	}
	return 0;
}
