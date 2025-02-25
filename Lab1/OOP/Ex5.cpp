#include <iostream>
using namespace std;

enum Color
{
    red,
    green,
    blue
};
enum Size
{
    small,
    medium,
    big
};

class Toy
{
protected:
    double price;

public:
    Toy(double price)
    {
        this->price = price;
    }

    virtual void printType() = 0;
    friend class ToyBox;
};

class CarToy : public Toy
{
private:
    Color color;

public:
    CarToy(double price, Color color) : Toy(price), color(color) {}

    void printType()
    {
        cout << "This is a car toy\n";
    }

    friend class ToyBox;
};

class PuzzleToy : public Toy
{
private:
    Size size;

public:
    PuzzleToy(double price, Size size) : Toy(price), size(size) {}

    void printType()
    {
        cout << "This is a puzzle toy\n";
    }

    friend class ToyBox;
};

class ToyBox
{
private:
    Toy* toyBox[5];
    int numberOfItems;

public:
    ToyBox() {
        this->numberOfItems = 0;

        for(int i = 0; i < 5; i++) {
            toyBox[i] = nullptr;
        }
    }
    
    int addItem(const CarToy& carToy) {
        if (numberOfItems >= 5) return -1; 
        toyBox[numberOfItems] = new CarToy(carToy); 
        return ++numberOfItems; 
    }

    int addItem(const PuzzleToy& puzzleToy) {
        if (numberOfItems >= 5) return -1; 
        toyBox[numberOfItems] = new PuzzleToy(puzzleToy); 
        return ++numberOfItems; 
    }
    
    void printBox()
    {
        for (int i = 0; i < numberOfItems; i++)
            toyBox[i]->printType();
    }

    // Destructor: Giải phóng bộ nhớ
    ~ToyBox() {
        for (int i = 0; i < numberOfItems; i++) {
            delete toyBox[i];
        }
    }
};

int main(){
    // CarToy car(20000,red);
    // PuzzleToy puzzle(30000,small);
    // car.printType(); //This is a car toy
    // puzzle.printType();  //This is a puzzle toy
    
    // //------------------------------------
    CarToy car(20000,red);
    PuzzleToy puzzle(30000,small);

    ToyBox box;
    box.addItem(car);
    box.addItem(puzzle);
    box.printBox(); //This is a car toy, This is a puzzle toy

    // //------------------------------------
    // Toy* toy = new CarToy(30000,red);
    // toy->printType(); //This is a car toy

    return 0;
}