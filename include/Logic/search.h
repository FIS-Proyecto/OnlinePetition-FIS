#ifndef __SEARCH__
#define __SEARCH__

#include <vector>

#include "petition.h"

// Search function that returns a vector of petitions based on the petition name
std::vector<block::petition_p> search_petit_by_name(const std::string&);

// Search function that returns a vector of petitions based on the petition tag
std::vector<block::petition_p> search_petit_by_tag(const std::string&);

// Search function that returns a vector of petitions based on the petition title
std::vector<block::petition_p> show_five_petition(int);


#endif // __SEARCH__