//
// Created by heusebio on 02.05.2021.
//

#include "ASpell.hpp"

ASpell::ASpell() {}
ASpell::ASpell(std::string const &name, std::string const &effects)
{
    this->name = name;
    this->effects = effects;
}
ASpell::ASpell(ASpell const &copy) { *this = copy; }
ASpell::~ASpell() {}

ASpell &ASpell::operator=(ASpell const &as)
{
    this->name = as.name;
    this->effects = as.effects;
    return *this;
}

std::string ASpell::getName() const { return this->name; }
std::string ASpell::getEffects() const { return this->effects; }

void ASpell::launch(ATarget const &at) const { at.getHitBySpell(*this); }