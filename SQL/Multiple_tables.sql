-- create a table
create table artists(id integer primary key, name text);

--
select * from albums;
select * from artists;

select * from artists where id = 3;
select * from albums
where artist_id = 3;

-- select some part
select albums.name, albums.year, artists.name from albums, artists;

-- join
select * from albums
join artists on albums.artist_id = artists.id;

--
select * from albums
left join artists on albums.artist_id = artists.id;

-- a column with the same name.
-- as: rename a column
select
	albums.name as 'Album',
	albums.year,
  artists.name as 'Artist'
from
	albums
join artists on
	albums.artist_id = artists.id
where
	albums.year > 1980;

--
