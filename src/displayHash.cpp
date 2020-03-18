#include <Rcpp.h>
#include "marker_hash.h"
using namespace Rcpp;

//[[Rcpp::export]]
void displayHash(XPtr<markerHash> a) {
  for(auto & x : *a) {
    Rcout << x.first << " -> " << x.second << "\n";
  }
}