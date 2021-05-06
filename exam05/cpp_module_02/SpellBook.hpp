//
// Created by heusebio on 02.05.2021.
//

#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <vector>

class SpellBook
{
private:
    std::vector<ASpell *> arr;
public:
    SpellBook();
    SpellBook(SpellBook const &copy);
    ~SpellBook();

    SpellBook &operator=(SpellBook const &sp);

    void learnSpell(ASpell *as);
    void forgetSpell(std::string const &name);
    ASpell* createSpell(std::string const &name);
};


#endif //SPELLBOOK_HPP
