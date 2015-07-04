# encoding: utf-8

##
# Backup Generated: backup_sqlite
# Once configured, you can run the backup with the following command:
#
# $ backup perform -t backup_sqlite [-c <path_to_configuration_file>]
#
# For more information about Backup's components, see the documentation at:
# http://backup.github.io/backup
#
Model.new(:backup_sqlite, 'Description for backup_sqlite') do

  ##
  # SQLite [Database]
  #
  database SQLite do |db|
    # Path to database file
    db.path               = "/home/brxue/test/sqlite/test.db"

    # Optional: Use to set the location of this utility
    #   if it cannot be found by name in your $PATH
    db.sqlitedump_utility = "/usr/bin/sqlite3"
  end

  ##
  # Local (Copy) [Storage]
  #
  store_with Local do |local|
    local.path       = "/home/brxue/test/backup/backups/"
    local.keep       = 5
  end

end
