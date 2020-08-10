#include "Includes.h"

#ifndef UTILS_H
#define UTILS_H

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) 
{
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}

class Utils {
    public:
};

#endif