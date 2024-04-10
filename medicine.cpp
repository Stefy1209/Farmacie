#include <utility>
#include <iostream>

#include "medicine.h"

using std::cout;

Medicine::Medicine() : id(0), name("Unknown"), producer("Unknown"), active_substance("Unknown"), price(-1) {
}

Medicine::Medicine(ID id, std::string name, std::string producer, std::string active_substance,
                   Price price): id(id), name(std::move(name)), producer(std::move(producer)), active_substance(std::move(active_substance)), price(price) {}

Medicine::Medicine(const Medicine &other) :
        id(other.id),
        name(other.name),
        producer(other.producer),
        active_substance(other.active_substance),
        price(other.price)
{
    //cout << "COPIE FACUTA\n";
}


bool Medicine::operator==(const Medicine &medicine) const {
    return  this->id == medicine.id and
            this->name == medicine.name and
            this->producer == medicine.producer and
            this->active_substance == medicine.active_substance and
            this->price == medicine.price;
}

Medicine& Medicine::operator=(const Medicine &other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
        producer = other.producer;
        active_substance = other.active_substance;
        price = other.price;
    }
    return *this;
}

ostream& operator<<(std::ostream& os, const Medicine& medicine) {
    os << "ID: " << medicine.getID() << '\n';
    os << "Name: " << medicine.getName() << '\n';
    os << "Producer: " << medicine.getProducer() << '\n';
    os << "Active Substance: " << medicine.getActiveSubstance() << '\n';
    os << "Price: " << medicine.getPrice() << '\n';
    os << '\n';
    return os;
}

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