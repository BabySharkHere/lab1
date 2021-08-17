/* Класс <<Рациональное число>> (РЧ). Поля: числитель, знаменатель. Методы: вычисление
модуля, перегрузка операции приведения типа к double, операций вычитания <<->> из РЧ целого
числа и РЧ, операции получения обратного РЧ <<!>>. */

#include <iostream>
#include <cstdlib>

using namespace std;

void cleaning() {
    cin.clear();
    while (cin.get() != '\n');
}
class r_numbers {
private:
    int numinator;
    int denominator;
public:
    r_numbers(int num1, int num2)
    {
        cout << "Параметры конструируются" << endl;
        numinator = num1;
        denominator = num2; // конструктор с параметрами
    }

    r_numbers()
    {
        numinator = 0;
        denominator = 0; // конструктор по-умолчанию
    };

    ~r_numbers()
    {
        cout << "Деструктор активирован" << endl; // деструктор
    }
    int getDen()
    {
        return denominator;
    }

    r_numbers operator ! () {

        if (numinator == 0) {
            cout << "Невозможно перевернуть" << endl;
            return r_numbers(numinator, denominator);
        }
        else {
            cout << denominator << "/" << numinator << endl;
        }
    }

    operator double() {
        cout << "Double оператор активирован" << endl;

        return ((double)numinator / denominator);
    }

    void new_r() {
        int a, b;
        cout << "Введите числитель" << endl;

        while (!(cin >> numinator) || cin.get() != '\n') {
            cout << "Ошибка! Попробуйте другое число" << endl;
            cleaning();
        }

        cout << "Введите знаменатель" << endl;

        while (!(cin >> b) || cin.get() != '\n') {
            cout << "Ошибка! Попробуйте другое число" << endl;
            cleaning();
        }

        if (b != 0)
            denominator = b;
        else
            cout << "Знаменатель не должен быть равен 0" << endl;
    }

    void prin_num() {

        if (numinator == 0 && denominator == 0)
            cout << "0" << endl;
        else
            if (numinator != 0 && denominator == 0)
                cout << "Знаменатель равен нулю" << endl;
            else
                cout << "Ваше число: " << endl << numinator << "/" << denominator << endl;

    }
    void modul() {
        if (numinator == 0 && denominator == 0)
            cout << "Пусто" << endl;
        else {
            cout << "Модуль рационального числа : ";
            cout << abs(numinator) << "/" << abs(denominator) << endl;
        }
    }




    r_numbers operator - (const r_numbers& rc) {
        int x = 0;
        if ((denominator == rc.denominator) && (numinator == rc.numinator))
            x = 1;
        else
            if (denominator == rc.denominator) {
                x = 2;
            }
            else
            {
                x = 3;
            }
        switch (x) {
        case 1: {
            cout << "Ответ: 0" << endl;
            break;
        };
        case 2: {
            return r_numbers(numinator - rc.numinator, denominator);
            //cout << numinator - rc.numinator << "/" << denominator << endl;
            break;
        };
        case 3: {
            return r_numbers(rc.denominator * numinator - denominator * rc.numinator, denominator * rc.denominator);
            // cout << rc.denominator * numinator - denominator * rc.numinator << "/" << denominator * rc.denominator << endl;
            break;
        };
        }
    }

    r_numbers operator - (const int& nat) {
        if (numinator - denominator * nat == 0)
            cout << "ОТВЕТ: 0" << endl;
        else
            return r_numbers(numinator - denominator * nat, denominator);
    }

};
int main()
{
    setlocale(LC_ALL, "ru");

    int b, z;
    r_numbers* a = new r_numbers;
    r_numbers* c = new r_numbers;
    r_numbers* d = new r_numbers;
    r_numbers* temp = new r_numbers;

    do {

        cout << "1. Введите рациональное число(будем работать только с ним)" << endl
            << "2. Вывести рациональное число" << endl
            << "3. Очистить консоль" << endl
            << "4. Второе рациональное число" << endl
            << "5. Разность (РЧ-РЧ)" << endl
            << "6. Разность (РЧ-нат)" << endl
            << "7. Модуль рационального числа" << endl
            << "8. Double оператор" << endl
            << "9. Перевернуть РЧ" << endl
            << "0. Выход" << endl;

        while (!(cin >> b) || cin.get() != '\n') {
            cout << "Ошибка!!! Попробуйте другое число" << endl;
            cleaning();
        }


        switch (b) {

        case 1:
        {
            a->new_r();
            break;
        };

        case 2: { a->prin_num();
            c->prin_num();
            system("Pause");
            system("CLS");
            break;

        };

        case 0:
        {
            delete a;
            delete c;
            delete d;
            delete temp;
            cout << "Объекты удалены" << endl;

            exit(0);
            break;
        }

        case 3: {
            system("CLS");
            break;
        }

        case 4: {
            c->new_r();
            break;
        };

        case 5: {
            if (a->getDen() == 0) {
                cout << "Разность невозможна" << endl;
            }
            else {
                *d = *a - *c;
                //cout << "Разность (РЧ-РЧ): ";
                d->prin_num();

            }
            system("Pause");
            system("CLS");
            break;
        };

        case 6: {
            if (a->getDen() == 0) {

                cout << "Разность невозможна" << endl;
            }
            else {
                int num;
                cout << "Введите натуральное число" << endl;
                while (!(cin >> num) || cin.get() != '\n') {
                    cout << "Ошибка! Попробуйте другое число" << endl;
                    cleaning();
                }
                *d = *a - num;
                //cout << "Разность (РЧ - нат): ";
                d->prin_num();
                cout << endl;
            }
            system("Pause");
            system("CLS");
            break;
        }

        case 7: {
            a->modul();
            system("Pause");
            system("CLS");
            break;
        }

        case 8: {
            double cTemp = double(*c);
            double aTemp = double(*a);

            if (aTemp != NULL)
                cout << aTemp << endl;
            if (cTemp != NULL)
                cout << cTemp << endl;
            system("Pause");
            system("CLS");
            break;

        }

        case 9: {

            *temp = *a;
            !*temp;
            //temp->prin_num();
            system("Pause");
            system("CLS");
            break;
        }

        default:
        {
            cout << "Ошибка! Попробуйте другое число" << endl;
        }
        break;
        }

    } while (true);
    return 0;
}

