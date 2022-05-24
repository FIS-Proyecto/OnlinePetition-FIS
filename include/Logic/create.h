#ifndef __CREATE__
#define __CREATE__

#include <ctime>

#include "../DataBase/db.h"
#include "petition.h"
#include "user.h"

// Create function that creates a petition
void create_petit(account::user* user, const std::string& title, const std::string& description, const std::string& tags) {
  std::time_t t = std::time(0);
  std::tm* time = std::localtime(&t);

  std::string day = std::to_string(time->tm_mday);
  std::string month = (time->tm_mon + 1 < 10 ? "0" : "") + std::to_string(time->tm_mon + 1);
  std::string year = std::to_string(time->tm_year + 1900);
  std::string date = day + '/' + month + '/' + year;

  db::petition new_petition(title, 
                            description, 
                            user->data_.name_, 
                            user->data_.get_uid(),
                            date,
                            "0", 
                            tags);
  db::query::add_petition(new_petition);
}

#endif  // __CREATE__