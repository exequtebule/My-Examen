#include <random>
#include <time.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <algorithm>
#include <vector>
#include <random>
#include <time.h>

using namespace std;


///PRODUCTS //START
//enum alcoholType {vodka, viski, vino};

class foodProduct {
protected:
    string name;
    string firm;
    double price;

public:
    foodProduct() { setName(""); setFirm(""); setPrice(0); }
    foodProduct(const string _name, const string _firm, const double _price) { setName(_name); setFirm(_firm); setPrice(_price); }

    void setName(const string _name) { name = _name; }
    void setFirm(const string _firm) { firm = _firm; }
    void setPrice(const double _price) { price = _price; }


    virtual void setSpirt(const int _spirt) = 0;
    virtual void setMl(const double _ml) = 0;
    virtual void setGram(const double _gram) = 0;
    virtual void setTaste(const string _taste) = 0;


    string getName() { return name; }
    string getFirm() { return firm; }
    double getPrice() { return price; }

    virtual string whatIs() { return "Some"; }
    virtual void draw() { cout << "name: " << name << "\nfirm: " << firm << "\nprice: " << price << endl; }

};
class alcohol : public foodProduct {

    int spirt; //% спірту, градус
    double ml;
    //alcoholType

public:
    alcohol() { setSpirt(0); setMl(0); }
    alcohol(const int _spirt, const double _ml) { setSpirt(_spirt); setMl(_ml); }

    void setSpirt(const int _spirt) {
        if (_spirt <= 100) {
            spirt = _spirt;
        }
        else {
            spirt = 100;
        }
    }
    void setMl(const double _ml) { ml = _ml; }

    int getSpirt() { return spirt; }
    double getMl() { return ml; }

    string whatIs() override { return "Alcohol"; }
    void draw() override { foodProduct::draw(); cout << "spirt: " << spirt << "\nml: " << ml << "\n--------------------\n"; }

    //непотрібні функції + костиль
    void setGram(const double _gram) {//try catch типу нема що ініціалізувати, да костильно, но я незнаю як по іншому зробити
    }
    void setTaste(const string _taste) {}
};
class food : public foodProduct {

    double gram;
    //foodType

public:
    food() { setGram(0); }
    food(const double _gram) { setGram(_gram); }

    void setGram(const double _gram) { gram = _gram; }

    double getGram() { return gram; }

    string whatIs() override { return "Food"; }
    void draw() override { foodProduct::draw(); cout << "gram: " << gram << "\n--------------------\n"; }

    //непотрібні функції
    void setSpirt(const int _spirt) {}
    void setMl(const double _ml) {}
    void setTaste(const string _taste) {}
};
class drink : public foodProduct {

    double ml;

public:
    drink() { setMl(0); }
    drink(const double _ml) { setMl(_ml); }

    void setMl(const double _ml) { ml = _ml; }

    double getMl() { return ml; }

    string whatIs() override { return "Drink"; }
    void draw() override { foodProduct::draw(); cout << "ml: " << ml << "\n--------------------\n"; }


    //непотрібні функції
    void setGram(const double _gram) {}
    void setSpirt(const int _spirt) {}
    void setTaste(const string _taste) {}
};
class petFood :public foodProduct {

    string taste;
    double gram;
public:

    petFood() { setTaste(""); setGram(0); }
    petFood(const string _taste, const double _gram) { setTaste(_taste); setGram(_gram); }

    void setGram(const double _gram) { gram = _gram; }
    void setTaste(const string _taste) { taste = _taste; }

    double getGram() { return gram; }
    string getTaste() { return taste; }

    string whatIs() override { return "Pet food"; }
    void draw() override { foodProduct::draw(); cout << "taste: " << taste << "gram: " << gram << "\n--------------------\n"; }

    //непотрібні функції
    void setMl(const double _ml) {}
    void setSpirt(const int _spirt) {}
};
class chockolade : public foodProduct {

