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
    Product(int id);

    double calculate_profit();

    void new_product();

    double _calculate_quality_factor(double w1 = 0.1, double w0 = -4.6);

    int number_produced;
    int number_sold;
    int seller_id;
    double cost_to_produce;
    double selling_price;
    double quality_factor;
    std::vector<double> profit_history;
};


#endif //SIMULATIONT_PRODUCT_H
