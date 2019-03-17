#include <iostream>

class Rational
{
public:

    Rational(int newnumerator = 0, int newdenominator = 1)
    {
        numerator = newnumerator;
        denominator = newdenominator;
    }

    int getnum() const
    {
        return numerator;
    }

    int getden() const
    {
        return denominator;
    }

    void setnum(int newnum)
    {
        numerator = newnum;
    }

    void setden(int newden)
    {
        denominator = newden;
    }

    void reduction()
    {
        bool nsign = true, dsign = true;

        if(numerator < 0)
        {
            numerator *= -1;
            nsign = false;
        }

        if(denominator < 0)
        {
            denominator *= -1;
            dsign = false;
        }

        int n = 0;
        if(numerator < denominator)
            n = numerator;
        else n = denominator;

        for(int i = 2; i <= n; ++i)
        {
            if(numerator % i == 0 && denominator % i == 0)
            {
                numerator /= i;
                denominator /= i;

                i = 1;
            }
        }

        if(nsign == false)
            numerator *= -1;
        if(dsign == false)
            denominator *= -1;
    }

    const Rational operator + (const Rational &r) const
    {
        return Rational(numerator * r.getden() + r.getnum() * denominator, denominator * r.getden());
    }

    void operator += (const Rational &r)
    {
        numerator = numerator * r.getden() + r.getnum() * denominator;
        denominator *= r.getden();
    }

    const Rational operator + (const int &x) const
    {
        return operator + (Rational(x, 1));
    }

    void operator += (const int &x)
    {
        numerator += x * denominator;
    }

    const Rational operator - (const Rational &r) const
    {
        return Rational(numerator * r.getden() - r.getnum() * denominator, denominator * r.getden());
    }

    void operator -= (const Rational &r)
    {
        numerator = numerator * r.getden() - r.getnum() * denominator;
        denominator *= r.getden();
    }

    const Rational operator - (const int &x) const
    {
        return operator - (Rational(x, 1));
    }

    void operator -= (const int &x)
    {
        numerator -= x * denominator;
    }

    const Rational operator * (const Rational &r) const
    {
        return Rational(numerator * r.getnum(), denominator * r.getden());
    }

    void operator *= (const Rational &r)
    {
        numerator *= r.getnum();
        denominator *= r.getden();
    }

    const Rational operator * (const int &x) const
    {
        return operator * (Rational(x, 1));
    }

    void operator *= (const int &x)
    {
        numerator *= x;
    }

    const Rational operator / (const Rational &r) const
    {
        return operator * (Rational(r.getden(), r.getnum()));
    }

    void operator /= (const Rational &r)
    {
        numerator *= r.getden();
        denominator *= r.getnum();
    }

    const Rational operator / (const int &x) const
    {
        return operator * (Rational(1, x));
    }

    void operator /= (const int &x)
    {
        denominator *= x;
    }

    bool operator == (const Rational &r)
    {
        this->reduction();
        //r.reduction();
        Rational newr = r;
        newr.reduction();

        if(numerator == newr.getnum() && denominator == newr.getden())
            return true;
        else return false;
    }

    bool operator == (const int &x)
    {
        this->reduction();

        if(numerator == x && denominator == 1)
            return true;
        else return false;
    }

    bool operator != (Rational &r)
    {
        return !(*this == r);
    }

    bool operator != (const int &x)
    {
        return !(*this == x);
    }

private:

    int numerator, denominator;
};

class ComplexHighPrecision
{
public:

    ComplexHighPrecision(Rational newr = Rational(), Rational newi = Rational())
    {
        r = newr;
        i = newi;
    }

    Rational getr() const
    {
        return r;
    }

    Rational geti() const
    {
        return i;
    }

    void setr(Rational newr)
    {
        r = newr;
    }

    void seti(Rational newi)
    {
        i = newi;
    }

    Rational sqrr() const
    {
        return r * r;
    }

    Rational sqri() const
    {
        return i * i;
    }

    const ComplexHighPrecision operator + (const ComplexHighPrecision &c) const
    {
        return ComplexHighPrecision(r + c.getr(), i + c.geti());
    }

    void operator += (const ComplexHighPrecision &c)
    {
        r += c.getr();
        i += c.geti();
    }

    const ComplexHighPrecision operator + (const Rational &x) const
    {
        return operator + (ComplexHighPrecision(x, 0));
    }

