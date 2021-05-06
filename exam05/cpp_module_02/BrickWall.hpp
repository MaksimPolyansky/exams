//
// Created by heusebio on 02.05.2021.
//

#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall : public ATarget
{
public:
    BrickWall();
    ~BrickWall();

    virtual ATarget *clone() const;
};


#endif //BRICKWALL_HPP
