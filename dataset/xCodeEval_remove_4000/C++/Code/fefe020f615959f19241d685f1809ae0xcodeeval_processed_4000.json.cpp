

using namespace std;









typedef long long ll;
typedef long double ld;
ld pi = 3.141592653589793238;





const ll INF = ll(2e18);



  

  

ll mo(const ll input, const ll ceil)
{
  return input >= ceil ? input % ceil : input;
}

struct Point
{
  ld x;
  ld y;
};





bool onSegment(Point p, Point q, Point r)
{
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
          q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
    return true;

  return false;
}











ld orientation(Point p, Point q, Point r)
{
  

  

  ld val = (q.y - p.y) * (r.x - q.x) -
           (q.x - p.x) * (r.y - q.y);

  if (val == 0) return 0;  


  return (val > 0) ? 1 : 2; 

}





bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
  

  

  ld o1 = orientation(p1, q1, p2);
  ld o2 = orientation(p1, q1, q2);
  ld o3 = orientation(p2, q2, p1);
  ld o4 = orientation(p2, q2, q1);

  

  if (o1 != o2 && o3 != o4)
    return true;

  

  

  if (o1 == 0 && onSegment(p1, p2, q1)) return true;

  

  if (o2 == 0 && onSegment(p1, q2, q1)) return true;

  

  if (o3 == 0 && onSegment(p2, p1, q2)) return true;

  

  if (o4 == 0 && onSegment(p2, q1, q2)) return true;

  return false; 

}

ld distanc(ld x1, ld y1, ld x2, ld y2)
{
  ld gb = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  gb = 1.0 * sqrtl(gb * 1.0);
  return gb;
}

