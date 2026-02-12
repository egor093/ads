//#include <iostream>
//#include <chrono>
//using namespace std;
//using namespace std::chrono;
//
//int main() {
//    setlocale(0, "");
//    int n;
//    cout << "Введите число n: ";
//    cin >> n;
//    auto start = high_resolution_clock::now();
//    int a = 0, b = 1, c;
//
//    for (int i = 3; i <= n; i++) {
//        c = a + b;
//        a = b;
//        b = c;
//    }
//cout << "Результат: " << abs(b) << endl;
//   
//    auto end = high_resolution_clock::now();
//    auto duration = duration_cast<nanoseconds>(end - start);
//
//    long long nanosec = duration.count();
//    long long microsec = nanosec / 1000;
//    long long millisec = microsec / 1000;
//    long long sec = millisec / 1000;
//    long long minutes = sec / 60;
//
//    sec %= 60;
//    millisec %= 1000;
//    microsec %= 1000;
//    nanosec %= 1000;
//
//    cout << "Время выполнения: ";
//    cout << minutes << " минут " << sec << " секунд "
//        << millisec << " миллисекунд "
//        << microsec << " микросекунд "
//        << nanosec << " наносекунд ";
//    return 0;
//}