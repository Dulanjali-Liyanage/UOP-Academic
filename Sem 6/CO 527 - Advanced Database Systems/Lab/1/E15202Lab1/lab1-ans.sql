select last_name,count(last_name) from employees group by last_name order by count(last_name) desc limit 10;


select dept_no,count(emp_no) from dept_emp where emp_no in (select emp_no from titles where title='Engineer' or title='Senior Engineer') group by dept_no;


select emp_no,first_name,last_name from employees where emp_no in (select distinct emp_no from titles where title='Senior Engineer' and emp_no in (select emp_no from dept_manager where emp_no in (select emp_no from employees where sex='F')));


select titles.emp_no,dept_no,title from (dept_emp join titles on dept_emp.emp_no = titles.emp_no) where titles.emp_no in (select emp_no from salaries where salary > 115000);
select dept_no,count(emp_no) from dept_emp where emp_no in (select emp_no from salaries where salary > 115000) group by dept_no;
 

select first_name,last_name,hire_date,
round(datediff(CURDATE(),birth_date)/366) as age,
round(datediff(CURDATE(),hire_date)/366) as years_of_service
from employees where round(datediff(CURDATE(),birth_date)/366) > 50 and round(datediff(CURDATE(),hire_date)/366) > 10;

 
select first_name,last_name from employees where emp_no not in (select emp_no from dept_emp where dept_no in (select dept_no from departments where dept_name='Human Resources'));
 

select first_name,last_name from employees where emp_no in (select emp_no from salaries where salary > (select max(salary) from salaries where emp_no in (select emp_no from dept_emp where dept_no in (select dept_no from departments where dept_name='Finance'))));
 

select first_name,last_name from employees where emp_no in (select emp_no from salaries where salary > (select avg(salary) from salaries));
 

select ((select avg(salary) from salaries) - (select avg(salary) from salaries where emp_no in (select emp_no from titles where title='Senior Engineer'))) as avg_difference;
 

create view currentDeptEmp as
select emp_no,dept_no from dept_emp where from_date < CURDATE() and to_date > CURDATE();

create view EmpWithoutCurrentDep as
select emp_no from dept_emp where to_date < CURDATE();
	

select emp_no,dept_no from dept_emp where from_date < CURDATE() and to_date > CURDATE();
select emp_no from dept_emp where to_date < CURDATE();


create table printSalaryChange(
	emp_no int,
	new_salary int,
    old_salary int,
    difference int
);
delimiter |
create trigger print_salary_change
before update on salaries
for each row
insert into printSalaryChange values(new.emp_no,new.salary,(select salary from salaries where emp_no=new.emp_no and from_date=new.from_date and to_date=new.to_date),(new.salary-(select salary from salaries where emp_no=new.emp_no and from_date=new.from_date and to_date=to_date)));
|
delimiter ;



delimiter |
create trigger salary_error 
before update on salaries
for each row
begin
if new.salary > (select salary from salaries where emp_no=new.emp_no and from_date=new.from_date and to_date=new.to_date)*1.1 then
SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Incorrect Salary';
end if;
end |
delimiter ;