void solve(int tc)
{
  ld a, b, c;
  cin >> a >> b >> c;
  ld x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  

  if(x1 > x2)
  {
    swap(x1, x2);
    swap(y1, y2);
  }
  

  

  

  

  

  

  

  

  

  

  

  

  


  if(y1 >= y2)
  {
    

    

    

    

    

    

    


    


    ld dist = fabs(x1 - x2) + fabs(y1 - y2);
    

    if(a == 0 || b == 0 || (a < 0 && b > 0) || (a > 0 && b < 0))

    {
      cout << fixed << setprecision(12) << dist << "\n";
      return;
    }

    

    ld xa = x1;
    ld ya = y1;
    ld xb = x2;
    ld yb = y1;
    ld xc = x2;
    ld yc = y2;
    ld xd = x1;
    ld yd = y2;

    

    bool abfuck = 0, dcfuck = 0, bcfuck = 0, adfuck = 0;


    


    

    

    

    

    {
      struct Point p1 = {xa, ya}, q1 = {xb, yb};
      ld linexa = xa, lineya = ((-a / b) * xa) - (c / b);
      ld id0 = xb, lineyb = ((-a / b) * xb) - (c / b);
      struct Point p2 = {linexa, lineya}, q2 = {id0, lineyb};
      abfuck = doIntersect(p1, q1, p2, q2);
    }

    


    

    

    

    

    {
      struct Point p1 = {xd, yd}, q1 = {xc, yc};
      ld id1 = xd, lineyd = ((-a / b) * xd) - (c / b);
      ld linexc = xc, lineyc = ((-a / b) * xc) - (c / b);
      struct Point p2 = {id1, lineyd}, q2 = {linexc, lineyc};
      dcfuck = doIntersect(p1, q1, p2, q2);
    }


    


    

    

    

    

    {
      struct Point p1 = {xb, yb}, q1 = {xc, yc};
      ld lineyb = yb, id0 = ((-b / a) * yb) - (c / a);
      ld lineyc = yc, linexc = ((-b / a) * yc) - (c / a);
      struct Point p2 = {id0, lineyb}, q2 = {linexc, lineyc};
      bcfuck = doIntersect(p1, q1, p2, q2);
    }

    


    

    

    

    

    {
      struct Point p1 = {xa, ya}, q1 = {xd, yd};
      ld lineya = ya, linexa = ((-b / a) * ya) - (c / a);
      ld lineyd = yd, id1 = ((-b / a) * yd) - (c / a);
      struct Point p2 = {linexa, lineya}, q2 = {id1, lineyd};
      adfuck = doIntersect(p1, q1, p2, q2);
    }

    

    

    

    

    

    

    

    

    

    

    


    


    

    if(abfuck == 0 && bcfuck == 0 && dcfuck == 0 && adfuck == 0)
    {
      cout << fixed << setprecision(12) << dist << "\n";
      return;
    }

    


    if(abfuck == 1 && bcfuck == 1)
    {
      ld lineya = ya, linexa = ((-b / a) * ya) - (c / a);
      ld linexc = xc, lineyc = ((-a / b) * xc) - (c / b);
      ld newdim = distanc(xa, ya, linexa, lineya) + distanc(linexa, lineya, linexc, lineyc) + distanc(linexc, lineyc, xc, yc);
      cout << fixed << setprecision(12) << min(newdim, dist) << "\n";
      return;
    }
    else if(adfuck == 1 && dcfuck == 1)
    {
      ld id1 = xd, lineyd = ((-a / b) * xd) - (c / b);
      ld lineyc = yc, linexc = ((-b / a) * yc) - (c / a);
      ld newdim = distanc(xa, ya, id1, lineyd) + distanc(id1, lineyd, linexc, lineyc) + distanc(linexc, lineyc, xc, yc);
      cout << fixed << setprecision(12) << min(newdim, dist) << "\n";
      return;
    }
    else if(abfuck == 1 && dcfuck == 1)
    {
      

      

      

      

      

      

      


      

      ld lineya = ya, linexa = ((-b / a) * ya) - (c / a);
      ld lineyc = yc, linexc = ((-b / a) * yc) - (c / a);
      ld newdim = distanc(xa, ya, linexa, lineya) + distanc(linexa, lineya, linexc, lineyc) + distanc(linexc, lineyc, xc, yc);
      cout << fixed << setprecision(12) << min(newdim, dist) << "\n";
      return;
    }
    else if(adfuck == 1 && bcfuck == 1)
    {
      ld id1 = xd, lineyd = ((-a / b) * xd) - (c / b);
      ld linexc = xc, lineyc = ((-a / b) * xc) - (c / b);
      ld newdim = distanc(xa, ya, id1, lineyd) + distanc(id1, lineyd, linexc, lineyc) + distanc(linexc, lineyc, xc, yc);
      cout << fixed << setprecision(12) << min(newdim, dist) << "\n";
      return;
    }
    else
    {
      xd("bitchphela")
    }

  }
  else
  {
    

    

    

    

    

    

    


    


    ld dist = fabs(x1 - x2) + fabs(y1 - y2);
    if(a == 0 || b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))

    {
      cout << fixed << setprecision(12) << dist << "\n";
      return;
    }

    

    ld xa = x1;
    ld ya = y2;
    ld xb = x2;
    ld yb = y2;
    ld xc = x2;
    ld yc = y1;
    ld xd = x1;
    ld yd = y1;

    

    bool abfuck = 0, dcfuck = 0, bcfuck = 0, adfuck = 0;


    


    

    

    

    

    {
      struct Point p1 = {xa, ya}, q1 = {xb, yb};
      ld linexa = xa, lineya = ((-a / b) * xa) - (c / b);
      ld id0 = xb, lineyb = ((-a / b) * xb) - (c / b);
      struct Point p2 = {linexa, lineya}, q2 = {id0, lineyb};
      abfuck = doIntersect(p1, q1, p2, q2);
    }

    


    

    

    

    

    {
      struct Point p1 = {xd, yd}, q1 = {xc, yc};
      ld id1 = xd, lineyd = ((-a / b) * xd) - (c / b);
      ld linexc = xc, lineyc = ((-a / b) * xc) - (c / b);
      struct Point p2 = {id1, lineyd}, q2 = {linexc, lineyc};
      dcfuck = doIntersect(p1, q1, p2, q2);
    }


    


    

    

    

    

    {
      struct Point p1 = {xb, yb}, q1 = {xc, yc};
      ld lineyb = yb, id0 = ((-b / a) * yb) - (c / a);
      ld lineyc = yc, linexc = ((-b / a) * yc) - (c / a);
      struct Point p2 = {id0, lineyb}, q2 = {linexc, lineyc};
      bcfuck = doIntersect(p1, q1, p2, q2);
    }

    


    

    

    

    

    {
      struct Point p1 = {xa, ya}, q1 = {xd, yd};
      ld lineya = ya, linexa = ((-b / a) * ya) - (c / a);
      ld lineyd = yd, id1 = ((-b / a) * yd) - (c / a);
      struct Point p2 = {linexa, lineya}, q2 = {id1, lineyd};
      adfuck = doIntersect(p1, q1, p2, q2);
    }

    

    

    

    

    

    

    


    


    

    if(abfuck == 0 && bcfuck == 0 && dcfuck == 0 && adfuck == 0)
    {
      cout << fixed << setprecision(12) << dist << "\n";
      return;
    }

    


    if(adfuck == 1 && abfuck == 1)
    {
      ld id1 = xd, lineyd = ((-a / b) * xd) - (c / b);
      ld lineyb = yb, id0 = ((-b / a) * yb) - (c / a);
      ld newdim = distanc(xd, yd, id1, lineyd) + distanc(id1, lineyd, id0, lineyb) + distanc(id0, lineyb, xb, yb);
      cout << fixed << setprecision(12) << min(newdim, dist) << "\n";
      return;
    }
    else if(dcfuck == 1 && bcfuck == 1)
    {
      ld lineyd = yd, id1 = ((-b / a) * yd) - (c / a);
      ld linexc = xc, lineyc = ((-a / b) * xc) - (c / b);
      ld newdim = distanc(xd, yd, id1, lineyd) + distanc(id1, lineyd, linexc, lineyc) + distanc(linexc, lineyc, xb, yb);
      cout << fixed << setprecision(12) << min(newdim, dist) << "\n";
      return;
    }
    else if(adfuck == 1 && bcfuck == 1)
    {
      

      

      

      

      

      

      


      

      ld id1 = xd, lineyd = ((-a / b) * xd) - (c / b);
      ld linexc = xc, lineyc = ((-a / b) * xc) - (c / b);
      ld newdim = distanc(xd, yd, id1, lineyd) + distanc(id1, lineyd, linexc, lineyc) + distanc(linexc, lineyc, xb, yb);
      cout << fixed << setprecision(12) << min(newdim, dist) << "\n";
      return;
    }
    else if(dcfuck == 1 && abfuck == 1)
    {
      ld lineyd = yd, id1 = ((-b / a) * yd) - (c / a);
      ld lineyb = yb, id0 = ((-b / a) * yb) - (c / a);
      ld newdim = distanc(xd, yd, id1, lineyd) + distanc(id1, lineyd, id0, lineyb) + distanc(id0, lineyb, xb, yb);
      cout << fixed << setprecision(12) << min(newdim, dist) << "\n";
      return;
    }
    else 
    {
      xd("bitchdusra") 
    }
  }

}

signed main()
{
  fio
  int tt = 1;
  

  for (int i = 0; i < tt; i++)
  {
    solve(i + 1);
  }
  return 0;
}
