#include <iostream>
using namespace std;

Character::Character() {
    // STUDENT ANSWER
}

Character::Character(int hp, int x, int y) {
    // STUDENT ANSWER
}

int Character::getHp() {
    // STUDENT ANSWER
}

void Character::setHp(int hp) {
    // STUDENT ANSWER
}

int Character::getX() {
    // STUDENT ANSWER
}

void Character::setX(int x) {
    // STUDENT ANSWER
}

int Character::getY() {
    // STUDENT ANSWER
}

void Character::setY(int y) {
    // STUDENT ANSWER
}

int Character::getManhattanDistTo(Character* other) {
    // STUDENT ANSWER
}

int main(){
    Character ch1(100, 3, 6);
    cout << ch1.getHp() << " " << ch1.getX() << " " << ch1.getY(); //100 3 6

    return 0;
}