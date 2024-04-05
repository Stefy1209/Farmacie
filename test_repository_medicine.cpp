#include <cassert>

#include "test_repository_medicine.h"
#include "repository_medicine.h"

void runTestRepository() {
    MedicineRepository repository;
    vector<Medicine> listRepository;
    vector<Medicine> medicineList = {Medicine(1, "Aspirin", "Bayer", "Acetylsalicylic Acid", 5.0),
                                     Medicine(2, "Ibuprofen", "Pfizer", "Ibuprofen", 10.0),
                                     Medicine(3, "Acetaminophen", "Johnson & Johnson", "Acetaminophen", 8.0),
                                     Medicine(4, "Lisinopril", "AstraZeneca", "Lisinopril", 20.0),
                                     Medicine(5, "Loratadine", "Bayer", "Loratadine", 15.0)} ;


    ///Test addMedicine + getList
    for(const Medicine & medicine : medicineList) {
        repository.addMedicine(medicine);
    }

    listRepository = repository.getList();
    assert(listRepository == medicineList);
    assert(repository.getSizeList() == 5);

    ///Test getMedicine
    Medicine medicineAux;
    for(size_t index = 0; index < 5; ++index) {
        medicineAux = repository.getMedicine(index);
        assert(medicineAux == medicineList[index]);
    }

    ///Test removeMedicine
    ///First part tests if medicine is in repository
    ///Second part tests if it is not (nothing should have changed in repository)
    repository.removeMedicine(medicineList[4]);
    listRepository = repository.getList();
    assert(listRepository[0] == medicineList[0]);
    assert(listRepository[1] == medicineList[1]);
    assert(listRepository[2] == medicineList[2]);
    assert(listRepository[3] == medicineList[3]);

    repository.removeMedicine(medicineList[5]);
    listRepository = repository.getList();
    assert(listRepository[0] == medicineList[0]);
    assert(listRepository[1] == medicineList[1]);
    assert(listRepository[2] == medicineList[2]);
    assert(listRepository[3] == medicineList[3]);

    ///Test modifyMedicine
    repository.modifyMedicine(medicineList[2], medicineList[4]);
    listRepository = repository.getList();
    assert(listRepository[0] == medicineList[0]);
    assert(listRepository[1] == medicineList[1]);
    assert(listRepository[2] == medicineList[4]);
    assert(listRepository[3] == medicineList[3]);
}
