#ifndef _TABS_HH
#define _TABS_HH

#include "Boxy.hh"

class Tabs {
public:
  Tabs();
  Tabs( double kerf, double thick);
  ~Tabs();
  int drawTabs( Boxy* box, int ntabs, double len);
  void setKerf( double k);
  void setThick( double t);
  double getKerf();
  double getThick();
  static double kerf;
  static double thick;
  
private:
};

void tabbedSide( Boxy* b, double slen, double swid, 
		 int nt, int nr, int nb, int nl);
void tabbedInside( Boxy* b, double slen, double swid, 
		 int nt, int nr, int nb, int nl);

#endif
