#include <cassert>

#include "test_service_medicine.h"
#include "service_medicine.h"

void runTestService() {
    ServiceMedicine service;
    My_list<Medicine> list;
    My_list<Medicine> medicineList = {Medicine(1, "Aspirin", "Bayer", "Acetylsalicylic Acid", 5.0),
                                     Medicine(2, "Ibuprofen", "Pfizer", "Ibuprofen", 10.0),
                                     Medicine(3, "Acetaminophen", "Johnson & Johnson", "Acetaminophen", 8.0),
                                     Medicine(4, "Lisinopril", "AstraZeneca", "Lisinopril", 20.0),
                                     Medicine(5, "Loratadine", "Bayer", "Acetaminophen", 15.0)} ;

    list = service.getAll();
    assert(list.empty());

    ///Test addMedicine
    for(size_t i = 0; i < 5; ++i) {
        service.addMedicine(medicineList[i].getName(),
                            medicineList[i].getProducer(),
                            medicineList[i].getActiveSubstance(),
                            medicineList[i].getPrice());
    }
    list = service.getAll();
    assert(list == medicineList);

    ///Test removeMedicine
    service.removeMedicine(3);
    list = service.getAll();
    assert(list[0] == medicineList[0]);
    assert(list[1] == medicineList[1]);
    assert(list[2] == medicineList[3]);
    assert(list[3] == medicineList[4]);

    ///Test modifyMedicine
    service.modifyMedicine(4, medicineList[2].getName(),
                                medicineList[2].getProducer(),
                                medicineList[2].getActiveSubstance(),
                                medicineList[2].getPrice());
    list = service.getAll();
    assert(list[0] == medicineList[0]);
    assert(list[1] == medicineList[1]);
    assert(list[2] == Medicine(4, "Acetaminophen", "Johnson & Johnson", "Acetaminophen", 8.0));
    assert(list[3] == medicineList[4]);

    ///Test findMedicine
    Medicine medicine = service.findMedicine("Loratadine", "Bayer", "Acetaminophen");
    assert(medicine == medicineList[4]);
    medicine = service.findMedicine("Acetaminophen", "Johnson & Johnson", "Loratadine");
    assert(medicine == Medicine(-1, "Unfounded", "Unfounded", "Unfounded", -1));

    ///Test filterByPrice
    My_list<Medicine> filtered_by_price = service.filterByPrice(14);
    assert(filtered_by_price[0] == medicineList[0]);
    assert(filtered_by_price[1] == medicineList[1]);
    assert(filtered_by_price[2] == Medicine(4, "Acetaminophen", "Johnson & Johnson", "Acetaminophen", 8.0));

    ///Test filerByActiveSubstance
    My_list<Medicine> filtered_by_active_substance = service.filerByActiveSubstance("Acetaminophen");
    assert(filtered_by_active_substance[0] == Medicine(4, "Acetaminophen", "Johnson & Johnson", "Acetaminophen", 8.0));

    ///Test sortByName
    My_list<Medicine> list_sorted_by_name = service.sortByName();
    assert(list_sorted_by_name[0] == Medicine(4, "Acetaminophen", "Johnson & Johnson", "Acetaminophen", 8.0));
    assert(list_sorted_by_name[1] == medicineList[0]);
    assert(list_sorted_by_name[2] == medicineList[1]);
    assert(list_sorted_by_name[3] == medicineList[4]);

    ///Test sortByProducer
    My_list<Medicine> list_sorted_by_Producer = service.sortByProducer();
    assert(list_sorted_by_Producer[0] == medicineList[0]);
    assert(list_sorted_by_Producer[1] == medicineList[4]);
    assert(list_sorted_by_Producer[2] == Medicine(4, "Acetaminophen", "Johnson & Johnson", "Acetaminophen", 8.0));
    assert(list_sorted_by_Producer[3] == medicineList[1]);

    ///Test sortByActiveSubstanceAndPrice
    My_list<Medicine> list_sorted_by_active_substance_and_price = service.sortByActiveSubstanceAndPrice();
    assert(list_sorted_by_active_substance_and_price[0] == Medicine(4, "Acetaminophen", "Johnson & Johnson", "Acetaminophen", 8.0));
    assert(list_sorted_by_active_substance_and_price[1] == medicineList[4]);
    assert(list_sorted_by_active_substance_and_price[2] == medicineList[0]);
    assert(list_sorted_by_active_substance_and_price[3] == medicineList[1]);
}

