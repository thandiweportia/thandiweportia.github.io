Python 3.9.6 (tags/v3.9.6:db3ff76, Jun 28 2021, 15:26:21) [MSC v.1929 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> import mysql.connector
>>> mydb = mysql.connector.connect(
	host="localhost",
	user="root",
	password=""
	)
>>> mycursor = mydb.cursor()
>>> mycursor.execute("CREATE DATABASE college")
>>> mydb = mysql.connector.connect(
	host="localhost",
	user="root",
	password="",
	database="college")
>>> mycursor = mydb.cursor()
>>> mycursor.execute("CREATE TABLE students (name VARCHAR(255), address VARCHAR(255))")
>>> mydb = mysql.connector.connect(
	host="localhost",
	user="root",
	password="",
	database="college")
>>> mycursor = mydb.cursor()
>>> mycursor.execute("SHOW TABLES")
>>> for x in mycursor:
	print(x)

	
('students',)
>>> import mysql.connector
>>> mydb = mysql.connector.connect(
	host="localhost",
	user="root",
	password="",
	database="college")
>>> mycursor = mydb.cursor()
>>> sql = "INSERT INTO college (name, address) VALUES (%s, %s)"
>>> val = ("John", "Highway 21")
>>> mycursor.execute(sql, val)
Traceback (most recent call last):
  File "<pyshell#23>", line 1, in <module>
    mycursor.execute(sql, val)
  File "C:\Users\Thandiwe Portia\AppData\Roaming\Python\Python39\site-packages\mysql\connector\cursor.py", line 568, in execute
    self._handle_result(self._connection.cmd_query(stmt))
  File "C:\Users\Thandiwe Portia\AppData\Roaming\Python\Python39\site-packages\mysql\connector\connection.py", line 846, in cmd_query
    result = self._handle_result(self._send_cmd(ServerCmd.QUERY, query))
  File "C:\Users\Thandiwe Portia\AppData\Roaming\Python\Python39\site-packages\mysql\connector\connection.py", line 656, in _handle_result
    raise errors.get_exception(packet)
mysql.connector.errors.ProgrammingError: 1146 (42S02): Table 'college.college' doesn't exist
>>> import mysql.connectorimport mysql.connector
SyntaxError: invalid syntax
>>> mydb = mysql.connector.connect(
	host="localhost",
	user="root",
	password="",
	database="college")>>> import mysql.connector
SyntaxError: invalid syntax
>>> import mysql.connector
>>> mydb = mysql.connector.connect(
	host="localhost",
	user="root",
	password="",
	database="college")
>>> mycursor = mydb.cursor()
>>> sql = "INSERT INTO students (name, address) VALUES (%s, %s)"
>>> val = ("Portia", "Soweto 25")
>>> mycursor.execute(sql, val)
>>> mydb.commit()
>>> print(mycursor.rowcount, "record inserted.")
1 record inserted.
>>> import mysql.connector
>>> mydb = mysql.connector.connect(
	host="localhost",
	user="root",
	password="",
	database="college")
>>> mycursor = mydb.cursor()
>>> sql = "INSERT INTO students (name, address) VALUES (%s, %s)"
>>> val = [
  ('Lihle', 'Dobsonville 30'),
  ('Mbali', '42 Avenue st 22'),
  ('Hlehle', 'AucklandPark 21'),
  ('Michael', 'Johannesburg 34'),
  ('Samu', 'Bedford blvd 32'),
  ('Buhle', 'Green side 21'),
  ('Richard', 'Davey st 31'),
  ('Susan', 'Long way 39'),
  ('Vicky', 'Yellow Garden 32'),
  ('Ben', 'Park Lane 38'),
  ('William', 'Central st 44'),
  ('Chuck', 'Main Road 39'),
  ('Viola', 'Sideway 33')
]
>>> mycursor.executemany(sql, val)
>>> mydb.commit()
>>> print(mycursor.rowcount, "was inserted.")
13 was inserted.
>>> import mysql.connector
>>> mydb = mysql.connector.connect(
	host="localhost",
	user="root",
	password="",
	database="college")
>>> mycursor = mydb.cursor()
>>> mycursor.execute("SELECT name, address FROM students")
>>> myresult = mycursor.fetchall()
>>> for x in myresult:
	print(x)

	
('Portia', 'Soweto 25')
('Lihle', 'Dobsonville 30')
('Mbali', '42 Avenue st 22')
('Hlehle', 'AucklandPark 21')
('Michael', 'Johannesburg 34')
('Samu', 'Bedford blvd 32')
('Buhle', 'Green side 21')
('Richard', 'Davey st 31')
('Susan', 'Long way 39')
('Vicky', 'Yellow Garden 32')
('Ben', 'Park Lane 38')
('William', 'Central st 44')
('Chuck', 'Main Road 39')
('Viola', 'Sideway 33')
>>> import mysql.connector
>>> mydb = mysql.connector.connect(
	host="localhost",
	user="root",
	password="",
	database="college")
>>> mycursor = mydb.cursor()
>>> sql = "SELECT * FROM students WHERE address ='Long way 39'"
>>> mycursor.execute(sql)
>>> myresult = mycursor.fetchall()
>>> for x in myresult:
	print(x)

	
('Susan', 'Long way 39')
>>> import mysql.connector
>>> mydb = mysql.connector.connect(
	host="localhost",
		user="root",
		password="",
		database="college")
>>> mycursor = mydb.cursor()
>>> sql = "SELECT * FROM students ORDER BY name"
>>> mycursor.execute(sql)
>>> myresult = mycursor.fetchall()
>>> for x in myresult:
	print(x)

	
('Ben', 'Park Lane 38')
('Buhle', 'Green side 21')
('Chuck', 'Main Road 39')
('Hlehle', 'AucklandPark 21')
('Lihle', 'Dobsonville 30')
('Mbali', '42 Avenue st 22')
('Michael', 'Johannesburg 34')
('Portia', 'Soweto 25')
('Richard', 'Davey st 31')
('Samu', 'Bedford blvd 32')
('Susan', 'Long way 39')
('Vicky', 'Yellow Garden 32')
('Viola', 'Sideway 33')
('William', 'Central st 44')
>>> import mysql.connector
>>> mydb = mysql.connector.connect(
	host="localhost",
		user="root",
		password="",
		database="college")
>>> mycursor = mydb.cursor()
>>> sql = "DELETE FROM customers WHERE address = 'Mountain 21'"
>>> import mysql.connector
>>> mydb = mysql.connector.connect(
	host="localhost",
		user="root",
		password="",
		database="college")
>>> mycursor = mydb.cursor()
>>> sql = "DELETE FROM students WHERE address = 'AucklandPark 21'"
>>> mycursor.execute(sql)
>>> mydb.commit()
>>> print(mycursor.rowcount, "record(s) deleted")
1 record(s) deleted
>>> import mysql.connector
>>> mydb = mysql.connector.connect(
	host="localhost",
		user="root",
		password="",
		database="college")
>>> mycursor = mydb.cursor()
>>> sql = "UPDATE students SET address = %s WHERE address = %s"
>>> val = ("Vaal ", "Canyon 13")
>>> mycursor.execute(sql, val)
>>> mydb.commit()
>>> print(mycursor.rowcount, "record(s) affected")
0 record(s) affected
>>> import mysql.connector
>>> mydb = mysql.connector.connect(
	host="localhost",
		user="root",
		password="",
		database="college")
>>> mycursor = mydb.cursor()
>>> mycursor.execute("SELECT * FROM students LIMIT 5 OFFSET 2")
>>> myresult = mycursor.fetchall()
>>> for x in myresult:
	print(x)

	
('Mbali', '42 Avenue st 22')
('Michael', 'Johannesburg 34')
('Samu', 'Bedford blvd 32')
('Buhle', 'Green side 21')
('Richard', 'Davey st 31')
>>> 