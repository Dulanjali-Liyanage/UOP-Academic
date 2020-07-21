CREATE DATABASE foodapp;

USE foodapp;

CREATE TABLE customer_details(
	customerID VARCHAR(10)PRIMARY KEY,
	customerName VARCHAR(100),
	customerAddress VARCHAR(100),
	customerPayMethod VARCHAR(10),
	customerPhoneNum INT(10),
	customerEmail VARCHAR(40)
);

CREATE TABLE restaurants(
	restaurantID VARCHAR(10),
	restaurantName VARCHAR(40),
	foodItemCode VARCHAR(10),
	foodItemName VARCHAR(40),
	priceEach INT,
	PRIMARY KEY(restaurantID,foodItemCode)
);

CREATE TABLE order_details(
	orderNumber INT AUTO_INCREMENT PRIMARY KEY,
	orderDateTime DATETIME DEFAULT NOW(),
	customerID VARCHAR(10),
	restaurantID VARCHAR(10),
	foodItemCode VARCHAR(10),
	foodItemQuantity INT,
	totalPrice INT,
	FOREIGN KEY (restaurantID,foodItemCode) REFERENCES restaurants(restaurantID,foodItemCode),
	FOREIGN KEY(customerID) REFERENCES customer_details(customerID)
);


INSERT INTO `customer_details` (`customerID`, `customerName`, `customerAddress`, `customerPayMethod`, `customerPhoneNum`, `customerEmail`) VALUES ('A001', 'Dulanjali', 'Matara', 'Cash', '0712381123', 'abc@gmail.com');
INSERT INTO `customer_details` (`customerID`, `customerName`, `customerAddress`, `customerPayMethod`, `customerPhoneNum`, `customerEmail`) VALUES ('A002', 'Saroja', 'Kandy', 'Cash', '0722050131', 'pqr@gmail.com');

INSERT INTO `restaurants` (`restaurantID`, `restaurantName`, `foodItemCode`, `foodItemName`, `priceEach`) VALUES ('R001', 'AAA', 'F001', 'Fried Rice', '200');
INSERT INTO `restaurants` (`restaurantID`, `restaurantName`, `foodItemCode`, `foodItemName`, `priceEach`) VALUES ('R001', 'AAA', 'F002', 'Kottu', '300');

#When a customer add details of their order order_details table
#will be filled with the below details
set autocommit = 0;
start transaction;
insert into order_details (CustomerID,restaurantID,foodItemCode,foodItemQuantity,totalPrice) values("A001","R001","F001",1,200);
commit;

#When a customer decided to cancel the order the details will be rolled back
set autocommit = 0;
start transaction;
insert into order_details (CustomerID,restaurantID,foodItemCode,foodItemQuantity,totalPrice) values("A002","R001","F002",1,300);
rollback;

#A.1)First  concurrent session
set autocommit = 0;
start transaction;
insert into order_details (CustomerID,restaurantID,foodItemCode,foodItemQuantity,totalPrice) values("A001","R001","F002",1,300);
commit;
#A.2)Second concurrent session
set autocommit = 0;
start transaction;
insert into order_details (CustomerID,restaurantID,foodItemCode,foodItemQuantity,totalPrice) values("A002","R001","F002",1,300);
commit;

#B.1)First concurrent session
set autocommit = 0;
start transaction;
insert into order_details (CustomerID,restaurantID,foodItemCode,foodItemQuantity,totalPrice) values("A001","R001","F002",1,300);
commit;
#B.2)Second concurrent session
set autocommit = 0;
start transaction;
insert into order_details (CustomerID,restaurantID,foodItemCode,foodItemQuantity,totalPrice) values("A002","R001","F002",1,300);
rollback;

#C.1)First concurrent session
set autocommit = 0;
start transaction;
update customer_details set customerAddress="Colombo" where customerID="A001";
commit;
#C.2)Second concurrent session
set autocommit = 0;
start transaction;
update customer_details set customerAddress="Galle" where customerID="A001";
commit;