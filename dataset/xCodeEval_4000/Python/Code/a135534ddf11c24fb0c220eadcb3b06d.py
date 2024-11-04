from collections import namedtuple
import math

DRAW = False































def usage():
    print """
voronoi - compute Voronoi diagram or Delaunay triangulation

voronoi [-t -p -d]  [filename]

Voronoi reads from filename (or standard input if no filename given) for a set 
of points in the plane and writes either the Voronoi diagram or the Delaunay 
triangulation to the standard output.  Each input line should consist of two 
real numbers, separated by white space.

If option -t is present, the Delaunay triangulation is produced. 
Each output line is a triple i j k, which are the indices of the three points
in a Delaunay triangle. Points are numbered starting at 0.

If option -t is not present, the Voronoi diagram is produced.  
There are four output record types.

s a b      indicates that an input point at coordinates a b was seen.
l a b c    indicates a line with equation ax + by = c.
v a b      indicates a vertex at a b.
e l v1 v2  indicates a Voronoi segment which is a subsegment of line number l
           with endpoints numbered v1 and v2.  If v1 or v2 is -1, the line 
           extends to infinity.

Other options include:

d    Print debugging info

p    Produce output suitable for input to plot (1), rather than the forms 
     described above.

On unsorted data uniformly distributed in the unit square, voronoi uses about 
20n+140 bytes of storage.

AUTHOR
Steve J. Fortune (1987) A Sweepline Algorithm for Voronoi Diagrams,
Algorithmica 2, 153-174.
"""


























import math
import sys
import getopt
TOLERANCE = 1e-9
BIG_FLOAT = 1e38


class Context(object):
    def __init__(self):
        self.doPrint = 0
        self.debug   = 0
        self.plot    = 0
        self.triangulate = False
        self.vertices  = []    
        self.lines     = []    
        self.edges     = []    
        self.triangles = []    

    def circle(self,x,y,rad):
        pass

    def clip_line(self,edge):
        pass

    def line(self,x0,y0,x1,y1):
        pass

    def outSite(self,s):
        if(self.debug):
            print "site (%d) at %f %f" % (s.sitenum, s.x, s.y)
        elif(self.triangulate):
            pass
        elif(self.plot):
            self.circle (s.x, s.y, cradius)
        elif(self.doPrint):
            print "s %f %f" % (s.x, s.y)

    def outVertex(self,s):
        self.vertices.append((s.x,s.y))
        if(self.debug):
            print  "vertex(%d) at %f %f" % (s.sitenum, s.x, s.y)
        elif(self.triangulate):
            pass
        elif(self.doPrint and not self.plot):
            print "v %f %f" % (s.x,s.y)

    def outTriple(self,s1,s2,s3):
        self.triangles.append((s1.sitenum, s2.sitenum, s3.sitenum))
        if(self.debug):
            print "circle through left=%d right=%d bottom=%d" % (s1.sitenum, s2.sitenum, s3.sitenum)
        elif(self.triangulate and self.doPrint and not self.plot):
            print "%d %d %d" % (s1.sitenum, s2.sitenum, s3.sitenum)

    def outBisector(self,edge):
        self.lines.append((edge.a, edge.b, edge.c))
        if(self.debug):
            print "line(%d) %gx+%gy=%g, bisecting %d %d" % (edge.edgenum, edge.a, edge.b, edge.c, edge.reg[0].sitenum, edge.reg[1].sitenum)
        elif(self.triangulate):
            if(self.plot):
                self.line(edge.reg[0].x, edge.reg[0].y, edge.reg[1].x, edge.reg[1].y)
        elif(self.doPrint and not self.plot):
            print "l %f %f %f" % (edge.a, edge.b, edge.c)

    def outEdge(self,edge):
        sitenumL = -1
        if edge.ep[Edge.LE] is not None:
            sitenumL = edge.ep[Edge.LE].sitenum
        sitenumR = -1
        if edge.ep[Edge.RE] is not None:
            sitenumR = edge.ep[Edge.RE].sitenum
        self.edges.append((edge.edgenum,sitenumL,sitenumR))
        if(not self.triangulate):
            if self.plot:
                self.clip_line(edge)
            elif(self.doPrint): 
                print "e %d" % edge.edgenum,
                print " %d " % sitenumL,
                print "%d" % sitenumR


