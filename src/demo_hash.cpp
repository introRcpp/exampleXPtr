#include <Rcpp.h>
#include "marker_hash.h"

using namespace Rcpp;

// [[Rcpp::export]]
IntegerVector f(std::string s) {
  markerHash A;
  A.insert( std::make_pair( "rs01", genomicCoord(1, 32) ) );
  A.insert( std::make_pair( "rs03", genomicCoord(3, 32) ) );
  A[ "rs04" ] = genomicCoord(3,45); // pour que ceci marche le constructeur genomicCoord() est indispensable !
  A[ "rs01" ] = genomicCoord(5,5);
  for(auto & x : A) {
    Rcout << x.first << " -> " << x.second << "\n";
  }
  Rcout << A["rs01"] << "\n";
  Rcout << A["rs07"] << "\n";
  auto sz = A.find(s);
  if(sz != A.end())
    Rcout << sz-> first << " -> " << sz->second << "\n";
  
  genomicCoord u = A[s];
  return IntegerVector::create(Named("chr") = u.chr, Named("pos") = u.pos);
}
