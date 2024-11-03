
#include <iostream>
#include <stdio.h>


#include <math.h>
#include <stdlib.h>

const double INF = 1E200;
const double EP = 1E-10;
const int MAXV = 300;
const double PI = acos(-1.0);

using namespace std;


struct POINT {
    double x;
    double y;
    POINT(double a = 0, double b = 0) {
        x = a;    

        y = b;
    }
};
struct LINESEG { 

    POINT s;
    POINT e;
    LINESEG(POINT a, POINT b) {
        s = a;
        e = b;
    }
    LINESEG() { }
};
struct LINE { 

    double a;
    double b;
    double c;
    LINE(double d1 = 1, double d2 = -1, double d3 = 0) {
        a = d1;
        b = d2;
        c = d3;
    }
};





double dist(POINT p1, POINT p2) {
    return( sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)) );
}


bool equal_point(POINT p1, POINT p2) {
    return ( (abs(p1.x - p2.x) < EP)&&(abs(p1.y - p2.y) < EP) );
}

double multiply(POINT sp, POINT ep, POINT op) {
    return( (sp.x - op.x) * (ep.y - op.y) - (ep.x - op.x) * (sp.y - op.y) );
}

double dotmultiply(POINT p1, POINT p2, POINT p0) {
    return ( (p1.x - p0.x) * (p2.x - p0.x) + (p1.y - p0.y) * (p2.y - p0.y) );
}

bool online(LINESEG l, POINT p) {
    return( (multiply(l.e, p,l.s) == 0) && ( ( (p.x - l.s.x) * (p.x - l.e.x) <= 0 )&&( (p.y - l.s.y) * (p.y - l.e.y) <= 0 ) ) );
}


POINT rotate(POINT o, double alpha, POINT p) {
    POINT tp;
    p.x -= o.x;
    p.y -= o.y;
    tp.x = p.x * cos(alpha) - p.y * sin(alpha) + o.x;
    tp.y = p.y * cos(alpha) + p.x * sin(alpha) + o.y;
    return tp;
}

double angle(POINT o, POINT s, POINT e) {
    double cosfi, fi, norm;
    double dsx = s.x - o.x;
    double dsy = s.y - o.y;
    double dex = e.x - o.x;
    double dey = e.y - o.y;

    cosfi = dsx * dex + dsy * dey;
    norm = (dsx * dsx + dsy * dsy) * (dex * dex + dey * dey);
    cosfi /= sqrt(norm);

    if (cosfi >=  1.0 ) return 0;
    if (cosfi <= -1.0 ) return -PI;

    fi = acos(cosfi);
    if (dsx * dey - dsy * dex > 0) return fi;      

    return -fi;

}



double relation(POINT p, LINESEG l) {
    LINESEG tl;
    tl.s = l.s;
    tl.e = p;
    return dotmultiply(tl.e, l.e, l.s) / (dist(l.s, l.e) * dist(l.s, l.e));
}


POINT perpendicular(POINT p, LINESEG l) {
    double r = relation(p, l);
    POINT tp;
    tp.x = l.s.x + r * (l.e.x - l.s.x);
    tp.y = l.s.y + r * (l.e.y - l.s.y);
    return tp;
}

double ptolinesegdist(POINT p, LINESEG l, POINT &np) {
    double r = relation(p, l);
    if(r < 0) {
        np = l.s;
        return dist(p, l.s);
    }
    if(r > 1) {
        np = l.e;
        return dist(p, l.e);
    }
    np = perpendicular(p, l);
    return dist(p, np);
}


double ptoldist(POINT p, LINESEG l) {
    return abs(multiply(p, l.e, l.s)) / dist(l.s, l.e);
}

double ptopointset(int vcount, POINT pointset[], POINT p, POINT &q) {
    double cd = double(INF), td;
    LINESEG l;
    POINT tq, cq;

    for(int i = 0; i < vcount - 1; i++) {
        l.s = pointset[i];
        l.e = pointset[i + 1];
        td = ptolinesegdist(p, l, tq);
        if(td < cd) {
            cd = td;
            cq = tq;
        }
    }
    q = cq;
    return cd;
}

bool CircleInsidePolygon(int vcount, POINT center, double radius, POINT polygon[]) {
    POINT q;
    double d;
    q.x = 0;
    q.y = 0;
    d = ptopointset(vcount, polygon, center, q);
    if(d < radius || fabs(d - radius) < EP)
        return true;
    return false;
}

double cosine(LINESEG l1, LINESEG l2) {
    return ( ( (l1.e.x - l1.s.x) * (l2.e.x-l2.s.x) + (l1.e.y-l1.s.y) * (l2.e.y-l2.s.y) ) / (dist(l1.e, l1.s) * dist(l2.e, l2.s) ) );
}


