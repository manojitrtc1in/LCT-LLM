



using namespace std;





typedef long double ld;
typedef long long ll;

const ld pi = acos(-1);
const ld eps = 1e-9;
const ld INF = 1e6;




ld Sqr(ld a) {
    return a * a;
}

ld id6(ld a) {
    return a * a * a;
}

bool Equal(ld a, ld b) {
	return fabs(a - b) < eps;
}

bool id2 (ld a, ld b) {
    return a < b || Equal(a, b);
}

bool id1 (ld a, ld b) {
    return a > b || Equal(a, b);
}

bool Less (ld a, ld b) {
    return (!Equal(a, b) && a < b);
}

bool More (ld a, ld b) {
    return (!Equal(a, b) && a > b);
}

ld Acos(ld a) {
    if(More(fabs(a), 1)) {
        throw "cos(a) -> a > 1";
    }
    if(Equal(a, 1)) {
        return acos(1);
    }
    if(Equal(a, -1)) {
        return acos(-1);
    }
    return acos(a);
}

ld Asin(ld a) {
    if(More(fabs(a), 1)) {
        throw "sin(a) -> a > 1";
    }
    if(Equal(a, 1)) {
        return asin(1);
    }
    if(Equal(a, -1)) {
        return asin(-1);
    }
    return asin(a);
}

ld id5(ld a) {

	if(Less(a, 0) ) {
        throw "sqrt(a) -> a < 0";
	}
	if (Equal(a, 0)) {
	    return 0;
	}
	return sqrt(a);
}

struct Line;

struct Vector { 

    ld x, y;

    Vector (ld a = 0, ld b = 0) {
        x = a;
        y = b;
    }

    void Scan() {
        cin >> x >> y;
    }

    void Print() const {
        cout << x << " " << y << " ";
    }

    Vector operator-() const {
		return Vector(-x, -y);
	}

    Vector operator+(const Vector &p) const {
		return Vector(x + p.x, y + p.y);
	}

    Vector operator-(const Vector &p) const {
		return Vector(x - p.x, y - p.y);
	}

    ld operator*(const Vector &p) const { 

		return (x * p.y - y * p.x);
	}

	ld operator%(const Vector &p) const { 

		return (x * p.x + y * p.y);
	}

	ld angle() const {                    

        return atan2(y, x);
	}

	ld Length() const {                   

        return id5(*this % *this);
	}

	Vector operator*(ld p) const {
        return Vector (x * p, y * p);
	}

	Vector operator/(ld p) const {
        return Vector (x / p, y / p);
	}

	bool IsZero() const {                 

		return Equal(x, ld(0)) && Equal(y, ld(0));
	}

	bool EqualVector (const Vector &p) const {     

        return Equal(x, p.x) && Equal(y, p.y);
	}

	ld Dist(const Vector &p) const {      

        return (*this - p).Length();
	}

	Vector Normalize (ld k = 1) const {   

		ld len = Length();
		if(Equal(len, 0)) {
            return *this;
		}
		return *this * (k / len);
	}

	Vector Height(const Vector &A, const Vector &B) const {  

        Vector C = *this;
        Vector V = B - A;
        Vector U = C - A;
        ld k = V % U / V.Length();
        if(Equal(V.Length(), 0)) {
            return A;
        }
        V = V.Normalize(k);
        Vector H = A + V;
        return H;
	}

    Vector Height(const Line &A) const;                      


	ld DistToLine(const Vector &A, const Vector &B) const {  

        ld d = A.Dist(B);
        ld s = (*this - A) * (*this - B);
        return fabs(s) / d;
	}

	ld DistToLine(const Line &A) const;

    bool IsOnLine(const Vector &A, const Vector &B) const { 

		return Equal((A - *this) * (B - *this), 0);
	}

	bool IsOnSegment (const Vector &A, const Vector &B) const { 

        if(IsOnLine(A, B) && id2((A - *this) % (B - *this), 0)) {
            return true;
        }
        return false;
	}

	Vector Rotate90 () const { 

        return Vector (-y, x);
	}

	Vector Rotate(ld cosa, ld sina) const {
		Vector V = *this;
		Vector U = V.Rotate90();
		Vector W = V * cosa + U * sina;
		return W;
	}

	Vector Rotate(ld alpha) const { 

		return Rotate(cos(alpha), sin(alpha) );
	}

	ld DistToSegment (const Vector &A, const Vector &B) const { 

        Vector C = (*this);
        if(IsOnSegment(A, B)) {
            return 0;
        }
        if(C.Height(A, B).IsOnSegment(A, B)) {
            return DistToLine(A, B);
        }
        return min(C.Dist(A), C.Dist(B));
    }
};

