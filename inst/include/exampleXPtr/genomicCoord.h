#ifndef _genomic_coord_
#define _genomic_coord_

#include <Rcpp.h>
#include <iostream>
#define NA_int -2147483648
using namespace Rcpp;

class genomicCoord {
public:
  int chr;
  int pos;
  genomicCoord() : chr(NA_int), pos(NA_int) {}
  genomicCoord(int c, int p) : chr(c), pos(p) {}
};

std::ostream& operator<<(std::ostream& ostr, genomicCoord x);

#endif
