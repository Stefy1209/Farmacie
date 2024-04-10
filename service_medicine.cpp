#include <algorithm>
#include <vector>

#include "service_medicine.h"

using std::sort;
using std::vector;

void ServiceMedicine::addMedicine(const std::string &name, const std::string &producer,
                                  const std::string &active_substance, Price price) {
    for(size_t index = 0; index < main_data.getSizeList(); ++index) {
        Medicine aux = main_data.getMedicine(index);
        if(aux.getName() == name and
           aux.getProducer() == producer and
           aux.getActiveSubstance() == active_substance and
           aux.getPrice() == price)
            throw std::out_of_range("Medicine already exists\n");
    }

    ID id = 1;
    if(not main_data.getList().empty()) {
        id = main_data.getMedicine(main_data.getSizeList() - 1).getID() + 1;//the id of the last medicine + 1
    }
    Medicine medicine(id, name, producer, active_substance, price);

    main_data.addMedicine(medicine);
}

void ServiceMedicine::removeMedicine(ID id) {
    for(size_t index = 0; index < main_data.getSizeList(); ++index) {
        Medicine medicine = main_data.getMedicine(index);
        if(medicine.getID() == id) {
            main_data.removeMedicine(medicine);
            return;
        }
    }

    throw std::out_of_range("Medicine doesn't exist\n");
}

void ServiceMedicine::modifyMedicine(ID id, const std::string &new_name, const std::string &new_producer,
                                     const std::string &new_active_substance, Price new_price) {
    Medicine new_medicine(id, new_name, new_producer, new_active_substance, new_price);
    for(size_t index = 0; index < main_data.getSizeList(); ++index) {
        Medicine medicine = main_data.getMedicine(index);
        if(medicine.getID() == new_medicine.getID()) {
            main_data.modifyMedicine(medicine, new_medicine);
            return;
        }
    }

    throw std::out_of_range("Medicine doesn't exist\n");
}

My_list<Medicine> & ServiceMedicine::getAll() {
    return main_data.getList();
}

Medicine ServiceMedicine::findMedicine(const std::string &name, const std::string &producer,
                                       const std::string &active_substance) {
    Medicine medicine( -1, "Unfounded", "Unfounded", "Unfounded", -1);

    for(size_t index = 0; index < main_data.getSizeList(); ++index) {
        Medicine aux = main_data.getMedicine(index);
        if( aux.getName() ==  name and
            aux.getProducer() == producer and
            aux.getActiveSubstance() == active_substance) {
            medicine = aux;
            return medicine;
        }
    }

    return medicine;}

My_list<Medicine> ServiceMedicine::filterByPrice(Price price) {
    My_list<Medicine> list_filtered;

    for(size_t index = 0; index < main_data.getSizeList(); ++index) {
        Medicine medicine = main_data.getMedicine(index);
        if(medicine.getPrice() <= price) {
            list_filtered.add(medicine);
        }
    }

    return list_filtered;}

My_list<Medicine> ServiceMedicine::filerByActiveSubstance(const string &active_substance) {
    My_list<Medicine> list_filtered;

    for(size_t index = 0; index < main_data.getSizeList(); ++index) {
        Medicine medicine = main_data.getMedicine(index);
        if(medicine.getActiveSubstance() == active_substance) {
            list_filtered.add(medicine);
        }
    }

    return list_filtered;}

bool compareByName(const Medicine &a, const Medicine &b) {
    //if(a.getName() == b.getName())
        //return a.getID() < b.getID();
    return a.getName() < b.getName();
}

My_list<Medicine> ServiceMedicine::sortByName() {
    My_list<Medicine> list_ordered;
    vector<Medicine> vector;

    for(size_t index = 0; index < main_data.getSizeList(); ++index) {
        vector.push_back(main_data.getMedicine(index));
    }

    sort(vector.begin(), vector.end(), compareByName);

    for(const Medicine& medicine:vector) {
        list_ordered.add(medicine);
    }

    return list_ordered;}

bool compareByProducer(const Medicine &a, const Medicine &b) {
    if(a.getProducer() == b.getProducer())
        return a.getID() < b.getID();
    return a.getProducer() < b.getProducer();
}

My_list<Medicine> ServiceMedicine::sortByProducer() {
    My_list<Medicine> list_ordered;
    vector<Medicine> vector;

    for(size_t index = 0; index < main_data.getSizeList(); ++index) {
        vector.push_back(main_data.getMedicine(index));
    }

    sort(vector.begin(), vector.end(), compareByProducer);

    for(const Medicine& medicine:vector) {
        list_ordered.add(medicine);
    }

    return list_ordered;}

bool compareByActiveSubstanceAndPrice(const Medicine &a, const Medicine &b) {
    if(a.getActiveSubstance() == b.getActiveSubstance())
        return a.getPrice() < b.getPrice();
    return a.getActiveSubstance() < b.getActiveSubstance();
}

My_list<Medicine> ServiceMedicine::sortByActiveSubstanceAndPrice() {
    My_list<Medicine> list_ordered;

    vector<Medicine> vector;

    for(size_t index = 0; index < main_data.getSizeList(); ++index) {
        vector.push_back(main_data.getMedicine(index));
    }

    sort(vector.begin(), vector.end(), compareByActiveSubstanceAndPrice);

    for(const Medicine& medicine:vector) {
        list_ordered.add(medicine);
    }

    return list_ordered;}// in mod normal nu imi place sa pun asa paranteza dar altfel nu imi arata 100% coverage soooooo !!!F#CK YOU CLION!!!