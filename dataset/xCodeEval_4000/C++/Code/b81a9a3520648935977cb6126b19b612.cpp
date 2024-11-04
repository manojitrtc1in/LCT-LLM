#define _CRT_SECURE_NO_DEPRECATE





#include <stdio.h>
#include <tchar.h>
#include <iostream>

#include <math.h>




#include <vector>


#ifndef ONLINE_JUDGE
#include <time.h>
#include <assert.h>
#include "..\..\Common\define.h"
#endif

#ifndef PI
#define PI 3.1415926535897932384626433832795
#endif


#ifndef POINT_VECTOR_2_COMMON
#define POINT_VECTOR_2_COMMON \
	T x,y; \
	this_t operator-() const { return this_t(-x, -y); } \
	this_t operator+=(const CVector<T>& A) { x += A.x; y += A.y; return *this; } \
	this_t operator+(const CVector<T>& A) const { this_t R = *this; R += A; return R; } \
	this_t operator-=(const CVector<T>& A) { x -= A.x; y -= A.y; return *this; } \
	this_t operator-(const CVector<T>& A) const { this_t R = *this; R -= A; return R; } \
	this_t operator*=(T k) { x *= k; y *= k; return *this; } \
	this_t operator*(T k) const { this_t R = *this; R *= k; return R; } \
	this_t operator/=(T k) { x /= k; y /= k; return *this; } \
	this_t operator/(T k) const { this_t R = *this; R /= k; return R; } \
	bool Equals(const this_t& A, T eps=T(1e-10)) const { return (x-A.x)*(x-A.x) + (y-A.y)*(y-A.y) < eps*eps; } \
	template<typename ostream_t> void Echo(ostream_t& ostream) const { ostream<<"("<<x<<", "<<y<<")\n"; }
#endif
	
namespace al { namespace geom_2d {
	template<typename T> bool Equals(T a, T b, T eps) { return a > b ? a-b < eps : b-a < eps; }
	template<typename T> bool InRegion(T x, T a, T b, T eps) { return (a-eps<x && b+eps>x) || (b-eps<x && a+eps>x); }

