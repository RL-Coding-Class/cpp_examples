#include <print>
#include <string>

class Vehicle
{
protected:
    std::string type;

private:
    std::string brand;
    std::string model;
    int wheels;
    int doors;
    int color; // 0 - black, 1 - red, 2 - blue, 3 - green, 4 - white
public:
    Vehicle(std::string _brand, std::string _model, int _wheels, int _doors, int _color, std::string _type = "Vehicle")
        : type(std::move(_type)), brand(std::move(_brand)), model(std::move(_model)), wheels(_wheels), doors(_doors),
          color(_color)
    {
        std::print("{} : {} {} with {} wheels, {} doors and color of {}\n", type, brand, model, wheels, doors, color);
    }
    auto get_doors() { return doors; }
};

/* Starship uses constructrs from the bsae Vehicle class.
 */
class Starship : public Vehicle
{
public:
    using Vehicle::Vehicle;
};

/* Car can have aditional ifno about gear type.
 */
class Car : public Vehicle
{
private:
    bool has_automatic_gear{false};

public:
    Car(std::string _brand, std::string _model, int _doors, int _color, bool _has_automatic_gear)
        : Vehicle(_brand, _model, 2, _doors, _color, "Car"), has_automatic_gear(_has_automatic_gear)
    {
        std::print("{} has {} doors.  Does it have automatic gear?\n", type, get_doors(),
                   has_automatic_gear ? "Yes, it has!" : "No, it hasn't.");
    }
    Car(std::string _brand, std::string _model, bool _has_automatic_gear)
        : Car(_brand, _model, 4, 5, _has_automatic_gear)
    {
    }
};

/* Bike can have gear or not.
 */
class Bike : public Vehicle
{
private:
    bool has_gears{false};

public:
    Bike(std::string _brand, std::string _model, int _color, bool _has_gears)
        : Vehicle(_brand, _model, 2, 0, _color, "Bike"), has_gears(_has_gears)
    {
        std::print("My bike has {} doors. Does it have gears? {}\n", get_doors(),
                   has_gears ? "Yes, it has!" : "No, it hasn't.");
    }
    Bike(std::string _brand, std::string _model, bool _has_gears) : Bike(_brand, _model, 1, _has_gears) {}
};

/* Base abstract class for the engine kind.
 */
class Engine
{
public:
    virtual void start_engine() = 0;
};

/* Diesel engine.
 */
class Diesel : public Engine
{
};

/* Gasoline engine.
 */
class Gasoline : public Engine
{
};

/* Electric engine.
 */
class Electric : public Engine
{
};

class GasolineCar : public Car, public Gasoline
{
public:
    GasolineCar() = default;
};

class ElectricCar : public Car, public Electric
{
};

class HybridCar : public GasolineCar, public ElectricCar
{
};

/* Task 1
 *
 */
#define ENABLE_TASK_1 1

int main()
{
    Vehicle v1("Unknown", "Unknown", 4, 4, 0);
    Starship s1("USS", "Enterprise", 0, 0, 0);

    // Car c1(v1);
    Car c2("Porshe", "911", 4, 2, 1);
    // Bike b2(4, 5, 1);
    Bike b3("Gazelle", "Arroyo C5", 2);

    v1.get_doors();
    b3.get_doors();

#if ENABLE_TASK_1
    GasolineCar gs_car_1("Renault", "Twingo", 4, 5, 4);
#endif
}