double lsangle(LINESEG l1, LINESEG l2) {
    POINT o, s, e;
    o.x = o.y = 0;
    s.x = l1.e.x - l1.s.x;
    s.y = l1.e.y - l1.s.y;
    e.x = l2.e.x - l2.s.x;
    e.y = l2.e.y - l2.s.y;
    return angle(o, s, e);
}







bool intersect(LINESEG u, LINESEG v) {
    return( ( max(u.s.x, u.e.x) >= min(v.s.x, v.e.x) ) &&                     

            ( max(v.s.x, v.e.x) >= min(u.s.x, u.e.x) ) &&
            ( max(u.s.y, u.e.y) >= min(v.s.y, v.e.y) ) &&
            ( max(v.s.y, v.e.y) >= min(u.s.y, u.e.y) ) &&
            ( multiply(v.s, u.e, u.s) * multiply(u.e, v.e, u.s) >= 0 ) &&         

            ( multiply(u.s, v.e, v.s) * multiply(v.e, u.e, v.s) >=0 ) );
}


bool intersect_A(LINESEG u, LINESEG v) {
    return ( ( intersect(u, v) ) &&
             ( !online(u, v.s) ) &&
             ( !online(u, v.e) ) &&
             ( !online(v, u.e) ) &&
             ( !online(v, u.s) ) );
}


bool intersect_l(LINESEG u, LINESEG v) {
    return multiply(u.s, v.e, v.s) * multiply(v.e, u.e, v.s) >= 0;
}


LINE makeline(POINT p1, POINT p2) {
    LINE tl;
    int sign = 1;
    tl.a = p2.y - p1.y;
    if(tl.a < 0) {
        sign = -1;
        tl.a = sign * tl.a;
    }
    tl.b = sign * (p1.x - p2.x);
    tl.c = sign * (p1.y * p2.x - p1.x * p2.y);
    return tl;
}


double slope(LINE l) {
    if(abs(l.a) < 1e-20)
        return 0;
    if(abs(l.b) < 1e-20)
        return INF;
    return -(l.a / l.b);
}


double alpha(LINE l) {
    if(abs(l.a) < EP)
        return 0;
    if(abs(l.b ) < EP)
        return PI / 2;
    double k=slope(l);
    if(k > 0)
        return atan(k);
    return PI + atan(k);
}


POINT symmetry(LINE l, POINT p) {
    POINT tp;
    tp.x = ((l.b * l.b - l.a * l.a) * p.x - 2 * l.a * l.b * p.y - 2 * l.a * l.c) / (l.a * l.a + l.b * l.b);
    tp.y = ((l.a * l.a - l.b * l.b) * p.y - 2 * l.a * l.b * p.x - 2 * l.b * l.c) / (l.a * l.a + l.b * l.b);
    return tp;
}


bool lineintersect(LINE l1, LINE l2, POINT &p) { 

    double d = l1.a * l2.b - l2.a * l1.b;
    if(abs(d) < EP) 

        return false;
    p.x = (l2.c * l1.b - l1.c * l2.b) / d;
    p.y = (l2.a * l1.c - l1.a * l2.c) / d;
    return true;
}


bool intersection(LINESEG l1, LINESEG l2, POINT &inter) {
    LINE ll1,ll2;
    ll1 = makeline(l1.s, l1.e);
    ll2 = makeline(l2.s, l2.e);
    if(lineintersect(ll1, ll2, inter))
        return online(l1, inter) && online(l2, inter);
    return false;
}






bool issimple(int vcount, POINT polygon[]) {
    int cn;
    LINESEG l1,l2;
    for(int i = 0; i < vcount; i++) {
        l1.s = polygon[i];
        l1.e = polygon[(i + 1) % vcount];
        cn = vcount - 3;
        while(cn) {
            l2.s = polygon[(i + 2) % vcount];
            l2.e = polygon[(i + 3) % vcount];
            if(intersect(l1, l2)) break;
            cn--;
        }
        if(cn)
            return false;
    }
    return true;
}


void checkconvex(int vcount, POINT polygon[], bool bc[]) {
    int index = 0;
    POINT tp = polygon[0];
    for(int i = 1; i < vcount; i++) 

        if(polygon[i].y < tp.y || (polygon[i].y == tp.y && polygon[i].x < tp.x)) {
            tp = polygon[i];
            index = i;
        }
    int count = vcount - 1;
    bc[index] = true;
    while(count) { 

        if(multiply(polygon[(index + 1) % vcount], polygon[(index + 2) % vcount], polygon[index]) >= 0)
            bc[(index + 1) % vcount] = true;
        else
            bc[(index + 1) % vcount] = false;
        index++;
        count--;
    }
}


