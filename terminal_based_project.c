#include <stdio.h>
#include <string.h>

#define MAX_BOOKINGS 500

// ============================
// STRUCTURES
// ============================

struct Customer {
    int customerID;
    char name[50];
    char phone[15];
    char password[20];
};

struct Court {
    int courtNo;
    char courtName[30];
    char status[20];
};

struct Booking {
    int bookingID;
    int customerID;
    int courtNo;
    char bookingDate[20];
    int timeSlot;
};

struct Equipment {
    int equipmentID;
    char equipmentName[50];
    int quantity;
};

// ============================
// GLOBAL ARRAYS
// ============================

struct Customer  customers[200];
struct Court     courts[50];
struct Booking   bookings[MAX_BOOKINGS];
struct Equipment equipments[100];

int customerCount  = 0;
int bookingCount   = 0;
int equipmentCount = 0;
int courtCount     = 2;

// ============================
// FUNCTION DECLARATIONS
// ============================

void registerCustomer();
int  customerLogin();
void updateCustomer();
void searchCustomer();
void displayCustomers();

void addCourt();
void displayCourts();
void updateCourt();          // FIX: was declared as updateCourtStatus() but defined as updateCourt()
void searchCourt();
void availableCourts();

void createBooking();
int  checkAvailability(int courtNo, char date[], int timeSlot);
void cancelBooking();
void searchBooking();
void displayBookings();

void addEquipment();
void displayEquipment();
void rentEquipment();
void returnEquipment();
void searchEquipment();

void dailyReport();
void monthlyReport();
void bookingStatistics();
void adminLogin();
void systemSummary();

// ============================
// MAIN
// ============================

int main() {
   
    courts[0].courtNo = 1;
    strcpy(courts[0].courtName, "Court A");
    strcpy(courts[0].status, "Available");

    courts[1].courtNo = 2;
    strcpy(courts[1].courtName, "Court B");
    strcpy(courts[1].status, "Available");

    int choice;

    do {
        
        printf("\n=========================================================\n");
        printf("      INDOOR BADMINTON COURT RESERVATION SYSTEM          \n");
        printf("=========================================================\n");
        printf(" 1.  Customer Registration\n");
        printf(" 2.  Customer Login\n");
        printf(" 3.  Update Customer\n");
        printf(" 4.  Search Customer\n");
        printf(" 5.  Display Customers\n");
        printf("---------------------------------------------------------\n");
        printf("14.  Admin Panel\n");
        printf(" 0.  Exit\n");
        printf("=========================================================\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);

        if      (choice == 1)  registerCustomer();
        else if (choice == 2)  customerLogin();
        else if (choice == 3)  updateCustomer();
        else if (choice == 4)  searchCustomer();
        else if (choice == 5)  displayCustomers();
        else if (choice == 14) adminLogin();
        else if (choice == 0)  printf("Thank You For Using The System!\n");
        else                   printf("Invalid Choice!\n");

    } while (choice != 0);

    return 0;
}

// ============================
// CUSTOMER FUNCTIONS
// ============================

void registerCustomer() {
    printf("\n--- Customer Registration ---\n");

    printf("Enter Customer Name : ");
    scanf("%s", customers[customerCount].name);

    printf("Enter Customer Phone No (eg: 07########) : ");
    scanf("%s", customers[customerCount].phone);

    printf("Create a Password (less than 20 characters) : ");
    scanf("%s", customers[customerCount].password);

    if (strlen(customers[customerCount].phone) == 10 && strlen(customers[customerCount].password) > 0 && strlen(customers[customerCount].password) < 20) {

        customers[customerCount].customerID = 100 + customerCount;

        printf("\nCustomer Registered Successfully!\n");
        printf("Customer ID    : %d\n", customers[customerCount].customerID);
        printf("Customer Name  : %s\n", customers[customerCount].name);
        printf("Customer Phone : %s\n", customers[customerCount].phone);

        customerCount++;
    } else {
        printf("Invalid Phone Number or Password!\n");
    }
}

int customerLogin() {
    char phoneN[15];
    char password[20];
    int choice;

    printf("\n--- Customer Login ---\n");
    printf("Enter Phone Number : ");
    scanf("%s", phoneN);

    printf("Enter Password : ");
    scanf("%s", password);

    if (strlen(phoneN) == 10 && strlen(password) < 20) {
        for (int i = 0; i < customerCount; i++) {
            if (strcmp(customers[i].phone, phoneN) == 0 && strcmp(customers[i].password, password) == 0) {
                printf("Login Successful!\n");
                printf("Welcome %s\n", customers[i].name);
                do{
                    printf("---------------------------------------------------------\n");
                    printf(" 1.  Display Courts\n");
                    printf(" 2.  Search Court\n");
                    printf(" 3.  Check Available Courts\n");
                    printf(" 4.  Book Court\n");
                    printf(" 5.  Cancel Booking\n");
                    printf("---------------------------------------------------------\n");
                    printf(" 6.  Equipment Rental\n");
                    printf(" 7.  Return Equipment\n");
                    printf(" 0.  Log Out\n");

                    printf("Enter Choice : ");
                    scanf("%d", &choice);

                   if (choice == 1)  displayCourts();
                   else if (choice == 2)  searchCourt();
                   else if (choice == 3)  availableCourts();
                   else if (choice == 4)  createBooking();
                   else if (choice == 5)  cancelBooking();
                   else if (choice == 6) { displayEquipment(); rentEquipment(); }
                   else if (choice == 7) returnEquipment();

                } while (choice!=0);
                
                return 0;
            }
        }
        printf("Invalid Login!\n");
    } else {
        printf("Invalid Login Details!\n");
    }
}

void updateCustomer() {
    char phone[15];
    int i;

    printf("\nEnter Phone Number of Customer to Update: ");
    scanf("%s", phone);

    for (i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].phone, phone) == 0) {
            printf("\nCustomer Found!\n");
            printf("Current Name  : %s\n", customers[i].name);
            printf("Current Phone : %s\n", customers[i].phone);

            printf("\nEnter New Name : ");
            scanf("%s", customers[i].name);

            printf("Enter New Phone Number : ");
            scanf("%s", customers[i].phone);

            printf("Enter New Password : ");
            scanf("%s", customers[i].password);

            printf("\nCustomer Details Updated Successfully!\n");
            return;
        }
    }
    printf("\nCustomer Not Found!\n");
}

