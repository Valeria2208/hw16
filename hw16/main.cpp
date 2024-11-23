//
//  main.cpp
//  hw16
//
//  Created by Valeria Dudinova on 23.11.2024.
//

#include <iostream>

using namespace std;

class IOutput
{
public:
    virtual void Show() = 0;
    virtual void Show(const char* info) = 0;
    virtual ~IOutput() = default;
};

// Клас Array, який імплементує інтерфейс IOutput
class Array : public IOutput
{
private:
    int* elements;
    size_t size;

public:
    Array(int arr[], size_t size)
    {
        this->size = size;
        elements = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            elements[i] = arr[i];
        }
    }

    ~Array() {
        delete[] elements; // Звільнення пам'яті
    }

    // Метод Show() - відображає елементи масиву
    void Show() override
    {
        cout << "Array elements: ";
        for (size_t i = 0; i < size; i++)
        {
            cout << elements[i] << " ";
        }
        cout << endl;
    }

    // Метод Show(info) - відображає елементи масиву та повідомлення
    void Show(const char* info) override
    {
        cout << info << endl;
        Show(); // Виклик методу Show() для відображення елементів
    }
};

int main()
{
    // Ініціалізація масиву
    int data[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(data) / sizeof(data[0]);

    // Створення об'єкта Array
    Array arr(data, size);

    // Тестування методів Show()
    cout << "Show method test():" << endl;
    arr.Show();

    cout << "\nShow method test(info):" << endl;
    arr.Show("This is the content of the array:");

    return 0;
}

