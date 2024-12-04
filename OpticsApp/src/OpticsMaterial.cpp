#include "OpticsMaterial.hpp"

OpticMaterial::OpticMaterial() : m_Type(""), m_Thickness(0.0), m_Diopter(0.0), m_Material(""), m_Price(0.0) {}

OpticMaterial::OpticMaterial(std::string type, float thickness, float diopter, std::string material, float price)
        : m_Type(type), m_Thickness(thickness), m_Diopter(diopter), m_Material(material), m_Price(price) {}

std::ostream& operator<<(std::ostream& os, const OpticMaterial& om)
{
    os << "Type: " << om.m_Type << ", Thickness: " << om.m_Thickness << "mm, Diopter: " << om.m_Diopter
       << ", Material: " << om.m_Material << ", Price: " << om.m_Price << " lv";
    return os;
}
