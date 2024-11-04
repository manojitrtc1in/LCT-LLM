#include <iostream>
#include <conio.h>
#include <string>

struct segment
{
	int x1;
	int y1;
	int x2;	
	int y2;

	segment() {}
	segment(int xup, int yl, int xd, int yr) : x1(xup), y1(yl), x2(xd), y2(yr) {}
};

struct rect
{
	int x1;
	int y1;
	int x2;	
	int y2;
	segment seg[4];
	int size;

	rect() {}
	rect(int xup, int yl, int xd, int yr) : x1(xup), y1(yl), x2(xd), y2(yr) {}
};

struct point
{
	int x;
	int y;
	point() {}
	point(int bx, int by) : x(bx), y(by) {}
};

struct flatseg
{
	int p1;
	int p2;
	flatseg() {}
	flatseg(int bp1, int bp2) : p1(bp1), p2(bp2) {}
};

const int maxNM = 1000;

flatseg rows[maxNM][4];	

flatseg columns[maxNM][4];		


int arPoint[maxNM][maxNM];
int n, m;
int countWorkPoint;

int CalcPf(segment a, segment b);
bool IsOnlyFrame(rect rect1, rect rect2);
void AddRect(int xup, int yl, int xd, int yr);
bool IsGoodParams(point plu, point prd);
bool IsGorizontalLineGood(int x, int p1, int p2);
bool IsVerticalLineGood(int y, int p1, int p2);

int countRect;
rect arRect[2000000];	

const int maxSizeRct = 4001;
int arSizesRect[maxSizeRct];	


