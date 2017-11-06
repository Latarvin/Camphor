# SQL Note

在codecademy上的SQL教程笔记

## CRUD

```SQL
CREATE TABLE celebs (id INTEGER, name TEXT, age INTEGER);
INSERT INTO celebs (id, name, age) VALUES (2, 'Beyonce Knowles', 33); 

UPDATE celebs 
SET age = 22 
WHERE id = 1; 

SELECT * FROM celebs;

/* add column */
ALTER TABLE celebs ADD COLUMN twitter_handle TEXT; 
SELECT * FROM celebs;

// update
UPDATE celebs 
SET twitter_handle = '@taylorswift13' 
WHERE id = 4; 

SELECT * FROM celebs;

// delete
UPDATE celebs 
SET twitter_handle = '@taylorswift13' 
WHERE id = 4; 

DELETE FROM celebs WHERE twitter_handle IS NULL; 

SELECT * FROM celebs;

```



## New task

```sql
// new table with value constraints
CREATE TABLE awards (
  id INTEGER PRIMARY KEY,
  recipient TEXT NOT NULL,
  award_name TEXT DEFAULT "Grammy");
```