    void operator += (const Rational &x)
    {
        r += x;
    }

    const ComplexHighPrecision operator - (const ComplexHighPrecision &c) const
    {
        return ComplexHighPrecision(r - c.getr(), i - c.geti());
    }

    void operator -= (const ComplexHighPrecision &c)
    {
        r -= c.getr();
        i -= c.geti();
    }

    const ComplexHighPrecision operator - (const Rational &x) const
    {
        return operator - (ComplexHighPrecision(x, 0));
    }

    void operator -= (const Rational &x)
    {
        r -= x;
    }

    const ComplexHighPrecision operator * (const ComplexHighPrecision &c) const
    {
        return ComplexHighPrecision(r * c.getr() - i * c.geti(), i * c.getr() + r * c.geti());
    }

    void operator *= (const ComplexHighPrecision &c)
    {
        Rational auxr = r * c.getr() - i * c.geti();
        Rational auxi = i * c.getr() + r * c.geti();

        r = auxr;
        i = auxi;
    }

    const ComplexHighPrecision operator * (const Rational &x) const
    {
        return operator * (ComplexHighPrecision(x, 0));
    }

    void operator *= (const Rational &x)
    {
        Rational auxr = r * x;
        Rational auxi = i * x;

        r = auxr;
        i = auxi;
    }

    const ComplexHighPrecision operator / (const ComplexHighPrecision &c) const
    {
        return ComplexHighPrecision((r * c.getr() + i * c.geti())/(c.sqrr() + c.sqri()), (i * c.getr() - r * c.geti())/(c.sqrr() + c.sqri()));
    }

    void operator /= (const ComplexHighPrecision &c)
    {
        Rational auxr = (r * c.getr() + i * c.geti())/(c.sqrr() + c.sqri());
        Rational auxi = (i * c.getr() - r * c.geti())/(c.sqrr() + c.sqri());

        r = auxr;
        i = auxi;
    }

    const ComplexHighPrecision operator / (const Rational &x) const
    {
        return operator / (ComplexHighPrecision(x, 0));
    }

    void operator /= (const Rational &x)
    {
        Rational auxr = (r * x)/(x * x);
        Rational auxi = (i * x)/(x * x);

        r = auxr;
        i = auxi;
    }

    bool operator == (const ComplexHighPrecision &c)
    {
        if(r == c.getr() && i == c.geti())
            return true;
        else return false;
    }

    bool operator == (const Rational &x)
    {
        if(r == x && i == 0)
            return true;
        else return false;
    }

    bool operator != (const ComplexHighPrecision &c)
    {
        return !(*this == c);
    }

    bool operator != (const Rational &x)
    {
        return !(*this == x);
    }

private:

    Rational r, i;
};

std::ostream& operator << ( std::ostream &os, const Rational &r )
{
	os << r.getnum() << "/" << r.getden();

	return os;
}

std::ostream& operator << ( std::ostream &os, const ComplexHighPrecision &c )
{
	os << "(" << c.getr() << "," << c.geti() << "i)";

	return os;
}

int main()
{
    ComplexHighPrecision d;

    Rational b, c(2, 2);
    ComplexHighPrecision a(b, c);
    std::cout << a << '\n';

    a.setr(c);
    std::cout << a << '\n';

    ComplexHighPrecision x(Rational(3, 3), Rational(5, 1));

    std::cout << a * c << '\n';
    x /= c;
    std::cout << x << '\n';

    ComplexHighPrecision y(Rational(1, 1), Rational(5, 1));
    ComplexHighPrecision z(Rational(9, 3), Rational());
    Rational h(3, 1);

    if(z == h)
        std::cout << "Dziala!" << '\n';
    else std::cout << "Nie dziala :(" << '\n';

    Rational f(5, 10), g(4, 8);
    g.reduction();

    if(f != g)
        std::cout << "Prawda" << '\n';
    else std::cout << "Nie prawda, liczby sa sobie rowne" << '\n';

    std::cout << "f po redukcji: " << f << ", g po redukcji: " << g << '\n';

    Rational e(2250, 6930);
    e.reduction();
    std::cout << "e po skroceniu: " << e << '\n';

    Rational p(1, 2);
    Rational q(2, 5);
    Rational r = p / 3;
    p /= 3;
    std::cout << "p = " << p << ", q = " << q << ", r = " << r << '\n';

    return 0;
}