    string taste;
    double gram;

public:
    chockolade() { setTaste(""); setGram(0); }
    chockolade(const string _taste, const double _gram) { setTaste(_taste); setGram(_gram); }

    void setGram(const double _gram) { gram = _gram; }
    void setTaste(const string _taste) { taste = _taste; }

    double getGram() { return gram; }
    string getTaste() { return taste; }

    string whatIs() override { return "Chockolade"; }
    void draw() override { foodProduct::draw(); cout << "taste: " << taste << "gram: " << gram << "\n--------------------\n"; }


    //непотрібні функції
    void setMl(const double _ml) {}
    void setSpirt(const int _spirt) {}
};
class fruit : public foodProduct {

    double gram;

public:
    fruit() { setGram(0); }
    fruit(const double _gram) { setGram(_gram); }

    void setGram(const double _gram) { gram = _gram; }

    double getGram() { return gram; }

    string whatIs() override { return "Fruit"; }
    void draw() override { foodProduct::draw(); cout << "gram: " << gram << "\n--------------------\n"; }

    //непотрібні функції
    void setSpirt(const int _spirt) {}
    void setMl(const double _ml) {}
    void setTaste(const string _taste) {}

};

//Костиль
class voidClass : public foodProduct {
public:

    string whatIs() override { return ""; }
    void draw() override { cout << "There is nothing.\n--------------------\n"; } //місце пусте

    void setTaste(const string _taste) {}
    void setSpirt(const int _spirt) {}
    void setMl(const double _ml) {}
    void setGram(const double _gram) {}

};
//and other
///PRODUCTS //END


//рисовка / меню

///STORE PREMISES //START
class shelf {
public:
    foodProduct* arr[5][5];//розділена на 5 "секторів" по 5 продуктів
    int numSector, numProduct;//номер секторра і продукта в ньому

    shelf() :numSector(5), numProduct(5) { shelfInit(); }

    void shelfInit() {
        for (int i = 0; i < numSector; i++) {
            for (int j = 0; j < numProduct; j++) {
                arr[i][j] = new voidClass;
            }
        }
    }

};
class department : public shelf {
public:

    shelf sf[4]; //4 полички в одному відділі
    int numShelf; // номер полки
    string nameDeparment; // назва відділу


    department() :numShelf(4), nameDeparment("") {}

    void setNumShelf(const int _numShelf) { numShelf = _numShelf; }
    void setNameDeparment(const string _nameDeparment) { nameDeparment = _nameDeparment; }

    int getNumShelf() { return numShelf; }
    string getNameDeparment() { return nameDeparment; }


};
class line : public department {
public:
    department dp[2]; //2 відділи в одному ряді
    int numDepartment; //номер відділу

    line() :numDepartment(2) {}

    void setNumDepartment(const int _numDeparment) { numDepartment = _numDeparment; }

    int getNumDepartment() { return numDepartment; }

};
class floor : public line {
public:

    line l[3]; //3 ряда
    int numLine; //номер ряду

    floor() :numLine(3) {}

    void setNumLine(const int _numLine) { numLine = _numLine; }

    int getNumLine() { return numLine; }

};
class Hause : public floor {
public:
    floor f[2]; // 2 поверха в магазині
    int numFloor; //номер поверху

