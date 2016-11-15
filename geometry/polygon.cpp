
#include "./lines.cpp"
// We slaan veelhoeken op als een vector van punten in counterclockwise volgorde. Hierbij zetten we het eerste punt ook op het eind.
// VB: vector<pt> P: P.push_back(pt(1, 1)); P.push_back(pt(3, 3)); P.push_back(pt(1, 5)); P.push_back(P[0]) is een driehoek.
#include <vector>
using namespace std;
double omtrek(const vector<pt> &P) {
  double resultaat = 0.0;
  for (int i = 0; i < (int)P.size()-1; i++)
    resultaat += Dist(P[i], P[i+1]);
  return resultaat; }
// De oppervlakte is de helft van de determinant van aanliggende punten.
double oppervlakte(const vector<pt> &P) {
  double resultaat = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int)P.size()-1; i++) {
    resultaat += P[i]^P[i+1];
  }		return fabs(resultaat) / 2.0; }
// Een veelhoek is convex DESDA alle hoeken linksaf zijn (wanneer je ze tegen de klok in doorloopt).
bool isConvex(const vector<pt> &P) {
  int sz = (int)P.size();
  if (sz <= 3) return false;   // punten en lijnen (sz=2/3) zijn niet convex
  bool isLinks = ccw(P[0], P[1], P[2]);
  for (int i = 1; i < sz-1; i++)
    if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLinks)
      return false;
  return true; }
// Dit checkt of een punt binnen een veelhoek ligt door te checken of de som van de hoeken (linksaf positief en rechtsaf negatief) gelijk is aan 360 graden.
// Let op: Dit werkt ook voor niet-convexe veelhoeken, maar detecteert geen punten op de rand (voeg dus op lijnstukcheck toe als dit mogelijk is).
bool inVeelvlak(pt punt, const vector<pt> &P) {
  if ((int)P.size() == 0) return false;
  double som = 0;    // assume the first vertex is equal to the last vertex
  for (int i = 0; i < (int)P.size()-1; i++) {
    if (ccw(punt, P[i], P[i+1]))
         som += hoek(P[i], punt, P[i+1]);                   // left turn/ccw
    else som -= hoek(P[i], punt, P[i+1]); }                 // right turn/cw
  return fabs(fabs(som) - 2*acos(-1.0)) < EPS; }
