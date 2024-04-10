#ifndef FARMACIE_SERVICE_MEDICINE_H
#define FARMACIE_SERVICE_MEDICINE_H

#include "repository_medicine.h"

class ServiceMedicine {
private:
    MedicineRepository main_data;
public:
    void addMedicine(const string & name, const string & producer, const string & active_substance, Price price);
    void removeMedicine(ID id);
    void modifyMedicine(ID id, const string & new_name, const string & new_producer, const string & new_active_substance, Price new_price);
    My_list<Medicine> & getAll();

    Medicine findMedicine(const string & name, const string & producer, const string & active_substance);

    My_list<Medicine> filterByPrice(Price price);
    My_list<Medicine> filerByActiveSubstance(const string &active_substance);

    My_list<Medicine> sortByName();
    My_list<Medicine> sortByProducer();
    My_list<Medicine> sortByActiveSubstanceAndPrice();
};

#endif //FARMACIE_SERVICE_MEDICINE_H
