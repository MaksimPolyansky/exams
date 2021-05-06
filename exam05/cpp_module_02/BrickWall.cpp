//
// Created by heusebio on 02.05.2021.
//

#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}
BrickWall::~BrickWall() {}

ATarget *BrickWall::clone() const { return new BrickWall(); }
