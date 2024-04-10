#include <iostream>

#include "ui.h"

using std::cin;
using std::cout;

void UI::preloadData() {
    vector<Medicine> medicineList = {Medicine(1, "Aspirin", "Bayer", "Acetylsalicylic Acid", 5.0),
                                     Medicine(2, "Ibuprofen", "Pfizer", "Ibuprofen", 10.0),
                                     Medicine(3, "Acetaminophen", "Johnson & Johnson", "Acetaminophen", 8.0),
                                     Medicine(4, "Lisinopril", "AstraZeneca", "Lisinopril", 20.0),
                                     Medicine(5, "Loratadine", "Bayer", "Acetaminophen", 15.0)} ;

    for(size_t i = 0; i < 5; ++i) {
        service.addMedicine(medicineList[i].getName(),
                            medicineList[i].getProducer(),
                            medicineList[i].getActiveSubstance(),
                            medicineList[i].getPrice());
    }
}

void UI::runUI() {
    bool finished = false;
    string command;
    preloadData();

    while (not finished) {
        cout << ">>> ";
        cin >> command;
        cout << '\n';
        switch (command[0]) {
            case 'a': {
                if (command == "add") {
                    runAdd();
                }
                break;
            }
            case 'r': {
                if (command == "remove") {
                    runRemove();
                }
                break;
            }
            case 'e': {
                if (command == "exit") {
                    finished = true;
                }
                break;
            }
            case 'f': {
                if (command == "find") {
                    runFind();
                }
                if (command == "filter_by_price") {
                    runFilterByPrice();
                }
                if (command == "filter_by_substance") {
                    runFilterByActiveSubstance();
                }
                break;
            }
            case 's': {
                if (command == "sort_by_name") {
                    runSortByName();
                }
                if (command == "sort_by_producer") {
                    runSortByProducer();
                }
                if (command == "sort_by_substance") {
                    runSortByActiveSubstanceAndPrice();
                }
                break;
            }
            case 'p': {
                if (command == "print") {
                    runPrint();
                }
                break;
            }
            case 'm': {
                if (command == "modify") {
                    runModify();
                }
                break;
            }
            default: {
                break;
            }
        }
    }

}

void print(const vector<Medicine> & list) {
    for(const Medicine & medicine:list) {
        cout << medicine;
    }
}

void UI::runPrint() {
    const vector<Medicine>& list = service.getAll();
    print(list);
}

void UI::runAdd() {
    string name, producer, active_substance;
    Price price = -1;

    cout << "Name: ";
    cin >> name;
    cout << "Producer: ";
    cin >> producer;
    cout << "Active Substance: ";
    cin >> active_substance;
    cout << "Price: ";
    cin >> price;
    cout << '\n';

    service.addMedicine(name, producer, active_substance, price);
}

void UI::runRemove() {
    ID id = -1;

    cout << "ID: ";
    cin >> id;
    cout << '\n';

    service.removeMedicine(id);
}

void UI::runModify() {
    ID id = -1;
    string new_name, new_producer, new_active_substance;
    Price new_price = -1;

    cout << "ID: ";
    cin >> id;
    cout << "New Name: ";
    cin >> new_name;
    cout << "New Producer: ";
    cin >> new_producer;
    cout << "New Active Substance: ";
    cin >> new_active_substance;
    cout << "New Price: ";
    cin >> new_price;
    cout << '\n';

    service.modifyMedicine(id, new_name, new_producer, new_active_substance, new_price);
}

void UI::runFind() {
    string name, producer, active_substance;

    cout << "Name: ";
    cin >> name;
    cout << "Producer: ";
    cin >> producer;
    cout << "Active Substance: ";
    cin >> active_substance;
    cout << '\n';

    Medicine medicine = service.findMedicine(name, producer, active_substance);

    cout << medicine;
}

void UI::runFilterByPrice() {
    Price price = -1;

    cout << "Price: ";
    cin >> price;
    cout << '\n';

    vector<Medicine> list = service.filterByPrice(price);

    print(list);
}

void UI::runFilterByActiveSubstance() {
    string active_substance;

    cout << "Active Substance: ";
    cin >> active_substance;
    cout << '\n';

    vector<Medicine> list = service.filerByActiveSubstance(active_substance);

    print(list);
}

void UI::runSortByName() {
    vector<Medicine> list = service.sortByName();
    print(list);
}

void UI::runSortByProducer() {
    vector<Medicine> list = service.sortByProducer();
    print(list);
}

void UI::runSortByActiveSubstanceAndPrice() {
    vector<Medicine> list = service.sortByActiveSubstanceAndPrice();
    print(list);
}