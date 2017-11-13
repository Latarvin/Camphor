import sqlite3

conn = sqlite3.connect('<DBname>.<db/sqlite/db3>')
cur = conn.cursor()
cur.execute('<SQL statement>')
conn.commit()
conn.close()

# create a table
cur.execute('DROP TABLE IF EXISTS students;')
cur.execute('CREATE TABLE students( \
             sid int PRIMARY KEY, \
             name char[10] NOT NULL, \
             dept char[2], \
             Age int DEFAULT 20);')
conn.commit()


# insert
cur.execute('INSERT INFO students, \
             VALUES({}, {}, {}, {})'.format(1, 'smith', 'cs', 35))
conn.commit()

# insert multiple tuple
tmp = [ (2, 'martin', 'cs', 20),
        (3, 'Bern', 'ee', 28),
        ]

cur.executemany('INSERT INFO students, \
                 VALUES({}, {}, {}, {})'.format(tmp))
conn.commit()

# adjust
cur.execute('UPDATE students \
             SET age = 17 \
             WHERE name = \'martin\' AND dept = \'cs\'')
conn.commit()

# query
cur.execute('SELECT * FROM students \
             WHERE age < 25 ORDER BY age')
for row in cur:
    print(row)

cur.execute('SELECT dept, MAX(age) \
             FROM students GROUP BY dept')
for row in cur:
    print( 'dept = {}'.format(row[0]) )
    print( 'MAX(age) = {} \n'.format(row[1]) )
    
