//
// Created by Mac on 23/03/23.
//
#include "Product.h"

Product::Product(int id) {
    srand(time(NULL));
    cost_to_produce = (rand() % 151) + 150;
    selling_price = (rand() % 51) + cost_to_produce + 50;
    number_produced = (rand() % 3001) + 2000;
    number_sold = 0;
    seller_id = id;
    quality_factor = _calculate_quality_factor();
    profit_history = std::vector<double>();
}

double Product::calculate_profit() {
    double profit = selling_price * number_sold - cost_to_produce * number_produced;
    profit_history.push_back(profit);
    return profit;
}

void Product::new_product() {
    cost_to_produce = (rand() % 151) + 150;
    selling_price = (rand() % 51) + cost_to_produce + 50;
    number_produced = (rand() % 3001) + 2000;
    number_sold = 0;
    quality_factor = _calculate_quality_factor();
}

double Product::_calculate_quality_factor(double w1, double w0) {
    double w_x = w0 + w1 * selling_price / 10;
    return (10 / (1 + exp(-w_x))) + log10(selling_price);
}
