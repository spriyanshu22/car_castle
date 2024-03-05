#include<iostream>
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <string> 
#include <sstream> 
#include <fstream>
#include <iomanip>
#include <ctime>

# define car_rent_limit 3
string cars_file = "cars.csv";
string manager_id = "p";
string manager_password = "p";
string manager_name = "Priyanshu Singh";
string employeeFile = "employees.csv";
string customerFile = "customers.csv";

/*
                                    DESCRIPTION
=> The code is a car rental system which has 3 classes : User, Customer and Employee
=> The User class is an abstract class which has a pure virtual function displayMenu()

DATA FILES & FORMAT:
• Manager Login : The username and password for the manager are stored in the code itself and the top.

• cars.csv : This file contains the details of the cars available for rent. 
    o The fields in the file are indexNo, carId, car_name, price, isAvailable, returnDate, username
    o indexNo : The index number of the car
    o carId : The unique id of the car (preferably a string) 
    o car_name : The name of the car
    o price : The price of the car in INR
    o isAvailable : A boolean value indicating whether the car is available for rent or not
    o returnDate : The date on which the car is expected to be returned in yyyy/mm/dd format
    o username : The username of the customer who has rented the car

• customers.csv : This file contains the details of the customers who have rented the cars
    o The fields in the file are username, name, password, customer_record, no_car_rented, car1_id, car2_id, car3_id
    o username : The username of the customer
    o name : The name of the customer
    o password : The password of the customer
    o customer_record : A number indicating the customer’s record
    o no_car_rented : The number of cars rented by the customer
    o car1_id : The id of the first car rented by the customer
    o car2_id : The id of the second car rented by the customer
    o car3_id : The id of the third car rented by the customer

• employees.csv : This file contains the details of the employees who are renting the cars
    o The fields in the file are username, name, password, employee_record, no_car_rented, car1_id, car2_id, car3_id
    o username : The username of the employee
    o name : The name of the employee
    o password : The password of the employee
    o employee_record : A number indicating the employee’s record
    o no_car_rented : The number of cars rented by the employee
    o car1_id : The id of the first car rented by the employee
    o car2_id : The id of the second car rented by the employee
    o car3_id : The id of the third car rented by the employee


=> The Customer and Employee classes are derived from the User class and they override the displayMenu() function
=> The page starts with Home() with the following functionalities:
    a) Customer Login
    b) Employee Login
    c) Customer Signup
    d) Employee Signup
    e) Manager Login
    f) Exit

=>  After choosing Customer Login, the customer is asked to enter the username and password. 
    If the username and password are incorrect, the customer is redirected to the Home() page after confirmation of the customer.
    If the username and password are correct, the customer is redirected to the Customer class with following functionalities: 
    i) Rent a car
    ii) View rented cars
    iii) Return a car
    iv) Exit

=>  After choosing Employee Login, the employee is asked to enter the username and password.
=>  Rest of the functionalities are same as the Customer class. Only the difference is that the employee gets an extra 15% discount on the rent price of the car.

=> After choosing Manager Login, the manager is asked to enter the username and password.
=> The manager is redirected to the Manager class with the following functionalities:
    i) Add a car
    ii) Remove a car
    iii) View all cars
    iv) Add an employee
    v) Remove an employee
    vi) View all employees
    vii) Add a customer
    viii) Remove a customer
    ix) View all customers
    x) Exit

RENTING A CAR:
=> On selecting a car to rent, the customer is asked to enter the return date in yyyy/mm/dd format. 
    If the return date is before the current date,or invalid format of date, or the date for rent is more than 30 days, the customer is redirected to the Customer class after confirmation.
    If the return date is valid, the customer is asked to confirm the rent.
    If the customer has already rented 3 cars, the customer is prompted with a message that the customer has already rented 3 cars.
    If the customer confirms the rent, the bill amount is calculated and displayed to the customer.

RETURNING A CAR:
=> On selecting a car to return, the customer is showed the list of card rented by him asked to enter the index number of the car to be returned.
   The customer is asked to enter the condition of the car (1. No damage, 2. Minor damage, 3. Major damage).
   Now based on the condition of the car and late return of the car, the customer record is updated and the penalty is calculated and displayed to the customer.

HANDLING EXCEPTIONS:
=> If the manager is trying to delete a customer who has rented a car, the manager is prompted with a message that the customer has rented a car and cannot be deleted.
=> Same is in the case of employee.
=> The exit option is available at every stage of the program, which allows to go back to previous menu, and exit the code in case of Home() page.
=> If the manager is trying to deletea a car that is rented, the manager is prompted with a message that the car is rented and cannot be deleted.
=> If at any point, the user gives an invalid input, the user is prompted with a message of invalid input and then redirected to the same page again after confirmation.
=> At any point, if the file is not opened, the manager is prompted with a message that the file is not opened.
=> If the customer with a bad customer record (less than zero) is trying to rent a car, the customer is prompted with a message that the customer record is not good enough to rent a car.
=> If the customer is trying to rent a car and no cars are available, the customer is prompted with a message that no cars are available.
=> If the customer is trying to rent a car and the customer has already rented 3 cars, the customer is prompted with a message that the customer has already rented 3 cars.
=> If the customer is trying to return a car and no cars are rented, the customer is prompted with a message that no cars are rented yet.
=> Similarly all these features are implementd for employees also.
=> The list of car in the cars.csv is always maintained in the sorted order of indexNo.
=> While adding a new car, the indexNo is automatically assigned to the car.
=> The username, car_id, employee_id are unique and are not repeated in the customers.csv, cars.csv and employees.csv respectively, and this is checked at the time of adding a new customer, car and employee and if repeated, the user is prompted with a message that the username, car_id, employee_id is already taken.
*/



/*
ADD THE FOLLOWING DATA TO THE CSV FILES:

cars.csv
1,UP53CD3898,Audi,6000,1,null,null
2,UP53ED3938,mercedes,5000,1,null,null
3,UP53CJ9098,bmw,5200,1,null,null
4,UP53FJ9998,rolls royce,15000,1,null,null
5,UP5DF39809,suv,1100,1,null,null
6,UP53KJ9841,porshe,16000,1,null,null
7,UP53LJ3898,honda city ,4000,1,null,null
8,UP53KE3898,maruti 800,2000,1,null,null
9,UP53IE3987,swift,3000,1,null,null
10,UP53KW3876,alto,2500,1,null,null

customers.csv
shubh123,shubh singh,shubh@,5,0,null,null,null
rahul123,rahul singh,rahul@,4,0,null,null,null
s,shivam singh,s,3,0,null,null,null
mohit123,mohit singh,mohit@,1,0,null,null,null
manoj123,manoj singh,manoj@,5,0,null,null,null
sarvesh123,sarvesh,sarvesh@,5,0,null,null,null
satyam123,satyam,satyam@,5,0,null,null,null
raunak123,raunak singh,raunak@,5,0,null,null,null
prem123,prem,prem@,4,0,null,null,null
prem123_,prem_,prem@,4,0,null,null,null


employees.csv
sarvesh456,saravesh,sarvesh@,5,0,null,null,null
rohit456,rohit singh,rohit@,4,0,null,null,null
ramesh456,ramesh chauhan,ramesh@,4,0,null,null,null


*/

// CSV files format ::
// cars database : indexNo,carId(string), car_name(string), price(int), isAvailable(boolean), returnDate(string), username(string)
// customers database : username(string), name(string), password(string), customer_record(int), no_car_rented(int), car1_id(string/null), car2_id(string/null), car3_id(string/null)
// employees database : username(string), name(string), password(string), employee_record(int), no_car_rented(int), car1_id(string/null), car2_id(string/null), car3_id(string/null)

/////////////////////////////////Car class //////////////////////////////
class Car {
    public:
    string car_name;
    int price;
    bool isAvailable;
    string carId;
    
    Car() : car_name(""), price(0), isAvailable(false) {}; // default constructor
    Car(string car_name, int price, bool isAvailable,string carId) : car_name(car_name), price(price), isAvailable(isAvailable) ,carId(carId) {};
};

///////////////////////////////// User CLASS ///////////////////////////////////////
class User {
public:
    User(const string& name, const string& username, const string& password)
        : name(name), username(username), password(password) {}

    virtual ~User() {}

