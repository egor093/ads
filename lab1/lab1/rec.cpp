#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    auto start = high_resolution_clock::now();
    cout << "Введите число n: ";
    cin >> n;
            cout << "Результат: " << abs(fibonacci(n));
        cout << endl;
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);

        long long nanosec = duration.count();
        long long microsec = nanosec / 1000;
        long long millisec = microsec / 1000;
        long long sec = millisec / 1000;
        long long minutes = sec / 60;

        sec %= 60;
        millisec %= 1000;
        microsec %= 1000;
        nanosec %= 1000;

        cout << "Время выполнения: ";
        cout << minutes << " минут " << sec << " секунд "
            << millisec << " миллисекунд "
            << microsec << " микросекунд "
            << nanosec << " наносекунд ";

    return 0;
}