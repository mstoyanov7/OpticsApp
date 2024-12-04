#include "SupplierManagement.hpp"

void SupplierManagement::Run()
{   
    loadDatabase();

    int menuSelection;
    do {
        menuSelection = Utility::MainMenuGetChoice();
        
        switch (menuSelection)
        {   
            case SHOPPING_MENU: showShoppingMenu(); break;
            case MANAGER_MENU: showManagerMenu(); break;
            case EXIT: saveDatabase(); break;
            default: std::cout << "Invalid choice. Please try again." << std::endl; break;
        }  
    } while (menuSelection != EXIT);
}

void SupplierManagement::addSupplier(const Supplier& supplier) 
{
    m_Suppliers.push_back(supplier);
}

void SupplierManagement::listSuppliers() const 
{
    for (int i = 0; i < m_Suppliers.size(); ++i) 
    {
        std::cout << i + 1 << ". " << m_Suppliers[i] << std::endl;
    }
}

Supplier* SupplierManagement::selectSupplier(const int& index) 
{
    if (index >= 0 && index < m_Suppliers.size()) 
    {
        return &m_Suppliers[index];
    }
    return nullptr;
}

void SupplierManagement::removeSupplier(const int& index)
{
    if (index >= 0 && index < m_Suppliers.size())
    {
        m_Suppliers.erase(m_Suppliers.begin() + index);
    }
}

void SupplierManagement::modifySupplier(const int& index)
{
    if (index >= 0 && index < m_Suppliers.size())
    {
        std::cout << "\nEnter new details for supplier (leave empty to keep current value):" << std::endl;
        std::string bulstat, name, location, phone;

        std::cout << "Bulstat (current: " << m_Suppliers[index].getBulstat() << "): ";
        getline(std::cin, bulstat);
        if (!bulstat.empty()) m_Suppliers[index].setBulstat(bulstat);

        std::cout << "Name (current: " << m_Suppliers[index].getName() << "): ";
        getline(std::cin, name);
        if (!name.empty()) m_Suppliers[index].setName(name);

        std::cout << "Location (current: " << m_Suppliers[index].getLocation() << "): ";
        getline(std::cin, location);
        if (!location.empty()) m_Suppliers[index].setLocation(location);

        std::cout << "Phone (current: " << m_Suppliers[index].getPhone() << "): ";
        getline(std::cin, phone);
        if (!phone.empty()) m_Suppliers[index].setPhone(phone);
    }
}

void SupplierManagement::loadDatabase()
{
    std::ifstream infile(DATABASE);

    if (!infile.is_open())
    {
       std::cerr << "Failed to open the file or file was not found!" << std::endl;
       return;
    }

    std::string line;
    bool needToProcessLine = false;

    while (needToProcessLine || std::getline(infile, line))
    {
        if (!needToProcessLine)
        {
            Utility::trimWhitespaces(line);
        }

        needToProcessLine = false;

        if (line.empty()) continue;

        if (line.substr(0, 10) == "[Supplier]")
        {
            std::string supplierInfo = line.substr(10);
            Utility::trimWhitespaces(supplierInfo);

            std::stringstream ss(supplierInfo);
            std::string bulstat, name, location, phone;

            std::getline(ss, bulstat, ',');
            std::getline(ss, name, ',');
            std::getline(ss, location, ',');
            std::getline(ss, phone, ',');

            Utility::trimWhitespaces(bulstat);
            Utility::trimWhitespaces(name);
            Utility::trimWhitespaces(location);
            Utility::trimWhitespaces(phone);

            Supplier supplier(bulstat, name, location, phone);

            while (std::getline(infile, line))
            {
                Utility::trimWhitespaces(line);
                if (line.substr(0, 9) == "[Product]")
                {
                    std::string productInfo = line.substr(9);
                    Utility::trimWhitespaces(productInfo);

                    std::stringstream ssProduct(productInfo);
                    std::string type, thicknessStr, diopterStr, material, priceStr;

                    std::getline(ssProduct, type, ',');
                    std::getline(ssProduct, thicknessStr, ',');
                    std::getline(ssProduct, diopterStr, ',');
                    std::getline(ssProduct, material, ',');
                    std::getline(ssProduct, priceStr, ',');

                    Utility::trimWhitespaces(type);
                    Utility::trimWhitespaces(thicknessStr);
                    Utility::trimWhitespaces(diopterStr);
                    Utility::trimWhitespaces(material);
                    Utility::trimWhitespaces(priceStr);

                    float thickness = std::stof(thicknessStr);
                    float diopter = std::stof(diopterStr);
                    float price = std::stof(priceStr);

                    OpticMaterial product(type, thickness, diopter, material, price);
                    supplier.addMaterial(product);
                }
                else if (line.substr(0, 10) == "[Supplier]")
                {
                    needToProcessLine = true;
                    break;
                }
            }
            m_Suppliers.push_back(supplier);
        }
    }
}

