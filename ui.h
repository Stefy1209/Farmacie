#ifndef FARMACIE_UI_H
#define FARMACIE_UI_H

#include "service_medicine.h"

class UI {
private:
    ServiceMedicine service;

    void runAdd();
    void runRemove();
    void runModify();
    void runPrint();
    void preloadData();
    void runFind();
    void runFilterByPrice();
    void runFilterByActiveSubstance();
    void runSortByName();
    void runSortByProducer();
    void runSortByActiveSubstanceAndPrice();
public:
    void runUI();
};

#endif //FARMACIE_UI_H