	template<typename T> struct CVector;
	template<typename T> struct CPoint {
		typedef CPoint<T> this_t;
		POINT_VECTOR_2_COMMON;
		CPoint(const T X=T(0), const T Y=T(0)) { x = X, y = Y; }
		CVector<T> operator-(const this_t& A) const { return CVector<T>(x-A.x, y-A.y); }
		CVector<T> Vector() const { return CVector<T>(x, y); }
		T Distance2(const this_t& A) const { return (x-A.x)*(x-A.x) + (y-A.y)*(y-A.y); }
		T Distance(const this_t& A) const { return pow(Distance2(A), T(0.5)); }
	};
	template<typename T> struct CVector {
		typedef CVector<T> this_t;
		POINT_VECTOR_2_COMMON;
		CVector(const T X=T(0), const T Y=T(0)) { x = X, y = Y; }
		CPoint<T> Point() const { return CPoint<T>(x, y); }
		T Length2() const { return x*x+y*y; }
		T Length() const { return pow(x*x+y*y, T(0.5)); }
		T operator*(const this_t& A) const {return x*A.x+y*A.y; }
		T VectMult(const this_t& A) const {return x*A.y-y*A.x; }
		this_t GetRotated(T A) const { return CVector<T>(x*cos(A) - y*sin(A), x*sin(A) + y*cos(A)); }
		this_t GetRotated90CCW() const { return CVector<T>(-y, x); }
		this_t GetRotated90CW() const { return CVector<T>(y, -x); }
		this_t GetNormalized() const { this_t R(x, y); R /= R.Length(); return R; }
	};
	template<typename T> struct CLine {
		typedef CLine<T> this_t;
		T a,b,c;
		CLine(const T A=T(0), const T B=T(0), const T C=T(0)) { a=A; b=B; c=C; }
		CLine(const CPoint<T>& A, const CPoint<T>& B) { CVector<T> n = (B-A).GetRotated90CCW(); a = n.x; b = n.y; c = -(A.Vector()*n); }
		T Subst(const CPoint<T>& A) const { return a*A.x+b*A.y+c; }
		T Distance2(const CPoint<T>& A) const { T Tmp = Subst(A); return Tmp * Tmp / (a*a+b*b); }
		T Distance(const CPoint<T>& A) const { return pow(Distance2(A), T(0.5)); }
		bool Contains(const CPoint<T>& A, T eps=T(1e-10)) const { return Distance2(A) < eps*eps; }
		CVector<T> GetNorm() const { return CVector<T>(a, b); }
		CVector<T> GetLong() const { return CVector<T>(a, b).GetRotated90CW(); }
		CPoint<T> Projection(const CPoint<T>& A) const { CVector<T> n = GetNorm(); CPoint<T> R = A; R -= n * Subst(A) / n.Length2(); return R; }
		bool Equals(const this_t& A, T eps=T(1e-10)) const { T t1 = pow(a*a+b*b, T(0.5)); T t2 = pow(A.a*A.a+A.b*A.b, T(0.5)); return ::Equals(a/t1, A.a/t2, eps) && ::Equals(b/t1, A.b/t2, eps) && ::Equals(c/t1, A.c/t2, eps); }
		int Crosses(const this_t& A, CPoint<T>& Res = *((CPoint<T>*)0), T eps=T(1e-10)) {
			if(Equals(A, eps)) {
				if(&Res) {
					CPoint<T> O;
					Res = Projection(O);
				}
				return 2;
			}
			if(::Equals(GetLong().GetNormalized().VectMult(A.GetLong().GetNormalized()), T(0), eps*eps)) {
				return 0;
			}
			if(&Res) {
				T t = a*A.b-b*A.a;
				Res.x = (A.c*b - c*A.b)/t;
				Res.y = (c*A.a - A.c*a)/t;
			}
			return 1;
		}
		template<typename ostream_t> void Echo(ostream_t& ostream) const { ostream<<"("<<a<<", "<<b<<", "<<c<<")\n"; }
	};
	template<typename T> struct CSegment {
		typedef CSegment<T> this_t;
		CPoint<T> a,b;
		void l_swap(T& t1, T& t2)  { T t = t1; t1 = t2; t2 = t; }
		CSegment() : a(0, 0), b(0, 0) {}
		CSegment(const CPoint<T>& A, const CPoint<T>& B) : a(A), b(B) {}
		T Length2() const { return a.Distance2(b); }
		T Length() const { return a.Distance(b); }
		CLine<T> Line() const { return CLine<T>(a, b); }
		CPoint<T> Center() const { return CPoint<T>((a.x+b.x)/2, (a.y+b.y)/2); }
		bool Equals(const this_t& A, T eps=T(1e-10)) const { return a.Equals(A.a) && b.Equals(A.b) || a.Equals(A.b) && b.Equals(A.a); }
		bool Contains(const CPoint<T>& A, T eps=T(1e-10)) const { return Line().Contains(A, eps) && ::InRegion(A.x, a.x, b.x, eps) && ::InRegion(A.y, a.y, b.y, eps); }
		int Crosses(const this_t& A, CPoint<T>& Res = *((CPoint<T>*)0), T eps=T(1e-10)) {
			int LineRes = Line().Crosses(A.Line(), Res);
			if(LineRes == 0)
				return 0;
			else if(LineRes == 1)
				return ::InRegion(Res.x, a.x, b.x, eps) && ::InRegion(Res.y, a.y, b.y, eps) && ::InRegion(Res.x, A.a.x, A.b.x, eps) && ::InRegion(Res.y, A.a.y, A.b.y, eps) ? 1 : 0;
			else {
				CSegment<T> TmpSeg;
				int SegRes = Overlapes(A, TmpSeg, eps);
				if(SegRes)
					Res = TmpSeg.Center();
				return SegRes;
			}
		}
		int Crosses(const CLine<T>& A, CPoint<T>& Res = *((CPoint<T>*)0), T eps=T(1e-10)) {
			int LineRes = Line().Crosses(A, Res);
			if(LineRes == 0)
				return 0;
			else if(LineRes == 1)
				return ::InRegion(Res.x, a.x, b.x, eps) && ::InRegion(Res.y, a.y, b.y, eps) ? 1 : 0;
			else {
				Res = Center();
				return 2;
			}
		}
		int Overlapes(const this_t& A, this_t& Res = *((this_t*)0), T eps=T(1e-10)) {
			if(!Line().Equals(A.Line(), eps))
				return 0;
			CVector<T> n = (b-a).GetNormalized();
			T t11 = T(0), t12 = n*(b-a), t21 = n*(A.a-a), t22 = n*(A.b-a);
			if(t21 > t22) l_swap(t21, t22);
			if(t11+t12 > t21+t22) { l_swap(t11, t21); l_swap(t12, t22); }
			if(t22 < t11 - eps || t21 > t12 + eps)
				return 0;
			if(::Equals(t12, t21, eps)) {
				Res.a = a+n*t21;
				Res.b = a+n*t21;
				return 1;
			}
			if(t22 < t12) {
				Res.a = a+n*t21;
				Res.b = a+n*t22;
			}
			else if(t21 < t11) {
				Res.a = a+n*t11;
				Res.b = a+n*t12;
			}
			else {
				Res.a = a+n*t12;
				Res.b = a+n*t21;
			}
			return 2;
		}
		template<typename ostream_t> void Echo(ostream_t& ostream) const { ostream<<"("<<A.x<<", "<<A.y<<") - ("<<B.x<<", "<<B.y<<")\n"; }
	};
	template<typename T> struct CHalfPlane {
		CPoint<T> p;
		CVector<T> n;

		CHalfPlane() { }
		CHalfPlane(const CLine<T>& L, CPoint<T> P) { p = L.Projection(P); n = P-p; }
		CLine<T> GetLine() const { return CLine<T>(p, p+n.GetRotated90CW()); }
		bool Contains(const CPoint<T>& A, T eps=T(1e-10)) const { return (A-p)*n/n.Length() > -eps; }
	};
	template<typename T, int N=10> struct CConvexPolygon {
		int n;
		CPoint<T> p[N];

		CConvexPolygon(const CPoint<T>& p1 = *((CPoint<T>*)0), const CPoint<T>& p2 = *((CPoint<T>*)0), const CPoint<T>& p3 = *((CPoint<T>*)0), const CPoint<T>& p4 = *((CPoint<T>*)0)) {
			n = 0;
			if(&p1) p[n++] = p1;
			if(&p2) p[n++] = p2;
			if(&p3) p[n++] = p3;
			if(&p4) p[n++] = p4;
		}
		void Cut(CHalfPlane<T>& hp, T eps=T(1e-10)) {
			bool b[N];
			int n_in = 0;
			CPoint<T> ps[N];
			for(int i=0; i<n; i++) {
				ps[i] = p[i];
				b[i] = hp.Contains(p[i]);
				if(b[i]) n_in++;
			}
			if(n_in == n) {
				return;
			}
			if(n_in == 0) {
				n = 0;
				return;
			}
			CLine<T> L = hp.GetLine();
			int n_old = n;
			n=0;
			bool f = false;
			for(int i=0; i<2*n_old; i++) {
				int i_cur = i%n_old;
				int i_prev = (i+n_old-1)%n_old;
				if(f) {
					if(b[i_cur]) {
						p[n++] = ps[i_cur];
					}
					else {
						CSegment<T>(ps[i_cur], ps[i_prev]).Crosses(L, p[n++], eps);
						break;
					}
				}
				else {
					if(b[i_cur] && !b[i_prev]) {
						f = true;
						CSegment<T>(ps[i_cur], ps[i_prev]).Crosses(L, p[n++], eps);
						p[n++] = ps[i_cur];
					}
				}
			}
			Verify(eps);
		}
		void Verify(T eps=T(1e-10)) {
			CPoint<T> ps[N];
			for(int i=0; i<n; i++) {
				ps[i] = p[i];
			}
			int n_old = n;
			n=0;
			for(int i=0; i<n_old; i++)
				if(!ps[i].Equals(ps[(i+1)%n_old], eps))
					p[n++] = ps[i];
		}
		T Area() const {
			T R = T(0);
			for(int i=1; i<n-1; i++) {
				CSegment<T> s(p[i], p[i+1]);
				R += T(0.5)*s.Length()*s.Line().Distance(p[0]);
			}
			return R;
		}
		template<typename ostream_t> void Echo(ostream_t& ostream) const {
			ostream<<"("<<n<<" {";
			for(int i=0; i<n; i++)
				ostream<<(i?"; ":"")<<"("<<p[i].x<<", "<<p[i].y<<")";
			ostream<<"})\n";
		}
	};
}}