bool isconvex(int vcount, POINT polygon[]) {
    bool bc[MAXV];
    checkconvex(vcount, polygon, bc);
    for(int i = 0; i < vcount; i++) 

        if(!bc[i]) return false;
    return true;
}


double area_of_polygon(int vcount, POINT polygon[]) {
    double s;
    if (vcount < 3)
        return 0;
    s = polygon[0].y * (polygon[vcount - 1].x - polygon[1].x);
    for (int i = 1; i < vcount; i++)
        s += polygon[i].y * (polygon[(i - 1)].x - polygon[(i + 1) % vcount].x);
    return s / 2;
}


bool isconterclock(int vcount, POINT polygon[]) {
    return area_of_polygon(vcount, polygon) > 0;
}


bool isccwize(int vcount, POINT polygon[]) {
    int index = 0;
    POINT a, b, v;
    v = polygon[0];
    for(int i = 1; i < vcount; i++) 

        if(polygon[i].y < v.y || polygon[i].y == v.y && polygon[i].x < v.x) index = i;
    a = polygon[(index - 1 + vcount) % vcount]; 

    b = polygon[(index + 1) % vcount]; 

    return multiply(v, b, a) > 0;
}

int insidepolygon(int vcount, POINT Polygon[], POINT q) {
    int c = 0, n;
    LINESEG l1,l2;
    bool bintersect_a, bonline1, bonline2, bonline3;
    double r1, r2;
    l1.s = q;
    l1.e = q;
    l1.e.x = double(INF);
    n = vcount;
    for (int i = 0; i < vcount; i++) {
        l2.s = Polygon[i];
        l2.e = Polygon[(i + 1) % n];
        if(online(l2, q))
            return 1; 

        if ( ( bintersect_a = intersect_A(l1, l2) ) || 

                ( ( bonline1 = online(l1, Polygon[(i + 1) % n]) ) && 

                  ( ( !( bonline2 = online(l1, Polygon[(i + 2) % n]) ) ) && 
                    ( ( r1 = multiply(Polygon[i], Polygon[(i + 1) % n], l1.s) * multiply(Polygon[(i + 1) % n], Polygon[(i + 2) % n], l1.s) ) > 0) ||
                    ( bonline3 = online(l1, Polygon[(i + 2) % n] ) ) &&     
                    ( ( r2 = multiply(Polygon[i], Polygon[(i + 2) % n], l1.s) * multiply(Polygon[(i + 2) % n], Polygon[(i + 3) % n], l1.s) ) > 0 ) ) ) ) c++;
    }
    if(c % 2 == 1)
        return 0;
    else
        return 2;
}


bool InsideConvexPolygon(int vcount, POINT polygon[], POINT q) { 

    POINT p;
    LINESEG l;
    p.x = 0;
    p.y = 0;
    for(int i = 0; i < vcount; i++) { 

        p.x += polygon[i].x;
        p.y += polygon[i].y;
    }
    p.x /= vcount;
    p.y /= vcount;
    int i;
    for(i = 0; i < vcount; i++) {
        l.s = polygon[i];
        l.e = polygon[(i + 1) % vcount];
        if(multiply(p, l.e, l.s) * multiply(q, l.e, l.s) < 0) 
            break;
    }
    return (i == vcount);
}

void Graham_scan(POINT PointSet[], POINT ch[], int n, int &len) {
    int k = 0, top = 2;
    POINT tmp;
    

    for(int i = 1; i < n; i++)
        if ( PointSet[i].y < PointSet[k].y || ( PointSet[i].y == PointSet[k].y ) && (PointSet[i].x < PointSet[k].x) )
            k = i;
    tmp = PointSet[0];
    PointSet[0] = PointSet[k];
    PointSet[k] = tmp; 

    for (int i = 1; i < n - 1; i++) { 
        k = i;
        for (int j = i + 1; j < n; j++)
            if ( multiply(PointSet[j], PointSet[k], PointSet[0]) > 0 ||  

                    (multiply(PointSet[j], PointSet[k], PointSet[0]) == 0) && 
                    dist(PointSet[0], PointSet[j]) < dist(PointSet[0], PointSet[k]))
                k = j;
        tmp = PointSet[i];
        PointSet[i] = PointSet[k];
        PointSet[k] = tmp;
    }
    ch[0] = PointSet[0];
    ch[1] = PointSet[1];
    ch[2] = PointSet[2];
    for (int i = 3; i < n; i++) {
        while (multiply(PointSet[i], ch[top], ch[top-1]) >= 0)
            top--;
        ch[++top] = PointSet[i];
    }
    len = top + 1;
}


