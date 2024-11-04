#include <bits/stdc++.h>
#define endl '\n'
#define forn(i, n) for(int i=0;i<n;i++)
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>

using namespace std;

const int MAXN = 1000001;



typedef long long Long;

const double ERROR = 1e-9;
const double M_2PI = 2 * M_PI;



bool Igual(double a, double b) { 
    return fabs(a - b) < ERROR;
}



struct Punto {
    double x, y;

    Punto() : x(), y() {}
    Punto(double X, double Y) : x(X), y(Y) {}

    

    bool operator<(const Punto& cmp) const {
        if (!Igual(x, cmp.x)) return x < cmp.x;
        return Igual(y, cmp.y)? false: y < cmp.y;
    }
 
    bool operator==(const Punto& cmp) const {
        return Igual(x, cmp.x) && Igual(y, cmp.y);
    } 
};



double Distancia(const Punto& p, const Punto& q) {
    return hypot(p.x - q.x, p.y - q.y);
}



double Magnitud(const Punto& v) {
    return hypot(v.x, v.y);
}



double Dot(const Punto& v, const Punto& w) {
    return v.x * w.x + v.y * w.y;
}



double Cruz(const Punto& v, const Punto& w) {
    return v.x * w.y - v.y * w.x;
}



double GradARad(double grd) {
    return (grd * M_PI) / 180;
}



double RadAGrad(double rad) {
    return (rad * 180) / M_PI;
}







Punto Rotar(const Punto& p, double rad) {
    return Punto(p.x*cos(rad) - p.y*sin(rad),
                 p.x*sin(rad) + p.y*cos(rad));
}



Punto Trasladar(const Punto& o, const Punto& p) {
    return Punto(p.x - o.x, p.y - o.y);
}



Punto Escalar(const Punto& v, double s) {
    return Punto(v.x * s, v.y * s);
}



Punto Opuesto(const Punto& v) {
    return Punto(-v.x, -v.y);
}



double Angulo(const Punto& v, const Punto& w) {
    return acos(Dot(v, w) / (Magnitud(v) * Magnitud(w)));
}



int ManoDerecha(const Punto& o, const Punto& p, const Punto& q) {
    double ccw = Cruz(Trasladar(o, p), Trasladar(o, q));
    return Igual(ccw, 0)? 0: (ccw < 0)? -1: 1;
}










struct Linea {
    Punto p, q;
    Long a, b, c; 

    


    Linea() : p(), q(), a(), b(), c() {}

    Linea(Long A, Long B, Long C)
        : p(), q(), a(A), b(B), c(C) {
        if (Igual(a, 0)) {
            c /= -b; b = -1;
            p = Punto(0, c);
            q = Punto(1, c);
        } else if (Igual(b, 0)) {
            c /= -a; a = -1;
            p = Punto(c, 0);
            q = Punto(c, 1);
        } else {
            p = Punto(-c/a, 0);
            q = Punto(-(b+c)/a, 1);
        } if (q < p) swap(p, q);
    }

    Linea(const Punto& P, const Punto& Q)
        : p(P), q(Q), a(), b(), c() {
        

        if (q < p) swap(p, q);
        a = q.y - p.y;
        b = p.x - q.x;
        if (!a) c = p.y, b = -1;
        else if (!b) c = p.x, a = -1;
        else {
            

            c = abs(__gcd(a, b));
            a /= c, b /= c;
            

            c = -a*p.x - b*p.y;
        }
    }

    

    bool operator<(const Linea& cmp) const {
        if (!Igual(a, cmp.a)) return a < cmp.a;
        if (!Igual(b, cmp.b)) return b < cmp.b;
        return Igual(c, cmp.c)? false: c < cmp.c;
    }
};



bool PuntoEnRecta(const Punto& p, const Linea& r) {
    return !ManoDerecha(r.p, r.q, p);
}



bool PuntoEnSegmento(const Punto& p, const Linea& s) {
    return PuntoEnRecta(p, s) && !(p < s.p || s.q < p);
}



bool LineasParalelas(const Linea& l, const Linea& m) {
    return l.a == m.a && l.b == m.b; 

    

    

    

    

    

}



bool LineasIguales(const Linea& l, const Linea& m) {
    return LineasParalelas(l, m) && Igual(l.c, m.c);
}



