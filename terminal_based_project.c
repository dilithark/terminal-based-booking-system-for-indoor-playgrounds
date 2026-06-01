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

int main(){
    int choice;

    do{
        printf("=========================================================\n");
        printf("      INDOOR BADMINTON COURT RESERVATION SYSTEM.         \n");
        printf("=========================================================\n");

        printf("1. Customer Registration\n");
        printf("2. Customer Login\n");

        printf("3. Court Management\n");
        printf("4. Book Court\n");
        printf("5. Cancel Booking\n");
        printf("6. View Bookings\n");

        printf("7. Equipment Rental\n");

        printf("8. Admin Panel\n");
        printf("0. Exit\n\n");

         printf("\nEnter Choice : ");
        scanf("%d", &choice);

        if(choice == 1){
            registerCustomer();
        }

        else if(choice == 2){
            customerLogin();
        }

        else if(choice == 3){
            displayCourts();
        }

        else if(choice == 4){
            createBooking();
        }

        else if(choice == 5){
            cancelBooking();
        }

        else if(choice == 6){
            displayBookings();
        }

        else if(choice == 7){
            displayEquipment();
            rentEquipment();
        }

        else if(choice == 8){
            adminLogin();
        }

        else if(choice == 0){
            printf("Thank You For Using The System!\n");
        }

        else{
            printf("Invalid Choice!\n");
        }

    }
    while (choice != 0);

    return 0;
}


void registerCustomer(){
    int id = 100;
    printf("Enter Customer Name\n");
    scanf("%s",customers[customerCount].name);

    printf("Enter Customer Phone NO(eg:- 07########)\n");
    scanf("%s",customers[customerCount].phone);

    printf("Create a password (enter a password less then 20 characters)\n");
    scanf("%s",customers[customerCount].password);

    customers[customerCount].customerID = id;
    id ++;

    if((strlen(customers[customerCount].phone) == 10) && (strlen(customers[customerCount].password))){

    printf("Customer Registered Successfully!\n");
    printf("Details: \n");
    printf("Customer ID: \n",customers[customerCount].customerID);
    printf("Customer NAME: \n",customers[customerCount].name);
    printf("Customer PHONE NO: \n",customers[customerCount].phone);
    printf("Customer PASSWORD: \n",customers[customerCount].password);

    customerCount++;
    }
    printf("Invalid PHONE NO or PASSWORD");
}


int customerLogin(){
    char phoneN[11];
    char password[20];

     printf("\nEnter Phone Number : ");
    scanf("%s", phoneN);

    printf("Enter Password : ");
    scanf("%s", password);

    if(strlen(phoneN) == 10 && strlen(password) < 20){
        for(int i = 0; i < customerCount; i++){
        if(strcmp(customers[i].phone, phoneN)==0 && strcmp(customers[i].password, password)==0){
             printf("Login Successful!\n");
            printf("Welcome %s\n", customers[i].name);

            return i;
        }
    }
    printf("Invalid Login!\n");
    }
    else{
        printf("Invalid Login Details");
    }
}

void adminLogin(){
    char username[20];
    char password[20];
    int choice;

    printf("\nEnter Username : ");
    scanf("%s", username);

    printf("Enter Password : ");
    scanf("%s", password);

    if(strcmp(username, "admin")==0 && strcmp(password, "admin123")==0){


    }
    printf("Invalid Admin Login Details ");

    do{
        printf("\n================ ADMIN PANEL ================\n");
            printf("1. View Customers\n");
            printf("2. View Bookings\n");
            printf("3. View Equipment\n");
            printf("4. Search Booking\n");
            printf("5. Daily Report\n");
            printf("6. System Summary\n");
            printf("7. Reports\n");
            printf("0. Logout\n");

            printf("Enter Choice : ");
            scanf("%d", &choice);
    }

}
