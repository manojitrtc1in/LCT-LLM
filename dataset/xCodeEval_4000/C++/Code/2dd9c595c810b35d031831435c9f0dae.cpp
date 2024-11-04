
#include <bits/stdc++.h>
using namespace std;















































































































































































































































































































































































































































































struct Point{ 

	long long x, y;
	Point() : x(0), y(0) {}
	Point(long long x, long long y) : x(x), y(y) {}
	bool operator < (const Point & p) const {return make_pair(x,y) < make_pair(p.x, p.y);}
	bool operator == (const Point & p) const {return make_pair(x,y) == make_pair(p.x, p.y);}
	bool operator != (const Point & p) const {return ! (*this == p); }
    Point operator = (const Point & p) { x = p.x, y = p.y;  return *this; }
    Point operator + (const Point & p) const { return Point(x+p.x, y+p.y);}
    Point operator - (const Point & p) const { return Point(x-p.x, y-p.y);}
    Point operator * (double c) const { return Point(x*c, y*c);}
};
long long cross(Point p, Point q) {return p.x * q.y - p.y * q.x;}
long long dot(Point p, Point q) {return p.x*q.x + p.y*q.y;}









long long isLeft( Point P0, Point P1, Point P2 ) {
    return cross(P1-P0, P2-P0);
}

struct Segment {
	Point s, t;
	bool operator < (const Segment & sg) const {return s < sg.s || ((s==sg.s)&&(t<sg.t)); }
	bool operator == (const Segment & sg) const {return s==sg.s && t==sg.t;}
};

void showS(set<Point> & sp) {
	for(Point x : sp)
		cout << "(" << x.x << "," << x.y << "), " ;
	cout << endl;
}

void showV(vector<Segment> & vs) {
	for(Segment x : vs)
		cout << "(" << x.s.x << "," << x.s.y << "), " << "(" << x.t.x << "," << x.t.y << ")"  << endl;
}

bool insideHinhQuat(Point A0, Point X, Point Y, Point B) {

	

	

	return (isLeft(A0, X, B) <= 0 && isLeft(A0,Y,B) >= 0 );
}

bool insideTriangle (Point A, Point B, Point C, Point Z) { 

	

	return ( isLeft(B, C, Z) <= 0 );
}
		


int main() {





 	int n;
 	cin >> n; 

 	vector<Point> polygonA; 

 	for(int i=0; i<n; ++i) {
 		Point a;
 		cin >> a.x >> a.y;
 		polygonA.push_back(a);
 	}
 	int m;
 	cin >> m; 

 	vector<Point> polygonB; 

 	for(int i=0; i<m; ++i) {
 		Point a;
 		cin >> a.x >> a.y; 

 		polygonB.push_back(a);
 	}
 	

 	

 	

 	Point A0 = polygonA.at(0);
 	for(size_t i=0; i<polygonB.size(); ++i) {
 		




 		
 		Point Bi = polygonB.at(i);
 		if(!insideHinhQuat(A0, polygonA.at(1), polygonA.at(n-1), Bi)) {
 			


 			
 			cout <<  "NO" << endl;
 			return 0;
 		}
 		int start = 1, end = n-1; 

 		while(end-start>=2) { 

 			int mid = (end+start)/2;
 			


 			
 			if(insideHinhQuat(A0, polygonA.at(start), polygonA.at(mid), Bi)) {
 				end = mid;
 			}
 			else {
 				start = mid;
 			}
 		}
 		


 		
		

		if(!insideTriangle(A0, polygonA.at(start), polygonA.at(end), Bi))  {
			


			
			cout <<  "NO" << endl;
			return 0;
		}
		else { 

			if ( (start == 1 && isLeft(A0, polygonA.at(start), Bi) == 0)
					|| (end == n-1 && isLeft(A0, polygonA.at(end), Bi) == 0)
					|| (isLeft(polygonA.at(start), polygonA.at(end), Bi) == 0) ) {
				


				
				cout <<  "NO" << endl;
				return 0;
			}
		}
 	}
 	cout << "YES" << endl;
 	
	return 0;
}