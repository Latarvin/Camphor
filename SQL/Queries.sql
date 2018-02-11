select name, imdb_rating from movies;

-- return unique values
select distinct genre from movies;

-- filter
select * from movies where imdb_rating > 8;

-- compare similar values
-- here Seven & Se7en
select * from movies
where name like 'Se_en';

-- get "a-" sth
select * from movies
where name like 'a%';

-- get "man" sth
select * from movies
where name like '%man%';

-- value between
select * from movies
where name between 'A' and 'J';

select * from movies
where year between 1990 and 2000;

-- multiple filter
select * from movies
where year between 1990 and 2000
and genre = 'comedy';

select * from movies
where genre = 'comedy'
or year < 1980;

-- sort the results in descending order
select * from movies
order by imdb_rating desc;

-- limit showing number
select * from movies
order by imdb_rating asc
limit 3;