void displayCustomers() {
    int i;
    printf("\n--- Customer List ---\n");

    if (customerCount == 0) {
        printf("No customers registered yet.\n");
        return;
    }

    for (i = 0; i < customerCount; i++) {
        printf("ID: %d  Name: %s  Phone: %s\n",
               customers[i].customerID,
               customers[i].name,
               customers[i].phone);
    }
}

void searchCustomer() {
    char phone[15];
    int cho, id, i;

    printf("Search by (1) ID or (2) Phone Number: ");
    scanf("%d", &cho);

    if (cho == 2) {
        printf("Enter Phone Number : ");
        scanf("%s", phone);

        for (i = 0; i < customerCount; i++) {
            if (strcmp(customers[i].phone, phone) == 0) {
                printf("Customer Found\n");
                printf("Name : %s\n", customers[i].name);
                printf("ID   : %d\n", customers[i].customerID);
                return;
            }
        }
        printf("Customer Not Found\n");
    } else {
        printf("Enter Customer ID : ");
        scanf("%d", &id);

        for (i = 0; i < customerCount; i++) {
            if (customers[i].customerID == id) {   
                printf("Customer Found\n");
                printf("Name     : %s\n", customers[i].name);
                printf("Phone No : %s\n", customers[i].phone);  
                return;
            }
        }
        printf("Customer Not Found\n");
    }
}

// ============================
// ADMIN FUNCTIONS
// ============================

