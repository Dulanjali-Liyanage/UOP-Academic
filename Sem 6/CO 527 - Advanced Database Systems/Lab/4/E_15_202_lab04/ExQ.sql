#Starting new transaction

set autocommit = 1;
start transaction;
update salaries set salary = 1.1*salary where emp_no=201772; 
select * from salaries where emp_no=201772;
rollback;

select * from salaries where emp_no=201772;


#Ending transaction

set autocommit = 0;
start transaction;
update salaries set salary = 1.1*salary where emp_no=201772; 
select * from salaries where emp_no=201772;
commit;
select * from salaries where emp_no=201772;


#To take the table to the original state
update salaries set salary = salary/1.1 where emp_no=201772;
select * from salaries where emp_no=201772;

set autocommit = 0;
start transaction;
update salaries set salary = 1.1*salary where emp_no=201772; 
select * from salaries where emp_no=201772;
rollback;
select * from salaries where emp_no=201772;
 
set autocommit = 0;
start transaction;
update salaries set salary = 1.1*salary where emp_no=201772;
start transaction;
select * from salaries where emp_no=201772;
rollback;
select * from salaries where emp_no=201772;

#concurrent access
#I of ACID

#First session
select * from departments;
set autocommit = 0;
start transaction;
insert into departments values ("d010","xyz");
select * from departments;
commit;

#Second session
select * from departments;
set autocommit = 0;
start transaction;
select * from departments;
select * from departments;
commit;
select * from departments;

#Concurrent updates

#First session
select * from departments;
set autocommit = 0;
start transaction;
update departments set dept_name="pqr" where dept_no="d010";
select * from departments;
commit;
select * from departments;
select * from departments;
commit;
select * from departments;

#Second session
select * from departments;
set autocommit = 0;
start transaction;
update departments set dept_name="Hello" where dept_no="d010";
select * from departments;
commit;
select * from departments;