using namespace std;

using namespace al::geom_2d;






int _tmain(int argc, char* argv[])
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif



	typedef double T;

	int n;
	T h,f;
	cin>>n>>h>>f;
	int l[500], r[500];
	T w = 0;
	for(int i=0; i<n; i++) {
		cin>>l[i]>>r[i];
		if(l[i] > r[i]) {
			int t = l[i];
			l[i] = r[i];
			r[i] = t;
		}
		w += r[i]-l[i];
	}
	T A = 2*h*w*(1+(f+h)/(f-h));
	CHalfPlane<T> hp1(CLine<T>(0, 1, -h), CPoint<T>(0, 0));
	CHalfPlane<T> hp2(CLine<T>(0, 1, h), CPoint<T>(0, 0));
	CPoint<T> F_Plus(0, f);
	CPoint<T> F_Minus(0, -f);
	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			if(l[i] > 0 && r[j] < 0)
				continue;
			if(l[j] > 0 && r[i] < 0)
				continue;
			if(l[i] == 0 || r[i] == 0 || l[j] == 0 || r[j] == 0) {
				int l1,r1,l2,r2;
				if(l[i] == 0) {
					l1 = l[i];
					r1 = r[i];
					l2 = l[j];
					r2 = r[j];
				}
				else if(r[i] == 0) {
					l1 = -r[i];
					r1 = -l[i];
					l2 = -r[j];
					r2 = -l[j];
				}
				else if(l[j] == 0) {
					l1 = l[j];
					r1 = r[j];
					l2 = l[i];
					r2 = r[i];
				}
				else {
					l1 = -r[j];
					r1 = -l[j];
					l2 = -r[i];
					r2 = -l[i];
				}
				if(r2 < 0)
					continue;
				if(l2 < 0) {
					CPoint<T> Cr;
					CSegment<T>(F_Plus, CPoint<T>(r1, h)).Line().Crosses(CSegment<T>(F_Minus, CPoint<T>(r2, -h)).Line(), Cr);
					CConvexPolygon<T> Pol(F_Plus, F_Minus, Cr);
					Pol.Cut(hp1);
					Pol.Cut(hp2);
					A -= (i==j?1:2)*Pol.Area();
					continue;
				}
				else {
					CPoint<T> Cr1,Cr2;
					CSegment<T>(F_Plus, CPoint<T>(r1, h)).Line().Crosses(CSegment<T>(F_Minus, CPoint<T>(l2, -h)).Line(), Cr1);
					CSegment<T>(F_Plus, CPoint<T>(r1, h)).Line().Crosses(CSegment<T>(F_Minus, CPoint<T>(r2, -h)).Line(), Cr2);
					CConvexPolygon<T> Pol(F_Minus, Cr1, Cr2);
					Pol.Cut(hp1);
					Pol.Cut(hp2);
					A -= (i==j?1:2)*Pol.Area();
					continue;
				}
			}
			if(l[i]*r[i] < 0 || l[j]*r[j] < 0) {
				int l1,r1,l2,r2;
				if(l[i]*r[i] < 0) {
					l1 = l[i];
					r1 = r[i];
					l2 = l[j];
					r2 = r[j];
				}
				else {
					l1 = l[j];
					r1 = r[j];
					l2 = l[i];
					r2 = r[i];
				}
				if(l2 > 0) {
					CPoint<T> Cr1,Cr2;
					CSegment<T>(F_Plus, CPoint<T>(r1, h)).Line().Crosses(CSegment<T>(F_Minus, CPoint<T>(l2, -h)).Line(), Cr1);
					CSegment<T>(F_Plus, CPoint<T>(r1, h)).Line().Crosses(CSegment<T>(F_Minus, CPoint<T>(r2, -h)).Line(), Cr2);
					CConvexPolygon<T> Pol(F_Minus, Cr1, Cr2);
					Pol.Cut(hp1);
					Pol.Cut(hp2);
					A -= (i==j?1:2)*Pol.Area();
					continue;
				}
				else if(r2 < 0) {
					CPoint<T> Cr1,Cr2;
					CSegment<T>(F_Plus, CPoint<T>(l1, h)).Line().Crosses(CSegment<T>(F_Minus, CPoint<T>(l2, -h)).Line(), Cr1);
					CSegment<T>(F_Plus, CPoint<T>(l1, h)).Line().Crosses(CSegment<T>(F_Minus, CPoint<T>(r2, -h)).Line(), Cr2);
					CConvexPolygon<T> Pol(F_Minus, Cr1, Cr2);
					Pol.Cut(hp1);
					Pol.Cut(hp2);
					A -= (i==j?1:2)*Pol.Area();
					continue;
				}
				else {
					CPoint<T> Cr1,Cr2;
					CSegment<T>(F_Plus, CPoint<T>(l1, h)).Line().Crosses(CSegment<T>(F_Minus, CPoint<T>(l2, -h)).Line(), Cr1);
					CSegment<T>(F_Plus, CPoint<T>(r1, h)).Line().Crosses(CSegment<T>(F_Minus, CPoint<T>(r2, -h)).Line(), Cr2);
					CConvexPolygon<T> Pol(F_Plus, Cr1, F_Minus, Cr2);
					Pol.Cut(hp1);
					Pol.Cut(hp2);
					A -= (i==j?1:2)*Pol.Area();
					continue;
				}
			}
			int l1,r1,l2,r2;
			l1 = l[i];
			r1 = r[i];
			l2 = l[j];
			r2 = r[j];
			CPoint<T> Cr1,Cr2,Cr3,Cr4;
			CSegment<T>(F_Plus, CPoint<T>(l1, h)).Line().Crosses(CSegment<T>(F_Minus, CPoint<T>(l2, -h)).Line(), Cr1);
			CSegment<T>(F_Plus, CPoint<T>(r1, h)).Line().Crosses(CSegment<T>(F_Minus, CPoint<T>(l2, -h)).Line(), Cr2);
			CSegment<T>(F_Plus, CPoint<T>(l1, h)).Line().Crosses(CSegment<T>(F_Minus, CPoint<T>(r2, -h)).Line(), Cr3);
			CSegment<T>(F_Plus, CPoint<T>(r1, h)).Line().Crosses(CSegment<T>(F_Minus, CPoint<T>(r2, -h)).Line(), Cr4);
			CConvexPolygon<T> Pol(Cr1, Cr2, Cr4, Cr3);
			Pol.Cut(hp1);
			Pol.Cut(hp2);
			A -= (i==j?1:2)*Pol.Area();
			continue;
		}
	}

	printf("%0.10lf\n", A);




	return 0;
}