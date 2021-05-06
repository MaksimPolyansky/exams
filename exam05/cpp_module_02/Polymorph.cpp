//
// Created by heusebio on 02.05.2021.
//

#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into critter") {}
Polymorph::~Polymorph() {}

ASpell *Polymorph::clone() const { return new Polymorph(); }