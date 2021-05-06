//
// Created by heusebio on 02.05.2021.
//

#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}
Dummy::~Dummy() {}

ATarget *Dummy::clone() const { return new Dummy(); }