#ifndef FARMACIE_REPOSITORY_MEDICINE_H
#define FARMACIE_REPOSITORY_MEDICINE_H

#include <vector>

#include "medicine.h"

using std::vector;
using std::find;

class MedicineRepository {
private:
    vector<Medicine> list;
public:
    vector<Medicine> getList();

    void addMedicine(const Medicine & medicine);
    void removeMedicine(const Medicine & medicine);
};

#endif //FARMACIE_REPOSITORY_MEDICINE_H