def voronoi(siteList,context):
    edgeList  = EdgeList(siteList.xmin,siteList.xmax,len(siteList))
    priorityQ = PriorityQueue(siteList.ymin,siteList.ymax,len(siteList))
    siteIter = siteList.iterator()
    
    bottomsite = siteIter.next()
    context.outSite(bottomsite)
    newsite = siteIter.next()
    minpt = Site(-BIG_FLOAT,-BIG_FLOAT)
    while True:
        if not priorityQ.isEmpty():
            minpt = priorityQ.getMinPt()

        if (newsite and (priorityQ.isEmpty() or cmp(newsite,minpt) < 0)):
            
            context.outSite(newsite)
            
            
            lbnd = edgeList.leftbnd(newsite) 
            rbnd = lbnd.right                    
            
            
            
            bot  = lbnd.rightreg(bottomsite)     
            edge = Edge.bisect(bot,newsite)      
            context.outBisector(edge)
            
            
            
            
            bisector = Halfedge(edge,Edge.LE)    
            edgeList.insert(lbnd,bisector)       

            
            
            p = lbnd.intersect(bisector)
            if p is not None:
                priorityQ.delete(lbnd)
                priorityQ.insert(lbnd,p,newsite.distance(p))

            
            
            lbnd = bisector
            bisector = Halfedge(edge,Edge.RE)     
            edgeList.insert(lbnd,bisector)        

            
            p = bisector.intersect(rbnd)
            if p is not None:
                
                priorityQ.insert(bisector,p,newsite.distance(p))
            
            newsite = siteIter.next()

        elif not priorityQ.isEmpty():
            

            
            
            
            lbnd  = priorityQ.popMinHalfedge()      
            llbnd = lbnd.left               
            rbnd  = lbnd.right              
            rrbnd = rbnd.right              
            
            
            
            bot = lbnd.leftreg(bottomsite)  
            top = rbnd.rightreg(bottomsite) 
            
            
            mid = lbnd.rightreg(bottomsite)
            context.outTriple(bot,top,mid)          

            
            
            v = lbnd.vertex                 
            siteList.setSiteNumber(v)
            context.outVertex(v)
            
            
            if lbnd.edge.setEndpoint(lbnd.pm,v):
                context.outEdge(lbnd.edge)
            
            if rbnd.edge.setEndpoint(rbnd.pm,v):
                context.outEdge(rbnd.edge)

            
            
            
            edgeList.delete(lbnd)           
            priorityQ.delete(rbnd)
            edgeList.delete(rbnd)
            
            
            
            
            pm = Edge.LE
            if bot.y > top.y:
                bot,top = top,bot
                pm = Edge.RE

            
            
            edge = Edge.bisect(bot, top)     
            context.outBisector(edge)

            
            bisector = Halfedge(edge, pm)    
            
            
            
            
            
            edgeList.insert(llbnd, bisector) 
            if edge.setEndpoint(Edge.RE - pm, v):
                context.outEdge(edge)
            
            
            
            p = llbnd.intersect(bisector)
            if p is not None:
                priorityQ.delete(llbnd);
                priorityQ.insert(llbnd, p, bot.distance(p))

            
            p = bisector.intersect(rrbnd)
            if p is not None:
                priorityQ.insert(bisector, p, bot.distance(p))
        else:
            break

    he = edgeList.leftend.right
    while he is not edgeList.rightend:
        context.outEdge(he.edge)
        he = he.right


def isEqual(a,b,relativeError=TOLERANCE):
    
    norm = max(abs(a),abs(b))
    return (norm < relativeError) or (abs(a - b) < (relativeError * norm))


class Site(object):
    def __init__(self,x=0.0,y=0.0,sitenum=0):
        self.x = x
        self.y = y
        self.sitenum = sitenum

    def dump(self):
        print "Site 

    def __cmp__(self,other):
        if self.y < other.y:
            return -1
        elif self.y > other.y:
            return 1
        elif self.x < other.x:
            return -1
        elif self.x > other.x:
            return 1
        else:
            return 0

    def distance(self,other):
        dx = self.x - other.x
        dy = self.y - other.y
        return math.sqrt(dx*dx + dy*dy)


