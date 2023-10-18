// 10-18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

//Pair.h file 
class Pair
{
    friend ostream& (ostream& out, const Pair& pair)
    {

    }
public:
    Pair() : first(0), second(0) {}
    Pair(int newFirst, int newSecond) :
        first(newFirst), second(newSecond) {}
    
    void setFirst(int newFirst);
    void setSecond(int newSecond);
    int getFirst() const;
    int getSecond() const;

    void print() const;

    //bool operator==(const Pair& otherPair) const;

    ~Pair(){}

private:
    int first;
    int second;
};



//Pair.cpp - Source code of the class
//bool Pair::operator==(const Pair& otherPair) const
//{
//    return (first == otherPair.first &&
//        second == otherPair.second);
//}

void Pair::setFirst(int newFirst)
{
    first = newFirst;
}

void Pair::setSecond(int newSecond)
{
    second = newSecond;
}
int Pair::getFirst() const
{
    return first;
}
int Pair::getSecond() const
{
    return second;
}

void Pair::print() const
{
    cout << "Pair is: (" << first << ", " << second << ")\n";

}


bool operator==(const Pair& pair1, const Pair& pair2)
{
    return (pair1.getFirst() == pair2.getFirst() &&
        pair1.getSecond() == pair2.getSecond());
}


int main()
{
    Pair pair1;
    Pair pair2(3, 5);

    pair1.setFirst(pair2.getFirst());
    pair2.setSecond(pair2.getSecond());

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
