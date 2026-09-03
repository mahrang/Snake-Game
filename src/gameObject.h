#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <thread>

class GameObject
{
 public:
    //  destructor
    ~GameObject();
    
protected:
    std::vector<std::thread> threads;
};

#endif