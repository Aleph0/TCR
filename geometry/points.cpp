#include <math.h> // Nodig voor sinus en cosins
typedef double NUM; // double of long long

struct pt { NUM x, y; // Maak punt door pt var = pt(x,y) 
	pt() { x = y = 0; }	
	pt(NUM _x, NUM _y) : x(_x), y(_y) {} 
// Definieer operaties: scalar (*), inproduct (*), 2D-uitproduct (^)
	pt operator*(NUM scalar) const {return pt(scalar * x, scalar * y);}
	NUM operator*(const pt &rhs) const {return x * rhs.x + y * rhs.y;}
	NUM operator^(const pt &rhs) const {return x * rhs.y - y * rhs.y;}
	pt operator+(const pt &rhs) const{return pt(x + rhs.x, y + rhs.y);}
	pt operator-(const pt &rhs) const{return pt(x - rhs.x, y - rhs.y);}
	NUM lensq() const { return x*x + y*y; }		// Lengte van lijn in kwadraat.
	NUM len() const { return sqrt(lensq()); }
// Als Num = double moeten onderstaande operatoren met fabs(x-rhs.x) < EPS.
	bool operator==(const pt &rhs) const{return x == rhs.x && y == rhs.y;}
	bool operator!=(const pt &rhs) const{return x != rhs.x || y != rhs.y;}
	bool operator<(const pt &rhs) const{ // Handig voor sorteren.
		if (x != rhs.x) return x < rhs.x; return y < rhs.y;}
};
NUM sqDist(const pt &a, const pt &b) {return (b-a).lensq();}
NUM Dist(const pt &a, const pt &b) {return (b-a).len();}

pt rotate(pt p, double theta) {	 //	draait punt tegen de klok in rond (0,0).
double rad = (theta) * acos(-1.0) / 180.0; 	// mits theta in graden.
return pt(p.x * cos(rad) - p.y * sin(rad),
			 p.x * sin(rad) + p.y * cos(rad)); }
// Als je punt b rond punt a wilt draaien: rotate( b - a, theta) + a

struct poolpt { double r, phi;	// Poolcoordinaten!!
	poolpt() {r = phi = 0;}
	poolpt(double _r, double _phi) : r(_r), phi(_phi) {} 	
};
poolpt car_to_pool(pt p) { return poolpt(p.len(), atan2(p.y,p.x)); }
pt pool_to_car(poolpt p) { return pt(p.r * cos(p.phi), p.r * sin(p.phi));}
