#include "../../include/DataBase/db.h"
#include "../../include/Logic/login.h"
#include "../../include/Logic/search.h"

// Made by Adrian, ask him if you have any questions.
std::vector<block::petition_p> search_petit_by_name(const std::string& name) {
  std::vector<block::petition_p> returned_petitions_vec;
  for(auto& i : db::query::filter_petition(name)) {
    returned_petitions_vec.emplace_back(block::petition_p(i));
  }
  return returned_petitions_vec;
}

std::vector<block::petition_p> search_petit_by_tag(const std::string& tag) {
  std::vector<block::petition_p> returned_petitions_vec;
  for(auto& i : db::query::filter_petition(tag)) {
    returned_petitions_vec.emplace_back(block::petition_p(i));
  }
  return returned_petitions_vec;
}

std::vector<block::petition_p> show_five_petition(int n) {
  std::vector<block::petition_p> returned_petitions_vec;
  std::vector<block::petition_p> returned_petitions_vec_aux;
  for(auto& i : db::query::filter_petition(";")) {
    returned_petitions_vec.emplace_back(block::petition_p(i));
  }
  size_t n_ = static_cast<size_t>(n);
  if (n_ > returned_petitions_vec.size()) {
    n = 0;
  }
  int n_tpe = n+5;
  int i = n;
  for (; n < n_tpe; n++) {
    if (n  > returned_petitions_vec.size()) 
      i = 0;
    returned_petitions_vec_aux.emplace_back(returned_petitions_vec[i]);
    i++;
  }
  return returned_petitions_vec_aux;
}
