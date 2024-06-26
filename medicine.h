#ifndef FARMACIE_MEDICINE_H
#define FARMACIE_MEDICINE_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

typedef unsigned long long ID;
typedef double Price;

class Medicine{
private:
    ID id;
    string name;
    string producer;
    string active_substance;
    Price price;
public:

    Medicine();
    Medicine(ID id,
             string name,
             string producer,
             string active_substance,
             Price price);
    Medicine(const Medicine &other);
    ~Medicine() = default;

    bool operator==(const Medicine & medicine) const;
    Medicine& operator=(const Medicine & other);
    friend ostream& operator<<(ostream& os, const Medicine& medicine);

    [[nodiscard]] ID getID() const;
    [[nodiscard]] string getName() const;
    [[nodiscard]] string getProducer() const;
    [[nodiscard]] string getActiveSubstance() const;
    [[nodiscard]] Price getPrice() const;

    void setName(const string & new_name);
    void setProducer(const string & new_producer);
    void setActiveSubstance(const string & new_active_substance);
    void setPrice(Price new_price);
};

#endif //FARMACIE_MEDICINE_H
