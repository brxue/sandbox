# Installation

1. yum list "\*postgres\*" to query out the PostgreSQL related packages.
2. sudo yum install postgresql.x86_64 postgresql-contrib.x86_64 postgresql-devel.x86_64 postgresql-libs.x86_64 postgresql-plpython.x86_64 postgresql-server.x86_64
3. after this step, the following key tools will be installed (`rpm -ql postgresql.x86_64 | grep bin` can be used to check what binary tools will be installed.):
   * postgres - PostgreSQL server program
   * psql - PostgreSQL client program
   * initdb - Initialize PostgreSQL database cluster directory
   * createdb - Create database
   * createuser - Create user
   * dropdb - Delete database
   * dropuser - Delete user

# Configuration

1. Switch to root user `su - root`
2. Use `initdb -D /the/path/of/database/clusters` (normally /var/lib/pgsql/data) to initialize database cluster directory
   * After this step, PostgreSQL will by default provide us a DB user `postgres` and a dababase named `postgres`
   * Optionaly you can edit PostgreSQL configurations through `/var/lib/pgsql/data/postgresql.conf` and `/var/lib/pgsql/data/pg_hba.conf`
3. Use `systemctl start postgresql` to start PostgreSQL server
4. Use `systemctl statuts postgresql` to check whethere the server is running now
5. Use `systemctl enable postgresql` to enable starting PostgreSQL server automatically on system restart

# Create DATABASE and USER
1. Use `su - postgres` to switch to the user `postgres`
2. Use `createdb testdb` to create a database named `testdb`
3. Use `psql testdb` to connect to the database
4. Use `CREATE USER brxue WITH SUPERUSER LOGIN PASSWORD 'your password here';` to create a user
5. Eixt user `postgres` and now you can login as DB user `brxue` like this: `psql -h localhost -d testdb -U brxue`
