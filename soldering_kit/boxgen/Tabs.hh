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
  double getKerf();

private:
  double kerf;
  double thick;
  
};



#endif