class Edge(object):
    LE = 0
    RE = 1
    EDGE_NUM = 0
    DELETED = {}   

    def __init__(self):
        self.a = 0.0
        self.b = 0.0
        self.c = 0.0
        self.ep  = [None,None]
        self.reg = [None,None]
        self.edgenum = 0

    def dump(self):
        print "(
        print "ep",self.ep
        print "reg",self.reg

    def setEndpoint(self, lrFlag, site):
        self.ep[lrFlag] = site
        if self.ep[Edge.RE - lrFlag] is None:
            return False
        return True

    @staticmethod
    def bisect(s1,s2):
        newedge = Edge()
        newedge.reg[0] = s1 
        newedge.reg[1] = s2

        
        

        
        dx = float(s2.x - s1.x)
        dy = float(s2.y - s1.y)
        adx = abs(dx)  
        ady = abs(dy)
        
        
        newedge.c = float(s1.x * dx + s1.y * dy + (dx*dx + dy*dy)*0.5)  
        if adx > ady :
            
            newedge.a = 1.0
            newedge.b = dy/dx
            newedge.c /= dx
        else:
            
            newedge.b = 1.0
            newedge.a = dx/dy
            newedge.c /= dy

        newedge.edgenum = Edge.EDGE_NUM
        Edge.EDGE_NUM += 1
        return newedge



class Halfedge(object):
    def __init__(self,edge=None,pm=Edge.LE):
        self.left  = None   
        self.right = None   
        self.qnext = None   
        self.edge  = edge   
        self.pm     = pm
        self.vertex = None  
        self.ystar  = BIG_FLOAT

    def dump(self):
        print "Halfedge--------------------------"
        print "left: ",    self.left  
        print "right: ",   self.right 
        print "edge: ",    self.edge  
        print "pm: ",      self.pm    
        print "vertex: ",
        if self.vertex: self.vertex.dump()
        else: print "None"
        print "ystar: ",   self.ystar 


    def __cmp__(self,other):
        if self.ystar > other.ystar:
            return 1
        elif self.ystar < other.ystar:
            return -1
        elif self.vertex.x > other.vertex.x:
            return 1
        elif self.vertex.x < other.vertex.x:
            return -1
        else:
            return 0

    def leftreg(self,default):
        if not self.edge: 
            return default
        elif self.pm == Edge.LE:
            return self.edge.reg[Edge.LE]
        else:
            return self.edge.reg[Edge.RE]

    def rightreg(self,default):
        if not self.edge: 
            return default
        elif self.pm == Edge.LE:
            return self.edge.reg[Edge.RE]
        else:
            return self.edge.reg[Edge.LE]


    
    def isPointRightOf(self,pt):
        e = self.edge
        topsite = e.reg[1]
        right_of_site = pt.x > topsite.x
        
        if(right_of_site and self.pm == Edge.LE): 
            return True
        
        if(not right_of_site and self.pm == Edge.RE):
            return False
        
        if(e.a == 1.0):
            dyp = pt.y - topsite.y
            dxp = pt.x - topsite.x
            fast = 0;
            if ((not right_of_site and e.b < 0.0) or (right_of_site and e.b >= 0.0)):
                above = dyp >= e.b * dxp
                fast = above
            else:
                above = pt.x + pt.y * e.b > e.c
                if(e.b < 0.0):
                    above = not above
                if (not above):
                    fast = 1
            if (not fast):
                dxs = topsite.x - (e.reg[0]).x
                above = e.b * (dxp*dxp - dyp*dyp) < dxs*dyp*(1.0+2.0*dxp/dxs + e.b*e.b)
                if(e.b < 0.0):
                    above = not above
        else:  
            yl = e.c - e.a * pt.x
            t1 = pt.y - yl
            t2 = pt.x - topsite.x
            t3 = yl - topsite.y
            above = t1*t1 > t2*t2 + t3*t3
        
        if(self.pm==Edge.LE):
            return above
        else:
            return not above

    
    
    def intersect(self,other):
        e1 = self.edge
        e2 = other.edge
        if (e1 is None) or (e2 is None):
            return None

        
        if e1.reg[1] is e2.reg[1]:
            return None

        d = e1.a * e2.b - e1.b * e2.a
        if isEqual(d,0.0):
            return None

        xint = (e1.c*e2.b - e2.c*e1.b) / d
        yint = (e2.c*e1.a - e1.c*e2.a) / d
        if(cmp(e1.reg[1],e2.reg[1]) < 0):
            he = self
            e = e1
        else:
            he = other
            e = e2

        rightOfSite = xint >= e.reg[1].x
        if((rightOfSite     and he.pm == Edge.LE) or
           (not rightOfSite and he.pm == Edge.RE)):
            return None

        
        
        return Site(xint,yint)

        


