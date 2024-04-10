#ifndef FARMACIE_REPOSITORY_MEDICINE_H
#define FARMACIE_REPOSITORY_MEDICINE_H

#include "medicine.h"
#include "my_list.h"

using std::find;

class MedicineRepository {
private:
    My_list<Medicine> list;
public:
    My_list<Medicine>& getList();
    size_t getSizeList();
    Medicine& getMedicine(size_t index);

    void addMedicine(const Medicine & medicine);
    void removeMedicine(const Medicine & medicine);
    void modifyMedicine(const Medicine & old_medicine, const Medicine & new_medicine);
};

#endif //FARMACIE_REPOSITORY_MEDICINE_H
