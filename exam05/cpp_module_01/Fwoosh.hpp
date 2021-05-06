//
// Created by heusebio on 02.05.2021.
//

#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh: public ASpell
{
public:
    Fwoosh();
    ~Fwoosh();

    virtual ASpell *clone() const;
};

#endif //FWOOSH_HPP