int main()
{
	using namespace std;

	string strNM[maxNM];
		
	cin >> n >> m;
	for(int i=0; i < n; i++)
	{
		cin >> strNM[i];		
	}

	for(int i=0; i < n; i++)
	{
		string str = strNM[i];
		for(int j=0; j < m; j++)
		{
			char ch = str[j];			
			if(ch == '.')
			{
				arPoint[i][j] = 0;
			}
			else if(ch == '#')
			{
				arPoint[i][j] = 1;
			}
		}
	}
	
	

	


	for(int i=0; i<maxNM; i++)
	{
		for(int ns=0; ns<4; ns++)
		{
			rows[i][ns] = flatseg(-1, -1);
			columns[i][ns] = flatseg(-1, -1);		
		}
	}

	

	for(int x=0; x<n; x++)
	{
		bool isLine = false;
		int ns = -1;
		int p1, p2;
		for(int y=0; y<m; y++)
		{
			if(arPoint[x][y])
			{
				

				if(!isLine)
				{
					isLine = true;
					p1 = y;
					ns++;

					

					if(ns >= 4)
					{
						cout << "NO";
						return 0;
					}					
				}				
			}
			else
			{
				

				if(isLine)
				{
					isLine = false;
					p2 = y-1;
					rows[x][ns] = flatseg(p1, p2);					
				}
			}
		}

		

		if(isLine)
		{
			p2 = m-1;
			rows[x][ns] = flatseg(p1, p2);
		}
	}

	

	for(int y=0; y<m; y++)
	{
		bool isLine = false;
		int ns = -1;
		int p1, p2;
		for(int x=0; x<n; x++)
		{
			if(arPoint[x][y])
			{
				

				if(!isLine)
				{
					isLine = true;
					p1 = x;
					ns++;

					

					if(ns >= 4)
					{
						cout << "NO";
						return 0;
					}					
				}				
			}
			else
			{
				

				if(isLine)
				{
					isLine = false;
					p2 = x-1;
					columns[y][ns] = flatseg(p1, p2);					
				}
			}
		}

		

		if(isLine)
		{
			p2 = n-1;
			columns[y][ns] = flatseg(p1, p2);
		}
	}

	


	point workPoint[8000];	

	int cpf = 0;
	for(int x1=0; x1<n; x1++)
	{
		for(int y1=0; y1<m; y1++)
		{
			if(arPoint[x1][y1])
			{
				workPoint[cpf++] = point(x1, y1);
				if(cpf > 8000)
				{
					cout << "NO";
					return 0;
				}
			}
		}
	}
	countWorkPoint = cpf;
	countRect = 0;
	for(int i=0; i<maxSizeRct; i++)
	{
		arSizesRect[i] = 0;
	}

	

	int lefty = 1000, righty = 0;
	for(int i=0; i<countWorkPoint; i++)
	{
		if(workPoint[i].y < lefty)
		{
			lefty = workPoint[i].y;
		}
		if(workPoint[i].y > righty)
		{
			righty = workPoint[i].y;
		}
	}
	

	int upx = 1000, downx = 0;
	for(int i=0; i<countWorkPoint; i++)
	{
		if((workPoint[i].y == lefty) && (workPoint[i].x < upx))
		{
			upx = workPoint[i].x;
		}
		if((workPoint[i].y == righty) && (workPoint[i].x > downx))
		{
			downx = workPoint[i].x;
		}
	}
	
	

	for(int lu = 0; lu < countWorkPoint; lu++)
	{
		for(int rd = (lu+1); rd < countWorkPoint; rd++)
		{
			if(IsGoodParams(workPoint[lu], workPoint[rd]))
			{
				AddRect(workPoint[lu].x, workPoint[lu].y, workPoint[rd].x, workPoint[rd].y);
			}
		}
	}

	

	int arSizesRectLarger[maxSizeRct];
	arSizesRectLarger[maxSizeRct-1] = arSizesRect[maxSizeRct-1];
	int allCount = 0;
	for(int i=maxSizeRct-2; i >=0; i--)
	{
		allCount += arSizesRect[i+1];
		arSizesRectLarger[i] = arSizesRect[i] + allCount;
	}

	for(int i=0; i<countRect; i++)
	{
		

		if((arRect[i].x1 != upx) || (arRect[i].y1 != lefty))
		{
			continue;
		}

		int minSizeRectTwo = countWorkPoint - arRect[i].size;
		if((minSizeRectTwo > 4000) || (arSizesRectLarger[minSizeRectTwo] == 0))
		{
			continue;
		}

		for(int j=0; j<countRect; j++)
		{
			

			

			

			


			

			if(((arRect[i].x2 == downx) && (arRect[i].y2 == righty)) || ((arRect[j].x2 == downx) && (arRect[j].y2 == righty)))
			{
				if(IsOnlyFrame(arRect[i], arRect[j]))
				{	
					cout << "YES" << endl;
					cout << arRect[i].x1+1 << " " << arRect[i].y1+1 << " " << arRect[i].x2+1 << " " << arRect[i].y2+1 << " " << endl;
					cout << arRect[j].x1+1 << " " << arRect[j].y1+1 << " " << arRect[j].x2+1 << " " << arRect[j].y2+1 << " " << endl;
					
					

					return 0;
				}
			}						
		}
	}

	

	cout << "NO";
	

	return 0;
}

bool IsGoodParams(point plu, point prd)
{
	if((prd.x < (plu.x+2)) || prd.y < (plu.y+2))
		return false;
	if(!IsGorizontalLineGood(plu.x, plu.y, prd.y))
		return false;
	if(!IsGorizontalLineGood(prd.x, plu.y, prd.y))
		return false;
	if(!IsVerticalLineGood(plu.y, plu.x, prd.x))
		return false;
	if(!IsVerticalLineGood(prd.y, plu.x, prd.x))
		return false;

	

	return true;
}

bool IsGorizontalLineGood(int x, int p1, int p2)
{
	for(int i=0; i<4; i++)
	{
		if(rows[x][i].p1 == -1)
		{
			return false;
		}
		else if((p1 >= rows[x][i].p1) && (p2 <= rows[x][i].p2))
		{
			return true;
		}
	}
	return false;
}

bool IsVerticalLineGood(int y, int p1, int p2)
{
	for(int i=0; i<4; i++)
	{
		if(columns[y][i].p1 == -1)
		{
			return false;
		}
		else if((p1 >= columns[y][i].p1) && (p2 <= columns[y][i].p2))
		{
			return true;
		}
	}
	return false;
}