    Hause() :numFloor(2) {
        //Floor 1

        // line 1 deparment 1--------------------------------------------------------------
        setAlcohol(0, "GreenDay", "IF Alcohol", 99.99, 35, 150);
        setAlcohol(1, "VGood", "Lviv Alcohol", 199.99, 25, 170);
        setAlcohol(2, "NonStop", "IF Alcohol", 78.99, 30, 125);
        setAlcohol(3, "Viski", "J. Bruss", 53.50, 37, 150);
        f[0].l[0].dp[0].setNameDeparment(f[0].l[0].dp[0].sf[0].arr[0][0]->whatIs());
        //---------------------------------------------------------------------------------


        // line 1 deparment 2--------------------------------------------------------------
        setFood(0, "Bread", "IF Bakery", 15.50, 350);
        setFood(1, "Cookies", "IF Bakery", 35.90, 1000);
        setFood(2, "Croissant", "IF Bakery", 9.99, 250);
        setFood(3, "Pie ", "IF Bakery", 255.50, 2150);
        f[0].l[0].dp[1].setNameDeparment(f[0].l[0].dp[1].sf[0].arr[0][0]->whatIs());
        //---------------------------------------------------------------------------------


        // line 2 deparment 1--------------------------------------------------------------
        setDrink(0, "Coca-Cola", "IF DrinkFactory", 25.50, 120);
        setDrink(1, "Fanta", "Lenos", 35.90, 130);
        setDrink(2, "Sprite", "IF DrinkFactory", 39.99, 135);
        setDrink(3, "Pepsi ", "F-Factory", 55.50, 125);
        f[0].l[1].dp[0].setNameDeparment(f[0].l[1].dp[0].sf[0].arr[0][0]->whatIs());
        //---------------------------------------------------------------------------------


         // line 2 deparment 2--------------------------------------------------------------
        setPetFood(0, "Doggy", "Pet paradise", 75.50, "Meat", 320);
        setPetFood(1, "Kitty", "Pet paradise", 45.90, "Sausage", 250);
        setPetFood(2, "Super Parrot", "IF Pet Paradise", 89.99, "Banane", 80);
        setPetFood(3, "Doggy DLuxe", "Pet paradise", 155.50, "Fish", 225);
        f[0].l[1].dp[1].setNameDeparment(f[0].l[1].dp[1].sf[0].arr[0][0]->whatIs());
        //---------------------------------------------------------------------------------


        // line 3 deparment 1--------------------------------------------------------------
        setChocolade(0, "Golden Wind", "JJBA", 9999999.99, "Masterpiece", 1);
        setChocolade(1, "Boom", "AWK", 57.90, "Berry", 100);
        setChocolade(2, "Po", "Roshen", 89.99, "Ko", 80);
        setChocolade(3, "Bliss", "Rohen", 45.50, "White choco", 315);
        f[0].l[2].dp[0].setNameDeparment(f[0].l[2].dp[0].sf[0].arr[0][0]->whatIs());
        //---------------------------------------------------------------------------------


        // line 3 deparment 2--------------------------------------------------------------
        setFruit(0, "Barry", "IF Fruits", 45.50, 100);
        setFruit(1, "Banana", "IF Fruits", 45.90, 100);
        setFruit(2, "Kiwi", "IF Fruits", 79.99, 100);
        setFruit(3, "Mango ", "IF Fruits", 155.50, 100);
        f[0].l[2].dp[1].setNameDeparment(f[0].l[2].dp[1].sf[0].arr[0][0]->whatIs()); //якась помилка, тому так захардкорив
        //---------------------------------------------------------------------------------

    }

