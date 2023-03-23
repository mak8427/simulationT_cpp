#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include "Consumer.h"

Consumer::Consumer(const std::vector<double>& data) {    // random distribution with sigma 2 mean 200
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> dis(data[0], data[1]);
    capital = dis(gen);
    agent_preference_seller = {{0, 0}, {1, 0}, {2, 0}};
}

double Consumer::product_score(Product& product) {
    double score = 0.0;
    if (product.selling_price > capital) {
        return score;
    }
    score = score + product.quality_factor / product.selling_price * 50.55555;
    score = score * (0.7 + agent_preference_seller[product.seller_id] * 0.2 + (double)(rand() % 10) * 0.01);
    return score;
}

void Consumer::capital_change(std::vector<double>& data) {
    // random distribution with sigma 2 mean 200
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> dis(data[0], data[1]);
    capital = dis(gen);
}

void Consumer::update_agent_preference() {
    for (int i = 0; i < 3; i++) {
        agent_preference_seller[i] = std::count(agent_10y_history.begin(), agent_10y_history.end(), i) / 10.0;
    }
}
