#include <stdio.h>
#include <string.h>

// ============================
// STRUCTURES
// ============================

struct Customer{
    int customerID;
    char name[50];
    char phone[15];
    char password[20];
};

struct Court{
    int courtNo;
    char courtName[30];
    char status[20];
};

struct Booking{
    int bookingID;
    int customerID;
    int courtNo;
    char bookingDate[20];
    int timeSlot;
};

struct Equipment{
    int equipmentID;
    char equipmentName[50];
    int quantity;
};

struct Report{
    int totalBookings;
    int totalCustomers;
    int totalEquipmentRented;
};

// ============================
// GLOBAL ARRAYS
// ============================

struct Customer customers[100];
struct Court courts[2];
struct Booking bookings[500];
struct Equipment equipments[100];

int customerCount = 0;
int bookingCount = 0;
int equipmentCount = 0;

// ============================
// FUNCTION DECLARATIONS
// ============================

// Customer Functions
void registerCustomer();
int customerLogin();
void updateCustomer();
void searchCustomer();
void displayCustomers();

// Court Functions
void addCourt();
void displayCourts();
void updateCourtStatus();
void searchCourt();
void availableCourts();

// Booking Functions
void createBooking();
int checkAvailability(int courtNo, char date[], int timeSlot);
void cancelBooking();
void searchBooking();
void displayBookings();

// Equipment Functions
void addEquipment();
void displayEquipment();
void rentEquipment();
void returnEquipment();
void searchEquipment();

// Report/Admin Functions
void dailyReport();
void monthlyReport();
void bookingStatistics();
void adminLogin();
void systemSummary();

/*meke thiyen names tika use krl hadamu ethkota okkoma ekathu krnna giyma lesi...*/