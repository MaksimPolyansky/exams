//
// Created by heusebio on 03.05.2021.
//

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::TargetGenerator(TargetGenerator const &copy) { *this = copy; }
TargetGenerator::~TargetGenerator() {}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &ta)
{
    this->arr = ta.arr;
    return *this;
}

void TargetGenerator::learnTargetType(ATarget *at)
{
    std::vector<ATarget *>::iterator i_b = this->arr.begin();
    std::vector<ATarget *>::iterator i_e = this->arr.end();

    if (at)
    {
        for (; i_b != i_e; i_b++)
        {
            if ((*i_b)->getType() == at->getType())
                return;
        }
        this->arr.push_back(at->clone());
    }
}
void TargetGenerator::forgetTargetType(std::string const &name)
{
    std::vector<ATarget *>::iterator i_b = this->arr.begin();
    std::vector<ATarget *>::iterator i_e = this->arr.end();

    for (; i_b != i_e; i_b++)
    {
        if ((*i_b)->getType() == name)
        {
            delete *i_b;
            this->arr.erase(i_b);
            return;
        }
    }
}
ATarget *TargetGenerator::createTarget(std::string const &name)
{
    std::vector<ATarget *>::iterator i_b = this->arr.begin();
    std::vector<ATarget *>::iterator i_e = this->arr.end();

    for (; i_b != i_e; i_b++)
    {
        if ((*i_b)->getType() == name)
            return (*i_b);
    }
    return (NULL);
}