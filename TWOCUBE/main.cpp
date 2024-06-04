#include <iostream>
#include "TwoCube.hpp"

using namespace std;


Sides intToside(int x)
{
    switch(x)
    {
        case 0 : return Sides::FRONT;
        case 1 : return Sides::BACK;
        case 2 : return Sides::LEFT;
        case 3 : return Sides::RIGHT;
        case 4 : return Sides::TOP;
        case 5 : return Sides::BOTTOM;
    }
}
void testTwoCube()
{
    vector<Color> blue = {Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE};
    vector<Color> green = {Color::GREEN,Color::GREEN,Color::GREEN,Color::GREEN};
    vector<Color> orange = {Color::ORANGE,Color::ORANGE,Color::ORANGE,Color::ORANGE};
    vector<Color> red = {Color::RED,Color::RED,Color::RED,Color::RED};
    vector<Color> white = {Color::WHITE,Color::WHITE,Color::WHITE,Color::WHITE};
    vector<Color> yellow = {Color::YELLOW,Color::YELLOW,Color::YELLOW,Color::YELLOW};
    unordered_map<Sides,vector<Color>> cube;
    cube[Sides::FRONT] = green;
    cube[Sides::BACK] = blue;
    cube[Sides::TOP] = white;
    cube[Sides::BOTTOM] = yellow;
    cube[Sides::LEFT] = orange;
    cube[Sides::RIGHT] = red;
    
    


    TwoCube one(cube);
    one.print();
    auto x = one.next_state(Turns::TOP_LEFT);
    x.print();
    
    
    
    
    

}
int main()
{
    int a;
    cout << "Hello World " << endl;
    cout << "\n" << endl;
    testTwoCube();
    return 0;
} 