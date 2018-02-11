-- create table
CREATE TABLE celebs (id INTEGER, name TEXT, age INTEGER);

-- add info
INSERT INTO celebs (id, name, age)
VALUES (1, 'Justin Bieber', 21);

-- view content
SELECT * FROM celebs;

-- more content
INSERT INTO celebs (id, name, age)
VALUES (2, 'Beyounce Knowles', 33);

INSERT INTO celebs (id, name, age)
VALUES (3, 'Jeremy Lin', 26);

INSERT INTO celebs (id, name, age)
VALUES (2, 'Taylor Swift', 26);

-- see name column
SELECT name FROM celebs;

-- edit a row
update celebs
set age = 22
where id = 1;

select * from celebs;

-- add a column
alter table celebs add column twitter_handle text;

select * from celebs;

-- add content
update celebs
set twitter_handle = '@taylorswift13'
where id = 4;

-- delete NULL
delete from celebs where twitter_handle is NULL;

select * from celebs;
