#mysql.exe -u root -p
CREATE DATABASE company_security;
use company_security;
CREATE USER 'user1'@'localhost' IDENTIFIED BY '1234';
exit;

#mysql.exe -u user1 -p
show databases;
show grants;
exit;

#mysql.exe -u root -p
show databases;
exit;

#mysql.exe -u root -p
use company_security;
GRANT SELECT ON company_security.employee TO 'user1'@'localhost';
flush privileges;
exit;

#mysql.exe -u user1 -p
show grants;
use company_security;
select * from employee;
#INSERT INTO EMPLOYEE VALUES('Alex','X','Ramsey',999888888,'1995-08-14','202 Boston, London, TX','M', 40000,'333445555',1); 
exit;

#mysql.exe -u root -p
use company_security;
GRANT INSERT ON company_security.employee TO 'user1'@'localhost';
flush privileges;
exit;

#mysql.exe -u user1 -p
show grants;
use company_security;
INSERT INTO EMPLOYEE VALUES('Alex','X','Ramsey',999888888,'1995-08-14','202 Boston, London, TX','M', 40000,'333445555',1);
exit;

#mysql.exe -u root -p
use company_security;
GRANT SELECT ON company_security.works_on TO 'user1'@'localhost';
GRANT CREATE VIEW ON company_security.* TO 'user1'@'localhost';
GRANT SHOW VIEW ON company_security.* TO 'user1'@'localhost';
flush privileges;
exit;

#mysql.exe -u user1 -p
show grants;
use company_security;
create view works_on1 as select Fname,Lname,Pno from employee,works_on where employee.Ssn = works_on.Essn;
show tables;
select * from works_on1;
exit;

#mysql.exe -u root -p
use company_security;
CREATE USER 'user2'@'localhost' IDENTIFIED BY '1234';
GRANT SELECT ON company_security.works_on1 TO 'user2'@'localhost';
flush privileges;
exit;

#mysql.exe -u user2 –p
show grants;
use company_security;
select * from works_on1;
exit;

#mysql.exe -u root -p
use company_security;
REVOKE SELECT ON company_security.works_on from 'user1'@'localhost';
REVOKE CREATE VIEW ON company_security.* FROM 'user1'@'localhost';
REVOKE SHOW VIEW ON company_security.* FROM 'user1'@'localhost';
REVOKE INSERT ON company_security.employee FROM 'user1'@'localhost';
flush privileges;
exit;

#mysql.exe -u user1 –p
show grants;
show databases;
exit;

#mysql.exe -u user2 –p
use company_security;
select * from works_on1;
exit;

#sql injection attacks
#mysql.exe -u root –p
use company_security;
select * from employee where Ssn=999887777;
select * from employee where Ssn=999887777 or 'x'='x';