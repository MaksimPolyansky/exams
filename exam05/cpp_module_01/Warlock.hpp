//
// Created by heusebio on 02.05.2021.
//

#ifndef CPP_MODULE_01_WARLOCK_HPP
#define CPP_MODULE_01_WARLOCK_HPP

#include "ATarget.hpp"
#include "ASpell.hpp"
#include <vector>

class Warlock
{
private:
    std::string name;
    std::string title;
    Warlock();
    Warlock(Warlock const &copy);
    Warlock &operator=(Warlock const &wa);
    std::vector<ASpell *> arr;
public:
    Warlock(std::string const &name, std::string const &title);
    ~Warlock();

    std::string const &getName() const;
    std::string const &getTitle() const;

    void setTitle(std::string const &title);

    void introduce() const;

    void learnSpell(ASpell const *as);
    void forgetSpell(std::string name);
    void launchSpell(std::string name, ATarget const &at);
};

#endif //CPP_MODULE_01_WARLOCK_HPP
