#include "repository_medicine.h"

vector<Medicine> MedicineRepository::getList() {
    return list;
}

size_t MedicineRepository::getSizeList() {
    return list.size();
}

Medicine MedicineRepository::getMedicine(size_t index) {
    return list[index];
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

void MedicineRepository::modifyMedicine(const Medicine &old_medicine, const Medicine &new_medicine) {
    for(Medicine & medicine:list) {
        if(medicine == old_medicine) {
            medicine = new_medicine;
            return;
        }
    }
}