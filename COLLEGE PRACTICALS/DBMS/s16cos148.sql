select deposit.cname from deposit,customers where city in (select city from customers,deposit where customers.cname = deposit.cname and customers.cname = 'Anil' and amount > 2000) and customers.cname = deposit.cname;
select distinct(employee.dept_no),emp_name,job_title from dep,employee,job where employee.DEPT_NO = dep.DEPT_NO and dep.DEPT_NO=job.DEPT_NO and employee.dept_no in (select dept_no from employee where dept_no=15); 
select cname from deposit group by bname having count(bname) >= (select max(count(bname)) from deposit group by bname) ;
select city from branch group by city having count(city) >= (select max(count(city)) from branch group by city) ;