void ConvexClosure(POINT PointSet[], POINT ch[], int n, int &len) {

    int top = 0, index, first;
    double curmax, curcos, curdis;
    POINT tmp;
    LINESEG l1,l2;
    bool use[MAXV];
    tmp = PointSet[0];
    index = 0;
    

    for(int i = 1; i < n; i++) {
        if(PointSet[i].y < tmp.y || PointSet[i].y == tmp.y && PointSet[i].x < tmp.x)
            index = i;
        use[i] = false;
    }
    tmp = PointSet[index];
    first = index;
    use[index] = true;
    index = -1;
    ch[top++] = tmp;
    tmp.x -= 100;
    l1.s = tmp;
    l1.e = ch[0];
    l2.s = ch[0];
    while(index != first) {
        curmax = -100;
        curdis = 0;
        

        for(int i = 0; i < n; i++) {
            if(use[i])continue;
            l2.e = PointSet[i];
            curcos = cosine(l1, l2); 

            if(curcos > curmax || fabs(curcos - curmax) < 1e-6 && dist(l2.s, l2.e) > curdis) {
                curmax = curcos;
                index = i;
                curdis = dist(l2.s,l2.e);
            }
        }
        use[first] = false;            

        use[index] = true;
        ch[top++] = PointSet[index];
        l1.s = ch[top - 2];
        l1.e = ch[top - 1];
        l2.s = ch[top - 1];
    }
    len = top - 1;
}

bool LinesegInsidePolygon(int vcount, POINT polygon[], LINESEG l) {
    

    if(!insidepolygon(vcount, polygon, l.s) || !insidepolygon(vcount, polygon, l.e))
        return false;
    int top = 0;
    POINT PointSet[MAXV], tmp;
    LINESEG s;
    for(int i = 0; i < vcount; i++) {
        s.s = polygon[i];
        s.e = polygon[(i + 1) % vcount];
        if(online(s, l.s)) 

            PointSet[top++] = l.s;
        else if(online(s, l.e)) 

            PointSet[top++] = l.e;
        else {
            if(online(l, s.s)) 

                PointSet[top++] = s.s;
            else if(online(l, s.e)) 

                PointSet[top++] = s.e;
            else {
                if(intersect(l, s)) 

                    return false;
            }
        }
    }
    for(int i = 0; i < top - 1; i++) { 
        for(int j = i + 1; j < top; j++) {
            if( PointSet[i].x > PointSet[j].x || fabs(PointSet[i].x - PointSet[j].x) < EP && PointSet[i].y > PointSet[j].y ) {
                tmp = PointSet[i];
                PointSet[i] = PointSet[j];
                PointSet[j] = tmp;
            }
        }
    }
    for(int i = 0; i < top - 1; i++) {
        tmp.x = (PointSet[i].x + PointSet[i+1].x) / 2; 

        tmp.y = (PointSet[i].y + PointSet[i+1].y) / 2;
        if(!insidepolygon(vcount, polygon, tmp))
            return false;
    }
    return true;
}

void AddPosPart(double x, double y, double w, double &xtr, double &ytr, double &wtr) {
    if (abs(wtr + w) < 1e-10 ) return; 

    xtr = ( wtr*xtr + w*x ) / ( wtr + w );
    ytr = ( wtr*ytr + w*y ) / ( wtr + w );
    wtr = w + wtr;
    return;
}
void AddNegPart(double x, double y, double w, double &xtl, double &ytl, double &wtl) {
    if ( abs(wtl + w) < 1e-10 )
        return; 

    xtl = ( wtl*xtl + w*x ) / ( wtl + w );
    ytl = ( wtl*ytl + w*y ) / ( wtl + w );
    wtl = w + wtl;
    return;
}
void AddRegion ( double x1, double y1, double x2, double y2, double &xtr, double &ytr, double &wtr, double &xtl, double &ytl, double &wtl ) {
    if ( abs(x1 - x2) < 1e-10 )
        return;
    if ( x2 > x1 ) {
        AddPosPart ((x2 + x1) / 2, y1 / 2, (x2 - x1) * y1, xtr, ytr, wtr); 
        AddPosPart ((x1 + x2 + x2) / 3, (y1 + y1 + y2) / 3, (x2 - x1) * (y2 - y1) / 2, xtr, ytr, wtr);

    } else {
        AddNegPart ((x2 + x1) / 2, y1 / 2, (x2 - x1) * y1, xtl, ytl, wtl);

        AddNegPart ((x1 + x2 + x2) / 3, (y1 + y1 + y2) / 3, (x2 - x1) * (y2 - y1) / 2, xtl, ytl, wtl);

    }
}
POINT cg_simple(int vcount, POINT polygon[]) {
    double xtr, ytr, wtr, xtl, ytl, wtl;
    

    POINT p1, p2, tp;
    xtr = ytr = wtr = 0.0;
    xtl = ytl = wtl = 0.0;
    for(int i = 0; i < vcount; i++) {
        p1 = polygon[i];
        p2 = polygon[(i + 1) % vcount];
        AddRegion(p1.x, p1.y, p2.x, p2.y, xtr, ytr, wtr, xtl, ytl, wtl); 

    }
    tp.x = (wtr * xtr + wtl*xtl) / (wtr + wtl);
    tp.y = (wtr * ytr + wtl*ytl) / (wtr + wtl);
    return tp;
}


