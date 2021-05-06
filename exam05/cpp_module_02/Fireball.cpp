//
// Created by heusebio on 02.05.2021.
//

#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}
Fireball::~Fireball() {}

ASpell *Fireball::clone() const { return new Fireball(); }