#include <iostream>
#include <string>
using namespace std;

string patientID[100], patientName[100], patientAge[100], patientDisease[100];
int totalPatients = 0;

string doctorID[100], doctorName[100], doctorSpecialty[100];
int totalDoctors = 0;

string apptID[100], apptPatient[100], apptDoctor[100], apptDate[100];
int totalAppointments = 0;

void addPatient() {
    cout << "\n--- Add New Patient ---\n";
    cout << "Enter Patient ID   : "; cin >> patientID[totalPatients];
    cout << "Enter Patient Name : "; cin >> patientName[totalPatients];
    cout << "Enter Age          : "; cin >> patientAge[totalPatients];
    cout << "Enter Disease      : "; cin >> patientDisease[totalPatients];
    totalPatients++;
    cout << "Patient Added Successfully!\n";
}

void viewPatients() {
    cout << "\n--- All Patients ---\n";
    if (totalPatients == 0) {
        cout << "No patients found.\n";
        return;
    }
    cout << "--------------------------------------------\n";
    for (int i = 0; i < totalPatients; i++) {
        cout << "Patient " << i + 1 << ":\n";
        cout << "  ID      : " << patientID[i]      << "\n";
        cout << "  Name    : " << patientName[i]    << "\n";
        cout << "  Age     : " << patientAge[i]     << "\n";
        cout << "  Disease : " << patientDisease[i] << "\n";
        cout << "--------------------------------------------\n";
    }
}

void searchPatient() {
    string name;
    cout << "Enter Patient Name to Search: "; cin >> name;
    bool found = false;
    for (int i = 0; i < totalPatients; i++) {
        if (patientName[i] == name) {
            cout << "\nPatient Found!\n";
            cout << "  ID      : " << patientID[i]      << "\n";
            cout << "  Name    : " << patientName[i]    << "\n";
            cout << "  Age     : " << patientAge[i]     << "\n";
            cout << "  Disease : " << patientDisease[i] << "\n";
            found = true;
        }
    }
    if (!found) cout << "Patient Not Found!\n";
}

void deletePatient() {
    string id;
    cout << "Enter Patient ID to Delete: "; cin >> id;
    bool found = false;
    for (int i = 0; i < totalPatients; i++) {
        if (patientID[i] == id) {
            for (int j = i; j < totalPatients - 1; j++) {
                patientID[j]      = patientID[j + 1];
                patientName[j]    = patientName[j + 1];
                patientAge[j]     = patientAge[j + 1];
                patientDisease[j] = patientDisease[j + 1];
            }
            totalPatients--;
            cout << "Patient Deleted!\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Patient Not Found!\n";
}

void addDoctor() {
    cout << "\n--- Add New Doctor ---\n";
    cout << "Enter Doctor ID            : "; cin >> doctorID[totalDoctors];
    cout << "Enter Doctor Name          : "; cin >> doctorName[totalDoctors];
    cout << "Enter Doctor Specialization: "; cin >> doctorSpecialty[totalDoctors];
    totalDoctors++;
    cout << "Doctor Added Successfully!\n";
}

void viewDoctors() {
    cout << "\n--- All Doctors ---\n";
    if (totalDoctors == 0) {
        cout << "No doctors found.\n";
        return;
    }
    cout << "--------------------------------------------\n";
    for (int i = 0; i < totalDoctors; i++) {
        cout << "Doctor " << i + 1 << ":\n";
        cout << "  ID             : " << doctorID[i]        << "\n";
        cout << "  Name           : " << doctorName[i]      << "\n";
        cout << "  Specialization : " << doctorSpecialty[i] << "\n";
        cout << "--------------------------------------------\n";
    }
}

void bookAppointment() {
    cout << "\n--- Book Appointment ---\n";
    cout << "Enter Appointment ID : "; cin >> apptID[totalAppointments];
    cout << "Enter Patient Name   : "; cin >> apptPatient[totalAppointments];
    cout << "Enter Doctor Name    : "; cin >> apptDoctor[totalAppointments];
    cout << "Enter Date (DD/MM/YY): "; cin >> apptDate[totalAppointments];
    totalAppointments++;
    cout << "Appointment Booked!\n";
}

void viewAppointments() {
    cout << "\n--- All Appointments ---\n";
    if (totalAppointments == 0) {
        cout << "No appointments found.\n";
        return;
    }
    cout << "--------------------------------------------\n";
    for (int i = 0; i < totalAppointments; i++) {
        cout << "Appointment " << i + 1 << ":\n";
        cout << "  ID      : " << apptID[i]      << "\n";
        cout << "  Patient : " << apptPatient[i] << "\n";
        cout << "  Doctor  : " << apptDoctor[i]  << "\n";
        cout << "  Date    : " << apptDate[i]    << "\n";
        cout << "--------------------------------------------\n";
    }
}

void patientMenu() {
    int choice;
    do {
        cout << "\n===== Patient Menu =====\n";
        cout << "1. Add Patient\n";
        cout << "2. View All Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Delete Patient\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter choice: "; cin >> choice;

        if      (choice == 1) addPatient();
        else if (choice == 2) viewPatients();
        else if (choice == 3) searchPatient();
        else if (choice == 4) deletePatient();
        else if (choice == 5) cout << "Going back...\n";
        else                  cout << "Wrong choice!\n";

    } while (choice != 5);
}

void doctorMenu() {
    int choice;
    do {
        cout << "\n===== Doctor Menu =====\n";
        cout << "1. Add Doctor\n";
        cout << "2. View All Doctors\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter choice: "; cin >> choice;

        if      (choice == 1) addDoctor();
        else if (choice == 2) viewDoctors();
        else if (choice == 3) cout << "Going back...\n";
        else                  cout << "Wrong choice!\n";

    } while (choice != 3);
}

void appointmentMenu() {
    int choice;
    do {
        cout << "\n===== Appointment Menu =====\n";
        cout << "1. Book Appointment\n";
        cout << "2. View All Appointments\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter choice: "; cin >> choice;

        if      (choice == 1) bookAppointment();
        else if (choice == 2) viewAppointments();
        else if (choice == 3) cout << "Going back...\n";
        else                  cout << "Wrong choice!\n";

    } while (choice != 3);
}

int main() {
    int choice;
    do {
        cout << "\n========================================\n";
        cout << "     HOSPITAL MANAGEMENT SYSTEM         \n";
        cout << "========================================\n";
        cout << "1. Patient Management\n";
        cout << "2. Doctor Management\n";
        cout << "3. Appointment Management\n";
        cout << "4. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: "; cin >> choice;

        if      (choice == 1) patientMenu();
        else if (choice == 2) doctorMenu();
        else if (choice == 3) appointmentMenu();
        else if (choice == 4) cout << "\nThank you! Goodbye.\n";
        else                  cout << "Wrong choice! Try again.\n";

    } while (choice != 4);

    return 0;
}
