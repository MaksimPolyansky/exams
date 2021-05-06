//
// Created by heusebio on 02.05.2021.
//

#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed"){}
Fwoosh::~Fwoosh() {}

ASpell *Fwoosh::clone() const { return new Fwoosh(); }