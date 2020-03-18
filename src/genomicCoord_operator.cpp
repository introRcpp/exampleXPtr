#include "genomicCoord.h"

std::ostream& operator<<(std::ostream& ostr, genomicCoord x) {
  return ostr << x.chr << ":" << x.pos;
}
