# 🧾 Cash Memo System in C++

A console-based C++ application designed to generate cash memos or receipts. This project demonstrates core object-oriented programming (OOP) principles, including class design, encapsulation, and operator overloading. It is structured professionally with separate header and implementation files and is built using a `Makefile`.

---

## ✨ Features

- **Dynamic Data Entry**: Captures all necessary details for a cash memo, including shop information, customer details, and item specifics.
- **Formatted Output**: Generates a clean, well-formatted cash memo ready for display.
- **Input Validation**: Ensures that data like names, numbers, and dates are entered in a valid format.
- **OOP Design**: Utilizes a collection of classes to model real-world entities like `Item`, `Date`, and `Address`.
- **Makefile Build System**: Includes a straightforward `Makefile` for easy compilation and execution.

---

## 📁 Project Structure

The project is organized into `include` and `src` directories to separate class declarations from their implementations.

```
cashmemo-cpp/
├── include/
│   ├── Address.h
│   ├── CashMemo.h
│   ├── CellNumber.h
│   ├── Date.h
│   ├── Item.h
│   ├── Name.h
│   ├── ReceiptNo.h
│   └── ShopDetails.h
│
├── src/
│   ├── Address.cpp
│   ├── cashmemo_app.cpp  (Main application entry point)
│   ├── CashMemo.cpp
│   ├── CellNumber.cpp
│   ├── Date.cpp
│   ├── Item.cpp
│   ├── Name.cpp
│   ├── ReceiptNo.cpp
│   └── ShopDetails.cpp
│
├── build/                 (Created automatically by the Makefile)
├── Makefile               (To compile and run the project)
├── .gitignore             (Specifies files for Git to ignore)
└── README.md              (This file)
```

---

## ⚙️ How to Build and Run

This project uses a `Makefile` to automate the build process. Ensure you have `g++` and `make` installed on your system.

Open a terminal in the project's root directory and use the following commands:

**1. To compile the project:**
This command compiles all source files and links them into an executable located in `build/bin/`.
```bash
make
```

**2. To compile and run the project:**
```bash
make run
```

**3. To clean the build directory:**
This command removes all compiled files.
```bash
make clean
```

---

## 🖥️ Sample Usage

Here is an example of the program's input and output flow:

```
$ make run
                  SHOP DETAILS

Enter Shop First Name : Super
Enter Shop Last Name : Electronics
Enter Shop Description : Quality Gadgets
Shop's Owner Name
Enter first name: Zohaib
Enter middle name: (or '-' to skip)-
Enter last name: Khan
CellInfo 
Enter Country Code : 92
Enter Number : 3001234567
Address Info
Street No : 123
City : Islamabad
Country : Pakistan
Enter date (DD MM YYYY): 22 6 2024
                  CUSTOMER'S INFO
Enter first name: Ali
Enter middle name: (or '-' to skip)-
Enter last name: Ahmed

Enter 2 Items:
Enter particular: Wireless Mouse
Enter quantity: 1
Enter rate: 1500
Enter particular: Keyboard
Enter quantity: 1
Enter rate: 2500
------------------------------------------------------
              Super Electronics
------------------------------------------------------
         Quality Gadgets
           Cell : +92 3001234567

No: 1001                                  Date: 22-6-2024
Name: Ali Ahmed

------------------------------------------------------
     Qty         Particulars      Rate      Amount
------------------------------------------------------
       1      Wireless Mouse   1500.00     1500.00
       1          Keyboard   2500.00     2500.00
------------------------------------------------------
                                         Total: 4000.00
------------------------------------------------------
Signature: Zohaib Khan
Address : Street # 123, Islamabad, Pakistan

```

---

## 🧩 Core Classes

- **`CashMemo`**: The main class that aggregates all other components to form the final receipt.
- **`ShopDetails`**: Manages the store's information, such as its name, address, and contact details.
- **`Item`**: Represents a single item in the memo, including its quantity, name, rate, and total amount.
- **`Name`**, **`Address`**, **`CellNumber`**, **`Date`**, **`ReceiptNo`**: Helper classes that model individual data components with their own logic and validation.

---

## 👨‍💻 Author

Developed By **Zohaib Khan** 🎓

## 📄 License

MIT License © 2025 [Zohaib Khan](https://github.com/ZohaibCodez).