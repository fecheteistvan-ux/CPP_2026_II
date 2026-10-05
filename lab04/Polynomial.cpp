#include "Polynomial.h"
#include  <algorithm>

Polynomial::Polynomial(int degree, const double coefficients[]) {
    this -> capacity = degree +1 ;
    this -> coefficients = new double[this -> capacity];
    for (int i = 0; i < this -> capacity; i++) {
        this -> coefficients[i] = coefficients[i];
    }
}
Polynomial::Polynomial(const Polynomial &that) {
    this -> capacity = that.capacity;
    this -> coefficients = new double[this -> capacity];
    for (int i = 0; i < this -> capacity; i++) {
        this -> coefficients[i] = that.coefficients[i];
    }
}

Polynomial::~Polynomial() {
    delete [] this -> coefficients;
}
int Polynomial::degree() const {
    return this -> capacity -1;
}
double Polynomial::evaluate(double x) const {
    double result = coefficients[0];
    for (int i = 1; i < capacity; i++) {
        result = result * x + coefficients[i];
    }
    return result;
}

Polynomial Polynomial::derivative() const {
    if (degree() == 0) {
        double zero[] = {0.0};
        return Polynomial(0, zero);
    }
    int deg = degree()-1;
    double *deriv_coeff =new double[deg+1];
    for (int i = 0; i <= deg; i++) {
        deriv_coeff[i] = coefficients[i] *(degree() -i);
    }
    Polynomial res(deg,deriv_coeff);
    delete [] deriv_coeff;
    return res;
}

double Polynomial::operator[](int index) const {
    if (index >=0 && index <  capacity)
        return coefficients[index];
    return 0.0;
}

Polynomial operator-(const Polynomial &a) {
    int deg = a.degree();
    double *temp = new double[deg+1];
    for (int i = 0; i <= deg; i++)
        temp[i]= -a.coefficients[i];
    Polynomial res(deg, temp);
    delete [] temp;
    return res;
}

Polynomial operator+(const Polynomial &a,const Polynomial &b) {
    int deg = max(a.degree(), b.degree());
    int cap = deg + 1;
    double *temp = new double[cap]();

    for (int i = 0; i < a.capacity; ++i) {
        int power = a.degree() - i;
        temp[cap - 1 - power] += a.coefficients[i];
    }
    for (int i = 0; i < b.capacity; ++i) {
        int power = b.degree() - i;
        temp[cap - 1 - power] += b.coefficients[i];
    }

    Polynomial res(deg, temp);
    delete[] temp;
    return res;
}
Polynomial operator-(const Polynomial &a,const Polynomial &b) {
    return a + (-b);
}

Polynomial operator*(const Polynomial &a,const Polynomial &b) {
    int deg = a.degree() + b.degree();
    int cap =deg + 1;
    double *temp = new double[cap];
    for (int i = 0; i < a.capacity; i++) {
        for (int j = 0; j < b.capacity; j++) {
            temp[i + j] += a.coefficients[i]* b.coefficients[j];
        }
    }
    Polynomial res(deg, temp);
    delete [] temp;
    return res;
}

ostream & operator <<(ostream& out, const Polynomial& what) {
    bool first = true;
    for (int i = 0; i < what.capacity; ++i) {
        double c = what.coefficients[i];
        if (c == 0 && what.capacity > 1) {
            continue;
        }
        int power = what.degree() - i;
        if (!first) {
            if (c > 0) {
                out << " + ";
            } else {
                out << " - ";
            }
        } else if (c < 0) {
            out << "-";
        }
        double absC = (c < 0) ? -c : c;
        if (absC != 1 || power == 0) {
            out << absC;
        }
        if (power > 0) {
            out << "x";
            if (power > 1) {
                out << "^" << power;
            }
        }
        first = false;
    }
    if (first) {
        out << "0";
    }
    return out;

}