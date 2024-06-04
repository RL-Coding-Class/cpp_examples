#include <print>

auto sep() {
    std::print("---------\n");
}

struct Base
{
    int a{0};
    int b{0};
    int c{100};

    Base() = default;
    Base(int _a, int _b) : a{_a}, b{_b} { std::print("l.{} {:>30} : Initialized with a={} b={}\n", __LINE__, __PRETTY_FUNCTION__, _a, _b); }

    auto print() const -> void { std::print("l.{} {:>30} : a={} b={} c={}\n", __LINE__, __PRETTY_FUNCTION__, a, b, c); }

    // Wirtualny detruktor aby zablokować traktowanie struktury jako POD (plain old data).
    // Dla POD kompilator wygeneruje konstruktory pozwalajaće inicjalizować wszystkie zmienne,
    // np, można by napisać Base(1, 2, 3) i wtedy a=1, b=2, c=3.
    virtual ~Base() {}
};

struct A : public Base
{
    int aa{0};

    A() = default;
    A(int _aa) : aa{_aa} { std::print("l.{} {:>30} : Initialized with aa={}\n", __LINE__, __PRETTY_FUNCTION__, _aa); }
    // A(int _a, int _aa) : Base(_a, 0), aa{_aa} { std::print("l.{} {:>30} : Initialized with a={} aa={}\n", __LINE__, __PRETTY_FUNCTION__, _a, _aa); }

    auto print() const -> void { std::print("l.{} {:>30} : a={} b={} aa={}\n", __LINE__, __PRETTY_FUNCTION__, a, b, aa); }
};

struct B : public Base
{
    int bb{0};

    B() = default;
    B(int _bb) : bb{_bb} { std::print("l.{} {:>30} : Initialized with bb={}\n", __LINE__, __PRETTY_FUNCTION__, _bb); }
    // B(int _b, int _bb) : Base(0, _b), bb{_bb} { std::print("l.{} {:>30} : Initialized with b={} bb={}\n", __LINE__, __PRETTY_FUNCTION__, _b, _bb); }

    auto print() const -> void { std::print("l.{} {:>30} : a={} b={} bb={}\n", __LINE__, __PRETTY_FUNCTION__, a, b, bb); }
};

struct Derived : public A, public B
{
    Derived() = default;
    Derived(int _a, int _b) : A(10), B(20) { std::print("l.{} {:>30} : Initialized with a={} b={}\n", __LINE__, __PRETTY_FUNCTION__, _a, _b); }
    // Derived(int _a, int _b) : A(_a, 10), B(_b, 20) { std::print("l.{} {:>30} : Initialized with a={} b={}\n", __LINE__, __PRETTY_FUNCTION__, _a, _b); }
    // Derived(int _a, int _b) : Base(_a, _b) { std::print("l.{} {:>30} : Initialized with a={} b={}\n", __LINE__, __PRETTY_FUNCTION__, _a, _b); }
    // Derived(int _a, int _b) : Base(_a, _b), A(0, 10), B(0, 20) { std::print("l.{} {:>30} : Initialized with a={} b={}\n", __LINE__, __PRETTY_FUNCTION__, _a, _b); }

    auto print() const -> void
    {
        // std::print("l.{} {:>30} : a={} b={} aa={} bb={}\n", __LINE__, __PRETTY_FUNCTION__, a, b, aa, bb);
        std::print("l.{} {:>30} : a={} b={} aa={} bb={}\n", __LINE__, __PRETTY_FUNCTION__, A::a, B::b, aa, bb);
    }
};

auto step_1() {
    sep();

    Derived d;

    // static_cast<Base>(d).print();
    static_cast<A>(d).print();
    static_cast<B>(d).print();
    d.print();
}

auto step_2() {
    sep();

    Derived d(1, 2);

    // static_cast<Base>(d).print();
    static_cast<A>(d).print();
    static_cast<B>(d).print();
    d.print();
}

auto step_3() {
    sep();

    Derived d(1, 2);

    // static_cast<Base>(d).print();
    static_cast<A>(d).print();
    static_cast<B>(d).print();
    d.print();
}

auto step_4() {
    sep();

    Derived d(1, 2);

    // static_cast<Base>(d).print();
    static_cast<A>(d).print();
    static_cast<B>(d).print();
    d.print();
}

int main()
{
    // step_1();
    // step_2();
    // step_3();
    // step_4();
}
