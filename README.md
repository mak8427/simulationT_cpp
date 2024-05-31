# Economic Simulation Project

This repository contains a C++ project for simulating a simple economic system involving products and consumers. The simulation models the interaction between consumers and products, allowing for the calculation of profits based on consumer purchasing decisions and product attributes.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Classes and Functions](#classes-and-functions)
- [Contributing](#contributing)

## Overview

The project simulates an economic environment where consumers purchase products based on their preferences and capital. The products have attributes like selling price, cost to produce, and quality factor. The simulation calculates profits for each product and updates consumer preferences over time.

## Features

- **Product and Consumer Classes**: Define the attributes and behaviors of products and consumers.
- **Randomized Data Generation**: Simulate realistic economic scenarios using random data generation.
- **Profit Calculation**: Compute profits for each product based on sales and production costs.
- **Consumer Preferences**: Update consumer preferences based on purchase history.
- **Performance Measurement**: Measure the time taken for various operations in the simulation.

## Installation

### Prerequisites

- C++ compiler (e.g., GCC, Clang, MSVC)
- CMake (optional, for building the project)

### Clone the Repository

```sh
git clone https://github.com/your-username/economic-simulation.git
cd economic-simulation
```

### Build the Project

Using CMake:

```sh
mkdir build
cd build
cmake ..
make
```

Or compile directly using a C++ compiler:

```sh
g++ -o simulation main.cpp Product.cpp Consumer.cpp util.cpp
```

## Usage

Run the simulation executable:

```sh
./simulation
```

The program will simulate the interactions between consumers and products, outputting the profits for each product and other relevant information.

## Classes and Functions

### Consumer Class

Defined in `Consumer.h` and `Consumer.cpp`.

- **Attributes**:
  - `capital`
  - `agent_preference_seller`
  - `agent_10y_history`
- **Methods**:
  - `product_score(const Product& product)`
  - `capital_change(const std::vector<double>& data)`
  - `update_agent_preference()`
  - `get_capital() const`
  - `get_agent_10y_history() const`
  - `get_agent_preference_seller() const`

### Product Class

Defined in `Product.h` and `Product.cpp`.

- **Attributes**:
  - `cost_to_produce`
  - `selling_price`
  - `number_produced`
  - `number_sold`
  - `seller_id`
  - `quality_factor`
  - `profit_history`
- **Methods**:
  - `calculate_profit() const`
  - `new_product()`
  - `get_quality_factor() const`
  - `get_seller_id() const`
  - `get_selling_price() const`
  - `get_cost_to_produce() const`
  - `get_number_produced() const`
  - `get_number_sold() const`
  - `increment_number_sold()`
  - `get_profit_history() const`

### Utility Functions

Defined in `util.h` and `util.cpp`.

- `double rand_choice(const std::vector<double>& data)`
- `double rand_in_range(double min, double max)`

### Main Functions

Defined in `main.cpp`.

- `void buy_product_for_agent(Consumer& agent, std::vector<Product>& product_list)`
- `void buy_product_for_agents(std::vector<Consumer>& agent_list, std::vector<Product>& product_list)`
- `void compute_profit(const std::vector<Product>& product_list)`

## Contributing

Contributions are welcome! Please fork this repository, create a new branch, and submit a pull request. Ensure your code follows the existing style and include comments where necessary.

### Steps to Contribute

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.

