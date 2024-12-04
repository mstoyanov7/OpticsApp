#ifndef SUPPLIER_HPP
#define SUPPLIER_HPP

#include "OpticsMaterial.hpp"

#include <vector>

class Supplier {
public:
    Supplier();
    Supplier(std::string bulstat, std::string name, std::string location, std::string phone);

    std::string getBulstat() const { return m_Bulstat; }
    std::string getName() const { return m_Name; }
    std::string getLocation() const { return m_Location; }
    std::string getPhone() const { return m_Phone; }
    
    std::vector<OpticMaterial> getMaterials() const {return m_Materials; }

    void setBulstat(const std::string& bulstat) {m_Bulstat = bulstat;}
    void setName(const std::string& name) {m_Name = name;}
    void setLocation(const std::string& location) {m_Location = location;}
    void setPhone(const std::string& phone) {m_Phone = phone;}

    void addMaterial(const OpticMaterial& material);
    void listMaterials() const;

    float orderMaterials(const std::vector<int>& materialIndexes) const;

    friend std::ostream& operator<<(std::ostream& os, const Supplier& s);

private:
    std::string m_Bulstat;
    std::string m_Name;
    std::string m_Location;
    std::string m_Phone;
    std::vector<OpticMaterial> m_Materials;
};

#endif // SUPPLIER_HPP