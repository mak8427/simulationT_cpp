#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iterator>
#include "Product.h"
#include "Consumer.h"
#include "util.h"

void buy_product_for_agent(Consumer& agent, std::vector<Product>& product_list) {
    double best = 0;
    int best_product = -1;

    for (size_t i = 0; i < product_list.size(); ++i) {
        if (agent.get_capital() > product_list[i].get_selling_price() && product_list[i].get_number_sold() < product_list[i].get_number_produced()) {
            double tmp = agent.product_score(product_list[i]);
            if (tmp > best) {
                best = tmp;
                best_product = static_cast<int>(i);
            }
        }
    }

    if (best != 0 && best_product >= 0) {
        product_list[best_product].increment_number_sold();
        agent.update_agent_preference();
    }
}

void buy_product_for_agents(std::vector<Consumer>& agent_list, std::vector<Product>& product_list) {
    for (Consumer& agent : agent_list) {
        buy_product_for_agent(agent, product_list);
    }
}

void compute_profit(const std::vector<Product>& product_list) {
    for (const Product& product : product_list) {
        std::cout << "profit of product " << product.get_seller_id() << " is " << product.calculate_profit() << std::endl;
    }
}

int main() {
    // Set mean and standard deviation
    double mu = 400.0;
    double sigma = 200.0;

    // Generate random data from a left-skewed distribution using std
    std::gamma_distribution<> gamma(6, 100);
    std::vector<double> data(100000);
    std::generate(data.begin(), data.end(), [&]() { return gamma(gen); });
    double data_mean = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
    double data_stddev = std::sqrt(
            std::inner_product(data.begin(), data.end(), data.begin(), 0.0) / data.size() - std::pow(data_mean, 2));
    for (double &value: data) {
        value = ((value - data_mean) / data_stddev) * sigma + mu;
    }

    // Create 3 products with random values
    std::vector<Product> product_list = {Product(0), Product(1), Product(2)};
    std::vector<Consumer> agent_list(10000, Consumer(data));

    for (int x = 0; x < 10; ++x) {
        auto start1 = std::chrono::high_resolution_clock::now();
        buy_product_for_agents(agent_list, product_list);
        compute_profit(product_list);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count();

        auto start2 = std::chrono::high_resolution_clock::now();
        for (Product &product: product_list) {
            product.new_product();
        }
        auto end2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();
        std::cout << "proportion of time spent in buy_product: "
                  << static_cast<double>(duration1) / static_cast<double>(duration2) << std::endl;
    }

    for (const Product &product: product_list) {
        std::cout << "Total profit for product " << product.get_seller_id() << ": "
                  << std::accumulate(product.get_profit_history().begin(), product.get_profit_history().end(), 0)
                  << std::endl;
    }

    return 0;
}