POINT gravitycenter(int vcount,POINT polygon[]) {
    POINT tp;
    double x, y, s, x0, y0, cs, k;
    x = 0;
    y = 0;
    s = 0;
    for(int i = 1; i < vcount - 1; i++) {
        x0 = (polygon[0].x + polygon[i].x + polygon[i + 1].x) / 3;
        y0 = (polygon[0].y + polygon[i].y + polygon[i + 1].y) / 3; 

        cs = multiply(polygon[i], polygon[i + 1], polygon[0]) / 2;
        

        if(abs(s) < 1e-20) {
            x = x0;
            y = y0;
            s += cs;
            continue;
        }
        k = cs / s; 

        x = (x + k * x0) / (1 + k);
        y = (y + k * y0) / (1 + k);
        s += cs;
    }
    tp.x = x;
    tp.y = y;
    return tp;
}

POINT a_point_insidepoly(int vcount, POINT polygon[]) {
    POINT v, a, b, r;
    int index = 0;
    v = polygon[0];
    for(int i = 1; i < vcount; i++) { 

        if(polygon[i].y < v.y) {
            v = polygon[i];
            index = i;
        }
    }
    a = polygon[(index - 1 + vcount) % vcount]; 

    b = polygon[(index + 1) % vcount]; 

    POINT tri[3],q;
    tri[0] = a;
    tri[1] = v;
    tri[2] = b;
    double md = INF;
    int in1 = index;
    bool bin = false;
    for(int i = 0; i < vcount; i++) { 

        if(i == index) continue;
        if(i == (index - 1 + vcount) % vcount) continue;
        if(i == (index + 1) % vcount) continue;
        if(!InsideConvexPolygon(3, tri, polygon[i])) continue;
        bin = true;
        if(dist(v, polygon[i]) < md) {
            q = polygon[i];
            md = dist(v, q);
        }
    }
    if(!bin) { 

        r.x = (a.x + b.x) / 2;
        r.y = (a.y + b.y) / 2;
        return r;
    }
    r.x = (v.x + q.x) / 2; 

    r.y = (v.y + q.y) / 2;
    return r;
}

void pointtangentpoly(int vcount, POINT polygon[], POINT p, POINT &rp, POINT &lp) {
    LINESEG ep, en;
    bool blp, bln;
    rp = polygon[0];
    lp = polygon[0];
    for(int i = 1; i < vcount; i++) {
        ep.s = polygon[(i + vcount - 1) % vcount];
        ep.e = polygon[i];
        en.s = polygon[i];
        en.e = polygon[(i + 1) % vcount];
        blp = multiply(ep.e, p, ep.s) >= 0;                

        bln = multiply(en.e, p, en.s) >= 0;                

        if(!blp && bln) {
            if(multiply(polygon[i], rp, p) > 0)           

                rp = polygon[i];
        }
        if(blp && !bln) {
            if(multiply(lp, polygon[i], p)>0)           

                lp = polygon[i];
        }
    }
    return ;
}


bool core_exist(int vcount, POINT polygon[], POINT &p) {
    int i, j, k;
    LINESEG l;
    LINE lineset[MAXV];
    for(i = 0; i < vcount; i++)
        lineset[i] = makeline(polygon[i], polygon[(i + 1) % vcount]);
    for(i = 0; i < vcount; i++) {
        for(j = 0; j < vcount; j++) {
            if(i == j)continue;
            if(lineintersect(lineset[i], lineset[j], p)) {
                for(k = 0; k < vcount; k++) {
                    l.s = polygon[k];
                    l.e = polygon[(k + 1) % vcount];
                    if(multiply(p, l.e, l.s) > 0)
                        

                        break;
                }
                if(k == vcount)             

                    break;
            }
        }
        if(j < vcount) break;
    }
    if(i < vcount) return true;
    return false;
}

