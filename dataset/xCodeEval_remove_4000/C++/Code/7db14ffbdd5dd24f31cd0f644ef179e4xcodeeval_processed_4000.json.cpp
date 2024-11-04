








using namespace std;

const int MAXN = 1000001;



typedef long long Long;

const double ERROR = 1e-9;
const double id10 = 2 * M_PI;



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



double id11(double grd) {
    return (grd * M_PI) / 180;
}



double id5(double rad) {
    return (rad * 180) / M_PI;
}







Punto Rotar(const Punto& p, double rad) {
    return Punto(p.x*cos(rad) - p.y*sin(rad),
                 p.x*sin(rad) + p.y*cos(rad));
}



Punto id17(const Punto& o, const Punto& p) {
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



int id20(const Punto& o, const Punto& p, const Punto& q) {
    double ccw = Cruz(id17(o, p), id17(o, q));
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



bool id8(const Punto& p, const Linea& r) {
    return !id20(r.p, r.q, p);
}



bool id23(const Punto& p, const Linea& s) {
    return id8(p, s) && !(p < s.p || s.q < p);
}



bool id3(const Linea& l, const Linea& m) {
    return l.a == m.a && l.b == m.b; 

    

    

    

    

    

}



bool id13(const Linea& l, const Linea& m) {
    return id3(l, m) && Igual(l.c, m.c);
}



bool id12(const Linea& l, const Linea& m) {
    return (l.a == m.b && l.b == -m.a) ||
           (m.a == l.b && m.b == -l.a); 

    

    

    

    

    

}



Linea id6(const Linea& l, const Punto& p) {
    return Linea(p, Punto(p.x - l.b, p.y + l.a));
}



Linea id21(const Linea& l, const Punto& p) {
    return Linea(p, Punto(p.x + l.a, p.y + l.b));
}







int id27(const Linea& r, const Linea& s) {
    if (id13(r, s)) return -1;
    return id3(r, s)? 0: 1;
}







int id14(const Linea& r, const Linea& s) {
    if (id3(r, s)) return -1;
    int t1 = id20(r.p, r.q, s.p);
    int t2 = id20(r.p, r.q, s.q);
    return (t1 != t2)? 1: 0;
}







int id1(const Linea& s, const Linea& t) {
    int t1 = id20(s.p, s.q, t.p);
    int t2 = id20(s.p, s.q, t.q);

    if (t1 == t2) return t1? 0:
        (id23(s.p, t) ||
         id23(s.q, t) ||
         id23(t.p, s) ||
         id23(t.q, s))? -1: 0;

    return (id20(t.p, t.q, s.p) !=
            id20(t.p, t.q, s.q))? 1: 0;
}



Punto id9(const Linea& l, const Linea& m) {
    assert(!id3(l, m)); 

    if (Igual(l.a, 0)) Punto((double)(l.c*m.b + m.c) / -m.a, l.c);
    double y = (double)(m.a*l.c - l.a*m.c) / (m.b*l.a - m.a*l.b);
    return Punto((double)(l.c + l.b * y) / -l.a, y);
}



Punto id2(const Punto& v, const Linea& r) {
    Punto a = id17(r.p, v), b = id17(r.p, r.q);
    return id17(Opuesto(r.p), Escalar(b,
        Dot(a, b) / pow(Magnitud(b), 2)));
}



double id24(const Punto& p, const Linea& r) {
    return Distancia(id2(p, r), p);
}



double id26(const Punto& p, const Linea& s) {
    Punto proy = id2(p, s);
    if (proy < s.p) return Distancia(s.p, p);
    if (s.q < proy) return Distancia(s.q, p);
    return Distancia(proy, p);
}



double id7(const Linea& l, const Linea& m) {
    return id3(l, m)? id24(l.p, m): 0;
}



double id25(const Linea& s, const Linea& r) {
    if (id1(s, r)) return 0;
    return min(min(id26(s.p, r),
                   id26(s.q, r)),
               min(id26(r.p, s),
                   id26(r.q, s)));
}







typedef vector<Punto> Poligono;



bool id16(const Punto& p, const Poligono& P) {
    for (int i = 1; i < P.size(); ++i) {
        Punto l = min(P[i - 1], P[i]);
        Punto r = max(P[i - 1], P[i]);
        if (id20(l, r, p) == 0 &&
            !(p < l || r < p)) return true;
    }
    return false;
}





int id22(const Punto& p, const Poligono& P) {
    if (id16(p, P)) return -1;
    int dir = id20(P[0], P[1], p);
    for (int i = 2; i < P.size(); ++i)
        if (id20(P[i - 1], P[i], p)
            != dir) return 0; 

    return 1; 

}





int RayCasting(const Punto& p, const Poligono& P) {
    if (id16(p, P)) return -1;
    Punto o = *min_element(P.begin(), P.end());
    Linea rayo(p, Punto(o.x - M_PI, o.y - M_E));

    int cruces = 0;
    for (int i = 1; i < P.size(); ++i)
        if (id1(rayo,
            Linea(P[i - 1], P[i]))) ++cruces;
    return cruces & 1;
}





int id15(const Punto& p, const Poligono& P) {
    if (id16(p, P)) return -1;
    double angulo = 0;
    for (int i = 1; i < P.size(); ++i)
        angulo += id20(p, P[i - 1], P[i]) * Angulo(
            id17(p, P[i - 1]), id17(p, P[i]));
    return (fabs(angulo) > M_PI)? 1: 0;
}



double Area(const Poligono& P) {
    double area = 0;
    for (int i = 1; i < P.size(); ++i)
        area += Cruz(P[i - 1], P[i]);
    return fabs(area) / 2.0;
}



double id28(const Poligono& P) {
    double id19 = 0;
    for (int i = 1; i < P.size(); ++i)
        id19 += Distancia(P[i - 1], P[i]);
    return id19;
}



Poligono id0(vector<Punto> P){
    

    sort(P.begin(), P.end());
    Poligono arriba, abajo;
    for (int i = 0; i < P.size(); ++i) {
        while (arriba.size() > 1) {
            int p = arriba.size() - 1;
            

            if (id20(arriba[p - 1],
                arriba[p], P[i]) < 0) break;
            arriba.pop_back();
        }
        arriba.push_back(P[i]);
    }
    arriba.pop_back();
    for (int i = P.size() - 1; i >= 0; --i) {
        while (abajo.size() > 1) {
            int p = abajo.size() - 1;
            

            if (id20(abajo[p - 1],
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



bool id18(
    const Linea& r, const Poligono& P) {
    for (int i = 0, prim = 0; i < P.size(); ++i) {
        int lado = id20(r.p, r.q, P[i]);
        if (!lado) continue; if (!prim) prim = lado;
        else if (lado != prim) return true;
    }
    return false;
}





vector<Poligono> id4(
    const Poligono& P, const Linea& r) {
    if (!id18(r, P))
        return vector<Poligono>(1, P);
    int ind = 0;
    vector<Poligono> Ps(2);
    for (int i = 1; i < P.size(); ++i) {
        Linea s(P[i - 1], P[i]);
        if (id14(r, s)) {
            Punto p = id9(r, s);
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
	P = id0(P);
	double ans = 1e50;
	forn(i, n)
		ans = min(ans, Distancia(P[i], P[i + 1]) / 2.0);

	vector<Linea> s;
	forn(i, n)
		s.pb( Linea( P[i], P[(i + 2) % P.size()] ) );

	forn(i, n)
		forn(j, s.size())
			if(!(s[j].p == P[i]) && !(s[j].q == P[i]))
				ans = min(ans, id26(P[i], s[j]) / 2.0);

	cout<<ans - ERROR<<endl;
	return 0;
}
