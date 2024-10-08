#!/bin/bash

rm -rf /finished_init

# -------------------------------- CHECK VARS -------------------------------- #
if [[ -z $MYSQL_ROOT_PASSWORD || -z $MYSQL_USERNAME || -z $MYSQL_PASSWORD || -z $DB_NAME ]]; then
	echo -e "\033[0;31mMissing .env vars!\033[0m"
	exit 1
fi

if [ ! -d "/var/lib/mysql/wordpress" ]; then
	# ---------------------------- SET MYSQL SETTINGS ---------------------------- #
	service mysql start
	sleep 2
	mysql -u root -p$MYSQL_ROOT_PASSWORD -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';FLUSH PRIVILEGES;"
	mysql -u root -p$MYSQL_ROOT_PASSWORD -e "CREATE DATABASE IF NOT EXISTS $DB_NAME;"
	mysql -u root -p$MYSQL_ROOT_PASSWORD -e "CREATE USER IF NOT EXISTS '$MYSQL_USERNAME'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
	mysql -u root -p$MYSQL_ROOT_PASSWORD -e "GRANT ALL PRIVILEGES ON *.* TO 'pgeeser'@'%';"
	mysql -u root -p$MYSQL_ROOT_PASSWORD -e "FLUSH PRIVILEGES;"
	sleep 2
	killall mysqld
	service mysql stop
fi

touch /finished_init
echo -e "\033[1;33mFinished MySQL init!\033[0m"

# ------------------ EXECUTE ALL COMMANDS GIVEN AS ARGUMENTS ----------------- #
exec "$@"