void Diameter(POINT ch[], int n, double &dia) {
    int znum = 0,k = 1;
    int zd[MAXV][2];
    double tmp;
    while(multiply(ch[0], ch[k + 1], ch[n - 1]) > multiply(ch[0], ch[k], ch[n - 1]) - EP)
        k++;
    int i = 0, j = k;
    while(i <= k && j < n) {
        zd[znum][0] = i;
        zd[znum++][1] = j;
        while(multiply(ch[i + 1], ch[j + 1], ch[i]) > multiply(ch[i + 1], ch[j], ch[i]) - EP && j< n-1) {
            zd[znum][0] = i;
            zd[znum++][1] = j;
            j++;
        }
        i++;
    }
    dia = -1.0;
    for(i = 0; i < znum; i++) {
        printf("%d %d\n", zd[i][0], zd[i][1]);
        tmp = dist(ch[zd[i][0]], ch[zd[i][1]]);
        if(dia < tmp)
            dia = tmp;
    }
}



bool point_in_circle(POINT o, double r, POINT p) {
    double d2 = (p.x - o.x) * (p.x - o.x) + (p.y - o.y) * (p.y - o.y);
    double r2 = r * r;
    return d2 < r2 || abs(d2 - r2) < EP;
}

bool cocircle(POINT p1, POINT p2, POINT p3, POINT &q, double &r) {
    double x12 = p2.x - p1.x;
    double y12 = p2.y - p1.y;
    double x13 = p3.x - p1.x;
    double y13 = p3.y - p1.y;
    double z2 = x12 * (p1.x + p2.x) + y12 * (p1.y + p2.y);
    double z3 = x13 * (p1.x + p3.x) + y13 * (p1.y + p3.y);
    double d = 2.0 * (x12 * (p3.y - p2.y) - y12 * (p3.x - p2.x));
    if(abs(d) < EP) 

        return false;
    q.x = (y13 * z2 - y12 * z3) / d;
    q.y = (x12 * z3 - x13 * z2) / d;
    r = dist(p1, q);
    return true;
}
int line_circle(LINE l, POINT o, double r, POINT &p1, POINT &p2) {
    return true;
}






POINT rect4th(POINT a, POINT b, POINT c) {
    POINT d;
    if(abs(dotmultiply(a, b, c)) < EP) { 

        d.x = a.x + b.x - c.x;
        d.y = a.y + b.y - c.y;
    }
    if(abs(dotmultiply(a, c, b)) < EP) { 

        d.x = a.x + c.x - b.x;
        d.y = a.y + c.y - b.x;
    }
    if(abs(dotmultiply(c, b, a)) < EP) { 

        d.x = c.x + b.x - a.x;
        d.y = c.y + b.y - a.y;
    }
    return d;
}














int CircleRelation(POINT p1, double r1, POINT p2, double r2) {
    double d = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    if(fabs(d - r1 - r2) < EP) 

        return 2;
    if(fabs(d - fabs(r1 - r2)) < EP) return 4;
    if(d > r1 + r2) return 1;
    if(d < fabs(r1 - r2)) return 5;
    if(fabs(r1 - r2) < d && d < r1 + r2) return 3;
    return 0; 

}






bool CircleRecRelation(POINT pc, double r, POINT pr1, POINT pr2, POINT pr3, POINT pr4) {
    if(pr1.x < pc.x && pc.x < pr2.x && pr3.y < pc.y && pc.y < pr2.y) {
        LINESEG line1(pr1, pr2);
        LINESEG line2(pr2, pr3);
        LINESEG line3(pr3, pr4);
        LINESEG line4(pr4, pr1);
        if(r < ptoldist(pc, line1) && r < ptoldist(pc, line2) && r < ptoldist(pc, line3) && r < ptoldist(pc, line4))
            return true;
    }
    return false;
}




double PtoplaneDist(double x, double y, double z, double a, double b, double c, double d) {
    return fabs(a * x + b * y + c * z + d) / sqrt(a * a + b * b + c * c);
}




bool SameSide(POINT p1, POINT p2, LINE line) {
    return (line.a * p1.x + line.b * p1.y + line.c) * (line.a * p2.x + line.b * p2.y + line.c) > 0;
}














void reflect(double a1, double b1, double c1, double a2, double b2, double c2, double &a, double &b, double &c) {
    double n, m;
    double tpb, tpa;
    tpb = b1 * b2 + a1 * a2;
    tpa = a2 * b1 - a1 * b2;
    m = (tpb * b1 + tpa * a1) / (b1 * b1 + a1 * a1);
    n = (tpa * b1 - tpb * a1) / (b1 * b1 + a1 * a1);
    if(fabs(a1 * b2 - a2 * b1) < 1e-20) {
        a = a2;
        b = b2;
        c = c2;
        return;
    }
    double xx,yy; 

    xx = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
    yy = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1);
    a = n;
    b = -m;
    c = m * yy - xx * n;
}




