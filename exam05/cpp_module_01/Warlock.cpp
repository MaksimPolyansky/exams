//
// Created by heusebio on 02.05.2021.
//

#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
    this->name = name;
    this->title = title;
    std::cout << this->getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() { std::cout << this->getName() << ": My job here is done!" << std::endl; }

std::string const &Warlock::getName() const { return this->name; }
std::string const &Warlock::getTitle() const { return this->title; }

void Warlock::setTitle(std::string const &title) { this->title = title; }

void Warlock::introduce() const
{
    std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
}

void Warlock::learnSpell(ASpell const *as)
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
void Warlock::forgetSpell(std::string name)
{
    std::vector<ASpell *>::iterator i_b = this->arr.begin();
    std::vector<ASpell *>::iterator i_e = this->arr.end();

    for (; i_b != i_e; i_b++)
    {
        if ((*i_b)->getName() == name)
        {
            delete *i_b;
            this->arr.erase(i_b);
            return;
        }
    }
}
void Warlock::launchSpell(std::string name, ATarget const &at)
{
    std::vector<ASpell *>::iterator i_b = this->arr.begin();
    std::vector<ASpell *>::iterator i_e = this->arr.end();

    for (; i_b != i_e; i_b++)
    {
        if ((*i_b)->getName() == name)
        {
            (*i_b)->launch(at);
            return;
        }
    }
}
