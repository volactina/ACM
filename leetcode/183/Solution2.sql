select Name Customers
from Customers A left join Orders B
on A.Id=B.CustomerId
where B.CustomerId is null