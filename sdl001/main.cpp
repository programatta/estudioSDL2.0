#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    Game game;
    int result = game.start();
    if( result != 0 )
        cout << "Algo fue mal en la inicialización!" << endl;
    return result;
}
