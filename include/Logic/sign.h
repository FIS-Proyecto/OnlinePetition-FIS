#ifndef __SIGN__
#define __SIGN__

#include "petition.h"
#include "user.h"

// Sign function that signs a petition
void sign_petit(block::petition_p& petition) {
  int current_sign = std::stoi(petition.data_.nSigns_);
  petition.data_.nSigns_ = std::to_string(current_sign + 1);
  db::query::edit_petition(petition.data_.get_pid(), db_edit::petition({
    n_signs(petition.data_.nSigns_),
  }));
}

#endif  // __SIGN__