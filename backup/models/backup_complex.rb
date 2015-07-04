# encoding: utf-8

##
# Backup Generated: backup_complex
# Once configured, you can run the backup with the following command:
#
# $ backup perform -t backup_complex [-c <path_to_configuration_file>]
#
# For more information about Backup's components, see the documentation at:
# http://backup.github.io/backup
#
Model.new(:backup_complex, 'Description for backup_complex') do
  ##
  # Archive [Archive]
  #
  # Adding a file or directory (including sub-directories):
  #   archive.add "/path/to/a/file.rb"
  #   archive.add "/path/to/a/directory/"
  #
  # Excluding a file or directory (including sub-directories):
  #   archive.exclude "/path/to/an/excluded_file.rb"
  #   archive.exclude "/path/to/an/excluded_directory
  #
  # By default, relative paths will be relative to the directory
  # where `backup perform` is executed, and they will be expanded
  # to the root of the filesystem when added to the archive.
  #
  # If a `root` path is set, relative paths will be relative to the
  # given `root` path and will not be expanded when added to the archive.
  #
  #   archive.root '/path/to/archive/root'
  #
  archive :my_archive do |archive|
    # Run the `tar` command using `sudo`
    # archive.use_sudo
    archive.add "/path/to/a/file.rb"
    archive.add "/path/to/a/folder/"
    archive.exclude "/path/to/a/excluded_file.rb"
    archive.exclude "/path/to/a/excluded_folder"
  end

  ##
  # SQLite [Database]
  #
  database SQLite do |db|
    # Path to database file
    db.path               = "/path/to/my/sqlite/db.sqlite"

    # Optional: Use to set the location of this utility
    #   if it cannot be found by name in your $PATH
    db.sqlitedump_utility = "/opt/local/bin/sqlite3"
  end

  ##
  # SCP (Secure Copy) [Storage]
  #
  store_with SCP do |server|
    server.username   = "my_username"
    server.password   = "my_password"
    server.ip         = "123.45.678.90"
    server.port       = 22
    server.path       = "~/backups/"
    server.keep       = 5

    # Additional options for the SSH connection.
    # server.ssh_options = {}
  end

  ##
  # Local (Copy) [Storage]
  #
  store_with Local do |local|
    local.path       = "~/backups/"
    local.keep       = 5
  end

  ##
  # Gzip [Compressor]
  #
  compress_with Gzip

  ##
  # Mail [Notifier]
  #
  # The default delivery method for Mail Notifiers is 'SMTP'.
  # See the documentation for other delivery options.
  #
  notify_by Mail do |mail|
    mail.on_success           = true
    mail.on_warning           = true
    mail.on_failure           = true

    mail.from                 = "sender@email.com"
    mail.to                   = "receiver@email.com"
    mail.address              = "smtp.gmail.com"
    mail.port                 = 587
    mail.domain               = "your.host.name"
    mail.user_name            = "sender@email.com"
    mail.password             = "my_password"
    mail.authentication       = "plain"
    mail.encryption           = :starttls
  end

end
