select A.Name Employee
from Employee A join Employee B
on A.ManagerId=B.Id and A.Salary>B.Salary