    virtual void displayMenu() = 0; // Pure virtual function for displaying menu
protected:
    string name;
    string username;
    string password;
};

////////////////////////////////// Customer() ////////////////////////////////
class Customer : public User {
public:
    Customer(const string& name, const string& username, const string& password)
        : User(name, username, password) {}

    void displayMenu() override {
        cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
        cout<<"-*-*-*-*-*-*-*-*-*-*-*-Welcome "<<name<<" to Customer Menu-*-*-*-*-*-*-*-*-*-*-*-\n";
        cout << "Select any of the following:\n";
        cout << "1. Rent a car\n";
        cout << "2. View rented cars\n";
        cout << "3. Return a car\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        // Add switch case to call appropriate method based on user choice
        switch (choice)
        {
        case 1:
            //Call rentCar method
            if(availableCarsCount()==0){
                cout<<"****************Sorry, no cars available****************\n";
            }
            else {
                if(rentedCarsCount()>=car_rent_limit){
                    cout<<"****************You have already rented 3 cars****************\n";
                }
                else{
                    viewAvailableCars();
                    rentCar();
                }
            }
            break;
        case 2:
            // Call viewRentedCars method
            if(rentedCarsCount()==0){
                cout<<"****************No cars rented yet****************\n";
            }
            else {
                viewRentedCars();
            }
            break;
        case 3:  
            // Call returnCar method
            if(rentedCarsCount()==0){
                cout<<"****************No cars rented yet****************\n";
            }
            else {
                viewRentedCars();
                returnCar();
            }
            break;  
        case 4:
            // Exit
            cout<<"Exiting Customer Menu\n";
            return;
        default:
            cout<<"****************Invalid choice****************\n";
            break;
        }

        // redirecting to displayMenu <--- <-- <-- <-- 
        cout<<"****************Enter 1 to go back to Customer Menu****************\n";
        int choice1;
        cin>>choice1;
        cin.ignore();
        if(choice1==1){
            displayMenu();
        }
    }

    // checks if the given string represent a date in yyyy/mm/dd and not any arbtrary input
    bool isValidDateFormat(string date){
        if(date.length()!=10){
            return false;
        }
        if(date[4]!='/' || date[7]!='/'){
            return false;
        }
        for(int i=0;i<10;i++){
            if(i==4 || i==7){
                continue;
            }
            if(date[i]<'0' || date[i]>'9'){
                return false;
            }
        }
        return true;
    }

    // isBorrowableDate : takes the date in yyyy/mm/dd format as input then also accesses todays date from system and checks if the argument date after todays date or not and if no then returns 0
    // now if yes then checks if the argument date is after less than 30 days from todays date and if yes then returns 1 else -1
    int isBorrowableDate(string date){
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int year = 1900 + ltm->tm_year;
        int month = 1 + ltm->tm_mon;
        int day = ltm->tm_mday;
        string today_date = to_string(year)+"/"+to_string(month)+"/"+to_string(day);
        if(date<today_date){
            return 0;
        }
        else{
            string date1 = date;
            string date2 = today_date;
            int year1 = stoi(date1.substr(0,4));
            int month1 = stoi(date1.substr(5,2));
            int day1 = stoi(date1.substr(8,2));
            int year2 = stoi(date2.substr(0,4));
            int month2 = stoi(date2.substr(5,2));
            int day2 = stoi(date2.substr(8,2));
            if(year1-year2==0 && month1-month2==0 && day1-day2<=30){
                return 1;
            }
            else{
                return -1;
            }
        }
    }

