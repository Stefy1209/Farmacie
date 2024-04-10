#include "test_medicine.h"
#include "test_repository_medicine.h"
#include "test_service_medicine.h"
#include "ui.h"

int main() {
    runTestMedicine();
    runTestRepository();
    runTestService();
    UI ui;
    ui.runUI();
    return 0;
}
