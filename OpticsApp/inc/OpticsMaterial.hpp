#ifndef OPTICSMATERIAL_HPP
#define OPTICSMATERIAL_HPP

#include <iostream>
#include <string>

class OpticMaterial {
public:
    OpticMaterial();
    OpticMaterial(std::string type, float thickness, float diopter, std::string material, float price);

    std::string getType() const { return m_Type; }
    std::string getMaterial() const { return m_Material; }
    float getThickness() const { return m_Thickness; }
    float getPrice() const { return m_Price; }
    float getDiopter() const { return m_Diopter; }

    friend std::ostream& operator<<(std::ostream& os, const OpticMaterial& om);

private:
    std::string m_Type;
    float m_Thickness;
    float m_Diopter;
    std::string m_Material;
    float m_Price;
};

#endif // OPTICSMATERIAL_HPP