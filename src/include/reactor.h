#ifndef MSGMAP_REACTOR_H
#define MSGMAP_REACTOR_H

#include <map>
#include <string>

typedef int (*reactor_func_t)(int argc, ...);

class reactor
{
private:
    std::map < std::string, reactor_func_t > reactor_map;

public:
};


#endif //MSGMAP_REACTOR_H
