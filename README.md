# Supplier Management Application Documentation
## Overview
The Supplier Management Application is a C++ software designed to manage suppliers and their associated materials, providing functionalities for adding, modifying, and removing suppliers, as well as shopping for optical materials from listed suppliers.

## Features

### Supplier Management:

- Add new suppliers.

- Modify supplier details.

- Remove existing suppliers.

- List all suppliers.

### Material Management:

- Add materials to a supplier.

- View a supplier's materials.
   
### Shopping:

- Select a supplier and view their materials.

- Order materials and calculate the total price.

### Data Persistence:

- Save supplier and material data to a file.
    
- Load supplier and material data from a file.

## Class Descriptions

### SupplierManagement

Header File: SupplierManagement.h

Implementation File: SupplierManagement.cpp

### Responsibilities:
Acts as the main interface for running the application.

Handles user interactions for supplier and material management.

Interfaces with the database for data persistence.

### Key Methods:
`void Run()`: Main method to start the application.

`void addSupplier(const Supplier& supplier)`: Adds a new supplier.

`void removeSupplier(const int& index)`: Removes a supplier by index.

`void modifySupplier(const int& index)`: Modifies a supplier's details.

`void listSuppliers() const`: Lists all suppliers.

`void showShoppingMenu()`: Handles the shopping menu.

`void showManagerMenu()`: Handles the manager menu.

`void loadDatabase()`: Loads supplier data from the database.

`void saveDatabase()`: Saves supplier data to the database.


## Supplier
Header File: `Supplier.h`

### Responsibilities:
Represents a supplier with associated details and materials.

Provides methods to manage materials.

### Key Attributes:
`std::string m_Bulstat`: Unique identifier for the supplier.

`std::string m_Name`: Supplier's name.

`std::string m_Location`: Supplier's location.

`std::string m_Phone`: Supplier's contact number.

`std::vector<OpticMaterial> m_Materials`: List of materials provided by the supplier.

### Key Methods:
`void addMaterial(const OpticMaterial& material)`: Adds a material to the supplier.

`void listMaterials() const`: Lists all materials for the supplier.

`float orderMaterials(const std::vector<int>& materialIndexes) const`: Calculates the total price for selected materials.

## OpticMaterial
Header File: `OpticsMaterial.h`

### Responsibilities:
Represents an optical material with attributes like type, thickness, diopter, material, and price.

### Key Attributes:
`std::string m_Type`: Type of the optical material.

`float m_Thickness`: Thickness in millimeters.

`float m_Diopter`: Optical diopter value.

`std::string m_Material`: Material type.

`float m_Price`: Price of the material.

### Key Methods:
`Getters`: Retrieve individual attributes (`getType()`, `getMaterial()`, etc.).

`Overloaded operator<<`: Outputs material details in a formatted manner.

## Utility
Header File: `Utility.h`

### Responsibilities:
Provides static utility functions for common operations and menu management.

### Key Methods:
`int MainMenuGetChoice()`: Displays and retrieves the main menu choice.

`int ShoppingMenuGetChoice()`: Retrieves the shopping menu choice.

`int ManagerMenuGetChoice(int& choice)`: Displays and retrieves the manager menu choice.

`bool AddProducts()`: Prompts whether to add products to a supplier.

`void trimWhitespaces(std::string& s)`: Removes leading and trailing whitespaces from a string.