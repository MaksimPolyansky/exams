//
// Created by heusebio on 02.05.2021.
//

#include "ATarget.hpp"

ATarget::ATarget() {}
ATarget::ATarget(std::string const &type) { this->type = type; }
ATarget::ATarget(ATarget const &copy) { *this = copy; }
ATarget::~ATarget() {}

ATarget &ATarget::operator=(ATarget const &at)
{
    this->type = at.type;
    return *this;
}

std::string const &ATarget::getType() const { return this->type; }

void ATarget::getHitBySpell(const ASpell &as) const { std::cout << this->getType() << " has been " << as.getEffects() << std::endl; }