void SupplierManagement::saveDatabase()
{
    std::ofstream outfile(DATABASE);
    if (!outfile.is_open())
    {
        std::cerr << "Failed to open the file for writing." << std::endl;
        return;
    }

    for (const auto& supplier : m_Suppliers)
    {
        outfile << "[Supplier] " << supplier.getBulstat() << ", " << supplier.getName() << ", "
                << supplier.getLocation() << ", " << supplier.getPhone() << "\n";

        for (const auto& product : supplier.getMaterials())
        {
            outfile << "[Product] " << product.getType() << ", " << product.getThickness() << ", "
                    << product.getDiopter() << ", " << product.getMaterial() << ", " << product.getPrice() << "\n";
        }
        
        outfile << "\n"; // Add an empty line between suppliers
    }

    outfile.close();
}

void SupplierManagement::showShoppingMenu()
{   
    if (isSuppliersListEmpty())
    {
        std::cout << "No suppliers in database! Please add suppliers to enable shopping option.\n";
        return;
    }

    listSuppliers();
    Supplier* selectedSupplier = selectSupplier(Utility::ShoppingMenuGetChoice());

    if (selectedSupplier) {
        std::cout << "\nMaterials available from " << selectedSupplier->getName() << ":" << std::endl;

        selectedSupplier->listMaterials();

        std::vector<int> orderIndexes;
        int index;

        std::cout << "\nEnter the indexes of the materials to order (enter -1 to finish): " << std::endl;

        while (true)
        {
            std::cin >> index;
            if (index == -1) break;
            orderIndexes.push_back(index - 1);
        }

        float totalPrice = selectedSupplier->orderMaterials(orderIndexes);
        std::cout << "\nTotal order price: " << totalPrice << " lv" << std::endl;
    }
}

void SupplierManagement::showManagerMenu()
{
    int managerMenuChoice;
    do {
        Utility::ManagerMenuGetChoice(managerMenuChoice);

        switch (managerMenuChoice)
        {
            case ADD_SUPPLIER:
            {   
                std::string bulstat, name, location, phone;
                std::cout << "Enter supplier details:" << std::endl;

                std::cout << "Bulstat: ";
                getline(std::cin, bulstat);

                std::cout << "Name: ";
                getline(std::cin, name);

                std::cout << "Location: ";
                getline(std::cin, location);

                std::cout << "Phone: ";
                getline(std::cin, phone);

                Supplier newSupplier = Supplier(bulstat, name, location, phone);

                if (Utility::AddProducts())
                {
                    int numProducts;
                    std::cout << "\nHow many products do you want to add? \n";
                    std::cin >> numProducts;
                    std::cin.ignore();

                    for (int i = 0; i < numProducts; ++i)
                    {
                        std::string type, material;
                        float thickness, diopter, price;

                        std::cout << "\nEnter details for product " << i + 1 << ":" << std::endl;
                        std::cout << "Type: ";
                        getline(std::cin, type);

                        std::cout << "Thickness (mm): ";
                        std::cin >> thickness;
                        std::cin.ignore();

                        std::cout << "Diopter: ";
                        std::cin >> diopter;
                        std::cin.ignore();

                        std::cout << "Material: ";
                        getline(std::cin, material);

                        std::cout << "Price (lv): ";
                        std::cin >> price;
                        std::cin.ignore();

                        OpticMaterial newMaterial(type, thickness, diopter, material, price);
                        newSupplier.addMaterial(newMaterial);
                    }
                }
                addSupplier(newSupplier);
                break;
            }

            case REMOVE_SUPPLIER:
            {
                if (!isSuppliersListEmpty())
                {   
                    listSuppliers();

                    int removeIndex;

                    std::cout << "\nEnter the number of the supplier to remove: ";
                    std::cin >> removeIndex;
                    std::cin.ignore();

                    removeSupplier(removeIndex - 1);

                    break; 
                }

                system("cls");
                std::cout << "Suppliers list is empty!\n\n";
                break;
            }

            case MODIFY_SUPPLIER: {
                if (!isSuppliersListEmpty())
                {    
                    listSuppliers();

                    int modifyIndex;

                    std::cout << "\nEnter the number of the supplier to modify: ";
                    std::cin >> modifyIndex;
                    std::cin.ignore();

                    modifySupplier(modifyIndex - 1);
                    break;
                }

                system("cls");
                std::cout << "Suppliers list is empty!\n\n";
                break;
            }

            case EXIT_MANAGER_MENU: break;
            default: std::cout << "Invalid choice. Please try again." << std::endl; break;
        }
    } while (managerMenuChoice != EXIT_MANAGER_MENU);
}

bool SupplierManagement::isSuppliersListEmpty() const
{ 
    return m_Suppliers.empty();
}