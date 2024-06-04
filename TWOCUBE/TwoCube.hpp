#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <stack>

enum class Sides{TOP,BOTTOM,RIGHT,LEFT,BACK,FRONT};
enum class Color{WHITE,BLUE,RED,ORANGE,YELLOW,GREEN};
enum class Turns{
            TOP_LEFT,
            TOP_RIGHT,
            DOWN_LEFT,
            DOWN_RIGHT,
            RIGHT_UP,
            RIGHT_DOWN,
            LEFT_UP,
            LEFT_DOWN, 
            BACK_RIGHT,
            BACK_LEFT,
            FRONT_LEFT,
            FRONT_RIGHT,
            START

        };

namespace std {
    template <>
    struct hash<Sides> {
        std::size_t operator()(const Sides& side) const noexcept {
            return std::hash<int>()(static_cast<int>(side));
        }
    };
}


class TwoCube
{
    public:
        
        //Default Constructor
        //set cube to already solved
        TwoCube();
        //Constructor Based on Defined Sides of a Cube
        TwoCube(std::unordered_map<Sides,std::vector<Color> > Tsides);
        //copy constructor
        TwoCube(const TwoCube &other);
        //Next State of Cube
        TwoCube next_state(Turns turn);
        //isSolved check if cube is solved
        bool isSolved();
        //check if specifc side is fully solved
        bool sideSolved(Sides side);
        //return string of the the sides
        std::string sidetoString(Sides side);
        //return string of colors
        std::string colortoString(Color color);
        //string of all colors on one side
        std::string colorsPerSide(std::vector<Color> colors);
        //print the cube
        void print();
        //return the sides map
        std::unordered_map<Sides,std::vector<Color>> getSides();
        //a list of all the possible next states
        std::vector<TwoCube> nextPossiblestates();
        //Equality constructor
        bool operator==(const TwoCube& other) const;
        //inequality operator
        bool operator!=(const TwoCube& other) const;
        //change state
        void changeState(Turns turn);
        //cube mixer
        void setDecided(std::string ans)
        {
            decidedTurn = ans;
        }    
        
        

        struct HashFunction {
        std::size_t operator()(const TwoCube& tc) const {
            std::size_t hash = 0;
            for (const auto& pair : tc.sides) {
                std::size_t sideHash = std::hash<Sides>()(pair.first);
                for (const auto& color : pair.second) {
                    sideHash ^= std::hash<int>()(static_cast<int>(color)) + 0x9e3779b9 + (sideHash << 6) + (sideHash >> 2);
                }
                hash ^= sideHash + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };
        



    private:
        std::unordered_map<Sides,bool> sCheck;
        std::unordered_map<Sides,std::vector<Color>> sides;
        std::string decidedTurn;
};
namespace std {
    template <>
    struct hash<TwoCube> {
        std::size_t operator()(const TwoCube& tc) const {
            return TwoCube::HashFunction()(tc);
        }
    };
}
//return an pair of states of 
std::vector<TwoCube> solveBFS(const TwoCube& start, const TwoCube& end);
TwoCube mixer(std::vector<Turns> mix, TwoCube mixed);
std::vector<TwoCube> mixerTest(std::vector<Turns> mix, TwoCube mixed);
std::vector<Color> sideDecider(std::vector<int> c);
Color intToColor(int x);