struct Circle { 

    Vector O;
    ld R;

    Circle() {
        O = Vector();
        R = ld(0);
    }

    Circle(Vector V, ld a = ld(0)) {
        O = V;
        R = a;
    }

    void Scan() {
        O.Scan();
        cin >> R;
    }

    bool EqualCircle (const Circle & W) const { 

        return O.EqualVector(W.O) && Equal(W.R, R);
    }
};

pair <Vector, Vector> GetLine(ld A, ld B, ld C) {
    if(A == 0) {
        return {Vector(0, -C / B), Vector(1, -C / B)};
    }
    if(B == 0) {
        return {Vector(-C / A, 0), Vector(-C / A, 1)};
    }
    return {Vector(0, -C / B), Vector(1, -(A + C) / B)};
}

struct Segment {  

    Vector A, B;
    Segment() {
        A = Vector();
        B = Vector();
    }

    Segment (Vector C, Vector D) {
        A = C;
        B = D;
    }

    void Scan() {
        A.Scan();
        B.Scan();
    }

    void Print() {
        A.Print();
        B.Print();
    }
};

struct Line {    

    Vector A, B;

    Line() {
        A = Vector();
        B = Vector();
    }

    Line(Vector A, Vector B) {
       A = A;
       B = B;
    }

    Line(ld a, ld b, ld c) {
        A = GetLine(a, b, c).first;
        B = GetLine(a, b, c).second;
    }

    Line (Segment C) {
        A = C.A;
        B = C.B;
    }

    void Scan() { 

        A.Scan();
        B.Scan();
    }

    void scan() { 

        ld a, b, c;
        cin >> a >> b >> c;
        A = GetLine(a, b, c).first;
        B = GetLine(a, b, c).second;
    }

    void Print() {
        A.Print();
        B.Print();
    }
};

pair <int, Vector> LinesCross(const Vector &A, const Vector &B, const Vector &C, const Vector &D) { 

    ld s1 = (C - A) * (D - A); 

    ld s2 = (D - B) * (C - B); 

    ld s = s1 + s2;         

    Vector V = B - A;
    V = V / s;
	V = V * s1;
	Vector O = A + V;
    if(Equal(s, 0)) {  

        if(!A.IsOnLine(C, D)) {  

            return {0, Vector()}; 

        }
        return {2, Vector()};  

    }
    return {1, O};         

}

pair <int, Vector> LinesCross(const Line &L1, const Line &L2) { 

    return LinesCross(L1.A, L1.B, L2.A, L2.B);
}

pair <int, Vector> SegmentsCross(const Vector &A, const Vector &B, const Vector &C, const Vector &D) { 

    if(LinesCross(A, B, C, D).first == 1) {
        Vector O = LinesCross(A, B, C, D).second;
        if(O.IsOnSegment(A, B) && O.IsOnSegment(C, D)){
            return {1, O}; 

        }
    }
    if(LinesCross(A, B, C, D).first == 2) {
        if(A.IsOnSegment(C, D) || B.IsOnSegment(C, D) || C.IsOnSegment(A, B) || D.IsOnSegment(A, B)) {
            return {2, Vector()}; 

        }
    }
    return {0, Vector()};  

}

pair <int, Vector> SegmentsCross(const Segment &A, const Segment &B) {   

    return SegmentsCross(A.A, A.B, B.A, B.B);
}

pair <int, Vector> id7 (const Vector &A, const Vector &B, const Vector &C, const Vector &D) { 

    if(LinesCross(A, B, C, D).first == 0) {
        return {0, Vector()}; 

    }
    if(LinesCross(A, B, C, D).first == 1) {
        Vector O = LinesCross(A, B, C, D).second;
        if(O.IsOnSegment(C, D)) {
            return {1, O}; 

        }
    }
    if(LinesCross(A, B, C, D).first == 2) {
        return {2, Vector()}; 

    }
}

pair <int, Vector> id7 (const Line &A, const Segment &B) { 

    return id7(A.A, A.B, B.A, B.B);
}

Vector id4 (Vector &A, Vector &B, Vector &C) { 

    Vector H1 = A.Height(B, C);
    Vector H2 = B.Height(A, C);
    return LinesCross(H1, A, H2, B).second;
}

Vector Bisector (Vector &A, Vector &B, Vector &C) { 

    ld len1 = B.Dist(A);
    ld len2 = B.Dist(C);
    Vector V = C - A;
    ld len = A.Dist(C);
    ld k = len1 / (len1 + len2) * len;
    V = V.Normalize(k);
    return A + V;
}

