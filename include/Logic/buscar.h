#ifndef BUSCAR_H
#define BUSCAR_H

#include "petition.h"


#include <vector>
// Search function that returns a vector of petitions based on the petition name
std::vector<block::petition_p> search_petit_by_name(const std::string&);
// Search function that returns a vector of petitions based on the petition tag
std::vector<block::petition_p> search_petit_by_tag(const std::string&);
// Search function that returns a vector of petitions based on the petition title
std::vector<block::petition_p> show_five_petition(int);


#endif // BUSCAR_H