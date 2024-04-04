#include <cassert>

#include "test_medicine.h"
#include "medicine.h"

void runTestMedicine() {
    Medicine medicine1;
    assert(medicine1.getID() == 0);
    assert(medicine1.getName() == "Unknown");
    assert(medicine1.getProducer() == "Unknown");
    assert(medicine1.getActiveSubstance() == "Unknown");
    assert(medicine1.getPrice() == -1);

    Medicine medicine2(1, "Nurofen", "cineva =)", "ibuprofen", 20.49);
    assert(medicine2.getID() == 1);
    assert(medicine2.getName() == "Nurofen");
    assert(medicine2.getProducer() == "cineva =)");
    assert(medicine2.getActiveSubstance() == "ibuprofen");
    assert(medicine2.getPrice() == 20.49);

    medicine1 = medicine2;
    assert(medicine1.getID() == 1);
    assert(medicine1.getName() == "Nurofen");
    assert(medicine1.getProducer() == "cineva =)");
    assert(medicine1.getActiveSubstance() == "ibuprofen");
    assert(medicine1.getPrice() == 20.49);

    medicine2.setName("alt nume");
    assert(medicine2.getName() == "alt nume");

    medicine2.setProducer("alt producator");
    assert(medicine2.getProducer() == "alt producator");

    medicine2.setActiveSubstance("alta substanta");
    assert(medicine2.getActiveSubstance() == "alta substanta");

    medicine2.setPrice(19);
    assert(medicine2.getPrice() == 19);
}
