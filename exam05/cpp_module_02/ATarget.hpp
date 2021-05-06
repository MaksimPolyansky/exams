//
// Created by heusebio on 02.05.2021.
//

#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "ASpell.hpp"
class ASpell;

class ATarget
{
private:
    std::string type;
public:
    ATarget();
    ATarget(std::string const &type);
    ATarget(ATarget const &copy);
    virtual ~ATarget();

    ATarget &operator=(ATarget const &at);

    std::string const &getType() const;

    void getHitBySpell(ASpell const &as) const;

    virtual ATarget *clone() const = 0;
};

#endif //ATARGET_HPP
