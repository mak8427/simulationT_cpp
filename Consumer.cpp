#include "Consumer.h"
#include "util.h"
#include <random>




double rand_choice(const std::vector<double>& data) {
    std::uniform_int_distribution<> dist(0, static_cast<int>(data.size()) - 1);
    return data[dist(gen)];
}

Consumer::Consumer(const std::vector<double>& data) {
    capital = rand_choice(data);
    agent_preference_seller = {{0, 0.0}, {1, 0.0}, {2, 0.0}};
}

double Consumer::product_score(const Product& product) {
    double score = 0.0;
    if (product.get_selling_price() > capital) {
        return score;
    }
    score += product.get_quality_factor() / product.get_selling_price() * 50.55555;
    score *= (0.7 + agent_preference_seller.at(product.get_seller_id()) * 0.2 + rand_in_range(0, 9) * 0.01);
    return score;
}

void Consumer::capital_change(const std::vector<double>& data) {
    capital = rand_choice(data);
}

void Consumer::update_agent_preference() {
    for (int i = 0; i < 3; ++i) {
        agent_preference_seller[i] = static_cast<double>(std::count(agent_10y_history.begin(), agent_10y_history.end(), i)) / 10.0;
    }
}

int Consumer::get_capital() const {
    return static_cast<int>(capital);
}

const std::vector<int>& Consumer::get_agent_10y_history() const {
    return agent_10y_history;
}

const std::map<int, double>& Consumer::get_agent_preference_seller() const {
    return agent_preference_seller;
}