bool r2inr1(double A, double B, double C, double D) {
    double X, Y, L, K, DMax;
    if (A < B) {
        double tmp = A;
        A = B;
        B = tmp;
    }
    if (C < D) {
        double tmp = C;
        C = D;
        D = tmp;
    }
    if (A > C && B > D)                 

        return true;
    else if (D >= B) return false;
    else {
        X = sqrt(A * A + B * B);         

        Y = sqrt(C * C + D * D);         

        if (Y < B) 

            return true; 

        else if (Y > X) return false;
        else {
            L = (B - sqrt(Y * Y - A * A)) / 2;
            K = (A - sqrt(Y * Y - B * B)) / 2;
            DMax = sqrt(L * L + K * K);
            if (D >= DMax) return false;
            else return true;
        }
    }
}




void  c2point(POINT p1, double r1, POINT p2, double r2, POINT &rp1, POINT &rp2) {
    double a, b, r;
    a = p2.x - p1.x;
    b = p2.y - p1.y;
    r = (a * a + b * b + r1 * r1 - r2 * r2) / 2;
    if(a == 0 && b != 0) {
        rp1.y = rp2.y = r / b;
        rp1.x = sqrt(r1 * r1 - rp1.y * rp1.y);
        rp2.x = -rp1.x;
    } else if(a != 0 && b == 0) {
        rp1.x = rp2.x = r / a;
        rp1.y = sqrt(r1 * r1 - rp1.x * rp2.x);
        rp2.y = -rp1.y;
    } else if(a != 0 && b != 0) {
        double delta;
        delta = b * b * r * r - (a * a + b * b) * (r * r - r1 * r1 * a * a);
        rp1.y = (b * r + sqrt(delta)) / (a * a + b * b);
        rp2.y = (b * r - sqrt(delta)) / (a * a + b * b);
        rp1.x = (r - b * rp1.y) / a;
        rp2.x = (r - b * rp2.y) / a;
    }

    rp1.x += p1.x;
    rp1.y += p1.y;
    rp2.x += p1.x;
    rp2.y += p1.y;
}





double c2area(POINT p1, double r1, POINT p2, double r2) {
    POINT rp1, rp2;
    c2point(p1, r1, p2, r2, rp1, rp2);
    if(r1 > r2) { 

        swap(p1, p2);
        swap(r1, r2);
    }
    double a, b, rr;
    a = p1.x - p2.x;
    b = p1.y - p2.y;
    rr = sqrt(a * a + b * b);

    double dx1, dy1, dx2, dy2;
    double sita1, sita2;
    dx1 = rp1.x - p1.x;
    dy1 = rp1.y - p1.y;
    dx2 = rp2.x - p1.x;
    dy2 = rp2.y - p1.y;
    sita1 = acos((dx1 * dx2 + dy1 * dy2) / r1 / r1);

    dx1 = rp1.x - p2.x;
    dy1 = rp1.y - p2.y;
    dx2 = rp2.x - p2.x;
    dy2 = rp2.y - p2.y;
    sita2 = acos((dx1 * dx2 + dy1 * dy2) / r2 / r2);
    double s = 0;
    if(rr < r2)

        s = r1 * r1 * (PI - sita1 / 2 + sin(sita1) / 2) + r2 * r2 * (sita2 - sin(sita2)) / 2;
    else

        s = (r1 * r1 * (sita1 - sin(sita1)) + r2 * r2 * (sita2 - sin(sita2))) / 2;
    return s;
}






long double c3area(POINT p1,long double r1, POINT p2,long double r2) {
    long double x1,y1,x2,y2;
    x1 = p1.x,y1 = p1.y,x2 = p2.x,y2 = p2.y;
    long double dis = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if(r1 > r2)  swap(r1,r2)    ;


    if(dis >= r1 + r2) return 0;
    else if(r2 - r1 >= dis){
            return r1 * r1 * acos(-1);
    }else {
        long double d1 = acos((r1 * r1 + dis * dis - r2 * r2) / (2.0 * r1 * dis));
        long double d2 = acos((r2 * r2 + dis * dis - r1 * r1) / (2.0 * r2 * dis));


        d1 *= 2.0,d2 *= 2.0;
        long double s = sin(d1) * r1 * r1;
        long double ss = sin(d2) * r2 * r2;
        

        long double s1 = d1 * r1 * r1;
        long double s2 = d2 * r2 * r2;



        return (s1 + s2 - s - ss) / 2.0;

    }
}