    void setAlcohol(const int g, const string _name, const string _firm, const double _price, const int _spirt, const double _ml) {
        for (int i = 0; i < numSector; i++) {
            for (int j = 0; j < numProduct; j++) {
                f[0].l[0].dp[0].sf[g].arr[i][j] = new alcohol();
                f[0].l[0].dp[0].sf[g].arr[i][j]->setName(_name);
                f[0].l[0].dp[0].sf[g].arr[i][j]->setFirm(_firm);
                f[0].l[0].dp[0].sf[g].arr[i][j]->setPrice(_price);
                f[0].l[0].dp[0].sf[g].arr[i][j]->setSpirt(_spirt);
                f[0].l[0].dp[0].sf[g].arr[i][j]->setMl(_ml);
            }
        }
    }
    void setFood(const int g, const string _name, const string _firm, const double _price, const double _gram) {
        for (int i = 0; i < numSector; i++) {
            for (int j = 0; j < numProduct; j++) {
                f[0].l[0].dp[1].sf[g].arr[i][j] = new food();
                f[0].l[0].dp[1].sf[g].arr[i][j]->setName(_name);
                f[0].l[0].dp[1].sf[g].arr[i][j]->setFirm(_firm);
                f[0].l[0].dp[1].sf[g].arr[i][j]->setPrice(_price);
                f[0].l[0].dp[1].sf[g].arr[i][j]->setGram(_gram);
            }
        }
    }
    void setDrink(const int g, const string _name, const string _firm, const double _price, const double _ml) {
        for (int i = 0; i < numSector; i++) {
            for (int j = 0; j < numProduct; j++) {
                f[0].l[1].dp[0].sf[g].arr[i][j] = new drink();
                f[0].l[1].dp[0].sf[g].arr[i][j]->setName(_name);
                f[0].l[1].dp[0].sf[g].arr[i][j]->setFirm(_firm);
                f[0].l[1].dp[0].sf[g].arr[i][j]->setPrice(_price);
                f[0].l[1].dp[0].sf[g].arr[i][j]->setMl(_ml);
            }
        }
    }
    void setPetFood(const int g, const string _name, const string _firm, const double _price, const string _taste, const double _gram) {
        for (int i = 0; i < numSector; i++) {
            for (int j = 0; j < numProduct; j++) {
                f[0].l[1].dp[1].sf[g].arr[i][j] = new petFood();
                f[0].l[1].dp[1].sf[g].arr[i][j]->setName(_name);
                f[0].l[1].dp[1].sf[g].arr[i][j]->setFirm(_firm);
                f[0].l[1].dp[1].sf[g].arr[i][j]->setPrice(_price);
                f[0].l[1].dp[1].sf[g].arr[i][j]->setTaste(_taste);
                f[0].l[1].dp[1].sf[g].arr[i][j]->setGram(_gram);
            }
        }
    }
    void setChocolade(const int g, const string _name, const string _firm, const double _price, const string _taste, const double _gram) {
        for (int i = 0; i < numSector; i++) {
            for (int j = 0; j < numProduct; j++) {
                f[0].l[2].dp[0].sf[g].arr[i][j] = new chockolade();
                f[0].l[2].dp[0].sf[g].arr[i][j]->setName(_name);
                f[0].l[2].dp[0].sf[g].arr[i][j]->setFirm(_firm);
                f[0].l[2].dp[0].sf[g].arr[i][j]->setPrice(_price);
                f[0].l[2].dp[0].sf[g].arr[i][j]->setTaste(_taste);
                f[0].l[2].dp[0].sf[g].arr[i][j]->setGram(_gram);
            }
        }
    }
    void setFruit(const int g, const string _name, const string _firm, const double _price, const double _gram) {
        for (int i = 0; i < numSector; i++) {
            for (int j = 0; j < numProduct; j++) {
                f[0].l[2].dp[1].sf[g].arr[i][j] = new fruit();
                f[0].l[2].dp[1].sf[g].arr[i][j]->setName(_name);
                f[0].l[2].dp[1].sf[g].arr[i][j]->setFirm(_firm);
                f[0].l[2].dp[1].sf[g].arr[i][j]->setPrice(_price);
                f[0].l[2].dp[1].sf[g].arr[i][j]->setGram(_gram);
            }
        }
    }


    void setNumFloor(const int _numFloor) { numFloor = _numFloor; }

    int getNumFloor() { return numFloor; }

};
///STORE PREMISES //END




///ASSOCIATED WITH THE STORE //START
class basket {
    foodProduct* arr[15];//масив класів продуктів
    double money;//мани

public:
    basket() {
        for (int i = 0; i < 15; i++) {
            arr[i] = new voidClass;
        }
        setMoney(0);
    }

