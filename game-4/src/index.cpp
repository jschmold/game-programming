#include <iostream>

#include "entities/entities.h"

using namespace std;
using namespace Game4::Entities;

int main(int argc, char* argv[])
{
    World world;
    Player* ply = new Player();
    ply->addToWorld(world);


    cout << "Hello World";
    return 0;
}