int clpoint(POINT p, double r, double a, double b, double c, POINT &rp1, POINT &rp2) {
    int res = 0;
    c = c + a * p.x + b*p.y;
    double tmp;
    if(a == 0 && b != 0) {
        tmp = -c / b;
        if(r * r < tmp * tmp)
            res = 0;
        else if(r * r == tmp * tmp) {
            res = 1;
            rp1.y = tmp;
            rp1.x = 0;
        } else {
            res = 2;
            rp1.y = rp2.y = tmp;
            rp1.x = sqrt(r * r - tmp * tmp);
            rp2.x = -rp1.x;

        }
    } else if(a != 0 && b == 0) {
        tmp = -c / a;
        if(r * r < tmp * tmp)
            res = 0;
        else if(r * r == tmp * tmp) {
            res = 1;
            rp1.x = tmp;
            rp1.y = 0;
        } else {
            res = 2;
            rp1.x = rp2.x = tmp;
            rp1.y = sqrt(r * r - tmp * tmp);
            rp2.y = -rp1.y;
        }
    } else if(a != 0&&b != 0) {
        double delta;
        delta = b * b * c * c - (a * a + b * b) * (c * c - a * a * r * r);
        if(delta < 0)
            res = 0;
        else if(delta == 0) {
            res = 1;
            rp1.y = -b * c / (a * a + b * b);
            rp1.x = (-c - b * rp1.y) / a;
        } else {
            res = 2;
            rp1.y = (-b * c + sqrt(delta)) / (a * a + b * b);
            rp2.y = (-b * c - sqrt(delta)) / (a * a + b * b);
            rp1.x = (-c - b * rp1.y) / a;
            rp2.x = (-c - b * rp2.y) / a;
        }
    }
    rp1.x += p.x;
    rp1.y += p.y;
    rp2.x += p.x;
    rp2.y += p.y;
    return res;
}


void incircle(POINT p1, POINT p2, POINT p3, POINT &rp, double &r) {
    double dx31, dy31, dx21, dy21, d31, d21, a1, b1, c1;
    dx31 = p3.x - p1.x;
    dy31 = p3.y - p1.y;
    dx21 = p2.x - p1.x;
    dy21 = p2.y - p1.y;

    d31 = sqrt(dx31 * dx31 + dy31 * dy31);
    d21 = sqrt(dx21 * dx21 + dy21 * dy21);
    a1 = dx31 * d21 - dx21 * d31;
    b1 = dy31 * d21 - dy21 * d31;
    c1 = a1 * p1.x + b1 * p1.y;

    double dx32, dy32, dx12, dy12, d32, d12, a2, b2, c2;
    dx32 = p3.x - p2.x;
    dy32 = p3.y - p2.y;
    dx12 = -dx21;
    dy12 = -dy21;

    d32 = sqrt(dx32 * dx32 + dy32 * dy32);
    d12 = d21;
    a2 = dx12 * d32 - dx32 * d12;
    b2 = dy12 * d32 - dy32 * d12;
    c2 = a2 * p2.x + b2 * p2.y;
    rp.x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
    rp.y = (c2 * a1 - c1 * a2) / (a1 * b2 - a2 * b1);
    r = fabs(dy21 * rp.x - dx21 * rp.y + dx21 * p1.y - dy21 * p1.x) / d21;
}




void cutpoint(POINT p, double r, POINT sp, POINT &rp1, POINT &rp2) {
    POINT p2;
    p2.x = (p.x + sp.x) / 2;
    p2.y = (p.y + sp.y) / 2;
    double dx2, dy2, r2;
    dx2 = p2.x - p.x;
    dy2 = p2.y - p.y;
    r2 = sqrt(dx2 * dx2 + dy2 * dy2);
    c2point(p, r, p2, r2, rp1, rp2);
}



int rotat(LINESEG l1, LINESEG l2) {
    double dx1, dx2, dy1, dy2;
    dx1 = l1.s.x - l1.e.x;
    dy1 = l1.s.y - l1.e.y;
    dx2 = l2.s.x - l2.e.x;
    dy2 = l2.s.y - l2.e.y;
    double d;
    d = dx1 * dy2 - dx2 * dy1;
    if(d == 0) return 0;
    else if(d > 0) return -1;
    else return 1;
}





int main(int argc, char** argv) {
    POINT x,y;
    double r1,r2;
    while(cin >> x.x >> x.y >> r1 >> y.x >> y.y >> r2) {
        int flag = CircleRelation(x,r1,y,r2);


        if(flag != 1) {
            long double s = c3area(x,r1,y,r2);
            cout << fixed <<  s <<endl;


        } else {
            cout << "0.000000000" << endl;
        }
    }
    return 0;
}