    void initBasket(const Hause& h, const int a, const int _l, const int _dp, const int _sf, const int x, const int y) {
        if (_l == 0) {
            if (_dp == 0) {
                initBasketAlcohol(h, a, _l, _dp, _sf, x, y);
            }
            else {
                initBasketFood(h, a, _l, _dp, _sf, x, y);
            }
        }
        else if (_l == 1) {
            if (_dp == 0) {
                initBasketDrink(h, a, _l, _dp, _sf, x, y);
            }
            else {
                initBasketPetFood(h, a, _l, _dp, _sf, x, y);
            }
        }
        else {
            if (_dp == 0) {
                initBasketChockolade(h, a, _l, _dp, _sf, x, y);
            }
            else {
                initBasketFruit(h, a, _l, _dp, _sf, x, y);
            }
        }
    }

    void initBasketAlcohol(const Hause& h, const int a, const int _l, const int _dp, const int _sf, const int x, const int y) {
        arr[a] = new alcohol;
        arr[a] = h.f[0].l[_l].dp[_dp].sf[_sf].arr[x][y];
    }
    void initBasketFood(const Hause& h, const int a, const int _l, const int _dp, const int _sf, const int x, const int y) {
        arr[a] = new food;
        arr[a] = h.f[0].l[_l].dp[_dp].sf[_sf].arr[x][y];
    }
    void initBasketDrink(const Hause& h, const int a, const int _l, const int _dp, const int _sf, const int x, const int y) {
        arr[a] = new drink;
        arr[a] = h.f[0].l[_l].dp[_dp].sf[_sf].arr[x][y];
    }
    void initBasketPetFood(const Hause& h, const int a, const int _l, const int _dp, const int _sf, const int x, const int y) {
        arr[a] = new petFood;
        arr[a] = h.f[0].l[_l].dp[_dp].sf[_sf].arr[x][y];
    }
    void initBasketChockolade(const Hause& h, const int a, const int _l, const int _dp, const int _sf, const int x, const int y) {
        arr[a] = new chockolade;
        arr[a] = h.f[0].l[_l].dp[_dp].sf[_sf].arr[x][y];
    }
    void initBasketFruit(const Hause& h, const int a, const int _l, const int _dp, const int _sf, const int x, const int y) {
        arr[a] = new fruit;
        arr[a] = h.f[0].l[_l].dp[_dp].sf[_sf].arr[x][y];
    }



    void setMoney(const double _money) {
        if (_money > 0) {
            money = _money;
        }
        else {
            money = 0;
        }
    }

    double getMoney() { return money; }

    bool basketIsVoid() {
        if (arr[0]->getPrice() > 0) {
            return true;
        }
        return false;
    }

    void cashRegister() {
        system("cls");
        for (int i = 0; i < 15; i++) {
            if (money > arr[i]->getPrice()) {
                money -= arr[i]->getPrice();
            }
            else if (money < arr[i]->getPrice()) {
                cout << "There is not enough money to pay for all the goods." << endl; //не вистачає грошей для оплати усіх товарів
                return;
            }
        }
        cout << "Thanks for your purchase:\n" << endl; //дякуємо за покупки
        for (int i = 0; i < 15; i++) {
            if (arr[i]->getPrice() > 0) {
                arr[i]->draw();
            }
            else {
                return;
            }
        }
        return;

    }

    void drawArr() {
        system("cls");
        for (int i = 0; i < 15; i++) {
            cout << i + 1 << ")\n";
            arr[i]->draw();
        }
        system("pause");
    }

};

///ASSOCIATED WITH THE STORE //END





