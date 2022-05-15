#ifndef PETITION_H
#define PETITION_H

#include "../DataBase/db.h"

// Petition class that contains the petition data

namespace block{
  class petition_p {
   public:
    petition_p();
    petition_p(db::petition data) {
      data_ = data;
    }

    db::petition data_;
  };
}


#endif