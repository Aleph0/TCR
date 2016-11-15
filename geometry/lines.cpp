
#include <math.h>
#include "./points.cpp"
double EPS = 0.00000001;
// We definieren een lijn met ax+by+c=0. Daarbij kiezen we b = 1 als b != 0.
struct line { double a, b, c; };
// Het initialiseren van de lijn kan met de volgende functie:
line pttoline(pt p1, pt p2) 
{ 	line l;
	if (fabs(p1.x - p2.x) < EPS) { l.a = 1.0; l.b = 0.0; l.c = -p1.x; }
	else { l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x); l.b = 1.0; l.c = -(double)(l.a * p1.x) - p1.y;}
	return l;
}	// Parallelcheck:
bool zijnParallel(line l1, line l2) { 
	return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }
// Snijpunten + check (let op: return ook false als lijnen hetzelfde zijn!)
bool snijpunten(line l1, line l2, pt &p) { // in &p komt het snijpunt.
  if (zijnParallel(l1, l2)) return false;
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
  else                  p.y = -(l2.a * p.x + l2.c); // Line 1 is verticaal!
  return true; }

// Voor verplaatsen van lijnstukken en afstandberekeningen zijn vectoren handig.
struct vec { double x, y; 
	vec(double _x, double _y) : x(_x), y(_y) {} 
	NUM operator*(const vec &rhs) const {return x * rhs.x + y * rhs.y;}
	NUM operator^(const vec &rhs) const {return x * rhs.y - y * rhs.x;}
	NUM lensq() const { return x*x + y*y;}
};
vec verschilvector(pt a, pt b) { return vec(b.x - a.x, b.y - a.y); }
vec schalen(vec v, double s) { return vec(v.x * s, v.y * s); } 
pt verplaatsen(pt p, vec v) { return pt(p.x + v.x , p.y + v.y); }

// Afstand tussen een punt en een lijn bepalen.
double afstandTotLijn(pt p, pt a, pt b, pt &c) {
  vec ap = verschilvector(a, p), ab = verschilvector(a, b);
  double u = (ap * ab) / ab.lensq();
  c = verplaatsen(a, schalen(ab, u));
  return sqrt((p-c).len()); }
 // In het geval dat we de afstand tot lijnsegment ab willen: als u < 0 is de afstand |ap| en als u > 1 dan is de afstand |bp|.

double hoek(pt a, pt o, pt b) {  // geeft hoek aob in radialen.
  vec oa = verschilvector(o, a), ob = verschilvector(o, b);
  return acos(oa * ob / sqrt(oa.lensq() * ob.lensq())); }
// Onderstaande test of lopen van p -> q -> r een hoek naar links is (counterclockwise). Als < EPS is het een check of p,q,r collinear zijn.
 bool ccw(pt p, pt q, pt r) {
  return (verschilvector(p, q) ^ verschilvector(p, r)) > 0; }