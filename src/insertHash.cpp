#include <Rcpp.h>
#include "marker_hash.h"
using namespace Rcpp;

//[[Rcpp::export]]
void insertHash(XPtr<markerHash> a, CharacterVector name, IntegerVector chr, IntegerVector pos) {
  int n = chr.size();
  for(int i = 0; i < n; i++) {
    (*a)[CHAR(name[i])] = genomicCoord(chr[i], pos[i]);
  }
}