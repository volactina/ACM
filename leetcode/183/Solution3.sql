select a.Name Customers
from(
    select DISTINCT A.Name, A.Id
    from Customers A left join Orders B
    on A.Id=B.CustomerId
    where B.CustomerId is null
)as a