bool LineasPerpendiculares(const Linea& l, const Linea& m) {
    return (l.a == m.b && l.b == -m.a) ||
           (m.a == l.b && m.b == -l.a); 

    

    

    

    

    

}



Linea ParalelaEnPunto(const Linea& l, const Punto& p) {
    return Linea(p, Punto(p.x - l.b, p.y + l.a));
}



Linea PerpendicularEnPunto(const Linea& l, const Punto& p) {
    return Linea(p, Punto(p.x + l.a, p.y + l.b));
}







int InterseccionRectas(const Linea& r, const Linea& s) {
    if (LineasIguales(r, s)) return -1;
    return LineasParalelas(r, s)? 0: 1;
}







int IntersecRectaSegmen(const Linea& r, const Linea& s) {
    if (LineasParalelas(r, s)) return -1;
    int t1 = ManoDerecha(r.p, r.q, s.p);
    int t2 = ManoDerecha(r.p, r.q, s.q);
    return (t1 != t2)? 1: 0;
}







int InterseccionSegmentos(const Linea& s, const Linea& t) {
    int t1 = ManoDerecha(s.p, s.q, t.p);
    int t2 = ManoDerecha(s.p, s.q, t.q);

    if (t1 == t2) return t1? 0:
        (PuntoEnSegmento(s.p, t) ||
         PuntoEnSegmento(s.q, t) ||
         PuntoEnSegmento(t.p, s) ||
         PuntoEnSegmento(t.q, s))? -1: 0;

    return (ManoDerecha(t.p, t.q, s.p) !=
            ManoDerecha(t.p, t.q, s.q))? 1: 0;
}



Punto PuntoInterseccion(const Linea& l, const Linea& m) {
    assert(!LineasParalelas(l, m)); 

    if (Igual(l.a, 0)) Punto((double)(l.c*m.b + m.c) / -m.a, l.c);
    double y = (double)(m.a*l.c - l.a*m.c) / (m.b*l.a - m.a*l.b);
    return Punto((double)(l.c + l.b * y) / -l.a, y);
}



Punto ProyeccionEnRecta(const Punto& v, const Linea& r) {
    Punto a = Trasladar(r.p, v), b = Trasladar(r.p, r.q);
    return Trasladar(Opuesto(r.p), Escalar(b,
        Dot(a, b) / pow(Magnitud(b), 2)));
}



double DistanciaPuntoRecta(const Punto& p, const Linea& r) {
    return Distancia(ProyeccionEnRecta(p, r), p);
}



double DistanciaPuntoSegmento(const Punto& p, const Linea& s) {
    Punto proy = ProyeccionEnRecta(p, s);
    if (proy < s.p) return Distancia(s.p, p);
    if (s.q < proy) return Distancia(s.q, p);
    return Distancia(proy, p);
}



double DistanciaRectaRecta(const Linea& l, const Linea& m) {
    return LineasParalelas(l, m)? DistanciaPuntoRecta(l.p, m): 0;
}



double DistanciaSegmenSegmen(const Linea& s, const Linea& r) {
    if (InterseccionSegmentos(s, r)) return 0;
    return min(min(DistanciaPuntoSegmento(s.p, r),
                   DistanciaPuntoSegmento(s.q, r)),
               min(DistanciaPuntoSegmento(r.p, s),
                   DistanciaPuntoSegmento(r.q, s)));
}







typedef vector<Punto> Poligono;



bool PuntoEnPerimetro(const Punto& p, const Poligono& P) {
    for (int i = 1; i < P.size(); ++i) {
        Punto l = min(P[i - 1], P[i]);
        Punto r = max(P[i - 1], P[i]);
        if (ManoDerecha(l, r, p) == 0 &&
            !(p < l || r < p)) return true;
    }
    return false;
}





int PuntoEnConvexo(const Punto& p, const Poligono& P) {
    if (PuntoEnPerimetro(p, P)) return -1;
    int dir = ManoDerecha(P[0], P[1], p);
    for (int i = 2; i < P.size(); ++i)
        if (ManoDerecha(P[i - 1], P[i], p)
            != dir) return 0; 

    return 1; 

}





int RayCasting(const Punto& p, const Poligono& P) {
    if (PuntoEnPerimetro(p, P)) return -1;
    Punto o = *min_element(P.begin(), P.end());
    Linea rayo(p, Punto(o.x - M_PI, o.y - M_E));

    int cruces = 0;
    for (int i = 1; i < P.size(); ++i)
        if (InterseccionSegmentos(rayo,
            Linea(P[i - 1], P[i]))) ++cruces;
    return cruces & 1;
}





