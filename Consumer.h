//
// Created by Mac on 23/03/23.
//

#ifndef SIMULATIONT_CONSUMER_H
#define SIMULATIONT_CONSUMER_H


#include <vector>
#include <map>
#include "Product.h"

class Consumer {
public:
    explicit Consumer(const std::vector<double>& data);
    double product_score(const Product& product);
    void capital_change(const std::vector<double>& data);
    void update_agent_preference();
    int get_capital() const;
    const std::vector<int>& get_agent_10y_history() const;
    const std::map<int, double>& get_agent_preference_seller() const;

private:
    double capital;
    std::vector<int> agent_10y_history;
    std::map<int, double> agent_preference_seller;
};


#endif //SIMULATIONT_CONSUMER_H
