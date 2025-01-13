
#include <cstdio>
#include "Boxy.hh"

int main( int argc, char *argv[]) {
  Boxy b(10000);
  b.draw( 100, 100);
  b.rotate( 90);
  b.drawr( 10, 0);
  b.drawr( 0, 10);
  b.drawr( -10, 0);
  b.drawr( 0, -10);
  b.print();
}