///LOGIC //START
void drawLine(const Hause& h, const int a, basket& b) {

    cout << "---------------------------------------------------" << endl;
    for (int j = 0; j < h.numDepartment; j++) {
        cout << "|" << h.f[0].l[a].dp[j].nameDeparment;
    }
    cout << "|\n---------------------------------------------------" << endl;

}
void drawAllLine(const Hause& h, basket& b) {
    for (int i = 0; i < h.numLine; i++) {
        drawLine(h, i, b);
    }

}
void drawDeparment(const Hause& h, const int _l, const int _dp, basket& b) {
    system("cls");
    cout << "\t\t\"" << h.f[0].l[_l].dp[_dp].nameDeparment << "\"\n";
    for (int i = 0; i < h.numShelf; i++) {
        cout << "---------------------------------------------------" << endl;
        cout << "|" << h.f[0].l[_l].dp[_dp].sf[i].arr[0][0]->getName() << "|\n";
        cout << "---------------------------------------------------" << endl;
    }
}
void drawShelf(Hause& h, const int _l, const int _dp, const int _sf, basket& b) {
    system("cls");
    static int a = 0;
    if (a < 15) {
        int x, y;
        for (int i = 0; i < h.numSector; i++) {
            for (int j = 0; j < h.numProduct; j++) {
                cout << "x - " << i << " y - " << j << endl;
                h.f[0].l[_l].dp[_dp].sf[_sf].arr[i][j]->draw();
            }
        }
        cout << "Input x & y: " << endl;
        switch (_getch()) {
        case 'e':
            return;
        default:
            cin >> x >> y;
            b.initBasket(h, a, _l, _dp, _sf, x, y);
            h.f[0].l[_l].dp[_dp].sf[_sf].arr[x][y] = new voidClass;
            a++;
        }

    }
    else {
        cout << "There is no space in the basket" << endl; //немає місця в корзині
        return;
    }
}


bool menuShelf(Hause& h, const int _l, const int _dp, const int _sf, basket& b) {
    while (true) {
        system("cls");
        drawShelf(h, _l, _dp, _sf, b); // рисуємо полку і вибираємо продовольчі товари собі в корзину
        switch (_getch()) {
        case '4':

        case 'k':
            b.drawArr();
            break;
        case 'c':
            b.cashRegister();
            return false;
        default:
            return false;
        }
    }
}
bool menuDeparment(Hause& h, const int _l, const int _dp, basket& b) {

    while (true) {
        system("cls");
        drawDeparment(h, _l, _dp, b);// рисуємо вибраний відділ і вибираєм полку
        switch (_getch()) {
        case '1':
            menuShelf(h, _l, _dp, 0, b);
            break;
        case '2':
            menuShelf(h, _l, _dp, 1, b);
            break;
        case '3':
            menuShelf(h, _l, _dp, 2, b);
            break;
        case '4':
            menuShelf(h, _l, _dp, 3, b);
            break;
        case 'k':
            b.drawArr();
            break;
        case 'c':
            b.cashRegister();
            return false;
        default:
            return false;
        }
    }

}
bool menuLine(Hause& h, const int _l, basket& b) {

    while (true) {
        system("cls");
        drawLine(h, _l, b); // рисуємо вибраний ряд і вибираємо відділ
        switch (_getch()) {
        case '1':
            menuDeparment(h, _l, 0, b);
            break;
        case '2':
            menuDeparment(h, _l, 1, b);
            break;
        case 'k':
            b.drawArr();
            break;
        case 'c':
            b.cashRegister();
            return false;
        default:
            return false;
        }
    }

}

bool menu(Hause& h, basket& b) {
    int m;
    cout << "Input money: ";
    cin >> m;
    b.setMoney(m);
    while (true) {
        system("cls");
        drawAllLine(h, b);// рисуємо 3 ряда на 1 поверсі і вибираємо ряд
        if (_kbhit) {
            switch (_getch()) {
            case '1':
                menuLine(h, 0, b);
                break;
            case '2':
                menuLine(h, 1, b);
                break;
            case '3':
                menuLine(h, 2, b);
                break;
            case 'k':
                b.drawArr();
                break;
            case 'c':
                b.cashRegister();
                return false;
            default:
                if (b.basketIsVoid()) {
                    b.cashRegister();
                }
                return false;
            }

        }
    }
}
///LOGIC //END






int main() {

    Hause h;
    basket b;


    while (menu(h, b)) {}

    return 1;
}

