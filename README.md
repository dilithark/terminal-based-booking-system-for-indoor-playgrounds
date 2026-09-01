# terminal-based-booking-system-for-indoor-playgrounds
System Overview
This C program is a console-based management system designed for an indoor badminton facility. It handles multi-tier user roles (Customers and Admins), court reservations across multiple time slots, equipment inventory rentals/returns, and operational reporting (daily/monthly statistics and system summaries).

Key Data Structures
struct Customer: Stores customer records, including a unique customerID, name, phone (acting as a unique identifier), and a password.

struct Court: Defines court details such as courtNo, courtName, and operational status (e.g., "Available", "Maintenance").

struct Booking: Tracks reservation records linking a bookingID, customerID, courtNo, bookingDate (YYYY-MM-DD), and a timeSlot (1 to 4).

struct Equipment: Manages rental items via an equipmentID, equipmentName, and available stock quantity.

Operational Modules & Workflow
1. Customer Management
Registration: New users can sign up by providing a name, a valid 10-digit phone number, and a password. A unique customerID is auto-generated (100 + index).

Authentication & Session: Customers log in using their phone number and password. Successful authentication opens a dedicated customer menu allowing them to check court availability, create/cancel bookings, and rent or return equipment.

Search & Update: Customers can be searched by ID or phone number, and existing records can be modified.

2. Court & Booking Management
Court Status: The system initializes with two courts ("Court A" and "Court B") set to "Available". Admins can add new courts or toggle existing ones into "Maintenance" mode.

Reservation System: Customers can select a date and choose from four hourly time slots:

8AM - 9AM

9AM - 10AM

10AM - 11AM

11AM - 12PM

Conflict Prevention: The checkAvailability() function scans existing bookings to ensure double-booking does not occur for the same court, date, and time slot.

Receipt Generation: Upon a successful booking, a formatted text receipt is printed displaying booking details, customer ID, court name, date, slot, and status.

3. Equipment Rental
Admins can add inventory items (e.g., rackets, shuttlecocks) with initial quantities.

Authenticated customers can rent equipment (which decrements available stock) and return items (which increments stock back).

4. Admin Panel & Reports
Protected by admin credentials (admin / admin123), administrators have access to comprehensive reporting tools:

Daily & Monthly Reports: Aggregates total bookings, active equipment types, and court utilization for specific days or months.

Booking Statistics: Computes court popularity, individual time slot usage, and identifies the most heavily booked time slot.

System Summary: Provides a holistic overview of total registered customers, active bookings, total courts, and cumulative equipment quantities.