class EdgeList(object):
    def __init__(self,xmin,xmax,nsites):
        if xmin > xmax: xmin,xmax = xmax,xmin
        self.hashsize = int(2*math.sqrt(nsites+4))
        
        self.xmin   = xmin
        self.deltax = float(xmax - xmin)
        self.hash   = [None]*self.hashsize
        
        self.leftend  = Halfedge()
        self.rightend = Halfedge()
        self.leftend.right = self.rightend
        self.rightend.left = self.leftend
        self.hash[0]  = self.leftend
        self.hash[-1] = self.rightend

    def insert(self,left,he):
        he.left  = left
        he.right = left.right
        left.right.left = he
        left.right = he

    def delete(self,he):
        he.left.right = he.right
        he.right.left = he.left
        he.edge = Edge.DELETED

    
    def gethash(self,b):
        if(b < 0 or b >= self.hashsize):
            return None
        he = self.hash[b]
        if he is None or he.edge is not Edge.DELETED:
            return he

        
        self.hash[b] = None
        return None

    def leftbnd(self,pt):
        
        bucket = int(((pt.x - self.xmin)/self.deltax * self.hashsize))
        
        if(bucket < 0): 
            bucket =0;
        
        if(bucket >=self.hashsize): 
            bucket = self.hashsize-1

        he = self.gethash(bucket)
        if(he is None):
            i = 1
            while True:
                he = self.gethash(bucket-i)
                if (he is not None): break;
                he = self.gethash(bucket+i)
                if (he is not None): break;
                i += 1
    
        
        if (he is self.leftend) or (he is not self.rightend and he.isPointRightOf(pt)):
            he = he.right
            while he is not self.rightend and he.isPointRightOf(pt):
                he = he.right
            he = he.left;
        else:
            he = he.left
            while (he is not self.leftend and not he.isPointRightOf(pt)):
                he = he.left

        
        if(bucket > 0 and bucket < self.hashsize-1):
            self.hash[bucket] = he
        return he



class PriorityQueue(object):
    def __init__(self,ymin,ymax,nsites):
        self.ymin = ymin
        self.deltay = ymax - ymin
        self.hashsize = int(4 * math.sqrt(nsites))
        self.count = 0
        self.minidx = 0
        self.hash = []
        for i in range(self.hashsize):
            self.hash.append(Halfedge())

    def __len__(self):
        return self.count

    def isEmpty(self):
        return self.count == 0

    def insert(self,he,site,offset):
        he.vertex = site
        he.ystar  = site.y + offset
        last = self.hash[self.getBucket(he)]
        next = last.qnext
        while((next is not None) and cmp(he,next) > 0):
            last = next
            next = last.qnext
        he.qnext = last.qnext
        last.qnext = he
        self.count += 1

    def delete(self,he):
        if (he.vertex is not None):
            last = self.hash[self.getBucket(he)]
            while last.qnext is not he:
                last = last.qnext
            last.qnext = he.qnext
            self.count -= 1
            he.vertex = None

    def getBucket(self,he):
        bucket = int(((he.ystar - self.ymin) / self.deltay) * self.hashsize)
        if bucket < 0: bucket = 0
        if bucket >= self.hashsize: bucket = self.hashsize-1
        if bucket < self.minidx:  self.minidx = bucket
        return bucket

    def getMinPt(self):
        while(self.hash[self.minidx].qnext is None):
            self.minidx += 1
        he = self.hash[self.minidx].qnext
        x = he.vertex.x
        y = he.ystar
        return Site(x,y)

    def popMinHalfedge(self):
        curr = self.hash[self.minidx].qnext
        self.hash[self.minidx].qnext = curr.qnext
        self.count -= 1
        return curr



class SiteList(object):
    def __init__(self,pointList):
        self.__sites = []
        self.__sitenum = 0

        self.__xmin = pointList[0].x
        self.__ymin = pointList[0].y
        self.__xmax = pointList[0].x
        self.__ymax = pointList[0].y
        for i,pt in enumerate(pointList):
            self.__sites.append(Site(pt.x,pt.y,i))
            if pt.x < self.__xmin: self.__xmin = pt.x
            if pt.y < self.__ymin: self.__ymin = pt.y
            if pt.x > self.__xmax: self.__xmax = pt.x
            if pt.y > self.__ymax: self.__ymax = pt.y
        self.__sites.sort()

    def setSiteNumber(self,site):
        site.sitenum = self.__sitenum
        self.__sitenum += 1

    class Iterator(object):
        def __init__(this,lst):  this.generator = (s for s in lst)
        def __iter__(this):      return this
        def next(this): 
            try:
                return this.generator.next()
            except StopIteration:
                return None

    def iterator(self):
        return SiteList.Iterator(self.__sites)

    def __iter__(self):
        return SiteList.Iterator(self.__sites)

    def __len__(self):
        return len(self.__sites)

    def _getxmin(self): return self.__xmin
    def _getymin(self): return self.__ymin
    def _getxmax(self): return self.__xmax
    def _getymax(self): return self.__ymax
    xmin = property(_getxmin)
    ymin = property(_getymin)
    xmax = property(_getxmax)
    ymax = property(_getymax)