    // counts the number of available cars from the cars.csv file and returns the count
    int availableCarsCount()
    {
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return -1;
        }
        string line;
        int count = 0;
        while (getline(file, line)) {
            stringstream ss(line);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                if (isAvailable_str == "1") {
                    count++;
                }
            }
        }
        file.close();
        return count;
    }
    
    // checks if the car is rented or not by taking the car_id and returns true if rented else false
    bool isCarRented(int indexNo){
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                if (stoi(indexNo_str) == indexNo && isAvailable_str == "0") {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
        return false;
    }
    
    // checks if the car is available for rent or not by taking the indexNo and returns true if available else false 
    bool isCarAvailableForRent(int indexNo){
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                if (stoi(indexNo_str) == indexNo && isAvailable_str == "1") {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
        return false;
    }

    
    // counts the number of rented cars from the cars.csv file and returns the count
    int rentedCarsCount()
    {
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return -1;
        }
        string line;
        int count = 0;
        while (getline(file, line)) {
            stringstream ss(line);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                if (isAvailable_str == "0" && username_str==username) {
                    count++;
                }
            }
        }
        file.close();
        return count;
    }

    // prints the list of available cars
    void viewAvailableCars() {
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        string line;

        while (getline(file, line)) {  
            stringstream ss(line);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',')) {
                double price = stod(price_str);
                bool isAvailable = (isAvailable_str == "1");
                //cout<<"isAvailable"<<isAvailable_str;
                if (isAvailable) {
                    cout <<indexNo_str << ". Model: " << car_name << ", Price: " << price << endl;
                }
            }
        }
        file.close();
    }

    // returns todays date in yyyy/mm/dd format
    // in case of date is 3 then it stores 03
    string getTodaysDate(){
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int year = 1900 + ltm->tm_year;
        int month = 1 + ltm->tm_mon;
        int day = ltm->tm_mday;
        string today_date = to_string(year)+"/";
        if(month<10){
            today_date+="0";
        }
        today_date+=to_string(month)+"/";
        if(day<10){
            today_date+="0";
        }
        today_date+=to_string(day);
        return today_date;
    }
    
    // Function to calculate the diff in number of days between two dates
    int calculateDaysFrom(string date1, string date2) {
    tm tm1 = {0}, tm2 = {0};

    stringstream ss1(date1);
    ss1 >> get_time(&tm1, "%Y/%m/%d");

    stringstream ss2(date2);
    ss2 >> get_time(&tm2, "%Y/%m/%d");

    time_t t1 = mktime(&tm1);
    time_t t2 = mktime(&tm2);

    int difference = difftime(t2, t1) / (60 * 60 * 24);

    return difference;
    }
    
    // returns customer_record of the customer from the customers.csv file
    int getCustomerRecord(){
        ifstream file("customers.csv");
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return -1;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name, password1, customer_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
            if (getline(ss, username1, ',') && getline(ss, name, ',') && getline(ss, password1, ',') && getline(ss, customer_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
                if (username1 == username) {
                    file.close();
                    return stoi(customer_record_str);
                }
            }
        }
        file.close();
        return -1;
    }
    
    // Method to rent a car : asks the index no of car to be rented and then return date and then a confirmation that you want to rent : if yes 
    //then updates the cars.csv file with username of the customer and return date and then updates the customers.csv file with the car_id
    // else returns to the displayMenu
    void rentCar() {
        cout << "Enter the index number of the car you want to rent: ";
        int indexNo;
        cin >> indexNo;
        cin.ignore();
        if(!isCarAvailableForRent(indexNo)){
            cout<<"****************Invalid Index****************\n";
            return;
        }

        // checking customer_record
        int customer_record = getCustomerRecord();
        if(customer_record<0){
            cout<<"*********Your customer record is not good enough to rent a car*********\n";
            return;
        }
        
        cout << "Enter the return date (YYYY/MM/DD): ";
        string returnDate;
        getline(cin, returnDate);

        // checking if the date is in valid format
        if(!isValidDateFormat(returnDate)){
            cout<<"****************Invalid Date Format****************\n";
            return;
        }

        // getting current date
        double car_per_day_cost;
        string currDate;
        currDate = getTodaysDate();

        // checking if the return date is valid or not and getting the difference in days
        int days_difference = calculateDaysFrom(currDate,returnDate);
        if(days_difference<0){
            cout<<"*********Return date can't be before today*********\n";
            return;
        }
        else if(days_difference>30){
            cout<<"*****Rent time should be not more than 30 days*****\n";
            return;
        }



        // confirmation to rent the car
        cout << "Are you sure you want to rent this car? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore();
        
        if (choice == 'y') {

            string car_id_final="null";

            // updating the cars.csv file
            ifstream file(cars_file);
            if (!file.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            string line;
            string new_file_content;
            while (getline(file, line)) {
                stringstream ss(line);
                string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
                if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                    if (stoi(indexNo_str) == indexNo) {
                        isAvailable_str = "0";
                        username_str = username;
                        returnDate_str = returnDate;
                        car_id_final=car_id;
                        // storing the rent price of the car
                        car_per_day_cost = stod(price_str);
                    }
                    new_file_content += indexNo_str + "," + car_id + "," + car_name + "," + price_str + "," + isAvailable_str + "," + returnDate_str + "," + username_str + "\n";
                }
            }
            file.close();
            ofstream file_out(cars_file);
            if (!file_out.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            file_out << new_file_content;
            file_out.close();
            
            
            // updating customers.csv file
            ifstream file1("customers.csv");
            if (!file1.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            string line1;
            string new_file_content1;
            while (getline(file1, line1)) {
                stringstream ss(line1);
                string username1, name, password1, customer_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
                if (getline(ss, username1, ',') && getline(ss, name, ',') && getline(ss, password1, ',') && getline(ss, customer_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
                    if (username1 == username) {
                        int no_car_rented = stoi(no_car_rented_str);
                        no_car_rented++;
                        if (car1_id == "null") {
                            car1_id = car_id_final;
                        } else if (car2_id == "null") {
                            car2_id = car_id_final;
                        } else if (car3_id == "null") {
                            car3_id = car_id_final;
                        }
                        new_file_content1 += username1 + "," + name + "," + password1 + "," + customer_record_str + "," + to_string(no_car_rented) + "," + car1_id + "," + car2_id + "," + car3_id + "\n";
                    } else {
                        new_file_content1 += line1 + "\n";
                    }
                }
            }
            file1.close();
            ofstream file_out1("customers.csv");
            if (!file_out1.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            file_out1 << new_file_content1;
            file_out1.close();

            cout << "Car rented successfully.\n";

            // Calculating the bill amount
            double total_cost = (days_difference+1)*car_per_day_cost;
            cout<<"Total cost of renting the car for "<<days_difference+1<<" days is: "<<"Rs. "<<total_cost<<endl;
        }
        else{
            return;
        }
    }  
    
    // view rented cars: this method takes the car_id from the customers.csv and then using this prints the car_name, price and returnDate of the cars form cars.csv file
    void viewRentedCars() {
        
        // reading the car ids from the customers.csv file
        ifstream file("customers.csv");
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        string line;
        string car1_id, car2_id, car3_id;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name, password1, customer_record_str, no_car_rented_str, car1_id_str, car2_id_str, car3_id_str;
            if (getline(ss, username1, ',') && getline(ss, name, ',') && getline(ss, password1, ',') && getline(ss, customer_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id_str, ',') && getline(ss, car2_id_str, ',') && getline(ss, car3_id_str, ',')) {
                if (username1 == username) {
                    car1_id = car1_id_str;
                    car2_id = car2_id_str;
                    car3_id = car3_id_str;
                }
            }
        }
        file.close();

        // case if no car is rented
        if(car1_id=="null" && car2_id=="null" && car3_id=="null"){
            cout<<"*************No cars rented yet*************\n";
            return;
        }

        // using the car ids to print the car_name, price and returnDate from the cars.csv file
        ifstream file1(cars_file);
        if (!file1.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        string line1;
        while (getline(file1, line1)) {
            stringstream ss(line1);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                if (car_id == car1_id || car_id == car2_id || car_id == car3_id) {
                    cout <<indexNo_str<<". "<< "Car Name: " << car_name << ", Price: " << price_str << ", Return Date: " << returnDate_str << endl;
                }
            }
        }
        file1.close();
    }

    // inputs the condition of the car and the penaltydays and returns the customer record deductions
    int calculateCustomerRecordDeductions(int condition, int days_difference){
        int customerRecordDeduction = 0;
        if(condition==2){
            customerRecordDeduction += 1;
        }
        else if(condition==3){
            customerRecordDeduction += 2;
        }

        if(days_difference>0){
            customerRecordDeduction += (days_difference/10) + 1;
        }

        return customerRecordDeduction;
    }

    // return a car: this method asks the index of car to return and then a confirmation for return : 
    // if yes : then updates the cars.csv file and make the car_id (which we take from the car.csv file) null in the customers.csv file and reduce the no_car_rented by 1  
    // if no : then returns to displayMenu
    void returnCar()
    {
        cout << "Enter the index number of the car you want to return: ";
        int indexNo;
        cin >> indexNo;
        cin.ignore();

        if(!isCarRented(indexNo)){
            cout<<"****************Invalid Choice****************\n";
            return;
        }

        // getting the condition of car
        cout<<"*********Enter the condition of the car: *********\n";
        cout<<"1. No damage\n";
        cout<<"2. Minor damage\n";
        cout<<"3. Major damage\n";
        cout<<"Enter your choice: ";
        int condition;
        cin>>condition;
        cin.ignore();
        if(condition<1 || condition>3){
            cout<<"****************Invalid Choice****************\n";
            return;
        }

        cout << "Are you sure you want to return this car? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore();

        
        if (choice == 'y') {
            
            string rented_car_id="null";
            string expected_return_date="null";
            double car_per_day_cost;
            // updating the cars.csv file
            ifstream file(cars_file);
            if (!file.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            string line;
            string new_file_content;
            while (getline(file, line)) {
                stringstream ss(line);
                string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
                if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                    if (stoi(indexNo_str) == indexNo) {
                        rented_car_id=car_id;
                        expected_return_date=returnDate_str;
                        car_per_day_cost = stod(price_str);
                        isAvailable_str = "1";
                        returnDate_str = "null";
                        username_str = "null";
                    }
                    new_file_content += indexNo_str + "," + car_id + "," + car_name + "," + price_str + "," + isAvailable_str + "," + returnDate_str + "," + username_str + "\n";
                }
            }
            file.close();
            ofstream file_out(cars_file);
            if (!file_out.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            file_out << new_file_content;
            file_out.close();

            
            ///////// update customers.csv file
            ifstream file1("customers.csv");
            if (!file1.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            string line1;
            string new_file_content1;
            while (getline(file1, line1)) {
                stringstream ss(line1);
                string username1, name, password1, customer_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
                if (getline(ss, username1, ',') && getline(ss, name, ',') && getline(ss, password1, ',') && getline(ss, customer_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
                    if (username1 == username) {
                        int no_car_rented = stoi(no_car_rented_str);
                        no_car_rented--;
                        if (car1_id == rented_car_id) {
                            car1_id = "null";
                        } else if (car2_id == rented_car_id) {
                            car2_id = "null";
                        } else if (car3_id == rented_car_id) {
                            car3_id = "null";
                        }

                        // calculating penalties if any
                        double penalty = 0;
                        if(condition==2){
                            penalty += 1000;
                        }
                        else if(condition==3){
                            penalty += 5000;
                        }

                        // calculating the days difference
                        int days_difference = calculateDaysFrom(expected_return_date,getTodaysDate());
                        if(days_difference>0){
                            penalty += days_difference*2*car_per_day_cost;
                        }

                        // update customer_record in customers.csv file
                        int customerRecordDeductions = calculateCustomerRecordDeductions(condition,days_difference);
                        int newCustomerRecord = stoi(customer_record_str) - customerRecordDeductions;
                        
                        // finally updating the customers.csv file
                        new_file_content1 += username1 + "," + name + "," + password1 + "," + to_string(newCustomerRecord) + "," + to_string(no_car_rented) + "," + car1_id + "," + car2_id + "," + car3_id + "\n";
                        cout<<"Car returned successfully\n";
                        
                        if(penalty>0){
                            cout<<"Penalty for returning the car late or in damaged condition is: "<<"Rs. "<<penalty<<endl;
                        }

                    } else {
                        new_file_content1 += line1 + "\n";
                    }
                }
            }
            file1.close();
            ofstream file_out1("customers.csv");
            if (!file_out1.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            file_out1 << new_file_content1;
            file_out1.close();
        }
    }    
    
    // takes the username and password and checks if the user is present in the customers.csv file or not and if yes then returns true else false
    bool verifyCustomer() {
        ifstream file("customers.csv");
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name1, password1, customer_record_str, no_car_rented_str, car1_index_str, car2_index_str, car3_index_str;
            if (getline(ss, username1, ',') && getline(ss, name1, ',') && getline(ss, password1, ',') && getline(ss, customer_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_index_str, ',') && getline(ss, car2_index_str, ',') && getline(ss, car3_index_str, ',')) {
                if (username1 == username && password1 == password) {
                    file.close();
                    name=name1;
                    return true;
                }
            }
        }
        file.close();
        return false;
    }

};


////////////////////////////////// Employee() ////////////////////////////////
// we will deploy with the same class as of Customer class just here we will access the employees.csv file instead of customers.csv file
class Employee : public User {
public:
    Employee(const string& name, const string& username, const string& password)
        : User(name, username, password) {}

    // displayMen()
    void displayMenu() override {
        cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
        cout<<"-*-*-*-*-*-*-*-*-*-*-*-Welcome "<<name<<" to Employee Menu-*-*-*-*-*-*-*-*-*-*-*-\n";
        cout << "Select any of the following:\n";
        cout << "1. Rent a car\n";
        cout << "2. View rented cars\n";
        cout << "3. Return a car\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        
        // adding switch to all classes
        switch (choice)
        {
        case 1:
            //Call rentCar method
            if(availableCarsCount()==0){
                cout<<"****************Sorry, no cars available****************\n";
            }
            else {
                if(rentedCarsCount()>=car_rent_limit){
                    cout<<"****************You have already rented 3 cars****************\n";
                }
                else{
                    viewAvailableCars();
                    rentCar();
                }
            }
            break;
        case 2:
            // Call viewRentedCars method
            if(rentedCarsCount()==0){
                cout<<"****************No cars rented yet****************\n";
            }
            else {
                viewRentedCars();
            }
            break;
        case 3:
            // Call returnCar method
            if(rentedCarsCount()==0){
                cout<<"****************No cars rented yet****************\n";
            }
            else {
                viewRentedCars();
                returnCar();
            }
            break;
        case 4:
            // Exit
            cout<<"****************Exiting Employee Menu****************\n";
            return;
        default:
            cout<<"****************Invalid choice****************\n";
            break;
        }

        // redirecting to displayMenu <--- <-- <-- <-- 
        cout<<"****************Enter 1 to go back to Employee Menu****************\n";
        int choice1;
        cin>>choice1;
        cin.ignore();
        if(choice1==1){
            displayMenu();
        }
    }

    // checks if the given string represent a date in yyyy/mm/dd and not any arbtrary input
    bool isValidDateFormat(string date){
        if(date.length()!=10){
            return false;
        }
        if(date[4]!='/' || date[7]!='/'){
            return false;
        }
        for(int i=0;i<10;i++){
            if(i==4 || i==7){
                continue;
            }
            if(date[i]<'0' || date[i]>'9'){
                return false;
            }
        }
        return true;
    }

    // isBorrowableDate : takes the date in yyyy/mm/dd format as input then also accesses todays date from system and checks if the argument date after todays date or not and if no then returns 0
    // now if yes then checks if the argument date is after less than 30 days from todays date and if yes then returns 1 else -1
    int isBorrowableDate(string date){
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int year = 1900 + ltm->tm_year;
        int month = 1 + ltm->tm_mon;
        int day = ltm->tm_mday;
        string today_date = to_string(year)+"/"+to_string(month)+"/"+to_string(day);
        if(date<today_date){
            return 0;
        }
        else{
            string date1 = date;
            string date2 = today_date;
            int year1 = stoi(date1.substr(0,4));
            int month1 = stoi(date1.substr(5,2));
            int day1 = stoi(date1.substr(8,2));
            int year2 = stoi(date2.substr(0,4));
            int month2 = stoi(date2.substr(5,2));
            int day2 = stoi(date2.substr(8,2));
            if(year1-year2==0 && month1-month2==0 && day1-day2<=30){
                return 1;
            }
            else{
                return -1;
            }
        }
    }

    // counts the number of available cars from the cars.csv file and returns the count
    int availableCarsCount()
    {
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return -1;
        }
        string line;
        int count = 0;
        while (getline(file, line)) {
            stringstream ss(line);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                if (isAvailable_str == "1") {
                    count++;
                }
            }
        }
        file.close();
        return count;
    }

    // checks if the car is rented or not by taking the car_id and returns true if rented else false
    bool isCarRented(int indexNo){
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                if (stoi(indexNo_str) == indexNo && isAvailable_str == "0") {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
        return false;
    }

    // checks if the car is available for rent or not by taking the indexNo and returns true if available else false
    bool isCarAvailableForRent(int indexNo){
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                if (stoi(indexNo_str) == indexNo && isAvailable_str == "1") {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
        return false;
    }

    // counts the number of rented cars from the cars.csv file and returns the count
    int rentedCarsCount()
    {
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return -1;
        }
        string line;
        int count = 0;
        while (getline(file, line)) {
            stringstream ss(line);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                if (isAvailable_str == "0" && username_str==username) {
                    count++;
                }
            }
        }
        file.close();
        return count;
    }

    // prints the list of available cars
    void viewAvailableCars() {
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        string line;

        while (getline(file, line)) {  
            stringstream ss(line);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',')) {
                double price = stod(price_str);
                bool isAvailable = (isAvailable_str == "1");
                //cout<<"isAvailable"<<isAvailable_str;
                if (isAvailable) {
                    cout <<indexNo_str << ". Model: " << car_name << ", Price: " << price*0.85 << endl;
                }
            }
        }
        file.close();
    }

    // returns todays date in yyyy/mm/dd format
    // in case of date is 3 then it stores 03
    string getTodaysDate(){
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int year = 1900 + ltm->tm_year;
        int month = 1 + ltm->tm_mon;
        int day = ltm->tm_mday;
        string today_date = to_string(year)+"/";
        if(month<10){
            today_date+="0";
        }
        today_date+=to_string(month)+"/";
        if(day<10){
            today_date+="0";
        }
        today_date+=to_string(day);
        return today_date;
    }

    // Function to calculate the diff in number of days between two dates
    int calculateDaysFrom(string date1, string date2) {
    tm tm1 = {0}, tm2 = {0};

    stringstream ss1(date1);
    ss1 >> get_time(&tm1, "%Y/%m/%d");

    stringstream ss2(date2);
    ss2 >> get_time(&tm2, "%Y/%m/%d");

    time_t t1 = mktime(&tm1);
    time_t t2 = mktime(&tm2);

    int difference = difftime(t2, t1) / (60 * 60 * 24);

    return difference;
    }


    // returns employee_record of the employee from the employees.csv file
    int getEmployeeRecord(){
        ifstream file(employeeFile);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return -1;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name, password1, employee_record_str;
            if (getline(ss, username1, ',') && getline(ss, name, ',') && getline(ss, password1, ',') && getline(ss, employee_record_str, ',')) {
                if (username1 == username) {
                    file.close();
                    return stoi(employee_record_str);
                }
            }
        }
        file.close();
        return -1;
    }

    // Method to rent a car : asks the index no of car to be rented and then return date and then a confirmation that you want to rent : if yes 
    //then updates the cars.csv file with username of the employee and return date and then updates the employee.csv file with the car_id
    // else returns to the displayMenu
    void rentCar() {
        cout << "Enter the index number of the car you want to rent: ";
        int indexNo;
        cin >> indexNo;
        cin.ignore();
        if(!isCarAvailableForRent(indexNo)){
            cout<<"****************Invalid Index****************\n";
            return;
        }

        // checking employee_record
        int employee_record = getEmployeeRecord();
        if(employee_record<0){
            cout<<"*********Your employee record is not good enough to rent a car*********\n";
            return;
        }
        
        cout << "Enter the return date (YYYY/MM/DD): ";
        string returnDate;
        getline(cin, returnDate);

        // checking if the date is in valid format
        if(!isValidDateFormat(returnDate)){
            cout<<"****************Invalid Date Format****************\n";
            return;
        }

        // getting current date
        double car_per_day_cost;
        string currDate;
        currDate = getTodaysDate();

        // checking if the return date is valid or not and getting the difference in days
        int days_difference = calculateDaysFrom(currDate,returnDate);
        if(days_difference<0){
            cout<<"*********Return date can't be before today*********\n";
            return;
        }
        else if(days_difference>30){
            cout<<"*****Rent time should be not more than 30 days*****\n";
            return;
        }



        // confirmation to rent the car
        cout << "Are you sure you want to rent this car? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore();
        
        if (choice == 'y') {

            string car_id_final="null";

            // updating the cars.csv file
            ifstream file(cars_file);
            if (!file.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            string line;
            string new_file_content;
            while (getline(file, line)) {
                stringstream ss(line);
                string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
                if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                    if (stoi(indexNo_str) == indexNo) {
                        isAvailable_str = "0";
                        username_str = username;
                        returnDate_str = returnDate;
                        car_id_final=car_id;
                        // storing the rent price of the car
                        car_per_day_cost = stod(price_str);
                    }
                    new_file_content += indexNo_str + "," + car_id + "," + car_name + "," + price_str + "," + isAvailable_str + "," + returnDate_str + "," + username_str + "\n";
                }
            }
            file.close();
            ofstream file_out(cars_file);
            if (!file_out.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            file_out << new_file_content;
            file_out.close();
            
            
            // updatingnemployee.csv file
            ifstream file1(employeeFile);
            if (!file1.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            string line1;
            string new_file_content1;
            while (getline(file1, line1)) {
                stringstream ss(line1);
                string username1, name, password1, employee_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
                if (getline(ss, username1, ',') && getline(ss, name, ',') && getline(ss, password1, ',') && getline(ss, employee_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
                    if (username1 == username) {
                        int no_car_rented = stoi(no_car_rented_str);
                        no_car_rented++;
                        if (car1_id == "null") {
                            car1_id = car_id_final;
                        } else if (car2_id == "null") {
                            car2_id = car_id_final;
                        } else if (car3_id == "null") {
                            car3_id = car_id_final;
                        }
                        new_file_content1 += username1 + "," + name + "," + password1 + "," + employee_record_str + "," + to_string(no_car_rented) + "," + car1_id + "," + car2_id + "," + car3_id + "\n";
                    } else {
                        new_file_content1 += line1 + "\n";
                    }
                }
            }
            file1.close();
            ofstream file_out1(employeeFile);
            if (!file_out1.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            file_out1 << new_file_content1;
            file_out1.close();

            cout << "Car rented successfully.\n";

            // Calculating the bill amount
            double total_cost = (days_difference+1)*car_per_day_cost*0.85;
            cout<<"Total cost of renting the car for "<<days_difference+1<<" days is: "<<"Rs. "<<total_cost<<endl;
        }
        else{
            return;
        }
    }

    // view rented cars: this method takes the car_id from the employees.csv and then using this prints the car_name, price and returnDate of the cars form cars.csv file
    void viewRentedCars() {
        
        // reading the car ids from the employees.csv file
        ifstream file(employeeFile);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        string line;
        string car1_id, car2_id, car3_id;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name, password1, employee_record_str, no_car_rented_str, car1_id_str, car2_id_str, car3_id_str;
            if (getline(ss, username1, ',') && getline(ss, name, ',') && getline(ss, password1, ',') && getline(ss, employee_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id_str, ',') && getline(ss, car2_id_str, ',') && getline(ss, car3_id_str, ',')) {
                if (username1 == username) {
                    car1_id = car1_id_str;
                    car2_id = car2_id_str;
                    car3_id = car3_id_str;
                }
            }
        }
        file.close();

        // case if no car is rented
        if(car1_id=="null" && car2_id=="null" && car3_id=="null"){
            cout<<"*************No cars rented yet*************\n";
            return;
        }

        // using the car ids to print the car_name, price and returnDate from the cars.csv file
        ifstream file1(cars_file);
        if (!file1.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        string line1;
        while (getline(file1, line1)) {
            stringstream ss(line1);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                if (car_id == car1_id || car_id == car2_id || car_id == car3_id) {
                    cout <<indexNo_str<<". "<< "Car Name: " << car_name << ", Price: " << price_str << ", Return Date: " << returnDate_str << endl;
                }
            }
        }
        file1.close();
    }

    // inputs the condition of the car and the penaltydays and returns the employee record deductions
    int calculateEmployeeRecordDeductions(int condition, int days_difference){
        int employeeRecordDeduction = 0;
        if(condition==2){
            employeeRecordDeduction += 1;
        }
        else if(condition==3){
            employeeRecordDeduction += 2;
        }

        if(days_difference>0){
            employeeRecordDeduction += (days_difference/10) + 1;
        }

        return employeeRecordDeduction;
        
    }

    // return a car: this method asks the index of car to return and then a confirmation for return :
    // if yes : then updates the cars.csv file and make the car_id (which we take from the car.csv file) null in the employees.csv file and reduce the no_car_rented by 1
    // if no : then returns to displayMenu
    void returnCar()
    {
        cout << "Enter the index number of the car you want to return: ";
        int indexNo;
        cin >> indexNo;
        cin.ignore();

        if(!isCarRented(indexNo)){
            cout<<"****************Invalid Choice****************\n";
            return;
        }

        // getting the condition of car
        cout<<"*********Enter the condition of the car: *********\n";
        cout<<"1. No damage\n";
        cout<<"2. Minor damage\n";
        cout<<"3. Major damage\n";
        cout<<"Enter your choice: ";
        int condition;
        cin>>condition;
        cin.ignore();
        if(condition<1 || condition>3){
            cout<<"****************Invalid Choice****************\n";
            return;
        }

        cout << "Are you sure you want to return this car? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore();

        
        if (choice == 'y') {
            
            string rented_car_id="null";
            string expected_return_date="null";
            double car_per_day_cost;
            // updating the cars.csv file
            ifstream file(cars_file);
            if (!file.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            string line;
            string new_file_content;
            while (getline(file, line)) {
                stringstream ss(line);
                string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
                if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                    if (stoi(indexNo_str) == indexNo) {
                        rented_car_id=car_id;
                        expected_return_date=returnDate_str;
                        car_per_day_cost = stod(price_str);
                        isAvailable_str = "1";
                        returnDate_str = "null";
                        username_str = "null";
                    }
                    new_file_content += indexNo_str + "," + car_id + "," + car_name + "," + price_str + "," + isAvailable_str + "," + returnDate_str + "," + username_str + "\n";
                }
            }
            file.close();
            ofstream file_out(cars_file);
            if (!file_out.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            file_out << new_file_content;
            file_out.close();

            ///////// update employees.csv file
            ifstream file1(employeeFile);
            if (!file1.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            string line1;
            string new_file_content1;
            while (getline(file1, line1)) {
                stringstream ss(line1);
                string username1, name, password1, employee_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
                if (getline(ss, username1, ',') && getline(ss, name, ',') && getline(ss, password1, ',') && getline(ss, employee_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
                    if (username1 == username) {
                        int no_car_rented = stoi(no_car_rented_str);
                        no_car_rented--;
                        if (car1_id == rented_car_id) {
                            car1_id = "null";
                        } else if (car2_id == rented_car_id) {
                            car2_id = "null";
                        } else if (car3_id == rented_car_id) {
                            car3_id = "null";
                        }

                        // calculating penalties if any
                        double penalty = 0;
                        if(condition==2){
                            penalty += 1000;
                        }
                        else if(condition==3){
                            penalty += 5000;
                        }

                        // calculating the days difference
                        int days_difference = calculateDaysFrom(expected_return_date,getTodaysDate());
                        if(days_difference>0){
                            penalty += days_difference*2*car_per_day_cost*0.85;
                        }

                        // update employee_record in employees.csv file
                        int employeeRecordDeductions = calculateEmployeeRecordDeductions(condition,days_difference);
                        int newEmployeeRecord = stoi(employee_record_str) - employeeRecordDeductions;
                        
                        // finally updating the employees.csv file
                        new_file_content1 += username1 + "," + name + "," + password1 + "," + to_string(newEmployeeRecord) + "," + to_string(no_car_rented) + "," + car1_id + "," + car2_id + "," + car3_id + "\n";
                        cout<<"Car returned successfully\n";
                        
                        if(penalty>0){
                            cout<<"Penalty for returning the car late or in damaged condition is: "<<"Rs. "<<penalty<<endl;
                        }

                    } else {
                        new_file_content1 += line1 + "\n";
                    }
                }
            }
            file1.close();
            ofstream file_out1(employeeFile);
            if (!file_out1.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            file_out1 << new_file_content1;
            file_out1.close();
        }
    }

    // takes the username and password and checks if the user is present in the employees.csv file or not and if yes then returns true else false
    bool verifyEmployee() {
        ifstream file(employeeFile);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name1, password1, employee_record_str;
            if (getline(ss, username1, ',') && getline(ss, name1, ',') && getline(ss, password1, ',') && getline(ss, employee_record_str, ',')) {
                if (username1 == username && password1 == password) {
                    file.close();
                    name=name1;
                    return true;
                }
            }
        }
        file.close();
        return false;
    }

};


////////////////////////////////// Manager() ////////////////////////////////
class Manager : public User {
public:
    Manager(const string& name, const string& username, const string& password)
        : User(name, username, password) {}

    void displayMenu() override {
        cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
        cout<<"-*-*-*-*-*-*-*-*-*-*--*-*-*-Welcome "<<manager_name<<"-*-*-*-*-*-*-*-*-*-*-*--*-*-\n";
        cout << "Manager Menu : Select any of the following:\n";
        cout << "1. Add a new car\n";
        cout << "2. Add a new employee\n";
        cout << "3. Add a new customer\n";
        cout << "4. View all cars\n";
        cout << "5. View all employees\n";
        cout << "6. View all customers\n";
        cout << "7. Delete a car\n";
        cout << "8. Delete an employee\n";
        cout << "9. Delete a customer\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        // Add switch case to call appropriate method based on user choice
        switch (choice)
        {
        case 1:
            // Call addCar method
            addCar();
            break;
        case 2:
            // Call addEmployee method
            addEmployee();
            break;
        case 3:
            // Call addCustomer method
            addCustomer();
            break;
        case 4:
            // Call viewAllCars method
            if(countNoOfCars()==0){
                cout<<"****************No cars to display****************\n";
            }else {
                viewAllCars();
            }
            break;
        case 5:    
            // Call viewAllEmployees method
            if(countNoOfEmployees()==0){
                cout<<"****************No employees to display****************\n";
            }else {
                viewAllEmployees();
            }
            break;  
        case 6:
            // Call viewAllCustomers method
            if(countNoOfCustomers()==0){
                cout<<"****************No customers to display****************\n";
            }else {
                viewAllCustomers();
            }
            break;
        case 7:
            // Call deleteCar method
            if(countNoOfCars()==0){
                cout<<"****************No cars to delete****************\n";
                displayMenu();
            }
            else{
            viewAllCars();
            deleteCar();
            }
            break;
        case 8:
            // Call deleteEmployee method
            if(countNoOfEmployees()==0){
                cout<<"****************No employees to delete****************\n";
                displayMenu();
            }else {
                viewAllEmployees();
                deleteEmployee();
            }
            break;
        case 9:
            // Call deleteCustomer method
            if(countNoOfCustomers()==0){
                cout<<"****************No customers to delete****************\n";
                displayMenu();
            }else {
                viewAllCustomers();
                deleteCustomer();
            }
            break;
            case 10: 
            return;
        default:
            cout<<"****************Invalid choice****************\n";
            break;
        }

        // redirecting to displayMenu <--- <-- <-- <--
        cout<<"****************Enter 1 to go back to Manager Menu****************\n";
        int choice1;
        cin>>choice1;
        cin.ignore();
        if(choice1==1){
            displayMenu();
        }
    }
   
    //checks if the employee with given username has rented a car or not and if yes then returns true else false
    bool hasEmployeeRentCar(string &username){
        ifstream file(employeeFile);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name1, password1, employee_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
            if (getline(ss, username1, ',') && getline(ss, name1, ',') && getline(ss, password1, ',') && getline(ss, employee_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
                if (username1 == username && no_car_rented_str!="0") {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
        return false;
    }


    // checks if the customer with given username has rented a car or not and if yes then returns true else false
    bool hasCustomerRentedCar(string &username){
        ifstream file("customers.csv");
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name1, password1, customer_record_str, no_car_rented_str, car1_index_str, car2_index_str, car3_index_str;
            if (getline(ss, username1, ',') && getline(ss, name1, ',') && getline(ss, password1, ',') && getline(ss, customer_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_index_str, ',') && getline(ss, car2_index_str, ',') && getline(ss, car3_index_str, ',')) {
                if (username1 == username && no_car_rented_str!="0") {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
        return false;
    }

    // checks if the given string contains spaces or not and if yes then returns true else false
    bool checkForSpaces(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                return true;
            }
        }
        return false;
    }
    
    // view all employees: this method checks if the given username is present in the employee.csv file or not
    bool checkIfEmployeeIsAvailable(string username){
        ifstream file(employeeFile);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name1, password1, employee_record_str;
            if (getline(ss, username1, ',') && getline(ss, name1, ',') && getline(ss, password1, ',') && getline(ss, employee_record_str, ',')) {
                if (username1 == username) {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
        return false;
    }
    
    // view all customers: this method checks if the given username is present in the customers.csv file or not
    bool checkIfCustomerIsAvailable(string username){
        ifstream file("customers.csv");
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name1, password1, customer_record_str, no_car_rented_str, car1_index_str, car2_index_str, car3_index_str;
            if (getline(ss, username1, ',') && getline(ss, name1, ',') && getline(ss, password1, ',') && getline(ss, customer_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_index_str, ',') && getline(ss, car2_index_str, ',') && getline(ss, car3_index_str, ',')) {
                if (username1 == username) {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
        return false;
    }
    
    // counts the number of cars from the cars.csv file and returns the count
    int countNoOfCars(){
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return -1;
        }
        string line;
        int count = 0;
        while (getline(file, line)) {
            count++;
        }
        file.close();
        return count;
    }

    // counts the number of employees from the employees.csv file and returns the count
    int countNoOfEmployees(){
        ifstream file(employeeFile);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return -1;
        }
        string line;
        int count = 0;
        while (getline(file, line)) {
            count++;
        }
        file.close();
        return count;
    }
    
    // counts the number of cars from the cars.csv file and returns the count
    int countNoOfCustomers(){
        ifstream file("customers.csv");
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return -1;
        }
        string line;
        int count = 0;
        while (getline(file, line)) {
            count++;
        }
        file.close();
        return count;
    }

    // give the average value of employee rating
    int getAverageEmployeeRating(){
        ifstream file("employees.csv");
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return -1;
        }
        string line;
        int count = 0;
        int sum = 0;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name1, password1, employee_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
            if (getline(ss, username1, ',') && getline(ss, name1, ',') && getline(ss, password1, ',') && getline(ss, employee_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
                sum += stoi(employee_record_str);
                count++;
            }
        }
        file.close();
        
        cout<<"sumEmpinManager: "<<sum<<endl;
        
        if(count==0){
            return 0;
        }

        if(sum==0){
            return 5;
        }
        return sum/count;
    }

    // give the average value of customer rating
    int getAverageCustomerRating(){
        ifstream file("customers.csv");
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return -1;
        }
        string line;
        int count = 0;
        int sum = 0;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name1, password1, customer_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
            if (getline(ss, username1, ',') && getline(ss, name1, ',') && getline(ss, password1, ',') && getline(ss, customer_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
                sum += stoi(customer_record_str);
                count++;
            }
        }
        file.close();

        cout<<"sumCusinManager: "<<sum<<endl;

        if(count==0){
            return 0;
        }

        if(sum==0){
            return 5;
        }
        return sum/count;
    }
    
    // lowestAvailableIndex: this method returns the lowest index number which is not present in the cars.csv file
    int lowestAvailableIndex()
    {
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return -1;
        }
        string line;
        int index = 1;
        while (getline(file, line)) {
            stringstream ss(line);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                if (stoi(indexNo_str) != index) {
                    file.close();
                    return index;
                }
                index++;
            }
        }
        file.close();
        return index;
    }

    // checkIdUnique: this method takes the car_id and checks if the car_id is unique or not and if yes then returns true else false
    bool checkIdUnique(string &car_id)
    {
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string indexNo_str,car_id1, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id1, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                if (car_id1 == car_id) {
                    file.close();
                    return false;
                }
            }
        }
        file.close();
        return true;
    }

    // after deleting a car, this method calibrates the index numbers of the cars.csv file
    void calibrateIndexes(){
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        string line;
        int index = 1;
        string new_file_content;
        while (getline(file, line)) {
            stringstream ss(line);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                new_file_content += to_string(index) + "," + car_id + "," + car_name + "," + price_str + "," + isAvailable_str + "," + returnDate_str + "," + username_str + "\n";
                index++;
            }
        }
        file.close();
        ofstream file_out(cars_file);
        if (!file_out.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        file_out << new_file_content;
        file_out.close();
    }
    
    // Asks the user to enter the car details(carId, car_name, price) and then it checks if the carId is uniques or not and if yes then adds the car to the cars.csv file else returns to displayMenu
    void addCar() {
        int index = lowestAvailableIndex();
        cout << "Enter the car name: ";
        string car_name;
        getline(cin,car_name);
        cout << "Enter the car id: ";
        string car_id;
        getline(cin,car_id);
        cout << "Enter the price: ";
        int price;
        cin >> price;
        cin.ignore();

        // check for spaces in car_id
        if(checkForSpaces(car_id)){
            cout<<"****************Car id can't contain spaces****************\n";
            return;
        }
        
        bool isIdUnique = checkIdUnique(car_id);

        if(isIdUnique){
            ofstream file(cars_file, ios::app);
            if (!file.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            file << index << "," << car_id << "," << car_name << "," << price << ",1,null,null\n";
            file.close();
            cout << "Car added successfully.\n";
        }
        else{
            cout<<"Car id already exists, Please Enter unique car id\n";
        }
    }    

    // checkEmployeeUsernameUnique: this method takes the username and checks if the username is unique or not and if yes then returns true else false
    bool checkEmployeeUsernameUnique(string &username)
    {
        ifstream file(employeeFile);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name, password1, employee_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
            if (getline(ss, username1, ',') && getline(ss, name, ',') && getline(ss, password1, ',') && getline(ss, employee_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
                if (username1 == username) {
                    file.close();
                    return false;
                }
            }
        }
        file.close();
        return true;
    }
    
    // checkCustomerUsernameUnique: this method takes the username and checks if the username is unique or not and if yes then returns true else false
    bool checkCustomerUsernameUnique(string &username)
    {
        ifstream file("customers.csv");
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return false;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name, password1, customer_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
            if (getline(ss, username1, ',') && getline(ss, name, ',') && getline(ss, password1, ',') && getline(ss, customer_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
                if (username1 == username) {
                    file.close();
                    return false;
                }
            }
        }
        file.close();
        return true;
    }   

    // addEmployee: this method takes the username, name and password and then checks if the username is unique or not and if yes then adds the employee to the employees.csv file else returns to displayMenu
    void addEmployee() {
        cout << "Enter the name: ";
        string name;
        getline(cin,name);
        cout << "Enter the username: ";
        string username;
        getline(cin,username);
        cout << "Enter the password: ";
        string password;
        getline(cin,password);
        
        // checks for spaces in username and password
        if(checkForSpaces(username) || checkForSpaces(password)){
            cout<<"****************Username and password can't contain spaces****************\n";
            return;
        }

        int average_Employee_Rating = max(3,getAverageEmployeeRating());

        bool isUsernameUnique = checkEmployeeUsernameUnique(username);

        if(isUsernameUnique){
            ofstream file(employeeFile, ios::app);
            if (!file.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            file << username << "," << name << "," << password << "," << average_Employee_Rating << ",0,null,null,null\n";
            file.close();
            cout << "Employee added successfully.\n";
        }
        else{
            cout<<"Username already exists, Please Enter details again with a unique username\n";
        }
    }

    // addCustomer: this method takes the username, name and password and then checks if the username is unique or not and if yes then adds the customer to the customers.csv file else returns to displayMenu
    void addCustomer() {
        cout << "Enter the name: ";
        string name;
        getline(cin,name);
        cout << "Enter the username: ";
        string username;
        getline(cin,username);
        cout << "Enter the password: ";
        string password;
        getline(cin,password);
        
        

        // checks for spaces in username and password
        if(checkForSpaces(username) || checkForSpaces(password)){
            cout<<"****************Username and password can't contain spaces****************\n";
            return;
        }
        
        bool isUsernameUnique = checkCustomerUsernameUnique(username);

        int averageCustomerRating = max(3,getAverageCustomerRating());

        if(isUsernameUnique){
            ofstream file("customers.csv", ios::app);
            if (!file.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            file << username << "," << name << "," << password << "," << averageCustomerRating << ",0,null,null,null\n";
            file.close();
            cout << "Customer added successfully.\n";
        }
        else{
            cout<<"Username already exists, Please Enter details again with a unique username\n";
        }
    }

    // verifies the manager by checking the username and password and if correct then returns true else false
    bool verifyManager()
    {
        if (username == manager_id && password == manager_password) {
            return true;
        }
        return false;   
    }

    // display all the cars with index, id, name, price,isAvailalble, and if not available then due date and id of person who borrowed from the cars.csv file
    void viewAllCars() {
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                cout <<indexNo_str<<". "<<"Car Id: " << car_id << ", Car Name: " << car_name << ", Price: " << price_str << ", Is Available: " << isAvailable_str;
                if (isAvailable_str == "0") {
                    cout << ", Return Date: " << returnDate_str << ", Borrowed by: " << username_str;
                }
                cout << endl;
            }
        }
        file.close();
    }
    
    // viewAllEmployees: this method displays all the employees from the employees.csv file along with the if of any car if rented
    void viewAllEmployees() {
        ifstream file("employees.csv");
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name, password1, employee_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
            if (getline(ss, username1, ',') && getline(ss, name, ',') && getline(ss, password1, ',') && getline(ss, employee_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
                cout << "Username: " << username1 << ", Name: " << name << ", No of cars rented: " << no_car_rented_str;
                if(car1_id!="null")
                    cout<<", Car1: " << car1_id;
                if(car2_id!="null")
                    cout<<", Car2: " << car2_id;
                if(car3_id!="null")
                    cout<<", Car3: " << car3_id;
                cout<<endl;
            }
        }
        file.close();
    }

    // viewAllCustomer: this method displays all the employees from the employees.csv file along with the if of any car if rented
    void viewAllCustomers() {
        ifstream file("customers.csv");
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username1, name, password1, customer_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
            if (getline(ss, username1, ',') && getline(ss, name, ',') && getline(ss, password1, ',') && getline(ss, customer_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
                cout << "Username: " << username1 << ", Name: " << name << ", No of cars rented: " << no_car_rented_str;
                if(car1_id!="null")
                    cout<<", Car1: " << car1_id;
                if(car2_id!="null")
                    cout<<", Car2: " << car2_id;
                if(car3_id!="null")
                    cout<<", Car3: " << car3_id;
                cout<<endl;
            }
        }
        file.close();
    }
    
    // deleteEmployee: this method deletes the employee from the employees.csv file by taking the username of the employee after taking a confirmation from the manager, also notifies that if the employee is not present or if the employee has rented any car
    void deleteEmployee() {
        cout << "Enter the username of the employee you want to delete: ";
        string username;
        getline(cin,username);

        bool isEmployeeAvailable = checkIfEmployeeIsAvailable(username);
        if(!isEmployeeAvailable){
            cout<<"****************Employee not found****************\n";
            return;
        }
        else if(hasEmployeeRentCar(username)){
            cout<<"****************Employee has rented a car, cannot delete****************\n";
            return;
        }
        else{
            ifstream file(employeeFile);
            if (!file.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            string line;
            string new_file_content;
            while (getline(file, line)) {
                stringstream ss(line);
                string username1, name, password1, employee_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
                if (getline(ss, username1, ',') && getline(ss, name, ',') && getline(ss, password1, ',') && getline(ss, employee_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
                    if (username1 != username) {
                        new_file_content += username1 + "," + name + "," + password1 + "," + employee_record_str + "," + no_car_rented_str + "," + car1_id + "," + car2_id + "," + car3_id + "\n";
                    }
                }
            }
            file.close();
            ofstream file_out(employeeFile);
            if (!file_out.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            file_out << new_file_content;
            file_out.close();
            cout << "****************Employee deleted successfully.****************\n";
        }
    }
    
    // deleteCustomer: this method deletes the customer from the customers.csv file by taking the username of the customer after taking a confirmation from the manager, also notifies that if the customer is not present or if the customer has rented any car
    void deleteCustomer() {
        cout << "Enter the username of the customer you want to delete: ";
        string username;
        getline(cin,username);

        bool isCustomerAvailable = checkIfCustomerIsAvailable(username);
        if(!isCustomerAvailable){
            cout<<"****************Customer not found****************\n";
            return;
        }
        else if(hasCustomerRentedCar(username)){
            cout<<"****************Customer has rented a car, cannot delete****************\n";
            return;
        }
        else{
            ifstream file("customers.csv");
            if (!file.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            string line;
            string new_file_content;
            while (getline(file, line)) {
                stringstream ss(line);
                string username1, name, password1, customer_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
                if (getline(ss, username1, ',') && getline(ss, name, ',') && getline(ss, password1, ',') && getline(ss, customer_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
                    if (username1 != username) {
                        new_file_content += username1 + "," + name + "," + password1 + "," + customer_record_str + "," + no_car_rented_str + "," + car1_id + "," + car2_id + "," + car3_id + "\n";
                    }
                }
            }
            file.close();
            ofstream file_out("customers.csv");
            if (!file_out.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            file_out << new_file_content;
            file_out.close();
            cout << "****************Customer deleted successfully.****************\n";
        }

       
        
    }
    
    // deletes the car from the cars.csv file by taking the index number of the car after taking a confirmation from the manager, also notifies that if the car is not present or if the car is already rented
    void deleteCar() {
        cout << "Enter the index number of the car you want to delete: ";
        int indexNo;
        cin >> indexNo;
        cin.ignore();
        ifstream file(cars_file);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        string line;
        bool carFound = false;
        bool carRented = false;
        while (getline(file, line)) {
            stringstream ss(line);
            string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
            if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                if (stoi(indexNo_str) == indexNo) {
                    carFound = true;
                    if (isAvailable_str == "0") {
                        carRented = true;
                    }
                    break;
                }
            }
        }
        file.close();
        if (!carFound) {
            cout << "Car not found.\n";
        } else if (carRented) {
            cout << "Car is already rented.\n";
        } else {
            ifstream file(cars_file);
            if (!file.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            string line;
            string new_file_content;
            while (getline(file, line)) {
                stringstream ss(line);
                string indexNo_str,car_id, car_name, price_str, isAvailable_str, returnDate_str, username_str;
                if (getline(ss, indexNo_str, ',') &&getline(ss, car_id, ',') && getline(ss, car_name, ',') && getline(ss, price_str, ',') && getline(ss, isAvailable_str, ',') && getline(ss, returnDate_str, ',') && getline(ss, username_str, ',')) {
                    if (stoi(indexNo_str) != indexNo) {
                        new_file_content += indexNo_str + "," + car_id + "," + car_name + "," + price_str + "," + isAvailable_str + "," + returnDate_str + "," + username_str + "\n";
                    }
                }
            }  
            file.close();
            ofstream file_out(cars_file);
            if (!file_out.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }
            file_out << new_file_content;
            file_out.close();
            cout << "Car deleted successfully.\n";

            calibrateIndexes();
        }
    }

};


////////////////////////////////// Functions to check for spaces() ////////////////////////////////
bool checkForSpaces(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            return true;
        }
    }
    return false;
}

// give the average value of employee rating
int getAverageEmployeeRating(){
    ifstream file("employees.csv");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return -1;
    }
    string line;
    int count = 0;
    int sum = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string username1, name1, password1, employee_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
        if (getline(ss, username1, ',') && getline(ss, name1, ',') && getline(ss, password1, ',') && getline(ss, employee_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
            sum += stoi(employee_record_str);
            count++;
        }
    }
    file.close();
    if(count==0){
        return 5;
    }

    cout<<"CalculatedAverageEmpRating: "<<sum<<" "<<count<<endl;

    return sum/count;
}

// give the average value of customer rating
int getAverageCustomerRating(){
    ifstream file("customers.csv");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return -1;
    }
    string line;
    int count = 0;
    int sum = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string username1, name1, password1, customer_record_str, no_car_rented_str, car1_id, car2_id, car3_id;
        if (getline(ss, username1, ',') && getline(ss, name1, ',') && getline(ss, password1, ',') && getline(ss, customer_record_str, ',') && getline(ss, no_car_rented_str, ',') && getline(ss, car1_id, ',') && getline(ss, car2_id, ',') && getline(ss, car3_id, ',')) {
            sum += stoi(customer_record_str);
            count++;
        }
    }
    file.close();
    if(count==0){
        return 0;
    }

    if(sum==0){
        return 5;
    }
    return sum/count;
}

////////////////////////////////// Sign-in as Customer ////////////////////////////////
void signUpAsCustomer(){
    
    cout << "Enter the name: ";
    string name;
    getline(cin,name);
    cout << "Enter the username: ";
    string username;
    getline(cin,username);
    cout << "Enter the password: ";
    string password;
    getline(cin,password);
    

    // checks for spaces in username and password
    if(checkForSpaces(username) || checkForSpaces(password)){
        cout<<"****************Username and password can't contain spaces****************\n";
        return;
    }

    int average_Customer_Rating = max(3,getAverageCustomerRating());

    // upading the customers.csv file
    ofstream file("customers.csv", ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    file << username << "," << name << "," << password << ","<<average_Customer_Rating<<",0,null,null,null\n";
    file.close();
    cout << "You have been added successfully.\n";
}


////////////////////////////////// Sign-in as Employee ////////////////////////////////
void signUpAsEmployee(){
    cout << "Enter the name: ";
    string name;
    getline(cin,name);
    cout << "Enter the username: ";
    string username;
    getline(cin,username);
    cout << "Enter the password: ";
    string password;
    getline(cin,password);

    // checks for spaces in username and password
    if(checkForSpaces(username) || checkForSpaces(password)){
        cout<<"****************Username and password can't contain spaces****************\n";
        return;
    }

    int average_Employee_Rating = max(3,getAverageEmployeeRating());


    // upading the employees.csv file
    ofstream file("employees.csv", ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    file << username << "," << name << "," << password << ","<<average_Employee_Rating<<",0,null,null,null\n";
    file.close();
    cout << "You have been added successfully.\n";

}


////////////////////////////////// HOME() ////////////////////////////////
void home(){
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*Welcome to Car Castle-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    cout << "Home : Select any of the following:\n";
    cout << "1. Login as Customer\n";
    cout << "2. Login as Employee\n";
    cout << "3. Sign-in as Customer\n";
    cout << "4. Sign-in as Employee\n";
    cout << "5. Sign-in as Manager\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    
    int choice;
    cin >> choice;
    cin.ignore();

    if(choice==1){

        string input_username;
        string input_name="null";
        string input_password;
        cout<<"Enter username: ";
        getline(cin,input_username);
        cout<<"Enter password: ";
        getline(cin,input_password);
        Customer c(input_name, input_username, input_password);
        bool verified = c.verifyCustomer();
        if (verified) {
            c.displayMenu();
        } else {
            cout << "Invalid username or password.\n";
        }
    }
    else if(choice==2){
        string input_username;
        string input_name="null";
        string input_password;
        cout<<"Enter username: ";
        getline(cin,input_username);
        cout<<"Enter password: ";
        getline(cin,input_password);
        Employee e(input_name, input_username, input_password);
        bool verified = e.verifyEmployee();
        if (verified) {
            e.displayMenu();
        } else {
            cout << "Invalid username or password.\n";
        }
    }
    else if(choice ==3){
        signUpAsCustomer();
    }
    else if(choice==4){
        signUpAsEmployee();
    }
    else if(choice==5){

        string input_username;
        string input_name="null";
        string input_password;
        cout<<"Enter username: ";
        getline(cin,input_username);
        cout<<"Enter password: ";
        getline(cin,input_password);

        Manager m(input_name, input_username, input_password);
        bool verified = m.verifyManager();
        if (verified) {
            m.displayMenu();
        } else {
            cout << "**********Invalid username or password**********\n";
        }
    }
    else if(choice==6){
        exit(0);
    }
    else{
        cout<<"****************Invalid choice****************\n";
    }

    cout<<"****************Enter 1 to go back to Home****************\n";
    int choice1;
    cin>>choice1;
    cin.ignore();
    if(choice1==1){
        home();
    }else 
    return;

    // Exiting Car Castle
    cout<<"****************Exiting Car Castle****************\n";
    cout<<"****************Please visit again****************\n";
}

////////////////////////////////// MAIN() ////////////////////////////////
int main() {

    home();
    // Your code for interacting with the database and implementing the system goes here

    return 0;
}