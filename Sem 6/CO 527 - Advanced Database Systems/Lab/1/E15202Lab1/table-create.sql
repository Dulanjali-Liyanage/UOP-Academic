CREATE DATABASE company;

USE company;

CREATE TABLE employees(
	emp_no INT PRIMARY KEY,
	birth_date DATE,
	first_name VARCHAR(14),
	last_name VARCHAR(16),
	sex ENUM('M','F'),
	hire_date DATE
);

CREATE TABLE departments(
	dept_no CHAR(4) PRIMARY KEY,
	dept_name VARCHAR(40)
);
CREATE TABLE dept_emp(
	emp_no INT,
	dept_no CHAR(4),
	from_date DATE,
	to_date DATE,
    PRIMARY KEY(emp_no,dept_no),
	FOREIGN KEY(emp_no) REFERENCES employees(emp_no),
	FOREIGN KEY(dept_no) REFERENCES departments(dept_no)
);
CREATE TABLE dept_manager(
	emp_no INT,
    dept_no CHAR(4),
	from_date DATE,
	to_date DATE,
    PRIMARY KEY(dept_no,emp_no),
	FOREIGN KEY(emp_no) REFERENCES employees(emp_no),
	FOREIGN KEY(dept_no) REFERENCES departments(dept_no)
);

CREATE TABLE salaries(
	emp_no INT,
	salary INT,
    from_date DATE,
	to_date DATE,
    PRIMARY KEY(from_date,to_date,emp_no),
	FOREIGN KEY(emp_no) REFERENCES employees(emp_no)
);
CREATE TABLE titles(
	emp_no INT,
	title VARCHAR(50),
	from_date DATE,
	to_date DATE,
    PRIMARY KEY(title,emp_no),
	FOREIGN KEY(emp_no) REFERENCES employees(emp_no)
);