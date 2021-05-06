//
// Created by heusebio on 02.05.2021.
//

#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::SpellBook(SpellBook const &copy) { *this = copy; }
SpellBook::~SpellBook() {}

SpellBook &SpellBook::operator=(SpellBook const &sp)
{
    this->arr = sp.arr;
    return *this;
}

void SpellBook::learnSpell(ASpell *as)
{
    std::vector<ASpell *>::iterator i_b = this->arr.begin();
    std::vector<ASpell *>::iterator i_e = this->arr.end();

    if (as)
    {
        for (; i_b != i_e; i_b++)
        {
            if ((*i_b)->getName() == as->getName())
                return;
        }
        this->arr.push_back(as->clone());
    }
}
void SpellBook::forgetSpell(std::string const &name)
{
    std::vector<ASpell *>::iterator i_b = this->arr.begin();
    std::vector<ASpell *>::iterator i_e = this->arr.end();

    for (; i_b != i_e; i_b++)
    {
        if ((*i_b)->getName() == name)
        {
            delete *i_b;
            this->arr.erase(i_b);
            return;;
        }
    }
}
ASpell *SpellBook::createSpell(std::string const &name)
{
    std::vector<ASpell *>::iterator i_b = this->arr.begin();
    std::vector<ASpell *>::iterator i_e = this->arr.end();

    for (; i_b != i_e; i_b++)
    {
        if ((*i_b)->getName() == name)
            return (*i_b);
    }
    return NULL;
}