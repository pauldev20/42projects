#!/bin/bash

rm -rf /finished_init

# -------------------------------- CHECK VARS -------------------------------- #
if [[ -z $WORDPRESS_DB_NAME || -z $WORDPRESS_DB_USER || -z $WORDPRESS_DB_PASSWORD || -z $WORDPRESS_DB_HOST || -z $DOMAIN_NAME \
		|| -z $WORDPRESS_TITLE || -z $WORDPRESS_ADMIN_USER || -z $WORDPRESS_ADMIN_PASSWORD || -z $WORDPRESS_ADMIN_EMAIL \
		|| -z $WORDPRESS_USER || -z $WORDPRESS_EMAIL || -z $WORDPRESS_PASSWORD ]]; then
	echo -e "\033[0;31mMissing .env vars!\033[0m"
	exit 1
fi

# --------------------- DOWNLOAD AND CONFIGURE WORDPRESS --------------------- #
if [ ! -f "/var/www/html/wp-config.php" ]; then
	mkdir -p /var/www/html
	cd /var/www/html && rm -rf *
	chmod 777 /var/www/html

	wp core download --path=/var/www/html --allow-root

	wp config create --path=/var/www/html --dbname=$WORDPRESS_DB_NAME --dbhost=$WORDPRESS_DB_HOST --dbuser=$WORDPRESS_DB_USER --dbpass=$WORDPRESS_DB_PASSWORD --allow-root
	wp core install --path=/var/www/html --skip-email --url=$DOMAIN_NAME --title="$WORDPRESS_TITLE" --admin_user=$WORDPRESS_ADMIN_USER --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL --allow-root
	wp user create $WORDPRESS_USER $WORDPRESS_EMAIL --role=author --user_pass=$WORDPRESS_PASSWORD --path=/var/www/html --allow-root
fi

# ----------------------------- UPDATE WORDPRESS ----------------------------- #
wp plugin update --path=/var/www/html --all --allow-root

touch /finished_init
echo -e "\033[1;33mFinished Wordpress init!\033[0m"

# ------------------ EXECUTE ALL COMMANDS GIVEN AS ARGUMENTS ----------------- #
exec "$@"
