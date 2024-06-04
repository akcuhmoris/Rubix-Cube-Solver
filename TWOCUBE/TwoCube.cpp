#include "TwoCube.hpp"


TwoCube::TwoCube()
{
    sides[Sides::TOP] = {Color::WHITE,Color::WHITE,Color::WHITE,Color::WHITE};
    sides[Sides::BOTTOM] = {Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE};
    sides[Sides::RIGHT] = {Color::RED,Color::RED,Color::RED,Color::RED};
    sides[Sides::LEFT] = {Color::ORANGE,Color::ORANGE,Color::ORANGE,Color::ORANGE};
    sides[Sides::BACK] = {Color::YELLOW,Color::YELLOW,Color::YELLOW,Color::YELLOW};
    sides[Sides::FRONT] = {Color::GREEN,Color::GREEN,Color::GREEN,Color::GREEN};
    decidedTurn = "START";
}
TwoCube::TwoCube(std::unordered_map<Sides,std::vector<Color>> Tsides)
{
    sides[Sides::TOP] = Tsides[Sides::TOP];
    sides[Sides::BOTTOM] = Tsides[Sides::BOTTOM];
    sides[Sides::RIGHT] = Tsides[Sides::RIGHT];
    sides[Sides::BACK] = Tsides[Sides::BACK];
    sides[Sides::LEFT] = Tsides[Sides::LEFT];
    sides[Sides::FRONT] = Tsides[Sides::FRONT];
    decidedTurn = "START";
}
TwoCube::TwoCube(const TwoCube &other)
{
    sides = other.sides;
    sCheck = other.sCheck;
    decidedTurn = other.decidedTurn;
}
bool TwoCube::sideSolved(Sides side)
{
    for(int x = 0;x < 4;x++)
    {
        if(sides[side][0] != sides[side][x])
        {
            sCheck[side] = false;
            return false;
        }      
    }
    return true;
}
bool TwoCube::isSolved()
{
    std::vector<Sides> c = {Sides::TOP,Sides::BOTTOM,Sides::RIGHT,Sides::LEFT,Sides::BACK,Sides::FRONT};
    for(int x = 0;x < 6;x++)
    {
        if(!sideSolved(c[x]))
            return false;
    }
    return true;
}
std::string TwoCube::sidetoString(Sides side)
{
    switch(side){
        case Sides::FRONT: return "FRONT";
        case Sides::LEFT: return "LEFT";
        case Sides::BACK: return "BACK";
        case Sides::RIGHT: return "RIGHT";
        case Sides::TOP: return "TOP";
        case Sides::BOTTOM: return "BOTTOM";
    }
}
std::string TwoCube::colortoString(Color color)
{
    switch(color)
    {
        case Color::WHITE: return "WHITE";
        case Color::YELLOW: return "YELLOW";
        case Color::BLUE: return "BLUE";
        case Color::GREEN: return "GREEN";
        case Color::RED: return "RED";
        case Color::ORANGE: return "ORANGE";
    }
}
std::string TwoCube::colorsPerSide(std::vector<Color> colors)
{
    std::string s = "";
    for(int x = 0;x < 4;x++)
    {
        s = s + colortoString(colors[x]) + ", ";
    }
    s.resize(s.size()-2);
    return s;
}
void TwoCube::print()
{
    std::cout << decidedTurn << std::endl;
    std::cout << sidetoString(Sides::FRONT) << ": " << colorsPerSide(sides[Sides::FRONT]) << std::endl;
    std::cout << sidetoString(Sides::LEFT) << ": " << colorsPerSide(sides[Sides::LEFT]) << std::endl;
    std::cout << sidetoString(Sides::BACK) << ": " << colorsPerSide(sides[Sides::BACK]) << std::endl;
    std::cout << sidetoString(Sides::RIGHT) << ": " << colorsPerSide(sides[Sides::RIGHT]) << std::endl;
    std::cout << sidetoString(Sides::TOP) << ": " << colorsPerSide(sides[Sides::TOP]) << std::endl;
    std::cout << sidetoString(Sides::BOTTOM) << ": " << colorsPerSide(sides[Sides::BOTTOM]) << std::endl;
    
}
std::unordered_map<Sides,std::vector<Color>> TwoCube::getSides()
{
    return sides;
}
TwoCube TwoCube::next_state(Turns turn)
{
    TwoCube n(*this);
    if(turn == Turns::TOP_LEFT)
    {
        n.sides[Sides::LEFT][0] = sides[Sides::FRONT][0];
        n.sides[Sides::LEFT][1] = sides[Sides::FRONT][1];
        n.sides[Sides::BACK][0] = sides[Sides::LEFT][0];
        n.sides[Sides::BACK][1] = sides[Sides::LEFT][1];
        n.sides[Sides::RIGHT][0] = sides[Sides::BACK][0];
        n.sides[Sides::RIGHT][1] = sides[Sides::BACK][1];
        n.sides[Sides::FRONT][0] = sides[Sides::RIGHT][0];
        n.sides[Sides::FRONT][1] = sides[Sides::RIGHT][1];
        n.sides[Sides::TOP][0] = sides[Sides::TOP][3];
        n.sides[Sides::TOP][1] = sides[Sides::TOP][0];
        n.sides[Sides::TOP][2] = sides[Sides::TOP][1];
        n.sides[Sides::TOP][3] = sides[Sides::TOP][2];
        n.decidedTurn = "TOP_LEFT";

    }
    else if(turn == Turns::TOP_RIGHT)
    {
        n.sides[Sides::LEFT][0] = sides[Sides::BACK][0];
        n.sides[Sides::LEFT][1] = sides[Sides::BACK][1];
        n.sides[Sides::BACK][0] = sides[Sides::RIGHT][0];
        n.sides[Sides::BACK][1] = sides[Sides::RIGHT][1];
        n.sides[Sides::RIGHT][0] = sides[Sides::FRONT][0];
        n.sides[Sides::RIGHT][1] = sides[Sides::FRONT][1];
        n.sides[Sides::FRONT][0] = sides[Sides::LEFT][0];
        n.sides[Sides::FRONT][1] = sides[Sides::LEFT][1];
        n.sides[Sides::TOP][0] = sides[Sides::TOP][1];
        n.sides[Sides::TOP][1] = sides[Sides::TOP][2];
        n.sides[Sides::TOP][2] = sides[Sides::TOP][3];
        n.sides[Sides::TOP][3] = sides[Sides::TOP][0];
        n.decidedTurn = "TOP_RIGHT";
    }
    else if(turn == Turns::DOWN_LEFT)
    {
        n.sides[Sides::LEFT][2] = sides[Sides::FRONT][2];
        n.sides[Sides::LEFT][3] = sides[Sides::FRONT][3];
        n.sides[Sides::BACK][2] = sides[Sides::LEFT][2];
        n.sides[Sides::BACK][3] = sides[Sides::LEFT][3];
        n.sides[Sides::RIGHT][2] = sides[Sides::BACK][2];
        n.sides[Sides::RIGHT][3] = sides[Sides::BACK][3];
        n.sides[Sides::FRONT][2] = sides[Sides::RIGHT][2];
        n.sides[Sides::FRONT][3] = sides[Sides::RIGHT][3];
        n.sides[Sides::BOTTOM][0] = sides[Sides::BOTTOM][1];
        n.sides[Sides::BOTTOM][1] = sides[Sides::BOTTOM][2];
        n.sides[Sides::BOTTOM][2] = sides[Sides::BOTTOM][3];
        n.sides[Sides::BOTTOM][3] = sides[Sides::BOTTOM][0];
        n.decidedTurn = "DOWN_LEFT";
    }
    else if(turn == Turns::DOWN_RIGHT)
    {
        n.sides[Sides::LEFT][2] = sides[Sides::BACK][2];
        n.sides[Sides::LEFT][3] = sides[Sides::BACK][3];
        n.sides[Sides::BACK][2] = sides[Sides::RIGHT][2];
        n.sides[Sides::BACK][3] = sides[Sides::RIGHT][3];
        n.sides[Sides::RIGHT][2] = sides[Sides::FRONT][2];
        n.sides[Sides::RIGHT][3] = sides[Sides::FRONT][3];
        n.sides[Sides::FRONT][2] = sides[Sides::LEFT][2];
        n.sides[Sides::FRONT][3] = sides[Sides::LEFT][3];
        n.sides[Sides::BOTTOM][0] = sides[Sides::BOTTOM][3];
        n.sides[Sides::BOTTOM][1] = sides[Sides::BOTTOM][0];
        n.sides[Sides::BOTTOM][2] = sides[Sides::BOTTOM][1];
        n.sides[Sides::BOTTOM][3] = sides[Sides::BOTTOM][2];
        n.decidedTurn = "DOWN_RIGHT";
    }
    else if(turn == Turns::RIGHT_UP)
    {
        n.sides[Sides::FRONT][1] = sides[Sides::BOTTOM][1];
        n.sides[Sides::FRONT][2] = sides[Sides::BOTTOM][2];
        n.sides[Sides::TOP][1] = sides[Sides::FRONT][1];
        n.sides[Sides::TOP][2] = sides[Sides::FRONT][2];
        n.sides[Sides::BACK][0] = sides[Sides::TOP][2];
        n.sides[Sides::BACK][3] = sides[Sides::TOP][1];
        n.sides[Sides::BOTTOM][1] = sides[Sides::BACK][3];
        n.sides[Sides::BOTTOM][2] = sides[Sides::BACK][0];
        n.sides[Sides::RIGHT][0] = sides[Sides::RIGHT][3];
        n.sides[Sides::RIGHT][1] = sides[Sides::RIGHT][0];
        n.sides[Sides::RIGHT][2] = sides[Sides::RIGHT][1];
        n.sides[Sides::RIGHT][3] = sides[Sides::RIGHT][2];
        n.decidedTurn = "RIGHT_UP";      
    }
    else if(turn == Turns::RIGHT_DOWN)
    {
        n.sides[Sides::FRONT][1] = sides[Sides::TOP][1];
        n.sides[Sides::FRONT][2] = sides[Sides::TOP][2];
        n.sides[Sides::TOP][1] = sides[Sides::BACK][3];
        n.sides[Sides::TOP][2] = sides[Sides::BACK][0];
        n.sides[Sides::BACK][0] = sides[Sides::BOTTOM][2];
        n.sides[Sides::BACK][3] = sides[Sides::BOTTOM][1];
        n.sides[Sides::BOTTOM][1] = sides[Sides::FRONT][1];
        n.sides[Sides::BOTTOM][2] = sides[Sides::FRONT][2];
        n.sides[Sides::RIGHT][0] = sides[Sides::RIGHT][1];
        n.sides[Sides::RIGHT][1] = sides[Sides::RIGHT][2];
        n.sides[Sides::RIGHT][2] = sides[Sides::RIGHT][3];
        n.sides[Sides::RIGHT][3] = sides[Sides::RIGHT][0];
        n.decidedTurn = "RIGHT_DOWN";           
    }
    else if(turn == Turns::LEFT_UP)
    {
        n.sides[Sides::FRONT][0] = sides[Sides::BOTTOM][0];
        n.sides[Sides::FRONT][3] = sides[Sides::BOTTOM][3];
        n.sides[Sides::TOP][0] = sides[Sides::FRONT][0];
        n.sides[Sides::TOP][3] = sides[Sides::FRONT][3];
        n.sides[Sides::BACK][1] = sides[Sides::TOP][0];
        n.sides[Sides::BACK][2] = sides[Sides::TOP][3];
        n.sides[Sides::BOTTOM][3] = sides[Sides::BACK][1];
        n.sides[Sides::BOTTOM][0] = sides[Sides::BACK][2];
        n.sides[Sides::LEFT][0] = sides[Sides::LEFT][1];
        n.sides[Sides::LEFT][1] = sides[Sides::LEFT][2];
        n.sides[Sides::LEFT][2] = sides[Sides::LEFT][3];
        n.sides[Sides::LEFT][3] = sides[Sides::LEFT][0]; 
        n.decidedTurn = "LEFT_UP"; 

    }
    else if(turn == Turns::LEFT_DOWN)
    {
        n.sides[Sides::FRONT][0] = sides[Sides::TOP][0];
        n.sides[Sides::FRONT][3] = sides[Sides::TOP][3];
        n.sides[Sides::TOP][0] = sides[Sides::BACK][1];
        n.sides[Sides::TOP][3] = sides[Sides::BACK][2];
        n.sides[Sides::BACK][1] = sides[Sides::BOTTOM][3];
        n.sides[Sides::BACK][2] = sides[Sides::BOTTOM][0];
        n.sides[Sides::BOTTOM][0] = sides[Sides::FRONT][0];
        n.sides[Sides::BOTTOM][3] = sides[Sides::FRONT][3];
        n.sides[Sides::LEFT][0] = sides[Sides::LEFT][3];
        n.sides[Sides::LEFT][1] = sides[Sides::LEFT][0];
        n.sides[Sides::LEFT][2] = sides[Sides::LEFT][1];
        n.sides[Sides::LEFT][3] = sides[Sides::LEFT][2]; 
        n.decidedTurn = "LEFT_DOWN";
    }
    else if(turn == Turns::BACK_LEFT)
    {
        n.sides[Sides::LEFT][0] = sides[Sides::TOP][1];
        n.sides[Sides::LEFT][3] = sides[Sides::TOP][0];
        n.sides[Sides::BOTTOM][2] = sides[Sides::LEFT][0];
        n.sides[Sides::BOTTOM][3] = sides[Sides::LEFT][3];
        n.sides[Sides::RIGHT][1] = sides[Sides::BOTTOM][2];
        n.sides[Sides::RIGHT][2] = sides[Sides::BOTTOM][3];
        n.sides[Sides::TOP][0] = sides[Sides::RIGHT][1];
        n.sides[Sides::TOP][1] = sides[Sides::RIGHT][2];
        n.sides[Sides::BACK][0] = sides[Sides::BACK][3];
        n.sides[Sides::BACK][1] = sides[Sides::BACK][0];
        n.sides[Sides::BACK][2] = sides[Sides::BACK][1];
        n.sides[Sides::BACK][3] = sides[Sides::BACK][2]; 
        n.decidedTurn = "BACK_LEFT";

    }
    else if(turn == Turns::FRONT_LEFT)
    {
        n.sides[Sides::LEFT][1] = sides[Sides::TOP][2];
        n.sides[Sides::LEFT][2] = sides[Sides::TOP][3];
        n.sides[Sides::BOTTOM][0] = sides[Sides::LEFT][1];
        n.sides[Sides::BOTTOM][1] = sides[Sides::LEFT][2];
        n.sides[Sides::RIGHT][0] = sides[Sides::BOTTOM][1];
        n.sides[Sides::RIGHT][3] = sides[Sides::BOTTOM][0];
        n.sides[Sides::TOP][2] = sides[Sides::RIGHT][3];
        n.sides[Sides::TOP][3] = sides[Sides::RIGHT][0];
        n.sides[Sides::FRONT][0] = sides[Sides::FRONT][1];
        n.sides[Sides::FRONT][1] = sides[Sides::FRONT][2];
        n.sides[Sides::FRONT][2] = sides[Sides::FRONT][3];
        n.sides[Sides::FRONT][3] = sides[Sides::FRONT][0];  
        n.decidedTurn = "FRONT_LEFT";

    }
    else if(turn == Turns::BACK_RIGHT)
    {
        n.sides[Sides::LEFT][0] = sides[Sides::BOTTOM][2];
        n.sides[Sides::LEFT][3] = sides[Sides::BOTTOM][3];
        n.sides[Sides::BOTTOM][2] = sides[Sides::RIGHT][1];
        n.sides[Sides::BOTTOM][3] = sides[Sides::RIGHT][2];
        n.sides[Sides::RIGHT][1] = sides[Sides::TOP][0];
        n.sides[Sides::RIGHT][2] = sides[Sides::TOP][1];
        n.sides[Sides::TOP][0] = sides[Sides::LEFT][3];
        n.sides[Sides::TOP][1] = sides[Sides::LEFT][0];
        n.sides[Sides::BACK][0] = sides[Sides::BACK][1];
        n.sides[Sides::BACK][1] = sides[Sides::BACK][2];
        n.sides[Sides::BACK][2] = sides[Sides::BACK][3];
        n.sides[Sides::BACK][3] = sides[Sides::BACK][0]; 
        n.decidedTurn = "BACK_RIGHT";
        
    }
    else if(turn == Turns::FRONT_RIGHT)
    {
        n.sides[Sides::LEFT][1] = sides[Sides::BOTTOM][0];
        n.sides[Sides::LEFT][2] = sides[Sides::BOTTOM][1];
        n.sides[Sides::BOTTOM][0] = sides[Sides::RIGHT][3];
        n.sides[Sides::BOTTOM][1] = sides[Sides::RIGHT][0];
        n.sides[Sides::RIGHT][0] = sides[Sides::TOP][3];
        n.sides[Sides::RIGHT][3] = sides[Sides::TOP][2];
        n.sides[Sides::TOP][2] = sides[Sides::LEFT][1];
        n.sides[Sides::TOP][3] = sides[Sides::LEFT][2];
        n.sides[Sides::FRONT][0] = sides[Sides::FRONT][3];
        n.sides[Sides::FRONT][1] = sides[Sides::FRONT][0];
        n.sides[Sides::FRONT][2] = sides[Sides::FRONT][1];
        n.sides[Sides::FRONT][3] = sides[Sides::FRONT][2];  
        n.decidedTurn = "FRONT_RIGHT";

    }
    return n;
}
std::vector<TwoCube> TwoCube::nextPossiblestates()
{
    Turns turns[] = {
            Turns::TOP_LEFT,
            Turns::TOP_RIGHT,
            Turns::DOWN_LEFT,
            Turns::DOWN_RIGHT,
            Turns::RIGHT_UP,
            Turns::RIGHT_DOWN,
            Turns::LEFT_UP,
            Turns::LEFT_DOWN, 
            Turns::BACK_RIGHT,
            Turns::BACK_LEFT,
            Turns::FRONT_LEFT,
            Turns::FRONT_RIGHT};
    std::vector<TwoCube> nextStates;
    for(Turns turn : turns)
    {
        nextStates.push_back(next_state(turn));
    }
    return nextStates;
}
bool TwoCube::operator==(const TwoCube& other) const
{
    return sides == other.sides;
}
bool TwoCube::operator!=(const TwoCube& other) const
{
    return sides != other.sides;
}
void TwoCube::changeState(Turns turn)
{
    *this = next_state(turn);
}
TwoCube mixer(std::vector<Turns> mix, TwoCube mixed)
{
    TwoCube n = mixed;
    for(auto m : mix)
    {
        n = n.next_state(m);
    }
    return n;
}
std::vector<TwoCube> mixerTest(std::vector<Turns> mix, TwoCube mixed)
{
    TwoCube n = mixed;
    std::vector<TwoCube> ret;
    for(auto m : mix)
    {
        n = n.next_state(m);
        ret.push_back(n);
    }
    return ret;
}
std::vector<TwoCube> solveBFS(const TwoCube& start, const TwoCube& end)
{
    //define top sides as all white

    std::queue<std::vector<TwoCube>> que;
    que.push({start});
    std::unordered_map<TwoCube,bool> visited;
    visited[start] = true;
    while(!que.empty())
    {
        std::vector<TwoCube> temp = que.front();
        que.pop();
        if(end == temp.back())
        {
            return temp;
        }
        std::vector<TwoCube> nebs = temp.back().nextPossiblestates();
        for(TwoCube n : nebs)
        {
            if(visited[n] == false)
            {
                visited[n] = true;
                std::vector<TwoCube> newP = temp;
                newP.push_back(n);
                que.push(newP);
            }
        }


    }
    return {};

}
Color intToColor(int x)
{
    switch(x)
    {
        case 0 : return Color::WHITE;
        case 1 : return Color::YELLOW;
        case 2 : return Color::GREEN;
        case 3 : return Color::BLUE;
        case 4 : return Color::ORANGE;
        case 5 : return Color::RED;
    }
}

std::vector<Color> sideDecider(std::vector<int> c)
{
    std::vector<Color> ret;
    for(int i : c)
    {
        ret.push_back(intToColor(i));
    }
    return ret;
}
