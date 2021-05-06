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

void Warlock::learnSpell(ASpell *as)
{
    book.learnSpell(as);
}
void Warlock::forgetSpell(std::string name)
{
    book.forgetSpell(name);
}
void Warlock::launchSpell(std::string name, ATarget const &at)
{
    ASpell *t1 = book.createSpell(name);
    if (t1)
        t1->launch(at);
}