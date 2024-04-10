#include "repository_medicine.h"

My_list<Medicine>& MedicineRepository::getList() {
    return list;
}

size_t MedicineRepository::getSizeList() {
    return list.getSize();
}

Medicine& MedicineRepository::getMedicine(size_t index) {
    return list.get(index);
}

void MedicineRepository::addMedicine(const Medicine &medicine) {
    list.add(medicine);
}

void MedicineRepository::removeMedicine(const Medicine &medicine) {
/*
    auto index = find(list.being(), list.end(), medicine);

    if(index != list.end()) {
        list.remove(index);
    }
*/
    list.remove(medicine);
}

void MedicineRepository::modifyMedicine(const Medicine &old_medicine, const Medicine &new_medicine) {
    for(size_t index = 0; index < list.getSize(); ++index) {
        Medicine& medicine = list.get(index);
        if(medicine == old_medicine) {
            medicine = new_medicine;
            return;
        }
    }
}