Vector id8 (Vector &A, Vector &B, Vector &C) { 

    return LinesCross(Bisector(A, B, C), B, Bisector(B, A, C), A).second;
}

ld radius (Vector &A, Vector &B, Vector &C) { 

    return id8(A, B, C).Dist(id8(A, B, C).Height(A, B));
}

Vector Vector::Height(const Line &A) const { 

        return this->Height(A.A, A.B);
}

ld Vector::DistToLine(const Line &A) const { 

    return this->DistToLine(A.A, A.B);
}

pair <int, vector <Vector> > id3(const Line &A, const Circle &W) { 

    ld h = W.O.DistToLine(A.A, A.B);
    if (W.R < h) {
        return {0, {}}; 

    }
    Vector H = W.O.Height(A.A, A.B);
    Vector V = A.B - A.A;
    ld k = id5(Sqr(W.R) - Sqr(h));
    V = V.Normalize(k);
    if (V.IsZero()) {
        return {1, {H + V}}; 

    } else {
        return {2, {H + V, H - V}}; 

    }
}

pair <int, vector <Vector> > id0(const Circle &W1, const Circle &W2) { 

    ld d = W1.O.Dist(W2.O);
    if (Less(W1.R + W2.R, d) || Less(d, fabs(W1.R - W2.R))) {
        return {0, {}}; 

    }
    if (W1.EqualCircle(W2)) {
        return {3, {}}; 

    }
    ld a = (Sqr(W1.R) - Sqr(W2.R) + Sqr(d)) / ld(2) / d;
    ld h = id5(Sqr(W1.R) - Sqr(a));
    Vector V = W2.O - W1.O;
    Vector U = V.Rotate90();
    V = V.Normalize(a);
    U = U.Normalize(h);
    Vector H = W1.O + V;
    if (U.IsZero()) {
        return {1, {H + U}}; 

    } else {
        return {2, {H + U, H - U}}; 

    }
}

pair <int, vector <Vector> > Tangent(const Vector &A, const Circle &W)  { 

    Vector V = W.O - A;
    ld d = V.Length();
    if (d < W.R) {
        return {0, {}}; 

    }
    ld al = Asin(W.R / d);
    ld l = id5(Sqr(d) - Sqr(W.R));
    V = V.Normalize(l);
    Vector N = A + V.Rotate(al);
    Vector M = A + V.Rotate(-al);
    if (Equal(W.R, d)) {
        return {1, {N}}; 

    } else {
        return {2, {N, M}}; 

    }
}

int Location(const Vector &A, Line &a) {
    if(Equal((a.B - a.A) * (A - a.A), 0)) { 

        return 0;
    }
    if(More((a.B - a.A) * (A - a.A), 0)) { 

        return 1;
    }
    if(Less((a.B - a.A) * (A - a.A), 0)) { 

        return 2;
    }
}

int Location(const Vector &A, Segment &a) {
    if(Equal((a.B - a.A) * (A - a.A), 0)) { 

        return 0;
    }
    if(More((a.B - a.A) * (A - a.A), 0)) { 

        return 1;
    }
    if(Less((a.B - a.A) * (A - a.A), 0)) { 

        return 2;
    }
}

int Location(const Vector &A, const Vector &B, const Vector &C) {
    if(Equal((C - B) * (A - B), 0)) { 

        return 0;
    }
    if(More((C - B) * (A - B), 0)) { 

        return 1;
    }
    if(Less((C - B) * (A - B), 0)) { 

        return 2;
    }
}


int main() {

    



    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(8);
    int n, a, b;
    cin >> n >> a >> b;
    if(a == 1 || b == 1) {
        for(int i = 0; i < n; i++) {
            cout << i + 1 << pp;
        }
        return 0;
    }
    int q, w;
    for(int i = 0; i <= n; i++) {
        if(n < i * a) {
            cout << -1;
            return 0;
         } 
         if ((n - i * a) % b == 0) {
            q = i;
            w = (n - i * a) / b;
            break;
         }
    }
    for(int i = 1; i <= q * a; i++) {
        if(i % a == 0) {
            cout << i - a + 1 << " ";
            continue;
        }
        cout << i + 1<< pp;
    }
    int e = q * a;
    for(int i = 1; i <= w * b; i++) {
        if(i % b == 0) {
            cout << e + i - b + 1 << " ";
            continue;
        }
        cout << e + i + 1 << pp;
    }
}









