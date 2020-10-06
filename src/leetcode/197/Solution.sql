select B.Id
from Weather A join Weather B
on DATE_ADD(A.RecordDate,INTERVAL 1 DAY)=B.RecordDate and A.Temperature<B.Temperature