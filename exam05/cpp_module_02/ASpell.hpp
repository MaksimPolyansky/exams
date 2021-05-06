//
// Created by heusebio on 02.05.2021.
//

#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"
class ATarget;

class ASpell
{
private:
    std::string name;
    std::string effects;
public:
    ASpell();
    ASpell(std::string const &name, std::string const &effects);
    ASpell(ASpell const &copy);
    virtual ~ASpell();

    ASpell &operator=(ASpell const &as);

    std::string getName() const;
    std::string getEffects() const;

    void launch(ATarget const &at) const;

    virtual ASpell *clone() const = 0;
};

#endif //ASPELL_HPP