void adminLogin() {
    char username[20];
    char password[20];
    int choice;

    printf("\n--- Admin Login ---\n");
    printf("Enter Username : ");
    scanf("%s", username);

    printf("Enter Password : ");
    scanf("%s", password);

    if (strcmp(username, "admin") != 0 || strcmp(password, "admin123") != 0) {
        printf("Invalid Admin Login Details!\n");
        return;
    }

    printf("Admin Login Successful!\n");

    do {
        printf("\n================ ADMIN PANEL ================\n");
        printf(" 1. View Customers\n");
        printf(" 2. View Bookings\n");
        printf(" 3. View Equipment\n");
        printf(" 4. Search Booking\n");
        printf(" 5. Daily Report\n");
        printf(" 6. Booking Statistics\n");
        printf(" 7. Monthly Report\n");
        printf(" 8. System Summary\n");
        printf(" 9. Add Court\n");         
        printf("10. Update Court Status\n");
        printf("11. Add Equipment\n");
        printf(" 0. Logout\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);

        if      (choice == 1)  
        displayCustomers();

        else if (choice == 2)  
        displayBookings();

        else if (choice == 3)  
        displayEquipment();

        else if (choice == 4)  
        searchBooking();

        else if (choice == 5)  
        dailyReport();

        else if (choice == 6)  
        bookingStatistics();
        
        else if (choice == 7)  
        monthlyReport();

        else if (choice == 8)  
        systemSummary();

        else if (choice == 9)  
        addCourt();

        else if (choice == 10) 
        updateCourt();

        else if (choice == 11) 
        addEquipment();

        else if (choice == 0)  
        printf("Logged Out.\n");

        else                   
        printf("Invalid Input\n");

    } while (choice != 0);
}

void dailyReport() {
    printf("\n========== DAILY REPORT ==========\n");

    printf("Total Customers       : %d\n", customerCount);
    printf("Total Bookings        : %d\n", bookingCount);
    printf("Total Equipment Types : %d\n", equipmentCount);
    printf("\n--- Available Slots ---\n");

    availableCourts();
}

void systemSummary() {
    int totalEquipmentQty = 0;
    int i;

    for (i = 0; i < equipmentCount; i++) {
        totalEquipmentQty += equipments[i].quantity;
    }

    printf("\n====================================\n");
    printf("           SYSTEM SUMMARY\n");
    printf("====================================\n");
    printf("Total Customers      : %d\n", customerCount);
    printf("Total Bookings       : %d\n", bookingCount);
    printf("Total Courts         : %d\n", courtCount);
    printf("Equipment Types      : %d\n", equipmentCount);
    printf("Total Equipment Qty  : %d\n", totalEquipmentQty);
    printf("====================================\n");
}

void bookingStatistics() {
    int i;
    int court1Count = 0, court2Count = 0;
    int slot1 = 0, slot2 = 0, slot3 = 0, slot4 = 0;

    for (i = 0; i < bookingCount; i++) {
        if (bookings[i].courtNo == 1) court1Count++;
        if (bookings[i].courtNo == 2) court2Count++;

        switch (bookings[i].timeSlot) {
            case 1: 
            slot1++; 
            break;

            case 2: 
            slot2++; 
            break;

            case 3: 
            slot3++; 
            break;

            case 4: 
            slot4++; 
            break;

            default:
            printf("Invalid choice");
        }
    }

    printf("\n========== BOOKING STATISTICS ==========\n");
    printf("Total Bookings : %d\n", bookingCount);

    printf("\nCourt Usage:\n");
    printf("Court 1 : %d bookings\n", court1Count);
    printf("Court 2 : %d bookings\n", court2Count);

    printf("\nTime Slot Usage:\n");
    printf("8AM  - 9AM  : %d bookings\n", slot1);
    printf("9AM  - 10AM : %d bookings\n", slot2);
    printf("10AM - 11AM : %d bookings\n", slot3);
    printf("11AM - 12PM : %d bookings\n", slot4);

    if (court1Count > court2Count)
        printf("\nMost Popular Court : Court 1\n");
    else if (court2Count > court1Count)
        printf("\nMost Popular Court : Court 2\n");
    else
        printf("\nBoth Courts Are Equally Popular\n");
}

void monthlyReport() {
    int month, year, i;
    int totalBookings = 0, court1Bookings = 0, court2Bookings = 0;

    printf("Enter Month (1-12) : ");
    scanf("%d", &month);

    printf("Enter Year         : ");
    scanf("%d", &year);

    for (i = 0; i < bookingCount; i++) {
        int bYear, bMonth, bDay;
        sscanf(bookings[i].bookingDate, "%d-%d-%d", &bYear, &bMonth, &bDay);

        if (bMonth == month && bYear == year) {
            totalBookings++;
            if (bookings[i].courtNo == 1) court1Bookings++;
            if (bookings[i].courtNo == 2) court2Bookings++;
        }
    }

    printf("\n========== MONTHLY REPORT ==========\n");
    printf("Month : %d\nYear  : %d\n\n", month, year);
    printf("Total Bookings : %d\n", totalBookings);
    printf("\nCourt Usage:\n");
    printf("Court 1 : %d bookings\n", court1Bookings);
    printf("Court 2 : %d bookings\n", court2Bookings);

    if (court1Bookings > court2Bookings)
        printf("\nMost Popular Court : Court 1\n");
    else if (court2Bookings > court1Bookings)
        printf("\nMost Popular Court : Court 2\n");
    else
        printf("\nBoth Courts Are Equally Popular\n");
}

// ============================
// COURT FUNCTIONS
// ============================

void displayCourts() {
    int i;

    if (courtCount == 0) {
        printf("\nNo courts available!\n");
        return;
    }

    printf("\n--- Available Courts ---\n");
    for (i = 0; i < courtCount; i++) {
        printf("Court No   : %d\n", courts[i].courtNo);
        printf("Court Name : %s\n", courts[i].courtName);
        printf("Status     : %s\n\n", courts[i].status);
    }
}

void searchCourt() {
    int courtNo, i;

    printf("Enter Court Number : ");
    scanf("%d", &courtNo);

    for (i = 0; i < courtCount; i++) {
        if (courts[i].courtNo == courtNo) {
            printf("Court Found\n");
            printf("Court Name : %s\n", courts[i].courtName);
            printf("Status     : %s\n", courts[i].status);
            return;
        }
    }
    printf("Invalid Court Number or Court Not Found\n");
}

void availableCourts() {
    char date[20];
    int court, slot, i, booked;

    printf("Enter Date (YYYY-MM-DD): ");
    scanf("%s", date);

    printf("\nAvailability for %s:\n", date);

    for (court = 1; court <= courtCount; court++) {
        for (slot = 1; slot <= 4; slot++) {
            booked = 0;

            for (i = 0; i < bookingCount; i++) {
                if (bookings[i].courtNo == court &&
                    strcmp(bookings[i].bookingDate, date) == 0 &&
                    bookings[i].timeSlot == slot) {
                    booked = 1;
                    break;
                }
            }

            printf("Court %d  Slot %d : %s\n",
                   court, slot, booked ? "BOOKED" : "Available");
        }
    }
}

void addCourt() {
    if (courtCount >= 50) {
        printf("\nCannot add more courts! Max limit is 50.\n");
        return;
    }

    printf("Enter Court Number : ");
    scanf("%d", &courts[courtCount].courtNo);

    printf("Enter Court Name   : ");
    scanf("%s", courts[courtCount].courtName);

    printf("Enter Court Status : ");
    scanf("%s", courts[courtCount].status);

    courtCount++;
    printf("Court Added Successfully!\n");
}

// FIX: renamed from updateCourtStatus() to match the definition used everywhere;
//      replaced undefined viewCourts() call with displayCourts()
void updateCourt() {
    int id;
    printf("\n--- UPDATE COURT STATUS ---\n");
    displayCourts();  // FIX: was viewCourts() which does not exist

    printf("\nEnter Court ID: ");
    scanf("%d", &id);

    if (id < 1 || id > courtCount) {
        printf("Invalid Court ID!\n");
        return;
    }

    printf("\nCurrent Status: %s\n", courts[id - 1].status);
    printf("1. Available\n");
    printf("2. Maintenance\n");
    printf("Choose: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        strcpy(courts[id - 1].status, "Available");
        printf("Status updated to 'Available'!\n");
    } else if (choice == 2) {
        strcpy(courts[id - 1].status, "Maintenance");
        printf("Status updated to 'Maintenance'!\n");
    } else {
        printf("Invalid choice!\n");
    }
}

// ============================
// BOOKING FUNCTIONS
// ============================

int checkAvailability(int courtNo, char date[], int timeSlot) {
    int i;
    for (i = 0; i < bookingCount; i++) {
        if (bookings[i].courtNo == courtNo &&
            strcmp(bookings[i].bookingDate, date) == 0 &&
            bookings[i].timeSlot == timeSlot) {
            return 0; // Not available
        }
    }
    return 1; // Available
}

void createBooking() {
    int customerID, courtNo, timeSlot;
    char date[20];

    if (bookingCount >= MAX_BOOKINGS) {
        printf("\nError: Booking system is full!\n");
        return;
    }

    printf("\n--- Create New Booking ---\n");
    printf("Enter Customer ID          : ");
    scanf("%d", &customerID);

    printf("Enter Court Number (1-%d)  : ", courtCount);
    scanf("%d", &courtNo);

    if (courtNo < 1 || courtNo > courtCount) {  // FIX: was courtNo <= 1
        printf("Invalid Court Number!\n");
        return;
    }

    printf("Enter Booking Date (YYYY-MM-DD) : ");
    scanf("%s", date);

    printf("\nTime Slots:\n");
    printf("1. 8AM  - 9AM\n");
    printf("2. 9AM  - 10AM\n");
    printf("3. 10AM - 11AM\n");
    printf("4. 11AM - 12PM\n");
    printf("Enter Time Slot (1-4) : ");
    scanf("%d", &timeSlot);

    if (timeSlot < 1 || timeSlot > 4) {
        printf("Invalid Time Slot!\n");
        return;
    }

    if (checkAvailability(courtNo, date, timeSlot)) {
        bookings[bookingCount].bookingID  = bookingCount + 1000;
        bookings[bookingCount].customerID = customerID;
        bookings[bookingCount].courtNo    = courtNo;
        strcpy(bookings[bookingCount].bookingDate, date);
        bookings[bookingCount].timeSlot   = timeSlot;

        bookingCount++;
        printf("Booking Successful! Booking ID: %d\n", bookingCount - 1 + 1000);
    } else {
        printf("Court already booked for that date and time slot!\n");
    }
}

void displayBookings() {
    int i;
    printf("\n--- Booking List ---\n");

    if (bookingCount == 0) {
        printf("No bookings found.\n");
        return;
    }

    for (i = 0; i < bookingCount; i++) {
        printf("Booking ID  : %d\n", bookings[i].bookingID);
        printf("Customer ID : %d\n", bookings[i].customerID);
        printf("Court No    : %d\n", bookings[i].courtNo);
        printf("Date        : %s\n", bookings[i].bookingDate);
        printf("Time Slot   : %d\n\n", bookings[i].timeSlot);
    }
}

void cancelBooking() {
    int bookingID, i, j;

    printf("\n--- Cancel a Booking ---\n");
    printf("Enter Booking ID : ");
    scanf("%d", &bookingID);

    for (i = 0; i < bookingCount; i++) {
        if (bookings[i].bookingID == bookingID) {
            for (j = i; j < bookingCount - 1; j++) {
                bookings[j] = bookings[j + 1];
            }
            bookingCount--;
            printf("Booking Cancelled Successfully!\n");
            return;
        }
    }
    printf("Booking Not Found\n");
}

void searchBooking() {
    int bookingID, i;

    printf("\n--- Search Booking ---\n");
    printf("Enter Booking ID : ");
    scanf("%d", &bookingID);

    for (i = 0; i < bookingCount; i++) {
        if (bookings[i].bookingID == bookingID) {
            printf("Booking Found\n");
            printf("Court No  : %d\n", bookings[i].courtNo);
            printf("Date      : %s\n", bookings[i].bookingDate);
            printf("Time Slot : %d\n", bookings[i].timeSlot);  // FIX: was %s
            return;  // FIX: missing return caused "Not Found" to also print
        }
    }
    printf("Booking Not Found\n");
}

// ============================
// EQUIPMENT FUNCTIONS
// ============================

void addEquipment() {
    printf("\n--- Add Equipment ---\n");
    printf("Enter Equipment Name : ");
    scanf("%s", equipments[equipmentCount].equipmentName);

    printf("Enter Quantity       : ");
    scanf("%d", &equipments[equipmentCount].quantity);

    equipments[equipmentCount].equipmentID = equipmentCount + 1;
    equipmentCount++;
    printf("Equipment Added Successfully!\n");
}

void displayEquipment() {
    int i;
    printf("\n--- Equipment List ---\n");

    if (equipmentCount == 0) {
        printf("No equipment found.\n");
        return;
    }

    for (i = 0; i < equipmentCount; i++) {
        printf("ID       : %d\n", equipments[i].equipmentID);
        printf("Name     : %s\n", equipments[i].equipmentName);
        printf("Quantity : %d\n\n", equipments[i].quantity);
    }
}

void rentEquipment() {
    int id, qty, i;

    printf("\n--- Rent Equipment ---\n");
    printf("Enter Equipment ID : ");
    scanf("%d", &id);

    printf("Enter Quantity     : ");
    scanf("%d", &qty);

    for (i = 0; i < equipmentCount; i++) {
        if (equipments[i].equipmentID == id) {
            if (equipments[i].quantity >= qty) {
                equipments[i].quantity -= qty;
                printf("Equipment Rented Successfully!\n");
            } else {
                printf("Insufficient quantity available! Available: %d\n",
                       equipments[i].quantity);
            }
            return;
        }
    }
    printf("Equipment Not Found!\n");
}

void returnEquipment() {
    int id, qty, i;

    printf("\n--- Return Equipment ---\n");
    printf("Enter Equipment ID : ");
    scanf("%d", &id);

    printf("Enter Quantity     : ");
    scanf("%d", &qty);

    for (i = 0; i < equipmentCount; i++) {
        if (equipments[i].equipmentID == id) {
            equipments[i].quantity += qty;
            printf("Equipment Returned Successfully!\n");
            return;
        }
    }
    printf("Equipment Not Found!\n");
}

void searchEquipment() {
    int id, i;

    printf("\n--- Search Equipment ---\n");
    printf("Enter Equipment ID : ");
    scanf("%d", &id);

    for (i = 0; i < equipmentCount; i++) {
        if (equipments[i].equipmentID == id) {
            printf("Equipment Found\n");
            printf("Name     : %s\n", equipments[i].equipmentName);
            printf("Quantity : %d\n", equipments[i].quantity);
            return;
        }
    }
    printf("Equipment Not Found!\n");
}