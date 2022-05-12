#ifndef BUSCAR_H
#define BUSCAR_H

#include "petition.h"


#include <vector>

std::vector<block::petition_p> search_petit_by_name(const std::string&);

std::vector<block::petition_p> search_petit_by_tag(const std::string&);

std::vector<block::petition_p> show_five_petition(int);


#endif // BUSCAR_H