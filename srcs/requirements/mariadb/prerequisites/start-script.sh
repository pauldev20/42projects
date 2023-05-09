#!/bin/bash

rm -rf /finished_init

# -------------------------------- CHECK VARS -------------------------------- #
if [[ -z $MYSQL_ROOT_PASSWORD || -z $MYSQL_USERNAME || -z $MYSQL_PASSWORD ]]; then
	echo -e "\033[0;31mMissing .env vars!\033[0m"
	exit 1
fi

if grep -Fxq "bind-address            = 127.0.0.1" "/etc/mysql/mariadb.conf.d/50-server.cnf"; then
	# ------------------------------ MARIADB CONFIG ------------------------------ #
	sed -i '/bind-address            = 127.0.0.1/d' /etc/mysql/mariadb.conf.d/50-server.cnf

	# ---------------------------- SET MYSQL SETTINGS ---------------------------- #
	service mysql start
	sleep 1
	mysql -u root -p$MYSQL_ROOT_PASSWORD -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';FLUSH PRIVILEGES;"
	mysql -u root -p$MYSQL_ROOT_PASSWORD -e "CREATE DATABASE IF NOT EXISTS wordpress;"
	mysql -u root -p$MYSQL_ROOT_PASSWORD -e "CREATE USER IF NOT EXISTS '$MYSQL_USERNAME'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
	mysql -u root -p$MYSQL_ROOT_PASSWORD -e "GRANT ALL PRIVILEGES ON *.* TO 'pgeeser'@'%';"
	mysql -u root -p$MYSQL_ROOT_PASSWORD -e "FLUSH PRIVILEGES;"
	sleep 1
	killall mysqld
	service mysql stop
fi

touch /finished_init
echo -e "\033[1;33mFinished MySQL init!\033[0m"

# ------------------ EXECUTE ALL COMMANDS GIVEN AS ARGUMENTS ----------------- #
exec "$@"