void AddRect(int xup, int yl, int xd, int yr)
{
	rect rct(xup, yl, xd, yr);
	
	rct.seg[0] = segment(xup, yl, xup, yr);
	rct.seg[1] = segment(xd, yl, xd, yr);
	rct.seg[2] = segment(xup+1, yr, xd-1, yr);
	rct.seg[3] = segment(xup+1, yl, xd-1, yl);

	rct.size = (yr-yl+1)*2 + (xd-xup-1 )*2;

	arSizesRect[rct.size]++;	


	arRect[countRect] = rct;

	countRect++;	
}



bool IsOnlyFrame(rect rect1, rect rect2)
{
	int countpf = (rect1.x2 - rect1.x1 + 1)*2 + (rect1.y2 - rect1.y1 - 1)*2;

	if((rect1.x1 == rect2.x1) && (rect1.y1 == rect2.y1) && (rect1.x2 == rect2.x2) && (rect1.y2 == rect2.y2))
	{
		if(countpf == countWorkPoint)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	

	else if(rect2.x1 > rect1.x2 || rect2.x2 < rect1.x1 || rect2.y1 > rect1.y2 || rect2.y2 < rect1.y1 )
	{
		countpf += ((rect2.x2 - rect2.x1 + 1)*2 + (rect2.y2 - rect2.y1 - 1)*2);
		
		if(countpf == countWorkPoint)
		{
			return true;
		}
		else
		{
			return false;
		}		
	}

	countpf += ((rect2.x2 - rect2.x1 + 1)*2 + (rect2.y2 - rect2.y1 - 1)*2);

	int calcpf = 0;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			calcpf += CalcPf(rect1.seg[i], rect2.seg[j]);
		}
	}

	countpf -= calcpf;

	if(countpf == countWorkPoint)
	{
		return true;
	}
	else
	{
		return false;
	}	
}


int CalcPf(segment a, segment b)
{
	int calcpf = 0;

	if(a.x1 == a.x2)
	{
		if(b.x1 == b.x2)
		{
			if(a.x1 == b.x1)
			{
				if((a.y2 < b.y1) || (a.y1 > b.y2))
				{
					return 0;
				}
				else
				{
					if((a.y1 >= b.y1) && (a.y2 <= b.y2))
					{
						calcpf = a.y2 - a.y1 + 1;
					}
					else if((b.y1 >= a.y1) && (b.y2 <= a.y2))
					{
						calcpf = b.y2 - b.y1 + 1;
					}					
					else if((a.y1 >= b.y1) && (a.y2 >= b.y2))
					{
						calcpf = b.y2 - a.y1 + 1;
					}
					else if((b.y1 >= a.y1) && (b.y2 >= a.y2))
					{
						calcpf = a.y2 - b.y1 + 1;
					}
				}
			}
		}
		else if(b.y1 == b.y2)
		{
			if((a.y2 < b.y1) || (a.y1 > b.y1))
			{
				return 0;
			}
			else
			{
				if((a.x1 >= b.x1) && (a.x1 <= b.x2))
				{
					if((a.y1 <= b.y1) && (a.y2 >= b.y1))
					{
						calcpf = 1;
					}
				}
			}
		}
	}
	else if(a.y1 == a.y2)
	{
		if(b.x1 == b.x2)
		{
			if((b.y2 < a.y1) || (b.y1 > a.y2))
			{
				return 0;
			}
			else
			{
				if((b.x1 >= a.x1) && (b.x1 <= a.x2))
				{
					if((b.y1 <= a.y1) && (b.y2 >= a.y1))
					{
						calcpf = 1;
					}
				}
			}
		}
		else if(b.y1 == b.y2)
		{
			if(a.y1 == b.y1)
			{
				if((a.x2 < b.x1) || (a.x1 > b.x2))
				{
					return 0;
				}
				else
				{
					if((a.x1 >= b.x1) && (a.x2 <= b.x2))
					{
						calcpf = a.x2 - a.x1 + 1;
					}
					else if((b.x1 >= a.x1) && (b.x2 <= a.x2))
					{
						calcpf = b.x2 - b.x1 + 1;
					}					
					else if((a.x1 >= b.x1) && (a.x2 >= b.x2))
					{
						calcpf = b.x2 - a.x1 + 1;
					}
					else if((b.x1 >= a.x1) && (b.x2 >= a.x2))
					{
						calcpf = a.x2 - b.x1 + 1;
					}
				}
			}
		}
	}

	return calcpf;
}