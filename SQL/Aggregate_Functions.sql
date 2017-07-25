select * from fake_apps;

-- count the number
select count(*) from fake_apps;

-- with filter
select count(*) from fake_apps
where price = 0;

-- collaborate with the SELECT statement to arrange identical data into groups
select price, count(*) from fake_apps
group by price;

--
select price, count(*) from fake_apps
where downloads > 20000
group by price;

-- sum
select sum(downloads) from fake_apps;

select category, sum(downloads) from fake_apps
group by category;

-- max
select max(downloads) from fake_apps;

select name, category, max(downloads)
from fake_apps
group by category;

-- min
select min(downloads) from fake_apps;

select name, category, min(downloads)
from fake_apps
group by category;

-- average
select avg(downloads) from fake_apps;

select price, avg(downloads)
from fake_apps
group by price;

-- two digit float
select price, round(avg(downloads), 2)
from fake_apps
group by price;

-- e.g. 12.0
select price, round(avg(downloads))
from fake_apps
group by price;
