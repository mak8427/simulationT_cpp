//
// Created by Mac on 23/03/23.
//

#ifndef SIMULATIONT_CONSUMER_H
#define SIMULATIONT_CONSUMER_H


#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <vector>
#include "Product.h"

class Consumer {
public:
    Consumer(const std::vector<double>& data);

    double product_score(Product& product);

    void capital_change(std::vector<double>& data);

    void update_agent_preference();

    double capital;
    std::vector<int> agent_10y_history;
    std::map<int, double> agent_preference_seller;
};


#endif //SIMULATIONT_CONSUMER_H