int AngleSummation(const Punto& p, const Poligono& P) {
    if (PuntoEnPerimetro(p, P)) return -1;
    double angulo = 0;
    for (int i = 1; i < P.size(); ++i)
        angulo += ManoDerecha(p, P[i - 1], P[i]) * Angulo(
            Trasladar(p, P[i - 1]), Trasladar(p, P[i]));
    return (fabs(angulo) > M_PI)? 1: 0;
}



double Area(const Poligono& P) {
    double area = 0;
    for (int i = 1; i < P.size(); ++i)
        area += Cruz(P[i - 1], P[i]);
    return fabs(area) / 2.0;
}



double Perimetro(const Poligono& P) {
    double perimetro = 0;
    for (int i = 1; i < P.size(); ++i)
        perimetro += Distancia(P[i - 1], P[i]);
    return perimetro;
}



Poligono CercoConvexo(vector<Punto> P){
    

    sort(P.begin(), P.end());
    Poligono arriba, abajo;
    for (int i = 0; i < P.size(); ++i) {
        while (arriba.size() > 1) {
            int p = arriba.size() - 1;
            

            if (ManoDerecha(arriba[p - 1],
                arriba[p], P[i]) < 0) break;
            arriba.pop_back();
        }
        arriba.push_back(P[i]);
    }
    arriba.pop_back();
    for (int i = P.size() - 1; i >= 0; --i) {
        while (abajo.size() > 1) {
            int p = abajo.size() - 1;
            

            if (ManoDerecha(abajo[p - 1],
                abajo[p], P[i]) < 0) break;
            abajo.pop_back();
        }
        abajo.push_back(P[i]);
    }
    arriba.insert(arriba.end(),
        abajo.begin(), abajo.end());
    return arriba; 

}



Punto Centroide(const Poligono& P) {
    double x = 0, y = 0, k = 0;
    for (int i = 1; i < P.size(); ++i) {
        double cruz = Cruz(P[i - 1], P[i]);
        x += cruz * (P[i - 1].x + P[i].x);
        y += cruz * (P[i - 1].y + P[i].y);
        k += cruz * 3;
    }
    return Punto(x/k, y/k);
}



bool RectaCortaPoligono(
    const Linea& r, const Poligono& P) {
    for (int i = 0, prim = 0; i < P.size(); ++i) {
        int lado = ManoDerecha(r.p, r.q, P[i]);
        if (!lado) continue; if (!prim) prim = lado;
        else if (lado != prim) return true;
    }
    return false;
}





vector<Poligono> CortarPoligono(
    const Poligono& P, const Linea& r) {
    if (!RectaCortaPoligono(r, P))
        return vector<Poligono>(1, P);
    int ind = 0;
    vector<Poligono> Ps(2);
    for (int i = 1; i < P.size(); ++i) {
        Linea s(P[i - 1], P[i]);
        if (IntersecRectaSegmen(r, s)) {
            Punto p = PuntoInterseccion(r, s);
            if (P[i - 1] == p) continue;
            Ps[ind].push_back(P[i - 1]);
            Ps[1 - ind].push_back(p);
            Ps[ind].push_back(p);
            ind = 1 - ind;
        }
        else Ps[ind].push_back(P[i - 1]);
    }
    Ps[0].push_back(Ps[0][0]);
    Ps[1].push_back(Ps[1][0]);
    return Ps;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(9);
	int n,x,y;
	cin>>n;
	Poligono P;
	forn(i, n) {
		cin>>x>>y;
		P.pb(Punto(x, y));
	}
	P = CercoConvexo(P);
	double ans = 1e50;
	forn(i, n)
		ans = min(ans, Distancia(P[i], P[i + 1]) / 2.0);

	vector<Linea> s;
	forn(i, n)
		s.pb( Linea( P[i], P[(i + 2) % P.size()] ) );

	forn(i, n)
		forn(j, s.size())
			if(!(s[j].p == P[i]) && !(s[j].q == P[i]))
				ans = min(ans, DistanciaPuntoSegmento(P[i], s[j]) / 2.0);

	cout<<ans - ERROR<<endl;
	return 0;
}
