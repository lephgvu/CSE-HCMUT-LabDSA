#include <iostream>
#include <math.h>
using namespace std;

class Polynomial;
class Term {
private:
    double coeff;   
    int exp;
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
class Polynomial {
private:
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
    }
    void insertTerm(const Term& term);
    void insertTerm(double coeff, int exp);
    void print() {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};

void Polynomial::insertTerm(const Term& term) {
    insertTerm(term.coeff, term.exp);
}

void Polynomial::insertTerm(double coeff, int exp) {
    if (coeff == 0) return; // Không chèn hệ số 0

    SLinkedList<Term>::Iterator it = this->terms->begin();
    int index = 0; // Đếm vị trí của phần tử trong danh sách

    while (it != this->terms->end() && (*it).exp > exp) {
        ++it;
        ++index;
    }

    // Nếu tìm thấy một phần tử có cùng exp, cộng hệ số
    if (it != this->terms->end() && (*it).exp == exp) {
        double newCoeff = (*it).coeff + coeff;
        if (newCoeff == 0) {
            this->terms->removeAt(index); // Nếu hệ số mới bằng 0, xóa phần tử
        } else {
            *it = Term(newCoeff, exp); // Cập nhật hệ số mới
        }
    } else {
        // Chèn phần tử mới vào đúng vị trí
        this->terms->addAt(index, Term(coeff, exp));
    }
}


int main(){
    Polynomial *poly = new Polynomial();
    poly->insertTerm(6.0, 2);
    poly->insertTerm(4.0, 5);
    poly->insertTerm(4.0, 3);
    poly->insertTerm(6.0, 5);
    poly->insertTerm(-1.0, 0);
    poly->insertTerm(-6.0, 6);
    poly->insertTerm(6.0, 6);
    poly->print();
    // [
    // Term: (10 5)
    // Term: (4 3)
    // Term: (6 2)
    // Term: (-1 0)
    // ]
// //----------------------------
//     int n = 5;
//     int coeff[] = { 1, 2, 3, 4, 5 };
//     int exp[] = { 1, 2, 3, 4, 5 };

//     Polynomial p1;
//     for (int i = 0; i < n; ++i)
//         p1.insertTerm(coeff[i], exp[i]);

//     p1.print();
//     // [
//     // Term: (5 5)
//     // Term: (4 4)
//     // Term: (3 3)
//     // Term: (2 2)
//     // Term: (1 1)
//     // ]

    return 0;
}