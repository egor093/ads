#include <iostream>
#include <string>
#include <locale>

using namespace std;

struct Item {
    string name;
    int weight;
    int value;
};

void backpack(int capacity, Item* items, int num_items) {

    int cols = capacity + 1;
    int total_cells = (num_items + 1) * cols;
    int* dp = new int[total_cells];

    for (int i = 0; i < total_cells; ++i)
        dp[i] = 0;

    auto idx = [cols](int i, int w) { return i * cols + w; };

    for (int i = 1; i <= num_items; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            int curIndex = idx(i, w);
            int prevIndex = idx(i - 1, w);
            if (items[i - 1].weight <= w) {
                int take = dp[idx(i - 1, w - items[i - 1].weight)] + items[i - 1].value;
                int notake = dp[prevIndex];
                dp[curIndex] = (take > notake) ? take : notake;
            }
            else {
                dp[curIndex] = dp[prevIndex];
            }
        }
    }

    int max_value = dp[idx(num_items, capacity)];
    cout << "Максимальная стоимость: " << max_value << endl;

    cout << "Предметы в рюкзаке:" << endl;
    int w = capacity;
    for (int i = num_items; i > 0 && max_value > 0; --i) {
        if (max_value != dp[idx(i - 1, w)]) {
            cout << "- " << items[i - 1].name
                << " (вес: " << items[i - 1].weight
                << ", стоимость: " << items[i - 1].value << ")" << endl;
            max_value -= items[i - 1].value;
            w -= items[i - 1].weight;
        }
    }

    delete[] dp;
}

int main() {
    setlocale(LC_ALL, "rus");
    int capacity;
    cout << "Введите вместимость рюкзака: ";
    cin >> capacity;

    int num_items;
    cout << "Введите количество предметов: ";
    cin >> num_items;

    Item* items = new Item[num_items];
    for (int i = 0; i < num_items; ++i) {
        cout << "Введите название предмета, его вес и стоимость: ";
        cin >> items[i].name >> items[i].weight >> items[i].value;
    }

    backpack(capacity, items, num_items);

    delete[] items;
    return 0;
}