#ifndef PETITION_H
#define PETITION_H

#include "../DataBase/db.h"

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