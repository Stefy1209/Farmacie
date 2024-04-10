#include <algorithm>

#include "service_medicine.h"

using std::sort;

void ServiceMedicine::addMedicine(const std::string &name, const std::string &producer,
                                  const std::string &active_substance, Price price) {
    ID id = 1;
    if(not main_data.getList().empty()) {
        id = main_data.getMedicine(main_data.getSizeList() - 1).getID() + 1;//the id of the last medicine + 1
    }
    Medicine medicine(id, name, producer, active_substance, price);
    main_data.addMedicine(medicine);
}

void ServiceMedicine::removeMedicine(ID id) {
    for(const Medicine & medicine:main_data.getList()) {
        if(medicine.getID() == id) {
            main_data.removeMedicine(medicine);
            return;
        }
    }
}

void ServiceMedicine::modifyMedicine(ID id, const std::string &new_name, const std::string &new_producer,
                                     const std::string &new_active_substance, Price new_price) {
    Medicine new_medicine(id, new_name, new_producer, new_active_substance, new_price);
    for(const Medicine & medicine:main_data.getList()) {
        if(medicine.getID() == new_medicine.getID()) {
            main_data.modifyMedicine(medicine, new_medicine);
            return;
        }
    }
}

vector<Medicine>& ServiceMedicine::getAll() {
    return main_data.getList();
}

Medicine ServiceMedicine::findMedicine(const std::string &name, const std::string &producer,
                                       const std::string &active_substance) {
    Medicine medicine( -1, "Unfounded", "Unfounded", "Unfounded", -1);

    for(const Medicine & aux:main_data.getList()) {
        if( aux.getName() ==  name and
            aux.getProducer() == producer and
            aux.getActiveSubstance() == active_substance) {
            medicine = aux;
            return medicine;
        }
    }

    return medicine;}

vector<Medicine> ServiceMedicine::filterByPrice(Price price) {
    vector<Medicine> list_filtered;

    for(const Medicine & medicine:main_data.getList()) {
        if(medicine.getPrice() <= price) {
            list_filtered.push_back(medicine);
        }
    }

    return list_filtered;}

vector<Medicine> ServiceMedicine::filerByActiveSubstance(const std::string &active_substance) {
    vector<Medicine> list_filtered;

    for(const Medicine & medicine:main_data.getList()) {
        if(medicine.getActiveSubstance() == active_substance) {
            list_filtered.push_back(medicine);
        }
    }

    return list_filtered;}

bool compareByName(const Medicine &a, const Medicine &b) {
    //if(a.getName() == b.getName())
        //return a.getID() < b.getID();
    return a.getName() < b.getName();
}

vector<Medicine> ServiceMedicine::sortByName() {
    vector<Medicine> list_ordered = main_data.getList();

    sort(list_ordered.begin(), list_ordered.end(), compareByName);

    return list_ordered;}

bool compareByProducer(const Medicine &a, const Medicine &b) {
    if(a.getProducer() == b.getProducer())
        return a.getID() < b.getID();
    return a.getProducer() < b.getProducer();
}

vector<Medicine> ServiceMedicine::sortByProducer() {
    vector<Medicine> list_ordered = main_data.getList();

    sort(list_ordered.begin(), list_ordered.end(), compareByProducer);

    return list_ordered;}

bool compareByActiveSubstanceAndPrice(const Medicine &a, const Medicine &b) {
    if(a.getActiveSubstance() == b.getActiveSubstance())
        return a.getPrice() < b.getPrice();
    return a.getActiveSubstance() < b.getActiveSubstance();
}

vector<Medicine> ServiceMedicine::sortByActiveSubstanceAndPrice() {
    vector<Medicine> list_ordered = main_data.getList();

    sort(list_ordered.begin(), list_ordered.end(), compareByActiveSubstanceAndPrice);

    return list_ordered;}// in mod normal nu imi place sa pun asa paranteza dar altfel nu imi arata 100% coverage soooooo !!!F#CK YOU CLION!!!