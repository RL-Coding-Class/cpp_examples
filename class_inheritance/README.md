# Dziedziczenie

## Diamond diagram

Plik: [diamond_problem_example.cpp](diamond_problem_example.cpp).

Ten przykład demonstruje kilka kwestii związanych z diagramami diamentowymi. Przeanalizujmy go krok po kroku. Program możesz skompilować poleceniem `make` i następnie uruchomić `./diamond_problem_example`. Można to zrobić w jednej linijce:
```bash
make && ./diamond_problem_example
```

W każdym kolejnym kroku będziemy odkomentowywać linijki. Notacja `-#l.13` oznacza usuń komentarz z linii 13, a `+#l.13` oznacza zakomentuj tę linijkę. Wyrażenie: cofnij zmianę oznacza, że trzeba zrobić krok przeciwny, np: cofnij zmianę `-#l.3` oznacza: zrób `+#l.3`.

Polecenie `aktywuj krok X` oznacza odkomentowanie odpowiedniej funkcji `krok_x` w funkcji `main()`.

### Krok 0

W tym kroku mamy podstawową strukturę z klasą bazową `Base`, dziedziczącymi po niej klasami `A` i `B` oraz końcową klasą `Derived` dziedziczącą po `A` i `B`.

Klasa `Base` ma dwa pola `a` i `b` a klasy `A` i `B` odpowiednio po jednym polu `aa` i `bb`.

W tym kroku problem diamentowy nie ukaże się.

### Krok 1

Aktywuj krok 1, następnie skompiluj i uruchom program. W wyniku zobaczysz trzy linie pokazujące wynik wywołania funkcji `print` dla każdej z klas `Derived, `A, i `B`. Nie ma na tej liście `Base`. Zobacz, co się stanie, gdy zrobisz `-#l.66`.

Komunikat
```
diamond_problem_example.cpp: In function ‘auto step_1()’:
diamond_problem_example.cpp:60:24: error: ‘Base’ is an ambiguous base of ‘Derived’
   60 |     static_cast<Base>(d).print();
```
oznacza, że kompilator nie jest w stanie jednoznacznie określić, poprzez którą klasę, `A` czy `B` ma dotrzeć do klasy `Base`.

Cofnij zmianę `-#l.66`.

### Krok 2

Aktywuj krok 2, skompiluj i uruchom kod. Tutaj mamy lekką modyfikację kroku 1, w którym klasa `Derived` tworzona jest z dwoma argumentami. Na wyjściu zobaczymy efekt zadziałania konstruktora. Mamy tu zainicjalizowane zmienne `aa` i `bb` ale nic nie stało się ze zmiennymi `a` i `b`. Poprawimy to w kolejnym kroku.

### Krok 3

Aktywuj krok 3, wykonaj akcje `-#l.30`, `-#l.41`, `+#l.49` oraz `-#l.50`. Następnie skompiluj i uruchom kod. Zwróć uwagę, że w konstruktorach w `l.30` i `l.41` inicjujemy jedną ze składowych klasy `Base` wartością 0, co widać w wyniku funkcji `print` w `l.32` i `l.43`. Każda z tych klas `A` i `B` ma swoją kopię `Base`, co widać w funkcjach `print()`, gdzie każda z klas pośrednich `A` i `B` ma swój zestaw zmiennych `a` i `b`.

Ale w `l.57` widzimy poprawne wartości. To dlatego, że musimy podać, które wartości `a` i `b` chcemy wypisać. Widać to w `l.57` jako `A::a` i `B::b`. Zobacz, co się stanie dla `-#l.56`. Potem wycofaj tę zmianę.

### Krok 4

W tym kroku poprawimy już problem diagramu diamentowego.

Aktywuj krok 4 oraz `-#l.88` (musi być zakomentowane bo da błąd kompilacji we wcześniejszych krokach). Następnie w linijkach `l.24` i `l.35` dodaj słowo `virtual` przy dziedziczeniu. Powinny one wyglądać teraz tak:
```c++
struct A : virtual public Base
struct B : virtual public Base
```
Skompiluj i uruchom.

Zauważysz teraz, że pomimo inicjalizacji obiektów wartościami, funkcje `print()` pokazują zmienne `a` i `b` równe 0. To dlatego, że teraz klasa `Derived` ma swój niezależny zestaw zmiennych z `Base`.

W tym momencie możemy zrobić `-#l.56` i `+#l.57`. Program ponownie skompiluje się i wykona poprawnie.

Żeby jednak działał poprawnie, musimy bezpośrednio wywołać konstruktor dla klasy `Base`. Zacznij od `+#l.50` i `-#l.51`. Skompiluj i uruchom.

To oczywiście poprawiło `Base` ale popsuło `A` i `B`. Zatem musimy wywołać wszystkie trzy konstruktory: `+#l.51` i `-#l.52`. Skompiluj i uruchom.

Teraz wszystko działa poprawnie.
