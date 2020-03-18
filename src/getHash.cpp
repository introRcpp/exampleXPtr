#include <Rcpp.h>
#include "marker_hash.h"
using namespace Rcpp;


//[[Rcpp::export]]
List getHash(XPtr<markerHash> a, CharacterVector name) {
  int n = name.size();
  IntegerVector chr = no_init(n);
  IntegerVector pos = no_init(n);
  for(int i = 0; i < n; i++) {
    if( (*a).count(CHAR(name[i])) > 0) {
      genomicCoord gc = (*a)[ CHAR(name[i]) ];
      chr[i] = gc.chr;
      pos[i] = gc.pos;
    } else {
      chr[i] = NA_int;
      pos[i] = NA_int;
    }
  }
  List L;
  L["name"] = name;
  L["chr"] = chr;
  L["pos"] = pos;
  return L;
}
