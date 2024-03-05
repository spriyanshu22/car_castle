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
    a Customer Login
    b Employee Login
    c Customer Signup
    d Employee Signup
    e Manager Login
    f Exit

=>  After choosing Customer Login, the customer is asked to enter the username and password. 
    If the username and password are incorrect, the customer is redirected to the Home() page after confirmation of the customer.
    If the username and password are correct, the customer is redirected to the Customer class with following functionalities: 
    i Rent a car
    ii View rented cars
    iii Return a car
    iv Exit

=>  After choosing Employee Login, the employee is asked to enter the username and password.
=>  Rest of the functionalities are same as the Customer class. Only the difference is that the employee gets an extra 15% discount on the rent price of the car.

=> After choosing Manager Login, the manager is asked to enter the username and password.
=> The manager is redirected to the Manager class with the following functionalities:
    i Add a car
    ii Remove a car
    iii View all cars
    iv Add an employee
    v Remove an employee
    vi View all employees
    vii Add a customer
    viii Remove a customer
    ix View all customers
    x Exit

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
