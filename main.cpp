#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include "Product.h"
#include "Consumer.h"

std::vector<Product> create_products() {
    std::vector<Product> products;
    for (int i = 0; i < 3; ++i) {
        products.push_back(Product(i));
    }
    return products;
}

std::vector<Consumer> create_consumers() {
    // Set mean and standard deviation
    double mu = 400;
    double sigma = 200;

    // Generate random data from a left-skewed distribution using C++ random library
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::gamma_distribution<double> distribution(6, 100);
    std::vector<double> data(100000);
    for (double& d : data) {
        d = distribution(generator);
    }
    double mean = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
    double stdev = std::sqrt(std::inner_product(data.begin(), data.end(), data.begin(), 0.0) / data.size() - mean * mean);
    for (double& d : data) {
        d = (d - mean) / stdev * sigma + mu;
    }

    // Create 10000 consumers with random capital from data
    std::vector<Consumer> consumers;
    for (int i = 0; i < 10000; ++i) {
        consumers.push_back(Consumer(data));
    }
    return consumers;
}

void simulate() {
    auto products = create_products();
    auto consumers = create_consumers();
    for (int i = 0; i < 10; ++i) {
        auto s1 = std::chrono::system_clock::now();

        buy_product_multiprocessed(consumers, products);

        compute_profit(products);
        auto s2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - s1).count();
        auto t1 = std::chrono::system_clock::now();
        for (auto& product : products) {
            product.new_product();
        }
        auto t2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - t1).count();

        std::cout << "proportion of time spent in buy_product: " << static_cast<double>(s2) / t2 << '\n';
    }
    for (const auto& product : products) {
        std::cout << "profit of product " << product.get_id() << " is " << std::accumulate(product.get_profit_history().begin(), product.get_profit_history().end(), 0.0) << '\n';
    }
}

int main() {
    simulate();
    std::cout << "fine\n";
    return 0;
}
