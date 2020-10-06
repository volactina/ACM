delete from Person
where (Id) not in(
    select id from(
        select min(id) id
        from Person
        group by Email
    )tmp
)