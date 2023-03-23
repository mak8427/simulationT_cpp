//
// Created by Mac on 23/03/23.
//

#ifndef SIMULATIONT_PRODUCT_H
#define SIMULATIONT_PRODUCT_H
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

class Product {
public:
    Product(int id = 0);
    double calculate_profit() const;
    void new_product();
    float get_quality_factor() const;
    int get_seller_id() const;
    int get_selling_price() const;
    int get_cost_to_produce() const;
    int get_number_produced() const;
    int get_number_sold() const;
    void increment_number_sold();
    const std::vector<float>& get_profit_history() const;
    std::string to_string() const;

private:
    float _calculate_quality_factor(float w1 = 0.1f, float w0 = -4.6f);

    int cost_to_produce;
    int selling_price;
    int number_produced;
    int number_sold;
    int seller_id;
    float quality_factor;
    std::vector<float> profit_history;
};


#endif //SIMULATIONT_PRODUCT_H
