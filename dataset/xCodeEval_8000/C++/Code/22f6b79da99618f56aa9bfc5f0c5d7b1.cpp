

















#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
char s[100010];
int bucket[210000], rankk[210000], pos[210000], y[210000],height[210000],x[210000];
struct valuee{
	int amount,len;
};
valuee value[1100000];
int top;
ll anss;
void getans(int len)
{
	top = 0; anss = 0;
	for (int i = 1; i <= len; i++)
	{
		int tempall = 0;
		while (top != 0 && value[top].len >=height[i])
		{
			ll realamount= value[top].amount+1;
			ll reallen = value[top].len - max(height[i],value[top-1].len);
			realamount = (realamount*(realamount + 1)) / 2;
			anss += realamount*reallen;
			if (value[top - 1].len >height[i])
				value[top - 1].amount += value[top].amount;
			else
				tempall += value[top].amount;
			top--;
		}
		if (height[i])
		{
			value[++top].len = height[i];
			value[top].amount= tempall+1;
		}
		else
		{
			value[0].len = 0; value[0].amount = 0;
		}
		int reallen = len - 1 - rankk[i]+1- max(height[i],height[i-1]);
		anss += reallen;
	}
}
void stringsort(int len)
{
	int templen = max(len, 26);
	for (int i = 0; i < len; i++)
	{
		bucket[s[i] - 'a' + 1]++;
	}
	for (int i = 1; i <=templen; i++)
		bucket[i] += bucket[i - 1];
	for (int i = 0; i < len; i++)
		rankk[bucket[s[i] - 'a' + 1]--] = i,
		pos[i]=s[i]-'a'+1;
	for (int i = 1;i<=templen; i++)
		bucket[i] = 0;
	for (int i = 1; i <=len; i<<=1)

	{
		int m = 0;
		for (int j = len-1; j >len-1- i; j--)
			y[m++] = j;
		for (int j = 1; j <=len; j++)
		{
			if (rankk[j] <= i - 1 )
				continue;
			y[m++] = rankk[j] - i;
		}
		for (int j = 0; j < len; j++)
			bucket[pos[j]]++;
		for (int j = 1; j <= templen; j++)
			bucket[j] += bucket[j - 1];
		for (int j = 0; j < len; j++)
			x[j] = pos[j];
		for (int j = m-1; j>=0; j--)
		{
			int realrank = x[y[j]];
			rankk[bucket[realrank]--] = y[j];
		}
		for (int j= 0; j <= templen; j++)
			bucket[j] = 0;
		int level = 1;
		pos[rankk[1]] = 1;
		for (int j = 2; j <= len; j++)
		{
			int pos1 = rankk[j]; int pos2 = rankk[j - 1];
			int pos3 = pos1 + i; int pos4 = pos2 + i;
			if (x[pos1]>x[pos2])
			{
				pos[pos1] = ++level;
			}
			else
			{
				if (x[pos3] > x[pos4])
					pos[pos1] = ++level;
				else
					pos[pos1] = level;
			}
		}
	}
	for (int i = 0; i < len; i++)
		rankk[pos[i]] = i;
}
void getheight(int len)
{
	int h = 0;
	for (int i = 0; i < len; i++)
	{
		if (h)
			h--;
		int rank1 = pos[i]; int rank2 = rank1 + 1;
		int pos2 = rankk[rank2];
		while (s[i + h] == s[pos2 + h]&&rank1!=len)
			h++;
		if (rank1 != len)
			height[rank1] = h;
		else
			height[rank1] = 0;
	}
}

void solve(int len)
{
	int j=1;
	for (int i = 1; i <= len; i=j)
	{
		j = i;
	}
}
int main()
{
	scanf("%s", s);
	int len = strlen(s);
	stringsort(len);
	getheight(len);
	getans(len);
	printf("%I64d\n", anss);
	return 0;
}

