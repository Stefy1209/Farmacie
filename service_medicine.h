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
    vector<Medicine> getAll();

    Medicine findMedicine(const string & name, const string & producer, const string & active_substance);

    vector<Medicine> filterByPrice(Price price);
    vector<Medicine> filerByActiveSubstance(const string & active_substance);

    vector<Medicine> sortByName();
    vector<Medicine> sortByProducer();
    vector<Medicine> sortByActiveSubstanceAndPrice();
};

#endif //FARMACIE_SERVICE_MEDICINE_H
