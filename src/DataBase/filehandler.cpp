
#include "db.h"

template<class Type_>
Type_ filehandler::get() {
  
}


filehandler::filehandler() {
  file_ = std::fstream(database, std::ios::in | std::ios::out | std::ios::binary);
}


