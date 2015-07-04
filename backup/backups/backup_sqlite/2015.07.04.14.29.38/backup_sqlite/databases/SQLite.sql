PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE students(id integer primary key, name text, age integer, email text);
INSERT INTO "students" VALUES(1,'ZhangSan',19,NULL);
INSERT INTO "students" VALUES(2,'LiSi',20,NULL);
COMMIT;
