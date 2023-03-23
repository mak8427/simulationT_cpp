//
// Created by Mac on 23/03/23.
//
#include "Product.h"

#include "Product.h"
#include <cmath>
#include <random>
#include <sstream>

#include "util.h"



Product::Product(int id) {
    cost_to_produce = rand_in_range(150, 300);
    selling_price = rand_in_range(50, 100) + cost_to_produce;
    number_produced = rand_in_range(2000, 5000) + 200;
    number_sold = 0;
    seller_id = id;
    quality_factor = _calculate_quality_factor();
}

double Product::calculate_profit() const {
    double profit = selling_price * number_sold - cost_to_produce * number_produced;
    return profit;
}




void Product::new_product() {
    cost_to_produce = rand_in_range(150, 300);
    selling_price = rand_in_range(50, 100) + cost_to_produce;
    number_produced = rand_in_range(2000, 5000) + 200;
    number_sold = 0;
    quality_factor = _calculate_quality_factor();
}

float Product::_calculate_quality_factor(float w1, float w0) {
    float w_x = w0 + w1 * static_cast<float>(selling_price) / 10.0f;
    return (10.0f / (1.0f + std::exp(-w_x))) + std::log10(static_cast<float>(selling_price));
}

int Product::get_seller_id() const {
    return seller_id;
}

int Product::get_selling_price() const {
    return selling_price;
}

int Product::get_cost_to_produce() const {
    return cost_to_produce;
}

int Product::get_number_produced() const {
    return number_produced;
}

int Product::get_number_sold() const {
    return number_sold;
}

void Product::increment_number_sold() {
    ++number_sold;
}

float Product::get_quality_factor() const {
    return quality_factor;
}

const std::vector<float>& Product::get_profit_history() const {
    return profit_history;
}

