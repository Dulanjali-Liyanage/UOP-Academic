#mysql.exe -u root -p
use company_security;

CREATE USER 'A'@'localhost' IDENTIFIED BY '1234';
CREATE USER 'B'@'localhost' IDENTIFIED BY '1234';
CREATE USER 'C'@'localhost' IDENTIFIED BY '1234';
CREATE USER 'D'@'localhost' IDENTIFIED BY '1234';
CREATE USER 'E'@'localhost' IDENTIFIED BY '1234';

#1
GRANT SELECT,UPDATE ON company_security.department TO 'A'@'localhost' WITH GRANT OPTION;
GRANT SELECT,UPDATE ON company_security.dept_locations TO 'A'@'localhost' WITH GRANT OPTION;
GRANT SELECT,UPDATE ON company_security.employee TO 'A'@'localhost' WITH GRANT OPTION;
GRANT SELECT,UPDATE ON company_security.project TO 'A'@'localhost' WITH GRANT OPTION;
GRANT SELECT,UPDATE ON company_security.works_on TO 'A'@'localhost' WITH GRANT OPTION;

#2
GRANT SELECT(`Dname`,`Dnumber`) ON company_security.department TO 'B'@'localhost';
GRANT SELECT (`Fname`,`Minit`,`Lname`,`Ssn`,`Bdate`,`Address`,`Sex`,`Super_ssn`,`Dno`) ON company_security.employee TO 'B'@'localhost';

#3
GRANT SELECT,UPDATE ON company_security.works_on TO 'C'@'localhost';
GRANT SELECT (`Fname`,`Minit`,`Lname`,`Ssn`) ON company_security.employee TO 'C'@'localhost';
GRANT SELECT (`Pname`,`Pnumber`) ON company_security.project TO 'C'@'localhost';

#4
GRANT SELECT ON company_security.employee TO 'D'@'localhost';
GRANT SELECT,UPDATE ON company_security.dependent TO 'D'@'localhost';

#5
CREATE VIEW userE AS SELECT * FROM employee WHERE Dno=3;
GRANT SELECT ON company_security.userE TO 'E'@'localhost';