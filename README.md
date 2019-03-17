# Complex-number
Zadanie z kursu C/C++ (ALX/Warszawa/kwiecień-czerwiec 2018)

2 Liczby zespolone
Uwaga: w tym zadaniu kompletnie nie trzeba nic wiedziec o liczbach zespolonych.
Zaimplementuj klase Complex, słuzaca do obliczen na liczbach zespolonych. Liczba zespolona to para (r; i)
(odpowiednio: czesc rzeczywista i urojona). Definiujemy nastepujace operacje na liczbach zespolonych: dodawanie, odejmowanie, mnozenie, dzielenie

Do liczby zespolonej mozna dodac, odjac, mnozyc i dzielic takze liczby rzeczywiste. Dowolna liczba rzeczywista
x jest po prostu traktowana jako liczba zespolona (x; 0).
Zadbaj o dostarczenie bogatego zestawu operatorów arytmetycznych dla tej klasy. Dostarcz takze operatory ==
i !=.

2.1 Gwiazdka
Zwykle wystarczy, aby czesc rzeczywista i urojona była trzymana w zmiennej typu double. Czasami jednak
potrzebujemy obliczen o wysokiej precyzji. Wtedy z pomoca przychodzi implementowany na zajeciach typ
Ulamek, czyli liczba wymierna. Przygotuj druga klase ComplexHighPrecision, która bedzie wewnetrznie uzywała
obiektów typu Ulamek do reprezentowania czesci rzeczywistej i urojonej. Przy okazji zmien nazwe klasy
Ulamek na angielskie Rational.

Porównaj ile kodu zmieniło sie przy przejsciu od klasy Complex do ComplexHighPrecision.
