#include "Supplier.hpp"

Supplier::Supplier() : m_Bulstat(""), m_Name(""), m_Location(""), m_Phone("") {}

Supplier::Supplier(std::string bulstat, std::string name, std::string location, std::string phone)
    : m_Bulstat(bulstat), m_Name(name), m_Location(location), m_Phone(phone) {}


void Supplier::addMaterial(const OpticMaterial& material)
{
    m_Materials.push_back(material);
}

void Supplier::listMaterials() const 
{
    for (size_t i = 0; i < m_Materials.size(); i++) 
    {
        std::cout << i + 1 << ". " << m_Materials[i] << std::endl;
    }
}

float Supplier::orderMaterials(const std::vector<int>& materialIndexes) const 
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

std::ostream& operator<<(std::ostream& os, const Supplier& s) 
{
    os << "Bulstat: " << s.m_Bulstat << ", Name: " << s.m_Name << ", Location: " << s.m_Location
       << ", Phone: " << s.m_Phone;
       
    return os;
}