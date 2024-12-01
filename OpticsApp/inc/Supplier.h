#include "OpticsMaterial.h"

#include <vector>

class Supplier {
public:
    Supplier() : m_Bulstat(""), m_Name(""), m_Location(""), m_Phone("") {}
    Supplier(std::string bulstat, std::string name, std::string location, std::string phone)
        : m_Bulstat(bulstat), m_Name(name), m_Location(location), m_Phone(phone) {}

    std::string getBulstat() const { return m_Bulstat; }
    std::string getName() const { return m_Name; }
    std::string getLocation() const { return m_Location; }
    std::string getPhone() const { return m_Phone; }

    void setBulstat(const std::string& bulstat) {m_Bulstat = bulstat;}
    void setName(const std::string& name) {m_Name = name;}
    void setLocation(const std::string& location) {m_Location = location;}
    void setPhone(const std::string& phone) {m_Phone = phone;}

    void addMaterial(const OpticMaterial& material)
    {
        m_Materials.push_back(material);
    }

    void listMaterials() const 
    {
        for (size_t i = 0; i < m_Materials.size(); i++) 
        {
            std::cout << i + 1 << ". " << m_Materials[i] << std::endl;
        }
    }

    float orderMaterials(const std::vector<int>& materialIndexes) const 
    {
        float total = 0.0;  
        for (int index : materialIndexes) 
        {
            if (index >= 0 && index < m_Materials.size()) 
            {
                total += m_Materials[index].getPrice();
            }
        }
        return total;
    }

    friend std::ostream& operator<<(std::ostream& os, const Supplier& s) 
    {
        os << "Bulstat: " << s.m_Bulstat << ", Name: " << s.m_Name << ", Location: " << s.m_Location
           << ", Phone: " << s.m_Phone;
           
        return os;
    }

private:
    std::string m_Bulstat;
    std::string m_Name;
    std::string m_Location;
    std::string m_Phone;
    std::vector<OpticMaterial> m_Materials;
};