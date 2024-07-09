#include <iostream>
#include <vector>
#include <numeric>

int candy(std::vector<int>& ratings) {
    int size = ratings.size();
    std::vector<int> candies(size, 1); // Каждому ребенку выдается хотя бы одна конфета

    // Слева направо
    for (int i = 1; i < size; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Справа налево
    for (int i = size - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = std::max(candies[i], candies[i + 1] + 1);
        }
    }

    // Суммируем количество конфет
    return std::accumulate(candies.begin(), candies.end(), 0);
}

int main() {
    std::vector<int> ratings = { 1, 0, 2 }; // Пример рейтингов
    std::cout << "Минимальное количество конфет, которое нужно иметь: " << candy(ratings) << std::endl;
    return 0;
}
