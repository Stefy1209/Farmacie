#include "repository_medicine.h"

vector<Medicine> MedicineRepository::getList() {
    return list;
}

void MedicineRepository::addMedicine(const Medicine &medicine) {
    list.push_back(medicine);
}

void MedicineRepository::removeMedicine(const Medicine &medicine) {
    auto index = find(list.begin(), list.end(), medicine);

    if(index != list.end()) {
        list.erase(index);
    }
}