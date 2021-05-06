//
// Created by heusebio on 03.05.2021.
//

#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <vector>

class TargetGenerator
{
private:
    std::vector<ATarget *> arr;
public:
    TargetGenerator();
    TargetGenerator(TargetGenerator const &copy);
    ~TargetGenerator();

    TargetGenerator &operator=(TargetGenerator const &ta);

    void learnTargetType(ATarget *at);
    void forgetTargetType(std::string const &name);
    ATarget* createTarget(std::string const &name);
};


#endif //TARGETGENERATOR_HPP
