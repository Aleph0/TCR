
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
// Wanneer je drie punten hebt, kun je de cirkel door deze punten vinden door eerst de straal te berekenen met Dist(p1,p2) * Dist(p2,p3) * Dist(p3,p1) / (4 * oppDriehoek(p1,p2,p3)) en dan het juiste middelpunt te nemen.