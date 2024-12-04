#ifndef SUPPLIERMANAGEMENT_HPP
#define SUPPLIERMANAGEMENT_HPP

#include "Utility.hpp"
#include "Supplier.hpp"

class SupplierManagement
{
    public:
        SupplierManagement() = default;
        void Run();

    private:
        void addSupplier(const Supplier& supplier);
        void removeSupplier(const int& index);
        void modifySupplier(const int& index);
        void listSuppliers() const;

        Supplier* selectSupplier(const int& index);
        
        void loadDatabase();
        void saveDatabase();

        void showShoppingMenu();
        void showManagerMenu();
        
        bool isSuppliersListEmpty() const;

    private:
        std::vector<Supplier> m_Suppliers;
};

#endif // SUPPLIERMANAGEMENT_HPP