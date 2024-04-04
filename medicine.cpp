#include "medicine.h"

#include <utility>

Medicine::Medicine() {
    id = 0;
    name = "Unknown";
    producer = "Unknown";
    active_substance = "Unknown";
    price = -1;
}

Medicine::Medicine(ID id, std::string name, std::string producer, std::string active_substance,
                   Price price): id(id), name(std::move(name)), producer(std::move(producer)), active_substance(std::move(active_substance)), price(price) {}

ID Medicine::getID() const {
    return id;
}

string Medicine::getName() const {
    return name;
}

string Medicine::getProducer() const {
    return producer;
}

string Medicine::getActiveSubstance() const {
    return active_substance;
}

Price Medicine::getPrice() const {
    return price;
}

void Medicine::setName(const std::string & new_name) {
    name = new_name;
}

void Medicine::setProducer(const std::string & new_producer) {
    producer = new_producer;
}

void Medicine::setActiveSubstance(const std::string &new_active_substance) {
    active_substance = new_active_substance;
}

void Medicine::setPrice(Price new_price) {
    price = new_price;
}