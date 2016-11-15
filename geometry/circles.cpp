
// Een koorde in een cirkel die middelpuntshoek alpha heeft, 
// heeft lengte 2 * r * sin(alpha/2).
#include "./lines.cpp"
// 0 (in cirkel, 1 op rand, 2 erbuiten)
int binnenCirkel(pt p, pt c, NUM r) {
  NUM dx = p.x - c.x, dy = p.y - c.y;
  NUM Euc = dx * dx + dy * dy, rSq = r * r; 
  return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; } // Als double gebruik <EPS

bool vindMiddelpunt(pt p1, pt p2, double r, pt &c) {
  double d2 = sqDist(p1, p2);	
  double det = r * r / d2 - 0.25;
  if (det < 0.0) return false; // Geen oplossing als afstand > 2R.
  c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * sqrt(det);
  c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * sqrt(det);
  return true; } // ander middelpunt krijg je door p2 en p1 om te draaien.
// De inCircle vindt de ingeschreven cirkel.
double rInCircle(double ab, double bc, double ca) {
	return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca)); }
double rInCircle(pt a, pt b, pt c) {
  return rInCircle(Dist(a, b), Dist(b, c), Dist(c, a)); }
int inCircle(pt p1, pt p2, pt p3, pt &ctr, double &r) {
  r = rInCircle(p1, p2, p3);
  if (fabs(r) < EPS) return 0; // Geen ingeschreven cirkel
  line l1, l2; // De ingeschreven cirkel is het snijpunt van bisectrices.
  double ratio = Dist(p1, p2) / Dist(p1, p3);
  pt p = verplaatsen(p2, schalen(verschilvector(p2, p3), ratio / (1 + ratio)));
  l1 = pttoline(p1, p);

  ratio = Dist(p2, p1) / Dist(p2, p3);
  p = verplaatsen(p1, schalen(verschilvector(p1, p3), ratio / (1 + ratio)));
  l2 = pttoline(p2, p);

  snijpunten(l1, l2, ctr);           // get their intersection point
}