def computeVoronoiDiagram(points):
    """ Takes a list of point objects (which must have x and y fields).
        Returns a 3-tuple of:

           (1) a list of 2-tuples, which are the x,y coordinates of the 
               Voronoi diagram vertices
           (2) a list of 3-tuples (a,b,c) which are the equations of the
               lines in the Voronoi diagram: a*x + b*y = c
           (3) a list of 3-tuples, (l, v1, v2) representing edges of the 
               Voronoi diagram.  l is the index of the line, v1 and v2 are
               the indices of the vetices at the end of the edge.  If 
               v1 or v2 is -1, the line extends to infinity.
    """
    siteList = SiteList(points)
    context  = Context()
    voronoi(siteList,context)
    return (context.vertices,context.lines,context.edges)


def computeDelaunayTriangulation(points):
    """ Takes a list of point objects (which must have x and y fields).
        Returns a list of 3-tuples: the indices of the points that form a
        Delaunay triangle.
    """
    siteList = SiteList(points)
    context  = Context()
    context.triangulate = true
    voronoi(siteList,context)
    return context.triangles

def dist(p, v):
    return (p.x - v[0]) * (p.x - v[0]) + (p.y - v[1]) * (p.y - v[1])

def distp(p1, p2):
    return dist(p1, (p2.x, p2.y))

def modulo2pi(angle):
    return angle - 2 * math.pi * math.floor((angle + math.pi) / (2 * math.pi))


if __name__ == '__main__':
    Point = namedtuple('Point', ['x', 'y'])
    N = int(raw_input())
    l = []
    for _ in range(N):
        x, y = map(int, raw_input().split())
        l.append(Point(x, y))
    vor, _, _ = computeVoronoiDiagram(l)
    if not vor:
        print -1
    else:
        is_obtuse = True
        rv = sorted([min([(math.sqrt(dist(p, v)), v) for p in l]) for v in vor])
        rmin = 0
        r_collision = 0
        
        save = []
        while is_obtuse and rv:
            
            rmin, interesting_vor = rv.pop()
            interesting_points = sorted([p for p in l if abs(math.sqrt(dist(p, interesting_vor)) - rmin) < 1e-4], key=lambda p: math.atan2(p.y - interesting_vor[1], p.x - interesting_vor[0]))
            n = len(interesting_points)
            
            save.append((interesting_vor, interesting_points))
            r_collision = max([math.sqrt(distp(interesting_points[i], interesting_points[(i + 1) % n])) for i in range(n)]) / 2
            angles = map(lambda p: math.atan2(p.y - interesting_vor[1], p.x - interesting_vor[0]), interesting_points)
            
            is_obtuse = any([angles[i + 1] - angles[i] >= math.pi for i in range(n - 1)] + [angles[0] + 2 * math.pi - angles[-1] >= math.pi])
        
        if DRAW:
            with open('draw.tex', 'w') as f:
                for p in l:
                    f.write('\\filldraw[black] (%d,%d) circle (%e);\n' % (p.x, p.y, rmin))
                for p in l:
                    f.write('\\filldraw[white] (%d,%d) circle (2pt);\n' % (p.x, p.y))
                for iv, ip in save[2:3]:
                    f.write('\\filldraw[black] (%d,%d) circle (20pt);\n' % (iv[0], iv[1]))
                    f.write('\\draw[cyan]' + ' -- '.join('(%d,%d)' % (p.x, p.y) for p in ip) + ' -- cycle;\n')
                f.write('\\filldraw[yellow] (%d,%d) circle (2pt);\n' % (interesting_vor[0], interesting_vor[1]))
                for p in interesting_points:
                    f.write('\\filldraw[red] (%d,%d) circle (2pt);\n' % (p.x, p.y))
        if is_obtuse or rmin <= r_collision:
            print -1
        else:
            print rmin