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
    friend std::ostream& operator<<(std::ostream& os, const petition_p& petition) {
      os << petition.data_.title_ << "\t\tMade by: " << petition.data_.author_ << "\tTags: " << petition.data_.tags_ << "\n\n";
      std::stringstream ss_desc(petition.data_.description_);
      std::string word, line, final_line;
      size_t space_count = 0;
      while (std::getline(ss_desc, word, ' ')) {
        if (space_count >= 6) {
          final_line += line + "\n";
          line.clear();
          space_count = 0;
        }
        line += word + " ";
        space_count++;
      }
      if(final_line.find(line) == std::string::npos) {
        final_line += line;
      }
      os << final_line << "\n\n";
      os << "Votes: " << petition.data_.nSigns_ << "\n";
      os << "Date: " << petition.data_.date_ << "\n\n";
      return os;
    }

    db::petition data_;
  };
}


#endif