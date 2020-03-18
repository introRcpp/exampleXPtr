#include <Rcpp.h>
#include "marker_hash.h"
using namespace Rcpp;

//[[Rcpp::export]]
XPtr<markerHash> newHash() {
  markerHash * a (new markerHash);
  XPtr<markerHash> p(a, true);
  return p;
}

